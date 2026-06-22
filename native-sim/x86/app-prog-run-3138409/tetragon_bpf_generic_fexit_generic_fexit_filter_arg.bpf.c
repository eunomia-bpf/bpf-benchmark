extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char fexit_calls;
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

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_0(
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
	case 115ULL: goto x86_l_73;
	case 124ULL: goto x86_l_7c;
	case 130ULL: goto x86_l_82;
	case 132ULL: goto x86_l_84;
	case 136ULL: goto x86_l_88;
	case 140ULL: goto x86_l_8c;
	case 144ULL: goto x86_l_90;
	case 146ULL: goto x86_l_92;
	case 152ULL: goto x86_l_98;
	case 156ULL: goto x86_l_9c;
	case 162ULL: goto x86_l_a2;
	case 166ULL: goto x86_l_a6;
	case 172ULL: goto x86_l_ac;
	case 178ULL: goto x86_l_b2;
	case 180ULL: goto x86_l_b4;
	case 186ULL: goto x86_l_ba;
	case 189ULL: goto x86_l_bd;
	case 193ULL: goto x86_l_c1;
	case 199ULL: goto x86_l_c7;
	case 208ULL: goto x86_l_d0;
	case 214ULL: goto x86_l_d6;
	case 217ULL: goto x86_l_d9;
	case 220ULL: goto x86_l_dc;
	case 224ULL: goto x86_l_e0;
	case 232ULL: goto x86_l_e8;
	case 238ULL: goto x86_l_ee;
	case 242ULL: goto x86_l_f2;
	case 249ULL: goto x86_l_f9;
	case 252ULL: goto x86_l_fc;
	case 254ULL: goto x86_l_fe;
	case 257ULL: goto x86_l_101;
	case 259ULL: goto x86_l_103;
	case 262ULL: goto x86_l_106;
	case 268ULL: goto x86_l_10c;
	case 271ULL: goto x86_l_10f;
	case 277ULL: goto x86_l_115;
	case 280ULL: goto x86_l_118;
	case 282ULL: goto x86_l_11a;
	case 285ULL: goto x86_l_11d;
	case 291ULL: goto x86_l_123;
	case 296ULL: goto x86_l_128;
	case 299ULL: goto x86_l_12b;
	case 301ULL: goto x86_l_12d;
	case 304ULL: goto x86_l_130;
	case 307ULL: goto x86_l_133;
	case 313ULL: goto x86_l_139;
	case 316ULL: goto x86_l_13c;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 331ULL: goto x86_l_14b;
	case 336ULL: goto x86_l_150;
	case 339ULL: goto x86_l_153;
	case 342ULL: goto x86_l_156;
	case 348ULL: goto x86_l_15c;
	case 351ULL: goto x86_l_15f;
	case 354ULL: goto x86_l_162;
	case 360ULL: goto x86_l_168;
	case 363ULL: goto x86_l_16b;
	case 365ULL: goto x86_l_16d;
	case 370ULL: goto x86_l_172;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 378ULL: goto x86_l_17a;
	case 381ULL: goto x86_l_17d;
	case 384ULL: goto x86_l_180;
	case 390ULL: goto x86_l_186;
	case 399ULL: goto x86_l_18f;
	case 408ULL: goto x86_l_198;
	case 417ULL: goto x86_l_1a1;
	case 426ULL: goto x86_l_1aa;
	case 435ULL: goto x86_l_1b3;
	case 438ULL: goto x86_l_1b6;
	case 441ULL: goto x86_l_1b9;
	case 447ULL: goto x86_l_1bf;
	case 450ULL: goto x86_l_1c2;
	case 456ULL: goto x86_l_1c8;
	case 459ULL: goto x86_l_1cb;
	case 462ULL: goto x86_l_1ce;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 477ULL: goto x86_l_1dd;
	case 480ULL: goto x86_l_1e0;
	case 483ULL: goto x86_l_1e3;
	case 489ULL: goto x86_l_1e9;
	case 492ULL: goto x86_l_1ec;
	case 496ULL: goto x86_l_1f0;
	case 501ULL: goto x86_l_1f5;
	case 504ULL: goto x86_l_1f8;
	case 508ULL: goto x86_l_1fc;
	case 513ULL: goto x86_l_201;
	case 519ULL: goto x86_l_207;
	case 524ULL: goto x86_l_20c;
	case 527ULL: goto x86_l_20f;
	case 532ULL: goto x86_l_214;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 546ULL: goto x86_l_222;
	case 552ULL: goto x86_l_228;
	case 556ULL: goto x86_l_22c;
	case 560ULL: goto x86_l_230;
	case 568ULL: goto x86_l_238;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 585ULL: goto x86_l_249;
	case 587ULL: goto x86_l_24b;
	case 590ULL: goto x86_l_24e;
	case 595ULL: goto x86_l_253;
	case 601ULL: goto x86_l_259;
	case 604ULL: goto x86_l_25c;
	case 607ULL: goto x86_l_25f;
	case 613ULL: goto x86_l_265;
	case 620ULL: goto x86_l_26c;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 632ULL: goto x86_l_278;
	case 635ULL: goto x86_l_27b;
	case 641ULL: goto x86_l_281;
	case 644ULL: goto x86_l_284;
	case 648ULL: goto x86_l_288;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 672ULL: goto x86_l_2a0;
	case 677ULL: goto x86_l_2a5;
	case 681ULL: goto x86_l_2a9;
	case 684ULL: goto x86_l_2ac;
	case 688ULL: goto x86_l_2b0;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 705ULL: goto x86_l_2c1;
	case 709ULL: goto x86_l_2c5;
	case 712ULL: goto x86_l_2c8;
	case 716ULL: goto x86_l_2cc;
	case 722ULL: goto x86_l_2d2;
	case 728ULL: goto x86_l_2d8;
	case 733ULL: goto x86_l_2dd;
	case 737ULL: goto x86_l_2e1;
	case 740ULL: goto x86_l_2e4;
	case 744ULL: goto x86_l_2e8;
	case 750ULL: goto x86_l_2ee;
	case 756ULL: goto x86_l_2f4;
	case 761ULL: goto x86_l_2f9;
	case 765ULL: goto x86_l_2fd;
	case 768ULL: goto x86_l_300;
	case 772ULL: goto x86_l_304;
	case 778ULL: goto x86_l_30a;
	case 784ULL: goto x86_l_310;
	case 789ULL: goto x86_l_315;
	case 793ULL: goto x86_l_319;
	case 796ULL: goto x86_l_31c;
	case 800ULL: goto x86_l_320;
	case 806ULL: goto x86_l_326;
	case 812ULL: goto x86_l_32c;
	case 817ULL: goto x86_l_331;
	case 821ULL: goto x86_l_335;
	case 824ULL: goto x86_l_338;
	case 828ULL: goto x86_l_33c;
	case 834ULL: goto x86_l_342;
	case 840ULL: goto x86_l_348;
	case 845ULL: goto x86_l_34d;
	case 849ULL: goto x86_l_351;
	case 852ULL: goto x86_l_354;
	case 856ULL: goto x86_l_358;
	case 862ULL: goto x86_l_35e;
	case 868ULL: goto x86_l_364;
	case 873ULL: goto x86_l_369;
	case 877ULL: goto x86_l_36d;
	case 880ULL: goto x86_l_370;
	case 884ULL: goto x86_l_374;
	case 890ULL: goto x86_l_37a;
	case 896ULL: goto x86_l_380;
	case 901ULL: goto x86_l_385;
	case 905ULL: goto x86_l_389;
	case 908ULL: goto x86_l_38c;
	case 912ULL: goto x86_l_390;
	case 918ULL: goto x86_l_396;
	case 924ULL: goto x86_l_39c;
	case 929ULL: goto x86_l_3a1;
	case 933ULL: goto x86_l_3a5;
	case 936ULL: goto x86_l_3a8;
	case 940ULL: goto x86_l_3ac;
	case 946ULL: goto x86_l_3b2;
	case 952ULL: goto x86_l_3b8;
	case 957ULL: goto x86_l_3bd;
	case 961ULL: goto x86_l_3c1;
	case 964ULL: goto x86_l_3c4;
	case 968ULL: goto x86_l_3c8;
	case 974ULL: goto x86_l_3ce;
	case 980ULL: goto x86_l_3d4;
	case 985ULL: goto x86_l_3d9;
	case 989ULL: goto x86_l_3dd;
	case 992ULL: goto x86_l_3e0;
	case 996ULL: goto x86_l_3e4;
	case 1002ULL: goto x86_l_3ea;
	case 1008ULL: goto x86_l_3f0;
	case 1013ULL: goto x86_l_3f5;
	case 1017ULL: goto x86_l_3f9;
	case 1020ULL: goto x86_l_3fc;
	case 1024ULL: goto x86_l_400;
	case 1030ULL: goto x86_l_406;
	case 1036ULL: goto x86_l_40c;
	case 1041ULL: goto x86_l_411;
	case 1045ULL: goto x86_l_415;
	case 1048ULL: goto x86_l_418;
	case 1052ULL: goto x86_l_41c;
	case 1058ULL: goto x86_l_422;
	case 1064ULL: goto x86_l_428;
	case 1069ULL: goto x86_l_42d;
	case 1073ULL: goto x86_l_431;
	case 1076ULL: goto x86_l_434;
	case 1080ULL: goto x86_l_438;
	case 1086ULL: goto x86_l_43e;
	case 1092ULL: goto x86_l_444;
	case 1097ULL: goto x86_l_449;
	case 1101ULL: goto x86_l_44d;
	case 1104ULL: goto x86_l_450;
	case 1108ULL: goto x86_l_454;
	case 1114ULL: goto x86_l_45a;
	case 1120ULL: goto x86_l_460;
	case 1125ULL: goto x86_l_465;
	case 1129ULL: goto x86_l_469;
	case 1132ULL: goto x86_l_46c;
	case 1136ULL: goto x86_l_470;
	case 1142ULL: goto x86_l_476;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1157ULL: goto x86_l_485;
	case 1160ULL: goto x86_l_488;
	case 1164ULL: goto x86_l_48c;
	case 1170ULL: goto x86_l_492;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1185ULL: goto x86_l_4a1;
	case 1188ULL: goto x86_l_4a4;
	case 1192ULL: goto x86_l_4a8;
	case 1198ULL: goto x86_l_4ae;
	case 1204ULL: goto x86_l_4b4;
	case 1209ULL: goto x86_l_4b9;
	case 1213ULL: goto x86_l_4bd;
	case 1216ULL: goto x86_l_4c0;
	case 1220ULL: goto x86_l_4c4;
	case 1226ULL: goto x86_l_4ca;
	case 1232ULL: goto x86_l_4d0;
	case 1237ULL: goto x86_l_4d5;
	case 1241ULL: goto x86_l_4d9;
	case 1244ULL: goto x86_l_4dc;
	case 1248ULL: goto x86_l_4e0;
	case 1254ULL: goto x86_l_4e6;
	case 1260ULL: goto x86_l_4ec;
	case 1265ULL: goto x86_l_4f1;
	case 1269ULL: goto x86_l_4f5;
	case 1272ULL: goto x86_l_4f8;
	case 1276ULL: goto x86_l_4fc;
	case 1282ULL: goto x86_l_502;
	case 1288ULL: goto x86_l_508;
	case 1293ULL: goto x86_l_50d;
	case 1297ULL: goto x86_l_511;
	case 1300ULL: goto x86_l_514;
	case 1304ULL: goto x86_l_518;
	case 1310ULL: goto x86_l_51e;
	case 1316ULL: goto x86_l_524;
	case 1321ULL: goto x86_l_529;
	case 1325ULL: goto x86_l_52d;
	case 1328ULL: goto x86_l_530;
	case 1332ULL: goto x86_l_534;
	case 1338ULL: goto x86_l_53a;
	case 1344ULL: goto x86_l_540;
	case 1349ULL: goto x86_l_545;
	case 1353ULL: goto x86_l_549;
	case 1356ULL: goto x86_l_54c;
	case 1360ULL: goto x86_l_550;
	case 1366ULL: goto x86_l_556;
	case 1372ULL: goto x86_l_55c;
	case 1377ULL: goto x86_l_561;
	case 1381ULL: goto x86_l_565;
	case 1384ULL: goto x86_l_568;
	case 1388ULL: goto x86_l_56c;
	case 1394ULL: goto x86_l_572;
	case 1400ULL: goto x86_l_578;
	case 1405ULL: goto x86_l_57d;
	case 1409ULL: goto x86_l_581;
	case 1412ULL: goto x86_l_584;
	case 1416ULL: goto x86_l_588;
	case 1422ULL: goto x86_l_58e;
	case 1428ULL: goto x86_l_594;
	case 1433ULL: goto x86_l_599;
	case 1437ULL: goto x86_l_59d;
	case 1440ULL: goto x86_l_5a0;
	case 1444ULL: goto x86_l_5a4;
	case 1450ULL: goto x86_l_5aa;
	case 1456ULL: goto x86_l_5b0;
	case 1461ULL: goto x86_l_5b5;
	case 1465ULL: goto x86_l_5b9;
	case 1468ULL: goto x86_l_5bc;
	case 1472ULL: goto x86_l_5c0;
	case 1478ULL: goto x86_l_5c6;
	case 1484ULL: goto x86_l_5cc;
	case 1489ULL: goto x86_l_5d1;
	case 1493ULL: goto x86_l_5d5;
	case 1496ULL: goto x86_l_5d8;
	case 1500ULL: goto x86_l_5dc;
	case 1506ULL: goto x86_l_5e2;
	case 1512ULL: goto x86_l_5e8;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1524ULL: goto x86_l_5f4;
	case 1528ULL: goto x86_l_5f8;
	case 1534ULL: goto x86_l_5fe;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1549ULL: goto x86_l_60d;
	case 1552ULL: goto x86_l_610;
	case 1556ULL: goto x86_l_614;
	case 1562ULL: goto x86_l_61a;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1577ULL: goto x86_l_629;
	case 1580ULL: goto x86_l_62c;
	case 1584ULL: goto x86_l_630;
	case 1590ULL: goto x86_l_636;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1605ULL: goto x86_l_645;
	case 1608ULL: goto x86_l_648;
	case 1612ULL: goto x86_l_64c;
	case 1618ULL: goto x86_l_652;
	case 1624ULL: goto x86_l_658;
	case 1629ULL: goto x86_l_65d;
	case 1633ULL: goto x86_l_661;
	case 1636ULL: goto x86_l_664;
	case 1640ULL: goto x86_l_668;
	case 1646ULL: goto x86_l_66e;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1661ULL: goto x86_l_67d;
	case 1664ULL: goto x86_l_680;
	case 1668ULL: goto x86_l_684;
	case 1674ULL: goto x86_l_68a;
	case 1680ULL: goto x86_l_690;
	case 1685ULL: goto x86_l_695;
	case 1689ULL: goto x86_l_699;
	case 1692ULL: goto x86_l_69c;
	case 1696ULL: goto x86_l_6a0;
	case 1702ULL: goto x86_l_6a6;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1717ULL: goto x86_l_6b5;
	case 1720ULL: goto x86_l_6b8;
	case 1724ULL: goto x86_l_6bc;
	case 1730ULL: goto x86_l_6c2;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
	case 1745ULL: goto x86_l_6d1;
	case 1748ULL: goto x86_l_6d4;
	case 1752ULL: goto x86_l_6d8;
	case 1758ULL: goto x86_l_6de;
	case 1764ULL: goto x86_l_6e4;
	case 1769ULL: goto x86_l_6e9;
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
	/* 0x18: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
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
	/* 0x31: je     37f7 <generic_fexit_filter_arg+0x37f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14327ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r15d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_41:
	/* 0x41: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_48:
	/* 0x48: mov    rdi,QWORD PTR [rip+0x0] */
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
	/* 0x59: je     37dc <generic_fexit_filter_arg+0x37dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14300ULL;
	}
x86_l_5f:
	/* 0x5f: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_67:
	/* 0x67: je     37dc <generic_fexit_filter_arg+0x37dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14300ULL;
	}
x86_l_6d:
	/* 0x6d: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_70:
	/* 0x70: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_73:
	/* 0x73: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_7c:
	/* 0x7c: je     3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14181ULL;
	}
x86_l_82:
	/* 0x82: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_84:
	/* 0x84: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_88:
	/* 0x88: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8c:
	/* 0x8c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_90:
	/* 0x90: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_92:
	/* 0x92: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_98:
	/* 0x98: cmp    DWORD PTR [rax+rbp*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 25ULL);
x86_l_9c:
	/* 0x9c: jb     375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14171ULL;
	}
x86_l_a2:
	/* 0xa2: mov    edx,DWORD PTR [rax+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_a6:
	/* 0xa6: test   edx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1023ULL);
x86_l_ac:
	/* 0xac: je     375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14171ULL;
	}
x86_l_b2:
	/* 0xb2: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b4:
	/* 0xb4: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ba:
	/* 0xba: mov    edx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_bd:
	/* 0xbd: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_c1:
	/* 0xc1: ja     3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14181ULL;
	}
x86_l_c7:
	/* 0xc7: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_d0:
	/* 0xd0: jne    3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14181ULL;
	}
x86_l_d6:
	/* 0xd6: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_d9:
	/* 0xd9: add    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dc:
	/* 0xdc: mov    eax,DWORD PTR [rax+rcx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 12ULL);
x86_l_e0:
	/* 0xe0: mov    rcx,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_e8:
	/* 0xe8: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ee:
	/* 0xee: lea    r8,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_f2:
	/* 0xf2: add    r8,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f9:
	/* 0xf9: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_fc:
	/* 0xfc: jg     128 <generic_fexit_filter_arg+0x128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_128;
	}
x86_l_fe:
	/* 0xfe: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_101:
	/* 0x101: jg     150 <generic_fexit_filter_arg+0x150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_150;
	}
x86_l_103:
	/* 0x103: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_106:
	/* 0x106: jle    cd2 <generic_fexit_filter_arg+0xcd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3282ULL;
	}
x86_l_10c:
	/* 0x10c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10f:
	/* 0x10f: je     1b2b <generic_fexit_filter_arg+0x1b2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6955ULL;
	}
x86_l_115:
	/* 0x115: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_118:
	/* 0x118: je     186 <generic_fexit_filter_arg+0x186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_186;
	}
x86_l_11a:
	/* 0x11a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_11d:
	/* 0x11d: je     1d9 <generic_fexit_filter_arg+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d9;
	}
x86_l_123:
	/* 0x123: jmp    375b <generic_fexit_filter_arg+0x375b> */
	return 14171ULL;
x86_l_128:
	/* 0x128: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_12b:
	/* 0x12b: jg     172 <generic_fexit_filter_arg+0x172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_172;
	}
x86_l_12d:
	/* 0x12d: lea    ecx,[rax-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_130:
	/* 0x130: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_133:
	/* 0x133: jb     1b2b <generic_fexit_filter_arg+0x1b2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6955ULL;
	}
x86_l_139:
	/* 0x139: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_13c:
	/* 0x13c: je     1d15 <generic_fexit_filter_arg+0x1d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7445ULL;
	}
x86_l_142:
	/* 0x142: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_145:
	/* 0x145: je     1b2b <generic_fexit_filter_arg+0x1b2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6955ULL;
	}
x86_l_14b:
	/* 0x14b: jmp    375b <generic_fexit_filter_arg+0x375b> */
	return 14171ULL;
x86_l_150:
	/* 0x150: lea    ecx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_153:
	/* 0x153: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_156:
	/* 0x156: jb     1b2b <generic_fexit_filter_arg+0x1b2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6955ULL;
	}
x86_l_15c:
	/* 0x15c: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_15f:
	/* 0x15f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_162:
	/* 0x162: jb     1d19 <generic_fexit_filter_arg+0x1d19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7449ULL;
	}
x86_l_168:
	/* 0x168: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_16b:
	/* 0x16b: je     186 <generic_fexit_filter_arg+0x186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_186;
	}
x86_l_16d:
	/* 0x16d: jmp    375b <generic_fexit_filter_arg+0x375b> */
	return 14171ULL;
x86_l_172:
	/* 0x172: lea    ecx,[rax-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_175:
	/* 0x175: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_178:
	/* 0x178: jb     1d9 <generic_fexit_filter_arg+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d9;
	}
x86_l_17a:
	/* 0x17a: lea    ecx,[rax-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_17d:
	/* 0x17d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_180:
	/* 0x180: jae    1c80 <generic_fexit_filter_arg+0x1c80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7296ULL;
	}
x86_l_186:
	/* 0x186: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_198:
	/* 0x198: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1a1:
	/* 0x1a1: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1aa:
	/* 0x1aa: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1b3:
	/* 0x1b3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6:
	/* 0x1b6: cmp    eax,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_1b9:
	/* 0x1b9: jg     1bc7 <generic_fexit_filter_arg+0x1bc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7111ULL;
	}
x86_l_1bf:
	/* 0x1bf: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1c2:
	/* 0x1c2: je     1e90 <generic_fexit_filter_arg+0x1e90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7824ULL;
	}
x86_l_1c8:
	/* 0x1c8: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1cb:
	/* 0x1cb: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1ce:
	/* 0x1ce: je     1e92 <generic_fexit_filter_arg+0x1e92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7826ULL;
	}
x86_l_1d4:
	/* 0x1d4: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_1d9:
	/* 0x1d9: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dd:
	/* 0x1dd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e0:
	/* 0x1e0: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1e3:
	/* 0x1e3: ja     373b <generic_fexit_filter_arg+0x373b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14139ULL;
	}
x86_l_1e9:
	/* 0x1e9: mov    edx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ec:
	/* 0x1ec: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1f0:
	/* 0x1f0: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1f5:
	/* 0x1f5: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1f8:
	/* 0x1f8: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc:
	/* 0x1fc: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_201:
	/* 0x201: jb     1e26 <generic_fexit_filter_arg+0x1e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7718ULL;
	}
x86_l_207:
	/* 0x207: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_20c:
	/* 0x20c: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_20f:
	/* 0x20f: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_214:
	/* 0x214: jb     1d8c <generic_fexit_filter_arg+0x1d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7564ULL;
	}
x86_l_21a:
	/* 0x21a: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_21f:
	/* 0x21f: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_222:
	/* 0x222: jae    373b <generic_fexit_filter_arg+0x373b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14139ULL;
	}
x86_l_228:
	/* 0x228: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22c:
	/* 0x22c: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_230:
	/* 0x230: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_238:
	/* 0x238: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_23f:
	/* 0x23f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_244:
	/* 0x244: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_249:
	/* 0x249: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b:
	/* 0x24b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24e:
	/* 0x24e: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_253:
	/* 0x253: je     3610 <generic_fexit_filter_arg+0x3610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13840ULL;
	}
x86_l_259:
	/* 0x259: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_25c:
	/* 0x25c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25f:
	/* 0x25f: je     3610 <generic_fexit_filter_arg+0x3610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13840ULL;
	}
x86_l_265:
	/* 0x265: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_26c:
	/* 0x26c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_271:
	/* 0x271: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_276:
	/* 0x276: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278:
	/* 0x278: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27b:
	/* 0x27b: je     360d <generic_fexit_filter_arg+0x360d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13837ULL;
	}
x86_l_281:
	/* 0x281: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_284:
	/* 0x284: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_288:
	/* 0x288: cmp    edx,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 94ULL);
x86_l_28b:
	/* 0x28b: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_290:
	/* 0x290: cmovb  eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_B);
x86_l_293:
	/* 0x293: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_296:
	/* 0x296: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_298:
	/* 0x298: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_29b:
	/* 0x29b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a0:
	/* 0x2a0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a5:
	/* 0x2a5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a9:
	/* 0x2a9: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ac:
	/* 0x2ac: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_2b0:
	/* 0x2b0: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_2b6:
	/* 0x2b6: lea    eax,[rdx+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_2bc:
	/* 0x2bc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c1:
	/* 0x2c1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c5:
	/* 0x2c5: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2c8:
	/* 0x2c8: cmp    rdx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 2ULL);
x86_l_2cc:
	/* 0x2cc: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_2d2:
	/* 0x2d2: lea    eax,[rdx+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_2d8:
	/* 0x2d8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2dd:
	/* 0x2dd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2e1:
	/* 0x2e1: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2e4:
	/* 0x2e4: cmp    rdx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 3ULL);
x86_l_2e8:
	/* 0x2e8: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_2ee:
	/* 0x2ee: lea    eax,[rdx+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_2f4:
	/* 0x2f4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f9:
	/* 0x2f9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2fd:
	/* 0x2fd: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_300:
	/* 0x300: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_304:
	/* 0x304: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_30a:
	/* 0x30a: lea    eax,[rdx+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_310:
	/* 0x310: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_315:
	/* 0x315: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_319:
	/* 0x319: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c:
	/* 0x31c: cmp    rdx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 5ULL);
x86_l_320:
	/* 0x320: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_326:
	/* 0x326: lea    eax,[rdx+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_32c:
	/* 0x32c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_331:
	/* 0x331: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_335:
	/* 0x335: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_338:
	/* 0x338: cmp    rdx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 6ULL);
x86_l_33c:
	/* 0x33c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_342:
	/* 0x342: lea    eax,[rdx+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_348:
	/* 0x348: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_34d:
	/* 0x34d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_351:
	/* 0x351: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_354:
	/* 0x354: cmp    rdx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 7ULL);
x86_l_358:
	/* 0x358: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_35e:
	/* 0x35e: lea    eax,[rdx+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_364:
	/* 0x364: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_369:
	/* 0x369: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_36d:
	/* 0x36d: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_370:
	/* 0x370: cmp    rdx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 8ULL);
x86_l_374:
	/* 0x374: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_37a:
	/* 0x37a: lea    eax,[rdx+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_380:
	/* 0x380: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_385:
	/* 0x385: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_389:
	/* 0x389: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_38c:
	/* 0x38c: cmp    rdx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 9ULL);
x86_l_390:
	/* 0x390: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_396:
	/* 0x396: lea    eax,[rdx+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_39c:
	/* 0x39c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3a1:
	/* 0x3a1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3a5:
	/* 0x3a5: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_3a8:
	/* 0x3a8: cmp    rdx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 10ULL);
x86_l_3ac:
	/* 0x3ac: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_3b2:
	/* 0x3b2: lea    eax,[rdx+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_3b8:
	/* 0x3b8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3bd:
	/* 0x3bd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3c1:
	/* 0x3c1: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_3c4:
	/* 0x3c4: cmp    rdx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 11ULL);
x86_l_3c8:
	/* 0x3c8: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_3ce:
	/* 0x3ce: lea    eax,[rdx+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_3d4:
	/* 0x3d4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3d9:
	/* 0x3d9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3dd:
	/* 0x3dd: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_3e0:
	/* 0x3e0: cmp    rdx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 12ULL);
x86_l_3e4:
	/* 0x3e4: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_3ea:
	/* 0x3ea: lea    eax,[rdx+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_3f0:
	/* 0x3f0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f5:
	/* 0x3f5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3f9:
	/* 0x3f9: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fc:
	/* 0x3fc: cmp    rdx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 13ULL);
x86_l_400:
	/* 0x400: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_406:
	/* 0x406: lea    eax,[rdx+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_40c:
	/* 0x40c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_411:
	/* 0x411: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_415:
	/* 0x415: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_418:
	/* 0x418: cmp    rdx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 14ULL);
x86_l_41c:
	/* 0x41c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_422:
	/* 0x422: lea    eax,[rdx+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_428:
	/* 0x428: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_42d:
	/* 0x42d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_431:
	/* 0x431: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_434:
	/* 0x434: cmp    rdx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 15ULL);
x86_l_438:
	/* 0x438: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_43e:
	/* 0x43e: lea    eax,[rdx+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_444:
	/* 0x444: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_449:
	/* 0x449: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_44d:
	/* 0x44d: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_450:
	/* 0x450: cmp    rdx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 16ULL);
x86_l_454:
	/* 0x454: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_45a:
	/* 0x45a: lea    eax,[rdx+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_460:
	/* 0x460: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_465:
	/* 0x465: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_469:
	/* 0x469: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_46c:
	/* 0x46c: cmp    rdx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 17ULL);
x86_l_470:
	/* 0x470: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_476:
	/* 0x476: lea    eax,[rdx+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_47c:
	/* 0x47c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_481:
	/* 0x481: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_485:
	/* 0x485: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_488:
	/* 0x488: cmp    rdx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18ULL);
x86_l_48c:
	/* 0x48c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_492:
	/* 0x492: lea    eax,[rdx+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_498:
	/* 0x498: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_49d:
	/* 0x49d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4a1:
	/* 0x4a1: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_4a4:
	/* 0x4a4: cmp    rdx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 19ULL);
x86_l_4a8:
	/* 0x4a8: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_4ae:
	/* 0x4ae: lea    eax,[rdx+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_4b4:
	/* 0x4b4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4b9:
	/* 0x4b9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4bd:
	/* 0x4bd: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_4c0:
	/* 0x4c0: cmp    rdx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 20ULL);
x86_l_4c4:
	/* 0x4c4: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_4ca:
	/* 0x4ca: lea    eax,[rdx+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_4d0:
	/* 0x4d0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4d5:
	/* 0x4d5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4d9:
	/* 0x4d9: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4dc:
	/* 0x4dc: cmp    rdx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 21ULL);
x86_l_4e0:
	/* 0x4e0: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_4e6:
	/* 0x4e6: lea    eax,[rdx+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_4ec:
	/* 0x4ec: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4f1:
	/* 0x4f1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4f5:
	/* 0x4f5: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_4f8:
	/* 0x4f8: cmp    rdx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 22ULL);
x86_l_4fc:
	/* 0x4fc: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_502:
	/* 0x502: lea    eax,[rdx+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_508:
	/* 0x508: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_50d:
	/* 0x50d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_511:
	/* 0x511: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_514:
	/* 0x514: cmp    rdx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 23ULL);
x86_l_518:
	/* 0x518: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_51e:
	/* 0x51e: lea    eax,[rdx+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_524:
	/* 0x524: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_529:
	/* 0x529: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_52d:
	/* 0x52d: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_530:
	/* 0x530: cmp    rdx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 24ULL);
x86_l_534:
	/* 0x534: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_53a:
	/* 0x53a: lea    eax,[rdx+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_540:
	/* 0x540: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_545:
	/* 0x545: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_549:
	/* 0x549: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_54c:
	/* 0x54c: cmp    rdx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 25ULL);
x86_l_550:
	/* 0x550: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_556:
	/* 0x556: lea    eax,[rdx+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_55c:
	/* 0x55c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_561:
	/* 0x561: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_565:
	/* 0x565: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_568:
	/* 0x568: cmp    rdx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 26ULL);
x86_l_56c:
	/* 0x56c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_572:
	/* 0x572: lea    eax,[rdx+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_578:
	/* 0x578: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_57d:
	/* 0x57d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_581:
	/* 0x581: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_584:
	/* 0x584: cmp    rdx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 27ULL);
x86_l_588:
	/* 0x588: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_58e:
	/* 0x58e: lea    eax,[rdx+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_594:
	/* 0x594: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_599:
	/* 0x599: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_59d:
	/* 0x59d: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_5a0:
	/* 0x5a0: cmp    rdx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 28ULL);
x86_l_5a4:
	/* 0x5a4: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_5aa:
	/* 0x5aa: lea    eax,[rdx+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_5b0:
	/* 0x5b0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b5:
	/* 0x5b5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5b9:
	/* 0x5b9: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5bc:
	/* 0x5bc: cmp    rdx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 29ULL);
x86_l_5c0:
	/* 0x5c0: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_5c6:
	/* 0x5c6: lea    eax,[rdx+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_5cc:
	/* 0x5cc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d1:
	/* 0x5d1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5d5:
	/* 0x5d5: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_5d8:
	/* 0x5d8: cmp    rdx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 30ULL);
x86_l_5dc:
	/* 0x5dc: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_5e2:
	/* 0x5e2: lea    eax,[rdx+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_5e8:
	/* 0x5e8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ed:
	/* 0x5ed: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5f1:
	/* 0x5f1: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_5f4:
	/* 0x5f4: cmp    rdx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 31ULL);
x86_l_5f8:
	/* 0x5f8: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_5fe:
	/* 0x5fe: lea    eax,[rdx+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_604:
	/* 0x604: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_609:
	/* 0x609: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_60d:
	/* 0x60d: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_610:
	/* 0x610: cmp    rdx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 32ULL);
x86_l_614:
	/* 0x614: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_61a:
	/* 0x61a: lea    eax,[rdx+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_620:
	/* 0x620: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_625:
	/* 0x625: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_629:
	/* 0x629: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_62c:
	/* 0x62c: cmp    rdx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 33ULL);
x86_l_630:
	/* 0x630: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_636:
	/* 0x636: lea    eax,[rdx+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_63c:
	/* 0x63c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_641:
	/* 0x641: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_645:
	/* 0x645: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_648:
	/* 0x648: cmp    rdx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 34ULL);
x86_l_64c:
	/* 0x64c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_652:
	/* 0x652: lea    eax,[rdx+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_658:
	/* 0x658: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_65d:
	/* 0x65d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_661:
	/* 0x661: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_664:
	/* 0x664: cmp    rdx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 35ULL);
x86_l_668:
	/* 0x668: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_66e:
	/* 0x66e: lea    eax,[rdx+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_674:
	/* 0x674: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_679:
	/* 0x679: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_67d:
	/* 0x67d: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_680:
	/* 0x680: cmp    rdx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 36ULL);
x86_l_684:
	/* 0x684: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_68a:
	/* 0x68a: lea    eax,[rdx+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_690:
	/* 0x690: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_695:
	/* 0x695: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_699:
	/* 0x699: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69c:
	/* 0x69c: cmp    rdx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 37ULL);
x86_l_6a0:
	/* 0x6a0: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_6a6:
	/* 0x6a6: lea    eax,[rdx+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_6ac:
	/* 0x6ac: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6b1:
	/* 0x6b1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6b5:
	/* 0x6b5: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_6b8:
	/* 0x6b8: cmp    rdx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 38ULL);
x86_l_6bc:
	/* 0x6bc: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_6c2:
	/* 0x6c2: lea    eax,[rdx+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_6c8:
	/* 0x6c8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6cd:
	/* 0x6cd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6d1:
	/* 0x6d1: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_6d4:
	/* 0x6d4: cmp    rdx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 39ULL);
x86_l_6d8:
	/* 0x6d8: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_6de:
	/* 0x6de: lea    eax,[rdx+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_6e4:
	/* 0x6e4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6e9:
	/* 0x6e9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
	return 1773ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1773ULL: goto x86_l_6ed;
	case 1776ULL: goto x86_l_6f0;
	case 1780ULL: goto x86_l_6f4;
	case 1786ULL: goto x86_l_6fa;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1801ULL: goto x86_l_709;
	case 1804ULL: goto x86_l_70c;
	case 1808ULL: goto x86_l_710;
	case 1814ULL: goto x86_l_716;
	case 1820ULL: goto x86_l_71c;
	case 1825ULL: goto x86_l_721;
	case 1829ULL: goto x86_l_725;
	case 1832ULL: goto x86_l_728;
	case 1836ULL: goto x86_l_72c;
	case 1842ULL: goto x86_l_732;
	case 1848ULL: goto x86_l_738;
	case 1853ULL: goto x86_l_73d;
	case 1857ULL: goto x86_l_741;
	case 1860ULL: goto x86_l_744;
	case 1864ULL: goto x86_l_748;
	case 1870ULL: goto x86_l_74e;
	case 1876ULL: goto x86_l_754;
	case 1881ULL: goto x86_l_759;
	case 1885ULL: goto x86_l_75d;
	case 1888ULL: goto x86_l_760;
	case 1892ULL: goto x86_l_764;
	case 1898ULL: goto x86_l_76a;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1913ULL: goto x86_l_779;
	case 1916ULL: goto x86_l_77c;
	case 1920ULL: goto x86_l_780;
	case 1926ULL: goto x86_l_786;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1941ULL: goto x86_l_795;
	case 1944ULL: goto x86_l_798;
	case 1948ULL: goto x86_l_79c;
	case 1954ULL: goto x86_l_7a2;
	case 1960ULL: goto x86_l_7a8;
	case 1965ULL: goto x86_l_7ad;
	case 1969ULL: goto x86_l_7b1;
	case 1972ULL: goto x86_l_7b4;
	case 1976ULL: goto x86_l_7b8;
	case 1982ULL: goto x86_l_7be;
	case 1988ULL: goto x86_l_7c4;
	case 1993ULL: goto x86_l_7c9;
	case 1997ULL: goto x86_l_7cd;
	case 2000ULL: goto x86_l_7d0;
	case 2004ULL: goto x86_l_7d4;
	case 2010ULL: goto x86_l_7da;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2025ULL: goto x86_l_7e9;
	case 2028ULL: goto x86_l_7ec;
	case 2032ULL: goto x86_l_7f0;
	case 2038ULL: goto x86_l_7f6;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2053ULL: goto x86_l_805;
	case 2056ULL: goto x86_l_808;
	case 2060ULL: goto x86_l_80c;
	case 2066ULL: goto x86_l_812;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2081ULL: goto x86_l_821;
	case 2084ULL: goto x86_l_824;
	case 2088ULL: goto x86_l_828;
	case 2094ULL: goto x86_l_82e;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2109ULL: goto x86_l_83d;
	case 2112ULL: goto x86_l_840;
	case 2116ULL: goto x86_l_844;
	case 2122ULL: goto x86_l_84a;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2137ULL: goto x86_l_859;
	case 2140ULL: goto x86_l_85c;
	case 2144ULL: goto x86_l_860;
	case 2150ULL: goto x86_l_866;
	case 2156ULL: goto x86_l_86c;
	case 2161ULL: goto x86_l_871;
	case 2165ULL: goto x86_l_875;
	case 2168ULL: goto x86_l_878;
	case 2172ULL: goto x86_l_87c;
	case 2178ULL: goto x86_l_882;
	case 2184ULL: goto x86_l_888;
	case 2189ULL: goto x86_l_88d;
	case 2193ULL: goto x86_l_891;
	case 2196ULL: goto x86_l_894;
	case 2200ULL: goto x86_l_898;
	case 2206ULL: goto x86_l_89e;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2221ULL: goto x86_l_8ad;
	case 2224ULL: goto x86_l_8b0;
	case 2228ULL: goto x86_l_8b4;
	case 2234ULL: goto x86_l_8ba;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2249ULL: goto x86_l_8c9;
	case 2252ULL: goto x86_l_8cc;
	case 2256ULL: goto x86_l_8d0;
	case 2262ULL: goto x86_l_8d6;
	case 2268ULL: goto x86_l_8dc;
	case 2273ULL: goto x86_l_8e1;
	case 2277ULL: goto x86_l_8e5;
	case 2280ULL: goto x86_l_8e8;
	case 2284ULL: goto x86_l_8ec;
	case 2290ULL: goto x86_l_8f2;
	case 2296ULL: goto x86_l_8f8;
	case 2301ULL: goto x86_l_8fd;
	case 2305ULL: goto x86_l_901;
	case 2308ULL: goto x86_l_904;
	case 2312ULL: goto x86_l_908;
	case 2318ULL: goto x86_l_90e;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2333ULL: goto x86_l_91d;
	case 2336ULL: goto x86_l_920;
	case 2340ULL: goto x86_l_924;
	case 2346ULL: goto x86_l_92a;
	case 2352ULL: goto x86_l_930;
	case 2357ULL: goto x86_l_935;
	case 2361ULL: goto x86_l_939;
	case 2364ULL: goto x86_l_93c;
	case 2368ULL: goto x86_l_940;
	case 2374ULL: goto x86_l_946;
	case 2380ULL: goto x86_l_94c;
	case 2385ULL: goto x86_l_951;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2396ULL: goto x86_l_95c;
	case 2402ULL: goto x86_l_962;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2417ULL: goto x86_l_971;
	case 2420ULL: goto x86_l_974;
	case 2424ULL: goto x86_l_978;
	case 2430ULL: goto x86_l_97e;
	case 2436ULL: goto x86_l_984;
	case 2441ULL: goto x86_l_989;
	case 2445ULL: goto x86_l_98d;
	case 2448ULL: goto x86_l_990;
	case 2452ULL: goto x86_l_994;
	case 2458ULL: goto x86_l_99a;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2473ULL: goto x86_l_9a9;
	case 2476ULL: goto x86_l_9ac;
	case 2480ULL: goto x86_l_9b0;
	case 2486ULL: goto x86_l_9b6;
	case 2492ULL: goto x86_l_9bc;
	case 2497ULL: goto x86_l_9c1;
	case 2501ULL: goto x86_l_9c5;
	case 2504ULL: goto x86_l_9c8;
	case 2508ULL: goto x86_l_9cc;
	case 2514ULL: goto x86_l_9d2;
	case 2520ULL: goto x86_l_9d8;
	case 2525ULL: goto x86_l_9dd;
	case 2529ULL: goto x86_l_9e1;
	case 2532ULL: goto x86_l_9e4;
	case 2536ULL: goto x86_l_9e8;
	case 2542ULL: goto x86_l_9ee;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2557ULL: goto x86_l_9fd;
	case 2560ULL: goto x86_l_a00;
	case 2564ULL: goto x86_l_a04;
	case 2570ULL: goto x86_l_a0a;
	case 2576ULL: goto x86_l_a10;
	case 2581ULL: goto x86_l_a15;
	case 2585ULL: goto x86_l_a19;
	case 2588ULL: goto x86_l_a1c;
	case 2592ULL: goto x86_l_a20;
	case 2598ULL: goto x86_l_a26;
	case 2604ULL: goto x86_l_a2c;
	case 2609ULL: goto x86_l_a31;
	case 2613ULL: goto x86_l_a35;
	case 2616ULL: goto x86_l_a38;
	case 2620ULL: goto x86_l_a3c;
	case 2626ULL: goto x86_l_a42;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2641ULL: goto x86_l_a51;
	case 2644ULL: goto x86_l_a54;
	case 2648ULL: goto x86_l_a58;
	case 2654ULL: goto x86_l_a5e;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2669ULL: goto x86_l_a6d;
	case 2672ULL: goto x86_l_a70;
	case 2676ULL: goto x86_l_a74;
	case 2682ULL: goto x86_l_a7a;
	case 2688ULL: goto x86_l_a80;
	case 2693ULL: goto x86_l_a85;
	case 2697ULL: goto x86_l_a89;
	case 2700ULL: goto x86_l_a8c;
	case 2704ULL: goto x86_l_a90;
	case 2710ULL: goto x86_l_a96;
	case 2716ULL: goto x86_l_a9c;
	case 2721ULL: goto x86_l_aa1;
	case 2725ULL: goto x86_l_aa5;
	case 2728ULL: goto x86_l_aa8;
	case 2732ULL: goto x86_l_aac;
	case 2738ULL: goto x86_l_ab2;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2753ULL: goto x86_l_ac1;
	case 2756ULL: goto x86_l_ac4;
	case 2760ULL: goto x86_l_ac8;
	case 2766ULL: goto x86_l_ace;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2781ULL: goto x86_l_add;
	case 2784ULL: goto x86_l_ae0;
	case 2788ULL: goto x86_l_ae4;
	case 2794ULL: goto x86_l_aea;
	case 2800ULL: goto x86_l_af0;
	case 2805ULL: goto x86_l_af5;
	case 2809ULL: goto x86_l_af9;
	case 2812ULL: goto x86_l_afc;
	case 2816ULL: goto x86_l_b00;
	case 2822ULL: goto x86_l_b06;
	case 2828ULL: goto x86_l_b0c;
	case 2833ULL: goto x86_l_b11;
	case 2837ULL: goto x86_l_b15;
	case 2840ULL: goto x86_l_b18;
	case 2844ULL: goto x86_l_b1c;
	case 2850ULL: goto x86_l_b22;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2865ULL: goto x86_l_b31;
	case 2868ULL: goto x86_l_b34;
	case 2872ULL: goto x86_l_b38;
	case 2878ULL: goto x86_l_b3e;
	case 2884ULL: goto x86_l_b44;
	case 2889ULL: goto x86_l_b49;
	case 2893ULL: goto x86_l_b4d;
	case 2896ULL: goto x86_l_b50;
	case 2900ULL: goto x86_l_b54;
	case 2906ULL: goto x86_l_b5a;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2921ULL: goto x86_l_b69;
	case 2924ULL: goto x86_l_b6c;
	case 2928ULL: goto x86_l_b70;
	case 2934ULL: goto x86_l_b76;
	case 2940ULL: goto x86_l_b7c;
	case 2945ULL: goto x86_l_b81;
	case 2949ULL: goto x86_l_b85;
	case 2952ULL: goto x86_l_b88;
	case 2956ULL: goto x86_l_b8c;
	case 2962ULL: goto x86_l_b92;
	case 2968ULL: goto x86_l_b98;
	case 2973ULL: goto x86_l_b9d;
	case 2977ULL: goto x86_l_ba1;
	case 2980ULL: goto x86_l_ba4;
	case 2984ULL: goto x86_l_ba8;
	case 2990ULL: goto x86_l_bae;
	case 2996ULL: goto x86_l_bb4;
	case 3001ULL: goto x86_l_bb9;
	case 3005ULL: goto x86_l_bbd;
	case 3008ULL: goto x86_l_bc0;
	case 3012ULL: goto x86_l_bc4;
	case 3018ULL: goto x86_l_bca;
	case 3024ULL: goto x86_l_bd0;
	case 3029ULL: goto x86_l_bd5;
	case 3033ULL: goto x86_l_bd9;
	case 3036ULL: goto x86_l_bdc;
	case 3040ULL: goto x86_l_be0;
	case 3046ULL: goto x86_l_be6;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3061ULL: goto x86_l_bf5;
	case 3064ULL: goto x86_l_bf8;
	case 3068ULL: goto x86_l_bfc;
	case 3074ULL: goto x86_l_c02;
	case 3080ULL: goto x86_l_c08;
	case 3085ULL: goto x86_l_c0d;
	case 3089ULL: goto x86_l_c11;
	case 3092ULL: goto x86_l_c14;
	case 3096ULL: goto x86_l_c18;
	case 3102ULL: goto x86_l_c1e;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3117ULL: goto x86_l_c2d;
	case 3120ULL: goto x86_l_c30;
	case 3124ULL: goto x86_l_c34;
	case 3130ULL: goto x86_l_c3a;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3145ULL: goto x86_l_c49;
	case 3148ULL: goto x86_l_c4c;
	case 3152ULL: goto x86_l_c50;
	case 3154ULL: goto x86_l_c52;
	case 3160ULL: goto x86_l_c58;
	case 3165ULL: goto x86_l_c5d;
	case 3169ULL: goto x86_l_c61;
	case 3172ULL: goto x86_l_c64;
	case 3176ULL: goto x86_l_c68;
	case 3178ULL: goto x86_l_c6a;
	case 3184ULL: goto x86_l_c70;
	case 3189ULL: goto x86_l_c75;
	case 3193ULL: goto x86_l_c79;
	case 3196ULL: goto x86_l_c7c;
	case 3200ULL: goto x86_l_c80;
	case 3202ULL: goto x86_l_c82;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3217ULL: goto x86_l_c91;
	case 3220ULL: goto x86_l_c94;
	case 3224ULL: goto x86_l_c98;
	case 3226ULL: goto x86_l_c9a;
	case 3232ULL: goto x86_l_ca0;
	case 3237ULL: goto x86_l_ca5;
	case 3241ULL: goto x86_l_ca9;
	case 3244ULL: goto x86_l_cac;
	case 3248ULL: goto x86_l_cb0;
	case 3250ULL: goto x86_l_cb2;
	case 3256ULL: goto x86_l_cb8;
	case 3262ULL: goto x86_l_cbe;
	case 3266ULL: goto x86_l_cc2;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3285ULL: goto x86_l_cd5;
	case 3291ULL: goto x86_l_cdb;
	case 3294ULL: goto x86_l_cde;
	case 3300ULL: goto x86_l_ce4;
	case 3304ULL: goto x86_l_ce8;
	case 3307ULL: goto x86_l_ceb;
	case 3310ULL: goto x86_l_cee;
	case 3316ULL: goto x86_l_cf4;
	case 3320ULL: goto x86_l_cf8;
	case 3324ULL: goto x86_l_cfc;
	case 3329ULL: goto x86_l_d01;
	case 3332ULL: goto x86_l_d04;
	case 3336ULL: goto x86_l_d08;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3350ULL: goto x86_l_d16;
	case 3355ULL: goto x86_l_d1b;
	case 3361ULL: goto x86_l_d21;
	case 3366ULL: goto x86_l_d26;
	case 3369ULL: goto x86_l_d29;
	case 3375ULL: goto x86_l_d2f;
	case 3380ULL: goto x86_l_d34;
	case 3384ULL: goto x86_l_d38;
	case 3388ULL: goto x86_l_d3c;
	case 3396ULL: goto x86_l_d44;
	case 3403ULL: goto x86_l_d4b;
	case 3408ULL: goto x86_l_d50;
	case 3413ULL: goto x86_l_d55;
	case 3415ULL: goto x86_l_d57;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3429ULL: goto x86_l_d65;
	case 3432ULL: goto x86_l_d68;
	case 3435ULL: goto x86_l_d6b;
	case 3441ULL: goto x86_l_d71;
	case 3448ULL: goto x86_l_d78;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3460ULL: goto x86_l_d84;
	case 3463ULL: goto x86_l_d87;
	case 3469ULL: goto x86_l_d8d;
	case 3472ULL: goto x86_l_d90;
	case 3476ULL: goto x86_l_d94;
	case 3479ULL: goto x86_l_d97;
	case 3484ULL: goto x86_l_d9c;
	case 3487ULL: goto x86_l_d9f;
	case 3490ULL: goto x86_l_da2;
	case 3492ULL: goto x86_l_da4;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3505ULL: goto x86_l_db1;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3516ULL: goto x86_l_dbc;
	case 3522ULL: goto x86_l_dc2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6ed:
	/* 0x6ed: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_6f0:
	/* 0x6f0: cmp    rdx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 40ULL);
x86_l_6f4:
	/* 0x6f4: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_6fa:
	/* 0x6fa: lea    eax,[rdx+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_700:
	/* 0x700: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_705:
	/* 0x705: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_709:
	/* 0x709: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_70c:
	/* 0x70c: cmp    rdx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 41ULL);
x86_l_710:
	/* 0x710: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_716:
	/* 0x716: lea    eax,[rdx+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_71c:
	/* 0x71c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_721:
	/* 0x721: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_725:
	/* 0x725: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_728:
	/* 0x728: cmp    rdx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 42ULL);
x86_l_72c:
	/* 0x72c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_732:
	/* 0x732: lea    eax,[rdx+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_738:
	/* 0x738: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_73d:
	/* 0x73d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_741:
	/* 0x741: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_744:
	/* 0x744: cmp    rdx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 43ULL);
x86_l_748:
	/* 0x748: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_74e:
	/* 0x74e: lea    eax,[rdx+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_754:
	/* 0x754: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_759:
	/* 0x759: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_75d:
	/* 0x75d: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_760:
	/* 0x760: cmp    rdx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 44ULL);
x86_l_764:
	/* 0x764: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_76a:
	/* 0x76a: lea    eax,[rdx+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_770:
	/* 0x770: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_775:
	/* 0x775: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_779:
	/* 0x779: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_77c:
	/* 0x77c: cmp    rdx,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 45ULL);
x86_l_780:
	/* 0x780: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_786:
	/* 0x786: lea    eax,[rdx+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_78c:
	/* 0x78c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_791:
	/* 0x791: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_795:
	/* 0x795: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_798:
	/* 0x798: cmp    rdx,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 46ULL);
x86_l_79c:
	/* 0x79c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_7a2:
	/* 0x7a2: lea    eax,[rdx+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_7a8:
	/* 0x7a8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7ad:
	/* 0x7ad: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7b1:
	/* 0x7b1: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_7b4:
	/* 0x7b4: cmp    rdx,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 47ULL);
x86_l_7b8:
	/* 0x7b8: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_7be:
	/* 0x7be: lea    eax,[rdx+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_7c4:
	/* 0x7c4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7c9:
	/* 0x7c9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7cd:
	/* 0x7cd: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_7d0:
	/* 0x7d0: cmp    rdx,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 48ULL);
x86_l_7d4:
	/* 0x7d4: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_7da:
	/* 0x7da: lea    eax,[rdx+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_7e0:
	/* 0x7e0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7e5:
	/* 0x7e5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7e9:
	/* 0x7e9: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_7ec:
	/* 0x7ec: cmp    rdx,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 49ULL);
x86_l_7f0:
	/* 0x7f0: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_7f6:
	/* 0x7f6: lea    eax,[rdx+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_7fc:
	/* 0x7fc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_801:
	/* 0x801: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_805:
	/* 0x805: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_808:
	/* 0x808: cmp    rdx,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 50ULL);
x86_l_80c:
	/* 0x80c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_812:
	/* 0x812: lea    eax,[rdx+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_818:
	/* 0x818: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_81d:
	/* 0x81d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_821:
	/* 0x821: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_824:
	/* 0x824: cmp    rdx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 51ULL);
x86_l_828:
	/* 0x828: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_82e:
	/* 0x82e: lea    eax,[rdx+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_834:
	/* 0x834: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_839:
	/* 0x839: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_83d:
	/* 0x83d: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_840:
	/* 0x840: cmp    rdx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 52ULL);
x86_l_844:
	/* 0x844: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_84a:
	/* 0x84a: lea    eax,[rdx+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_850:
	/* 0x850: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_855:
	/* 0x855: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_859:
	/* 0x859: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_85c:
	/* 0x85c: cmp    rdx,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 53ULL);
x86_l_860:
	/* 0x860: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_866:
	/* 0x866: lea    eax,[rdx+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_86c:
	/* 0x86c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_871:
	/* 0x871: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_875:
	/* 0x875: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_878:
	/* 0x878: cmp    rdx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 54ULL);
x86_l_87c:
	/* 0x87c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_882:
	/* 0x882: lea    eax,[rdx+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_888:
	/* 0x888: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_88d:
	/* 0x88d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_891:
	/* 0x891: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_894:
	/* 0x894: cmp    rdx,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 55ULL);
x86_l_898:
	/* 0x898: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_89e:
	/* 0x89e: lea    eax,[rdx+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_8a4:
	/* 0x8a4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8a9:
	/* 0x8a9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8ad:
	/* 0x8ad: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_8b0:
	/* 0x8b0: cmp    rdx,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 56ULL);
x86_l_8b4:
	/* 0x8b4: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_8ba:
	/* 0x8ba: lea    eax,[rdx+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_8c0:
	/* 0x8c0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8c5:
	/* 0x8c5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8c9:
	/* 0x8c9: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_8cc:
	/* 0x8cc: cmp    rdx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 57ULL);
x86_l_8d0:
	/* 0x8d0: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_8d6:
	/* 0x8d6: lea    eax,[rdx+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_8dc:
	/* 0x8dc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8e1:
	/* 0x8e1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8e5:
	/* 0x8e5: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_8e8:
	/* 0x8e8: cmp    rdx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 58ULL);
x86_l_8ec:
	/* 0x8ec: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_8f2:
	/* 0x8f2: lea    eax,[rdx+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_8f8:
	/* 0x8f8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8fd:
	/* 0x8fd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_901:
	/* 0x901: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_904:
	/* 0x904: cmp    rdx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 59ULL);
x86_l_908:
	/* 0x908: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_90e:
	/* 0x90e: lea    eax,[rdx+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_914:
	/* 0x914: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_919:
	/* 0x919: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_91d:
	/* 0x91d: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_920:
	/* 0x920: cmp    rdx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 60ULL);
x86_l_924:
	/* 0x924: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_92a:
	/* 0x92a: lea    eax,[rdx+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_930:
	/* 0x930: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_935:
	/* 0x935: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_939:
	/* 0x939: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_93c:
	/* 0x93c: cmp    rdx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 61ULL);
x86_l_940:
	/* 0x940: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_946:
	/* 0x946: lea    eax,[rdx+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_94c:
	/* 0x94c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_951:
	/* 0x951: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_955:
	/* 0x955: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_958:
	/* 0x958: cmp    rdx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 62ULL);
x86_l_95c:
	/* 0x95c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_962:
	/* 0x962: lea    eax,[rdx+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_968:
	/* 0x968: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_96d:
	/* 0x96d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_971:
	/* 0x971: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_974:
	/* 0x974: cmp    rdx,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 63ULL);
x86_l_978:
	/* 0x978: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_97e:
	/* 0x97e: lea    eax,[rdx+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_984:
	/* 0x984: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_989:
	/* 0x989: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_98d:
	/* 0x98d: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_990:
	/* 0x990: cmp    rdx,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 64ULL);
x86_l_994:
	/* 0x994: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_99a:
	/* 0x99a: lea    eax,[rdx+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_9a0:
	/* 0x9a0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9a5:
	/* 0x9a5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9a9:
	/* 0x9a9: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_9ac:
	/* 0x9ac: cmp    rdx,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 65ULL);
x86_l_9b0:
	/* 0x9b0: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_9b6:
	/* 0x9b6: lea    eax,[rdx+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_9bc:
	/* 0x9bc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9c1:
	/* 0x9c1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9c5:
	/* 0x9c5: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_9c8:
	/* 0x9c8: cmp    rdx,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 66ULL);
x86_l_9cc:
	/* 0x9cc: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_9d2:
	/* 0x9d2: lea    eax,[rdx+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_9d8:
	/* 0x9d8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9dd:
	/* 0x9dd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9e1:
	/* 0x9e1: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_9e4:
	/* 0x9e4: cmp    rdx,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 67ULL);
x86_l_9e8:
	/* 0x9e8: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_9ee:
	/* 0x9ee: lea    eax,[rdx+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_9f4:
	/* 0x9f4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9f9:
	/* 0x9f9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9fd:
	/* 0x9fd: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_a00:
	/* 0xa00: cmp    rdx,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 68ULL);
x86_l_a04:
	/* 0xa04: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a0a:
	/* 0xa0a: lea    eax,[rdx+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_a10:
	/* 0xa10: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a15:
	/* 0xa15: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a19:
	/* 0xa19: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a1c:
	/* 0xa1c: cmp    rdx,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 69ULL);
x86_l_a20:
	/* 0xa20: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a26:
	/* 0xa26: lea    eax,[rdx+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_a2c:
	/* 0xa2c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a31:
	/* 0xa31: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a35:
	/* 0xa35: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_a38:
	/* 0xa38: cmp    rdx,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 70ULL);
x86_l_a3c:
	/* 0xa3c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a42:
	/* 0xa42: lea    eax,[rdx+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_a48:
	/* 0xa48: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a4d:
	/* 0xa4d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a51:
	/* 0xa51: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_a54:
	/* 0xa54: cmp    rdx,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 71ULL);
x86_l_a58:
	/* 0xa58: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a5e:
	/* 0xa5e: lea    eax,[rdx+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_a64:
	/* 0xa64: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a69:
	/* 0xa69: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a6d:
	/* 0xa6d: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_a70:
	/* 0xa70: cmp    rdx,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 72ULL);
x86_l_a74:
	/* 0xa74: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a7a:
	/* 0xa7a: lea    eax,[rdx+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_a80:
	/* 0xa80: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a85:
	/* 0xa85: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a89:
	/* 0xa89: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_a8c:
	/* 0xa8c: cmp    rdx,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 73ULL);
x86_l_a90:
	/* 0xa90: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a96:
	/* 0xa96: lea    eax,[rdx+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_a9c:
	/* 0xa9c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aa1:
	/* 0xaa1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_aa5:
	/* 0xaa5: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_aa8:
	/* 0xaa8: cmp    rdx,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 74ULL);
x86_l_aac:
	/* 0xaac: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_ab2:
	/* 0xab2: lea    eax,[rdx+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_ab8:
	/* 0xab8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_abd:
	/* 0xabd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ac1:
	/* 0xac1: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_ac4:
	/* 0xac4: cmp    rdx,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 75ULL);
x86_l_ac8:
	/* 0xac8: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_ace:
	/* 0xace: lea    eax,[rdx+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_ad4:
	/* 0xad4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ad9:
	/* 0xad9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_add:
	/* 0xadd: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_ae0:
	/* 0xae0: cmp    rdx,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 76ULL);
x86_l_ae4:
	/* 0xae4: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_aea:
	/* 0xaea: lea    eax,[rdx+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_af0:
	/* 0xaf0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_af5:
	/* 0xaf5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_af9:
	/* 0xaf9: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_afc:
	/* 0xafc: cmp    rdx,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 77ULL);
x86_l_b00:
	/* 0xb00: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b06:
	/* 0xb06: lea    eax,[rdx+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_b0c:
	/* 0xb0c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b11:
	/* 0xb11: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b15:
	/* 0xb15: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_b18:
	/* 0xb18: cmp    rdx,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 78ULL);
x86_l_b1c:
	/* 0xb1c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b22:
	/* 0xb22: lea    eax,[rdx+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_b28:
	/* 0xb28: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b2d:
	/* 0xb2d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b31:
	/* 0xb31: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_b34:
	/* 0xb34: cmp    rdx,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 79ULL);
x86_l_b38:
	/* 0xb38: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b3e:
	/* 0xb3e: lea    eax,[rdx+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_b44:
	/* 0xb44: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b49:
	/* 0xb49: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b4d:
	/* 0xb4d: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_b50:
	/* 0xb50: cmp    rdx,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 80ULL);
x86_l_b54:
	/* 0xb54: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b5a:
	/* 0xb5a: lea    eax,[rdx+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_b60:
	/* 0xb60: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b65:
	/* 0xb65: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b69:
	/* 0xb69: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_b6c:
	/* 0xb6c: cmp    rdx,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 81ULL);
x86_l_b70:
	/* 0xb70: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b76:
	/* 0xb76: lea    eax,[rdx+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_b7c:
	/* 0xb7c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b81:
	/* 0xb81: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b85:
	/* 0xb85: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_b88:
	/* 0xb88: cmp    rdx,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 82ULL);
x86_l_b8c:
	/* 0xb8c: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b92:
	/* 0xb92: lea    eax,[rdx+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_b98:
	/* 0xb98: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b9d:
	/* 0xb9d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ba1:
	/* 0xba1: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_ba4:
	/* 0xba4: cmp    rdx,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 83ULL);
x86_l_ba8:
	/* 0xba8: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_bae:
	/* 0xbae: lea    eax,[rdx+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_bb4:
	/* 0xbb4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bb9:
	/* 0xbb9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bbd:
	/* 0xbbd: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_bc0:
	/* 0xbc0: cmp    rdx,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 84ULL);
x86_l_bc4:
	/* 0xbc4: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_bca:
	/* 0xbca: lea    eax,[rdx+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_bd0:
	/* 0xbd0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bd5:
	/* 0xbd5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bd9:
	/* 0xbd9: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bdc:
	/* 0xbdc: cmp    rdx,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 85ULL);
x86_l_be0:
	/* 0xbe0: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_be6:
	/* 0xbe6: lea    eax,[rdx+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_bec:
	/* 0xbec: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bf1:
	/* 0xbf1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bf5:
	/* 0xbf5: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_bf8:
	/* 0xbf8: cmp    rdx,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 86ULL);
x86_l_bfc:
	/* 0xbfc: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c02:
	/* 0xc02: lea    eax,[rdx+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_c08:
	/* 0xc08: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c0d:
	/* 0xc0d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c11:
	/* 0xc11: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_c14:
	/* 0xc14: cmp    rdx,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 87ULL);
x86_l_c18:
	/* 0xc18: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c1e:
	/* 0xc1e: lea    eax,[rdx+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_c24:
	/* 0xc24: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c29:
	/* 0xc29: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c2d:
	/* 0xc2d: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_c30:
	/* 0xc30: cmp    rdx,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 88ULL);
x86_l_c34:
	/* 0xc34: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c3a:
	/* 0xc3a: lea    eax,[rdx+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_c40:
	/* 0xc40: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c45:
	/* 0xc45: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c49:
	/* 0xc49: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c4c:
	/* 0xc4c: cmp    rdx,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 89ULL);
x86_l_c50:
	/* 0xc50: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c52:
	/* 0xc52: lea    eax,[rdx+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_c58:
	/* 0xc58: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c5d:
	/* 0xc5d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c61:
	/* 0xc61: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_c64:
	/* 0xc64: cmp    rdx,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 90ULL);
x86_l_c68:
	/* 0xc68: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c6a:
	/* 0xc6a: lea    eax,[rdx+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_c70:
	/* 0xc70: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c75:
	/* 0xc75: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c79:
	/* 0xc79: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_c7c:
	/* 0xc7c: cmp    rdx,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 91ULL);
x86_l_c80:
	/* 0xc80: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c82:
	/* 0xc82: lea    eax,[rdx+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_c88:
	/* 0xc88: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c8d:
	/* 0xc8d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c91:
	/* 0xc91: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_c94:
	/* 0xc94: cmp    rdx,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 92ULL);
x86_l_c98:
	/* 0xc98: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c9a:
	/* 0xc9a: lea    eax,[rdx+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_ca0:
	/* 0xca0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ca5:
	/* 0xca5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ca9:
	/* 0xca9: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cac:
	/* 0xcac: cmp    rdx,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 93ULL);
x86_l_cb0:
	/* 0xcb0: je     cc5 <generic_fexit_filter_arg+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_cb2:
	/* 0xcb2: add    edx,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_cb8:
	/* 0xcb8: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cbe:
	/* 0xcbe: movzx  eax,BYTE PTR [rcx+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 0ULL);
x86_l_cc2:
	/* 0xcc2: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_cc5:
	/* 0xcc5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cca:
	/* 0xcca: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_ccd:
	/* 0xccd: jmp    35ff <generic_fexit_filter_arg+0x35ff> */
	return 13823ULL;
x86_l_cd2:
	/* 0xcd2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd5:
	/* 0xcd5: je     1b2b <generic_fexit_filter_arg+0x1b2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6955ULL;
	}
x86_l_cdb:
	/* 0xcdb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cde:
	/* 0xcde: jne    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14171ULL;
	}
x86_l_ce4:
	/* 0xce4: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ce8:
	/* 0xce8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ceb:
	/* 0xceb: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_cee:
	/* 0xcee: ja     373b <generic_fexit_filter_arg+0x373b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14139ULL;
	}
x86_l_cf4:
	/* 0xcf4: mov    edx,DWORD PTR [r8+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cf8:
	/* 0xcf8: add    r8,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_cfc:
	/* 0xcfc: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_d01:
	/* 0xd01: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d04:
	/* 0xd04: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d08:
	/* 0xd08: jb     2d63 <generic_fexit_filter_arg+0x2d63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11619ULL;
	}
x86_l_d0e:
	/* 0xd0e: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_d13:
	/* 0xd13: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d16:
	/* 0xd16: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1b:
	/* 0xd1b: jb     2cbf <generic_fexit_filter_arg+0x2cbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11455ULL;
	}
x86_l_d21:
	/* 0xd21: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_d26:
	/* 0xd26: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d29:
	/* 0xd29: jae    373b <generic_fexit_filter_arg+0x373b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14139ULL;
	}
x86_l_d2f:
	/* 0xd2f: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d34:
	/* 0xd34: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d38:
	/* 0xd38: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d3c:
	/* 0xd3c: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d44:
	/* 0xd44: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_d4b:
	/* 0xd4b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d50:
	/* 0xd50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d55:
	/* 0xd55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d57:
	/* 0xd57: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d5a:
	/* 0xd5a: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5f:
	/* 0xd5f: je     3732 <generic_fexit_filter_arg+0x3732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14130ULL;
	}
x86_l_d65:
	/* 0xd65: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_d68:
	/* 0xd68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d6b:
	/* 0xd6b: je     3732 <generic_fexit_filter_arg+0x3732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14130ULL;
	}
x86_l_d71:
	/* 0xd71: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_d78:
	/* 0xd78: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d7d:
	/* 0xd7d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d82:
	/* 0xd82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d84:
	/* 0xd84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d87:
	/* 0xd87: je     372f <generic_fexit_filter_arg+0x372f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14127ULL;
	}
x86_l_d8d:
	/* 0xd8d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d90:
	/* 0xd90: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d94:
	/* 0xd94: cmp    edx,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 94ULL);
x86_l_d97:
	/* 0xd97: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_d9c:
	/* 0xd9c: cmovb  eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_B);
x86_l_d9f:
	/* 0xd9f: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_da2:
	/* 0xda2: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da4:
	/* 0xda4: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_da7:
	/* 0xda7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_dac:
	/* 0xdac: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db1:
	/* 0xdb1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_db5:
	/* 0xdb5: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_db8:
	/* 0xdb8: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_dbc:
	/* 0xdbc: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_dc2:
	/* 0xdc2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 3526ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3526ULL: goto x86_l_dc6;
	case 3532ULL: goto x86_l_dcc;
	case 3537ULL: goto x86_l_dd1;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3549ULL: goto x86_l_ddd;
	case 3553ULL: goto x86_l_de1;
	case 3559ULL: goto x86_l_de7;
	case 3563ULL: goto x86_l_deb;
	case 3569ULL: goto x86_l_df1;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3583ULL: goto x86_l_dff;
	case 3586ULL: goto x86_l_e02;
	case 3590ULL: goto x86_l_e06;
	case 3596ULL: goto x86_l_e0c;
	case 3600ULL: goto x86_l_e10;
	case 3606ULL: goto x86_l_e16;
	case 3611ULL: goto x86_l_e1b;
	case 3616ULL: goto x86_l_e20;
	case 3620ULL: goto x86_l_e24;
	case 3623ULL: goto x86_l_e27;
	case 3627ULL: goto x86_l_e2b;
	case 3633ULL: goto x86_l_e31;
	case 3637ULL: goto x86_l_e35;
	case 3643ULL: goto x86_l_e3b;
	case 3648ULL: goto x86_l_e40;
	case 3653ULL: goto x86_l_e45;
	case 3657ULL: goto x86_l_e49;
	case 3660ULL: goto x86_l_e4c;
	case 3664ULL: goto x86_l_e50;
	case 3670ULL: goto x86_l_e56;
	case 3674ULL: goto x86_l_e5a;
	case 3680ULL: goto x86_l_e60;
	case 3685ULL: goto x86_l_e65;
	case 3690ULL: goto x86_l_e6a;
	case 3694ULL: goto x86_l_e6e;
	case 3697ULL: goto x86_l_e71;
	case 3701ULL: goto x86_l_e75;
	case 3707ULL: goto x86_l_e7b;
	case 3711ULL: goto x86_l_e7f;
	case 3717ULL: goto x86_l_e85;
	case 3722ULL: goto x86_l_e8a;
	case 3727ULL: goto x86_l_e8f;
	case 3731ULL: goto x86_l_e93;
	case 3734ULL: goto x86_l_e96;
	case 3738ULL: goto x86_l_e9a;
	case 3744ULL: goto x86_l_ea0;
	case 3748ULL: goto x86_l_ea4;
	case 3754ULL: goto x86_l_eaa;
	case 3759ULL: goto x86_l_eaf;
	case 3764ULL: goto x86_l_eb4;
	case 3768ULL: goto x86_l_eb8;
	case 3771ULL: goto x86_l_ebb;
	case 3775ULL: goto x86_l_ebf;
	case 3781ULL: goto x86_l_ec5;
	case 3785ULL: goto x86_l_ec9;
	case 3791ULL: goto x86_l_ecf;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3805ULL: goto x86_l_edd;
	case 3808ULL: goto x86_l_ee0;
	case 3812ULL: goto x86_l_ee4;
	case 3818ULL: goto x86_l_eea;
	case 3822ULL: goto x86_l_eee;
	case 3828ULL: goto x86_l_ef4;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3842ULL: goto x86_l_f02;
	case 3845ULL: goto x86_l_f05;
	case 3849ULL: goto x86_l_f09;
	case 3855ULL: goto x86_l_f0f;
	case 3859ULL: goto x86_l_f13;
	case 3865ULL: goto x86_l_f19;
	case 3870ULL: goto x86_l_f1e;
	case 3875ULL: goto x86_l_f23;
	case 3879ULL: goto x86_l_f27;
	case 3882ULL: goto x86_l_f2a;
	case 3886ULL: goto x86_l_f2e;
	case 3892ULL: goto x86_l_f34;
	case 3896ULL: goto x86_l_f38;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3916ULL: goto x86_l_f4c;
	case 3919ULL: goto x86_l_f4f;
	case 3923ULL: goto x86_l_f53;
	case 3929ULL: goto x86_l_f59;
	case 3933ULL: goto x86_l_f5d;
	case 3939ULL: goto x86_l_f63;
	case 3944ULL: goto x86_l_f68;
	case 3949ULL: goto x86_l_f6d;
	case 3953ULL: goto x86_l_f71;
	case 3956ULL: goto x86_l_f74;
	case 3960ULL: goto x86_l_f78;
	case 3966ULL: goto x86_l_f7e;
	case 3970ULL: goto x86_l_f82;
	case 3976ULL: goto x86_l_f88;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3990ULL: goto x86_l_f96;
	case 3993ULL: goto x86_l_f99;
	case 3997ULL: goto x86_l_f9d;
	case 4003ULL: goto x86_l_fa3;
	case 4007ULL: goto x86_l_fa7;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4023ULL: goto x86_l_fb7;
	case 4027ULL: goto x86_l_fbb;
	case 4030ULL: goto x86_l_fbe;
	case 4034ULL: goto x86_l_fc2;
	case 4040ULL: goto x86_l_fc8;
	case 4044ULL: goto x86_l_fcc;
	case 4050ULL: goto x86_l_fd2;
	case 4055ULL: goto x86_l_fd7;
	case 4060ULL: goto x86_l_fdc;
	case 4064ULL: goto x86_l_fe0;
	case 4067ULL: goto x86_l_fe3;
	case 4071ULL: goto x86_l_fe7;
	case 4077ULL: goto x86_l_fed;
	case 4081ULL: goto x86_l_ff1;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4097ULL: goto x86_l_1001;
	case 4101ULL: goto x86_l_1005;
	case 4104ULL: goto x86_l_1008;
	case 4108ULL: goto x86_l_100c;
	case 4114ULL: goto x86_l_1012;
	case 4118ULL: goto x86_l_1016;
	case 4124ULL: goto x86_l_101c;
	case 4129ULL: goto x86_l_1021;
	case 4134ULL: goto x86_l_1026;
	case 4138ULL: goto x86_l_102a;
	case 4141ULL: goto x86_l_102d;
	case 4145ULL: goto x86_l_1031;
	case 4151ULL: goto x86_l_1037;
	case 4155ULL: goto x86_l_103b;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4175ULL: goto x86_l_104f;
	case 4178ULL: goto x86_l_1052;
	case 4182ULL: goto x86_l_1056;
	case 4188ULL: goto x86_l_105c;
	case 4192ULL: goto x86_l_1060;
	case 4198ULL: goto x86_l_1066;
	case 4203ULL: goto x86_l_106b;
	case 4208ULL: goto x86_l_1070;
	case 4212ULL: goto x86_l_1074;
	case 4215ULL: goto x86_l_1077;
	case 4219ULL: goto x86_l_107b;
	case 4225ULL: goto x86_l_1081;
	case 4229ULL: goto x86_l_1085;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4245ULL: goto x86_l_1095;
	case 4249ULL: goto x86_l_1099;
	case 4252ULL: goto x86_l_109c;
	case 4256ULL: goto x86_l_10a0;
	case 4262ULL: goto x86_l_10a6;
	case 4266ULL: goto x86_l_10aa;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4282ULL: goto x86_l_10ba;
	case 4286ULL: goto x86_l_10be;
	case 4289ULL: goto x86_l_10c1;
	case 4293ULL: goto x86_l_10c5;
	case 4299ULL: goto x86_l_10cb;
	case 4303ULL: goto x86_l_10cf;
	case 4309ULL: goto x86_l_10d5;
	case 4314ULL: goto x86_l_10da;
	case 4319ULL: goto x86_l_10df;
	case 4323ULL: goto x86_l_10e3;
	case 4326ULL: goto x86_l_10e6;
	case 4330ULL: goto x86_l_10ea;
	case 4336ULL: goto x86_l_10f0;
	case 4340ULL: goto x86_l_10f4;
	case 4346ULL: goto x86_l_10fa;
	case 4351ULL: goto x86_l_10ff;
	case 4356ULL: goto x86_l_1104;
	case 4360ULL: goto x86_l_1108;
	case 4363ULL: goto x86_l_110b;
	case 4367ULL: goto x86_l_110f;
	case 4373ULL: goto x86_l_1115;
	case 4377ULL: goto x86_l_1119;
	case 4383ULL: goto x86_l_111f;
	case 4388ULL: goto x86_l_1124;
	case 4393ULL: goto x86_l_1129;
	case 4397ULL: goto x86_l_112d;
	case 4400ULL: goto x86_l_1130;
	case 4404ULL: goto x86_l_1134;
	case 4410ULL: goto x86_l_113a;
	case 4414ULL: goto x86_l_113e;
	case 4420ULL: goto x86_l_1144;
	case 4425ULL: goto x86_l_1149;
	case 4430ULL: goto x86_l_114e;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4441ULL: goto x86_l_1159;
	case 4447ULL: goto x86_l_115f;
	case 4451ULL: goto x86_l_1163;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4467ULL: goto x86_l_1173;
	case 4471ULL: goto x86_l_1177;
	case 4474ULL: goto x86_l_117a;
	case 4478ULL: goto x86_l_117e;
	case 4484ULL: goto x86_l_1184;
	case 4488ULL: goto x86_l_1188;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4504ULL: goto x86_l_1198;
	case 4508ULL: goto x86_l_119c;
	case 4511ULL: goto x86_l_119f;
	case 4515ULL: goto x86_l_11a3;
	case 4521ULL: goto x86_l_11a9;
	case 4525ULL: goto x86_l_11ad;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4541ULL: goto x86_l_11bd;
	case 4545ULL: goto x86_l_11c1;
	case 4548ULL: goto x86_l_11c4;
	case 4552ULL: goto x86_l_11c8;
	case 4558ULL: goto x86_l_11ce;
	case 4562ULL: goto x86_l_11d2;
	case 4568ULL: goto x86_l_11d8;
	case 4573ULL: goto x86_l_11dd;
	case 4578ULL: goto x86_l_11e2;
	case 4582ULL: goto x86_l_11e6;
	case 4585ULL: goto x86_l_11e9;
	case 4589ULL: goto x86_l_11ed;
	case 4595ULL: goto x86_l_11f3;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4619ULL: goto x86_l_120b;
	case 4622ULL: goto x86_l_120e;
	case 4626ULL: goto x86_l_1212;
	case 4632ULL: goto x86_l_1218;
	case 4636ULL: goto x86_l_121c;
	case 4642ULL: goto x86_l_1222;
	case 4647ULL: goto x86_l_1227;
	case 4652ULL: goto x86_l_122c;
	case 4656ULL: goto x86_l_1230;
	case 4659ULL: goto x86_l_1233;
	case 4663ULL: goto x86_l_1237;
	case 4669ULL: goto x86_l_123d;
	case 4673ULL: goto x86_l_1241;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4693ULL: goto x86_l_1255;
	case 4696ULL: goto x86_l_1258;
	case 4700ULL: goto x86_l_125c;
	case 4706ULL: goto x86_l_1262;
	case 4710ULL: goto x86_l_1266;
	case 4716ULL: goto x86_l_126c;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4730ULL: goto x86_l_127a;
	case 4733ULL: goto x86_l_127d;
	case 4737ULL: goto x86_l_1281;
	case 4743ULL: goto x86_l_1287;
	case 4747ULL: goto x86_l_128b;
	case 4753ULL: goto x86_l_1291;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4767ULL: goto x86_l_129f;
	case 4770ULL: goto x86_l_12a2;
	case 4774ULL: goto x86_l_12a6;
	case 4780ULL: goto x86_l_12ac;
	case 4784ULL: goto x86_l_12b0;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4800ULL: goto x86_l_12c0;
	case 4804ULL: goto x86_l_12c4;
	case 4807ULL: goto x86_l_12c7;
	case 4811ULL: goto x86_l_12cb;
	case 4817ULL: goto x86_l_12d1;
	case 4821ULL: goto x86_l_12d5;
	case 4827ULL: goto x86_l_12db;
	case 4832ULL: goto x86_l_12e0;
	case 4837ULL: goto x86_l_12e5;
	case 4841ULL: goto x86_l_12e9;
	case 4844ULL: goto x86_l_12ec;
	case 4848ULL: goto x86_l_12f0;
	case 4854ULL: goto x86_l_12f6;
	case 4858ULL: goto x86_l_12fa;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4878ULL: goto x86_l_130e;
	case 4881ULL: goto x86_l_1311;
	case 4885ULL: goto x86_l_1315;
	case 4891ULL: goto x86_l_131b;
	case 4895ULL: goto x86_l_131f;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4915ULL: goto x86_l_1333;
	case 4918ULL: goto x86_l_1336;
	case 4922ULL: goto x86_l_133a;
	case 4928ULL: goto x86_l_1340;
	case 4932ULL: goto x86_l_1344;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4952ULL: goto x86_l_1358;
	case 4955ULL: goto x86_l_135b;
	case 4959ULL: goto x86_l_135f;
	case 4965ULL: goto x86_l_1365;
	case 4969ULL: goto x86_l_1369;
	case 4975ULL: goto x86_l_136f;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4989ULL: goto x86_l_137d;
	case 4992ULL: goto x86_l_1380;
	case 4996ULL: goto x86_l_1384;
	case 5002ULL: goto x86_l_138a;
	case 5006ULL: goto x86_l_138e;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5022ULL: goto x86_l_139e;
	case 5026ULL: goto x86_l_13a2;
	case 5029ULL: goto x86_l_13a5;
	case 5033ULL: goto x86_l_13a9;
	case 5039ULL: goto x86_l_13af;
	case 5043ULL: goto x86_l_13b3;
	case 5049ULL: goto x86_l_13b9;
	case 5054ULL: goto x86_l_13be;
	case 5059ULL: goto x86_l_13c3;
	case 5063ULL: goto x86_l_13c7;
	case 5066ULL: goto x86_l_13ca;
	case 5070ULL: goto x86_l_13ce;
	case 5076ULL: goto x86_l_13d4;
	case 5080ULL: goto x86_l_13d8;
	case 5086ULL: goto x86_l_13de;
	case 5091ULL: goto x86_l_13e3;
	case 5096ULL: goto x86_l_13e8;
	case 5100ULL: goto x86_l_13ec;
	case 5103ULL: goto x86_l_13ef;
	case 5107ULL: goto x86_l_13f3;
	case 5113ULL: goto x86_l_13f9;
	case 5117ULL: goto x86_l_13fd;
	case 5123ULL: goto x86_l_1403;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5137ULL: goto x86_l_1411;
	case 5140ULL: goto x86_l_1414;
	case 5144ULL: goto x86_l_1418;
	case 5150ULL: goto x86_l_141e;
	case 5154ULL: goto x86_l_1422;
	case 5160ULL: goto x86_l_1428;
	case 5165ULL: goto x86_l_142d;
	case 5170ULL: goto x86_l_1432;
	case 5174ULL: goto x86_l_1436;
	case 5177ULL: goto x86_l_1439;
	case 5181ULL: goto x86_l_143d;
	case 5187ULL: goto x86_l_1443;
	case 5191ULL: goto x86_l_1447;
	case 5197ULL: goto x86_l_144d;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5211ULL: goto x86_l_145b;
	case 5214ULL: goto x86_l_145e;
	case 5218ULL: goto x86_l_1462;
	case 5224ULL: goto x86_l_1468;
	case 5228ULL: goto x86_l_146c;
	case 5234ULL: goto x86_l_1472;
	case 5239ULL: goto x86_l_1477;
	case 5244ULL: goto x86_l_147c;
	case 5248ULL: goto x86_l_1480;
	case 5251ULL: goto x86_l_1483;
	case 5255ULL: goto x86_l_1487;
	case 5261ULL: goto x86_l_148d;
	case 5265ULL: goto x86_l_1491;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5281ULL: goto x86_l_14a1;
	case 5285ULL: goto x86_l_14a5;
	case 5288ULL: goto x86_l_14a8;
	case 5292ULL: goto x86_l_14ac;
	case 5298ULL: goto x86_l_14b2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_dc6:
	/* 0xdc6: lea    eax,[rdx+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_dcc:
	/* 0xdcc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_dd1:
	/* 0xdd1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dd6:
	/* 0xdd6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_dda:
	/* 0xdda: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_ddd:
	/* 0xddd: cmp    rdx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 2ULL);
x86_l_de1:
	/* 0xde1: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_de7:
	/* 0xde7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_deb:
	/* 0xdeb: lea    eax,[rdx+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_df1:
	/* 0xdf1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_df6:
	/* 0xdf6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dfb:
	/* 0xdfb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_dff:
	/* 0xdff: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_e02:
	/* 0xe02: cmp    rdx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 3ULL);
x86_l_e06:
	/* 0xe06: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_e0c:
	/* 0xe0c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e10:
	/* 0xe10: lea    eax,[rdx+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_e16:
	/* 0xe16: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e1b:
	/* 0xe1b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e20:
	/* 0xe20: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_e24:
	/* 0xe24: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_e27:
	/* 0xe27: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_e2b:
	/* 0xe2b: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_e31:
	/* 0xe31: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e35:
	/* 0xe35: lea    eax,[rdx+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_e3b:
	/* 0xe3b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e40:
	/* 0xe40: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e45:
	/* 0xe45: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_e49:
	/* 0xe49: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e4c:
	/* 0xe4c: cmp    rdx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 5ULL);
x86_l_e50:
	/* 0xe50: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_e56:
	/* 0xe56: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5a:
	/* 0xe5a: lea    eax,[rdx+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_e60:
	/* 0xe60: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e65:
	/* 0xe65: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e6a:
	/* 0xe6a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_e6e:
	/* 0xe6e: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_e71:
	/* 0xe71: cmp    rdx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 6ULL);
x86_l_e75:
	/* 0xe75: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_e7b:
	/* 0xe7b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e7f:
	/* 0xe7f: lea    eax,[rdx+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_e85:
	/* 0xe85: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e8a:
	/* 0xe8a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8f:
	/* 0xe8f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_e93:
	/* 0xe93: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_e96:
	/* 0xe96: cmp    rdx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 7ULL);
x86_l_e9a:
	/* 0xe9a: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_ea0:
	/* 0xea0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea4:
	/* 0xea4: lea    eax,[rdx+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_eaa:
	/* 0xeaa: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_eaf:
	/* 0xeaf: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eb4:
	/* 0xeb4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_eb8:
	/* 0xeb8: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_ebb:
	/* 0xebb: cmp    rdx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 8ULL);
x86_l_ebf:
	/* 0xebf: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_ec5:
	/* 0xec5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec9:
	/* 0xec9: lea    eax,[rdx+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_ecf:
	/* 0xecf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ed4:
	/* 0xed4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed9:
	/* 0xed9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_edd:
	/* 0xedd: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ee0:
	/* 0xee0: cmp    rdx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 9ULL);
x86_l_ee4:
	/* 0xee4: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_eea:
	/* 0xeea: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eee:
	/* 0xeee: lea    eax,[rdx+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_ef4:
	/* 0xef4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ef9:
	/* 0xef9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_efe:
	/* 0xefe: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f02:
	/* 0xf02: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_f05:
	/* 0xf05: cmp    rdx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 10ULL);
x86_l_f09:
	/* 0xf09: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_f0f:
	/* 0xf0f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f13:
	/* 0xf13: lea    eax,[rdx+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_f19:
	/* 0xf19: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f1e:
	/* 0xf1e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f23:
	/* 0xf23: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f27:
	/* 0xf27: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_f2a:
	/* 0xf2a: cmp    rdx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 11ULL);
x86_l_f2e:
	/* 0xf2e: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_f34:
	/* 0xf34: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f38:
	/* 0xf38: lea    eax,[rdx+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_f3e:
	/* 0xf3e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f43:
	/* 0xf43: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f48:
	/* 0xf48: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f4c:
	/* 0xf4c: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_f4f:
	/* 0xf4f: cmp    rdx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 12ULL);
x86_l_f53:
	/* 0xf53: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_f59:
	/* 0xf59: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f5d:
	/* 0xf5d: lea    eax,[rdx+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_f63:
	/* 0xf63: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f68:
	/* 0xf68: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f6d:
	/* 0xf6d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f71:
	/* 0xf71: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f74:
	/* 0xf74: cmp    rdx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 13ULL);
x86_l_f78:
	/* 0xf78: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_f7e:
	/* 0xf7e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f82:
	/* 0xf82: lea    eax,[rdx+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_f88:
	/* 0xf88: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f8d:
	/* 0xf8d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f92:
	/* 0xf92: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f96:
	/* 0xf96: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_f99:
	/* 0xf99: cmp    rdx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 14ULL);
x86_l_f9d:
	/* 0xf9d: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_fa3:
	/* 0xfa3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fa7:
	/* 0xfa7: lea    eax,[rdx+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_fad:
	/* 0xfad: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fb2:
	/* 0xfb2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fb7:
	/* 0xfb7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fbb:
	/* 0xfbb: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_fbe:
	/* 0xfbe: cmp    rdx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 15ULL);
x86_l_fc2:
	/* 0xfc2: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_fc8:
	/* 0xfc8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fcc:
	/* 0xfcc: lea    eax,[rdx+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_fd2:
	/* 0xfd2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fd7:
	/* 0xfd7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fdc:
	/* 0xfdc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fe0:
	/* 0xfe0: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_fe3:
	/* 0xfe3: cmp    rdx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 16ULL);
x86_l_fe7:
	/* 0xfe7: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_fed:
	/* 0xfed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff1:
	/* 0xff1: lea    eax,[rdx+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_ff7:
	/* 0xff7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ffc:
	/* 0xffc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1001:
	/* 0x1001: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1005:
	/* 0x1005: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1008:
	/* 0x1008: cmp    rdx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 17ULL);
x86_l_100c:
	/* 0x100c: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1012:
	/* 0x1012: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1016:
	/* 0x1016: lea    eax,[rdx+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_101c:
	/* 0x101c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1021:
	/* 0x1021: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1026:
	/* 0x1026: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_102a:
	/* 0x102a: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_102d:
	/* 0x102d: cmp    rdx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18ULL);
x86_l_1031:
	/* 0x1031: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1037:
	/* 0x1037: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_103b:
	/* 0x103b: lea    eax,[rdx+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1041:
	/* 0x1041: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1046:
	/* 0x1046: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_104b:
	/* 0x104b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_104f:
	/* 0x104f: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1052:
	/* 0x1052: cmp    rdx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 19ULL);
x86_l_1056:
	/* 0x1056: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_105c:
	/* 0x105c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1060:
	/* 0x1060: lea    eax,[rdx+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1066:
	/* 0x1066: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_106b:
	/* 0x106b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1070:
	/* 0x1070: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1074:
	/* 0x1074: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_1077:
	/* 0x1077: cmp    rdx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 20ULL);
x86_l_107b:
	/* 0x107b: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1081:
	/* 0x1081: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1085:
	/* 0x1085: lea    eax,[rdx+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_108b:
	/* 0x108b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1090:
	/* 0x1090: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1095:
	/* 0x1095: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1099:
	/* 0x1099: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_109c:
	/* 0x109c: cmp    rdx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 21ULL);
x86_l_10a0:
	/* 0x10a0: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_10a6:
	/* 0x10a6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10aa:
	/* 0x10aa: lea    eax,[rdx+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_10b0:
	/* 0x10b0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10b5:
	/* 0x10b5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ba:
	/* 0x10ba: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10be:
	/* 0x10be: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_10c1:
	/* 0x10c1: cmp    rdx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 22ULL);
x86_l_10c5:
	/* 0x10c5: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_10cb:
	/* 0x10cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10cf:
	/* 0x10cf: lea    eax,[rdx+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_10d5:
	/* 0x10d5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10da:
	/* 0x10da: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10df:
	/* 0x10df: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10e3:
	/* 0x10e3: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_10e6:
	/* 0x10e6: cmp    rdx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 23ULL);
x86_l_10ea:
	/* 0x10ea: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_10f0:
	/* 0x10f0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f4:
	/* 0x10f4: lea    eax,[rdx+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_10fa:
	/* 0x10fa: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10ff:
	/* 0x10ff: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1104:
	/* 0x1104: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1108:
	/* 0x1108: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_110b:
	/* 0x110b: cmp    rdx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 24ULL);
x86_l_110f:
	/* 0x110f: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1115:
	/* 0x1115: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1119:
	/* 0x1119: lea    eax,[rdx+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_111f:
	/* 0x111f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1124:
	/* 0x1124: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1129:
	/* 0x1129: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_112d:
	/* 0x112d: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1130:
	/* 0x1130: cmp    rdx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 25ULL);
x86_l_1134:
	/* 0x1134: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_113a:
	/* 0x113a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113e:
	/* 0x113e: lea    eax,[rdx+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_1144:
	/* 0x1144: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1149:
	/* 0x1149: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114e:
	/* 0x114e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1152:
	/* 0x1152: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1155:
	/* 0x1155: cmp    rdx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 26ULL);
x86_l_1159:
	/* 0x1159: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_115f:
	/* 0x115f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1163:
	/* 0x1163: lea    eax,[rdx+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1169:
	/* 0x1169: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_116e:
	/* 0x116e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1173:
	/* 0x1173: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1177:
	/* 0x1177: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_117a:
	/* 0x117a: cmp    rdx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 27ULL);
x86_l_117e:
	/* 0x117e: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1184:
	/* 0x1184: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1188:
	/* 0x1188: lea    eax,[rdx+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_118e:
	/* 0x118e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1193:
	/* 0x1193: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1198:
	/* 0x1198: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_119c:
	/* 0x119c: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_119f:
	/* 0x119f: cmp    rdx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 28ULL);
x86_l_11a3:
	/* 0x11a3: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_11a9:
	/* 0x11a9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ad:
	/* 0x11ad: lea    eax,[rdx+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_11b3:
	/* 0x11b3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11b8:
	/* 0x11b8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11bd:
	/* 0x11bd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11c1:
	/* 0x11c1: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11c4:
	/* 0x11c4: cmp    rdx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 29ULL);
x86_l_11c8:
	/* 0x11c8: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_11ce:
	/* 0x11ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d2:
	/* 0x11d2: lea    eax,[rdx+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_11d8:
	/* 0x11d8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11dd:
	/* 0x11dd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11e2:
	/* 0x11e2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11e6:
	/* 0x11e6: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_11e9:
	/* 0x11e9: cmp    rdx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 30ULL);
x86_l_11ed:
	/* 0x11ed: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_11f3:
	/* 0x11f3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f7:
	/* 0x11f7: lea    eax,[rdx+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_11fd:
	/* 0x11fd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1202:
	/* 0x1202: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1207:
	/* 0x1207: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_120b:
	/* 0x120b: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_120e:
	/* 0x120e: cmp    rdx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 31ULL);
x86_l_1212:
	/* 0x1212: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1218:
	/* 0x1218: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_121c:
	/* 0x121c: lea    eax,[rdx+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_1222:
	/* 0x1222: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1227:
	/* 0x1227: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122c:
	/* 0x122c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1230:
	/* 0x1230: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_1233:
	/* 0x1233: cmp    rdx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 32ULL);
x86_l_1237:
	/* 0x1237: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_123d:
	/* 0x123d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1241:
	/* 0x1241: lea    eax,[rdx+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_1247:
	/* 0x1247: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_124c:
	/* 0x124c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1251:
	/* 0x1251: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1255:
	/* 0x1255: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1258:
	/* 0x1258: cmp    rdx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 33ULL);
x86_l_125c:
	/* 0x125c: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1262:
	/* 0x1262: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1266:
	/* 0x1266: lea    eax,[rdx+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_126c:
	/* 0x126c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1271:
	/* 0x1271: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1276:
	/* 0x1276: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_127a:
	/* 0x127a: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_127d:
	/* 0x127d: cmp    rdx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 34ULL);
x86_l_1281:
	/* 0x1281: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1287:
	/* 0x1287: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_128b:
	/* 0x128b: lea    eax,[rdx+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_1291:
	/* 0x1291: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1296:
	/* 0x1296: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_129b:
	/* 0x129b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_129f:
	/* 0x129f: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_12a2:
	/* 0x12a2: cmp    rdx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 35ULL);
x86_l_12a6:
	/* 0x12a6: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_12ac:
	/* 0x12ac: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b0:
	/* 0x12b0: lea    eax,[rdx+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_12b6:
	/* 0x12b6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12bb:
	/* 0x12bb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12c0:
	/* 0x12c0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12c4:
	/* 0x12c4: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_12c7:
	/* 0x12c7: cmp    rdx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 36ULL);
x86_l_12cb:
	/* 0x12cb: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_12d1:
	/* 0x12d1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d5:
	/* 0x12d5: lea    eax,[rdx+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_12db:
	/* 0x12db: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12e0:
	/* 0x12e0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12e5:
	/* 0x12e5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12e9:
	/* 0x12e9: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12ec:
	/* 0x12ec: cmp    rdx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 37ULL);
x86_l_12f0:
	/* 0x12f0: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_12f6:
	/* 0x12f6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12fa:
	/* 0x12fa: lea    eax,[rdx+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_1300:
	/* 0x1300: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1305:
	/* 0x1305: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130a:
	/* 0x130a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_130e:
	/* 0x130e: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_1311:
	/* 0x1311: cmp    rdx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 38ULL);
x86_l_1315:
	/* 0x1315: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_131b:
	/* 0x131b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131f:
	/* 0x131f: lea    eax,[rdx+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_1325:
	/* 0x1325: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_132a:
	/* 0x132a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_132f:
	/* 0x132f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1333:
	/* 0x1333: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1336:
	/* 0x1336: cmp    rdx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 39ULL);
x86_l_133a:
	/* 0x133a: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1340:
	/* 0x1340: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1344:
	/* 0x1344: lea    eax,[rdx+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_134a:
	/* 0x134a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_134f:
	/* 0x134f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1354:
	/* 0x1354: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1358:
	/* 0x1358: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_135b:
	/* 0x135b: cmp    rdx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 40ULL);
x86_l_135f:
	/* 0x135f: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1365:
	/* 0x1365: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1369:
	/* 0x1369: lea    eax,[rdx+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_136f:
	/* 0x136f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1374:
	/* 0x1374: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1379:
	/* 0x1379: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_137d:
	/* 0x137d: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1380:
	/* 0x1380: cmp    rdx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 41ULL);
x86_l_1384:
	/* 0x1384: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_138a:
	/* 0x138a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_138e:
	/* 0x138e: lea    eax,[rdx+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_1394:
	/* 0x1394: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1399:
	/* 0x1399: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_139e:
	/* 0x139e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13a2:
	/* 0x13a2: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_13a5:
	/* 0x13a5: cmp    rdx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 42ULL);
x86_l_13a9:
	/* 0x13a9: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_13af:
	/* 0x13af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b3:
	/* 0x13b3: lea    eax,[rdx+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_13b9:
	/* 0x13b9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13be:
	/* 0x13be: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13c3:
	/* 0x13c3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13c7:
	/* 0x13c7: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_13ca:
	/* 0x13ca: cmp    rdx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 43ULL);
x86_l_13ce:
	/* 0x13ce: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_13d4:
	/* 0x13d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d8:
	/* 0x13d8: lea    eax,[rdx+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_13de:
	/* 0x13de: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13e3:
	/* 0x13e3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e8:
	/* 0x13e8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13ec:
	/* 0x13ec: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_13ef:
	/* 0x13ef: cmp    rdx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 44ULL);
x86_l_13f3:
	/* 0x13f3: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_13f9:
	/* 0x13f9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13fd:
	/* 0x13fd: lea    eax,[rdx+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_1403:
	/* 0x1403: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1408:
	/* 0x1408: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_140d:
	/* 0x140d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1411:
	/* 0x1411: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1414:
	/* 0x1414: cmp    rdx,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 45ULL);
x86_l_1418:
	/* 0x1418: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_141e:
	/* 0x141e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1422:
	/* 0x1422: lea    eax,[rdx+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_1428:
	/* 0x1428: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_142d:
	/* 0x142d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1432:
	/* 0x1432: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1436:
	/* 0x1436: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_1439:
	/* 0x1439: cmp    rdx,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 46ULL);
x86_l_143d:
	/* 0x143d: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1443:
	/* 0x1443: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1447:
	/* 0x1447: lea    eax,[rdx+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_144d:
	/* 0x144d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1452:
	/* 0x1452: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1457:
	/* 0x1457: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_145b:
	/* 0x145b: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_145e:
	/* 0x145e: cmp    rdx,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 47ULL);
x86_l_1462:
	/* 0x1462: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_1468:
	/* 0x1468: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146c:
	/* 0x146c: lea    eax,[rdx+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_1472:
	/* 0x1472: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1477:
	/* 0x1477: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_147c:
	/* 0x147c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1480:
	/* 0x1480: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_1483:
	/* 0x1483: cmp    rdx,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 48ULL);
x86_l_1487:
	/* 0x1487: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_148d:
	/* 0x148d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1491:
	/* 0x1491: lea    eax,[rdx+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_1497:
	/* 0x1497: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_149c:
	/* 0x149c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a1:
	/* 0x14a1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14a5:
	/* 0x14a5: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_14a8:
	/* 0x14a8: cmp    rdx,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 49ULL);
x86_l_14ac:
	/* 0x14ac: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6942ULL;
	}
x86_l_14b2:
	/* 0x14b2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 5302ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5302ULL: goto x86_l_14b6;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5318ULL: goto x86_l_14c6;
	case 5322ULL: goto x86_l_14ca;
	case 5325ULL: goto x86_l_14cd;
	case 5329ULL: goto x86_l_14d1;
	case 5335ULL: goto x86_l_14d7;
	case 5339ULL: goto x86_l_14db;
	case 5345ULL: goto x86_l_14e1;
	case 5350ULL: goto x86_l_14e6;
	case 5355ULL: goto x86_l_14eb;
	case 5359ULL: goto x86_l_14ef;
	case 5362ULL: goto x86_l_14f2;
	case 5366ULL: goto x86_l_14f6;
	case 5372ULL: goto x86_l_14fc;
	case 5376ULL: goto x86_l_1500;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5392ULL: goto x86_l_1510;
	case 5396ULL: goto x86_l_1514;
	case 5399ULL: goto x86_l_1517;
	case 5403ULL: goto x86_l_151b;
	case 5409ULL: goto x86_l_1521;
	case 5413ULL: goto x86_l_1525;
	case 5419ULL: goto x86_l_152b;
	case 5424ULL: goto x86_l_1530;
	case 5429ULL: goto x86_l_1535;
	case 5433ULL: goto x86_l_1539;
	case 5436ULL: goto x86_l_153c;
	case 5440ULL: goto x86_l_1540;
	case 5446ULL: goto x86_l_1546;
	case 5450ULL: goto x86_l_154a;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5466ULL: goto x86_l_155a;
	case 5470ULL: goto x86_l_155e;
	case 5473ULL: goto x86_l_1561;
	case 5477ULL: goto x86_l_1565;
	case 5483ULL: goto x86_l_156b;
	case 5487ULL: goto x86_l_156f;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5507ULL: goto x86_l_1583;
	case 5510ULL: goto x86_l_1586;
	case 5514ULL: goto x86_l_158a;
	case 5520ULL: goto x86_l_1590;
	case 5524ULL: goto x86_l_1594;
	case 5530ULL: goto x86_l_159a;
	case 5535ULL: goto x86_l_159f;
	case 5540ULL: goto x86_l_15a4;
	case 5544ULL: goto x86_l_15a8;
	case 5547ULL: goto x86_l_15ab;
	case 5551ULL: goto x86_l_15af;
	case 5557ULL: goto x86_l_15b5;
	case 5561ULL: goto x86_l_15b9;
	case 5567ULL: goto x86_l_15bf;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5581ULL: goto x86_l_15cd;
	case 5584ULL: goto x86_l_15d0;
	case 5588ULL: goto x86_l_15d4;
	case 5594ULL: goto x86_l_15da;
	case 5598ULL: goto x86_l_15de;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5614ULL: goto x86_l_15ee;
	case 5618ULL: goto x86_l_15f2;
	case 5621ULL: goto x86_l_15f5;
	case 5625ULL: goto x86_l_15f9;
	case 5631ULL: goto x86_l_15ff;
	case 5635ULL: goto x86_l_1603;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5651ULL: goto x86_l_1613;
	case 5655ULL: goto x86_l_1617;
	case 5658ULL: goto x86_l_161a;
	case 5662ULL: goto x86_l_161e;
	case 5668ULL: goto x86_l_1624;
	case 5672ULL: goto x86_l_1628;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5692ULL: goto x86_l_163c;
	case 5695ULL: goto x86_l_163f;
	case 5699ULL: goto x86_l_1643;
	case 5705ULL: goto x86_l_1649;
	case 5709ULL: goto x86_l_164d;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5729ULL: goto x86_l_1661;
	case 5732ULL: goto x86_l_1664;
	case 5736ULL: goto x86_l_1668;
	case 5742ULL: goto x86_l_166e;
	case 5746ULL: goto x86_l_1672;
	case 5752ULL: goto x86_l_1678;
	case 5757ULL: goto x86_l_167d;
	case 5762ULL: goto x86_l_1682;
	case 5766ULL: goto x86_l_1686;
	case 5769ULL: goto x86_l_1689;
	case 5773ULL: goto x86_l_168d;
	case 5779ULL: goto x86_l_1693;
	case 5783ULL: goto x86_l_1697;
	case 5789ULL: goto x86_l_169d;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5803ULL: goto x86_l_16ab;
	case 5806ULL: goto x86_l_16ae;
	case 5810ULL: goto x86_l_16b2;
	case 5816ULL: goto x86_l_16b8;
	case 5820ULL: goto x86_l_16bc;
	case 5826ULL: goto x86_l_16c2;
	case 5831ULL: goto x86_l_16c7;
	case 5836ULL: goto x86_l_16cc;
	case 5840ULL: goto x86_l_16d0;
	case 5843ULL: goto x86_l_16d3;
	case 5847ULL: goto x86_l_16d7;
	case 5853ULL: goto x86_l_16dd;
	case 5857ULL: goto x86_l_16e1;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5884ULL: goto x86_l_16fc;
	case 5890ULL: goto x86_l_1702;
	case 5894ULL: goto x86_l_1706;
	case 5900ULL: goto x86_l_170c;
	case 5905ULL: goto x86_l_1711;
	case 5910ULL: goto x86_l_1716;
	case 5914ULL: goto x86_l_171a;
	case 5917ULL: goto x86_l_171d;
	case 5921ULL: goto x86_l_1721;
	case 5927ULL: goto x86_l_1727;
	case 5931ULL: goto x86_l_172b;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5951ULL: goto x86_l_173f;
	case 5954ULL: goto x86_l_1742;
	case 5958ULL: goto x86_l_1746;
	case 5964ULL: goto x86_l_174c;
	case 5968ULL: goto x86_l_1750;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5984ULL: goto x86_l_1760;
	case 5988ULL: goto x86_l_1764;
	case 5991ULL: goto x86_l_1767;
	case 5995ULL: goto x86_l_176b;
	case 6001ULL: goto x86_l_1771;
	case 6005ULL: goto x86_l_1775;
	case 6011ULL: goto x86_l_177b;
	case 6016ULL: goto x86_l_1780;
	case 6021ULL: goto x86_l_1785;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6032ULL: goto x86_l_1790;
	case 6038ULL: goto x86_l_1796;
	case 6042ULL: goto x86_l_179a;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6062ULL: goto x86_l_17ae;
	case 6065ULL: goto x86_l_17b1;
	case 6069ULL: goto x86_l_17b5;
	case 6075ULL: goto x86_l_17bb;
	case 6079ULL: goto x86_l_17bf;
	case 6085ULL: goto x86_l_17c5;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6099ULL: goto x86_l_17d3;
	case 6102ULL: goto x86_l_17d6;
	case 6106ULL: goto x86_l_17da;
	case 6112ULL: goto x86_l_17e0;
	case 6116ULL: goto x86_l_17e4;
	case 6122ULL: goto x86_l_17ea;
	case 6127ULL: goto x86_l_17ef;
	case 6132ULL: goto x86_l_17f4;
	case 6136ULL: goto x86_l_17f8;
	case 6139ULL: goto x86_l_17fb;
	case 6143ULL: goto x86_l_17ff;
	case 6149ULL: goto x86_l_1805;
	case 6153ULL: goto x86_l_1809;
	case 6159ULL: goto x86_l_180f;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6173ULL: goto x86_l_181d;
	case 6176ULL: goto x86_l_1820;
	case 6180ULL: goto x86_l_1824;
	case 6186ULL: goto x86_l_182a;
	case 6190ULL: goto x86_l_182e;
	case 6196ULL: goto x86_l_1834;
	case 6201ULL: goto x86_l_1839;
	case 6206ULL: goto x86_l_183e;
	case 6210ULL: goto x86_l_1842;
	case 6213ULL: goto x86_l_1845;
	case 6217ULL: goto x86_l_1849;
	case 6223ULL: goto x86_l_184f;
	case 6227ULL: goto x86_l_1853;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6247ULL: goto x86_l_1867;
	case 6250ULL: goto x86_l_186a;
	case 6254ULL: goto x86_l_186e;
	case 6260ULL: goto x86_l_1874;
	case 6264ULL: goto x86_l_1878;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6284ULL: goto x86_l_188c;
	case 6287ULL: goto x86_l_188f;
	case 6291ULL: goto x86_l_1893;
	case 6297ULL: goto x86_l_1899;
	case 6301ULL: goto x86_l_189d;
	case 6307ULL: goto x86_l_18a3;
	case 6312ULL: goto x86_l_18a8;
	case 6317ULL: goto x86_l_18ad;
	case 6321ULL: goto x86_l_18b1;
	case 6324ULL: goto x86_l_18b4;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6338ULL: goto x86_l_18c2;
	case 6344ULL: goto x86_l_18c8;
	case 6349ULL: goto x86_l_18cd;
	case 6354ULL: goto x86_l_18d2;
	case 6358ULL: goto x86_l_18d6;
	case 6361ULL: goto x86_l_18d9;
	case 6365ULL: goto x86_l_18dd;
	case 6371ULL: goto x86_l_18e3;
	case 6375ULL: goto x86_l_18e7;
	case 6381ULL: goto x86_l_18ed;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6395ULL: goto x86_l_18fb;
	case 6398ULL: goto x86_l_18fe;
	case 6402ULL: goto x86_l_1902;
	case 6408ULL: goto x86_l_1908;
	case 6412ULL: goto x86_l_190c;
	case 6418ULL: goto x86_l_1912;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6432ULL: goto x86_l_1920;
	case 6435ULL: goto x86_l_1923;
	case 6439ULL: goto x86_l_1927;
	case 6445ULL: goto x86_l_192d;
	case 6449ULL: goto x86_l_1931;
	case 6455ULL: goto x86_l_1937;
	case 6460ULL: goto x86_l_193c;
	case 6465ULL: goto x86_l_1941;
	case 6469ULL: goto x86_l_1945;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6482ULL: goto x86_l_1952;
	case 6486ULL: goto x86_l_1956;
	case 6492ULL: goto x86_l_195c;
	case 6497ULL: goto x86_l_1961;
	case 6502ULL: goto x86_l_1966;
	case 6506ULL: goto x86_l_196a;
	case 6509ULL: goto x86_l_196d;
	case 6513ULL: goto x86_l_1971;
	case 6519ULL: goto x86_l_1977;
	case 6523ULL: goto x86_l_197b;
	case 6529ULL: goto x86_l_1981;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6543ULL: goto x86_l_198f;
	case 6546ULL: goto x86_l_1992;
	case 6550ULL: goto x86_l_1996;
	case 6556ULL: goto x86_l_199c;
	case 6560ULL: goto x86_l_19a0;
	case 6566ULL: goto x86_l_19a6;
	case 6571ULL: goto x86_l_19ab;
	case 6576ULL: goto x86_l_19b0;
	case 6580ULL: goto x86_l_19b4;
	case 6583ULL: goto x86_l_19b7;
	case 6587ULL: goto x86_l_19bb;
	case 6593ULL: goto x86_l_19c1;
	case 6597ULL: goto x86_l_19c5;
	case 6603ULL: goto x86_l_19cb;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6617ULL: goto x86_l_19d9;
	case 6620ULL: goto x86_l_19dc;
	case 6624ULL: goto x86_l_19e0;
	case 6630ULL: goto x86_l_19e6;
	case 6634ULL: goto x86_l_19ea;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6654ULL: goto x86_l_19fe;
	case 6657ULL: goto x86_l_1a01;
	case 6661ULL: goto x86_l_1a05;
	case 6667ULL: goto x86_l_1a0b;
	case 6671ULL: goto x86_l_1a0f;
	case 6677ULL: goto x86_l_1a15;
	case 6682ULL: goto x86_l_1a1a;
	case 6687ULL: goto x86_l_1a1f;
	case 6691ULL: goto x86_l_1a23;
	case 6694ULL: goto x86_l_1a26;
	case 6698ULL: goto x86_l_1a2a;
	case 6704ULL: goto x86_l_1a30;
	case 6708ULL: goto x86_l_1a34;
	case 6714ULL: goto x86_l_1a3a;
	case 6719ULL: goto x86_l_1a3f;
	case 6724ULL: goto x86_l_1a44;
	case 6728ULL: goto x86_l_1a48;
	case 6731ULL: goto x86_l_1a4b;
	case 6735ULL: goto x86_l_1a4f;
	case 6741ULL: goto x86_l_1a55;
	case 6745ULL: goto x86_l_1a59;
	case 6751ULL: goto x86_l_1a5f;
	case 6756ULL: goto x86_l_1a64;
	case 6761ULL: goto x86_l_1a69;
	case 6765ULL: goto x86_l_1a6d;
	case 6768ULL: goto x86_l_1a70;
	case 6772ULL: goto x86_l_1a74;
	case 6778ULL: goto x86_l_1a7a;
	case 6782ULL: goto x86_l_1a7e;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6798ULL: goto x86_l_1a8e;
	case 6802ULL: goto x86_l_1a92;
	case 6805ULL: goto x86_l_1a95;
	case 6809ULL: goto x86_l_1a99;
	case 6815ULL: goto x86_l_1a9f;
	case 6819ULL: goto x86_l_1aa3;
	case 6825ULL: goto x86_l_1aa9;
	case 6830ULL: goto x86_l_1aae;
	case 6835ULL: goto x86_l_1ab3;
	case 6839ULL: goto x86_l_1ab7;
	case 6842ULL: goto x86_l_1aba;
	case 6846ULL: goto x86_l_1abe;
	case 6848ULL: goto x86_l_1ac0;
	case 6852ULL: goto x86_l_1ac4;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6872ULL: goto x86_l_1ad8;
	case 6875ULL: goto x86_l_1adb;
	case 6879ULL: goto x86_l_1adf;
	case 6881ULL: goto x86_l_1ae1;
	case 6885ULL: goto x86_l_1ae5;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6901ULL: goto x86_l_1af5;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6912ULL: goto x86_l_1b00;
	case 6914ULL: goto x86_l_1b02;
	case 6918ULL: goto x86_l_1b06;
	case 6924ULL: goto x86_l_1b0c;
	case 6930ULL: goto x86_l_1b12;
	case 6935ULL: goto x86_l_1b17;
	case 6939ULL: goto x86_l_1b1b;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6955ULL: goto x86_l_1b2b;
	case 6958ULL: goto x86_l_1b2e;
	case 6964ULL: goto x86_l_1b34;
	case 6966ULL: goto x86_l_1b36;
	case 6976ULL: goto x86_l_1b40;
	case 6980ULL: goto x86_l_1b44;
	case 6982ULL: goto x86_l_1b46;
	case 6986ULL: goto x86_l_1b4a;
	case 6989ULL: goto x86_l_1b4d;
	case 6995ULL: goto x86_l_1b53;
	case 7000ULL: goto x86_l_1b58;
	case 7003ULL: goto x86_l_1b5b;
	case 7009ULL: goto x86_l_1b61;
	case 7013ULL: goto x86_l_1b65;
	case 7016ULL: goto x86_l_1b68;
	case 7019ULL: goto x86_l_1b6b;
	case 7025ULL: goto x86_l_1b71;
	case 7028ULL: goto x86_l_1b74;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7048ULL: goto x86_l_1b88;
	case 7054ULL: goto x86_l_1b8e;
	case 7058ULL: goto x86_l_1b92;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14b6:
	/* 0x14b6: lea    eax,[rdx+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_14bc:
	/* 0x14bc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14c1:
	/* 0x14c1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c6:
	/* 0x14c6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14ca:
	/* 0x14ca: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_14cd:
	/* 0x14cd: cmp    rdx,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 50ULL);
x86_l_14d1:
	/* 0x14d1: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_14d7:
	/* 0x14d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14db:
	/* 0x14db: lea    eax,[rdx+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_14e1:
	/* 0x14e1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14e6:
	/* 0x14e6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14eb:
	/* 0x14eb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14ef:
	/* 0x14ef: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_14f2:
	/* 0x14f2: cmp    rdx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 51ULL);
x86_l_14f6:
	/* 0x14f6: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_14fc:
	/* 0x14fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1500:
	/* 0x1500: lea    eax,[rdx+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_1506:
	/* 0x1506: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_150b:
	/* 0x150b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1510:
	/* 0x1510: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1514:
	/* 0x1514: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_1517:
	/* 0x1517: cmp    rdx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 52ULL);
x86_l_151b:
	/* 0x151b: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1521:
	/* 0x1521: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1525:
	/* 0x1525: lea    eax,[rdx+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_152b:
	/* 0x152b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1530:
	/* 0x1530: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1535:
	/* 0x1535: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1539:
	/* 0x1539: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_153c:
	/* 0x153c: cmp    rdx,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 53ULL);
x86_l_1540:
	/* 0x1540: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1546:
	/* 0x1546: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154a:
	/* 0x154a: lea    eax,[rdx+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_1550:
	/* 0x1550: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1555:
	/* 0x1555: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_155a:
	/* 0x155a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_155e:
	/* 0x155e: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_1561:
	/* 0x1561: cmp    rdx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 54ULL);
x86_l_1565:
	/* 0x1565: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_156b:
	/* 0x156b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156f:
	/* 0x156f: lea    eax,[rdx+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_1575:
	/* 0x1575: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_157a:
	/* 0x157a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157f:
	/* 0x157f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1583:
	/* 0x1583: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1586:
	/* 0x1586: cmp    rdx,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 55ULL);
x86_l_158a:
	/* 0x158a: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1590:
	/* 0x1590: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1594:
	/* 0x1594: lea    eax,[rdx+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_159a:
	/* 0x159a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_159f:
	/* 0x159f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15a4:
	/* 0x15a4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15a8:
	/* 0x15a8: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_15ab:
	/* 0x15ab: cmp    rdx,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 56ULL);
x86_l_15af:
	/* 0x15af: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_15b5:
	/* 0x15b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b9:
	/* 0x15b9: lea    eax,[rdx+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_15bf:
	/* 0x15bf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15c4:
	/* 0x15c4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15c9:
	/* 0x15c9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15cd:
	/* 0x15cd: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_15d0:
	/* 0x15d0: cmp    rdx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 57ULL);
x86_l_15d4:
	/* 0x15d4: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_15da:
	/* 0x15da: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15de:
	/* 0x15de: lea    eax,[rdx+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_15e4:
	/* 0x15e4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15e9:
	/* 0x15e9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ee:
	/* 0x15ee: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15f2:
	/* 0x15f2: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_15f5:
	/* 0x15f5: cmp    rdx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 58ULL);
x86_l_15f9:
	/* 0x15f9: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_15ff:
	/* 0x15ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1603:
	/* 0x1603: lea    eax,[rdx+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_1609:
	/* 0x1609: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_160e:
	/* 0x160e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1613:
	/* 0x1613: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1617:
	/* 0x1617: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_161a:
	/* 0x161a: cmp    rdx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 59ULL);
x86_l_161e:
	/* 0x161e: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1624:
	/* 0x1624: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1628:
	/* 0x1628: lea    eax,[rdx+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_162e:
	/* 0x162e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1633:
	/* 0x1633: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1638:
	/* 0x1638: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_163c:
	/* 0x163c: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_163f:
	/* 0x163f: cmp    rdx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 60ULL);
x86_l_1643:
	/* 0x1643: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1649:
	/* 0x1649: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_164d:
	/* 0x164d: lea    eax,[rdx+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_1653:
	/* 0x1653: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1658:
	/* 0x1658: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165d:
	/* 0x165d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1661:
	/* 0x1661: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1664:
	/* 0x1664: cmp    rdx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 61ULL);
x86_l_1668:
	/* 0x1668: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_166e:
	/* 0x166e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1672:
	/* 0x1672: lea    eax,[rdx+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_1678:
	/* 0x1678: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_167d:
	/* 0x167d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1682:
	/* 0x1682: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1686:
	/* 0x1686: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_1689:
	/* 0x1689: cmp    rdx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 62ULL);
x86_l_168d:
	/* 0x168d: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1693:
	/* 0x1693: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1697:
	/* 0x1697: lea    eax,[rdx+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_169d:
	/* 0x169d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16a2:
	/* 0x16a2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16a7:
	/* 0x16a7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16ab:
	/* 0x16ab: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_16ae:
	/* 0x16ae: cmp    rdx,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 63ULL);
x86_l_16b2:
	/* 0x16b2: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_16b8:
	/* 0x16b8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bc:
	/* 0x16bc: lea    eax,[rdx+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_16c2:
	/* 0x16c2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16c7:
	/* 0x16c7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16cc:
	/* 0x16cc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16d0:
	/* 0x16d0: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_16d3:
	/* 0x16d3: cmp    rdx,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 64ULL);
x86_l_16d7:
	/* 0x16d7: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_16dd:
	/* 0x16dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e1:
	/* 0x16e1: lea    eax,[rdx+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_16e7:
	/* 0x16e7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16ec:
	/* 0x16ec: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f1:
	/* 0x16f1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16f5:
	/* 0x16f5: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_16f8:
	/* 0x16f8: cmp    rdx,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 65ULL);
x86_l_16fc:
	/* 0x16fc: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1702:
	/* 0x1702: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1706:
	/* 0x1706: lea    eax,[rdx+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_170c:
	/* 0x170c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1711:
	/* 0x1711: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1716:
	/* 0x1716: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_171a:
	/* 0x171a: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_171d:
	/* 0x171d: cmp    rdx,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 66ULL);
x86_l_1721:
	/* 0x1721: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1727:
	/* 0x1727: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_172b:
	/* 0x172b: lea    eax,[rdx+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_1731:
	/* 0x1731: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1736:
	/* 0x1736: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_173b:
	/* 0x173b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_173f:
	/* 0x173f: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_1742:
	/* 0x1742: cmp    rdx,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 67ULL);
x86_l_1746:
	/* 0x1746: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_174c:
	/* 0x174c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1750:
	/* 0x1750: lea    eax,[rdx+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_1756:
	/* 0x1756: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_175b:
	/* 0x175b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1760:
	/* 0x1760: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1764:
	/* 0x1764: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_1767:
	/* 0x1767: cmp    rdx,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 68ULL);
x86_l_176b:
	/* 0x176b: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1771:
	/* 0x1771: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1775:
	/* 0x1775: lea    eax,[rdx+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_177b:
	/* 0x177b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1780:
	/* 0x1780: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1785:
	/* 0x1785: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1789:
	/* 0x1789: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_178c:
	/* 0x178c: cmp    rdx,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 69ULL);
x86_l_1790:
	/* 0x1790: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1796:
	/* 0x1796: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_179a:
	/* 0x179a: lea    eax,[rdx+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_17a0:
	/* 0x17a0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17a5:
	/* 0x17a5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17aa:
	/* 0x17aa: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17ae:
	/* 0x17ae: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_17b1:
	/* 0x17b1: cmp    rdx,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 70ULL);
x86_l_17b5:
	/* 0x17b5: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_17bb:
	/* 0x17bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17bf:
	/* 0x17bf: lea    eax,[rdx+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_17c5:
	/* 0x17c5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17ca:
	/* 0x17ca: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17cf:
	/* 0x17cf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17d3:
	/* 0x17d3: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_17d6:
	/* 0x17d6: cmp    rdx,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 71ULL);
x86_l_17da:
	/* 0x17da: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_17e0:
	/* 0x17e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17e4:
	/* 0x17e4: lea    eax,[rdx+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_17ea:
	/* 0x17ea: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17ef:
	/* 0x17ef: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f4:
	/* 0x17f4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17f8:
	/* 0x17f8: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_17fb:
	/* 0x17fb: cmp    rdx,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 72ULL);
x86_l_17ff:
	/* 0x17ff: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1805:
	/* 0x1805: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1809:
	/* 0x1809: lea    eax,[rdx+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_180f:
	/* 0x180f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1814:
	/* 0x1814: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1819:
	/* 0x1819: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_181d:
	/* 0x181d: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1820:
	/* 0x1820: cmp    rdx,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 73ULL);
x86_l_1824:
	/* 0x1824: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_182a:
	/* 0x182a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_182e:
	/* 0x182e: lea    eax,[rdx+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_1834:
	/* 0x1834: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1839:
	/* 0x1839: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_183e:
	/* 0x183e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1842:
	/* 0x1842: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_1845:
	/* 0x1845: cmp    rdx,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 74ULL);
x86_l_1849:
	/* 0x1849: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_184f:
	/* 0x184f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1853:
	/* 0x1853: lea    eax,[rdx+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_1859:
	/* 0x1859: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_185e:
	/* 0x185e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1863:
	/* 0x1863: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1867:
	/* 0x1867: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_186a:
	/* 0x186a: cmp    rdx,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 75ULL);
x86_l_186e:
	/* 0x186e: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1874:
	/* 0x1874: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1878:
	/* 0x1878: lea    eax,[rdx+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_187e:
	/* 0x187e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1883:
	/* 0x1883: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1888:
	/* 0x1888: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_188c:
	/* 0x188c: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_188f:
	/* 0x188f: cmp    rdx,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 76ULL);
x86_l_1893:
	/* 0x1893: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1899:
	/* 0x1899: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189d:
	/* 0x189d: lea    eax,[rdx+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_18a3:
	/* 0x18a3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18a8:
	/* 0x18a8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18ad:
	/* 0x18ad: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18b1:
	/* 0x18b1: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18b4:
	/* 0x18b4: cmp    rdx,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 77ULL);
x86_l_18b8:
	/* 0x18b8: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_18be:
	/* 0x18be: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18c2:
	/* 0x18c2: lea    eax,[rdx+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_18c8:
	/* 0x18c8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18cd:
	/* 0x18cd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d2:
	/* 0x18d2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18d6:
	/* 0x18d6: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_18d9:
	/* 0x18d9: cmp    rdx,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 78ULL);
x86_l_18dd:
	/* 0x18dd: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_18e3:
	/* 0x18e3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e7:
	/* 0x18e7: lea    eax,[rdx+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_18ed:
	/* 0x18ed: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18f2:
	/* 0x18f2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f7:
	/* 0x18f7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18fb:
	/* 0x18fb: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_18fe:
	/* 0x18fe: cmp    rdx,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 79ULL);
x86_l_1902:
	/* 0x1902: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1908:
	/* 0x1908: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190c:
	/* 0x190c: lea    eax,[rdx+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_1912:
	/* 0x1912: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1917:
	/* 0x1917: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191c:
	/* 0x191c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1920:
	/* 0x1920: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_1923:
	/* 0x1923: cmp    rdx,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 80ULL);
x86_l_1927:
	/* 0x1927: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_192d:
	/* 0x192d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1931:
	/* 0x1931: lea    eax,[rdx+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_1937:
	/* 0x1937: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_193c:
	/* 0x193c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1941:
	/* 0x1941: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1945:
	/* 0x1945: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1948:
	/* 0x1948: cmp    rdx,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 81ULL);
x86_l_194c:
	/* 0x194c: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1952:
	/* 0x1952: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1956:
	/* 0x1956: lea    eax,[rdx+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_195c:
	/* 0x195c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1961:
	/* 0x1961: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1966:
	/* 0x1966: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_196a:
	/* 0x196a: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_196d:
	/* 0x196d: cmp    rdx,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 82ULL);
x86_l_1971:
	/* 0x1971: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1977:
	/* 0x1977: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197b:
	/* 0x197b: lea    eax,[rdx+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_1981:
	/* 0x1981: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1986:
	/* 0x1986: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_198b:
	/* 0x198b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_198f:
	/* 0x198f: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1992:
	/* 0x1992: cmp    rdx,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 83ULL);
x86_l_1996:
	/* 0x1996: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_199c:
	/* 0x199c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a0:
	/* 0x19a0: lea    eax,[rdx+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_19a6:
	/* 0x19a6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19ab:
	/* 0x19ab: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19b0:
	/* 0x19b0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19b4:
	/* 0x19b4: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_19b7:
	/* 0x19b7: cmp    rdx,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 84ULL);
x86_l_19bb:
	/* 0x19bb: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_19c1:
	/* 0x19c1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19c5:
	/* 0x19c5: lea    eax,[rdx+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_19cb:
	/* 0x19cb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19d0:
	/* 0x19d0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d5:
	/* 0x19d5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19d9:
	/* 0x19d9: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_19dc:
	/* 0x19dc: cmp    rdx,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 85ULL);
x86_l_19e0:
	/* 0x19e0: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_19e6:
	/* 0x19e6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ea:
	/* 0x19ea: lea    eax,[rdx+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_19f0:
	/* 0x19f0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19f5:
	/* 0x19f5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19fa:
	/* 0x19fa: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19fe:
	/* 0x19fe: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_1a01:
	/* 0x1a01: cmp    rdx,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 86ULL);
x86_l_1a05:
	/* 0x1a05: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1a0b:
	/* 0x1a0b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a0f:
	/* 0x1a0f: lea    eax,[rdx+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_1a15:
	/* 0x1a15: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a1a:
	/* 0x1a1a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a1f:
	/* 0x1a1f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a23:
	/* 0x1a23: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_1a26:
	/* 0x1a26: cmp    rdx,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 87ULL);
x86_l_1a2a:
	/* 0x1a2a: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1a30:
	/* 0x1a30: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a34:
	/* 0x1a34: lea    eax,[rdx+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_1a3a:
	/* 0x1a3a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a3f:
	/* 0x1a3f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a44:
	/* 0x1a44: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a48:
	/* 0x1a48: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_1a4b:
	/* 0x1a4b: cmp    rdx,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 88ULL);
x86_l_1a4f:
	/* 0x1a4f: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1a55:
	/* 0x1a55: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a59:
	/* 0x1a59: lea    eax,[rdx+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_1a5f:
	/* 0x1a5f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a64:
	/* 0x1a64: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a69:
	/* 0x1a69: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1a70:
	/* 0x1a70: cmp    rdx,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 89ULL);
x86_l_1a74:
	/* 0x1a74: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1a7a:
	/* 0x1a7a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7e:
	/* 0x1a7e: lea    eax,[rdx+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_1a84:
	/* 0x1a84: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a89:
	/* 0x1a89: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a8e:
	/* 0x1a8e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a92:
	/* 0x1a92: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_1a95:
	/* 0x1a95: cmp    rdx,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 90ULL);
x86_l_1a99:
	/* 0x1a99: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1a9f:
	/* 0x1a9f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa3:
	/* 0x1aa3: lea    eax,[rdx+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_1aa9:
	/* 0x1aa9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1aae:
	/* 0x1aae: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab3:
	/* 0x1ab3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_1aba:
	/* 0x1aba: cmp    rdx,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 91ULL);
x86_l_1abe:
	/* 0x1abe: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1ac0:
	/* 0x1ac0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac4:
	/* 0x1ac4: lea    eax,[rdx+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_1aca:
	/* 0x1aca: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1acf:
	/* 0x1acf: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad4:
	/* 0x1ad4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_1adb:
	/* 0x1adb: cmp    rdx,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 92ULL);
x86_l_1adf:
	/* 0x1adf: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1ae1:
	/* 0x1ae1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae5:
	/* 0x1ae5: lea    eax,[rdx+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_1aeb:
	/* 0x1aeb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1af0:
	/* 0x1af0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af5:
	/* 0x1af5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1af9:
	/* 0x1af9: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1afc:
	/* 0x1afc: cmp    rdx,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 93ULL);
x86_l_1b00:
	/* 0x1b00: je     1b1e <generic_fexit_filter_arg+0x1b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1e;
	}
x86_l_1b02:
	/* 0x1b02: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b06:
	/* 0x1b06: add    ecx,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_1b0c:
	/* 0x1b0c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b12:
	/* 0x1b12: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b17:
	/* 0x1b17: movzx  eax,BYTE PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b23:
	/* 0x1b23: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b26:
	/* 0x1b26: jmp    3721 <generic_fexit_filter_arg+0x3721> */
	return 14113ULL;
x86_l_1b2b:
	/* 0x1b2b: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_1b2e:
	/* 0x1b2e: ja     375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14171ULL;
	}
x86_l_1b34:
	/* 0x1b34: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b36:
	/* 0x1b36: movabs rcx,0x1e10000c00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 129117457408ULL);
x86_l_1b40:
	/* 0x1b40: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1b44:
	/* 0x1b44: jae    1b7f <generic_fexit_filter_arg+0x1b7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b7f;
	}
x86_l_1b46:
	/* 0x1b46: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b4a:
	/* 0x1b4a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1b4d:
	/* 0x1b4d: ja     3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14181ULL;
	}
x86_l_1b53:
	/* 0x1b53: mov    ecx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4126ULL);
x86_l_1b58:
	/* 0x1b58: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1b5b:
	/* 0x1b5b: jae    1be1 <generic_fexit_filter_arg+0x1be1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7137ULL;
	}
x86_l_1b61:
	/* 0x1b61: mov    rdx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b65:
	/* 0x1b65: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1b68:
	/* 0x1b68: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b6b:
	/* 0x1b6b: jae    1c4a <generic_fexit_filter_arg+0x1c4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7242ULL;
	}
x86_l_1b71:
	/* 0x1b71: cmp    QWORD PTR [r8],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b74:
	/* 0x1b74: jne    1c58 <generic_fexit_filter_arg+0x1c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7256ULL;
	}
x86_l_1b7a:
	/* 0x1b7a: jmp    350c <generic_fexit_filter_arg+0x350c> */
	return 13580ULL;
x86_l_1b7f:
	/* 0x1b7f: mov    ecx,0x3012 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12306ULL);
x86_l_1b84:
	/* 0x1b84: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1b88:
	/* 0x1b88: jae    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14171ULL;
	}
x86_l_1b8e:
	/* 0x1b8e: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b92:
	/* 0x1b92: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
	return 7061ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7061ULL: goto x86_l_1b95;
	case 7067ULL: goto x86_l_1b9b;
	case 7072ULL: goto x86_l_1ba0;
	case 7075ULL: goto x86_l_1ba3;
	case 7081ULL: goto x86_l_1ba9;
	case 7085ULL: goto x86_l_1bad;
	case 7088ULL: goto x86_l_1bb0;
	case 7091ULL: goto x86_l_1bb3;
	case 7097ULL: goto x86_l_1bb9;
	case 7100ULL: goto x86_l_1bbc;
	case 7106ULL: goto x86_l_1bc2;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7126ULL: goto x86_l_1bd6;
	case 7132ULL: goto x86_l_1bdc;
	case 7137ULL: goto x86_l_1be1;
	case 7142ULL: goto x86_l_1be6;
	case 7145ULL: goto x86_l_1be9;
	case 7151ULL: goto x86_l_1bef;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7163ULL: goto x86_l_1bfb;
	case 7170ULL: goto x86_l_1c02;
	case 7175ULL: goto x86_l_1c07;
	case 7180ULL: goto x86_l_1c0c;
	case 7182ULL: goto x86_l_1c0e;
	case 7185ULL: goto x86_l_1c11;
	case 7191ULL: goto x86_l_1c17;
	case 7194ULL: goto x86_l_1c1a;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7215ULL: goto x86_l_1c2f;
	case 7219ULL: goto x86_l_1c33;
	case 7222ULL: goto x86_l_1c36;
	case 7228ULL: goto x86_l_1c3c;
	case 7231ULL: goto x86_l_1c3f;
	case 7237ULL: goto x86_l_1c45;
	case 7242ULL: goto x86_l_1c4a;
	case 7245ULL: goto x86_l_1c4d;
	case 7247ULL: goto x86_l_1c4f;
	case 7250ULL: goto x86_l_1c52;
	case 7256ULL: goto x86_l_1c58;
	case 7260ULL: goto x86_l_1c5c;
	case 7263ULL: goto x86_l_1c5f;
	case 7269ULL: goto x86_l_1c65;
	case 7273ULL: goto x86_l_1c69;
	case 7276ULL: goto x86_l_1c6c;
	case 7282ULL: goto x86_l_1c72;
	case 7285ULL: goto x86_l_1c75;
	case 7291ULL: goto x86_l_1c7b;
	case 7296ULL: goto x86_l_1c80;
	case 7299ULL: goto x86_l_1c83;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7318ULL: goto x86_l_1c96;
	case 7324ULL: goto x86_l_1c9c;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7336ULL: goto x86_l_1ca8;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7355ULL: goto x86_l_1cbb;
	case 7358ULL: goto x86_l_1cbe;
	case 7364ULL: goto x86_l_1cc4;
	case 7367ULL: goto x86_l_1cc7;
	case 7371ULL: goto x86_l_1ccb;
	case 7376ULL: goto x86_l_1cd0;
	case 7381ULL: goto x86_l_1cd5;
	case 7386ULL: goto x86_l_1cda;
	case 7391ULL: goto x86_l_1cdf;
	case 7394ULL: goto x86_l_1ce2;
	case 7396ULL: goto x86_l_1ce4;
	case 7399ULL: goto x86_l_1ce7;
	case 7405ULL: goto x86_l_1ced;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7418ULL: goto x86_l_1cfa;
	case 7422ULL: goto x86_l_1cfe;
	case 7425ULL: goto x86_l_1d01;
	case 7431ULL: goto x86_l_1d07;
	case 7434ULL: goto x86_l_1d0a;
	case 7440ULL: goto x86_l_1d10;
	case 7445ULL: goto x86_l_1d15;
	case 7449ULL: goto x86_l_1d19;
	case 7452ULL: goto x86_l_1d1c;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7461ULL: goto x86_l_1d25;
	case 7463ULL: goto x86_l_1d27;
	case 7466ULL: goto x86_l_1d2a;
	case 7469ULL: goto x86_l_1d2d;
	case 7475ULL: goto x86_l_1d33;
	case 7478ULL: goto x86_l_1d36;
	case 7484ULL: goto x86_l_1d3c;
	case 7486ULL: goto x86_l_1d3e;
	case 7491ULL: goto x86_l_1d43;
	case 7495ULL: goto x86_l_1d47;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7510ULL: goto x86_l_1d56;
	case 7516ULL: goto x86_l_1d5c;
	case 7526ULL: goto x86_l_1d66;
	case 7530ULL: goto x86_l_1d6a;
	case 7536ULL: goto x86_l_1d70;
	case 7543ULL: goto x86_l_1d77;
	case 7550ULL: goto x86_l_1d7e;
	case 7556ULL: goto x86_l_1d84;
	case 7559ULL: goto x86_l_1d87;
	case 7564ULL: goto x86_l_1d8c;
	case 7568ULL: goto x86_l_1d90;
	case 7572ULL: goto x86_l_1d94;
	case 7580ULL: goto x86_l_1d9c;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7599ULL: goto x86_l_1daf;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7619ULL: goto x86_l_1dc3;
	case 7625ULL: goto x86_l_1dc9;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7642ULL: goto x86_l_1dda;
	case 7644ULL: goto x86_l_1ddc;
	case 7647ULL: goto x86_l_1ddf;
	case 7653ULL: goto x86_l_1de5;
	case 7657ULL: goto x86_l_1de9;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7678ULL: goto x86_l_1dfe;
	case 7680ULL: goto x86_l_1e00;
	case 7683ULL: goto x86_l_1e03;
	case 7687ULL: goto x86_l_1e07;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7700ULL: goto x86_l_1e14;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7710ULL: goto x86_l_1e1e;
	case 7713ULL: goto x86_l_1e21;
	case 7718ULL: goto x86_l_1e26;
	case 7726ULL: goto x86_l_1e2e;
	case 7732ULL: goto x86_l_1e34;
	case 7738ULL: goto x86_l_1e3a;
	case 7741ULL: goto x86_l_1e3d;
	case 7747ULL: goto x86_l_1e43;
	case 7750ULL: goto x86_l_1e46;
	case 7753ULL: goto x86_l_1e49;
	case 7756ULL: goto x86_l_1e4c;
	case 7758ULL: goto x86_l_1e4e;
	case 7760ULL: goto x86_l_1e50;
	case 7763ULL: goto x86_l_1e53;
	case 7769ULL: goto x86_l_1e59;
	case 7771ULL: goto x86_l_1e5b;
	case 7777ULL: goto x86_l_1e61;
	case 7782ULL: goto x86_l_1e66;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7796ULL: goto x86_l_1e74;
	case 7801ULL: goto x86_l_1e79;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7814ULL: goto x86_l_1e86;
	case 7819ULL: goto x86_l_1e8b;
	case 7824ULL: goto x86_l_1e90;
	case 7826ULL: goto x86_l_1e92;
	case 7830ULL: goto x86_l_1e96;
	case 7833ULL: goto x86_l_1e99;
	case 7836ULL: goto x86_l_1e9c;
	case 7838ULL: goto x86_l_1e9e;
	case 7841ULL: goto x86_l_1ea1;
	case 7843ULL: goto x86_l_1ea3;
	case 7846ULL: goto x86_l_1ea6;
	case 7849ULL: goto x86_l_1ea9;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7861ULL: goto x86_l_1eb5;
	case 7867ULL: goto x86_l_1ebb;
	case 7872ULL: goto x86_l_1ec0;
	case 7875ULL: goto x86_l_1ec3;
	case 7877ULL: goto x86_l_1ec5;
	case 7880ULL: goto x86_l_1ec8;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7895ULL: goto x86_l_1ed7;
	case 7898ULL: goto x86_l_1eda;
	case 7904ULL: goto x86_l_1ee0;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7917ULL: goto x86_l_1eed;
	case 7923ULL: goto x86_l_1ef3;
	case 7926ULL: goto x86_l_1ef6;
	case 7932ULL: goto x86_l_1efc;
	case 7935ULL: goto x86_l_1eff;
	case 7941ULL: goto x86_l_1f05;
	case 7946ULL: goto x86_l_1f0a;
	case 7949ULL: goto x86_l_1f0d;
	case 7955ULL: goto x86_l_1f13;
	case 7958ULL: goto x86_l_1f16;
	case 7964ULL: goto x86_l_1f1c;
	case 7967ULL: goto x86_l_1f1f;
	case 7973ULL: goto x86_l_1f25;
	case 7978ULL: goto x86_l_1f2a;
	case 7981ULL: goto x86_l_1f2d;
	case 7984ULL: goto x86_l_1f30;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8003ULL: goto x86_l_1f43;
	case 8010ULL: goto x86_l_1f4a;
	case 8016ULL: goto x86_l_1f50;
	case 8021ULL: goto x86_l_1f55;
	case 8025ULL: goto x86_l_1f59;
	case 8031ULL: goto x86_l_1f5f;
	case 8034ULL: goto x86_l_1f62;
	case 8037ULL: goto x86_l_1f65;
	case 8040ULL: goto x86_l_1f68;
	case 8043ULL: goto x86_l_1f6b;
	case 8045ULL: goto x86_l_1f6d;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8060ULL: goto x86_l_1f7c;
	case 8062ULL: goto x86_l_1f7e;
	case 8068ULL: goto x86_l_1f84;
	case 8071ULL: goto x86_l_1f87;
	case 8076ULL: goto x86_l_1f8c;
	case 8079ULL: goto x86_l_1f8f;
	case 8081ULL: goto x86_l_1f91;
	case 8084ULL: goto x86_l_1f94;
	case 8090ULL: goto x86_l_1f9a;
	case 8093ULL: goto x86_l_1f9d;
	case 8099ULL: goto x86_l_1fa3;
	case 8103ULL: goto x86_l_1fa7;
	case 8106ULL: goto x86_l_1faa;
	case 8112ULL: goto x86_l_1fb0;
	case 8115ULL: goto x86_l_1fb3;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8131ULL: goto x86_l_1fc3;
	case 8134ULL: goto x86_l_1fc6;
	case 8140ULL: goto x86_l_1fcc;
	case 8145ULL: goto x86_l_1fd1;
	case 8150ULL: goto x86_l_1fd6;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8164ULL: goto x86_l_1fe4;
	case 8167ULL: goto x86_l_1fe7;
	case 8169ULL: goto x86_l_1fe9;
	case 8174ULL: goto x86_l_1fee;
	case 8177ULL: goto x86_l_1ff1;
	case 8183ULL: goto x86_l_1ff7;
	case 8186ULL: goto x86_l_1ffa;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8201ULL: goto x86_l_2009;
	case 8204ULL: goto x86_l_200c;
	case 8210ULL: goto x86_l_2012;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8228ULL: goto x86_l_2024;
	case 8232ULL: goto x86_l_2028;
	case 8236ULL: goto x86_l_202c;
	case 8244ULL: goto x86_l_2034;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8264ULL: goto x86_l_2048;
	case 8266ULL: goto x86_l_204a;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8275ULL: goto x86_l_2053;
	case 8281ULL: goto x86_l_2059;
	case 8285ULL: goto x86_l_205d;
	case 8288ULL: goto x86_l_2060;
	case 8294ULL: goto x86_l_2066;
	case 8301ULL: goto x86_l_206d;
	case 8306ULL: goto x86_l_2072;
	case 8311ULL: goto x86_l_2077;
	case 8313ULL: goto x86_l_2079;
	case 8316ULL: goto x86_l_207c;
	case 8322ULL: goto x86_l_2082;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8334ULL: goto x86_l_208e;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8347ULL: goto x86_l_209b;
	case 8350ULL: goto x86_l_209e;
	case 8352ULL: goto x86_l_20a0;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8368ULL: goto x86_l_20b0;
	case 8372ULL: goto x86_l_20b4;
	case 8378ULL: goto x86_l_20ba;
	case 8385ULL: goto x86_l_20c1;
	case 8390ULL: goto x86_l_20c6;
	case 8394ULL: goto x86_l_20ca;
	case 8397ULL: goto x86_l_20cd;
	case 8401ULL: goto x86_l_20d1;
	case 8407ULL: goto x86_l_20d7;
	case 8414ULL: goto x86_l_20de;
	case 8419ULL: goto x86_l_20e3;
	case 8423ULL: goto x86_l_20e7;
	case 8426ULL: goto x86_l_20ea;
	case 8430ULL: goto x86_l_20ee;
	case 8436ULL: goto x86_l_20f4;
	case 8443ULL: goto x86_l_20fb;
	case 8448ULL: goto x86_l_2100;
	case 8452ULL: goto x86_l_2104;
	case 8455ULL: goto x86_l_2107;
	case 8459ULL: goto x86_l_210b;
	case 8465ULL: goto x86_l_2111;
	case 8472ULL: goto x86_l_2118;
	case 8477ULL: goto x86_l_211d;
	case 8481ULL: goto x86_l_2121;
	case 8484ULL: goto x86_l_2124;
	case 8488ULL: goto x86_l_2128;
	case 8494ULL: goto x86_l_212e;
	case 8501ULL: goto x86_l_2135;
	case 8506ULL: goto x86_l_213a;
	case 8510ULL: goto x86_l_213e;
	case 8513ULL: goto x86_l_2141;
	case 8517ULL: goto x86_l_2145;
	case 8523ULL: goto x86_l_214b;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8539ULL: goto x86_l_215b;
	case 8542ULL: goto x86_l_215e;
	case 8546ULL: goto x86_l_2162;
	case 8552ULL: goto x86_l_2168;
	case 8559ULL: goto x86_l_216f;
	case 8564ULL: goto x86_l_2174;
	case 8568ULL: goto x86_l_2178;
	case 8571ULL: goto x86_l_217b;
	case 8575ULL: goto x86_l_217f;
	case 8581ULL: goto x86_l_2185;
	case 8588ULL: goto x86_l_218c;
	case 8593ULL: goto x86_l_2191;
	case 8597ULL: goto x86_l_2195;
	case 8600ULL: goto x86_l_2198;
	case 8604ULL: goto x86_l_219c;
	case 8610ULL: goto x86_l_21a2;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8626ULL: goto x86_l_21b2;
	case 8629ULL: goto x86_l_21b5;
	case 8633ULL: goto x86_l_21b9;
	case 8639ULL: goto x86_l_21bf;
	case 8646ULL: goto x86_l_21c6;
	case 8651ULL: goto x86_l_21cb;
	case 8655ULL: goto x86_l_21cf;
	case 8658ULL: goto x86_l_21d2;
	case 8662ULL: goto x86_l_21d6;
	case 8668ULL: goto x86_l_21dc;
	case 8675ULL: goto x86_l_21e3;
	case 8680ULL: goto x86_l_21e8;
	case 8684ULL: goto x86_l_21ec;
	case 8687ULL: goto x86_l_21ef;
	case 8691ULL: goto x86_l_21f3;
	case 8697ULL: goto x86_l_21f9;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8713ULL: goto x86_l_2209;
	case 8716ULL: goto x86_l_220c;
	case 8720ULL: goto x86_l_2210;
	case 8726ULL: goto x86_l_2216;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8749ULL: goto x86_l_222d;
	case 8755ULL: goto x86_l_2233;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b95:
	/* 0x1b95: ja     3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14181ULL;
	}
x86_l_1b9b:
	/* 0x1b9b: mov    ecx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4126ULL);
x86_l_1ba0:
	/* 0x1ba0: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1ba3:
	/* 0x1ba3: jae    1c8e <generic_fexit_filter_arg+0x1c8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1c8e;
	}
x86_l_1ba9:
	/* 0x1ba9: mov    edx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bad:
	/* 0x1bad: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1bb0:
	/* 0x1bb0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1bb3:
	/* 0x1bb3: jae    1cdf <generic_fexit_filter_arg+0x1cdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1cdf;
	}
x86_l_1bb9:
	/* 0x1bb9: cmp    DWORD PTR [r8],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bbc:
	/* 0x1bbc: jne    1ced <generic_fexit_filter_arg+0x1ced> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ced;
	}
x86_l_1bc2:
	/* 0x1bc2: jmp    350c <generic_fexit_filter_arg+0x350c> */
	return 13580ULL;
x86_l_1bc7:
	/* 0x1bc7: cmp    eax,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 40ULL);
x86_l_1bca:
	/* 0x1bca: je     1e66 <generic_fexit_filter_arg+0x1e66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e66;
	}
x86_l_1bd0:
	/* 0x1bd0: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1bd3:
	/* 0x1bd3: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_1bd6:
	/* 0x1bd6: je     1e92 <generic_fexit_filter_arg+0x1e92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e92;
	}
x86_l_1bdc:
	/* 0x1bdc: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_1be1:
	/* 0x1be1: mov    ecx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3072ULL);
x86_l_1be6:
	/* 0x1be6: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1be9:
	/* 0x1be9: jae    3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14181ULL;
	}
x86_l_1bef:
	/* 0x1bef: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_1bf2:
	/* 0x1bf2: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1bf7:
	/* 0x1bf7: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1c02:
	/* 0x1c02: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c07:
	/* 0x1c07: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c0c:
	/* 0x1c0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0e:
	/* 0x1c0e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c11:
	/* 0x1c11: je     3333 <generic_fexit_filter_arg+0x3333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13107ULL;
	}
x86_l_1c17:
	/* 0x1c17: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c1a:
	/* 0x1c1a: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c23:
	/* 0x1c23: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c28:
	/* 0x1c28: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c2d:
	/* 0x1c2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2f:
	/* 0x1c2f: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c33:
	/* 0x1c33: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1c36:
	/* 0x1c36: je     2e33 <generic_fexit_filter_arg+0x2e33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11827ULL;
	}
x86_l_1c3c:
	/* 0x1c3c: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1c3f:
	/* 0x1c3f: je     2ee8 <generic_fexit_filter_arg+0x2ee8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12008ULL;
	}
x86_l_1c45:
	/* 0x1c45: jmp    2ef7 <generic_fexit_filter_arg+0x2ef7> */
	return 12023ULL;
x86_l_1c4a:
	/* 0x1c4a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1c4d:
	/* 0x1c4d: jne    1c58 <generic_fexit_filter_arg+0x1c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c58;
	}
x86_l_1c4f:
	/* 0x1c4f: test   QWORD PTR [r8],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c52:
	/* 0x1c52: jne    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14171ULL;
	}
x86_l_1c58:
	/* 0x1c58: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5c:
	/* 0x1c5c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c5f:
	/* 0x1c5f: jb     358b <generic_fexit_filter_arg+0x358b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13707ULL;
	}
x86_l_1c65:
	/* 0x1c65: mov    rsi,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c69:
	/* 0x1c69: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c6c:
	/* 0x1c6c: jae    1f8c <generic_fexit_filter_arg+0x1f8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f8c;
	}
x86_l_1c72:
	/* 0x1c72: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c75:
	/* 0x1c75: jne    1f9a <generic_fexit_filter_arg+0x1f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f9a;
	}
x86_l_1c7b:
	/* 0x1c7b: jmp    350c <generic_fexit_filter_arg+0x350c> */
	return 13580ULL;
x86_l_1c80:
	/* 0x1c80: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_1c83:
	/* 0x1c83: je     1d19 <generic_fexit_filter_arg+0x1d19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d19;
	}
x86_l_1c89:
	/* 0x1c89: jmp    375b <generic_fexit_filter_arg+0x375b> */
	return 14171ULL;
x86_l_1c8e:
	/* 0x1c8e: mov    ecx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3072ULL);
x86_l_1c93:
	/* 0x1c93: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1c96:
	/* 0x1c96: jae    3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14181ULL;
	}
x86_l_1c9c:
	/* 0x1c9c: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_1c9f:
	/* 0x1c9f: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ca8:
	/* 0x1ca8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1caf:
	/* 0x1caf: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cb9:
	/* 0x1cb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cbb:
	/* 0x1cbb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cbe:
	/* 0x1cbe: je     3333 <generic_fexit_filter_arg+0x3333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13107ULL;
	}
x86_l_1cc4:
	/* 0x1cc4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1cc7:
	/* 0x1cc7: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ccb:
	/* 0x1ccb: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cd0:
	/* 0x1cd0: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cd5:
	/* 0x1cd5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cda:
	/* 0x1cda: jmp    3121 <generic_fexit_filter_arg+0x3121> */
	return 12577ULL;
x86_l_1cdf:
	/* 0x1cdf: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1ce2:
	/* 0x1ce2: jne    1ced <generic_fexit_filter_arg+0x1ced> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ced;
	}
x86_l_1ce4:
	/* 0x1ce4: test   DWORD PTR [r8],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ce7:
	/* 0x1ce7: jne    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14171ULL;
	}
x86_l_1ced:
	/* 0x1ced: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf1:
	/* 0x1cf1: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1cf4:
	/* 0x1cf4: jb     358b <generic_fexit_filter_arg+0x358b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13707ULL;
	}
x86_l_1cfa:
	/* 0x1cfa: mov    esi,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1cfe:
	/* 0x1cfe: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d01:
	/* 0x1d01: jae    2dad <generic_fexit_filter_arg+0x2dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11693ULL;
	}
x86_l_1d07:
	/* 0x1d07: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d0a:
	/* 0x1d0a: jne    2dbb <generic_fexit_filter_arg+0x2dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11707ULL;
	}
x86_l_1d10:
	/* 0x1d10: jmp    350c <generic_fexit_filter_arg+0x350c> */
	return 13580ULL;
x86_l_1d15:
	/* 0x1d15: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1d19:
	/* 0x1d19: mov    r9d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d1c:
	/* 0x1d1c: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d20:
	/* 0x1d20: test   r9,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64);
x86_l_1d23:
	/* 0x1d23: jne    1d33 <generic_fexit_filter_arg+0x1d33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d33;
	}
x86_l_1d25:
	/* 0x1d25: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1d27:
	/* 0x1d27: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1d2a:
	/* 0x1d2a: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_1d2d:
	/* 0x1d2d: jne    3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14181ULL;
	}
x86_l_1d33:
	/* 0x1d33: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_1d36:
	/* 0x1d36: ja     1f2a <generic_fexit_filter_arg+0x1f2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f2a;
	}
x86_l_1d3c:
	/* 0x1d3c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1d3e:
	/* 0x1d3e: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_1d43:
	/* 0x1d43: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1d47:
	/* 0x1d47: jb     2b34 <generic_fexit_filter_arg+0x2b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11060ULL;
	}
x86_l_1d4d:
	/* 0x1d4d: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_1d52:
	/* 0x1d52: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1d56:
	/* 0x1d56: jb     201a <generic_fexit_filter_arg+0x201a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_201a;
	}
x86_l_1d5c:
	/* 0x1d5c: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_1d66:
	/* 0x1d66: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1d6a:
	/* 0x1d6a: jae    1f2a <generic_fexit_filter_arg+0x1f2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f2a;
	}
x86_l_1d70:
	/* 0x1d70: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1d77:
	/* 0x1d77: cmp    r9d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 144ULL);
x86_l_1d7e:
	/* 0x1d7e: jbe    3031 <generic_fexit_filter_arg+0x3031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12337ULL;
	}
x86_l_1d84:
	/* 0x1d84: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d87:
	/* 0x1d87: jmp    3696 <generic_fexit_filter_arg+0x3696> */
	return 13974ULL;
x86_l_1d8c:
	/* 0x1d8c: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d90:
	/* 0x1d90: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d94:
	/* 0x1d94: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1d9c:
	/* 0x1d9c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1da3:
	/* 0x1da3: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1da8:
	/* 0x1da8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dad:
	/* 0x1dad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1daf:
	/* 0x1daf: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1db2:
	/* 0x1db2: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1db7:
	/* 0x1db7: je     3610 <generic_fexit_filter_arg+0x3610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13840ULL;
	}
x86_l_1dbd:
	/* 0x1dbd: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1dc0:
	/* 0x1dc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dc3:
	/* 0x1dc3: je     3610 <generic_fexit_filter_arg+0x3610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13840ULL;
	}
x86_l_1dc9:
	/* 0x1dc9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1dd0:
	/* 0x1dd0: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1dd5:
	/* 0x1dd5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dda:
	/* 0x1dda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ddc:
	/* 0x1ddc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ddf:
	/* 0x1ddf: je     360d <generic_fexit_filter_arg+0x360d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13837ULL;
	}
x86_l_1de5:
	/* 0x1de5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1de9:
	/* 0x1de9: cmp    ecx,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_1def:
	/* 0x1def: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1df4:
	/* 0x1df4: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1df7:
	/* 0x1df7: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e00:
	/* 0x1e00: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1e03:
	/* 0x1e03: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1e07:
	/* 0x1e07: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1e0a:
	/* 0x1e0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e0f:
	/* 0x1e0f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e14:
	/* 0x1e14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e16:
	/* 0x1e16: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e1b:
	/* 0x1e1b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1e1e:
	/* 0x1e1e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1e21:
	/* 0x1e21: jmp    35ff <generic_fexit_filter_arg+0x35ff> */
	return 13823ULL;
x86_l_1e26:
	/* 0x1e26: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1e2e:
	/* 0x1e2e: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1e34:
	/* 0x1e34: ja     360d <generic_fexit_filter_arg+0x360d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13837ULL;
	}
x86_l_1e3a:
	/* 0x1e3a: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e3d:
	/* 0x1e3d: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1e43:
	/* 0x1e43: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1e46:
	/* 0x1e46: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1e49:
	/* 0x1e49: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1e4e:
	/* 0x1e4e: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1e50:
	/* 0x1e50: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1e53:
	/* 0x1e53: je     2f02 <generic_fexit_filter_arg+0x2f02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12034ULL;
	}
x86_l_1e59:
	/* 0x1e59: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1e5b:
	/* 0x1e5b: jne    2f02 <generic_fexit_filter_arg+0x2f02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12034ULL;
	}
x86_l_1e61:
	/* 0x1e61: jmp    2f19 <generic_fexit_filter_arg+0x2f19> */
	return 12057ULL;
x86_l_1e66:
	/* 0x1e66: movzx  ecx,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e6a:
	/* 0x1e6a: mov    WORD PTR [rsp+0x76],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_1e6f:
	/* 0x1e6f: movzx  ecx,WORD PTR [r8+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1e74:
	/* 0x1e74: mov    WORD PTR [rsp+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e79:
	/* 0x1e79: mov    rcx,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e7d:
	/* 0x1e7d: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e82:
	/* 0x1e82: mov    rcx,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e86:
	/* 0x1e86: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e8b:
	/* 0x1e8b: lea    r8,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e90:
	/* 0x1e90: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e92:
	/* 0x1e92: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e96:
	/* 0x1e96: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e99:
	/* 0x1e99: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1e9c:
	/* 0x1e9c: jle    1ec0 <generic_fexit_filter_arg+0x1ec0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ec0;
	}
x86_l_1e9e:
	/* 0x1e9e: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_1ea1:
	/* 0x1ea1: jg     1eea <generic_fexit_filter_arg+0x1eea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1eea;
	}
x86_l_1ea3:
	/* 0x1ea3: lea    eax,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_1ea6:
	/* 0x1ea6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ea9:
	/* 0x1ea9: jb     1fd8 <generic_fexit_filter_arg+0x1fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1fd8;
	}
x86_l_1eaf:
	/* 0x1eaf: lea    eax,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_1eb2:
	/* 0x1eb2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1eb5:
	/* 0x1eb5: jb     1fcc <generic_fexit_filter_arg+0x1fcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1fcc;
	}
x86_l_1ebb:
	/* 0x1ebb: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_1ec0:
	/* 0x1ec0: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_1ec3:
	/* 0x1ec3: jle    1f0a <generic_fexit_filter_arg+0x1f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f0a;
	}
x86_l_1ec5:
	/* 0x1ec5: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1ec8:
	/* 0x1ec8: jg     1fbe <generic_fexit_filter_arg+0x1fbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1fbe;
	}
x86_l_1ece:
	/* 0x1ece: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1ed1:
	/* 0x1ed1: je     1fcc <generic_fexit_filter_arg+0x1fcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fcc;
	}
x86_l_1ed7:
	/* 0x1ed7: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1eda:
	/* 0x1eda: jne    3756 <generic_fexit_filter_arg+0x3756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14166ULL;
	}
x86_l_1ee0:
	/* 0x1ee0: movzx  r12d,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1ee5:
	/* 0x1ee5: jmp    30e6 <generic_fexit_filter_arg+0x30e6> */
	return 12518ULL;
x86_l_1eea:
	/* 0x1eea: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_1eed:
	/* 0x1eed: jg     1fee <generic_fexit_filter_arg+0x1fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1fee;
	}
x86_l_1ef3:
	/* 0x1ef3: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1ef6:
	/* 0x1ef6: je     2bef <generic_fexit_filter_arg+0x2bef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11247ULL;
	}
x86_l_1efc:
	/* 0x1efc: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_1eff:
	/* 0x1eff: je     2be0 <generic_fexit_filter_arg+0x2be0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11232ULL;
	}
x86_l_1f05:
	/* 0x1f05: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_1f0a:
	/* 0x1f0a: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1f0d:
	/* 0x1f0d: je     2bef <generic_fexit_filter_arg+0x2bef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11247ULL;
	}
x86_l_1f13:
	/* 0x1f13: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1f16:
	/* 0x1f16: je     2be0 <generic_fexit_filter_arg+0x2be0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11232ULL;
	}
x86_l_1f1c:
	/* 0x1f1c: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_1f1f:
	/* 0x1f1f: je     1fd8 <generic_fexit_filter_arg+0x1fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fd8;
	}
x86_l_1f25:
	/* 0x1f25: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_1f2a:
	/* 0x1f2a: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1f2d:
	/* 0x1f2d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1f30:
	/* 0x1f30: jae    3029 <generic_fexit_filter_arg+0x3029> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12329ULL;
	}
x86_l_1f36:
	/* 0x1f36: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1f43:
	/* 0x1f43: cmp    r9d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 144ULL);
x86_l_1f4a:
	/* 0x1f4a: ja     368e <generic_fexit_filter_arg+0x368e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13966ULL;
	}
x86_l_1f50:
	/* 0x1f50: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f55:
	/* 0x1f55: movzx  eax,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f59:
	/* 0x1f59: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1f5f:
	/* 0x1f5f: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1f62:
	/* 0x1f62: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1f65:
	/* 0x1f65: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1f68:
	/* 0x1f68: mov    eax,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R9, X86_WIDTH_32);
x86_l_1f6b:
	/* 0x1f6b: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1f6d:
	/* 0x1f6d: test   r9w,r9w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_16);
x86_l_1f71:
	/* 0x1f71: mov    QWORD PTR [rsp+0x18],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f76:
	/* 0x1f76: je     31b3 <generic_fexit_filter_arg+0x31b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12723ULL;
	}
x86_l_1f7c:
	/* 0x1f7c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1f7e:
	/* 0x1f7e: jne    31b3 <generic_fexit_filter_arg+0x31b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12723ULL;
	}
x86_l_1f84:
	/* 0x1f84: mov    edx,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R9, X86_WIDTH_32);
x86_l_1f87:
	/* 0x1f87: jmp    31cb <generic_fexit_filter_arg+0x31cb> */
	return 12747ULL;
x86_l_1f8c:
	/* 0x1f8c: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1f8f:
	/* 0x1f8f: jne    1f9a <generic_fexit_filter_arg+0x1f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f9a;
	}
x86_l_1f91:
	/* 0x1f91: test   QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f94:
	/* 0x1f94: jne    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14171ULL;
	}
x86_l_1f9a:
	/* 0x1f9a: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1f9d:
	/* 0x1f9d: jb     358b <generic_fexit_filter_arg+0x358b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13707ULL;
	}
x86_l_1fa3:
	/* 0x1fa3: mov    rsi,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fa7:
	/* 0x1fa7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1faa:
	/* 0x1faa: jae    3159 <generic_fexit_filter_arg+0x3159> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12633ULL;
	}
x86_l_1fb0:
	/* 0x1fb0: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fb3:
	/* 0x1fb3: jne    3167 <generic_fexit_filter_arg+0x3167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12647ULL;
	}
x86_l_1fb9:
	/* 0x1fb9: jmp    350c <generic_fexit_filter_arg+0x350c> */
	return 13580ULL;
x86_l_1fbe:
	/* 0x1fbe: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_1fc1:
	/* 0x1fc1: je     1fd8 <generic_fexit_filter_arg+0x1fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fd8;
	}
x86_l_1fc3:
	/* 0x1fc3: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1fc6:
	/* 0x1fc6: jne    3756 <generic_fexit_filter_arg+0x3756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14166ULL;
	}
x86_l_1fcc:
	/* 0x1fcc: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd1:
	/* 0x1fd1: movzx  esi,WORD PTR [r8+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1fd6:
	/* 0x1fd6: jmp    1fe2 <generic_fexit_filter_arg+0x1fe2> */
	goto x86_l_1fe2;
x86_l_1fd8:
	/* 0x1fd8: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fdd:
	/* 0x1fdd: movzx  esi,WORD PTR [r8+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1fe2:
	/* 0x1fe2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fe4:
	/* 0x1fe4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fe7:
	/* 0x1fe7: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fe9:
	/* 0x1fe9: jmp    2c04 <generic_fexit_filter_arg+0x2c04> */
	return 11268ULL;
x86_l_1fee:
	/* 0x1fee: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_1ff1:
	/* 0x1ff1: je     30e1 <generic_fexit_filter_arg+0x30e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12513ULL;
	}
x86_l_1ff7:
	/* 0x1ff7: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_1ffa:
	/* 0x1ffa: jne    3756 <generic_fexit_filter_arg+0x3756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14166ULL;
	}
x86_l_2000:
	/* 0x2000: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2003:
	/* 0x2003: jne    32dc <generic_fexit_filter_arg+0x32dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13020ULL;
	}
x86_l_2009:
	/* 0x2009: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_200c:
	/* 0x200c: jne    32e9 <generic_fexit_filter_arg+0x32e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13033ULL;
	}
x86_l_2012:
	/* 0x2012: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2015:
	/* 0x2015: jmp    32f8 <generic_fexit_filter_arg+0x32f8> */
	return 13048ULL;
x86_l_201a:
	/* 0x201a: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_201f:
	/* 0x201f: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2024:
	/* 0x2024: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2028:
	/* 0x2028: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_202c:
	/* 0x202c: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2034:
	/* 0x2034: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_203b:
	/* 0x203b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2040:
	/* 0x2040: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2045:
	/* 0x2045: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_2048:
	/* 0x2048: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204a:
	/* 0x204a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_204d:
	/* 0x204d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2050:
	/* 0x2050: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2053:
	/* 0x2053: je     3691 <generic_fexit_filter_arg+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13969ULL;
	}
x86_l_2059:
	/* 0x2059: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_205d:
	/* 0x205d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2060:
	/* 0x2060: je     3691 <generic_fexit_filter_arg+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13969ULL;
	}
x86_l_2066:
	/* 0x2066: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_206d:
	/* 0x206d: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2072:
	/* 0x2072: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2077:
	/* 0x2077: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2079:
	/* 0x2079: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_207c:
	/* 0x207c: je     368e <generic_fexit_filter_arg+0x368e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13966ULL;
	}
x86_l_2082:
	/* 0x2082: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2085:
	/* 0x2085: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_208a:
	/* 0x208a: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_208e:
	/* 0x208e: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_2092:
	/* 0x2092: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_2097:
	/* 0x2097: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_209b:
	/* 0x209b: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_209e:
	/* 0x209e: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a0:
	/* 0x20a0: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_20a4:
	/* 0x20a4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20a9:
	/* 0x20a9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20ad:
	/* 0x20ad: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20b0:
	/* 0x20b0: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_20b4:
	/* 0x20b4: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_20ba:
	/* 0x20ba: lea    eax,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_20c1:
	/* 0x20c1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20c6:
	/* 0x20c6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20ca:
	/* 0x20ca: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_20cd:
	/* 0x20cd: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_20d1:
	/* 0x20d1: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_20d7:
	/* 0x20d7: lea    eax,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_20de:
	/* 0x20de: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20e3:
	/* 0x20e3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20e7:
	/* 0x20e7: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_20ea:
	/* 0x20ea: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_20ee:
	/* 0x20ee: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_20f4:
	/* 0x20f4: lea    eax,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_20fb:
	/* 0x20fb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2100:
	/* 0x2100: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2104:
	/* 0x2104: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_2107:
	/* 0x2107: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_210b:
	/* 0x210b: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2111:
	/* 0x2111: lea    eax,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_2118:
	/* 0x2118: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_211d:
	/* 0x211d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2121:
	/* 0x2121: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2124:
	/* 0x2124: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2128:
	/* 0x2128: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_212e:
	/* 0x212e: lea    eax,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_2135:
	/* 0x2135: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_213a:
	/* 0x213a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_213e:
	/* 0x213e: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_2141:
	/* 0x2141: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_2145:
	/* 0x2145: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_214b:
	/* 0x214b: lea    eax,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_2152:
	/* 0x2152: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2157:
	/* 0x2157: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_215b:
	/* 0x215b: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_215e:
	/* 0x215e: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2162:
	/* 0x2162: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2168:
	/* 0x2168: lea    eax,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_216f:
	/* 0x216f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2174:
	/* 0x2174: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2178:
	/* 0x2178: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_217b:
	/* 0x217b: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_217f:
	/* 0x217f: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2185:
	/* 0x2185: lea    eax,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_218c:
	/* 0x218c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2191:
	/* 0x2191: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2195:
	/* 0x2195: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2198:
	/* 0x2198: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_219c:
	/* 0x219c: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_21a2:
	/* 0x21a2: lea    eax,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_21a9:
	/* 0x21a9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21ae:
	/* 0x21ae: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21b2:
	/* 0x21b2: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_21b5:
	/* 0x21b5: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_21b9:
	/* 0x21b9: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_21bf:
	/* 0x21bf: lea    eax,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_21c6:
	/* 0x21c6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21cb:
	/* 0x21cb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21cf:
	/* 0x21cf: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_21d2:
	/* 0x21d2: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_21d6:
	/* 0x21d6: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_21dc:
	/* 0x21dc: lea    eax,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_21e3:
	/* 0x21e3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21e8:
	/* 0x21e8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21ec:
	/* 0x21ec: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_21ef:
	/* 0x21ef: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_21f3:
	/* 0x21f3: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_21f9:
	/* 0x21f9: lea    eax,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_2200:
	/* 0x2200: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2205:
	/* 0x2205: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2209:
	/* 0x2209: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220c:
	/* 0x220c: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_2210:
	/* 0x2210: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2216:
	/* 0x2216: lea    eax,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_221d:
	/* 0x221d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2222:
	/* 0x2222: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2226:
	/* 0x2226: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_2229:
	/* 0x2229: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_222d:
	/* 0x222d: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2233:
	/* 0x2233: lea    eax,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
	return 8762ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8771ULL: goto x86_l_2243;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8784ULL: goto x86_l_2250;
	case 8791ULL: goto x86_l_2257;
	case 8796ULL: goto x86_l_225c;
	case 8800ULL: goto x86_l_2260;
	case 8803ULL: goto x86_l_2263;
	case 8807ULL: goto x86_l_2267;
	case 8813ULL: goto x86_l_226d;
	case 8820ULL: goto x86_l_2274;
	case 8825ULL: goto x86_l_2279;
	case 8829ULL: goto x86_l_227d;
	case 8832ULL: goto x86_l_2280;
	case 8836ULL: goto x86_l_2284;
	case 8842ULL: goto x86_l_228a;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8858ULL: goto x86_l_229a;
	case 8861ULL: goto x86_l_229d;
	case 8865ULL: goto x86_l_22a1;
	case 8871ULL: goto x86_l_22a7;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8887ULL: goto x86_l_22b7;
	case 8890ULL: goto x86_l_22ba;
	case 8894ULL: goto x86_l_22be;
	case 8900ULL: goto x86_l_22c4;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8916ULL: goto x86_l_22d4;
	case 8919ULL: goto x86_l_22d7;
	case 8923ULL: goto x86_l_22db;
	case 8929ULL: goto x86_l_22e1;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8952ULL: goto x86_l_22f8;
	case 8958ULL: goto x86_l_22fe;
	case 8965ULL: goto x86_l_2305;
	case 8970ULL: goto x86_l_230a;
	case 8974ULL: goto x86_l_230e;
	case 8977ULL: goto x86_l_2311;
	case 8981ULL: goto x86_l_2315;
	case 8987ULL: goto x86_l_231b;
	case 8994ULL: goto x86_l_2322;
	case 8999ULL: goto x86_l_2327;
	case 9003ULL: goto x86_l_232b;
	case 9006ULL: goto x86_l_232e;
	case 9010ULL: goto x86_l_2332;
	case 9016ULL: goto x86_l_2338;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9032ULL: goto x86_l_2348;
	case 9035ULL: goto x86_l_234b;
	case 9039ULL: goto x86_l_234f;
	case 9045ULL: goto x86_l_2355;
	case 9052ULL: goto x86_l_235c;
	case 9057ULL: goto x86_l_2361;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9074ULL: goto x86_l_2372;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9090ULL: goto x86_l_2382;
	case 9093ULL: goto x86_l_2385;
	case 9097ULL: goto x86_l_2389;
	case 9103ULL: goto x86_l_238f;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9126ULL: goto x86_l_23a6;
	case 9132ULL: goto x86_l_23ac;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9148ULL: goto x86_l_23bc;
	case 9151ULL: goto x86_l_23bf;
	case 9155ULL: goto x86_l_23c3;
	case 9161ULL: goto x86_l_23c9;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9177ULL: goto x86_l_23d9;
	case 9180ULL: goto x86_l_23dc;
	case 9184ULL: goto x86_l_23e0;
	case 9190ULL: goto x86_l_23e6;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9206ULL: goto x86_l_23f6;
	case 9209ULL: goto x86_l_23f9;
	case 9213ULL: goto x86_l_23fd;
	case 9219ULL: goto x86_l_2403;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9238ULL: goto x86_l_2416;
	case 9242ULL: goto x86_l_241a;
	case 9248ULL: goto x86_l_2420;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9264ULL: goto x86_l_2430;
	case 9267ULL: goto x86_l_2433;
	case 9271ULL: goto x86_l_2437;
	case 9277ULL: goto x86_l_243d;
	case 9284ULL: goto x86_l_2444;
	case 9289ULL: goto x86_l_2449;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9300ULL: goto x86_l_2454;
	case 9306ULL: goto x86_l_245a;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9322ULL: goto x86_l_246a;
	case 9325ULL: goto x86_l_246d;
	case 9329ULL: goto x86_l_2471;
	case 9335ULL: goto x86_l_2477;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9351ULL: goto x86_l_2487;
	case 9354ULL: goto x86_l_248a;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9380ULL: goto x86_l_24a4;
	case 9383ULL: goto x86_l_24a7;
	case 9387ULL: goto x86_l_24ab;
	case 9393ULL: goto x86_l_24b1;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9409ULL: goto x86_l_24c1;
	case 9412ULL: goto x86_l_24c4;
	case 9416ULL: goto x86_l_24c8;
	case 9422ULL: goto x86_l_24ce;
	case 9429ULL: goto x86_l_24d5;
	case 9434ULL: goto x86_l_24da;
	case 9438ULL: goto x86_l_24de;
	case 9441ULL: goto x86_l_24e1;
	case 9445ULL: goto x86_l_24e5;
	case 9451ULL: goto x86_l_24eb;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9467ULL: goto x86_l_24fb;
	case 9470ULL: goto x86_l_24fe;
	case 9474ULL: goto x86_l_2502;
	case 9480ULL: goto x86_l_2508;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9499ULL: goto x86_l_251b;
	case 9503ULL: goto x86_l_251f;
	case 9509ULL: goto x86_l_2525;
	case 9516ULL: goto x86_l_252c;
	case 9521ULL: goto x86_l_2531;
	case 9525ULL: goto x86_l_2535;
	case 9528ULL: goto x86_l_2538;
	case 9532ULL: goto x86_l_253c;
	case 9538ULL: goto x86_l_2542;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9554ULL: goto x86_l_2552;
	case 9557ULL: goto x86_l_2555;
	case 9561ULL: goto x86_l_2559;
	case 9567ULL: goto x86_l_255f;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9583ULL: goto x86_l_256f;
	case 9586ULL: goto x86_l_2572;
	case 9590ULL: goto x86_l_2576;
	case 9596ULL: goto x86_l_257c;
	case 9603ULL: goto x86_l_2583;
	case 9608ULL: goto x86_l_2588;
	case 9612ULL: goto x86_l_258c;
	case 9615ULL: goto x86_l_258f;
	case 9619ULL: goto x86_l_2593;
	case 9625ULL: goto x86_l_2599;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9641ULL: goto x86_l_25a9;
	case 9644ULL: goto x86_l_25ac;
	case 9648ULL: goto x86_l_25b0;
	case 9654ULL: goto x86_l_25b6;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9670ULL: goto x86_l_25c6;
	case 9673ULL: goto x86_l_25c9;
	case 9677ULL: goto x86_l_25cd;
	case 9683ULL: goto x86_l_25d3;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9699ULL: goto x86_l_25e3;
	case 9702ULL: goto x86_l_25e6;
	case 9706ULL: goto x86_l_25ea;
	case 9712ULL: goto x86_l_25f0;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9728ULL: goto x86_l_2600;
	case 9731ULL: goto x86_l_2603;
	case 9735ULL: goto x86_l_2607;
	case 9741ULL: goto x86_l_260d;
	case 9748ULL: goto x86_l_2614;
	case 9753ULL: goto x86_l_2619;
	case 9757ULL: goto x86_l_261d;
	case 9760ULL: goto x86_l_2620;
	case 9764ULL: goto x86_l_2624;
	case 9770ULL: goto x86_l_262a;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9786ULL: goto x86_l_263a;
	case 9789ULL: goto x86_l_263d;
	case 9793ULL: goto x86_l_2641;
	case 9799ULL: goto x86_l_2647;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9815ULL: goto x86_l_2657;
	case 9818ULL: goto x86_l_265a;
	case 9822ULL: goto x86_l_265e;
	case 9828ULL: goto x86_l_2664;
	case 9835ULL: goto x86_l_266b;
	case 9840ULL: goto x86_l_2670;
	case 9844ULL: goto x86_l_2674;
	case 9847ULL: goto x86_l_2677;
	case 9851ULL: goto x86_l_267b;
	case 9857ULL: goto x86_l_2681;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9873ULL: goto x86_l_2691;
	case 9876ULL: goto x86_l_2694;
	case 9880ULL: goto x86_l_2698;
	case 9886ULL: goto x86_l_269e;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9902ULL: goto x86_l_26ae;
	case 9905ULL: goto x86_l_26b1;
	case 9909ULL: goto x86_l_26b5;
	case 9915ULL: goto x86_l_26bb;
	case 9922ULL: goto x86_l_26c2;
	case 9927ULL: goto x86_l_26c7;
	case 9931ULL: goto x86_l_26cb;
	case 9934ULL: goto x86_l_26ce;
	case 9938ULL: goto x86_l_26d2;
	case 9944ULL: goto x86_l_26d8;
	case 9951ULL: goto x86_l_26df;
	case 9956ULL: goto x86_l_26e4;
	case 9960ULL: goto x86_l_26e8;
	case 9963ULL: goto x86_l_26eb;
	case 9967ULL: goto x86_l_26ef;
	case 9973ULL: goto x86_l_26f5;
	case 9980ULL: goto x86_l_26fc;
	case 9985ULL: goto x86_l_2701;
	case 9989ULL: goto x86_l_2705;
	case 9992ULL: goto x86_l_2708;
	case 9996ULL: goto x86_l_270c;
	case 10002ULL: goto x86_l_2712;
	case 10009ULL: goto x86_l_2719;
	case 10014ULL: goto x86_l_271e;
	case 10018ULL: goto x86_l_2722;
	case 10021ULL: goto x86_l_2725;
	case 10025ULL: goto x86_l_2729;
	case 10031ULL: goto x86_l_272f;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10047ULL: goto x86_l_273f;
	case 10050ULL: goto x86_l_2742;
	case 10054ULL: goto x86_l_2746;
	case 10060ULL: goto x86_l_274c;
	case 10067ULL: goto x86_l_2753;
	case 10072ULL: goto x86_l_2758;
	case 10076ULL: goto x86_l_275c;
	case 10079ULL: goto x86_l_275f;
	case 10083ULL: goto x86_l_2763;
	case 10089ULL: goto x86_l_2769;
	case 10096ULL: goto x86_l_2770;
	case 10101ULL: goto x86_l_2775;
	case 10105ULL: goto x86_l_2779;
	case 10108ULL: goto x86_l_277c;
	case 10112ULL: goto x86_l_2780;
	case 10118ULL: goto x86_l_2786;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10134ULL: goto x86_l_2796;
	case 10137ULL: goto x86_l_2799;
	case 10141ULL: goto x86_l_279d;
	case 10147ULL: goto x86_l_27a3;
	case 10154ULL: goto x86_l_27aa;
	case 10159ULL: goto x86_l_27af;
	case 10163ULL: goto x86_l_27b3;
	case 10166ULL: goto x86_l_27b6;
	case 10170ULL: goto x86_l_27ba;
	case 10176ULL: goto x86_l_27c0;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10192ULL: goto x86_l_27d0;
	case 10195ULL: goto x86_l_27d3;
	case 10199ULL: goto x86_l_27d7;
	case 10205ULL: goto x86_l_27dd;
	case 10212ULL: goto x86_l_27e4;
	case 10217ULL: goto x86_l_27e9;
	case 10221ULL: goto x86_l_27ed;
	case 10224ULL: goto x86_l_27f0;
	case 10228ULL: goto x86_l_27f4;
	case 10234ULL: goto x86_l_27fa;
	case 10241ULL: goto x86_l_2801;
	case 10246ULL: goto x86_l_2806;
	case 10250ULL: goto x86_l_280a;
	case 10253ULL: goto x86_l_280d;
	case 10257ULL: goto x86_l_2811;
	case 10263ULL: goto x86_l_2817;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10279ULL: goto x86_l_2827;
	case 10282ULL: goto x86_l_282a;
	case 10286ULL: goto x86_l_282e;
	case 10292ULL: goto x86_l_2834;
	case 10299ULL: goto x86_l_283b;
	case 10304ULL: goto x86_l_2840;
	case 10308ULL: goto x86_l_2844;
	case 10311ULL: goto x86_l_2847;
	case 10315ULL: goto x86_l_284b;
	case 10321ULL: goto x86_l_2851;
	case 10328ULL: goto x86_l_2858;
	case 10333ULL: goto x86_l_285d;
	case 10337ULL: goto x86_l_2861;
	case 10340ULL: goto x86_l_2864;
	case 10344ULL: goto x86_l_2868;
	case 10350ULL: goto x86_l_286e;
	case 10357ULL: goto x86_l_2875;
	case 10362ULL: goto x86_l_287a;
	case 10366ULL: goto x86_l_287e;
	case 10369ULL: goto x86_l_2881;
	case 10373ULL: goto x86_l_2885;
	case 10379ULL: goto x86_l_288b;
	case 10386ULL: goto x86_l_2892;
	case 10391ULL: goto x86_l_2897;
	case 10395ULL: goto x86_l_289b;
	case 10398ULL: goto x86_l_289e;
	case 10402ULL: goto x86_l_28a2;
	case 10408ULL: goto x86_l_28a8;
	case 10415ULL: goto x86_l_28af;
	case 10420ULL: goto x86_l_28b4;
	case 10424ULL: goto x86_l_28b8;
	case 10427ULL: goto x86_l_28bb;
	case 10431ULL: goto x86_l_28bf;
	case 10437ULL: goto x86_l_28c5;
	case 10444ULL: goto x86_l_28cc;
	case 10449ULL: goto x86_l_28d1;
	case 10453ULL: goto x86_l_28d5;
	case 10456ULL: goto x86_l_28d8;
	case 10460ULL: goto x86_l_28dc;
	case 10466ULL: goto x86_l_28e2;
	case 10473ULL: goto x86_l_28e9;
	case 10478ULL: goto x86_l_28ee;
	case 10482ULL: goto x86_l_28f2;
	case 10485ULL: goto x86_l_28f5;
	case 10489ULL: goto x86_l_28f9;
	case 10495ULL: goto x86_l_28ff;
	case 10502ULL: goto x86_l_2906;
	case 10507ULL: goto x86_l_290b;
	case 10511ULL: goto x86_l_290f;
	case 10514ULL: goto x86_l_2912;
	case 10518ULL: goto x86_l_2916;
	case 10524ULL: goto x86_l_291c;
	case 10531ULL: goto x86_l_2923;
	case 10536ULL: goto x86_l_2928;
	case 10540ULL: goto x86_l_292c;
	case 10543ULL: goto x86_l_292f;
	case 10547ULL: goto x86_l_2933;
	case 10553ULL: goto x86_l_2939;
	case 10560ULL: goto x86_l_2940;
	case 10565ULL: goto x86_l_2945;
	case 10569ULL: goto x86_l_2949;
	case 10572ULL: goto x86_l_294c;
	case 10576ULL: goto x86_l_2950;
	case 10582ULL: goto x86_l_2956;
	case 10589ULL: goto x86_l_295d;
	case 10594ULL: goto x86_l_2962;
	case 10598ULL: goto x86_l_2966;
	case 10601ULL: goto x86_l_2969;
	case 10605ULL: goto x86_l_296d;
	case 10611ULL: goto x86_l_2973;
	default: return 0xffffffffffffffffULL;
	}
x86_l_223a:
	/* 0x223a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_223f:
	/* 0x223f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2243:
	/* 0x2243: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_2246:
	/* 0x2246: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_224a:
	/* 0x224a: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2250:
	/* 0x2250: lea    eax,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_2257:
	/* 0x2257: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_225c:
	/* 0x225c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2260:
	/* 0x2260: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_2263:
	/* 0x2263: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_2267:
	/* 0x2267: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_226d:
	/* 0x226d: lea    eax,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_2274:
	/* 0x2274: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2279:
	/* 0x2279: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_227d:
	/* 0x227d: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2280:
	/* 0x2280: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_2284:
	/* 0x2284: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_228a:
	/* 0x228a: lea    eax,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_2291:
	/* 0x2291: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2296:
	/* 0x2296: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_229a:
	/* 0x229a: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_229d:
	/* 0x229d: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_22a1:
	/* 0x22a1: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_22a7:
	/* 0x22a7: lea    eax,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_22ae:
	/* 0x22ae: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22b3:
	/* 0x22b3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22b7:
	/* 0x22b7: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_22ba:
	/* 0x22ba: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_22be:
	/* 0x22be: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_22c4:
	/* 0x22c4: lea    eax,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_22cb:
	/* 0x22cb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22d0:
	/* 0x22d0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22d4:
	/* 0x22d4: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_22d7:
	/* 0x22d7: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_22db:
	/* 0x22db: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_22e1:
	/* 0x22e1: lea    eax,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_22e8:
	/* 0x22e8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22ed:
	/* 0x22ed: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22f1:
	/* 0x22f1: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22f4:
	/* 0x22f4: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_22f8:
	/* 0x22f8: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_22fe:
	/* 0x22fe: lea    eax,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_2305:
	/* 0x2305: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_230a:
	/* 0x230a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_230e:
	/* 0x230e: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_2311:
	/* 0x2311: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_2315:
	/* 0x2315: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_231b:
	/* 0x231b: lea    eax,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_2322:
	/* 0x2322: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2327:
	/* 0x2327: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_232b:
	/* 0x232b: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_232e:
	/* 0x232e: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_2332:
	/* 0x2332: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2338:
	/* 0x2338: lea    eax,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_233f:
	/* 0x233f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2344:
	/* 0x2344: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2348:
	/* 0x2348: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_234b:
	/* 0x234b: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_234f:
	/* 0x234f: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2355:
	/* 0x2355: lea    eax,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_235c:
	/* 0x235c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2361:
	/* 0x2361: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2365:
	/* 0x2365: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2368:
	/* 0x2368: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_236c:
	/* 0x236c: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2372:
	/* 0x2372: lea    eax,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_2379:
	/* 0x2379: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_237e:
	/* 0x237e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2382:
	/* 0x2382: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_2385:
	/* 0x2385: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_2389:
	/* 0x2389: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_238f:
	/* 0x238f: lea    eax,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_2396:
	/* 0x2396: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_239b:
	/* 0x239b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_239f:
	/* 0x239f: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_23a2:
	/* 0x23a2: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_23a6:
	/* 0x23a6: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_23ac:
	/* 0x23ac: lea    eax,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_23b3:
	/* 0x23b3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23b8:
	/* 0x23b8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23bc:
	/* 0x23bc: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_23bf:
	/* 0x23bf: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_23c3:
	/* 0x23c3: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_23c9:
	/* 0x23c9: lea    eax,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_23d0:
	/* 0x23d0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23d5:
	/* 0x23d5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23d9:
	/* 0x23d9: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23dc:
	/* 0x23dc: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_23e0:
	/* 0x23e0: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_23e6:
	/* 0x23e6: lea    eax,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_23ed:
	/* 0x23ed: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23f2:
	/* 0x23f2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23f6:
	/* 0x23f6: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_23f9:
	/* 0x23f9: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_23fd:
	/* 0x23fd: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2403:
	/* 0x2403: lea    eax,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_240a:
	/* 0x240a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_240f:
	/* 0x240f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2413:
	/* 0x2413: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2416:
	/* 0x2416: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_241a:
	/* 0x241a: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2420:
	/* 0x2420: lea    eax,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_2427:
	/* 0x2427: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_242c:
	/* 0x242c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2430:
	/* 0x2430: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_2433:
	/* 0x2433: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_2437:
	/* 0x2437: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_243d:
	/* 0x243d: lea    eax,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_2444:
	/* 0x2444: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2449:
	/* 0x2449: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_244d:
	/* 0x244d: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2450:
	/* 0x2450: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_2454:
	/* 0x2454: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_245a:
	/* 0x245a: lea    eax,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_2461:
	/* 0x2461: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2466:
	/* 0x2466: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_246a:
	/* 0x246a: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_246d:
	/* 0x246d: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_2471:
	/* 0x2471: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2477:
	/* 0x2477: lea    eax,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_247e:
	/* 0x247e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2483:
	/* 0x2483: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2487:
	/* 0x2487: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_248a:
	/* 0x248a: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_248e:
	/* 0x248e: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2494:
	/* 0x2494: lea    eax,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_249b:
	/* 0x249b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24a0:
	/* 0x24a0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24a4:
	/* 0x24a4: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_24a7:
	/* 0x24a7: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_24ab:
	/* 0x24ab: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_24b1:
	/* 0x24b1: lea    eax,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_24b8:
	/* 0x24b8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24bd:
	/* 0x24bd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24c1:
	/* 0x24c1: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24c4:
	/* 0x24c4: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_24c8:
	/* 0x24c8: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_24ce:
	/* 0x24ce: lea    eax,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_24d5:
	/* 0x24d5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24da:
	/* 0x24da: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24de:
	/* 0x24de: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_24e1:
	/* 0x24e1: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_24e5:
	/* 0x24e5: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_24eb:
	/* 0x24eb: lea    eax,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_24f2:
	/* 0x24f2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24f7:
	/* 0x24f7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24fb:
	/* 0x24fb: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_24fe:
	/* 0x24fe: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_2502:
	/* 0x2502: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2508:
	/* 0x2508: lea    eax,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_250f:
	/* 0x250f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2514:
	/* 0x2514: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2518:
	/* 0x2518: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_251b:
	/* 0x251b: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_251f:
	/* 0x251f: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2525:
	/* 0x2525: lea    eax,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_252c:
	/* 0x252c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2531:
	/* 0x2531: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2535:
	/* 0x2535: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2538:
	/* 0x2538: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_253c:
	/* 0x253c: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2542:
	/* 0x2542: lea    eax,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_2549:
	/* 0x2549: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_254e:
	/* 0x254e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2552:
	/* 0x2552: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_2555:
	/* 0x2555: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_2559:
	/* 0x2559: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_255f:
	/* 0x255f: lea    eax,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_2566:
	/* 0x2566: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_256b:
	/* 0x256b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_256f:
	/* 0x256f: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_2572:
	/* 0x2572: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_2576:
	/* 0x2576: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_257c:
	/* 0x257c: lea    eax,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_2583:
	/* 0x2583: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2588:
	/* 0x2588: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_258c:
	/* 0x258c: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_258f:
	/* 0x258f: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_2593:
	/* 0x2593: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2599:
	/* 0x2599: lea    eax,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_25a0:
	/* 0x25a0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25a5:
	/* 0x25a5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25a9:
	/* 0x25a9: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25ac:
	/* 0x25ac: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_25b0:
	/* 0x25b0: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_25b6:
	/* 0x25b6: lea    eax,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_25bd:
	/* 0x25bd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25c2:
	/* 0x25c2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25c6:
	/* 0x25c6: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_25c9:
	/* 0x25c9: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_25cd:
	/* 0x25cd: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_25d3:
	/* 0x25d3: lea    eax,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_25da:
	/* 0x25da: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25df:
	/* 0x25df: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25e3:
	/* 0x25e3: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_25e6:
	/* 0x25e6: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_25ea:
	/* 0x25ea: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_25f0:
	/* 0x25f0: lea    eax,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_25f7:
	/* 0x25f7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25fc:
	/* 0x25fc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2600:
	/* 0x2600: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_2603:
	/* 0x2603: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_2607:
	/* 0x2607: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_260d:
	/* 0x260d: lea    eax,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_2614:
	/* 0x2614: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2619:
	/* 0x2619: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_261d:
	/* 0x261d: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2620:
	/* 0x2620: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_2624:
	/* 0x2624: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_262a:
	/* 0x262a: lea    eax,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_2631:
	/* 0x2631: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2636:
	/* 0x2636: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_263a:
	/* 0x263a: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_263d:
	/* 0x263d: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_2641:
	/* 0x2641: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2647:
	/* 0x2647: lea    eax,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_264e:
	/* 0x264e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2653:
	/* 0x2653: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2657:
	/* 0x2657: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_265a:
	/* 0x265a: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_265e:
	/* 0x265e: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2664:
	/* 0x2664: lea    eax,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_266b:
	/* 0x266b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2670:
	/* 0x2670: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2674:
	/* 0x2674: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_2677:
	/* 0x2677: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_267b:
	/* 0x267b: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2681:
	/* 0x2681: lea    eax,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_2688:
	/* 0x2688: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_268d:
	/* 0x268d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2691:
	/* 0x2691: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2694:
	/* 0x2694: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_2698:
	/* 0x2698: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_269e:
	/* 0x269e: lea    eax,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_26a5:
	/* 0x26a5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26aa:
	/* 0x26aa: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26ae:
	/* 0x26ae: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_26b1:
	/* 0x26b1: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_26b5:
	/* 0x26b5: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_26bb:
	/* 0x26bb: lea    eax,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_26c2:
	/* 0x26c2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26c7:
	/* 0x26c7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26cb:
	/* 0x26cb: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_26ce:
	/* 0x26ce: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_26d2:
	/* 0x26d2: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_26d8:
	/* 0x26d8: lea    eax,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_26df:
	/* 0x26df: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26e4:
	/* 0x26e4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26e8:
	/* 0x26e8: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_26eb:
	/* 0x26eb: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_26ef:
	/* 0x26ef: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_26f5:
	/* 0x26f5: lea    eax,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_26fc:
	/* 0x26fc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2701:
	/* 0x2701: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2705:
	/* 0x2705: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2708:
	/* 0x2708: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_270c:
	/* 0x270c: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2712:
	/* 0x2712: lea    eax,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_2719:
	/* 0x2719: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_271e:
	/* 0x271e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2722:
	/* 0x2722: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_2725:
	/* 0x2725: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_2729:
	/* 0x2729: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_272f:
	/* 0x272f: lea    eax,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_2736:
	/* 0x2736: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_273b:
	/* 0x273b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_273f:
	/* 0x273f: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_2742:
	/* 0x2742: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_2746:
	/* 0x2746: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_274c:
	/* 0x274c: lea    eax,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_2753:
	/* 0x2753: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2758:
	/* 0x2758: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_275c:
	/* 0x275c: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_275f:
	/* 0x275f: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_2763:
	/* 0x2763: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2769:
	/* 0x2769: lea    eax,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_2770:
	/* 0x2770: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2775:
	/* 0x2775: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2779:
	/* 0x2779: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_277c:
	/* 0x277c: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_2780:
	/* 0x2780: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2786:
	/* 0x2786: lea    eax,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_278d:
	/* 0x278d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2792:
	/* 0x2792: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2796:
	/* 0x2796: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_2799:
	/* 0x2799: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_279d:
	/* 0x279d: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_27a3:
	/* 0x27a3: lea    eax,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_27aa:
	/* 0x27aa: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27af:
	/* 0x27af: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_27b3:
	/* 0x27b3: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_27b6:
	/* 0x27b6: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_27ba:
	/* 0x27ba: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_27c0:
	/* 0x27c0: lea    eax,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_27c7:
	/* 0x27c7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27cc:
	/* 0x27cc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_27d0:
	/* 0x27d0: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_27d3:
	/* 0x27d3: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_27d7:
	/* 0x27d7: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_27dd:
	/* 0x27dd: lea    eax,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_27e4:
	/* 0x27e4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27e9:
	/* 0x27e9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_27ed:
	/* 0x27ed: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_27f0:
	/* 0x27f0: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_27f4:
	/* 0x27f4: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_27fa:
	/* 0x27fa: lea    eax,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_2801:
	/* 0x2801: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2806:
	/* 0x2806: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_280a:
	/* 0x280a: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_280d:
	/* 0x280d: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_2811:
	/* 0x2811: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2817:
	/* 0x2817: lea    eax,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_281e:
	/* 0x281e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2823:
	/* 0x2823: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2827:
	/* 0x2827: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_282a:
	/* 0x282a: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_282e:
	/* 0x282e: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2834:
	/* 0x2834: lea    eax,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_283b:
	/* 0x283b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2840:
	/* 0x2840: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2844:
	/* 0x2844: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_2847:
	/* 0x2847: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_284b:
	/* 0x284b: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2851:
	/* 0x2851: lea    eax,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_2858:
	/* 0x2858: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_285d:
	/* 0x285d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2861:
	/* 0x2861: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2864:
	/* 0x2864: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_2868:
	/* 0x2868: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_286e:
	/* 0x286e: lea    eax,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_2875:
	/* 0x2875: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_287a:
	/* 0x287a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_287e:
	/* 0x287e: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_2881:
	/* 0x2881: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_2885:
	/* 0x2885: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_288b:
	/* 0x288b: lea    eax,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_2892:
	/* 0x2892: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2897:
	/* 0x2897: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_289b:
	/* 0x289b: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_289e:
	/* 0x289e: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_28a2:
	/* 0x28a2: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_28a8:
	/* 0x28a8: lea    eax,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_28af:
	/* 0x28af: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28b4:
	/* 0x28b4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_28b8:
	/* 0x28b8: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_28bb:
	/* 0x28bb: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_28bf:
	/* 0x28bf: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_28c5:
	/* 0x28c5: lea    eax,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_28cc:
	/* 0x28cc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28d1:
	/* 0x28d1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_28d5:
	/* 0x28d5: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_28d8:
	/* 0x28d8: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_28dc:
	/* 0x28dc: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_28e2:
	/* 0x28e2: lea    eax,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_28e9:
	/* 0x28e9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28ee:
	/* 0x28ee: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_28f2:
	/* 0x28f2: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_28f5:
	/* 0x28f5: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_28f9:
	/* 0x28f9: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_28ff:
	/* 0x28ff: lea    eax,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_2906:
	/* 0x2906: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_290b:
	/* 0x290b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_290f:
	/* 0x290f: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_2912:
	/* 0x2912: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_2916:
	/* 0x2916: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_291c:
	/* 0x291c: lea    eax,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_2923:
	/* 0x2923: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2928:
	/* 0x2928: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_292c:
	/* 0x292c: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_292f:
	/* 0x292f: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_2933:
	/* 0x2933: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2939:
	/* 0x2939: lea    eax,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_2940:
	/* 0x2940: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2945:
	/* 0x2945: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2949:
	/* 0x2949: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_294c:
	/* 0x294c: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_2950:
	/* 0x2950: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2956:
	/* 0x2956: lea    eax,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_295d:
	/* 0x295d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2962:
	/* 0x2962: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2966:
	/* 0x2966: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_2969:
	/* 0x2969: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_296d:
	/* 0x296d: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11046ULL;
	}
x86_l_2973:
	/* 0x2973: lea    eax,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
	return 10618ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10627ULL: goto x86_l_2983;
	case 10630ULL: goto x86_l_2986;
	case 10634ULL: goto x86_l_298a;
	case 10640ULL: goto x86_l_2990;
	case 10647ULL: goto x86_l_2997;
	case 10652ULL: goto x86_l_299c;
	case 10656ULL: goto x86_l_29a0;
	case 10659ULL: goto x86_l_29a3;
	case 10663ULL: goto x86_l_29a7;
	case 10669ULL: goto x86_l_29ad;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10685ULL: goto x86_l_29bd;
	case 10688ULL: goto x86_l_29c0;
	case 10692ULL: goto x86_l_29c4;
	case 10698ULL: goto x86_l_29ca;
	case 10705ULL: goto x86_l_29d1;
	case 10710ULL: goto x86_l_29d6;
	case 10714ULL: goto x86_l_29da;
	case 10717ULL: goto x86_l_29dd;
	case 10721ULL: goto x86_l_29e1;
	case 10727ULL: goto x86_l_29e7;
	case 10734ULL: goto x86_l_29ee;
	case 10739ULL: goto x86_l_29f3;
	case 10743ULL: goto x86_l_29f7;
	case 10746ULL: goto x86_l_29fa;
	case 10750ULL: goto x86_l_29fe;
	case 10756ULL: goto x86_l_2a04;
	case 10763ULL: goto x86_l_2a0b;
	case 10768ULL: goto x86_l_2a10;
	case 10772ULL: goto x86_l_2a14;
	case 10775ULL: goto x86_l_2a17;
	case 10779ULL: goto x86_l_2a1b;
	case 10785ULL: goto x86_l_2a21;
	case 10792ULL: goto x86_l_2a28;
	case 10797ULL: goto x86_l_2a2d;
	case 10801ULL: goto x86_l_2a31;
	case 10804ULL: goto x86_l_2a34;
	case 10808ULL: goto x86_l_2a38;
	case 10814ULL: goto x86_l_2a3e;
	case 10821ULL: goto x86_l_2a45;
	case 10826ULL: goto x86_l_2a4a;
	case 10830ULL: goto x86_l_2a4e;
	case 10833ULL: goto x86_l_2a51;
	case 10837ULL: goto x86_l_2a55;
	case 10843ULL: goto x86_l_2a5b;
	case 10850ULL: goto x86_l_2a62;
	case 10855ULL: goto x86_l_2a67;
	case 10859ULL: goto x86_l_2a6b;
	case 10862ULL: goto x86_l_2a6e;
	case 10866ULL: goto x86_l_2a72;
	case 10872ULL: goto x86_l_2a78;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10895ULL: goto x86_l_2a8f;
	case 10901ULL: goto x86_l_2a95;
	case 10908ULL: goto x86_l_2a9c;
	case 10913ULL: goto x86_l_2aa1;
	case 10917ULL: goto x86_l_2aa5;
	case 10920ULL: goto x86_l_2aa8;
	case 10924ULL: goto x86_l_2aac;
	case 10926ULL: goto x86_l_2aae;
	case 10933ULL: goto x86_l_2ab5;
	case 10938ULL: goto x86_l_2aba;
	case 10942ULL: goto x86_l_2abe;
	case 10945ULL: goto x86_l_2ac1;
	case 10949ULL: goto x86_l_2ac5;
	case 10951ULL: goto x86_l_2ac7;
	case 10958ULL: goto x86_l_2ace;
	case 10963ULL: goto x86_l_2ad3;
	case 10967ULL: goto x86_l_2ad7;
	case 10970ULL: goto x86_l_2ada;
	case 10974ULL: goto x86_l_2ade;
	case 10976ULL: goto x86_l_2ae0;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10992ULL: goto x86_l_2af0;
	case 10995ULL: goto x86_l_2af3;
	case 10999ULL: goto x86_l_2af7;
	case 11001ULL: goto x86_l_2af9;
	case 11004ULL: goto x86_l_2afc;
	case 11009ULL: goto x86_l_2b01;
	case 11014ULL: goto x86_l_2b06;
	case 11018ULL: goto x86_l_2b0a;
	case 11021ULL: goto x86_l_2b0d;
	case 11025ULL: goto x86_l_2b11;
	case 11027ULL: goto x86_l_2b13;
	case 11034ULL: goto x86_l_2b1a;
	case 11039ULL: goto x86_l_2b1f;
	case 11043ULL: goto x86_l_2b23;
	case 11046ULL: goto x86_l_2b26;
	case 11051ULL: goto x86_l_2b2b;
	case 11055ULL: goto x86_l_2b2f;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11070ULL: goto x86_l_2b3e;
	case 11074ULL: goto x86_l_2b42;
	case 11078ULL: goto x86_l_2b46;
	case 11086ULL: goto x86_l_2b4e;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11103ULL: goto x86_l_2b5f;
	case 11106ULL: goto x86_l_2b62;
	case 11108ULL: goto x86_l_2b64;
	case 11111ULL: goto x86_l_2b67;
	case 11114ULL: goto x86_l_2b6a;
	case 11117ULL: goto x86_l_2b6d;
	case 11123ULL: goto x86_l_2b73;
	case 11127ULL: goto x86_l_2b77;
	case 11130ULL: goto x86_l_2b7a;
	case 11136ULL: goto x86_l_2b80;
	case 11143ULL: goto x86_l_2b87;
	case 11148ULL: goto x86_l_2b8c;
	case 11153ULL: goto x86_l_2b91;
	case 11155ULL: goto x86_l_2b93;
	case 11158ULL: goto x86_l_2b96;
	case 11164ULL: goto x86_l_2b9c;
	case 11169ULL: goto x86_l_2ba1;
	case 11173ULL: goto x86_l_2ba5;
	case 11180ULL: goto x86_l_2bac;
	case 11185ULL: goto x86_l_2bb1;
	case 11189ULL: goto x86_l_2bb5;
	case 11196ULL: goto x86_l_2bbc;
	case 11198ULL: goto x86_l_2bbe;
	case 11201ULL: goto x86_l_2bc1;
	case 11205ULL: goto x86_l_2bc5;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11224ULL: goto x86_l_2bd8;
	case 11227ULL: goto x86_l_2bdb;
	case 11232ULL: goto x86_l_2be0;
	case 11237ULL: goto x86_l_2be5;
	case 11241ULL: goto x86_l_2be9;
	case 11245ULL: goto x86_l_2bed;
	case 11247ULL: goto x86_l_2bef;
	case 11252ULL: goto x86_l_2bf4;
	case 11255ULL: goto x86_l_2bf7;
	case 11259ULL: goto x86_l_2bfb;
	case 11262ULL: goto x86_l_2bfe;
	case 11266ULL: goto x86_l_2c02;
	case 11268ULL: goto x86_l_2c04;
	case 11271ULL: goto x86_l_2c07;
	case 11274ULL: goto x86_l_2c0a;
	case 11276ULL: goto x86_l_2c0c;
	case 11279ULL: goto x86_l_2c0f;
	case 11282ULL: goto x86_l_2c12;
	case 11284ULL: goto x86_l_2c14;
	case 11287ULL: goto x86_l_2c17;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11301ULL: goto x86_l_2c25;
	case 11304ULL: goto x86_l_2c28;
	case 11310ULL: goto x86_l_2c2e;
	case 11315ULL: goto x86_l_2c33;
	case 11318ULL: goto x86_l_2c36;
	case 11324ULL: goto x86_l_2c3c;
	case 11329ULL: goto x86_l_2c41;
	case 11332ULL: goto x86_l_2c44;
	case 11338ULL: goto x86_l_2c4a;
	case 11343ULL: goto x86_l_2c4f;
	case 11346ULL: goto x86_l_2c52;
	case 11352ULL: goto x86_l_2c58;
	case 11357ULL: goto x86_l_2c5d;
	case 11360ULL: goto x86_l_2c60;
	case 11366ULL: goto x86_l_2c66;
	case 11371ULL: goto x86_l_2c6b;
	case 11374ULL: goto x86_l_2c6e;
	case 11380ULL: goto x86_l_2c74;
	case 11383ULL: goto x86_l_2c77;
	case 11389ULL: goto x86_l_2c7d;
	case 11392ULL: goto x86_l_2c80;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11406ULL: goto x86_l_2c8e;
	case 11413ULL: goto x86_l_2c95;
	case 11418ULL: goto x86_l_2c9a;
	case 11423ULL: goto x86_l_2c9f;
	case 11425ULL: goto x86_l_2ca1;
	case 11428ULL: goto x86_l_2ca4;
	case 11434ULL: goto x86_l_2caa;
	case 11437ULL: goto x86_l_2cad;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11455ULL: goto x86_l_2cbf;
	case 11459ULL: goto x86_l_2cc3;
	case 11463ULL: goto x86_l_2cc7;
	case 11471ULL: goto x86_l_2ccf;
	case 11478ULL: goto x86_l_2cd6;
	case 11483ULL: goto x86_l_2cdb;
	case 11488ULL: goto x86_l_2ce0;
	case 11490ULL: goto x86_l_2ce2;
	case 11493ULL: goto x86_l_2ce5;
	case 11498ULL: goto x86_l_2cea;
	case 11504ULL: goto x86_l_2cf0;
	case 11509ULL: goto x86_l_2cf5;
	case 11512ULL: goto x86_l_2cf8;
	case 11518ULL: goto x86_l_2cfe;
	case 11523ULL: goto x86_l_2d03;
	case 11530ULL: goto x86_l_2d0a;
	case 11535ULL: goto x86_l_2d0f;
	case 11540ULL: goto x86_l_2d14;
	case 11542ULL: goto x86_l_2d16;
	case 11545ULL: goto x86_l_2d19;
	case 11551ULL: goto x86_l_2d1f;
	case 11554ULL: goto x86_l_2d22;
	case 11558ULL: goto x86_l_2d26;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11571ULL: goto x86_l_2d33;
	case 11578ULL: goto x86_l_2d3a;
	case 11582ULL: goto x86_l_2d3e;
	case 11585ULL: goto x86_l_2d41;
	case 11589ULL: goto x86_l_2d45;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11601ULL: goto x86_l_2d51;
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11632ULL: goto x86_l_2d70;
	case 11638ULL: goto x86_l_2d76;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11652ULL: goto x86_l_2d84;
	case 11658ULL: goto x86_l_2d8a;
	case 11661ULL: goto x86_l_2d8d;
	case 11664ULL: goto x86_l_2d90;
	case 11667ULL: goto x86_l_2d93;
	case 11669ULL: goto x86_l_2d95;
	case 11671ULL: goto x86_l_2d97;
	case 11674ULL: goto x86_l_2d9a;
	case 11680ULL: goto x86_l_2da0;
	case 11682ULL: goto x86_l_2da2;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11696ULL: goto x86_l_2db0;
	case 11698ULL: goto x86_l_2db2;
	case 11701ULL: goto x86_l_2db5;
	case 11707ULL: goto x86_l_2dbb;
	case 11710ULL: goto x86_l_2dbe;
	case 11716ULL: goto x86_l_2dc4;
	case 11720ULL: goto x86_l_2dc8;
	case 11723ULL: goto x86_l_2dcb;
	case 11729ULL: goto x86_l_2dd1;
	case 11732ULL: goto x86_l_2dd4;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11746ULL: goto x86_l_2de2;
	case 11749ULL: goto x86_l_2de5;
	case 11754ULL: goto x86_l_2dea;
	case 11760ULL: goto x86_l_2df0;
	case 11763ULL: goto x86_l_2df3;
	case 11768ULL: goto x86_l_2df8;
	case 11772ULL: goto x86_l_2dfc;
	case 11779ULL: goto x86_l_2e03;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11791ULL: goto x86_l_2e0f;
	case 11794ULL: goto x86_l_2e12;
	case 11800ULL: goto x86_l_2e18;
	case 11803ULL: goto x86_l_2e1b;
	case 11807ULL: goto x86_l_2e1f;
	case 11812ULL: goto x86_l_2e24;
	case 11817ULL: goto x86_l_2e29;
	case 11822ULL: goto x86_l_2e2e;
	case 11827ULL: goto x86_l_2e33;
	case 11830ULL: goto x86_l_2e36;
	case 11833ULL: goto x86_l_2e39;
	case 11837ULL: goto x86_l_2e3d;
	case 11842ULL: goto x86_l_2e42;
	case 11845ULL: goto x86_l_2e45;
	case 11848ULL: goto x86_l_2e48;
	case 11853ULL: goto x86_l_2e4d;
	case 11857ULL: goto x86_l_2e51;
	case 11862ULL: goto x86_l_2e56;
	case 11865ULL: goto x86_l_2e59;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11877ULL: goto x86_l_2e65;
	case 11882ULL: goto x86_l_2e6a;
	case 11887ULL: goto x86_l_2e6f;
	case 11890ULL: goto x86_l_2e72;
	case 11895ULL: goto x86_l_2e77;
	case 11898ULL: goto x86_l_2e7a;
	case 11902ULL: goto x86_l_2e7e;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11919ULL: goto x86_l_2e8f;
	case 11921ULL: goto x86_l_2e91;
	case 11924ULL: goto x86_l_2e94;
	case 11930ULL: goto x86_l_2e9a;
	case 11933ULL: goto x86_l_2e9d;
	case 11941ULL: goto x86_l_2ea5;
	case 11946ULL: goto x86_l_2eaa;
	case 11951ULL: goto x86_l_2eaf;
	case 11956ULL: goto x86_l_2eb4;
	case 11960ULL: goto x86_l_2eb8;
	case 11964ULL: goto x86_l_2ebc;
	case 11968ULL: goto x86_l_2ec0;
	case 11973ULL: goto x86_l_2ec5;
	case 11978ULL: goto x86_l_2eca;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11988ULL: goto x86_l_2ed4;
	case 11991ULL: goto x86_l_2ed7;
	case 11994ULL: goto x86_l_2eda;
	case 12000ULL: goto x86_l_2ee0;
	case 12003ULL: goto x86_l_2ee3;
	case 12006ULL: goto x86_l_2ee6;
	case 12008ULL: goto x86_l_2ee8;
	case 12011ULL: goto x86_l_2eeb;
	case 12014ULL: goto x86_l_2eee;
	case 12018ULL: goto x86_l_2ef2;
	case 12023ULL: goto x86_l_2ef7;
	case 12025ULL: goto x86_l_2ef9;
	case 12029ULL: goto x86_l_2efd;
	case 12034ULL: goto x86_l_2f02;
	case 12037ULL: goto x86_l_2f05;
	case 12039ULL: goto x86_l_2f07;
	case 12041ULL: goto x86_l_2f09;
	case 12043ULL: goto x86_l_2f0b;
	case 12046ULL: goto x86_l_2f0e;
	case 12051ULL: goto x86_l_2f13;
	case 12055ULL: goto x86_l_2f17;
	case 12057ULL: goto x86_l_2f19;
	case 12060ULL: goto x86_l_2f1c;
	case 12066ULL: goto x86_l_2f22;
	case 12069ULL: goto x86_l_2f25;
	case 12071ULL: goto x86_l_2f27;
	case 12075ULL: goto x86_l_2f2b;
	case 12080ULL: goto x86_l_2f30;
	case 12084ULL: goto x86_l_2f34;
	case 12087ULL: goto x86_l_2f37;
	case 12092ULL: goto x86_l_2f3c;
	case 12096ULL: goto x86_l_2f40;
	case 12100ULL: goto x86_l_2f44;
	case 12103ULL: goto x86_l_2f47;
	case 12109ULL: goto x86_l_2f4d;
	case 12116ULL: goto x86_l_2f54;
	case 12121ULL: goto x86_l_2f59;
	case 12126ULL: goto x86_l_2f5e;
	case 12129ULL: goto x86_l_2f61;
	case 12131ULL: goto x86_l_2f63;
	case 12134ULL: goto x86_l_2f66;
	case 12141ULL: goto x86_l_2f6d;
	case 12146ULL: goto x86_l_2f72;
	case 12149ULL: goto x86_l_2f75;
	case 12151ULL: goto x86_l_2f77;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12162ULL: goto x86_l_2f82;
	case 12168ULL: goto x86_l_2f88;
	case 12171ULL: goto x86_l_2f8b;
	case 12177ULL: goto x86_l_2f91;
	case 12180ULL: goto x86_l_2f94;
	case 12184ULL: goto x86_l_2f98;
	case 12189ULL: goto x86_l_2f9d;
	case 12192ULL: goto x86_l_2fa0;
	case 12196ULL: goto x86_l_2fa4;
	case 12201ULL: goto x86_l_2fa9;
	case 12206ULL: goto x86_l_2fae;
	case 12209ULL: goto x86_l_2fb1;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12219ULL: goto x86_l_2fbb;
	case 12221ULL: goto x86_l_2fbd;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12234ULL: goto x86_l_2fca;
	case 12237ULL: goto x86_l_2fcd;
	case 12239ULL: goto x86_l_2fcf;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12253ULL: goto x86_l_2fdd;
	case 12255ULL: goto x86_l_2fdf;
	case 12259ULL: goto x86_l_2fe3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_297a:
	/* 0x297a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_297f:
	/* 0x297f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2983:
	/* 0x2983: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_2986:
	/* 0x2986: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_298a:
	/* 0x298a: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2990:
	/* 0x2990: lea    eax,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_2997:
	/* 0x2997: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_299c:
	/* 0x299c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_29a0:
	/* 0x29a0: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_29a3:
	/* 0x29a3: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_29a7:
	/* 0x29a7: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_29ad:
	/* 0x29ad: lea    eax,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_29b4:
	/* 0x29b4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29b9:
	/* 0x29b9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_29bd:
	/* 0x29bd: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_29c0:
	/* 0x29c0: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_29c4:
	/* 0x29c4: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_29ca:
	/* 0x29ca: lea    eax,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_29d1:
	/* 0x29d1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29d6:
	/* 0x29d6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_29da:
	/* 0x29da: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_29dd:
	/* 0x29dd: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_29e1:
	/* 0x29e1: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_29e7:
	/* 0x29e7: lea    eax,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_29ee:
	/* 0x29ee: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29f3:
	/* 0x29f3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_29f7:
	/* 0x29f7: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_29fa:
	/* 0x29fa: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_29fe:
	/* 0x29fe: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2a04:
	/* 0x2a04: lea    eax,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_2a0b:
	/* 0x2a0b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a10:
	/* 0x2a10: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a14:
	/* 0x2a14: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_2a17:
	/* 0x2a17: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_2a1b:
	/* 0x2a1b: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2a21:
	/* 0x2a21: lea    eax,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_2a28:
	/* 0x2a28: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a2d:
	/* 0x2a2d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a31:
	/* 0x2a31: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a34:
	/* 0x2a34: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_2a38:
	/* 0x2a38: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2a3e:
	/* 0x2a3e: lea    eax,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_2a45:
	/* 0x2a45: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a4a:
	/* 0x2a4a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a4e:
	/* 0x2a4e: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_2a51:
	/* 0x2a51: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_2a55:
	/* 0x2a55: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2a5b:
	/* 0x2a5b: lea    eax,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_2a62:
	/* 0x2a62: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a67:
	/* 0x2a67: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_2a6e:
	/* 0x2a6e: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_2a72:
	/* 0x2a72: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2a78:
	/* 0x2a78: lea    eax,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_2a7f:
	/* 0x2a7f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a84:
	/* 0x2a84: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a88:
	/* 0x2a88: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_2a8b:
	/* 0x2a8b: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_2a8f:
	/* 0x2a8f: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2a95:
	/* 0x2a95: lea    eax,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_2a9c:
	/* 0x2a9c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2aa1:
	/* 0x2aa1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2aa8:
	/* 0x2aa8: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_2aac:
	/* 0x2aac: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2aae:
	/* 0x2aae: lea    eax,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_2ab5:
	/* 0x2ab5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2aba:
	/* 0x2aba: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2abe:
	/* 0x2abe: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_2ac1:
	/* 0x2ac1: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_2ac5:
	/* 0x2ac5: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2ac7:
	/* 0x2ac7: lea    eax,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_2ace:
	/* 0x2ace: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ad3:
	/* 0x2ad3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2ad7:
	/* 0x2ad7: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_2ada:
	/* 0x2ada: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_2ade:
	/* 0x2ade: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2ae0:
	/* 0x2ae0: lea    eax,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_2ae7:
	/* 0x2ae7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2aec:
	/* 0x2aec: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2af0:
	/* 0x2af0: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_2af3:
	/* 0x2af3: cmp    r13d,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 92ULL);
x86_l_2af7:
	/* 0x2af7: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2af9:
	/* 0x2af9: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2afc:
	/* 0x2afc: add    eax,0xfa3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4003ULL);
x86_l_2b01:
	/* 0x2b01: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b06:
	/* 0x2b06: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b0a:
	/* 0x2b0a: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b0d:
	/* 0x2b0d: cmp    r13d,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 93ULL);
x86_l_2b11:
	/* 0x2b11: je     2b26 <generic_fexit_filter_arg+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2b13:
	/* 0x2b13: lea    eax,[r13+0xfa2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4002ULL);
x86_l_2b1a:
	/* 0x2b1a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b1f:
	/* 0x2b1f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b23:
	/* 0x2b23: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_2b26:
	/* 0x2b26: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b2b:
	/* 0x2b2b: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b2f:
	/* 0x2b2f: jmp    3680 <generic_fexit_filter_arg+0x3680> */
	return 13952ULL;
x86_l_2b34:
	/* 0x2b34: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b39:
	/* 0x2b39: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b3e:
	/* 0x2b3e: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b42:
	/* 0x2b42: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b46:
	/* 0x2b46: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2b4e:
	/* 0x2b4e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2b55:
	/* 0x2b55: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b5a:
	/* 0x2b5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b5f:
	/* 0x2b5f: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_2b62:
	/* 0x2b62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b64:
	/* 0x2b64: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2b67:
	/* 0x2b67: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b6a:
	/* 0x2b6a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2b6d:
	/* 0x2b6d: je     3691 <generic_fexit_filter_arg+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13969ULL;
	}
x86_l_2b73:
	/* 0x2b73: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b77:
	/* 0x2b77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b7a:
	/* 0x2b7a: je     3691 <generic_fexit_filter_arg+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13969ULL;
	}
x86_l_2b80:
	/* 0x2b80: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2b87:
	/* 0x2b87: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b8c:
	/* 0x2b8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b91:
	/* 0x2b91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b93:
	/* 0x2b93: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b96:
	/* 0x2b96: je     368e <generic_fexit_filter_arg+0x368e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13966ULL;
	}
x86_l_2b9c:
	/* 0x2b9c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ba1:
	/* 0x2ba1: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2ba5:
	/* 0x2ba5: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_2bac:
	/* 0x2bac: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2bb1:
	/* 0x2bb1: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2bb5:
	/* 0x2bb5: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2bbc:
	/* 0x2bbc: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bbe:
	/* 0x2bbe: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2bc1:
	/* 0x2bc1: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2bc5:
	/* 0x2bc5: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2bc8:
	/* 0x2bc8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bcd:
	/* 0x2bcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bcf:
	/* 0x2bcf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bd4:
	/* 0x2bd4: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bd8:
	/* 0x2bd8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2bdb:
	/* 0x2bdb: jmp    3680 <generic_fexit_filter_arg+0x3680> */
	return 13952ULL;
x86_l_2be0:
	/* 0x2be0: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2be5:
	/* 0x2be5: mov    rdx,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2be9:
	/* 0x2be9: mov    rdi,QWORD PTR [r8+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bed:
	/* 0x2bed: jmp    2bfb <generic_fexit_filter_arg+0x2bfb> */
	goto x86_l_2bfb;
x86_l_2bef:
	/* 0x2bef: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bf4:
	/* 0x2bf4: mov    rdx,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf7:
	/* 0x2bf7: mov    rdi,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bfb:
	/* 0x2bfb: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2bfe:
	/* 0x2bfe: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2c02:
	/* 0x2c02: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c04:
	/* 0x2c04: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c07:
	/* 0x2c07: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2c0a:
	/* 0x2c0a: jg     2c33 <generic_fexit_filter_arg+0x2c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c33;
	}
x86_l_2c0c:
	/* 0x2c0c: lea    eax,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_2c0f:
	/* 0x2c0f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c12:
	/* 0x2c12: jb     2c66 <generic_fexit_filter_arg+0x2c66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2c66;
	}
x86_l_2c14:
	/* 0x2c14: lea    eax,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_2c17:
	/* 0x2c17: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c1a:
	/* 0x2c1a: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c1f:
	/* 0x2c1f: jb     2df0 <generic_fexit_filter_arg+0x2df0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2df0;
	}
x86_l_2c25:
	/* 0x2c25: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2c28:
	/* 0x2c28: je     30e6 <generic_fexit_filter_arg+0x30e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12518ULL;
	}
x86_l_2c2e:
	/* 0x2c2e: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_2c33:
	/* 0x2c33: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_2c36:
	/* 0x2c36: ja     2ddf <generic_fexit_filter_arg+0x2ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ddf;
	}
x86_l_2c3c:
	/* 0x2c3c: mov    eax,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5242880ULL);
x86_l_2c41:
	/* 0x2c41: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2c44:
	/* 0x2c44: jb     2e42 <generic_fexit_filter_arg+0x2e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e42;
	}
x86_l_2c4a:
	/* 0x2c4a: mov    eax,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10485760ULL);
x86_l_2c4f:
	/* 0x2c4f: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2c52:
	/* 0x2c52: jb     2e56 <generic_fexit_filter_arg+0x2e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e56;
	}
x86_l_2c58:
	/* 0x2c58: mov    eax,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50331648ULL);
x86_l_2c5d:
	/* 0x2c5d: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2c60:
	/* 0x2c60: jae    2ddf <generic_fexit_filter_arg+0x2ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2ddf;
	}
x86_l_2c66:
	/* 0x2c66: movzx  eax,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2c6b:
	/* 0x2c6b: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2c6e:
	/* 0x2c6e: je     2e6a <generic_fexit_filter_arg+0x2e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e6a;
	}
x86_l_2c74:
	/* 0x2c74: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c77:
	/* 0x2c77: jne    2ef7 <generic_fexit_filter_arg+0x2ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ef7;
	}
x86_l_2c7d:
	/* 0x2c7d: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2c80:
	/* 0x2c80: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c85:
	/* 0x2c85: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_2c95:
	/* 0x2c95: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2c9a:
	/* 0x2c9a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c9f:
	/* 0x2c9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca1:
	/* 0x2ca1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca4:
	/* 0x2ca4: je     3382 <generic_fexit_filter_arg+0x3382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13186ULL;
	}
x86_l_2caa:
	/* 0x2caa: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2cad:
	/* 0x2cad: mov    DWORD PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691872ULL);
x86_l_2cb5:
	/* 0x2cb5: mov    DWORD PTR [rsp+0x2c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2cba:
	/* 0x2cba: jmp    2ec0 <generic_fexit_filter_arg+0x2ec0> */
	goto x86_l_2ec0;
x86_l_2cbf:
	/* 0x2cbf: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cc3:
	/* 0x2cc3: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cc7:
	/* 0x2cc7: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2ccf:
	/* 0x2ccf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2cd6:
	/* 0x2cd6: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cdb:
	/* 0x2cdb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ce0:
	/* 0x2ce0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce2:
	/* 0x2ce2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ce5:
	/* 0x2ce5: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cea:
	/* 0x2cea: je     3737 <generic_fexit_filter_arg+0x3737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14135ULL;
	}
x86_l_2cf0:
	/* 0x2cf0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cf5:
	/* 0x2cf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cf8:
	/* 0x2cf8: je     3737 <generic_fexit_filter_arg+0x3737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14135ULL;
	}
x86_l_2cfe:
	/* 0x2cfe: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d03:
	/* 0x2d03: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2d0a:
	/* 0x2d0a: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d14:
	/* 0x2d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d16:
	/* 0x2d16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d19:
	/* 0x2d19: je     372f <generic_fexit_filter_arg+0x372f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14127ULL;
	}
x86_l_2d1f:
	/* 0x2d1f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d22:
	/* 0x2d22: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d26:
	/* 0x2d26: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2d2b:
	/* 0x2d2b: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2d30:
	/* 0x2d30: cmovb  esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2d33:
	/* 0x2d33: lea    eax,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2d3a:
	/* 0x2d3a: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d3e:
	/* 0x2d3e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2d41:
	/* 0x2d41: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d45:
	/* 0x2d45: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d4a:
	/* 0x2d4a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d4f:
	/* 0x2d4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d51:
	/* 0x2d51: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d56:
	/* 0x2d56: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2d5e:
	/* 0x2d5e: jmp    3721 <generic_fexit_filter_arg+0x3721> */
	return 14113ULL;
x86_l_2d63:
	/* 0x2d63: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d68:
	/* 0x2d68: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2d70:
	/* 0x2d70: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2d76:
	/* 0x2d76: ja     372f <generic_fexit_filter_arg+0x372f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14127ULL;
	}
x86_l_2d7c:
	/* 0x2d7c: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d81:
	/* 0x2d81: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d84:
	/* 0x2d84: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2d8a:
	/* 0x2d8a: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2d8d:
	/* 0x2d8d: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2d90:
	/* 0x2d90: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2d93:
	/* 0x2d93: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2d95:
	/* 0x2d95: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2d97:
	/* 0x2d97: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_2d9a:
	/* 0x2d9a: je     33a3 <generic_fexit_filter_arg+0x33a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13219ULL;
	}
x86_l_2da0:
	/* 0x2da0: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2da2:
	/* 0x2da2: jne    33a3 <generic_fexit_filter_arg+0x33a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13219ULL;
	}
x86_l_2da8:
	/* 0x2da8: jmp    33ba <generic_fexit_filter_arg+0x33ba> */
	return 13242ULL;
x86_l_2dad:
	/* 0x2dad: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2db0:
	/* 0x2db0: jne    2dbb <generic_fexit_filter_arg+0x2dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2dbb;
	}
x86_l_2db2:
	/* 0x2db2: test   DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2db5:
	/* 0x2db5: jne    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14171ULL;
	}
x86_l_2dbb:
	/* 0x2dbb: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2dbe:
	/* 0x2dbe: jb     358b <generic_fexit_filter_arg+0x358b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13707ULL;
	}
x86_l_2dc4:
	/* 0x2dc4: mov    esi,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dc8:
	/* 0x2dc8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2dcb:
	/* 0x2dcb: jae    333b <generic_fexit_filter_arg+0x333b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13115ULL;
	}
x86_l_2dd1:
	/* 0x2dd1: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dd4:
	/* 0x2dd4: jne    3349 <generic_fexit_filter_arg+0x3349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13129ULL;
	}
x86_l_2dda:
	/* 0x2dda: jmp    350c <generic_fexit_filter_arg+0x350c> */
	return 13580ULL;
x86_l_2ddf:
	/* 0x2ddf: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_2de2:
	/* 0x2de2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2de5:
	/* 0x2de5: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dea:
	/* 0x2dea: jae    3756 <generic_fexit_filter_arg+0x3756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14166ULL;
	}
x86_l_2df0:
	/* 0x2df0: mov    r12d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_32);
x86_l_2df3:
	/* 0x2df3: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2df8:
	/* 0x2df8: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2dfc:
	/* 0x2dfc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2e03:
	/* 0x2e03: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2e08:
	/* 0x2e08: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e0d:
	/* 0x2e0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e0f:
	/* 0x2e0f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e12:
	/* 0x2e12: je     3333 <generic_fexit_filter_arg+0x3333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13107ULL;
	}
x86_l_2e18:
	/* 0x2e18: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e1b:
	/* 0x2e1b: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e1f:
	/* 0x2e1f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e24:
	/* 0x2e24: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e29:
	/* 0x2e29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e2e:
	/* 0x2e2e: jmp    3121 <generic_fexit_filter_arg+0x3121> */
	return 12577ULL;
x86_l_2e33:
	/* 0x2e33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e36:
	/* 0x2e36: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2e39:
	/* 0x2e39: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e3d:
	/* 0x2e3d: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_2e42:
	/* 0x2e42: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e45:
	/* 0x2e45: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e48:
	/* 0x2e48: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2e4d:
	/* 0x2e4d: setb   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_B);
x86_l_2e51:
	/* 0x2e51: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_2e56:
	/* 0x2e56: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e59:
	/* 0x2e59: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e5c:
	/* 0x2e5c: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2e61:
	/* 0x2e61: setae  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_AE);
x86_l_2e65:
	/* 0x2e65: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_2e6a:
	/* 0x2e6a: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e6f:
	/* 0x2e6f: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_2e72:
	/* 0x2e72: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e77:
	/* 0x2e77: mov    eax,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2e7a:
	/* 0x2e7a: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_2e85:
	/* 0x2e85: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2e8a:
	/* 0x2e8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e8f:
	/* 0x2e8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e91:
	/* 0x2e91: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e94:
	/* 0x2e94: je     3389 <generic_fexit_filter_arg+0x3389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13193ULL;
	}
x86_l_2e9a:
	/* 0x2e9a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e9d:
	/* 0x2e9d: mov    DWORD PTR [rsp+0x28],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691968ULL);
x86_l_2ea5:
	/* 0x2ea5: mov    DWORD PTR [rsp+0x2c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2eaa:
	/* 0x2eaa: mov    DWORD PTR [rsp+0x30],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2eaf:
	/* 0x2eaf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eb4:
	/* 0x2eb4: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2eb8:
	/* 0x2eb8: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2ebc:
	/* 0x2ebc: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ec0:
	/* 0x2ec0: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ec5:
	/* 0x2ec5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eca:
	/* 0x2eca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ecc:
	/* 0x2ecc: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ed1:
	/* 0x2ed1: mov    ecx,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ed4:
	/* 0x2ed4: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2ed7:
	/* 0x2ed7: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2eda:
	/* 0x2eda: jb     31ab <generic_fexit_filter_arg+0x31ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12715ULL;
	}
x86_l_2ee0:
	/* 0x2ee0: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2ee3:
	/* 0x2ee3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2ee6:
	/* 0x2ee6: ja     2ef7 <generic_fexit_filter_arg+0x2ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ef7;
	}
x86_l_2ee8:
	/* 0x2ee8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2eeb:
	/* 0x2eeb: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2eee:
	/* 0x2eee: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ef2:
	/* 0x2ef2: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_2ef7:
	/* 0x2ef7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ef9:
	/* 0x2ef9: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2efd:
	/* 0x2efd: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_2f02:
	/* 0x2f02: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f05:
	/* 0x2f05: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2f07:
	/* 0x2f07: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f09:
	/* 0x2f09: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2f0b:
	/* 0x2f0b: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2f0e:
	/* 0x2f0e: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2f13:
	/* 0x2f13: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2f17:
	/* 0x2f17: ja     2f27 <generic_fexit_filter_arg+0x2f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f27;
	}
x86_l_2f19:
	/* 0x2f19: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f1c:
	/* 0x2f1c: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2f22:
	/* 0x2f22: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2f25:
	/* 0x2f25: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2f27:
	/* 0x2f27: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2f2b:
	/* 0x2f2b: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f30:
	/* 0x2f30: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f34:
	/* 0x2f34: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2f37:
	/* 0x2f37: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f3c:
	/* 0x2f3c: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2f40:
	/* 0x2f40: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f44:
	/* 0x2f44: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2f47:
	/* 0x2f47: je     360d <generic_fexit_filter_arg+0x360d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13837ULL;
	}
x86_l_2f4d:
	/* 0x2f4d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2f54:
	/* 0x2f54: lea    r12,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f59:
	/* 0x2f59: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f5e:
	/* 0x2f5e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2f61:
	/* 0x2f61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f63:
	/* 0x2f63: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2f66:
	/* 0x2f66: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2f6d:
	/* 0x2f6d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f72:
	/* 0x2f72: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2f75:
	/* 0x2f75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f77:
	/* 0x2f77: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f7a:
	/* 0x2f7a: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f7f:
	/* 0x2f7f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2f82:
	/* 0x2f82: je     3610 <generic_fexit_filter_arg+0x3610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13840ULL;
	}
x86_l_2f88:
	/* 0x2f88: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f8b:
	/* 0x2f8b: je     3610 <generic_fexit_filter_arg+0x3610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13840ULL;
	}
x86_l_2f91:
	/* 0x2f91: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2f94:
	/* 0x2f94: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f98:
	/* 0x2f98: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f9d:
	/* 0x2f9d: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa0:
	/* 0x2fa0: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2fa4:
	/* 0x2fa4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fa9:
	/* 0x2fa9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fae:
	/* 0x2fae: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2fb1:
	/* 0x2fb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb3:
	/* 0x2fb3: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2fb8:
	/* 0x2fb8: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2fbb:
	/* 0x2fbb: jbe    2fdf <generic_fexit_filter_arg+0x2fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2fdf;
	}
x86_l_2fbd:
	/* 0x2fbd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc1:
	/* 0x2fc1: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2fc6:
	/* 0x2fc6: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2fca:
	/* 0x2fca: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2fcd:
	/* 0x2fcd: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fcf:
	/* 0x2fcf: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2fd5:
	/* 0x2fd5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fda:
	/* 0x2fda: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2fdd:
	/* 0x2fdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fdf:
	/* 0x2fdf: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2fe3:
	/* 0x2fe3: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
	return 12263ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12263ULL: goto x86_l_2fe7;
	case 12268ULL: goto x86_l_2fec;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12285ULL: goto x86_l_2ffd;
	case 12290ULL: goto x86_l_3002;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12307ULL: goto x86_l_3013;
	case 12314ULL: goto x86_l_301a;
	case 12319ULL: goto x86_l_301f;
	case 12324ULL: goto x86_l_3024;
	case 12329ULL: goto x86_l_3029;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12341ULL: goto x86_l_3035;
	case 12345ULL: goto x86_l_3039;
	case 12350ULL: goto x86_l_303e;
	case 12355ULL: goto x86_l_3043;
	case 12360ULL: goto x86_l_3048;
	case 12363ULL: goto x86_l_304b;
	case 12367ULL: goto x86_l_304f;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12378ULL: goto x86_l_305a;
	case 12381ULL: goto x86_l_305d;
	case 12385ULL: goto x86_l_3061;
	case 12387ULL: goto x86_l_3063;
	case 12393ULL: goto x86_l_3069;
	case 12398ULL: goto x86_l_306e;
	case 12403ULL: goto x86_l_3073;
	case 12409ULL: goto x86_l_3079;
	case 12411ULL: goto x86_l_307b;
	case 12417ULL: goto x86_l_3081;
	case 12420ULL: goto x86_l_3084;
	case 12423ULL: goto x86_l_3087;
	case 12429ULL: goto x86_l_308d;
	case 12432ULL: goto x86_l_3090;
	case 12434ULL: goto x86_l_3092;
	case 12440ULL: goto x86_l_3098;
	case 12442ULL: goto x86_l_309a;
	case 12448ULL: goto x86_l_30a0;
	case 12451ULL: goto x86_l_30a3;
	case 12457ULL: goto x86_l_30a9;
	case 12460ULL: goto x86_l_30ac;
	case 12462ULL: goto x86_l_30ae;
	case 12468ULL: goto x86_l_30b4;
	case 12470ULL: goto x86_l_30b6;
	case 12473ULL: goto x86_l_30b9;
	case 12479ULL: goto x86_l_30bf;
	case 12482ULL: goto x86_l_30c2;
	case 12488ULL: goto x86_l_30c8;
	case 12491ULL: goto x86_l_30cb;
	case 12493ULL: goto x86_l_30cd;
	case 12499ULL: goto x86_l_30d3;
	case 12502ULL: goto x86_l_30d6;
	case 12504ULL: goto x86_l_30d8;
	case 12508ULL: goto x86_l_30dc;
	case 12513ULL: goto x86_l_30e1;
	case 12518ULL: goto x86_l_30e6;
	case 12523ULL: goto x86_l_30eb;
	case 12527ULL: goto x86_l_30ef;
	case 12534ULL: goto x86_l_30f6;
	case 12539ULL: goto x86_l_30fb;
	case 12544ULL: goto x86_l_3100;
	case 12546ULL: goto x86_l_3102;
	case 12549ULL: goto x86_l_3105;
	case 12555ULL: goto x86_l_310b;
	case 12558ULL: goto x86_l_310e;
	case 12562ULL: goto x86_l_3112;
	case 12567ULL: goto x86_l_3117;
	case 12572ULL: goto x86_l_311c;
	case 12577ULL: goto x86_l_3121;
	case 12579ULL: goto x86_l_3123;
	case 12583ULL: goto x86_l_3127;
	case 12585ULL: goto x86_l_3129;
	case 12588ULL: goto x86_l_312c;
	case 12590ULL: goto x86_l_312e;
	case 12595ULL: goto x86_l_3133;
	case 12598ULL: goto x86_l_3136;
	case 12600ULL: goto x86_l_3138;
	case 12603ULL: goto x86_l_313b;
	case 12606ULL: goto x86_l_313e;
	case 12608ULL: goto x86_l_3140;
	case 12613ULL: goto x86_l_3145;
	case 12616ULL: goto x86_l_3148;
	case 12618ULL: goto x86_l_314a;
	case 12621ULL: goto x86_l_314d;
	case 12624ULL: goto x86_l_3150;
	case 12628ULL: goto x86_l_3154;
	case 12633ULL: goto x86_l_3159;
	case 12636ULL: goto x86_l_315c;
	case 12638ULL: goto x86_l_315e;
	case 12641ULL: goto x86_l_3161;
	case 12647ULL: goto x86_l_3167;
	case 12650ULL: goto x86_l_316a;
	case 12656ULL: goto x86_l_3170;
	case 12660ULL: goto x86_l_3174;
	case 12663ULL: goto x86_l_3177;
	case 12669ULL: goto x86_l_317d;
	case 12672ULL: goto x86_l_3180;
	case 12678ULL: goto x86_l_3186;
	case 12681ULL: goto x86_l_3189;
	case 12687ULL: goto x86_l_318f;
	case 12690ULL: goto x86_l_3192;
	case 12693ULL: goto x86_l_3195;
	case 12699ULL: goto x86_l_319b;
	case 12704ULL: goto x86_l_31a0;
	case 12707ULL: goto x86_l_31a3;
	case 12710ULL: goto x86_l_31a6;
	case 12715ULL: goto x86_l_31ab;
	case 12718ULL: goto x86_l_31ae;
	case 12723ULL: goto x86_l_31b3;
	case 12726ULL: goto x86_l_31b6;
	case 12729ULL: goto x86_l_31b9;
	case 12731ULL: goto x86_l_31bb;
	case 12733ULL: goto x86_l_31bd;
	case 12736ULL: goto x86_l_31c0;
	case 12741ULL: goto x86_l_31c5;
	case 12745ULL: goto x86_l_31c9;
	case 12747ULL: goto x86_l_31cb;
	case 12750ULL: goto x86_l_31ce;
	case 12756ULL: goto x86_l_31d4;
	case 12759ULL: goto x86_l_31d7;
	case 12761ULL: goto x86_l_31d9;
	case 12765ULL: goto x86_l_31dd;
	case 12768ULL: goto x86_l_31e0;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12780ULL: goto x86_l_31ec;
	case 12784ULL: goto x86_l_31f0;
	case 12787ULL: goto x86_l_31f3;
	case 12793ULL: goto x86_l_31f9;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12810ULL: goto x86_l_320a;
	case 12813ULL: goto x86_l_320d;
	case 12815ULL: goto x86_l_320f;
	case 12818ULL: goto x86_l_3212;
	case 12825ULL: goto x86_l_3219;
	case 12830ULL: goto x86_l_321e;
	case 12833ULL: goto x86_l_3221;
	case 12835ULL: goto x86_l_3223;
	case 12840ULL: goto x86_l_3228;
	case 12843ULL: goto x86_l_322b;
	case 12848ULL: goto x86_l_3230;
	case 12851ULL: goto x86_l_3233;
	case 12857ULL: goto x86_l_3239;
	case 12863ULL: goto x86_l_323f;
	case 12869ULL: goto x86_l_3245;
	case 12874ULL: goto x86_l_324a;
	case 12878ULL: goto x86_l_324e;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12891ULL: goto x86_l_325b;
	case 12895ULL: goto x86_l_325f;
	case 12900ULL: goto x86_l_3264;
	case 12903ULL: goto x86_l_3267;
	case 12905ULL: goto x86_l_3269;
	case 12910ULL: goto x86_l_326e;
	case 12913ULL: goto x86_l_3271;
	case 12915ULL: goto x86_l_3273;
	case 12918ULL: goto x86_l_3276;
	case 12923ULL: goto x86_l_327b;
	case 12927ULL: goto x86_l_327f;
	case 12930ULL: goto x86_l_3282;
	case 12932ULL: goto x86_l_3284;
	case 12938ULL: goto x86_l_328a;
	case 12943ULL: goto x86_l_328f;
	case 12948ULL: goto x86_l_3294;
	case 12950ULL: goto x86_l_3296;
	case 12954ULL: goto x86_l_329a;
	case 12958ULL: goto x86_l_329e;
	case 12962ULL: goto x86_l_32a2;
	case 12968ULL: goto x86_l_32a8;
	case 12972ULL: goto x86_l_32ac;
	case 12978ULL: goto x86_l_32b2;
	case 12982ULL: goto x86_l_32b6;
	case 12988ULL: goto x86_l_32bc;
	case 12992ULL: goto x86_l_32c0;
	case 12998ULL: goto x86_l_32c6;
	case 13005ULL: goto x86_l_32cd;
	case 13010ULL: goto x86_l_32d2;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13023ULL: goto x86_l_32df;
	case 13026ULL: goto x86_l_32e2;
	case 13028ULL: goto x86_l_32e4;
	case 13031ULL: goto x86_l_32e7;
	case 13033ULL: goto x86_l_32e9;
	case 13038ULL: goto x86_l_32ee;
	case 13041ULL: goto x86_l_32f1;
	case 13043ULL: goto x86_l_32f3;
	case 13046ULL: goto x86_l_32f6;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13057ULL: goto x86_l_3301;
	case 13064ULL: goto x86_l_3308;
	case 13069ULL: goto x86_l_330d;
	case 13074ULL: goto x86_l_3312;
	case 13076ULL: goto x86_l_3314;
	case 13079ULL: goto x86_l_3317;
	case 13081ULL: goto x86_l_3319;
	case 13084ULL: goto x86_l_331c;
	case 13087ULL: goto x86_l_331f;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13102ULL: goto x86_l_332e;
	case 13107ULL: goto x86_l_3333;
	case 13110ULL: goto x86_l_3336;
	case 13115ULL: goto x86_l_333b;
	case 13118ULL: goto x86_l_333e;
	case 13120ULL: goto x86_l_3340;
	case 13123ULL: goto x86_l_3343;
	case 13129ULL: goto x86_l_3349;
	case 13132ULL: goto x86_l_334c;
	case 13138ULL: goto x86_l_3352;
	case 13142ULL: goto x86_l_3356;
	case 13145ULL: goto x86_l_3359;
	case 13151ULL: goto x86_l_335f;
	case 13154ULL: goto x86_l_3362;
	case 13160ULL: goto x86_l_3368;
	case 13163ULL: goto x86_l_336b;
	case 13169ULL: goto x86_l_3371;
	case 13172ULL: goto x86_l_3374;
	case 13175ULL: goto x86_l_3377;
	case 13181ULL: goto x86_l_337d;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13193ULL: goto x86_l_3389;
	case 13198ULL: goto x86_l_338e;
	case 13201ULL: goto x86_l_3391;
	case 13204ULL: goto x86_l_3394;
	case 13207ULL: goto x86_l_3397;
	case 13210ULL: goto x86_l_339a;
	case 13214ULL: goto x86_l_339e;
	case 13219ULL: goto x86_l_33a3;
	case 13222ULL: goto x86_l_33a6;
	case 13224ULL: goto x86_l_33a8;
	case 13226ULL: goto x86_l_33aa;
	case 13228ULL: goto x86_l_33ac;
	case 13231ULL: goto x86_l_33af;
	case 13236ULL: goto x86_l_33b4;
	case 13240ULL: goto x86_l_33b8;
	case 13242ULL: goto x86_l_33ba;
	case 13245ULL: goto x86_l_33bd;
	case 13251ULL: goto x86_l_33c3;
	case 13254ULL: goto x86_l_33c6;
	case 13256ULL: goto x86_l_33c8;
	case 13260ULL: goto x86_l_33cc;
	case 13264ULL: goto x86_l_33d0;
	case 13267ULL: goto x86_l_33d3;
	case 13272ULL: goto x86_l_33d8;
	case 13276ULL: goto x86_l_33dc;
	case 13280ULL: goto x86_l_33e0;
	case 13283ULL: goto x86_l_33e3;
	case 13289ULL: goto x86_l_33e9;
	case 13296ULL: goto x86_l_33f0;
	case 13301ULL: goto x86_l_33f5;
	case 13306ULL: goto x86_l_33fa;
	case 13309ULL: goto x86_l_33fd;
	case 13311ULL: goto x86_l_33ff;
	case 13314ULL: goto x86_l_3402;
	case 13321ULL: goto x86_l_3409;
	case 13326ULL: goto x86_l_340e;
	case 13329ULL: goto x86_l_3411;
	case 13331ULL: goto x86_l_3413;
	case 13336ULL: goto x86_l_3418;
	case 13339ULL: goto x86_l_341b;
	case 13344ULL: goto x86_l_3420;
	case 13347ULL: goto x86_l_3423;
	case 13353ULL: goto x86_l_3429;
	case 13359ULL: goto x86_l_342f;
	case 13365ULL: goto x86_l_3435;
	case 13369ULL: goto x86_l_3439;
	case 13374ULL: goto x86_l_343e;
	case 13377ULL: goto x86_l_3441;
	case 13381ULL: goto x86_l_3445;
	case 13386ULL: goto x86_l_344a;
	case 13391ULL: goto x86_l_344f;
	case 13394ULL: goto x86_l_3452;
	case 13396ULL: goto x86_l_3454;
	case 13401ULL: goto x86_l_3459;
	case 13404ULL: goto x86_l_345c;
	case 13406ULL: goto x86_l_345e;
	case 13410ULL: goto x86_l_3462;
	case 13415ULL: goto x86_l_3467;
	case 13419ULL: goto x86_l_346b;
	case 13422ULL: goto x86_l_346e;
	case 13424ULL: goto x86_l_3470;
	case 13430ULL: goto x86_l_3476;
	case 13435ULL: goto x86_l_347b;
	case 13440ULL: goto x86_l_3480;
	case 13442ULL: goto x86_l_3482;
	case 13446ULL: goto x86_l_3486;
	case 13450ULL: goto x86_l_348a;
	case 13455ULL: goto x86_l_348f;
	case 13461ULL: goto x86_l_3495;
	case 13466ULL: goto x86_l_349a;
	case 13472ULL: goto x86_l_34a0;
	case 13477ULL: goto x86_l_34a5;
	case 13483ULL: goto x86_l_34ab;
	case 13488ULL: goto x86_l_34b0;
	case 13494ULL: goto x86_l_34b6;
	case 13501ULL: goto x86_l_34bd;
	case 13506ULL: goto x86_l_34c2;
	case 13511ULL: goto x86_l_34c7;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13527ULL: goto x86_l_34d7;
	case 13532ULL: goto x86_l_34dc;
	case 13538ULL: goto x86_l_34e2;
	case 13543ULL: goto x86_l_34e7;
	case 13549ULL: goto x86_l_34ed;
	case 13556ULL: goto x86_l_34f4;
	case 13561ULL: goto x86_l_34f9;
	case 13566ULL: goto x86_l_34fe;
	case 13571ULL: goto x86_l_3503;
	case 13574ULL: goto x86_l_3506;
	case 13580ULL: goto x86_l_350c;
	case 13583ULL: goto x86_l_350f;
	case 13586ULL: goto x86_l_3512;
	case 13590ULL: goto x86_l_3516;
	case 13595ULL: goto x86_l_351b;
	case 13599ULL: goto x86_l_351f;
	case 13605ULL: goto x86_l_3525;
	case 13609ULL: goto x86_l_3529;
	case 13615ULL: goto x86_l_352f;
	case 13619ULL: goto x86_l_3533;
	case 13625ULL: goto x86_l_3539;
	case 13632ULL: goto x86_l_3540;
	case 13637ULL: goto x86_l_3545;
	case 13642ULL: goto x86_l_354a;
	case 13647ULL: goto x86_l_354f;
	case 13652ULL: goto x86_l_3554;
	case 13658ULL: goto x86_l_355a;
	case 13663ULL: goto x86_l_355f;
	case 13669ULL: goto x86_l_3565;
	case 13674ULL: goto x86_l_356a;
	case 13680ULL: goto x86_l_3570;
	case 13687ULL: goto x86_l_3577;
	case 13692ULL: goto x86_l_357c;
	case 13697ULL: goto x86_l_3581;
	case 13702ULL: goto x86_l_3586;
	case 13705ULL: goto x86_l_3589;
	case 13707ULL: goto x86_l_358b;
	case 13710ULL: goto x86_l_358e;
	case 13713ULL: goto x86_l_3591;
	case 13719ULL: goto x86_l_3597;
	case 13724ULL: goto x86_l_359c;
	case 13731ULL: goto x86_l_35a3;
	case 13736ULL: goto x86_l_35a8;
	case 13741ULL: goto x86_l_35ad;
	case 13743ULL: goto x86_l_35af;
	case 13750ULL: goto x86_l_35b6;
	case 13755ULL: goto x86_l_35bb;
	case 13760ULL: goto x86_l_35c0;
	case 13762ULL: goto x86_l_35c2;
	case 13769ULL: goto x86_l_35c9;
	case 13774ULL: goto x86_l_35ce;
	case 13779ULL: goto x86_l_35d3;
	case 13781ULL: goto x86_l_35d5;
	case 13788ULL: goto x86_l_35dc;
	case 13793ULL: goto x86_l_35e1;
	case 13798ULL: goto x86_l_35e6;
	case 13803ULL: goto x86_l_35eb;
	case 13805ULL: goto x86_l_35ed;
	case 13808ULL: goto x86_l_35f0;
	case 13810ULL: goto x86_l_35f2;
	case 13813ULL: goto x86_l_35f5;
	case 13818ULL: goto x86_l_35fa;
	case 13823ULL: goto x86_l_35ff;
	case 13825ULL: goto x86_l_3601;
	case 13828ULL: goto x86_l_3604;
	case 13831ULL: goto x86_l_3607;
	case 13835ULL: goto x86_l_360b;
	case 13837ULL: goto x86_l_360d;
	case 13840ULL: goto x86_l_3610;
	case 13845ULL: goto x86_l_3615;
	case 13848ULL: goto x86_l_3618;
	case 13853ULL: goto x86_l_361d;
	case 13860ULL: goto x86_l_3624;
	case 13865ULL: goto x86_l_3629;
	case 13870ULL: goto x86_l_362e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2fe7:
	/* 0x2fe7: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_2fec:
	/* 0x2fec: jg     34cc <generic_fexit_filter_arg+0x34cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_34cc;
	}
x86_l_2ff2:
	/* 0x2ff2: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2ff7:
	/* 0x2ff7: je     359c <generic_fexit_filter_arg+0x359c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_359c;
	}
x86_l_2ffd:
	/* 0x2ffd: cmp    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_3002:
	/* 0x3002: je     35c2 <generic_fexit_filter_arg+0x35c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c2;
	}
x86_l_3008:
	/* 0x3008: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_300d:
	/* 0x300d: jne    360d <generic_fexit_filter_arg+0x360d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_360d;
	}
x86_l_3013:
	/* 0x3013: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_301a:
	/* 0x301a: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_301f:
	/* 0x301f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3024:
	/* 0x3024: jmp    35e6 <generic_fexit_filter_arg+0x35e6> */
	goto x86_l_35e6;
x86_l_3029:
	/* 0x3029: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_302c:
	/* 0x302c: jmp    369a <generic_fexit_filter_arg+0x369a> */
	return 13978ULL;
x86_l_3031:
	/* 0x3031: lea    rcx,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_3035:
	/* 0x3035: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3039:
	/* 0x3039: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_303e:
	/* 0x303e: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3043:
	/* 0x3043: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3048:
	/* 0x3048: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304b:
	/* 0x304b: lea    rdx,[r8+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_304f:
	/* 0x304f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3053:
	/* 0x3053: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3058:
	/* 0x3058: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_305a:
	/* 0x305a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_305d:
	/* 0x305d: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3061:
	/* 0x3061: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3063:
	/* 0x3063: je     31a0 <generic_fexit_filter_arg+0x31a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a0;
	}
x86_l_3069:
	/* 0x3069: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_306e:
	/* 0x306e: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_3073:
	/* 0x3073: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3079:
	/* 0x3079: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_307b:
	/* 0x307b: je     31a3 <generic_fexit_filter_arg+0x31a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a3;
	}
x86_l_3081:
	/* 0x3081: mov    ecx,DWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3084:
	/* 0x3084: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3087:
	/* 0x3087: jbe    31a0 <generic_fexit_filter_arg+0x31a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_31a0;
	}
x86_l_308d:
	/* 0x308d: mov    edx,DWORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3090:
	/* 0x3090: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3092:
	/* 0x3092: je     31a0 <generic_fexit_filter_arg+0x31a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a0;
	}
x86_l_3098:
	/* 0x3098: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_309a:
	/* 0x309a: je     31a3 <generic_fexit_filter_arg+0x31a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a3;
	}
x86_l_30a0:
	/* 0x30a0: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_30a3:
	/* 0x30a3: jb     31a0 <generic_fexit_filter_arg+0x31a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_31a0;
	}
x86_l_30a9:
	/* 0x30a9: mov    edx,DWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30ac:
	/* 0x30ac: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_30ae:
	/* 0x30ae: je     31a0 <generic_fexit_filter_arg+0x31a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a0;
	}
x86_l_30b4:
	/* 0x30b4: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_30b6:
	/* 0x30b6: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_30b9:
	/* 0x30b9: je     3696 <generic_fexit_filter_arg+0x3696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13974ULL;
	}
x86_l_30bf:
	/* 0x30bf: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_30c2:
	/* 0x30c2: jb     31a0 <generic_fexit_filter_arg+0x31a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_31a0;
	}
x86_l_30c8:
	/* 0x30c8: mov    ecx,DWORD PTR [rsi+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_30cb:
	/* 0x30cb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_30cd:
	/* 0x30cd: je     31a0 <generic_fexit_filter_arg+0x31a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a0;
	}
x86_l_30d3:
	/* 0x30d3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30d6:
	/* 0x30d6: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_30d8:
	/* 0x30d8: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_30dc:
	/* 0x30dc: jmp    31a3 <generic_fexit_filter_arg+0x31a3> */
	goto x86_l_31a3;
x86_l_30e1:
	/* 0x30e1: movzx  r12d,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_30e6:
	/* 0x30e6: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_30eb:
	/* 0x30eb: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_30ef:
	/* 0x30ef: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_30f6:
	/* 0x30f6: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_30fb:
	/* 0x30fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3100:
	/* 0x3100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3102:
	/* 0x3102: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3105:
	/* 0x3105: je     3333 <generic_fexit_filter_arg+0x3333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3333;
	}
x86_l_310b:
	/* 0x310b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_310e:
	/* 0x310e: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3112:
	/* 0x3112: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3117:
	/* 0x3117: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_311c:
	/* 0x311c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3121:
	/* 0x3121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3123:
	/* 0x3123: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3127:
	/* 0x3127: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3129:
	/* 0x3129: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_312c:
	/* 0x312c: ja     3150 <generic_fexit_filter_arg+0x3150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3150;
	}
x86_l_312e:
	/* 0x312e: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_3133:
	/* 0x3133: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_3136:
	/* 0x3136: jae    3140 <generic_fexit_filter_arg+0x3140> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3140;
	}
x86_l_3138:
	/* 0x3138: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_313b:
	/* 0x313b: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_313e:
	/* 0x313e: jmp    3150 <generic_fexit_filter_arg+0x3150> */
	goto x86_l_3150;
x86_l_3140:
	/* 0x3140: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_3145:
	/* 0x3145: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_3148:
	/* 0x3148: jae    3150 <generic_fexit_filter_arg+0x3150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3150;
	}
x86_l_314a:
	/* 0x314a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_314d:
	/* 0x314d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_3150:
	/* 0x3150: movzx  r12d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3154:
	/* 0x3154: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_3159:
	/* 0x3159: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_315c:
	/* 0x315c: jne    3167 <generic_fexit_filter_arg+0x3167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3167;
	}
x86_l_315e:
	/* 0x315e: test   QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3161:
	/* 0x3161: jne    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14171ULL;
	}
x86_l_3167:
	/* 0x3167: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_316a:
	/* 0x316a: jb     358b <generic_fexit_filter_arg+0x358b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_358b;
	}
x86_l_3170:
	/* 0x3170: mov    rdx,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3174:
	/* 0x3174: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3177:
	/* 0x3177: jb     3503 <generic_fexit_filter_arg+0x3503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3503;
	}
x86_l_317d:
	/* 0x317d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3180:
	/* 0x3180: je     375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14171ULL;
	}
x86_l_3186:
	/* 0x3186: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3189:
	/* 0x3189: jne    3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14181ULL;
	}
x86_l_318f:
	/* 0x318f: mov    rcx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_3192:
	/* 0x3192: test   QWORD PTR [r8],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3195:
	/* 0x3195: jne    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14171ULL;
	}
x86_l_319b:
	/* 0x319b: jmp    358b <generic_fexit_filter_arg+0x358b> */
	goto x86_l_358b;
x86_l_31a0:
	/* 0x31a0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31a3:
	/* 0x31a3: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_31a6:
	/* 0x31a6: jmp    3696 <generic_fexit_filter_arg+0x3696> */
	return 13974ULL;
x86_l_31ab:
	/* 0x31ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31ae:
	/* 0x31ae: jmp    3397 <generic_fexit_filter_arg+0x3397> */
	goto x86_l_3397;
x86_l_31b3:
	/* 0x31b3: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_31b6:
	/* 0x31b6: mov    ecx,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R9, X86_WIDTH_32);
x86_l_31b9:
	/* 0x31b9: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31bb:
	/* 0x31bb: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_31bd:
	/* 0x31bd: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_31c0:
	/* 0x31c0: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_31c5:
	/* 0x31c5: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_31c9:
	/* 0x31c9: ja     31d9 <generic_fexit_filter_arg+0x31d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_31d9;
	}
x86_l_31cb:
	/* 0x31cb: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_31ce:
	/* 0x31ce: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_31d4:
	/* 0x31d4: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_31d7:
	/* 0x31d7: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_31d9:
	/* 0x31d9: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_31dd:
	/* 0x31dd: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31e0:
	/* 0x31e0: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_31e3:
	/* 0x31e3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31e8:
	/* 0x31e8: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_31ec:
	/* 0x31ec: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_31f0:
	/* 0x31f0: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_31f3:
	/* 0x31f3: je     368e <generic_fexit_filter_arg+0x368e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13966ULL;
	}
x86_l_31f9:
	/* 0x31f9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_3200:
	/* 0x3200: lea    r12,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3205:
	/* 0x3205: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_320a:
	/* 0x320a: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_320d:
	/* 0x320d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320f:
	/* 0x320f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3212:
	/* 0x3212: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3219:
	/* 0x3219: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_321e:
	/* 0x321e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3221:
	/* 0x3221: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3223:
	/* 0x3223: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3228:
	/* 0x3228: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_322b:
	/* 0x322b: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3230:
	/* 0x3230: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3233:
	/* 0x3233: je     3691 <generic_fexit_filter_arg+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13969ULL;
	}
x86_l_3239:
	/* 0x3239: cmp    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_323f:
	/* 0x323f: je     3691 <generic_fexit_filter_arg+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13969ULL;
	}
x86_l_3245:
	/* 0x3245: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_324a:
	/* 0x324a: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_324e:
	/* 0x324e: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3253:
	/* 0x3253: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3258:
	/* 0x3258: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_325b:
	/* 0x325b: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_325f:
	/* 0x325f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3264:
	/* 0x3264: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_3267:
	/* 0x3267: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3269:
	/* 0x3269: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_326e:
	/* 0x326e: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_3271:
	/* 0x3271: jbe    3296 <generic_fexit_filter_arg+0x3296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3296;
	}
x86_l_3273:
	/* 0x3273: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_3276:
	/* 0x3276: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_327b:
	/* 0x327b: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_327f:
	/* 0x327f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3282:
	/* 0x3282: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3284:
	/* 0x3284: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_328a:
	/* 0x328a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_328f:
	/* 0x328f: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3294:
	/* 0x3294: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3296:
	/* 0x3296: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_329a:
	/* 0x329a: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_329e:
	/* 0x329e: cmp    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_32a2:
	/* 0x32a2: jg     351b <generic_fexit_filter_arg+0x351b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_351b;
	}
x86_l_32a8:
	/* 0x32a8: cmp    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32ac:
	/* 0x32ac: je     361d <generic_fexit_filter_arg+0x361d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_361d;
	}
x86_l_32b2:
	/* 0x32b2: cmp    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_32b6:
	/* 0x32b6: je     3643 <generic_fexit_filter_arg+0x3643> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13891ULL;
	}
x86_l_32bc:
	/* 0x32bc: cmp    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_32c0:
	/* 0x32c0: jne    368e <generic_fexit_filter_arg+0x368e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13966ULL;
	}
x86_l_32c6:
	/* 0x32c6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_32cd:
	/* 0x32cd: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_32d2:
	/* 0x32d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32d7:
	/* 0x32d7: jmp    3667 <generic_fexit_filter_arg+0x3667> */
	return 13927ULL;
x86_l_32dc:
	/* 0x32dc: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32df:
	/* 0x32df: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_32e2:
	/* 0x32e2: jne    32ee <generic_fexit_filter_arg+0x32ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32ee;
	}
x86_l_32e4:
	/* 0x32e4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_32e7:
	/* 0x32e7: je     32ee <generic_fexit_filter_arg+0x32ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ee;
	}
x86_l_32e9:
	/* 0x32e9: movzx  r12d,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_32ee:
	/* 0x32ee: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_32f1:
	/* 0x32f1: je     32f8 <generic_fexit_filter_arg+0x32f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f8;
	}
x86_l_32f3:
	/* 0x32f3: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_32f6:
	/* 0x32f6: jne    3333 <generic_fexit_filter_arg+0x3333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3333;
	}
x86_l_32f8:
	/* 0x32f8: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_32fd:
	/* 0x32fd: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3301:
	/* 0x3301: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_3308:
	/* 0x3308: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_330d:
	/* 0x330d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3312:
	/* 0x3312: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3314:
	/* 0x3314: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3317:
	/* 0x3317: je     3333 <generic_fexit_filter_arg+0x3333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3333;
	}
x86_l_3319:
	/* 0x3319: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_331c:
	/* 0x331c: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_331f:
	/* 0x331f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3324:
	/* 0x3324: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3329:
	/* 0x3329: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_332e:
	/* 0x332e: jmp    3121 <generic_fexit_filter_arg+0x3121> */
	goto x86_l_3121;
x86_l_3333:
	/* 0x3333: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3336:
	/* 0x3336: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_333b:
	/* 0x333b: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_333e:
	/* 0x333e: jne    3349 <generic_fexit_filter_arg+0x3349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3349;
	}
x86_l_3340:
	/* 0x3340: test   DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3343:
	/* 0x3343: jne    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14171ULL;
	}
x86_l_3349:
	/* 0x3349: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_334c:
	/* 0x334c: jb     358b <generic_fexit_filter_arg+0x358b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_358b;
	}
x86_l_3352:
	/* 0x3352: mov    edx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3356:
	/* 0x3356: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3359:
	/* 0x3359: jb     3586 <generic_fexit_filter_arg+0x3586> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3586;
	}
x86_l_335f:
	/* 0x335f: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3362:
	/* 0x3362: je     375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14171ULL;
	}
x86_l_3368:
	/* 0x3368: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_336b:
	/* 0x336b: jne    3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14181ULL;
	}
x86_l_3371:
	/* 0x3371: mov    rcx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_3374:
	/* 0x3374: test   DWORD PTR [r8],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3377:
	/* 0x3377: jne    375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14171ULL;
	}
x86_l_337d:
	/* 0x337d: jmp    358b <generic_fexit_filter_arg+0x358b> */
	goto x86_l_358b;
x86_l_3382:
	/* 0x3382: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3387:
	/* 0x3387: jmp    3391 <generic_fexit_filter_arg+0x3391> */
	goto x86_l_3391;
x86_l_3389:
	/* 0x3389: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_338e:
	/* 0x338e: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3391:
	/* 0x3391: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_3394:
	/* 0x3394: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_3397:
	/* 0x3397: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_339a:
	/* 0x339a: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_339e:
	/* 0x339e: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_33a3:
	/* 0x33a3: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_33a6:
	/* 0x33a6: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_33a8:
	/* 0x33a8: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33aa:
	/* 0x33aa: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_33ac:
	/* 0x33ac: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_33af:
	/* 0x33af: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_33b4:
	/* 0x33b4: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_33b8:
	/* 0x33b8: ja     33c8 <generic_fexit_filter_arg+0x33c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_33c8;
	}
x86_l_33ba:
	/* 0x33ba: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_33bd:
	/* 0x33bd: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_33c3:
	/* 0x33c3: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_33c6:
	/* 0x33c6: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_33c8:
	/* 0x33c8: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_33cc:
	/* 0x33cc: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33d0:
	/* 0x33d0: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_33d3:
	/* 0x33d3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d8:
	/* 0x33d8: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_33dc:
	/* 0x33dc: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_33e0:
	/* 0x33e0: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_33e3:
	/* 0x33e3: je     372f <generic_fexit_filter_arg+0x372f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14127ULL;
	}
x86_l_33e9:
	/* 0x33e9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_33f0:
	/* 0x33f0: lea    r12,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33f5:
	/* 0x33f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33fa:
	/* 0x33fa: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_33fd:
	/* 0x33fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ff:
	/* 0x33ff: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3402:
	/* 0x3402: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3409:
	/* 0x3409: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_340e:
	/* 0x340e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3411:
	/* 0x3411: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3413:
	/* 0x3413: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3418:
	/* 0x3418: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_341b:
	/* 0x341b: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3420:
	/* 0x3420: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3423:
	/* 0x3423: je     3732 <generic_fexit_filter_arg+0x3732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14130ULL;
	}
x86_l_3429:
	/* 0x3429: cmp    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_342f:
	/* 0x342f: je     3732 <generic_fexit_filter_arg+0x3732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14130ULL;
	}
x86_l_3435:
	/* 0x3435: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3439:
	/* 0x3439: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_343e:
	/* 0x343e: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3441:
	/* 0x3441: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3445:
	/* 0x3445: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_344a:
	/* 0x344a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_344f:
	/* 0x344f: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_3452:
	/* 0x3452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3454:
	/* 0x3454: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_3459:
	/* 0x3459: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_345c:
	/* 0x345c: jbe    3482 <generic_fexit_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3482;
	}
x86_l_345e:
	/* 0x345e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3462:
	/* 0x3462: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3467:
	/* 0x3467: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_346b:
	/* 0x346b: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_346e:
	/* 0x346e: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3470:
	/* 0x3470: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3476:
	/* 0x3476: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_347b:
	/* 0x347b: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3480:
	/* 0x3480: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3482:
	/* 0x3482: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3486:
	/* 0x3486: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_348a:
	/* 0x348a: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_348f:
	/* 0x348f: jg     354f <generic_fexit_filter_arg+0x354f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_354f;
	}
x86_l_3495:
	/* 0x3495: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_349a:
	/* 0x349a: je     36be <generic_fexit_filter_arg+0x36be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14014ULL;
	}
x86_l_34a0:
	/* 0x34a0: cmp    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_34a5:
	/* 0x34a5: je     36e4 <generic_fexit_filter_arg+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_34ab:
	/* 0x34ab: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_34b0:
	/* 0x34b0: jne    372f <generic_fexit_filter_arg+0x372f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14127ULL;
	}
x86_l_34b6:
	/* 0x34b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_34bd:
	/* 0x34bd: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_34c2:
	/* 0x34c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34c7:
	/* 0x34c7: jmp    3708 <generic_fexit_filter_arg+0x3708> */
	return 14088ULL;
x86_l_34cc:
	/* 0x34cc: cmp    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_34d1:
	/* 0x34d1: je     35af <generic_fexit_filter_arg+0x35af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35af;
	}
x86_l_34d7:
	/* 0x34d7: cmp    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_34dc:
	/* 0x34dc: je     35d5 <generic_fexit_filter_arg+0x35d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35d5;
	}
x86_l_34e2:
	/* 0x34e2: cmp    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_34e7:
	/* 0x34e7: jne    360d <generic_fexit_filter_arg+0x360d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_360d;
	}
x86_l_34ed:
	/* 0x34ed: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_34f4:
	/* 0x34f4: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_34f9:
	/* 0x34f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34fe:
	/* 0x34fe: jmp    35e6 <generic_fexit_filter_arg+0x35e6> */
	goto x86_l_35e6;
x86_l_3503:
	/* 0x3503: cmp    QWORD PTR [r8],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3506:
	/* 0x3506: jne    358b <generic_fexit_filter_arg+0x358b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_358b;
	}
x86_l_350c:
	/* 0x350c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_350f:
	/* 0x350f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3512:
	/* 0x3512: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_3516:
	/* 0x3516: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	return 14166ULL;
x86_l_351b:
	/* 0x351b: cmp    DWORD PTR [rsp],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_351f:
	/* 0x351f: je     3630 <generic_fexit_filter_arg+0x3630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13872ULL;
	}
x86_l_3525:
	/* 0x3525: cmp    DWORD PTR [rsp],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3529:
	/* 0x3529: je     3656 <generic_fexit_filter_arg+0x3656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13910ULL;
	}
x86_l_352f:
	/* 0x352f: cmp    DWORD PTR [rsp],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3533:
	/* 0x3533: jne    368e <generic_fexit_filter_arg+0x368e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13966ULL;
	}
x86_l_3539:
	/* 0x3539: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3540:
	/* 0x3540: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3545:
	/* 0x3545: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_354a:
	/* 0x354a: jmp    3667 <generic_fexit_filter_arg+0x3667> */
	return 13927ULL;
x86_l_354f:
	/* 0x354f: cmp    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_3554:
	/* 0x3554: je     36d1 <generic_fexit_filter_arg+0x36d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14033ULL;
	}
x86_l_355a:
	/* 0x355a: cmp    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_355f:
	/* 0x355f: je     36f7 <generic_fexit_filter_arg+0x36f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14071ULL;
	}
x86_l_3565:
	/* 0x3565: cmp    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_356a:
	/* 0x356a: jne    372f <generic_fexit_filter_arg+0x372f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14127ULL;
	}
x86_l_3570:
	/* 0x3570: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3577:
	/* 0x3577: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_357c:
	/* 0x357c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3581:
	/* 0x3581: jmp    3708 <generic_fexit_filter_arg+0x3708> */
	return 14088ULL;
x86_l_3586:
	/* 0x3586: cmp    DWORD PTR [r8],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3589:
	/* 0x3589: je     350c <generic_fexit_filter_arg+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_350c;
	}
x86_l_358b:
	/* 0x358b: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_358e:
	/* 0x358e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3591:
	/* 0x3591: je     375b <generic_fexit_filter_arg+0x375b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14171ULL;
	}
x86_l_3597:
	/* 0x3597: jmp    3765 <generic_fexit_filter_arg+0x3765> */
	return 14181ULL;
x86_l_359c:
	/* 0x359c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_35a3:
	/* 0x35a3: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35a8:
	/* 0x35a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35ad:
	/* 0x35ad: jmp    35e6 <generic_fexit_filter_arg+0x35e6> */
	goto x86_l_35e6;
x86_l_35af:
	/* 0x35af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_35b6:
	/* 0x35b6: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35bb:
	/* 0x35bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35c0:
	/* 0x35c0: jmp    35e6 <generic_fexit_filter_arg+0x35e6> */
	goto x86_l_35e6;
x86_l_35c2:
	/* 0x35c2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_35c9:
	/* 0x35c9: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35ce:
	/* 0x35ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35d3:
	/* 0x35d3: jmp    35e6 <generic_fexit_filter_arg+0x35e6> */
	goto x86_l_35e6;
x86_l_35d5:
	/* 0x35d5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_35dc:
	/* 0x35dc: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35e1:
	/* 0x35e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35e6:
	/* 0x35e6: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35eb:
	/* 0x35eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ed:
	/* 0x35ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35f0:
	/* 0x35f0: je     360d <generic_fexit_filter_arg+0x360d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_360d;
	}
x86_l_35f2:
	/* 0x35f2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_35f5:
	/* 0x35f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35fa:
	/* 0x35fa: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_35ff:
	/* 0x35ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3601:
	/* 0x3601: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3604:
	/* 0x3604: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3607:
	/* 0x3607: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_360b:
	/* 0x360b: jmp    3610 <generic_fexit_filter_arg+0x3610> */
	goto x86_l_3610;
x86_l_360d:
	/* 0x360d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3610:
	/* 0x3610: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3615:
	/* 0x3615: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3618:
	/* 0x3618: jmp    373b <generic_fexit_filter_arg+0x373b> */
	return 14139ULL;
x86_l_361d:
	/* 0x361d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3624:
	/* 0x3624: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3629:
	/* 0x3629: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_362e:
	/* 0x362e: jmp    3667 <generic_fexit_filter_arg+0x3667> */
	return 13927ULL;
	return 13872ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13872ULL: goto x86_l_3630;
	case 13879ULL: goto x86_l_3637;
	case 13884ULL: goto x86_l_363c;
	case 13889ULL: goto x86_l_3641;
	case 13891ULL: goto x86_l_3643;
	case 13898ULL: goto x86_l_364a;
	case 13903ULL: goto x86_l_364f;
	case 13908ULL: goto x86_l_3654;
	case 13910ULL: goto x86_l_3656;
	case 13917ULL: goto x86_l_365d;
	case 13922ULL: goto x86_l_3662;
	case 13927ULL: goto x86_l_3667;
	case 13932ULL: goto x86_l_366c;
	case 13934ULL: goto x86_l_366e;
	case 13937ULL: goto x86_l_3671;
	case 13939ULL: goto x86_l_3673;
	case 13942ULL: goto x86_l_3676;
	case 13947ULL: goto x86_l_367b;
	case 13952ULL: goto x86_l_3680;
	case 13954ULL: goto x86_l_3682;
	case 13957ULL: goto x86_l_3685;
	case 13960ULL: goto x86_l_3688;
	case 13964ULL: goto x86_l_368c;
	case 13966ULL: goto x86_l_368e;
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	case 13978ULL: goto x86_l_369a;
	case 13981ULL: goto x86_l_369d;
	case 13987ULL: goto x86_l_36a3;
	case 13989ULL: goto x86_l_36a5;
	case 13999ULL: goto x86_l_36af;
	case 14003ULL: goto x86_l_36b3;
	case 14009ULL: goto x86_l_36b9;
	case 14014ULL: goto x86_l_36be;
	case 14021ULL: goto x86_l_36c5;
	case 14026ULL: goto x86_l_36ca;
	case 14031ULL: goto x86_l_36cf;
	case 14033ULL: goto x86_l_36d1;
	case 14040ULL: goto x86_l_36d8;
	case 14045ULL: goto x86_l_36dd;
	case 14050ULL: goto x86_l_36e2;
	case 14052ULL: goto x86_l_36e4;
	case 14059ULL: goto x86_l_36eb;
	case 14064ULL: goto x86_l_36f0;
	case 14069ULL: goto x86_l_36f5;
	case 14071ULL: goto x86_l_36f7;
	case 14078ULL: goto x86_l_36fe;
	case 14083ULL: goto x86_l_3703;
	case 14088ULL: goto x86_l_3708;
	case 14093ULL: goto x86_l_370d;
	case 14095ULL: goto x86_l_370f;
	case 14098ULL: goto x86_l_3712;
	case 14100ULL: goto x86_l_3714;
	case 14103ULL: goto x86_l_3717;
	case 14108ULL: goto x86_l_371c;
	case 14113ULL: goto x86_l_3721;
	case 14115ULL: goto x86_l_3723;
	case 14118ULL: goto x86_l_3726;
	case 14121ULL: goto x86_l_3729;
	case 14125ULL: goto x86_l_372d;
	case 14127ULL: goto x86_l_372f;
	case 14130ULL: goto x86_l_3732;
	case 14135ULL: goto x86_l_3737;
	case 14139ULL: goto x86_l_373b;
	case 14142ULL: goto x86_l_373e;
	case 14144ULL: goto x86_l_3740;
	case 14146ULL: goto x86_l_3742;
	case 14156ULL: goto x86_l_374c;
	case 14160ULL: goto x86_l_3750;
	case 14162ULL: goto x86_l_3752;
	case 14166ULL: goto x86_l_3756;
	case 14169ULL: goto x86_l_3759;
	case 14171ULL: goto x86_l_375b;
	case 14175ULL: goto x86_l_375f;
	case 14177ULL: goto x86_l_3761;
	case 14179ULL: goto x86_l_3763;
	case 14181ULL: goto x86_l_3765;
	case 14185ULL: goto x86_l_3769;
	case 14187ULL: goto x86_l_376b;
	case 14191ULL: goto x86_l_376f;
	case 14197ULL: goto x86_l_3775;
	case 14200ULL: goto x86_l_3778;
	case 14206ULL: goto x86_l_377e;
	case 14210ULL: goto x86_l_3782;
	case 14216ULL: goto x86_l_3788;
	case 14218ULL: goto x86_l_378a;
	case 14222ULL: goto x86_l_378e;
	case 14228ULL: goto x86_l_3794;
	case 14232ULL: goto x86_l_3798;
	case 14238ULL: goto x86_l_379e;
	case 14242ULL: goto x86_l_37a2;
	case 14248ULL: goto x86_l_37a8;
	case 14252ULL: goto x86_l_37ac;
	case 14258ULL: goto x86_l_37b2;
	case 14261ULL: goto x86_l_37b5;
	case 14266ULL: goto x86_l_37ba;
	case 14273ULL: goto x86_l_37c1;
	case 14280ULL: goto x86_l_37c8;
	case 14285ULL: goto x86_l_37cd;
	case 14290ULL: goto x86_l_37d2;
	case 14293ULL: goto x86_l_37d5;
	case 14298ULL: goto x86_l_37da;
	case 14300ULL: goto x86_l_37dc;
	case 14307ULL: goto x86_l_37e3;
	case 14312ULL: goto x86_l_37e8;
	case 14317ULL: goto x86_l_37ed;
	case 14320ULL: goto x86_l_37f0;
	case 14325ULL: goto x86_l_37f5;
	case 14327ULL: goto x86_l_37f7;
	case 14329ULL: goto x86_l_37f9;
	case 14336ULL: goto x86_l_3800;
	case 14338ULL: goto x86_l_3802;
	case 14339ULL: goto x86_l_3803;
	case 14344ULL: goto x86_l_3808;
	case 14347ULL: goto x86_l_380b;
	case 14355ULL: goto x86_l_3813;
	case 14357ULL: goto x86_l_3815;
	case 14363ULL: goto x86_l_381b;
	case 14371ULL: goto x86_l_3823;
	case 14373ULL: goto x86_l_3825;
	case 14379ULL: goto x86_l_382b;
	case 14387ULL: goto x86_l_3833;
	case 14389ULL: goto x86_l_3835;
	case 14395ULL: goto x86_l_383b;
	case 14403ULL: goto x86_l_3843;
	case 14405ULL: goto x86_l_3845;
	case 14411ULL: goto x86_l_384b;
	case 14419ULL: goto x86_l_3853;
	case 14421ULL: goto x86_l_3855;
	case 14427ULL: goto x86_l_385b;
	case 14435ULL: goto x86_l_3863;
	case 14437ULL: goto x86_l_3865;
	case 14444ULL: goto x86_l_386c;
	case 14451ULL: goto x86_l_3873;
	case 14456ULL: goto x86_l_3878;
	case 14461ULL: goto x86_l_387d;
	case 14464ULL: goto x86_l_3880;
	case 14469ULL: goto x86_l_3885;
	case 14471ULL: goto x86_l_3887;
	case 14475ULL: goto x86_l_388b;
	case 14480ULL: goto x86_l_3890;
	case 14482ULL: goto x86_l_3892;
	case 14487ULL: goto x86_l_3897;
	case 14492ULL: goto x86_l_389c;
	case 14499ULL: goto x86_l_38a3;
	case 14504ULL: goto x86_l_38a8;
	case 14509ULL: goto x86_l_38ad;
	case 14511ULL: goto x86_l_38af;
	case 14514ULL: goto x86_l_38b2;
	case 14520ULL: goto x86_l_38b8;
	case 14527ULL: goto x86_l_38bf;
	case 14532ULL: goto x86_l_38c4;
	case 14537ULL: goto x86_l_38c9;
	case 14539ULL: goto x86_l_38cb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3630:
	/* 0x3630: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3637:
	/* 0x3637: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_363c:
	/* 0x363c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3641:
	/* 0x3641: jmp    3667 <generic_fexit_filter_arg+0x3667> */
	goto x86_l_3667;
x86_l_3643:
	/* 0x3643: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_364a:
	/* 0x364a: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_364f:
	/* 0x364f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3654:
	/* 0x3654: jmp    3667 <generic_fexit_filter_arg+0x3667> */
	goto x86_l_3667;
x86_l_3656:
	/* 0x3656: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_365d:
	/* 0x365d: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3662:
	/* 0x3662: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3667:
	/* 0x3667: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_366c:
	/* 0x366c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366e:
	/* 0x366e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3671:
	/* 0x3671: je     368e <generic_fexit_filter_arg+0x368e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_368e;
	}
x86_l_3673:
	/* 0x3673: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3676:
	/* 0x3676: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_367b:
	/* 0x367b: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3680:
	/* 0x3680: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3682:
	/* 0x3682: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3685:
	/* 0x3685: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3688:
	/* 0x3688: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_368c:
	/* 0x368c: jmp    3691 <generic_fexit_filter_arg+0x3691> */
	goto x86_l_3691;
x86_l_368e:
	/* 0x368e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3691:
	/* 0x3691: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3696:
	/* 0x3696: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_369a:
	/* 0x369a: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_369d:
	/* 0x369d: ja     3756 <generic_fexit_filter_arg+0x3756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3756;
	}
x86_l_36a3:
	/* 0x36a3: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36a5:
	/* 0x36a5: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_36af:
	/* 0x36af: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_36b3:
	/* 0x36b3: jb     3752 <generic_fexit_filter_arg+0x3752> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3752;
	}
x86_l_36b9:
	/* 0x36b9: jmp    3756 <generic_fexit_filter_arg+0x3756> */
	goto x86_l_3756;
x86_l_36be:
	/* 0x36be: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_36c5:
	/* 0x36c5: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_36ca:
	/* 0x36ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36cf:
	/* 0x36cf: jmp    3708 <generic_fexit_filter_arg+0x3708> */
	goto x86_l_3708;
x86_l_36d1:
	/* 0x36d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_36d8:
	/* 0x36d8: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_36dd:
	/* 0x36dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36e2:
	/* 0x36e2: jmp    3708 <generic_fexit_filter_arg+0x3708> */
	goto x86_l_3708;
x86_l_36e4:
	/* 0x36e4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_36eb:
	/* 0x36eb: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_36f0:
	/* 0x36f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36f5:
	/* 0x36f5: jmp    3708 <generic_fexit_filter_arg+0x3708> */
	goto x86_l_3708;
x86_l_36f7:
	/* 0x36f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_36fe:
	/* 0x36fe: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3703:
	/* 0x3703: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3708:
	/* 0x3708: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_370d:
	/* 0x370d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_370f:
	/* 0x370f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3712:
	/* 0x3712: je     372f <generic_fexit_filter_arg+0x372f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_372f;
	}
x86_l_3714:
	/* 0x3714: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3717:
	/* 0x3717: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_371c:
	/* 0x371c: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3721:
	/* 0x3721: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3723:
	/* 0x3723: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3726:
	/* 0x3726: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3729:
	/* 0x3729: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_372d:
	/* 0x372d: jmp    3732 <generic_fexit_filter_arg+0x3732> */
	goto x86_l_3732;
x86_l_372f:
	/* 0x372f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3732:
	/* 0x3732: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3737:
	/* 0x3737: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_373b:
	/* 0x373b: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_373e:
	/* 0x373e: ja     3756 <generic_fexit_filter_arg+0x3756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3756;
	}
x86_l_3740:
	/* 0x3740: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3742:
	/* 0x3742: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_374c:
	/* 0x374c: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3750:
	/* 0x3750: jae    3756 <generic_fexit_filter_arg+0x3756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3756;
	}
x86_l_3752:
	/* 0x3752: xor    r12,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_3756:
	/* 0x3756: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_3759:
	/* 0x3759: je     3765 <generic_fexit_filter_arg+0x3765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3765;
	}
x86_l_375b:
	/* 0x375b: cmp    rbp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 1ULL);
x86_l_375f:
	/* 0x375f: je     37dc <generic_fexit_filter_arg+0x37dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37dc;
	}
x86_l_3761:
	/* 0x3761: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_3763:
	/* 0x3763: jne    37ba <generic_fexit_filter_arg+0x37ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37ba;
	}
x86_l_3765:
	/* 0x3765: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_3769:
	/* 0x3769: jg     378a <generic_fexit_filter_arg+0x378a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_378a;
	}
x86_l_376b:
	/* 0x376b: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_376f:
	/* 0x376f: je     3808 <generic_fexit_filter_arg+0x3808> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3808;
	}
x86_l_3775:
	/* 0x3775: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_3778:
	/* 0x3778: je     3815 <generic_fexit_filter_arg+0x3815> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3815;
	}
x86_l_377e:
	/* 0x377e: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_3782:
	/* 0x3782: je     3825 <generic_fexit_filter_arg+0x3825> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3825;
	}
x86_l_3788:
	/* 0x3788: jmp    37a8 <generic_fexit_filter_arg+0x37a8> */
	goto x86_l_37a8;
x86_l_378a:
	/* 0x378a: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_378e:
	/* 0x378e: je     3835 <generic_fexit_filter_arg+0x3835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3835;
	}
x86_l_3794:
	/* 0x3794: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_3798:
	/* 0x3798: je     3845 <generic_fexit_filter_arg+0x3845> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3845;
	}
x86_l_379e:
	/* 0x379e: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_37a2:
	/* 0x37a2: je     3855 <generic_fexit_filter_arg+0x3855> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3855;
	}
x86_l_37a8:
	/* 0x37a8: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_37ac:
	/* 0x37ac: jg     3887 <generic_fexit_filter_arg+0x3887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3887;
	}
x86_l_37b2:
	/* 0x37b2: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_37b5:
	/* 0x37b5: jmp    3865 <generic_fexit_filter_arg+0x3865> */
	goto x86_l_3865;
x86_l_37ba:
	/* 0x37ba: mov    DWORD PTR [r14+0x5ef4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_37c1:
	/* 0x37c1: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_37c8:
	/* 0x37c8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_37cd:
	/* 0x37cd: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_37d2:
	/* 0x37d2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_37d5:
	/* 0x37d5: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_37da:
	/* 0x37da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37dc:
	/* 0x37dc: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_37e3:
	/* 0x37e3: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_37e8:
	/* 0x37e8: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_37ed:
	/* 0x37ed: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_37f0:
	/* 0x37f0: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_37f5:
	/* 0x37f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37f7:
	/* 0x37f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37f9:
	/* 0x37f9: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_3800:
	/* 0x3800: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3802:
	/* 0x3802: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3803:
	/* 0x3803: jmp    38d0 <generic_fexit_filter_arg+0x38d0> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3808:
	/* 0x3808: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_380b:
	/* 0x380b: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_3813:
	/* 0x3813: jne    3865 <generic_fexit_filter_arg+0x3865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3865;
	}
x86_l_3815:
	/* 0x3815: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_381b:
	/* 0x381b: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_3823:
	/* 0x3823: jne    3865 <generic_fexit_filter_arg+0x3865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3865;
	}
x86_l_3825:
	/* 0x3825: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_382b:
	/* 0x382b: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_3833:
	/* 0x3833: jne    3865 <generic_fexit_filter_arg+0x3865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3865;
	}
x86_l_3835:
	/* 0x3835: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_383b:
	/* 0x383b: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_3843:
	/* 0x3843: jne    3865 <generic_fexit_filter_arg+0x3865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3865;
	}
x86_l_3845:
	/* 0x3845: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_384b:
	/* 0x384b: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_3853:
	/* 0x3853: jne    3865 <generic_fexit_filter_arg+0x3865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3865;
	}
x86_l_3855:
	/* 0x3855: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_385b:
	/* 0x385b: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_3863:
	/* 0x3863: je     3887 <generic_fexit_filter_arg+0x3887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3887;
	}
x86_l_3865:
	/* 0x3865: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_386c:
	/* 0x386c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_3873:
	/* 0x3873: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3878:
	/* 0x3878: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_387d:
	/* 0x387d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3880:
	/* 0x3880: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3885:
	/* 0x3885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3887:
	/* 0x3887: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_388b:
	/* 0x388b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3890:
	/* 0x3890: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3892:
	/* 0x3892: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3897:
	/* 0x3897: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_389c:
	/* 0x389c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_38a3:
	/* 0x38a3: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_38a8:
	/* 0x38a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38ad:
	/* 0x38ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38af:
	/* 0x38af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38b2:
	/* 0x38b2: je     37f7 <generic_fexit_filter_arg+0x37f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f7;
	}
x86_l_38b8:
	/* 0x38b8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_38bf:
	/* 0x38bf: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_38c4:
	/* 0x38c4: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_38c9:
	/* 0x38c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38cb:
	/* 0x38cb: jmp    37f7 <generic_fexit_filter_arg+0x37f7> */
	goto x86_l_37f7;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12904U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1769ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1773ULL && __x86_pc <= 3522ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3526ULL && __x86_pc <= 5298ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5302ULL && __x86_pc <= 7058ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7061ULL && __x86_pc <= 8755ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8762ULL && __x86_pc <= 10611ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10618ULL && __x86_pc <= 12259ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12263ULL && __x86_pc <= 13870ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13872ULL && __x86_pc <= 14539ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

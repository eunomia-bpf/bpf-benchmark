extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
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
extern char usdt_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 21ULL: goto x86_l_15;
	case 28ULL: goto x86_l_1c;
	case 33ULL: goto x86_l_21;
	case 38ULL: goto x86_l_26;
	case 40ULL: goto x86_l_28;
	case 43ULL: goto x86_l_2b;
	case 49ULL: goto x86_l_31;
	case 52ULL: goto x86_l_34;
	case 59ULL: goto x86_l_3b;
	case 66ULL: goto x86_l_42;
	case 73ULL: goto x86_l_49;
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
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 152ULL: goto x86_l_98;
	case 155ULL: goto x86_l_9b;
	case 158ULL: goto x86_l_9e;
	case 162ULL: goto x86_l_a2;
	case 164ULL: goto x86_l_a4;
	case 170ULL: goto x86_l_aa;
	case 173ULL: goto x86_l_ad;
	case 176ULL: goto x86_l_b0;
	case 178ULL: goto x86_l_b2;
	case 184ULL: goto x86_l_b8;
	case 187ULL: goto x86_l_bb;
	case 190ULL: goto x86_l_be;
	case 192ULL: goto x86_l_c0;
	case 198ULL: goto x86_l_c6;
	case 201ULL: goto x86_l_c9;
	case 204ULL: goto x86_l_cc;
	case 206ULL: goto x86_l_ce;
	case 212ULL: goto x86_l_d4;
	case 215ULL: goto x86_l_d7;
	case 218ULL: goto x86_l_da;
	case 220ULL: goto x86_l_dc;
	case 226ULL: goto x86_l_e2;
	case 230ULL: goto x86_l_e6;
	case 236ULL: goto x86_l_ec;
	case 240ULL: goto x86_l_f0;
	case 246ULL: goto x86_l_f6;
	case 252ULL: goto x86_l_fc;
	case 254ULL: goto x86_l_fe;
	case 260ULL: goto x86_l_104;
	case 263ULL: goto x86_l_107;
	case 267ULL: goto x86_l_10b;
	case 273ULL: goto x86_l_111;
	case 282ULL: goto x86_l_11a;
	case 288ULL: goto x86_l_120;
	case 291ULL: goto x86_l_123;
	case 294ULL: goto x86_l_126;
	case 298ULL: goto x86_l_12a;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 315ULL: goto x86_l_13b;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 327ULL: goto x86_l_147;
	case 330ULL: goto x86_l_14a;
	case 336ULL: goto x86_l_150;
	case 339ULL: goto x86_l_153;
	case 345ULL: goto x86_l_159;
	case 348ULL: goto x86_l_15c;
	case 354ULL: goto x86_l_162;
	case 357ULL: goto x86_l_165;
	case 359ULL: goto x86_l_167;
	case 364ULL: goto x86_l_16c;
	case 367ULL: goto x86_l_16f;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 379ULL: goto x86_l_17b;
	case 385ULL: goto x86_l_181;
	case 388ULL: goto x86_l_184;
	case 391ULL: goto x86_l_187;
	case 394ULL: goto x86_l_18a;
	case 400ULL: goto x86_l_190;
	case 403ULL: goto x86_l_193;
	case 407ULL: goto x86_l_197;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 429ULL: goto x86_l_1ad;
	case 435ULL: goto x86_l_1b3;
	case 440ULL: goto x86_l_1b8;
	case 443ULL: goto x86_l_1bb;
	case 449ULL: goto x86_l_1c1;
	case 454ULL: goto x86_l_1c6;
	case 458ULL: goto x86_l_1ca;
	case 461ULL: goto x86_l_1cd;
	case 465ULL: goto x86_l_1d1;
	case 473ULL: goto x86_l_1d9;
	case 480ULL: goto x86_l_1e0;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 492ULL: goto x86_l_1ec;
	case 495ULL: goto x86_l_1ef;
	case 498ULL: goto x86_l_1f2;
	case 501ULL: goto x86_l_1f5;
	case 507ULL: goto x86_l_1fb;
	case 510ULL: goto x86_l_1fe;
	case 516ULL: goto x86_l_204;
	case 519ULL: goto x86_l_207;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 536ULL: goto x86_l_218;
	case 538ULL: goto x86_l_21a;
	case 541ULL: goto x86_l_21d;
	case 547ULL: goto x86_l_223;
	case 550ULL: goto x86_l_226;
	case 554ULL: goto x86_l_22a;
	case 559ULL: goto x86_l_22f;
	case 563ULL: goto x86_l_233;
	case 566ULL: goto x86_l_236;
	case 568ULL: goto x86_l_238;
	case 572ULL: goto x86_l_23c;
	case 577ULL: goto x86_l_241;
	case 582ULL: goto x86_l_246;
	case 586ULL: goto x86_l_24a;
	case 589ULL: goto x86_l_24d;
	case 593ULL: goto x86_l_251;
	case 599ULL: goto x86_l_257;
	case 606ULL: goto x86_l_25e;
	case 611ULL: goto x86_l_263;
	case 615ULL: goto x86_l_267;
	case 618ULL: goto x86_l_26a;
	case 622ULL: goto x86_l_26e;
	case 628ULL: goto x86_l_274;
	case 635ULL: goto x86_l_27b;
	case 640ULL: goto x86_l_280;
	case 644ULL: goto x86_l_284;
	case 647ULL: goto x86_l_287;
	case 651ULL: goto x86_l_28b;
	case 657ULL: goto x86_l_291;
	case 664ULL: goto x86_l_298;
	case 669ULL: goto x86_l_29d;
	case 673ULL: goto x86_l_2a1;
	case 676ULL: goto x86_l_2a4;
	case 680ULL: goto x86_l_2a8;
	case 686ULL: goto x86_l_2ae;
	case 693ULL: goto x86_l_2b5;
	case 698ULL: goto x86_l_2ba;
	case 702ULL: goto x86_l_2be;
	case 705ULL: goto x86_l_2c1;
	case 709ULL: goto x86_l_2c5;
	case 715ULL: goto x86_l_2cb;
	case 722ULL: goto x86_l_2d2;
	case 727ULL: goto x86_l_2d7;
	case 731ULL: goto x86_l_2db;
	case 734ULL: goto x86_l_2de;
	case 738ULL: goto x86_l_2e2;
	case 744ULL: goto x86_l_2e8;
	case 751ULL: goto x86_l_2ef;
	case 756ULL: goto x86_l_2f4;
	case 760ULL: goto x86_l_2f8;
	case 763ULL: goto x86_l_2fb;
	case 767ULL: goto x86_l_2ff;
	case 773ULL: goto x86_l_305;
	case 780ULL: goto x86_l_30c;
	case 785ULL: goto x86_l_311;
	case 789ULL: goto x86_l_315;
	case 792ULL: goto x86_l_318;
	case 796ULL: goto x86_l_31c;
	case 802ULL: goto x86_l_322;
	case 809ULL: goto x86_l_329;
	case 814ULL: goto x86_l_32e;
	case 818ULL: goto x86_l_332;
	case 821ULL: goto x86_l_335;
	case 825ULL: goto x86_l_339;
	case 831ULL: goto x86_l_33f;
	case 838ULL: goto x86_l_346;
	case 843ULL: goto x86_l_34b;
	case 847ULL: goto x86_l_34f;
	case 850ULL: goto x86_l_352;
	case 854ULL: goto x86_l_356;
	case 860ULL: goto x86_l_35c;
	case 867ULL: goto x86_l_363;
	case 872ULL: goto x86_l_368;
	case 876ULL: goto x86_l_36c;
	case 879ULL: goto x86_l_36f;
	case 883ULL: goto x86_l_373;
	case 889ULL: goto x86_l_379;
	case 896ULL: goto x86_l_380;
	case 901ULL: goto x86_l_385;
	case 905ULL: goto x86_l_389;
	case 908ULL: goto x86_l_38c;
	case 912ULL: goto x86_l_390;
	case 918ULL: goto x86_l_396;
	case 925ULL: goto x86_l_39d;
	case 930ULL: goto x86_l_3a2;
	case 934ULL: goto x86_l_3a6;
	case 937ULL: goto x86_l_3a9;
	case 941ULL: goto x86_l_3ad;
	case 947ULL: goto x86_l_3b3;
	case 954ULL: goto x86_l_3ba;
	case 959ULL: goto x86_l_3bf;
	case 963ULL: goto x86_l_3c3;
	case 966ULL: goto x86_l_3c6;
	case 970ULL: goto x86_l_3ca;
	case 976ULL: goto x86_l_3d0;
	case 983ULL: goto x86_l_3d7;
	case 988ULL: goto x86_l_3dc;
	case 992ULL: goto x86_l_3e0;
	case 995ULL: goto x86_l_3e3;
	case 999ULL: goto x86_l_3e7;
	case 1005ULL: goto x86_l_3ed;
	case 1012ULL: goto x86_l_3f4;
	case 1017ULL: goto x86_l_3f9;
	case 1021ULL: goto x86_l_3fd;
	case 1024ULL: goto x86_l_400;
	case 1028ULL: goto x86_l_404;
	case 1034ULL: goto x86_l_40a;
	case 1041ULL: goto x86_l_411;
	case 1046ULL: goto x86_l_416;
	case 1050ULL: goto x86_l_41a;
	case 1053ULL: goto x86_l_41d;
	case 1057ULL: goto x86_l_421;
	case 1063ULL: goto x86_l_427;
	case 1070ULL: goto x86_l_42e;
	case 1075ULL: goto x86_l_433;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1086ULL: goto x86_l_43e;
	case 1092ULL: goto x86_l_444;
	case 1099ULL: goto x86_l_44b;
	case 1104ULL: goto x86_l_450;
	case 1108ULL: goto x86_l_454;
	case 1111ULL: goto x86_l_457;
	case 1115ULL: goto x86_l_45b;
	case 1121ULL: goto x86_l_461;
	case 1128ULL: goto x86_l_468;
	case 1133ULL: goto x86_l_46d;
	case 1137ULL: goto x86_l_471;
	case 1140ULL: goto x86_l_474;
	case 1144ULL: goto x86_l_478;
	case 1150ULL: goto x86_l_47e;
	case 1157ULL: goto x86_l_485;
	case 1162ULL: goto x86_l_48a;
	case 1166ULL: goto x86_l_48e;
	case 1169ULL: goto x86_l_491;
	case 1173ULL: goto x86_l_495;
	case 1179ULL: goto x86_l_49b;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1195ULL: goto x86_l_4ab;
	case 1198ULL: goto x86_l_4ae;
	case 1202ULL: goto x86_l_4b2;
	case 1208ULL: goto x86_l_4b8;
	case 1215ULL: goto x86_l_4bf;
	case 1220ULL: goto x86_l_4c4;
	case 1224ULL: goto x86_l_4c8;
	case 1227ULL: goto x86_l_4cb;
	case 1231ULL: goto x86_l_4cf;
	case 1237ULL: goto x86_l_4d5;
	case 1244ULL: goto x86_l_4dc;
	case 1249ULL: goto x86_l_4e1;
	case 1253ULL: goto x86_l_4e5;
	case 1256ULL: goto x86_l_4e8;
	case 1260ULL: goto x86_l_4ec;
	case 1266ULL: goto x86_l_4f2;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1282ULL: goto x86_l_502;
	case 1285ULL: goto x86_l_505;
	case 1289ULL: goto x86_l_509;
	case 1295ULL: goto x86_l_50f;
	case 1302ULL: goto x86_l_516;
	case 1307ULL: goto x86_l_51b;
	case 1311ULL: goto x86_l_51f;
	case 1314ULL: goto x86_l_522;
	case 1318ULL: goto x86_l_526;
	case 1324ULL: goto x86_l_52c;
	case 1331ULL: goto x86_l_533;
	case 1336ULL: goto x86_l_538;
	case 1340ULL: goto x86_l_53c;
	case 1343ULL: goto x86_l_53f;
	case 1347ULL: goto x86_l_543;
	case 1353ULL: goto x86_l_549;
	case 1360ULL: goto x86_l_550;
	case 1365ULL: goto x86_l_555;
	case 1369ULL: goto x86_l_559;
	case 1372ULL: goto x86_l_55c;
	case 1376ULL: goto x86_l_560;
	case 1382ULL: goto x86_l_566;
	case 1389ULL: goto x86_l_56d;
	case 1394ULL: goto x86_l_572;
	case 1398ULL: goto x86_l_576;
	case 1401ULL: goto x86_l_579;
	case 1405ULL: goto x86_l_57d;
	case 1411ULL: goto x86_l_583;
	case 1418ULL: goto x86_l_58a;
	case 1423ULL: goto x86_l_58f;
	case 1427ULL: goto x86_l_593;
	case 1430ULL: goto x86_l_596;
	case 1434ULL: goto x86_l_59a;
	case 1440ULL: goto x86_l_5a0;
	case 1447ULL: goto x86_l_5a7;
	case 1452ULL: goto x86_l_5ac;
	case 1456ULL: goto x86_l_5b0;
	case 1459ULL: goto x86_l_5b3;
	case 1463ULL: goto x86_l_5b7;
	case 1469ULL: goto x86_l_5bd;
	case 1476ULL: goto x86_l_5c4;
	case 1481ULL: goto x86_l_5c9;
	case 1485ULL: goto x86_l_5cd;
	case 1488ULL: goto x86_l_5d0;
	case 1492ULL: goto x86_l_5d4;
	case 1498ULL: goto x86_l_5da;
	case 1505ULL: goto x86_l_5e1;
	case 1510ULL: goto x86_l_5e6;
	case 1514ULL: goto x86_l_5ea;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1527ULL: goto x86_l_5f7;
	case 1534ULL: goto x86_l_5fe;
	case 1539ULL: goto x86_l_603;
	case 1543ULL: goto x86_l_607;
	case 1546ULL: goto x86_l_60a;
	case 1550ULL: goto x86_l_60e;
	case 1556ULL: goto x86_l_614;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1572ULL: goto x86_l_624;
	case 1575ULL: goto x86_l_627;
	case 1579ULL: goto x86_l_62b;
	case 1585ULL: goto x86_l_631;
	case 1592ULL: goto x86_l_638;
	case 1597ULL: goto x86_l_63d;
	case 1601ULL: goto x86_l_641;
	case 1604ULL: goto x86_l_644;
	case 1608ULL: goto x86_l_648;
	case 1614ULL: goto x86_l_64e;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1630ULL: goto x86_l_65e;
	case 1633ULL: goto x86_l_661;
	case 1637ULL: goto x86_l_665;
	case 1643ULL: goto x86_l_66b;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1659ULL: goto x86_l_67b;
	case 1662ULL: goto x86_l_67e;
	case 1666ULL: goto x86_l_682;
	case 1672ULL: goto x86_l_688;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1688ULL: goto x86_l_698;
	case 1691ULL: goto x86_l_69b;
	case 1695ULL: goto x86_l_69f;
	case 1701ULL: goto x86_l_6a5;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1717ULL: goto x86_l_6b5;
	case 1720ULL: goto x86_l_6b8;
	case 1724ULL: goto x86_l_6bc;
	case 1730ULL: goto x86_l_6c2;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1746ULL: goto x86_l_6d2;
	case 1749ULL: goto x86_l_6d5;
	case 1753ULL: goto x86_l_6d9;
	case 1759ULL: goto x86_l_6df;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1775ULL: goto x86_l_6ef;
	case 1778ULL: goto x86_l_6f2;
	case 1782ULL: goto x86_l_6f6;
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
	/* 0x15: mov    rdi,QWORD PTR [rip+0xbe77] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1c:
	/* 0x1c: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_21:
	/* 0x21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     32bc <generic_usdt_filter_arg_2+0x32bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12988ULL;
	}
x86_l_31:
	/* 0x31: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    r15d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_3b:
	/* 0x3b: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_42:
	/* 0x42: mov    rdi,QWORD PTR [rip+0xbe77] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_49:
	/* 0x49: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     32a1 <generic_usdt_filter_arg_2+0x32a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12961ULL;
	}
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     32a1 <generic_usdt_filter_arg_2+0x32a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12961ULL;
	}
x86_l_67:
	/* 0x67: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_6a:
	/* 0x6a: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6d:
	/* 0x6d: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_76:
	/* 0x76: je     322a <generic_usdt_filter_arg_2+0x322a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12842ULL;
	}
x86_l_7c:
	/* 0x7c: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7e:
	/* 0x7e: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_82:
	/* 0x82: lea    rsi,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_86:
	/* 0x86: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8a:
	/* 0x8a: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8e:
	/* 0x8e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_92:
	/* 0x92: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_98:
	/* 0x98: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9b:
	/* 0x9b: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9e:
	/* 0x9e: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a2:
	/* 0xa2: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_a4:
	/* 0xa4: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_aa:
	/* 0xaa: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ad:
	/* 0xad: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b0:
	/* 0xb0: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_b2:
	/* 0xb2: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b8:
	/* 0xb8: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_bb:
	/* 0xbb: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_be:
	/* 0xbe: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_c0:
	/* 0xc0: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c6:
	/* 0xc6: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c9:
	/* 0xc9: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cc:
	/* 0xcc: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_ce:
	/* 0xce: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_d4:
	/* 0xd4: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d7:
	/* 0xd7: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_da:
	/* 0xda: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_dc:
	/* 0xdc: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_e2:
	/* 0xe2: cmp    DWORD PTR [rax+rbp*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 25ULL);
x86_l_e6:
	/* 0xe6: jb     3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12832ULL;
	}
x86_l_ec:
	/* 0xec: mov    edx,DWORD PTR [rax+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_f0:
	/* 0xf0: test   edx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1023ULL);
x86_l_f6:
	/* 0xf6: je     3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12832ULL;
	}
x86_l_fc:
	/* 0xfc: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fe:
	/* 0xfe: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_104:
	/* 0x104: mov    edx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_107:
	/* 0x107: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_10b:
	/* 0x10b: ja     322a <generic_usdt_filter_arg_2+0x322a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12842ULL;
	}
x86_l_111:
	/* 0x111: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_11a:
	/* 0x11a: jne    322a <generic_usdt_filter_arg_2+0x322a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12842ULL;
	}
x86_l_120:
	/* 0x120: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_123:
	/* 0x123: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_126:
	/* 0x126: mov    ecx,DWORD PTR [rax+rcx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 12ULL);
x86_l_12a:
	/* 0x12a: mov    rax,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_132:
	/* 0x132: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_137:
	/* 0x137: lea    r8,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_13b:
	/* 0x13b: add    r8,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_142:
	/* 0x142: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_145:
	/* 0x145: jg     16c <generic_usdt_filter_arg_2+0x16c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16c;
	}
x86_l_147:
	/* 0x147: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_14a:
	/* 0x14a: jg     cd2 <generic_usdt_filter_arg_2+0xcd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3282ULL;
	}
x86_l_150:
	/* 0x150: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_153:
	/* 0x153: je     e91 <generic_usdt_filter_arg_2+0xe91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3729ULL;
	}
x86_l_159:
	/* 0x159: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_15c:
	/* 0x15c: je     cf0 <generic_usdt_filter_arg_2+0xcf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3312ULL;
	}
x86_l_162:
	/* 0x162: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_165:
	/* 0x165: je     181 <generic_usdt_filter_arg_2+0x181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_181;
	}
x86_l_167:
	/* 0x167: jmp    3220 <generic_usdt_filter_arg_2+0x3220> */
	return 12832ULL;
x86_l_16c:
	/* 0x16c: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_16f:
	/* 0x16f: jg     ce8 <generic_usdt_filter_arg_2+0xce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3304ULL;
	}
x86_l_175:
	/* 0x175: lea    eax,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_178:
	/* 0x178: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17b:
	/* 0x17b: jae    d59 <generic_usdt_filter_arg_2+0xd59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3417ULL;
	}
x86_l_181:
	/* 0x181: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_184:
	/* 0x184: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_187:
	/* 0x187: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_18a:
	/* 0x18a: ja     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12800ULL;
	}
x86_l_190:
	/* 0x190: mov    r13d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_193:
	/* 0x193: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_197:
	/* 0x197: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_19c:
	/* 0x19c: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_19f:
	/* 0x19f: jb     1aed <generic_usdt_filter_arg_2+0x1aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6893ULL;
	}
x86_l_1a5:
	/* 0x1a5: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_1aa:
	/* 0x1aa: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1ad:
	/* 0x1ad: jb     1a48 <generic_usdt_filter_arg_2+0x1a48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6728ULL;
	}
x86_l_1b3:
	/* 0x1b3: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_1b8:
	/* 0x1b8: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1bb:
	/* 0x1bb: jae    3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12800ULL;
	}
x86_l_1c1:
	/* 0x1c1: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca:
	/* 0x1ca: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd:
	/* 0x1cd: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d1:
	/* 0x1d1: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1d9:
	/* 0x1d9: mov    rdi,QWORD PTR [rip+0xbe77] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1e0:
	/* 0x1e0: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e5:
	/* 0x1e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ea:
	/* 0x1ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec:
	/* 0x1ec: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1ef:
	/* 0x1ef: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f2:
	/* 0x1f2: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1f5:
	/* 0x1f5: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_1fb:
	/* 0x1fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fe:
	/* 0x1fe: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_204:
	/* 0x204: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_207:
	/* 0x207: mov    rdi,QWORD PTR [rip+0xbe77] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_20e:
	/* 0x20e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_213:
	/* 0x213: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_218:
	/* 0x218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a:
	/* 0x21a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21d:
	/* 0x21d: je     31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12790ULL;
	}
x86_l_223:
	/* 0x223: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_226:
	/* 0x226: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_22a:
	/* 0x22a: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_22f:
	/* 0x22f: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_233:
	/* 0x233: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_236:
	/* 0x236: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_238:
	/* 0x238: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_23c:
	/* 0x23c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_241:
	/* 0x241: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_246:
	/* 0x246: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24a:
	/* 0x24a: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24d:
	/* 0x24d: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_251:
	/* 0x251: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_257:
	/* 0x257: lea    eax,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_25e:
	/* 0x25e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_263:
	/* 0x263: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_267:
	/* 0x267: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_26a:
	/* 0x26a: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_26e:
	/* 0x26e: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_274:
	/* 0x274: lea    eax,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_27b:
	/* 0x27b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_280:
	/* 0x280: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_284:
	/* 0x284: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_287:
	/* 0x287: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_28b:
	/* 0x28b: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_291:
	/* 0x291: lea    eax,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_298:
	/* 0x298: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29d:
	/* 0x29d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a1:
	/* 0x2a1: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_2a4:
	/* 0x2a4: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_2a8:
	/* 0x2a8: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_2ae:
	/* 0x2ae: lea    eax,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_2b5:
	/* 0x2b5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ba:
	/* 0x2ba: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2be:
	/* 0x2be: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1:
	/* 0x2c1: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2c5:
	/* 0x2c5: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_2cb:
	/* 0x2cb: lea    eax,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_2d2:
	/* 0x2d2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d7:
	/* 0x2d7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2db:
	/* 0x2db: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_2de:
	/* 0x2de: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_2e2:
	/* 0x2e2: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_2e8:
	/* 0x2e8: lea    eax,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_2ef:
	/* 0x2ef: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f4:
	/* 0x2f4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2f8:
	/* 0x2f8: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2fb:
	/* 0x2fb: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2ff:
	/* 0x2ff: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_305:
	/* 0x305: lea    eax,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_30c:
	/* 0x30c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_311:
	/* 0x311: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_315:
	/* 0x315: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_318:
	/* 0x318: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_31c:
	/* 0x31c: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_322:
	/* 0x322: lea    eax,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_329:
	/* 0x329: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_32e:
	/* 0x32e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_332:
	/* 0x332: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_335:
	/* 0x335: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_339:
	/* 0x339: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_33f:
	/* 0x33f: lea    eax,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_346:
	/* 0x346: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_34b:
	/* 0x34b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_34f:
	/* 0x34f: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_352:
	/* 0x352: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_356:
	/* 0x356: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_35c:
	/* 0x35c: lea    eax,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_363:
	/* 0x363: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_368:
	/* 0x368: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_36c:
	/* 0x36c: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_36f:
	/* 0x36f: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_373:
	/* 0x373: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_379:
	/* 0x379: lea    eax,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_380:
	/* 0x380: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_385:
	/* 0x385: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_389:
	/* 0x389: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_38c:
	/* 0x38c: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_390:
	/* 0x390: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_396:
	/* 0x396: lea    eax,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_39d:
	/* 0x39d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3a2:
	/* 0x3a2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3a6:
	/* 0x3a6: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a9:
	/* 0x3a9: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_3ad:
	/* 0x3ad: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_3b3:
	/* 0x3b3: lea    eax,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_3ba:
	/* 0x3ba: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3bf:
	/* 0x3bf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3c3:
	/* 0x3c3: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_3c6:
	/* 0x3c6: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_3ca:
	/* 0x3ca: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_3d0:
	/* 0x3d0: lea    eax,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_3d7:
	/* 0x3d7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3dc:
	/* 0x3dc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3e0:
	/* 0x3e0: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_3e3:
	/* 0x3e3: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_3e7:
	/* 0x3e7: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_3ed:
	/* 0x3ed: lea    eax,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_3f4:
	/* 0x3f4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f9:
	/* 0x3f9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3fd:
	/* 0x3fd: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_400:
	/* 0x400: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_404:
	/* 0x404: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_40a:
	/* 0x40a: lea    eax,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_411:
	/* 0x411: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_416:
	/* 0x416: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_41a:
	/* 0x41a: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_41d:
	/* 0x41d: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_421:
	/* 0x421: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_427:
	/* 0x427: lea    eax,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_42e:
	/* 0x42e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_433:
	/* 0x433: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_437:
	/* 0x437: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_43a:
	/* 0x43a: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_43e:
	/* 0x43e: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_444:
	/* 0x444: lea    eax,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_44b:
	/* 0x44b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_450:
	/* 0x450: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_454:
	/* 0x454: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_457:
	/* 0x457: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_45b:
	/* 0x45b: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_461:
	/* 0x461: lea    eax,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_468:
	/* 0x468: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_46d:
	/* 0x46d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_471:
	/* 0x471: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_474:
	/* 0x474: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_478:
	/* 0x478: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_47e:
	/* 0x47e: lea    eax,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_485:
	/* 0x485: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_48a:
	/* 0x48a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_48e:
	/* 0x48e: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_491:
	/* 0x491: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_495:
	/* 0x495: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_49b:
	/* 0x49b: lea    eax,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_4a2:
	/* 0x4a2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4a7:
	/* 0x4a7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4ab:
	/* 0x4ab: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_4ae:
	/* 0x4ae: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_4b2:
	/* 0x4b2: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_4b8:
	/* 0x4b8: lea    eax,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_4bf:
	/* 0x4bf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4c4:
	/* 0x4c4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4c8:
	/* 0x4c8: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_4cb:
	/* 0x4cb: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_4cf:
	/* 0x4cf: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_4d5:
	/* 0x4d5: lea    eax,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_4dc:
	/* 0x4dc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4e1:
	/* 0x4e1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4e5:
	/* 0x4e5: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_4e8:
	/* 0x4e8: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_4ec:
	/* 0x4ec: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_4f2:
	/* 0x4f2: lea    eax,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_4f9:
	/* 0x4f9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4fe:
	/* 0x4fe: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_502:
	/* 0x502: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_505:
	/* 0x505: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_509:
	/* 0x509: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_50f:
	/* 0x50f: lea    eax,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_516:
	/* 0x516: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_51b:
	/* 0x51b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_51f:
	/* 0x51f: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_522:
	/* 0x522: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_526:
	/* 0x526: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_52c:
	/* 0x52c: lea    eax,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_533:
	/* 0x533: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_538:
	/* 0x538: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_53c:
	/* 0x53c: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_53f:
	/* 0x53f: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_543:
	/* 0x543: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_549:
	/* 0x549: lea    eax,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_550:
	/* 0x550: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_555:
	/* 0x555: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_559:
	/* 0x559: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_55c:
	/* 0x55c: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_560:
	/* 0x560: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_566:
	/* 0x566: lea    eax,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_56d:
	/* 0x56d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_572:
	/* 0x572: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_576:
	/* 0x576: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_579:
	/* 0x579: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_57d:
	/* 0x57d: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_583:
	/* 0x583: lea    eax,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_58a:
	/* 0x58a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_58f:
	/* 0x58f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_593:
	/* 0x593: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_596:
	/* 0x596: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_59a:
	/* 0x59a: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_5a0:
	/* 0x5a0: lea    eax,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_5a7:
	/* 0x5a7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ac:
	/* 0x5ac: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5b0:
	/* 0x5b0: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_5b3:
	/* 0x5b3: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_5b7:
	/* 0x5b7: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_5bd:
	/* 0x5bd: lea    eax,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_5c4:
	/* 0x5c4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5c9:
	/* 0x5c9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5cd:
	/* 0x5cd: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_5d0:
	/* 0x5d0: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_5d4:
	/* 0x5d4: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_5da:
	/* 0x5da: lea    eax,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_5e1:
	/* 0x5e1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5e6:
	/* 0x5e6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5ea:
	/* 0x5ea: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5ed:
	/* 0x5ed: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_5f1:
	/* 0x5f1: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_5f7:
	/* 0x5f7: lea    eax,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_5fe:
	/* 0x5fe: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_603:
	/* 0x603: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_607:
	/* 0x607: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_60a:
	/* 0x60a: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_60e:
	/* 0x60e: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_614:
	/* 0x614: lea    eax,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_61b:
	/* 0x61b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_620:
	/* 0x620: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_624:
	/* 0x624: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_627:
	/* 0x627: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_62b:
	/* 0x62b: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_631:
	/* 0x631: lea    eax,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_638:
	/* 0x638: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_63d:
	/* 0x63d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_641:
	/* 0x641: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_644:
	/* 0x644: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_648:
	/* 0x648: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_64e:
	/* 0x64e: lea    eax,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_655:
	/* 0x655: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_65a:
	/* 0x65a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_65e:
	/* 0x65e: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_661:
	/* 0x661: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_665:
	/* 0x665: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_66b:
	/* 0x66b: lea    eax,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_672:
	/* 0x672: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_677:
	/* 0x677: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_67b:
	/* 0x67b: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_67e:
	/* 0x67e: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_682:
	/* 0x682: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_688:
	/* 0x688: lea    eax,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_68f:
	/* 0x68f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_694:
	/* 0x694: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_698:
	/* 0x698: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_69b:
	/* 0x69b: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_69f:
	/* 0x69f: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_6a5:
	/* 0x6a5: lea    eax,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_6ac:
	/* 0x6ac: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6b1:
	/* 0x6b1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6b5:
	/* 0x6b5: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_6b8:
	/* 0x6b8: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_6bc:
	/* 0x6bc: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_6c2:
	/* 0x6c2: lea    eax,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_6c9:
	/* 0x6c9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6ce:
	/* 0x6ce: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6d2:
	/* 0x6d2: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6d5:
	/* 0x6d5: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_6d9:
	/* 0x6d9: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
x86_l_6df:
	/* 0x6df: lea    eax,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_6e6:
	/* 0x6e6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6eb:
	/* 0x6eb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6ef:
	/* 0x6ef: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_6f2:
	/* 0x6f2: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_6f6:
	/* 0x6f6: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3269ULL;
	}
	return 1788ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1788ULL: goto x86_l_6fc;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1804ULL: goto x86_l_70c;
	case 1807ULL: goto x86_l_70f;
	case 1811ULL: goto x86_l_713;
	case 1817ULL: goto x86_l_719;
	case 1824ULL: goto x86_l_720;
	case 1829ULL: goto x86_l_725;
	case 1833ULL: goto x86_l_729;
	case 1836ULL: goto x86_l_72c;
	case 1840ULL: goto x86_l_730;
	case 1846ULL: goto x86_l_736;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1862ULL: goto x86_l_746;
	case 1865ULL: goto x86_l_749;
	case 1869ULL: goto x86_l_74d;
	case 1875ULL: goto x86_l_753;
	case 1882ULL: goto x86_l_75a;
	case 1887ULL: goto x86_l_75f;
	case 1891ULL: goto x86_l_763;
	case 1894ULL: goto x86_l_766;
	case 1898ULL: goto x86_l_76a;
	case 1904ULL: goto x86_l_770;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1920ULL: goto x86_l_780;
	case 1923ULL: goto x86_l_783;
	case 1927ULL: goto x86_l_787;
	case 1933ULL: goto x86_l_78d;
	case 1940ULL: goto x86_l_794;
	case 1945ULL: goto x86_l_799;
	case 1949ULL: goto x86_l_79d;
	case 1952ULL: goto x86_l_7a0;
	case 1956ULL: goto x86_l_7a4;
	case 1962ULL: goto x86_l_7aa;
	case 1969ULL: goto x86_l_7b1;
	case 1974ULL: goto x86_l_7b6;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1985ULL: goto x86_l_7c1;
	case 1991ULL: goto x86_l_7c7;
	case 1998ULL: goto x86_l_7ce;
	case 2003ULL: goto x86_l_7d3;
	case 2007ULL: goto x86_l_7d7;
	case 2010ULL: goto x86_l_7da;
	case 2014ULL: goto x86_l_7de;
	case 2020ULL: goto x86_l_7e4;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2036ULL: goto x86_l_7f4;
	case 2039ULL: goto x86_l_7f7;
	case 2043ULL: goto x86_l_7fb;
	case 2049ULL: goto x86_l_801;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2065ULL: goto x86_l_811;
	case 2068ULL: goto x86_l_814;
	case 2072ULL: goto x86_l_818;
	case 2078ULL: goto x86_l_81e;
	case 2085ULL: goto x86_l_825;
	case 2090ULL: goto x86_l_82a;
	case 2094ULL: goto x86_l_82e;
	case 2097ULL: goto x86_l_831;
	case 2101ULL: goto x86_l_835;
	case 2107ULL: goto x86_l_83b;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2123ULL: goto x86_l_84b;
	case 2126ULL: goto x86_l_84e;
	case 2130ULL: goto x86_l_852;
	case 2136ULL: goto x86_l_858;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2152ULL: goto x86_l_868;
	case 2155ULL: goto x86_l_86b;
	case 2159ULL: goto x86_l_86f;
	case 2165ULL: goto x86_l_875;
	case 2172ULL: goto x86_l_87c;
	case 2177ULL: goto x86_l_881;
	case 2181ULL: goto x86_l_885;
	case 2184ULL: goto x86_l_888;
	case 2188ULL: goto x86_l_88c;
	case 2194ULL: goto x86_l_892;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2210ULL: goto x86_l_8a2;
	case 2213ULL: goto x86_l_8a5;
	case 2217ULL: goto x86_l_8a9;
	case 2223ULL: goto x86_l_8af;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2239ULL: goto x86_l_8bf;
	case 2242ULL: goto x86_l_8c2;
	case 2246ULL: goto x86_l_8c6;
	case 2252ULL: goto x86_l_8cc;
	case 2259ULL: goto x86_l_8d3;
	case 2264ULL: goto x86_l_8d8;
	case 2268ULL: goto x86_l_8dc;
	case 2271ULL: goto x86_l_8df;
	case 2275ULL: goto x86_l_8e3;
	case 2281ULL: goto x86_l_8e9;
	case 2288ULL: goto x86_l_8f0;
	case 2293ULL: goto x86_l_8f5;
	case 2297ULL: goto x86_l_8f9;
	case 2300ULL: goto x86_l_8fc;
	case 2304ULL: goto x86_l_900;
	case 2310ULL: goto x86_l_906;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2326ULL: goto x86_l_916;
	case 2329ULL: goto x86_l_919;
	case 2333ULL: goto x86_l_91d;
	case 2339ULL: goto x86_l_923;
	case 2346ULL: goto x86_l_92a;
	case 2351ULL: goto x86_l_92f;
	case 2355ULL: goto x86_l_933;
	case 2358ULL: goto x86_l_936;
	case 2362ULL: goto x86_l_93a;
	case 2368ULL: goto x86_l_940;
	case 2375ULL: goto x86_l_947;
	case 2380ULL: goto x86_l_94c;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2391ULL: goto x86_l_957;
	case 2397ULL: goto x86_l_95d;
	case 2404ULL: goto x86_l_964;
	case 2409ULL: goto x86_l_969;
	case 2413ULL: goto x86_l_96d;
	case 2416ULL: goto x86_l_970;
	case 2420ULL: goto x86_l_974;
	case 2426ULL: goto x86_l_97a;
	case 2433ULL: goto x86_l_981;
	case 2438ULL: goto x86_l_986;
	case 2442ULL: goto x86_l_98a;
	case 2445ULL: goto x86_l_98d;
	case 2449ULL: goto x86_l_991;
	case 2455ULL: goto x86_l_997;
	case 2462ULL: goto x86_l_99e;
	case 2467ULL: goto x86_l_9a3;
	case 2471ULL: goto x86_l_9a7;
	case 2474ULL: goto x86_l_9aa;
	case 2478ULL: goto x86_l_9ae;
	case 2484ULL: goto x86_l_9b4;
	case 2491ULL: goto x86_l_9bb;
	case 2496ULL: goto x86_l_9c0;
	case 2500ULL: goto x86_l_9c4;
	case 2503ULL: goto x86_l_9c7;
	case 2507ULL: goto x86_l_9cb;
	case 2513ULL: goto x86_l_9d1;
	case 2520ULL: goto x86_l_9d8;
	case 2525ULL: goto x86_l_9dd;
	case 2529ULL: goto x86_l_9e1;
	case 2532ULL: goto x86_l_9e4;
	case 2536ULL: goto x86_l_9e8;
	case 2542ULL: goto x86_l_9ee;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2558ULL: goto x86_l_9fe;
	case 2561ULL: goto x86_l_a01;
	case 2565ULL: goto x86_l_a05;
	case 2571ULL: goto x86_l_a0b;
	case 2578ULL: goto x86_l_a12;
	case 2583ULL: goto x86_l_a17;
	case 2587ULL: goto x86_l_a1b;
	case 2590ULL: goto x86_l_a1e;
	case 2594ULL: goto x86_l_a22;
	case 2600ULL: goto x86_l_a28;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2616ULL: goto x86_l_a38;
	case 2619ULL: goto x86_l_a3b;
	case 2623ULL: goto x86_l_a3f;
	case 2629ULL: goto x86_l_a45;
	case 2636ULL: goto x86_l_a4c;
	case 2641ULL: goto x86_l_a51;
	case 2645ULL: goto x86_l_a55;
	case 2648ULL: goto x86_l_a58;
	case 2652ULL: goto x86_l_a5c;
	case 2658ULL: goto x86_l_a62;
	case 2665ULL: goto x86_l_a69;
	case 2670ULL: goto x86_l_a6e;
	case 2674ULL: goto x86_l_a72;
	case 2677ULL: goto x86_l_a75;
	case 2681ULL: goto x86_l_a79;
	case 2687ULL: goto x86_l_a7f;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2703ULL: goto x86_l_a8f;
	case 2706ULL: goto x86_l_a92;
	case 2710ULL: goto x86_l_a96;
	case 2716ULL: goto x86_l_a9c;
	case 2723ULL: goto x86_l_aa3;
	case 2728ULL: goto x86_l_aa8;
	case 2732ULL: goto x86_l_aac;
	case 2735ULL: goto x86_l_aaf;
	case 2739ULL: goto x86_l_ab3;
	case 2745ULL: goto x86_l_ab9;
	case 2752ULL: goto x86_l_ac0;
	case 2757ULL: goto x86_l_ac5;
	case 2761ULL: goto x86_l_ac9;
	case 2764ULL: goto x86_l_acc;
	case 2768ULL: goto x86_l_ad0;
	case 2774ULL: goto x86_l_ad6;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2790ULL: goto x86_l_ae6;
	case 2793ULL: goto x86_l_ae9;
	case 2797ULL: goto x86_l_aed;
	case 2803ULL: goto x86_l_af3;
	case 2810ULL: goto x86_l_afa;
	case 2815ULL: goto x86_l_aff;
	case 2819ULL: goto x86_l_b03;
	case 2822ULL: goto x86_l_b06;
	case 2826ULL: goto x86_l_b0a;
	case 2832ULL: goto x86_l_b10;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2848ULL: goto x86_l_b20;
	case 2851ULL: goto x86_l_b23;
	case 2855ULL: goto x86_l_b27;
	case 2861ULL: goto x86_l_b2d;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2877ULL: goto x86_l_b3d;
	case 2880ULL: goto x86_l_b40;
	case 2884ULL: goto x86_l_b44;
	case 2890ULL: goto x86_l_b4a;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2906ULL: goto x86_l_b5a;
	case 2909ULL: goto x86_l_b5d;
	case 2913ULL: goto x86_l_b61;
	case 2919ULL: goto x86_l_b67;
	case 2926ULL: goto x86_l_b6e;
	case 2931ULL: goto x86_l_b73;
	case 2935ULL: goto x86_l_b77;
	case 2938ULL: goto x86_l_b7a;
	case 2942ULL: goto x86_l_b7e;
	case 2948ULL: goto x86_l_b84;
	case 2955ULL: goto x86_l_b8b;
	case 2960ULL: goto x86_l_b90;
	case 2964ULL: goto x86_l_b94;
	case 2967ULL: goto x86_l_b97;
	case 2971ULL: goto x86_l_b9b;
	case 2977ULL: goto x86_l_ba1;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2993ULL: goto x86_l_bb1;
	case 2996ULL: goto x86_l_bb4;
	case 3000ULL: goto x86_l_bb8;
	case 3006ULL: goto x86_l_bbe;
	case 3013ULL: goto x86_l_bc5;
	case 3018ULL: goto x86_l_bca;
	case 3022ULL: goto x86_l_bce;
	case 3025ULL: goto x86_l_bd1;
	case 3029ULL: goto x86_l_bd5;
	case 3035ULL: goto x86_l_bdb;
	case 3042ULL: goto x86_l_be2;
	case 3047ULL: goto x86_l_be7;
	case 3051ULL: goto x86_l_beb;
	case 3054ULL: goto x86_l_bee;
	case 3058ULL: goto x86_l_bf2;
	case 3064ULL: goto x86_l_bf8;
	case 3071ULL: goto x86_l_bff;
	case 3076ULL: goto x86_l_c04;
	case 3080ULL: goto x86_l_c08;
	case 3083ULL: goto x86_l_c0b;
	case 3087ULL: goto x86_l_c0f;
	case 3093ULL: goto x86_l_c15;
	case 3100ULL: goto x86_l_c1c;
	case 3105ULL: goto x86_l_c21;
	case 3109ULL: goto x86_l_c25;
	case 3112ULL: goto x86_l_c28;
	case 3116ULL: goto x86_l_c2c;
	case 3122ULL: goto x86_l_c32;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3138ULL: goto x86_l_c42;
	case 3141ULL: goto x86_l_c45;
	case 3145ULL: goto x86_l_c49;
	case 3147ULL: goto x86_l_c4b;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3163ULL: goto x86_l_c5b;
	case 3166ULL: goto x86_l_c5e;
	case 3170ULL: goto x86_l_c62;
	case 3172ULL: goto x86_l_c64;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3188ULL: goto x86_l_c74;
	case 3191ULL: goto x86_l_c77;
	case 3195ULL: goto x86_l_c7b;
	case 3197ULL: goto x86_l_c7d;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3213ULL: goto x86_l_c8d;
	case 3216ULL: goto x86_l_c90;
	case 3220ULL: goto x86_l_c94;
	case 3222ULL: goto x86_l_c96;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3238ULL: goto x86_l_ca6;
	case 3241ULL: goto x86_l_ca9;
	case 3245ULL: goto x86_l_cad;
	case 3247ULL: goto x86_l_caf;
	case 3254ULL: goto x86_l_cb6;
	case 3261ULL: goto x86_l_cbd;
	case 3266ULL: goto x86_l_cc2;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3285ULL: goto x86_l_cd5;
	case 3288ULL: goto x86_l_cd8;
	case 3294ULL: goto x86_l_cde;
	case 3297ULL: goto x86_l_ce1;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3307ULL: goto x86_l_ceb;
	case 3310ULL: goto x86_l_cee;
	case 3312ULL: goto x86_l_cf0;
	case 3321ULL: goto x86_l_cf9;
	case 3330ULL: goto x86_l_d02;
	case 3339ULL: goto x86_l_d0b;
	case 3348ULL: goto x86_l_d14;
	case 3357ULL: goto x86_l_d1d;
	case 3360ULL: goto x86_l_d20;
	case 3363ULL: goto x86_l_d23;
	case 3365ULL: goto x86_l_d25;
	case 3368ULL: goto x86_l_d28;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3380ULL: goto x86_l_d34;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3394ULL: goto x86_l_d42;
	case 3400ULL: goto x86_l_d48;
	case 3403ULL: goto x86_l_d4b;
	case 3406ULL: goto x86_l_d4e;
	case 3412ULL: goto x86_l_d54;
	case 3417ULL: goto x86_l_d59;
	case 3420ULL: goto x86_l_d5c;
	case 3426ULL: goto x86_l_d62;
	case 3430ULL: goto x86_l_d66;
	case 3432ULL: goto x86_l_d68;
	case 3435ULL: goto x86_l_d6b;
	case 3441ULL: goto x86_l_d71;
	case 3444ULL: goto x86_l_d74;
	case 3447ULL: goto x86_l_d77;
	case 3450ULL: goto x86_l_d7a;
	case 3452ULL: goto x86_l_d7c;
	case 3454ULL: goto x86_l_d7e;
	case 3457ULL: goto x86_l_d81;
	case 3460ULL: goto x86_l_d84;
	case 3466ULL: goto x86_l_d8a;
	case 3469ULL: goto x86_l_d8d;
	case 3475ULL: goto x86_l_d93;
	case 3477ULL: goto x86_l_d95;
	case 3482ULL: goto x86_l_d9a;
	case 3486ULL: goto x86_l_d9e;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3501ULL: goto x86_l_dad;
	case 3507ULL: goto x86_l_db3;
	case 3517ULL: goto x86_l_dbd;
	case 3521ULL: goto x86_l_dc1;
	case 3527ULL: goto x86_l_dc7;
	case 3534ULL: goto x86_l_dce;
	case 3541ULL: goto x86_l_dd5;
	case 3547ULL: goto x86_l_ddb;
	case 3551ULL: goto x86_l_ddf;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3565ULL: goto x86_l_ded;
	case 3570ULL: goto x86_l_df2;
	case 3573ULL: goto x86_l_df5;
	case 3577ULL: goto x86_l_df9;
	case 3581ULL: goto x86_l_dfd;
	case 3584ULL: goto x86_l_e00;
	case 3589ULL: goto x86_l_e05;
	case 3591ULL: goto x86_l_e07;
	case 3594ULL: goto x86_l_e0a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6fc:
	/* 0x6fc: lea    eax,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_703:
	/* 0x703: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_708:
	/* 0x708: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_70c:
	/* 0x70c: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_70f:
	/* 0x70f: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_713:
	/* 0x713: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_719:
	/* 0x719: lea    eax,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_720:
	/* 0x720: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_725:
	/* 0x725: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_729:
	/* 0x729: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_72c:
	/* 0x72c: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_730:
	/* 0x730: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_736:
	/* 0x736: lea    eax,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_73d:
	/* 0x73d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_742:
	/* 0x742: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_746:
	/* 0x746: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_749:
	/* 0x749: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_74d:
	/* 0x74d: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_753:
	/* 0x753: lea    eax,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_75a:
	/* 0x75a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_75f:
	/* 0x75f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_763:
	/* 0x763: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_766:
	/* 0x766: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_76a:
	/* 0x76a: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_770:
	/* 0x770: lea    eax,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_777:
	/* 0x777: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_77c:
	/* 0x77c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_780:
	/* 0x780: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_783:
	/* 0x783: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_787:
	/* 0x787: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_78d:
	/* 0x78d: lea    eax,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_794:
	/* 0x794: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_799:
	/* 0x799: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_79d:
	/* 0x79d: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_7a0:
	/* 0x7a0: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_7a4:
	/* 0x7a4: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_7aa:
	/* 0x7aa: lea    eax,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_7b1:
	/* 0x7b1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7b6:
	/* 0x7b6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7ba:
	/* 0x7ba: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_7bd:
	/* 0x7bd: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_7c1:
	/* 0x7c1: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_7c7:
	/* 0x7c7: lea    eax,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_7ce:
	/* 0x7ce: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7d3:
	/* 0x7d3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7d7:
	/* 0x7d7: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_7da:
	/* 0x7da: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_7de:
	/* 0x7de: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_7e4:
	/* 0x7e4: lea    eax,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_7eb:
	/* 0x7eb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7f0:
	/* 0x7f0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7f4:
	/* 0x7f4: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_7f7:
	/* 0x7f7: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_7fb:
	/* 0x7fb: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_801:
	/* 0x801: lea    eax,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_808:
	/* 0x808: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_80d:
	/* 0x80d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_811:
	/* 0x811: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_814:
	/* 0x814: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_818:
	/* 0x818: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_81e:
	/* 0x81e: lea    eax,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_825:
	/* 0x825: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_82a:
	/* 0x82a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_82e:
	/* 0x82e: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_831:
	/* 0x831: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_835:
	/* 0x835: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_83b:
	/* 0x83b: lea    eax,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_842:
	/* 0x842: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_847:
	/* 0x847: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_84b:
	/* 0x84b: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_84e:
	/* 0x84e: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_852:
	/* 0x852: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_858:
	/* 0x858: lea    eax,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_85f:
	/* 0x85f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_864:
	/* 0x864: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_868:
	/* 0x868: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_86b:
	/* 0x86b: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_86f:
	/* 0x86f: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_875:
	/* 0x875: lea    eax,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_87c:
	/* 0x87c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_881:
	/* 0x881: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_885:
	/* 0x885: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_888:
	/* 0x888: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_88c:
	/* 0x88c: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_892:
	/* 0x892: lea    eax,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_899:
	/* 0x899: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_89e:
	/* 0x89e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8a2:
	/* 0x8a2: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_8a5:
	/* 0x8a5: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_8a9:
	/* 0x8a9: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_8af:
	/* 0x8af: lea    eax,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_8b6:
	/* 0x8b6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8bb:
	/* 0x8bb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8bf:
	/* 0x8bf: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_8c2:
	/* 0x8c2: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_8c6:
	/* 0x8c6: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_8cc:
	/* 0x8cc: lea    eax,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_8d3:
	/* 0x8d3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8d8:
	/* 0x8d8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8dc:
	/* 0x8dc: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_8df:
	/* 0x8df: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_8e3:
	/* 0x8e3: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_8e9:
	/* 0x8e9: lea    eax,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_8f0:
	/* 0x8f0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8f5:
	/* 0x8f5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8f9:
	/* 0x8f9: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_8fc:
	/* 0x8fc: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_900:
	/* 0x900: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_906:
	/* 0x906: lea    eax,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_90d:
	/* 0x90d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_912:
	/* 0x912: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_916:
	/* 0x916: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_919:
	/* 0x919: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_91d:
	/* 0x91d: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_923:
	/* 0x923: lea    eax,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_92a:
	/* 0x92a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_92f:
	/* 0x92f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_933:
	/* 0x933: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_936:
	/* 0x936: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_93a:
	/* 0x93a: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_940:
	/* 0x940: lea    eax,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_947:
	/* 0x947: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_94c:
	/* 0x94c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_950:
	/* 0x950: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_953:
	/* 0x953: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_957:
	/* 0x957: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_95d:
	/* 0x95d: lea    eax,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_964:
	/* 0x964: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_969:
	/* 0x969: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_96d:
	/* 0x96d: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_970:
	/* 0x970: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_974:
	/* 0x974: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_97a:
	/* 0x97a: lea    eax,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_981:
	/* 0x981: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_986:
	/* 0x986: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_98a:
	/* 0x98a: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_98d:
	/* 0x98d: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_991:
	/* 0x991: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_997:
	/* 0x997: lea    eax,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_99e:
	/* 0x99e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9a3:
	/* 0x9a3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9a7:
	/* 0x9a7: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_9aa:
	/* 0x9aa: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_9ae:
	/* 0x9ae: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_9b4:
	/* 0x9b4: lea    eax,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_9bb:
	/* 0x9bb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9c0:
	/* 0x9c0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9c4:
	/* 0x9c4: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_9c7:
	/* 0x9c7: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_9cb:
	/* 0x9cb: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_9d1:
	/* 0x9d1: lea    eax,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_9d8:
	/* 0x9d8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9dd:
	/* 0x9dd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9e1:
	/* 0x9e1: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_9e4:
	/* 0x9e4: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_9e8:
	/* 0x9e8: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_9ee:
	/* 0x9ee: lea    eax,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_9f5:
	/* 0x9f5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9fa:
	/* 0x9fa: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9fe:
	/* 0x9fe: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a01:
	/* 0xa01: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_a05:
	/* 0xa05: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a0b:
	/* 0xa0b: lea    eax,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_a12:
	/* 0xa12: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a17:
	/* 0xa17: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a1b:
	/* 0xa1b: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_a1e:
	/* 0xa1e: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_a22:
	/* 0xa22: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a28:
	/* 0xa28: lea    eax,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_a2f:
	/* 0xa2f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a34:
	/* 0xa34: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a38:
	/* 0xa38: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_a3b:
	/* 0xa3b: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_a3f:
	/* 0xa3f: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a45:
	/* 0xa45: lea    eax,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_a4c:
	/* 0xa4c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a51:
	/* 0xa51: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a55:
	/* 0xa55: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_a58:
	/* 0xa58: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_a5c:
	/* 0xa5c: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a62:
	/* 0xa62: lea    eax,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_a69:
	/* 0xa69: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a6e:
	/* 0xa6e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a72:
	/* 0xa72: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_a75:
	/* 0xa75: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_a79:
	/* 0xa79: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a7f:
	/* 0xa7f: lea    eax,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_a86:
	/* 0xa86: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a8b:
	/* 0xa8b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a8f:
	/* 0xa8f: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_a92:
	/* 0xa92: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_a96:
	/* 0xa96: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_a9c:
	/* 0xa9c: lea    eax,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_aa3:
	/* 0xaa3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aa8:
	/* 0xaa8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_aac:
	/* 0xaac: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_aaf:
	/* 0xaaf: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_ab3:
	/* 0xab3: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_ab9:
	/* 0xab9: lea    eax,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_ac0:
	/* 0xac0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ac5:
	/* 0xac5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ac9:
	/* 0xac9: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_acc:
	/* 0xacc: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_ad0:
	/* 0xad0: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_ad6:
	/* 0xad6: lea    eax,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_add:
	/* 0xadd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ae2:
	/* 0xae2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ae6:
	/* 0xae6: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ae9:
	/* 0xae9: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_aed:
	/* 0xaed: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_af3:
	/* 0xaf3: lea    eax,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_afa:
	/* 0xafa: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aff:
	/* 0xaff: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b03:
	/* 0xb03: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_b06:
	/* 0xb06: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_b0a:
	/* 0xb0a: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b10:
	/* 0xb10: lea    eax,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_b17:
	/* 0xb17: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b1c:
	/* 0xb1c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b20:
	/* 0xb20: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_b23:
	/* 0xb23: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_b27:
	/* 0xb27: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b2d:
	/* 0xb2d: lea    eax,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_b34:
	/* 0xb34: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b39:
	/* 0xb39: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b3d:
	/* 0xb3d: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_b40:
	/* 0xb40: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_b44:
	/* 0xb44: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b4a:
	/* 0xb4a: lea    eax,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_b51:
	/* 0xb51: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b56:
	/* 0xb56: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b5a:
	/* 0xb5a: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_b5d:
	/* 0xb5d: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_b61:
	/* 0xb61: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b67:
	/* 0xb67: lea    eax,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_b6e:
	/* 0xb6e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b73:
	/* 0xb73: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b77:
	/* 0xb77: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_b7a:
	/* 0xb7a: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_b7e:
	/* 0xb7e: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_b84:
	/* 0xb84: lea    eax,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_b8b:
	/* 0xb8b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b90:
	/* 0xb90: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b94:
	/* 0xb94: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_b97:
	/* 0xb97: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_b9b:
	/* 0xb9b: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_ba1:
	/* 0xba1: lea    eax,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_ba8:
	/* 0xba8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bad:
	/* 0xbad: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bb1:
	/* 0xbb1: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_bb4:
	/* 0xbb4: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_bb8:
	/* 0xbb8: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_bbe:
	/* 0xbbe: lea    eax,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_bc5:
	/* 0xbc5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bca:
	/* 0xbca: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bce:
	/* 0xbce: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bd1:
	/* 0xbd1: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_bd5:
	/* 0xbd5: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_bdb:
	/* 0xbdb: lea    eax,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_be2:
	/* 0xbe2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_be7:
	/* 0xbe7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_beb:
	/* 0xbeb: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_bee:
	/* 0xbee: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_bf2:
	/* 0xbf2: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_bf8:
	/* 0xbf8: lea    eax,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_bff:
	/* 0xbff: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c04:
	/* 0xc04: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c08:
	/* 0xc08: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_c0b:
	/* 0xc0b: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_c0f:
	/* 0xc0f: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c15:
	/* 0xc15: lea    eax,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_c1c:
	/* 0xc1c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c21:
	/* 0xc21: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c25:
	/* 0xc25: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_c28:
	/* 0xc28: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_c2c:
	/* 0xc2c: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c32:
	/* 0xc32: lea    eax,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_c39:
	/* 0xc39: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c3e:
	/* 0xc3e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c42:
	/* 0xc42: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c45:
	/* 0xc45: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_c49:
	/* 0xc49: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c4b:
	/* 0xc4b: lea    eax,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_c52:
	/* 0xc52: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c57:
	/* 0xc57: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c5b:
	/* 0xc5b: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_c5e:
	/* 0xc5e: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_c62:
	/* 0xc62: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c64:
	/* 0xc64: lea    eax,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_c6b:
	/* 0xc6b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c70:
	/* 0xc70: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c74:
	/* 0xc74: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_c77:
	/* 0xc77: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_c7b:
	/* 0xc7b: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c7d:
	/* 0xc7d: lea    eax,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_c84:
	/* 0xc84: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c89:
	/* 0xc89: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c8d:
	/* 0xc8d: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_c90:
	/* 0xc90: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_c94:
	/* 0xc94: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_c96:
	/* 0xc96: lea    eax,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_c9d:
	/* 0xc9d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ca2:
	/* 0xca2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ca6:
	/* 0xca6: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ca9:
	/* 0xca9: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_cad:
	/* 0xcad: je     cc5 <generic_usdt_filter_arg_2+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc5;
	}
x86_l_caf:
	/* 0xcaf: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_cb6:
	/* 0xcb6: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cbd:
	/* 0xcbd: movzx  eax,BYTE PTR [rcx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_cc2:
	/* 0xcc2: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_cc5:
	/* 0xcc5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cca:
	/* 0xcca: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ccd:
	/* 0xccd: jmp    31e8 <generic_usdt_filter_arg_2+0x31e8> */
	return 12776ULL;
x86_l_cd2:
	/* 0xcd2: lea    eax,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_cd5:
	/* 0xcd5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cd8:
	/* 0xcd8: jb     d71 <generic_usdt_filter_arg_2+0xd71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d71;
	}
x86_l_cde:
	/* 0xcde: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_ce1:
	/* 0xce1: je     cf0 <generic_usdt_filter_arg_2+0xcf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf0;
	}
x86_l_ce3:
	/* 0xce3: jmp    3220 <generic_usdt_filter_arg_2+0x3220> */
	return 12832ULL;
x86_l_ce8:
	/* 0xce8: lea    eax,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_ceb:
	/* 0xceb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cee:
	/* 0xcee: jae    d68 <generic_usdt_filter_arg_2+0xd68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d68;
	}
x86_l_cf0:
	/* 0xcf0: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_cf9:
	/* 0xcf9: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_d02:
	/* 0xd02: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d0b:
	/* 0xd0b: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_d14:
	/* 0xd14: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_d1d:
	/* 0xd1d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d20:
	/* 0xd20: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_d23:
	/* 0xd23: jg     d3f <generic_usdt_filter_arg_2+0xd3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d3f;
	}
x86_l_d25:
	/* 0xd25: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d28:
	/* 0xd28: je     1b5e <generic_usdt_filter_arg_2+0x1b5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7006ULL;
	}
x86_l_d2e:
	/* 0xd2e: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_d31:
	/* 0xd31: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_d34:
	/* 0xd34: je     1b60 <generic_usdt_filter_arg_2+0x1b60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7008ULL;
	}
x86_l_d3a:
	/* 0xd3a: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_d3f:
	/* 0xd3f: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_d42:
	/* 0xd42: je     1b34 <generic_usdt_filter_arg_2+0x1b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6964ULL;
	}
x86_l_d48:
	/* 0xd48: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_d4b:
	/* 0xd4b: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_d4e:
	/* 0xd4e: je     1b60 <generic_usdt_filter_arg_2+0x1b60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7008ULL;
	}
x86_l_d54:
	/* 0xd54: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_d59:
	/* 0xd59: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_d5c:
	/* 0xd5c: jne    3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12832ULL;
	}
x86_l_d62:
	/* 0xd62: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d66:
	/* 0xd66: jmp    d71 <generic_usdt_filter_arg_2+0xd71> */
	goto x86_l_d71;
x86_l_d68:
	/* 0xd68: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_d6b:
	/* 0xd6b: jne    3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12832ULL;
	}
x86_l_d71:
	/* 0xd71: mov    r13d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d74:
	/* 0xd74: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d77:
	/* 0xd77: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d7a:
	/* 0xd7a: jne    d8a <generic_usdt_filter_arg_2+0xd8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d8a;
	}
x86_l_d7c:
	/* 0xd7c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d7e:
	/* 0xd7e: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_d81:
	/* 0xd81: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_d84:
	/* 0xd84: jne    322a <generic_usdt_filter_arg_2+0x322a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12842ULL;
	}
x86_l_d8a:
	/* 0xd8a: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_d8d:
	/* 0xd8d: ja     1bd7 <generic_usdt_filter_arg_2+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7127ULL;
	}
x86_l_d93:
	/* 0xd93: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d95:
	/* 0xd95: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_d9a:
	/* 0xd9a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_d9e:
	/* 0xd9e: jb     2737 <generic_usdt_filter_arg_2+0x2737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10039ULL;
	}
x86_l_da4:
	/* 0xda4: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_da9:
	/* 0xda9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_dad:
	/* 0xdad: jb     1c20 <generic_usdt_filter_arg_2+0x1c20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7200ULL;
	}
x86_l_db3:
	/* 0xdb3: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_dbd:
	/* 0xdbd: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_dc1:
	/* 0xdc1: jae    1bd7 <generic_usdt_filter_arg_2+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7127ULL;
	}
x86_l_dc7:
	/* 0xdc7: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_dce:
	/* 0xdce: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_dd5:
	/* 0xdd5: ja     1bf8 <generic_usdt_filter_arg_2+0x1bf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7160ULL;
	}
x86_l_ddb:
	/* 0xddb: lea    rcx,[r8+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_ddf:
	/* 0xddf: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_de3:
	/* 0xde3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_de8:
	/* 0xde8: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_ded:
	/* 0xded: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_df2:
	/* 0xdf2: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df5:
	/* 0xdf5: lea    rdx,[r8+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_df9:
	/* 0xdf9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_dfd:
	/* 0xdfd: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_e00:
	/* 0xe00: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e05:
	/* 0xe05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e07:
	/* 0xe07: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e0a:
	/* 0xe0a: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 3598ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3598ULL: goto x86_l_e0e;
	case 3600ULL: goto x86_l_e10;
	case 3606ULL: goto x86_l_e16;
	case 3611ULL: goto x86_l_e1b;
	case 3616ULL: goto x86_l_e20;
	case 3622ULL: goto x86_l_e26;
	case 3624ULL: goto x86_l_e28;
	case 3630ULL: goto x86_l_e2e;
	case 3633ULL: goto x86_l_e31;
	case 3636ULL: goto x86_l_e34;
	case 3642ULL: goto x86_l_e3a;
	case 3646ULL: goto x86_l_e3e;
	case 3648ULL: goto x86_l_e40;
	case 3654ULL: goto x86_l_e46;
	case 3656ULL: goto x86_l_e48;
	case 3662ULL: goto x86_l_e4e;
	case 3665ULL: goto x86_l_e51;
	case 3671ULL: goto x86_l_e57;
	case 3675ULL: goto x86_l_e5b;
	case 3677ULL: goto x86_l_e5d;
	case 3683ULL: goto x86_l_e63;
	case 3685ULL: goto x86_l_e65;
	case 3688ULL: goto x86_l_e68;
	case 3694ULL: goto x86_l_e6e;
	case 3697ULL: goto x86_l_e71;
	case 3703ULL: goto x86_l_e77;
	case 3707ULL: goto x86_l_e7b;
	case 3709ULL: goto x86_l_e7d;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3720ULL: goto x86_l_e88;
	case 3724ULL: goto x86_l_e8c;
	case 3729ULL: goto x86_l_e91;
	case 3732ULL: goto x86_l_e94;
	case 3735ULL: goto x86_l_e97;
	case 3738ULL: goto x86_l_e9a;
	case 3744ULL: goto x86_l_ea0;
	case 3748ULL: goto x86_l_ea4;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3760ULL: goto x86_l_eb0;
	case 3765ULL: goto x86_l_eb5;
	case 3771ULL: goto x86_l_ebb;
	case 3776ULL: goto x86_l_ec0;
	case 3779ULL: goto x86_l_ec3;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3793ULL: goto x86_l_ed1;
	case 3799ULL: goto x86_l_ed7;
	case 3802ULL: goto x86_l_eda;
	case 3806ULL: goto x86_l_ede;
	case 3809ULL: goto x86_l_ee1;
	case 3813ULL: goto x86_l_ee5;
	case 3821ULL: goto x86_l_eed;
	case 3828ULL: goto x86_l_ef4;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3840ULL: goto x86_l_f00;
	case 3843ULL: goto x86_l_f03;
	case 3849ULL: goto x86_l_f09;
	case 3855ULL: goto x86_l_f0f;
	case 3860ULL: goto x86_l_f14;
	case 3863ULL: goto x86_l_f17;
	case 3869ULL: goto x86_l_f1d;
	case 3876ULL: goto x86_l_f24;
	case 3881ULL: goto x86_l_f29;
	case 3886ULL: goto x86_l_f2e;
	case 3888ULL: goto x86_l_f30;
	case 3891ULL: goto x86_l_f33;
	case 3897ULL: goto x86_l_f39;
	case 3900ULL: goto x86_l_f3c;
	case 3905ULL: goto x86_l_f41;
	case 3908ULL: goto x86_l_f44;
	case 3913ULL: goto x86_l_f49;
	case 3916ULL: goto x86_l_f4c;
	case 3919ULL: goto x86_l_f4f;
	case 3921ULL: goto x86_l_f51;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3942ULL: goto x86_l_f66;
	case 3948ULL: goto x86_l_f6c;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3965ULL: goto x86_l_f7d;
	case 3968ULL: goto x86_l_f80;
	case 3972ULL: goto x86_l_f84;
	case 3978ULL: goto x86_l_f8a;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3995ULL: goto x86_l_f9b;
	case 3998ULL: goto x86_l_f9e;
	case 4002ULL: goto x86_l_fa2;
	case 4008ULL: goto x86_l_fa8;
	case 4014ULL: goto x86_l_fae;
	case 4019ULL: goto x86_l_fb3;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4032ULL: goto x86_l_fc0;
	case 4038ULL: goto x86_l_fc6;
	case 4044ULL: goto x86_l_fcc;
	case 4049ULL: goto x86_l_fd1;
	case 4055ULL: goto x86_l_fd7;
	case 4058ULL: goto x86_l_fda;
	case 4062ULL: goto x86_l_fde;
	case 4068ULL: goto x86_l_fe4;
	case 4074ULL: goto x86_l_fea;
	case 4079ULL: goto x86_l_fef;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4092ULL: goto x86_l_ffc;
	case 4098ULL: goto x86_l_1002;
	case 4104ULL: goto x86_l_1008;
	case 4109ULL: goto x86_l_100d;
	case 4115ULL: goto x86_l_1013;
	case 4118ULL: goto x86_l_1016;
	case 4122ULL: goto x86_l_101a;
	case 4128ULL: goto x86_l_1020;
	case 4134ULL: goto x86_l_1026;
	case 4139ULL: goto x86_l_102b;
	case 4145ULL: goto x86_l_1031;
	case 4148ULL: goto x86_l_1034;
	case 4152ULL: goto x86_l_1038;
	case 4158ULL: goto x86_l_103e;
	case 4164ULL: goto x86_l_1044;
	case 4169ULL: goto x86_l_1049;
	case 4175ULL: goto x86_l_104f;
	case 4178ULL: goto x86_l_1052;
	case 4182ULL: goto x86_l_1056;
	case 4188ULL: goto x86_l_105c;
	case 4194ULL: goto x86_l_1062;
	case 4199ULL: goto x86_l_1067;
	case 4205ULL: goto x86_l_106d;
	case 4208ULL: goto x86_l_1070;
	case 4212ULL: goto x86_l_1074;
	case 4218ULL: goto x86_l_107a;
	case 4224ULL: goto x86_l_1080;
	case 4229ULL: goto x86_l_1085;
	case 4235ULL: goto x86_l_108b;
	case 4238ULL: goto x86_l_108e;
	case 4242ULL: goto x86_l_1092;
	case 4248ULL: goto x86_l_1098;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4265ULL: goto x86_l_10a9;
	case 4268ULL: goto x86_l_10ac;
	case 4272ULL: goto x86_l_10b0;
	case 4278ULL: goto x86_l_10b6;
	case 4284ULL: goto x86_l_10bc;
	case 4289ULL: goto x86_l_10c1;
	case 4295ULL: goto x86_l_10c7;
	case 4298ULL: goto x86_l_10ca;
	case 4302ULL: goto x86_l_10ce;
	case 4308ULL: goto x86_l_10d4;
	case 4314ULL: goto x86_l_10da;
	case 4319ULL: goto x86_l_10df;
	case 4325ULL: goto x86_l_10e5;
	case 4328ULL: goto x86_l_10e8;
	case 4332ULL: goto x86_l_10ec;
	case 4338ULL: goto x86_l_10f2;
	case 4344ULL: goto x86_l_10f8;
	case 4349ULL: goto x86_l_10fd;
	case 4355ULL: goto x86_l_1103;
	case 4358ULL: goto x86_l_1106;
	case 4362ULL: goto x86_l_110a;
	case 4368ULL: goto x86_l_1110;
	case 4374ULL: goto x86_l_1116;
	case 4379ULL: goto x86_l_111b;
	case 4385ULL: goto x86_l_1121;
	case 4388ULL: goto x86_l_1124;
	case 4392ULL: goto x86_l_1128;
	case 4398ULL: goto x86_l_112e;
	case 4404ULL: goto x86_l_1134;
	case 4409ULL: goto x86_l_1139;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4422ULL: goto x86_l_1146;
	case 4428ULL: goto x86_l_114c;
	case 4434ULL: goto x86_l_1152;
	case 4439ULL: goto x86_l_1157;
	case 4445ULL: goto x86_l_115d;
	case 4448ULL: goto x86_l_1160;
	case 4452ULL: goto x86_l_1164;
	case 4458ULL: goto x86_l_116a;
	case 4464ULL: goto x86_l_1170;
	case 4469ULL: goto x86_l_1175;
	case 4475ULL: goto x86_l_117b;
	case 4478ULL: goto x86_l_117e;
	case 4482ULL: goto x86_l_1182;
	case 4488ULL: goto x86_l_1188;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4505ULL: goto x86_l_1199;
	case 4508ULL: goto x86_l_119c;
	case 4512ULL: goto x86_l_11a0;
	case 4518ULL: goto x86_l_11a6;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4535ULL: goto x86_l_11b7;
	case 4538ULL: goto x86_l_11ba;
	case 4542ULL: goto x86_l_11be;
	case 4548ULL: goto x86_l_11c4;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4565ULL: goto x86_l_11d5;
	case 4568ULL: goto x86_l_11d8;
	case 4572ULL: goto x86_l_11dc;
	case 4578ULL: goto x86_l_11e2;
	case 4584ULL: goto x86_l_11e8;
	case 4589ULL: goto x86_l_11ed;
	case 4595ULL: goto x86_l_11f3;
	case 4598ULL: goto x86_l_11f6;
	case 4602ULL: goto x86_l_11fa;
	case 4608ULL: goto x86_l_1200;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4625ULL: goto x86_l_1211;
	case 4628ULL: goto x86_l_1214;
	case 4632ULL: goto x86_l_1218;
	case 4638ULL: goto x86_l_121e;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4655ULL: goto x86_l_122f;
	case 4658ULL: goto x86_l_1232;
	case 4662ULL: goto x86_l_1236;
	case 4668ULL: goto x86_l_123c;
	case 4674ULL: goto x86_l_1242;
	case 4679ULL: goto x86_l_1247;
	case 4685ULL: goto x86_l_124d;
	case 4688ULL: goto x86_l_1250;
	case 4692ULL: goto x86_l_1254;
	case 4698ULL: goto x86_l_125a;
	case 4704ULL: goto x86_l_1260;
	case 4709ULL: goto x86_l_1265;
	case 4715ULL: goto x86_l_126b;
	case 4718ULL: goto x86_l_126e;
	case 4722ULL: goto x86_l_1272;
	case 4728ULL: goto x86_l_1278;
	case 4734ULL: goto x86_l_127e;
	case 4739ULL: goto x86_l_1283;
	case 4745ULL: goto x86_l_1289;
	case 4748ULL: goto x86_l_128c;
	case 4752ULL: goto x86_l_1290;
	case 4758ULL: goto x86_l_1296;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4775ULL: goto x86_l_12a7;
	case 4778ULL: goto x86_l_12aa;
	case 4782ULL: goto x86_l_12ae;
	case 4788ULL: goto x86_l_12b4;
	case 4794ULL: goto x86_l_12ba;
	case 4799ULL: goto x86_l_12bf;
	case 4805ULL: goto x86_l_12c5;
	case 4808ULL: goto x86_l_12c8;
	case 4812ULL: goto x86_l_12cc;
	case 4818ULL: goto x86_l_12d2;
	case 4824ULL: goto x86_l_12d8;
	case 4829ULL: goto x86_l_12dd;
	case 4835ULL: goto x86_l_12e3;
	case 4838ULL: goto x86_l_12e6;
	case 4842ULL: goto x86_l_12ea;
	case 4848ULL: goto x86_l_12f0;
	case 4854ULL: goto x86_l_12f6;
	case 4859ULL: goto x86_l_12fb;
	case 4865ULL: goto x86_l_1301;
	case 4868ULL: goto x86_l_1304;
	case 4872ULL: goto x86_l_1308;
	case 4878ULL: goto x86_l_130e;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4895ULL: goto x86_l_131f;
	case 4898ULL: goto x86_l_1322;
	case 4902ULL: goto x86_l_1326;
	case 4908ULL: goto x86_l_132c;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4925ULL: goto x86_l_133d;
	case 4928ULL: goto x86_l_1340;
	case 4932ULL: goto x86_l_1344;
	case 4938ULL: goto x86_l_134a;
	case 4944ULL: goto x86_l_1350;
	case 4949ULL: goto x86_l_1355;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4962ULL: goto x86_l_1362;
	case 4968ULL: goto x86_l_1368;
	case 4974ULL: goto x86_l_136e;
	case 4979ULL: goto x86_l_1373;
	case 4985ULL: goto x86_l_1379;
	case 4988ULL: goto x86_l_137c;
	case 4992ULL: goto x86_l_1380;
	case 4998ULL: goto x86_l_1386;
	case 5004ULL: goto x86_l_138c;
	case 5009ULL: goto x86_l_1391;
	case 5015ULL: goto x86_l_1397;
	case 5018ULL: goto x86_l_139a;
	case 5022ULL: goto x86_l_139e;
	case 5028ULL: goto x86_l_13a4;
	case 5034ULL: goto x86_l_13aa;
	case 5039ULL: goto x86_l_13af;
	case 5045ULL: goto x86_l_13b5;
	case 5048ULL: goto x86_l_13b8;
	case 5052ULL: goto x86_l_13bc;
	case 5058ULL: goto x86_l_13c2;
	case 5064ULL: goto x86_l_13c8;
	case 5069ULL: goto x86_l_13cd;
	case 5075ULL: goto x86_l_13d3;
	case 5078ULL: goto x86_l_13d6;
	case 5082ULL: goto x86_l_13da;
	case 5088ULL: goto x86_l_13e0;
	case 5094ULL: goto x86_l_13e6;
	case 5099ULL: goto x86_l_13eb;
	case 5105ULL: goto x86_l_13f1;
	case 5108ULL: goto x86_l_13f4;
	case 5112ULL: goto x86_l_13f8;
	case 5118ULL: goto x86_l_13fe;
	case 5124ULL: goto x86_l_1404;
	case 5129ULL: goto x86_l_1409;
	case 5135ULL: goto x86_l_140f;
	case 5138ULL: goto x86_l_1412;
	case 5142ULL: goto x86_l_1416;
	case 5148ULL: goto x86_l_141c;
	case 5154ULL: goto x86_l_1422;
	case 5159ULL: goto x86_l_1427;
	case 5165ULL: goto x86_l_142d;
	case 5168ULL: goto x86_l_1430;
	case 5172ULL: goto x86_l_1434;
	case 5178ULL: goto x86_l_143a;
	case 5184ULL: goto x86_l_1440;
	case 5189ULL: goto x86_l_1445;
	case 5195ULL: goto x86_l_144b;
	case 5198ULL: goto x86_l_144e;
	case 5202ULL: goto x86_l_1452;
	case 5208ULL: goto x86_l_1458;
	case 5214ULL: goto x86_l_145e;
	case 5219ULL: goto x86_l_1463;
	case 5225ULL: goto x86_l_1469;
	case 5228ULL: goto x86_l_146c;
	case 5232ULL: goto x86_l_1470;
	case 5238ULL: goto x86_l_1476;
	case 5244ULL: goto x86_l_147c;
	case 5249ULL: goto x86_l_1481;
	case 5255ULL: goto x86_l_1487;
	case 5258ULL: goto x86_l_148a;
	case 5262ULL: goto x86_l_148e;
	case 5268ULL: goto x86_l_1494;
	case 5274ULL: goto x86_l_149a;
	case 5279ULL: goto x86_l_149f;
	case 5285ULL: goto x86_l_14a5;
	case 5288ULL: goto x86_l_14a8;
	case 5292ULL: goto x86_l_14ac;
	case 5298ULL: goto x86_l_14b2;
	case 5304ULL: goto x86_l_14b8;
	case 5309ULL: goto x86_l_14bd;
	case 5315ULL: goto x86_l_14c3;
	case 5318ULL: goto x86_l_14c6;
	case 5322ULL: goto x86_l_14ca;
	case 5328ULL: goto x86_l_14d0;
	case 5334ULL: goto x86_l_14d6;
	case 5339ULL: goto x86_l_14db;
	case 5345ULL: goto x86_l_14e1;
	case 5348ULL: goto x86_l_14e4;
	case 5352ULL: goto x86_l_14e8;
	case 5358ULL: goto x86_l_14ee;
	case 5364ULL: goto x86_l_14f4;
	case 5369ULL: goto x86_l_14f9;
	case 5375ULL: goto x86_l_14ff;
	case 5378ULL: goto x86_l_1502;
	case 5382ULL: goto x86_l_1506;
	case 5388ULL: goto x86_l_150c;
	case 5394ULL: goto x86_l_1512;
	case 5399ULL: goto x86_l_1517;
	case 5405ULL: goto x86_l_151d;
	case 5408ULL: goto x86_l_1520;
	case 5412ULL: goto x86_l_1524;
	case 5418ULL: goto x86_l_152a;
	case 5424ULL: goto x86_l_1530;
	case 5429ULL: goto x86_l_1535;
	case 5435ULL: goto x86_l_153b;
	case 5438ULL: goto x86_l_153e;
	case 5442ULL: goto x86_l_1542;
	case 5448ULL: goto x86_l_1548;
	case 5454ULL: goto x86_l_154e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e0e:
	/* 0xe0e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e10:
	/* 0xe10: je     1bf8 <generic_usdt_filter_arg_2+0x1bf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7160ULL;
	}
x86_l_e16:
	/* 0xe16: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_e1b:
	/* 0xe1b: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_e20:
	/* 0xe20: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_e26:
	/* 0xe26: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e28:
	/* 0xe28: je     315e <generic_usdt_filter_arg_2+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12638ULL;
	}
x86_l_e2e:
	/* 0xe2e: mov    ecx,DWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e31:
	/* 0xe31: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_e34:
	/* 0xe34: jbe    3001 <generic_usdt_filter_arg_2+0x3001> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12289ULL;
	}
x86_l_e3a:
	/* 0xe3a: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e3e:
	/* 0xe3e: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e40:
	/* 0xe40: je     3001 <generic_usdt_filter_arg_2+0x3001> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12289ULL;
	}
x86_l_e46:
	/* 0xe46: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e48:
	/* 0xe48: je     3004 <generic_usdt_filter_arg_2+0x3004> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12292ULL;
	}
x86_l_e4e:
	/* 0xe4e: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_e51:
	/* 0xe51: jb     3001 <generic_usdt_filter_arg_2+0x3001> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12289ULL;
	}
x86_l_e57:
	/* 0xe57: mov    edx,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e5b:
	/* 0xe5b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e5d:
	/* 0xe5d: je     3001 <generic_usdt_filter_arg_2+0x3001> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12289ULL;
	}
x86_l_e63:
	/* 0xe63: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e65:
	/* 0xe65: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e68:
	/* 0xe68: je     315e <generic_usdt_filter_arg_2+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12638ULL;
	}
x86_l_e6e:
	/* 0xe6e: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_e71:
	/* 0xe71: jb     3001 <generic_usdt_filter_arg_2+0x3001> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12289ULL;
	}
x86_l_e77:
	/* 0xe77: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e7b:
	/* 0xe7b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e7d:
	/* 0xe7d: je     3001 <generic_usdt_filter_arg_2+0x3001> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12289ULL;
	}
x86_l_e83:
	/* 0xe83: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e86:
	/* 0xe86: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e88:
	/* 0xe88: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_e8c:
	/* 0xe8c: jmp    3004 <generic_usdt_filter_arg_2+0x3004> */
	return 12292ULL;
x86_l_e91:
	/* 0xe91: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e94:
	/* 0xe94: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e97:
	/* 0xe97: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_e9a:
	/* 0xe9a: ja     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12800ULL;
	}
x86_l_ea0:
	/* 0xea0: mov    edx,DWORD PTR [r8+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ea4:
	/* 0xea4: add    r8,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ea8:
	/* 0xea8: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_ead:
	/* 0xead: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_eb0:
	/* 0xeb0: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eb5:
	/* 0xeb5: jb     29f0 <generic_usdt_filter_arg_2+0x29f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10736ULL;
	}
x86_l_ebb:
	/* 0xebb: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_ec0:
	/* 0xec0: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ec3:
	/* 0xec3: jb     294c <generic_usdt_filter_arg_2+0x294c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10572ULL;
	}
x86_l_ec9:
	/* 0xec9: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_ece:
	/* 0xece: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ed1:
	/* 0xed1: jae    3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12800ULL;
	}
x86_l_ed7:
	/* 0xed7: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_eda:
	/* 0xeda: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ede:
	/* 0xede: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee1:
	/* 0xee1: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ee5:
	/* 0xee5: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_eed:
	/* 0xeed: mov    rdi,QWORD PTR [rip+0xbe77] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_ef4:
	/* 0xef4: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ef9:
	/* 0xef9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_efe:
	/* 0xefe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f00:
	/* 0xf00: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f03:
	/* 0xf03: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f09:
	/* 0xf09: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_f0f:
	/* 0xf0f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f14:
	/* 0xf14: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f17:
	/* 0xf17: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_f1d:
	/* 0xf1d: mov    rdi,QWORD PTR [rip+0xbe77] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_f24:
	/* 0xf24: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f29:
	/* 0xf29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f2e:
	/* 0xf2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f30:
	/* 0xf30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f33:
	/* 0xf33: je     31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12790ULL;
	}
x86_l_f39:
	/* 0xf39: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f3c:
	/* 0xf3c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f41:
	/* 0xf41: cmp    edx,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 94ULL);
x86_l_f44:
	/* 0xf44: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_f49:
	/* 0xf49: cmovb  eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_B);
x86_l_f4c:
	/* 0xf4c: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_f4f:
	/* 0xf4f: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f51:
	/* 0xf51: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_f54:
	/* 0xf54: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f59:
	/* 0xf59: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f5f:
	/* 0xf5f: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f62:
	/* 0xf62: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_f66:
	/* 0xf66: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_f6c:
	/* 0xf6c: lea    eax,[rdx+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_f72:
	/* 0xf72: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f77:
	/* 0xf77: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f7d:
	/* 0xf7d: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_f80:
	/* 0xf80: cmp    rdx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 2ULL);
x86_l_f84:
	/* 0xf84: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_f8a:
	/* 0xf8a: lea    eax,[rdx+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_f90:
	/* 0xf90: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f95:
	/* 0xf95: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f9b:
	/* 0xf9b: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_f9e:
	/* 0xf9e: cmp    rdx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 3ULL);
x86_l_fa2:
	/* 0xfa2: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_fa8:
	/* 0xfa8: lea    eax,[rdx+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_fae:
	/* 0xfae: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fb3:
	/* 0xfb3: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fb9:
	/* 0xfb9: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_fbc:
	/* 0xfbc: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_fc0:
	/* 0xfc0: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_fc6:
	/* 0xfc6: lea    eax,[rdx+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_fcc:
	/* 0xfcc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fd1:
	/* 0xfd1: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fd7:
	/* 0xfd7: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fda:
	/* 0xfda: cmp    rdx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 5ULL);
x86_l_fde:
	/* 0xfde: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_fe4:
	/* 0xfe4: lea    eax,[rdx+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_fea:
	/* 0xfea: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fef:
	/* 0xfef: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ff5:
	/* 0xff5: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_ff8:
	/* 0xff8: cmp    rdx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 6ULL);
x86_l_ffc:
	/* 0xffc: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1002:
	/* 0x1002: lea    eax,[rdx+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_1008:
	/* 0x1008: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_100d:
	/* 0x100d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1013:
	/* 0x1013: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1016:
	/* 0x1016: cmp    rdx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 7ULL);
x86_l_101a:
	/* 0x101a: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1020:
	/* 0x1020: lea    eax,[rdx+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_1026:
	/* 0x1026: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_102b:
	/* 0x102b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1031:
	/* 0x1031: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1034:
	/* 0x1034: cmp    rdx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 8ULL);
x86_l_1038:
	/* 0x1038: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_103e:
	/* 0x103e: lea    eax,[rdx+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_1044:
	/* 0x1044: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1049:
	/* 0x1049: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_104f:
	/* 0x104f: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1052:
	/* 0x1052: cmp    rdx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 9ULL);
x86_l_1056:
	/* 0x1056: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_105c:
	/* 0x105c: lea    eax,[rdx+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1062:
	/* 0x1062: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1067:
	/* 0x1067: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_106d:
	/* 0x106d: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1070:
	/* 0x1070: cmp    rdx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 10ULL);
x86_l_1074:
	/* 0x1074: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_107a:
	/* 0x107a: lea    eax,[rdx+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1080:
	/* 0x1080: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1085:
	/* 0x1085: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_108b:
	/* 0x108b: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_108e:
	/* 0x108e: cmp    rdx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 11ULL);
x86_l_1092:
	/* 0x1092: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1098:
	/* 0x1098: lea    eax,[rdx+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_109e:
	/* 0x109e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10a3:
	/* 0x10a3: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10a9:
	/* 0x10a9: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_10ac:
	/* 0x10ac: cmp    rdx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 12ULL);
x86_l_10b0:
	/* 0x10b0: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_10b6:
	/* 0x10b6: lea    eax,[rdx+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_10bc:
	/* 0x10bc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10c1:
	/* 0x10c1: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10c7:
	/* 0x10c7: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ca:
	/* 0x10ca: cmp    rdx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 13ULL);
x86_l_10ce:
	/* 0x10ce: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_10d4:
	/* 0x10d4: lea    eax,[rdx+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_10da:
	/* 0x10da: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10df:
	/* 0x10df: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10e5:
	/* 0x10e5: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_10e8:
	/* 0x10e8: cmp    rdx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 14ULL);
x86_l_10ec:
	/* 0x10ec: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_10f2:
	/* 0x10f2: lea    eax,[rdx+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_10f8:
	/* 0x10f8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10fd:
	/* 0x10fd: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1103:
	/* 0x1103: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1106:
	/* 0x1106: cmp    rdx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 15ULL);
x86_l_110a:
	/* 0x110a: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1110:
	/* 0x1110: lea    eax,[rdx+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1116:
	/* 0x1116: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_111b:
	/* 0x111b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1121:
	/* 0x1121: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1124:
	/* 0x1124: cmp    rdx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 16ULL);
x86_l_1128:
	/* 0x1128: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_112e:
	/* 0x112e: lea    eax,[rdx+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_1134:
	/* 0x1134: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1139:
	/* 0x1139: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_113f:
	/* 0x113f: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1142:
	/* 0x1142: cmp    rdx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 17ULL);
x86_l_1146:
	/* 0x1146: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_114c:
	/* 0x114c: lea    eax,[rdx+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1152:
	/* 0x1152: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1157:
	/* 0x1157: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_115d:
	/* 0x115d: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1160:
	/* 0x1160: cmp    rdx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18ULL);
x86_l_1164:
	/* 0x1164: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_116a:
	/* 0x116a: lea    eax,[rdx+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1170:
	/* 0x1170: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1175:
	/* 0x1175: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_117b:
	/* 0x117b: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_117e:
	/* 0x117e: cmp    rdx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 19ULL);
x86_l_1182:
	/* 0x1182: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1188:
	/* 0x1188: lea    eax,[rdx+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_118e:
	/* 0x118e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1193:
	/* 0x1193: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1199:
	/* 0x1199: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_119c:
	/* 0x119c: cmp    rdx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 20ULL);
x86_l_11a0:
	/* 0x11a0: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_11a6:
	/* 0x11a6: lea    eax,[rdx+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_11ac:
	/* 0x11ac: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11b1:
	/* 0x11b1: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11b7:
	/* 0x11b7: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ba:
	/* 0x11ba: cmp    rdx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 21ULL);
x86_l_11be:
	/* 0x11be: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_11c4:
	/* 0x11c4: lea    eax,[rdx+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_11ca:
	/* 0x11ca: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11cf:
	/* 0x11cf: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11d5:
	/* 0x11d5: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_11d8:
	/* 0x11d8: cmp    rdx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 22ULL);
x86_l_11dc:
	/* 0x11dc: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_11e2:
	/* 0x11e2: lea    eax,[rdx+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_11e8:
	/* 0x11e8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11ed:
	/* 0x11ed: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11f3:
	/* 0x11f3: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_11f6:
	/* 0x11f6: cmp    rdx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 23ULL);
x86_l_11fa:
	/* 0x11fa: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1200:
	/* 0x1200: lea    eax,[rdx+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_1206:
	/* 0x1206: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_120b:
	/* 0x120b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1211:
	/* 0x1211: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_1214:
	/* 0x1214: cmp    rdx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 24ULL);
x86_l_1218:
	/* 0x1218: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_121e:
	/* 0x121e: lea    eax,[rdx+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_1224:
	/* 0x1224: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1229:
	/* 0x1229: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_122f:
	/* 0x122f: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1232:
	/* 0x1232: cmp    rdx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 25ULL);
x86_l_1236:
	/* 0x1236: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_123c:
	/* 0x123c: lea    eax,[rdx+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_1242:
	/* 0x1242: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1247:
	/* 0x1247: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_124d:
	/* 0x124d: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1250:
	/* 0x1250: cmp    rdx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 26ULL);
x86_l_1254:
	/* 0x1254: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_125a:
	/* 0x125a: lea    eax,[rdx+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1260:
	/* 0x1260: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1265:
	/* 0x1265: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_126b:
	/* 0x126b: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_126e:
	/* 0x126e: cmp    rdx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 27ULL);
x86_l_1272:
	/* 0x1272: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1278:
	/* 0x1278: lea    eax,[rdx+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_127e:
	/* 0x127e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1283:
	/* 0x1283: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1289:
	/* 0x1289: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_128c:
	/* 0x128c: cmp    rdx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 28ULL);
x86_l_1290:
	/* 0x1290: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1296:
	/* 0x1296: lea    eax,[rdx+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_129c:
	/* 0x129c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12a1:
	/* 0x12a1: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12a7:
	/* 0x12a7: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12aa:
	/* 0x12aa: cmp    rdx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 29ULL);
x86_l_12ae:
	/* 0x12ae: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_12b4:
	/* 0x12b4: lea    eax,[rdx+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_12ba:
	/* 0x12ba: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12bf:
	/* 0x12bf: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12c5:
	/* 0x12c5: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_12c8:
	/* 0x12c8: cmp    rdx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 30ULL);
x86_l_12cc:
	/* 0x12cc: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_12d2:
	/* 0x12d2: lea    eax,[rdx+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_12d8:
	/* 0x12d8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12dd:
	/* 0x12dd: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12e3:
	/* 0x12e3: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_12e6:
	/* 0x12e6: cmp    rdx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 31ULL);
x86_l_12ea:
	/* 0x12ea: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_12f0:
	/* 0x12f0: lea    eax,[rdx+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_12f6:
	/* 0x12f6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12fb:
	/* 0x12fb: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1301:
	/* 0x1301: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_1304:
	/* 0x1304: cmp    rdx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 32ULL);
x86_l_1308:
	/* 0x1308: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_130e:
	/* 0x130e: lea    eax,[rdx+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_1314:
	/* 0x1314: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1319:
	/* 0x1319: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_131f:
	/* 0x131f: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1322:
	/* 0x1322: cmp    rdx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 33ULL);
x86_l_1326:
	/* 0x1326: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_132c:
	/* 0x132c: lea    eax,[rdx+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_1332:
	/* 0x1332: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1337:
	/* 0x1337: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_133d:
	/* 0x133d: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_1340:
	/* 0x1340: cmp    rdx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 34ULL);
x86_l_1344:
	/* 0x1344: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_134a:
	/* 0x134a: lea    eax,[rdx+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_1350:
	/* 0x1350: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1355:
	/* 0x1355: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_135b:
	/* 0x135b: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_135e:
	/* 0x135e: cmp    rdx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 35ULL);
x86_l_1362:
	/* 0x1362: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1368:
	/* 0x1368: lea    eax,[rdx+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_136e:
	/* 0x136e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1373:
	/* 0x1373: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1379:
	/* 0x1379: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_137c:
	/* 0x137c: cmp    rdx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 36ULL);
x86_l_1380:
	/* 0x1380: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1386:
	/* 0x1386: lea    eax,[rdx+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_138c:
	/* 0x138c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1391:
	/* 0x1391: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1397:
	/* 0x1397: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_139a:
	/* 0x139a: cmp    rdx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 37ULL);
x86_l_139e:
	/* 0x139e: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_13a4:
	/* 0x13a4: lea    eax,[rdx+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_13aa:
	/* 0x13aa: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13af:
	/* 0x13af: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13b5:
	/* 0x13b5: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_13b8:
	/* 0x13b8: cmp    rdx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 38ULL);
x86_l_13bc:
	/* 0x13bc: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_13c2:
	/* 0x13c2: lea    eax,[rdx+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_13c8:
	/* 0x13c8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13cd:
	/* 0x13cd: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13d3:
	/* 0x13d3: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_13d6:
	/* 0x13d6: cmp    rdx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 39ULL);
x86_l_13da:
	/* 0x13da: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_13e0:
	/* 0x13e0: lea    eax,[rdx+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_13e6:
	/* 0x13e6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13eb:
	/* 0x13eb: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13f1:
	/* 0x13f1: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_13f4:
	/* 0x13f4: cmp    rdx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 40ULL);
x86_l_13f8:
	/* 0x13f8: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_13fe:
	/* 0x13fe: lea    eax,[rdx+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_1404:
	/* 0x1404: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1409:
	/* 0x1409: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_140f:
	/* 0x140f: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1412:
	/* 0x1412: cmp    rdx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 41ULL);
x86_l_1416:
	/* 0x1416: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_141c:
	/* 0x141c: lea    eax,[rdx+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_1422:
	/* 0x1422: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1427:
	/* 0x1427: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_142d:
	/* 0x142d: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_1430:
	/* 0x1430: cmp    rdx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 42ULL);
x86_l_1434:
	/* 0x1434: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_143a:
	/* 0x143a: lea    eax,[rdx+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_1440:
	/* 0x1440: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1445:
	/* 0x1445: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_144b:
	/* 0x144b: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_144e:
	/* 0x144e: cmp    rdx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 43ULL);
x86_l_1452:
	/* 0x1452: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1458:
	/* 0x1458: lea    eax,[rdx+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_145e:
	/* 0x145e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1463:
	/* 0x1463: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1469:
	/* 0x1469: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_146c:
	/* 0x146c: cmp    rdx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 44ULL);
x86_l_1470:
	/* 0x1470: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1476:
	/* 0x1476: lea    eax,[rdx+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_147c:
	/* 0x147c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1481:
	/* 0x1481: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1487:
	/* 0x1487: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_148a:
	/* 0x148a: cmp    rdx,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 45ULL);
x86_l_148e:
	/* 0x148e: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1494:
	/* 0x1494: lea    eax,[rdx+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_149a:
	/* 0x149a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_149f:
	/* 0x149f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14a5:
	/* 0x14a5: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_14a8:
	/* 0x14a8: cmp    rdx,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 46ULL);
x86_l_14ac:
	/* 0x14ac: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_14b2:
	/* 0x14b2: lea    eax,[rdx+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_14b8:
	/* 0x14b8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14bd:
	/* 0x14bd: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14c3:
	/* 0x14c3: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_14c6:
	/* 0x14c6: cmp    rdx,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 47ULL);
x86_l_14ca:
	/* 0x14ca: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_14d0:
	/* 0x14d0: lea    eax,[rdx+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_14d6:
	/* 0x14d6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14db:
	/* 0x14db: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14e1:
	/* 0x14e1: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_14e4:
	/* 0x14e4: cmp    rdx,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 48ULL);
x86_l_14e8:
	/* 0x14e8: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_14ee:
	/* 0x14ee: lea    eax,[rdx+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_14f4:
	/* 0x14f4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14f9:
	/* 0x14f9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14ff:
	/* 0x14ff: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1502:
	/* 0x1502: cmp    rdx,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 49ULL);
x86_l_1506:
	/* 0x1506: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_150c:
	/* 0x150c: lea    eax,[rdx+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_1512:
	/* 0x1512: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1517:
	/* 0x1517: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_151d:
	/* 0x151d: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_1520:
	/* 0x1520: cmp    rdx,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 50ULL);
x86_l_1524:
	/* 0x1524: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_152a:
	/* 0x152a: lea    eax,[rdx+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_1530:
	/* 0x1530: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1535:
	/* 0x1535: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_153b:
	/* 0x153b: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_153e:
	/* 0x153e: cmp    rdx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 51ULL);
x86_l_1542:
	/* 0x1542: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6713ULL;
	}
x86_l_1548:
	/* 0x1548: lea    eax,[rdx+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_154e:
	/* 0x154e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
	return 5459ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5459ULL: goto x86_l_1553;
	case 5465ULL: goto x86_l_1559;
	case 5468ULL: goto x86_l_155c;
	case 5472ULL: goto x86_l_1560;
	case 5478ULL: goto x86_l_1566;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5495ULL: goto x86_l_1577;
	case 5498ULL: goto x86_l_157a;
	case 5502ULL: goto x86_l_157e;
	case 5508ULL: goto x86_l_1584;
	case 5514ULL: goto x86_l_158a;
	case 5519ULL: goto x86_l_158f;
	case 5525ULL: goto x86_l_1595;
	case 5528ULL: goto x86_l_1598;
	case 5532ULL: goto x86_l_159c;
	case 5538ULL: goto x86_l_15a2;
	case 5544ULL: goto x86_l_15a8;
	case 5549ULL: goto x86_l_15ad;
	case 5555ULL: goto x86_l_15b3;
	case 5558ULL: goto x86_l_15b6;
	case 5562ULL: goto x86_l_15ba;
	case 5568ULL: goto x86_l_15c0;
	case 5574ULL: goto x86_l_15c6;
	case 5579ULL: goto x86_l_15cb;
	case 5585ULL: goto x86_l_15d1;
	case 5588ULL: goto x86_l_15d4;
	case 5592ULL: goto x86_l_15d8;
	case 5598ULL: goto x86_l_15de;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5615ULL: goto x86_l_15ef;
	case 5618ULL: goto x86_l_15f2;
	case 5622ULL: goto x86_l_15f6;
	case 5628ULL: goto x86_l_15fc;
	case 5634ULL: goto x86_l_1602;
	case 5639ULL: goto x86_l_1607;
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5652ULL: goto x86_l_1614;
	case 5658ULL: goto x86_l_161a;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5675ULL: goto x86_l_162b;
	case 5678ULL: goto x86_l_162e;
	case 5682ULL: goto x86_l_1632;
	case 5688ULL: goto x86_l_1638;
	case 5694ULL: goto x86_l_163e;
	case 5699ULL: goto x86_l_1643;
	case 5705ULL: goto x86_l_1649;
	case 5708ULL: goto x86_l_164c;
	case 5712ULL: goto x86_l_1650;
	case 5718ULL: goto x86_l_1656;
	case 5724ULL: goto x86_l_165c;
	case 5729ULL: goto x86_l_1661;
	case 5735ULL: goto x86_l_1667;
	case 5738ULL: goto x86_l_166a;
	case 5742ULL: goto x86_l_166e;
	case 5748ULL: goto x86_l_1674;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5765ULL: goto x86_l_1685;
	case 5768ULL: goto x86_l_1688;
	case 5772ULL: goto x86_l_168c;
	case 5778ULL: goto x86_l_1692;
	case 5784ULL: goto x86_l_1698;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5798ULL: goto x86_l_16a6;
	case 5802ULL: goto x86_l_16aa;
	case 5808ULL: goto x86_l_16b0;
	case 5814ULL: goto x86_l_16b6;
	case 5819ULL: goto x86_l_16bb;
	case 5825ULL: goto x86_l_16c1;
	case 5828ULL: goto x86_l_16c4;
	case 5832ULL: goto x86_l_16c8;
	case 5838ULL: goto x86_l_16ce;
	case 5844ULL: goto x86_l_16d4;
	case 5849ULL: goto x86_l_16d9;
	case 5855ULL: goto x86_l_16df;
	case 5858ULL: goto x86_l_16e2;
	case 5862ULL: goto x86_l_16e6;
	case 5868ULL: goto x86_l_16ec;
	case 5874ULL: goto x86_l_16f2;
	case 5879ULL: goto x86_l_16f7;
	case 5885ULL: goto x86_l_16fd;
	case 5888ULL: goto x86_l_1700;
	case 5892ULL: goto x86_l_1704;
	case 5898ULL: goto x86_l_170a;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5915ULL: goto x86_l_171b;
	case 5918ULL: goto x86_l_171e;
	case 5922ULL: goto x86_l_1722;
	case 5928ULL: goto x86_l_1728;
	case 5934ULL: goto x86_l_172e;
	case 5939ULL: goto x86_l_1733;
	case 5945ULL: goto x86_l_1739;
	case 5948ULL: goto x86_l_173c;
	case 5952ULL: goto x86_l_1740;
	case 5958ULL: goto x86_l_1746;
	case 5964ULL: goto x86_l_174c;
	case 5969ULL: goto x86_l_1751;
	case 5975ULL: goto x86_l_1757;
	case 5978ULL: goto x86_l_175a;
	case 5982ULL: goto x86_l_175e;
	case 5988ULL: goto x86_l_1764;
	case 5994ULL: goto x86_l_176a;
	case 5999ULL: goto x86_l_176f;
	case 6005ULL: goto x86_l_1775;
	case 6008ULL: goto x86_l_1778;
	case 6012ULL: goto x86_l_177c;
	case 6018ULL: goto x86_l_1782;
	case 6024ULL: goto x86_l_1788;
	case 6029ULL: goto x86_l_178d;
	case 6035ULL: goto x86_l_1793;
	case 6038ULL: goto x86_l_1796;
	case 6042ULL: goto x86_l_179a;
	case 6048ULL: goto x86_l_17a0;
	case 6054ULL: goto x86_l_17a6;
	case 6059ULL: goto x86_l_17ab;
	case 6065ULL: goto x86_l_17b1;
	case 6068ULL: goto x86_l_17b4;
	case 6072ULL: goto x86_l_17b8;
	case 6078ULL: goto x86_l_17be;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6095ULL: goto x86_l_17cf;
	case 6098ULL: goto x86_l_17d2;
	case 6102ULL: goto x86_l_17d6;
	case 6108ULL: goto x86_l_17dc;
	case 6114ULL: goto x86_l_17e2;
	case 6119ULL: goto x86_l_17e7;
	case 6125ULL: goto x86_l_17ed;
	case 6128ULL: goto x86_l_17f0;
	case 6132ULL: goto x86_l_17f4;
	case 6138ULL: goto x86_l_17fa;
	case 6144ULL: goto x86_l_1800;
	case 6149ULL: goto x86_l_1805;
	case 6155ULL: goto x86_l_180b;
	case 6158ULL: goto x86_l_180e;
	case 6162ULL: goto x86_l_1812;
	case 6168ULL: goto x86_l_1818;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6185ULL: goto x86_l_1829;
	case 6188ULL: goto x86_l_182c;
	case 6192ULL: goto x86_l_1830;
	case 6198ULL: goto x86_l_1836;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6215ULL: goto x86_l_1847;
	case 6218ULL: goto x86_l_184a;
	case 6222ULL: goto x86_l_184e;
	case 6228ULL: goto x86_l_1854;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6245ULL: goto x86_l_1865;
	case 6248ULL: goto x86_l_1868;
	case 6252ULL: goto x86_l_186c;
	case 6258ULL: goto x86_l_1872;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6278ULL: goto x86_l_1886;
	case 6282ULL: goto x86_l_188a;
	case 6288ULL: goto x86_l_1890;
	case 6294ULL: goto x86_l_1896;
	case 6299ULL: goto x86_l_189b;
	case 6305ULL: goto x86_l_18a1;
	case 6308ULL: goto x86_l_18a4;
	case 6312ULL: goto x86_l_18a8;
	case 6318ULL: goto x86_l_18ae;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6335ULL: goto x86_l_18bf;
	case 6338ULL: goto x86_l_18c2;
	case 6342ULL: goto x86_l_18c6;
	case 6348ULL: goto x86_l_18cc;
	case 6354ULL: goto x86_l_18d2;
	case 6359ULL: goto x86_l_18d7;
	case 6365ULL: goto x86_l_18dd;
	case 6368ULL: goto x86_l_18e0;
	case 6372ULL: goto x86_l_18e4;
	case 6378ULL: goto x86_l_18ea;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6395ULL: goto x86_l_18fb;
	case 6398ULL: goto x86_l_18fe;
	case 6402ULL: goto x86_l_1902;
	case 6408ULL: goto x86_l_1908;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6425ULL: goto x86_l_1919;
	case 6428ULL: goto x86_l_191c;
	case 6432ULL: goto x86_l_1920;
	case 6438ULL: goto x86_l_1926;
	case 6444ULL: goto x86_l_192c;
	case 6449ULL: goto x86_l_1931;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6462ULL: goto x86_l_193e;
	case 6468ULL: goto x86_l_1944;
	case 6474ULL: goto x86_l_194a;
	case 6479ULL: goto x86_l_194f;
	case 6485ULL: goto x86_l_1955;
	case 6488ULL: goto x86_l_1958;
	case 6492ULL: goto x86_l_195c;
	case 6498ULL: goto x86_l_1962;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6515ULL: goto x86_l_1973;
	case 6518ULL: goto x86_l_1976;
	case 6522ULL: goto x86_l_197a;
	case 6528ULL: goto x86_l_1980;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6545ULL: goto x86_l_1991;
	case 6548ULL: goto x86_l_1994;
	case 6552ULL: goto x86_l_1998;
	case 6558ULL: goto x86_l_199e;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6575ULL: goto x86_l_19af;
	case 6578ULL: goto x86_l_19b2;
	case 6582ULL: goto x86_l_19b6;
	case 6588ULL: goto x86_l_19bc;
	case 6594ULL: goto x86_l_19c2;
	case 6599ULL: goto x86_l_19c7;
	case 6605ULL: goto x86_l_19cd;
	case 6608ULL: goto x86_l_19d0;
	case 6612ULL: goto x86_l_19d4;
	case 6614ULL: goto x86_l_19d6;
	case 6620ULL: goto x86_l_19dc;
	case 6625ULL: goto x86_l_19e1;
	case 6631ULL: goto x86_l_19e7;
	case 6634ULL: goto x86_l_19ea;
	case 6638ULL: goto x86_l_19ee;
	case 6640ULL: goto x86_l_19f0;
	case 6646ULL: goto x86_l_19f6;
	case 6651ULL: goto x86_l_19fb;
	case 6657ULL: goto x86_l_1a01;
	case 6660ULL: goto x86_l_1a04;
	case 6664ULL: goto x86_l_1a08;
	case 6666ULL: goto x86_l_1a0a;
	case 6672ULL: goto x86_l_1a10;
	case 6677ULL: goto x86_l_1a15;
	case 6683ULL: goto x86_l_1a1b;
	case 6686ULL: goto x86_l_1a1e;
	case 6690ULL: goto x86_l_1a22;
	case 6692ULL: goto x86_l_1a24;
	case 6698ULL: goto x86_l_1a2a;
	case 6704ULL: goto x86_l_1a30;
	case 6710ULL: goto x86_l_1a36;
	case 6713ULL: goto x86_l_1a39;
	case 6718ULL: goto x86_l_1a3e;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6733ULL: goto x86_l_1a4d;
	case 6737ULL: goto x86_l_1a51;
	case 6740ULL: goto x86_l_1a54;
	case 6744ULL: goto x86_l_1a58;
	case 6752ULL: goto x86_l_1a60;
	case 6759ULL: goto x86_l_1a67;
	case 6764ULL: goto x86_l_1a6c;
	case 6769ULL: goto x86_l_1a71;
	case 6771ULL: goto x86_l_1a73;
	case 6774ULL: goto x86_l_1a76;
	case 6777ULL: goto x86_l_1a79;
	case 6780ULL: goto x86_l_1a7c;
	case 6786ULL: goto x86_l_1a82;
	case 6789ULL: goto x86_l_1a85;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6819ULL: goto x86_l_1aa3;
	case 6822ULL: goto x86_l_1aa6;
	case 6828ULL: goto x86_l_1aac;
	case 6835ULL: goto x86_l_1ab3;
	case 6840ULL: goto x86_l_1ab8;
	case 6844ULL: goto x86_l_1abc;
	case 6851ULL: goto x86_l_1ac3;
	case 6853ULL: goto x86_l_1ac5;
	case 6856ULL: goto x86_l_1ac8;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6873ULL: goto x86_l_1ad9;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6885ULL: goto x86_l_1ae5;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6901ULL: goto x86_l_1af5;
	case 6908ULL: goto x86_l_1afc;
	case 6914ULL: goto x86_l_1b02;
	case 6918ULL: goto x86_l_1b06;
	case 6924ULL: goto x86_l_1b0c;
	case 6927ULL: goto x86_l_1b0f;
	case 6930ULL: goto x86_l_1b12;
	case 6933ULL: goto x86_l_1b15;
	case 6936ULL: goto x86_l_1b18;
	case 6938ULL: goto x86_l_1b1a;
	case 6942ULL: goto x86_l_1b1e;
	case 6948ULL: goto x86_l_1b24;
	case 6950ULL: goto x86_l_1b26;
	case 6956ULL: goto x86_l_1b2c;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6968ULL: goto x86_l_1b38;
	case 6973ULL: goto x86_l_1b3d;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6987ULL: goto x86_l_1b4b;
	case 6992ULL: goto x86_l_1b50;
	case 6996ULL: goto x86_l_1b54;
	case 7001ULL: goto x86_l_1b59;
	case 7006ULL: goto x86_l_1b5e;
	case 7008ULL: goto x86_l_1b60;
	case 7011ULL: goto x86_l_1b63;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7019ULL: goto x86_l_1b6b;
	case 7022ULL: goto x86_l_1b6e;
	case 7024ULL: goto x86_l_1b70;
	case 7027ULL: goto x86_l_1b73;
	case 7030ULL: goto x86_l_1b76;
	case 7036ULL: goto x86_l_1b7c;
	case 7039ULL: goto x86_l_1b7f;
	case 7042ULL: goto x86_l_1b82;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7056ULL: goto x86_l_1b90;
	case 7058ULL: goto x86_l_1b92;
	case 7061ULL: goto x86_l_1b95;
	case 7067ULL: goto x86_l_1b9b;
	case 7070ULL: goto x86_l_1b9e;
	case 7076ULL: goto x86_l_1ba4;
	case 7079ULL: goto x86_l_1ba7;
	case 7085ULL: goto x86_l_1bad;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7098ULL: goto x86_l_1bba;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7113ULL: goto x86_l_1bc9;
	case 7116ULL: goto x86_l_1bcc;
	case 7122ULL: goto x86_l_1bd2;
	case 7127ULL: goto x86_l_1bd7;
	case 7130ULL: goto x86_l_1bda;
	case 7133ULL: goto x86_l_1bdd;
	case 7139ULL: goto x86_l_1be3;
	case 7147ULL: goto x86_l_1beb;
	case 7154ULL: goto x86_l_1bf2;
	case 7160ULL: goto x86_l_1bf8;
	case 7163ULL: goto x86_l_1bfb;
	case 7168ULL: goto x86_l_1c00;
	case 7171ULL: goto x86_l_1c03;
	case 7177ULL: goto x86_l_1c09;
	case 7180ULL: goto x86_l_1c0c;
	case 7186ULL: goto x86_l_1c12;
	case 7189ULL: goto x86_l_1c15;
	case 7195ULL: goto x86_l_1c1b;
	case 7200ULL: goto x86_l_1c20;
	case 7205ULL: goto x86_l_1c25;
	case 7209ULL: goto x86_l_1c29;
	case 7212ULL: goto x86_l_1c2c;
	case 7216ULL: goto x86_l_1c30;
	case 7224ULL: goto x86_l_1c38;
	case 7231ULL: goto x86_l_1c3f;
	case 7236ULL: goto x86_l_1c44;
	case 7241ULL: goto x86_l_1c49;
	case 7243ULL: goto x86_l_1c4b;
	case 7246ULL: goto x86_l_1c4e;
	case 7249ULL: goto x86_l_1c51;
	case 7252ULL: goto x86_l_1c54;
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	case 7266ULL: goto x86_l_1c62;
	case 7272ULL: goto x86_l_1c68;
	case 7279ULL: goto x86_l_1c6f;
	case 7284ULL: goto x86_l_1c74;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1553:
	/* 0x1553: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1559:
	/* 0x1559: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_155c:
	/* 0x155c: cmp    rdx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 52ULL);
x86_l_1560:
	/* 0x1560: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1566:
	/* 0x1566: lea    eax,[rdx+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_156c:
	/* 0x156c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1571:
	/* 0x1571: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1577:
	/* 0x1577: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_157a:
	/* 0x157a: cmp    rdx,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 53ULL);
x86_l_157e:
	/* 0x157e: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1584:
	/* 0x1584: lea    eax,[rdx+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_158a:
	/* 0x158a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_158f:
	/* 0x158f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1595:
	/* 0x1595: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_1598:
	/* 0x1598: cmp    rdx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 54ULL);
x86_l_159c:
	/* 0x159c: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_15a2:
	/* 0x15a2: lea    eax,[rdx+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_15a8:
	/* 0x15a8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15ad:
	/* 0x15ad: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15b3:
	/* 0x15b3: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_15b6:
	/* 0x15b6: cmp    rdx,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 55ULL);
x86_l_15ba:
	/* 0x15ba: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_15c0:
	/* 0x15c0: lea    eax,[rdx+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_15c6:
	/* 0x15c6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15cb:
	/* 0x15cb: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15d1:
	/* 0x15d1: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_15d4:
	/* 0x15d4: cmp    rdx,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 56ULL);
x86_l_15d8:
	/* 0x15d8: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_15de:
	/* 0x15de: lea    eax,[rdx+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_15e4:
	/* 0x15e4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15e9:
	/* 0x15e9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15ef:
	/* 0x15ef: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_15f2:
	/* 0x15f2: cmp    rdx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 57ULL);
x86_l_15f6:
	/* 0x15f6: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_15fc:
	/* 0x15fc: lea    eax,[rdx+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_1602:
	/* 0x1602: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1607:
	/* 0x1607: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_160d:
	/* 0x160d: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_1610:
	/* 0x1610: cmp    rdx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 58ULL);
x86_l_1614:
	/* 0x1614: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_161a:
	/* 0x161a: lea    eax,[rdx+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_1620:
	/* 0x1620: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1625:
	/* 0x1625: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_162b:
	/* 0x162b: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_162e:
	/* 0x162e: cmp    rdx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 59ULL);
x86_l_1632:
	/* 0x1632: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1638:
	/* 0x1638: lea    eax,[rdx+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_163e:
	/* 0x163e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1643:
	/* 0x1643: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1649:
	/* 0x1649: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_164c:
	/* 0x164c: cmp    rdx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 60ULL);
x86_l_1650:
	/* 0x1650: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1656:
	/* 0x1656: lea    eax,[rdx+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_165c:
	/* 0x165c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1661:
	/* 0x1661: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1667:
	/* 0x1667: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_166a:
	/* 0x166a: cmp    rdx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 61ULL);
x86_l_166e:
	/* 0x166e: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1674:
	/* 0x1674: lea    eax,[rdx+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_167a:
	/* 0x167a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_167f:
	/* 0x167f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1685:
	/* 0x1685: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_1688:
	/* 0x1688: cmp    rdx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 62ULL);
x86_l_168c:
	/* 0x168c: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1692:
	/* 0x1692: lea    eax,[rdx+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_1698:
	/* 0x1698: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_169d:
	/* 0x169d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16a3:
	/* 0x16a3: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_16a6:
	/* 0x16a6: cmp    rdx,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 63ULL);
x86_l_16aa:
	/* 0x16aa: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_16b0:
	/* 0x16b0: lea    eax,[rdx+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_16b6:
	/* 0x16b6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16bb:
	/* 0x16bb: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16c1:
	/* 0x16c1: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_16c4:
	/* 0x16c4: cmp    rdx,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 64ULL);
x86_l_16c8:
	/* 0x16c8: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_16ce:
	/* 0x16ce: lea    eax,[rdx+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_16d4:
	/* 0x16d4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16d9:
	/* 0x16d9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16df:
	/* 0x16df: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_16e2:
	/* 0x16e2: cmp    rdx,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 65ULL);
x86_l_16e6:
	/* 0x16e6: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_16ec:
	/* 0x16ec: lea    eax,[rdx+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_16f2:
	/* 0x16f2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16f7:
	/* 0x16f7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16fd:
	/* 0x16fd: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_1700:
	/* 0x1700: cmp    rdx,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 66ULL);
x86_l_1704:
	/* 0x1704: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_170a:
	/* 0x170a: lea    eax,[rdx+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_1710:
	/* 0x1710: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1715:
	/* 0x1715: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_171b:
	/* 0x171b: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_171e:
	/* 0x171e: cmp    rdx,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 67ULL);
x86_l_1722:
	/* 0x1722: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1728:
	/* 0x1728: lea    eax,[rdx+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_172e:
	/* 0x172e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1733:
	/* 0x1733: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1739:
	/* 0x1739: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_173c:
	/* 0x173c: cmp    rdx,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 68ULL);
x86_l_1740:
	/* 0x1740: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1746:
	/* 0x1746: lea    eax,[rdx+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_174c:
	/* 0x174c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1751:
	/* 0x1751: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1757:
	/* 0x1757: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_175a:
	/* 0x175a: cmp    rdx,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 69ULL);
x86_l_175e:
	/* 0x175e: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1764:
	/* 0x1764: lea    eax,[rdx+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_176a:
	/* 0x176a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_176f:
	/* 0x176f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1775:
	/* 0x1775: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_1778:
	/* 0x1778: cmp    rdx,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 70ULL);
x86_l_177c:
	/* 0x177c: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1782:
	/* 0x1782: lea    eax,[rdx+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_1788:
	/* 0x1788: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_178d:
	/* 0x178d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1793:
	/* 0x1793: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_1796:
	/* 0x1796: cmp    rdx,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 71ULL);
x86_l_179a:
	/* 0x179a: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_17a0:
	/* 0x17a0: lea    eax,[rdx+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_17a6:
	/* 0x17a6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17ab:
	/* 0x17ab: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17b1:
	/* 0x17b1: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_17b4:
	/* 0x17b4: cmp    rdx,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 72ULL);
x86_l_17b8:
	/* 0x17b8: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_17be:
	/* 0x17be: lea    eax,[rdx+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_17c4:
	/* 0x17c4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17c9:
	/* 0x17c9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17cf:
	/* 0x17cf: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_17d2:
	/* 0x17d2: cmp    rdx,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 73ULL);
x86_l_17d6:
	/* 0x17d6: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_17dc:
	/* 0x17dc: lea    eax,[rdx+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_17e2:
	/* 0x17e2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17e7:
	/* 0x17e7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17ed:
	/* 0x17ed: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_17f0:
	/* 0x17f0: cmp    rdx,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 74ULL);
x86_l_17f4:
	/* 0x17f4: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_17fa:
	/* 0x17fa: lea    eax,[rdx+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_1800:
	/* 0x1800: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1805:
	/* 0x1805: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_180b:
	/* 0x180b: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_180e:
	/* 0x180e: cmp    rdx,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 75ULL);
x86_l_1812:
	/* 0x1812: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1818:
	/* 0x1818: lea    eax,[rdx+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_181e:
	/* 0x181e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1823:
	/* 0x1823: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1829:
	/* 0x1829: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_182c:
	/* 0x182c: cmp    rdx,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 76ULL);
x86_l_1830:
	/* 0x1830: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1836:
	/* 0x1836: lea    eax,[rdx+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_183c:
	/* 0x183c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1841:
	/* 0x1841: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1847:
	/* 0x1847: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_184a:
	/* 0x184a: cmp    rdx,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 77ULL);
x86_l_184e:
	/* 0x184e: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1854:
	/* 0x1854: lea    eax,[rdx+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_185a:
	/* 0x185a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_185f:
	/* 0x185f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1865:
	/* 0x1865: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_1868:
	/* 0x1868: cmp    rdx,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 78ULL);
x86_l_186c:
	/* 0x186c: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1872:
	/* 0x1872: lea    eax,[rdx+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_1878:
	/* 0x1878: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_187d:
	/* 0x187d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1883:
	/* 0x1883: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_1886:
	/* 0x1886: cmp    rdx,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 79ULL);
x86_l_188a:
	/* 0x188a: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1890:
	/* 0x1890: lea    eax,[rdx+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_1896:
	/* 0x1896: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_189b:
	/* 0x189b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18a1:
	/* 0x18a1: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_18a4:
	/* 0x18a4: cmp    rdx,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 80ULL);
x86_l_18a8:
	/* 0x18a8: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_18ae:
	/* 0x18ae: lea    eax,[rdx+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_18b4:
	/* 0x18b4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18b9:
	/* 0x18b9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18bf:
	/* 0x18bf: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_18c2:
	/* 0x18c2: cmp    rdx,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 81ULL);
x86_l_18c6:
	/* 0x18c6: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_18cc:
	/* 0x18cc: lea    eax,[rdx+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_18d2:
	/* 0x18d2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18d7:
	/* 0x18d7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18dd:
	/* 0x18dd: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_18e0:
	/* 0x18e0: cmp    rdx,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 82ULL);
x86_l_18e4:
	/* 0x18e4: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_18ea:
	/* 0x18ea: lea    eax,[rdx+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_18f0:
	/* 0x18f0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18f5:
	/* 0x18f5: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18fb:
	/* 0x18fb: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_18fe:
	/* 0x18fe: cmp    rdx,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 83ULL);
x86_l_1902:
	/* 0x1902: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1908:
	/* 0x1908: lea    eax,[rdx+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_190e:
	/* 0x190e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1913:
	/* 0x1913: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1919:
	/* 0x1919: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_191c:
	/* 0x191c: cmp    rdx,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 84ULL);
x86_l_1920:
	/* 0x1920: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1926:
	/* 0x1926: lea    eax,[rdx+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_192c:
	/* 0x192c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1931:
	/* 0x1931: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1937:
	/* 0x1937: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_193a:
	/* 0x193a: cmp    rdx,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 85ULL);
x86_l_193e:
	/* 0x193e: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1944:
	/* 0x1944: lea    eax,[rdx+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_194a:
	/* 0x194a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_194f:
	/* 0x194f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1955:
	/* 0x1955: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_1958:
	/* 0x1958: cmp    rdx,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 86ULL);
x86_l_195c:
	/* 0x195c: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1962:
	/* 0x1962: lea    eax,[rdx+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_1968:
	/* 0x1968: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_196d:
	/* 0x196d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1973:
	/* 0x1973: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_1976:
	/* 0x1976: cmp    rdx,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 87ULL);
x86_l_197a:
	/* 0x197a: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1980:
	/* 0x1980: lea    eax,[rdx+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_1986:
	/* 0x1986: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_198b:
	/* 0x198b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1991:
	/* 0x1991: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_1994:
	/* 0x1994: cmp    rdx,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 88ULL);
x86_l_1998:
	/* 0x1998: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_199e:
	/* 0x199e: lea    eax,[rdx+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_19a4:
	/* 0x19a4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19a9:
	/* 0x19a9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19af:
	/* 0x19af: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_19b2:
	/* 0x19b2: cmp    rdx,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 89ULL);
x86_l_19b6:
	/* 0x19b6: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_19bc:
	/* 0x19bc: lea    eax,[rdx+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_19c2:
	/* 0x19c2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19c7:
	/* 0x19c7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19cd:
	/* 0x19cd: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_19d0:
	/* 0x19d0: cmp    rdx,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 90ULL);
x86_l_19d4:
	/* 0x19d4: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_19d6:
	/* 0x19d6: lea    eax,[rdx+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_19dc:
	/* 0x19dc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19e1:
	/* 0x19e1: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19e7:
	/* 0x19e7: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_19ea:
	/* 0x19ea: cmp    rdx,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 91ULL);
x86_l_19ee:
	/* 0x19ee: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_19f0:
	/* 0x19f0: lea    eax,[rdx+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_19f6:
	/* 0x19f6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19fb:
	/* 0x19fb: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a01:
	/* 0x1a01: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_1a04:
	/* 0x1a04: cmp    rdx,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 92ULL);
x86_l_1a08:
	/* 0x1a08: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1a0a:
	/* 0x1a0a: lea    eax,[rdx+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_1a10:
	/* 0x1a10: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a15:
	/* 0x1a15: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a1e:
	/* 0x1a1e: cmp    rdx,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 93ULL);
x86_l_1a22:
	/* 0x1a22: je     1a39 <generic_usdt_filter_arg_2+0x1a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a39;
	}
x86_l_1a24:
	/* 0x1a24: add    edx,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_1a2a:
	/* 0x1a2a: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a30:
	/* 0x1a30: movzx  eax,BYTE PTR [r13+rdx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a36:
	/* 0x1a36: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_1a39:
	/* 0x1a39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a3e:
	/* 0x1a3e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a43:
	/* 0x1a43: jmp    31e8 <generic_usdt_filter_arg_2+0x31e8> */
	return 12776ULL;
x86_l_1a48:
	/* 0x1a48: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a4d:
	/* 0x1a4d: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a51:
	/* 0x1a51: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a54:
	/* 0x1a54: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a58:
	/* 0x1a58: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a60:
	/* 0x1a60: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1a67:
	/* 0x1a67: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a6c:
	/* 0x1a6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a71:
	/* 0x1a71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a73:
	/* 0x1a73: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1a76:
	/* 0x1a76: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a79:
	/* 0x1a79: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1a7c:
	/* 0x1a7c: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_1a82:
	/* 0x1a82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a85:
	/* 0x1a85: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_1a8b:
	/* 0x1a8b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a90:
	/* 0x1a90: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1a97:
	/* 0x1a97: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1aa1:
	/* 0x1aa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa3:
	/* 0x1aa3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1aa6:
	/* 0x1aa6: je     31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12790ULL;
	}
x86_l_1aac:
	/* 0x1aac: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_1ab3:
	/* 0x1ab3: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1ab8:
	/* 0x1ab8: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1abc:
	/* 0x1abc: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ac8:
	/* 0x1ac8: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1acc:
	/* 0x1acc: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1acf:
	/* 0x1acf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ad4:
	/* 0x1ad4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad9:
	/* 0x1ad9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1adb:
	/* 0x1adb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ae5:
	/* 0x1ae5: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1ae8:
	/* 0x1ae8: jmp    31e8 <generic_usdt_filter_arg_2+0x31e8> */
	return 12776ULL;
x86_l_1aed:
	/* 0x1aed: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1af5:
	/* 0x1af5: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1afc:
	/* 0x1afc: ja     2c60 <generic_usdt_filter_arg_2+0x2c60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11360ULL;
	}
x86_l_1b02:
	/* 0x1b02: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b06:
	/* 0x1b06: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1b0c:
	/* 0x1b0c: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1b0f:
	/* 0x1b0f: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1b12:
	/* 0x1b12: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1b15:
	/* 0x1b15: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1b18:
	/* 0x1b18: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1b1a:
	/* 0x1b1a: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_1b1e:
	/* 0x1b1e: je     2b32 <generic_usdt_filter_arg_2+0x2b32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11058ULL;
	}
x86_l_1b24:
	/* 0x1b24: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1b26:
	/* 0x1b26: jne    2b32 <generic_usdt_filter_arg_2+0x2b32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11058ULL;
	}
x86_l_1b2c:
	/* 0x1b2c: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_1b2f:
	/* 0x1b2f: jmp    2b4a <generic_usdt_filter_arg_2+0x2b4a> */
	return 11082ULL;
x86_l_1b34:
	/* 0x1b34: movzx  eax,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b38:
	/* 0x1b38: mov    WORD PTR [rsp+0x76],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_1b3d:
	/* 0x1b3d: movzx  eax,WORD PTR [r8+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1b42:
	/* 0x1b42: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b47:
	/* 0x1b47: mov    rax,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b4b:
	/* 0x1b4b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b50:
	/* 0x1b50: mov    rax,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b54:
	/* 0x1b54: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b59:
	/* 0x1b59: lea    r8,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b5e:
	/* 0x1b5e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b60:
	/* 0x1b60: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b63:
	/* 0x1b63: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b66:
	/* 0x1b66: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1b69:
	/* 0x1b69: jle    1b8d <generic_usdt_filter_arg_2+0x1b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b8d;
	}
x86_l_1b6b:
	/* 0x1b6b: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1b6e:
	/* 0x1b6e: jg     1bb7 <generic_usdt_filter_arg_2+0x1bb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1bb7;
	}
x86_l_1b70:
	/* 0x1b70: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_1b73:
	/* 0x1b73: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b76:
	/* 0x1b76: jb     27f5 <generic_usdt_filter_arg_2+0x27f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10229ULL;
	}
x86_l_1b7c:
	/* 0x1b7c: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_1b7f:
	/* 0x1b7f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b82:
	/* 0x1b82: jb     27ee <generic_usdt_filter_arg_2+0x27ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10222ULL;
	}
x86_l_1b88:
	/* 0x1b88: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_1b8d:
	/* 0x1b8d: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1b90:
	/* 0x1b90: jle    1c00 <generic_usdt_filter_arg_2+0x1c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c00;
	}
x86_l_1b92:
	/* 0x1b92: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1b95:
	/* 0x1b95: jg     27e0 <generic_usdt_filter_arg_2+0x27e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10208ULL;
	}
x86_l_1b9b:
	/* 0x1b9b: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1b9e:
	/* 0x1b9e: je     27ee <generic_usdt_filter_arg_2+0x27ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10222ULL;
	}
x86_l_1ba4:
	/* 0x1ba4: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1ba7:
	/* 0x1ba7: jne    321b <generic_usdt_filter_arg_2+0x321b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12827ULL;
	}
x86_l_1bad:
	/* 0x1bad: movzx  r12d,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1bb2:
	/* 0x1bb2: jmp    2c6d <generic_usdt_filter_arg_2+0x2c6d> */
	return 11373ULL;
x86_l_1bb7:
	/* 0x1bb7: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1bba:
	/* 0x1bba: jg     2804 <generic_usdt_filter_arg_2+0x2804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10244ULL;
	}
x86_l_1bc0:
	/* 0x1bc0: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1bc3:
	/* 0x1bc3: je     283a <generic_usdt_filter_arg_2+0x283a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10298ULL;
	}
x86_l_1bc9:
	/* 0x1bc9: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1bcc:
	/* 0x1bcc: je     2830 <generic_usdt_filter_arg_2+0x2830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10288ULL;
	}
x86_l_1bd2:
	/* 0x1bd2: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_1bd7:
	/* 0x1bd7: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1bda:
	/* 0x1bda: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1bdd:
	/* 0x1bdd: jae    2af8 <generic_usdt_filter_arg_2+0x2af8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11000ULL;
	}
x86_l_1be3:
	/* 0x1be3: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1beb:
	/* 0x1beb: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1bf2:
	/* 0x1bf2: jbe    2b00 <generic_usdt_filter_arg_2+0x2b00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11008ULL;
	}
x86_l_1bf8:
	/* 0x1bf8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bfb:
	/* 0x1bfb: jmp    315e <generic_usdt_filter_arg_2+0x315e> */
	return 12638ULL;
x86_l_1c00:
	/* 0x1c00: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1c03:
	/* 0x1c03: je     283a <generic_usdt_filter_arg_2+0x283a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10298ULL;
	}
x86_l_1c09:
	/* 0x1c09: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1c0c:
	/* 0x1c0c: je     2830 <generic_usdt_filter_arg_2+0x2830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10288ULL;
	}
x86_l_1c12:
	/* 0x1c12: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1c15:
	/* 0x1c15: je     27f5 <generic_usdt_filter_arg_2+0x27f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10229ULL;
	}
x86_l_1c1b:
	/* 0x1c1b: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_1c20:
	/* 0x1c20: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c25:
	/* 0x1c25: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c29:
	/* 0x1c29: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c2c:
	/* 0x1c2c: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c30:
	/* 0x1c30: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c38:
	/* 0x1c38: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1c3f:
	/* 0x1c3f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c44:
	/* 0x1c44: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c49:
	/* 0x1c49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4b:
	/* 0x1c4b: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1c4e:
	/* 0x1c4e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c51:
	/* 0x1c51: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1c54:
	/* 0x1c54: je     315a <generic_usdt_filter_arg_2+0x315a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12634ULL;
	}
x86_l_1c5a:
	/* 0x1c5a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5f:
	/* 0x1c5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c62:
	/* 0x1c62: je     315a <generic_usdt_filter_arg_2+0x315a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12634ULL;
	}
x86_l_1c68:
	/* 0x1c68: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1c6f:
	/* 0x1c6f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c74:
	/* 0x1c74: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 7289ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7289ULL: goto x86_l_1c79;
	case 7291ULL: goto x86_l_1c7b;
	case 7294ULL: goto x86_l_1c7e;
	case 7300ULL: goto x86_l_1c84;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7312ULL: goto x86_l_1c90;
	case 7316ULL: goto x86_l_1c94;
	case 7321ULL: goto x86_l_1c99;
	case 7325ULL: goto x86_l_1c9d;
	case 7328ULL: goto x86_l_1ca0;
	case 7330ULL: goto x86_l_1ca2;
	case 7334ULL: goto x86_l_1ca6;
	case 7339ULL: goto x86_l_1cab;
	case 7343ULL: goto x86_l_1caf;
	case 7346ULL: goto x86_l_1cb2;
	case 7350ULL: goto x86_l_1cb6;
	case 7356ULL: goto x86_l_1cbc;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7372ULL: goto x86_l_1ccc;
	case 7375ULL: goto x86_l_1ccf;
	case 7379ULL: goto x86_l_1cd3;
	case 7385ULL: goto x86_l_1cd9;
	case 7392ULL: goto x86_l_1ce0;
	case 7397ULL: goto x86_l_1ce5;
	case 7401ULL: goto x86_l_1ce9;
	case 7404ULL: goto x86_l_1cec;
	case 7408ULL: goto x86_l_1cf0;
	case 7414ULL: goto x86_l_1cf6;
	case 7421ULL: goto x86_l_1cfd;
	case 7426ULL: goto x86_l_1d02;
	case 7430ULL: goto x86_l_1d06;
	case 7433ULL: goto x86_l_1d09;
	case 7437ULL: goto x86_l_1d0d;
	case 7443ULL: goto x86_l_1d13;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7459ULL: goto x86_l_1d23;
	case 7462ULL: goto x86_l_1d26;
	case 7466ULL: goto x86_l_1d2a;
	case 7472ULL: goto x86_l_1d30;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7488ULL: goto x86_l_1d40;
	case 7491ULL: goto x86_l_1d43;
	case 7495ULL: goto x86_l_1d47;
	case 7501ULL: goto x86_l_1d4d;
	case 7508ULL: goto x86_l_1d54;
	case 7513ULL: goto x86_l_1d59;
	case 7517ULL: goto x86_l_1d5d;
	case 7520ULL: goto x86_l_1d60;
	case 7524ULL: goto x86_l_1d64;
	case 7530ULL: goto x86_l_1d6a;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7546ULL: goto x86_l_1d7a;
	case 7549ULL: goto x86_l_1d7d;
	case 7553ULL: goto x86_l_1d81;
	case 7559ULL: goto x86_l_1d87;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7575ULL: goto x86_l_1d97;
	case 7578ULL: goto x86_l_1d9a;
	case 7582ULL: goto x86_l_1d9e;
	case 7588ULL: goto x86_l_1da4;
	case 7595ULL: goto x86_l_1dab;
	case 7600ULL: goto x86_l_1db0;
	case 7604ULL: goto x86_l_1db4;
	case 7607ULL: goto x86_l_1db7;
	case 7611ULL: goto x86_l_1dbb;
	case 7617ULL: goto x86_l_1dc1;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7633ULL: goto x86_l_1dd1;
	case 7636ULL: goto x86_l_1dd4;
	case 7640ULL: goto x86_l_1dd8;
	case 7646ULL: goto x86_l_1dde;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7662ULL: goto x86_l_1dee;
	case 7665ULL: goto x86_l_1df1;
	case 7669ULL: goto x86_l_1df5;
	case 7675ULL: goto x86_l_1dfb;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7691ULL: goto x86_l_1e0b;
	case 7694ULL: goto x86_l_1e0e;
	case 7698ULL: goto x86_l_1e12;
	case 7704ULL: goto x86_l_1e18;
	case 7711ULL: goto x86_l_1e1f;
	case 7716ULL: goto x86_l_1e24;
	case 7720ULL: goto x86_l_1e28;
	case 7723ULL: goto x86_l_1e2b;
	case 7727ULL: goto x86_l_1e2f;
	case 7733ULL: goto x86_l_1e35;
	case 7740ULL: goto x86_l_1e3c;
	case 7745ULL: goto x86_l_1e41;
	case 7749ULL: goto x86_l_1e45;
	case 7752ULL: goto x86_l_1e48;
	case 7756ULL: goto x86_l_1e4c;
	case 7762ULL: goto x86_l_1e52;
	case 7769ULL: goto x86_l_1e59;
	case 7774ULL: goto x86_l_1e5e;
	case 7778ULL: goto x86_l_1e62;
	case 7781ULL: goto x86_l_1e65;
	case 7785ULL: goto x86_l_1e69;
	case 7791ULL: goto x86_l_1e6f;
	case 7798ULL: goto x86_l_1e76;
	case 7803ULL: goto x86_l_1e7b;
	case 7807ULL: goto x86_l_1e7f;
	case 7810ULL: goto x86_l_1e82;
	case 7814ULL: goto x86_l_1e86;
	case 7820ULL: goto x86_l_1e8c;
	case 7827ULL: goto x86_l_1e93;
	case 7832ULL: goto x86_l_1e98;
	case 7836ULL: goto x86_l_1e9c;
	case 7839ULL: goto x86_l_1e9f;
	case 7843ULL: goto x86_l_1ea3;
	case 7849ULL: goto x86_l_1ea9;
	case 7856ULL: goto x86_l_1eb0;
	case 7861ULL: goto x86_l_1eb5;
	case 7865ULL: goto x86_l_1eb9;
	case 7868ULL: goto x86_l_1ebc;
	case 7872ULL: goto x86_l_1ec0;
	case 7878ULL: goto x86_l_1ec6;
	case 7885ULL: goto x86_l_1ecd;
	case 7890ULL: goto x86_l_1ed2;
	case 7894ULL: goto x86_l_1ed6;
	case 7897ULL: goto x86_l_1ed9;
	case 7901ULL: goto x86_l_1edd;
	case 7907ULL: goto x86_l_1ee3;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7923ULL: goto x86_l_1ef3;
	case 7926ULL: goto x86_l_1ef6;
	case 7930ULL: goto x86_l_1efa;
	case 7936ULL: goto x86_l_1f00;
	case 7943ULL: goto x86_l_1f07;
	case 7948ULL: goto x86_l_1f0c;
	case 7952ULL: goto x86_l_1f10;
	case 7955ULL: goto x86_l_1f13;
	case 7959ULL: goto x86_l_1f17;
	case 7965ULL: goto x86_l_1f1d;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7981ULL: goto x86_l_1f2d;
	case 7984ULL: goto x86_l_1f30;
	case 7988ULL: goto x86_l_1f34;
	case 7994ULL: goto x86_l_1f3a;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8010ULL: goto x86_l_1f4a;
	case 8013ULL: goto x86_l_1f4d;
	case 8017ULL: goto x86_l_1f51;
	case 8023ULL: goto x86_l_1f57;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8039ULL: goto x86_l_1f67;
	case 8042ULL: goto x86_l_1f6a;
	case 8046ULL: goto x86_l_1f6e;
	case 8052ULL: goto x86_l_1f74;
	case 8059ULL: goto x86_l_1f7b;
	case 8064ULL: goto x86_l_1f80;
	case 8068ULL: goto x86_l_1f84;
	case 8071ULL: goto x86_l_1f87;
	case 8075ULL: goto x86_l_1f8b;
	case 8081ULL: goto x86_l_1f91;
	case 8088ULL: goto x86_l_1f98;
	case 8093ULL: goto x86_l_1f9d;
	case 8097ULL: goto x86_l_1fa1;
	case 8100ULL: goto x86_l_1fa4;
	case 8104ULL: goto x86_l_1fa8;
	case 8110ULL: goto x86_l_1fae;
	case 8117ULL: goto x86_l_1fb5;
	case 8122ULL: goto x86_l_1fba;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8133ULL: goto x86_l_1fc5;
	case 8139ULL: goto x86_l_1fcb;
	case 8146ULL: goto x86_l_1fd2;
	case 8151ULL: goto x86_l_1fd7;
	case 8155ULL: goto x86_l_1fdb;
	case 8158ULL: goto x86_l_1fde;
	case 8162ULL: goto x86_l_1fe2;
	case 8168ULL: goto x86_l_1fe8;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8184ULL: goto x86_l_1ff8;
	case 8187ULL: goto x86_l_1ffb;
	case 8191ULL: goto x86_l_1fff;
	case 8197ULL: goto x86_l_2005;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8213ULL: goto x86_l_2015;
	case 8216ULL: goto x86_l_2018;
	case 8220ULL: goto x86_l_201c;
	case 8226ULL: goto x86_l_2022;
	case 8233ULL: goto x86_l_2029;
	case 8238ULL: goto x86_l_202e;
	case 8242ULL: goto x86_l_2032;
	case 8245ULL: goto x86_l_2035;
	case 8249ULL: goto x86_l_2039;
	case 8255ULL: goto x86_l_203f;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8271ULL: goto x86_l_204f;
	case 8274ULL: goto x86_l_2052;
	case 8278ULL: goto x86_l_2056;
	case 8284ULL: goto x86_l_205c;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8300ULL: goto x86_l_206c;
	case 8303ULL: goto x86_l_206f;
	case 8307ULL: goto x86_l_2073;
	case 8313ULL: goto x86_l_2079;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8329ULL: goto x86_l_2089;
	case 8332ULL: goto x86_l_208c;
	case 8336ULL: goto x86_l_2090;
	case 8342ULL: goto x86_l_2096;
	case 8349ULL: goto x86_l_209d;
	case 8354ULL: goto x86_l_20a2;
	case 8358ULL: goto x86_l_20a6;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8378ULL: goto x86_l_20ba;
	case 8383ULL: goto x86_l_20bf;
	case 8387ULL: goto x86_l_20c3;
	case 8390ULL: goto x86_l_20c6;
	case 8394ULL: goto x86_l_20ca;
	case 8400ULL: goto x86_l_20d0;
	case 8407ULL: goto x86_l_20d7;
	case 8412ULL: goto x86_l_20dc;
	case 8416ULL: goto x86_l_20e0;
	case 8419ULL: goto x86_l_20e3;
	case 8423ULL: goto x86_l_20e7;
	case 8429ULL: goto x86_l_20ed;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8445ULL: goto x86_l_20fd;
	case 8448ULL: goto x86_l_2100;
	case 8452ULL: goto x86_l_2104;
	case 8458ULL: goto x86_l_210a;
	case 8465ULL: goto x86_l_2111;
	case 8470ULL: goto x86_l_2116;
	case 8474ULL: goto x86_l_211a;
	case 8477ULL: goto x86_l_211d;
	case 8481ULL: goto x86_l_2121;
	case 8487ULL: goto x86_l_2127;
	case 8494ULL: goto x86_l_212e;
	case 8499ULL: goto x86_l_2133;
	case 8503ULL: goto x86_l_2137;
	case 8506ULL: goto x86_l_213a;
	case 8510ULL: goto x86_l_213e;
	case 8516ULL: goto x86_l_2144;
	case 8523ULL: goto x86_l_214b;
	case 8528ULL: goto x86_l_2150;
	case 8532ULL: goto x86_l_2154;
	case 8535ULL: goto x86_l_2157;
	case 8539ULL: goto x86_l_215b;
	case 8545ULL: goto x86_l_2161;
	case 8552ULL: goto x86_l_2168;
	case 8557ULL: goto x86_l_216d;
	case 8561ULL: goto x86_l_2171;
	case 8564ULL: goto x86_l_2174;
	case 8568ULL: goto x86_l_2178;
	case 8574ULL: goto x86_l_217e;
	case 8581ULL: goto x86_l_2185;
	case 8586ULL: goto x86_l_218a;
	case 8590ULL: goto x86_l_218e;
	case 8593ULL: goto x86_l_2191;
	case 8597ULL: goto x86_l_2195;
	case 8603ULL: goto x86_l_219b;
	case 8610ULL: goto x86_l_21a2;
	case 8615ULL: goto x86_l_21a7;
	case 8619ULL: goto x86_l_21ab;
	case 8622ULL: goto x86_l_21ae;
	case 8626ULL: goto x86_l_21b2;
	case 8632ULL: goto x86_l_21b8;
	case 8639ULL: goto x86_l_21bf;
	case 8644ULL: goto x86_l_21c4;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8655ULL: goto x86_l_21cf;
	case 8661ULL: goto x86_l_21d5;
	case 8668ULL: goto x86_l_21dc;
	case 8673ULL: goto x86_l_21e1;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8684ULL: goto x86_l_21ec;
	case 8690ULL: goto x86_l_21f2;
	case 8697ULL: goto x86_l_21f9;
	case 8702ULL: goto x86_l_21fe;
	case 8706ULL: goto x86_l_2202;
	case 8709ULL: goto x86_l_2205;
	case 8713ULL: goto x86_l_2209;
	case 8719ULL: goto x86_l_220f;
	case 8726ULL: goto x86_l_2216;
	case 8731ULL: goto x86_l_221b;
	case 8735ULL: goto x86_l_221f;
	case 8738ULL: goto x86_l_2222;
	case 8742ULL: goto x86_l_2226;
	case 8748ULL: goto x86_l_222c;
	case 8755ULL: goto x86_l_2233;
	case 8760ULL: goto x86_l_2238;
	case 8764ULL: goto x86_l_223c;
	case 8767ULL: goto x86_l_223f;
	case 8771ULL: goto x86_l_2243;
	case 8777ULL: goto x86_l_2249;
	case 8784ULL: goto x86_l_2250;
	case 8789ULL: goto x86_l_2255;
	case 8793ULL: goto x86_l_2259;
	case 8796ULL: goto x86_l_225c;
	case 8800ULL: goto x86_l_2260;
	case 8806ULL: goto x86_l_2266;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8822ULL: goto x86_l_2276;
	case 8825ULL: goto x86_l_2279;
	case 8829ULL: goto x86_l_227d;
	case 8835ULL: goto x86_l_2283;
	case 8842ULL: goto x86_l_228a;
	case 8847ULL: goto x86_l_228f;
	case 8851ULL: goto x86_l_2293;
	case 8854ULL: goto x86_l_2296;
	case 8858ULL: goto x86_l_229a;
	case 8864ULL: goto x86_l_22a0;
	case 8871ULL: goto x86_l_22a7;
	case 8876ULL: goto x86_l_22ac;
	case 8880ULL: goto x86_l_22b0;
	case 8883ULL: goto x86_l_22b3;
	case 8887ULL: goto x86_l_22b7;
	case 8893ULL: goto x86_l_22bd;
	case 8900ULL: goto x86_l_22c4;
	case 8905ULL: goto x86_l_22c9;
	case 8909ULL: goto x86_l_22cd;
	case 8912ULL: goto x86_l_22d0;
	case 8916ULL: goto x86_l_22d4;
	case 8922ULL: goto x86_l_22da;
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8938ULL: goto x86_l_22ea;
	case 8941ULL: goto x86_l_22ed;
	case 8945ULL: goto x86_l_22f1;
	case 8951ULL: goto x86_l_22f7;
	case 8958ULL: goto x86_l_22fe;
	case 8963ULL: goto x86_l_2303;
	case 8967ULL: goto x86_l_2307;
	case 8970ULL: goto x86_l_230a;
	case 8974ULL: goto x86_l_230e;
	case 8980ULL: goto x86_l_2314;
	case 8987ULL: goto x86_l_231b;
	case 8992ULL: goto x86_l_2320;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9003ULL: goto x86_l_232b;
	case 9009ULL: goto x86_l_2331;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9025ULL: goto x86_l_2341;
	case 9028ULL: goto x86_l_2344;
	case 9032ULL: goto x86_l_2348;
	case 9038ULL: goto x86_l_234e;
	case 9045ULL: goto x86_l_2355;
	case 9050ULL: goto x86_l_235a;
	case 9054ULL: goto x86_l_235e;
	case 9057ULL: goto x86_l_2361;
	case 9061ULL: goto x86_l_2365;
	case 9067ULL: goto x86_l_236b;
	case 9074ULL: goto x86_l_2372;
	case 9079ULL: goto x86_l_2377;
	case 9083ULL: goto x86_l_237b;
	case 9086ULL: goto x86_l_237e;
	case 9090ULL: goto x86_l_2382;
	case 9096ULL: goto x86_l_2388;
	case 9103ULL: goto x86_l_238f;
	case 9108ULL: goto x86_l_2394;
	case 9112ULL: goto x86_l_2398;
	case 9115ULL: goto x86_l_239b;
	case 9119ULL: goto x86_l_239f;
	case 9125ULL: goto x86_l_23a5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c79:
	/* 0x1c79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7b:
	/* 0x1c7b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c7e:
	/* 0x1c7e: je     3157 <generic_usdt_filter_arg_2+0x3157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12631ULL;
	}
x86_l_1c84:
	/* 0x1c84: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1c87:
	/* 0x1c87: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c8c:
	/* 0x1c8c: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1c90:
	/* 0x1c90: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_1c94:
	/* 0x1c94: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_1c99:
	/* 0x1c99: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1c9d:
	/* 0x1c9d: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1ca0:
	/* 0x1ca0: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca2:
	/* 0x1ca2: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1ca6:
	/* 0x1ca6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cab:
	/* 0x1cab: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1caf:
	/* 0x1caf: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cb2:
	/* 0x1cb2: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_1cb6:
	/* 0x1cb6: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1cbc:
	/* 0x1cbc: lea    eax,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_1cc3:
	/* 0x1cc3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cc8:
	/* 0x1cc8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ccc:
	/* 0x1ccc: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1ccf:
	/* 0x1ccf: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_1cd3:
	/* 0x1cd3: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1cd9:
	/* 0x1cd9: lea    eax,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_1ce0:
	/* 0x1ce0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ce5:
	/* 0x1ce5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1cec:
	/* 0x1cec: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_1cf0:
	/* 0x1cf0: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1cf6:
	/* 0x1cf6: lea    eax,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_1cfd:
	/* 0x1cfd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d02:
	/* 0x1d02: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d06:
	/* 0x1d06: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1d09:
	/* 0x1d09: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_1d0d:
	/* 0x1d0d: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1d13:
	/* 0x1d13: lea    eax,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_1d1a:
	/* 0x1d1a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d1f:
	/* 0x1d1f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d23:
	/* 0x1d23: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d26:
	/* 0x1d26: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_1d2a:
	/* 0x1d2a: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1d30:
	/* 0x1d30: lea    eax,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_1d37:
	/* 0x1d37: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d3c:
	/* 0x1d3c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d40:
	/* 0x1d40: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1d43:
	/* 0x1d43: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_1d47:
	/* 0x1d47: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1d4d:
	/* 0x1d4d: lea    eax,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_1d54:
	/* 0x1d54: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d59:
	/* 0x1d59: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d5d:
	/* 0x1d5d: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1d60:
	/* 0x1d60: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_1d64:
	/* 0x1d64: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1d6a:
	/* 0x1d6a: lea    eax,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_1d71:
	/* 0x1d71: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d76:
	/* 0x1d76: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1d7d:
	/* 0x1d7d: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_1d81:
	/* 0x1d81: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1d87:
	/* 0x1d87: lea    eax,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_1d8e:
	/* 0x1d8e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d93:
	/* 0x1d93: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d97:
	/* 0x1d97: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d9a:
	/* 0x1d9a: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1d9e:
	/* 0x1d9e: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1da4:
	/* 0x1da4: lea    eax,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1dab:
	/* 0x1dab: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1db0:
	/* 0x1db0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1db4:
	/* 0x1db4: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1db7:
	/* 0x1db7: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_1dbb:
	/* 0x1dbb: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1dc1:
	/* 0x1dc1: lea    eax,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1dc8:
	/* 0x1dc8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dcd:
	/* 0x1dcd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dd1:
	/* 0x1dd1: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1dd4:
	/* 0x1dd4: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_1dd8:
	/* 0x1dd8: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1dde:
	/* 0x1dde: lea    eax,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_1de5:
	/* 0x1de5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dea:
	/* 0x1dea: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dee:
	/* 0x1dee: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1df1:
	/* 0x1df1: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_1df5:
	/* 0x1df5: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1dfb:
	/* 0x1dfb: lea    eax,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_1e02:
	/* 0x1e02: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e07:
	/* 0x1e07: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e0b:
	/* 0x1e0b: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e0e:
	/* 0x1e0e: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_1e12:
	/* 0x1e12: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1e18:
	/* 0x1e18: lea    eax,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_1e1f:
	/* 0x1e1f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e24:
	/* 0x1e24: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e28:
	/* 0x1e28: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_1e2b:
	/* 0x1e2b: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_1e2f:
	/* 0x1e2f: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1e35:
	/* 0x1e35: lea    eax,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1e3c:
	/* 0x1e3c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e41:
	/* 0x1e41: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e45:
	/* 0x1e45: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1e48:
	/* 0x1e48: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_1e4c:
	/* 0x1e4c: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1e52:
	/* 0x1e52: lea    eax,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1e59:
	/* 0x1e59: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e5e:
	/* 0x1e5e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e62:
	/* 0x1e62: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1e65:
	/* 0x1e65: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_1e69:
	/* 0x1e69: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1e6f:
	/* 0x1e6f: lea    eax,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_1e76:
	/* 0x1e76: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e7b:
	/* 0x1e7b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e7f:
	/* 0x1e7f: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e82:
	/* 0x1e82: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_1e86:
	/* 0x1e86: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1e8c:
	/* 0x1e8c: lea    eax,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1e93:
	/* 0x1e93: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e98:
	/* 0x1e98: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e9c:
	/* 0x1e9c: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1e9f:
	/* 0x1e9f: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_1ea3:
	/* 0x1ea3: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1ea9:
	/* 0x1ea9: lea    eax,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1eb0:
	/* 0x1eb0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1eb5:
	/* 0x1eb5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1eb9:
	/* 0x1eb9: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1ebc:
	/* 0x1ebc: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_1ec0:
	/* 0x1ec0: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1ec6:
	/* 0x1ec6: lea    eax,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1ecd:
	/* 0x1ecd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ed2:
	/* 0x1ed2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ed6:
	/* 0x1ed6: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_1ed9:
	/* 0x1ed9: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_1edd:
	/* 0x1edd: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1ee3:
	/* 0x1ee3: lea    eax,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_1eea:
	/* 0x1eea: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1eef:
	/* 0x1eef: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ef3:
	/* 0x1ef3: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ef6:
	/* 0x1ef6: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_1efa:
	/* 0x1efa: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1f00:
	/* 0x1f00: lea    eax,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_1f07:
	/* 0x1f07: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f0c:
	/* 0x1f0c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f10:
	/* 0x1f10: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_1f13:
	/* 0x1f13: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_1f17:
	/* 0x1f17: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1f1d:
	/* 0x1f1d: lea    eax,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_1f24:
	/* 0x1f24: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f29:
	/* 0x1f29: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1f30:
	/* 0x1f30: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_1f34:
	/* 0x1f34: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1f3a:
	/* 0x1f3a: lea    eax,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_1f41:
	/* 0x1f41: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f46:
	/* 0x1f46: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_1f4d:
	/* 0x1f4d: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_1f51:
	/* 0x1f51: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1f57:
	/* 0x1f57: lea    eax,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_1f5e:
	/* 0x1f5e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f63:
	/* 0x1f63: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f67:
	/* 0x1f67: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f6a:
	/* 0x1f6a: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_1f6e:
	/* 0x1f6e: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1f74:
	/* 0x1f74: lea    eax,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_1f7b:
	/* 0x1f7b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f80:
	/* 0x1f80: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f84:
	/* 0x1f84: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1f87:
	/* 0x1f87: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_1f8b:
	/* 0x1f8b: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1f91:
	/* 0x1f91: lea    eax,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1f98:
	/* 0x1f98: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f9d:
	/* 0x1f9d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fa1:
	/* 0x1fa1: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1fa4:
	/* 0x1fa4: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_1fa8:
	/* 0x1fa8: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1fae:
	/* 0x1fae: lea    eax,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_1fb5:
	/* 0x1fb5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fba:
	/* 0x1fba: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fbe:
	/* 0x1fbe: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_1fc1:
	/* 0x1fc1: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_1fc5:
	/* 0x1fc5: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1fcb:
	/* 0x1fcb: lea    eax,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_1fd2:
	/* 0x1fd2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fd7:
	/* 0x1fd7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fdb:
	/* 0x1fdb: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fde:
	/* 0x1fde: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_1fe2:
	/* 0x1fe2: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_1fe8:
	/* 0x1fe8: lea    eax,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_1fef:
	/* 0x1fef: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ff4:
	/* 0x1ff4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ff8:
	/* 0x1ff8: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_1ffb:
	/* 0x1ffb: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_1fff:
	/* 0x1fff: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2005:
	/* 0x2005: lea    eax,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_200c:
	/* 0x200c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2011:
	/* 0x2011: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2015:
	/* 0x2015: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2018:
	/* 0x2018: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_201c:
	/* 0x201c: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2022:
	/* 0x2022: lea    eax,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_2029:
	/* 0x2029: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_202e:
	/* 0x202e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2032:
	/* 0x2032: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_2035:
	/* 0x2035: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_2039:
	/* 0x2039: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_203f:
	/* 0x203f: lea    eax,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_2046:
	/* 0x2046: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_204b:
	/* 0x204b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_204f:
	/* 0x204f: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2052:
	/* 0x2052: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_2056:
	/* 0x2056: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_205c:
	/* 0x205c: lea    eax,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_2063:
	/* 0x2063: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2068:
	/* 0x2068: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_206c:
	/* 0x206c: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_206f:
	/* 0x206f: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_2073:
	/* 0x2073: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2079:
	/* 0x2079: lea    eax,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_2080:
	/* 0x2080: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2085:
	/* 0x2085: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2089:
	/* 0x2089: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_208c:
	/* 0x208c: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_2090:
	/* 0x2090: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2096:
	/* 0x2096: lea    eax,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_209d:
	/* 0x209d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20a2:
	/* 0x20a2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20a6:
	/* 0x20a6: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_20a9:
	/* 0x20a9: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_20ad:
	/* 0x20ad: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_20b3:
	/* 0x20b3: lea    eax,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_20ba:
	/* 0x20ba: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20bf:
	/* 0x20bf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20c3:
	/* 0x20c3: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20c6:
	/* 0x20c6: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_20ca:
	/* 0x20ca: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_20d0:
	/* 0x20d0: lea    eax,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_20d7:
	/* 0x20d7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20dc:
	/* 0x20dc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20e0:
	/* 0x20e0: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_20e3:
	/* 0x20e3: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_20e7:
	/* 0x20e7: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_20ed:
	/* 0x20ed: lea    eax,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_20f4:
	/* 0x20f4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20f9:
	/* 0x20f9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20fd:
	/* 0x20fd: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2100:
	/* 0x2100: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_2104:
	/* 0x2104: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_210a:
	/* 0x210a: lea    eax,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_2111:
	/* 0x2111: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2116:
	/* 0x2116: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_211a:
	/* 0x211a: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_211d:
	/* 0x211d: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_2121:
	/* 0x2121: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2127:
	/* 0x2127: lea    eax,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_212e:
	/* 0x212e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2133:
	/* 0x2133: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2137:
	/* 0x2137: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_213a:
	/* 0x213a: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_213e:
	/* 0x213e: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2144:
	/* 0x2144: lea    eax,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_214b:
	/* 0x214b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2150:
	/* 0x2150: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2154:
	/* 0x2154: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_2157:
	/* 0x2157: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_215b:
	/* 0x215b: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2161:
	/* 0x2161: lea    eax,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_2168:
	/* 0x2168: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_216d:
	/* 0x216d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2171:
	/* 0x2171: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_2174:
	/* 0x2174: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_2178:
	/* 0x2178: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_217e:
	/* 0x217e: lea    eax,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_2185:
	/* 0x2185: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_218a:
	/* 0x218a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_218e:
	/* 0x218e: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_2191:
	/* 0x2191: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_2195:
	/* 0x2195: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_219b:
	/* 0x219b: lea    eax,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_21a2:
	/* 0x21a2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21a7:
	/* 0x21a7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21ab:
	/* 0x21ab: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ae:
	/* 0x21ae: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_21b2:
	/* 0x21b2: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_21b8:
	/* 0x21b8: lea    eax,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_21bf:
	/* 0x21bf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21c4:
	/* 0x21c4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21c8:
	/* 0x21c8: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_21cb:
	/* 0x21cb: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_21cf:
	/* 0x21cf: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_21d5:
	/* 0x21d5: lea    eax,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_21dc:
	/* 0x21dc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21e1:
	/* 0x21e1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21e5:
	/* 0x21e5: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_21e8:
	/* 0x21e8: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_21ec:
	/* 0x21ec: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_21f2:
	/* 0x21f2: lea    eax,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_21f9:
	/* 0x21f9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21fe:
	/* 0x21fe: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2202:
	/* 0x2202: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_2205:
	/* 0x2205: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_2209:
	/* 0x2209: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_220f:
	/* 0x220f: lea    eax,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_2216:
	/* 0x2216: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_221b:
	/* 0x221b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_221f:
	/* 0x221f: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2222:
	/* 0x2222: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_2226:
	/* 0x2226: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_222c:
	/* 0x222c: lea    eax,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_2233:
	/* 0x2233: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2238:
	/* 0x2238: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_223c:
	/* 0x223c: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_223f:
	/* 0x223f: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_2243:
	/* 0x2243: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2249:
	/* 0x2249: lea    eax,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_2250:
	/* 0x2250: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2255:
	/* 0x2255: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2259:
	/* 0x2259: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_225c:
	/* 0x225c: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_2260:
	/* 0x2260: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2266:
	/* 0x2266: lea    eax,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_226d:
	/* 0x226d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2272:
	/* 0x2272: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2276:
	/* 0x2276: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_2279:
	/* 0x2279: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_227d:
	/* 0x227d: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2283:
	/* 0x2283: lea    eax,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_228a:
	/* 0x228a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_228f:
	/* 0x228f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2293:
	/* 0x2293: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2296:
	/* 0x2296: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_229a:
	/* 0x229a: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_22a0:
	/* 0x22a0: lea    eax,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_22a7:
	/* 0x22a7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22ac:
	/* 0x22ac: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22b0:
	/* 0x22b0: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_22b3:
	/* 0x22b3: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_22b7:
	/* 0x22b7: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_22bd:
	/* 0x22bd: lea    eax,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_22c4:
	/* 0x22c4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22c9:
	/* 0x22c9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22cd:
	/* 0x22cd: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_22d0:
	/* 0x22d0: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_22d4:
	/* 0x22d4: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_22da:
	/* 0x22da: lea    eax,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_22e1:
	/* 0x22e1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22e6:
	/* 0x22e6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22ea:
	/* 0x22ea: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_22ed:
	/* 0x22ed: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_22f1:
	/* 0x22f1: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_22f7:
	/* 0x22f7: lea    eax,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_22fe:
	/* 0x22fe: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2303:
	/* 0x2303: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2307:
	/* 0x2307: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_230a:
	/* 0x230a: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_230e:
	/* 0x230e: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2314:
	/* 0x2314: lea    eax,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_231b:
	/* 0x231b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2320:
	/* 0x2320: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2324:
	/* 0x2324: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_2327:
	/* 0x2327: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_232b:
	/* 0x232b: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2331:
	/* 0x2331: lea    eax,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_2338:
	/* 0x2338: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_233d:
	/* 0x233d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2341:
	/* 0x2341: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_2344:
	/* 0x2344: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_2348:
	/* 0x2348: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_234e:
	/* 0x234e: lea    eax,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_2355:
	/* 0x2355: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_235a:
	/* 0x235a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_235e:
	/* 0x235e: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_2361:
	/* 0x2361: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_2365:
	/* 0x2365: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_236b:
	/* 0x236b: lea    eax,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_2372:
	/* 0x2372: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2377:
	/* 0x2377: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_237b:
	/* 0x237b: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_237e:
	/* 0x237e: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_2382:
	/* 0x2382: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_2388:
	/* 0x2388: lea    eax,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_238f:
	/* 0x238f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2394:
	/* 0x2394: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2398:
	/* 0x2398: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_239b:
	/* 0x239b: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_239f:
	/* 0x239f: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_23a5:
	/* 0x23a5: lea    eax,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
	return 9132ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9141ULL: goto x86_l_23b5;
	case 9144ULL: goto x86_l_23b8;
	case 9148ULL: goto x86_l_23bc;
	case 9154ULL: goto x86_l_23c2;
	case 9161ULL: goto x86_l_23c9;
	case 9166ULL: goto x86_l_23ce;
	case 9170ULL: goto x86_l_23d2;
	case 9173ULL: goto x86_l_23d5;
	case 9177ULL: goto x86_l_23d9;
	case 9183ULL: goto x86_l_23df;
	case 9190ULL: goto x86_l_23e6;
	case 9195ULL: goto x86_l_23eb;
	case 9199ULL: goto x86_l_23ef;
	case 9202ULL: goto x86_l_23f2;
	case 9206ULL: goto x86_l_23f6;
	case 9212ULL: goto x86_l_23fc;
	case 9219ULL: goto x86_l_2403;
	case 9224ULL: goto x86_l_2408;
	case 9228ULL: goto x86_l_240c;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9241ULL: goto x86_l_2419;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9257ULL: goto x86_l_2429;
	case 9260ULL: goto x86_l_242c;
	case 9264ULL: goto x86_l_2430;
	case 9270ULL: goto x86_l_2436;
	case 9277ULL: goto x86_l_243d;
	case 9282ULL: goto x86_l_2442;
	case 9286ULL: goto x86_l_2446;
	case 9289ULL: goto x86_l_2449;
	case 9293ULL: goto x86_l_244d;
	case 9299ULL: goto x86_l_2453;
	case 9306ULL: goto x86_l_245a;
	case 9311ULL: goto x86_l_245f;
	case 9315ULL: goto x86_l_2463;
	case 9318ULL: goto x86_l_2466;
	case 9322ULL: goto x86_l_246a;
	case 9328ULL: goto x86_l_2470;
	case 9335ULL: goto x86_l_2477;
	case 9340ULL: goto x86_l_247c;
	case 9344ULL: goto x86_l_2480;
	case 9347ULL: goto x86_l_2483;
	case 9351ULL: goto x86_l_2487;
	case 9357ULL: goto x86_l_248d;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9380ULL: goto x86_l_24a4;
	case 9386ULL: goto x86_l_24aa;
	case 9393ULL: goto x86_l_24b1;
	case 9398ULL: goto x86_l_24b6;
	case 9402ULL: goto x86_l_24ba;
	case 9405ULL: goto x86_l_24bd;
	case 9409ULL: goto x86_l_24c1;
	case 9415ULL: goto x86_l_24c7;
	case 9422ULL: goto x86_l_24ce;
	case 9427ULL: goto x86_l_24d3;
	case 9431ULL: goto x86_l_24d7;
	case 9434ULL: goto x86_l_24da;
	case 9438ULL: goto x86_l_24de;
	case 9444ULL: goto x86_l_24e4;
	case 9451ULL: goto x86_l_24eb;
	case 9456ULL: goto x86_l_24f0;
	case 9460ULL: goto x86_l_24f4;
	case 9463ULL: goto x86_l_24f7;
	case 9467ULL: goto x86_l_24fb;
	case 9473ULL: goto x86_l_2501;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9489ULL: goto x86_l_2511;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9502ULL: goto x86_l_251e;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9518ULL: goto x86_l_252e;
	case 9521ULL: goto x86_l_2531;
	case 9525ULL: goto x86_l_2535;
	case 9531ULL: goto x86_l_253b;
	case 9538ULL: goto x86_l_2542;
	case 9543ULL: goto x86_l_2547;
	case 9547ULL: goto x86_l_254b;
	case 9550ULL: goto x86_l_254e;
	case 9554ULL: goto x86_l_2552;
	case 9560ULL: goto x86_l_2558;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	case 9576ULL: goto x86_l_2568;
	case 9579ULL: goto x86_l_256b;
	case 9583ULL: goto x86_l_256f;
	case 9589ULL: goto x86_l_2575;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9605ULL: goto x86_l_2585;
	case 9608ULL: goto x86_l_2588;
	case 9612ULL: goto x86_l_258c;
	case 9618ULL: goto x86_l_2592;
	case 9625ULL: goto x86_l_2599;
	case 9630ULL: goto x86_l_259e;
	case 9634ULL: goto x86_l_25a2;
	case 9637ULL: goto x86_l_25a5;
	case 9641ULL: goto x86_l_25a9;
	case 9647ULL: goto x86_l_25af;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	case 9663ULL: goto x86_l_25bf;
	case 9666ULL: goto x86_l_25c2;
	case 9670ULL: goto x86_l_25c6;
	case 9676ULL: goto x86_l_25cc;
	case 9683ULL: goto x86_l_25d3;
	case 9688ULL: goto x86_l_25d8;
	case 9692ULL: goto x86_l_25dc;
	case 9695ULL: goto x86_l_25df;
	case 9699ULL: goto x86_l_25e3;
	case 9705ULL: goto x86_l_25e9;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9721ULL: goto x86_l_25f9;
	case 9724ULL: goto x86_l_25fc;
	case 9728ULL: goto x86_l_2600;
	case 9734ULL: goto x86_l_2606;
	case 9741ULL: goto x86_l_260d;
	case 9746ULL: goto x86_l_2612;
	case 9750ULL: goto x86_l_2616;
	case 9753ULL: goto x86_l_2619;
	case 9757ULL: goto x86_l_261d;
	case 9763ULL: goto x86_l_2623;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9779ULL: goto x86_l_2633;
	case 9782ULL: goto x86_l_2636;
	case 9786ULL: goto x86_l_263a;
	case 9792ULL: goto x86_l_2640;
	case 9799ULL: goto x86_l_2647;
	case 9804ULL: goto x86_l_264c;
	case 9808ULL: goto x86_l_2650;
	case 9811ULL: goto x86_l_2653;
	case 9815ULL: goto x86_l_2657;
	case 9821ULL: goto x86_l_265d;
	case 9828ULL: goto x86_l_2664;
	case 9833ULL: goto x86_l_2669;
	case 9837ULL: goto x86_l_266d;
	case 9840ULL: goto x86_l_2670;
	case 9844ULL: goto x86_l_2674;
	case 9850ULL: goto x86_l_267a;
	case 9857ULL: goto x86_l_2681;
	case 9862ULL: goto x86_l_2686;
	case 9866ULL: goto x86_l_268a;
	case 9869ULL: goto x86_l_268d;
	case 9873ULL: goto x86_l_2691;
	case 9879ULL: goto x86_l_2697;
	case 9886ULL: goto x86_l_269e;
	case 9891ULL: goto x86_l_26a3;
	case 9895ULL: goto x86_l_26a7;
	case 9898ULL: goto x86_l_26aa;
	case 9902ULL: goto x86_l_26ae;
	case 9904ULL: goto x86_l_26b0;
	case 9911ULL: goto x86_l_26b7;
	case 9916ULL: goto x86_l_26bc;
	case 9920ULL: goto x86_l_26c0;
	case 9923ULL: goto x86_l_26c3;
	case 9927ULL: goto x86_l_26c7;
	case 9929ULL: goto x86_l_26c9;
	case 9936ULL: goto x86_l_26d0;
	case 9941ULL: goto x86_l_26d5;
	case 9945ULL: goto x86_l_26d9;
	case 9948ULL: goto x86_l_26dc;
	case 9952ULL: goto x86_l_26e0;
	case 9954ULL: goto x86_l_26e2;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9970ULL: goto x86_l_26f2;
	case 9973ULL: goto x86_l_26f5;
	case 9977ULL: goto x86_l_26f9;
	case 9979ULL: goto x86_l_26fb;
	case 9982ULL: goto x86_l_26fe;
	case 9987ULL: goto x86_l_2703;
	case 9992ULL: goto x86_l_2708;
	case 9996ULL: goto x86_l_270c;
	case 9999ULL: goto x86_l_270f;
	case 10003ULL: goto x86_l_2713;
	case 10005ULL: goto x86_l_2715;
	case 10012ULL: goto x86_l_271c;
	case 10017ULL: goto x86_l_2721;
	case 10021ULL: goto x86_l_2725;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10044ULL: goto x86_l_273c;
	case 10048ULL: goto x86_l_2740;
	case 10051ULL: goto x86_l_2743;
	case 10055ULL: goto x86_l_2747;
	case 10063ULL: goto x86_l_274f;
	case 10070ULL: goto x86_l_2756;
	case 10075ULL: goto x86_l_275b;
	case 10080ULL: goto x86_l_2760;
	case 10082ULL: goto x86_l_2762;
	case 10085ULL: goto x86_l_2765;
	case 10088ULL: goto x86_l_2768;
	case 10091ULL: goto x86_l_276b;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10105ULL: goto x86_l_2779;
	case 10111ULL: goto x86_l_277f;
	case 10118ULL: goto x86_l_2786;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10130ULL: goto x86_l_2792;
	case 10133ULL: goto x86_l_2795;
	case 10139ULL: goto x86_l_279b;
	case 10144ULL: goto x86_l_27a0;
	case 10148ULL: goto x86_l_27a4;
	case 10155ULL: goto x86_l_27ab;
	case 10160ULL: goto x86_l_27b0;
	case 10164ULL: goto x86_l_27b4;
	case 10171ULL: goto x86_l_27bb;
	case 10173ULL: goto x86_l_27bd;
	case 10176ULL: goto x86_l_27c0;
	case 10180ULL: goto x86_l_27c4;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10203ULL: goto x86_l_27db;
	case 10208ULL: goto x86_l_27e0;
	case 10211ULL: goto x86_l_27e3;
	case 10213ULL: goto x86_l_27e5;
	case 10216ULL: goto x86_l_27e8;
	case 10222ULL: goto x86_l_27ee;
	case 10227ULL: goto x86_l_27f3;
	case 10229ULL: goto x86_l_27f5;
	case 10234ULL: goto x86_l_27fa;
	case 10236ULL: goto x86_l_27fc;
	case 10239ULL: goto x86_l_27ff;
	case 10242ULL: goto x86_l_2802;
	case 10244ULL: goto x86_l_2804;
	case 10247ULL: goto x86_l_2807;
	case 10253ULL: goto x86_l_280d;
	case 10256ULL: goto x86_l_2810;
	case 10262ULL: goto x86_l_2816;
	case 10265ULL: goto x86_l_2819;
	case 10271ULL: goto x86_l_281f;
	case 10274ULL: goto x86_l_2822;
	case 10280ULL: goto x86_l_2828;
	case 10283ULL: goto x86_l_282b;
	case 10288ULL: goto x86_l_2830;
	case 10292ULL: goto x86_l_2834;
	case 10296ULL: goto x86_l_2838;
	case 10298ULL: goto x86_l_283a;
	case 10301ULL: goto x86_l_283d;
	case 10305ULL: goto x86_l_2841;
	case 10308ULL: goto x86_l_2844;
	case 10312ULL: goto x86_l_2848;
	case 10314ULL: goto x86_l_284a;
	case 10317ULL: goto x86_l_284d;
	case 10320ULL: goto x86_l_2850;
	case 10322ULL: goto x86_l_2852;
	case 10325ULL: goto x86_l_2855;
	case 10328ULL: goto x86_l_2858;
	case 10330ULL: goto x86_l_285a;
	case 10333ULL: goto x86_l_285d;
	case 10336ULL: goto x86_l_2860;
	case 10342ULL: goto x86_l_2866;
	case 10345ULL: goto x86_l_2869;
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10359ULL: goto x86_l_2877;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10369ULL: goto x86_l_2881;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10383ULL: goto x86_l_288f;
	case 10389ULL: goto x86_l_2895;
	case 10394ULL: goto x86_l_289a;
	case 10397ULL: goto x86_l_289d;
	case 10399ULL: goto x86_l_289f;
	case 10404ULL: goto x86_l_28a4;
	case 10407ULL: goto x86_l_28a7;
	case 10413ULL: goto x86_l_28ad;
	case 10416ULL: goto x86_l_28b0;
	case 10422ULL: goto x86_l_28b6;
	case 10425ULL: goto x86_l_28b9;
	case 10428ULL: goto x86_l_28bc;
	case 10431ULL: goto x86_l_28bf;
	case 10435ULL: goto x86_l_28c3;
	case 10442ULL: goto x86_l_28ca;
	case 10447ULL: goto x86_l_28cf;
	case 10452ULL: goto x86_l_28d4;
	case 10454ULL: goto x86_l_28d6;
	case 10457ULL: goto x86_l_28d9;
	case 10463ULL: goto x86_l_28df;
	case 10466ULL: goto x86_l_28e2;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10484ULL: goto x86_l_28f4;
	case 10487ULL: goto x86_l_28f7;
	case 10490ULL: goto x86_l_28fa;
	case 10496ULL: goto x86_l_2900;
	case 10499ULL: goto x86_l_2903;
	case 10503ULL: goto x86_l_2907;
	case 10507ULL: goto x86_l_290b;
	case 10514ULL: goto x86_l_2912;
	case 10517ULL: goto x86_l_2915;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10529ULL: goto x86_l_2921;
	case 10532ULL: goto x86_l_2924;
	case 10538ULL: goto x86_l_292a;
	case 10541ULL: goto x86_l_292d;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10555ULL: goto x86_l_293b;
	case 10560ULL: goto x86_l_2940;
	case 10562ULL: goto x86_l_2942;
	case 10567ULL: goto x86_l_2947;
	case 10572ULL: goto x86_l_294c;
	case 10577ULL: goto x86_l_2951;
	case 10581ULL: goto x86_l_2955;
	case 10584ULL: goto x86_l_2958;
	case 10588ULL: goto x86_l_295c;
	case 10596ULL: goto x86_l_2964;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10613ULL: goto x86_l_2975;
	case 10615ULL: goto x86_l_2977;
	case 10618ULL: goto x86_l_297a;
	case 10624ULL: goto x86_l_2980;
	case 10630ULL: goto x86_l_2986;
	case 10633ULL: goto x86_l_2989;
	case 10636ULL: goto x86_l_298c;
	case 10642ULL: goto x86_l_2992;
	case 10649ULL: goto x86_l_2999;
	case 10654ULL: goto x86_l_299e;
	case 10659ULL: goto x86_l_29a3;
	case 10661ULL: goto x86_l_29a5;
	case 10664ULL: goto x86_l_29a8;
	case 10670ULL: goto x86_l_29ae;
	case 10675ULL: goto x86_l_29b3;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10689ULL: goto x86_l_29c1;
	case 10696ULL: goto x86_l_29c8;
	case 10698ULL: goto x86_l_29ca;
	case 10701ULL: goto x86_l_29cd;
	case 10705ULL: goto x86_l_29d1;
	case 10708ULL: goto x86_l_29d4;
	case 10713ULL: goto x86_l_29d9;
	case 10718ULL: goto x86_l_29de;
	case 10720ULL: goto x86_l_29e0;
	case 10725ULL: goto x86_l_29e5;
	case 10728ULL: goto x86_l_29e8;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10744ULL: goto x86_l_29f8;
	case 10750ULL: goto x86_l_29fe;
	case 10756ULL: goto x86_l_2a04;
	case 10761ULL: goto x86_l_2a09;
	case 10765ULL: goto x86_l_2a0d;
	case 10768ULL: goto x86_l_2a10;
	case 10774ULL: goto x86_l_2a16;
	case 10777ULL: goto x86_l_2a19;
	case 10780ULL: goto x86_l_2a1c;
	case 10783ULL: goto x86_l_2a1f;
	case 10785ULL: goto x86_l_2a21;
	case 10787ULL: goto x86_l_2a23;
	case 10790ULL: goto x86_l_2a26;
	case 10796ULL: goto x86_l_2a2c;
	case 10798ULL: goto x86_l_2a2e;
	case 10804ULL: goto x86_l_2a34;
	case 10809ULL: goto x86_l_2a39;
	case 10812ULL: goto x86_l_2a3c;
	case 10815ULL: goto x86_l_2a3f;
	case 10820ULL: goto x86_l_2a44;
	case 10824ULL: goto x86_l_2a48;
	case 10829ULL: goto x86_l_2a4d;
	case 10832ULL: goto x86_l_2a50;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23ac:
	/* 0x23ac: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23b1:
	/* 0x23b1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23b5:
	/* 0x23b5: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_23b8:
	/* 0x23b8: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_23bc:
	/* 0x23bc: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_23c2:
	/* 0x23c2: lea    eax,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_23c9:
	/* 0x23c9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23ce:
	/* 0x23ce: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23d2:
	/* 0x23d2: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_23d5:
	/* 0x23d5: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_23d9:
	/* 0x23d9: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_23df:
	/* 0x23df: lea    eax,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_23e6:
	/* 0x23e6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23eb:
	/* 0x23eb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23ef:
	/* 0x23ef: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_23f2:
	/* 0x23f2: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_23f6:
	/* 0x23f6: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_23fc:
	/* 0x23fc: lea    eax,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_2403:
	/* 0x2403: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2408:
	/* 0x2408: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_240c:
	/* 0x240c: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_240f:
	/* 0x240f: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_2413:
	/* 0x2413: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2419:
	/* 0x2419: lea    eax,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_2420:
	/* 0x2420: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2425:
	/* 0x2425: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2429:
	/* 0x2429: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_242c:
	/* 0x242c: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_2430:
	/* 0x2430: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2436:
	/* 0x2436: lea    eax,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_243d:
	/* 0x243d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2442:
	/* 0x2442: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2446:
	/* 0x2446: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_2449:
	/* 0x2449: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_244d:
	/* 0x244d: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2453:
	/* 0x2453: lea    eax,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_245a:
	/* 0x245a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_245f:
	/* 0x245f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2463:
	/* 0x2463: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2466:
	/* 0x2466: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_246a:
	/* 0x246a: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2470:
	/* 0x2470: lea    eax,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_2477:
	/* 0x2477: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_247c:
	/* 0x247c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2480:
	/* 0x2480: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_2483:
	/* 0x2483: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_2487:
	/* 0x2487: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_248d:
	/* 0x248d: lea    eax,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_2494:
	/* 0x2494: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2499:
	/* 0x2499: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_249d:
	/* 0x249d: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_24a0:
	/* 0x24a0: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_24a4:
	/* 0x24a4: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_24aa:
	/* 0x24aa: lea    eax,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_24b1:
	/* 0x24b1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24b6:
	/* 0x24b6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24ba:
	/* 0x24ba: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_24bd:
	/* 0x24bd: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_24c1:
	/* 0x24c1: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_24c7:
	/* 0x24c7: lea    eax,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_24ce:
	/* 0x24ce: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24d3:
	/* 0x24d3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24d7:
	/* 0x24d7: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_24da:
	/* 0x24da: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_24de:
	/* 0x24de: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_24e4:
	/* 0x24e4: lea    eax,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_24eb:
	/* 0x24eb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24f0:
	/* 0x24f0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24f4:
	/* 0x24f4: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_24f7:
	/* 0x24f7: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_24fb:
	/* 0x24fb: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2501:
	/* 0x2501: lea    eax,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_2508:
	/* 0x2508: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_250d:
	/* 0x250d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2511:
	/* 0x2511: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_2514:
	/* 0x2514: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_2518:
	/* 0x2518: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_251e:
	/* 0x251e: lea    eax,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_2525:
	/* 0x2525: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_252a:
	/* 0x252a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_252e:
	/* 0x252e: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_2531:
	/* 0x2531: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_2535:
	/* 0x2535: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_253b:
	/* 0x253b: lea    eax,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_2542:
	/* 0x2542: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2547:
	/* 0x2547: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_254b:
	/* 0x254b: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_254e:
	/* 0x254e: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_2552:
	/* 0x2552: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2558:
	/* 0x2558: lea    eax,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_255f:
	/* 0x255f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2564:
	/* 0x2564: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2568:
	/* 0x2568: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_256b:
	/* 0x256b: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_256f:
	/* 0x256f: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2575:
	/* 0x2575: lea    eax,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_257c:
	/* 0x257c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2581:
	/* 0x2581: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2585:
	/* 0x2585: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_2588:
	/* 0x2588: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_258c:
	/* 0x258c: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2592:
	/* 0x2592: lea    eax,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_2599:
	/* 0x2599: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_259e:
	/* 0x259e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25a2:
	/* 0x25a2: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_25a5:
	/* 0x25a5: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_25a9:
	/* 0x25a9: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_25af:
	/* 0x25af: lea    eax,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_25b6:
	/* 0x25b6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25bb:
	/* 0x25bb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25bf:
	/* 0x25bf: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_25c2:
	/* 0x25c2: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_25c6:
	/* 0x25c6: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_25cc:
	/* 0x25cc: lea    eax,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_25d3:
	/* 0x25d3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25d8:
	/* 0x25d8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25dc:
	/* 0x25dc: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_25df:
	/* 0x25df: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_25e3:
	/* 0x25e3: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_25e9:
	/* 0x25e9: lea    eax,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_25f0:
	/* 0x25f0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25f5:
	/* 0x25f5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25f9:
	/* 0x25f9: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_25fc:
	/* 0x25fc: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_2600:
	/* 0x2600: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2606:
	/* 0x2606: lea    eax,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_260d:
	/* 0x260d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2612:
	/* 0x2612: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2616:
	/* 0x2616: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_2619:
	/* 0x2619: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_261d:
	/* 0x261d: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2623:
	/* 0x2623: lea    eax,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_262a:
	/* 0x262a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_262f:
	/* 0x262f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2633:
	/* 0x2633: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2636:
	/* 0x2636: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_263a:
	/* 0x263a: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2640:
	/* 0x2640: lea    eax,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_2647:
	/* 0x2647: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_264c:
	/* 0x264c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2650:
	/* 0x2650: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_2653:
	/* 0x2653: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_2657:
	/* 0x2657: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_265d:
	/* 0x265d: lea    eax,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_2664:
	/* 0x2664: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2669:
	/* 0x2669: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_266d:
	/* 0x266d: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_2670:
	/* 0x2670: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_2674:
	/* 0x2674: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_267a:
	/* 0x267a: lea    eax,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_2681:
	/* 0x2681: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2686:
	/* 0x2686: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_268a:
	/* 0x268a: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_268d:
	/* 0x268d: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_2691:
	/* 0x2691: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2697:
	/* 0x2697: lea    eax,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_269e:
	/* 0x269e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26a3:
	/* 0x26a3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26a7:
	/* 0x26a7: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_26aa:
	/* 0x26aa: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_26ae:
	/* 0x26ae: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_26b0:
	/* 0x26b0: lea    eax,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_26b7:
	/* 0x26b7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26bc:
	/* 0x26bc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26c0:
	/* 0x26c0: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_26c3:
	/* 0x26c3: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_26c7:
	/* 0x26c7: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_26c9:
	/* 0x26c9: lea    eax,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_26d0:
	/* 0x26d0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26d5:
	/* 0x26d5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26d9:
	/* 0x26d9: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_26dc:
	/* 0x26dc: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_26e0:
	/* 0x26e0: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_26e2:
	/* 0x26e2: lea    eax,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_26e9:
	/* 0x26e9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26ee:
	/* 0x26ee: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26f2:
	/* 0x26f2: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_26f5:
	/* 0x26f5: cmp    r13d,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 92ULL);
x86_l_26f9:
	/* 0x26f9: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_26fb:
	/* 0x26fb: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_26fe:
	/* 0x26fe: add    eax,0xfa3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4003ULL);
x86_l_2703:
	/* 0x2703: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2708:
	/* 0x2708: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_270c:
	/* 0x270c: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_270f:
	/* 0x270f: cmp    r13d,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 93ULL);
x86_l_2713:
	/* 0x2713: je     2728 <generic_usdt_filter_arg_2+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2728;
	}
x86_l_2715:
	/* 0x2715: lea    eax,[r13+0xfa2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4002ULL);
x86_l_271c:
	/* 0x271c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2721:
	/* 0x2721: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2725:
	/* 0x2725: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_2728:
	/* 0x2728: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_272d:
	/* 0x272d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2732:
	/* 0x2732: jmp    3149 <generic_usdt_filter_arg_2+0x3149> */
	return 12617ULL;
x86_l_2737:
	/* 0x2737: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_273c:
	/* 0x273c: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2740:
	/* 0x2740: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2743:
	/* 0x2743: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2747:
	/* 0x2747: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_274f:
	/* 0x274f: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2756:
	/* 0x2756: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_275b:
	/* 0x275b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2760:
	/* 0x2760: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2762:
	/* 0x2762: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2765:
	/* 0x2765: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2768:
	/* 0x2768: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_276b:
	/* 0x276b: je     315a <generic_usdt_filter_arg_2+0x315a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12634ULL;
	}
x86_l_2771:
	/* 0x2771: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2776:
	/* 0x2776: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2779:
	/* 0x2779: je     315a <generic_usdt_filter_arg_2+0x315a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12634ULL;
	}
x86_l_277f:
	/* 0x277f: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2786:
	/* 0x2786: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_278b:
	/* 0x278b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2790:
	/* 0x2790: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2792:
	/* 0x2792: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2795:
	/* 0x2795: je     3157 <generic_usdt_filter_arg_2+0x3157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12631ULL;
	}
x86_l_279b:
	/* 0x279b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27a0:
	/* 0x27a0: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_27a4:
	/* 0x27a4: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_27ab:
	/* 0x27ab: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_27b0:
	/* 0x27b0: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_27b4:
	/* 0x27b4: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_27bb:
	/* 0x27bb: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27bd:
	/* 0x27bd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_27c0:
	/* 0x27c0: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_27c4:
	/* 0x27c4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_27c7:
	/* 0x27c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27cc:
	/* 0x27cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ce:
	/* 0x27ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27d3:
	/* 0x27d3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d8:
	/* 0x27d8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_27db:
	/* 0x27db: jmp    3149 <generic_usdt_filter_arg_2+0x3149> */
	return 12617ULL;
x86_l_27e0:
	/* 0x27e0: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_27e3:
	/* 0x27e3: je     27f5 <generic_usdt_filter_arg_2+0x27f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27f5;
	}
x86_l_27e5:
	/* 0x27e5: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_27e8:
	/* 0x27e8: jne    321b <generic_usdt_filter_arg_2+0x321b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12827ULL;
	}
x86_l_27ee:
	/* 0x27ee: movzx  edi,WORD PTR [r8+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_27f3:
	/* 0x27f3: jmp    27fa <generic_usdt_filter_arg_2+0x27fa> */
	goto x86_l_27fa;
x86_l_27f5:
	/* 0x27f5: movzx  edi,WORD PTR [r8+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_27fa:
	/* 0x27fa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27fc:
	/* 0x27fc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27ff:
	/* 0x27ff: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2802:
	/* 0x2802: jmp    284a <generic_usdt_filter_arg_2+0x284a> */
	goto x86_l_284a;
x86_l_2804:
	/* 0x2804: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2807:
	/* 0x2807: je     2c68 <generic_usdt_filter_arg_2+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_280d:
	/* 0x280d: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_2810:
	/* 0x2810: jne    321b <generic_usdt_filter_arg_2+0x321b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12827ULL;
	}
x86_l_2816:
	/* 0x2816: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2819:
	/* 0x2819: jne    2e34 <generic_usdt_filter_arg_2+0x2e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11828ULL;
	}
x86_l_281f:
	/* 0x281f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2822:
	/* 0x2822: jne    2e41 <generic_usdt_filter_arg_2+0x2e41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11841ULL;
	}
x86_l_2828:
	/* 0x2828: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_282b:
	/* 0x282b: jmp    2e50 <generic_usdt_filter_arg_2+0x2e50> */
	return 11856ULL;
x86_l_2830:
	/* 0x2830: mov    rdx,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2834:
	/* 0x2834: mov    r9,QWORD PTR [r8+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2838:
	/* 0x2838: jmp    2841 <generic_usdt_filter_arg_2+0x2841> */
	goto x86_l_2841;
x86_l_283a:
	/* 0x283a: mov    rdx,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_283d:
	/* 0x283d: mov    r9,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2841:
	/* 0x2841: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2844:
	/* 0x2844: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2848:
	/* 0x2848: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_284a:
	/* 0x284a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_284d:
	/* 0x284d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2850:
	/* 0x2850: jg     2874 <generic_usdt_filter_arg_2+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2874;
	}
x86_l_2852:
	/* 0x2852: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_2855:
	/* 0x2855: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2858:
	/* 0x2858: jb     289f <generic_usdt_filter_arg_2+0x289f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_289f;
	}
x86_l_285a:
	/* 0x285a: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_285d:
	/* 0x285d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2860:
	/* 0x2860: jb     2900 <generic_usdt_filter_arg_2+0x2900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2900;
	}
x86_l_2866:
	/* 0x2866: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2869:
	/* 0x2869: je     2c6d <generic_usdt_filter_arg_2+0x2c6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11373ULL;
	}
x86_l_286f:
	/* 0x286f: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_2874:
	/* 0x2874: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2877:
	/* 0x2877: ja     28f4 <generic_usdt_filter_arg_2+0x28f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28f4;
	}
x86_l_2879:
	/* 0x2879: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_287e:
	/* 0x287e: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2881:
	/* 0x2881: jb     2a39 <generic_usdt_filter_arg_2+0x2a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2a39;
	}
x86_l_2887:
	/* 0x2887: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_288c:
	/* 0x288c: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_288f:
	/* 0x288f: jb     2a4d <generic_usdt_filter_arg_2+0x2a4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2a4d;
	}
x86_l_2895:
	/* 0x2895: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_289a:
	/* 0x289a: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_289d:
	/* 0x289d: jae    28f4 <generic_usdt_filter_arg_2+0x28f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_28f4;
	}
x86_l_289f:
	/* 0x289f: movzx  eax,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_28a4:
	/* 0x28a4: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_28a7:
	/* 0x28a7: je     2a61 <generic_usdt_filter_arg_2+0x2a61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10849ULL;
	}
x86_l_28ad:
	/* 0x28ad: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28b0:
	/* 0x28b0: jne    2aed <generic_usdt_filter_arg_2+0x2aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10989ULL;
	}
x86_l_28b6:
	/* 0x28b6: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_28b9:
	/* 0x28b9: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_28bc:
	/* 0x28bc: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28bf:
	/* 0x28bf: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28c3:
	/* 0x28c3: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_28ca:
	/* 0x28ca: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28cf:
	/* 0x28cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28d4:
	/* 0x28d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d6:
	/* 0x28d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28d9:
	/* 0x28d9: je     2ce2 <generic_usdt_filter_arg_2+0x2ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11490ULL;
	}
x86_l_28df:
	/* 0x28df: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_28e2:
	/* 0x28e2: mov    DWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_28ea:
	/* 0x28ea: mov    DWORD PTR [rsp+0x24],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_28ef:
	/* 0x28ef: jmp    2ab9 <generic_usdt_filter_arg_2+0x2ab9> */
	return 10937ULL;
x86_l_28f4:
	/* 0x28f4: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_28f7:
	/* 0x28f7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28fa:
	/* 0x28fa: jae    321b <generic_usdt_filter_arg_2+0x321b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12827ULL;
	}
x86_l_2900:
	/* 0x2900: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_2903:
	/* 0x2903: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2907:
	/* 0x2907: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_290b:
	/* 0x290b: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2912:
	/* 0x2912: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_2915:
	/* 0x2915: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_291a:
	/* 0x291a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_291f:
	/* 0x291f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2921:
	/* 0x2921: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2924:
	/* 0x2924: je     2e8d <generic_usdt_filter_arg_2+0x2e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11917ULL;
	}
x86_l_292a:
	/* 0x292a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_292d:
	/* 0x292d: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2931:
	/* 0x2931: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2936:
	/* 0x2936: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_293b:
	/* 0x293b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2940:
	/* 0x2940: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2942:
	/* 0x2942: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2947:
	/* 0x2947: jmp    2cb0 <generic_usdt_filter_arg_2+0x2cb0> */
	return 11440ULL;
x86_l_294c:
	/* 0x294c: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2951:
	/* 0x2951: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2955:
	/* 0x2955: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2958:
	/* 0x2958: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_295c:
	/* 0x295c: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2964:
	/* 0x2964: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_296b:
	/* 0x296b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2970:
	/* 0x2970: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2975:
	/* 0x2975: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2977:
	/* 0x2977: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_297a:
	/* 0x297a: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2980:
	/* 0x2980: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_2986:
	/* 0x2986: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2989:
	/* 0x2989: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_298c:
	/* 0x298c: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_2992:
	/* 0x2992: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2999:
	/* 0x2999: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_299e:
	/* 0x299e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29a3:
	/* 0x29a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a5:
	/* 0x29a5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29a8:
	/* 0x29a8: je     31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12790ULL;
	}
x86_l_29ae:
	/* 0x29ae: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b3:
	/* 0x29b3: cmp    ecx,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_29b9:
	/* 0x29b9: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_29be:
	/* 0x29be: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_29c1:
	/* 0x29c1: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_29c8:
	/* 0x29c8: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ca:
	/* 0x29ca: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_29cd:
	/* 0x29cd: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_29d1:
	/* 0x29d1: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_29d4:
	/* 0x29d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29d9:
	/* 0x29d9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29de:
	/* 0x29de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e0:
	/* 0x29e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29e5:
	/* 0x29e5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_29e8:
	/* 0x29e8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_29eb:
	/* 0x29eb: jmp    31e8 <generic_usdt_filter_arg_2+0x31e8> */
	return 12776ULL;
x86_l_29f0:
	/* 0x29f0: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_29f8:
	/* 0x29f8: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_29fe:
	/* 0x29fe: ja     2c60 <generic_usdt_filter_arg_2+0x2c60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11360ULL;
	}
x86_l_2a04:
	/* 0x2a04: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a09:
	/* 0x2a09: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a0d:
	/* 0x2a0d: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2a10:
	/* 0x2a10: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2a16:
	/* 0x2a16: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2a19:
	/* 0x2a19: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2a1c:
	/* 0x2a1c: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2a1f:
	/* 0x2a1f: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2a21:
	/* 0x2a21: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2a23:
	/* 0x2a23: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_2a26:
	/* 0x2a26: je     2e95 <generic_usdt_filter_arg_2+0x2e95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11925ULL;
	}
x86_l_2a2c:
	/* 0x2a2c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2a2e:
	/* 0x2a2e: jne    2e95 <generic_usdt_filter_arg_2+0x2e95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11925ULL;
	}
x86_l_2a34:
	/* 0x2a34: jmp    2eac <generic_usdt_filter_arg_2+0x2eac> */
	return 11948ULL;
x86_l_2a39:
	/* 0x2a39: movzx  eax,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a3c:
	/* 0x2a3c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a3f:
	/* 0x2a3f: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2a44:
	/* 0x2a44: setb   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_B);
x86_l_2a48:
	/* 0x2a48: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_2a4d:
	/* 0x2a4d: movzx  eax,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a50:
	/* 0x2a50: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
	return 10835ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10844ULL: goto x86_l_2a5c;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10858ULL: goto x86_l_2a6a;
	case 10861ULL: goto x86_l_2a6d;
	case 10864ULL: goto x86_l_2a70;
	case 10868ULL: goto x86_l_2a74;
	case 10875ULL: goto x86_l_2a7b;
	case 10880ULL: goto x86_l_2a80;
	case 10885ULL: goto x86_l_2a85;
	case 10887ULL: goto x86_l_2a87;
	case 10890ULL: goto x86_l_2a8a;
	case 10896ULL: goto x86_l_2a90;
	case 10899ULL: goto x86_l_2a93;
	case 10907ULL: goto x86_l_2a9b;
	case 10911ULL: goto x86_l_2a9f;
	case 10915ULL: goto x86_l_2aa3;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10929ULL: goto x86_l_2ab1;
	case 10933ULL: goto x86_l_2ab5;
	case 10937ULL: goto x86_l_2ab9;
	case 10942ULL: goto x86_l_2abe;
	case 10947ULL: goto x86_l_2ac3;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10957ULL: goto x86_l_2acd;
	case 10960ULL: goto x86_l_2ad0;
	case 10966ULL: goto x86_l_2ad6;
	case 10969ULL: goto x86_l_2ad9;
	case 10972ULL: goto x86_l_2adc;
	case 10974ULL: goto x86_l_2ade;
	case 10977ULL: goto x86_l_2ae1;
	case 10980ULL: goto x86_l_2ae4;
	case 10984ULL: goto x86_l_2ae8;
	case 10989ULL: goto x86_l_2aed;
	case 10991ULL: goto x86_l_2aef;
	case 10995ULL: goto x86_l_2af3;
	case 11000ULL: goto x86_l_2af8;
	case 11003ULL: goto x86_l_2afb;
	case 11008ULL: goto x86_l_2b00;
	case 11012ULL: goto x86_l_2b04;
	case 11018ULL: goto x86_l_2b0a;
	case 11021ULL: goto x86_l_2b0d;
	case 11024ULL: goto x86_l_2b10;
	case 11027ULL: goto x86_l_2b13;
	case 11030ULL: goto x86_l_2b16;
	case 11032ULL: goto x86_l_2b18;
	case 11036ULL: goto x86_l_2b1c;
	case 11042ULL: goto x86_l_2b22;
	case 11044ULL: goto x86_l_2b24;
	case 11050ULL: goto x86_l_2b2a;
	case 11053ULL: goto x86_l_2b2d;
	case 11058ULL: goto x86_l_2b32;
	case 11061ULL: goto x86_l_2b35;
	case 11064ULL: goto x86_l_2b38;
	case 11066ULL: goto x86_l_2b3a;
	case 11068ULL: goto x86_l_2b3c;
	case 11071ULL: goto x86_l_2b3f;
	case 11076ULL: goto x86_l_2b44;
	case 11080ULL: goto x86_l_2b48;
	case 11082ULL: goto x86_l_2b4a;
	case 11086ULL: goto x86_l_2b4e;
	case 11092ULL: goto x86_l_2b54;
	case 11095ULL: goto x86_l_2b57;
	case 11097ULL: goto x86_l_2b59;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11115ULL: goto x86_l_2b6b;
	case 11118ULL: goto x86_l_2b6e;
	case 11122ULL: goto x86_l_2b72;
	case 11126ULL: goto x86_l_2b76;
	case 11129ULL: goto x86_l_2b79;
	case 11135ULL: goto x86_l_2b7f;
	case 11139ULL: goto x86_l_2b83;
	case 11146ULL: goto x86_l_2b8a;
	case 11151ULL: goto x86_l_2b8f;
	case 11156ULL: goto x86_l_2b94;
	case 11159ULL: goto x86_l_2b97;
	case 11161ULL: goto x86_l_2b99;
	case 11164ULL: goto x86_l_2b9c;
	case 11171ULL: goto x86_l_2ba3;
	case 11176ULL: goto x86_l_2ba8;
	case 11179ULL: goto x86_l_2bab;
	case 11181ULL: goto x86_l_2bad;
	case 11184ULL: goto x86_l_2bb0;
	case 11189ULL: goto x86_l_2bb5;
	case 11192ULL: goto x86_l_2bb8;
	case 11198ULL: goto x86_l_2bbe;
	case 11201ULL: goto x86_l_2bc1;
	case 11205ULL: goto x86_l_2bc5;
	case 11211ULL: goto x86_l_2bcb;
	case 11214ULL: goto x86_l_2bce;
	case 11219ULL: goto x86_l_2bd3;
	case 11224ULL: goto x86_l_2bd8;
	case 11227ULL: goto x86_l_2bdb;
	case 11231ULL: goto x86_l_2bdf;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11244ULL: goto x86_l_2bec;
	case 11246ULL: goto x86_l_2bee;
	case 11251ULL: goto x86_l_2bf3;
	case 11254ULL: goto x86_l_2bf6;
	case 11256ULL: goto x86_l_2bf8;
	case 11261ULL: goto x86_l_2bfd;
	case 11265ULL: goto x86_l_2c01;
	case 11268ULL: goto x86_l_2c04;
	case 11271ULL: goto x86_l_2c07;
	case 11277ULL: goto x86_l_2c0d;
	case 11282ULL: goto x86_l_2c12;
	case 11285ULL: goto x86_l_2c15;
	case 11287ULL: goto x86_l_2c17;
	case 11291ULL: goto x86_l_2c1b;
	case 11295ULL: goto x86_l_2c1f;
	case 11299ULL: goto x86_l_2c23;
	case 11302ULL: goto x86_l_2c26;
	case 11308ULL: goto x86_l_2c2c;
	case 11310ULL: goto x86_l_2c2e;
	case 11316ULL: goto x86_l_2c34;
	case 11321ULL: goto x86_l_2c39;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11338ULL: goto x86_l_2c4a;
	case 11345ULL: goto x86_l_2c51;
	case 11350ULL: goto x86_l_2c56;
	case 11355ULL: goto x86_l_2c5b;
	case 11360ULL: goto x86_l_2c60;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11373ULL: goto x86_l_2c6d;
	case 11377ULL: goto x86_l_2c71;
	case 11381ULL: goto x86_l_2c75;
	case 11388ULL: goto x86_l_2c7c;
	case 11391ULL: goto x86_l_2c7f;
	case 11396ULL: goto x86_l_2c84;
	case 11401ULL: goto x86_l_2c89;
	case 11403ULL: goto x86_l_2c8b;
	case 11406ULL: goto x86_l_2c8e;
	case 11412ULL: goto x86_l_2c94;
	case 11415ULL: goto x86_l_2c97;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11436ULL: goto x86_l_2cac;
	case 11440ULL: goto x86_l_2cb0;
	case 11442ULL: goto x86_l_2cb2;
	case 11445ULL: goto x86_l_2cb5;
	case 11447ULL: goto x86_l_2cb7;
	case 11452ULL: goto x86_l_2cbc;
	case 11455ULL: goto x86_l_2cbf;
	case 11457ULL: goto x86_l_2cc1;
	case 11460ULL: goto x86_l_2cc4;
	case 11463ULL: goto x86_l_2cc7;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11473ULL: goto x86_l_2cd1;
	case 11475ULL: goto x86_l_2cd3;
	case 11478ULL: goto x86_l_2cd6;
	case 11481ULL: goto x86_l_2cd9;
	case 11485ULL: goto x86_l_2cdd;
	case 11490ULL: goto x86_l_2ce2;
	case 11495ULL: goto x86_l_2ce7;
	case 11498ULL: goto x86_l_2cea;
	case 11501ULL: goto x86_l_2ced;
	case 11503ULL: goto x86_l_2cef;
	case 11506ULL: goto x86_l_2cf2;
	case 11509ULL: goto x86_l_2cf5;
	case 11513ULL: goto x86_l_2cf9;
	case 11518ULL: goto x86_l_2cfe;
	case 11521ULL: goto x86_l_2d01;
	case 11524ULL: goto x86_l_2d04;
	case 11526ULL: goto x86_l_2d06;
	case 11528ULL: goto x86_l_2d08;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11540ULL: goto x86_l_2d14;
	case 11542ULL: goto x86_l_2d16;
	case 11545ULL: goto x86_l_2d19;
	case 11551ULL: goto x86_l_2d1f;
	case 11554ULL: goto x86_l_2d22;
	case 11556ULL: goto x86_l_2d24;
	case 11560ULL: goto x86_l_2d28;
	case 11565ULL: goto x86_l_2d2d;
	case 11570ULL: goto x86_l_2d32;
	case 11574ULL: goto x86_l_2d36;
	case 11577ULL: goto x86_l_2d39;
	case 11581ULL: goto x86_l_2d3d;
	case 11585ULL: goto x86_l_2d41;
	case 11589ULL: goto x86_l_2d45;
	case 11592ULL: goto x86_l_2d48;
	case 11598ULL: goto x86_l_2d4e;
	case 11605ULL: goto x86_l_2d55;
	case 11610ULL: goto x86_l_2d5a;
	case 11615ULL: goto x86_l_2d5f;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11623ULL: goto x86_l_2d67;
	case 11630ULL: goto x86_l_2d6e;
	case 11635ULL: goto x86_l_2d73;
	case 11638ULL: goto x86_l_2d76;
	case 11640ULL: goto x86_l_2d78;
	case 11643ULL: goto x86_l_2d7b;
	case 11648ULL: goto x86_l_2d80;
	case 11651ULL: goto x86_l_2d83;
	case 11657ULL: goto x86_l_2d89;
	case 11660ULL: goto x86_l_2d8c;
	case 11664ULL: goto x86_l_2d90;
	case 11670ULL: goto x86_l_2d96;
	case 11673ULL: goto x86_l_2d99;
	case 11678ULL: goto x86_l_2d9e;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11695ULL: goto x86_l_2daf;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11707ULL: goto x86_l_2dbb;
	case 11709ULL: goto x86_l_2dbd;
	case 11714ULL: goto x86_l_2dc2;
	case 11717ULL: goto x86_l_2dc5;
	case 11719ULL: goto x86_l_2dc7;
	case 11724ULL: goto x86_l_2dcc;
	case 11729ULL: goto x86_l_2dd1;
	case 11733ULL: goto x86_l_2dd5;
	case 11736ULL: goto x86_l_2dd8;
	case 11738ULL: goto x86_l_2dda;
	case 11744ULL: goto x86_l_2de0;
	case 11749ULL: goto x86_l_2de5;
	case 11752ULL: goto x86_l_2de8;
	case 11754ULL: goto x86_l_2dea;
	case 11758ULL: goto x86_l_2dee;
	case 11762ULL: goto x86_l_2df2;
	case 11767ULL: goto x86_l_2df7;
	case 11773ULL: goto x86_l_2dfd;
	case 11778ULL: goto x86_l_2e02;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11795ULL: goto x86_l_2e13;
	case 11800ULL: goto x86_l_2e18;
	case 11806ULL: goto x86_l_2e1e;
	case 11813ULL: goto x86_l_2e25;
	case 11818ULL: goto x86_l_2e2a;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11831ULL: goto x86_l_2e37;
	case 11834ULL: goto x86_l_2e3a;
	case 11836ULL: goto x86_l_2e3c;
	case 11839ULL: goto x86_l_2e3f;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11849ULL: goto x86_l_2e49;
	case 11851ULL: goto x86_l_2e4b;
	case 11854ULL: goto x86_l_2e4e;
	case 11856ULL: goto x86_l_2e50;
	case 11859ULL: goto x86_l_2e53;
	case 11863ULL: goto x86_l_2e57;
	case 11867ULL: goto x86_l_2e5b;
	case 11874ULL: goto x86_l_2e62;
	case 11879ULL: goto x86_l_2e67;
	case 11884ULL: goto x86_l_2e6c;
	case 11886ULL: goto x86_l_2e6e;
	case 11889ULL: goto x86_l_2e71;
	case 11891ULL: goto x86_l_2e73;
	case 11894ULL: goto x86_l_2e76;
	case 11897ULL: goto x86_l_2e79;
	case 11902ULL: goto x86_l_2e7e;
	case 11907ULL: goto x86_l_2e83;
	case 11912ULL: goto x86_l_2e88;
	case 11917ULL: goto x86_l_2e8d;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11928ULL: goto x86_l_2e98;
	case 11930ULL: goto x86_l_2e9a;
	case 11932ULL: goto x86_l_2e9c;
	case 11934ULL: goto x86_l_2e9e;
	case 11937ULL: goto x86_l_2ea1;
	case 11942ULL: goto x86_l_2ea6;
	case 11946ULL: goto x86_l_2eaa;
	case 11948ULL: goto x86_l_2eac;
	case 11951ULL: goto x86_l_2eaf;
	case 11957ULL: goto x86_l_2eb5;
	case 11960ULL: goto x86_l_2eb8;
	case 11962ULL: goto x86_l_2eba;
	case 11966ULL: goto x86_l_2ebe;
	case 11970ULL: goto x86_l_2ec2;
	case 11973ULL: goto x86_l_2ec5;
	case 11977ULL: goto x86_l_2ec9;
	case 11981ULL: goto x86_l_2ecd;
	case 11985ULL: goto x86_l_2ed1;
	case 11988ULL: goto x86_l_2ed4;
	case 11994ULL: goto x86_l_2eda;
	case 12001ULL: goto x86_l_2ee1;
	case 12006ULL: goto x86_l_2ee6;
	case 12011ULL: goto x86_l_2eeb;
	case 12014ULL: goto x86_l_2eee;
	case 12016ULL: goto x86_l_2ef0;
	case 12019ULL: goto x86_l_2ef3;
	case 12026ULL: goto x86_l_2efa;
	case 12031ULL: goto x86_l_2eff;
	case 12034ULL: goto x86_l_2f02;
	case 12036ULL: goto x86_l_2f04;
	case 12044ULL: goto x86_l_2f0c;
	case 12047ULL: goto x86_l_2f0f;
	case 12052ULL: goto x86_l_2f14;
	case 12055ULL: goto x86_l_2f17;
	case 12061ULL: goto x86_l_2f1d;
	case 12070ULL: goto x86_l_2f26;
	case 12074ULL: goto x86_l_2f2a;
	case 12080ULL: goto x86_l_2f30;
	case 12085ULL: goto x86_l_2f35;
	case 12090ULL: goto x86_l_2f3a;
	case 12093ULL: goto x86_l_2f3d;
	case 12097ULL: goto x86_l_2f41;
	case 12102ULL: goto x86_l_2f46;
	case 12107ULL: goto x86_l_2f4b;
	case 12110ULL: goto x86_l_2f4e;
	case 12112ULL: goto x86_l_2f50;
	case 12117ULL: goto x86_l_2f55;
	case 12120ULL: goto x86_l_2f58;
	case 12122ULL: goto x86_l_2f5a;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12136ULL: goto x86_l_2f68;
	case 12139ULL: goto x86_l_2f6b;
	case 12141ULL: goto x86_l_2f6d;
	case 12147ULL: goto x86_l_2f73;
	case 12152ULL: goto x86_l_2f78;
	case 12160ULL: goto x86_l_2f80;
	case 12162ULL: goto x86_l_2f82;
	case 12166ULL: goto x86_l_2f86;
	case 12170ULL: goto x86_l_2f8a;
	case 12175ULL: goto x86_l_2f8f;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12192ULL: goto x86_l_2fa0;
	case 12197ULL: goto x86_l_2fa5;
	case 12203ULL: goto x86_l_2fab;
	case 12208ULL: goto x86_l_2fb0;
	case 12214ULL: goto x86_l_2fb6;
	case 12221ULL: goto x86_l_2fbd;
	case 12226ULL: goto x86_l_2fc2;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12239ULL: goto x86_l_2fcf;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12256ULL: goto x86_l_2fe0;
	case 12261ULL: goto x86_l_2fe5;
	case 12267ULL: goto x86_l_2feb;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12284ULL: goto x86_l_2ffc;
	case 12289ULL: goto x86_l_3001;
	case 12292ULL: goto x86_l_3004;
	case 12295ULL: goto x86_l_3007;
	case 12300ULL: goto x86_l_300c;
	case 12305ULL: goto x86_l_3011;
	case 12311ULL: goto x86_l_3017;
	case 12316ULL: goto x86_l_301c;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12333ULL: goto x86_l_302d;
	case 12340ULL: goto x86_l_3034;
	case 12345ULL: goto x86_l_3039;
	case 12350ULL: goto x86_l_303e;
	case 12355ULL: goto x86_l_3043;
	case 12360ULL: goto x86_l_3048;
	case 12366ULL: goto x86_l_304e;
	case 12371ULL: goto x86_l_3053;
	case 12377ULL: goto x86_l_3059;
	case 12382ULL: goto x86_l_305e;
	case 12388ULL: goto x86_l_3064;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12405ULL: goto x86_l_3075;
	case 12410ULL: goto x86_l_307a;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12427ULL: goto x86_l_308b;
	case 12429ULL: goto x86_l_308d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a53:
	/* 0x2a53: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2a58:
	/* 0x2a58: setae  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_AE);
x86_l_2a5c:
	/* 0x2a5c: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_2a61:
	/* 0x2a61: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a66:
	/* 0x2a66: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a6a:
	/* 0x2a6a: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_2a6d:
	/* 0x2a6d: mov    eax,DWORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2a70:
	/* 0x2a70: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a74:
	/* 0x2a74: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_2a7b:
	/* 0x2a7b: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a80:
	/* 0x2a80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a85:
	/* 0x2a85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a87:
	/* 0x2a87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a8a:
	/* 0x2a8a: je     2ce2 <generic_usdt_filter_arg_2+0x2ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce2;
	}
x86_l_2a90:
	/* 0x2a90: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a93:
	/* 0x2a93: mov    DWORD PTR [rsp+0x20],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953600ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2aa3:
	/* 0x2aa3: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aad:
	/* 0x2aad: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2ab1:
	/* 0x2ab1: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2ab5:
	/* 0x2ab5: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ab9:
	/* 0x2ab9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2abe:
	/* 0x2abe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ac3:
	/* 0x2ac3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac5:
	/* 0x2ac5: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2aca:
	/* 0x2aca: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2acd:
	/* 0x2acd: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2ad0:
	/* 0x2ad0: jb     2cef <generic_usdt_filter_arg_2+0x2cef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2cef;
	}
x86_l_2ad6:
	/* 0x2ad6: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2ad9:
	/* 0x2ad9: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2adc:
	/* 0x2adc: ja     2aed <generic_usdt_filter_arg_2+0x2aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2aed;
	}
x86_l_2ade:
	/* 0x2ade: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ae1:
	/* 0x2ae1: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2ae4:
	/* 0x2ae4: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ae8:
	/* 0x2ae8: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_2aed:
	/* 0x2aed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aef:
	/* 0x2aef: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2af3:
	/* 0x2af3: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_2af8:
	/* 0x2af8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2afb:
	/* 0x2afb: jmp    3161 <generic_usdt_filter_arg_2+0x3161> */
	return 12641ULL;
x86_l_2b00:
	/* 0x2b00: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b04:
	/* 0x2b04: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2b0a:
	/* 0x2b0a: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2b0d:
	/* 0x2b0d: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2b10:
	/* 0x2b10: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2b13:
	/* 0x2b13: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2b16:
	/* 0x2b16: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2b18:
	/* 0x2b18: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_2b1c:
	/* 0x2b1c: je     2cfe <generic_usdt_filter_arg_2+0x2cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cfe;
	}
x86_l_2b22:
	/* 0x2b22: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2b24:
	/* 0x2b24: jne    2cfe <generic_usdt_filter_arg_2+0x2cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cfe;
	}
x86_l_2b2a:
	/* 0x2b2a: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_2b2d:
	/* 0x2b2d: jmp    2d16 <generic_usdt_filter_arg_2+0x2d16> */
	goto x86_l_2d16;
x86_l_2b32:
	/* 0x2b32: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b35:
	/* 0x2b35: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2b38:
	/* 0x2b38: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b3a:
	/* 0x2b3a: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_2b3c:
	/* 0x2b3c: add    edi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2b3f:
	/* 0x2b3f: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2b44:
	/* 0x2b44: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2b48:
	/* 0x2b48: ja     2b59 <generic_usdt_filter_arg_2+0x2b59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b59;
	}
x86_l_2b4a:
	/* 0x2b4a: movzx  eax,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b4e:
	/* 0x2b4e: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2b54:
	/* 0x2b54: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2b57:
	/* 0x2b57: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2b59:
	/* 0x2b59: mov    DWORD PTR [rsp+0x4c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2b5d:
	/* 0x2b5d: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b62:
	/* 0x2b62: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b67:
	/* 0x2b67: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b6b:
	/* 0x2b6b: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2b72:
	/* 0x2b72: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b76:
	/* 0x2b76: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2b79:
	/* 0x2b79: je     2c60 <generic_usdt_filter_arg_2+0x2c60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c60;
	}
x86_l_2b7f:
	/* 0x2b7f: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b83:
	/* 0x2b83: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2b8a:
	/* 0x2b8a: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b8f:
	/* 0x2b8f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b94:
	/* 0x2b94: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2b97:
	/* 0x2b97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b99:
	/* 0x2b99: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2b9c:
	/* 0x2b9c: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ba3:
	/* 0x2ba3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ba8:
	/* 0x2ba8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2bab:
	/* 0x2bab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bad:
	/* 0x2bad: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bb0:
	/* 0x2bb0: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bb5:
	/* 0x2bb5: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2bb8:
	/* 0x2bb8: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_2bbe:
	/* 0x2bbe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bc1:
	/* 0x2bc1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc5:
	/* 0x2bc5: je     31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12797ULL;
	}
x86_l_2bcb:
	/* 0x2bcb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2bce:
	/* 0x2bce: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bd3:
	/* 0x2bd3: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bd8:
	/* 0x2bd8: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bdb:
	/* 0x2bdb: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2bdf:
	/* 0x2bdf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2be4:
	/* 0x2be4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2be9:
	/* 0x2be9: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2bec:
	/* 0x2bec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bee:
	/* 0x2bee: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2bf3:
	/* 0x2bf3: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2bf6:
	/* 0x2bf6: jbe    2c17 <generic_usdt_filter_arg_2+0x2c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c17;
	}
x86_l_2bf8:
	/* 0x2bf8: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bfd:
	/* 0x2bfd: lea    rdi,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2c01:
	/* 0x2c01: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2c04:
	/* 0x2c04: sub    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c07:
	/* 0x2c07: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c0d:
	/* 0x2c0d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c12:
	/* 0x2c12: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2c15:
	/* 0x2c15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c17:
	/* 0x2c17: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c1b:
	/* 0x2c1b: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c23:
	/* 0x2c23: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c26:
	/* 0x2c26: jg     2fcc <generic_usdt_filter_arg_2+0x2fcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2fcc;
	}
x86_l_2c2c:
	/* 0x2c2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c2e:
	/* 0x2c2e: je     307a <generic_usdt_filter_arg_2+0x307a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_307a;
	}
x86_l_2c34:
	/* 0x2c34: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2c39:
	/* 0x2c39: je     30a0 <generic_usdt_filter_arg_2+0x30a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12448ULL;
	}
x86_l_2c3f:
	/* 0x2c3f: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2c44:
	/* 0x2c44: jne    31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12790ULL;
	}
x86_l_2c4a:
	/* 0x2c4a: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2c51:
	/* 0x2c51: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c56:
	/* 0x2c56: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c5b:
	/* 0x2c5b: jmp    30c4 <generic_usdt_filter_arg_2+0x30c4> */
	return 12484ULL;
x86_l_2c60:
	/* 0x2c60: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c63:
	/* 0x2c63: jmp    31fd <generic_usdt_filter_arg_2+0x31fd> */
	return 12797ULL;
x86_l_2c68:
	/* 0x2c68: movzx  r12d,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2c6d:
	/* 0x2c6d: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2c71:
	/* 0x2c71: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c75:
	/* 0x2c75: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2c7c:
	/* 0x2c7c: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2c7f:
	/* 0x2c7f: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c84:
	/* 0x2c84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c89:
	/* 0x2c89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8b:
	/* 0x2c8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c8e:
	/* 0x2c8e: je     2e8d <generic_usdt_filter_arg_2+0x2e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e8d;
	}
x86_l_2c94:
	/* 0x2c94: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2c97:
	/* 0x2c97: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c9b:
	/* 0x2c9b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ca0:
	/* 0x2ca0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ca5:
	/* 0x2ca5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2caa:
	/* 0x2caa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cac:
	/* 0x2cac: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cb0:
	/* 0x2cb0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cb2:
	/* 0x2cb2: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_2cb5:
	/* 0x2cb5: ja     2cd9 <generic_usdt_filter_arg_2+0x2cd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2cd9;
	}
x86_l_2cb7:
	/* 0x2cb7: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_2cbc:
	/* 0x2cbc: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2cbf:
	/* 0x2cbf: jae    2cc9 <generic_usdt_filter_arg_2+0x2cc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2cc9;
	}
x86_l_2cc1:
	/* 0x2cc1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cc4:
	/* 0x2cc4: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2cc7:
	/* 0x2cc7: jmp    2cd9 <generic_usdt_filter_arg_2+0x2cd9> */
	goto x86_l_2cd9;
x86_l_2cc9:
	/* 0x2cc9: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_2cce:
	/* 0x2cce: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2cd1:
	/* 0x2cd1: jae    2cd9 <generic_usdt_filter_arg_2+0x2cd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2cd9;
	}
x86_l_2cd3:
	/* 0x2cd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cd6:
	/* 0x2cd6: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2cd9:
	/* 0x2cd9: movzx  r12d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cdd:
	/* 0x2cdd: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_2ce2:
	/* 0x2ce2: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ce7:
	/* 0x2ce7: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_2cea:
	/* 0x2cea: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_2ced:
	/* 0x2ced: jmp    2cf2 <generic_usdt_filter_arg_2+0x2cf2> */
	goto x86_l_2cf2;
x86_l_2cef:
	/* 0x2cef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cf2:
	/* 0x2cf2: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2cf5:
	/* 0x2cf5: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cf9:
	/* 0x2cf9: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_2cfe:
	/* 0x2cfe: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d01:
	/* 0x2d01: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2d04:
	/* 0x2d04: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d06:
	/* 0x2d06: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2d08:
	/* 0x2d08: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2d0b:
	/* 0x2d0b: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2d10:
	/* 0x2d10: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2d14:
	/* 0x2d14: ja     2d24 <generic_usdt_filter_arg_2+0x2d24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d24;
	}
x86_l_2d16:
	/* 0x2d16: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d19:
	/* 0x2d19: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2d1f:
	/* 0x2d1f: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2d22:
	/* 0x2d22: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2d24:
	/* 0x2d24: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2d28:
	/* 0x2d28: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d2d:
	/* 0x2d2d: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d32:
	/* 0x2d32: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d36:
	/* 0x2d36: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2d39:
	/* 0x2d39: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2d41:
	/* 0x2d41: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d45:
	/* 0x2d45: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2d48:
	/* 0x2d48: je     3157 <generic_usdt_filter_arg_2+0x3157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12631ULL;
	}
x86_l_2d4e:
	/* 0x2d4e: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2d55:
	/* 0x2d55: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d5a:
	/* 0x2d5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d5f:
	/* 0x2d5f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d62:
	/* 0x2d62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d64:
	/* 0x2d64: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d67:
	/* 0x2d67: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2d6e:
	/* 0x2d6e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d73:
	/* 0x2d73: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d76:
	/* 0x2d76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d78:
	/* 0x2d78: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d7b:
	/* 0x2d7b: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d80:
	/* 0x2d80: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2d83:
	/* 0x2d83: je     315a <generic_usdt_filter_arg_2+0x315a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12634ULL;
	}
x86_l_2d89:
	/* 0x2d89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d8c:
	/* 0x2d8c: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d90:
	/* 0x2d90: je     315e <generic_usdt_filter_arg_2+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12638ULL;
	}
x86_l_2d96:
	/* 0x2d96: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d99:
	/* 0x2d99: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d9e:
	/* 0x2d9e: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2da2:
	/* 0x2da2: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2da7:
	/* 0x2da7: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dac:
	/* 0x2dac: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2daf:
	/* 0x2daf: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2db3:
	/* 0x2db3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2db8:
	/* 0x2db8: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2dbb:
	/* 0x2dbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dbd:
	/* 0x2dbd: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2dc2:
	/* 0x2dc2: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2dc5:
	/* 0x2dc5: jbe    2dea <generic_usdt_filter_arg_2+0x2dea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2dea;
	}
x86_l_2dc7:
	/* 0x2dc7: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dcc:
	/* 0x2dcc: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dd1:
	/* 0x2dd1: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2dd5:
	/* 0x2dd5: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2dd8:
	/* 0x2dd8: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dda:
	/* 0x2dda: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2de0:
	/* 0x2de0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2de5:
	/* 0x2de5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2de8:
	/* 0x2de8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dea:
	/* 0x2dea: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2dee:
	/* 0x2dee: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2df2:
	/* 0x2df2: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2df7:
	/* 0x2df7: jg     300c <generic_usdt_filter_arg_2+0x300c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_300c;
	}
x86_l_2dfd:
	/* 0x2dfd: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2e02:
	/* 0x2e02: je     30e6 <generic_usdt_filter_arg_2+0x30e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12518ULL;
	}
x86_l_2e08:
	/* 0x2e08: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2e0d:
	/* 0x2e0d: je     310c <generic_usdt_filter_arg_2+0x310c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12556ULL;
	}
x86_l_2e13:
	/* 0x2e13: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2e18:
	/* 0x2e18: jne    3157 <generic_usdt_filter_arg_2+0x3157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12631ULL;
	}
x86_l_2e1e:
	/* 0x2e1e: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2e25:
	/* 0x2e25: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e2a:
	/* 0x2e2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e2f:
	/* 0x2e2f: jmp    3130 <generic_usdt_filter_arg_2+0x3130> */
	return 12592ULL;
x86_l_2e34:
	/* 0x2e34: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e37:
	/* 0x2e37: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2e3a:
	/* 0x2e3a: jne    2e46 <generic_usdt_filter_arg_2+0x2e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e46;
	}
x86_l_2e3c:
	/* 0x2e3c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2e3f:
	/* 0x2e3f: je     2e46 <generic_usdt_filter_arg_2+0x2e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e46;
	}
x86_l_2e41:
	/* 0x2e41: movzx  r12d,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2e46:
	/* 0x2e46: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2e49:
	/* 0x2e49: je     2e50 <generic_usdt_filter_arg_2+0x2e50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e50;
	}
x86_l_2e4b:
	/* 0x2e4b: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2e4e:
	/* 0x2e4e: jne    2e8d <generic_usdt_filter_arg_2+0x2e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e8d;
	}
x86_l_2e50:
	/* 0x2e50: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2e53:
	/* 0x2e53: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2e57:
	/* 0x2e57: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2e5b:
	/* 0x2e5b: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2e62:
	/* 0x2e62: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2e67:
	/* 0x2e67: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e6c:
	/* 0x2e6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6e:
	/* 0x2e6e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e71:
	/* 0x2e71: je     2e8d <generic_usdt_filter_arg_2+0x2e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e8d;
	}
x86_l_2e73:
	/* 0x2e73: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e76:
	/* 0x2e76: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2e79:
	/* 0x2e79: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e7e:
	/* 0x2e7e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e83:
	/* 0x2e83: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e88:
	/* 0x2e88: jmp    2caa <generic_usdt_filter_arg_2+0x2caa> */
	goto x86_l_2caa;
x86_l_2e8d:
	/* 0x2e8d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e90:
	/* 0x2e90: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	return 12827ULL;
x86_l_2e95:
	/* 0x2e95: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e98:
	/* 0x2e98: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2e9a:
	/* 0x2e9a: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e9c:
	/* 0x2e9c: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2e9e:
	/* 0x2e9e: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2ea1:
	/* 0x2ea1: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2ea6:
	/* 0x2ea6: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2eaa:
	/* 0x2eaa: ja     2eba <generic_usdt_filter_arg_2+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2eba;
	}
x86_l_2eac:
	/* 0x2eac: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2eaf:
	/* 0x2eaf: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2eb5:
	/* 0x2eb5: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2eb8:
	/* 0x2eb8: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2eba:
	/* 0x2eba: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2ebe:
	/* 0x2ebe: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ec2:
	/* 0x2ec2: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2ec5:
	/* 0x2ec5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec9:
	/* 0x2ec9: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2ecd:
	/* 0x2ecd: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ed1:
	/* 0x2ed1: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2ed4:
	/* 0x2ed4: je     31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12790ULL;
	}
x86_l_2eda:
	/* 0x2eda: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2ee1:
	/* 0x2ee1: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee6:
	/* 0x2ee6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eeb:
	/* 0x2eeb: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2eee:
	/* 0x2eee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef0:
	/* 0x2ef0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2ef3:
	/* 0x2ef3: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2efa:
	/* 0x2efa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eff:
	/* 0x2eff: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2f02:
	/* 0x2f02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f04:
	/* 0x2f04: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f0c:
	/* 0x2f0c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f0f:
	/* 0x2f0f: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f14:
	/* 0x2f14: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2f17:
	/* 0x2f17: je     31f9 <generic_usdt_filter_arg_2+0x31f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12793ULL;
	}
x86_l_2f1d:
	/* 0x2f1d: cmp    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_2f26:
	/* 0x2f26: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f2a:
	/* 0x2f2a: je     31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12797ULL;
	}
x86_l_2f30:
	/* 0x2f30: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f35:
	/* 0x2f35: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f3a:
	/* 0x2f3a: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f3d:
	/* 0x2f3d: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2f41:
	/* 0x2f41: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f46:
	/* 0x2f46: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f4b:
	/* 0x2f4b: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2f4e:
	/* 0x2f4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f50:
	/* 0x2f50: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2f55:
	/* 0x2f55: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2f58:
	/* 0x2f58: jbe    2f82 <generic_usdt_filter_arg_2+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f82;
	}
x86_l_2f5a:
	/* 0x2f5a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f64:
	/* 0x2f64: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2f68:
	/* 0x2f68: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2f6b:
	/* 0x2f6b: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f6d:
	/* 0x2f6d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f73:
	/* 0x2f73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f78:
	/* 0x2f78: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f80:
	/* 0x2f80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f82:
	/* 0x2f82: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f86:
	/* 0x2f86: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f8a:
	/* 0x2f8a: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_2f8f:
	/* 0x2f8f: jg     3043 <generic_usdt_filter_arg_2+0x3043> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3043;
	}
x86_l_2f95:
	/* 0x2f95: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2f9a:
	/* 0x2f9a: je     3185 <generic_usdt_filter_arg_2+0x3185> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12677ULL;
	}
x86_l_2fa0:
	/* 0x2fa0: cmp    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_2fa5:
	/* 0x2fa5: je     31ab <generic_usdt_filter_arg_2+0x31ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12715ULL;
	}
x86_l_2fab:
	/* 0x2fab: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_2fb0:
	/* 0x2fb0: jne    31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12790ULL;
	}
x86_l_2fb6:
	/* 0x2fb6: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2fbd:
	/* 0x2fbd: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fc2:
	/* 0x2fc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fc7:
	/* 0x2fc7: jmp    31cf <generic_usdt_filter_arg_2+0x31cf> */
	return 12751ULL;
x86_l_2fcc:
	/* 0x2fcc: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2fcf:
	/* 0x2fcf: je     308d <generic_usdt_filter_arg_2+0x308d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_308d;
	}
x86_l_2fd5:
	/* 0x2fd5: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_2fda:
	/* 0x2fda: je     30b3 <generic_usdt_filter_arg_2+0x30b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12467ULL;
	}
x86_l_2fe0:
	/* 0x2fe0: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_2fe5:
	/* 0x2fe5: jne    31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12790ULL;
	}
x86_l_2feb:
	/* 0x2feb: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2ff2:
	/* 0x2ff2: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ff7:
	/* 0x2ff7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ffc:
	/* 0x2ffc: jmp    30c4 <generic_usdt_filter_arg_2+0x30c4> */
	return 12484ULL;
x86_l_3001:
	/* 0x3001: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3004:
	/* 0x3004: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3007:
	/* 0x3007: jmp    315e <generic_usdt_filter_arg_2+0x315e> */
	return 12638ULL;
x86_l_300c:
	/* 0x300c: cmp    DWORD PTR [rsp+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_3011:
	/* 0x3011: je     30f9 <generic_usdt_filter_arg_2+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_3017:
	/* 0x3017: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_301c:
	/* 0x301c: je     311f <generic_usdt_filter_arg_2+0x311f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12575ULL;
	}
x86_l_3022:
	/* 0x3022: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_3027:
	/* 0x3027: jne    3157 <generic_usdt_filter_arg_2+0x3157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12631ULL;
	}
x86_l_302d:
	/* 0x302d: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3034:
	/* 0x3034: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3039:
	/* 0x3039: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_303e:
	/* 0x303e: jmp    3130 <generic_usdt_filter_arg_2+0x3130> */
	return 12592ULL;
x86_l_3043:
	/* 0x3043: cmp    DWORD PTR [rsp+0x38],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168579ULL);
x86_l_3048:
	/* 0x3048: je     3198 <generic_usdt_filter_arg_2+0x3198> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12696ULL;
	}
x86_l_304e:
	/* 0x304e: cmp    DWORD PTR [rsp+0x38],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168580ULL);
x86_l_3053:
	/* 0x3053: je     31be <generic_usdt_filter_arg_2+0x31be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12734ULL;
	}
x86_l_3059:
	/* 0x3059: cmp    DWORD PTR [rsp+0x38],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168581ULL);
x86_l_305e:
	/* 0x305e: jne    31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12790ULL;
	}
x86_l_3064:
	/* 0x3064: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_306b:
	/* 0x306b: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3070:
	/* 0x3070: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3075:
	/* 0x3075: jmp    31cf <generic_usdt_filter_arg_2+0x31cf> */
	return 12751ULL;
x86_l_307a:
	/* 0x307a: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3081:
	/* 0x3081: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3086:
	/* 0x3086: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_308b:
	/* 0x308b: jmp    30c4 <generic_usdt_filter_arg_2+0x30c4> */
	return 12484ULL;
x86_l_308d:
	/* 0x308d: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
	return 12436ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12436ULL: goto x86_l_3094;
	case 12441ULL: goto x86_l_3099;
	case 12446ULL: goto x86_l_309e;
	case 12448ULL: goto x86_l_30a0;
	case 12455ULL: goto x86_l_30a7;
	case 12460ULL: goto x86_l_30ac;
	case 12465ULL: goto x86_l_30b1;
	case 12467ULL: goto x86_l_30b3;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12489ULL: goto x86_l_30c9;
	case 12491ULL: goto x86_l_30cb;
	case 12494ULL: goto x86_l_30ce;
	case 12500ULL: goto x86_l_30d4;
	case 12503ULL: goto x86_l_30d7;
	case 12508ULL: goto x86_l_30dc;
	case 12513ULL: goto x86_l_30e1;
	case 12518ULL: goto x86_l_30e6;
	case 12525ULL: goto x86_l_30ed;
	case 12530ULL: goto x86_l_30f2;
	case 12535ULL: goto x86_l_30f7;
	case 12537ULL: goto x86_l_30f9;
	case 12544ULL: goto x86_l_3100;
	case 12549ULL: goto x86_l_3105;
	case 12554ULL: goto x86_l_310a;
	case 12556ULL: goto x86_l_310c;
	case 12563ULL: goto x86_l_3113;
	case 12568ULL: goto x86_l_3118;
	case 12573ULL: goto x86_l_311d;
	case 12575ULL: goto x86_l_311f;
	case 12582ULL: goto x86_l_3126;
	case 12587ULL: goto x86_l_312b;
	case 12592ULL: goto x86_l_3130;
	case 12597ULL: goto x86_l_3135;
	case 12599ULL: goto x86_l_3137;
	case 12602ULL: goto x86_l_313a;
	case 12604ULL: goto x86_l_313c;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12617ULL: goto x86_l_3149;
	case 12619ULL: goto x86_l_314b;
	case 12622ULL: goto x86_l_314e;
	case 12625ULL: goto x86_l_3151;
	case 12629ULL: goto x86_l_3155;
	case 12631ULL: goto x86_l_3157;
	case 12634ULL: goto x86_l_315a;
	case 12638ULL: goto x86_l_315e;
	case 12641ULL: goto x86_l_3161;
	case 12644ULL: goto x86_l_3164;
	case 12650ULL: goto x86_l_316a;
	case 12652ULL: goto x86_l_316c;
	case 12662ULL: goto x86_l_3176;
	case 12666ULL: goto x86_l_317a;
	case 12672ULL: goto x86_l_3180;
	case 12677ULL: goto x86_l_3185;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12694ULL: goto x86_l_3196;
	case 12696ULL: goto x86_l_3198;
	case 12703ULL: goto x86_l_319f;
	case 12708ULL: goto x86_l_31a4;
	case 12713ULL: goto x86_l_31a9;
	case 12715ULL: goto x86_l_31ab;
	case 12722ULL: goto x86_l_31b2;
	case 12727ULL: goto x86_l_31b7;
	case 12732ULL: goto x86_l_31bc;
	case 12734ULL: goto x86_l_31be;
	case 12741ULL: goto x86_l_31c5;
	case 12746ULL: goto x86_l_31ca;
	case 12751ULL: goto x86_l_31cf;
	case 12756ULL: goto x86_l_31d4;
	case 12758ULL: goto x86_l_31d6;
	case 12761ULL: goto x86_l_31d9;
	case 12763ULL: goto x86_l_31db;
	case 12766ULL: goto x86_l_31de;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12778ULL: goto x86_l_31ea;
	case 12781ULL: goto x86_l_31ed;
	case 12784ULL: goto x86_l_31f0;
	case 12788ULL: goto x86_l_31f4;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12797ULL: goto x86_l_31fd;
	case 12800ULL: goto x86_l_3200;
	case 12803ULL: goto x86_l_3203;
	case 12805ULL: goto x86_l_3205;
	case 12807ULL: goto x86_l_3207;
	case 12817ULL: goto x86_l_3211;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12827ULL: goto x86_l_321b;
	case 12830ULL: goto x86_l_321e;
	case 12832ULL: goto x86_l_3220;
	case 12836ULL: goto x86_l_3224;
	case 12838ULL: goto x86_l_3226;
	case 12840ULL: goto x86_l_3228;
	case 12842ULL: goto x86_l_322a;
	case 12846ULL: goto x86_l_322e;
	case 12848ULL: goto x86_l_3230;
	case 12852ULL: goto x86_l_3234;
	case 12858ULL: goto x86_l_323a;
	case 12861ULL: goto x86_l_323d;
	case 12867ULL: goto x86_l_3243;
	case 12871ULL: goto x86_l_3247;
	case 12877ULL: goto x86_l_324d;
	case 12879ULL: goto x86_l_324f;
	case 12883ULL: goto x86_l_3253;
	case 12889ULL: goto x86_l_3259;
	case 12893ULL: goto x86_l_325d;
	case 12899ULL: goto x86_l_3263;
	case 12903ULL: goto x86_l_3267;
	case 12909ULL: goto x86_l_326d;
	case 12913ULL: goto x86_l_3271;
	case 12919ULL: goto x86_l_3277;
	case 12922ULL: goto x86_l_327a;
	case 12927ULL: goto x86_l_327f;
	case 12934ULL: goto x86_l_3286;
	case 12941ULL: goto x86_l_328d;
	case 12946ULL: goto x86_l_3292;
	case 12951ULL: goto x86_l_3297;
	case 12954ULL: goto x86_l_329a;
	case 12959ULL: goto x86_l_329f;
	case 12961ULL: goto x86_l_32a1;
	case 12968ULL: goto x86_l_32a8;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12981ULL: goto x86_l_32b5;
	case 12986ULL: goto x86_l_32ba;
	case 12988ULL: goto x86_l_32bc;
	case 12990ULL: goto x86_l_32be;
	case 12997ULL: goto x86_l_32c5;
	case 12999ULL: goto x86_l_32c7;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13008ULL: goto x86_l_32d0;
	case 13016ULL: goto x86_l_32d8;
	case 13018ULL: goto x86_l_32da;
	case 13024ULL: goto x86_l_32e0;
	case 13032ULL: goto x86_l_32e8;
	case 13034ULL: goto x86_l_32ea;
	case 13040ULL: goto x86_l_32f0;
	case 13048ULL: goto x86_l_32f8;
	case 13050ULL: goto x86_l_32fa;
	case 13056ULL: goto x86_l_3300;
	case 13064ULL: goto x86_l_3308;
	case 13066ULL: goto x86_l_330a;
	case 13072ULL: goto x86_l_3310;
	case 13080ULL: goto x86_l_3318;
	case 13082ULL: goto x86_l_331a;
	case 13088ULL: goto x86_l_3320;
	case 13096ULL: goto x86_l_3328;
	case 13098ULL: goto x86_l_332a;
	case 13105ULL: goto x86_l_3331;
	case 13112ULL: goto x86_l_3338;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13132ULL: goto x86_l_334c;
	case 13136ULL: goto x86_l_3350;
	case 13141ULL: goto x86_l_3355;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13153ULL: goto x86_l_3361;
	case 13160ULL: goto x86_l_3368;
	case 13165ULL: goto x86_l_336d;
	case 13170ULL: goto x86_l_3372;
	case 13172ULL: goto x86_l_3374;
	case 13175ULL: goto x86_l_3377;
	case 13181ULL: goto x86_l_337d;
	case 13188ULL: goto x86_l_3384;
	case 13193ULL: goto x86_l_3389;
	case 13198ULL: goto x86_l_338e;
	case 13200ULL: goto x86_l_3390;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3094:
	/* 0x3094: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3099:
	/* 0x3099: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_309e:
	/* 0x309e: jmp    30c4 <generic_usdt_filter_arg_2+0x30c4> */
	goto x86_l_30c4;
x86_l_30a0:
	/* 0x30a0: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_30a7:
	/* 0x30a7: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30ac:
	/* 0x30ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30b1:
	/* 0x30b1: jmp    30c4 <generic_usdt_filter_arg_2+0x30c4> */
	goto x86_l_30c4;
x86_l_30b3:
	/* 0x30b3: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_30ba:
	/* 0x30ba: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30bf:
	/* 0x30bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30c4:
	/* 0x30c4: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30c9:
	/* 0x30c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30cb:
	/* 0x30cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30ce:
	/* 0x30ce: je     31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31f6;
	}
x86_l_30d4:
	/* 0x30d4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_30d7:
	/* 0x30d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30dc:
	/* 0x30dc: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30e1:
	/* 0x30e1: jmp    31e8 <generic_usdt_filter_arg_2+0x31e8> */
	goto x86_l_31e8;
x86_l_30e6:
	/* 0x30e6: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_30ed:
	/* 0x30ed: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30f2:
	/* 0x30f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30f7:
	/* 0x30f7: jmp    3130 <generic_usdt_filter_arg_2+0x3130> */
	goto x86_l_3130;
x86_l_30f9:
	/* 0x30f9: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3100:
	/* 0x3100: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3105:
	/* 0x3105: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_310a:
	/* 0x310a: jmp    3130 <generic_usdt_filter_arg_2+0x3130> */
	goto x86_l_3130;
x86_l_310c:
	/* 0x310c: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3113:
	/* 0x3113: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3118:
	/* 0x3118: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_311d:
	/* 0x311d: jmp    3130 <generic_usdt_filter_arg_2+0x3130> */
	goto x86_l_3130;
x86_l_311f:
	/* 0x311f: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3126:
	/* 0x3126: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_312b:
	/* 0x312b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3130:
	/* 0x3130: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3135:
	/* 0x3135: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3137:
	/* 0x3137: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_313a:
	/* 0x313a: je     3157 <generic_usdt_filter_arg_2+0x3157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3157;
	}
x86_l_313c:
	/* 0x313c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_313f:
	/* 0x313f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3144:
	/* 0x3144: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3149:
	/* 0x3149: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314b:
	/* 0x314b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_314e:
	/* 0x314e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3151:
	/* 0x3151: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_3155:
	/* 0x3155: jmp    315a <generic_usdt_filter_arg_2+0x315a> */
	goto x86_l_315a;
x86_l_3157:
	/* 0x3157: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_315a:
	/* 0x315a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_315e:
	/* 0x315e: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3161:
	/* 0x3161: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_3164:
	/* 0x3164: ja     321b <generic_usdt_filter_arg_2+0x321b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_321b;
	}
x86_l_316a:
	/* 0x316a: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_316c:
	/* 0x316c: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_3176:
	/* 0x3176: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_317a:
	/* 0x317a: jb     3217 <generic_usdt_filter_arg_2+0x3217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3217;
	}
x86_l_3180:
	/* 0x3180: jmp    321b <generic_usdt_filter_arg_2+0x321b> */
	goto x86_l_321b;
x86_l_3185:
	/* 0x3185: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_318c:
	/* 0x318c: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3191:
	/* 0x3191: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3196:
	/* 0x3196: jmp    31cf <generic_usdt_filter_arg_2+0x31cf> */
	goto x86_l_31cf;
x86_l_3198:
	/* 0x3198: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_319f:
	/* 0x319f: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31a4:
	/* 0x31a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31a9:
	/* 0x31a9: jmp    31cf <generic_usdt_filter_arg_2+0x31cf> */
	goto x86_l_31cf;
x86_l_31ab:
	/* 0x31ab: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_31b2:
	/* 0x31b2: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31b7:
	/* 0x31b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31bc:
	/* 0x31bc: jmp    31cf <generic_usdt_filter_arg_2+0x31cf> */
	goto x86_l_31cf;
x86_l_31be:
	/* 0x31be: mov    rdi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_31c5:
	/* 0x31c5: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31ca:
	/* 0x31ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31cf:
	/* 0x31cf: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31d4:
	/* 0x31d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d6:
	/* 0x31d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31d9:
	/* 0x31d9: je     31f6 <generic_usdt_filter_arg_2+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31f6;
	}
x86_l_31db:
	/* 0x31db: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_31de:
	/* 0x31de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31e3:
	/* 0x31e3: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31e8:
	/* 0x31e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ea:
	/* 0x31ea: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31ed:
	/* 0x31ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31f0:
	/* 0x31f0: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_31f4:
	/* 0x31f4: jmp    31f9 <generic_usdt_filter_arg_2+0x31f9> */
	goto x86_l_31f9;
x86_l_31f6:
	/* 0x31f6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31f9:
	/* 0x31f9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31fd:
	/* 0x31fd: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3200:
	/* 0x3200: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_3203:
	/* 0x3203: ja     321b <generic_usdt_filter_arg_2+0x321b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_321b;
	}
x86_l_3205:
	/* 0x3205: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3207:
	/* 0x3207: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_3211:
	/* 0x3211: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3215:
	/* 0x3215: jae    321b <generic_usdt_filter_arg_2+0x321b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_321b;
	}
x86_l_3217:
	/* 0x3217: xor    r12,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_321b:
	/* 0x321b: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_321e:
	/* 0x321e: je     322a <generic_usdt_filter_arg_2+0x322a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_322a;
	}
x86_l_3220:
	/* 0x3220: cmp    rbp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 1ULL);
x86_l_3224:
	/* 0x3224: je     32a1 <generic_usdt_filter_arg_2+0x32a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a1;
	}
x86_l_3226:
	/* 0x3226: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_3228:
	/* 0x3228: jne    327f <generic_usdt_filter_arg_2+0x327f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_327f;
	}
x86_l_322a:
	/* 0x322a: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_322e:
	/* 0x322e: jg     324f <generic_usdt_filter_arg_2+0x324f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_324f;
	}
x86_l_3230:
	/* 0x3230: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_3234:
	/* 0x3234: je     32cd <generic_usdt_filter_arg_2+0x32cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32cd;
	}
x86_l_323a:
	/* 0x323a: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_323d:
	/* 0x323d: je     32da <generic_usdt_filter_arg_2+0x32da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32da;
	}
x86_l_3243:
	/* 0x3243: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_3247:
	/* 0x3247: je     32ea <generic_usdt_filter_arg_2+0x32ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ea;
	}
x86_l_324d:
	/* 0x324d: jmp    326d <generic_usdt_filter_arg_2+0x326d> */
	goto x86_l_326d;
x86_l_324f:
	/* 0x324f: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_3253:
	/* 0x3253: je     32fa <generic_usdt_filter_arg_2+0x32fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32fa;
	}
x86_l_3259:
	/* 0x3259: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_325d:
	/* 0x325d: je     330a <generic_usdt_filter_arg_2+0x330a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_330a;
	}
x86_l_3263:
	/* 0x3263: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3267:
	/* 0x3267: je     331a <generic_usdt_filter_arg_2+0x331a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_331a;
	}
x86_l_326d:
	/* 0x326d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3271:
	/* 0x3271: jg     334c <generic_usdt_filter_arg_2+0x334c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_334c;
	}
x86_l_3277:
	/* 0x3277: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_327a:
	/* 0x327a: jmp    332a <generic_usdt_filter_arg_2+0x332a> */
	goto x86_l_332a;
x86_l_327f:
	/* 0x327f: mov    DWORD PTR [r14+0x5ef4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_3286:
	/* 0x3286: mov    rsi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_328d:
	/* 0x328d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3292:
	/* 0x3292: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3297:
	/* 0x3297: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_329a:
	/* 0x329a: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_329f:
	/* 0x329f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a1:
	/* 0x32a1: mov    rsi,QWORD PTR [rip+0xbe73] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_32a8:
	/* 0x32a8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_32ad:
	/* 0x32ad: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32b2:
	/* 0x32b2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_32b5:
	/* 0x32b5: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_32ba:
	/* 0x32ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32bc:
	/* 0x32bc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32be:
	/* 0x32be: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_32c5:
	/* 0x32c5: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_32c7:
	/* 0x32c7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_32c8:
	/* 0x32c8: jmp    3395 <generic_usdt_filter_arg_2+0x3395> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_32cd:
	/* 0x32cd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32d0:
	/* 0x32d0: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_32d8:
	/* 0x32d8: jne    332a <generic_usdt_filter_arg_2+0x332a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_332a;
	}
x86_l_32da:
	/* 0x32da: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_32e0:
	/* 0x32e0: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_32e8:
	/* 0x32e8: jne    332a <generic_usdt_filter_arg_2+0x332a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_332a;
	}
x86_l_32ea:
	/* 0x32ea: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_32f0:
	/* 0x32f0: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_32f8:
	/* 0x32f8: jne    332a <generic_usdt_filter_arg_2+0x332a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_332a;
	}
x86_l_32fa:
	/* 0x32fa: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_3300:
	/* 0x3300: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_3308:
	/* 0x3308: jne    332a <generic_usdt_filter_arg_2+0x332a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_332a;
	}
x86_l_330a:
	/* 0x330a: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3310:
	/* 0x3310: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_3318:
	/* 0x3318: jne    332a <generic_usdt_filter_arg_2+0x332a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_332a;
	}
x86_l_331a:
	/* 0x331a: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_3320:
	/* 0x3320: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_3328:
	/* 0x3328: je     334c <generic_usdt_filter_arg_2+0x334c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_334c;
	}
x86_l_332a:
	/* 0x332a: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_3331:
	/* 0x3331: mov    rsi,QWORD PTR [rip+0xbe76] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_3338:
	/* 0x3338: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_333d:
	/* 0x333d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3342:
	/* 0x3342: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3345:
	/* 0x3345: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_334a:
	/* 0x334a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334c:
	/* 0x334c: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3350:
	/* 0x3350: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3355:
	/* 0x3355: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3357:
	/* 0x3357: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_335c:
	/* 0x335c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3361:
	/* 0x3361: mov    rdi,QWORD PTR [rip+0xbe76] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3368:
	/* 0x3368: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_336d:
	/* 0x336d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3372:
	/* 0x3372: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3374:
	/* 0x3374: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3377:
	/* 0x3377: je     32bc <generic_usdt_filter_arg_2+0x32bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32bc;
	}
x86_l_337d:
	/* 0x337d: mov    rdi,QWORD PTR [rip+0xbe76] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3384:
	/* 0x3384: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3389:
	/* 0x3389: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_338e:
	/* 0x338e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3390:
	/* 0x3390: jmp    32bc <generic_usdt_filter_arg_2+0x32bc> */
	goto x86_l_32bc;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11456U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1782ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1788ULL && __x86_pc <= 3594ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3598ULL && __x86_pc <= 5454ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5459ULL && __x86_pc <= 7284ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7289ULL && __x86_pc <= 9125ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9132ULL && __x86_pc <= 10832ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10835ULL && __x86_pc <= 12429ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12436ULL && __x86_pc <= 13200ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

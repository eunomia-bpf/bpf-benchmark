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

static __noinline __u64 tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_0(
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
	case 119ULL: goto x86_l_77;
	case 121ULL: goto x86_l_79;
	case 124ULL: goto x86_l_7c;
	case 133ULL: goto x86_l_85;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 141ULL: goto x86_l_8d;
	case 145ULL: goto x86_l_91;
	case 149ULL: goto x86_l_95;
	case 152ULL: goto x86_l_98;
	case 159ULL: goto x86_l_9f;
	case 164ULL: goto x86_l_a4;
	case 166ULL: goto x86_l_a6;
	case 170ULL: goto x86_l_aa;
	case 178ULL: goto x86_l_b2;
	case 184ULL: goto x86_l_b8;
	case 187ULL: goto x86_l_bb;
	case 193ULL: goto x86_l_c1;
	case 196ULL: goto x86_l_c4;
	case 198ULL: goto x86_l_c6;
	case 201ULL: goto x86_l_c9;
	case 209ULL: goto x86_l_d1;
	case 215ULL: goto x86_l_d7;
	case 217ULL: goto x86_l_d9;
	case 223ULL: goto x86_l_df;
	case 226ULL: goto x86_l_e2;
	case 232ULL: goto x86_l_e8;
	case 234ULL: goto x86_l_ea;
	case 237ULL: goto x86_l_ed;
	case 245ULL: goto x86_l_f5;
	case 251ULL: goto x86_l_fb;
	case 254ULL: goto x86_l_fe;
	case 260ULL: goto x86_l_104;
	case 263ULL: goto x86_l_107;
	case 269ULL: goto x86_l_10d;
	case 272ULL: goto x86_l_110;
	case 278ULL: goto x86_l_116;
	case 280ULL: goto x86_l_118;
	case 285ULL: goto x86_l_11d;
	case 289ULL: goto x86_l_121;
	case 297ULL: goto x86_l_129;
	case 300ULL: goto x86_l_12c;
	case 305ULL: goto x86_l_131;
	case 310ULL: goto x86_l_136;
	case 318ULL: goto x86_l_13e;
	case 322ULL: goto x86_l_142;
	case 327ULL: goto x86_l_147;
	case 332ULL: goto x86_l_14c;
	case 337ULL: goto x86_l_151;
	case 344ULL: goto x86_l_158;
	case 349ULL: goto x86_l_15d;
	case 356ULL: goto x86_l_164;
	case 364ULL: goto x86_l_16c;
	case 367ULL: goto x86_l_16f;
	case 372ULL: goto x86_l_174;
	case 374ULL: goto x86_l_176;
	case 379ULL: goto x86_l_17b;
	case 386ULL: goto x86_l_182;
	case 389ULL: goto x86_l_185;
	case 394ULL: goto x86_l_18a;
	case 396ULL: goto x86_l_18c;
	case 398ULL: goto x86_l_18e;
	case 405ULL: goto x86_l_195;
	case 407ULL: goto x86_l_197;
	case 408ULL: goto x86_l_198;
	case 413ULL: goto x86_l_19d;
	case 415ULL: goto x86_l_19f;
	case 423ULL: goto x86_l_1a7;
	case 425ULL: goto x86_l_1a9;
	case 430ULL: goto x86_l_1ae;
	case 438ULL: goto x86_l_1b6;
	case 440ULL: goto x86_l_1b8;
	case 445ULL: goto x86_l_1bd;
	case 453ULL: goto x86_l_1c5;
	case 455ULL: goto x86_l_1c7;
	case 460ULL: goto x86_l_1cc;
	case 468ULL: goto x86_l_1d4;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 483ULL: goto x86_l_1e3;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 498ULL: goto x86_l_1f2;
	case 500ULL: goto x86_l_1f4;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 519ULL: goto x86_l_207;
	case 524ULL: goto x86_l_20c;
	case 526ULL: goto x86_l_20e;
	case 530ULL: goto x86_l_212;
	case 535ULL: goto x86_l_217;
	case 537ULL: goto x86_l_219;
	case 542ULL: goto x86_l_21e;
	case 547ULL: goto x86_l_223;
	case 552ULL: goto x86_l_228;
	case 559ULL: goto x86_l_22f;
	case 564ULL: goto x86_l_234;
	case 566ULL: goto x86_l_236;
	case 569ULL: goto x86_l_239;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 587ULL: goto x86_l_24b;
	case 592ULL: goto x86_l_250;
	case 594ULL: goto x86_l_252;
	case 599ULL: goto x86_l_257;
	case 601ULL: goto x86_l_259;
	case 604ULL: goto x86_l_25c;
	case 607ULL: goto x86_l_25f;
	case 610ULL: goto x86_l_262;
	case 618ULL: goto x86_l_26a;
	case 624ULL: goto x86_l_270;
	case 627ULL: goto x86_l_273;
	case 631ULL: goto x86_l_277;
	case 637ULL: goto x86_l_27d;
	case 645ULL: goto x86_l_285;
	case 650ULL: goto x86_l_28a;
	case 657ULL: goto x86_l_291;
	case 663ULL: goto x86_l_297;
	case 666ULL: goto x86_l_29a;
	case 673ULL: goto x86_l_2a1;
	case 678ULL: goto x86_l_2a6;
	case 681ULL: goto x86_l_2a9;
	case 687ULL: goto x86_l_2af;
	case 690ULL: goto x86_l_2b2;
	case 694ULL: goto x86_l_2b6;
	case 698ULL: goto x86_l_2ba;
	case 704ULL: goto x86_l_2c0;
	case 713ULL: goto x86_l_2c9;
	case 719ULL: goto x86_l_2cf;
	case 727ULL: goto x86_l_2d7;
	case 733ULL: goto x86_l_2dd;
	case 737ULL: goto x86_l_2e1;
	case 744ULL: goto x86_l_2e8;
	case 749ULL: goto x86_l_2ed;
	case 752ULL: goto x86_l_2f0;
	case 754ULL: goto x86_l_2f2;
	case 757ULL: goto x86_l_2f5;
	case 759ULL: goto x86_l_2f7;
	case 762ULL: goto x86_l_2fa;
	case 765ULL: goto x86_l_2fd;
	case 771ULL: goto x86_l_303;
	case 774ULL: goto x86_l_306;
	case 780ULL: goto x86_l_30c;
	case 785ULL: goto x86_l_311;
	case 788ULL: goto x86_l_314;
	case 790ULL: goto x86_l_316;
	case 793ULL: goto x86_l_319;
	case 796ULL: goto x86_l_31c;
	case 798ULL: goto x86_l_31e;
	case 801ULL: goto x86_l_321;
	case 804ULL: goto x86_l_324;
	case 810ULL: goto x86_l_32a;
	case 813ULL: goto x86_l_32d;
	case 819ULL: goto x86_l_333;
	case 823ULL: goto x86_l_337;
	case 828ULL: goto x86_l_33c;
	case 831ULL: goto x86_l_33f;
	case 837ULL: goto x86_l_345;
	case 840ULL: goto x86_l_348;
	case 843ULL: goto x86_l_34b;
	case 849ULL: goto x86_l_351;
	case 852ULL: goto x86_l_354;
	case 855ULL: goto x86_l_357;
	case 861ULL: goto x86_l_35d;
	case 866ULL: goto x86_l_362;
	case 869ULL: goto x86_l_365;
	case 875ULL: goto x86_l_36b;
	case 878ULL: goto x86_l_36e;
	case 880ULL: goto x86_l_370;
	case 883ULL: goto x86_l_373;
	case 889ULL: goto x86_l_379;
	case 892ULL: goto x86_l_37c;
	case 898ULL: goto x86_l_382;
	case 901ULL: goto x86_l_385;
	case 907ULL: goto x86_l_38b;
	case 910ULL: goto x86_l_38e;
	case 916ULL: goto x86_l_394;
	case 918ULL: goto x86_l_396;
	case 928ULL: goto x86_l_3a0;
	case 932ULL: goto x86_l_3a4;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 947ULL: goto x86_l_3b3;
	case 953ULL: goto x86_l_3b9;
	case 963ULL: goto x86_l_3c3;
	case 967ULL: goto x86_l_3c7;
	case 973ULL: goto x86_l_3cd;
	case 976ULL: goto x86_l_3d0;
	case 982ULL: goto x86_l_3d6;
	case 984ULL: goto x86_l_3d8;
	case 989ULL: goto x86_l_3dd;
	case 993ULL: goto x86_l_3e1;
	case 999ULL: goto x86_l_3e7;
	case 1004ULL: goto x86_l_3ec;
	case 1007ULL: goto x86_l_3ef;
	case 1013ULL: goto x86_l_3f5;
	case 1016ULL: goto x86_l_3f8;
	case 1019ULL: goto x86_l_3fb;
	case 1025ULL: goto x86_l_401;
	case 1030ULL: goto x86_l_406;
	case 1032ULL: goto x86_l_408;
	case 1038ULL: goto x86_l_40e;
	case 1043ULL: goto x86_l_413;
	case 1046ULL: goto x86_l_416;
	case 1049ULL: goto x86_l_419;
	case 1055ULL: goto x86_l_41f;
	case 1058ULL: goto x86_l_422;
	case 1064ULL: goto x86_l_428;
	case 1067ULL: goto x86_l_42b;
	case 1073ULL: goto x86_l_431;
	case 1078ULL: goto x86_l_436;
	case 1081ULL: goto x86_l_439;
	case 1083ULL: goto x86_l_43b;
	case 1086ULL: goto x86_l_43e;
	case 1088ULL: goto x86_l_440;
	case 1091ULL: goto x86_l_443;
	case 1097ULL: goto x86_l_449;
	case 1106ULL: goto x86_l_452;
	case 1115ULL: goto x86_l_45b;
	case 1124ULL: goto x86_l_464;
	case 1133ULL: goto x86_l_46d;
	case 1142ULL: goto x86_l_476;
	case 1145ULL: goto x86_l_479;
	case 1151ULL: goto x86_l_47f;
	case 1154ULL: goto x86_l_482;
	case 1160ULL: goto x86_l_488;
	case 1163ULL: goto x86_l_48b;
	case 1168ULL: goto x86_l_490;
	case 1171ULL: goto x86_l_493;
	case 1177ULL: goto x86_l_499;
	case 1182ULL: goto x86_l_49e;
	case 1186ULL: goto x86_l_4a2;
	case 1190ULL: goto x86_l_4a6;
	case 1195ULL: goto x86_l_4ab;
	case 1198ULL: goto x86_l_4ae;
	case 1204ULL: goto x86_l_4b4;
	case 1207ULL: goto x86_l_4b7;
	case 1210ULL: goto x86_l_4ba;
	case 1216ULL: goto x86_l_4c0;
	case 1219ULL: goto x86_l_4c3;
	case 1225ULL: goto x86_l_4c9;
	case 1230ULL: goto x86_l_4ce;
	case 1233ULL: goto x86_l_4d1;
	case 1239ULL: goto x86_l_4d7;
	case 1244ULL: goto x86_l_4dc;
	case 1247ULL: goto x86_l_4df;
	case 1253ULL: goto x86_l_4e5;
	case 1256ULL: goto x86_l_4e8;
	case 1262ULL: goto x86_l_4ee;
	case 1265ULL: goto x86_l_4f1;
	case 1268ULL: goto x86_l_4f4;
	case 1274ULL: goto x86_l_4fa;
	case 1277ULL: goto x86_l_4fd;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1291ULL: goto x86_l_50b;
	case 1297ULL: goto x86_l_511;
	case 1300ULL: goto x86_l_514;
	case 1306ULL: goto x86_l_51a;
	case 1309ULL: goto x86_l_51d;
	case 1313ULL: goto x86_l_521;
	case 1318ULL: goto x86_l_526;
	case 1322ULL: goto x86_l_52a;
	case 1325ULL: goto x86_l_52d;
	case 1331ULL: goto x86_l_533;
	case 1334ULL: goto x86_l_536;
	case 1337ULL: goto x86_l_539;
	case 1343ULL: goto x86_l_53f;
	case 1351ULL: goto x86_l_547;
	case 1357ULL: goto x86_l_54d;
	case 1360ULL: goto x86_l_550;
	case 1366ULL: goto x86_l_556;
	case 1370ULL: goto x86_l_55a;
	case 1376ULL: goto x86_l_560;
	case 1379ULL: goto x86_l_563;
	case 1382ULL: goto x86_l_566;
	case 1385ULL: goto x86_l_569;
	case 1387ULL: goto x86_l_56b;
	case 1389ULL: goto x86_l_56d;
	case 1392ULL: goto x86_l_570;
	case 1394ULL: goto x86_l_572;
	case 1397ULL: goto x86_l_575;
	case 1399ULL: goto x86_l_577;
	case 1401ULL: goto x86_l_579;
	case 1404ULL: goto x86_l_57c;
	case 1407ULL: goto x86_l_57f;
	case 1409ULL: goto x86_l_581;
	case 1411ULL: goto x86_l_583;
	case 1414ULL: goto x86_l_586;
	case 1418ULL: goto x86_l_58a;
	case 1422ULL: goto x86_l_58e;
	case 1428ULL: goto x86_l_594;
	case 1432ULL: goto x86_l_598;
	case 1438ULL: goto x86_l_59e;
	case 1441ULL: goto x86_l_5a1;
	case 1443ULL: goto x86_l_5a3;
	case 1448ULL: goto x86_l_5a8;
	case 1452ULL: goto x86_l_5ac;
	case 1454ULL: goto x86_l_5ae;
	case 1457ULL: goto x86_l_5b1;
	case 1460ULL: goto x86_l_5b4;
	case 1462ULL: goto x86_l_5b6;
	case 1464ULL: goto x86_l_5b8;
	case 1470ULL: goto x86_l_5be;
	case 1473ULL: goto x86_l_5c1;
	case 1479ULL: goto x86_l_5c7;
	case 1481ULL: goto x86_l_5c9;
	case 1486ULL: goto x86_l_5ce;
	case 1490ULL: goto x86_l_5d2;
	case 1496ULL: goto x86_l_5d8;
	case 1501ULL: goto x86_l_5dd;
	case 1505ULL: goto x86_l_5e1;
	case 1511ULL: goto x86_l_5e7;
	case 1521ULL: goto x86_l_5f1;
	case 1525ULL: goto x86_l_5f5;
	case 1531ULL: goto x86_l_5fb;
	case 1538ULL: goto x86_l_602;
	case 1544ULL: goto x86_l_608;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1559ULL: goto x86_l_617;
	case 1563ULL: goto x86_l_61b;
	case 1567ULL: goto x86_l_61f;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1579ULL: goto x86_l_62b;
	case 1584ULL: goto x86_l_630;
	case 1586ULL: goto x86_l_632;
	case 1592ULL: goto x86_l_638;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1607ULL: goto x86_l_647;
	case 1609ULL: goto x86_l_649;
	case 1615ULL: goto x86_l_64f;
	case 1620ULL: goto x86_l_654;
	case 1623ULL: goto x86_l_657;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1637ULL: goto x86_l_665;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1650ULL: goto x86_l_672;
	case 1656ULL: goto x86_l_678;
	case 1658ULL: goto x86_l_67a;
	case 1664ULL: goto x86_l_680;
	case 1667ULL: goto x86_l_683;
	case 1673ULL: goto x86_l_689;
	case 1678ULL: goto x86_l_68e;
	case 1680ULL: goto x86_l_690;
	case 1686ULL: goto x86_l_696;
	case 1688ULL: goto x86_l_698;
	case 1694ULL: goto x86_l_69e;
	case 1697ULL: goto x86_l_6a1;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1710ULL: goto x86_l_6ae;
	case 1716ULL: goto x86_l_6b4;
	case 1718ULL: goto x86_l_6b6;
	case 1720ULL: goto x86_l_6b8;
	case 1723ULL: goto x86_l_6bb;
	case 1728ULL: goto x86_l_6c0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_a:
	/* 0xa: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     18c <generic_retkprobe_filter_arg+0x18c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18c;
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
	/* 0x58: je     176 <generic_retkprobe_filter_arg+0x176> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176;
	}
x86_l_5e:
	/* 0x5e: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_66:
	/* 0x66: je     176 <generic_retkprobe_filter_arg+0x176> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176;
	}
x86_l_6c:
	/* 0x6c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: mov    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_77:
	/* 0x77: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_79:
	/* 0x79: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_7c:
	/* 0x7c: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_85:
	/* 0x85: je     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1;
	}
x86_l_87:
	/* 0x87: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_89:
	/* 0x89: mov    ecx,DWORD PTR [rdi+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_8d:
	/* 0x8d: lea    r11,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_91:
	/* 0x91: add    r11,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_95:
	/* 0x95: mov    r9d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R11, X86_WIDTH_32);
x86_l_98:
	/* 0x98: and    r9d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_9f:
	/* 0x9f: cmp    DWORD PTR [rdi+r9*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 25ULL);
x86_l_a4:
	/* 0xa4: jae    11d <generic_retkprobe_filter_arg+0x11d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_11d;
	}
x86_l_a6:
	/* 0xa6: cmp    r9,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 1ULL);
x86_l_aa:
	/* 0xaa: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b2:
	/* 0xb2: je     176 <generic_retkprobe_filter_arg+0x176> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176;
	}
x86_l_b8:
	/* 0xb8: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_bb:
	/* 0xbb: jne    151 <generic_retkprobe_filter_arg+0x151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_151;
	}
x86_l_c1:
	/* 0xc1: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_c4:
	/* 0xc4: jg     ea <generic_retkprobe_filter_arg+0xea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ea;
	}
x86_l_c6:
	/* 0xc6: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_c9:
	/* 0xc9: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d1:
	/* 0xd1: je     19d <generic_retkprobe_filter_arg+0x19d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19d;
	}
x86_l_d7:
	/* 0xd7: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_d9:
	/* 0xd9: je     1a9 <generic_retkprobe_filter_arg+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a9;
	}
x86_l_df:
	/* 0xdf: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_e2:
	/* 0xe2: je     1b8 <generic_retkprobe_filter_arg+0x1b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b8;
	}
x86_l_e8:
	/* 0xe8: jmp    10d <generic_retkprobe_filter_arg+0x10d> */
	goto x86_l_10d;
x86_l_ea:
	/* 0xea: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_ed:
	/* 0xed: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_f5:
	/* 0xf5: je     1c7 <generic_retkprobe_filter_arg+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c7;
	}
x86_l_fb:
	/* 0xfb: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_fe:
	/* 0xfe: je     1d6 <generic_retkprobe_filter_arg+0x1d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d6;
	}
x86_l_104:
	/* 0x104: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_107:
	/* 0x107: je     1e5 <generic_retkprobe_filter_arg+0x1e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e5;
	}
x86_l_10d:
	/* 0x10d: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_110:
	/* 0x110: jg     20e <generic_retkprobe_filter_arg+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_20e;
	}
x86_l_116:
	/* 0x116: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_118:
	/* 0x118: jmp    1f4 <generic_retkprobe_filter_arg+0x1f4> */
	goto x86_l_1f4;
x86_l_11d:
	/* 0x11d: lea    rax,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_121:
	/* 0x121: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_129:
	/* 0x129: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c:
	/* 0x12c: lea    rax,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_131:
	/* 0x131: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_136:
	/* 0x136: mov    QWORD PTR [rsp+0x98],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_13e:
	/* 0x13e: mov    QWORD PTR [rsp],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_142:
	/* 0x142: mov    QWORD PTR [rsp+0x8],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_147:
	/* 0x147: mov    QWORD PTR [rsp+0x10],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14c:
	/* 0x14c: jmp    27d <generic_retkprobe_filter_arg+0x27d> */
	goto x86_l_27d;
x86_l_151:
	/* 0x151: mov    DWORD PTR [r14+0x5f04],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_158:
	/* 0x158: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_15d:
	/* 0x15d: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_164:
	/* 0x164: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16c:
	/* 0x16c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_16f:
	/* 0x16f: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_174:
	/* 0x174: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176:
	/* 0x176: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_17b:
	/* 0x17b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_182:
	/* 0x182: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_185:
	/* 0x185: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_18a:
	/* 0x18a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c:
	/* 0x18c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18e:
	/* 0x18e: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_195:
	/* 0x195: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_197:
	/* 0x197: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_198:
	/* 0x198: jmp    3505 <native_bpf_strncasestr+0x72> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_19d:
	/* 0x19d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19f:
	/* 0x19f: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_1a7:
	/* 0x1a7: jne    1f4 <generic_retkprobe_filter_arg+0x1f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f4;
	}
x86_l_1a9:
	/* 0x1a9: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1ae:
	/* 0x1ae: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_1b6:
	/* 0x1b6: jne    1f4 <generic_retkprobe_filter_arg+0x1f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f4;
	}
x86_l_1b8:
	/* 0x1b8: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1bd:
	/* 0x1bd: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_1c5:
	/* 0x1c5: jne    1f4 <generic_retkprobe_filter_arg+0x1f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f4;
	}
x86_l_1c7:
	/* 0x1c7: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1cc:
	/* 0x1cc: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_1d4:
	/* 0x1d4: jne    1f4 <generic_retkprobe_filter_arg+0x1f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f4;
	}
x86_l_1d6:
	/* 0x1d6: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1db:
	/* 0x1db: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_1e3:
	/* 0x1e3: jne    1f4 <generic_retkprobe_filter_arg+0x1f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f4;
	}
x86_l_1e5:
	/* 0x1e5: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1ea:
	/* 0x1ea: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_1f2:
	/* 0x1f2: je     20e <generic_retkprobe_filter_arg+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_1f4:
	/* 0x1f4: mov    DWORD PTR [r14+0x5f00],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_1fb:
	/* 0x1fb: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_200:
	/* 0x200: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_207:
	/* 0x207: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_20c:
	/* 0x20c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e:
	/* 0x20e: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_212:
	/* 0x212: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_217:
	/* 0x217: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219:
	/* 0x219: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21e:
	/* 0x21e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_223:
	/* 0x223: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_228:
	/* 0x228: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_22f:
	/* 0x22f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_234:
	/* 0x234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236:
	/* 0x236: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_239:
	/* 0x239: je     18c <generic_retkprobe_filter_arg+0x18c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18c;
	}
x86_l_23f:
	/* 0x23f: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_244:
	/* 0x244: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_24b:
	/* 0x24b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_250:
	/* 0x250: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252:
	/* 0x252: jmp    18c <generic_retkprobe_filter_arg+0x18c> */
	goto x86_l_18c;
x86_l_257:
	/* 0x257: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_259:
	/* 0x259: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_25c:
	/* 0x25c: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_25f:
	/* 0x25f: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_262:
	/* 0x262: mov    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_26a:
	/* 0x26a: je     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1;
	}
x86_l_270:
	/* 0x270: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_273:
	/* 0x273: cmp    r15,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 5ULL);
x86_l_277:
	/* 0x277: je     a6 <generic_retkprobe_filter_arg+0xa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6;
	}
x86_l_27d:
	/* 0x27d: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_285:
	/* 0x285: mov    r12d,DWORD PTR [rax+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_28a:
	/* 0x28a: test   r12d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_291:
	/* 0x291: je     a6 <generic_retkprobe_filter_arg+0xa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6;
	}
x86_l_297:
	/* 0x297: add    r12d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_29a:
	/* 0x29a: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2a1:
	/* 0x2a1: mov    eax,DWORD PTR [rdi+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_2a6:
	/* 0x2a6: cmp    eax,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2a9:
	/* 0x2a9: je     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1;
	}
x86_l_2af:
	/* 0x2af: add    r12,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b2:
	/* 0x2b2: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b6:
	/* 0x2b6: cmp    rcx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4ULL);
x86_l_2ba:
	/* 0x2ba: ja     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c1;
	}
x86_l_2c0:
	/* 0x2c0: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_2c9:
	/* 0x2c9: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c1;
	}
x86_l_2cf:
	/* 0x2cf: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_2d7:
	/* 0x2d7: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2dd:
	/* 0x2dd: lea    r13,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e1:
	/* 0x2e1: add    r13,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2e8:
	/* 0x2e8: mov    ecx,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ed:
	/* 0x2ed: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_2f0:
	/* 0x2f0: jle    311 <generic_retkprobe_filter_arg+0x311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_311;
	}
x86_l_2f2:
	/* 0x2f2: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_2f5:
	/* 0x2f5: jg     33c <generic_retkprobe_filter_arg+0x33c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_33c;
	}
x86_l_2f7:
	/* 0x2f7: lea    edx,[rcx-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_2fa:
	/* 0x2fa: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2fd:
	/* 0x2fd: jb     382 <generic_retkprobe_filter_arg+0x382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_382;
	}
x86_l_303:
	/* 0x303: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_306:
	/* 0x306: je     5a8 <generic_retkprobe_filter_arg+0x5a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a8;
	}
x86_l_30c:
	/* 0x30c: jmp    270 <generic_retkprobe_filter_arg+0x270> */
	goto x86_l_270;
x86_l_311:
	/* 0x311: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_314:
	/* 0x314: jle    362 <generic_retkprobe_filter_arg+0x362> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_362;
	}
x86_l_316:
	/* 0x316: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_319:
	/* 0x319: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_31c:
	/* 0x31c: jb     382 <generic_retkprobe_filter_arg+0x382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_382;
	}
x86_l_31e:
	/* 0x31e: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_321:
	/* 0x321: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_324:
	/* 0x324: jb     5a8 <generic_retkprobe_filter_arg+0x5a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5a8;
	}
x86_l_32a:
	/* 0x32a: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_32d:
	/* 0x32d: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270;
	}
x86_l_333:
	/* 0x333: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_337:
	/* 0x337: jmp    5a8 <generic_retkprobe_filter_arg+0x5a8> */
	goto x86_l_5a8;
x86_l_33c:
	/* 0x33c: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_33f:
	/* 0x33f: jg     508 <generic_retkprobe_filter_arg+0x508> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_508;
	}
x86_l_345:
	/* 0x345: lea    edx,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_348:
	/* 0x348: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_34b:
	/* 0x34b: jb     49e <generic_retkprobe_filter_arg+0x49e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_49e;
	}
x86_l_351:
	/* 0x351: lea    edx,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_354:
	/* 0x354: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_357:
	/* 0x357: jb     449 <generic_retkprobe_filter_arg+0x449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_449;
	}
x86_l_35d:
	/* 0x35d: jmp    270 <generic_retkprobe_filter_arg+0x270> */
	goto x86_l_270;
x86_l_362:
	/* 0x362: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_365:
	/* 0x365: jg     436 <generic_retkprobe_filter_arg+0x436> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_436;
	}
x86_l_36b:
	/* 0x36b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_36e:
	/* 0x36e: je     382 <generic_retkprobe_filter_arg+0x382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_382;
	}
x86_l_370:
	/* 0x370: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_373:
	/* 0x373: je     b2f <generic_retkprobe_filter_arg+0xb2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2863ULL;
	}
x86_l_379:
	/* 0x379: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_37c:
	/* 0x37c: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270;
	}
x86_l_382:
	/* 0x382: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_385:
	/* 0x385: jle    413 <generic_retkprobe_filter_arg+0x413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_413;
	}
x86_l_38b:
	/* 0x38b: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_38e:
	/* 0x38e: ja     6c0 <generic_retkprobe_filter_arg+0x6c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_6c0;
	}
x86_l_394:
	/* 0x394: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_396:
	/* 0x396: movabs rsi,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 128849018880ULL);
x86_l_3a0:
	/* 0x3a0: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3a4:
	/* 0x3a4: jb     4dc <generic_retkprobe_filter_arg+0x4dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4dc;
	}
x86_l_3aa:
	/* 0x3aa: mov    esi,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1610612736ULL);
x86_l_3af:
	/* 0x3af: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3b3:
	/* 0x3b3: jb     906 <generic_retkprobe_filter_arg+0x906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2310ULL;
	}
x86_l_3b9:
	/* 0x3b9: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_3c3:
	/* 0x3c3: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3c7:
	/* 0x3c7: jae    6c0 <generic_retkprobe_filter_arg+0x6c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_6c0;
	}
x86_l_3cd:
	/* 0x3cd: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_3d0:
	/* 0x3d0: ja     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c1;
	}
x86_l_3d6:
	/* 0x3d6: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3d8:
	/* 0x3d8: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_3dd:
	/* 0x3dd: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3e1:
	/* 0x3e1: jae    1032 <generic_retkprobe_filter_arg+0x1032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4146ULL;
	}
x86_l_3e7:
	/* 0x3e7: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ec:
	/* 0x3ec: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ef:
	/* 0x3ef: jle    156c <generic_retkprobe_filter_arg+0x156c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5484ULL;
	}
x86_l_3f5:
	/* 0x3f5: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3f8:
	/* 0x3f8: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fb:
	/* 0x3fb: jae    1cce <generic_retkprobe_filter_arg+0x1cce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7374ULL;
	}
x86_l_401:
	/* 0x401: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_406:
	/* 0x406: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_408:
	/* 0x408: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_257;
	}
x86_l_40e:
	/* 0x40e: jmp    1df4 <generic_retkprobe_filter_arg+0x1df4> */
	return 7668ULL;
x86_l_413:
	/* 0x413: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_416:
	/* 0x416: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_419:
	/* 0x419: jb     ba9 <generic_retkprobe_filter_arg+0xba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2985ULL;
	}
x86_l_41f:
	/* 0x41f: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_422:
	/* 0x422: je     6cc <generic_retkprobe_filter_arg+0x6cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1740ULL;
	}
x86_l_428:
	/* 0x428: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_42b:
	/* 0x42b: je     6cc <generic_retkprobe_filter_arg+0x6cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1740ULL;
	}
x86_l_431:
	/* 0x431: jmp    270 <generic_retkprobe_filter_arg+0x270> */
	goto x86_l_270;
x86_l_436:
	/* 0x436: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_439:
	/* 0x439: je     449 <generic_retkprobe_filter_arg+0x449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_449;
	}
x86_l_43b:
	/* 0x43b: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_43e:
	/* 0x43e: je     49e <generic_retkprobe_filter_arg+0x49e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49e;
	}
x86_l_440:
	/* 0x440: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_443:
	/* 0x443: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270;
	}
x86_l_449:
	/* 0x449: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_452:
	/* 0x452: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_45b:
	/* 0x45b: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_464:
	/* 0x464: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_46d:
	/* 0x46d: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_476:
	/* 0x476: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_479:
	/* 0x479: jg     70b <generic_retkprobe_filter_arg+0x70b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1803ULL;
	}
x86_l_47f:
	/* 0x47f: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_482:
	/* 0x482: je     d03 <generic_retkprobe_filter_arg+0xd03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3331ULL;
	}
x86_l_488:
	/* 0x488: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_48b:
	/* 0x48b: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_490:
	/* 0x490: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_493:
	/* 0x493: je     d05 <generic_retkprobe_filter_arg+0xd05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3333ULL;
	}
x86_l_499:
	/* 0x499: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	goto x86_l_25f;
x86_l_49e:
	/* 0x49e: mov    ebp,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a2:
	/* 0x4a2: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4a6:
	/* 0x4a6: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ab:
	/* 0x4ab: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_4ae:
	/* 0x4ae: jg     790 <generic_retkprobe_filter_arg+0x790> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1936ULL;
	}
x86_l_4b4:
	/* 0x4b4: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_4b7:
	/* 0x4b7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4ba:
	/* 0x4ba: jb     f55 <generic_retkprobe_filter_arg+0xf55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3925ULL;
	}
x86_l_4c0:
	/* 0x4c0: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4c3:
	/* 0x4c3: je     ec0 <generic_retkprobe_filter_arg+0xec0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3776ULL;
	}
x86_l_4c9:
	/* 0x4c9: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_4ce:
	/* 0x4ce: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_4d1:
	/* 0x4d1: je     7b0 <generic_retkprobe_filter_arg+0x7b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1968ULL;
	}
x86_l_4d7:
	/* 0x4d7: jmp    3423 <generic_retkprobe_filter_arg+0x3423> */
	return 13347ULL;
x86_l_4dc:
	/* 0x4dc: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_4df:
	/* 0x4df: jle    b1e <generic_retkprobe_filter_arg+0xb1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2846ULL;
	}
x86_l_4e5:
	/* 0x4e5: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_4e8:
	/* 0x4e8: jg     e78 <generic_retkprobe_filter_arg+0xe78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3704ULL;
	}
x86_l_4ee:
	/* 0x4ee: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_4f1:
	/* 0x4f1: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4f4:
	/* 0x4f4: jb     c37 <generic_retkprobe_filter_arg+0xc37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3127ULL;
	}
x86_l_4fa:
	/* 0x4fa: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4fd:
	/* 0x4fd: je     bbf <generic_retkprobe_filter_arg+0xbbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3007ULL;
	}
x86_l_503:
	/* 0x503: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	goto x86_l_c1;
x86_l_508:
	/* 0x508: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_50b:
	/* 0x50b: je     5a8 <generic_retkprobe_filter_arg+0x5a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a8;
	}
x86_l_511:
	/* 0x511: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_514:
	/* 0x514: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270;
	}
x86_l_51a:
	/* 0x51a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_51d:
	/* 0x51d: lea    rbp,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_521:
	/* 0x521: movzx  esi,BYTE PTR [r13+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_526:
	/* 0x526: movzx  edx,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_52a:
	/* 0x52a: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_52d:
	/* 0x52d: jg     1305 <generic_retkprobe_filter_arg+0x1305> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4869ULL;
	}
x86_l_533:
	/* 0x533: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_536:
	/* 0x536: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_539:
	/* 0x539: jae    185a <generic_retkprobe_filter_arg+0x185a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6234ULL;
	}
x86_l_53f:
	/* 0x53f: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_547:
	/* 0x547: mov    r8d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 256ULL);
x86_l_54d:
	/* 0x54d: cmp    dl,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 144ULL);
x86_l_550:
	/* 0x550: ja     1628 <generic_retkprobe_filter_arg+0x1628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5672ULL;
	}
x86_l_556:
	/* 0x556: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_55a:
	/* 0x55a: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_560:
	/* 0x560: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_563:
	/* 0x563: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_566:
	/* 0x566: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_569:
	/* 0x569: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_56b:
	/* 0x56b: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_56d:
	/* 0x56d: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_570:
	/* 0x570: je     579 <generic_retkprobe_filter_arg+0x579> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_579;
	}
x86_l_572:
	/* 0x572: mov    r8d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_575:
	/* 0x575: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_577:
	/* 0x577: je     594 <generic_retkprobe_filter_arg+0x594> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_594;
	}
x86_l_579:
	/* 0x579: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_57c:
	/* 0x57c: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_57f:
	/* 0x57f: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_581:
	/* 0x581: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_583:
	/* 0x583: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_586:
	/* 0x586: movzx  r8d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_58a:
	/* 0x58a: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_58e:
	/* 0x58e: ja     1628 <generic_retkprobe_filter_arg+0x1628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5672ULL;
	}
x86_l_594:
	/* 0x594: movzx  eax,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_598:
	/* 0x598: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_59e:
	/* 0x59e: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_5a1:
	/* 0x5a1: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_5a3:
	/* 0x5a3: jmp    2438 <generic_retkprobe_filter_arg+0x2438> */
	return 9272ULL;
x86_l_5a8:
	/* 0x5a8: mov    ebp,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ac:
	/* 0x5ac: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5ae:
	/* 0x5ae: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_5b1:
	/* 0x5b1: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_5b4:
	/* 0x5b4: je     5be <generic_retkprobe_filter_arg+0x5be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5be;
	}
x86_l_5b6:
	/* 0x5b6: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_5b8:
	/* 0x5b8: je     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1;
	}
x86_l_5be:
	/* 0x5be: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_5c1:
	/* 0x5c1: ja     8e3 <generic_retkprobe_filter_arg+0x8e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2275ULL;
	}
x86_l_5c7:
	/* 0x5c7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5c9:
	/* 0x5c9: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_5ce:
	/* 0x5ce: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5d2:
	/* 0x5d2: jb     a7e <generic_retkprobe_filter_arg+0xa7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2686ULL;
	}
x86_l_5d8:
	/* 0x5d8: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_5dd:
	/* 0x5dd: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5e1:
	/* 0x5e1: jb     94c <generic_retkprobe_filter_arg+0x94c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2380ULL;
	}
x86_l_5e7:
	/* 0x5e7: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_5f1:
	/* 0x5f1: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5f5:
	/* 0x5f5: jae    8e3 <generic_retkprobe_filter_arg+0x8e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2275ULL;
	}
x86_l_5fb:
	/* 0x5fb: mov    WORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_602:
	/* 0x602: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_608:
	/* 0x608: ja     8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2303ULL;
	}
x86_l_60e:
	/* 0x60e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_613:
	/* 0x613: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_617:
	/* 0x617: lea    rdx,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_61b:
	/* 0x61b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_61f:
	/* 0x61f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_624:
	/* 0x624: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_629:
	/* 0x629: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62b:
	/* 0x62b: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_630:
	/* 0x630: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_632:
	/* 0x632: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12470ULL;
	}
x86_l_638:
	/* 0x638: movzx  eax,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_63d:
	/* 0x63d: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_642:
	/* 0x642: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_647:
	/* 0x647: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_649:
	/* 0x649: je     30b8 <generic_retkprobe_filter_arg+0x30b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12472ULL;
	}
x86_l_64f:
	/* 0x64f: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_654:
	/* 0x654: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_657:
	/* 0x657: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65b:
	/* 0x65b: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_660:
	/* 0x660: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_665:
	/* 0x665: jb     8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2303ULL;
	}
x86_l_66b:
	/* 0x66b: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_670:
	/* 0x670: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_672:
	/* 0x672: je     8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2303ULL;
	}
x86_l_678:
	/* 0x678: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_67a:
	/* 0x67a: je     30c6 <generic_retkprobe_filter_arg+0x30c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12486ULL;
	}
x86_l_680:
	/* 0x680: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_683:
	/* 0x683: jb     8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2303ULL;
	}
x86_l_689:
	/* 0x689: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68e:
	/* 0x68e: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_690:
	/* 0x690: je     8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2303ULL;
	}
x86_l_696:
	/* 0x696: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_698:
	/* 0x698: je     30c6 <generic_retkprobe_filter_arg+0x30c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12486ULL;
	}
x86_l_69e:
	/* 0x69e: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_6a1:
	/* 0x6a1: jb     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12470ULL;
	}
x86_l_6a7:
	/* 0x6a7: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_6ac:
	/* 0x6ac: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6ae:
	/* 0x6ae: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12470ULL;
	}
x86_l_6b4:
	/* 0x6b4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b6:
	/* 0x6b6: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6b8:
	/* 0x6b8: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_6bb:
	/* 0x6bb: jmp    30b8 <generic_retkprobe_filter_arg+0x30b8> */
	return 12472ULL;
x86_l_6c0:
	/* 0x6c0: lea    edx,[rcx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
	return 1731ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1731ULL: goto x86_l_6c3;
	case 1734ULL: goto x86_l_6c6;
	case 1740ULL: goto x86_l_6cc;
	case 1743ULL: goto x86_l_6cf;
	case 1749ULL: goto x86_l_6d5;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1760ULL: goto x86_l_6e0;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1770ULL: goto x86_l_6ea;
	case 1776ULL: goto x86_l_6f0;
	case 1779ULL: goto x86_l_6f3;
	case 1782ULL: goto x86_l_6f6;
	case 1788ULL: goto x86_l_6fc;
	case 1792ULL: goto x86_l_700;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1806ULL: goto x86_l_70e;
	case 1812ULL: goto x86_l_714;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1823ULL: goto x86_l_71f;
	case 1829ULL: goto x86_l_725;
	case 1834ULL: goto x86_l_72a;
	case 1839ULL: goto x86_l_72f;
	case 1843ULL: goto x86_l_733;
	case 1849ULL: goto x86_l_739;
	case 1859ULL: goto x86_l_743;
	case 1863ULL: goto x86_l_747;
	case 1869ULL: goto x86_l_74d;
	case 1872ULL: goto x86_l_750;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1888ULL: goto x86_l_760;
	case 1891ULL: goto x86_l_763;
	case 1897ULL: goto x86_l_769;
	case 1902ULL: goto x86_l_76e;
	case 1905ULL: goto x86_l_771;
	case 1911ULL: goto x86_l_777;
	case 1915ULL: goto x86_l_77b;
	case 1917ULL: goto x86_l_77d;
	case 1923ULL: goto x86_l_783;
	case 1925ULL: goto x86_l_785;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1939ULL: goto x86_l_793;
	case 1945ULL: goto x86_l_799;
	case 1948ULL: goto x86_l_79c;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1962ULL: goto x86_l_7aa;
	case 1968ULL: goto x86_l_7b0;
	case 1973ULL: goto x86_l_7b5;
	case 1977ULL: goto x86_l_7b9;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2004ULL: goto x86_l_7d4;
	case 2006ULL: goto x86_l_7d6;
	case 2012ULL: goto x86_l_7dc;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2023ULL: goto x86_l_7e7;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2048ULL: goto x86_l_800;
	case 2051ULL: goto x86_l_803;
	case 2057ULL: goto x86_l_809;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2068ULL: goto x86_l_814;
	case 2073ULL: goto x86_l_819;
	case 2076ULL: goto x86_l_81c;
	case 2079ULL: goto x86_l_81f;
	case 2081ULL: goto x86_l_821;
	case 2084ULL: goto x86_l_824;
	case 2087ULL: goto x86_l_827;
	case 2092ULL: goto x86_l_82c;
	case 2095ULL: goto x86_l_82f;
	case 2098ULL: goto x86_l_832;
	case 2103ULL: goto x86_l_837;
	case 2107ULL: goto x86_l_83b;
	case 2113ULL: goto x86_l_841;
	case 2116ULL: goto x86_l_844;
	case 2120ULL: goto x86_l_848;
	case 2126ULL: goto x86_l_84e;
	case 2129ULL: goto x86_l_851;
	case 2133ULL: goto x86_l_855;
	case 2135ULL: goto x86_l_857;
	case 2137ULL: goto x86_l_859;
	case 2142ULL: goto x86_l_85e;
	case 2146ULL: goto x86_l_862;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2162ULL: goto x86_l_872;
	case 2165ULL: goto x86_l_875;
	case 2167ULL: goto x86_l_877;
	case 2171ULL: goto x86_l_87b;
	case 2178ULL: goto x86_l_882;
	case 2183ULL: goto x86_l_887;
	case 2187ULL: goto x86_l_88b;
	case 2190ULL: goto x86_l_88e;
	case 2192ULL: goto x86_l_890;
	case 2196ULL: goto x86_l_894;
	case 2203ULL: goto x86_l_89b;
	case 2208ULL: goto x86_l_8a0;
	case 2212ULL: goto x86_l_8a4;
	case 2215ULL: goto x86_l_8a7;
	case 2217ULL: goto x86_l_8a9;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2227ULL: goto x86_l_8b3;
	case 2234ULL: goto x86_l_8ba;
	case 2239ULL: goto x86_l_8bf;
	case 2242ULL: goto x86_l_8c2;
	case 2246ULL: goto x86_l_8c6;
	case 2250ULL: goto x86_l_8ca;
	case 2253ULL: goto x86_l_8cd;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2270ULL: goto x86_l_8de;
	case 2275ULL: goto x86_l_8e3;
	case 2278ULL: goto x86_l_8e6;
	case 2281ULL: goto x86_l_8e9;
	case 2283ULL: goto x86_l_8eb;
	case 2291ULL: goto x86_l_8f3;
	case 2297ULL: goto x86_l_8f9;
	case 2303ULL: goto x86_l_8ff;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2313ULL: goto x86_l_909;
	case 2319ULL: goto x86_l_90f;
	case 2321ULL: goto x86_l_911;
	case 2326ULL: goto x86_l_916;
	case 2330ULL: goto x86_l_91a;
	case 2336ULL: goto x86_l_920;
	case 2341ULL: goto x86_l_925;
	case 2344ULL: goto x86_l_928;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2356ULL: goto x86_l_934;
	case 2362ULL: goto x86_l_93a;
	case 2367ULL: goto x86_l_93f;
	case 2369ULL: goto x86_l_941;
	case 2375ULL: goto x86_l_947;
	case 2380ULL: goto x86_l_94c;
	case 2385ULL: goto x86_l_951;
	case 2389ULL: goto x86_l_955;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2409ULL: goto x86_l_969;
	case 2414ULL: goto x86_l_96e;
	case 2416ULL: goto x86_l_970;
	case 2418ULL: goto x86_l_972;
	case 2424ULL: goto x86_l_978;
	case 2429ULL: goto x86_l_97d;
	case 2432ULL: goto x86_l_980;
	case 2438ULL: goto x86_l_986;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2455ULL: goto x86_l_997;
	case 2460ULL: goto x86_l_99c;
	case 2462ULL: goto x86_l_99e;
	case 2465ULL: goto x86_l_9a1;
	case 2471ULL: goto x86_l_9a7;
	case 2474ULL: goto x86_l_9aa;
	case 2477ULL: goto x86_l_9ad;
	case 2482ULL: goto x86_l_9b2;
	case 2485ULL: goto x86_l_9b5;
	case 2488ULL: goto x86_l_9b8;
	case 2490ULL: goto x86_l_9ba;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2501ULL: goto x86_l_9c5;
	case 2504ULL: goto x86_l_9c8;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2516ULL: goto x86_l_9d4;
	case 2522ULL: goto x86_l_9da;
	case 2525ULL: goto x86_l_9dd;
	case 2529ULL: goto x86_l_9e1;
	case 2535ULL: goto x86_l_9e7;
	case 2538ULL: goto x86_l_9ea;
	case 2542ULL: goto x86_l_9ee;
	case 2544ULL: goto x86_l_9f0;
	case 2546ULL: goto x86_l_9f2;
	case 2549ULL: goto x86_l_9f5;
	case 2553ULL: goto x86_l_9f9;
	case 2560ULL: goto x86_l_a00;
	case 2566ULL: goto x86_l_a06;
	case 2570ULL: goto x86_l_a0a;
	case 2573ULL: goto x86_l_a0d;
	case 2575ULL: goto x86_l_a0f;
	case 2579ULL: goto x86_l_a13;
	case 2586ULL: goto x86_l_a1a;
	case 2592ULL: goto x86_l_a20;
	case 2596ULL: goto x86_l_a24;
	case 2599ULL: goto x86_l_a27;
	case 2601ULL: goto x86_l_a29;
	case 2605ULL: goto x86_l_a2d;
	case 2612ULL: goto x86_l_a34;
	case 2618ULL: goto x86_l_a3a;
	case 2622ULL: goto x86_l_a3e;
	case 2625ULL: goto x86_l_a41;
	case 2627ULL: goto x86_l_a43;
	case 2631ULL: goto x86_l_a47;
	case 2633ULL: goto x86_l_a49;
	case 2637ULL: goto x86_l_a4d;
	case 2644ULL: goto x86_l_a54;
	case 2650ULL: goto x86_l_a5a;
	case 2653ULL: goto x86_l_a5d;
	case 2657ULL: goto x86_l_a61;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2666ULL: goto x86_l_a6a;
	case 2671ULL: goto x86_l_a6f;
	case 2676ULL: goto x86_l_a74;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2695ULL: goto x86_l_a87;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2722ULL: goto x86_l_aa2;
	case 2724ULL: goto x86_l_aa4;
	case 2730ULL: goto x86_l_aaa;
	case 2735ULL: goto x86_l_aaf;
	case 2738ULL: goto x86_l_ab2;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2761ULL: goto x86_l_ac9;
	case 2766ULL: goto x86_l_ace;
	case 2768ULL: goto x86_l_ad0;
	case 2771ULL: goto x86_l_ad3;
	case 2777ULL: goto x86_l_ad9;
	case 2780ULL: goto x86_l_adc;
	case 2784ULL: goto x86_l_ae0;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2798ULL: goto x86_l_aee;
	case 2805ULL: goto x86_l_af5;
	case 2807ULL: goto x86_l_af7;
	case 2810ULL: goto x86_l_afa;
	case 2814ULL: goto x86_l_afe;
	case 2819ULL: goto x86_l_b03;
	case 2821ULL: goto x86_l_b05;
	case 2824ULL: goto x86_l_b08;
	case 2826ULL: goto x86_l_b0a;
	case 2831ULL: goto x86_l_b0f;
	case 2836ULL: goto x86_l_b14;
	case 2839ULL: goto x86_l_b17;
	case 2841ULL: goto x86_l_b19;
	case 2846ULL: goto x86_l_b1e;
	case 2849ULL: goto x86_l_b21;
	case 2852ULL: goto x86_l_b24;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2867ULL: goto x86_l_b33;
	case 2871ULL: goto x86_l_b37;
	case 2874ULL: goto x86_l_b3a;
	case 2880ULL: goto x86_l_b40;
	case 2883ULL: goto x86_l_b43;
	case 2886ULL: goto x86_l_b46;
	case 2892ULL: goto x86_l_b4c;
	case 2895ULL: goto x86_l_b4f;
	case 2901ULL: goto x86_l_b55;
	case 2906ULL: goto x86_l_b5a;
	case 2909ULL: goto x86_l_b5d;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2923ULL: goto x86_l_b6b;
	case 2929ULL: goto x86_l_b71;
	case 2932ULL: goto x86_l_b74;
	case 2938ULL: goto x86_l_b7a;
	case 2941ULL: goto x86_l_b7d;
	case 2947ULL: goto x86_l_b83;
	case 2952ULL: goto x86_l_b88;
	case 2955ULL: goto x86_l_b8b;
	case 2961ULL: goto x86_l_b91;
	case 2965ULL: goto x86_l_b95;
	case 2971ULL: goto x86_l_b9b;
	case 2976ULL: goto x86_l_ba0;
	case 2979ULL: goto x86_l_ba3;
	case 2985ULL: goto x86_l_ba9;
	case 2988ULL: goto x86_l_bac;
	case 2994ULL: goto x86_l_bb2;
	case 2996ULL: goto x86_l_bb4;
	case 3001ULL: goto x86_l_bb9;
	case 3005ULL: goto x86_l_bbd;
	case 3007ULL: goto x86_l_bbf;
	case 3012ULL: goto x86_l_bc4;
	case 3015ULL: goto x86_l_bc7;
	case 3017ULL: goto x86_l_bc9;
	case 3020ULL: goto x86_l_bcc;
	case 3023ULL: goto x86_l_bcf;
	case 3029ULL: goto x86_l_bd5;
	case 3033ULL: goto x86_l_bd9;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3049ULL: goto x86_l_be9;
	case 3053ULL: goto x86_l_bed;
	case 3055ULL: goto x86_l_bef;
	case 3065ULL: goto x86_l_bf9;
	case 3069ULL: goto x86_l_bfd;
	case 3075ULL: goto x86_l_c03;
	case 3080ULL: goto x86_l_c08;
	case 3083ULL: goto x86_l_c0b;
	case 3089ULL: goto x86_l_c11;
	case 3092ULL: goto x86_l_c14;
	case 3098ULL: goto x86_l_c1a;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3106ULL: goto x86_l_c22;
	case 3112ULL: goto x86_l_c28;
	case 3116ULL: goto x86_l_c2c;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3133ULL: goto x86_l_c3d;
	case 3137ULL: goto x86_l_c41;
	case 3142ULL: goto x86_l_c46;
	case 3149ULL: goto x86_l_c4d;
	case 3154ULL: goto x86_l_c52;
	case 3156ULL: goto x86_l_c54;
	case 3159ULL: goto x86_l_c57;
	case 3165ULL: goto x86_l_c5d;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3182ULL: goto x86_l_c6e;
	case 3187ULL: goto x86_l_c73;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3197ULL: goto x86_l_c7d;
	case 3203ULL: goto x86_l_c83;
	case 3206ULL: goto x86_l_c86;
	case 3210ULL: goto x86_l_c8a;
	case 3215ULL: goto x86_l_c8f;
	case 3220ULL: goto x86_l_c94;
	case 3226ULL: goto x86_l_c9a;
	case 3231ULL: goto x86_l_c9f;
	case 3237ULL: goto x86_l_ca5;
	case 3241ULL: goto x86_l_ca9;
	case 3246ULL: goto x86_l_cae;
	case 3253ULL: goto x86_l_cb5;
	case 3258ULL: goto x86_l_cba;
	case 3260ULL: goto x86_l_cbc;
	case 3263ULL: goto x86_l_cbf;
	case 3269ULL: goto x86_l_cc5;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3293ULL: goto x86_l_cdd;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3308ULL: goto x86_l_cec;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3321ULL: goto x86_l_cf9;
	case 3326ULL: goto x86_l_cfe;
	case 3331ULL: goto x86_l_d03;
	case 3333ULL: goto x86_l_d05;
	case 3336ULL: goto x86_l_d08;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3343ULL: goto x86_l_d0f;
	case 3346ULL: goto x86_l_d12;
	case 3349ULL: goto x86_l_d15;
	case 3355ULL: goto x86_l_d1b;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3366ULL: goto x86_l_d26;
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3380ULL: goto x86_l_d34;
	case 3386ULL: goto x86_l_d3a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c3:
	/* 0x6c3: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6c6:
	/* 0x6c6: jae    ba0 <generic_retkprobe_filter_arg+0xba0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ba0;
	}
x86_l_6cc:
	/* 0x6cc: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_6cf:
	/* 0x6cf: ja     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 193ULL;
	}
x86_l_6d5:
	/* 0x6d5: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_6d7:
	/* 0x6d7: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_6dc:
	/* 0x6dc: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_6e0:
	/* 0x6e0: jae    72a <generic_retkprobe_filter_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_72a;
	}
x86_l_6e2:
	/* 0x6e2: mov    edx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6e7:
	/* 0x6e7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6ea:
	/* 0x6ea: jle    b68 <generic_retkprobe_filter_arg+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b68;
	}
x86_l_6f0:
	/* 0x6f0: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_6f3:
	/* 0x6f3: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_6f6:
	/* 0x6f6: jae    101a <generic_retkprobe_filter_arg+0x101a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4122ULL;
	}
x86_l_6fc:
	/* 0x6fc: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_700:
	/* 0x700: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_706:
	/* 0x706: jmp    2126 <generic_retkprobe_filter_arg+0x2126> */
	return 8486ULL;
x86_l_70b:
	/* 0x70b: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_70e:
	/* 0x70e: je     cd8 <generic_retkprobe_filter_arg+0xcd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd8;
	}
x86_l_714:
	/* 0x714: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_717:
	/* 0x717: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_71c:
	/* 0x71c: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_71f:
	/* 0x71f: je     d05 <generic_retkprobe_filter_arg+0xd05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d05;
	}
x86_l_725:
	/* 0x725: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_72a:
	/* 0x72a: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_72f:
	/* 0x72f: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_733:
	/* 0x733: jb     c9f <generic_retkprobe_filter_arg+0xc9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c9f;
	}
x86_l_739:
	/* 0x739: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_743:
	/* 0x743: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_747:
	/* 0x747: jae    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 193ULL;
	}
x86_l_74d:
	/* 0x74d: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_750:
	/* 0x750: jne    12d0 <generic_retkprobe_filter_arg+0x12d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4816ULL;
	}
x86_l_756:
	/* 0x756: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_75b:
	/* 0x75b: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_760:
	/* 0x760: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_763:
	/* 0x763: ja     1e75 <generic_retkprobe_filter_arg+0x1e75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7797ULL;
	}
x86_l_769:
	/* 0x769: mov    eax,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5122ULL);
x86_l_76e:
	/* 0x76e: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_771:
	/* 0x771: jae    1e75 <generic_retkprobe_filter_arg+0x1e75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7797ULL;
	}
x86_l_777:
	/* 0x777: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77b:
	/* 0x77b: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_77d:
	/* 0x77d: jg     1e85 <generic_retkprobe_filter_arg+0x1e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7813ULL;
	}
x86_l_783:
	/* 0x783: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_785:
	/* 0x785: jle    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 624ULL;
	}
x86_l_78b:
	/* 0x78b: jmp    1e85 <generic_retkprobe_filter_arg+0x1e85> */
	return 7813ULL;
x86_l_790:
	/* 0x790: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_793:
	/* 0x793: jg     d89 <generic_retkprobe_filter_arg+0xd89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3465ULL;
	}
x86_l_799:
	/* 0x799: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_79c:
	/* 0x79c: je     ec0 <generic_retkprobe_filter_arg+0xec0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3776ULL;
	}
x86_l_7a2:
	/* 0x7a2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_7a7:
	/* 0x7a7: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_7aa:
	/* 0x7aa: jne    3423 <generic_retkprobe_filter_arg+0x3423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13347ULL;
	}
x86_l_7b0:
	/* 0x7b0: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b5:
	/* 0x7b5: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7b9:
	/* 0x7b9: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_7c1:
	/* 0x7c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7c6:
	/* 0x7c6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_7cd:
	/* 0x7cd: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7d2:
	/* 0x7d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d4:
	/* 0x7d4: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_7d6:
	/* 0x7d6: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_7dc:
	/* 0x7dc: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_7df:
	/* 0x7df: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_7e4:
	/* 0x7e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e7:
	/* 0x7e7: je     3415 <generic_retkprobe_filter_arg+0x3415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13333ULL;
	}
x86_l_7ed:
	/* 0x7ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7f2:
	/* 0x7f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_7f9:
	/* 0x7f9: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7fe:
	/* 0x7fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_800:
	/* 0x800: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_803:
	/* 0x803: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_809:
	/* 0x809: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_80c:
	/* 0x80c: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_811:
	/* 0x811: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_814:
	/* 0x814: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_819:
	/* 0x819: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_81c:
	/* 0x81c: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_81f:
	/* 0x81f: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_821:
	/* 0x821: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_824:
	/* 0x824: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_827:
	/* 0x827: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_82c:
	/* 0x82c: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_82f:
	/* 0x82f: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_832:
	/* 0x832: mov    QWORD PTR [rsp+0x38],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_837:
	/* 0x837: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_83b:
	/* 0x83b: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_841:
	/* 0x841: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_844:
	/* 0x844: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_848:
	/* 0x848: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_84e:
	/* 0x84e: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_851:
	/* 0x851: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_855:
	/* 0x855: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_857:
	/* 0x857: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_859:
	/* 0x859: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_85e:
	/* 0x85e: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_862:
	/* 0x862: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_869:
	/* 0x869: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_86e:
	/* 0x86e: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_872:
	/* 0x872: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_875:
	/* 0x875: je     8cf <generic_retkprobe_filter_arg+0x8cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8cf;
	}
x86_l_877:
	/* 0x877: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_87b:
	/* 0x87b: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_882:
	/* 0x882: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_887:
	/* 0x887: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_88b:
	/* 0x88b: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_88e:
	/* 0x88e: je     8cf <generic_retkprobe_filter_arg+0x8cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8cf;
	}
x86_l_890:
	/* 0x890: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_894:
	/* 0x894: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_89b:
	/* 0x89b: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_8a0:
	/* 0x8a0: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_8a4:
	/* 0x8a4: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_8a7:
	/* 0x8a7: je     8cf <generic_retkprobe_filter_arg+0x8cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8cf;
	}
x86_l_8a9:
	/* 0x8a9: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_8ad:
	/* 0x8ad: je     8cf <generic_retkprobe_filter_arg+0x8cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8cf;
	}
x86_l_8af:
	/* 0x8af: lea    r13d,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_8b3:
	/* 0x8b3: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8ba:
	/* 0x8ba: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_8bf:
	/* 0x8bf: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c2:
	/* 0x8c2: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_8c6:
	/* 0x8c6: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8ca:
	/* 0x8ca: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_8cd:
	/* 0x8cd: jne    85e <generic_retkprobe_filter_arg+0x85e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_85e;
	}
x86_l_8cf:
	/* 0x8cf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8d4:
	/* 0x8d4: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8d9:
	/* 0x8d9: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8de:
	/* 0x8de: jmp    3407 <generic_retkprobe_filter_arg+0x3407> */
	return 13319ULL;
x86_l_8e3:
	/* 0x8e3: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_8e6:
	/* 0x8e6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8e9:
	/* 0x8e9: jae    8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8ff;
	}
x86_l_8eb:
	/* 0x8eb: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_8f3:
	/* 0x8f3: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_8f9:
	/* 0x8f9: jbe    1124 <generic_retkprobe_filter_arg+0x1124> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4388ULL;
	}
x86_l_8ff:
	/* 0x8ff: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_901:
	/* 0x901: jmp    30c6 <generic_retkprobe_filter_arg+0x30c6> */
	return 12486ULL;
x86_l_906:
	/* 0x906: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_909:
	/* 0x909: ja     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 193ULL;
	}
x86_l_90f:
	/* 0x90f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_911:
	/* 0x911: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_916:
	/* 0x916: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_91a:
	/* 0x91a: jae    1065 <generic_retkprobe_filter_arg+0x1065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4197ULL;
	}
x86_l_920:
	/* 0x920: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_925:
	/* 0x925: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_928:
	/* 0x928: jle    1590 <generic_retkprobe_filter_arg+0x1590> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5520ULL;
	}
x86_l_92e:
	/* 0x92e: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_931:
	/* 0x931: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_934:
	/* 0x934: jae    1ce9 <generic_retkprobe_filter_arg+0x1ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7401ULL;
	}
x86_l_93a:
	/* 0x93a: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_93f:
	/* 0x93f: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_941:
	/* 0x941: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_947:
	/* 0x947: jmp    1e3b <generic_retkprobe_filter_arg+0x1e3b> */
	return 7739ULL;
x86_l_94c:
	/* 0x94c: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_951:
	/* 0x951: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_955:
	/* 0x955: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_95d:
	/* 0x95d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_962:
	/* 0x962: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_969:
	/* 0x969: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_96e:
	/* 0x96e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_970:
	/* 0x970: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_972:
	/* 0x972: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12470ULL;
	}
x86_l_978:
	/* 0x978: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_97d:
	/* 0x97d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_980:
	/* 0x980: je     30b8 <generic_retkprobe_filter_arg+0x30b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12472ULL;
	}
x86_l_986:
	/* 0x986: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_98b:
	/* 0x98b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_990:
	/* 0x990: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_997:
	/* 0x997: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_99c:
	/* 0x99c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99e:
	/* 0x99e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a1:
	/* 0x9a1: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12470ULL;
	}
x86_l_9a7:
	/* 0x9a7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_9aa:
	/* 0x9aa: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_9ad:
	/* 0x9ad: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_9b2:
	/* 0x9b2: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_9b5:
	/* 0x9b5: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_9b8:
	/* 0x9b8: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ba:
	/* 0x9ba: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_9bd:
	/* 0x9bd: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_9c0:
	/* 0x9c0: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_9c5:
	/* 0x9c5: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9c8:
	/* 0x9c8: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_9cb:
	/* 0x9cb: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9d0:
	/* 0x9d0: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_9d4:
	/* 0x9d4: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_9da:
	/* 0x9da: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9dd:
	/* 0x9dd: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_9e1:
	/* 0x9e1: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_9e7:
	/* 0x9e7: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9ea:
	/* 0x9ea: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_9ee:
	/* 0x9ee: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_9f0:
	/* 0x9f0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f2:
	/* 0x9f2: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_9f5:
	/* 0x9f5: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_9f9:
	/* 0x9f9: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a00:
	/* 0xa00: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a06:
	/* 0xa06: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a0a:
	/* 0xa0a: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_a0d:
	/* 0xa0d: je     a6a <generic_retkprobe_filter_arg+0xa6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6a;
	}
x86_l_a0f:
	/* 0xa0f: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_a13:
	/* 0xa13: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a1a:
	/* 0xa1a: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a20:
	/* 0xa20: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_a24:
	/* 0xa24: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_a27:
	/* 0xa27: je     a6a <generic_retkprobe_filter_arg+0xa6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6a;
	}
x86_l_a29:
	/* 0xa29: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_a2d:
	/* 0xa2d: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a34:
	/* 0xa34: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a3a:
	/* 0xa3a: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_a3e:
	/* 0xa3e: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a41:
	/* 0xa41: je     a6a <generic_retkprobe_filter_arg+0xa6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6a;
	}
x86_l_a43:
	/* 0xa43: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_a47:
	/* 0xa47: je     a6a <generic_retkprobe_filter_arg+0xa6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6a;
	}
x86_l_a49:
	/* 0xa49: lea    r13d,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_a4d:
	/* 0xa4d: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a54:
	/* 0xa54: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a5a:
	/* 0xa5a: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5d:
	/* 0xa5d: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_a61:
	/* 0xa61: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a65:
	/* 0xa65: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_a68:
	/* 0xa68: jne    9f5 <generic_retkprobe_filter_arg+0x9f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9f5;
	}
x86_l_a6a:
	/* 0xa6a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a6f:
	/* 0xa6f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a74:
	/* 0xa74: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a79:
	/* 0xa79: jmp    2e66 <generic_retkprobe_filter_arg+0x2e66> */
	return 11878ULL;
x86_l_a7e:
	/* 0xa7e: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a83:
	/* 0xa83: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a87:
	/* 0xa87: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_a8f:
	/* 0xa8f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a94:
	/* 0xa94: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_a9b:
	/* 0xa9b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aa0:
	/* 0xaa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa2:
	/* 0xaa2: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_aa4:
	/* 0xaa4: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12470ULL;
	}
x86_l_aaa:
	/* 0xaaa: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_aaf:
	/* 0xaaf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ab2:
	/* 0xab2: je     30b8 <generic_retkprobe_filter_arg+0x30b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12472ULL;
	}
x86_l_ab8:
	/* 0xab8: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_abd:
	/* 0xabd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac2:
	/* 0xac2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_ac9:
	/* 0xac9: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ace:
	/* 0xace: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad0:
	/* 0xad0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad3:
	/* 0xad3: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12470ULL;
	}
x86_l_ad9:
	/* 0xad9: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_adc:
	/* 0xadc: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ae0:
	/* 0xae0: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_ae6:
	/* 0xae6: mov    eax,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_aeb:
	/* 0xaeb: cmovae ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_aee:
	/* 0xaee: lea    eax,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_af5:
	/* 0xaf5: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af7:
	/* 0xaf7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_afa:
	/* 0xafa: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_afe:
	/* 0xafe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b03:
	/* 0xb03: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_b05:
	/* 0xb05: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b08:
	/* 0xb08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0a:
	/* 0xb0a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b0f:
	/* 0xb0f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b14:
	/* 0xb14: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_b17:
	/* 0xb17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b19:
	/* 0xb19: jmp    2e68 <generic_retkprobe_filter_arg+0x2e68> */
	return 11880ULL;
x86_l_b1e:
	/* 0xb1e: lea    edx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_b21:
	/* 0xb21: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_b24:
	/* 0xb24: jb     bbf <generic_retkprobe_filter_arg+0xbbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_bbf;
	}
x86_l_b2a:
	/* 0xb2a: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_b2f:
	/* 0xb2f: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b33:
	/* 0xb33: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b37:
	/* 0xb37: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_b3a:
	/* 0xb3a: jg     1182 <generic_retkprobe_filter_arg+0x1182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4482ULL;
	}
x86_l_b40:
	/* 0xb40: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_b43:
	/* 0xb43: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b46:
	/* 0xb46: jb     19db <generic_retkprobe_filter_arg+0x19db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6619ULL;
	}
x86_l_b4c:
	/* 0xb4c: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_b4f:
	/* 0xb4f: je     1943 <generic_retkprobe_filter_arg+0x1943> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6467ULL;
	}
x86_l_b55:
	/* 0xb55: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_b5a:
	/* 0xb5a: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_b5d:
	/* 0xb5d: je     11a2 <generic_retkprobe_filter_arg+0x11a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4514ULL;
	}
x86_l_b63:
	/* 0xb63: jmp    3423 <generic_retkprobe_filter_arg+0x3423> */
	return 13347ULL;
x86_l_b68:
	/* 0xb68: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b6b:
	/* 0xb6b: je     145f <generic_retkprobe_filter_arg+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5215ULL;
	}
x86_l_b71:
	/* 0xb71: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b74:
	/* 0xb74: jne    2126 <generic_retkprobe_filter_arg+0x2126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8486ULL;
	}
x86_l_b7a:
	/* 0xb7a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_b7d:
	/* 0xb7d: ja     211c <generic_retkprobe_filter_arg+0x211c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8476ULL;
	}
x86_l_b83:
	/* 0xb83: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_b88:
	/* 0xb88: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_b8b:
	/* 0xb8b: jae    211c <generic_retkprobe_filter_arg+0x211c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8476ULL;
	}
x86_l_b91:
	/* 0xb91: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b95:
	/* 0xb95: jl     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 624ULL;
	}
x86_l_b9b:
	/* 0xb9b: jmp    2126 <generic_retkprobe_filter_arg+0x2126> */
	return 8486ULL;
x86_l_ba0:
	/* 0xba0: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_ba3:
	/* 0xba3: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_ba9:
	/* 0xba9: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_bac:
	/* 0xbac: ja     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 193ULL;
	}
x86_l_bb2:
	/* 0xbb2: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_bb4:
	/* 0xbb4: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_bb9:
	/* 0xbb9: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_bbd:
	/* 0xbbd: jae    be4 <generic_retkprobe_filter_arg+0xbe4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_be4;
	}
x86_l_bbf:
	/* 0xbbf: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bc4:
	/* 0xbc4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bc7:
	/* 0xbc7: jle    c08 <generic_retkprobe_filter_arg+0xc08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c08;
	}
x86_l_bc9:
	/* 0xbc9: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_bcc:
	/* 0xbcc: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_bcf:
	/* 0xbcf: jae    e60 <generic_retkprobe_filter_arg+0xe60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3680ULL;
	}
x86_l_bd5:
	/* 0xbd5: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd9:
	/* 0xbd9: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_bdf:
	/* 0xbdf: jmp    1c50 <generic_retkprobe_filter_arg+0x1c50> */
	return 7248ULL;
x86_l_be4:
	/* 0xbe4: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_be9:
	/* 0xbe9: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_bed:
	/* 0xbed: jb     c37 <generic_retkprobe_filter_arg+0xc37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c37;
	}
x86_l_bef:
	/* 0xbef: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_bf9:
	/* 0xbf9: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_bfd:
	/* 0xbfd: jb     e84 <generic_retkprobe_filter_arg+0xe84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3716ULL;
	}
x86_l_c03:
	/* 0xc03: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_c08:
	/* 0xc08: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c0b:
	/* 0xc0b: je     1107 <generic_retkprobe_filter_arg+0x1107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4359ULL;
	}
x86_l_c11:
	/* 0xc11: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c14:
	/* 0xc14: jne    1c50 <generic_retkprobe_filter_arg+0x1c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7248ULL;
	}
x86_l_c1a:
	/* 0xc1a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c1d:
	/* 0xc1d: je     c28 <generic_retkprobe_filter_arg+0xc28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c28;
	}
x86_l_c1f:
	/* 0xc1f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_c22:
	/* 0xc22: jne    1c46 <generic_retkprobe_filter_arg+0x1c46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7238ULL;
	}
x86_l_c28:
	/* 0xc28: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2c:
	/* 0xc2c: jl     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 624ULL;
	}
x86_l_c32:
	/* 0xc32: jmp    1c50 <generic_retkprobe_filter_arg+0x1c50> */
	return 7248ULL;
x86_l_c37:
	/* 0xc37: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_c3d:
	/* 0xc3d: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c41:
	/* 0xc41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c46:
	/* 0xc46: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_c4d:
	/* 0xc4d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c52:
	/* 0xc52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c54:
	/* 0xc54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c57:
	/* 0xc57: je     208e <generic_retkprobe_filter_arg+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8334ULL;
	}
x86_l_c5d:
	/* 0xc5d: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c61:
	/* 0xc61: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c66:
	/* 0xc66: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c6b:
	/* 0xc6b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c6e:
	/* 0xc6e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c73:
	/* 0xc73: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c75:
	/* 0xc75: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c7a:
	/* 0xc7a: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_c7d:
	/* 0xc7d: je     1779 <generic_retkprobe_filter_arg+0x1779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6009ULL;
	}
x86_l_c83:
	/* 0xc83: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_c86:
	/* 0xc86: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8a:
	/* 0xc8a: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c8f:
	/* 0xc8f: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c94:
	/* 0xc94: je     1761 <generic_retkprobe_filter_arg+0x1761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5985ULL;
	}
x86_l_c9a:
	/* 0xc9a: jmp    176f <generic_retkprobe_filter_arg+0x176f> */
	return 5999ULL;
x86_l_c9f:
	/* 0xc9f: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_ca5:
	/* 0xca5: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ca9:
	/* 0xca9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cae:
	/* 0xcae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_cb5:
	/* 0xcb5: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cba:
	/* 0xcba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cbc:
	/* 0xcbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cbf:
	/* 0xcbf: je     208e <generic_retkprobe_filter_arg+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8334ULL;
	}
x86_l_cc5:
	/* 0xcc5: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc9:
	/* 0xcc9: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cce:
	/* 0xcce: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cd3:
	/* 0xcd3: jmp    1936 <generic_retkprobe_filter_arg+0x1936> */
	return 6454ULL;
x86_l_cd8:
	/* 0xcd8: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_cdd:
	/* 0xcdd: mov    WORD PTR [rsp+0x66],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 102ULL);
x86_l_ce2:
	/* 0xce2: movzx  edx,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_ce7:
	/* 0xce7: mov    WORD PTR [rsp+0x60],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cec:
	/* 0xcec: mov    rdx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf0:
	/* 0xcf0: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cf5:
	/* 0xcf5: mov    rdx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf9:
	/* 0xcf9: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cfe:
	/* 0xcfe: lea    r13,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d03:
	/* 0xd03: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d05:
	/* 0xd05: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_d08:
	/* 0xd08: jle    d31 <generic_retkprobe_filter_arg+0xd31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d31;
	}
x86_l_d0a:
	/* 0xd0a: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_d0d:
	/* 0xd0d: jg     d64 <generic_retkprobe_filter_arg+0xd64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3428ULL;
	}
x86_l_d0f:
	/* 0xd0f: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_d12:
	/* 0xd12: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d15:
	/* 0xd15: jb     1344 <generic_retkprobe_filter_arg+0x1344> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4932ULL;
	}
x86_l_d1b:
	/* 0xd1b: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_d1e:
	/* 0xd1e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d23:
	/* 0xd23: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d26:
	/* 0xd26: jb     133a <generic_retkprobe_filter_arg+0x133a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4922ULL;
	}
x86_l_d2c:
	/* 0xd2c: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_d31:
	/* 0xd31: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_d34:
	/* 0xd34: jle    fc7 <generic_retkprobe_filter_arg+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4039ULL;
	}
x86_l_d3a:
	/* 0xd3a: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
	return 3389ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3389ULL: goto x86_l_d3d;
	case 3395ULL: goto x86_l_d43;
	case 3398ULL: goto x86_l_d46;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3412ULL: goto x86_l_d54;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3431ULL: goto x86_l_d67;
	case 3437ULL: goto x86_l_d6d;
	case 3440ULL: goto x86_l_d70;
	case 3446ULL: goto x86_l_d76;
	case 3451ULL: goto x86_l_d7b;
	case 3454ULL: goto x86_l_d7e;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3468ULL: goto x86_l_d8c;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3482ULL: goto x86_l_d9a;
	case 3488ULL: goto x86_l_da0;
	case 3490ULL: goto x86_l_da2;
	case 3493ULL: goto x86_l_da5;
	case 3498ULL: goto x86_l_daa;
	case 3502ULL: goto x86_l_dae;
	case 3507ULL: goto x86_l_db3;
	case 3514ULL: goto x86_l_dba;
	case 3519ULL: goto x86_l_dbf;
	case 3521ULL: goto x86_l_dc1;
	case 3524ULL: goto x86_l_dc4;
	case 3530ULL: goto x86_l_dca;
	case 3532ULL: goto x86_l_dcc;
	case 3537ULL: goto x86_l_dd1;
	case 3539ULL: goto x86_l_dd3;
	case 3544ULL: goto x86_l_dd8;
	case 3546ULL: goto x86_l_dda;
	case 3548ULL: goto x86_l_ddc;
	case 3551ULL: goto x86_l_ddf;
	case 3554ULL: goto x86_l_de2;
	case 3557ULL: goto x86_l_de5;
	case 3559ULL: goto x86_l_de7;
	case 3561ULL: goto x86_l_de9;
	case 3565ULL: goto x86_l_ded;
	case 3568ULL: goto x86_l_df0;
	case 3570ULL: goto x86_l_df2;
	case 3574ULL: goto x86_l_df6;
	case 3576ULL: goto x86_l_df8;
	case 3578ULL: goto x86_l_dfa;
	case 3583ULL: goto x86_l_dff;
	case 3587ULL: goto x86_l_e03;
	case 3590ULL: goto x86_l_e06;
	case 3594ULL: goto x86_l_e0a;
	case 3598ULL: goto x86_l_e0e;
	case 3602ULL: goto x86_l_e12;
	case 3606ULL: goto x86_l_e16;
	case 3609ULL: goto x86_l_e19;
	case 3613ULL: goto x86_l_e1d;
	case 3617ULL: goto x86_l_e21;
	case 3621ULL: goto x86_l_e25;
	case 3625ULL: goto x86_l_e29;
	case 3627ULL: goto x86_l_e2b;
	case 3630ULL: goto x86_l_e2e;
	case 3633ULL: goto x86_l_e31;
	case 3635ULL: goto x86_l_e33;
	case 3637ULL: goto x86_l_e35;
	case 3639ULL: goto x86_l_e37;
	case 3645ULL: goto x86_l_e3d;
	case 3649ULL: goto x86_l_e41;
	case 3654ULL: goto x86_l_e46;
	case 3656ULL: goto x86_l_e48;
	case 3660ULL: goto x86_l_e4c;
	case 3663ULL: goto x86_l_e4f;
	case 3667ULL: goto x86_l_e53;
	case 3673ULL: goto x86_l_e59;
	case 3675ULL: goto x86_l_e5b;
	case 3680ULL: goto x86_l_e60;
	case 3683ULL: goto x86_l_e63;
	case 3689ULL: goto x86_l_e69;
	case 3693ULL: goto x86_l_e6d;
	case 3699ULL: goto x86_l_e73;
	case 3704ULL: goto x86_l_e78;
	case 3707ULL: goto x86_l_e7b;
	case 3710ULL: goto x86_l_e7e;
	case 3716ULL: goto x86_l_e84;
	case 3719ULL: goto x86_l_e87;
	case 3725ULL: goto x86_l_e8d;
	case 3730ULL: goto x86_l_e92;
	case 3735ULL: goto x86_l_e97;
	case 3738ULL: goto x86_l_e9a;
	case 3740ULL: goto x86_l_e9c;
	case 3743ULL: goto x86_l_e9f;
	case 3749ULL: goto x86_l_ea5;
	case 3753ULL: goto x86_l_ea9;
	case 3756ULL: goto x86_l_eac;
	case 3762ULL: goto x86_l_eb2;
	case 3765ULL: goto x86_l_eb5;
	case 3771ULL: goto x86_l_ebb;
	case 3776ULL: goto x86_l_ec0;
	case 3781ULL: goto x86_l_ec5;
	case 3785ULL: goto x86_l_ec9;
	case 3793ULL: goto x86_l_ed1;
	case 3798ULL: goto x86_l_ed6;
	case 3805ULL: goto x86_l_edd;
	case 3810ULL: goto x86_l_ee2;
	case 3812ULL: goto x86_l_ee4;
	case 3814ULL: goto x86_l_ee6;
	case 3820ULL: goto x86_l_eec;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3831ULL: goto x86_l_ef7;
	case 3837ULL: goto x86_l_efd;
	case 3842ULL: goto x86_l_f02;
	case 3849ULL: goto x86_l_f09;
	case 3854ULL: goto x86_l_f0e;
	case 3856ULL: goto x86_l_f10;
	case 3859ULL: goto x86_l_f13;
	case 3865ULL: goto x86_l_f19;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3879ULL: goto x86_l_f27;
	case 3886ULL: goto x86_l_f2e;
	case 3888ULL: goto x86_l_f30;
	case 3891ULL: goto x86_l_f33;
	case 3895ULL: goto x86_l_f37;
	case 3900ULL: goto x86_l_f3c;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3910ULL: goto x86_l_f46;
	case 3913ULL: goto x86_l_f49;
	case 3915ULL: goto x86_l_f4b;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3933ULL: goto x86_l_f5d;
	case 3939ULL: goto x86_l_f63;
	case 3945ULL: goto x86_l_f69;
	case 3948ULL: goto x86_l_f6c;
	case 3953ULL: goto x86_l_f71;
	case 3959ULL: goto x86_l_f77;
	case 3963ULL: goto x86_l_f7b;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3980ULL: goto x86_l_f8c;
	case 3983ULL: goto x86_l_f8f;
	case 3985ULL: goto x86_l_f91;
	case 3987ULL: goto x86_l_f93;
	case 3989ULL: goto x86_l_f95;
	case 3991ULL: goto x86_l_f97;
	case 3993ULL: goto x86_l_f99;
	case 3996ULL: goto x86_l_f9c;
	case 3998ULL: goto x86_l_f9e;
	case 4000ULL: goto x86_l_fa0;
	case 4002ULL: goto x86_l_fa2;
	case 4005ULL: goto x86_l_fa5;
	case 4008ULL: goto x86_l_fa8;
	case 4012ULL: goto x86_l_fac;
	case 4018ULL: goto x86_l_fb2;
	case 4020ULL: goto x86_l_fb4;
	case 4023ULL: goto x86_l_fb7;
	case 4029ULL: goto x86_l_fbd;
	case 4032ULL: goto x86_l_fc0;
	case 4034ULL: goto x86_l_fc2;
	case 4039ULL: goto x86_l_fc7;
	case 4042ULL: goto x86_l_fca;
	case 4048ULL: goto x86_l_fd0;
	case 4051ULL: goto x86_l_fd3;
	case 4057ULL: goto x86_l_fd9;
	case 4062ULL: goto x86_l_fde;
	case 4065ULL: goto x86_l_fe1;
	case 4071ULL: goto x86_l_fe7;
	case 4076ULL: goto x86_l_fec;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4089ULL: goto x86_l_ff9;
	case 4091ULL: goto x86_l_ffb;
	case 4094ULL: goto x86_l_ffe;
	case 4100ULL: goto x86_l_1004;
	case 4104ULL: goto x86_l_1008;
	case 4107ULL: goto x86_l_100b;
	case 4111ULL: goto x86_l_100f;
	case 4114ULL: goto x86_l_1012;
	case 4117ULL: goto x86_l_1015;
	case 4122ULL: goto x86_l_101a;
	case 4125ULL: goto x86_l_101d;
	case 4131ULL: goto x86_l_1023;
	case 4135ULL: goto x86_l_1027;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4155ULL: goto x86_l_103b;
	case 4161ULL: goto x86_l_1041;
	case 4171ULL: goto x86_l_104b;
	case 4175ULL: goto x86_l_104f;
	case 4181ULL: goto x86_l_1055;
	case 4184ULL: goto x86_l_1058;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4197ULL: goto x86_l_1065;
	case 4202ULL: goto x86_l_106a;
	case 4206ULL: goto x86_l_106e;
	case 4212ULL: goto x86_l_1074;
	case 4222ULL: goto x86_l_107e;
	case 4226ULL: goto x86_l_1082;
	case 4232ULL: goto x86_l_1088;
	case 4235ULL: goto x86_l_108b;
	case 4241ULL: goto x86_l_1091;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4253ULL: goto x86_l_109d;
	case 4258ULL: goto x86_l_10a2;
	case 4264ULL: goto x86_l_10a8;
	case 4269ULL: goto x86_l_10ad;
	case 4272ULL: goto x86_l_10b0;
	case 4278ULL: goto x86_l_10b6;
	case 4283ULL: goto x86_l_10bb;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4296ULL: goto x86_l_10c8;
	case 4299ULL: goto x86_l_10cb;
	case 4305ULL: goto x86_l_10d1;
	case 4310ULL: goto x86_l_10d6;
	case 4312ULL: goto x86_l_10d8;
	case 4317ULL: goto x86_l_10dd;
	case 4323ULL: goto x86_l_10e3;
	case 4326ULL: goto x86_l_10e6;
	case 4332ULL: goto x86_l_10ec;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4348ULL: goto x86_l_10fc;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4362ULL: goto x86_l_110a;
	case 4364ULL: goto x86_l_110c;
	case 4367ULL: goto x86_l_110f;
	case 4373ULL: goto x86_l_1115;
	case 4377ULL: goto x86_l_1119;
	case 4383ULL: goto x86_l_111f;
	case 4388ULL: goto x86_l_1124;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4402ULL: goto x86_l_1132;
	case 4406ULL: goto x86_l_1136;
	case 4412ULL: goto x86_l_113c;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4421ULL: goto x86_l_1145;
	case 4423ULL: goto x86_l_1147;
	case 4426ULL: goto x86_l_114a;
	case 4428ULL: goto x86_l_114c;
	case 4430ULL: goto x86_l_114e;
	case 4432ULL: goto x86_l_1150;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4439ULL: goto x86_l_1157;
	case 4441ULL: goto x86_l_1159;
	case 4443ULL: goto x86_l_115b;
	case 4445ULL: goto x86_l_115d;
	case 4448ULL: goto x86_l_1160;
	case 4451ULL: goto x86_l_1163;
	case 4455ULL: goto x86_l_1167;
	case 4461ULL: goto x86_l_116d;
	case 4463ULL: goto x86_l_116f;
	case 4466ULL: goto x86_l_1172;
	case 4472ULL: goto x86_l_1178;
	case 4475ULL: goto x86_l_117b;
	case 4477ULL: goto x86_l_117d;
	case 4482ULL: goto x86_l_1182;
	case 4485ULL: goto x86_l_1185;
	case 4491ULL: goto x86_l_118b;
	case 4494ULL: goto x86_l_118e;
	case 4500ULL: goto x86_l_1194;
	case 4505ULL: goto x86_l_1199;
	case 4508ULL: goto x86_l_119c;
	case 4514ULL: goto x86_l_11a2;
	case 4519ULL: goto x86_l_11a7;
	case 4523ULL: goto x86_l_11ab;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4543ULL: goto x86_l_11bf;
	case 4548ULL: goto x86_l_11c4;
	case 4550ULL: goto x86_l_11c6;
	case 4552ULL: goto x86_l_11c8;
	case 4558ULL: goto x86_l_11ce;
	case 4563ULL: goto x86_l_11d3;
	case 4566ULL: goto x86_l_11d6;
	case 4572ULL: goto x86_l_11dc;
	case 4577ULL: goto x86_l_11e1;
	case 4582ULL: goto x86_l_11e6;
	case 4589ULL: goto x86_l_11ed;
	case 4594ULL: goto x86_l_11f2;
	case 4596ULL: goto x86_l_11f4;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4619ULL: goto x86_l_120b;
	case 4622ULL: goto x86_l_120e;
	case 4624ULL: goto x86_l_1210;
	case 4627ULL: goto x86_l_1213;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4641ULL: goto x86_l_1221;
	case 4646ULL: goto x86_l_1226;
	case 4650ULL: goto x86_l_122a;
	case 4656ULL: goto x86_l_1230;
	case 4659ULL: goto x86_l_1233;
	case 4663ULL: goto x86_l_1237;
	case 4669ULL: goto x86_l_123d;
	case 4672ULL: goto x86_l_1240;
	case 4676ULL: goto x86_l_1244;
	case 4678ULL: goto x86_l_1246;
	case 4680ULL: goto x86_l_1248;
	case 4683ULL: goto x86_l_124b;
	case 4687ULL: goto x86_l_124f;
	case 4694ULL: goto x86_l_1256;
	case 4699ULL: goto x86_l_125b;
	case 4703ULL: goto x86_l_125f;
	case 4706ULL: goto x86_l_1262;
	case 4708ULL: goto x86_l_1264;
	case 4712ULL: goto x86_l_1268;
	case 4719ULL: goto x86_l_126f;
	case 4724ULL: goto x86_l_1274;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4733ULL: goto x86_l_127d;
	case 4737ULL: goto x86_l_1281;
	case 4744ULL: goto x86_l_1288;
	case 4749ULL: goto x86_l_128d;
	case 4753ULL: goto x86_l_1291;
	case 4756ULL: goto x86_l_1294;
	case 4758ULL: goto x86_l_1296;
	case 4762ULL: goto x86_l_129a;
	case 4764ULL: goto x86_l_129c;
	case 4768ULL: goto x86_l_12a0;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4783ULL: goto x86_l_12af;
	case 4787ULL: goto x86_l_12b3;
	case 4791ULL: goto x86_l_12b7;
	case 4794ULL: goto x86_l_12ba;
	case 4796ULL: goto x86_l_12bc;
	case 4801ULL: goto x86_l_12c1;
	case 4806ULL: goto x86_l_12c6;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4821ULL: goto x86_l_12d5;
	case 4826ULL: goto x86_l_12da;
	case 4829ULL: goto x86_l_12dd;
	case 4835ULL: goto x86_l_12e3;
	case 4840ULL: goto x86_l_12e8;
	case 4843ULL: goto x86_l_12eb;
	case 4849ULL: goto x86_l_12f1;
	case 4853ULL: goto x86_l_12f5;
	case 4855ULL: goto x86_l_12f7;
	case 4859ULL: goto x86_l_12fb;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4872ULL: goto x86_l_1308;
	case 4878ULL: goto x86_l_130e;
	case 4881ULL: goto x86_l_1311;
	case 4886ULL: goto x86_l_1316;
	case 4889ULL: goto x86_l_1319;
	case 4892ULL: goto x86_l_131c;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4913ULL: goto x86_l_1331;
	case 4916ULL: goto x86_l_1334;
	case 4922ULL: goto x86_l_133a;
	case 4925ULL: goto x86_l_133d;
	case 4930ULL: goto x86_l_1342;
	case 4932ULL: goto x86_l_1344;
	case 4935ULL: goto x86_l_1347;
	case 4940ULL: goto x86_l_134c;
	case 4942ULL: goto x86_l_134e;
	case 4944ULL: goto x86_l_1350;
	case 4947ULL: goto x86_l_1353;
	case 4949ULL: goto x86_l_1355;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d3d:
	/* 0xd3d: jg     1327 <generic_retkprobe_filter_arg+0x1327> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1327;
	}
x86_l_d43:
	/* 0xd43: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_d46:
	/* 0xd46: je     133a <generic_retkprobe_filter_arg+0x133a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133a;
	}
x86_l_d4c:
	/* 0xd4c: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d51:
	/* 0xd51: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d54:
	/* 0xd54: jne    25f <generic_retkprobe_filter_arg+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 607ULL;
	}
x86_l_d5a:
	/* 0xd5a: movzx  ebx,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_d5f:
	/* 0xd5f: jmp    1af2 <generic_retkprobe_filter_arg+0x1af2> */
	return 6898ULL;
x86_l_d64:
	/* 0xd64: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d67:
	/* 0xd67: jg     1384 <generic_retkprobe_filter_arg+0x1384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4996ULL;
	}
x86_l_d6d:
	/* 0xd6d: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_d70:
	/* 0xd70: je     13c1 <generic_retkprobe_filter_arg+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5057ULL;
	}
x86_l_d76:
	/* 0xd76: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d7b:
	/* 0xd7b: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_d7e:
	/* 0xd7e: je     13b4 <generic_retkprobe_filter_arg+0x13b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5044ULL;
	}
x86_l_d84:
	/* 0xd84: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_d89:
	/* 0xd89: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_d8c:
	/* 0xd8c: je     1485 <generic_retkprobe_filter_arg+0x1485> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5253ULL;
	}
x86_l_d92:
	/* 0xd92: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d97:
	/* 0xd97: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_d9a:
	/* 0xd9a: jne    3423 <generic_retkprobe_filter_arg+0x3423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13347ULL;
	}
x86_l_da0:
	/* 0xda0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da2:
	/* 0xda2: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da5:
	/* 0xda5: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_daa:
	/* 0xdaa: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dae:
	/* 0xdae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_db3:
	/* 0xdb3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_dba:
	/* 0xdba: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dbf:
	/* 0xdbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc1:
	/* 0xdc1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc4:
	/* 0xdc4: je     20a3 <generic_retkprobe_filter_arg+0x20a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8355ULL;
	}
x86_l_dca:
	/* 0xdca: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_dcc:
	/* 0xdcc: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd1:
	/* 0xdd1: je     e3d <generic_retkprobe_filter_arg+0xe3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e3d;
	}
x86_l_dd3:
	/* 0xdd3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dd8:
	/* 0xdd8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dda:
	/* 0xdda: jmp    de7 <generic_retkprobe_filter_arg+0xde7> */
	goto x86_l_de7;
x86_l_ddc:
	/* 0xddc: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ddf:
	/* 0xddf: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_de2:
	/* 0xde2: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_de5:
	/* 0xde5: je     e3d <generic_retkprobe_filter_arg+0xe3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e3d;
	}
x86_l_de7:
	/* 0xde7: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de9:
	/* 0xde9: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_ded:
	/* 0xded: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_df0:
	/* 0xdf0: jae    ddc <generic_retkprobe_filter_arg+0xddc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ddc;
	}
x86_l_df2:
	/* 0xdf2: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_df6:
	/* 0xdf6: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_df8:
	/* 0xdf8: je     e35 <generic_retkprobe_filter_arg+0xe35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e35;
	}
x86_l_dfa:
	/* 0xdfa: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_dff:
	/* 0xdff: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_e03:
	/* 0xe03: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_e06:
	/* 0xe06: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_e0a:
	/* 0xe0a: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_e0e:
	/* 0xe0e: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_e12:
	/* 0xe12: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_e16:
	/* 0xe16: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_e19:
	/* 0xe19: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_e1d:
	/* 0xe1d: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_e21:
	/* 0xe21: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_e25:
	/* 0xe25: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_e29:
	/* 0xe29: ja     ddc <generic_retkprobe_filter_arg+0xddc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ddc;
	}
x86_l_e2b:
	/* 0xe2b: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e2e:
	/* 0xe2e: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_e31:
	/* 0xe31: je     de9 <generic_retkprobe_filter_arg+0xde9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de9;
	}
x86_l_e33:
	/* 0xe33: jmp    ddc <generic_retkprobe_filter_arg+0xddc> */
	goto x86_l_ddc;
x86_l_e35:
	/* 0xe35: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e37:
	/* 0xe37: jns    23ba <generic_retkprobe_filter_arg+0x23ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9146ULL;
	}
x86_l_e3d:
	/* 0xe3d: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e41:
	/* 0xe41: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_e46:
	/* 0xe46: jae    e59 <generic_retkprobe_filter_arg+0xe59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e59;
	}
x86_l_e48:
	/* 0xe48: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_e4c:
	/* 0xe4c: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e4f:
	/* 0xe4f: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_e53:
	/* 0xe53: jne    da5 <generic_retkprobe_filter_arg+0xda5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_da5;
	}
x86_l_e59:
	/* 0xe59: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5b:
	/* 0xe5b: jmp    23bf <generic_retkprobe_filter_arg+0x23bf> */
	return 9151ULL;
x86_l_e60:
	/* 0xe60: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_e63:
	/* 0xe63: jne    1c50 <generic_retkprobe_filter_arg+0x1c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7248ULL;
	}
x86_l_e69:
	/* 0xe69: test   QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6d:
	/* 0xe6d: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_e73:
	/* 0xe73: jmp    1c50 <generic_retkprobe_filter_arg+0x1c50> */
	return 7248ULL;
x86_l_e78:
	/* 0xe78: lea    edx,[rax-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_e7b:
	/* 0xe7b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_e7e:
	/* 0xe7e: jae    1781 <generic_retkprobe_filter_arg+0x1781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6017ULL;
	}
x86_l_e84:
	/* 0xe84: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_e87:
	/* 0xe87: jne    fec <generic_retkprobe_filter_arg+0xfec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fec;
	}
x86_l_e8d:
	/* 0xe8d: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e92:
	/* 0xe92: mov    rdx,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e97:
	/* 0xe97: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_e9a:
	/* 0xe9a: je     ea5 <generic_retkprobe_filter_arg+0xea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea5;
	}
x86_l_e9c:
	/* 0xe9c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_e9f:
	/* 0xe9f: jne    1a4d <generic_retkprobe_filter_arg+0x1a4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6733ULL;
	}
x86_l_ea5:
	/* 0xea5: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea9:
	/* 0xea9: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_eac:
	/* 0xeac: jg     1a5f <generic_retkprobe_filter_arg+0x1a5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6751ULL;
	}
x86_l_eb2:
	/* 0xeb2: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_eb5:
	/* 0xeb5: jle    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 624ULL;
	}
x86_l_ebb:
	/* 0xebb: jmp    1a5f <generic_retkprobe_filter_arg+0x1a5f> */
	return 6751ULL;
x86_l_ec0:
	/* 0xec0: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec5:
	/* 0xec5: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ec9:
	/* 0xec9: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_ed1:
	/* 0xed1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ed6:
	/* 0xed6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_edd:
	/* 0xedd: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ee2:
	/* 0xee2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee4:
	/* 0xee4: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_ee6:
	/* 0xee6: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_eec:
	/* 0xeec: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_eef:
	/* 0xeef: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_ef4:
	/* 0xef4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ef7:
	/* 0xef7: je     3415 <generic_retkprobe_filter_arg+0x3415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13333ULL;
	}
x86_l_efd:
	/* 0xefd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f02:
	/* 0xf02: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_f09:
	/* 0xf09: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f0e:
	/* 0xf0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f10:
	/* 0xf10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f13:
	/* 0xf13: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_f19:
	/* 0xf19: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_f1f:
	/* 0xf1f: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_f24:
	/* 0xf24: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_f27:
	/* 0xf27: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_f2e:
	/* 0xf2e: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f30:
	/* 0xf30: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f33:
	/* 0xf33: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_f37:
	/* 0xf37: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f3c:
	/* 0xf3c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_f3e:
	/* 0xf3e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f43:
	/* 0xf43: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_f46:
	/* 0xf46: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_f49:
	/* 0xf49: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f4b:
	/* 0xf4b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f50:
	/* 0xf50: jmp    19ce <generic_retkprobe_filter_arg+0x19ce> */
	return 6606ULL;
x86_l_f55:
	/* 0xf55: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_f5d:
	/* 0xf5d: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_f63:
	/* 0xf63: ja     28da <generic_retkprobe_filter_arg+0x28da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10458ULL;
	}
x86_l_f69:
	/* 0xf69: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f6c:
	/* 0xf6c: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_f71:
	/* 0xf71: ja     1bd3 <generic_retkprobe_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7123ULL;
	}
x86_l_f77:
	/* 0xf77: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f7b:
	/* 0xf7b: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_f81:
	/* 0xf81: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_f84:
	/* 0xf84: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_f87:
	/* 0xf87: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_f8a:
	/* 0xf8a: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_f8c:
	/* 0xf8c: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_f8f:
	/* 0xf8f: je     f99 <generic_retkprobe_filter_arg+0xf99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f99;
	}
x86_l_f91:
	/* 0xf91: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_f93:
	/* 0xf93: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_f95:
	/* 0xf95: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_f97:
	/* 0xf97: je     fb4 <generic_retkprobe_filter_arg+0xfb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fb4;
	}
x86_l_f99:
	/* 0xf99: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f9c:
	/* 0xf9c: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_f9e:
	/* 0xf9e: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fa0:
	/* 0xfa0: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_fa2:
	/* 0xfa2: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_fa5:
	/* 0xfa5: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_fa8:
	/* 0xfa8: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_fac:
	/* 0xfac: ja     1c0a <generic_retkprobe_filter_arg+0x1c0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7178ULL;
	}
x86_l_fb2:
	/* 0xfb2: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_fb4:
	/* 0xfb4: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_fb7:
	/* 0xfb7: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_fbd:
	/* 0xfbd: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_fc0:
	/* 0xfc0: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_fc2:
	/* 0xfc2: jmp    2818 <generic_retkprobe_filter_arg+0x2818> */
	return 10264ULL;
x86_l_fc7:
	/* 0xfc7: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_fca:
	/* 0xfca: je     13c1 <generic_retkprobe_filter_arg+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5057ULL;
	}
x86_l_fd0:
	/* 0xfd0: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_fd3:
	/* 0xfd3: je     13b4 <generic_retkprobe_filter_arg+0x13b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5044ULL;
	}
x86_l_fd9:
	/* 0xfd9: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_fde:
	/* 0xfde: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_fe1:
	/* 0xfe1: je     1344 <generic_retkprobe_filter_arg+0x1344> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1344;
	}
x86_l_fe7:
	/* 0xfe7: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_fec:
	/* 0xfec: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff1:
	/* 0xff1: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ff6:
	/* 0xff6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_ff9:
	/* 0xff9: je     1004 <generic_retkprobe_filter_arg+0x1004> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1004;
	}
x86_l_ffb:
	/* 0xffb: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_ffe:
	/* 0xffe: jne    1aa0 <generic_retkprobe_filter_arg+0x1aa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6816ULL;
	}
x86_l_1004:
	/* 0x1004: mov    rdx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1008:
	/* 0x1008: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_100b:
	/* 0x100b: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_100f:
	/* 0x100f: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1012:
	/* 0x1012: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1015:
	/* 0x1015: jmp    1ab1 <generic_retkprobe_filter_arg+0x1ab1> */
	return 6833ULL;
x86_l_101a:
	/* 0x101a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_101d:
	/* 0x101d: jne    2126 <generic_retkprobe_filter_arg+0x2126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8486ULL;
	}
x86_l_1023:
	/* 0x1023: test   DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1027:
	/* 0x1027: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_102d:
	/* 0x102d: jmp    2126 <generic_retkprobe_filter_arg+0x2126> */
	return 8486ULL;
x86_l_1032:
	/* 0x1032: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_1037:
	/* 0x1037: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_103b:
	/* 0x103b: jb     15b4 <generic_retkprobe_filter_arg+0x15b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5556ULL;
	}
x86_l_1041:
	/* 0x1041: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_104b:
	/* 0x104b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_104f:
	/* 0x104f: jae    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 193ULL;
	}
x86_l_1055:
	/* 0x1055: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1058:
	/* 0x1058: jne    1d3d <generic_retkprobe_filter_arg+0x1d3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7485ULL;
	}
x86_l_105e:
	/* 0x105e: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1063:
	/* 0x1063: jmp    1096 <generic_retkprobe_filter_arg+0x1096> */
	goto x86_l_1096;
x86_l_1065:
	/* 0x1065: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_106a:
	/* 0x106a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_106e:
	/* 0x106e: jb     15ee <generic_retkprobe_filter_arg+0x15ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5614ULL;
	}
x86_l_1074:
	/* 0x1074: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_107e:
	/* 0x107e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1082:
	/* 0x1082: jae    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 193ULL;
	}
x86_l_1088:
	/* 0x1088: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_108b:
	/* 0x108b: jne    1d49 <generic_retkprobe_filter_arg+0x1d49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7497ULL;
	}
x86_l_1091:
	/* 0x1091: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1096:
	/* 0x1096: cmp    DWORD PTR [r12+0x10],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_109b:
	/* 0x109b: ja     10a8 <generic_retkprobe_filter_arg+0x10a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10a8;
	}
x86_l_109d:
	/* 0x109d: cmp    DWORD PTR [r12+0x14],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10a2:
	/* 0x10a2: jae    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 624ULL;
	}
x86_l_10a8:
	/* 0x10a8: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ad:
	/* 0x10ad: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_10b0:
	/* 0x10b0: jb     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 193ULL;
	}
x86_l_10b6:
	/* 0x10b6: cmp    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10bb:
	/* 0x10bb: ja     10c8 <generic_retkprobe_filter_arg+0x10c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10c8;
	}
x86_l_10bd:
	/* 0x10bd: cmp    DWORD PTR [r12+0x1c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_10c2:
	/* 0x10c2: jae    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 624ULL;
	}
x86_l_10c8:
	/* 0x10c8: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_10cb:
	/* 0x10cb: jb     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 193ULL;
	}
x86_l_10d1:
	/* 0x10d1: cmp    DWORD PTR [r12+0x20],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10d6:
	/* 0x10d6: ja     10e3 <generic_retkprobe_filter_arg+0x10e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10e3;
	}
x86_l_10d8:
	/* 0x10d8: cmp    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_10dd:
	/* 0x10dd: jae    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 624ULL;
	}
x86_l_10e3:
	/* 0x10e3: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_10e6:
	/* 0x10e6: jb     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 193ULL;
	}
x86_l_10ec:
	/* 0x10ec: cmp    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10f1:
	/* 0x10f1: ja     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 193ULL;
	}
x86_l_10f7:
	/* 0x10f7: cmp    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_10fc:
	/* 0x10fc: jae    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 624ULL;
	}
x86_l_1102:
	/* 0x1102: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_1107:
	/* 0x1107: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_110a:
	/* 0x110a: je     1115 <generic_retkprobe_filter_arg+0x1115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1115;
	}
x86_l_110c:
	/* 0x110c: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_110f:
	/* 0x110f: jne    1c3a <generic_retkprobe_filter_arg+0x1c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7226ULL;
	}
x86_l_1115:
	/* 0x1115: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1119:
	/* 0x1119: jg     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 624ULL;
	}
x86_l_111f:
	/* 0x111f: jmp    1c50 <generic_retkprobe_filter_arg+0x1c50> */
	return 7248ULL;
x86_l_1124:
	/* 0x1124: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1127:
	/* 0x1127: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_112c:
	/* 0x112c: ja     167f <generic_retkprobe_filter_arg+0x167f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5759ULL;
	}
x86_l_1132:
	/* 0x1132: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1136:
	/* 0x1136: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_113c:
	/* 0x113c: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_113f:
	/* 0x113f: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1142:
	/* 0x1142: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1145:
	/* 0x1145: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1147:
	/* 0x1147: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_114a:
	/* 0x114a: je     1154 <generic_retkprobe_filter_arg+0x1154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1154;
	}
x86_l_114c:
	/* 0x114c: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_114e:
	/* 0x114e: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1150:
	/* 0x1150: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1152:
	/* 0x1152: je     116f <generic_retkprobe_filter_arg+0x116f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_116f;
	}
x86_l_1154:
	/* 0x1154: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1157:
	/* 0x1157: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1159:
	/* 0x1159: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_115b:
	/* 0x115b: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_115d:
	/* 0x115d: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1160:
	/* 0x1160: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1163:
	/* 0x1163: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1167:
	/* 0x1167: ja     16b6 <generic_retkprobe_filter_arg+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5814ULL;
	}
x86_l_116d:
	/* 0x116d: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_116f:
	/* 0x116f: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1172:
	/* 0x1172: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1178:
	/* 0x1178: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_117b:
	/* 0x117b: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_117d:
	/* 0x117d: jmp    223c <generic_retkprobe_filter_arg+0x223c> */
	return 8764ULL;
x86_l_1182:
	/* 0x1182: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1185:
	/* 0x1185: jg     17c8 <generic_retkprobe_filter_arg+0x17c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6088ULL;
	}
x86_l_118b:
	/* 0x118b: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_118e:
	/* 0x118e: je     1943 <generic_retkprobe_filter_arg+0x1943> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6467ULL;
	}
x86_l_1194:
	/* 0x1194: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1199:
	/* 0x1199: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_119c:
	/* 0x119c: jne    3423 <generic_retkprobe_filter_arg+0x3423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13347ULL;
	}
x86_l_11a2:
	/* 0x11a2: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a7:
	/* 0x11a7: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11ab:
	/* 0x11ab: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_11b3:
	/* 0x11b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11b8:
	/* 0x11b8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_11bf:
	/* 0x11bf: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11c4:
	/* 0x11c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c6:
	/* 0x11c6: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_11c8:
	/* 0x11c8: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_11ce:
	/* 0x11ce: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_11d3:
	/* 0x11d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11d6:
	/* 0x11d6: je     3415 <generic_retkprobe_filter_arg+0x3415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13333ULL;
	}
x86_l_11dc:
	/* 0x11dc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11e1:
	/* 0x11e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11e6:
	/* 0x11e6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_11ed:
	/* 0x11ed: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11f2:
	/* 0x11f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f4:
	/* 0x11f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11f7:
	/* 0x11f7: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_11fd:
	/* 0x11fd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1200:
	/* 0x1200: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_1203:
	/* 0x1203: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_1208:
	/* 0x1208: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_120b:
	/* 0x120b: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_120e:
	/* 0x120e: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1210:
	/* 0x1210: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1213:
	/* 0x1213: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1216:
	/* 0x1216: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_121b:
	/* 0x121b: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_121e:
	/* 0x121e: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_1221:
	/* 0x1221: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1226:
	/* 0x1226: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_122a:
	/* 0x122a: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1230:
	/* 0x1230: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1233:
	/* 0x1233: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1237:
	/* 0x1237: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_123d:
	/* 0x123d: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1240:
	/* 0x1240: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1244:
	/* 0x1244: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1246:
	/* 0x1246: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1248:
	/* 0x1248: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_124b:
	/* 0x124b: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_124f:
	/* 0x124f: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1256:
	/* 0x1256: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_125b:
	/* 0x125b: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_125f:
	/* 0x125f: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_1262:
	/* 0x1262: je     12bc <generic_retkprobe_filter_arg+0x12bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bc;
	}
x86_l_1264:
	/* 0x1264: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1268:
	/* 0x1268: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_126f:
	/* 0x126f: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_1274:
	/* 0x1274: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1278:
	/* 0x1278: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_127b:
	/* 0x127b: je     12bc <generic_retkprobe_filter_arg+0x12bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bc;
	}
x86_l_127d:
	/* 0x127d: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1281:
	/* 0x1281: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1288:
	/* 0x1288: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_128d:
	/* 0x128d: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1291:
	/* 0x1291: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1294:
	/* 0x1294: je     12bc <generic_retkprobe_filter_arg+0x12bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bc;
	}
x86_l_1296:
	/* 0x1296: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_129a:
	/* 0x129a: je     12bc <generic_retkprobe_filter_arg+0x12bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bc;
	}
x86_l_129c:
	/* 0x129c: lea    r13d,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_12a0:
	/* 0x12a0: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12a7:
	/* 0x12a7: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_12ac:
	/* 0x12ac: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12af:
	/* 0x12af: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_12b3:
	/* 0x12b3: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_12b7:
	/* 0x12b7: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_12ba:
	/* 0x12ba: jne    124b <generic_retkprobe_filter_arg+0x124b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_124b;
	}
x86_l_12bc:
	/* 0x12bc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12c1:
	/* 0x12c1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12c6:
	/* 0x12c6: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12cb:
	/* 0x12cb: jmp    3407 <generic_retkprobe_filter_arg+0x3407> */
	return 13319ULL;
x86_l_12d0:
	/* 0x12d0: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d5:
	/* 0x12d5: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12da:
	/* 0x12da: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_12dd:
	/* 0x12dd: ja     1ecf <generic_retkprobe_filter_arg+0x1ecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7887ULL;
	}
x86_l_12e3:
	/* 0x12e3: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_12e8:
	/* 0x12e8: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_12eb:
	/* 0x12eb: jae    1ecf <generic_retkprobe_filter_arg+0x1ecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7887ULL;
	}
x86_l_12f1:
	/* 0x12f1: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f5:
	/* 0x12f5: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_12f7:
	/* 0x12f7: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_12fb:
	/* 0x12fb: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_12fd:
	/* 0x12fd: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1300:
	/* 0x1300: jmp    1ede <generic_retkprobe_filter_arg+0x1ede> */
	return 7902ULL;
x86_l_1305:
	/* 0x1305: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1308:
	/* 0x1308: je     1901 <generic_retkprobe_filter_arg+0x1901> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6401ULL;
	}
x86_l_130e:
	/* 0x130e: mov    r13d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_32);
x86_l_1311:
	/* 0x1311: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1316:
	/* 0x1316: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_1319:
	/* 0x1319: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_131c:
	/* 0x131c: je     186e <generic_retkprobe_filter_arg+0x186e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6254ULL;
	}
x86_l_1322:
	/* 0x1322: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_1327:
	/* 0x1327: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_132a:
	/* 0x132a: je     1344 <generic_retkprobe_filter_arg+0x1344> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1344;
	}
x86_l_132c:
	/* 0x132c: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1331:
	/* 0x1331: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1334:
	/* 0x1334: jne    25f <generic_retkprobe_filter_arg+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 607ULL;
	}
x86_l_133a:
	/* 0x133a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_133d:
	/* 0x133d: movzx  r13d,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1342:
	/* 0x1342: jmp    134c <generic_retkprobe_filter_arg+0x134c> */
	goto x86_l_134c;
x86_l_1344:
	/* 0x1344: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1347:
	/* 0x1347: movzx  r13d,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_134c:
	/* 0x134c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134e:
	/* 0x134e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1350:
	/* 0x1350: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1353:
	/* 0x1353: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1355:
	/* 0x1355: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
	return 4952ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4952ULL: goto x86_l_1358;
	case 4958ULL: goto x86_l_135e;
	case 4961ULL: goto x86_l_1361;
	case 4964ULL: goto x86_l_1364;
	case 4970ULL: goto x86_l_136a;
	case 4973ULL: goto x86_l_136d;
	case 4976ULL: goto x86_l_1370;
	case 4982ULL: goto x86_l_1376;
	case 4985ULL: goto x86_l_1379;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 4999ULL: goto x86_l_1387;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5019ULL: goto x86_l_139b;
	case 5022ULL: goto x86_l_139e;
	case 5028ULL: goto x86_l_13a4;
	case 5031ULL: goto x86_l_13a7;
	case 5037ULL: goto x86_l_13ad;
	case 5039ULL: goto x86_l_13af;
	case 5044ULL: goto x86_l_13b4;
	case 5048ULL: goto x86_l_13b8;
	case 5051ULL: goto x86_l_13bb;
	case 5055ULL: goto x86_l_13bf;
	case 5057ULL: goto x86_l_13c1;
	case 5061ULL: goto x86_l_13c5;
	case 5064ULL: goto x86_l_13c8;
	case 5068ULL: goto x86_l_13cc;
	case 5071ULL: goto x86_l_13cf;
	case 5075ULL: goto x86_l_13d3;
	case 5078ULL: goto x86_l_13d6;
	case 5080ULL: goto x86_l_13d8;
	case 5083ULL: goto x86_l_13db;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5094ULL: goto x86_l_13e6;
	case 5099ULL: goto x86_l_13eb;
	case 5102ULL: goto x86_l_13ee;
	case 5108ULL: goto x86_l_13f4;
	case 5113ULL: goto x86_l_13f9;
	case 5116ULL: goto x86_l_13fc;
	case 5122ULL: goto x86_l_1402;
	case 5127ULL: goto x86_l_1407;
	case 5130ULL: goto x86_l_140a;
	case 5136ULL: goto x86_l_1410;
	case 5140ULL: goto x86_l_1414;
	case 5143ULL: goto x86_l_1417;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5158ULL: goto x86_l_1426;
	case 5161ULL: goto x86_l_1429;
	case 5166ULL: goto x86_l_142e;
	case 5170ULL: goto x86_l_1432;
	case 5175ULL: goto x86_l_1437;
	case 5182ULL: goto x86_l_143e;
	case 5187ULL: goto x86_l_1443;
	case 5189ULL: goto x86_l_1445;
	case 5192ULL: goto x86_l_1448;
	case 5198ULL: goto x86_l_144e;
	case 5206ULL: goto x86_l_1456;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5232ULL: goto x86_l_1470;
	case 5238ULL: goto x86_l_1476;
	case 5242ULL: goto x86_l_147a;
	case 5248ULL: goto x86_l_1480;
	case 5253ULL: goto x86_l_1485;
	case 5255ULL: goto x86_l_1487;
	case 5258ULL: goto x86_l_148a;
	case 5263ULL: goto x86_l_148f;
	case 5267ULL: goto x86_l_1493;
	case 5272ULL: goto x86_l_1498;
	case 5279ULL: goto x86_l_149f;
	case 5284ULL: goto x86_l_14a4;
	case 5286ULL: goto x86_l_14a6;
	case 5289ULL: goto x86_l_14a9;
	case 5295ULL: goto x86_l_14af;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5316ULL: goto x86_l_14c4;
	case 5318ULL: goto x86_l_14c6;
	case 5321ULL: goto x86_l_14c9;
	case 5324ULL: goto x86_l_14cc;
	case 5327ULL: goto x86_l_14cf;
	case 5329ULL: goto x86_l_14d1;
	case 5331ULL: goto x86_l_14d3;
	case 5335ULL: goto x86_l_14d7;
	case 5338ULL: goto x86_l_14da;
	case 5340ULL: goto x86_l_14dc;
	case 5344ULL: goto x86_l_14e0;
	case 5347ULL: goto x86_l_14e3;
	case 5349ULL: goto x86_l_14e5;
	case 5353ULL: goto x86_l_14e9;
	case 5355ULL: goto x86_l_14eb;
	case 5359ULL: goto x86_l_14ef;
	case 5363ULL: goto x86_l_14f3;
	case 5366ULL: goto x86_l_14f6;
	case 5368ULL: goto x86_l_14f8;
	case 5370ULL: goto x86_l_14fa;
	case 5372ULL: goto x86_l_14fc;
	case 5378ULL: goto x86_l_1502;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5393ULL: goto x86_l_1511;
	case 5397ULL: goto x86_l_1515;
	case 5400ULL: goto x86_l_1518;
	case 5404ULL: goto x86_l_151c;
	case 5410ULL: goto x86_l_1522;
	case 5415ULL: goto x86_l_1527;
	case 5418ULL: goto x86_l_152a;
	case 5421ULL: goto x86_l_152d;
	case 5427ULL: goto x86_l_1533;
	case 5433ULL: goto x86_l_1539;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5449ULL: goto x86_l_1549;
	case 5454ULL: goto x86_l_154e;
	case 5456ULL: goto x86_l_1550;
	case 5459ULL: goto x86_l_1553;
	case 5465ULL: goto x86_l_1559;
	case 5469ULL: goto x86_l_155d;
	case 5474ULL: goto x86_l_1562;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5487ULL: goto x86_l_156f;
	case 5493ULL: goto x86_l_1575;
	case 5496ULL: goto x86_l_1578;
	case 5502ULL: goto x86_l_157e;
	case 5507ULL: goto x86_l_1583;
	case 5509ULL: goto x86_l_1585;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5523ULL: goto x86_l_1593;
	case 5529ULL: goto x86_l_1599;
	case 5532ULL: goto x86_l_159c;
	case 5538ULL: goto x86_l_15a2;
	case 5543ULL: goto x86_l_15a7;
	case 5545ULL: goto x86_l_15a9;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5562ULL: goto x86_l_15ba;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5578ULL: goto x86_l_15ca;
	case 5583ULL: goto x86_l_15cf;
	case 5585ULL: goto x86_l_15d1;
	case 5588ULL: goto x86_l_15d4;
	case 5594ULL: goto x86_l_15da;
	case 5599ULL: goto x86_l_15df;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5614ULL: goto x86_l_15ee;
	case 5620ULL: goto x86_l_15f4;
	case 5624ULL: goto x86_l_15f8;
	case 5629ULL: goto x86_l_15fd;
	case 5636ULL: goto x86_l_1604;
	case 5641ULL: goto x86_l_1609;
	case 5643ULL: goto x86_l_160b;
	case 5646ULL: goto x86_l_160e;
	case 5652ULL: goto x86_l_1614;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5679ULL: goto x86_l_162f;
	case 5685ULL: goto x86_l_1635;
	case 5688ULL: goto x86_l_1638;
	case 5694ULL: goto x86_l_163e;
	case 5696ULL: goto x86_l_1640;
	case 5702ULL: goto x86_l_1646;
	case 5705ULL: goto x86_l_1649;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5725ULL: goto x86_l_165d;
	case 5727ULL: goto x86_l_165f;
	case 5732ULL: goto x86_l_1664;
	case 5735ULL: goto x86_l_1667;
	case 5740ULL: goto x86_l_166c;
	case 5744ULL: goto x86_l_1670;
	case 5746ULL: goto x86_l_1672;
	case 5751ULL: goto x86_l_1677;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5793ULL: goto x86_l_16a1;
	case 5795ULL: goto x86_l_16a3;
	case 5797ULL: goto x86_l_16a5;
	case 5802ULL: goto x86_l_16aa;
	case 5805ULL: goto x86_l_16ad;
	case 5808ULL: goto x86_l_16b0;
	case 5814ULL: goto x86_l_16b6;
	case 5820ULL: goto x86_l_16bc;
	case 5826ULL: goto x86_l_16c2;
	case 5829ULL: goto x86_l_16c5;
	case 5835ULL: goto x86_l_16cb;
	case 5837ULL: goto x86_l_16cd;
	case 5843ULL: goto x86_l_16d3;
	case 5846ULL: goto x86_l_16d6;
	case 5852ULL: goto x86_l_16dc;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5877ULL: goto x86_l_16f5;
	case 5882ULL: goto x86_l_16fa;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5896ULL: goto x86_l_1708;
	case 5899ULL: goto x86_l_170b;
	case 5905ULL: goto x86_l_1711;
	case 5913ULL: goto x86_l_1719;
	case 5917ULL: goto x86_l_171d;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5930ULL: goto x86_l_172a;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5943ULL: goto x86_l_1737;
	case 5948ULL: goto x86_l_173c;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5963ULL: goto x86_l_174b;
	case 5966ULL: goto x86_l_174e;
	case 5969ULL: goto x86_l_1751;
	case 5973ULL: goto x86_l_1755;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5985ULL: goto x86_l_1761;
	case 5988ULL: goto x86_l_1764;
	case 5991ULL: goto x86_l_1767;
	case 5994ULL: goto x86_l_176a;
	case 5999ULL: goto x86_l_176f;
	case 6001ULL: goto x86_l_1771;
	case 6004ULL: goto x86_l_1774;
	case 6009ULL: goto x86_l_1779;
	case 6012ULL: goto x86_l_177c;
	case 6017ULL: goto x86_l_1781;
	case 6020ULL: goto x86_l_1784;
	case 6026ULL: goto x86_l_178a;
	case 6031ULL: goto x86_l_178f;
	case 6034ULL: goto x86_l_1792;
	case 6036ULL: goto x86_l_1794;
	case 6045ULL: goto x86_l_179d;
	case 6051ULL: goto x86_l_17a3;
	case 6055ULL: goto x86_l_17a7;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6070ULL: goto x86_l_17b6;
	case 6080ULL: goto x86_l_17c0;
	case 6083ULL: goto x86_l_17c3;
	case 6088ULL: goto x86_l_17c8;
	case 6093ULL: goto x86_l_17cd;
	case 6096ULL: goto x86_l_17d0;
	case 6102ULL: goto x86_l_17d6;
	case 6107ULL: goto x86_l_17db;
	case 6110ULL: goto x86_l_17de;
	case 6116ULL: goto x86_l_17e4;
	case 6122ULL: goto x86_l_17ea;
	case 6126ULL: goto x86_l_17ee;
	case 6130ULL: goto x86_l_17f2;
	case 6135ULL: goto x86_l_17f7;
	case 6142ULL: goto x86_l_17fe;
	case 6147ULL: goto x86_l_1803;
	case 6149ULL: goto x86_l_1805;
	case 6152ULL: goto x86_l_1808;
	case 6158ULL: goto x86_l_180e;
	case 6163ULL: goto x86_l_1813;
	case 6166ULL: goto x86_l_1816;
	case 6169ULL: goto x86_l_1819;
	case 6174ULL: goto x86_l_181e;
	case 6176ULL: goto x86_l_1820;
	case 6182ULL: goto x86_l_1826;
	case 6186ULL: goto x86_l_182a;
	case 6190ULL: goto x86_l_182e;
	case 6195ULL: goto x86_l_1833;
	case 6199ULL: goto x86_l_1837;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6215ULL: goto x86_l_1847;
	case 6220ULL: goto x86_l_184c;
	case 6227ULL: goto x86_l_1853;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6237ULL: goto x86_l_185d;
	case 6242ULL: goto x86_l_1862;
	case 6245ULL: goto x86_l_1865;
	case 6248ULL: goto x86_l_1868;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6263ULL: goto x86_l_1877;
	case 6271ULL: goto x86_l_187f;
	case 6276ULL: goto x86_l_1884;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6290ULL: goto x86_l_1892;
	case 6293ULL: goto x86_l_1895;
	case 6299ULL: goto x86_l_189b;
	case 6304ULL: goto x86_l_18a0;
	case 6307ULL: goto x86_l_18a3;
	case 6313ULL: goto x86_l_18a9;
	case 6316ULL: goto x86_l_18ac;
	case 6321ULL: goto x86_l_18b1;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6335ULL: goto x86_l_18bf;
	case 6338ULL: goto x86_l_18c2;
	case 6344ULL: goto x86_l_18c8;
	case 6346ULL: goto x86_l_18ca;
	case 6349ULL: goto x86_l_18cd;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6358ULL: goto x86_l_18d6;
	case 6363ULL: goto x86_l_18db;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6375ULL: goto x86_l_18e7;
	case 6380ULL: goto x86_l_18ec;
	case 6383ULL: goto x86_l_18ef;
	case 6386ULL: goto x86_l_18f2;
	case 6388ULL: goto x86_l_18f4;
	case 6390ULL: goto x86_l_18f6;
	case 6393ULL: goto x86_l_18f9;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6412ULL: goto x86_l_190c;
	case 6416ULL: goto x86_l_1910;
	case 6421ULL: goto x86_l_1915;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6435ULL: goto x86_l_1923;
	case 6438ULL: goto x86_l_1926;
	case 6444ULL: goto x86_l_192c;
	case 6449ULL: goto x86_l_1931;
	case 6454ULL: goto x86_l_1936;
	case 6457ULL: goto x86_l_1939;
	case 6462ULL: goto x86_l_193e;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6484ULL: goto x86_l_1954;
	case 6489ULL: goto x86_l_1959;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6503ULL: goto x86_l_1967;
	case 6505ULL: goto x86_l_1969;
	case 6511ULL: goto x86_l_196f;
	case 6516ULL: goto x86_l_1974;
	case 6519ULL: goto x86_l_1977;
	case 6525ULL: goto x86_l_197d;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6540ULL: goto x86_l_198c;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6550ULL: goto x86_l_1996;
	case 6556ULL: goto x86_l_199c;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6570ULL: goto x86_l_19aa;
	case 6577ULL: goto x86_l_19b1;
	case 6579ULL: goto x86_l_19b3;
	case 6582ULL: goto x86_l_19b6;
	case 6586ULL: goto x86_l_19ba;
	case 6591ULL: goto x86_l_19bf;
	case 6593ULL: goto x86_l_19c1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1358:
	/* 0x1358: jg     13dd <generic_retkprobe_filter_arg+0x13dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_13dd;
	}
x86_l_135e:
	/* 0x135e: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_1361:
	/* 0x1361: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1364:
	/* 0x1364: jb     1410 <generic_retkprobe_filter_arg+0x1410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1410;
	}
x86_l_136a:
	/* 0x136a: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_136d:
	/* 0x136d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1370:
	/* 0x1370: jb     1533 <generic_retkprobe_filter_arg+0x1533> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1533;
	}
x86_l_1376:
	/* 0x1376: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1379:
	/* 0x1379: je     1af2 <generic_retkprobe_filter_arg+0x1af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6898ULL;
	}
x86_l_137f:
	/* 0x137f: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_1384:
	/* 0x1384: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1387:
	/* 0x1387: je     1aed <generic_retkprobe_filter_arg+0x1aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6893ULL;
	}
x86_l_138d:
	/* 0x138d: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1392:
	/* 0x1392: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_1395:
	/* 0x1395: jne    25f <generic_retkprobe_filter_arg+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 607ULL;
	}
x86_l_139b:
	/* 0x139b: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_139e:
	/* 0x139e: jne    203d <generic_retkprobe_filter_arg+0x203d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8253ULL;
	}
x86_l_13a4:
	/* 0x13a4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_13a7:
	/* 0x13a7: jne    2049 <generic_retkprobe_filter_arg+0x2049> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8265ULL;
	}
x86_l_13ad:
	/* 0x13ad: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13af:
	/* 0x13af: jmp    205b <generic_retkprobe_filter_arg+0x205b> */
	return 8283ULL;
x86_l_13b4:
	/* 0x13b4: mov    rsi,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13b8:
	/* 0x13b8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_13bb:
	/* 0x13bb: mov    r8,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13bf:
	/* 0x13bf: jmp    13cc <generic_retkprobe_filter_arg+0x13cc> */
	goto x86_l_13cc;
x86_l_13c1:
	/* 0x13c1: mov    rsi,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c5:
	/* 0x13c5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_13c8:
	/* 0x13c8: mov    r8,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13cc:
	/* 0x13cc: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_13cf:
	/* 0x13cf: shr    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_13d3:
	/* 0x13d3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13d6:
	/* 0x13d6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13d8:
	/* 0x13d8: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_13db:
	/* 0x13db: jle    135e <generic_retkprobe_filter_arg+0x135e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_135e;
	}
x86_l_13dd:
	/* 0x13dd: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_13e0:
	/* 0x13e0: ja     1527 <generic_retkprobe_filter_arg+0x1527> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1527;
	}
x86_l_13e6:
	/* 0x13e6: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_13eb:
	/* 0x13eb: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_13ee:
	/* 0x13ee: jb     1659 <generic_retkprobe_filter_arg+0x1659> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1659;
	}
x86_l_13f4:
	/* 0x13f4: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_13f9:
	/* 0x13f9: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_13fc:
	/* 0x13fc: jb     166c <generic_retkprobe_filter_arg+0x166c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_166c;
	}
x86_l_1402:
	/* 0x1402: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_1407:
	/* 0x1407: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_140a:
	/* 0x140a: jae    1527 <generic_retkprobe_filter_arg+0x1527> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1527;
	}
x86_l_1410:
	/* 0x1410: movzx  eax,WORD PTR [rdx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1414:
	/* 0x1414: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1417:
	/* 0x1417: je     16e6 <generic_retkprobe_filter_arg+0x16e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16e6;
	}
x86_l_141d:
	/* 0x141d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1420:
	/* 0x1420: jne    176f <generic_retkprobe_filter_arg+0x176f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_176f;
	}
x86_l_1426:
	/* 0x1426: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1429:
	/* 0x1429: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_142e:
	/* 0x142e: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1432:
	/* 0x1432: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1437:
	/* 0x1437: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_143e:
	/* 0x143e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1443:
	/* 0x1443: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1445:
	/* 0x1445: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1448:
	/* 0x1448: je     1baf <generic_retkprobe_filter_arg+0x1baf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7087ULL;
	}
x86_l_144e:
	/* 0x144e: mov    DWORD PTR [rsp+0x68],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598816ULL);
x86_l_1456:
	/* 0x1456: mov    DWORD PTR [rsp+0x6c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_145a:
	/* 0x145a: jmp    172f <generic_retkprobe_filter_arg+0x172f> */
	goto x86_l_172f;
x86_l_145f:
	/* 0x145f: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1462:
	/* 0x1462: ja     2110 <generic_retkprobe_filter_arg+0x2110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8464ULL;
	}
x86_l_1468:
	/* 0x1468: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_146d:
	/* 0x146d: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1470:
	/* 0x1470: jae    2110 <generic_retkprobe_filter_arg+0x2110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8464ULL;
	}
x86_l_1476:
	/* 0x1476: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_147a:
	/* 0x147a: jg     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 624ULL;
	}
x86_l_1480:
	/* 0x1480: jmp    2126 <generic_retkprobe_filter_arg+0x2126> */
	return 8486ULL;
x86_l_1485:
	/* 0x1485: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1487:
	/* 0x1487: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_148a:
	/* 0x148a: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_148f:
	/* 0x148f: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1493:
	/* 0x1493: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1498:
	/* 0x1498: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_149f:
	/* 0x149f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14a4:
	/* 0x14a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a6:
	/* 0x14a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a9:
	/* 0x14a9: je     1fe0 <generic_retkprobe_filter_arg+0x1fe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8160ULL;
	}
x86_l_14af:
	/* 0x14af: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_14b1:
	/* 0x14b1: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b6:
	/* 0x14b6: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14bb:
	/* 0x14bb: je     1502 <generic_retkprobe_filter_arg+0x1502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1502;
	}
x86_l_14bd:
	/* 0x14bd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14c2:
	/* 0x14c2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c4:
	/* 0x14c4: jmp    14d1 <generic_retkprobe_filter_arg+0x14d1> */
	goto x86_l_14d1;
x86_l_14c6:
	/* 0x14c6: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_14c9:
	/* 0x14c9: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_14cc:
	/* 0x14cc: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_14cf:
	/* 0x14cf: je     1502 <generic_retkprobe_filter_arg+0x1502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1502;
	}
x86_l_14d1:
	/* 0x14d1: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d3:
	/* 0x14d3: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_14d7:
	/* 0x14d7: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_14da:
	/* 0x14da: jae    14c6 <generic_retkprobe_filter_arg+0x14c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_14c6;
	}
x86_l_14dc:
	/* 0x14dc: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_14e0:
	/* 0x14e0: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_14e3:
	/* 0x14e3: je     14fa <generic_retkprobe_filter_arg+0x14fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14fa;
	}
x86_l_14e5:
	/* 0x14e5: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_14e9:
	/* 0x14e9: ja     14c6 <generic_retkprobe_filter_arg+0x14c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_14c6;
	}
x86_l_14eb:
	/* 0x14eb: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_14ef:
	/* 0x14ef: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_14f3:
	/* 0x14f3: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_14f6:
	/* 0x14f6: je     14d3 <generic_retkprobe_filter_arg+0x14d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14d3;
	}
x86_l_14f8:
	/* 0x14f8: jmp    14c6 <generic_retkprobe_filter_arg+0x14c6> */
	goto x86_l_14c6;
x86_l_14fa:
	/* 0x14fa: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_14fc:
	/* 0x14fc: jns    221b <generic_retkprobe_filter_arg+0x221b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 8731ULL;
	}
x86_l_1502:
	/* 0x1502: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1506:
	/* 0x1506: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_150b:
	/* 0x150b: jae    1fd5 <generic_retkprobe_filter_arg+0x1fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8149ULL;
	}
x86_l_1511:
	/* 0x1511: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1515:
	/* 0x1515: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1518:
	/* 0x1518: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_151c:
	/* 0x151c: jne    148a <generic_retkprobe_filter_arg+0x148a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_148a;
	}
x86_l_1522:
	/* 0x1522: jmp    1fd5 <generic_retkprobe_filter_arg+0x1fd5> */
	return 8149ULL;
x86_l_1527:
	/* 0x1527: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_152a:
	/* 0x152a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_152d:
	/* 0x152d: jae    25f <generic_retkprobe_filter_arg+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 607ULL;
	}
x86_l_1533:
	/* 0x1533: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1539:
	/* 0x1539: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_153d:
	/* 0x153d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1542:
	/* 0x1542: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1549:
	/* 0x1549: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_154e:
	/* 0x154e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1550:
	/* 0x1550: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1553:
	/* 0x1553: je     208e <generic_retkprobe_filter_arg+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8334ULL;
	}
x86_l_1559:
	/* 0x1559: movzx  ecx,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_155d:
	/* 0x155d: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1562:
	/* 0x1562: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1567:
	/* 0x1567: jmp    1b25 <generic_retkprobe_filter_arg+0x1b25> */
	return 6949ULL;
x86_l_156c:
	/* 0x156c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_156f:
	/* 0x156f: je     1de7 <generic_retkprobe_filter_arg+0x1de7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7655ULL;
	}
x86_l_1575:
	/* 0x1575: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1578:
	/* 0x1578: jne    1df4 <generic_retkprobe_filter_arg+0x1df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7668ULL;
	}
x86_l_157e:
	/* 0x157e: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1583:
	/* 0x1583: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1585:
	/* 0x1585: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_158b:
	/* 0x158b: jmp    1df4 <generic_retkprobe_filter_arg+0x1df4> */
	return 7668ULL;
x86_l_1590:
	/* 0x1590: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1593:
	/* 0x1593: je     1e2e <generic_retkprobe_filter_arg+0x1e2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7726ULL;
	}
x86_l_1599:
	/* 0x1599: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_159c:
	/* 0x159c: jne    1e3b <generic_retkprobe_filter_arg+0x1e3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7739ULL;
	}
x86_l_15a2:
	/* 0x15a2: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15a7:
	/* 0x15a7: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_15a9:
	/* 0x15a9: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_15af:
	/* 0x15af: jmp    1e3b <generic_retkprobe_filter_arg+0x1e3b> */
	return 7739ULL;
x86_l_15b4:
	/* 0x15b4: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_15ba:
	/* 0x15ba: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15be:
	/* 0x15be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15c3:
	/* 0x15c3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_15ca:
	/* 0x15ca: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15cf:
	/* 0x15cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d1:
	/* 0x15d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15d4:
	/* 0x15d4: je     208e <generic_retkprobe_filter_arg+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8334ULL;
	}
x86_l_15da:
	/* 0x15da: movzx  ecx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15df:
	/* 0x15df: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15e4:
	/* 0x15e4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15e9:
	/* 0x15e9: jmp    1936 <generic_retkprobe_filter_arg+0x1936> */
	goto x86_l_1936;
x86_l_15ee:
	/* 0x15ee: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_15f4:
	/* 0x15f4: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15f8:
	/* 0x15f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15fd:
	/* 0x15fd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1604:
	/* 0x1604: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1609:
	/* 0x1609: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160b:
	/* 0x160b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_160e:
	/* 0x160e: je     208e <generic_retkprobe_filter_arg+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8334ULL;
	}
x86_l_1614:
	/* 0x1614: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1619:
	/* 0x1619: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_161e:
	/* 0x161e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1623:
	/* 0x1623: jmp    1936 <generic_retkprobe_filter_arg+0x1936> */
	goto x86_l_1936;
x86_l_1628:
	/* 0x1628: lea    eax,[r8-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_162f:
	/* 0x162f: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1635:
	/* 0x1635: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1638:
	/* 0x1638: jg     1dcb <generic_retkprobe_filter_arg+0x1dcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7627ULL;
	}
x86_l_163e:
	/* 0x163e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1640:
	/* 0x1640: je     242c <generic_retkprobe_filter_arg+0x242c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9260ULL;
	}
x86_l_1646:
	/* 0x1646: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1649:
	/* 0x1649: jne    2425 <generic_retkprobe_filter_arg+0x2425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9253ULL;
	}
x86_l_164f:
	/* 0x164f: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1654:
	/* 0x1654: jmp    2438 <generic_retkprobe_filter_arg+0x2438> */
	return 9272ULL;
x86_l_1659:
	/* 0x1659: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_165d:
	/* 0x165d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_165f:
	/* 0x165f: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_1664:
	/* 0x1664: setb   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_B);
x86_l_1667:
	/* 0x1667: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_166c:
	/* 0x166c: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1670:
	/* 0x1670: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1672:
	/* 0x1672: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_1677:
	/* 0x1677: setae  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_AE);
x86_l_167a:
	/* 0x167a: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_167f:
	/* 0x167f: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1684:
	/* 0x1684: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1689:
	/* 0x1689: jb     16b6 <generic_retkprobe_filter_arg+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16b6;
	}
x86_l_168b:
	/* 0x168b: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_1690:
	/* 0x1690: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1695:
	/* 0x1695: jb     16b6 <generic_retkprobe_filter_arg+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16b6;
	}
x86_l_1697:
	/* 0x1697: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_169c:
	/* 0x169c: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_16a1:
	/* 0x16a1: jb     16b6 <generic_retkprobe_filter_arg+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16b6;
	}
x86_l_16a3:
	/* 0x16a3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a5:
	/* 0x16a5: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_16aa:
	/* 0x16aa: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_16ad:
	/* 0x16ad: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_16b0:
	/* 0x16b0: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_16b6:
	/* 0x16b6: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_16bc:
	/* 0x16bc: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_16c2:
	/* 0x16c2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16c5:
	/* 0x16c5: jg     1d04 <generic_retkprobe_filter_arg+0x1d04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7428ULL;
	}
x86_l_16cb:
	/* 0x16cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16cd:
	/* 0x16cd: je     2230 <generic_retkprobe_filter_arg+0x2230> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8752ULL;
	}
x86_l_16d3:
	/* 0x16d3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16d6:
	/* 0x16d6: jne    2229 <generic_retkprobe_filter_arg+0x2229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8745ULL;
	}
x86_l_16dc:
	/* 0x16dc: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_16e1:
	/* 0x16e1: jmp    223c <generic_retkprobe_filter_arg+0x223c> */
	return 8764ULL;
x86_l_16e6:
	/* 0x16e6: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_16e9:
	/* 0x16e9: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_16ec:
	/* 0x16ec: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_16f1:
	/* 0x16f1: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16f5:
	/* 0x16f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16fa:
	/* 0x16fa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_1701:
	/* 0x1701: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1706:
	/* 0x1706: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1708:
	/* 0x1708: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_170b:
	/* 0x170b: je     1baf <generic_retkprobe_filter_arg+0x1baf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7087ULL;
	}
x86_l_1711:
	/* 0x1711: mov    DWORD PTR [rsp+0x68],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598912ULL);
x86_l_1719:
	/* 0x1719: mov    DWORD PTR [rsp+0x6c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_171d:
	/* 0x171d: mov    DWORD PTR [rsp+0x70],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1721:
	/* 0x1721: mov    DWORD PTR [rsp+0x74],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1726:
	/* 0x1726: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_172a:
	/* 0x172a: mov    DWORD PTR [rsp+0x78],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_172f:
	/* 0x172f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1734:
	/* 0x1734: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1737:
	/* 0x1737: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_173c:
	/* 0x173c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_173e:
	/* 0x173e: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1743:
	/* 0x1743: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_1746:
	/* 0x1746: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1749:
	/* 0x1749: jb     1779 <generic_retkprobe_filter_arg+0x1779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1779;
	}
x86_l_174b:
	/* 0x174b: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_174e:
	/* 0x174e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1751:
	/* 0x1751: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1755:
	/* 0x1755: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_175a:
	/* 0x175a: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_175f:
	/* 0x175f: ja     176f <generic_retkprobe_filter_arg+0x176f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_176f;
	}
x86_l_1761:
	/* 0x1761: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1764:
	/* 0x1764: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1767:
	/* 0x1767: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_176a:
	/* 0x176a: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_176f:
	/* 0x176f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1771:
	/* 0x1771: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1774:
	/* 0x1774: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_1779:
	/* 0x1779: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_177c:
	/* 0x177c: jmp    1bba <generic_retkprobe_filter_arg+0x1bba> */
	return 7098ULL;
x86_l_1781:
	/* 0x1781: cmp    eax,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_1784:
	/* 0x1784: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_178a:
	/* 0x178a: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_178f:
	/* 0x178f: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1792:
	/* 0x1792: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1794:
	/* 0x1794: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_179d:
	/* 0x179d: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_17a3:
	/* 0x17a3: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17a7:
	/* 0x17a7: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_17af:
	/* 0x17af: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_17b4:
	/* 0x17b4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b6:
	/* 0x17b6: andn   rax,rcx,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_17c0:
	/* 0x17c0: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_17c3:
	/* 0x17c3: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_17c8:
	/* 0x17c8: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17cd:
	/* 0x17cd: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_17d0:
	/* 0x17d0: je     1f40 <generic_retkprobe_filter_arg+0x1f40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8000ULL;
	}
x86_l_17d6:
	/* 0x17d6: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_17db:
	/* 0x17db: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_17de:
	/* 0x17de: jne    3423 <generic_retkprobe_filter_arg+0x3423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13347ULL;
	}
x86_l_17e4:
	/* 0x17e4: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_17ea:
	/* 0x17ea: mov    eax,DWORD PTR [r12+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_17ee:
	/* 0x17ee: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17f2:
	/* 0x17f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17f7:
	/* 0x17f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_17fe:
	/* 0x17fe: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1803:
	/* 0x1803: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1805:
	/* 0x1805: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1808:
	/* 0x1808: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_180e:
	/* 0x180e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1813:
	/* 0x1813: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1816:
	/* 0x1816: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1819:
	/* 0x1819: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 6174ULL);
	__x86_sim_call_depth++;
	return 13459ULL;
x86_l_181e:
	/* 0x181e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1820:
	/* 0x1820: jns    2b2a <generic_retkprobe_filter_arg+0x2b2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11050ULL;
	}
x86_l_1826:
	/* 0x1826: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_182a:
	/* 0x182a: lea    eax,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_182e:
	/* 0x182e: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1833:
	/* 0x1833: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1837:
	/* 0x1837: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_183c:
	/* 0x183c: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1841:
	/* 0x1841: jae    28da <generic_retkprobe_filter_arg+0x28da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10458ULL;
	}
x86_l_1847:
	/* 0x1847: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_184c:
	/* 0x184c: cmp    r13,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 416ULL);
x86_l_1853:
	/* 0x1853: jne    17ea <generic_retkprobe_filter_arg+0x17ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17ea;
	}
x86_l_1855:
	/* 0x1855: jmp    3423 <generic_retkprobe_filter_arg+0x3423> */
	return 13347ULL;
x86_l_185a:
	/* 0x185a: mov    r13d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_32);
x86_l_185d:
	/* 0x185d: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1862:
	/* 0x1862: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_1865:
	/* 0x1865: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1868:
	/* 0x1868: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_186e:
	/* 0x186e: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1873:
	/* 0x1873: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1877:
	/* 0x1877: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_187f:
	/* 0x187f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1884:
	/* 0x1884: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_188b:
	/* 0x188b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1890:
	/* 0x1890: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1892:
	/* 0x1892: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_1895:
	/* 0x1895: je     1b77 <generic_retkprobe_filter_arg+0x1b77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7031ULL;
	}
x86_l_189b:
	/* 0x189b: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_18a0:
	/* 0x18a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18a3:
	/* 0x18a3: je     1b79 <generic_retkprobe_filter_arg+0x1b79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7033ULL;
	}
x86_l_18a9:
	/* 0x18a9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_18ac:
	/* 0x18ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18b1:
	/* 0x18b1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_18b8:
	/* 0x18b8: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18bd:
	/* 0x18bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18bf:
	/* 0x18bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18c2:
	/* 0x18c2: je     1b77 <generic_retkprobe_filter_arg+0x1b77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7031ULL;
	}
x86_l_18c8:
	/* 0x18c8: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_18ca:
	/* 0x18ca: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_18cd:
	/* 0x18cd: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18cf:
	/* 0x18cf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_18d2:
	/* 0x18d2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_18d6:
	/* 0x18d6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18db:
	/* 0x18db: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_18dd:
	/* 0x18dd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18e2:
	/* 0x18e2: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_18e5:
	/* 0x18e5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_18e7:
	/* 0x18e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18ec:
	/* 0x18ec: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_18ef:
	/* 0x18ef: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_18f2:
	/* 0x18f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f4:
	/* 0x18f4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18f6:
	/* 0x18f6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18f9:
	/* 0x18f9: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_18fc:
	/* 0x18fc: jmp    1b79 <generic_retkprobe_filter_arg+0x1b79> */
	return 7033ULL;
x86_l_1901:
	/* 0x1901: movzx  ebx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1906:
	/* 0x1906: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_190c:
	/* 0x190c: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1910:
	/* 0x1910: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1915:
	/* 0x1915: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_191c:
	/* 0x191c: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1921:
	/* 0x1921: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1923:
	/* 0x1923: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1926:
	/* 0x1926: je     208e <generic_retkprobe_filter_arg+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8334ULL;
	}
x86_l_192c:
	/* 0x192c: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1931:
	/* 0x1931: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1936:
	/* 0x1936: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1939:
	/* 0x1939: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_193e:
	/* 0x193e: jmp    1b2d <generic_retkprobe_filter_arg+0x1b2d> */
	return 6957ULL;
x86_l_1943:
	/* 0x1943: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1948:
	/* 0x1948: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_194c:
	/* 0x194c: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1954:
	/* 0x1954: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1959:
	/* 0x1959: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1960:
	/* 0x1960: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1965:
	/* 0x1965: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1967:
	/* 0x1967: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1969:
	/* 0x1969: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_196f:
	/* 0x196f: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1974:
	/* 0x1974: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1977:
	/* 0x1977: je     3415 <generic_retkprobe_filter_arg+0x3415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13333ULL;
	}
x86_l_197d:
	/* 0x197d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1980:
	/* 0x1980: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1985:
	/* 0x1985: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_198c:
	/* 0x198c: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1991:
	/* 0x1991: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1993:
	/* 0x1993: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1996:
	/* 0x1996: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_199c:
	/* 0x199c: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_19a2:
	/* 0x19a2: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_19a7:
	/* 0x19a7: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_19aa:
	/* 0x19aa: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_19b1:
	/* 0x19b1: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b3:
	/* 0x19b3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_19b6:
	/* 0x19b6: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_19ba:
	/* 0x19ba: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19bf:
	/* 0x19bf: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_19c1:
	/* 0x19c1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
	return 6596ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6596ULL: goto x86_l_19c4;
	case 6599ULL: goto x86_l_19c7;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6609ULL: goto x86_l_19d1;
	case 6612ULL: goto x86_l_19d4;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6627ULL: goto x86_l_19e3;
	case 6633ULL: goto x86_l_19e9;
	case 6639ULL: goto x86_l_19ef;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6653ULL: goto x86_l_19fd;
	case 6657ULL: goto x86_l_1a01;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6677ULL: goto x86_l_1a15;
	case 6679ULL: goto x86_l_1a17;
	case 6681ULL: goto x86_l_1a19;
	case 6683ULL: goto x86_l_1a1b;
	case 6685ULL: goto x86_l_1a1d;
	case 6687ULL: goto x86_l_1a1f;
	case 6690ULL: goto x86_l_1a22;
	case 6692ULL: goto x86_l_1a24;
	case 6694ULL: goto x86_l_1a26;
	case 6696ULL: goto x86_l_1a28;
	case 6699ULL: goto x86_l_1a2b;
	case 6702ULL: goto x86_l_1a2e;
	case 6706ULL: goto x86_l_1a32;
	case 6712ULL: goto x86_l_1a38;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6723ULL: goto x86_l_1a43;
	case 6726ULL: goto x86_l_1a46;
	case 6728ULL: goto x86_l_1a48;
	case 6733ULL: goto x86_l_1a4d;
	case 6737ULL: goto x86_l_1a51;
	case 6740ULL: goto x86_l_1a54;
	case 6742ULL: goto x86_l_1a56;
	case 6745ULL: goto x86_l_1a59;
	case 6751ULL: goto x86_l_1a5f;
	case 6756ULL: goto x86_l_1a64;
	case 6759ULL: goto x86_l_1a67;
	case 6765ULL: goto x86_l_1a6d;
	case 6770ULL: goto x86_l_1a72;
	case 6775ULL: goto x86_l_1a77;
	case 6778ULL: goto x86_l_1a7a;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6789ULL: goto x86_l_1a85;
	case 6792ULL: goto x86_l_1a88;
	case 6796ULL: goto x86_l_1a8c;
	case 6802ULL: goto x86_l_1a92;
	case 6805ULL: goto x86_l_1a95;
	case 6811ULL: goto x86_l_1a9b;
	case 6816ULL: goto x86_l_1aa0;
	case 6820ULL: goto x86_l_1aa4;
	case 6823ULL: goto x86_l_1aa7;
	case 6827ULL: goto x86_l_1aab;
	case 6830ULL: goto x86_l_1aae;
	case 6833ULL: goto x86_l_1ab1;
	case 6836ULL: goto x86_l_1ab4;
	case 6841ULL: goto x86_l_1ab9;
	case 6844ULL: goto x86_l_1abc;
	case 6850ULL: goto x86_l_1ac2;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6865ULL: goto x86_l_1ad1;
	case 6868ULL: goto x86_l_1ad4;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6904ULL: goto x86_l_1af8;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6920ULL: goto x86_l_1b08;
	case 6925ULL: goto x86_l_1b0d;
	case 6927ULL: goto x86_l_1b0f;
	case 6930ULL: goto x86_l_1b12;
	case 6936ULL: goto x86_l_1b18;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6952ULL: goto x86_l_1b28;
	case 6957ULL: goto x86_l_1b2d;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6966ULL: goto x86_l_1b36;
	case 6969ULL: goto x86_l_1b39;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6983ULL: goto x86_l_1b47;
	case 6987ULL: goto x86_l_1b4b;
	case 6992ULL: goto x86_l_1b50;
	case 6997ULL: goto x86_l_1b55;
	case 6999ULL: goto x86_l_1b57;
	case 7002ULL: goto x86_l_1b5a;
	case 7005ULL: goto x86_l_1b5d;
	case 7007ULL: goto x86_l_1b5f;
	case 7012ULL: goto x86_l_1b64;
	case 7015ULL: goto x86_l_1b67;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7023ULL: goto x86_l_1b6f;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7042ULL: goto x86_l_1b82;
	case 7048ULL: goto x86_l_1b88;
	case 7058ULL: goto x86_l_1b92;
	case 7062ULL: goto x86_l_1b96;
	case 7066ULL: goto x86_l_1b9a;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7082ULL: goto x86_l_1baa;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7095ULL: goto x86_l_1bb7;
	case 7098ULL: goto x86_l_1bba;
	case 7101ULL: goto x86_l_1bbd;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7118ULL: goto x86_l_1bce;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7133ULL: goto x86_l_1bdd;
	case 7135ULL: goto x86_l_1bdf;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7147ULL: goto x86_l_1beb;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7159ULL: goto x86_l_1bf7;
	case 7161ULL: goto x86_l_1bf9;
	case 7166ULL: goto x86_l_1bfe;
	case 7169ULL: goto x86_l_1c01;
	case 7172ULL: goto x86_l_1c04;
	case 7178ULL: goto x86_l_1c0a;
	case 7184ULL: goto x86_l_1c10;
	case 7190ULL: goto x86_l_1c16;
	case 7193ULL: goto x86_l_1c19;
	case 7199ULL: goto x86_l_1c1f;
	case 7201ULL: goto x86_l_1c21;
	case 7207ULL: goto x86_l_1c27;
	case 7210ULL: goto x86_l_1c2a;
	case 7216ULL: goto x86_l_1c30;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7230ULL: goto x86_l_1c3e;
	case 7236ULL: goto x86_l_1c44;
	case 7238ULL: goto x86_l_1c46;
	case 7242ULL: goto x86_l_1c4a;
	case 7248ULL: goto x86_l_1c50;
	case 7253ULL: goto x86_l_1c55;
	case 7256ULL: goto x86_l_1c58;
	case 7262ULL: goto x86_l_1c5e;
	case 7267ULL: goto x86_l_1c63;
	case 7270ULL: goto x86_l_1c66;
	case 7272ULL: goto x86_l_1c68;
	case 7275ULL: goto x86_l_1c6b;
	case 7278ULL: goto x86_l_1c6e;
	case 7280ULL: goto x86_l_1c70;
	case 7284ULL: goto x86_l_1c74;
	case 7288ULL: goto x86_l_1c78;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7302ULL: goto x86_l_1c86;
	case 7308ULL: goto x86_l_1c8c;
	case 7311ULL: goto x86_l_1c8f;
	case 7317ULL: goto x86_l_1c95;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	case 7325ULL: goto x86_l_1c9d;
	case 7331ULL: goto x86_l_1ca3;
	case 7335ULL: goto x86_l_1ca7;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7349ULL: goto x86_l_1cb5;
	case 7353ULL: goto x86_l_1cb9;
	case 7359ULL: goto x86_l_1cbf;
	case 7363ULL: goto x86_l_1cc3;
	case 7369ULL: goto x86_l_1cc9;
	case 7374ULL: goto x86_l_1cce;
	case 7377ULL: goto x86_l_1cd1;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7390ULL: goto x86_l_1cde;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7404ULL: goto x86_l_1cec;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7417ULL: goto x86_l_1cf9;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7431ULL: goto x86_l_1d07;
	case 7437ULL: goto x86_l_1d0d;
	case 7440ULL: goto x86_l_1d10;
	case 7446ULL: goto x86_l_1d16;
	case 7451ULL: goto x86_l_1d1b;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7461ULL: goto x86_l_1d25;
	case 7464ULL: goto x86_l_1d28;
	case 7470ULL: goto x86_l_1d2e;
	case 7474ULL: goto x86_l_1d32;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7497ULL: goto x86_l_1d49;
	case 7502ULL: goto x86_l_1d4e;
	case 7507ULL: goto x86_l_1d53;
	case 7512ULL: goto x86_l_1d58;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7524ULL: goto x86_l_1d64;
	case 7527ULL: goto x86_l_1d67;
	case 7530ULL: goto x86_l_1d6a;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7554ULL: goto x86_l_1d82;
	case 7557ULL: goto x86_l_1d85;
	case 7560ULL: goto x86_l_1d88;
	case 7563ULL: goto x86_l_1d8b;
	case 7569ULL: goto x86_l_1d91;
	case 7574ULL: goto x86_l_1d96;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7587ULL: goto x86_l_1da3;
	case 7590ULL: goto x86_l_1da6;
	case 7593ULL: goto x86_l_1da9;
	case 7596ULL: goto x86_l_1dac;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7610ULL: goto x86_l_1dba;
	case 7615ULL: goto x86_l_1dbf;
	case 7618ULL: goto x86_l_1dc2;
	case 7620ULL: goto x86_l_1dc4;
	case 7622ULL: goto x86_l_1dc6;
	case 7627ULL: goto x86_l_1dcb;
	case 7630ULL: goto x86_l_1dce;
	case 7636ULL: goto x86_l_1dd4;
	case 7639ULL: goto x86_l_1dd7;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7660ULL: goto x86_l_1dec;
	case 7662ULL: goto x86_l_1dee;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7676ULL: goto x86_l_1dfc;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7690ULL: goto x86_l_1e0a;
	case 7696ULL: goto x86_l_1e10;
	case 7699ULL: goto x86_l_1e13;
	case 7702ULL: goto x86_l_1e16;
	case 7708ULL: goto x86_l_1e1c;
	case 7713ULL: goto x86_l_1e21;
	case 7715ULL: goto x86_l_1e23;
	case 7721ULL: goto x86_l_1e29;
	case 7726ULL: goto x86_l_1e2e;
	case 7731ULL: goto x86_l_1e33;
	case 7733ULL: goto x86_l_1e35;
	case 7739ULL: goto x86_l_1e3b;
	case 7744ULL: goto x86_l_1e40;
	case 7747ULL: goto x86_l_1e43;
	case 7753ULL: goto x86_l_1e49;
	case 7758ULL: goto x86_l_1e4e;
	case 7761ULL: goto x86_l_1e51;
	case 7767ULL: goto x86_l_1e57;
	case 7770ULL: goto x86_l_1e5a;
	case 7773ULL: goto x86_l_1e5d;
	case 7779ULL: goto x86_l_1e63;
	case 7784ULL: goto x86_l_1e68;
	case 7786ULL: goto x86_l_1e6a;
	case 7792ULL: goto x86_l_1e70;
	case 7797ULL: goto x86_l_1e75;
	case 7801ULL: goto x86_l_1e79;
	case 7803ULL: goto x86_l_1e7b;
	case 7805ULL: goto x86_l_1e7d;
	case 7807ULL: goto x86_l_1e7f;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7821ULL: goto x86_l_1e8d;
	case 7827ULL: goto x86_l_1e93;
	case 7832ULL: goto x86_l_1e98;
	case 7837ULL: goto x86_l_1e9d;
	case 7840ULL: goto x86_l_1ea0;
	case 7846ULL: goto x86_l_1ea6;
	case 7852ULL: goto x86_l_1eac;
	case 7856ULL: goto x86_l_1eb0;
	case 7862ULL: goto x86_l_1eb6;
	case 7864ULL: goto x86_l_1eb8;
	case 7868ULL: goto x86_l_1ebc;
	case 7874ULL: goto x86_l_1ec2;
	case 7876ULL: goto x86_l_1ec4;
	case 7882ULL: goto x86_l_1eca;
	case 7887ULL: goto x86_l_1ecf;
	case 7891ULL: goto x86_l_1ed3;
	case 7893ULL: goto x86_l_1ed5;
	case 7897ULL: goto x86_l_1ed9;
	case 7899ULL: goto x86_l_1edb;
	case 7902ULL: goto x86_l_1ede;
	case 7905ULL: goto x86_l_1ee1;
	case 7910ULL: goto x86_l_1ee6;
	case 7913ULL: goto x86_l_1ee9;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7929ULL: goto x86_l_1ef9;
	case 7932ULL: goto x86_l_1efc;
	case 7938ULL: goto x86_l_1f02;
	case 7944ULL: goto x86_l_1f08;
	case 7948ULL: goto x86_l_1f0c;
	case 7954ULL: goto x86_l_1f12;
	case 7957ULL: goto x86_l_1f15;
	case 7961ULL: goto x86_l_1f19;
	case 7963ULL: goto x86_l_1f1b;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7975ULL: goto x86_l_1f27;
	case 7981ULL: goto x86_l_1f2d;
	case 7984ULL: goto x86_l_1f30;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8014ULL: goto x86_l_1f4e;
	case 8019ULL: goto x86_l_1f53;
	case 8026ULL: goto x86_l_1f5a;
	case 8031ULL: goto x86_l_1f5f;
	case 8033ULL: goto x86_l_1f61;
	case 8036ULL: goto x86_l_1f64;
	case 8038ULL: goto x86_l_1f66;
	case 8040ULL: goto x86_l_1f68;
	case 8045ULL: goto x86_l_1f6d;
	case 8050ULL: goto x86_l_1f72;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8059ULL: goto x86_l_1f7b;
	case 8061ULL: goto x86_l_1f7d;
	case 8064ULL: goto x86_l_1f80;
	case 8067ULL: goto x86_l_1f83;
	case 8070ULL: goto x86_l_1f86;
	case 8072ULL: goto x86_l_1f88;
	case 8074ULL: goto x86_l_1f8a;
	case 8078ULL: goto x86_l_1f8e;
	case 8081ULL: goto x86_l_1f91;
	case 8083ULL: goto x86_l_1f93;
	case 8087ULL: goto x86_l_1f97;
	case 8090ULL: goto x86_l_1f9a;
	case 8092ULL: goto x86_l_1f9c;
	case 8096ULL: goto x86_l_1fa0;
	case 8098ULL: goto x86_l_1fa2;
	case 8102ULL: goto x86_l_1fa6;
	case 8106ULL: goto x86_l_1faa;
	case 8109ULL: goto x86_l_1fad;
	case 8111ULL: goto x86_l_1faf;
	case 8113ULL: goto x86_l_1fb1;
	case 8115ULL: goto x86_l_1fb3;
	case 8121ULL: goto x86_l_1fb9;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8132ULL: goto x86_l_1fc4;
	case 8136ULL: goto x86_l_1fc8;
	case 8139ULL: goto x86_l_1fcb;
	case 8143ULL: goto x86_l_1fcf;
	case 8149ULL: goto x86_l_1fd5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_19c4:
	/* 0x19c4: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_19c7:
	/* 0x19c7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_19c9:
	/* 0x19c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19ce:
	/* 0x19ce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19d1:
	/* 0x19d1: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_19d4:
	/* 0x19d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d6:
	/* 0x19d6: jmp    3409 <generic_retkprobe_filter_arg+0x3409> */
	return 13321ULL;
x86_l_19db:
	/* 0x19db: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_19e3:
	/* 0x19e3: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_19e9:
	/* 0x19e9: ja     28da <generic_retkprobe_filter_arg+0x28da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10458ULL;
	}
x86_l_19ef:
	/* 0x19ef: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_19f2:
	/* 0x19f2: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_19f7:
	/* 0x19f7: ja     2620 <generic_retkprobe_filter_arg+0x2620> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9760ULL;
	}
x86_l_19fd:
	/* 0x19fd: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a01:
	/* 0x1a01: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1a07:
	/* 0x1a07: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1a0a:
	/* 0x1a0a: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1a0d:
	/* 0x1a0d: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1a10:
	/* 0x1a10: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1a12:
	/* 0x1a12: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1a15:
	/* 0x1a15: je     1a1f <generic_retkprobe_filter_arg+0x1a1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a1f;
	}
x86_l_1a17:
	/* 0x1a17: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1a19:
	/* 0x1a19: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1a1b:
	/* 0x1a1b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1a1d:
	/* 0x1a1d: je     1a3a <generic_retkprobe_filter_arg+0x1a3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a3a;
	}
x86_l_1a1f:
	/* 0x1a1f: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a22:
	/* 0x1a22: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1a24:
	/* 0x1a24: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1a26:
	/* 0x1a26: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1a28:
	/* 0x1a28: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1a2b:
	/* 0x1a2b: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a2e:
	/* 0x1a2e: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1a32:
	/* 0x1a32: ja     2657 <generic_retkprobe_filter_arg+0x2657> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9815ULL;
	}
x86_l_1a38:
	/* 0x1a38: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1a3a:
	/* 0x1a3a: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a3d:
	/* 0x1a3d: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1a43:
	/* 0x1a43: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1a46:
	/* 0x1a46: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1a48:
	/* 0x1a48: jmp    2e88 <generic_retkprobe_filter_arg+0x2e88> */
	return 11912ULL;
x86_l_1a4d:
	/* 0x1a4d: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a51:
	/* 0x1a51: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1a54:
	/* 0x1a54: ja     1a5f <generic_retkprobe_filter_arg+0x1a5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a5f;
	}
x86_l_1a56:
	/* 0x1a56: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1a59:
	/* 0x1a59: jbe    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 624ULL;
	}
x86_l_1a5f:
	/* 0x1a5f: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a64:
	/* 0x1a64: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1a67:
	/* 0x1a67: jb     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 193ULL;
	}
x86_l_1a6d:
	/* 0x1a6d: mov    rdi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a72:
	/* 0x1a72: mov    rsi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a77:
	/* 0x1a77: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1a7a:
	/* 0x1a7a: je     1a85 <generic_retkprobe_filter_arg+0x1a85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a85;
	}
x86_l_1a7c:
	/* 0x1a7c: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1a7f:
	/* 0x1a7f: jne    20af <generic_retkprobe_filter_arg+0x20af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8367ULL;
	}
x86_l_1a85:
	/* 0x1a85: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a88:
	/* 0x1a88: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8c:
	/* 0x1a8c: jg     20c1 <generic_retkprobe_filter_arg+0x20c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8385ULL;
	}
x86_l_1a92:
	/* 0x1a92: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1a95:
	/* 0x1a95: jle    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 624ULL;
	}
x86_l_1a9b:
	/* 0x1a9b: jmp    20c1 <generic_retkprobe_filter_arg+0x20c1> */
	return 8385ULL;
x86_l_1aa0:
	/* 0x1aa0: mov    rdx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa4:
	/* 0x1aa4: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1aa7:
	/* 0x1aa7: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1aab:
	/* 0x1aab: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1aae:
	/* 0x1aae: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1ab1:
	/* 0x1ab1: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ab4:
	/* 0x1ab4: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab9:
	/* 0x1ab9: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1abc:
	/* 0x1abc: jb     2d18 <generic_retkprobe_filter_arg+0x2d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11544ULL;
	}
x86_l_1ac2:
	/* 0x1ac2: mov    r8,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    rdi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1acc:
	/* 0x1acc: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1acf:
	/* 0x1acf: je     1ada <generic_retkprobe_filter_arg+0x1ada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ada;
	}
x86_l_1ad1:
	/* 0x1ad1: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1ad4:
	/* 0x1ad4: jne    1ff5 <generic_retkprobe_filter_arg+0x1ff5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8181ULL;
	}
x86_l_1ada:
	/* 0x1ada: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1add:
	/* 0x1add: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1ae1:
	/* 0x1ae1: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1ae4:
	/* 0x1ae4: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1ae8:
	/* 0x1ae8: jmp    2003 <generic_retkprobe_filter_arg+0x2003> */
	return 8195ULL;
x86_l_1aed:
	/* 0x1aed: movzx  ebx,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1af2:
	/* 0x1af2: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1af8:
	/* 0x1af8: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1afc:
	/* 0x1afc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b01:
	/* 0x1b01: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1b08:
	/* 0x1b08: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b0d:
	/* 0x1b0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0f:
	/* 0x1b0f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b12:
	/* 0x1b12: je     208e <generic_retkprobe_filter_arg+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8334ULL;
	}
x86_l_1b18:
	/* 0x1b18: movzx  ecx,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1b1b:
	/* 0x1b1b: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b20:
	/* 0x1b20: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1b25:
	/* 0x1b25: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b28:
	/* 0x1b28: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b2d:
	/* 0x1b2d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b2f:
	/* 0x1b2f: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b34:
	/* 0x1b34: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b36:
	/* 0x1b36: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1b39:
	/* 0x1b39: ja     20fd <generic_retkprobe_filter_arg+0x20fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8445ULL;
	}
x86_l_1b3f:
	/* 0x1b3f: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1b44:
	/* 0x1b44: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b47:
	/* 0x1b47: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b4b:
	/* 0x1b4b: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b50:
	/* 0x1b50: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b55:
	/* 0x1b55: jae    1b5f <generic_retkprobe_filter_arg+0x1b5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b5f;
	}
x86_l_1b57:
	/* 0x1b57: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5a:
	/* 0x1b5a: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1b5d:
	/* 0x1b5d: jmp    1b6f <generic_retkprobe_filter_arg+0x1b6f> */
	goto x86_l_1b6f;
x86_l_1b5f:
	/* 0x1b5f: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1b64:
	/* 0x1b64: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b67:
	/* 0x1b67: jae    1b6f <generic_retkprobe_filter_arg+0x1b6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b6f;
	}
x86_l_1b69:
	/* 0x1b69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b6c:
	/* 0x1b6c: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1b6f:
	/* 0x1b6f: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b72:
	/* 0x1b72: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_1b77:
	/* 0x1b77: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b79:
	/* 0x1b79: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b7e:
	/* 0x1b7e: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1b82:
	/* 0x1b82: ja     2090 <generic_retkprobe_filter_arg+0x2090> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8336ULL;
	}
x86_l_1b88:
	/* 0x1b88: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_1b92:
	/* 0x1b92: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1b96:
	/* 0x1b96: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b9f:
	/* 0x1b9f: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ba4:
	/* 0x1ba4: jb     30e9 <generic_retkprobe_filter_arg+0x30e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12521ULL;
	}
x86_l_1baa:
	/* 0x1baa: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_1baf:
	/* 0x1baf: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bb4:
	/* 0x1bb4: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1bb7:
	/* 0x1bb7: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1bba:
	/* 0x1bba: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1bbd:
	/* 0x1bbd: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bcb:
	/* 0x1bcb: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1bce:
	/* 0x1bce: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_1bd3:
	/* 0x1bd3: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1bd8:
	/* 0x1bd8: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1bdd:
	/* 0x1bdd: jb     1c0a <generic_retkprobe_filter_arg+0x1c0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c0a;
	}
x86_l_1bdf:
	/* 0x1bdf: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_1be4:
	/* 0x1be4: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1be9:
	/* 0x1be9: jb     1c0a <generic_retkprobe_filter_arg+0x1c0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c0a;
	}
x86_l_1beb:
	/* 0x1beb: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_1bf0:
	/* 0x1bf0: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_1bf5:
	/* 0x1bf5: jb     1c0a <generic_retkprobe_filter_arg+0x1c0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c0a;
	}
x86_l_1bf7:
	/* 0x1bf7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bf9:
	/* 0x1bf9: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_1bfe:
	/* 0x1bfe: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1c01:
	/* 0x1c01: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_1c04:
	/* 0x1c04: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_1c0a:
	/* 0x1c0a: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1c10:
	/* 0x1c10: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1c16:
	/* 0x1c16: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c19:
	/* 0x1c19: jg     1f24 <generic_retkprobe_filter_arg+0x1f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f24;
	}
x86_l_1c1f:
	/* 0x1c1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c21:
	/* 0x1c21: je     280c <generic_retkprobe_filter_arg+0x280c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10252ULL;
	}
x86_l_1c27:
	/* 0x1c27: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c2a:
	/* 0x1c2a: jne    2805 <generic_retkprobe_filter_arg+0x2805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10245ULL;
	}
x86_l_1c30:
	/* 0x1c30: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1c35:
	/* 0x1c35: jmp    2818 <generic_retkprobe_filter_arg+0x2818> */
	return 10264ULL;
x86_l_1c3a:
	/* 0x1c3a: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3e:
	/* 0x1c3e: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_1c44:
	/* 0x1c44: jmp    1c50 <generic_retkprobe_filter_arg+0x1c50> */
	goto x86_l_1c50;
x86_l_1c46:
	/* 0x1c46: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c4a:
	/* 0x1c4a: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_1c50:
	/* 0x1c50: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c55:
	/* 0x1c55: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c58:
	/* 0x1c58: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_1c5e:
	/* 0x1c5e: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c63:
	/* 0x1c63: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c66:
	/* 0x1c66: jle    1c83 <generic_retkprobe_filter_arg+0x1c83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c83;
	}
x86_l_1c68:
	/* 0x1c68: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1c6b:
	/* 0x1c6b: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1c6e:
	/* 0x1c6e: jae    1cb2 <generic_retkprobe_filter_arg+0x1cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1cb2;
	}
x86_l_1c70:
	/* 0x1c70: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c74:
	/* 0x1c74: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c78:
	/* 0x1c78: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_1c7e:
	/* 0x1c7e: jmp    272a <generic_retkprobe_filter_arg+0x272a> */
	return 10026ULL;
x86_l_1c83:
	/* 0x1c83: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c86:
	/* 0x1c86: je     1d20 <generic_retkprobe_filter_arg+0x1d20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d20;
	}
x86_l_1c8c:
	/* 0x1c8c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c8f:
	/* 0x1c8f: jne    272a <generic_retkprobe_filter_arg+0x272a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10026ULL;
	}
x86_l_1c95:
	/* 0x1c95: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c98:
	/* 0x1c98: je     1ca3 <generic_retkprobe_filter_arg+0x1ca3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca3;
	}
x86_l_1c9a:
	/* 0x1c9a: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1c9d:
	/* 0x1c9d: jne    2720 <generic_retkprobe_filter_arg+0x2720> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10016ULL;
	}
x86_l_1ca3:
	/* 0x1ca3: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca7:
	/* 0x1ca7: jl     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 624ULL;
	}
x86_l_1cad:
	/* 0x1cad: jmp    272a <generic_retkprobe_filter_arg+0x272a> */
	return 10026ULL;
x86_l_1cb2:
	/* 0x1cb2: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1cb5:
	/* 0x1cb5: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb9:
	/* 0x1cb9: jne    272a <generic_retkprobe_filter_arg+0x272a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10026ULL;
	}
x86_l_1cbf:
	/* 0x1cbf: test   QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc3:
	/* 0x1cc3: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_1cc9:
	/* 0x1cc9: jmp    272a <generic_retkprobe_filter_arg+0x272a> */
	return 10026ULL;
x86_l_1cce:
	/* 0x1cce: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1cd1:
	/* 0x1cd1: jne    1df4 <generic_retkprobe_filter_arg+0x1df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1df4;
	}
x86_l_1cd7:
	/* 0x1cd7: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1cdc:
	/* 0x1cdc: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1cde:
	/* 0x1cde: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_1ce4:
	/* 0x1ce4: jmp    1df4 <generic_retkprobe_filter_arg+0x1df4> */
	goto x86_l_1df4;
x86_l_1ce9:
	/* 0x1ce9: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1cec:
	/* 0x1cec: jne    1e3b <generic_retkprobe_filter_arg+0x1e3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e3b;
	}
x86_l_1cf2:
	/* 0x1cf2: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cf7:
	/* 0x1cf7: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1cf9:
	/* 0x1cf9: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_1cff:
	/* 0x1cff: jmp    1e3b <generic_retkprobe_filter_arg+0x1e3b> */
	goto x86_l_1e3b;
x86_l_1d04:
	/* 0x1d04: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1d07:
	/* 0x1d07: je     2237 <generic_retkprobe_filter_arg+0x2237> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8759ULL;
	}
x86_l_1d0d:
	/* 0x1d0d: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1d10:
	/* 0x1d10: jne    2229 <generic_retkprobe_filter_arg+0x2229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8745ULL;
	}
x86_l_1d16:
	/* 0x1d16: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_1d1b:
	/* 0x1d1b: jmp    223c <generic_retkprobe_filter_arg+0x223c> */
	return 8764ULL;
x86_l_1d20:
	/* 0x1d20: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1d23:
	/* 0x1d23: je     1d2e <generic_retkprobe_filter_arg+0x1d2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d2e;
	}
x86_l_1d25:
	/* 0x1d25: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1d28:
	/* 0x1d28: jne    2714 <generic_retkprobe_filter_arg+0x2714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10004ULL;
	}
x86_l_1d2e:
	/* 0x1d2e: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d32:
	/* 0x1d32: jg     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 624ULL;
	}
x86_l_1d38:
	/* 0x1d38: jmp    272a <generic_retkprobe_filter_arg+0x272a> */
	return 10026ULL;
x86_l_1d3d:
	/* 0x1d3d: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d42:
	/* 0x1d42: movzx  ecx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d47:
	/* 0x1d47: jmp    1d53 <generic_retkprobe_filter_arg+0x1d53> */
	goto x86_l_1d53;
x86_l_1d49:
	/* 0x1d49: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d4e:
	/* 0x1d4e: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d53:
	/* 0x1d53: cmp    DWORD PTR [r12+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d58:
	/* 0x1d58: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1d5c:
	/* 0x1d5c: cmp    DWORD PTR [r12+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d61:
	/* 0x1d61: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1d64:
	/* 0x1d64: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1d67:
	/* 0x1d67: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d6a:
	/* 0x1d6a: jb     2d18 <generic_retkprobe_filter_arg+0x2d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11544ULL;
	}
x86_l_1d70:
	/* 0x1d70: cmp    DWORD PTR [r12+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d75:
	/* 0x1d75: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1d79:
	/* 0x1d79: cmp    DWORD PTR [r12+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1d7e:
	/* 0x1d7e: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1d82:
	/* 0x1d82: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1d85:
	/* 0x1d85: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d88:
	/* 0x1d88: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1d8b:
	/* 0x1d8b: jb     2d14 <generic_retkprobe_filter_arg+0x2d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11540ULL;
	}
x86_l_1d91:
	/* 0x1d91: cmp    DWORD PTR [r12+0x20],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d96:
	/* 0x1d96: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1d9a:
	/* 0x1d9a: cmp    DWORD PTR [r12+0x24],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d9f:
	/* 0x1d9f: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1da3:
	/* 0x1da3: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1da6:
	/* 0x1da6: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1da9:
	/* 0x1da9: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1dac:
	/* 0x1dac: jb     2d14 <generic_retkprobe_filter_arg+0x2d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11540ULL;
	}
x86_l_1db2:
	/* 0x1db2: cmp    DWORD PTR [r12+0x28],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1db7:
	/* 0x1db7: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1dba:
	/* 0x1dba: cmp    DWORD PTR [r12+0x2c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1dbf:
	/* 0x1dbf: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1dc2:
	/* 0x1dc2: and    cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1dc4:
	/* 0x1dc4: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1dc6:
	/* 0x1dc6: jmp    2d14 <generic_retkprobe_filter_arg+0x2d14> */
	return 11540ULL;
x86_l_1dcb:
	/* 0x1dcb: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1dce:
	/* 0x1dce: je     2433 <generic_retkprobe_filter_arg+0x2433> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9267ULL;
	}
x86_l_1dd4:
	/* 0x1dd4: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1dd7:
	/* 0x1dd7: jne    2425 <generic_retkprobe_filter_arg+0x2425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9253ULL;
	}
x86_l_1ddd:
	/* 0x1ddd: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_1de2:
	/* 0x1de2: jmp    2438 <generic_retkprobe_filter_arg+0x2438> */
	return 9272ULL;
x86_l_1de7:
	/* 0x1de7: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1dec:
	/* 0x1dec: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1dee:
	/* 0x1dee: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_1df4:
	/* 0x1df4: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df9:
	/* 0x1df9: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1dfc:
	/* 0x1dfc: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_1e02:
	/* 0x1e02: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e07:
	/* 0x1e07: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e0a:
	/* 0x1e0a: jle    21d3 <generic_retkprobe_filter_arg+0x21d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8659ULL;
	}
x86_l_1e10:
	/* 0x1e10: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1e13:
	/* 0x1e13: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e16:
	/* 0x1e16: jae    27a3 <generic_retkprobe_filter_arg+0x27a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10147ULL;
	}
x86_l_1e1c:
	/* 0x1e1c: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e21:
	/* 0x1e21: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1e23:
	/* 0x1e23: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_1e29:
	/* 0x1e29: jmp    2a17 <generic_retkprobe_filter_arg+0x2a17> */
	return 10775ULL;
x86_l_1e2e:
	/* 0x1e2e: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e33:
	/* 0x1e33: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1e35:
	/* 0x1e35: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_1e3b:
	/* 0x1e3b: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e40:
	/* 0x1e40: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1e43:
	/* 0x1e43: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_1e49:
	/* 0x1e49: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e4e:
	/* 0x1e4e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e51:
	/* 0x1e51: jle    21f7 <generic_retkprobe_filter_arg+0x21f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8695ULL;
	}
x86_l_1e57:
	/* 0x1e57: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1e5a:
	/* 0x1e5a: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e5d:
	/* 0x1e5d: jae    27be <generic_retkprobe_filter_arg+0x27be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10174ULL;
	}
x86_l_1e63:
	/* 0x1e63: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e68:
	/* 0x1e68: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1e6a:
	/* 0x1e6a: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_1e70:
	/* 0x1e70: jmp    2a59 <generic_retkprobe_filter_arg+0x2a59> */
	return 10841ULL;
x86_l_1e75:
	/* 0x1e75: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e79:
	/* 0x1e79: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1e7b:
	/* 0x1e7b: ja     1e85 <generic_retkprobe_filter_arg+0x1e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e85;
	}
x86_l_1e7d:
	/* 0x1e7d: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1e7f:
	/* 0x1e7f: jbe    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 624ULL;
	}
x86_l_1e85:
	/* 0x1e85: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e8a:
	/* 0x1e8a: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1e8d:
	/* 0x1e8d: jb     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 193ULL;
	}
x86_l_1e93:
	/* 0x1e93: mov    edi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e98:
	/* 0x1e98: mov    esi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1e9d:
	/* 0x1e9d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1ea0:
	/* 0x1ea0: ja     25cb <generic_retkprobe_filter_arg+0x25cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9675ULL;
	}
x86_l_1ea6:
	/* 0x1ea6: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_1eac:
	/* 0x1eac: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1eb0:
	/* 0x1eb0: jae    25cb <generic_retkprobe_filter_arg+0x25cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9675ULL;
	}
x86_l_1eb6:
	/* 0x1eb6: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_1eb8:
	/* 0x1eb8: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ebc:
	/* 0x1ebc: jg     25db <generic_retkprobe_filter_arg+0x25db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9691ULL;
	}
x86_l_1ec2:
	/* 0x1ec2: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_1ec4:
	/* 0x1ec4: jle    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 624ULL;
	}
x86_l_1eca:
	/* 0x1eca: jmp    25db <generic_retkprobe_filter_arg+0x25db> */
	return 9691ULL;
x86_l_1ecf:
	/* 0x1ecf: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ed3:
	/* 0x1ed3: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1ed5:
	/* 0x1ed5: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1ed9:
	/* 0x1ed9: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1edb:
	/* 0x1edb: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1ede:
	/* 0x1ede: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ee1:
	/* 0x1ee1: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ee6:
	/* 0x1ee6: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1ee9:
	/* 0x1ee9: jb     2d18 <generic_retkprobe_filter_arg+0x2d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11544ULL;
	}
x86_l_1eef:
	/* 0x1eef: mov    r8d,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ef4:
	/* 0x1ef4: mov    edi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ef9:
	/* 0x1ef9: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1efc:
	/* 0x1efc: ja     23cd <generic_retkprobe_filter_arg+0x23cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9165ULL;
	}
x86_l_1f02:
	/* 0x1f02: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_1f08:
	/* 0x1f08: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_1f0c:
	/* 0x1f0c: jae    23cd <generic_retkprobe_filter_arg+0x23cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9165ULL;
	}
x86_l_1f12:
	/* 0x1f12: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_1f15:
	/* 0x1f15: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1f19:
	/* 0x1f19: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1f1b:
	/* 0x1f1b: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1f1f:
	/* 0x1f1f: jmp    23da <generic_retkprobe_filter_arg+0x23da> */
	return 9178ULL;
x86_l_1f24:
	/* 0x1f24: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1f27:
	/* 0x1f27: je     2813 <generic_retkprobe_filter_arg+0x2813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10259ULL;
	}
x86_l_1f2d:
	/* 0x1f2d: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1f30:
	/* 0x1f30: jne    2805 <generic_retkprobe_filter_arg+0x2805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10245ULL;
	}
x86_l_1f36:
	/* 0x1f36: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_1f3b:
	/* 0x1f3b: jmp    2818 <generic_retkprobe_filter_arg+0x2818> */
	return 10264ULL;
x86_l_1f40:
	/* 0x1f40: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f42:
	/* 0x1f42: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f45:
	/* 0x1f45: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f4e:
	/* 0x1f4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f53:
	/* 0x1f53: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1f5a:
	/* 0x1f5a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f5f:
	/* 0x1f5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f61:
	/* 0x1f61: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f64:
	/* 0x1f64: je     1fe0 <generic_retkprobe_filter_arg+0x1fe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8160ULL;
	}
x86_l_1f66:
	/* 0x1f66: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1f68:
	/* 0x1f68: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f6d:
	/* 0x1f6d: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f72:
	/* 0x1f72: je     1fb9 <generic_retkprobe_filter_arg+0x1fb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb9;
	}
x86_l_1f74:
	/* 0x1f74: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f79:
	/* 0x1f79: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f7b:
	/* 0x1f7b: jmp    1f88 <generic_retkprobe_filter_arg+0x1f88> */
	goto x86_l_1f88;
x86_l_1f7d:
	/* 0x1f7d: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1f80:
	/* 0x1f80: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1f83:
	/* 0x1f83: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1f86:
	/* 0x1f86: je     1fb9 <generic_retkprobe_filter_arg+0x1fb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb9;
	}
x86_l_1f88:
	/* 0x1f88: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f8a:
	/* 0x1f8a: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1f8e:
	/* 0x1f8e: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1f91:
	/* 0x1f91: jae    1f7d <generic_retkprobe_filter_arg+0x1f7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f7d;
	}
x86_l_1f93:
	/* 0x1f93: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1f97:
	/* 0x1f97: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1f9a:
	/* 0x1f9a: je     1fb1 <generic_retkprobe_filter_arg+0x1fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb1;
	}
x86_l_1f9c:
	/* 0x1f9c: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1fa0:
	/* 0x1fa0: ja     1f7d <generic_retkprobe_filter_arg+0x1f7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f7d;
	}
x86_l_1fa2:
	/* 0x1fa2: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1fa6:
	/* 0x1fa6: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1faa:
	/* 0x1faa: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1fad:
	/* 0x1fad: je     1f8a <generic_retkprobe_filter_arg+0x1f8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f8a;
	}
x86_l_1faf:
	/* 0x1faf: jmp    1f7d <generic_retkprobe_filter_arg+0x1f7d> */
	goto x86_l_1f7d;
x86_l_1fb1:
	/* 0x1fb1: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1fb3:
	/* 0x1fb3: jns    221b <generic_retkprobe_filter_arg+0x221b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 8731ULL;
	}
x86_l_1fb9:
	/* 0x1fb9: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fbd:
	/* 0x1fbd: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1fc2:
	/* 0x1fc2: jae    1fd5 <generic_retkprobe_filter_arg+0x1fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fd5;
	}
x86_l_1fc4:
	/* 0x1fc4: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1fc8:
	/* 0x1fc8: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1fcb:
	/* 0x1fcb: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1fcf:
	/* 0x1fcf: jne    1f45 <generic_retkprobe_filter_arg+0x1f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f45;
	}
x86_l_1fd5:
	/* 0x1fd5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
	return 8151ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8151ULL: goto x86_l_1fd7;
	case 8155ULL: goto x86_l_1fdb;
	case 8160ULL: goto x86_l_1fe0;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8184ULL: goto x86_l_1ff8;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8195ULL: goto x86_l_2003;
	case 8198ULL: goto x86_l_2006;
	case 8201ULL: goto x86_l_2009;
	case 8204ULL: goto x86_l_200c;
	case 8210ULL: goto x86_l_2012;
	case 8215ULL: goto x86_l_2017;
	case 8220ULL: goto x86_l_201c;
	case 8223ULL: goto x86_l_201f;
	case 8225ULL: goto x86_l_2021;
	case 8228ULL: goto x86_l_2024;
	case 8234ULL: goto x86_l_202a;
	case 8237ULL: goto x86_l_202d;
	case 8241ULL: goto x86_l_2031;
	case 8244ULL: goto x86_l_2034;
	case 8248ULL: goto x86_l_2038;
	case 8253ULL: goto x86_l_203d;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8260ULL: goto x86_l_2044;
	case 8263ULL: goto x86_l_2047;
	case 8265ULL: goto x86_l_2049;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8274ULL: goto x86_l_2052;
	case 8277ULL: goto x86_l_2055;
	case 8283ULL: goto x86_l_205b;
	case 8289ULL: goto x86_l_2061;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8312ULL: goto x86_l_2078;
	case 8315ULL: goto x86_l_207b;
	case 8317ULL: goto x86_l_207d;
	case 8319ULL: goto x86_l_207f;
	case 8324ULL: goto x86_l_2084;
	case 8329ULL: goto x86_l_2089;
	case 8334ULL: goto x86_l_208e;
	case 8336ULL: goto x86_l_2090;
	case 8340ULL: goto x86_l_2094;
	case 8345ULL: goto x86_l_2099;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8367ULL: goto x86_l_20af;
	case 8370ULL: goto x86_l_20b2;
	case 8374ULL: goto x86_l_20b6;
	case 8376ULL: goto x86_l_20b8;
	case 8379ULL: goto x86_l_20bb;
	case 8385ULL: goto x86_l_20c1;
	case 8388ULL: goto x86_l_20c4;
	case 8394ULL: goto x86_l_20ca;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8407ULL: goto x86_l_20d7;
	case 8409ULL: goto x86_l_20d9;
	case 8412ULL: goto x86_l_20dc;
	case 8418ULL: goto x86_l_20e2;
	case 8421ULL: goto x86_l_20e5;
	case 8425ULL: goto x86_l_20e9;
	case 8431ULL: goto x86_l_20ef;
	case 8434ULL: goto x86_l_20f2;
	case 8440ULL: goto x86_l_20f8;
	case 8445ULL: goto x86_l_20fd;
	case 8449ULL: goto x86_l_2101;
	case 8454ULL: goto x86_l_2106;
	case 8459ULL: goto x86_l_210b;
	case 8464ULL: goto x86_l_2110;
	case 8468ULL: goto x86_l_2114;
	case 8474ULL: goto x86_l_211a;
	case 8476ULL: goto x86_l_211c;
	case 8480ULL: goto x86_l_2120;
	case 8486ULL: goto x86_l_2126;
	case 8491ULL: goto x86_l_212b;
	case 8494ULL: goto x86_l_212e;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8508ULL: goto x86_l_213c;
	case 8510ULL: goto x86_l_213e;
	case 8513ULL: goto x86_l_2141;
	case 8516ULL: goto x86_l_2144;
	case 8518ULL: goto x86_l_2146;
	case 8522ULL: goto x86_l_214a;
	case 8526ULL: goto x86_l_214e;
	case 8532ULL: goto x86_l_2154;
	case 8537ULL: goto x86_l_2159;
	case 8540ULL: goto x86_l_215c;
	case 8542ULL: goto x86_l_215e;
	case 8545ULL: goto x86_l_2161;
	case 8551ULL: goto x86_l_2167;
	case 8554ULL: goto x86_l_216a;
	case 8560ULL: goto x86_l_2170;
	case 8566ULL: goto x86_l_2176;
	case 8570ULL: goto x86_l_217a;
	case 8576ULL: goto x86_l_2180;
	case 8580ULL: goto x86_l_2184;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8594ULL: goto x86_l_2192;
	case 8598ULL: goto x86_l_2196;
	case 8604ULL: goto x86_l_219c;
	case 8608ULL: goto x86_l_21a0;
	case 8614ULL: goto x86_l_21a6;
	case 8619ULL: goto x86_l_21ab;
	case 8622ULL: goto x86_l_21ae;
	case 8628ULL: goto x86_l_21b4;
	case 8634ULL: goto x86_l_21ba;
	case 8638ULL: goto x86_l_21be;
	case 8644ULL: goto x86_l_21c4;
	case 8648ULL: goto x86_l_21c8;
	case 8654ULL: goto x86_l_21ce;
	case 8659ULL: goto x86_l_21d3;
	case 8662ULL: goto x86_l_21d6;
	case 8668ULL: goto x86_l_21dc;
	case 8671ULL: goto x86_l_21df;
	case 8677ULL: goto x86_l_21e5;
	case 8682ULL: goto x86_l_21ea;
	case 8684ULL: goto x86_l_21ec;
	case 8690ULL: goto x86_l_21f2;
	case 8695ULL: goto x86_l_21f7;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8707ULL: goto x86_l_2203;
	case 8713ULL: goto x86_l_2209;
	case 8718ULL: goto x86_l_220e;
	case 8720ULL: goto x86_l_2210;
	case 8726ULL: goto x86_l_2216;
	case 8731ULL: goto x86_l_221b;
	case 8736ULL: goto x86_l_2220;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8759ULL: goto x86_l_2237;
	case 8764ULL: goto x86_l_223c;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8777ULL: goto x86_l_2249;
	case 8783ULL: goto x86_l_224f;
	case 8787ULL: goto x86_l_2253;
	case 8791ULL: goto x86_l_2257;
	case 8796ULL: goto x86_l_225c;
	case 8801ULL: goto x86_l_2261;
	case 8808ULL: goto x86_l_2268;
	case 8813ULL: goto x86_l_226d;
	case 8816ULL: goto x86_l_2270;
	case 8818ULL: goto x86_l_2272;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8835ULL: goto x86_l_2283;
	case 8838ULL: goto x86_l_2286;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8848ULL: goto x86_l_2290;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8862ULL: goto x86_l_229e;
	case 8866ULL: goto x86_l_22a2;
	case 8871ULL: goto x86_l_22a7;
	case 8876ULL: goto x86_l_22ac;
	case 8882ULL: goto x86_l_22b2;
	case 8885ULL: goto x86_l_22b5;
	case 8888ULL: goto x86_l_22b8;
	case 8891ULL: goto x86_l_22bb;
	case 8895ULL: goto x86_l_22bf;
	case 8900ULL: goto x86_l_22c4;
	case 8902ULL: goto x86_l_22c6;
	case 8905ULL: goto x86_l_22c9;
	case 8908ULL: goto x86_l_22cc;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8919ULL: goto x86_l_22d7;
	case 8921ULL: goto x86_l_22d9;
	case 8926ULL: goto x86_l_22de;
	case 8928ULL: goto x86_l_22e0;
	case 8930ULL: goto x86_l_22e2;
	case 8938ULL: goto x86_l_22ea;
	case 8941ULL: goto x86_l_22ed;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8954ULL: goto x86_l_22fa;
	case 8957ULL: goto x86_l_22fd;
	case 8960ULL: goto x86_l_2300;
	case 8964ULL: goto x86_l_2304;
	case 8969ULL: goto x86_l_2309;
	case 8971ULL: goto x86_l_230b;
	case 8973ULL: goto x86_l_230d;
	case 8978ULL: goto x86_l_2312;
	case 8980ULL: goto x86_l_2314;
	case 8982ULL: goto x86_l_2316;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9009ULL: goto x86_l_2331;
	case 9013ULL: goto x86_l_2335;
	case 9017ULL: goto x86_l_2339;
	case 9021ULL: goto x86_l_233d;
	case 9024ULL: goto x86_l_2340;
	case 9028ULL: goto x86_l_2344;
	case 9033ULL: goto x86_l_2349;
	case 9038ULL: goto x86_l_234e;
	case 9040ULL: goto x86_l_2350;
	case 9043ULL: goto x86_l_2353;
	case 9049ULL: goto x86_l_2359;
	case 9052ULL: goto x86_l_235c;
	case 9058ULL: goto x86_l_2362;
	case 9061ULL: goto x86_l_2365;
	case 9067ULL: goto x86_l_236b;
	case 9070ULL: goto x86_l_236e;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9088ULL: goto x86_l_2380;
	case 9093ULL: goto x86_l_2385;
	case 9096ULL: goto x86_l_2388;
	case 9102ULL: goto x86_l_238e;
	case 9105ULL: goto x86_l_2391;
	case 9111ULL: goto x86_l_2397;
	case 9114ULL: goto x86_l_239a;
	case 9120ULL: goto x86_l_23a0;
	case 9123ULL: goto x86_l_23a3;
	case 9129ULL: goto x86_l_23a9;
	case 9134ULL: goto x86_l_23ae;
	case 9141ULL: goto x86_l_23b5;
	case 9146ULL: goto x86_l_23ba;
	case 9151ULL: goto x86_l_23bf;
	case 9155ULL: goto x86_l_23c3;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9168ULL: goto x86_l_23d0;
	case 9172ULL: goto x86_l_23d4;
	case 9174ULL: goto x86_l_23d6;
	case 9178ULL: goto x86_l_23da;
	case 9181ULL: goto x86_l_23dd;
	case 9184ULL: goto x86_l_23e0;
	case 9187ULL: goto x86_l_23e3;
	case 9193ULL: goto x86_l_23e9;
	case 9198ULL: goto x86_l_23ee;
	case 9203ULL: goto x86_l_23f3;
	case 9206ULL: goto x86_l_23f6;
	case 9212ULL: goto x86_l_23fc;
	case 9218ULL: goto x86_l_2402;
	case 9222ULL: goto x86_l_2406;
	case 9228ULL: goto x86_l_240c;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9237ULL: goto x86_l_2415;
	case 9241ULL: goto x86_l_2419;
	case 9246ULL: goto x86_l_241e;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9258ULL: goto x86_l_242a;
	case 9260ULL: goto x86_l_242c;
	case 9265ULL: goto x86_l_2431;
	case 9267ULL: goto x86_l_2433;
	case 9272ULL: goto x86_l_2438;
	case 9274ULL: goto x86_l_243a;
	case 9277ULL: goto x86_l_243d;
	case 9282ULL: goto x86_l_2442;
	case 9285ULL: goto x86_l_2445;
	case 9291ULL: goto x86_l_244b;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9304ULL: goto x86_l_2458;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9322ULL: goto x86_l_246a;
	case 9329ULL: goto x86_l_2471;
	case 9334ULL: goto x86_l_2476;
	case 9337ULL: goto x86_l_2479;
	case 9339ULL: goto x86_l_247b;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9354ULL: goto x86_l_248a;
	case 9357ULL: goto x86_l_248d;
	case 9359ULL: goto x86_l_248f;
	case 9362ULL: goto x86_l_2492;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9380ULL: goto x86_l_24a4;
	case 9385ULL: goto x86_l_24a9;
	case 9390ULL: goto x86_l_24ae;
	case 9396ULL: goto x86_l_24b4;
	case 9399ULL: goto x86_l_24b7;
	case 9402ULL: goto x86_l_24ba;
	case 9407ULL: goto x86_l_24bf;
	case 9409ULL: goto x86_l_24c1;
	case 9412ULL: goto x86_l_24c4;
	case 9420ULL: goto x86_l_24cc;
	case 9422ULL: goto x86_l_24ce;
	case 9425ULL: goto x86_l_24d1;
	case 9429ULL: goto x86_l_24d5;
	case 9434ULL: goto x86_l_24da;
	case 9439ULL: goto x86_l_24df;
	case 9441ULL: goto x86_l_24e1;
	case 9444ULL: goto x86_l_24e4;
	case 9447ULL: goto x86_l_24e7;
	case 9449ULL: goto x86_l_24e9;
	case 9454ULL: goto x86_l_24ee;
	case 9456ULL: goto x86_l_24f0;
	case 9458ULL: goto x86_l_24f2;
	case 9462ULL: goto x86_l_24f6;
	case 9465ULL: goto x86_l_24f9;
	case 9471ULL: goto x86_l_24ff;
	case 9476ULL: goto x86_l_2504;
	case 9478ULL: goto x86_l_2506;
	case 9483ULL: goto x86_l_250b;
	case 9486ULL: goto x86_l_250e;
	case 9490ULL: goto x86_l_2512;
	case 9495ULL: goto x86_l_2517;
	case 9497ULL: goto x86_l_2519;
	case 9500ULL: goto x86_l_251c;
	case 9503ULL: goto x86_l_251f;
	case 9505ULL: goto x86_l_2521;
	case 9510ULL: goto x86_l_2526;
	case 9512ULL: goto x86_l_2528;
	case 9514ULL: goto x86_l_252a;
	case 9518ULL: goto x86_l_252e;
	case 9522ULL: goto x86_l_2532;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
	case 9536ULL: goto x86_l_2540;
	case 9538ULL: goto x86_l_2542;
	case 9542ULL: goto x86_l_2546;
	case 9546ULL: goto x86_l_254a;
	case 9550ULL: goto x86_l_254e;
	case 9553ULL: goto x86_l_2551;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9567ULL: goto x86_l_255f;
	case 9569ULL: goto x86_l_2561;
	case 9572ULL: goto x86_l_2564;
	case 9578ULL: goto x86_l_256a;
	case 9581ULL: goto x86_l_256d;
	case 9587ULL: goto x86_l_2573;
	case 9590ULL: goto x86_l_2576;
	case 9596ULL: goto x86_l_257c;
	case 9599ULL: goto x86_l_257f;
	case 9605ULL: goto x86_l_2585;
	case 9610ULL: goto x86_l_258a;
	case 9617ULL: goto x86_l_2591;
	case 9622ULL: goto x86_l_2596;
	case 9625ULL: goto x86_l_2599;
	case 9631ULL: goto x86_l_259f;
	case 9634ULL: goto x86_l_25a2;
	case 9640ULL: goto x86_l_25a8;
	case 9643ULL: goto x86_l_25ab;
	case 9649ULL: goto x86_l_25b1;
	case 9652ULL: goto x86_l_25b4;
	case 9658ULL: goto x86_l_25ba;
	case 9663ULL: goto x86_l_25bf;
	case 9670ULL: goto x86_l_25c6;
	case 9675ULL: goto x86_l_25cb;
	case 9677ULL: goto x86_l_25cd;
	case 9681ULL: goto x86_l_25d1;
	case 9683ULL: goto x86_l_25d3;
	case 9685ULL: goto x86_l_25d5;
	case 9691ULL: goto x86_l_25db;
	case 9694ULL: goto x86_l_25de;
	case 9700ULL: goto x86_l_25e4;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9713ULL: goto x86_l_25f1;
	case 9719ULL: goto x86_l_25f7;
	case 9725ULL: goto x86_l_25fd;
	case 9729ULL: goto x86_l_2601;
	case 9735ULL: goto x86_l_2607;
	case 9737ULL: goto x86_l_2609;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1fd7:
	/* 0x1fd7: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fdb:
	/* 0x1fdb: jmp    3423 <generic_retkprobe_filter_arg+0x3423> */
	return 13347ULL;
x86_l_1fe0:
	/* 0x1fe0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fe2:
	/* 0x1fe2: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fec:
	/* 0x1fec: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff0:
	/* 0x1ff0: jmp    3423 <generic_retkprobe_filter_arg+0x3423> */
	return 13347ULL;
x86_l_1ff5:
	/* 0x1ff5: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1ff8:
	/* 0x1ff8: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1ffc:
	/* 0x1ffc: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1fff:
	/* 0x1fff: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2003:
	/* 0x2003: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2006:
	/* 0x2006: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2009:
	/* 0x2009: cmp    esi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 41ULL);
x86_l_200c:
	/* 0x200c: jb     2d14 <generic_retkprobe_filter_arg+0x2d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11540ULL;
	}
x86_l_2012:
	/* 0x2012: mov    r8,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2017:
	/* 0x2017: mov    rdi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_201c:
	/* 0x201c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_201f:
	/* 0x201f: je     202a <generic_retkprobe_filter_arg+0x202a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_202a;
	}
x86_l_2021:
	/* 0x2021: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2024:
	/* 0x2024: jne    2687 <generic_retkprobe_filter_arg+0x2687> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9863ULL;
	}
x86_l_202a:
	/* 0x202a: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_202d:
	/* 0x202d: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2031:
	/* 0x2031: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2034:
	/* 0x2034: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_2038:
	/* 0x2038: jmp    2695 <generic_retkprobe_filter_arg+0x2695> */
	return 9877ULL;
x86_l_203d:
	/* 0x203d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_203f:
	/* 0x203f: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2042:
	/* 0x2042: jne    204d <generic_retkprobe_filter_arg+0x204d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_204d;
	}
x86_l_2044:
	/* 0x2044: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2047:
	/* 0x2047: je     204d <generic_retkprobe_filter_arg+0x204d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_204d;
	}
x86_l_2049:
	/* 0x2049: movzx  ebx,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_204d:
	/* 0x204d: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2050:
	/* 0x2050: je     205b <generic_retkprobe_filter_arg+0x205b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_205b;
	}
x86_l_2052:
	/* 0x2052: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2055:
	/* 0x2055: jne    241e <generic_retkprobe_filter_arg+0x241e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_241e;
	}
x86_l_205b:
	/* 0x205b: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2061:
	/* 0x2061: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2065:
	/* 0x2065: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_206a:
	/* 0x206a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2071:
	/* 0x2071: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2076:
	/* 0x2076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2078:
	/* 0x2078: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_207b:
	/* 0x207b: je     208e <generic_retkprobe_filter_arg+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_208e;
	}
x86_l_207d:
	/* 0x207d: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_207f:
	/* 0x207f: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2084:
	/* 0x2084: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2089:
	/* 0x2089: jmp    1b25 <generic_retkprobe_filter_arg+0x1b25> */
	return 6949ULL;
x86_l_208e:
	/* 0x208e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2090:
	/* 0x2090: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2094:
	/* 0x2094: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2099:
	/* 0x2099: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_209e:
	/* 0x209e: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_20a3:
	/* 0x20a3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20a5:
	/* 0x20a5: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20aa:
	/* 0x20aa: jmp    23bf <generic_retkprobe_filter_arg+0x23bf> */
	goto x86_l_23bf;
x86_l_20af:
	/* 0x20af: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_20b2:
	/* 0x20b2: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b6:
	/* 0x20b6: ja     20c1 <generic_retkprobe_filter_arg+0x20c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20c1;
	}
x86_l_20b8:
	/* 0x20b8: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_20bb:
	/* 0x20bb: jbe    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 624ULL;
	}
x86_l_20c1:
	/* 0x20c1: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_20c4:
	/* 0x20c4: jb     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 193ULL;
	}
x86_l_20ca:
	/* 0x20ca: mov    rdi,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20cf:
	/* 0x20cf: mov    rsi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_20d4:
	/* 0x20d4: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_20d7:
	/* 0x20d7: je     20e2 <generic_retkprobe_filter_arg+0x20e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e2;
	}
x86_l_20d9:
	/* 0x20d9: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_20dc:
	/* 0x20dc: jne    26ca <generic_retkprobe_filter_arg+0x26ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9930ULL;
	}
x86_l_20e2:
	/* 0x20e2: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_20e5:
	/* 0x20e5: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e9:
	/* 0x20e9: jg     26dc <generic_retkprobe_filter_arg+0x26dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9948ULL;
	}
x86_l_20ef:
	/* 0x20ef: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_20f2:
	/* 0x20f2: jle    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 624ULL;
	}
x86_l_20f8:
	/* 0x20f8: jmp    26dc <generic_retkprobe_filter_arg+0x26dc> */
	return 9948ULL;
x86_l_20fd:
	/* 0x20fd: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2101:
	/* 0x2101: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2106:
	/* 0x2106: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_210b:
	/* 0x210b: jmp    1b6f <generic_retkprobe_filter_arg+0x1b6f> */
	return 7023ULL;
x86_l_2110:
	/* 0x2110: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2114:
	/* 0x2114: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_211a:
	/* 0x211a: jmp    2126 <generic_retkprobe_filter_arg+0x2126> */
	goto x86_l_2126;
x86_l_211c:
	/* 0x211c: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2120:
	/* 0x2120: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_2126:
	/* 0x2126: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_212b:
	/* 0x212b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_212e:
	/* 0x212e: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_2134:
	/* 0x2134: mov    esi,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2139:
	/* 0x2139: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_213c:
	/* 0x213c: jle    2159 <generic_retkprobe_filter_arg+0x2159> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2159;
	}
x86_l_213e:
	/* 0x213e: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2141:
	/* 0x2141: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2144:
	/* 0x2144: jae    218f <generic_retkprobe_filter_arg+0x218f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_218f;
	}
x86_l_2146:
	/* 0x2146: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_214a:
	/* 0x214a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_214e:
	/* 0x214e: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_2154:
	/* 0x2154: jmp    2b9b <generic_retkprobe_filter_arg+0x2b9b> */
	return 11163ULL;
x86_l_2159:
	/* 0x2159: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_215c:
	/* 0x215c: je     21ab <generic_retkprobe_filter_arg+0x21ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ab;
	}
x86_l_215e:
	/* 0x215e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2161:
	/* 0x2161: jne    2b9b <generic_retkprobe_filter_arg+0x2b9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11163ULL;
	}
x86_l_2167:
	/* 0x2167: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_216a:
	/* 0x216a: ja     2b91 <generic_retkprobe_filter_arg+0x2b91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11153ULL;
	}
x86_l_2170:
	/* 0x2170: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2176:
	/* 0x2176: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_217a:
	/* 0x217a: jae    2b91 <generic_retkprobe_filter_arg+0x2b91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11153ULL;
	}
x86_l_2180:
	/* 0x2180: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2184:
	/* 0x2184: jl     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 624ULL;
	}
x86_l_218a:
	/* 0x218a: jmp    2b9b <generic_retkprobe_filter_arg+0x2b9b> */
	return 11163ULL;
x86_l_218f:
	/* 0x218f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2192:
	/* 0x2192: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2196:
	/* 0x2196: jne    2b9b <generic_retkprobe_filter_arg+0x2b9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11163ULL;
	}
x86_l_219c:
	/* 0x219c: test   DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a0:
	/* 0x21a0: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_21a6:
	/* 0x21a6: jmp    2b9b <generic_retkprobe_filter_arg+0x2b9b> */
	return 11163ULL;
x86_l_21ab:
	/* 0x21ab: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_21ae:
	/* 0x21ae: ja     2b85 <generic_retkprobe_filter_arg+0x2b85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11141ULL;
	}
x86_l_21b4:
	/* 0x21b4: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_21ba:
	/* 0x21ba: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_21be:
	/* 0x21be: jae    2b85 <generic_retkprobe_filter_arg+0x2b85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11141ULL;
	}
x86_l_21c4:
	/* 0x21c4: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c8:
	/* 0x21c8: jg     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 624ULL;
	}
x86_l_21ce:
	/* 0x21ce: jmp    2b9b <generic_retkprobe_filter_arg+0x2b9b> */
	return 11163ULL;
x86_l_21d3:
	/* 0x21d3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21d6:
	/* 0x21d6: je     2a0a <generic_retkprobe_filter_arg+0x2a0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10762ULL;
	}
x86_l_21dc:
	/* 0x21dc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21df:
	/* 0x21df: jne    2a17 <generic_retkprobe_filter_arg+0x2a17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10775ULL;
	}
x86_l_21e5:
	/* 0x21e5: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21ea:
	/* 0x21ea: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_21ec:
	/* 0x21ec: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_21f2:
	/* 0x21f2: jmp    2a17 <generic_retkprobe_filter_arg+0x2a17> */
	return 10775ULL;
x86_l_21f7:
	/* 0x21f7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21fa:
	/* 0x21fa: je     2a4c <generic_retkprobe_filter_arg+0x2a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10828ULL;
	}
x86_l_2200:
	/* 0x2200: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2203:
	/* 0x2203: jne    2a59 <generic_retkprobe_filter_arg+0x2a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10841ULL;
	}
x86_l_2209:
	/* 0x2209: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_220e:
	/* 0x220e: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2210:
	/* 0x2210: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_2216:
	/* 0x2216: jmp    2a59 <generic_retkprobe_filter_arg+0x2a59> */
	return 10841ULL;
x86_l_221b:
	/* 0x221b: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2220:
	/* 0x2220: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2224:
	/* 0x2224: jmp    3423 <generic_retkprobe_filter_arg+0x3423> */
	return 13347ULL;
x86_l_2229:
	/* 0x2229: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_222e:
	/* 0x222e: jmp    223c <generic_retkprobe_filter_arg+0x223c> */
	goto x86_l_223c;
x86_l_2230:
	/* 0x2230: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2235:
	/* 0x2235: jmp    223c <generic_retkprobe_filter_arg+0x223c> */
	goto x86_l_223c;
x86_l_2237:
	/* 0x2237: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_223c:
	/* 0x223c: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_223e:
	/* 0x223e: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2241:
	/* 0x2241: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2246:
	/* 0x2246: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2249:
	/* 0x2249: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12470ULL;
	}
x86_l_224f:
	/* 0x224f: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2253:
	/* 0x2253: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2257:
	/* 0x2257: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_225c:
	/* 0x225c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2261:
	/* 0x2261: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2268:
	/* 0x2268: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_226d:
	/* 0x226d: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2270:
	/* 0x2270: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2272:
	/* 0x2272: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2277:
	/* 0x2277: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_227c:
	/* 0x227c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2283:
	/* 0x2283: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2286:
	/* 0x2286: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2288:
	/* 0x2288: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_228d:
	/* 0x228d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2290:
	/* 0x2290: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12470ULL;
	}
x86_l_2296:
	/* 0x2296: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_229b:
	/* 0x229b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_229e:
	/* 0x229e: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a2:
	/* 0x22a2: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a7:
	/* 0x22a7: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ac:
	/* 0x22ac: je     30c6 <generic_retkprobe_filter_arg+0x30c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12486ULL;
	}
x86_l_22b2:
	/* 0x22b2: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_22b5:
	/* 0x22b5: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_22b8:
	/* 0x22b8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_22bb:
	/* 0x22bb: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_22bf:
	/* 0x22bf: cmp    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_22c4:
	/* 0x22c4: jg     22fa <generic_retkprobe_filter_arg+0x22fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_22fa;
	}
x86_l_22c6:
	/* 0x22c6: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_22c9:
	/* 0x22c9: mov    BYTE PTR [rcx],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22cc:
	/* 0x22cc: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_22d0:
	/* 0x22d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22d5:
	/* 0x22d5: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_22d7:
	/* 0x22d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d9:
	/* 0x22d9: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22de:
	/* 0x22de: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_22e0:
	/* 0x22e0: jbe    2331 <generic_retkprobe_filter_arg+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2331;
	}
x86_l_22e2:
	/* 0x22e2: lea    rdi,[rbp*1+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 1ULL);
x86_l_22ea:
	/* 0x22ea: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22ed:
	/* 0x22ed: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22f3:
	/* 0x22f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22f8:
	/* 0x22f8: jmp    232c <generic_retkprobe_filter_arg+0x232c> */
	goto x86_l_232c;
x86_l_22fa:
	/* 0x22fa: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_22fd:
	/* 0x22fd: mov    WORD PTR [rcx],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2300:
	/* 0x2300: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2304:
	/* 0x2304: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2309:
	/* 0x2309: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_230b:
	/* 0x230b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_230d:
	/* 0x230d: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2312:
	/* 0x2312: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2314:
	/* 0x2314: jbe    2331 <generic_retkprobe_filter_arg+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2331;
	}
x86_l_2316:
	/* 0x2316: lea    rdi,[rbp*1+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 2ULL);
x86_l_231e:
	/* 0x231e: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2321:
	/* 0x2321: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2327:
	/* 0x2327: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_232c:
	/* 0x232c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_232f:
	/* 0x232f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2331:
	/* 0x2331: mov    eax,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2335:
	/* 0x2335: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2339:
	/* 0x2339: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_233d:
	/* 0x233d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2340:
	/* 0x2340: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2344:
	/* 0x2344: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2349:
	/* 0x2349: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_234e:
	/* 0x234e: jle    2385 <generic_retkprobe_filter_arg+0x2385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2385;
	}
x86_l_2350:
	/* 0x2350: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2353:
	/* 0x2353: jg     27d9 <generic_retkprobe_filter_arg+0x27d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10201ULL;
	}
x86_l_2359:
	/* 0x2359: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_235c:
	/* 0x235c: je     2e31 <generic_retkprobe_filter_arg+0x2e31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11825ULL;
	}
x86_l_2362:
	/* 0x2362: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2365:
	/* 0x2365: je     2e07 <generic_retkprobe_filter_arg+0x2e07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11783ULL;
	}
x86_l_236b:
	/* 0x236b: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_236e:
	/* 0x236e: jne    8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2303ULL;
	}
x86_l_2374:
	/* 0x2374: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2379:
	/* 0x2379: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2380:
	/* 0x2380: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	return 11851ULL;
x86_l_2385:
	/* 0x2385: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2388:
	/* 0x2388: jle    2a8e <generic_retkprobe_filter_arg+0x2a8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 10894ULL;
	}
x86_l_238e:
	/* 0x238e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2391:
	/* 0x2391: je     2e23 <generic_retkprobe_filter_arg+0x2e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11811ULL;
	}
x86_l_2397:
	/* 0x2397: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_239a:
	/* 0x239a: je     2df9 <generic_retkprobe_filter_arg+0x2df9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11769ULL;
	}
x86_l_23a0:
	/* 0x23a0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23a3:
	/* 0x23a3: jne    8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2303ULL;
	}
x86_l_23a9:
	/* 0x23a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23ae:
	/* 0x23ae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_23b5:
	/* 0x23b5: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	return 11851ULL;
x86_l_23ba:
	/* 0x23ba: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_23bf:
	/* 0x23bf: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c3:
	/* 0x23c3: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23c8:
	/* 0x23c8: jmp    3423 <generic_retkprobe_filter_arg+0x3423> */
	return 13347ULL;
x86_l_23cd:
	/* 0x23cd: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_23d0:
	/* 0x23d0: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_23d4:
	/* 0x23d4: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_23d6:
	/* 0x23d6: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_23da:
	/* 0x23da: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_23dd:
	/* 0x23dd: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_23e0:
	/* 0x23e0: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_23e3:
	/* 0x23e3: jb     2d14 <generic_retkprobe_filter_arg+0x2d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11540ULL;
	}
x86_l_23e9:
	/* 0x23e9: mov    r8d,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23ee:
	/* 0x23ee: mov    edi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23f3:
	/* 0x23f3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_23f6:
	/* 0x23f6: ja     2adc <generic_retkprobe_filter_arg+0x2adc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10972ULL;
	}
x86_l_23fc:
	/* 0x23fc: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_2402:
	/* 0x2402: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_2406:
	/* 0x2406: jae    2adc <generic_retkprobe_filter_arg+0x2adc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10972ULL;
	}
x86_l_240c:
	/* 0x240c: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_240f:
	/* 0x240f: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2413:
	/* 0x2413: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2415:
	/* 0x2415: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_2419:
	/* 0x2419: jmp    2ae9 <generic_retkprobe_filter_arg+0x2ae9> */
	return 10985ULL;
x86_l_241e:
	/* 0x241e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2420:
	/* 0x2420: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_2425:
	/* 0x2425: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_242a:
	/* 0x242a: jmp    2438 <generic_retkprobe_filter_arg+0x2438> */
	goto x86_l_2438;
x86_l_242c:
	/* 0x242c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2431:
	/* 0x2431: jmp    2438 <generic_retkprobe_filter_arg+0x2438> */
	goto x86_l_2438;
x86_l_2433:
	/* 0x2433: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2438:
	/* 0x2438: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_243a:
	/* 0x243a: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_243d:
	/* 0x243d: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2442:
	/* 0x2442: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2445:
	/* 0x2445: je     2c6f <generic_retkprobe_filter_arg+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11375ULL;
	}
x86_l_244b:
	/* 0x244b: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_244f:
	/* 0x244f: mov    QWORD PTR [rsp+0x38],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2454:
	/* 0x2454: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2458:
	/* 0x2458: mov    BYTE PTR [rsp+0x80],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2460:
	/* 0x2460: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2465:
	/* 0x2465: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_246a:
	/* 0x246a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2471:
	/* 0x2471: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2476:
	/* 0x2476: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2479:
	/* 0x2479: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247b:
	/* 0x247b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_247e:
	/* 0x247e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2483:
	/* 0x2483: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_248a:
	/* 0x248a: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_248d:
	/* 0x248d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248f:
	/* 0x248f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2492:
	/* 0x2492: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12470ULL;
	}
x86_l_2498:
	/* 0x2498: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_249d:
	/* 0x249d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24a0:
	/* 0x24a0: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a4:
	/* 0x24a4: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a9:
	/* 0x24a9: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ae:
	/* 0x24ae: je     30c6 <generic_retkprobe_filter_arg+0x30c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12486ULL;
	}
x86_l_24b4:
	/* 0x24b4: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_24b7:
	/* 0x24b7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_24ba:
	/* 0x24ba: cmp    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_24bf:
	/* 0x24bf: jg     2506 <generic_retkprobe_filter_arg+0x2506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2506;
	}
x86_l_24c1:
	/* 0x24c1: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_24c4:
	/* 0x24c4: movzx  ecx,BYTE PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_24cc:
	/* 0x24cc: mov    BYTE PTR [rax],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ce:
	/* 0x24ce: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_24d1:
	/* 0x24d1: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_24d5:
	/* 0x24d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24da:
	/* 0x24da: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24df:
	/* 0x24df: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_24e1:
	/* 0x24e1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_24e4:
	/* 0x24e4: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_24e7:
	/* 0x24e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e9:
	/* 0x24e9: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_24ee:
	/* 0x24ee: sub    esi,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24f0:
	/* 0x24f0: jbe    2542 <generic_retkprobe_filter_arg+0x2542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2542;
	}
x86_l_24f2:
	/* 0x24f2: lea    rdi,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_24f6:
	/* 0x24f6: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_24f9:
	/* 0x24f9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24ff:
	/* 0x24ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2504:
	/* 0x2504: jmp    253d <generic_retkprobe_filter_arg+0x253d> */
	goto x86_l_253d;
x86_l_2506:
	/* 0x2506: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_250b:
	/* 0x250b: mov    WORD PTR [rcx],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_250e:
	/* 0x250e: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2512:
	/* 0x2512: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2517:
	/* 0x2517: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2519:
	/* 0x2519: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_251c:
	/* 0x251c: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_251f:
	/* 0x251f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2521:
	/* 0x2521: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2526:
	/* 0x2526: sub    esi,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2528:
	/* 0x2528: jbe    2542 <generic_retkprobe_filter_arg+0x2542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2542;
	}
x86_l_252a:
	/* 0x252a: lea    rdi,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_252e:
	/* 0x252e: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2532:
	/* 0x2532: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2538:
	/* 0x2538: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_253d:
	/* 0x253d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2540:
	/* 0x2540: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2542:
	/* 0x2542: mov    eax,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2546:
	/* 0x2546: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_254a:
	/* 0x254a: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_254e:
	/* 0x254e: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2551:
	/* 0x2551: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2555:
	/* 0x2555: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255a:
	/* 0x255a: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_255f:
	/* 0x255f: jle    2596 <generic_retkprobe_filter_arg+0x2596> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2596;
	}
x86_l_2561:
	/* 0x2561: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2564:
	/* 0x2564: jg     29c2 <generic_retkprobe_filter_arg+0x29c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10690ULL;
	}
x86_l_256a:
	/* 0x256a: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_256d:
	/* 0x256d: je     3079 <generic_retkprobe_filter_arg+0x3079> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12409ULL;
	}
x86_l_2573:
	/* 0x2573: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2576:
	/* 0x2576: je     304f <generic_retkprobe_filter_arg+0x304f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12367ULL;
	}
x86_l_257c:
	/* 0x257c: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_257f:
	/* 0x257f: jne    2c6f <generic_retkprobe_filter_arg+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11375ULL;
	}
x86_l_2585:
	/* 0x2585: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_258a:
	/* 0x258a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2591:
	/* 0x2591: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	return 12435ULL;
x86_l_2596:
	/* 0x2596: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2599:
	/* 0x2599: jle    2c51 <generic_retkprobe_filter_arg+0x2c51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11345ULL;
	}
x86_l_259f:
	/* 0x259f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25a2:
	/* 0x25a2: je     306b <generic_retkprobe_filter_arg+0x306b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12395ULL;
	}
x86_l_25a8:
	/* 0x25a8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_25ab:
	/* 0x25ab: je     3041 <generic_retkprobe_filter_arg+0x3041> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12353ULL;
	}
x86_l_25b1:
	/* 0x25b1: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25b4:
	/* 0x25b4: jne    2c6f <generic_retkprobe_filter_arg+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11375ULL;
	}
x86_l_25ba:
	/* 0x25ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25bf:
	/* 0x25bf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_25c6:
	/* 0x25c6: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	return 12435ULL;
x86_l_25cb:
	/* 0x25cb: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_25cd:
	/* 0x25cd: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25d1:
	/* 0x25d1: ja     25db <generic_retkprobe_filter_arg+0x25db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25db;
	}
x86_l_25d3:
	/* 0x25d3: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_25d5:
	/* 0x25d5: jbe    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 624ULL;
	}
x86_l_25db:
	/* 0x25db: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_25de:
	/* 0x25de: jb     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 193ULL;
	}
x86_l_25e4:
	/* 0x25e4: mov    edi,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25e9:
	/* 0x25e9: mov    esi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_25ee:
	/* 0x25ee: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_25f1:
	/* 0x25f1: ja     2b34 <generic_retkprobe_filter_arg+0x2b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11060ULL;
	}
x86_l_25f7:
	/* 0x25f7: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_25fd:
	/* 0x25fd: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2601:
	/* 0x2601: jae    2b34 <generic_retkprobe_filter_arg+0x2b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11060ULL;
	}
x86_l_2607:
	/* 0x2607: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2609:
	/* 0x2609: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 9741ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9741ULL: goto x86_l_260d;
	case 9747ULL: goto x86_l_2613;
	case 9749ULL: goto x86_l_2615;
	case 9755ULL: goto x86_l_261b;
	case 9760ULL: goto x86_l_2620;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9772ULL: goto x86_l_262c;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9794ULL: goto x86_l_2642;
	case 9796ULL: goto x86_l_2644;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9806ULL: goto x86_l_264e;
	case 9809ULL: goto x86_l_2651;
	case 9815ULL: goto x86_l_2657;
	case 9821ULL: goto x86_l_265d;
	case 9827ULL: goto x86_l_2663;
	case 9830ULL: goto x86_l_2666;
	case 9836ULL: goto x86_l_266c;
	case 9838ULL: goto x86_l_266e;
	case 9844ULL: goto x86_l_2674;
	case 9847ULL: goto x86_l_2677;
	case 9853ULL: goto x86_l_267d;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9866ULL: goto x86_l_268a;
	case 9870ULL: goto x86_l_268e;
	case 9873ULL: goto x86_l_2691;
	case 9877ULL: goto x86_l_2695;
	case 9880ULL: goto x86_l_2698;
	case 9883ULL: goto x86_l_269b;
	case 9886ULL: goto x86_l_269e;
	case 9892ULL: goto x86_l_26a4;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9905ULL: goto x86_l_26b1;
	case 9907ULL: goto x86_l_26b3;
	case 9910ULL: goto x86_l_26b6;
	case 9916ULL: goto x86_l_26bc;
	case 9919ULL: goto x86_l_26bf;
	case 9922ULL: goto x86_l_26c2;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9933ULL: goto x86_l_26cd;
	case 9937ULL: goto x86_l_26d1;
	case 9939ULL: goto x86_l_26d3;
	case 9942ULL: goto x86_l_26d6;
	case 9948ULL: goto x86_l_26dc;
	case 9951ULL: goto x86_l_26df;
	case 9957ULL: goto x86_l_26e5;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9970ULL: goto x86_l_26f2;
	case 9972ULL: goto x86_l_26f4;
	case 9975ULL: goto x86_l_26f7;
	case 9981ULL: goto x86_l_26fd;
	case 9984ULL: goto x86_l_2700;
	case 9990ULL: goto x86_l_2706;
	case 9993ULL: goto x86_l_2709;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10008ULL: goto x86_l_2718;
	case 10014ULL: goto x86_l_271e;
	case 10016ULL: goto x86_l_2720;
	case 10020ULL: goto x86_l_2724;
	case 10026ULL: goto x86_l_272a;
	case 10029ULL: goto x86_l_272d;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10043ULL: goto x86_l_273b;
	case 10045ULL: goto x86_l_273d;
	case 10048ULL: goto x86_l_2740;
	case 10051ULL: goto x86_l_2743;
	case 10053ULL: goto x86_l_2745;
	case 10057ULL: goto x86_l_2749;
	case 10061ULL: goto x86_l_274d;
	case 10067ULL: goto x86_l_2753;
	case 10072ULL: goto x86_l_2758;
	case 10075ULL: goto x86_l_275b;
	case 10081ULL: goto x86_l_2761;
	case 10084ULL: goto x86_l_2764;
	case 10090ULL: goto x86_l_276a;
	case 10093ULL: goto x86_l_276d;
	case 10095ULL: goto x86_l_276f;
	case 10098ULL: goto x86_l_2772;
	case 10104ULL: goto x86_l_2778;
	case 10108ULL: goto x86_l_277c;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10122ULL: goto x86_l_278a;
	case 10126ULL: goto x86_l_278e;
	case 10132ULL: goto x86_l_2794;
	case 10136ULL: goto x86_l_2798;
	case 10142ULL: goto x86_l_279e;
	case 10147ULL: goto x86_l_27a3;
	case 10150ULL: goto x86_l_27a6;
	case 10156ULL: goto x86_l_27ac;
	case 10161ULL: goto x86_l_27b1;
	case 10163ULL: goto x86_l_27b3;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10177ULL: goto x86_l_27c1;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10190ULL: goto x86_l_27ce;
	case 10196ULL: goto x86_l_27d4;
	case 10201ULL: goto x86_l_27d9;
	case 10204ULL: goto x86_l_27dc;
	case 10210ULL: goto x86_l_27e2;
	case 10213ULL: goto x86_l_27e5;
	case 10219ULL: goto x86_l_27eb;
	case 10222ULL: goto x86_l_27ee;
	case 10228ULL: goto x86_l_27f4;
	case 10233ULL: goto x86_l_27f9;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10250ULL: goto x86_l_280a;
	case 10252ULL: goto x86_l_280c;
	case 10257ULL: goto x86_l_2811;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10266ULL: goto x86_l_281a;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10277ULL: goto x86_l_2825;
	case 10283ULL: goto x86_l_282b;
	case 10287ULL: goto x86_l_282f;
	case 10291ULL: goto x86_l_2833;
	case 10299ULL: goto x86_l_283b;
	case 10304ULL: goto x86_l_2840;
	case 10311ULL: goto x86_l_2847;
	case 10316ULL: goto x86_l_284c;
	case 10319ULL: goto x86_l_284f;
	case 10321ULL: goto x86_l_2851;
	case 10324ULL: goto x86_l_2854;
	case 10329ULL: goto x86_l_2859;
	case 10336ULL: goto x86_l_2860;
	case 10339ULL: goto x86_l_2863;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10349ULL: goto x86_l_286d;
	case 10355ULL: goto x86_l_2873;
	case 10360ULL: goto x86_l_2878;
	case 10363ULL: goto x86_l_287b;
	case 10367ULL: goto x86_l_287f;
	case 10372ULL: goto x86_l_2884;
	case 10377ULL: goto x86_l_2889;
	case 10383ULL: goto x86_l_288f;
	case 10386ULL: goto x86_l_2892;
	case 10390ULL: goto x86_l_2896;
	case 10393ULL: goto x86_l_2899;
	case 10395ULL: goto x86_l_289b;
	case 10400ULL: goto x86_l_28a0;
	case 10403ULL: goto x86_l_28a3;
	case 10407ULL: goto x86_l_28a7;
	case 10412ULL: goto x86_l_28ac;
	case 10414ULL: goto x86_l_28ae;
	case 10419ULL: goto x86_l_28b3;
	case 10421ULL: goto x86_l_28b5;
	case 10429ULL: goto x86_l_28bd;
	case 10431ULL: goto x86_l_28bf;
	case 10433ULL: goto x86_l_28c1;
	case 10438ULL: goto x86_l_28c6;
	case 10442ULL: goto x86_l_28ca;
	case 10445ULL: goto x86_l_28cd;
	case 10451ULL: goto x86_l_28d3;
	case 10456ULL: goto x86_l_28d8;
	case 10458ULL: goto x86_l_28da;
	case 10460ULL: goto x86_l_28dc;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10473ULL: goto x86_l_28e9;
	case 10477ULL: goto x86_l_28ed;
	case 10482ULL: goto x86_l_28f2;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	case 10491ULL: goto x86_l_28fb;
	case 10499ULL: goto x86_l_2903;
	case 10501ULL: goto x86_l_2905;
	case 10503ULL: goto x86_l_2907;
	case 10508ULL: goto x86_l_290c;
	case 10512ULL: goto x86_l_2910;
	case 10516ULL: goto x86_l_2914;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10530ULL: goto x86_l_2922;
	case 10532ULL: goto x86_l_2924;
	case 10536ULL: goto x86_l_2928;
	case 10540ULL: goto x86_l_292c;
	case 10543ULL: goto x86_l_292f;
	case 10548ULL: goto x86_l_2934;
	case 10553ULL: goto x86_l_2939;
	case 10555ULL: goto x86_l_293b;
	case 10558ULL: goto x86_l_293e;
	case 10564ULL: goto x86_l_2944;
	case 10567ULL: goto x86_l_2947;
	case 10573ULL: goto x86_l_294d;
	case 10576ULL: goto x86_l_2950;
	case 10582ULL: goto x86_l_2956;
	case 10585ULL: goto x86_l_2959;
	case 10591ULL: goto x86_l_295f;
	case 10596ULL: goto x86_l_2964;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10611ULL: goto x86_l_2973;
	case 10617ULL: goto x86_l_2979;
	case 10620ULL: goto x86_l_297c;
	case 10626ULL: goto x86_l_2982;
	case 10629ULL: goto x86_l_2985;
	case 10635ULL: goto x86_l_298b;
	case 10638ULL: goto x86_l_298e;
	case 10644ULL: goto x86_l_2994;
	case 10649ULL: goto x86_l_2999;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10664ULL: goto x86_l_29a8;
	case 10666ULL: goto x86_l_29aa;
	case 10669ULL: goto x86_l_29ad;
	case 10675ULL: goto x86_l_29b3;
	case 10679ULL: goto x86_l_29b7;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10693ULL: goto x86_l_29c5;
	case 10699ULL: goto x86_l_29cb;
	case 10702ULL: goto x86_l_29ce;
	case 10708ULL: goto x86_l_29d4;
	case 10711ULL: goto x86_l_29d7;
	case 10717ULL: goto x86_l_29dd;
	case 10722ULL: goto x86_l_29e2;
	case 10729ULL: goto x86_l_29e9;
	case 10734ULL: goto x86_l_29ee;
	case 10737ULL: goto x86_l_29f1;
	case 10743ULL: goto x86_l_29f7;
	case 10746ULL: goto x86_l_29fa;
	case 10752ULL: goto x86_l_2a00;
	case 10757ULL: goto x86_l_2a05;
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10769ULL: goto x86_l_2a11;
	case 10775ULL: goto x86_l_2a17;
	case 10778ULL: goto x86_l_2a1a;
	case 10784ULL: goto x86_l_2a20;
	case 10789ULL: goto x86_l_2a25;
	case 10792ULL: goto x86_l_2a28;
	case 10798ULL: goto x86_l_2a2e;
	case 10801ULL: goto x86_l_2a31;
	case 10804ULL: goto x86_l_2a34;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10817ULL: goto x86_l_2a41;
	case 10823ULL: goto x86_l_2a47;
	case 10828ULL: goto x86_l_2a4c;
	case 10833ULL: goto x86_l_2a51;
	case 10835ULL: goto x86_l_2a53;
	case 10841ULL: goto x86_l_2a59;
	case 10844ULL: goto x86_l_2a5c;
	case 10850ULL: goto x86_l_2a62;
	case 10855ULL: goto x86_l_2a67;
	case 10858ULL: goto x86_l_2a6a;
	case 10864ULL: goto x86_l_2a70;
	case 10867ULL: goto x86_l_2a73;
	case 10870ULL: goto x86_l_2a76;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10883ULL: goto x86_l_2a83;
	case 10889ULL: goto x86_l_2a89;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10902ULL: goto x86_l_2a96;
	case 10905ULL: goto x86_l_2a99;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10923ULL: goto x86_l_2aab;
	case 10928ULL: goto x86_l_2ab0;
	case 10931ULL: goto x86_l_2ab3;
	case 10937ULL: goto x86_l_2ab9;
	case 10940ULL: goto x86_l_2abc;
	case 10946ULL: goto x86_l_2ac2;
	case 10949ULL: goto x86_l_2ac5;
	case 10955ULL: goto x86_l_2acb;
	case 10960ULL: goto x86_l_2ad0;
	case 10967ULL: goto x86_l_2ad7;
	case 10972ULL: goto x86_l_2adc;
	case 10975ULL: goto x86_l_2adf;
	case 10979ULL: goto x86_l_2ae3;
	case 10981ULL: goto x86_l_2ae5;
	case 10985ULL: goto x86_l_2ae9;
	case 10988ULL: goto x86_l_2aec;
	case 10991ULL: goto x86_l_2aef;
	case 10994ULL: goto x86_l_2af2;
	case 11000ULL: goto x86_l_2af8;
	case 11005ULL: goto x86_l_2afd;
	case 11010ULL: goto x86_l_2b02;
	case 11013ULL: goto x86_l_2b05;
	case 11019ULL: goto x86_l_2b0b;
	case 11025ULL: goto x86_l_2b11;
	case 11029ULL: goto x86_l_2b15;
	case 11035ULL: goto x86_l_2b1b;
	case 11037ULL: goto x86_l_2b1d;
	case 11040ULL: goto x86_l_2b20;
	case 11042ULL: goto x86_l_2b22;
	case 11045ULL: goto x86_l_2b25;
	case 11050ULL: goto x86_l_2b2a;
	case 11055ULL: goto x86_l_2b2f;
	case 11060ULL: goto x86_l_2b34;
	case 11062ULL: goto x86_l_2b36;
	case 11066ULL: goto x86_l_2b3a;
	case 11068ULL: goto x86_l_2b3c;
	case 11070ULL: goto x86_l_2b3e;
	case 11076ULL: goto x86_l_2b44;
	case 11079ULL: goto x86_l_2b47;
	case 11085ULL: goto x86_l_2b4d;
	case 11090ULL: goto x86_l_2b52;
	case 11095ULL: goto x86_l_2b57;
	case 11098ULL: goto x86_l_2b5a;
	case 11104ULL: goto x86_l_2b60;
	case 11110ULL: goto x86_l_2b66;
	case 11114ULL: goto x86_l_2b6a;
	case 11120ULL: goto x86_l_2b70;
	case 11122ULL: goto x86_l_2b72;
	case 11128ULL: goto x86_l_2b78;
	case 11130ULL: goto x86_l_2b7a;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11145ULL: goto x86_l_2b89;
	case 11151ULL: goto x86_l_2b8f;
	case 11153ULL: goto x86_l_2b91;
	case 11157ULL: goto x86_l_2b95;
	case 11163ULL: goto x86_l_2b9b;
	case 11166ULL: goto x86_l_2b9e;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11180ULL: goto x86_l_2bac;
	case 11182ULL: goto x86_l_2bae;
	case 11185ULL: goto x86_l_2bb1;
	case 11188ULL: goto x86_l_2bb4;
	case 11190ULL: goto x86_l_2bb6;
	case 11194ULL: goto x86_l_2bba;
	case 11198ULL: goto x86_l_2bbe;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11212ULL: goto x86_l_2bcc;
	case 11214ULL: goto x86_l_2bce;
	case 11217ULL: goto x86_l_2bd1;
	case 11223ULL: goto x86_l_2bd7;
	case 11226ULL: goto x86_l_2bda;
	case 11232ULL: goto x86_l_2be0;
	case 11238ULL: goto x86_l_2be6;
	case 11242ULL: goto x86_l_2bea;
	case 11248ULL: goto x86_l_2bf0;
	case 11252ULL: goto x86_l_2bf4;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11266ULL: goto x86_l_2c02;
	case 11270ULL: goto x86_l_2c06;
	case 11276ULL: goto x86_l_2c0c;
	case 11280ULL: goto x86_l_2c10;
	case 11286ULL: goto x86_l_2c16;
	case 11291ULL: goto x86_l_2c1b;
	case 11294ULL: goto x86_l_2c1e;
	case 11300ULL: goto x86_l_2c24;
	case 11306ULL: goto x86_l_2c2a;
	case 11310ULL: goto x86_l_2c2e;
	case 11316ULL: goto x86_l_2c34;
	case 11320ULL: goto x86_l_2c38;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11334ULL: goto x86_l_2c46;
	case 11337ULL: goto x86_l_2c49;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11347ULL: goto x86_l_2c53;
	case 11353ULL: goto x86_l_2c59;
	case 11356ULL: goto x86_l_2c5c;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11370ULL: goto x86_l_2c6a;
	case 11375ULL: goto x86_l_2c6f;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	default: return 0xffffffffffffffffULL;
	}
x86_l_260d:
	/* 0x260d: jg     2b44 <generic_retkprobe_filter_arg+0x2b44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b44;
	}
x86_l_2613:
	/* 0x2613: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2615:
	/* 0x2615: jle    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 624ULL;
	}
x86_l_261b:
	/* 0x261b: jmp    2b44 <generic_retkprobe_filter_arg+0x2b44> */
	goto x86_l_2b44;
x86_l_2620:
	/* 0x2620: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2625:
	/* 0x2625: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_262a:
	/* 0x262a: jb     2657 <generic_retkprobe_filter_arg+0x2657> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2657;
	}
x86_l_262c:
	/* 0x262c: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_2631:
	/* 0x2631: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_2636:
	/* 0x2636: jb     2657 <generic_retkprobe_filter_arg+0x2657> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2657;
	}
x86_l_2638:
	/* 0x2638: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_263d:
	/* 0x263d: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_2642:
	/* 0x2642: jb     2657 <generic_retkprobe_filter_arg+0x2657> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2657;
	}
x86_l_2644:
	/* 0x2644: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2646:
	/* 0x2646: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_264b:
	/* 0x264b: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_264e:
	/* 0x264e: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_2651:
	/* 0x2651: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_2657:
	/* 0x2657: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_265d:
	/* 0x265d: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_2663:
	/* 0x2663: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2666:
	/* 0x2666: jg     29ee <generic_retkprobe_filter_arg+0x29ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_29ee;
	}
x86_l_266c:
	/* 0x266c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_266e:
	/* 0x266e: je     2e7c <generic_retkprobe_filter_arg+0x2e7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11900ULL;
	}
x86_l_2674:
	/* 0x2674: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2677:
	/* 0x2677: jne    2e75 <generic_retkprobe_filter_arg+0x2e75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11893ULL;
	}
x86_l_267d:
	/* 0x267d: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2682:
	/* 0x2682: jmp    2e88 <generic_retkprobe_filter_arg+0x2e88> */
	return 11912ULL;
x86_l_2687:
	/* 0x2687: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_268a:
	/* 0x268a: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_268e:
	/* 0x268e: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2691:
	/* 0x2691: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2695:
	/* 0x2695: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2698:
	/* 0x2698: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_269b:
	/* 0x269b: cmp    esi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_269e:
	/* 0x269e: jb     2d14 <generic_retkprobe_filter_arg+0x2d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11540ULL;
	}
x86_l_26a4:
	/* 0x26a4: mov    rdi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26a9:
	/* 0x26a9: mov    rsi,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_26ae:
	/* 0x26ae: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_26b1:
	/* 0x26b1: je     26bc <generic_retkprobe_filter_arg+0x26bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26bc;
	}
x86_l_26b3:
	/* 0x26b3: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_26b6:
	/* 0x26b6: jne    2c43 <generic_retkprobe_filter_arg+0x2c43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c43;
	}
x86_l_26bc:
	/* 0x26bc: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_26bf:
	/* 0x26bf: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_26c2:
	/* 0x26c2: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_26c5:
	/* 0x26c5: jmp    2b22 <generic_retkprobe_filter_arg+0x2b22> */
	goto x86_l_2b22;
x86_l_26ca:
	/* 0x26ca: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_26cd:
	/* 0x26cd: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d1:
	/* 0x26d1: ja     26dc <generic_retkprobe_filter_arg+0x26dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_26dc;
	}
x86_l_26d3:
	/* 0x26d3: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_26d6:
	/* 0x26d6: jbe    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 624ULL;
	}
x86_l_26dc:
	/* 0x26dc: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_26df:
	/* 0x26df: jb     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 193ULL;
	}
x86_l_26e5:
	/* 0x26e5: mov    rsi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26ea:
	/* 0x26ea: mov    rdx,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_26ef:
	/* 0x26ef: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_26f2:
	/* 0x26f2: je     26fd <generic_retkprobe_filter_arg+0x26fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26fd;
	}
x86_l_26f4:
	/* 0x26f4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_26f7:
	/* 0x26f7: jne    2c85 <generic_retkprobe_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11397ULL;
	}
x86_l_26fd:
	/* 0x26fd: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2700:
	/* 0x2700: jg     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 193ULL;
	}
x86_l_2706:
	/* 0x2706: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2709:
	/* 0x2709: jle    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 624ULL;
	}
x86_l_270f:
	/* 0x270f: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_2714:
	/* 0x2714: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2718:
	/* 0x2718: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_271e:
	/* 0x271e: jmp    272a <generic_retkprobe_filter_arg+0x272a> */
	goto x86_l_272a;
x86_l_2720:
	/* 0x2720: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2724:
	/* 0x2724: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_272a:
	/* 0x272a: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_272d:
	/* 0x272d: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_2733:
	/* 0x2733: mov    rsi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2738:
	/* 0x2738: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_273b:
	/* 0x273b: jle    2758 <generic_retkprobe_filter_arg+0x2758> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2758;
	}
x86_l_273d:
	/* 0x273d: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2740:
	/* 0x2740: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2743:
	/* 0x2743: jae    2787 <generic_retkprobe_filter_arg+0x2787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2787;
	}
x86_l_2745:
	/* 0x2745: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2749:
	/* 0x2749: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_274d:
	/* 0x274d: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_2753:
	/* 0x2753: jmp    2d3b <generic_retkprobe_filter_arg+0x2d3b> */
	return 11579ULL;
x86_l_2758:
	/* 0x2758: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_275b:
	/* 0x275b: je     29a5 <generic_retkprobe_filter_arg+0x29a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29a5;
	}
x86_l_2761:
	/* 0x2761: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2764:
	/* 0x2764: jne    2d3b <generic_retkprobe_filter_arg+0x2d3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11579ULL;
	}
x86_l_276a:
	/* 0x276a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_276d:
	/* 0x276d: je     2778 <generic_retkprobe_filter_arg+0x2778> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2778;
	}
x86_l_276f:
	/* 0x276f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2772:
	/* 0x2772: jne    2d31 <generic_retkprobe_filter_arg+0x2d31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11569ULL;
	}
x86_l_2778:
	/* 0x2778: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_277c:
	/* 0x277c: jl     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 624ULL;
	}
x86_l_2782:
	/* 0x2782: jmp    2d3b <generic_retkprobe_filter_arg+0x2d3b> */
	return 11579ULL;
x86_l_2787:
	/* 0x2787: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_278a:
	/* 0x278a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_278e:
	/* 0x278e: jne    2d3b <generic_retkprobe_filter_arg+0x2d3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11579ULL;
	}
x86_l_2794:
	/* 0x2794: test   QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2798:
	/* 0x2798: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_279e:
	/* 0x279e: jmp    2d3b <generic_retkprobe_filter_arg+0x2d3b> */
	return 11579ULL;
x86_l_27a3:
	/* 0x27a3: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_27a6:
	/* 0x27a6: jne    2a17 <generic_retkprobe_filter_arg+0x2a17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a17;
	}
x86_l_27ac:
	/* 0x27ac: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_27b1:
	/* 0x27b1: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_27b3:
	/* 0x27b3: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_27b9:
	/* 0x27b9: jmp    2a17 <generic_retkprobe_filter_arg+0x2a17> */
	goto x86_l_2a17;
x86_l_27be:
	/* 0x27be: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_27c1:
	/* 0x27c1: jne    2a59 <generic_retkprobe_filter_arg+0x2a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a59;
	}
x86_l_27c7:
	/* 0x27c7: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27cc:
	/* 0x27cc: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_27ce:
	/* 0x27ce: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_27d4:
	/* 0x27d4: jmp    2a59 <generic_retkprobe_filter_arg+0x2a59> */
	goto x86_l_2a59;
x86_l_27d9:
	/* 0x27d9: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_27dc:
	/* 0x27dc: je     2e3f <generic_retkprobe_filter_arg+0x2e3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11839ULL;
	}
x86_l_27e2:
	/* 0x27e2: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_27e5:
	/* 0x27e5: je     2e15 <generic_retkprobe_filter_arg+0x2e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11797ULL;
	}
x86_l_27eb:
	/* 0x27eb: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_27ee:
	/* 0x27ee: jne    8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2303ULL;
	}
x86_l_27f4:
	/* 0x27f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27f9:
	/* 0x27f9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2800:
	/* 0x2800: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	return 11851ULL;
x86_l_2805:
	/* 0x2805: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_280a:
	/* 0x280a: jmp    2818 <generic_retkprobe_filter_arg+0x2818> */
	goto x86_l_2818;
x86_l_280c:
	/* 0x280c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2811:
	/* 0x2811: jmp    2818 <generic_retkprobe_filter_arg+0x2818> */
	goto x86_l_2818;
x86_l_2813:
	/* 0x2813: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2818:
	/* 0x2818: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_281a:
	/* 0x281a: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_281d:
	/* 0x281d: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2822:
	/* 0x2822: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2825:
	/* 0x2825: je     28da <generic_retkprobe_filter_arg+0x28da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28da;
	}
x86_l_282b:
	/* 0x282b: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_282f:
	/* 0x282f: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2833:
	/* 0x2833: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_283b:
	/* 0x283b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2840:
	/* 0x2840: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2847:
	/* 0x2847: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_284c:
	/* 0x284c: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_284f:
	/* 0x284f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2851:
	/* 0x2851: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2854:
	/* 0x2854: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2859:
	/* 0x2859: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2860:
	/* 0x2860: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2863:
	/* 0x2863: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2865:
	/* 0x2865: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_286a:
	/* 0x286a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_286d:
	/* 0x286d: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_2873:
	/* 0x2873: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_2878:
	/* 0x2878: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_287b:
	/* 0x287b: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_287f:
	/* 0x287f: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2884:
	/* 0x2884: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2889:
	/* 0x2889: je     3423 <generic_retkprobe_filter_arg+0x3423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13347ULL;
	}
x86_l_288f:
	/* 0x288f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2892:
	/* 0x2892: mov    ebx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2896:
	/* 0x2896: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2899:
	/* 0x2899: jg     28e1 <generic_retkprobe_filter_arg+0x28e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_28e1;
	}
x86_l_289b:
	/* 0x289b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28a0:
	/* 0x28a0: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a3:
	/* 0x28a3: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_28a7:
	/* 0x28a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28ac:
	/* 0x28ac: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_28ae:
	/* 0x28ae: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28b3:
	/* 0x28b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b5:
	/* 0x28b5: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_28bd:
	/* 0x28bd: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_28bf:
	/* 0x28bf: jbe    2924 <generic_retkprobe_filter_arg+0x2924> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2924;
	}
x86_l_28c1:
	/* 0x28c1: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28c6:
	/* 0x28c6: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_28ca:
	/* 0x28ca: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_28cd:
	/* 0x28cd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28d3:
	/* 0x28d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28d8:
	/* 0x28d8: jmp    291f <generic_retkprobe_filter_arg+0x291f> */
	goto x86_l_291f;
x86_l_28da:
	/* 0x28da: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28dc:
	/* 0x28dc: jmp    3423 <generic_retkprobe_filter_arg+0x3423> */
	return 13347ULL;
x86_l_28e1:
	/* 0x28e1: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28e6:
	/* 0x28e6: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e9:
	/* 0x28e9: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_28ed:
	/* 0x28ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28f2:
	/* 0x28f2: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_28f4:
	/* 0x28f4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28f9:
	/* 0x28f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28fb:
	/* 0x28fb: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2903:
	/* 0x2903: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2905:
	/* 0x2905: jbe    2924 <generic_retkprobe_filter_arg+0x2924> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2924;
	}
x86_l_2907:
	/* 0x2907: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_290c:
	/* 0x290c: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2910:
	/* 0x2910: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2914:
	/* 0x2914: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_291a:
	/* 0x291a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_291f:
	/* 0x291f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2922:
	/* 0x2922: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2924:
	/* 0x2924: mov    eax,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2928:
	/* 0x2928: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_292c:
	/* 0x292c: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_292f:
	/* 0x292f: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2934:
	/* 0x2934: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2939:
	/* 0x2939: jle    2970 <generic_retkprobe_filter_arg+0x2970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2970;
	}
x86_l_293b:
	/* 0x293b: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_293e:
	/* 0x293e: jg     2ab0 <generic_retkprobe_filter_arg+0x2ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ab0;
	}
x86_l_2944:
	/* 0x2944: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2947:
	/* 0x2947: je     3138 <generic_retkprobe_filter_arg+0x3138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12600ULL;
	}
x86_l_294d:
	/* 0x294d: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2950:
	/* 0x2950: je     310e <generic_retkprobe_filter_arg+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12558ULL;
	}
x86_l_2956:
	/* 0x2956: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2959:
	/* 0x2959: jne    1fd5 <generic_retkprobe_filter_arg+0x1fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8149ULL;
	}
x86_l_295f:
	/* 0x295f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2964:
	/* 0x2964: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_296b:
	/* 0x296b: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	return 12626ULL;
x86_l_2970:
	/* 0x2970: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2973:
	/* 0x2973: jle    2ce4 <generic_retkprobe_filter_arg+0x2ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11492ULL;
	}
x86_l_2979:
	/* 0x2979: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_297c:
	/* 0x297c: je     312a <generic_retkprobe_filter_arg+0x312a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12586ULL;
	}
x86_l_2982:
	/* 0x2982: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2985:
	/* 0x2985: je     3100 <generic_retkprobe_filter_arg+0x3100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12544ULL;
	}
x86_l_298b:
	/* 0x298b: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_298e:
	/* 0x298e: jne    1fd5 <generic_retkprobe_filter_arg+0x1fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8149ULL;
	}
x86_l_2994:
	/* 0x2994: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2999:
	/* 0x2999: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_29a0:
	/* 0x29a0: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	return 12626ULL;
x86_l_29a5:
	/* 0x29a5: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_29a8:
	/* 0x29a8: je     29b3 <generic_retkprobe_filter_arg+0x29b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29b3;
	}
x86_l_29aa:
	/* 0x29aa: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_29ad:
	/* 0x29ad: jne    2d25 <generic_retkprobe_filter_arg+0x2d25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11557ULL;
	}
x86_l_29b3:
	/* 0x29b3: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b7:
	/* 0x29b7: jg     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 624ULL;
	}
x86_l_29bd:
	/* 0x29bd: jmp    2d3b <generic_retkprobe_filter_arg+0x2d3b> */
	return 11579ULL;
x86_l_29c2:
	/* 0x29c2: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_29c5:
	/* 0x29c5: je     3087 <generic_retkprobe_filter_arg+0x3087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12423ULL;
	}
x86_l_29cb:
	/* 0x29cb: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_29ce:
	/* 0x29ce: je     305d <generic_retkprobe_filter_arg+0x305d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12381ULL;
	}
x86_l_29d4:
	/* 0x29d4: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_29d7:
	/* 0x29d7: jne    2c6f <generic_retkprobe_filter_arg+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c6f;
	}
x86_l_29dd:
	/* 0x29dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29e2:
	/* 0x29e2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_29e9:
	/* 0x29e9: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	return 12435ULL;
x86_l_29ee:
	/* 0x29ee: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_29f1:
	/* 0x29f1: je     2e83 <generic_retkprobe_filter_arg+0x2e83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11907ULL;
	}
x86_l_29f7:
	/* 0x29f7: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_29fa:
	/* 0x29fa: jne    2e75 <generic_retkprobe_filter_arg+0x2e75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11893ULL;
	}
x86_l_2a00:
	/* 0x2a00: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2a05:
	/* 0x2a05: jmp    2e88 <generic_retkprobe_filter_arg+0x2e88> */
	return 11912ULL;
x86_l_2a0a:
	/* 0x2a0a: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2a0f:
	/* 0x2a0f: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2a11:
	/* 0x2a11: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_2a17:
	/* 0x2a17: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2a1a:
	/* 0x2a1a: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_2a20:
	/* 0x2a20: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a25:
	/* 0x2a25: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a28:
	/* 0x2a28: jle    2c9c <generic_retkprobe_filter_arg+0x2c9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11420ULL;
	}
x86_l_2a2e:
	/* 0x2a2e: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2a31:
	/* 0x2a31: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2a34:
	/* 0x2a34: jae    2db5 <generic_retkprobe_filter_arg+0x2db5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11701ULL;
	}
x86_l_2a3a:
	/* 0x2a3a: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2a3f:
	/* 0x2a3f: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2a41:
	/* 0x2a41: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_2a47:
	/* 0x2a47: jmp    3181 <generic_retkprobe_filter_arg+0x3181> */
	return 12673ULL;
x86_l_2a4c:
	/* 0x2a4c: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a51:
	/* 0x2a51: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2a53:
	/* 0x2a53: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_2a59:
	/* 0x2a59: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2a5c:
	/* 0x2a5c: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_2a62:
	/* 0x2a62: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a67:
	/* 0x2a67: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a6a:
	/* 0x2a6a: jle    2cc0 <generic_retkprobe_filter_arg+0x2cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11456ULL;
	}
x86_l_2a70:
	/* 0x2a70: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2a73:
	/* 0x2a73: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2a76:
	/* 0x2a76: jae    2dd0 <generic_retkprobe_filter_arg+0x2dd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11728ULL;
	}
x86_l_2a7c:
	/* 0x2a7c: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a81:
	/* 0x2a81: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2a83:
	/* 0x2a83: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_2a89:
	/* 0x2a89: jmp    31ca <generic_retkprobe_filter_arg+0x31ca> */
	return 12746ULL;
x86_l_2a8e:
	/* 0x2a8e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a90:
	/* 0x2a90: je     2deb <generic_retkprobe_filter_arg+0x2deb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11755ULL;
	}
x86_l_2a96:
	/* 0x2a96: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a99:
	/* 0x2a99: jne    8ff <generic_retkprobe_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2303ULL;
	}
x86_l_2a9f:
	/* 0x2a9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aa4:
	/* 0x2aa4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2aab:
	/* 0x2aab: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	return 11851ULL;
x86_l_2ab0:
	/* 0x2ab0: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2ab3:
	/* 0x2ab3: je     3146 <generic_retkprobe_filter_arg+0x3146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12614ULL;
	}
x86_l_2ab9:
	/* 0x2ab9: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_2abc:
	/* 0x2abc: je     311c <generic_retkprobe_filter_arg+0x311c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12572ULL;
	}
x86_l_2ac2:
	/* 0x2ac2: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2ac5:
	/* 0x2ac5: jne    1fd5 <generic_retkprobe_filter_arg+0x1fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8149ULL;
	}
x86_l_2acb:
	/* 0x2acb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ad0:
	/* 0x2ad0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2ad7:
	/* 0x2ad7: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	return 12626ULL;
x86_l_2adc:
	/* 0x2adc: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2adf:
	/* 0x2adf: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2ae3:
	/* 0x2ae3: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2ae5:
	/* 0x2ae5: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2ae9:
	/* 0x2ae9: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2aec:
	/* 0x2aec: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2aef:
	/* 0x2aef: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2af2:
	/* 0x2af2: jb     2d14 <generic_retkprobe_filter_arg+0x2d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11540ULL;
	}
x86_l_2af8:
	/* 0x2af8: mov    edi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2afd:
	/* 0x2afd: mov    esi,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2b02:
	/* 0x2b02: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2b05:
	/* 0x2b05: ja     2d06 <generic_retkprobe_filter_arg+0x2d06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11526ULL;
	}
x86_l_2b0b:
	/* 0x2b0b: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2b11:
	/* 0x2b11: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2b15:
	/* 0x2b15: jae    2d06 <generic_retkprobe_filter_arg+0x2d06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11526ULL;
	}
x86_l_2b1b:
	/* 0x2b1b: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2b1d:
	/* 0x2b1d: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_2b20:
	/* 0x2b20: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2b22:
	/* 0x2b22: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_2b25:
	/* 0x2b25: jmp    2d10 <generic_retkprobe_filter_arg+0x2d10> */
	return 11536ULL;
x86_l_2b2a:
	/* 0x2b2a: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2b2f:
	/* 0x2b2f: jmp    3415 <generic_retkprobe_filter_arg+0x3415> */
	return 13333ULL;
x86_l_2b34:
	/* 0x2b34: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2b36:
	/* 0x2b36: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b3a:
	/* 0x2b3a: ja     2b44 <generic_retkprobe_filter_arg+0x2b44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b44;
	}
x86_l_2b3c:
	/* 0x2b3c: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2b3e:
	/* 0x2b3e: jbe    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 624ULL;
	}
x86_l_2b44:
	/* 0x2b44: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2b47:
	/* 0x2b47: jb     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 193ULL;
	}
x86_l_2b4d:
	/* 0x2b4d: mov    esi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b52:
	/* 0x2b52: mov    edx,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2b57:
	/* 0x2b57: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2b5a:
	/* 0x2b5a: ja     3001 <generic_retkprobe_filter_arg+0x3001> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12289ULL;
	}
x86_l_2b60:
	/* 0x2b60: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2b66:
	/* 0x2b66: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2b6a:
	/* 0x2b6a: jae    3001 <generic_retkprobe_filter_arg+0x3001> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12289ULL;
	}
x86_l_2b70:
	/* 0x2b70: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2b72:
	/* 0x2b72: jg     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 193ULL;
	}
x86_l_2b78:
	/* 0x2b78: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2b7a:
	/* 0x2b7a: jle    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 624ULL;
	}
x86_l_2b80:
	/* 0x2b80: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_2b85:
	/* 0x2b85: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b89:
	/* 0x2b89: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_2b8f:
	/* 0x2b8f: jmp    2b9b <generic_retkprobe_filter_arg+0x2b9b> */
	goto x86_l_2b9b;
x86_l_2b91:
	/* 0x2b91: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b95:
	/* 0x2b95: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_2b9b:
	/* 0x2b9b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2b9e:
	/* 0x2b9e: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_2ba4:
	/* 0x2ba4: mov    esi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ba9:
	/* 0x2ba9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bac:
	/* 0x2bac: jle    2bc9 <generic_retkprobe_filter_arg+0x2bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2bc9;
	}
x86_l_2bae:
	/* 0x2bae: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2bb1:
	/* 0x2bb1: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2bb4:
	/* 0x2bb4: jae    2bff <generic_retkprobe_filter_arg+0x2bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2bff;
	}
x86_l_2bb6:
	/* 0x2bb6: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bba:
	/* 0x2bba: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bbe:
	/* 0x2bbe: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_2bc4:
	/* 0x2bc4: jmp    3253 <generic_retkprobe_filter_arg+0x3253> */
	return 12883ULL;
x86_l_2bc9:
	/* 0x2bc9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bcc:
	/* 0x2bcc: je     2c1b <generic_retkprobe_filter_arg+0x2c1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c1b;
	}
x86_l_2bce:
	/* 0x2bce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bd1:
	/* 0x2bd1: jne    3253 <generic_retkprobe_filter_arg+0x3253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12883ULL;
	}
x86_l_2bd7:
	/* 0x2bd7: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2bda:
	/* 0x2bda: ja     3249 <generic_retkprobe_filter_arg+0x3249> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12873ULL;
	}
x86_l_2be0:
	/* 0x2be0: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2be6:
	/* 0x2be6: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2bea:
	/* 0x2bea: jae    3249 <generic_retkprobe_filter_arg+0x3249> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12873ULL;
	}
x86_l_2bf0:
	/* 0x2bf0: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf4:
	/* 0x2bf4: jl     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 624ULL;
	}
x86_l_2bfa:
	/* 0x2bfa: jmp    3253 <generic_retkprobe_filter_arg+0x3253> */
	return 12883ULL;
x86_l_2bff:
	/* 0x2bff: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2c02:
	/* 0x2c02: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c06:
	/* 0x2c06: jne    3253 <generic_retkprobe_filter_arg+0x3253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12883ULL;
	}
x86_l_2c0c:
	/* 0x2c0c: test   DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c10:
	/* 0x2c10: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_2c16:
	/* 0x2c16: jmp    3253 <generic_retkprobe_filter_arg+0x3253> */
	return 12883ULL;
x86_l_2c1b:
	/* 0x2c1b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2c1e:
	/* 0x2c1e: ja     323d <generic_retkprobe_filter_arg+0x323d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12861ULL;
	}
x86_l_2c24:
	/* 0x2c24: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2c2a:
	/* 0x2c2a: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2c2e:
	/* 0x2c2e: jae    323d <generic_retkprobe_filter_arg+0x323d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12861ULL;
	}
x86_l_2c34:
	/* 0x2c34: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c38:
	/* 0x2c38: jg     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 624ULL;
	}
x86_l_2c3e:
	/* 0x2c3e: jmp    3253 <generic_retkprobe_filter_arg+0x3253> */
	return 12883ULL;
x86_l_2c43:
	/* 0x2c43: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2c46:
	/* 0x2c46: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2c49:
	/* 0x2c49: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2c4c:
	/* 0x2c4c: jmp    2d0d <generic_retkprobe_filter_arg+0x2d0d> */
	return 11533ULL;
x86_l_2c51:
	/* 0x2c51: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c53:
	/* 0x2c53: je     3033 <generic_retkprobe_filter_arg+0x3033> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12339ULL;
	}
x86_l_2c59:
	/* 0x2c59: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c5c:
	/* 0x2c5c: jne    2c6f <generic_retkprobe_filter_arg+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c6f;
	}
x86_l_2c5e:
	/* 0x2c5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c63:
	/* 0x2c63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2c6a:
	/* 0x2c6a: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	return 12435ULL;
x86_l_2c6f:
	/* 0x2c6f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c71:
	/* 0x2c71: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c76:
	/* 0x2c76: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
	return 11386ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11386ULL: goto x86_l_2c7a;
	case 11392ULL: goto x86_l_2c80;
	case 11397ULL: goto x86_l_2c85;
	case 11400ULL: goto x86_l_2c88;
	case 11406ULL: goto x86_l_2c8e;
	case 11409ULL: goto x86_l_2c91;
	case 11415ULL: goto x86_l_2c97;
	case 11420ULL: goto x86_l_2c9c;
	case 11423ULL: goto x86_l_2c9f;
	case 11429ULL: goto x86_l_2ca5;
	case 11432ULL: goto x86_l_2ca8;
	case 11438ULL: goto x86_l_2cae;
	case 11443ULL: goto x86_l_2cb3;
	case 11445ULL: goto x86_l_2cb5;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11459ULL: goto x86_l_2cc3;
	case 11465ULL: goto x86_l_2cc9;
	case 11468ULL: goto x86_l_2ccc;
	case 11474ULL: goto x86_l_2cd2;
	case 11479ULL: goto x86_l_2cd7;
	case 11481ULL: goto x86_l_2cd9;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11494ULL: goto x86_l_2ce6;
	case 11500ULL: goto x86_l_2cec;
	case 11503ULL: goto x86_l_2cef;
	case 11509ULL: goto x86_l_2cf5;
	case 11514ULL: goto x86_l_2cfa;
	case 11521ULL: goto x86_l_2d01;
	case 11526ULL: goto x86_l_2d06;
	case 11528ULL: goto x86_l_2d08;
	case 11531ULL: goto x86_l_2d0b;
	case 11533ULL: goto x86_l_2d0d;
	case 11536ULL: goto x86_l_2d10;
	case 11538ULL: goto x86_l_2d12;
	case 11540ULL: goto x86_l_2d14;
	case 11544ULL: goto x86_l_2d18;
	case 11546ULL: goto x86_l_2d1a;
	case 11552ULL: goto x86_l_2d20;
	case 11557ULL: goto x86_l_2d25;
	case 11561ULL: goto x86_l_2d29;
	case 11567ULL: goto x86_l_2d2f;
	case 11569ULL: goto x86_l_2d31;
	case 11573ULL: goto x86_l_2d35;
	case 11579ULL: goto x86_l_2d3b;
	case 11582ULL: goto x86_l_2d3e;
	case 11588ULL: goto x86_l_2d44;
	case 11593ULL: goto x86_l_2d49;
	case 11596ULL: goto x86_l_2d4c;
	case 11598ULL: goto x86_l_2d4e;
	case 11601ULL: goto x86_l_2d51;
	case 11604ULL: goto x86_l_2d54;
	case 11606ULL: goto x86_l_2d56;
	case 11609ULL: goto x86_l_2d59;
	case 11615ULL: goto x86_l_2d5f;
	case 11618ULL: goto x86_l_2d62;
	case 11624ULL: goto x86_l_2d68;
	case 11628ULL: goto x86_l_2d6c;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11642ULL: goto x86_l_2d7a;
	case 11648ULL: goto x86_l_2d80;
	case 11651ULL: goto x86_l_2d83;
	case 11657ULL: goto x86_l_2d89;
	case 11660ULL: goto x86_l_2d8c;
	case 11662ULL: goto x86_l_2d8e;
	case 11665ULL: goto x86_l_2d91;
	case 11671ULL: goto x86_l_2d97;
	case 11675ULL: goto x86_l_2d9b;
	case 11681ULL: goto x86_l_2da1;
	case 11686ULL: goto x86_l_2da6;
	case 11690ULL: goto x86_l_2daa;
	case 11696ULL: goto x86_l_2db0;
	case 11701ULL: goto x86_l_2db5;
	case 11704ULL: goto x86_l_2db8;
	case 11710ULL: goto x86_l_2dbe;
	case 11715ULL: goto x86_l_2dc3;
	case 11717ULL: goto x86_l_2dc5;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11731ULL: goto x86_l_2dd3;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11744ULL: goto x86_l_2de0;
	case 11750ULL: goto x86_l_2de6;
	case 11755ULL: goto x86_l_2deb;
	case 11760ULL: goto x86_l_2df0;
	case 11767ULL: goto x86_l_2df7;
	case 11769ULL: goto x86_l_2df9;
	case 11774ULL: goto x86_l_2dfe;
	case 11781ULL: goto x86_l_2e05;
	case 11783ULL: goto x86_l_2e07;
	case 11788ULL: goto x86_l_2e0c;
	case 11795ULL: goto x86_l_2e13;
	case 11797ULL: goto x86_l_2e15;
	case 11802ULL: goto x86_l_2e1a;
	case 11809ULL: goto x86_l_2e21;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11823ULL: goto x86_l_2e2f;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11837ULL: goto x86_l_2e3d;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11851ULL: goto x86_l_2e4b;
	case 11856ULL: goto x86_l_2e50;
	case 11858ULL: goto x86_l_2e52;
	case 11861ULL: goto x86_l_2e55;
	case 11867ULL: goto x86_l_2e5b;
	case 11872ULL: goto x86_l_2e60;
	case 11875ULL: goto x86_l_2e63;
	case 11878ULL: goto x86_l_2e66;
	case 11880ULL: goto x86_l_2e68;
	case 11882ULL: goto x86_l_2e6a;
	case 11885ULL: goto x86_l_2e6d;
	case 11888ULL: goto x86_l_2e70;
	case 11893ULL: goto x86_l_2e75;
	case 11898ULL: goto x86_l_2e7a;
	case 11900ULL: goto x86_l_2e7c;
	case 11905ULL: goto x86_l_2e81;
	case 11907ULL: goto x86_l_2e83;
	case 11912ULL: goto x86_l_2e88;
	case 11914ULL: goto x86_l_2e8a;
	case 11917ULL: goto x86_l_2e8d;
	case 11922ULL: goto x86_l_2e92;
	case 11925ULL: goto x86_l_2e95;
	case 11931ULL: goto x86_l_2e9b;
	case 11935ULL: goto x86_l_2e9f;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11949ULL: goto x86_l_2ead;
	case 11956ULL: goto x86_l_2eb4;
	case 11961ULL: goto x86_l_2eb9;
	case 11964ULL: goto x86_l_2ebc;
	case 11966ULL: goto x86_l_2ebe;
	case 11971ULL: goto x86_l_2ec3;
	case 11976ULL: goto x86_l_2ec8;
	case 11983ULL: goto x86_l_2ecf;
	case 11986ULL: goto x86_l_2ed2;
	case 11988ULL: goto x86_l_2ed4;
	case 11994ULL: goto x86_l_2eda;
	case 12000ULL: goto x86_l_2ee0;
	case 12005ULL: goto x86_l_2ee5;
	case 12008ULL: goto x86_l_2ee8;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12028ULL: goto x86_l_2efc;
	case 12036ULL: goto x86_l_2f04;
	case 12040ULL: goto x86_l_2f08;
	case 12043ULL: goto x86_l_2f0b;
	case 12045ULL: goto x86_l_2f0d;
	case 12050ULL: goto x86_l_2f12;
	case 12053ULL: goto x86_l_2f15;
	case 12057ULL: goto x86_l_2f19;
	case 12062ULL: goto x86_l_2f1e;
	case 12064ULL: goto x86_l_2f20;
	case 12067ULL: goto x86_l_2f23;
	case 12069ULL: goto x86_l_2f25;
	case 12074ULL: goto x86_l_2f2a;
	case 12076ULL: goto x86_l_2f2c;
	case 12078ULL: goto x86_l_2f2e;
	case 12083ULL: goto x86_l_2f33;
	case 12087ULL: goto x86_l_2f37;
	case 12090ULL: goto x86_l_2f3a;
	case 12096ULL: goto x86_l_2f40;
	case 12101ULL: goto x86_l_2f45;
	case 12103ULL: goto x86_l_2f47;
	case 12108ULL: goto x86_l_2f4c;
	case 12111ULL: goto x86_l_2f4f;
	case 12115ULL: goto x86_l_2f53;
	case 12120ULL: goto x86_l_2f58;
	case 12122ULL: goto x86_l_2f5a;
	case 12125ULL: goto x86_l_2f5d;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12134ULL: goto x86_l_2f66;
	case 12136ULL: goto x86_l_2f68;
	case 12141ULL: goto x86_l_2f6d;
	case 12145ULL: goto x86_l_2f71;
	case 12149ULL: goto x86_l_2f75;
	case 12155ULL: goto x86_l_2f7b;
	case 12160ULL: goto x86_l_2f80;
	case 12168ULL: goto x86_l_2f88;
	case 12170ULL: goto x86_l_2f8a;
	case 12174ULL: goto x86_l_2f8e;
	case 12178ULL: goto x86_l_2f92;
	case 12181ULL: goto x86_l_2f95;
	case 12183ULL: goto x86_l_2f97;
	case 12186ULL: goto x86_l_2f9a;
	case 12192ULL: goto x86_l_2fa0;
	case 12195ULL: goto x86_l_2fa3;
	case 12201ULL: goto x86_l_2fa9;
	case 12204ULL: goto x86_l_2fac;
	case 12210ULL: goto x86_l_2fb2;
	case 12213ULL: goto x86_l_2fb5;
	case 12219ULL: goto x86_l_2fbb;
	case 12224ULL: goto x86_l_2fc0;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12239ULL: goto x86_l_2fcf;
	case 12245ULL: goto x86_l_2fd5;
	case 12248ULL: goto x86_l_2fd8;
	case 12254ULL: goto x86_l_2fde;
	case 12257ULL: goto x86_l_2fe1;
	case 12263ULL: goto x86_l_2fe7;
	case 12266ULL: goto x86_l_2fea;
	case 12272ULL: goto x86_l_2ff0;
	case 12277ULL: goto x86_l_2ff5;
	case 12284ULL: goto x86_l_2ffc;
	case 12289ULL: goto x86_l_3001;
	case 12291ULL: goto x86_l_3003;
	case 12297ULL: goto x86_l_3009;
	case 12299ULL: goto x86_l_300b;
	case 12305ULL: goto x86_l_3011;
	case 12310ULL: goto x86_l_3016;
	case 12313ULL: goto x86_l_3019;
	case 12315ULL: goto x86_l_301b;
	case 12318ULL: goto x86_l_301e;
	case 12324ULL: goto x86_l_3024;
	case 12328ULL: goto x86_l_3028;
	case 12334ULL: goto x86_l_302e;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12351ULL: goto x86_l_303f;
	case 12353ULL: goto x86_l_3041;
	case 12358ULL: goto x86_l_3046;
	case 12365ULL: goto x86_l_304d;
	case 12367ULL: goto x86_l_304f;
	case 12372ULL: goto x86_l_3054;
	case 12379ULL: goto x86_l_305b;
	case 12381ULL: goto x86_l_305d;
	case 12386ULL: goto x86_l_3062;
	case 12393ULL: goto x86_l_3069;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12407ULL: goto x86_l_3077;
	case 12409ULL: goto x86_l_3079;
	case 12414ULL: goto x86_l_307e;
	case 12421ULL: goto x86_l_3085;
	case 12423ULL: goto x86_l_3087;
	case 12428ULL: goto x86_l_308c;
	case 12435ULL: goto x86_l_3093;
	case 12440ULL: goto x86_l_3098;
	case 12442ULL: goto x86_l_309a;
	case 12445ULL: goto x86_l_309d;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12455ULL: goto x86_l_30a7;
	case 12458ULL: goto x86_l_30aa;
	case 12460ULL: goto x86_l_30ac;
	case 12462ULL: goto x86_l_30ae;
	case 12465ULL: goto x86_l_30b1;
	case 12468ULL: goto x86_l_30b4;
	case 12470ULL: goto x86_l_30b6;
	case 12472ULL: goto x86_l_30b8;
	case 12476ULL: goto x86_l_30bc;
	case 12481ULL: goto x86_l_30c1;
	case 12486ULL: goto x86_l_30c6;
	case 12491ULL: goto x86_l_30cb;
	case 12495ULL: goto x86_l_30cf;
	case 12501ULL: goto x86_l_30d5;
	case 12511ULL: goto x86_l_30df;
	case 12515ULL: goto x86_l_30e3;
	case 12521ULL: goto x86_l_30e9;
	case 12525ULL: goto x86_l_30ed;
	case 12530ULL: goto x86_l_30f2;
	case 12535ULL: goto x86_l_30f7;
	case 12542ULL: goto x86_l_30fe;
	case 12544ULL: goto x86_l_3100;
	case 12549ULL: goto x86_l_3105;
	case 12556ULL: goto x86_l_310c;
	case 12558ULL: goto x86_l_310e;
	case 12563ULL: goto x86_l_3113;
	case 12570ULL: goto x86_l_311a;
	case 12572ULL: goto x86_l_311c;
	case 12577ULL: goto x86_l_3121;
	case 12584ULL: goto x86_l_3128;
	case 12586ULL: goto x86_l_312a;
	case 12591ULL: goto x86_l_312f;
	case 12598ULL: goto x86_l_3136;
	case 12600ULL: goto x86_l_3138;
	case 12605ULL: goto x86_l_313d;
	case 12612ULL: goto x86_l_3144;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12626ULL: goto x86_l_3152;
	case 12631ULL: goto x86_l_3157;
	case 12633ULL: goto x86_l_3159;
	case 12636ULL: goto x86_l_315c;
	case 12642ULL: goto x86_l_3162;
	case 12647ULL: goto x86_l_3167;
	case 12650ULL: goto x86_l_316a;
	case 12655ULL: goto x86_l_316f;
	case 12660ULL: goto x86_l_3174;
	case 12665ULL: goto x86_l_3179;
	case 12667ULL: goto x86_l_317b;
	case 12673ULL: goto x86_l_3181;
	case 12676ULL: goto x86_l_3184;
	case 12682ULL: goto x86_l_318a;
	case 12687ULL: goto x86_l_318f;
	case 12690ULL: goto x86_l_3192;
	case 12696ULL: goto x86_l_3198;
	case 12699ULL: goto x86_l_319b;
	case 12702ULL: goto x86_l_319e;
	case 12708ULL: goto x86_l_31a4;
	case 12711ULL: goto x86_l_31a7;
	case 12717ULL: goto x86_l_31ad;
	case 12720ULL: goto x86_l_31b0;
	case 12726ULL: goto x86_l_31b6;
	case 12731ULL: goto x86_l_31bb;
	case 12733ULL: goto x86_l_31bd;
	case 12738ULL: goto x86_l_31c2;
	case 12740ULL: goto x86_l_31c4;
	case 12746ULL: goto x86_l_31ca;
	case 12749ULL: goto x86_l_31cd;
	case 12755ULL: goto x86_l_31d3;
	case 12760ULL: goto x86_l_31d8;
	case 12763ULL: goto x86_l_31db;
	case 12769ULL: goto x86_l_31e1;
	case 12772ULL: goto x86_l_31e4;
	case 12775ULL: goto x86_l_31e7;
	case 12781ULL: goto x86_l_31ed;
	case 12784ULL: goto x86_l_31f0;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12799ULL: goto x86_l_31ff;
	case 12804ULL: goto x86_l_3204;
	case 12806ULL: goto x86_l_3206;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12820ULL: goto x86_l_3214;
	case 12826ULL: goto x86_l_321a;
	case 12829ULL: goto x86_l_321d;
	case 12835ULL: goto x86_l_3223;
	case 12838ULL: goto x86_l_3226;
	case 12844ULL: goto x86_l_322c;
	case 12849ULL: goto x86_l_3231;
	case 12856ULL: goto x86_l_3238;
	case 12861ULL: goto x86_l_323d;
	case 12865ULL: goto x86_l_3241;
	case 12871ULL: goto x86_l_3247;
	case 12873ULL: goto x86_l_3249;
	case 12877ULL: goto x86_l_324d;
	case 12883ULL: goto x86_l_3253;
	case 12886ULL: goto x86_l_3256;
	case 12892ULL: goto x86_l_325c;
	case 12897ULL: goto x86_l_3261;
	case 12900ULL: goto x86_l_3264;
	case 12902ULL: goto x86_l_3266;
	case 12905ULL: goto x86_l_3269;
	case 12908ULL: goto x86_l_326c;
	case 12910ULL: goto x86_l_326e;
	case 12913ULL: goto x86_l_3271;
	case 12919ULL: goto x86_l_3277;
	case 12922ULL: goto x86_l_327a;
	case 12928ULL: goto x86_l_3280;
	case 12932ULL: goto x86_l_3284;
	case 12938ULL: goto x86_l_328a;
	case 12943ULL: goto x86_l_328f;
	case 12946ULL: goto x86_l_3292;
	case 12948ULL: goto x86_l_3294;
	case 12951ULL: goto x86_l_3297;
	case 12957ULL: goto x86_l_329d;
	case 12960ULL: goto x86_l_32a0;
	case 12966ULL: goto x86_l_32a6;
	case 12971ULL: goto x86_l_32ab;
	case 12974ULL: goto x86_l_32ae;
	case 12980ULL: goto x86_l_32b4;
	case 12984ULL: goto x86_l_32b8;
	case 12990ULL: goto x86_l_32be;
	case 12995ULL: goto x86_l_32c3;
	case 12999ULL: goto x86_l_32c7;
	case 13005ULL: goto x86_l_32cd;
	case 13010ULL: goto x86_l_32d2;
	case 13013ULL: goto x86_l_32d5;
	case 13019ULL: goto x86_l_32db;
	case 13024ULL: goto x86_l_32e0;
	case 13027ULL: goto x86_l_32e3;
	case 13033ULL: goto x86_l_32e9;
	case 13037ULL: goto x86_l_32ed;
	case 13043ULL: goto x86_l_32f3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2c7a:
	/* 0x2c7a: jbe    30d5 <generic_retkprobe_filter_arg+0x30d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_30d5;
	}
x86_l_2c80:
	/* 0x2c80: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_2c85:
	/* 0x2c85: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2c88:
	/* 0x2c88: ja     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 193ULL;
	}
x86_l_2c8e:
	/* 0x2c8e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2c91:
	/* 0x2c91: jbe    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 624ULL;
	}
x86_l_2c97:
	/* 0x2c97: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_2c9c:
	/* 0x2c9c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c9f:
	/* 0x2c9f: je     3174 <generic_retkprobe_filter_arg+0x3174> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3174;
	}
x86_l_2ca5:
	/* 0x2ca5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ca8:
	/* 0x2ca8: jne    3181 <generic_retkprobe_filter_arg+0x3181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3181;
	}
x86_l_2cae:
	/* 0x2cae: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2cb3:
	/* 0x2cb3: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2cb5:
	/* 0x2cb5: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_2cbb:
	/* 0x2cbb: jmp    3181 <generic_retkprobe_filter_arg+0x3181> */
	goto x86_l_3181;
x86_l_2cc0:
	/* 0x2cc0: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cc3:
	/* 0x2cc3: je     31bd <generic_retkprobe_filter_arg+0x31bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31bd;
	}
x86_l_2cc9:
	/* 0x2cc9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ccc:
	/* 0x2ccc: jne    31ca <generic_retkprobe_filter_arg+0x31ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31ca;
	}
x86_l_2cd2:
	/* 0x2cd2: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cd7:
	/* 0x2cd7: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2cd9:
	/* 0x2cd9: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_2cdf:
	/* 0x2cdf: jmp    31ca <generic_retkprobe_filter_arg+0x31ca> */
	goto x86_l_31ca;
x86_l_2ce4:
	/* 0x2ce4: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_2ce6:
	/* 0x2ce6: je     30f2 <generic_retkprobe_filter_arg+0x30f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30f2;
	}
x86_l_2cec:
	/* 0x2cec: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2cef:
	/* 0x2cef: jne    1fd5 <generic_retkprobe_filter_arg+0x1fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8149ULL;
	}
x86_l_2cf5:
	/* 0x2cf5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cfa:
	/* 0x2cfa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2d01:
	/* 0x2d01: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	goto x86_l_3152;
x86_l_2d06:
	/* 0x2d06: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2d08:
	/* 0x2d08: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2d0b:
	/* 0x2d0b: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2d0d:
	/* 0x2d0d: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_2d10:
	/* 0x2d10: and    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2d12:
	/* 0x2d12: or     al,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2d14:
	/* 0x2d14: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d18:
	/* 0x2d18: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2d1a:
	/* 0x2d1a: je     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 624ULL;
	}
x86_l_2d20:
	/* 0x2d20: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_2d25:
	/* 0x2d25: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d29:
	/* 0x2d29: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_2d2f:
	/* 0x2d2f: jmp    2d3b <generic_retkprobe_filter_arg+0x2d3b> */
	goto x86_l_2d3b;
x86_l_2d31:
	/* 0x2d31: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d35:
	/* 0x2d35: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_2d3b:
	/* 0x2d3b: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2d3e:
	/* 0x2d3e: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_2d44:
	/* 0x2d44: mov    rdx,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d49:
	/* 0x2d49: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d4c:
	/* 0x2d4c: jle    2d77 <generic_retkprobe_filter_arg+0x2d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2d77;
	}
x86_l_2d4e:
	/* 0x2d4e: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2d51:
	/* 0x2d51: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2d54:
	/* 0x2d54: jb     2da6 <generic_retkprobe_filter_arg+0x2da6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2da6;
	}
x86_l_2d56:
	/* 0x2d56: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2d59:
	/* 0x2d59: je     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 624ULL;
	}
x86_l_2d5f:
	/* 0x2d5f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2d62:
	/* 0x2d62: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_2d68:
	/* 0x2d68: test   QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d6c:
	/* 0x2d6c: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_2d72:
	/* 0x2d72: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	return 13442ULL;
x86_l_2d77:
	/* 0x2d77: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d7a:
	/* 0x2d7a: je     3016 <generic_retkprobe_filter_arg+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3016;
	}
x86_l_2d80:
	/* 0x2d80: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d83:
	/* 0x2d83: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_2d89:
	/* 0x2d89: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2d8c:
	/* 0x2d8c: je     2d97 <generic_retkprobe_filter_arg+0x2d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d97;
	}
x86_l_2d8e:
	/* 0x2d8e: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2d91:
	/* 0x2d91: jne    3370 <generic_retkprobe_filter_arg+0x3370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13168ULL;
	}
x86_l_2d97:
	/* 0x2d97: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d9b:
	/* 0x2d9b: jl     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 624ULL;
	}
x86_l_2da1:
	/* 0x2da1: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	return 13442ULL;
x86_l_2da6:
	/* 0x2da6: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2daa:
	/* 0x2daa: jne    3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13442ULL;
	}
x86_l_2db0:
	/* 0x2db0: jmp    257 <generic_retkprobe_filter_arg+0x257> */
	return 599ULL;
x86_l_2db5:
	/* 0x2db5: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2db8:
	/* 0x2db8: jne    3181 <generic_retkprobe_filter_arg+0x3181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3181;
	}
x86_l_2dbe:
	/* 0x2dbe: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2dc3:
	/* 0x2dc3: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2dc5:
	/* 0x2dc5: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_2dcb:
	/* 0x2dcb: jmp    3181 <generic_retkprobe_filter_arg+0x3181> */
	goto x86_l_3181;
x86_l_2dd0:
	/* 0x2dd0: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2dd3:
	/* 0x2dd3: jne    31ca <generic_retkprobe_filter_arg+0x31ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31ca;
	}
x86_l_2dd9:
	/* 0x2dd9: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2dde:
	/* 0x2dde: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2de0:
	/* 0x2de0: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_2de6:
	/* 0x2de6: jmp    31ca <generic_retkprobe_filter_arg+0x31ca> */
	goto x86_l_31ca;
x86_l_2deb:
	/* 0x2deb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2df0:
	/* 0x2df0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2df7:
	/* 0x2df7: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	goto x86_l_2e4b;
x86_l_2df9:
	/* 0x2df9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2dfe:
	/* 0x2dfe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2e05:
	/* 0x2e05: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	goto x86_l_2e4b;
x86_l_2e07:
	/* 0x2e07: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e0c:
	/* 0x2e0c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2e13:
	/* 0x2e13: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	goto x86_l_2e4b;
x86_l_2e15:
	/* 0x2e15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e1a:
	/* 0x2e1a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_2e21:
	/* 0x2e21: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	goto x86_l_2e4b;
x86_l_2e23:
	/* 0x2e23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e28:
	/* 0x2e28: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2e2f:
	/* 0x2e2f: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	goto x86_l_2e4b;
x86_l_2e31:
	/* 0x2e31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e36:
	/* 0x2e36: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2e3d:
	/* 0x2e3d: jmp    2e4b <generic_retkprobe_filter_arg+0x2e4b> */
	goto x86_l_2e4b;
x86_l_2e3f:
	/* 0x2e3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e44:
	/* 0x2e44: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_2e4b:
	/* 0x2e4b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e50:
	/* 0x2e50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e52:
	/* 0x2e52: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e55:
	/* 0x2e55: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30b6;
	}
x86_l_2e5b:
	/* 0x2e5b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2e60:
	/* 0x2e60: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e63:
	/* 0x2e63: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2e66:
	/* 0x2e66: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2e68:
	/* 0x2e68: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e6a:
	/* 0x2e6a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e6d:
	/* 0x2e6d: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2e70:
	/* 0x2e70: jmp    30b8 <generic_retkprobe_filter_arg+0x30b8> */
	goto x86_l_30b8;
x86_l_2e75:
	/* 0x2e75: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2e7a:
	/* 0x2e7a: jmp    2e88 <generic_retkprobe_filter_arg+0x2e88> */
	goto x86_l_2e88;
x86_l_2e7c:
	/* 0x2e7c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2e81:
	/* 0x2e81: jmp    2e88 <generic_retkprobe_filter_arg+0x2e88> */
	goto x86_l_2e88;
x86_l_2e83:
	/* 0x2e83: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e88:
	/* 0x2e88: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2e8a:
	/* 0x2e8a: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2e8d:
	/* 0x2e8d: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2e92:
	/* 0x2e92: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2e95:
	/* 0x2e95: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_2e9b:
	/* 0x2e9b: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2e9f:
	/* 0x2e9f: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ea3:
	/* 0x2ea3: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ea8:
	/* 0x2ea8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ead:
	/* 0x2ead: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2eb4:
	/* 0x2eb4: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eb9:
	/* 0x2eb9: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2ebc:
	/* 0x2ebc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ebe:
	/* 0x2ebe: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ec3:
	/* 0x2ec3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ec8:
	/* 0x2ec8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ecf:
	/* 0x2ecf: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2ed2:
	/* 0x2ed2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed4:
	/* 0x2ed4: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2eda:
	/* 0x2eda: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_2ee0:
	/* 0x2ee0: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_2ee5:
	/* 0x2ee5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ee8:
	/* 0x2ee8: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eec:
	/* 0x2eec: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ef1:
	/* 0x2ef1: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef6:
	/* 0x2ef6: je     3423 <generic_retkprobe_filter_arg+0x3423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13347ULL;
	}
x86_l_2efc:
	/* 0x2efc: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f04:
	/* 0x2f04: mov    ebx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f08:
	/* 0x2f08: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2f0b:
	/* 0x2f0b: jg     2f47 <generic_retkprobe_filter_arg+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f47;
	}
x86_l_2f0d:
	/* 0x2f0d: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f12:
	/* 0x2f12: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f15:
	/* 0x2f15: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2f19:
	/* 0x2f19: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f1e:
	/* 0x2f1e: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2f20:
	/* 0x2f20: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f23:
	/* 0x2f23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f25:
	/* 0x2f25: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f2a:
	/* 0x2f2a: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f2c:
	/* 0x2f2c: jbe    2f8a <generic_retkprobe_filter_arg+0x2f8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f8a;
	}
x86_l_2f2e:
	/* 0x2f2e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f33:
	/* 0x2f33: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2f37:
	/* 0x2f37: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2f3a:
	/* 0x2f3a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f40:
	/* 0x2f40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f45:
	/* 0x2f45: jmp    2f80 <generic_retkprobe_filter_arg+0x2f80> */
	goto x86_l_2f80;
x86_l_2f47:
	/* 0x2f47: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f4c:
	/* 0x2f4c: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f4f:
	/* 0x2f4f: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f53:
	/* 0x2f53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f58:
	/* 0x2f58: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2f5a:
	/* 0x2f5a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f5d:
	/* 0x2f5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f5f:
	/* 0x2f5f: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f64:
	/* 0x2f64: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f66:
	/* 0x2f66: jbe    2f8a <generic_retkprobe_filter_arg+0x2f8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f8a;
	}
x86_l_2f68:
	/* 0x2f68: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f6d:
	/* 0x2f6d: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2f71:
	/* 0x2f71: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2f75:
	/* 0x2f75: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f7b:
	/* 0x2f7b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f80:
	/* 0x2f80: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f88:
	/* 0x2f88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8a:
	/* 0x2f8a: mov    eax,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2f8e:
	/* 0x2f8e: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f92:
	/* 0x2f92: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2f95:
	/* 0x2f95: jle    2fcc <generic_retkprobe_filter_arg+0x2fcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2fcc;
	}
x86_l_2f97:
	/* 0x2f97: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2f9a:
	/* 0x2f9a: jg     3211 <generic_retkprobe_filter_arg+0x3211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3211;
	}
x86_l_2fa0:
	/* 0x2fa0: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2fa3:
	/* 0x2fa3: je     33d4 <generic_retkprobe_filter_arg+0x33d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13268ULL;
	}
x86_l_2fa9:
	/* 0x2fa9: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2fac:
	/* 0x2fac: je     33aa <generic_retkprobe_filter_arg+0x33aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13226ULL;
	}
x86_l_2fb2:
	/* 0x2fb2: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2fb5:
	/* 0x2fb5: jne    3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13331ULL;
	}
x86_l_2fbb:
	/* 0x2fbb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fc0:
	/* 0x2fc0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2fc7:
	/* 0x2fc7: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	return 13294ULL;
x86_l_2fcc:
	/* 0x2fcc: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2fcf:
	/* 0x2fcf: jle    32f8 <generic_retkprobe_filter_arg+0x32f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13048ULL;
	}
x86_l_2fd5:
	/* 0x2fd5: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2fd8:
	/* 0x2fd8: je     33c6 <generic_retkprobe_filter_arg+0x33c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13254ULL;
	}
x86_l_2fde:
	/* 0x2fde: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2fe1:
	/* 0x2fe1: je     339c <generic_retkprobe_filter_arg+0x339c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13212ULL;
	}
x86_l_2fe7:
	/* 0x2fe7: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2fea:
	/* 0x2fea: jne    3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13331ULL;
	}
x86_l_2ff0:
	/* 0x2ff0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ff5:
	/* 0x2ff5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2ffc:
	/* 0x2ffc: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	return 13294ULL;
x86_l_3001:
	/* 0x3001: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_3003:
	/* 0x3003: ja     c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 193ULL;
	}
x86_l_3009:
	/* 0x3009: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_300b:
	/* 0x300b: jbe    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 624ULL;
	}
x86_l_3011:
	/* 0x3011: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_3016:
	/* 0x3016: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3019:
	/* 0x3019: je     3024 <generic_retkprobe_filter_arg+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3024;
	}
x86_l_301b:
	/* 0x301b: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_301e:
	/* 0x301e: jne    337f <generic_retkprobe_filter_arg+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13183ULL;
	}
x86_l_3024:
	/* 0x3024: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3028:
	/* 0x3028: jg     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 624ULL;
	}
x86_l_302e:
	/* 0x302e: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	return 13442ULL;
x86_l_3033:
	/* 0x3033: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3038:
	/* 0x3038: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_303f:
	/* 0x303f: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	goto x86_l_3093;
x86_l_3041:
	/* 0x3041: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3046:
	/* 0x3046: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_304d:
	/* 0x304d: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	goto x86_l_3093;
x86_l_304f:
	/* 0x304f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3054:
	/* 0x3054: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_305b:
	/* 0x305b: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	goto x86_l_3093;
x86_l_305d:
	/* 0x305d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3062:
	/* 0x3062: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3069:
	/* 0x3069: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	goto x86_l_3093;
x86_l_306b:
	/* 0x306b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3070:
	/* 0x3070: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3077:
	/* 0x3077: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	goto x86_l_3093;
x86_l_3079:
	/* 0x3079: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_307e:
	/* 0x307e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3085:
	/* 0x3085: jmp    3093 <generic_retkprobe_filter_arg+0x3093> */
	goto x86_l_3093;
x86_l_3087:
	/* 0x3087: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_308c:
	/* 0x308c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3093:
	/* 0x3093: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3098:
	/* 0x3098: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_309a:
	/* 0x309a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_309d:
	/* 0x309d: je     30b6 <generic_retkprobe_filter_arg+0x30b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30b6;
	}
x86_l_309f:
	/* 0x309f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_30a4:
	/* 0x30a4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_30a7:
	/* 0x30a7: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_30aa:
	/* 0x30aa: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_30ac:
	/* 0x30ac: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30ae:
	/* 0x30ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30b1:
	/* 0x30b1: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_30b4:
	/* 0x30b4: jmp    30b8 <generic_retkprobe_filter_arg+0x30b8> */
	goto x86_l_30b8;
x86_l_30b6:
	/* 0x30b6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30b8:
	/* 0x30b8: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30bc:
	/* 0x30bc: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30c1:
	/* 0x30c1: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30c6:
	/* 0x30c6: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_30cb:
	/* 0x30cb: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_30cf:
	/* 0x30cf: ja     25f <generic_retkprobe_filter_arg+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 607ULL;
	}
x86_l_30d5:
	/* 0x30d5: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_30df:
	/* 0x30df: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_30e3:
	/* 0x30e3: jae    25f <generic_retkprobe_filter_arg+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 607ULL;
	}
x86_l_30e9:
	/* 0x30e9: xor    rbx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_30ed:
	/* 0x30ed: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_30f2:
	/* 0x30f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30f7:
	/* 0x30f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_30fe:
	/* 0x30fe: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	goto x86_l_3152;
x86_l_3100:
	/* 0x3100: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3105:
	/* 0x3105: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_310c:
	/* 0x310c: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	goto x86_l_3152;
x86_l_310e:
	/* 0x310e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3113:
	/* 0x3113: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_311a:
	/* 0x311a: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	goto x86_l_3152;
x86_l_311c:
	/* 0x311c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3121:
	/* 0x3121: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3128:
	/* 0x3128: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	goto x86_l_3152;
x86_l_312a:
	/* 0x312a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_312f:
	/* 0x312f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3136:
	/* 0x3136: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	goto x86_l_3152;
x86_l_3138:
	/* 0x3138: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_313d:
	/* 0x313d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3144:
	/* 0x3144: jmp    3152 <generic_retkprobe_filter_arg+0x3152> */
	goto x86_l_3152;
x86_l_3146:
	/* 0x3146: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_314b:
	/* 0x314b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3152:
	/* 0x3152: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3157:
	/* 0x3157: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3159:
	/* 0x3159: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_315c:
	/* 0x315c: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13331ULL;
	}
x86_l_3162:
	/* 0x3162: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3167:
	/* 0x3167: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_316a:
	/* 0x316a: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_316f:
	/* 0x316f: jmp    3407 <generic_retkprobe_filter_arg+0x3407> */
	return 13319ULL;
x86_l_3174:
	/* 0x3174: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3179:
	/* 0x3179: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_317b:
	/* 0x317b: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_3181:
	/* 0x3181: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_3184:
	/* 0x3184: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_318a:
	/* 0x318a: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_318f:
	/* 0x318f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3192:
	/* 0x3192: jle    331a <generic_retkprobe_filter_arg+0x331a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13082ULL;
	}
x86_l_3198:
	/* 0x3198: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_319b:
	/* 0x319b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_319e:
	/* 0x319e: jb     3357 <generic_retkprobe_filter_arg+0x3357> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13143ULL;
	}
x86_l_31a4:
	/* 0x31a4: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_31a7:
	/* 0x31a7: je     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 624ULL;
	}
x86_l_31ad:
	/* 0x31ad: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_31b0:
	/* 0x31b0: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_31b6:
	/* 0x31b6: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_31bb:
	/* 0x31bb: jmp    3204 <generic_retkprobe_filter_arg+0x3204> */
	goto x86_l_3204;
x86_l_31bd:
	/* 0x31bd: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31c2:
	/* 0x31c2: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_31c4:
	/* 0x31c4: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_31ca:
	/* 0x31ca: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_31cd:
	/* 0x31cd: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_31d3:
	/* 0x31d3: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_31d8:
	/* 0x31d8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_31db:
	/* 0x31db: jle    3333 <generic_retkprobe_filter_arg+0x3333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13107ULL;
	}
x86_l_31e1:
	/* 0x31e1: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_31e4:
	/* 0x31e4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_31e7:
	/* 0x31e7: jb     335e <generic_retkprobe_filter_arg+0x335e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13150ULL;
	}
x86_l_31ed:
	/* 0x31ed: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_31f0:
	/* 0x31f0: je     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 624ULL;
	}
x86_l_31f6:
	/* 0x31f6: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_31f9:
	/* 0x31f9: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_31ff:
	/* 0x31ff: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3204:
	/* 0x3204: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_3206:
	/* 0x3206: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_320c:
	/* 0x320c: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	return 13442ULL;
x86_l_3211:
	/* 0x3211: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_3214:
	/* 0x3214: je     33e2 <generic_retkprobe_filter_arg+0x33e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13282ULL;
	}
x86_l_321a:
	/* 0x321a: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_321d:
	/* 0x321d: je     33b8 <generic_retkprobe_filter_arg+0x33b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13240ULL;
	}
x86_l_3223:
	/* 0x3223: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_3226:
	/* 0x3226: jne    3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13331ULL;
	}
x86_l_322c:
	/* 0x322c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3231:
	/* 0x3231: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_3238:
	/* 0x3238: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	return 13294ULL;
x86_l_323d:
	/* 0x323d: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3241:
	/* 0x3241: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_3247:
	/* 0x3247: jmp    3253 <generic_retkprobe_filter_arg+0x3253> */
	goto x86_l_3253;
x86_l_3249:
	/* 0x3249: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_324d:
	/* 0x324d: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_3253:
	/* 0x3253: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_3256:
	/* 0x3256: jb     3482 <generic_retkprobe_filter_arg+0x3482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13442ULL;
	}
x86_l_325c:
	/* 0x325c: mov    edx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3261:
	/* 0x3261: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3264:
	/* 0x3264: jle    328f <generic_retkprobe_filter_arg+0x328f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_328f;
	}
x86_l_3266:
	/* 0x3266: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3269:
	/* 0x3269: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_326c:
	/* 0x326c: jb     32c3 <generic_retkprobe_filter_arg+0x32c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_32c3;
	}
x86_l_326e:
	/* 0x326e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3271:
	/* 0x3271: je     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 624ULL;
	}
x86_l_3277:
	/* 0x3277: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_327a:
	/* 0x327a: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_3280:
	/* 0x3280: test   DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3284:
	/* 0x3284: jne    270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 624ULL;
	}
x86_l_328a:
	/* 0x328a: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	return 13442ULL;
x86_l_328f:
	/* 0x328f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3292:
	/* 0x3292: je     32d2 <generic_retkprobe_filter_arg+0x32d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32d2;
	}
x86_l_3294:
	/* 0x3294: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3297:
	/* 0x3297: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_329d:
	/* 0x329d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_32a0:
	/* 0x32a0: ja     346c <generic_retkprobe_filter_arg+0x346c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13420ULL;
	}
x86_l_32a6:
	/* 0x32a6: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_32ab:
	/* 0x32ab: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_32ae:
	/* 0x32ae: jae    346c <generic_retkprobe_filter_arg+0x346c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13420ULL;
	}
x86_l_32b4:
	/* 0x32b4: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b8:
	/* 0x32b8: jl     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 624ULL;
	}
x86_l_32be:
	/* 0x32be: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	return 13442ULL;
x86_l_32c3:
	/* 0x32c3: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32c7:
	/* 0x32c7: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_32cd:
	/* 0x32cd: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	return 13442ULL;
x86_l_32d2:
	/* 0x32d2: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_32d5:
	/* 0x32d5: ja     3478 <generic_retkprobe_filter_arg+0x3478> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13432ULL;
	}
x86_l_32db:
	/* 0x32db: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_32e0:
	/* 0x32e0: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_32e3:
	/* 0x32e3: jae    3478 <generic_retkprobe_filter_arg+0x3478> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13432ULL;
	}
x86_l_32e9:
	/* 0x32e9: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32ed:
	/* 0x32ed: jg     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 624ULL;
	}
x86_l_32f3:
	/* 0x32f3: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	return 13442ULL;
	return 13048ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13048ULL: goto x86_l_32f8;
	case 13050ULL: goto x86_l_32fa;
	case 13056ULL: goto x86_l_3300;
	case 13059ULL: goto x86_l_3303;
	case 13065ULL: goto x86_l_3309;
	case 13070ULL: goto x86_l_330e;
	case 13077ULL: goto x86_l_3315;
	case 13082ULL: goto x86_l_331a;
	case 13085ULL: goto x86_l_331d;
	case 13091ULL: goto x86_l_3323;
	case 13094ULL: goto x86_l_3326;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13107ULL: goto x86_l_3333;
	case 13110ULL: goto x86_l_3336;
	case 13116ULL: goto x86_l_333c;
	case 13119ULL: goto x86_l_333f;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13132ULL: goto x86_l_334c;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13150ULL: goto x86_l_335e;
	case 13155ULL: goto x86_l_3363;
	case 13157ULL: goto x86_l_3365;
	case 13163ULL: goto x86_l_336b;
	case 13168ULL: goto x86_l_3370;
	case 13172ULL: goto x86_l_3374;
	case 13178ULL: goto x86_l_337a;
	case 13183ULL: goto x86_l_337f;
	case 13187ULL: goto x86_l_3383;
	case 13193ULL: goto x86_l_3389;
	case 13198ULL: goto x86_l_338e;
	case 13203ULL: goto x86_l_3393;
	case 13210ULL: goto x86_l_339a;
	case 13212ULL: goto x86_l_339c;
	case 13217ULL: goto x86_l_33a1;
	case 13224ULL: goto x86_l_33a8;
	case 13226ULL: goto x86_l_33aa;
	case 13231ULL: goto x86_l_33af;
	case 13238ULL: goto x86_l_33b6;
	case 13240ULL: goto x86_l_33b8;
	case 13245ULL: goto x86_l_33bd;
	case 13252ULL: goto x86_l_33c4;
	case 13254ULL: goto x86_l_33c6;
	case 13259ULL: goto x86_l_33cb;
	case 13266ULL: goto x86_l_33d2;
	case 13268ULL: goto x86_l_33d4;
	case 13273ULL: goto x86_l_33d9;
	case 13280ULL: goto x86_l_33e0;
	case 13282ULL: goto x86_l_33e2;
	case 13287ULL: goto x86_l_33e7;
	case 13294ULL: goto x86_l_33ee;
	case 13299ULL: goto x86_l_33f3;
	case 13301ULL: goto x86_l_33f5;
	case 13304ULL: goto x86_l_33f8;
	case 13306ULL: goto x86_l_33fa;
	case 13311ULL: goto x86_l_33ff;
	case 13314ULL: goto x86_l_3402;
	case 13319ULL: goto x86_l_3407;
	case 13321ULL: goto x86_l_3409;
	case 13323ULL: goto x86_l_340b;
	case 13326ULL: goto x86_l_340e;
	case 13329ULL: goto x86_l_3411;
	case 13331ULL: goto x86_l_3413;
	case 13333ULL: goto x86_l_3415;
	case 13337ULL: goto x86_l_3419;
	case 13342ULL: goto x86_l_341e;
	case 13347ULL: goto x86_l_3423;
	case 13352ULL: goto x86_l_3428;
	case 13356ULL: goto x86_l_342c;
	case 13362ULL: goto x86_l_3432;
	case 13372ULL: goto x86_l_343c;
	case 13376ULL: goto x86_l_3440;
	case 13382ULL: goto x86_l_3446;
	case 13384ULL: goto x86_l_3448;
	case 13387ULL: goto x86_l_344b;
	case 13390ULL: goto x86_l_344e;
	case 13393ULL: goto x86_l_3451;
	case 13398ULL: goto x86_l_3456;
	case 13403ULL: goto x86_l_345b;
	case 13405ULL: goto x86_l_345d;
	case 13410ULL: goto x86_l_3462;
	case 13412ULL: goto x86_l_3464;
	case 13418ULL: goto x86_l_346a;
	case 13420ULL: goto x86_l_346c;
	case 13424ULL: goto x86_l_3470;
	case 13430ULL: goto x86_l_3476;
	case 13432ULL: goto x86_l_3478;
	case 13436ULL: goto x86_l_347c;
	case 13442ULL: goto x86_l_3482;
	case 13445ULL: goto x86_l_3485;
	case 13448ULL: goto x86_l_3488;
	case 13454ULL: goto x86_l_348e;
	case 13459ULL: goto x86_l_3493;
	case 13464ULL: goto x86_l_3498;
	case 13467ULL: goto x86_l_349b;
	case 13469ULL: goto x86_l_349d;
	case 13470ULL: goto x86_l_349e;
	case 13472ULL: goto x86_l_34a0;
	case 13474ULL: goto x86_l_34a2;
	case 13477ULL: goto x86_l_34a5;
	case 13480ULL: goto x86_l_34a8;
	case 13483ULL: goto x86_l_34ab;
	case 13485ULL: goto x86_l_34ad;
	case 13488ULL: goto x86_l_34b0;
	case 13492ULL: goto x86_l_34b4;
	case 13495ULL: goto x86_l_34b7;
	case 13497ULL: goto x86_l_34b9;
	case 13502ULL: goto x86_l_34be;
	case 13505ULL: goto x86_l_34c1;
	case 13507ULL: goto x86_l_34c3;
	case 13512ULL: goto x86_l_34c8;
	case 13516ULL: goto x86_l_34cc;
	case 13519ULL: goto x86_l_34cf;
	case 13522ULL: goto x86_l_34d2;
	case 13526ULL: goto x86_l_34d6;
	case 13530ULL: goto x86_l_34da;
	case 13534ULL: goto x86_l_34de;
	case 13537ULL: goto x86_l_34e1;
	case 13541ULL: goto x86_l_34e5;
	case 13545ULL: goto x86_l_34e9;
	case 13549ULL: goto x86_l_34ed;
	case 13552ULL: goto x86_l_34f0;
	case 13554ULL: goto x86_l_34f2;
	case 13558ULL: goto x86_l_34f6;
	case 13562ULL: goto x86_l_34fa;
	case 13565ULL: goto x86_l_34fd;
	case 13567ULL: goto x86_l_34ff;
	case 13569ULL: goto x86_l_3501;
	case 13571ULL: goto x86_l_3503;
	case 13572ULL: goto x86_l_3504;
	default: return 0xffffffffffffffffULL;
	}
x86_l_32f8:
	/* 0x32f8: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_32fa:
	/* 0x32fa: je     338e <generic_retkprobe_filter_arg+0x338e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_338e;
	}
x86_l_3300:
	/* 0x3300: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3303:
	/* 0x3303: jne    3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3413;
	}
x86_l_3309:
	/* 0x3309: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_330e:
	/* 0x330e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3315:
	/* 0x3315: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	goto x86_l_33ee;
x86_l_331a:
	/* 0x331a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_331d:
	/* 0x331d: je     3456 <generic_retkprobe_filter_arg+0x3456> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3456;
	}
x86_l_3323:
	/* 0x3323: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3326:
	/* 0x3326: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_332c:
	/* 0x332c: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3331:
	/* 0x3331: jmp    334a <generic_retkprobe_filter_arg+0x334a> */
	goto x86_l_334a;
x86_l_3333:
	/* 0x3333: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3336:
	/* 0x3336: je     345d <generic_retkprobe_filter_arg+0x345d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345d;
	}
x86_l_333c:
	/* 0x333c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_333f:
	/* 0x333f: jne    c1 <generic_retkprobe_filter_arg+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 193ULL;
	}
x86_l_3345:
	/* 0x3345: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_334a:
	/* 0x334a: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_334c:
	/* 0x334c: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_3352:
	/* 0x3352: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	goto x86_l_3482;
x86_l_3357:
	/* 0x3357: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_335c:
	/* 0x335c: jmp    3363 <generic_retkprobe_filter_arg+0x3363> */
	goto x86_l_3363;
x86_l_335e:
	/* 0x335e: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3363:
	/* 0x3363: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_3365:
	/* 0x3365: je     257 <generic_retkprobe_filter_arg+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 599ULL;
	}
x86_l_336b:
	/* 0x336b: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	goto x86_l_3482;
x86_l_3370:
	/* 0x3370: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3374:
	/* 0x3374: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_337a:
	/* 0x337a: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	goto x86_l_3482;
x86_l_337f:
	/* 0x337f: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3383:
	/* 0x3383: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_3389:
	/* 0x3389: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	goto x86_l_3482;
x86_l_338e:
	/* 0x338e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3393:
	/* 0x3393: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_339a:
	/* 0x339a: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	goto x86_l_33ee;
x86_l_339c:
	/* 0x339c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33a1:
	/* 0x33a1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_33a8:
	/* 0x33a8: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	goto x86_l_33ee;
x86_l_33aa:
	/* 0x33aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33af:
	/* 0x33af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_33b6:
	/* 0x33b6: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	goto x86_l_33ee;
x86_l_33b8:
	/* 0x33b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33bd:
	/* 0x33bd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_33c4:
	/* 0x33c4: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	goto x86_l_33ee;
x86_l_33c6:
	/* 0x33c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33cb:
	/* 0x33cb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_33d2:
	/* 0x33d2: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	goto x86_l_33ee;
x86_l_33d4:
	/* 0x33d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33d9:
	/* 0x33d9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_33e0:
	/* 0x33e0: jmp    33ee <generic_retkprobe_filter_arg+0x33ee> */
	goto x86_l_33ee;
x86_l_33e2:
	/* 0x33e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33e7:
	/* 0x33e7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_33ee:
	/* 0x33ee: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33f3:
	/* 0x33f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f5:
	/* 0x33f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33f8:
	/* 0x33f8: je     3413 <generic_retkprobe_filter_arg+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3413;
	}
x86_l_33fa:
	/* 0x33fa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_33ff:
	/* 0x33ff: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3402:
	/* 0x3402: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3407:
	/* 0x3407: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3409:
	/* 0x3409: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_340b:
	/* 0x340b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_340e:
	/* 0x340e: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_3411:
	/* 0x3411: jmp    3415 <generic_retkprobe_filter_arg+0x3415> */
	goto x86_l_3415;
x86_l_3413:
	/* 0x3413: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3415:
	/* 0x3415: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3419:
	/* 0x3419: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_341e:
	/* 0x341e: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3423:
	/* 0x3423: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3428:
	/* 0x3428: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_342c:
	/* 0x342c: ja     25f <generic_retkprobe_filter_arg+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 607ULL;
	}
x86_l_3432:
	/* 0x3432: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_343c:
	/* 0x343c: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3440:
	/* 0x3440: jae    25f <generic_retkprobe_filter_arg+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 607ULL;
	}
x86_l_3446:
	/* 0x3446: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3448:
	/* 0x3448: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_344b:
	/* 0x344b: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_344e:
	/* 0x344e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3451:
	/* 0x3451: jmp    25f <generic_retkprobe_filter_arg+0x25f> */
	return 607ULL;
x86_l_3456:
	/* 0x3456: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_345b:
	/* 0x345b: jmp    3462 <generic_retkprobe_filter_arg+0x3462> */
	goto x86_l_3462;
x86_l_345d:
	/* 0x345d: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3462:
	/* 0x3462: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_3464:
	/* 0x3464: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_346a:
	/* 0x346a: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	goto x86_l_3482;
x86_l_346c:
	/* 0x346c: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3470:
	/* 0x3470: jb     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 624ULL;
	}
x86_l_3476:
	/* 0x3476: jmp    3482 <generic_retkprobe_filter_arg+0x3482> */
	goto x86_l_3482;
x86_l_3478:
	/* 0x3478: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_347c:
	/* 0x347c: ja     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 624ULL;
	}
x86_l_3482:
	/* 0x3482: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_3485:
	/* 0x3485: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3488:
	/* 0x3488: je     270 <generic_retkprobe_filter_arg+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 624ULL;
	}
x86_l_348e:
	/* 0x348e: jmp    c1 <generic_retkprobe_filter_arg+0xc1> */
	return 193ULL;
x86_l_3493:
	/* 0x3493: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_3498:
	/* 0x3498: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_349b:
	/* 0x349b: je     3504 <native_bpf_strncasestr+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3504;
	}
x86_l_349d:
	/* 0x349d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_349e:
	/* 0x349e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34a0:
	/* 0x34a0: jmp    34ad <native_bpf_strncasestr+0x1a> */
	goto x86_l_34ad;
x86_l_34a2:
	/* 0x34a2: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_34a5:
	/* 0x34a5: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_34a8:
	/* 0x34a8: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_34ab:
	/* 0x34ab: je     3503 <native_bpf_strncasestr+0x70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3503;
	}
x86_l_34ad:
	/* 0x34ad: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34b0:
	/* 0x34b0: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_34b4:
	/* 0x34b4: cmp    r9,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RDX, X86_WIDTH_64);
x86_l_34b7:
	/* 0x34b7: jae    34a2 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_34a2;
	}
x86_l_34b9:
	/* 0x34b9: movsx  r9d,BYTE PTR [rsi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_34be:
	/* 0x34be: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_34c1:
	/* 0x34c1: je     3501 <native_bpf_strncasestr+0x6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3501;
	}
x86_l_34c3:
	/* 0x34c3: movsx  r10d,BYTE PTR [rdi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_34c8:
	/* 0x34c8: lea    r11d,[r10-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_34cc:
	/* 0x34cc: mov    ebx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R10, X86_WIDTH_32);
x86_l_34cf:
	/* 0x34cf: or     ebx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_34d2:
	/* 0x34d2: cmp    r11d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 26ULL);
x86_l_34d6:
	/* 0x34d6: cmovae ebx,r10d */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R10, X86_WIDTH_32, X86_CC_AE);
x86_l_34da:
	/* 0x34da: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_34de:
	/* 0x34de: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_34e1:
	/* 0x34e1: or     r11d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_34e5:
	/* 0x34e5: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_34e9:
	/* 0x34e9: cmovae r11d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_34ed:
	/* 0x34ed: cmp    ebx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R11, X86_WIDTH_32);
x86_l_34f0:
	/* 0x34f0: jne    34a2 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_34a2;
	}
x86_l_34f2:
	/* 0x34f2: lea    r9,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_34f6:
	/* 0x34f6: cmp    r8,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 99ULL);
x86_l_34fa:
	/* 0x34fa: mov    r8,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_64);
x86_l_34fd:
	/* 0x34fd: jb     34b0 <native_bpf_strncasestr+0x1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_34b0;
	}
x86_l_34ff:
	/* 0x34ff: jmp    34a2 <native_bpf_strncasestr+0xf> */
	goto x86_l_34a2;
x86_l_3501:
	/* 0x3501: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3503:
	/* 0x3503: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3504:
	/* 0x3504: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12820U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1728ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1731ULL && __x86_pc <= 3386ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3389ULL && __x86_pc <= 4949ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4952ULL && __x86_pc <= 6593ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6596ULL && __x86_pc <= 8149ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8151ULL && __x86_pc <= 9737ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9741ULL && __x86_pc <= 11382ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11386ULL && __x86_pc <= 13043ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13048ULL && __x86_pc <= 13572ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

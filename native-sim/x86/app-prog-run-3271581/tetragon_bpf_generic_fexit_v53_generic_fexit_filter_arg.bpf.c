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

static __noinline __u64 tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_0(
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
	case 71ULL: goto x86_l_47;
	case 78ULL: goto x86_l_4e;
	case 85ULL: goto x86_l_55;
	case 90ULL: goto x86_l_5a;
	case 92ULL: goto x86_l_5c;
	case 95ULL: goto x86_l_5f;
	case 101ULL: goto x86_l_65;
	case 109ULL: goto x86_l_6d;
	case 115ULL: goto x86_l_73;
	case 118ULL: goto x86_l_76;
	case 120ULL: goto x86_l_78;
	case 123ULL: goto x86_l_7b;
	case 132ULL: goto x86_l_84;
	case 134ULL: goto x86_l_86;
	case 136ULL: goto x86_l_88;
	case 140ULL: goto x86_l_8c;
	case 144ULL: goto x86_l_90;
	case 148ULL: goto x86_l_94;
	case 151ULL: goto x86_l_97;
	case 158ULL: goto x86_l_9e;
	case 163ULL: goto x86_l_a3;
	case 165ULL: goto x86_l_a5;
	case 169ULL: goto x86_l_a9;
	case 175ULL: goto x86_l_af;
	case 178ULL: goto x86_l_b2;
	case 184ULL: goto x86_l_b8;
	case 187ULL: goto x86_l_bb;
	case 189ULL: goto x86_l_bd;
	case 192ULL: goto x86_l_c0;
	case 198ULL: goto x86_l_c6;
	case 200ULL: goto x86_l_c8;
	case 206ULL: goto x86_l_ce;
	case 209ULL: goto x86_l_d1;
	case 215ULL: goto x86_l_d7;
	case 217ULL: goto x86_l_d9;
	case 220ULL: goto x86_l_dc;
	case 226ULL: goto x86_l_e2;
	case 229ULL: goto x86_l_e5;
	case 235ULL: goto x86_l_eb;
	case 238ULL: goto x86_l_ee;
	case 244ULL: goto x86_l_f4;
	case 247ULL: goto x86_l_f7;
	case 253ULL: goto x86_l_fd;
	case 255ULL: goto x86_l_ff;
	case 260ULL: goto x86_l_104;
	case 264ULL: goto x86_l_108;
	case 272ULL: goto x86_l_110;
	case 275ULL: goto x86_l_113;
	case 283ULL: goto x86_l_11b;
	case 288ULL: goto x86_l_120;
	case 296ULL: goto x86_l_128;
	case 301ULL: goto x86_l_12d;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 316ULL: goto x86_l_13c;
	case 321ULL: goto x86_l_141;
	case 328ULL: goto x86_l_148;
	case 335ULL: goto x86_l_14f;
	case 340ULL: goto x86_l_154;
	case 345ULL: goto x86_l_159;
	case 348ULL: goto x86_l_15c;
	case 353ULL: goto x86_l_161;
	case 355ULL: goto x86_l_163;
	case 362ULL: goto x86_l_16a;
	case 367ULL: goto x86_l_16f;
	case 372ULL: goto x86_l_174;
	case 375ULL: goto x86_l_177;
	case 380ULL: goto x86_l_17c;
	case 382ULL: goto x86_l_17e;
	case 384ULL: goto x86_l_180;
	case 391ULL: goto x86_l_187;
	case 392ULL: goto x86_l_188;
	case 394ULL: goto x86_l_18a;
	case 396ULL: goto x86_l_18c;
	case 398ULL: goto x86_l_18e;
	case 400ULL: goto x86_l_190;
	case 401ULL: goto x86_l_191;
	case 406ULL: goto x86_l_196;
	case 408ULL: goto x86_l_198;
	case 416ULL: goto x86_l_1a0;
	case 418ULL: goto x86_l_1a2;
	case 423ULL: goto x86_l_1a7;
	case 431ULL: goto x86_l_1af;
	case 433ULL: goto x86_l_1b1;
	case 438ULL: goto x86_l_1b6;
	case 446ULL: goto x86_l_1be;
	case 448ULL: goto x86_l_1c0;
	case 453ULL: goto x86_l_1c5;
	case 461ULL: goto x86_l_1cd;
	case 463ULL: goto x86_l_1cf;
	case 468ULL: goto x86_l_1d4;
	case 476ULL: goto x86_l_1dc;
	case 478ULL: goto x86_l_1de;
	case 483ULL: goto x86_l_1e3;
	case 491ULL: goto x86_l_1eb;
	case 493ULL: goto x86_l_1ed;
	case 500ULL: goto x86_l_1f4;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 517ULL: goto x86_l_205;
	case 520ULL: goto x86_l_208;
	case 525ULL: goto x86_l_20d;
	case 527ULL: goto x86_l_20f;
	case 531ULL: goto x86_l_213;
	case 536ULL: goto x86_l_218;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 548ULL: goto x86_l_224;
	case 555ULL: goto x86_l_22b;
	case 560ULL: goto x86_l_230;
	case 565ULL: goto x86_l_235;
	case 567ULL: goto x86_l_237;
	case 570ULL: goto x86_l_23a;
	case 576ULL: goto x86_l_240;
	case 583ULL: goto x86_l_247;
	case 588ULL: goto x86_l_24c;
	case 593ULL: goto x86_l_251;
	case 595ULL: goto x86_l_253;
	case 600ULL: goto x86_l_258;
	case 602ULL: goto x86_l_25a;
	case 607ULL: goto x86_l_25f;
	case 612ULL: goto x86_l_264;
	case 617ULL: goto x86_l_269;
	case 622ULL: goto x86_l_26e;
	case 625ULL: goto x86_l_271;
	case 633ULL: goto x86_l_279;
	case 639ULL: goto x86_l_27f;
	case 642ULL: goto x86_l_282;
	case 646ULL: goto x86_l_286;
	case 652ULL: goto x86_l_28c;
	case 660ULL: goto x86_l_294;
	case 665ULL: goto x86_l_299;
	case 672ULL: goto x86_l_2a0;
	case 678ULL: goto x86_l_2a6;
	case 681ULL: goto x86_l_2a9;
	case 688ULL: goto x86_l_2b0;
	case 693ULL: goto x86_l_2b5;
	case 696ULL: goto x86_l_2b8;
	case 702ULL: goto x86_l_2be;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 712ULL: goto x86_l_2c8;
	case 718ULL: goto x86_l_2ce;
	case 727ULL: goto x86_l_2d7;
	case 733ULL: goto x86_l_2dd;
	case 741ULL: goto x86_l_2e5;
	case 747ULL: goto x86_l_2eb;
	case 751ULL: goto x86_l_2ef;
	case 758ULL: goto x86_l_2f6;
	case 762ULL: goto x86_l_2fa;
	case 765ULL: goto x86_l_2fd;
	case 767ULL: goto x86_l_2ff;
	case 770ULL: goto x86_l_302;
	case 773ULL: goto x86_l_305;
	case 779ULL: goto x86_l_30b;
	case 782ULL: goto x86_l_30e;
	case 784ULL: goto x86_l_310;
	case 786ULL: goto x86_l_312;
	case 796ULL: goto x86_l_31c;
	case 800ULL: goto x86_l_320;
	case 802ULL: goto x86_l_322;
	case 812ULL: goto x86_l_32c;
	case 816ULL: goto x86_l_330;
	case 822ULL: goto x86_l_336;
	case 832ULL: goto x86_l_340;
	case 836ULL: goto x86_l_344;
	case 842ULL: goto x86_l_34a;
	case 845ULL: goto x86_l_34d;
	case 851ULL: goto x86_l_353;
	case 855ULL: goto x86_l_357;
	case 857ULL: goto x86_l_359;
	case 860ULL: goto x86_l_35c;
	case 862ULL: goto x86_l_35e;
	case 865ULL: goto x86_l_361;
	case 871ULL: goto x86_l_367;
	case 874ULL: goto x86_l_36a;
	case 880ULL: goto x86_l_370;
	case 883ULL: goto x86_l_373;
	case 889ULL: goto x86_l_379;
	case 892ULL: goto x86_l_37c;
	case 898ULL: goto x86_l_382;
	case 901ULL: goto x86_l_385;
	case 904ULL: goto x86_l_388;
	case 908ULL: goto x86_l_38c;
	case 911ULL: goto x86_l_38f;
	case 917ULL: goto x86_l_395;
	case 920ULL: goto x86_l_398;
	case 923ULL: goto x86_l_39b;
	case 929ULL: goto x86_l_3a1;
	case 932ULL: goto x86_l_3a4;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 946ULL: goto x86_l_3b2;
	case 952ULL: goto x86_l_3b8;
	case 957ULL: goto x86_l_3bd;
	case 960ULL: goto x86_l_3c0;
	case 963ULL: goto x86_l_3c3;
	case 969ULL: goto x86_l_3c9;
	case 972ULL: goto x86_l_3cc;
	case 975ULL: goto x86_l_3cf;
	case 981ULL: goto x86_l_3d5;
	case 986ULL: goto x86_l_3da;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 994ULL: goto x86_l_3e2;
	case 997ULL: goto x86_l_3e5;
	case 999ULL: goto x86_l_3e7;
	case 1001ULL: goto x86_l_3e9;
	case 1007ULL: goto x86_l_3ef;
	case 1010ULL: goto x86_l_3f2;
	case 1015ULL: goto x86_l_3f7;
	case 1021ULL: goto x86_l_3fd;
	case 1023ULL: goto x86_l_3ff;
	case 1028ULL: goto x86_l_404;
	case 1032ULL: goto x86_l_408;
	case 1038ULL: goto x86_l_40e;
	case 1043ULL: goto x86_l_413;
	case 1047ULL: goto x86_l_417;
	case 1053ULL: goto x86_l_41d;
	case 1063ULL: goto x86_l_427;
	case 1067ULL: goto x86_l_42b;
	case 1073ULL: goto x86_l_431;
	case 1080ULL: goto x86_l_438;
	case 1086ULL: goto x86_l_43e;
	case 1092ULL: goto x86_l_444;
	case 1096ULL: goto x86_l_448;
	case 1100ULL: goto x86_l_44c;
	case 1105ULL: goto x86_l_451;
	case 1110ULL: goto x86_l_456;
	case 1115ULL: goto x86_l_45b;
	case 1117ULL: goto x86_l_45d;
	case 1121ULL: goto x86_l_461;
	case 1125ULL: goto x86_l_465;
	case 1130ULL: goto x86_l_46a;
	case 1132ULL: goto x86_l_46c;
	case 1136ULL: goto x86_l_470;
	case 1138ULL: goto x86_l_472;
	case 1144ULL: goto x86_l_478;
	case 1149ULL: goto x86_l_47d;
	case 1154ULL: goto x86_l_482;
	case 1159ULL: goto x86_l_487;
	case 1161ULL: goto x86_l_489;
	case 1167ULL: goto x86_l_48f;
	case 1171ULL: goto x86_l_493;
	case 1174ULL: goto x86_l_496;
	case 1179ULL: goto x86_l_49b;
	case 1184ULL: goto x86_l_4a0;
	case 1189ULL: goto x86_l_4a5;
	case 1195ULL: goto x86_l_4ab;
	case 1199ULL: goto x86_l_4af;
	case 1201ULL: goto x86_l_4b1;
	case 1207ULL: goto x86_l_4b7;
	case 1209ULL: goto x86_l_4b9;
	case 1215ULL: goto x86_l_4bf;
	case 1218ULL: goto x86_l_4c2;
	case 1224ULL: goto x86_l_4c8;
	case 1228ULL: goto x86_l_4cc;
	case 1230ULL: goto x86_l_4ce;
	case 1236ULL: goto x86_l_4d4;
	case 1238ULL: goto x86_l_4d6;
	case 1244ULL: goto x86_l_4dc;
	case 1247ULL: goto x86_l_4df;
	case 1253ULL: goto x86_l_4e5;
	case 1257ULL: goto x86_l_4e9;
	case 1259ULL: goto x86_l_4eb;
	case 1265ULL: goto x86_l_4f1;
	case 1267ULL: goto x86_l_4f3;
	case 1269ULL: goto x86_l_4f5;
	case 1272ULL: goto x86_l_4f8;
	case 1277ULL: goto x86_l_4fd;
	case 1280ULL: goto x86_l_500;
	case 1282ULL: goto x86_l_502;
	case 1285ULL: goto x86_l_505;
	case 1291ULL: goto x86_l_50b;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1301ULL: goto x86_l_515;
	case 1304ULL: goto x86_l_518;
	case 1310ULL: goto x86_l_51e;
	case 1313ULL: goto x86_l_521;
	case 1316ULL: goto x86_l_524;
	case 1322ULL: goto x86_l_52a;
	case 1327ULL: goto x86_l_52f;
	case 1330ULL: goto x86_l_532;
	case 1336ULL: goto x86_l_538;
	case 1341ULL: goto x86_l_53d;
	case 1344ULL: goto x86_l_540;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1358ULL: goto x86_l_54e;
	case 1364ULL: goto x86_l_554;
	case 1367ULL: goto x86_l_557;
	case 1373ULL: goto x86_l_55d;
	case 1375ULL: goto x86_l_55f;
	case 1385ULL: goto x86_l_569;
	case 1389ULL: goto x86_l_56d;
	case 1395ULL: goto x86_l_573;
	case 1400ULL: goto x86_l_578;
	case 1404ULL: goto x86_l_57c;
	case 1410ULL: goto x86_l_582;
	case 1420ULL: goto x86_l_58c;
	case 1424ULL: goto x86_l_590;
	case 1430ULL: goto x86_l_596;
	case 1433ULL: goto x86_l_599;
	case 1439ULL: goto x86_l_59f;
	case 1441ULL: goto x86_l_5a1;
	case 1446ULL: goto x86_l_5a6;
	case 1450ULL: goto x86_l_5aa;
	case 1456ULL: goto x86_l_5b0;
	case 1460ULL: goto x86_l_5b4;
	case 1463ULL: goto x86_l_5b7;
	case 1469ULL: goto x86_l_5bd;
	case 1472ULL: goto x86_l_5c0;
	case 1475ULL: goto x86_l_5c3;
	case 1481ULL: goto x86_l_5c9;
	case 1484ULL: goto x86_l_5cc;
	case 1488ULL: goto x86_l_5d0;
	case 1490ULL: goto x86_l_5d2;
	case 1496ULL: goto x86_l_5d8;
	case 1501ULL: goto x86_l_5dd;
	case 1504ULL: goto x86_l_5e0;
	case 1507ULL: goto x86_l_5e3;
	case 1513ULL: goto x86_l_5e9;
	case 1516ULL: goto x86_l_5ec;
	case 1518ULL: goto x86_l_5ee;
	case 1521ULL: goto x86_l_5f1;
	case 1523ULL: goto x86_l_5f3;
	case 1528ULL: goto x86_l_5f8;
	case 1531ULL: goto x86_l_5fb;
	case 1537ULL: goto x86_l_601;
	case 1540ULL: goto x86_l_604;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1552ULL: goto x86_l_610;
	case 1558ULL: goto x86_l_616;
	case 1561ULL: goto x86_l_619;
	case 1567ULL: goto x86_l_61f;
	case 1572ULL: goto x86_l_624;
	case 1575ULL: goto x86_l_627;
	case 1578ULL: goto x86_l_62a;
	case 1584ULL: goto x86_l_630;
	case 1587ULL: goto x86_l_633;
	case 1593ULL: goto x86_l_639;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1604ULL: goto x86_l_644;
	case 1606ULL: goto x86_l_646;
	case 1610ULL: goto x86_l_64a;
	case 1613ULL: goto x86_l_64d;
	case 1619ULL: goto x86_l_653;
	case 1622ULL: goto x86_l_656;
	case 1625ULL: goto x86_l_659;
	case 1631ULL: goto x86_l_65f;
	case 1634ULL: goto x86_l_662;
	case 1640ULL: goto x86_l_668;
	case 1645ULL: goto x86_l_66d;
	case 1650ULL: goto x86_l_672;
	case 1654ULL: goto x86_l_676;
	case 1660ULL: goto x86_l_67c;
	case 1670ULL: goto x86_l_686;
	case 1674ULL: goto x86_l_68a;
	case 1680ULL: goto x86_l_690;
	case 1683ULL: goto x86_l_693;
	case 1689ULL: goto x86_l_699;
	case 1693ULL: goto x86_l_69d;
	case 1697ULL: goto x86_l_6a1;
	case 1700ULL: goto x86_l_6a4;
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
	/* 0xa: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_11:
	/* 0x11: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
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
	/* 0x38: je     17e <generic_fexit_filter_arg+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17e;
	}
x86_l_3e:
	/* 0x3e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    ebx,DWORD PTR [rax+0x5f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_47:
	/* 0x47: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_4e:
	/* 0x4e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_55:
	/* 0x55: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a:
	/* 0x5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c:
	/* 0x5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f:
	/* 0x5f: je     163 <generic_fexit_filter_arg+0x163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_163;
	}
x86_l_65:
	/* 0x65: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_6d:
	/* 0x6d: je     163 <generic_fexit_filter_arg+0x163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_163;
	}
x86_l_73:
	/* 0x73: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_76:
	/* 0x76: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_78:
	/* 0x78: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_7b:
	/* 0x7b: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_84:
	/* 0x84: je     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b8;
	}
x86_l_86:
	/* 0x86: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_88:
	/* 0x88: mov    ecx,DWORD PTR [rdi+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_8c:
	/* 0x8c: lea    r11,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_90:
	/* 0x90: add    r11,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_94:
	/* 0x94: mov    r9d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R11, X86_WIDTH_32);
x86_l_97:
	/* 0x97: and    r9d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_9e:
	/* 0x9e: cmp    DWORD PTR [rdi+r9*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 25ULL);
x86_l_a3:
	/* 0xa3: jae    104 <generic_fexit_filter_arg+0x104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_104;
	}
x86_l_a5:
	/* 0xa5: cmp    r9,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 1ULL);
x86_l_a9:
	/* 0xa9: je     163 <generic_fexit_filter_arg+0x163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_163;
	}
x86_l_af:
	/* 0xaf: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_b2:
	/* 0xb2: jne    141 <generic_fexit_filter_arg+0x141> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_141;
	}
x86_l_b8:
	/* 0xb8: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_bb:
	/* 0xbb: jg     d9 <generic_fexit_filter_arg+0xd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d9;
	}
x86_l_bd:
	/* 0xbd: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_c0:
	/* 0xc0: je     196 <generic_fexit_filter_arg+0x196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_196;
	}
x86_l_c6:
	/* 0xc6: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_c8:
	/* 0xc8: je     1a2 <generic_fexit_filter_arg+0x1a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a2;
	}
x86_l_ce:
	/* 0xce: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_d1:
	/* 0xd1: je     1b1 <generic_fexit_filter_arg+0x1b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1;
	}
x86_l_d7:
	/* 0xd7: jmp    f4 <generic_fexit_filter_arg+0xf4> */
	goto x86_l_f4;
x86_l_d9:
	/* 0xd9: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_dc:
	/* 0xdc: je     1c0 <generic_fexit_filter_arg+0x1c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c0;
	}
x86_l_e2:
	/* 0xe2: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_e5:
	/* 0xe5: je     1cf <generic_fexit_filter_arg+0x1cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cf;
	}
x86_l_eb:
	/* 0xeb: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_ee:
	/* 0xee: je     1de <generic_fexit_filter_arg+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1de;
	}
x86_l_f4:
	/* 0xf4: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_f7:
	/* 0xf7: jg     20f <generic_fexit_filter_arg+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_20f;
	}
x86_l_fd:
	/* 0xfd: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_ff:
	/* 0xff: jmp    1ed <generic_fexit_filter_arg+0x1ed> */
	goto x86_l_1ed;
x86_l_104:
	/* 0x104: lea    rax,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_108:
	/* 0x108: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_110:
	/* 0x110: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_113:
	/* 0x113: lea    rax,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11b:
	/* 0x11b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_120:
	/* 0x120: mov    QWORD PTR [rsp+0xa8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_128:
	/* 0x128: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12d:
	/* 0x12d: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132:
	/* 0x132: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_137:
	/* 0x137: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13c:
	/* 0x13c: jmp    28c <generic_fexit_filter_arg+0x28c> */
	goto x86_l_28c;
x86_l_141:
	/* 0x141: mov    DWORD PTR [r14+0x5f04],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_148:
	/* 0x148: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_14f:
	/* 0x14f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_154:
	/* 0x154: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_159:
	/* 0x159: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_15c:
	/* 0x15c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_161:
	/* 0x161: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163:
	/* 0x163: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_16a:
	/* 0x16a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_16f:
	/* 0x16f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_174:
	/* 0x174: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_177:
	/* 0x177: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_17c:
	/* 0x17c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e:
	/* 0x17e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_180:
	/* 0x180: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_187:
	/* 0x187: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_188:
	/* 0x188: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_18a:
	/* 0x18a: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_18c:
	/* 0x18c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_18e:
	/* 0x18e: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_190:
	/* 0x190: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_191:
	/* 0x191: jmp    3077 <native_bpf_strncasestr+0x72> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_196:
	/* 0x196: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_198:
	/* 0x198: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_1a0:
	/* 0x1a0: jne    1ed <generic_fexit_filter_arg+0x1ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ed;
	}
x86_l_1a2:
	/* 0x1a2: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1a7:
	/* 0x1a7: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_1af:
	/* 0x1af: jne    1ed <generic_fexit_filter_arg+0x1ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ed;
	}
x86_l_1b1:
	/* 0x1b1: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1b6:
	/* 0x1b6: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_1be:
	/* 0x1be: jne    1ed <generic_fexit_filter_arg+0x1ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ed;
	}
x86_l_1c0:
	/* 0x1c0: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1c5:
	/* 0x1c5: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_1cd:
	/* 0x1cd: jne    1ed <generic_fexit_filter_arg+0x1ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ed;
	}
x86_l_1cf:
	/* 0x1cf: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1d4:
	/* 0x1d4: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_1dc:
	/* 0x1dc: jne    1ed <generic_fexit_filter_arg+0x1ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ed;
	}
x86_l_1de:
	/* 0x1de: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1e3:
	/* 0x1e3: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_1eb:
	/* 0x1eb: je     20f <generic_fexit_filter_arg+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f;
	}
x86_l_1ed:
	/* 0x1ed: mov    DWORD PTR [r14+0x5f00],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_1f4:
	/* 0x1f4: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_1fb:
	/* 0x1fb: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_200:
	/* 0x200: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_205:
	/* 0x205: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_208:
	/* 0x208: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_20d:
	/* 0x20d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f:
	/* 0x20f: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_213:
	/* 0x213: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_218:
	/* 0x218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a:
	/* 0x21a: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21f:
	/* 0x21f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_224:
	/* 0x224: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_22b:
	/* 0x22b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_230:
	/* 0x230: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_235:
	/* 0x235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237:
	/* 0x237: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23a:
	/* 0x23a: je     17e <generic_fexit_filter_arg+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17e;
	}
x86_l_240:
	/* 0x240: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_247:
	/* 0x247: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_24c:
	/* 0x24c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_251:
	/* 0x251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253:
	/* 0x253: jmp    17e <generic_fexit_filter_arg+0x17e> */
	goto x86_l_17e;
x86_l_258:
	/* 0x258: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25a:
	/* 0x25a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25f:
	/* 0x25f: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_264:
	/* 0x264: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_269:
	/* 0x269: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26e:
	/* 0x26e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_271:
	/* 0x271: mov    rbx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_279:
	/* 0x279: je     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b8;
	}
x86_l_27f:
	/* 0x27f: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_282:
	/* 0x282: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_286:
	/* 0x286: je     a5 <generic_fexit_filter_arg+0xa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a5;
	}
x86_l_28c:
	/* 0x28c: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_294:
	/* 0x294: mov    r15d,DWORD PTR [rax+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_299:
	/* 0x299: test   r15d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_32, 1023ULL);
x86_l_2a0:
	/* 0x2a0: je     a5 <generic_fexit_filter_arg+0xa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a5;
	}
x86_l_2a6:
	/* 0x2a6: add    r15d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a9:
	/* 0x2a9: and    r15d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2b0:
	/* 0x2b0: mov    eax,DWORD PTR [rdi+r15*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_2b5:
	/* 0x2b5: cmp    eax,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2b8:
	/* 0x2b8: je     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b8;
	}
x86_l_2be:
	/* 0x2be: add    r15,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c1:
	/* 0x2c1: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c4:
	/* 0x2c4: cmp    rcx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4ULL);
x86_l_2c8:
	/* 0x2c8: ja     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b8;
	}
x86_l_2ce:
	/* 0x2ce: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_2d7:
	/* 0x2d7: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b8;
	}
x86_l_2dd:
	/* 0x2dd: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_2e5:
	/* 0x2e5: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2eb:
	/* 0x2eb: lea    rbp,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ef:
	/* 0x2ef: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2f6:
	/* 0x2f6: mov    ecx,DWORD PTR [r15+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2fa:
	/* 0x2fa: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2fd:
	/* 0x2fd: jle    359 <generic_fexit_filter_arg+0x359> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_359;
	}
x86_l_2ff:
	/* 0x2ff: lea    edx,[rcx-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_302:
	/* 0x302: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_305:
	/* 0x305: jb     54b <generic_fexit_filter_arg+0x54b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_54b;
	}
x86_l_30b:
	/* 0x30b: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_30e:
	/* 0x30e: ja     34a <generic_fexit_filter_arg+0x34a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_34a;
	}
x86_l_310:
	/* 0x310: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_312:
	/* 0x312: movabs rsi,0xc000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 824633720832ULL);
x86_l_31c:
	/* 0x31c: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_320:
	/* 0x320: jb     382 <generic_fexit_filter_arg+0x382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_382;
	}
x86_l_322:
	/* 0x322: movabs rsi,0x30000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 3298534883328ULL);
x86_l_32c:
	/* 0x32c: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_330:
	/* 0x330: jb     8be <generic_fexit_filter_arg+0x8be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2238ULL;
	}
x86_l_336:
	/* 0x336: movabs rsi,0x42000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 4535485464576ULL);
x86_l_340:
	/* 0x340: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_344:
	/* 0x344: jb     3d5 <generic_fexit_filter_arg+0x3d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3d5;
	}
x86_l_34a:
	/* 0x34a: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_34d:
	/* 0x34d: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27f;
	}
x86_l_353:
	/* 0x353: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_357:
	/* 0x357: jmp    3d5 <generic_fexit_filter_arg+0x3d5> */
	goto x86_l_3d5;
x86_l_359:
	/* 0x359: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_35c:
	/* 0x35c: jg     3bd <generic_fexit_filter_arg+0x3bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3bd;
	}
x86_l_35e:
	/* 0x35e: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_361:
	/* 0x361: jle    4fd <generic_fexit_filter_arg+0x4fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4fd;
	}
x86_l_367:
	/* 0x367: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_36a:
	/* 0x36a: je     54b <generic_fexit_filter_arg+0x54b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54b;
	}
x86_l_370:
	/* 0x370: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_373:
	/* 0x373: je     8be <generic_fexit_filter_arg+0x8be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2238ULL;
	}
x86_l_379:
	/* 0x379: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_37c:
	/* 0x37c: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27f;
	}
x86_l_382:
	/* 0x382: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_385:
	/* 0x385: mov    ebp,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_388:
	/* 0x388: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_38c:
	/* 0x38c: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_38f:
	/* 0x38f: jg     6d0 <generic_fexit_filter_arg+0x6d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1744ULL;
	}
x86_l_395:
	/* 0x395: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_398:
	/* 0x398: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_39b:
	/* 0x39b: jb     f7c <generic_fexit_filter_arg+0xf7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3964ULL;
	}
x86_l_3a1:
	/* 0x3a1: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3a4:
	/* 0x3a4: je     ed8 <generic_fexit_filter_arg+0xed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3800ULL;
	}
x86_l_3aa:
	/* 0x3aa: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_3af:
	/* 0x3af: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3b2:
	/* 0x3b2: je     6f0 <generic_fexit_filter_arg+0x6f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1776ULL;
	}
x86_l_3b8:
	/* 0x3b8: jmp    2cf4 <generic_fexit_filter_arg+0x2cf4> */
	return 11508ULL;
x86_l_3bd:
	/* 0x3bd: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_3c0:
	/* 0x3c0: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3c3:
	/* 0x3c3: jb     54b <generic_fexit_filter_arg+0x54b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_54b;
	}
x86_l_3c9:
	/* 0x3c9: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_3cc:
	/* 0x3cc: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3cf:
	/* 0x3cf: jae    8b5 <generic_fexit_filter_arg+0x8b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2229ULL;
	}
x86_l_3d5:
	/* 0x3d5: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3da:
	/* 0x3da: mov    ebp,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dd:
	/* 0x3dd: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3df:
	/* 0x3df: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_3e2:
	/* 0x3e2: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_3e5:
	/* 0x3e5: je     3ef <generic_fexit_filter_arg+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ef;
	}
x86_l_3e7:
	/* 0x3e7: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_3e9:
	/* 0x3e9: je     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b8;
	}
x86_l_3ef:
	/* 0x3ef: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_3f2:
	/* 0x3f2: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f7:
	/* 0x3f7: ja     831 <generic_fexit_filter_arg+0x831> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2097ULL;
	}
x86_l_3fd:
	/* 0x3fd: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3ff:
	/* 0x3ff: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_404:
	/* 0x404: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_408:
	/* 0x408: jb     bd6 <generic_fexit_filter_arg+0xbd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3030ULL;
	}
x86_l_40e:
	/* 0x40e: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_413:
	/* 0x413: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_417:
	/* 0x417: jb     a96 <generic_fexit_filter_arg+0xa96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2710ULL;
	}
x86_l_41d:
	/* 0x41d: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_427:
	/* 0x427: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_42b:
	/* 0x42b: jae    831 <generic_fexit_filter_arg+0x831> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2097ULL;
	}
x86_l_431:
	/* 0x431: mov    WORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_438:
	/* 0x438: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_43e:
	/* 0x43e: ja     934 <generic_fexit_filter_arg+0x934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2356ULL;
	}
x86_l_444:
	/* 0x444: lea    rcx,[rsi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_448:
	/* 0x448: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_44c:
	/* 0x44c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_451:
	/* 0x451: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_456:
	/* 0x456: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_45b:
	/* 0x45b: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45d:
	/* 0x45d: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_461:
	/* 0x461: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_465:
	/* 0x465: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_46a:
	/* 0x46a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46c:
	/* 0x46c: mov    ecx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_470:
	/* 0x470: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_472:
	/* 0x472: je     c72 <generic_fexit_filter_arg+0xc72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3186ULL;
	}
x86_l_478:
	/* 0x478: movzx  eax,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_47d:
	/* 0x47d: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_482:
	/* 0x482: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_487:
	/* 0x487: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_489:
	/* 0x489: je     c74 <generic_fexit_filter_arg+0xc74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3188ULL;
	}
x86_l_48f:
	/* 0x48f: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_493:
	/* 0x493: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_496:
	/* 0x496: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49b:
	/* 0x49b: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a0:
	/* 0x4a0: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a5:
	/* 0x4a5: jb     934 <generic_fexit_filter_arg+0x934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2356ULL;
	}
x86_l_4ab:
	/* 0x4ab: mov    edx,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4af:
	/* 0x4af: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4b1:
	/* 0x4b1: je     934 <generic_fexit_filter_arg+0x934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2356ULL;
	}
x86_l_4b7:
	/* 0x4b7: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_4b9:
	/* 0x4b9: je     c83 <generic_fexit_filter_arg+0xc83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3203ULL;
	}
x86_l_4bf:
	/* 0x4bf: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_4c2:
	/* 0x4c2: jb     934 <generic_fexit_filter_arg+0x934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2356ULL;
	}
x86_l_4c8:
	/* 0x4c8: mov    edx,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4cc:
	/* 0x4cc: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4ce:
	/* 0x4ce: je     934 <generic_fexit_filter_arg+0x934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2356ULL;
	}
x86_l_4d4:
	/* 0x4d4: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_4d6:
	/* 0x4d6: je     c83 <generic_fexit_filter_arg+0xc83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3203ULL;
	}
x86_l_4dc:
	/* 0x4dc: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_4df:
	/* 0x4df: jb     c72 <generic_fexit_filter_arg+0xc72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3186ULL;
	}
x86_l_4e5:
	/* 0x4e5: mov    ecx,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4e9:
	/* 0x4e9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4eb:
	/* 0x4eb: je     c72 <generic_fexit_filter_arg+0xc72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3186ULL;
	}
x86_l_4f1:
	/* 0x4f1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f3:
	/* 0x4f3: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4f5:
	/* 0x4f5: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_4f8:
	/* 0x4f8: jmp    c74 <generic_fexit_filter_arg+0xc74> */
	return 3188ULL;
x86_l_4fd:
	/* 0x4fd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_500:
	/* 0x500: je     54b <generic_fexit_filter_arg+0x54b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54b;
	}
x86_l_502:
	/* 0x502: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_505:
	/* 0x505: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27f;
	}
x86_l_50b:
	/* 0x50b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_50e:
	/* 0x50e: mov    ebp,DWORD PTR [rbp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_511:
	/* 0x511: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_515:
	/* 0x515: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_518:
	/* 0x518: jg     ff9 <generic_fexit_filter_arg+0xff9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4089ULL;
	}
x86_l_51e:
	/* 0x51e: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_521:
	/* 0x521: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_524:
	/* 0x524: jb     17ee <generic_fexit_filter_arg+0x17ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6126ULL;
	}
x86_l_52a:
	/* 0x52a: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52f:
	/* 0x52f: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_532:
	/* 0x532: je     1755 <generic_fexit_filter_arg+0x1755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5973ULL;
	}
x86_l_538:
	/* 0x538: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_53d:
	/* 0x53d: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_540:
	/* 0x540: je     101e <generic_fexit_filter_arg+0x101e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4126ULL;
	}
x86_l_546:
	/* 0x546: jmp    2f7d <generic_fexit_filter_arg+0x2f7d> */
	return 12157ULL;
x86_l_54b:
	/* 0x54b: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_54e:
	/* 0x54e: jle    5dd <generic_fexit_filter_arg+0x5dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5dd;
	}
x86_l_554:
	/* 0x554: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_557:
	/* 0x557: ja     624 <generic_fexit_filter_arg+0x624> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_624;
	}
x86_l_55d:
	/* 0x55d: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_55f:
	/* 0x55f: movabs rsi,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 128849018880ULL);
x86_l_569:
	/* 0x569: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_56d:
	/* 0x56d: jb     5f8 <generic_fexit_filter_arg+0x5f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5f8;
	}
x86_l_573:
	/* 0x573: mov    esi,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1610612736ULL);
x86_l_578:
	/* 0x578: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_57c:
	/* 0x57c: jb     86e <generic_fexit_filter_arg+0x86e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2158ULL;
	}
x86_l_582:
	/* 0x582: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_58c:
	/* 0x58c: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_590:
	/* 0x590: jae    624 <generic_fexit_filter_arg+0x624> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_624;
	}
x86_l_596:
	/* 0x596: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_599:
	/* 0x599: ja     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b8;
	}
x86_l_59f:
	/* 0x59f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5a1:
	/* 0x5a1: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_5a6:
	/* 0x5a6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5aa:
	/* 0x5aa: jae    1165 <generic_fexit_filter_arg+0x1165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4453ULL;
	}
x86_l_5b0:
	/* 0x5b0: mov    ecx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b4:
	/* 0x5b4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b7:
	/* 0x5b7: jle    1608 <generic_fexit_filter_arg+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5640ULL;
	}
x86_l_5bd:
	/* 0x5bd: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_5c0:
	/* 0x5c0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5c3:
	/* 0x5c3: jae    1bcb <generic_fexit_filter_arg+0x1bcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7115ULL;
	}
x86_l_5c9:
	/* 0x5c9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5cc:
	/* 0x5cc: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5d0:
	/* 0x5d0: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_5d2:
	/* 0x5d2: jne    1eb3 <generic_fexit_filter_arg+0x1eb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7859ULL;
	}
x86_l_5d8:
	/* 0x5d8: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_5dd:
	/* 0x5dd: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_5e0:
	/* 0x5e0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5e3:
	/* 0x5e3: jb     996 <generic_fexit_filter_arg+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2454ULL;
	}
x86_l_5e9:
	/* 0x5e9: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5ec:
	/* 0x5ec: je     630 <generic_fexit_filter_arg+0x630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_630;
	}
x86_l_5ee:
	/* 0x5ee: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5f1:
	/* 0x5f1: je     630 <generic_fexit_filter_arg+0x630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_630;
	}
x86_l_5f3:
	/* 0x5f3: jmp    27f <generic_fexit_filter_arg+0x27f> */
	goto x86_l_27f;
x86_l_5f8:
	/* 0x5f8: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_5fb:
	/* 0x5fb: jle    949 <generic_fexit_filter_arg+0x949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2377ULL;
	}
x86_l_601:
	/* 0x601: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_604:
	/* 0x604: jg     db5 <generic_fexit_filter_arg+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3509ULL;
	}
x86_l_60a:
	/* 0x60a: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_60d:
	/* 0x60d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_610:
	/* 0x610: jb     a23 <generic_fexit_filter_arg+0xa23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2595ULL;
	}
x86_l_616:
	/* 0x616: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_619:
	/* 0x619: je     9ac <generic_fexit_filter_arg+0x9ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2476ULL;
	}
x86_l_61f:
	/* 0x61f: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	goto x86_l_b8;
x86_l_624:
	/* 0x624: lea    edx,[rcx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_627:
	/* 0x627: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_62a:
	/* 0x62a: jae    98d <generic_fexit_filter_arg+0x98d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2445ULL;
	}
x86_l_630:
	/* 0x630: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_633:
	/* 0x633: ja     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b8;
	}
x86_l_639:
	/* 0x639: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_63b:
	/* 0x63b: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_640:
	/* 0x640: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_644:
	/* 0x644: jae    66d <generic_fexit_filter_arg+0x66d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_66d;
	}
x86_l_646:
	/* 0x646: mov    edx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64a:
	/* 0x64a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_64d:
	/* 0x64d: jle    956 <generic_fexit_filter_arg+0x956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2390ULL;
	}
x86_l_653:
	/* 0x653: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_656:
	/* 0x656: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_659:
	/* 0x659: jae    114e <generic_fexit_filter_arg+0x114e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4430ULL;
	}
x86_l_65f:
	/* 0x65f: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_662:
	/* 0x662: jne    20f9 <generic_fexit_filter_arg+0x20f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8441ULL;
	}
x86_l_668:
	/* 0x668: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_66d:
	/* 0x66d: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_672:
	/* 0x672: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_676:
	/* 0x676: jb     cae <generic_fexit_filter_arg+0xcae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3246ULL;
	}
x86_l_67c:
	/* 0x67c: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_686:
	/* 0x686: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_68a:
	/* 0x68a: jae    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b8;
	}
x86_l_690:
	/* 0x690: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_693:
	/* 0x693: jne    12a5 <generic_fexit_filter_arg+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4773ULL;
	}
x86_l_699:
	/* 0x699: mov    esi,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69d:
	/* 0x69d: mov    edx,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6a1:
	/* 0x6a1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_6a4:
	/* 0x6a4: ja     1f4a <generic_fexit_filter_arg+0x1f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8010ULL;
	}
	return 1706ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1706ULL: goto x86_l_6aa;
	case 1711ULL: goto x86_l_6af;
	case 1714ULL: goto x86_l_6b2;
	case 1720ULL: goto x86_l_6b8;
	case 1723ULL: goto x86_l_6bb;
	case 1725ULL: goto x86_l_6bd;
	case 1731ULL: goto x86_l_6c3;
	case 1733ULL: goto x86_l_6c5;
	case 1739ULL: goto x86_l_6cb;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1753ULL: goto x86_l_6d9;
	case 1756ULL: goto x86_l_6dc;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1770ULL: goto x86_l_6ea;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1785ULL: goto x86_l_6f9;
	case 1789ULL: goto x86_l_6fd;
	case 1800ULL: goto x86_l_708;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1817ULL: goto x86_l_719;
	case 1819ULL: goto x86_l_71b;
	case 1822ULL: goto x86_l_71e;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1836ULL: goto x86_l_72c;
	case 1842ULL: goto x86_l_732;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1864ULL: goto x86_l_748;
	case 1866ULL: goto x86_l_74a;
	case 1869ULL: goto x86_l_74d;
	case 1875ULL: goto x86_l_753;
	case 1878ULL: goto x86_l_756;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1892ULL: goto x86_l_764;
	case 1894ULL: goto x86_l_766;
	case 1897ULL: goto x86_l_769;
	case 1900ULL: goto x86_l_76c;
	case 1905ULL: goto x86_l_771;
	case 1908ULL: goto x86_l_774;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1920ULL: goto x86_l_780;
	case 1926ULL: goto x86_l_786;
	case 1929ULL: goto x86_l_789;
	case 1933ULL: goto x86_l_78d;
	case 1939ULL: goto x86_l_793;
	case 1942ULL: goto x86_l_796;
	case 1946ULL: goto x86_l_79a;
	case 1949ULL: goto x86_l_79d;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1961ULL: goto x86_l_7a9;
	case 1967ULL: goto x86_l_7af;
	case 1971ULL: goto x86_l_7b3;
	case 1975ULL: goto x86_l_7b7;
	case 1978ULL: goto x86_l_7ba;
	case 1980ULL: goto x86_l_7bc;
	case 1984ULL: goto x86_l_7c0;
	case 1990ULL: goto x86_l_7c6;
	case 1994ULL: goto x86_l_7ca;
	case 1998ULL: goto x86_l_7ce;
	case 2001ULL: goto x86_l_7d1;
	case 2003ULL: goto x86_l_7d3;
	case 2007ULL: goto x86_l_7d7;
	case 2013ULL: goto x86_l_7dd;
	case 2017ULL: goto x86_l_7e1;
	case 2021ULL: goto x86_l_7e5;
	case 2024ULL: goto x86_l_7e8;
	case 2026ULL: goto x86_l_7ea;
	case 2030ULL: goto x86_l_7ee;
	case 2032ULL: goto x86_l_7f0;
	case 2036ULL: goto x86_l_7f4;
	case 2042ULL: goto x86_l_7fa;
	case 2046ULL: goto x86_l_7fe;
	case 2049ULL: goto x86_l_801;
	case 2053ULL: goto x86_l_805;
	case 2057ULL: goto x86_l_809;
	case 2060ULL: goto x86_l_80c;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2079ULL: goto x86_l_81f;
	case 2081ULL: goto x86_l_821;
	case 2084ULL: goto x86_l_824;
	case 2087ULL: goto x86_l_827;
	case 2092ULL: goto x86_l_82c;
	case 2097ULL: goto x86_l_831;
	case 2100ULL: goto x86_l_834;
	case 2103ULL: goto x86_l_837;
	case 2109ULL: goto x86_l_83d;
	case 2120ULL: goto x86_l_848;
	case 2126ULL: goto x86_l_84e;
	case 2132ULL: goto x86_l_854;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2143ULL: goto x86_l_85f;
	case 2147ULL: goto x86_l_863;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2161ULL: goto x86_l_871;
	case 2167ULL: goto x86_l_877;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2178ULL: goto x86_l_882;
	case 2184ULL: goto x86_l_888;
	case 2188ULL: goto x86_l_88c;
	case 2191ULL: goto x86_l_88f;
	case 2197ULL: goto x86_l_895;
	case 2200ULL: goto x86_l_898;
	case 2203ULL: goto x86_l_89b;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2224ULL: goto x86_l_8b0;
	case 2229ULL: goto x86_l_8b5;
	case 2232ULL: goto x86_l_8b8;
	case 2238ULL: goto x86_l_8be;
	case 2247ULL: goto x86_l_8c7;
	case 2256ULL: goto x86_l_8d0;
	case 2265ULL: goto x86_l_8d9;
	case 2274ULL: goto x86_l_8e2;
	case 2283ULL: goto x86_l_8eb;
	case 2286ULL: goto x86_l_8ee;
	case 2288ULL: goto x86_l_8f0;
	case 2291ULL: goto x86_l_8f3;
	case 2294ULL: goto x86_l_8f6;
	case 2300ULL: goto x86_l_8fc;
	case 2303ULL: goto x86_l_8ff;
	case 2308ULL: goto x86_l_904;
	case 2311ULL: goto x86_l_907;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2325ULL: goto x86_l_915;
	case 2328ULL: goto x86_l_918;
	case 2334ULL: goto x86_l_91e;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2345ULL: goto x86_l_929;
	case 2351ULL: goto x86_l_92f;
	case 2356ULL: goto x86_l_934;
	case 2358ULL: goto x86_l_936;
	case 2362ULL: goto x86_l_93a;
	case 2366ULL: goto x86_l_93e;
	case 2372ULL: goto x86_l_944;
	case 2377ULL: goto x86_l_949;
	case 2380ULL: goto x86_l_94c;
	case 2383ULL: goto x86_l_94f;
	case 2385ULL: goto x86_l_951;
	case 2390ULL: goto x86_l_956;
	case 2393ULL: goto x86_l_959;
	case 2399ULL: goto x86_l_95f;
	case 2402ULL: goto x86_l_962;
	case 2408ULL: goto x86_l_968;
	case 2411ULL: goto x86_l_96b;
	case 2417ULL: goto x86_l_971;
	case 2422ULL: goto x86_l_976;
	case 2425ULL: goto x86_l_979;
	case 2431ULL: goto x86_l_97f;
	case 2434ULL: goto x86_l_982;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2448ULL: goto x86_l_990;
	case 2454ULL: goto x86_l_996;
	case 2457ULL: goto x86_l_999;
	case 2463ULL: goto x86_l_99f;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2474ULL: goto x86_l_9aa;
	case 2476ULL: goto x86_l_9ac;
	case 2480ULL: goto x86_l_9b0;
	case 2483ULL: goto x86_l_9b3;
	case 2485ULL: goto x86_l_9b5;
	case 2488ULL: goto x86_l_9b8;
	case 2491ULL: goto x86_l_9bb;
	case 2497ULL: goto x86_l_9c1;
	case 2501ULL: goto x86_l_9c5;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2517ULL: goto x86_l_9d5;
	case 2521ULL: goto x86_l_9d9;
	case 2523ULL: goto x86_l_9db;
	case 2533ULL: goto x86_l_9e5;
	case 2537ULL: goto x86_l_9e9;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2551ULL: goto x86_l_9f7;
	case 2557ULL: goto x86_l_9fd;
	case 2560ULL: goto x86_l_a00;
	case 2566ULL: goto x86_l_a06;
	case 2569ULL: goto x86_l_a09;
	case 2571ULL: goto x86_l_a0b;
	case 2574ULL: goto x86_l_a0e;
	case 2580ULL: goto x86_l_a14;
	case 2584ULL: goto x86_l_a18;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2617ULL: goto x86_l_a39;
	case 2624ULL: goto x86_l_a40;
	case 2626ULL: goto x86_l_a42;
	case 2629ULL: goto x86_l_a45;
	case 2635ULL: goto x86_l_a4b;
	case 2638ULL: goto x86_l_a4e;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2657ULL: goto x86_l_a61;
	case 2659ULL: goto x86_l_a63;
	case 2663ULL: goto x86_l_a67;
	case 2666ULL: goto x86_l_a6a;
	case 2672ULL: goto x86_l_a70;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2685ULL: goto x86_l_a7d;
	case 2690ULL: goto x86_l_a82;
	case 2696ULL: goto x86_l_a88;
	case 2699ULL: goto x86_l_a8b;
	case 2702ULL: goto x86_l_a8e;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2714ULL: goto x86_l_a9a;
	case 2718ULL: goto x86_l_a9e;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2746ULL: goto x86_l_aba;
	case 2748ULL: goto x86_l_abc;
	case 2751ULL: goto x86_l_abf;
	case 2757ULL: goto x86_l_ac5;
	case 2762ULL: goto x86_l_aca;
	case 2765ULL: goto x86_l_acd;
	case 2771ULL: goto x86_l_ad3;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2793ULL: goto x86_l_ae9;
	case 2795ULL: goto x86_l_aeb;
	case 2798ULL: goto x86_l_aee;
	case 2804ULL: goto x86_l_af4;
	case 2807ULL: goto x86_l_af7;
	case 2810ULL: goto x86_l_afa;
	case 2815ULL: goto x86_l_aff;
	case 2818ULL: goto x86_l_b02;
	case 2821ULL: goto x86_l_b05;
	case 2823ULL: goto x86_l_b07;
	case 2826ULL: goto x86_l_b0a;
	case 2829ULL: goto x86_l_b0d;
	case 2834ULL: goto x86_l_b12;
	case 2837ULL: goto x86_l_b15;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2849ULL: goto x86_l_b21;
	case 2855ULL: goto x86_l_b27;
	case 2858ULL: goto x86_l_b2a;
	case 2862ULL: goto x86_l_b2e;
	case 2868ULL: goto x86_l_b34;
	case 2871ULL: goto x86_l_b37;
	case 2875ULL: goto x86_l_b3b;
	case 2878ULL: goto x86_l_b3e;
	case 2881ULL: goto x86_l_b41;
	case 2886ULL: goto x86_l_b46;
	case 2890ULL: goto x86_l_b4a;
	case 2896ULL: goto x86_l_b50;
	case 2901ULL: goto x86_l_b55;
	case 2905ULL: goto x86_l_b59;
	case 2908ULL: goto x86_l_b5c;
	case 2910ULL: goto x86_l_b5e;
	case 2914ULL: goto x86_l_b62;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2929ULL: goto x86_l_b71;
	case 2932ULL: goto x86_l_b74;
	case 2934ULL: goto x86_l_b76;
	case 2938ULL: goto x86_l_b7a;
	case 2944ULL: goto x86_l_b80;
	case 2949ULL: goto x86_l_b85;
	case 2953ULL: goto x86_l_b89;
	case 2956ULL: goto x86_l_b8c;
	case 2958ULL: goto x86_l_b8e;
	case 2962ULL: goto x86_l_b92;
	case 2964ULL: goto x86_l_b94;
	case 2968ULL: goto x86_l_b98;
	case 2974ULL: goto x86_l_b9e;
	case 2979ULL: goto x86_l_ba3;
	case 2982ULL: goto x86_l_ba6;
	case 2986ULL: goto x86_l_baa;
	case 2990ULL: goto x86_l_bae;
	case 2993ULL: goto x86_l_bb1;
	case 2995ULL: goto x86_l_bb3;
	case 3000ULL: goto x86_l_bb8;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3012ULL: goto x86_l_bc4;
	case 3014ULL: goto x86_l_bc6;
	case 3017ULL: goto x86_l_bc9;
	case 3020ULL: goto x86_l_bcc;
	case 3025ULL: goto x86_l_bd1;
	case 3030ULL: goto x86_l_bd6;
	case 3034ULL: goto x86_l_bda;
	case 3038ULL: goto x86_l_bde;
	case 3049ULL: goto x86_l_be9;
	case 3054ULL: goto x86_l_bee;
	case 3059ULL: goto x86_l_bf3;
	case 3066ULL: goto x86_l_bfa;
	case 3068ULL: goto x86_l_bfc;
	case 3071ULL: goto x86_l_bff;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3081ULL: goto x86_l_c09;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3105ULL: goto x86_l_c21;
	case 3107ULL: goto x86_l_c23;
	case 3110ULL: goto x86_l_c26;
	case 3112ULL: goto x86_l_c28;
	case 3115ULL: goto x86_l_c2b;
	case 3120ULL: goto x86_l_c30;
	case 3124ULL: goto x86_l_c34;
	case 3130ULL: goto x86_l_c3a;
	case 3135ULL: goto x86_l_c3f;
	case 3138ULL: goto x86_l_c42;
	case 3145ULL: goto x86_l_c49;
	case 3147ULL: goto x86_l_c4b;
	case 3150ULL: goto x86_l_c4e;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3171ULL: goto x86_l_c63;
	case 3174ULL: goto x86_l_c66;
	case 3176ULL: goto x86_l_c68;
	case 3178ULL: goto x86_l_c6a;
	case 3181ULL: goto x86_l_c6d;
	case 3184ULL: goto x86_l_c70;
	case 3186ULL: goto x86_l_c72;
	case 3188ULL: goto x86_l_c74;
	case 3193ULL: goto x86_l_c79;
	case 3198ULL: goto x86_l_c7e;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3211ULL: goto x86_l_c8b;
	case 3217ULL: goto x86_l_c91;
	case 3227ULL: goto x86_l_c9b;
	case 3231ULL: goto x86_l_c9f;
	case 3237ULL: goto x86_l_ca5;
	case 3241ULL: goto x86_l_ca9;
	case 3246ULL: goto x86_l_cae;
	case 3251ULL: goto x86_l_cb3;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3268ULL: goto x86_l_cc4;
	case 3275ULL: goto x86_l_ccb;
	case 3277ULL: goto x86_l_ccd;
	case 3280ULL: goto x86_l_cd0;
	case 3286ULL: goto x86_l_cd6;
	case 3289ULL: goto x86_l_cd9;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3315ULL: goto x86_l_cf3;
	case 3321ULL: goto x86_l_cf9;
	case 3325ULL: goto x86_l_cfd;
	case 3331ULL: goto x86_l_d03;
	case 3336ULL: goto x86_l_d08;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3348ULL: goto x86_l_d14;
	case 3353ULL: goto x86_l_d19;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6aa:
	/* 0x6aa: mov    eax,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5122ULL);
x86_l_6af:
	/* 0x6af: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_6b2:
	/* 0x6b2: jae    1f4a <generic_fexit_filter_arg+0x1f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8010ULL;
	}
x86_l_6b8:
	/* 0x6b8: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6bb:
	/* 0x6bb: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_6bd:
	/* 0x6bd: jg     1f59 <generic_fexit_filter_arg+0x1f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8025ULL;
	}
x86_l_6c3:
	/* 0x6c3: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_6c5:
	/* 0x6c5: jle    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 639ULL;
	}
x86_l_6cb:
	/* 0x6cb: jmp    1f59 <generic_fexit_filter_arg+0x1f59> */
	return 8025ULL;
x86_l_6d0:
	/* 0x6d0: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_6d3:
	/* 0x6d3: jg     dfb <generic_fexit_filter_arg+0xdfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3579ULL;
	}
x86_l_6d9:
	/* 0x6d9: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_6dc:
	/* 0x6dc: je     ed8 <generic_fexit_filter_arg+0xed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3800ULL;
	}
x86_l_6e2:
	/* 0x6e2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_6e7:
	/* 0x6e7: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_6ea:
	/* 0x6ea: jne    2cf4 <generic_fexit_filter_arg+0x2cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11508ULL;
	}
x86_l_6f0:
	/* 0x6f0: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6f5:
	/* 0x6f5: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f9:
	/* 0x6f9: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6fd:
	/* 0x6fd: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_708:
	/* 0x708: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_70d:
	/* 0x70d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_712:
	/* 0x712: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_719:
	/* 0x719: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71b:
	/* 0x71b: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_71e:
	/* 0x71e: je     2ce3 <generic_fexit_filter_arg+0x2ce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11491ULL;
	}
x86_l_724:
	/* 0x724: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_729:
	/* 0x729: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_72c:
	/* 0x72c: je     2ce5 <generic_fexit_filter_arg+0x2ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11493ULL;
	}
x86_l_732:
	/* 0x732: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_737:
	/* 0x737: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_73c:
	/* 0x73c: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_741:
	/* 0x741: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_748:
	/* 0x748: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74a:
	/* 0x74a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_74d:
	/* 0x74d: je     2ce3 <generic_fexit_filter_arg+0x2ce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11491ULL;
	}
x86_l_753:
	/* 0x753: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_756:
	/* 0x756: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_759:
	/* 0x759: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_75e:
	/* 0x75e: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_761:
	/* 0x761: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_764:
	/* 0x764: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_766:
	/* 0x766: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_769:
	/* 0x769: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_76c:
	/* 0x76c: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_771:
	/* 0x771: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_774:
	/* 0x774: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_777:
	/* 0x777: mov    QWORD PTR [rsp+0x68],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_77c:
	/* 0x77c: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_780:
	/* 0x780: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_786:
	/* 0x786: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_789:
	/* 0x789: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_78d:
	/* 0x78d: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_793:
	/* 0x793: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_796:
	/* 0x796: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_79a:
	/* 0x79a: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_79d:
	/* 0x79d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a0:
	/* 0x7a0: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a5:
	/* 0x7a5: lea    ebp,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_7a9:
	/* 0x7a9: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7af:
	/* 0x7af: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_7b3:
	/* 0x7b3: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_7b7:
	/* 0x7b7: cmp    r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_7ba:
	/* 0x7ba: je     80e <generic_fexit_filter_arg+0x80e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_80e;
	}
x86_l_7bc:
	/* 0x7bc: lea    ebp,[r11+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_7c0:
	/* 0x7c0: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7c6:
	/* 0x7c6: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_7ca:
	/* 0x7ca: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_7ce:
	/* 0x7ce: cmp    r8,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64);
x86_l_7d1:
	/* 0x7d1: je     80e <generic_fexit_filter_arg+0x80e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_80e;
	}
x86_l_7d3:
	/* 0x7d3: lea    ebp,[r9+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_7d7:
	/* 0x7d7: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7dd:
	/* 0x7dd: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_7e1:
	/* 0x7e1: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_7e5:
	/* 0x7e5: cmp    rcx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_7e8:
	/* 0x7e8: je     80e <generic_fexit_filter_arg+0x80e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_80e;
	}
x86_l_7ea:
	/* 0x7ea: cmp    r12,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_7ee:
	/* 0x7ee: je     80e <generic_fexit_filter_arg+0x80e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_80e;
	}
x86_l_7f0:
	/* 0x7f0: lea    ebp,[rdx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_7f4:
	/* 0x7f4: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7fa:
	/* 0x7fa: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_7fe:
	/* 0x7fe: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_801:
	/* 0x801: add    r12,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_805:
	/* 0x805: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_809:
	/* 0x809: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_80c:
	/* 0x80c: jne    7a5 <generic_fexit_filter_arg+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7a5;
	}
x86_l_80e:
	/* 0x80e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_813:
	/* 0x813: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_818:
	/* 0x818: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_81d:
	/* 0x81d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81f:
	/* 0x81f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_821:
	/* 0x821: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_824:
	/* 0x824: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_827:
	/* 0x827: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_82c:
	/* 0x82c: jmp    2ce5 <generic_fexit_filter_arg+0x2ce5> */
	return 11493ULL;
x86_l_831:
	/* 0x831: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_834:
	/* 0x834: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_837:
	/* 0x837: jae    934 <generic_fexit_filter_arg+0x934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_934;
	}
x86_l_83d:
	/* 0x83d: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_848:
	/* 0x848: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_84e:
	/* 0x84e: jbe    124c <generic_fexit_filter_arg+0x124c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4684ULL;
	}
x86_l_854:
	/* 0x854: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_856:
	/* 0x856: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_85b:
	/* 0x85b: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_85f:
	/* 0x85f: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_863:
	/* 0x863: jbe    c91 <generic_fexit_filter_arg+0xc91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c91;
	}
x86_l_869:
	/* 0x869: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_86e:
	/* 0x86e: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_871:
	/* 0x871: ja     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 184ULL;
	}
x86_l_877:
	/* 0x877: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_879:
	/* 0x879: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_87e:
	/* 0x87e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_882:
	/* 0x882: jae    1197 <generic_fexit_filter_arg+0x1197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4503ULL;
	}
x86_l_888:
	/* 0x888: mov    ecx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_88c:
	/* 0x88c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_88f:
	/* 0x88f: jle    162b <generic_fexit_filter_arg+0x162b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5675ULL;
	}
x86_l_895:
	/* 0x895: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_898:
	/* 0x898: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_89b:
	/* 0x89b: jae    1be5 <generic_fexit_filter_arg+0x1be5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7141ULL;
	}
x86_l_8a1:
	/* 0x8a1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8a4:
	/* 0x8a4: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_8a8:
	/* 0x8a8: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_8aa:
	/* 0x8aa: jne    1ef6 <generic_fexit_filter_arg+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7926ULL;
	}
x86_l_8b0:
	/* 0x8b0: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_8b5:
	/* 0x8b5: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_8b8:
	/* 0x8b8: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_8be:
	/* 0x8be: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_8c7:
	/* 0x8c7: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_8d0:
	/* 0x8d0: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_8d9:
	/* 0x8d9: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_8e2:
	/* 0x8e2: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_8eb:
	/* 0x8eb: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_8ee:
	/* 0x8ee: jg     912 <generic_fexit_filter_arg+0x912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_912;
	}
x86_l_8f0:
	/* 0x8f0: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_8f3:
	/* 0x8f3: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_8f6:
	/* 0x8f6: je     d30 <generic_fexit_filter_arg+0xd30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3376ULL;
	}
x86_l_8fc:
	/* 0x8fc: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_8ff:
	/* 0x8ff: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_904:
	/* 0x904: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_907:
	/* 0x907: je     d32 <generic_fexit_filter_arg+0xd32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3378ULL;
	}
x86_l_90d:
	/* 0x90d: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_912:
	/* 0x912: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_915:
	/* 0x915: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_918:
	/* 0x918: je     d08 <generic_fexit_filter_arg+0xd08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d08;
	}
x86_l_91e:
	/* 0x91e: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_921:
	/* 0x921: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_926:
	/* 0x926: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_929:
	/* 0x929: je     d32 <generic_fexit_filter_arg+0xd32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3378ULL;
	}
x86_l_92f:
	/* 0x92f: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_934:
	/* 0x934: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_936:
	/* 0x936: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_93a:
	/* 0x93a: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_93e:
	/* 0x93e: jbe    c91 <generic_fexit_filter_arg+0xc91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c91;
	}
x86_l_944:
	/* 0x944: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_949:
	/* 0x949: lea    edx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_94c:
	/* 0x94c: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_94f:
	/* 0x94f: jb     9ac <generic_fexit_filter_arg+0x9ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9ac;
	}
x86_l_951:
	/* 0x951: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	return 184ULL;
x86_l_956:
	/* 0x956: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_959:
	/* 0x959: je     1406 <generic_fexit_filter_arg+0x1406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5126ULL;
	}
x86_l_95f:
	/* 0x95f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_962:
	/* 0x962: jne    20f9 <generic_fexit_filter_arg+0x20f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8441ULL;
	}
x86_l_968:
	/* 0x968: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_96b:
	/* 0x96b: ja     20f0 <generic_fexit_filter_arg+0x20f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8432ULL;
	}
x86_l_971:
	/* 0x971: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_976:
	/* 0x976: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_979:
	/* 0x979: jae    20f0 <generic_fexit_filter_arg+0x20f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8432ULL;
	}
x86_l_97f:
	/* 0x97f: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_982:
	/* 0x982: jl     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 639ULL;
	}
x86_l_988:
	/* 0x988: jmp    20f9 <generic_fexit_filter_arg+0x20f9> */
	return 8441ULL;
x86_l_98d:
	/* 0x98d: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_990:
	/* 0x990: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_996:
	/* 0x996: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_999:
	/* 0x999: ja     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 184ULL;
	}
x86_l_99f:
	/* 0x99f: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_9a1:
	/* 0x9a1: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_9a6:
	/* 0x9a6: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_9aa:
	/* 0x9aa: jae    9d0 <generic_fexit_filter_arg+0x9d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9d0;
	}
x86_l_9ac:
	/* 0x9ac: mov    rdx,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9b0:
	/* 0x9b0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9b3:
	/* 0x9b3: jle    9f4 <generic_fexit_filter_arg+0x9f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_9f4;
	}
x86_l_9b5:
	/* 0x9b5: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_9b8:
	/* 0x9b8: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_9bb:
	/* 0x9bb: jae    cf0 <generic_fexit_filter_arg+0xcf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_cf0;
	}
x86_l_9c1:
	/* 0x9c1: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9c5:
	/* 0x9c5: jne    1b4d <generic_fexit_filter_arg+0x1b4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6989ULL;
	}
x86_l_9cb:
	/* 0x9cb: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_9d0:
	/* 0x9d0: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_9d5:
	/* 0x9d5: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_9d9:
	/* 0x9d9: jb     a23 <generic_fexit_filter_arg+0xa23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a23;
	}
x86_l_9db:
	/* 0x9db: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_9e5:
	/* 0x9e5: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_9e9:
	/* 0x9e9: jb     dc1 <generic_fexit_filter_arg+0xdc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3521ULL;
	}
x86_l_9ef:
	/* 0x9ef: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	return 184ULL;
x86_l_9f4:
	/* 0x9f4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9f7:
	/* 0x9f7: je     122f <generic_fexit_filter_arg+0x122f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4655ULL;
	}
x86_l_9fd:
	/* 0x9fd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a00:
	/* 0xa00: jne    1b4d <generic_fexit_filter_arg+0x1b4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6989ULL;
	}
x86_l_a06:
	/* 0xa06: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_a09:
	/* 0xa09: je     a14 <generic_fexit_filter_arg+0xa14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a14;
	}
x86_l_a0b:
	/* 0xa0b: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_a0e:
	/* 0xa0e: jne    1b43 <generic_fexit_filter_arg+0x1b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6979ULL;
	}
x86_l_a14:
	/* 0xa14: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a18:
	/* 0xa18: jl     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 639ULL;
	}
x86_l_a1e:
	/* 0xa1e: jmp    1b4d <generic_fexit_filter_arg+0x1b4d> */
	return 6989ULL;
x86_l_a23:
	/* 0xa23: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_a28:
	/* 0xa28: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a2f:
	/* 0xa2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a34:
	/* 0xa34: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a39:
	/* 0xa39: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_a40:
	/* 0xa40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a42:
	/* 0xa42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a45:
	/* 0xa45: je     1700 <generic_fexit_filter_arg+0x1700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5888ULL;
	}
x86_l_a4b:
	/* 0xa4b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_a4e:
	/* 0xa4e: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a52:
	/* 0xa52: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a57:
	/* 0xa57: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a5c:
	/* 0xa5c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a61:
	/* 0xa61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a63:
	/* 0xa63: mov    ecx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a67:
	/* 0xa67: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_a6a:
	/* 0xa6a: je     172e <generic_fexit_filter_arg+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5934ULL;
	}
x86_l_a70:
	/* 0xa70: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_a73:
	/* 0xa73: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a78:
	/* 0xa78: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a7d:
	/* 0xa7d: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a82:
	/* 0xa82: jne    174b <generic_fexit_filter_arg+0x174b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5963ULL;
	}
x86_l_a88:
	/* 0xa88: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a8b:
	/* 0xa8b: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_a8e:
	/* 0xa8e: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a91:
	/* 0xa91: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_a96:
	/* 0xa96: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a9a:
	/* 0xa9a: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a9e:
	/* 0xa9e: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_aa9:
	/* 0xaa9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aae:
	/* 0xaae: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ab3:
	/* 0xab3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_aba:
	/* 0xaba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abc:
	/* 0xabc: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_abf:
	/* 0xabf: je     c72 <generic_fexit_filter_arg+0xc72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c72;
	}
x86_l_ac5:
	/* 0xac5: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_aca:
	/* 0xaca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_acd:
	/* 0xacd: je     c74 <generic_fexit_filter_arg+0xc74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c74;
	}
x86_l_ad3:
	/* 0xad3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ad8:
	/* 0xad8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_add:
	/* 0xadd: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ae2:
	/* 0xae2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_ae9:
	/* 0xae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aeb:
	/* 0xaeb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aee:
	/* 0xaee: je     c72 <generic_fexit_filter_arg+0xc72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c72;
	}
x86_l_af4:
	/* 0xaf4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_af7:
	/* 0xaf7: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_afa:
	/* 0xafa: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_aff:
	/* 0xaff: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_b02:
	/* 0xb02: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_b05:
	/* 0xb05: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b07:
	/* 0xb07: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_b0a:
	/* 0xb0a: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_b0d:
	/* 0xb0d: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b12:
	/* 0xb12: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b15:
	/* 0xb15: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_b18:
	/* 0xb18: mov    QWORD PTR [rsp+0x68],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b1d:
	/* 0xb1d: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_b21:
	/* 0xb21: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_b27:
	/* 0xb27: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b2a:
	/* 0xb2a: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_b2e:
	/* 0xb2e: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_b34:
	/* 0xb34: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b37:
	/* 0xb37: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_b3b:
	/* 0xb3b: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_b3e:
	/* 0xb3e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b41:
	/* 0xb41: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b46:
	/* 0xb46: lea    ebp,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_b4a:
	/* 0xb4a: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b50:
	/* 0xb50: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_b55:
	/* 0xb55: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_b59:
	/* 0xb59: cmp    r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_b5c:
	/* 0xb5c: je     bb3 <generic_fexit_filter_arg+0xbb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb3;
	}
x86_l_b5e:
	/* 0xb5e: lea    ebp,[r11+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_b62:
	/* 0xb62: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b68:
	/* 0xb68: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_b6d:
	/* 0xb6d: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_b71:
	/* 0xb71: cmp    r8,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64);
x86_l_b74:
	/* 0xb74: je     bb3 <generic_fexit_filter_arg+0xbb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb3;
	}
x86_l_b76:
	/* 0xb76: lea    ebp,[r9+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_b7a:
	/* 0xb7a: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b80:
	/* 0xb80: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_b85:
	/* 0xb85: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_b89:
	/* 0xb89: cmp    rcx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_b8c:
	/* 0xb8c: je     bb3 <generic_fexit_filter_arg+0xbb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb3;
	}
x86_l_b8e:
	/* 0xb8e: cmp    r12,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_b92:
	/* 0xb92: je     bb3 <generic_fexit_filter_arg+0xbb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb3;
	}
x86_l_b94:
	/* 0xb94: lea    ebp,[rdx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_b98:
	/* 0xb98: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b9e:
	/* 0xb9e: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_ba3:
	/* 0xba3: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba6:
	/* 0xba6: add    r12,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_baa:
	/* 0xbaa: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_bae:
	/* 0xbae: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_bb1:
	/* 0xbb1: jne    b46 <generic_fexit_filter_arg+0xb46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b46;
	}
x86_l_bb3:
	/* 0xbb3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bb8:
	/* 0xbb8: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bbd:
	/* 0xbbd: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bc2:
	/* 0xbc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc4:
	/* 0xbc4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc6:
	/* 0xbc6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bc9:
	/* 0xbc9: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_bcc:
	/* 0xbcc: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bd1:
	/* 0xbd1: jmp    c74 <generic_fexit_filter_arg+0xc74> */
	goto x86_l_c74;
x86_l_bd6:
	/* 0xbd6: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bda:
	/* 0xbda: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bde:
	/* 0xbde: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_be9:
	/* 0xbe9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bee:
	/* 0xbee: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bf3:
	/* 0xbf3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_bfa:
	/* 0xbfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfc:
	/* 0xbfc: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_bff:
	/* 0xbff: je     c72 <generic_fexit_filter_arg+0xc72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c72;
	}
x86_l_c01:
	/* 0xc01: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_c06:
	/* 0xc06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c09:
	/* 0xc09: je     c74 <generic_fexit_filter_arg+0xc74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c74;
	}
x86_l_c0b:
	/* 0xc0b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c10:
	/* 0xc10: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c15:
	/* 0xc15: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c1a:
	/* 0xc1a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_c21:
	/* 0xc21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c23:
	/* 0xc23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c26:
	/* 0xc26: je     c72 <generic_fexit_filter_arg+0xc72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c72;
	}
x86_l_c28:
	/* 0xc28: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_c2b:
	/* 0xc2b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c30:
	/* 0xc30: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_c34:
	/* 0xc34: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_c3a:
	/* 0xc3a: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_c3f:
	/* 0xc3f: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_c42:
	/* 0xc42: lea    eax,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_c49:
	/* 0xc49: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c4b:
	/* 0xc4b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c4e:
	/* 0xc4e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_c52:
	/* 0xc52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c57:
	/* 0xc57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c59:
	/* 0xc59: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c5e:
	/* 0xc5e: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c63:
	/* 0xc63: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_c66:
	/* 0xc66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c68:
	/* 0xc68: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c6a:
	/* 0xc6a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c6d:
	/* 0xc6d: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_c70:
	/* 0xc70: jmp    c74 <generic_fexit_filter_arg+0xc74> */
	goto x86_l_c74;
x86_l_c72:
	/* 0xc72: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c74:
	/* 0xc74: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c79:
	/* 0xc79: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c7e:
	/* 0xc7e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c83:
	/* 0xc83: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c87:
	/* 0xc87: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_c8b:
	/* 0xc8b: ja     26e <generic_fexit_filter_arg+0x26e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 622ULL;
	}
x86_l_c91:
	/* 0xc91: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_c9b:
	/* 0xc9b: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c9f:
	/* 0xc9f: jae    26e <generic_fexit_filter_arg+0x26e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 622ULL;
	}
x86_l_ca5:
	/* 0xca5: xor    rbx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_ca9:
	/* 0xca9: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_cae:
	/* 0xcae: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_cb3:
	/* 0xcb3: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cba:
	/* 0xcba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cbf:
	/* 0xcbf: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cc4:
	/* 0xcc4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_ccb:
	/* 0xccb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ccd:
	/* 0xccd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cd0:
	/* 0xcd0: je     1700 <generic_fexit_filter_arg+0x1700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5888ULL;
	}
x86_l_cd6:
	/* 0xcd6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_cd9:
	/* 0xcd9: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cdc:
	/* 0xcdc: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ce1:
	/* 0xce1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce6:
	/* 0xce6: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ceb:
	/* 0xceb: jmp    16c8 <generic_fexit_filter_arg+0x16c8> */
	return 5832ULL;
x86_l_cf0:
	/* 0xcf0: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_cf3:
	/* 0xcf3: jne    1b4d <generic_fexit_filter_arg+0x1b4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6989ULL;
	}
x86_l_cf9:
	/* 0xcf9: test   QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cfd:
	/* 0xcfd: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_d03:
	/* 0xd03: jmp    1b4d <generic_fexit_filter_arg+0x1b4d> */
	return 6989ULL;
x86_l_d08:
	/* 0xd08: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d0b:
	/* 0xd0b: mov    WORD PTR [rsp+0x66],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 102ULL);
x86_l_d10:
	/* 0xd10: movzx  edx,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_d14:
	/* 0xd14: mov    WORD PTR [rsp+0x60],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d19:
	/* 0xd19: mov    rdx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 3357ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3357ULL: goto x86_l_d1d;
	case 3362ULL: goto x86_l_d22;
	case 3366ULL: goto x86_l_d26;
	case 3371ULL: goto x86_l_d2b;
	case 3376ULL: goto x86_l_d30;
	case 3378ULL: goto x86_l_d32;
	case 3381ULL: goto x86_l_d35;
	case 3383ULL: goto x86_l_d37;
	case 3386ULL: goto x86_l_d3a;
	case 3388ULL: goto x86_l_d3c;
	case 3391ULL: goto x86_l_d3f;
	case 3394ULL: goto x86_l_d42;
	case 3400ULL: goto x86_l_d48;
	case 3403ULL: goto x86_l_d4b;
	case 3408ULL: goto x86_l_d50;
	case 3411ULL: goto x86_l_d53;
	case 3417ULL: goto x86_l_d59;
	case 3422ULL: goto x86_l_d5e;
	case 3425ULL: goto x86_l_d61;
	case 3431ULL: goto x86_l_d67;
	case 3434ULL: goto x86_l_d6a;
	case 3440ULL: goto x86_l_d70;
	case 3443ULL: goto x86_l_d73;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3457ULL: goto x86_l_d81;
	case 3463ULL: goto x86_l_d87;
	case 3467ULL: goto x86_l_d8b;
	case 3472ULL: goto x86_l_d90;
	case 3475ULL: goto x86_l_d93;
	case 3481ULL: goto x86_l_d99;
	case 3484ULL: goto x86_l_d9c;
	case 3490ULL: goto x86_l_da2;
	case 3495ULL: goto x86_l_da7;
	case 3498ULL: goto x86_l_daa;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3515ULL: goto x86_l_dbb;
	case 3521ULL: goto x86_l_dc1;
	case 3524ULL: goto x86_l_dc4;
	case 3530ULL: goto x86_l_dca;
	case 3534ULL: goto x86_l_dce;
	case 3538ULL: goto x86_l_dd2;
	case 3541ULL: goto x86_l_dd5;
	case 3543ULL: goto x86_l_dd7;
	case 3546ULL: goto x86_l_dda;
	case 3552ULL: goto x86_l_de0;
	case 3556ULL: goto x86_l_de4;
	case 3559ULL: goto x86_l_de7;
	case 3565ULL: goto x86_l_ded;
	case 3568ULL: goto x86_l_df0;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3582ULL: goto x86_l_dfe;
	case 3588ULL: goto x86_l_e04;
	case 3593ULL: goto x86_l_e09;
	case 3596ULL: goto x86_l_e0c;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	case 3609ULL: goto x86_l_e19;
	case 3612ULL: goto x86_l_e1c;
	case 3617ULL: goto x86_l_e21;
	case 3621ULL: goto x86_l_e25;
	case 3626ULL: goto x86_l_e2a;
	case 3631ULL: goto x86_l_e2f;
	case 3638ULL: goto x86_l_e36;
	case 3640ULL: goto x86_l_e38;
	case 3643ULL: goto x86_l_e3b;
	case 3649ULL: goto x86_l_e41;
	case 3652ULL: goto x86_l_e44;
	case 3657ULL: goto x86_l_e49;
	case 3659ULL: goto x86_l_e4b;
	case 3664ULL: goto x86_l_e50;
	case 3666ULL: goto x86_l_e52;
	case 3668ULL: goto x86_l_e54;
	case 3671ULL: goto x86_l_e57;
	case 3674ULL: goto x86_l_e5a;
	case 3677ULL: goto x86_l_e5d;
	case 3679ULL: goto x86_l_e5f;
	case 3681ULL: goto x86_l_e61;
	case 3685ULL: goto x86_l_e65;
	case 3688ULL: goto x86_l_e68;
	case 3690ULL: goto x86_l_e6a;
	case 3694ULL: goto x86_l_e6e;
	case 3696ULL: goto x86_l_e70;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3707ULL: goto x86_l_e7b;
	case 3710ULL: goto x86_l_e7e;
	case 3714ULL: goto x86_l_e82;
	case 3718ULL: goto x86_l_e86;
	case 3722ULL: goto x86_l_e8a;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3733ULL: goto x86_l_e95;
	case 3737ULL: goto x86_l_e99;
	case 3741ULL: goto x86_l_e9d;
	case 3745ULL: goto x86_l_ea1;
	case 3747ULL: goto x86_l_ea3;
	case 3750ULL: goto x86_l_ea6;
	case 3753ULL: goto x86_l_ea9;
	case 3755ULL: goto x86_l_eab;
	case 3757ULL: goto x86_l_ead;
	case 3759ULL: goto x86_l_eaf;
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3774ULL: goto x86_l_ebe;
	case 3776ULL: goto x86_l_ec0;
	case 3780ULL: goto x86_l_ec4;
	case 3783ULL: goto x86_l_ec7;
	case 3787ULL: goto x86_l_ecb;
	case 3793ULL: goto x86_l_ed1;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3809ULL: goto x86_l_ee1;
	case 3813ULL: goto x86_l_ee5;
	case 3824ULL: goto x86_l_ef0;
	case 3829ULL: goto x86_l_ef5;
	case 3834ULL: goto x86_l_efa;
	case 3841ULL: goto x86_l_f01;
	case 3843ULL: goto x86_l_f03;
	case 3846ULL: goto x86_l_f06;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3860ULL: goto x86_l_f14;
	case 3866ULL: goto x86_l_f1a;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3881ULL: goto x86_l_f29;
	case 3888ULL: goto x86_l_f30;
	case 3890ULL: goto x86_l_f32;
	case 3893ULL: goto x86_l_f35;
	case 3899ULL: goto x86_l_f3b;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3913ULL: goto x86_l_f49;
	case 3920ULL: goto x86_l_f50;
	case 3922ULL: goto x86_l_f52;
	case 3925ULL: goto x86_l_f55;
	case 3929ULL: goto x86_l_f59;
	case 3932ULL: goto x86_l_f5c;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3944ULL: goto x86_l_f68;
	case 3946ULL: goto x86_l_f6a;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3959ULL: goto x86_l_f77;
	case 3964ULL: goto x86_l_f7c;
	case 3975ULL: goto x86_l_f87;
	case 3981ULL: goto x86_l_f8d;
	case 3987ULL: goto x86_l_f93;
	case 3989ULL: goto x86_l_f95;
	case 3993ULL: goto x86_l_f99;
	case 3997ULL: goto x86_l_f9d;
	case 4003ULL: goto x86_l_fa3;
	case 4008ULL: goto x86_l_fa8;
	case 4012ULL: goto x86_l_fac;
	case 4016ULL: goto x86_l_fb0;
	case 4019ULL: goto x86_l_fb3;
	case 4021ULL: goto x86_l_fb5;
	case 4024ULL: goto x86_l_fb8;
	case 4030ULL: goto x86_l_fbe;
	case 4034ULL: goto x86_l_fc2;
	case 4037ULL: goto x86_l_fc5;
	case 4041ULL: goto x86_l_fc9;
	case 4044ULL: goto x86_l_fcc;
	case 4047ULL: goto x86_l_fcf;
	case 4052ULL: goto x86_l_fd4;
	case 4055ULL: goto x86_l_fd7;
	case 4061ULL: goto x86_l_fdd;
	case 4064ULL: goto x86_l_fe0;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4078ULL: goto x86_l_fee;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4092ULL: goto x86_l_ffc;
	case 4097ULL: goto x86_l_1001;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4112ULL: goto x86_l_1010;
	case 4117ULL: goto x86_l_1015;
	case 4120ULL: goto x86_l_1018;
	case 4126ULL: goto x86_l_101e;
	case 4130ULL: goto x86_l_1022;
	case 4134ULL: goto x86_l_1026;
	case 4145ULL: goto x86_l_1031;
	case 4150ULL: goto x86_l_1036;
	case 4155ULL: goto x86_l_103b;
	case 4162ULL: goto x86_l_1042;
	case 4164ULL: goto x86_l_1044;
	case 4167ULL: goto x86_l_1047;
	case 4173ULL: goto x86_l_104d;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4184ULL: goto x86_l_1058;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4200ULL: goto x86_l_1068;
	case 4207ULL: goto x86_l_106f;
	case 4209ULL: goto x86_l_1071;
	case 4212ULL: goto x86_l_1074;
	case 4218ULL: goto x86_l_107a;
	case 4221ULL: goto x86_l_107d;
	case 4226ULL: goto x86_l_1082;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4237ULL: goto x86_l_108d;
	case 4240ULL: goto x86_l_1090;
	case 4242ULL: goto x86_l_1092;
	case 4245ULL: goto x86_l_1095;
	case 4248ULL: goto x86_l_1098;
	case 4253ULL: goto x86_l_109d;
	case 4256ULL: goto x86_l_10a0;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4268ULL: goto x86_l_10ac;
	case 4274ULL: goto x86_l_10b2;
	case 4277ULL: goto x86_l_10b5;
	case 4281ULL: goto x86_l_10b9;
	case 4287ULL: goto x86_l_10bf;
	case 4290ULL: goto x86_l_10c2;
	case 4294ULL: goto x86_l_10c6;
	case 4297ULL: goto x86_l_10c9;
	case 4300ULL: goto x86_l_10cc;
	case 4305ULL: goto x86_l_10d1;
	case 4309ULL: goto x86_l_10d5;
	case 4315ULL: goto x86_l_10db;
	case 4319ULL: goto x86_l_10df;
	case 4323ULL: goto x86_l_10e3;
	case 4326ULL: goto x86_l_10e6;
	case 4328ULL: goto x86_l_10e8;
	case 4332ULL: goto x86_l_10ec;
	case 4338ULL: goto x86_l_10f2;
	case 4342ULL: goto x86_l_10f6;
	case 4346ULL: goto x86_l_10fa;
	case 4349ULL: goto x86_l_10fd;
	case 4351ULL: goto x86_l_10ff;
	case 4355ULL: goto x86_l_1103;
	case 4361ULL: goto x86_l_1109;
	case 4365ULL: goto x86_l_110d;
	case 4369ULL: goto x86_l_1111;
	case 4372ULL: goto x86_l_1114;
	case 4374ULL: goto x86_l_1116;
	case 4378ULL: goto x86_l_111a;
	case 4380ULL: goto x86_l_111c;
	case 4384ULL: goto x86_l_1120;
	case 4390ULL: goto x86_l_1126;
	case 4394ULL: goto x86_l_112a;
	case 4397ULL: goto x86_l_112d;
	case 4401ULL: goto x86_l_1131;
	case 4405ULL: goto x86_l_1135;
	case 4408ULL: goto x86_l_1138;
	case 4410ULL: goto x86_l_113a;
	case 4415ULL: goto x86_l_113f;
	case 4420ULL: goto x86_l_1144;
	case 4425ULL: goto x86_l_1149;
	case 4430ULL: goto x86_l_114e;
	case 4433ULL: goto x86_l_1151;
	case 4439ULL: goto x86_l_1157;
	case 4442ULL: goto x86_l_115a;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4458ULL: goto x86_l_116a;
	case 4462ULL: goto x86_l_116e;
	case 4468ULL: goto x86_l_1174;
	case 4478ULL: goto x86_l_117e;
	case 4482ULL: goto x86_l_1182;
	case 4488ULL: goto x86_l_1188;
	case 4491ULL: goto x86_l_118b;
	case 4497ULL: goto x86_l_1191;
	case 4501ULL: goto x86_l_1195;
	case 4503ULL: goto x86_l_1197;
	case 4508ULL: goto x86_l_119c;
	case 4512ULL: goto x86_l_11a0;
	case 4518ULL: goto x86_l_11a6;
	case 4528ULL: goto x86_l_11b0;
	case 4532ULL: goto x86_l_11b4;
	case 4538ULL: goto x86_l_11ba;
	case 4541ULL: goto x86_l_11bd;
	case 4547ULL: goto x86_l_11c3;
	case 4551ULL: goto x86_l_11c7;
	case 4555ULL: goto x86_l_11cb;
	case 4557ULL: goto x86_l_11cd;
	case 4561ULL: goto x86_l_11d1;
	case 4567ULL: goto x86_l_11d7;
	case 4571ULL: goto x86_l_11db;
	case 4574ULL: goto x86_l_11de;
	case 4580ULL: goto x86_l_11e4;
	case 4584ULL: goto x86_l_11e8;
	case 4586ULL: goto x86_l_11ea;
	case 4590ULL: goto x86_l_11ee;
	case 4596ULL: goto x86_l_11f4;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4609ULL: goto x86_l_1201;
	case 4611ULL: goto x86_l_1203;
	case 4615ULL: goto x86_l_1207;
	case 4621ULL: goto x86_l_120d;
	case 4624ULL: goto x86_l_1210;
	case 4630ULL: goto x86_l_1216;
	case 4634ULL: goto x86_l_121a;
	case 4640ULL: goto x86_l_1220;
	case 4644ULL: goto x86_l_1224;
	case 4650ULL: goto x86_l_122a;
	case 4655ULL: goto x86_l_122f;
	case 4658ULL: goto x86_l_1232;
	case 4660ULL: goto x86_l_1234;
	case 4663ULL: goto x86_l_1237;
	case 4669ULL: goto x86_l_123d;
	case 4673ULL: goto x86_l_1241;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4687ULL: goto x86_l_124f;
	case 4692ULL: goto x86_l_1254;
	case 4698ULL: goto x86_l_125a;
	case 4702ULL: goto x86_l_125e;
	case 4708ULL: goto x86_l_1264;
	case 4711ULL: goto x86_l_1267;
	case 4714ULL: goto x86_l_126a;
	case 4717ULL: goto x86_l_126d;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4724ULL: goto x86_l_1274;
	case 4726ULL: goto x86_l_1276;
	case 4728ULL: goto x86_l_1278;
	case 4730ULL: goto x86_l_127a;
	case 4732ULL: goto x86_l_127c;
	case 4735ULL: goto x86_l_127f;
	case 4737ULL: goto x86_l_1281;
	case 4739ULL: goto x86_l_1283;
	case 4741ULL: goto x86_l_1285;
	case 4744ULL: goto x86_l_1288;
	case 4748ULL: goto x86_l_128c;
	case 4754ULL: goto x86_l_1292;
	case 4757ULL: goto x86_l_1295;
	case 4763ULL: goto x86_l_129b;
	case 4766ULL: goto x86_l_129e;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4777ULL: goto x86_l_12a9;
	case 4781ULL: goto x86_l_12ad;
	case 4784ULL: goto x86_l_12b0;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4798ULL: goto x86_l_12be;
	case 4804ULL: goto x86_l_12c4;
	case 4807ULL: goto x86_l_12c7;
	case 4809ULL: goto x86_l_12c9;
	case 4813ULL: goto x86_l_12cd;
	case 4815ULL: goto x86_l_12cf;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4826ULL: goto x86_l_12da;
	case 4828ULL: goto x86_l_12dc;
	case 4833ULL: goto x86_l_12e1;
	case 4836ULL: goto x86_l_12e4;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4856ULL: goto x86_l_12f8;
	case 4858ULL: goto x86_l_12fa;
	case 4861ULL: goto x86_l_12fd;
	case 4863ULL: goto x86_l_12ff;
	case 4866ULL: goto x86_l_1302;
	case 4868ULL: goto x86_l_1304;
	case 4871ULL: goto x86_l_1307;
	case 4874ULL: goto x86_l_130a;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4886ULL: goto x86_l_1316;
	case 4892ULL: goto x86_l_131c;
	case 4895ULL: goto x86_l_131f;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4909ULL: goto x86_l_132d;
	case 4915ULL: goto x86_l_1333;
	case 4920ULL: goto x86_l_1338;
	case 4923ULL: goto x86_l_133b;
	case 4929ULL: goto x86_l_1341;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d1d:
	/* 0xd1d: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d22:
	/* 0xd22: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d26:
	/* 0xd26: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d2b:
	/* 0xd2b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d30:
	/* 0xd30: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d32:
	/* 0xd32: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_d35:
	/* 0xd35: jle    d5e <generic_fexit_filter_arg+0xd5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d5e;
	}
x86_l_d37:
	/* 0xd37: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_d3a:
	/* 0xd3a: jg     d90 <generic_fexit_filter_arg+0xd90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d90;
	}
x86_l_d3c:
	/* 0xd3c: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_d3f:
	/* 0xd3f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d42:
	/* 0xd42: jb     12f1 <generic_fexit_filter_arg+0x12f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_12f1;
	}
x86_l_d48:
	/* 0xd48: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_d4b:
	/* 0xd4b: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d50:
	/* 0xd50: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d53:
	/* 0xd53: jb     12ea <generic_fexit_filter_arg+0x12ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_12ea;
	}
x86_l_d59:
	/* 0xd59: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_d5e:
	/* 0xd5e: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_d61:
	/* 0xd61: jle    fd4 <generic_fexit_filter_arg+0xfd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fd4;
	}
x86_l_d67:
	/* 0xd67: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d6a:
	/* 0xd6a: jg     12d7 <generic_fexit_filter_arg+0x12d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12d7;
	}
x86_l_d70:
	/* 0xd70: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_d73:
	/* 0xd73: je     12ea <generic_fexit_filter_arg+0x12ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ea;
	}
x86_l_d79:
	/* 0xd79: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d7e:
	/* 0xd7e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d81:
	/* 0xd81: jne    269 <generic_fexit_filter_arg+0x269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 617ULL;
	}
x86_l_d87:
	/* 0xd87: movzx  ebx,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_d8b:
	/* 0xd8b: jmp    1ab0 <generic_fexit_filter_arg+0x1ab0> */
	return 6832ULL;
x86_l_d90:
	/* 0xd90: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d93:
	/* 0xd93: jg     132a <generic_fexit_filter_arg+0x132a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_132a;
	}
x86_l_d99:
	/* 0xd99: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_d9c:
	/* 0xd9c: je     1364 <generic_fexit_filter_arg+0x1364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4964ULL;
	}
x86_l_da2:
	/* 0xda2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_da7:
	/* 0xda7: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_daa:
	/* 0xdaa: je     135a <generic_fexit_filter_arg+0x135a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4954ULL;
	}
x86_l_db0:
	/* 0xdb0: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_db5:
	/* 0xdb5: lea    edx,[rax-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_db8:
	/* 0xdb8: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_dbb:
	/* 0xdbb: jae    180c <generic_fexit_filter_arg+0x180c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6156ULL;
	}
x86_l_dc1:
	/* 0xdc1: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_dc4:
	/* 0xdc4: jne    fa8 <generic_fexit_filter_arg+0xfa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fa8;
	}
x86_l_dca:
	/* 0xdca: mov    rsi,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dce:
	/* 0xdce: mov    rdx,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dd2:
	/* 0xdd2: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_dd5:
	/* 0xdd5: je     de0 <generic_fexit_filter_arg+0xde0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de0;
	}
x86_l_dd7:
	/* 0xdd7: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_dda:
	/* 0xdda: jne    1a11 <generic_fexit_filter_arg+0x1a11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6673ULL;
	}
x86_l_de0:
	/* 0xde0: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de4:
	/* 0xde4: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_de7:
	/* 0xde7: jg     1a23 <generic_fexit_filter_arg+0x1a23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6691ULL;
	}
x86_l_ded:
	/* 0xded: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_df0:
	/* 0xdf0: jle    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 639ULL;
	}
x86_l_df6:
	/* 0xdf6: jmp    1a23 <generic_fexit_filter_arg+0x1a23> */
	return 6691ULL;
x86_l_dfb:
	/* 0xdfb: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_dfe:
	/* 0xdfe: je     142b <generic_fexit_filter_arg+0x142b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5163ULL;
	}
x86_l_e04:
	/* 0xe04: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e09:
	/* 0xe09: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_e0c:
	/* 0xe0c: jne    2cf4 <generic_fexit_filter_arg+0x2cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11508ULL;
	}
x86_l_e12:
	/* 0xe12: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e17:
	/* 0xe17: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e19:
	/* 0xe19: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e1c:
	/* 0xe1c: mov    eax,DWORD PTR [r15+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_e21:
	/* 0xe21: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e25:
	/* 0xe25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e2a:
	/* 0xe2a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e2f:
	/* 0xe2f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_e36:
	/* 0xe36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e38:
	/* 0xe38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e3b:
	/* 0xe3b: je     21b3 <generic_fexit_filter_arg+0x21b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8627ULL;
	}
x86_l_e41:
	/* 0xe41: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_e44:
	/* 0xe44: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e49:
	/* 0xe49: je     eb5 <generic_fexit_filter_arg+0xeb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb5;
	}
x86_l_e4b:
	/* 0xe4b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e50:
	/* 0xe50: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e52:
	/* 0xe52: jmp    e5f <generic_fexit_filter_arg+0xe5f> */
	goto x86_l_e5f;
x86_l_e54:
	/* 0xe54: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e57:
	/* 0xe57: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e5a:
	/* 0xe5a: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_e5d:
	/* 0xe5d: je     eb5 <generic_fexit_filter_arg+0xeb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb5;
	}
x86_l_e5f:
	/* 0xe5f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e61:
	/* 0xe61: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_e65:
	/* 0xe65: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_e68:
	/* 0xe68: jae    e54 <generic_fexit_filter_arg+0xe54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e54;
	}
x86_l_e6a:
	/* 0xe6a: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_e6e:
	/* 0xe6e: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_e70:
	/* 0xe70: je     ead <generic_fexit_filter_arg+0xead> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ead;
	}
x86_l_e72:
	/* 0xe72: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_e77:
	/* 0xe77: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_e7b:
	/* 0xe7b: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_e7e:
	/* 0xe7e: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_e82:
	/* 0xe82: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_e86:
	/* 0xe86: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_e8a:
	/* 0xe8a: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_e8e:
	/* 0xe8e: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_e91:
	/* 0xe91: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_e95:
	/* 0xe95: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_e99:
	/* 0xe99: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_e9d:
	/* 0xe9d: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_ea1:
	/* 0xea1: ja     e54 <generic_fexit_filter_arg+0xe54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e54;
	}
x86_l_ea3:
	/* 0xea3: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ea6:
	/* 0xea6: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_ea9:
	/* 0xea9: je     e61 <generic_fexit_filter_arg+0xe61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e61;
	}
x86_l_eab:
	/* 0xeab: jmp    e54 <generic_fexit_filter_arg+0xe54> */
	goto x86_l_e54;
x86_l_ead:
	/* 0xead: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_eaf:
	/* 0xeaf: jns    2488 <generic_fexit_filter_arg+0x2488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9352ULL;
	}
x86_l_eb5:
	/* 0xeb5: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_eba:
	/* 0xeba: cmp    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_ebe:
	/* 0xebe: jae    ed1 <generic_fexit_filter_arg+0xed1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ed1;
	}
x86_l_ec0:
	/* 0xec0: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_ec4:
	/* 0xec4: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ec7:
	/* 0xec7: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_ecb:
	/* 0xecb: jne    e1c <generic_fexit_filter_arg+0xe1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e1c;
	}
x86_l_ed1:
	/* 0xed1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed3:
	/* 0xed3: jmp    248d <generic_fexit_filter_arg+0x248d> */
	return 9357ULL;
x86_l_ed8:
	/* 0xed8: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_edd:
	/* 0xedd: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee1:
	/* 0xee1: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ee5:
	/* 0xee5: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_ef0:
	/* 0xef0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef5:
	/* 0xef5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_efa:
	/* 0xefa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_f01:
	/* 0xf01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f03:
	/* 0xf03: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_f06:
	/* 0xf06: je     2ce3 <generic_fexit_filter_arg+0x2ce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11491ULL;
	}
x86_l_f0c:
	/* 0xf0c: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_f11:
	/* 0xf11: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f14:
	/* 0xf14: je     2ce5 <generic_fexit_filter_arg+0x2ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11493ULL;
	}
x86_l_f1a:
	/* 0xf1a: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f1f:
	/* 0xf1f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f24:
	/* 0xf24: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f29:
	/* 0xf29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_f30:
	/* 0xf30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f32:
	/* 0xf32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f35:
	/* 0xf35: je     2ce3 <generic_fexit_filter_arg+0x2ce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11491ULL;
	}
x86_l_f3b:
	/* 0xf3b: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_f41:
	/* 0xf41: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_f46:
	/* 0xf46: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_f49:
	/* 0xf49: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_f50:
	/* 0xf50: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f52:
	/* 0xf52: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f55:
	/* 0xf55: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_f59:
	/* 0xf59: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f5c:
	/* 0xf5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f61:
	/* 0xf61: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f66:
	/* 0xf66: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_f68:
	/* 0xf68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6a:
	/* 0xf6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f6f:
	/* 0xf6f: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f74:
	/* 0xf74: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_f77:
	/* 0xf77: jmp    2cd7 <generic_fexit_filter_arg+0x2cd7> */
	return 11479ULL;
x86_l_f7c:
	/* 0xf7c: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_f87:
	/* 0xf87: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_f8d:
	/* 0xf8d: jbe    14d1 <generic_fexit_filter_arg+0x14d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 5329ULL;
	}
x86_l_f93:
	/* 0xf93: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f95:
	/* 0xf95: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f99:
	/* 0xf99: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_f9d:
	/* 0xf9d: jbe    2d02 <generic_fexit_filter_arg+0x2d02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11522ULL;
	}
x86_l_fa3:
	/* 0xfa3: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_fa8:
	/* 0xfa8: mov    rsi,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fac:
	/* 0xfac: mov    rax,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fb0:
	/* 0xfb0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_fb3:
	/* 0xfb3: je     fbe <generic_fexit_filter_arg+0xfbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fbe;
	}
x86_l_fb5:
	/* 0xfb5: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_fb8:
	/* 0xfb8: jne    1a62 <generic_fexit_filter_arg+0x1a62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6754ULL;
	}
x86_l_fbe:
	/* 0xfbe: mov    rdx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc2:
	/* 0xfc2: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_fc5:
	/* 0xfc5: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_fc9:
	/* 0xfc9: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_fcc:
	/* 0xfcc: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_fcf:
	/* 0xfcf: jmp    1a73 <generic_fexit_filter_arg+0x1a73> */
	return 6771ULL;
x86_l_fd4:
	/* 0xfd4: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_fd7:
	/* 0xfd7: je     1364 <generic_fexit_filter_arg+0x1364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4964ULL;
	}
x86_l_fdd:
	/* 0xfdd: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_fe0:
	/* 0xfe0: je     135a <generic_fexit_filter_arg+0x135a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4954ULL;
	}
x86_l_fe6:
	/* 0xfe6: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_feb:
	/* 0xfeb: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_fee:
	/* 0xfee: je     12f1 <generic_fexit_filter_arg+0x12f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f1;
	}
x86_l_ff4:
	/* 0xff4: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_ff9:
	/* 0xff9: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_ffc:
	/* 0xffc: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1001:
	/* 0x1001: jg     157a <generic_fexit_filter_arg+0x157a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5498ULL;
	}
x86_l_1007:
	/* 0x1007: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_100a:
	/* 0x100a: je     1755 <generic_fexit_filter_arg+0x1755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5973ULL;
	}
x86_l_1010:
	/* 0x1010: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1015:
	/* 0x1015: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1018:
	/* 0x1018: jne    2f7d <generic_fexit_filter_arg+0x2f7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12157ULL;
	}
x86_l_101e:
	/* 0x101e: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1022:
	/* 0x1022: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1026:
	/* 0x1026: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1031:
	/* 0x1031: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1036:
	/* 0x1036: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_103b:
	/* 0x103b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1042:
	/* 0x1042: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1044:
	/* 0x1044: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1047:
	/* 0x1047: je     2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12140ULL;
	}
x86_l_104d:
	/* 0x104d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1050:
	/* 0x1050: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1055:
	/* 0x1055: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1058:
	/* 0x1058: je     2f6e <generic_fexit_filter_arg+0x2f6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12142ULL;
	}
x86_l_105e:
	/* 0x105e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1063:
	/* 0x1063: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1068:
	/* 0x1068: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_106f:
	/* 0x106f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1071:
	/* 0x1071: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1074:
	/* 0x1074: je     2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12140ULL;
	}
x86_l_107a:
	/* 0x107a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_107d:
	/* 0x107d: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1082:
	/* 0x1082: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_1085:
	/* 0x1085: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_108a:
	/* 0x108a: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_108d:
	/* 0x108d: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1090:
	/* 0x1090: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1092:
	/* 0x1092: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_1095:
	/* 0x1095: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1098:
	/* 0x1098: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_109d:
	/* 0x109d: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_10a0:
	/* 0x10a0: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_10a3:
	/* 0x10a3: mov    QWORD PTR [rsp+0x68],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10a8:
	/* 0x10a8: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_10ac:
	/* 0x10ac: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_10b2:
	/* 0x10b2: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_10b5:
	/* 0x10b5: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_10b9:
	/* 0x10b9: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_10bf:
	/* 0x10bf: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_10c2:
	/* 0x10c2: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_10c6:
	/* 0x10c6: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_10c9:
	/* 0x10c9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10cc:
	/* 0x10cc: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10d1:
	/* 0x10d1: lea    ebp,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_10d5:
	/* 0x10d5: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10db:
	/* 0x10db: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_10df:
	/* 0x10df: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_10e3:
	/* 0x10e3: cmp    r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_10e6:
	/* 0x10e6: je     113a <generic_fexit_filter_arg+0x113a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113a;
	}
x86_l_10e8:
	/* 0x10e8: lea    ebp,[r11+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_10ec:
	/* 0x10ec: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10f2:
	/* 0x10f2: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_10f6:
	/* 0x10f6: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_10fa:
	/* 0x10fa: cmp    r8,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64);
x86_l_10fd:
	/* 0x10fd: je     113a <generic_fexit_filter_arg+0x113a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113a;
	}
x86_l_10ff:
	/* 0x10ff: lea    ebp,[r9+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1103:
	/* 0x1103: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1109:
	/* 0x1109: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_110d:
	/* 0x110d: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1111:
	/* 0x1111: cmp    rcx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1114:
	/* 0x1114: je     113a <generic_fexit_filter_arg+0x113a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113a;
	}
x86_l_1116:
	/* 0x1116: cmp    r12,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_111a:
	/* 0x111a: je     113a <generic_fexit_filter_arg+0x113a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113a;
	}
x86_l_111c:
	/* 0x111c: lea    ebp,[rdx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1120:
	/* 0x1120: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1126:
	/* 0x1126: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_112a:
	/* 0x112a: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_112d:
	/* 0x112d: add    r12,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1131:
	/* 0x1131: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1135:
	/* 0x1135: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1138:
	/* 0x1138: jne    10d1 <generic_fexit_filter_arg+0x10d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10d1;
	}
x86_l_113a:
	/* 0x113a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_113f:
	/* 0x113f: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1144:
	/* 0x1144: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1149:
	/* 0x1149: jmp    2f60 <generic_fexit_filter_arg+0x2f60> */
	return 12128ULL;
x86_l_114e:
	/* 0x114e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1151:
	/* 0x1151: jne    20f9 <generic_fexit_filter_arg+0x20f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8441ULL;
	}
x86_l_1157:
	/* 0x1157: test   DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115a:
	/* 0x115a: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_1160:
	/* 0x1160: jmp    20f9 <generic_fexit_filter_arg+0x20f9> */
	return 8441ULL;
x86_l_1165:
	/* 0x1165: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_116a:
	/* 0x116a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_116e:
	/* 0x116e: jb     164e <generic_fexit_filter_arg+0x164e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5710ULL;
	}
x86_l_1174:
	/* 0x1174: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_117e:
	/* 0x117e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1182:
	/* 0x1182: jae    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 184ULL;
	}
x86_l_1188:
	/* 0x1188: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_118b:
	/* 0x118b: jne    1d25 <generic_fexit_filter_arg+0x1d25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7461ULL;
	}
x86_l_1191:
	/* 0x1191: movzx  eax,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1195:
	/* 0x1195: jmp    11c7 <generic_fexit_filter_arg+0x11c7> */
	goto x86_l_11c7;
x86_l_1197:
	/* 0x1197: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_119c:
	/* 0x119c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_11a0:
	/* 0x11a0: jb     168e <generic_fexit_filter_arg+0x168e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5774ULL;
	}
x86_l_11a6:
	/* 0x11a6: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_11b0:
	/* 0x11b0: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_11b4:
	/* 0x11b4: jae    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 184ULL;
	}
x86_l_11ba:
	/* 0x11ba: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_11bd:
	/* 0x11bd: jne    1d2f <generic_fexit_filter_arg+0x1d2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7471ULL;
	}
x86_l_11c3:
	/* 0x11c3: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11c7:
	/* 0x11c7: cmp    DWORD PTR [r15+0x10],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11cb:
	/* 0x11cb: ja     11d7 <generic_fexit_filter_arg+0x11d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11d7;
	}
x86_l_11cd:
	/* 0x11cd: cmp    DWORD PTR [r15+0x14],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11d1:
	/* 0x11d1: jae    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 639ULL;
	}
x86_l_11d7:
	/* 0x11d7: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11db:
	/* 0x11db: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_11de:
	/* 0x11de: jb     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 184ULL;
	}
x86_l_11e4:
	/* 0x11e4: cmp    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11e8:
	/* 0x11e8: ja     11f4 <generic_fexit_filter_arg+0x11f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11f4;
	}
x86_l_11ea:
	/* 0x11ea: cmp    DWORD PTR [r15+0x1c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11ee:
	/* 0x11ee: jae    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 639ULL;
	}
x86_l_11f4:
	/* 0x11f4: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_11f7:
	/* 0x11f7: jb     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 184ULL;
	}
x86_l_11fd:
	/* 0x11fd: cmp    DWORD PTR [r15+0x20],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1201:
	/* 0x1201: ja     120d <generic_fexit_filter_arg+0x120d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_120d;
	}
x86_l_1203:
	/* 0x1203: cmp    DWORD PTR [r15+0x24],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1207:
	/* 0x1207: jae    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 639ULL;
	}
x86_l_120d:
	/* 0x120d: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_1210:
	/* 0x1210: jb     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 184ULL;
	}
x86_l_1216:
	/* 0x1216: cmp    DWORD PTR [r15+0x28],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_121a:
	/* 0x121a: ja     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 184ULL;
	}
x86_l_1220:
	/* 0x1220: cmp    DWORD PTR [r15+0x2c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1224:
	/* 0x1224: jae    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 639ULL;
	}
x86_l_122a:
	/* 0x122a: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	return 184ULL;
x86_l_122f:
	/* 0x122f: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1232:
	/* 0x1232: je     123d <generic_fexit_filter_arg+0x123d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_123d;
	}
x86_l_1234:
	/* 0x1234: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1237:
	/* 0x1237: jne    1b37 <generic_fexit_filter_arg+0x1b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6967ULL;
	}
x86_l_123d:
	/* 0x123d: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1241:
	/* 0x1241: jg     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 639ULL;
	}
x86_l_1247:
	/* 0x1247: jmp    1b4d <generic_fexit_filter_arg+0x1b4d> */
	return 6989ULL;
x86_l_124c:
	/* 0x124c: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_124f:
	/* 0x124f: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1254:
	/* 0x1254: ja     1878 <generic_fexit_filter_arg+0x1878> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6264ULL;
	}
x86_l_125a:
	/* 0x125a: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_125e:
	/* 0x125e: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1264:
	/* 0x1264: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1267:
	/* 0x1267: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_126a:
	/* 0x126a: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_126d:
	/* 0x126d: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_126f:
	/* 0x126f: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1271:
	/* 0x1271: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1274:
	/* 0x1274: je     127c <generic_fexit_filter_arg+0x127c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127c;
	}
x86_l_1276:
	/* 0x1276: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1278:
	/* 0x1278: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_127a:
	/* 0x127a: je     1292 <generic_fexit_filter_arg+0x1292> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1292;
	}
x86_l_127c:
	/* 0x127c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_127f:
	/* 0x127f: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1281:
	/* 0x1281: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1283:
	/* 0x1283: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1285:
	/* 0x1285: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1288:
	/* 0x1288: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_128c:
	/* 0x128c: ja     188d <generic_fexit_filter_arg+0x188d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6285ULL;
	}
x86_l_1292:
	/* 0x1292: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1295:
	/* 0x1295: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_129b:
	/* 0x129b: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_129e:
	/* 0x129e: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_12a0:
	/* 0x12a0: jmp    189d <generic_fexit_filter_arg+0x189d> */
	return 6301ULL;
x86_l_12a5:
	/* 0x12a5: mov    esi,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12a9:
	/* 0x12a9: mov    eax,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12ad:
	/* 0x12ad: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_12b0:
	/* 0x12b0: ja     1fa1 <generic_fexit_filter_arg+0x1fa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8097ULL;
	}
x86_l_12b6:
	/* 0x12b6: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_12bb:
	/* 0x12bb: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_12be:
	/* 0x12be: jae    1fa1 <generic_fexit_filter_arg+0x1fa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8097ULL;
	}
x86_l_12c4:
	/* 0x12c4: mov    edx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c7:
	/* 0x12c7: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_12c9:
	/* 0x12c9: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_12cd:
	/* 0x12cd: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_12cf:
	/* 0x12cf: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_12d2:
	/* 0x12d2: jmp    1faf <generic_fexit_filter_arg+0x1faf> */
	return 8111ULL;
x86_l_12d7:
	/* 0x12d7: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_12da:
	/* 0x12da: je     12f1 <generic_fexit_filter_arg+0x12f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f1;
	}
x86_l_12dc:
	/* 0x12dc: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_12e1:
	/* 0x12e1: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_12e4:
	/* 0x12e4: jne    269 <generic_fexit_filter_arg+0x269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 617ULL;
	}
x86_l_12ea:
	/* 0x12ea: movzx  r12d,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_12ef:
	/* 0x12ef: jmp    12f6 <generic_fexit_filter_arg+0x12f6> */
	goto x86_l_12f6;
x86_l_12f1:
	/* 0x12f1: movzx  r12d,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_12f6:
	/* 0x12f6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12f8:
	/* 0x12f8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12fa:
	/* 0x12fa: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12fd:
	/* 0x12fd: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ff:
	/* 0x12ff: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1302:
	/* 0x1302: jg     137c <generic_fexit_filter_arg+0x137c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4988ULL;
	}
x86_l_1304:
	/* 0x1304: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_1307:
	/* 0x1307: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_130a:
	/* 0x130a: jb     13af <generic_fexit_filter_arg+0x13af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5039ULL;
	}
x86_l_1310:
	/* 0x1310: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_1313:
	/* 0x1313: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1316:
	/* 0x1316: jb     1537 <generic_fexit_filter_arg+0x1537> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5431ULL;
	}
x86_l_131c:
	/* 0x131c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_131f:
	/* 0x131f: je     1ab0 <generic_fexit_filter_arg+0x1ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6832ULL;
	}
x86_l_1325:
	/* 0x1325: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_132a:
	/* 0x132a: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_132d:
	/* 0x132d: je     1aac <generic_fexit_filter_arg+0x1aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6828ULL;
	}
x86_l_1333:
	/* 0x1333: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1338:
	/* 0x1338: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_133b:
	/* 0x133b: jne    269 <generic_fexit_filter_arg+0x269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 617ULL;
	}
x86_l_1341:
	/* 0x1341: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
	return 4932ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4932ULL: goto x86_l_1344;
	case 4938ULL: goto x86_l_134a;
	case 4941ULL: goto x86_l_134d;
	case 4947ULL: goto x86_l_1353;
	case 4949ULL: goto x86_l_1355;
	case 4954ULL: goto x86_l_135a;
	case 4958ULL: goto x86_l_135e;
	case 4962ULL: goto x86_l_1362;
	case 4964ULL: goto x86_l_1364;
	case 4967ULL: goto x86_l_1367;
	case 4971ULL: goto x86_l_136b;
	case 4974ULL: goto x86_l_136e;
	case 4978ULL: goto x86_l_1372;
	case 4981ULL: goto x86_l_1375;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4988ULL: goto x86_l_137c;
	case 4991ULL: goto x86_l_137f;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5005ULL: goto x86_l_138d;
	case 5011ULL: goto x86_l_1393;
	case 5016ULL: goto x86_l_1398;
	case 5019ULL: goto x86_l_139b;
	case 5025ULL: goto x86_l_13a1;
	case 5030ULL: goto x86_l_13a6;
	case 5033ULL: goto x86_l_13a9;
	case 5039ULL: goto x86_l_13af;
	case 5043ULL: goto x86_l_13b3;
	case 5046ULL: goto x86_l_13b6;
	case 5052ULL: goto x86_l_13bc;
	case 5055ULL: goto x86_l_13bf;
	case 5061ULL: goto x86_l_13c5;
	case 5064ULL: goto x86_l_13c8;
	case 5068ULL: goto x86_l_13cc;
	case 5072ULL: goto x86_l_13d0;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5089ULL: goto x86_l_13e1;
	case 5091ULL: goto x86_l_13e3;
	case 5094ULL: goto x86_l_13e6;
	case 5100ULL: goto x86_l_13ec;
	case 5103ULL: goto x86_l_13ef;
	case 5114ULL: goto x86_l_13fa;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5129ULL: goto x86_l_1409;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5143ULL: goto x86_l_1417;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5158ULL: goto x86_l_1426;
	case 5163ULL: goto x86_l_142b;
	case 5168ULL: goto x86_l_1430;
	case 5170ULL: goto x86_l_1432;
	case 5173ULL: goto x86_l_1435;
	case 5178ULL: goto x86_l_143a;
	case 5182ULL: goto x86_l_143e;
	case 5187ULL: goto x86_l_1443;
	case 5192ULL: goto x86_l_1448;
	case 5199ULL: goto x86_l_144f;
	case 5201ULL: goto x86_l_1451;
	case 5204ULL: goto x86_l_1454;
	case 5210ULL: goto x86_l_145a;
	case 5213ULL: goto x86_l_145d;
	case 5218ULL: goto x86_l_1462;
	case 5223ULL: goto x86_l_1467;
	case 5225ULL: goto x86_l_1469;
	case 5230ULL: goto x86_l_146e;
	case 5232ULL: goto x86_l_1470;
	case 5234ULL: goto x86_l_1472;
	case 5237ULL: goto x86_l_1475;
	case 5240ULL: goto x86_l_1478;
	case 5243ULL: goto x86_l_147b;
	case 5245ULL: goto x86_l_147d;
	case 5247ULL: goto x86_l_147f;
	case 5251ULL: goto x86_l_1483;
	case 5254ULL: goto x86_l_1486;
	case 5256ULL: goto x86_l_1488;
	case 5260ULL: goto x86_l_148c;
	case 5263ULL: goto x86_l_148f;
	case 5265ULL: goto x86_l_1491;
	case 5269ULL: goto x86_l_1495;
	case 5271ULL: goto x86_l_1497;
	case 5275ULL: goto x86_l_149b;
	case 5279ULL: goto x86_l_149f;
	case 5282ULL: goto x86_l_14a2;
	case 5284ULL: goto x86_l_14a4;
	case 5286ULL: goto x86_l_14a6;
	case 5288ULL: goto x86_l_14a8;
	case 5294ULL: goto x86_l_14ae;
	case 5299ULL: goto x86_l_14b3;
	case 5303ULL: goto x86_l_14b7;
	case 5305ULL: goto x86_l_14b9;
	case 5309ULL: goto x86_l_14bd;
	case 5312ULL: goto x86_l_14c0;
	case 5316ULL: goto x86_l_14c4;
	case 5322ULL: goto x86_l_14ca;
	case 5324ULL: goto x86_l_14cc;
	case 5329ULL: goto x86_l_14d1;
	case 5332ULL: goto x86_l_14d4;
	case 5337ULL: goto x86_l_14d9;
	case 5343ULL: goto x86_l_14df;
	case 5347ULL: goto x86_l_14e3;
	case 5353ULL: goto x86_l_14e9;
	case 5356ULL: goto x86_l_14ec;
	case 5359ULL: goto x86_l_14ef;
	case 5362ULL: goto x86_l_14f2;
	case 5364ULL: goto x86_l_14f4;
	case 5366ULL: goto x86_l_14f6;
	case 5369ULL: goto x86_l_14f9;
	case 5371ULL: goto x86_l_14fb;
	case 5373ULL: goto x86_l_14fd;
	case 5375ULL: goto x86_l_14ff;
	case 5377ULL: goto x86_l_1501;
	case 5380ULL: goto x86_l_1504;
	case 5382ULL: goto x86_l_1506;
	case 5384ULL: goto x86_l_1508;
	case 5386ULL: goto x86_l_150a;
	case 5389ULL: goto x86_l_150d;
	case 5393ULL: goto x86_l_1511;
	case 5399ULL: goto x86_l_1517;
	case 5403ULL: goto x86_l_151b;
	case 5409ULL: goto x86_l_1521;
	case 5412ULL: goto x86_l_1524;
	case 5414ULL: goto x86_l_1526;
	case 5419ULL: goto x86_l_152b;
	case 5422ULL: goto x86_l_152e;
	case 5425ULL: goto x86_l_1531;
	case 5431ULL: goto x86_l_1537;
	case 5436ULL: goto x86_l_153c;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5452ULL: goto x86_l_154c;
	case 5457ULL: goto x86_l_1551;
	case 5459ULL: goto x86_l_1553;
	case 5462ULL: goto x86_l_1556;
	case 5468ULL: goto x86_l_155c;
	case 5471ULL: goto x86_l_155f;
	case 5475ULL: goto x86_l_1563;
	case 5483ULL: goto x86_l_156b;
	case 5488ULL: goto x86_l_1570;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5501ULL: goto x86_l_157d;
	case 5507ULL: goto x86_l_1583;
	case 5512ULL: goto x86_l_1588;
	case 5515ULL: goto x86_l_158b;
	case 5521ULL: goto x86_l_1591;
	case 5527ULL: goto x86_l_1597;
	case 5531ULL: goto x86_l_159b;
	case 5535ULL: goto x86_l_159f;
	case 5540ULL: goto x86_l_15a4;
	case 5545ULL: goto x86_l_15a9;
	case 5552ULL: goto x86_l_15b0;
	case 5554ULL: goto x86_l_15b2;
	case 5557ULL: goto x86_l_15b5;
	case 5563ULL: goto x86_l_15bb;
	case 5568ULL: goto x86_l_15c0;
	case 5571ULL: goto x86_l_15c3;
	case 5574ULL: goto x86_l_15c6;
	case 5579ULL: goto x86_l_15cb;
	case 5581ULL: goto x86_l_15cd;
	case 5587ULL: goto x86_l_15d3;
	case 5591ULL: goto x86_l_15d7;
	case 5596ULL: goto x86_l_15dc;
	case 5600ULL: goto x86_l_15e0;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5615ULL: goto x86_l_15ef;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5633ULL: goto x86_l_1601;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5643ULL: goto x86_l_160b;
	case 5649ULL: goto x86_l_1611;
	case 5652ULL: goto x86_l_1614;
	case 5658ULL: goto x86_l_161a;
	case 5662ULL: goto x86_l_161e;
	case 5664ULL: goto x86_l_1620;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5678ULL: goto x86_l_162e;
	case 5684ULL: goto x86_l_1634;
	case 5687ULL: goto x86_l_1637;
	case 5693ULL: goto x86_l_163d;
	case 5697ULL: goto x86_l_1641;
	case 5699ULL: goto x86_l_1643;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5722ULL: goto x86_l_165a;
	case 5727ULL: goto x86_l_165f;
	case 5732ULL: goto x86_l_1664;
	case 5739ULL: goto x86_l_166b;
	case 5741ULL: goto x86_l_166d;
	case 5744ULL: goto x86_l_1670;
	case 5750ULL: goto x86_l_1676;
	case 5753ULL: goto x86_l_1679;
	case 5757ULL: goto x86_l_167d;
	case 5762ULL: goto x86_l_1682;
	case 5767ULL: goto x86_l_1687;
	case 5772ULL: goto x86_l_168c;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5786ULL: goto x86_l_169a;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5803ULL: goto x86_l_16ab;
	case 5805ULL: goto x86_l_16ad;
	case 5808ULL: goto x86_l_16b0;
	case 5810ULL: goto x86_l_16b2;
	case 5813ULL: goto x86_l_16b5;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5834ULL: goto x86_l_16ca;
	case 5838ULL: goto x86_l_16ce;
	case 5840ULL: goto x86_l_16d0;
	case 5843ULL: goto x86_l_16d3;
	case 5849ULL: goto x86_l_16d9;
	case 5854ULL: goto x86_l_16de;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5867ULL: goto x86_l_16eb;
	case 5872ULL: goto x86_l_16f0;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5883ULL: goto x86_l_16fb;
	case 5888ULL: goto x86_l_1700;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5900ULL: goto x86_l_170c;
	case 5905ULL: goto x86_l_1711;
	case 5910ULL: goto x86_l_1716;
	case 5915ULL: goto x86_l_171b;
	case 5918ULL: goto x86_l_171e;
	case 5920ULL: goto x86_l_1720;
	case 5923ULL: goto x86_l_1723;
	case 5926ULL: goto x86_l_1726;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5937ULL: goto x86_l_1731;
	case 5940ULL: goto x86_l_1734;
	case 5945ULL: goto x86_l_1739;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5965ULL: goto x86_l_174d;
	case 5968ULL: goto x86_l_1750;
	case 5973ULL: goto x86_l_1755;
	case 5977ULL: goto x86_l_1759;
	case 5981ULL: goto x86_l_175d;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6009ULL: goto x86_l_1779;
	case 6011ULL: goto x86_l_177b;
	case 6014ULL: goto x86_l_177e;
	case 6020ULL: goto x86_l_1784;
	case 6023ULL: goto x86_l_1787;
	case 6028ULL: goto x86_l_178c;
	case 6031ULL: goto x86_l_178f;
	case 6037ULL: goto x86_l_1795;
	case 6042ULL: goto x86_l_179a;
	case 6047ULL: goto x86_l_179f;
	case 6054ULL: goto x86_l_17a6;
	case 6056ULL: goto x86_l_17a8;
	case 6059ULL: goto x86_l_17ab;
	case 6065ULL: goto x86_l_17b1;
	case 6071ULL: goto x86_l_17b7;
	case 6076ULL: goto x86_l_17bc;
	case 6079ULL: goto x86_l_17bf;
	case 6086ULL: goto x86_l_17c6;
	case 6088ULL: goto x86_l_17c8;
	case 6091ULL: goto x86_l_17cb;
	case 6095ULL: goto x86_l_17cf;
	case 6098ULL: goto x86_l_17d2;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6110ULL: goto x86_l_17de;
	case 6115ULL: goto x86_l_17e3;
	case 6118ULL: goto x86_l_17e6;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6137ULL: goto x86_l_17f9;
	case 6143ULL: goto x86_l_17ff;
	case 6149ULL: goto x86_l_1805;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6159ULL: goto x86_l_180f;
	case 6165ULL: goto x86_l_1815;
	case 6169ULL: goto x86_l_1819;
	case 6172ULL: goto x86_l_181c;
	case 6174ULL: goto x86_l_181e;
	case 6183ULL: goto x86_l_1827;
	case 6189ULL: goto x86_l_182d;
	case 6193ULL: goto x86_l_1831;
	case 6201ULL: goto x86_l_1839;
	case 6206ULL: goto x86_l_183e;
	case 6208ULL: goto x86_l_1840;
	case 6218ULL: goto x86_l_184a;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6230ULL: goto x86_l_1856;
	case 6232ULL: goto x86_l_1858;
	case 6237ULL: goto x86_l_185d;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6249ULL: goto x86_l_1869;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6282ULL: goto x86_l_188a;
	case 6285ULL: goto x86_l_188d;
	case 6288ULL: goto x86_l_1890;
	case 6290ULL: goto x86_l_1892;
	case 6295ULL: goto x86_l_1897;
	case 6298ULL: goto x86_l_189a;
	case 6301ULL: goto x86_l_189d;
	case 6303ULL: goto x86_l_189f;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6314ULL: goto x86_l_18aa;
	case 6320ULL: goto x86_l_18b0;
	case 6324ULL: goto x86_l_18b4;
	case 6328ULL: goto x86_l_18b8;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6344ULL: goto x86_l_18c8;
	case 6349ULL: goto x86_l_18cd;
	case 6352ULL: goto x86_l_18d0;
	case 6354ULL: goto x86_l_18d2;
	case 6357ULL: goto x86_l_18d5;
	case 6362ULL: goto x86_l_18da;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6374ULL: goto x86_l_18e6;
	case 6377ULL: goto x86_l_18e9;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6391ULL: goto x86_l_18f7;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6412ULL: goto x86_l_190c;
	case 6415ULL: goto x86_l_190f;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6432ULL: goto x86_l_1920;
	case 6437ULL: goto x86_l_1925;
	case 6442ULL: goto x86_l_192a;
	case 6448ULL: goto x86_l_1930;
	case 6451ULL: goto x86_l_1933;
	case 6454ULL: goto x86_l_1936;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6465ULL: goto x86_l_1941;
	case 6467ULL: goto x86_l_1943;
	case 6469ULL: goto x86_l_1945;
	case 6475ULL: goto x86_l_194b;
	case 6479ULL: goto x86_l_194f;
	case 6482ULL: goto x86_l_1952;
	case 6484ULL: goto x86_l_1954;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6503ULL: goto x86_l_1967;
	case 6508ULL: goto x86_l_196c;
	case 6511ULL: goto x86_l_196f;
	case 6514ULL: goto x86_l_1972;
	case 6518ULL: goto x86_l_1976;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1344:
	/* 0x1344: jne    2086 <generic_fexit_filter_arg+0x2086> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8326ULL;
	}
x86_l_134a:
	/* 0x134a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_134d:
	/* 0x134d: jne    2092 <generic_fexit_filter_arg+0x2092> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8338ULL;
	}
x86_l_1353:
	/* 0x1353: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1355:
	/* 0x1355: jmp    20a4 <generic_fexit_filter_arg+0x20a4> */
	return 8356ULL;
x86_l_135a:
	/* 0x135a: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_135e:
	/* 0x135e: mov    r8,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1362:
	/* 0x1362: jmp    136b <generic_fexit_filter_arg+0x136b> */
	goto x86_l_136b;
x86_l_1364:
	/* 0x1364: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1367:
	/* 0x1367: mov    r8,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_136b:
	/* 0x136b: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_136e:
	/* 0x136e: shr    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1372:
	/* 0x1372: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1375:
	/* 0x1375: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1377:
	/* 0x1377: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_137a:
	/* 0x137a: jle    1304 <generic_fexit_filter_arg+0x1304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4868ULL;
	}
x86_l_137c:
	/* 0x137c: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_137f:
	/* 0x137f: ja     152b <generic_fexit_filter_arg+0x152b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_152b;
	}
x86_l_1385:
	/* 0x1385: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_138a:
	/* 0x138a: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_138d:
	/* 0x138d: jb     1852 <generic_fexit_filter_arg+0x1852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1852;
	}
x86_l_1393:
	/* 0x1393: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_1398:
	/* 0x1398: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_139b:
	/* 0x139b: jb     1865 <generic_fexit_filter_arg+0x1865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1865;
	}
x86_l_13a1:
	/* 0x13a1: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_13a6:
	/* 0x13a6: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_13a9:
	/* 0x13a9: jae    152b <generic_fexit_filter_arg+0x152b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_152b;
	}
x86_l_13af:
	/* 0x13af: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_13b3:
	/* 0x13b3: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_13b6:
	/* 0x13b6: je     196c <generic_fexit_filter_arg+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_196c;
	}
x86_l_13bc:
	/* 0x13bc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13bf:
	/* 0x13bf: jne    1a07 <generic_fexit_filter_arg+0x1a07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6663ULL;
	}
x86_l_13c5:
	/* 0x13c5: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_13c8:
	/* 0x13c8: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13cc:
	/* 0x13cc: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_13d0:
	/* 0x13d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d5:
	/* 0x13d5: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_13da:
	/* 0x13da: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_13e1:
	/* 0x13e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e3:
	/* 0x13e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13e6:
	/* 0x13e6: je     1bff <generic_fexit_filter_arg+0x1bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7167ULL;
	}
x86_l_13ec:
	/* 0x13ec: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13ef:
	/* 0x13ef: mov    DWORD PTR [rsp+0x80],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813920ULL);
x86_l_13fa:
	/* 0x13fa: mov    DWORD PTR [rsp+0x84],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1401:
	/* 0x1401: jmp    19c6 <generic_fexit_filter_arg+0x19c6> */
	return 6598ULL;
x86_l_1406:
	/* 0x1406: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1409:
	/* 0x1409: ja     20e5 <generic_fexit_filter_arg+0x20e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8421ULL;
	}
x86_l_140f:
	/* 0x140f: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_1414:
	/* 0x1414: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1417:
	/* 0x1417: jae    20e5 <generic_fexit_filter_arg+0x20e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8421ULL;
	}
x86_l_141d:
	/* 0x141d: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1420:
	/* 0x1420: jg     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 639ULL;
	}
x86_l_1426:
	/* 0x1426: jmp    20f9 <generic_fexit_filter_arg+0x20f9> */
	return 8441ULL;
x86_l_142b:
	/* 0x142b: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1430:
	/* 0x1430: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1432:
	/* 0x1432: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1435:
	/* 0x1435: mov    eax,DWORD PTR [r15+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_143a:
	/* 0x143a: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_143e:
	/* 0x143e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1443:
	/* 0x1443: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1448:
	/* 0x1448: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_144f:
	/* 0x144f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1451:
	/* 0x1451: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1454:
	/* 0x1454: je     21a2 <generic_fexit_filter_arg+0x21a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8610ULL;
	}
x86_l_145a:
	/* 0x145a: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_145d:
	/* 0x145d: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1462:
	/* 0x1462: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1467:
	/* 0x1467: je     14ae <generic_fexit_filter_arg+0x14ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ae;
	}
x86_l_1469:
	/* 0x1469: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_146e:
	/* 0x146e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1470:
	/* 0x1470: jmp    147d <generic_fexit_filter_arg+0x147d> */
	goto x86_l_147d;
x86_l_1472:
	/* 0x1472: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1475:
	/* 0x1475: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1478:
	/* 0x1478: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_147b:
	/* 0x147b: je     14ae <generic_fexit_filter_arg+0x14ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14ae;
	}
x86_l_147d:
	/* 0x147d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_147f:
	/* 0x147f: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1483:
	/* 0x1483: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1486:
	/* 0x1486: jae    1472 <generic_fexit_filter_arg+0x1472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1472;
	}
x86_l_1488:
	/* 0x1488: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_148c:
	/* 0x148c: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_148f:
	/* 0x148f: je     14a6 <generic_fexit_filter_arg+0x14a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a6;
	}
x86_l_1491:
	/* 0x1491: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1495:
	/* 0x1495: ja     1472 <generic_fexit_filter_arg+0x1472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1472;
	}
x86_l_1497:
	/* 0x1497: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_149b:
	/* 0x149b: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_149f:
	/* 0x149f: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_14a2:
	/* 0x14a2: je     147f <generic_fexit_filter_arg+0x147f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_147f;
	}
x86_l_14a4:
	/* 0x14a4: jmp    1472 <generic_fexit_filter_arg+0x1472> */
	goto x86_l_1472;
x86_l_14a6:
	/* 0x14a6: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_14a8:
	/* 0x14a8: jns    2466 <generic_fexit_filter_arg+0x2466> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9318ULL;
	}
x86_l_14ae:
	/* 0x14ae: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14b3:
	/* 0x14b3: cmp    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_14b7:
	/* 0x14b7: jae    14ca <generic_fexit_filter_arg+0x14ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_14ca;
	}
x86_l_14b9:
	/* 0x14b9: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_14bd:
	/* 0x14bd: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_14c0:
	/* 0x14c0: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_14c4:
	/* 0x14c4: jne    1435 <generic_fexit_filter_arg+0x1435> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1435;
	}
x86_l_14ca:
	/* 0x14ca: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14cc:
	/* 0x14cc: jmp    246b <generic_fexit_filter_arg+0x246b> */
	return 9323ULL;
x86_l_14d1:
	/* 0x14d1: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_14d4:
	/* 0x14d4: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_14d9:
	/* 0x14d9: ja     1c0e <generic_fexit_filter_arg+0x1c0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7182ULL;
	}
x86_l_14df:
	/* 0x14df: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_14e3:
	/* 0x14e3: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_14e9:
	/* 0x14e9: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_14ec:
	/* 0x14ec: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_14ef:
	/* 0x14ef: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_14f2:
	/* 0x14f2: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_14f4:
	/* 0x14f4: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_14f6:
	/* 0x14f6: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_14f9:
	/* 0x14f9: je     1501 <generic_fexit_filter_arg+0x1501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1501;
	}
x86_l_14fb:
	/* 0x14fb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_14fd:
	/* 0x14fd: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_14ff:
	/* 0x14ff: je     1517 <generic_fexit_filter_arg+0x1517> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1517;
	}
x86_l_1501:
	/* 0x1501: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1504:
	/* 0x1504: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1506:
	/* 0x1506: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1508:
	/* 0x1508: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_150a:
	/* 0x150a: add    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_150d:
	/* 0x150d: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1511:
	/* 0x1511: ja     1c23 <generic_fexit_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7203ULL;
	}
x86_l_1517:
	/* 0x1517: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_151b:
	/* 0x151b: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1521:
	/* 0x1521: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1524:
	/* 0x1524: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1526:
	/* 0x1526: jmp    1c33 <generic_fexit_filter_arg+0x1c33> */
	return 7219ULL;
x86_l_152b:
	/* 0x152b: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_152e:
	/* 0x152e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1531:
	/* 0x1531: jae    269 <generic_fexit_filter_arg+0x269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 617ULL;
	}
x86_l_1537:
	/* 0x1537: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_153c:
	/* 0x153c: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1540:
	/* 0x1540: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1545:
	/* 0x1545: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_154c:
	/* 0x154c: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1551:
	/* 0x1551: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1553:
	/* 0x1553: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1556:
	/* 0x1556: je     258 <generic_fexit_filter_arg+0x258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 600ULL;
	}
x86_l_155c:
	/* 0x155c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_155f:
	/* 0x155f: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1563:
	/* 0x1563: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_156b:
	/* 0x156b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1570:
	/* 0x1570: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1575:
	/* 0x1575: jmp    1aed <generic_fexit_filter_arg+0x1aed> */
	return 6893ULL;
x86_l_157a:
	/* 0x157a: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_157d:
	/* 0x157d: je     1da7 <generic_fexit_filter_arg+0x1da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7591ULL;
	}
x86_l_1583:
	/* 0x1583: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1588:
	/* 0x1588: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_158b:
	/* 0x158b: jne    2f7d <generic_fexit_filter_arg+0x2f7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12157ULL;
	}
x86_l_1591:
	/* 0x1591: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_1597:
	/* 0x1597: mov    eax,DWORD PTR [r15+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_159b:
	/* 0x159b: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_159f:
	/* 0x159f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a4:
	/* 0x15a4: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15a9:
	/* 0x15a9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_15b0:
	/* 0x15b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b2:
	/* 0x15b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15b5:
	/* 0x15b5: je     2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12140ULL;
	}
x86_l_15bb:
	/* 0x15bb: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15c0:
	/* 0x15c0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_15c3:
	/* 0x15c3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_15c6:
	/* 0x15c6: call   0 <generic_fexit_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 5579ULL);
	__x86_sim_call_depth++;
	return 12293ULL;
x86_l_15cb:
	/* 0x15cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15cd:
	/* 0x15cd: jns    277d <generic_fexit_filter_arg+0x277d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10109ULL;
	}
x86_l_15d3:
	/* 0x15d3: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_15d7:
	/* 0x15d7: lea    eax,[r12-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_15dc:
	/* 0x15dc: cmp    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_15e0:
	/* 0x15e0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e5:
	/* 0x15e5: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ea:
	/* 0x15ea: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15ef:
	/* 0x15ef: jae    1805 <generic_fexit_filter_arg+0x1805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1805;
	}
x86_l_15f5:
	/* 0x15f5: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_15fa:
	/* 0x15fa: cmp    r12,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 416ULL);
x86_l_1601:
	/* 0x1601: jne    1597 <generic_fexit_filter_arg+0x1597> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1597;
	}
x86_l_1603:
	/* 0x1603: jmp    2f7d <generic_fexit_filter_arg+0x2f7d> */
	return 12157ULL;
x86_l_1608:
	/* 0x1608: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_160b:
	/* 0x160b: je     1ea7 <generic_fexit_filter_arg+0x1ea7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7847ULL;
	}
x86_l_1611:
	/* 0x1611: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1614:
	/* 0x1614: jne    1eb3 <generic_fexit_filter_arg+0x1eb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7859ULL;
	}
x86_l_161a:
	/* 0x161a: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_161e:
	/* 0x161e: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1620:
	/* 0x1620: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_1626:
	/* 0x1626: jmp    1eb3 <generic_fexit_filter_arg+0x1eb3> */
	return 7859ULL;
x86_l_162b:
	/* 0x162b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_162e:
	/* 0x162e: je     1eea <generic_fexit_filter_arg+0x1eea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7914ULL;
	}
x86_l_1634:
	/* 0x1634: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1637:
	/* 0x1637: jne    1ef6 <generic_fexit_filter_arg+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7926ULL;
	}
x86_l_163d:
	/* 0x163d: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1641:
	/* 0x1641: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1643:
	/* 0x1643: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_1649:
	/* 0x1649: jmp    1ef6 <generic_fexit_filter_arg+0x1ef6> */
	return 7926ULL;
x86_l_164e:
	/* 0x164e: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1653:
	/* 0x1653: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_165a:
	/* 0x165a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_165f:
	/* 0x165f: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1664:
	/* 0x1664: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_166b:
	/* 0x166b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166d:
	/* 0x166d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1670:
	/* 0x1670: je     1700 <generic_fexit_filter_arg+0x1700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1700;
	}
x86_l_1676:
	/* 0x1676: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1679:
	/* 0x1679: movzx  eax,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_167d:
	/* 0x167d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1682:
	/* 0x1682: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1687:
	/* 0x1687: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_168c:
	/* 0x168c: jmp    16c8 <generic_fexit_filter_arg+0x16c8> */
	goto x86_l_16c8;
x86_l_168e:
	/* 0x168e: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1693:
	/* 0x1693: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_169a:
	/* 0x169a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_169f:
	/* 0x169f: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16a4:
	/* 0x16a4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_16ab:
	/* 0x16ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ad:
	/* 0x16ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b0:
	/* 0x16b0: je     1700 <generic_fexit_filter_arg+0x1700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1700;
	}
x86_l_16b2:
	/* 0x16b2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_16b5:
	/* 0x16b5: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16b9:
	/* 0x16b9: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16be:
	/* 0x16be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16c3:
	/* 0x16c3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16c8:
	/* 0x16c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ca:
	/* 0x16ca: mov    edx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16ce:
	/* 0x16ce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16d0:
	/* 0x16d0: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_16d3:
	/* 0x16d3: ja     26cf <generic_fexit_filter_arg+0x26cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9935ULL;
	}
x86_l_16d9:
	/* 0x16d9: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_16de:
	/* 0x16de: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_16e1:
	/* 0x16e1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e6:
	/* 0x16e6: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16eb:
	/* 0x16eb: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16f0:
	/* 0x16f0: jae    1716 <generic_fexit_filter_arg+0x1716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1716;
	}
x86_l_16f2:
	/* 0x16f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16f5:
	/* 0x16f5: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_16f8:
	/* 0x16f8: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16fb:
	/* 0x16fb: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_1700:
	/* 0x1700: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1702:
	/* 0x1702: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1707:
	/* 0x1707: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_170c:
	/* 0x170c: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1711:
	/* 0x1711: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_1716:
	/* 0x1716: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_171b:
	/* 0x171b: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_171e:
	/* 0x171e: jae    1726 <generic_fexit_filter_arg+0x1726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1726;
	}
x86_l_1720:
	/* 0x1720: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1723:
	/* 0x1723: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1726:
	/* 0x1726: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1729:
	/* 0x1729: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_172e:
	/* 0x172e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1731:
	/* 0x1731: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1734:
	/* 0x1734: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1739:
	/* 0x1739: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_173e:
	/* 0x173e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1743:
	/* 0x1743: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1746:
	/* 0x1746: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_174b:
	/* 0x174b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_174d:
	/* 0x174d: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1750:
	/* 0x1750: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_1755:
	/* 0x1755: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1759:
	/* 0x1759: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_175d:
	/* 0x175d: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1768:
	/* 0x1768: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_176d:
	/* 0x176d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1772:
	/* 0x1772: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1779:
	/* 0x1779: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177b:
	/* 0x177b: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_177e:
	/* 0x177e: je     2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12140ULL;
	}
x86_l_1784:
	/* 0x1784: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1787:
	/* 0x1787: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_178c:
	/* 0x178c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_178f:
	/* 0x178f: je     2f6e <generic_fexit_filter_arg+0x2f6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12142ULL;
	}
x86_l_1795:
	/* 0x1795: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_179a:
	/* 0x179a: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_179f:
	/* 0x179f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_17a6:
	/* 0x17a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a8:
	/* 0x17a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17ab:
	/* 0x17ab: je     2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12140ULL;
	}
x86_l_17b1:
	/* 0x17b1: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_17b7:
	/* 0x17b7: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_17bc:
	/* 0x17bc: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_17bf:
	/* 0x17bf: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_17c6:
	/* 0x17c6: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c8:
	/* 0x17c8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_17cb:
	/* 0x17cb: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_17cf:
	/* 0x17cf: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_17d2:
	/* 0x17d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d7:
	/* 0x17d7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17dc:
	/* 0x17dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17de:
	/* 0x17de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17e3:
	/* 0x17e3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_17e6:
	/* 0x17e6: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_17e9:
	/* 0x17e9: jmp    2f60 <generic_fexit_filter_arg+0x2f60> */
	return 12128ULL;
x86_l_17ee:
	/* 0x17ee: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_17f9:
	/* 0x17f9: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_17ff:
	/* 0x17ff: jbe    1e4d <generic_fexit_filter_arg+0x1e4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7757ULL;
	}
x86_l_1805:
	/* 0x1805: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1807:
	/* 0x1807: jmp    2f7d <generic_fexit_filter_arg+0x2f7d> */
	return 12157ULL;
x86_l_180c:
	/* 0x180c: cmp    eax,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_180f:
	/* 0x180f: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_1815:
	/* 0x1815: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1819:
	/* 0x1819: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_181c:
	/* 0x181c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_181e:
	/* 0x181e: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_1827:
	/* 0x1827: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_182d:
	/* 0x182d: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1831:
	/* 0x1831: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1839:
	/* 0x1839: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_183e:
	/* 0x183e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1840:
	/* 0x1840: andn   rax,rcx,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_184a:
	/* 0x184a: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_184d:
	/* 0x184d: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_1852:
	/* 0x1852: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1856:
	/* 0x1856: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1858:
	/* 0x1858: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_185d:
	/* 0x185d: setb   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_B);
x86_l_1860:
	/* 0x1860: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_1865:
	/* 0x1865: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1869:
	/* 0x1869: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_186b:
	/* 0x186b: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_1870:
	/* 0x1870: setae  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_AE);
x86_l_1873:
	/* 0x1873: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_1878:
	/* 0x1878: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_187b:
	/* 0x187b: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1880:
	/* 0x1880: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1885:
	/* 0x1885: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_188a:
	/* 0x188a: cmovae edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_188d:
	/* 0x188d: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1890:
	/* 0x1890: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1892:
	/* 0x1892: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1897:
	/* 0x1897: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_189a:
	/* 0x189a: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_189d:
	/* 0x189d: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_189f:
	/* 0x189f: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_18a2:
	/* 0x18a2: mov    eax,DWORD PTR [r15+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_18a7:
	/* 0x18a7: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_18aa:
	/* 0x18aa: je     2b3b <generic_fexit_filter_arg+0x2b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11067ULL;
	}
x86_l_18b0:
	/* 0x18b0: mov    DWORD PTR [rsp+0x7c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_18b4:
	/* 0x18b4: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_18b8:
	/* 0x18b8: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18bc:
	/* 0x18bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18c1:
	/* 0x18c1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_18c8:
	/* 0x18c8: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18cd:
	/* 0x18cd: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_18d0:
	/* 0x18d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d2:
	/* 0x18d2: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_18d5:
	/* 0x18d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18da:
	/* 0x18da: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_18e1:
	/* 0x18e1: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_18e4:
	/* 0x18e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e6:
	/* 0x18e6: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_18e9:
	/* 0x18e9: je     2b3b <generic_fexit_filter_arg+0x2b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11067ULL;
	}
x86_l_18ef:
	/* 0x18ef: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_18f4:
	/* 0x18f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18f7:
	/* 0x18f7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18fc:
	/* 0x18fc: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1901:
	/* 0x1901: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1906:
	/* 0x1906: je     2b4c <generic_fexit_filter_arg+0x2b4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11084ULL;
	}
x86_l_190c:
	/* 0x190c: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_190f:
	/* 0x190f: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1917:
	/* 0x1917: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_191c:
	/* 0x191c: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1920:
	/* 0x1920: movzx  ebx,WORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 124ULL);
x86_l_1925:
	/* 0x1925: cmp    DWORD PTR [rsp+0x28],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691845ULL);
x86_l_192a:
	/* 0x192a: jg     2205 <generic_fexit_filter_arg+0x2205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8709ULL;
	}
x86_l_1930:
	/* 0x1930: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1933:
	/* 0x1933: mov    BYTE PTR [rcx],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1936:
	/* 0x1936: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_193a:
	/* 0x193a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_193f:
	/* 0x193f: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1941:
	/* 0x1941: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1943:
	/* 0x1943: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_1945:
	/* 0x1945: jbe    223d <generic_fexit_filter_arg+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8765ULL;
	}
x86_l_194b:
	/* 0x194b: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_194f:
	/* 0x194f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1952:
	/* 0x1952: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1954:
	/* 0x1954: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_195a:
	/* 0x195a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_195f:
	/* 0x195f: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1967:
	/* 0x1967: jmp    2239 <generic_fexit_filter_arg+0x2239> */
	return 8761ULL;
x86_l_196c:
	/* 0x196c: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_196f:
	/* 0x196f: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_1972:
	/* 0x1972: mov    eax,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1976:
	/* 0x1976: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_197a:
	/* 0x197a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_197f:
	/* 0x197f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_1986:
	/* 0x1986: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_198b:
	/* 0x198b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 6541ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6541ULL: goto x86_l_198d;
	case 6544ULL: goto x86_l_1990;
	case 6550ULL: goto x86_l_1996;
	case 6553ULL: goto x86_l_1999;
	case 6564ULL: goto x86_l_19a4;
	case 6571ULL: goto x86_l_19ab;
	case 6578ULL: goto x86_l_19b2;
	case 6586ULL: goto x86_l_19ba;
	case 6590ULL: goto x86_l_19be;
	case 6598ULL: goto x86_l_19c6;
	case 6603ULL: goto x86_l_19cb;
	case 6608ULL: goto x86_l_19d0;
	case 6610ULL: goto x86_l_19d2;
	case 6614ULL: goto x86_l_19d6;
	case 6617ULL: goto x86_l_19d9;
	case 6620ULL: goto x86_l_19dc;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6632ULL: goto x86_l_19e8;
	case 6637ULL: goto x86_l_19ed;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6655ULL: goto x86_l_19ff;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6665ULL: goto x86_l_1a09;
	case 6668ULL: goto x86_l_1a0c;
	case 6673ULL: goto x86_l_1a11;
	case 6677ULL: goto x86_l_1a15;
	case 6680ULL: goto x86_l_1a18;
	case 6682ULL: goto x86_l_1a1a;
	case 6685ULL: goto x86_l_1a1d;
	case 6691ULL: goto x86_l_1a23;
	case 6695ULL: goto x86_l_1a27;
	case 6698ULL: goto x86_l_1a2a;
	case 6704ULL: goto x86_l_1a30;
	case 6708ULL: goto x86_l_1a34;
	case 6712ULL: goto x86_l_1a38;
	case 6715ULL: goto x86_l_1a3b;
	case 6717ULL: goto x86_l_1a3d;
	case 6720ULL: goto x86_l_1a40;
	case 6726ULL: goto x86_l_1a46;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6740ULL: goto x86_l_1a54;
	case 6743ULL: goto x86_l_1a57;
	case 6749ULL: goto x86_l_1a5d;
	case 6754ULL: goto x86_l_1a62;
	case 6758ULL: goto x86_l_1a66;
	case 6761ULL: goto x86_l_1a69;
	case 6765ULL: goto x86_l_1a6d;
	case 6768ULL: goto x86_l_1a70;
	case 6771ULL: goto x86_l_1a73;
	case 6774ULL: goto x86_l_1a76;
	case 6778ULL: goto x86_l_1a7a;
	case 6781ULL: goto x86_l_1a7d;
	case 6787ULL: goto x86_l_1a83;
	case 6791ULL: goto x86_l_1a87;
	case 6795ULL: goto x86_l_1a8b;
	case 6798ULL: goto x86_l_1a8e;
	case 6800ULL: goto x86_l_1a90;
	case 6803ULL: goto x86_l_1a93;
	case 6809ULL: goto x86_l_1a99;
	case 6812ULL: goto x86_l_1a9c;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6869ULL: goto x86_l_1ad5;
	case 6872ULL: goto x86_l_1ad8;
	case 6875ULL: goto x86_l_1adb;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6895ULL: goto x86_l_1aef;
	case 6899ULL: goto x86_l_1af3;
	case 6901ULL: goto x86_l_1af5;
	case 6904ULL: goto x86_l_1af8;
	case 6910ULL: goto x86_l_1afe;
	case 6915ULL: goto x86_l_1b03;
	case 6918ULL: goto x86_l_1b06;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6935ULL: goto x86_l_1b17;
	case 6938ULL: goto x86_l_1b1a;
	case 6941ULL: goto x86_l_1b1d;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6951ULL: goto x86_l_1b27;
	case 6953ULL: goto x86_l_1b29;
	case 6956ULL: goto x86_l_1b2c;
	case 6959ULL: goto x86_l_1b2f;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6971ULL: goto x86_l_1b3b;
	case 6977ULL: goto x86_l_1b41;
	case 6979ULL: goto x86_l_1b43;
	case 6983ULL: goto x86_l_1b47;
	case 6989ULL: goto x86_l_1b4d;
	case 6993ULL: goto x86_l_1b51;
	case 6996ULL: goto x86_l_1b54;
	case 7002ULL: goto x86_l_1b5a;
	case 7006ULL: goto x86_l_1b5e;
	case 7009ULL: goto x86_l_1b61;
	case 7011ULL: goto x86_l_1b63;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7019ULL: goto x86_l_1b6b;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7042ULL: goto x86_l_1b82;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7057ULL: goto x86_l_1b91;
	case 7060ULL: goto x86_l_1b94;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7071ULL: goto x86_l_1b9f;
	case 7075ULL: goto x86_l_1ba3;
	case 7081ULL: goto x86_l_1ba9;
	case 7086ULL: goto x86_l_1bae;
	case 7089ULL: goto x86_l_1bb1;
	case 7094ULL: goto x86_l_1bb6;
	case 7100ULL: goto x86_l_1bbc;
	case 7104ULL: goto x86_l_1bc0;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7118ULL: goto x86_l_1bce;
	case 7124ULL: goto x86_l_1bd4;
	case 7128ULL: goto x86_l_1bd8;
	case 7130ULL: goto x86_l_1bda;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7144ULL: goto x86_l_1be8;
	case 7150ULL: goto x86_l_1bee;
	case 7154ULL: goto x86_l_1bf2;
	case 7156ULL: goto x86_l_1bf4;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7171ULL: goto x86_l_1c03;
	case 7174ULL: goto x86_l_1c06;
	case 7177ULL: goto x86_l_1c09;
	case 7182ULL: goto x86_l_1c0e;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7195ULL: goto x86_l_1c1b;
	case 7200ULL: goto x86_l_1c20;
	case 7203ULL: goto x86_l_1c23;
	case 7206ULL: goto x86_l_1c26;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7216ULL: goto x86_l_1c30;
	case 7219ULL: goto x86_l_1c33;
	case 7221ULL: goto x86_l_1c35;
	case 7224ULL: goto x86_l_1c38;
	case 7229ULL: goto x86_l_1c3d;
	case 7232ULL: goto x86_l_1c40;
	case 7238ULL: goto x86_l_1c46;
	case 7245ULL: goto x86_l_1c4d;
	case 7249ULL: goto x86_l_1c51;
	case 7253ULL: goto x86_l_1c55;
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	case 7270ULL: goto x86_l_1c66;
	case 7275ULL: goto x86_l_1c6b;
	case 7278ULL: goto x86_l_1c6e;
	case 7280ULL: goto x86_l_1c70;
	case 7285ULL: goto x86_l_1c75;
	case 7290ULL: goto x86_l_1c7a;
	case 7297ULL: goto x86_l_1c81;
	case 7300ULL: goto x86_l_1c84;
	case 7302ULL: goto x86_l_1c86;
	case 7308ULL: goto x86_l_1c8c;
	case 7314ULL: goto x86_l_1c92;
	case 7319ULL: goto x86_l_1c97;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7343ULL: goto x86_l_1caf;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7357ULL: goto x86_l_1cbd;
	case 7362ULL: goto x86_l_1cc2;
	case 7365ULL: goto x86_l_1cc5;
	case 7369ULL: goto x86_l_1cc9;
	case 7374ULL: goto x86_l_1cce;
	case 7379ULL: goto x86_l_1cd3;
	case 7381ULL: goto x86_l_1cd5;
	case 7383ULL: goto x86_l_1cd7;
	case 7391ULL: goto x86_l_1cdf;
	case 7393ULL: goto x86_l_1ce1;
	case 7399ULL: goto x86_l_1ce7;
	case 7404ULL: goto x86_l_1cec;
	case 7408ULL: goto x86_l_1cf0;
	case 7411ULL: goto x86_l_1cf3;
	case 7413ULL: goto x86_l_1cf5;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7435ULL: goto x86_l_1d0b;
	case 7437ULL: goto x86_l_1d0d;
	case 7440ULL: goto x86_l_1d10;
	case 7446ULL: goto x86_l_1d16;
	case 7450ULL: goto x86_l_1d1a;
	case 7456ULL: goto x86_l_1d20;
	case 7461ULL: goto x86_l_1d25;
	case 7465ULL: goto x86_l_1d29;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7475ULL: goto x86_l_1d33;
	case 7479ULL: goto x86_l_1d37;
	case 7483ULL: goto x86_l_1d3b;
	case 7487ULL: goto x86_l_1d3f;
	case 7491ULL: goto x86_l_1d43;
	case 7494ULL: goto x86_l_1d46;
	case 7497ULL: goto x86_l_1d49;
	case 7500ULL: goto x86_l_1d4c;
	case 7506ULL: goto x86_l_1d52;
	case 7510ULL: goto x86_l_1d56;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7522ULL: goto x86_l_1d62;
	case 7525ULL: goto x86_l_1d65;
	case 7528ULL: goto x86_l_1d68;
	case 7531ULL: goto x86_l_1d6b;
	case 7537ULL: goto x86_l_1d71;
	case 7541ULL: goto x86_l_1d75;
	case 7545ULL: goto x86_l_1d79;
	case 7549ULL: goto x86_l_1d7d;
	case 7553ULL: goto x86_l_1d81;
	case 7556ULL: goto x86_l_1d84;
	case 7559ULL: goto x86_l_1d87;
	case 7562ULL: goto x86_l_1d8a;
	case 7568ULL: goto x86_l_1d90;
	case 7572ULL: goto x86_l_1d94;
	case 7575ULL: goto x86_l_1d97;
	case 7579ULL: goto x86_l_1d9b;
	case 7582ULL: goto x86_l_1d9e;
	case 7584ULL: goto x86_l_1da0;
	case 7586ULL: goto x86_l_1da2;
	case 7591ULL: goto x86_l_1da7;
	case 7593ULL: goto x86_l_1da9;
	case 7596ULL: goto x86_l_1dac;
	case 7601ULL: goto x86_l_1db1;
	case 7605ULL: goto x86_l_1db5;
	case 7610ULL: goto x86_l_1dba;
	case 7615ULL: goto x86_l_1dbf;
	case 7622ULL: goto x86_l_1dc6;
	case 7624ULL: goto x86_l_1dc8;
	case 7627ULL: goto x86_l_1dcb;
	case 7633ULL: goto x86_l_1dd1;
	case 7636ULL: goto x86_l_1dd4;
	case 7641ULL: goto x86_l_1dd9;
	case 7646ULL: goto x86_l_1dde;
	case 7648ULL: goto x86_l_1de0;
	case 7653ULL: goto x86_l_1de5;
	case 7655ULL: goto x86_l_1de7;
	case 7657ULL: goto x86_l_1de9;
	case 7660ULL: goto x86_l_1dec;
	case 7663ULL: goto x86_l_1def;
	case 7666ULL: goto x86_l_1df2;
	case 7668ULL: goto x86_l_1df4;
	case 7670ULL: goto x86_l_1df6;
	case 7674ULL: goto x86_l_1dfa;
	case 7677ULL: goto x86_l_1dfd;
	case 7679ULL: goto x86_l_1dff;
	case 7683ULL: goto x86_l_1e03;
	case 7686ULL: goto x86_l_1e06;
	case 7688ULL: goto x86_l_1e08;
	case 7692ULL: goto x86_l_1e0c;
	case 7694ULL: goto x86_l_1e0e;
	case 7698ULL: goto x86_l_1e12;
	case 7702ULL: goto x86_l_1e16;
	case 7705ULL: goto x86_l_1e19;
	case 7707ULL: goto x86_l_1e1b;
	case 7709ULL: goto x86_l_1e1d;
	case 7711ULL: goto x86_l_1e1f;
	case 7717ULL: goto x86_l_1e25;
	case 7722ULL: goto x86_l_1e2a;
	case 7726ULL: goto x86_l_1e2e;
	case 7728ULL: goto x86_l_1e30;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7739ULL: goto x86_l_1e3b;
	case 7745ULL: goto x86_l_1e41;
	case 7747ULL: goto x86_l_1e43;
	case 7752ULL: goto x86_l_1e48;
	case 7757ULL: goto x86_l_1e4d;
	case 7760ULL: goto x86_l_1e50;
	case 7765ULL: goto x86_l_1e55;
	case 7771ULL: goto x86_l_1e5b;
	case 7775ULL: goto x86_l_1e5f;
	case 7781ULL: goto x86_l_1e65;
	case 7784ULL: goto x86_l_1e68;
	case 7787ULL: goto x86_l_1e6b;
	case 7790ULL: goto x86_l_1e6e;
	case 7792ULL: goto x86_l_1e70;
	case 7794ULL: goto x86_l_1e72;
	case 7797ULL: goto x86_l_1e75;
	case 7799ULL: goto x86_l_1e77;
	case 7801ULL: goto x86_l_1e79;
	case 7803ULL: goto x86_l_1e7b;
	case 7805ULL: goto x86_l_1e7d;
	case 7808ULL: goto x86_l_1e80;
	case 7810ULL: goto x86_l_1e82;
	case 7812ULL: goto x86_l_1e84;
	case 7814ULL: goto x86_l_1e86;
	case 7817ULL: goto x86_l_1e89;
	case 7821ULL: goto x86_l_1e8d;
	case 7827ULL: goto x86_l_1e93;
	case 7831ULL: goto x86_l_1e97;
	case 7837ULL: goto x86_l_1e9d;
	case 7840ULL: goto x86_l_1ea0;
	case 7842ULL: goto x86_l_1ea2;
	case 7847ULL: goto x86_l_1ea7;
	case 7851ULL: goto x86_l_1eab;
	case 7853ULL: goto x86_l_1ead;
	case 7859ULL: goto x86_l_1eb3;
	case 7863ULL: goto x86_l_1eb7;
	case 7866ULL: goto x86_l_1eba;
	case 7872ULL: goto x86_l_1ec0;
	case 7876ULL: goto x86_l_1ec4;
	case 7879ULL: goto x86_l_1ec7;
	case 7885ULL: goto x86_l_1ecd;
	case 7888ULL: goto x86_l_1ed0;
	case 7891ULL: goto x86_l_1ed3;
	case 7897ULL: goto x86_l_1ed9;
	case 7901ULL: goto x86_l_1edd;
	case 7903ULL: goto x86_l_1edf;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7918ULL: goto x86_l_1eee;
	case 7920ULL: goto x86_l_1ef0;
	case 7926ULL: goto x86_l_1ef6;
	case 7930ULL: goto x86_l_1efa;
	case 7933ULL: goto x86_l_1efd;
	case 7939ULL: goto x86_l_1f03;
	case 7943ULL: goto x86_l_1f07;
	case 7946ULL: goto x86_l_1f0a;
	case 7952ULL: goto x86_l_1f10;
	case 7955ULL: goto x86_l_1f13;
	case 7958ULL: goto x86_l_1f16;
	case 7964ULL: goto x86_l_1f1c;
	case 7968ULL: goto x86_l_1f20;
	case 7970ULL: goto x86_l_1f22;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7984ULL: goto x86_l_1f30;
	case 7987ULL: goto x86_l_1f33;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8013ULL: goto x86_l_1f4d;
	case 8015ULL: goto x86_l_1f4f;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8025ULL: goto x86_l_1f59;
	case 8029ULL: goto x86_l_1f5d;
	case 8032ULL: goto x86_l_1f60;
	case 8038ULL: goto x86_l_1f66;
	case 8042ULL: goto x86_l_1f6a;
	case 8046ULL: goto x86_l_1f6e;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8061ULL: goto x86_l_1f7d;
	case 8065ULL: goto x86_l_1f81;
	case 8071ULL: goto x86_l_1f87;
	default: return 0xffffffffffffffffULL;
	}
x86_l_198d:
	/* 0x198d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1990:
	/* 0x1990: je     1bff <generic_fexit_filter_arg+0x1bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bff;
	}
x86_l_1996:
	/* 0x1996: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1999:
	/* 0x1999: mov    DWORD PTR [rsp+0x80],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755814016ULL);
x86_l_19a4:
	/* 0x19a4: mov    DWORD PTR [rsp+0x84],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_19ab:
	/* 0x19ab: mov    DWORD PTR [rsp+0x88],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_19b2:
	/* 0x19b2: mov    DWORD PTR [rsp+0x8c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_19ba:
	/* 0x19ba: shr    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_19be:
	/* 0x19be: mov    DWORD PTR [rsp+0x90],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_19c6:
	/* 0x19c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19cb:
	/* 0x19cb: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19d0:
	/* 0x19d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d2:
	/* 0x19d2: mov    ecx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19d6:
	/* 0x19d6: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_19d9:
	/* 0x19d9: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_19dc:
	/* 0x19dc: jb     1f2d <generic_fexit_filter_arg+0x1f2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f2d;
	}
x86_l_19e2:
	/* 0x19e2: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_19e5:
	/* 0x19e5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_19e8:
	/* 0x19e8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ed:
	/* 0x19ed: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f2:
	/* 0x19f2: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19f7:
	/* 0x19f7: ja     1a07 <generic_fexit_filter_arg+0x1a07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a07;
	}
x86_l_19f9:
	/* 0x19f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19fc:
	/* 0x19fc: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_19ff:
	/* 0x19ff: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a02:
	/* 0x1a02: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_1a07:
	/* 0x1a07: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a09:
	/* 0x1a09: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a0c:
	/* 0x1a0c: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_1a11:
	/* 0x1a11: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a15:
	/* 0x1a15: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1a18:
	/* 0x1a18: ja     1a23 <generic_fexit_filter_arg+0x1a23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a23;
	}
x86_l_1a1a:
	/* 0x1a1a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1a1d:
	/* 0x1a1d: jbe    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 639ULL;
	}
x86_l_1a23:
	/* 0x1a23: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a27:
	/* 0x1a27: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1a2a:
	/* 0x1a2a: jb     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 184ULL;
	}
x86_l_1a30:
	/* 0x1a30: mov    rdi,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a34:
	/* 0x1a34: mov    rsi,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a38:
	/* 0x1a38: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1a3b:
	/* 0x1a3b: je     1a46 <generic_fexit_filter_arg+0x1a46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a46;
	}
x86_l_1a3d:
	/* 0x1a3d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1a40:
	/* 0x1a40: jne    2038 <generic_fexit_filter_arg+0x2038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8248ULL;
	}
x86_l_1a46:
	/* 0x1a46: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a49:
	/* 0x1a49: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a4e:
	/* 0x1a4e: jg     204b <generic_fexit_filter_arg+0x204b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8267ULL;
	}
x86_l_1a54:
	/* 0x1a54: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1a57:
	/* 0x1a57: jle    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 639ULL;
	}
x86_l_1a5d:
	/* 0x1a5d: jmp    204b <generic_fexit_filter_arg+0x204b> */
	return 8267ULL;
x86_l_1a62:
	/* 0x1a62: mov    rdx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a66:
	/* 0x1a66: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1a69:
	/* 0x1a69: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1a6d:
	/* 0x1a6d: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1a70:
	/* 0x1a70: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1a73:
	/* 0x1a73: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a76:
	/* 0x1a76: mov    esi,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7a:
	/* 0x1a7a: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1a7d:
	/* 0x1a7d: jb     2b77 <generic_fexit_filter_arg+0x2b77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11127ULL;
	}
x86_l_1a83:
	/* 0x1a83: mov    r8,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a87:
	/* 0x1a87: mov    rdi,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a8b:
	/* 0x1a8b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1a8e:
	/* 0x1a8e: je     1a99 <generic_fexit_filter_arg+0x1a99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a99;
	}
x86_l_1a90:
	/* 0x1a90: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1a93:
	/* 0x1a93: jne    1ff2 <generic_fexit_filter_arg+0x1ff2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8178ULL;
	}
x86_l_1a99:
	/* 0x1a99: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1a9c:
	/* 0x1a9c: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1aa0:
	/* 0x1aa0: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1aa3:
	/* 0x1aa3: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1aa7:
	/* 0x1aa7: jmp    2000 <generic_fexit_filter_arg+0x2000> */
	return 8192ULL;
x86_l_1aac:
	/* 0x1aac: movzx  ebx,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1ab0:
	/* 0x1ab0: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1ab9:
	/* 0x1ab9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1abe:
	/* 0x1abe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1ac5:
	/* 0x1ac5: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1aca:
	/* 0x1aca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acc:
	/* 0x1acc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1acf:
	/* 0x1acf: je     258 <generic_fexit_filter_arg+0x258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 600ULL;
	}
x86_l_1ad5:
	/* 0x1ad5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ad8:
	/* 0x1ad8: movzx  eax,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1adb:
	/* 0x1adb: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ae3:
	/* 0x1ae3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ae8:
	/* 0x1ae8: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1aed:
	/* 0x1aed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aef:
	/* 0x1aef: mov    edx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1af3:
	/* 0x1af3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1af5:
	/* 0x1af5: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1af8:
	/* 0x1af8: ja     26e6 <generic_fexit_filter_arg+0x26e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9958ULL;
	}
x86_l_1afe:
	/* 0x1afe: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1b03:
	/* 0x1b03: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b06:
	/* 0x1b06: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b0b:
	/* 0x1b0b: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b10:
	/* 0x1b10: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b15:
	/* 0x1b15: jae    1b1f <generic_fexit_filter_arg+0x1b1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b1f;
	}
x86_l_1b17:
	/* 0x1b17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b1a:
	/* 0x1b1a: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1b1d:
	/* 0x1b1d: jmp    1b2f <generic_fexit_filter_arg+0x1b2f> */
	goto x86_l_1b2f;
x86_l_1b1f:
	/* 0x1b1f: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1b24:
	/* 0x1b24: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b27:
	/* 0x1b27: jae    1b2f <generic_fexit_filter_arg+0x1b2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b2f;
	}
x86_l_1b29:
	/* 0x1b29: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b2c:
	/* 0x1b2c: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1b2f:
	/* 0x1b2f: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b32:
	/* 0x1b32: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_1b37:
	/* 0x1b37: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b3b:
	/* 0x1b3b: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_1b41:
	/* 0x1b41: jmp    1b4d <generic_fexit_filter_arg+0x1b4d> */
	goto x86_l_1b4d;
x86_l_1b43:
	/* 0x1b43: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b47:
	/* 0x1b47: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_1b4d:
	/* 0x1b4d: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b51:
	/* 0x1b51: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1b54:
	/* 0x1b54: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12276ULL;
	}
x86_l_1b5a:
	/* 0x1b5a: mov    rsi,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b5e:
	/* 0x1b5e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b61:
	/* 0x1b61: jle    1b7f <generic_fexit_filter_arg+0x1b7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b7f;
	}
x86_l_1b63:
	/* 0x1b63: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1b66:
	/* 0x1b66: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1b69:
	/* 0x1b69: jae    1bae <generic_fexit_filter_arg+0x1bae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1bae;
	}
x86_l_1b6b:
	/* 0x1b6b: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b6f:
	/* 0x1b6f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b74:
	/* 0x1b74: jne    2621 <generic_fexit_filter_arg+0x2621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9761ULL;
	}
x86_l_1b7a:
	/* 0x1b7a: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_1b7f:
	/* 0x1b7f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b82:
	/* 0x1b82: je     1d08 <generic_fexit_filter_arg+0x1d08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d08;
	}
x86_l_1b88:
	/* 0x1b88: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b8b:
	/* 0x1b8b: jne    2621 <generic_fexit_filter_arg+0x2621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9761ULL;
	}
x86_l_1b91:
	/* 0x1b91: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1b94:
	/* 0x1b94: je     1b9f <generic_fexit_filter_arg+0x1b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b9f;
	}
x86_l_1b96:
	/* 0x1b96: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1b99:
	/* 0x1b99: jne    2617 <generic_fexit_filter_arg+0x2617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9751ULL;
	}
x86_l_1b9f:
	/* 0x1b9f: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba3:
	/* 0x1ba3: jl     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 639ULL;
	}
x86_l_1ba9:
	/* 0x1ba9: jmp    2621 <generic_fexit_filter_arg+0x2621> */
	return 9761ULL;
x86_l_1bae:
	/* 0x1bae: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1bb1:
	/* 0x1bb1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bb6:
	/* 0x1bb6: jne    2621 <generic_fexit_filter_arg+0x2621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9761ULL;
	}
x86_l_1bbc:
	/* 0x1bbc: test   QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc0:
	/* 0x1bc0: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_1bc6:
	/* 0x1bc6: jmp    2621 <generic_fexit_filter_arg+0x2621> */
	return 9761ULL;
x86_l_1bcb:
	/* 0x1bcb: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1bce:
	/* 0x1bce: jne    1eb3 <generic_fexit_filter_arg+0x1eb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1eb3;
	}
x86_l_1bd4:
	/* 0x1bd4: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1bd8:
	/* 0x1bd8: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1bda:
	/* 0x1bda: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_1be0:
	/* 0x1be0: jmp    1eb3 <generic_fexit_filter_arg+0x1eb3> */
	goto x86_l_1eb3;
x86_l_1be5:
	/* 0x1be5: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1be8:
	/* 0x1be8: jne    1ef6 <generic_fexit_filter_arg+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ef6;
	}
x86_l_1bee:
	/* 0x1bee: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bf2:
	/* 0x1bf2: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1bf4:
	/* 0x1bf4: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_1bfa:
	/* 0x1bfa: jmp    1ef6 <generic_fexit_filter_arg+0x1ef6> */
	goto x86_l_1ef6;
x86_l_1bff:
	/* 0x1bff: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c03:
	/* 0x1c03: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1c06:
	/* 0x1c06: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1c09:
	/* 0x1c09: jmp    1f30 <generic_fexit_filter_arg+0x1f30> */
	goto x86_l_1f30;
x86_l_1c0e:
	/* 0x1c0e: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1c11:
	/* 0x1c11: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1c16:
	/* 0x1c16: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1c1b:
	/* 0x1c1b: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_1c20:
	/* 0x1c20: cmovae esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_1c23:
	/* 0x1c23: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1c26:
	/* 0x1c26: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c28:
	/* 0x1c28: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1c2d:
	/* 0x1c2d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1c30:
	/* 0x1c30: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_1c33:
	/* 0x1c33: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1c35:
	/* 0x1c35: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1c38:
	/* 0x1c38: mov    eax,DWORD PTR [r15+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1c3d:
	/* 0x1c3d: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_1c40:
	/* 0x1c40: je     2ce3 <generic_fexit_filter_arg+0x2ce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11491ULL;
	}
x86_l_1c46:
	/* 0x1c46: mov    DWORD PTR [rsp+0x98],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1c4d:
	/* 0x1c4d: mov    DWORD PTR [rsp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1c51:
	/* 0x1c51: mov    DWORD PTR [rsp+0x68],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c55:
	/* 0x1c55: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c5a:
	/* 0x1c5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1c66:
	/* 0x1c66: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c6b:
	/* 0x1c6b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1c6e:
	/* 0x1c6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c70:
	/* 0x1c70: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c75:
	/* 0x1c75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c7a:
	/* 0x1c7a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1c81:
	/* 0x1c81: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1c84:
	/* 0x1c84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c86:
	/* 0x1c86: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1c8c:
	/* 0x1c8c: je     2ce3 <generic_fexit_filter_arg+0x2ce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11491ULL;
	}
x86_l_1c92:
	/* 0x1c92: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1c97:
	/* 0x1c97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c9a:
	/* 0x1c9a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ca9:
	/* 0x1ca9: je     2cf4 <generic_fexit_filter_arg+0x2cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11508ULL;
	}
x86_l_1caf:
	/* 0x1caf: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1cb2:
	/* 0x1cb2: cmp    DWORD PTR [rsp+0x68],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598789ULL);
x86_l_1cb7:
	/* 0x1cb7: jg     24f7 <generic_fexit_filter_arg+0x24f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9463ULL;
	}
x86_l_1cbd:
	/* 0x1cbd: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cc2:
	/* 0x1cc2: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc5:
	/* 0x1cc5: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1cc9:
	/* 0x1cc9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cce:
	/* 0x1cce: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1cd5:
	/* 0x1cd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd7:
	/* 0x1cd7: movzx  esi,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_1cdf:
	/* 0x1cdf: cmp    esi,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1ce1:
	/* 0x1ce1: jbe    253c <generic_fexit_filter_arg+0x253c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9532ULL;
	}
x86_l_1ce7:
	/* 0x1ce7: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cec:
	/* 0x1cec: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1cf0:
	/* 0x1cf0: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1cf3:
	/* 0x1cf3: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1cf5:
	/* 0x1cf5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cfb:
	/* 0x1cfb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d00:
	/* 0x1d00: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1d03:
	/* 0x1d03: jmp    253a <generic_fexit_filter_arg+0x253a> */
	return 9530ULL;
x86_l_1d08:
	/* 0x1d08: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1d0b:
	/* 0x1d0b: je     1d16 <generic_fexit_filter_arg+0x1d16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d16;
	}
x86_l_1d0d:
	/* 0x1d0d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1d10:
	/* 0x1d10: jne    260b <generic_fexit_filter_arg+0x260b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9739ULL;
	}
x86_l_1d16:
	/* 0x1d16: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d1a:
	/* 0x1d1a: jg     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 639ULL;
	}
x86_l_1d20:
	/* 0x1d20: jmp    2621 <generic_fexit_filter_arg+0x2621> */
	return 9761ULL;
x86_l_1d25:
	/* 0x1d25: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d29:
	/* 0x1d29: movzx  ecx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d2d:
	/* 0x1d2d: jmp    1d37 <generic_fexit_filter_arg+0x1d37> */
	goto x86_l_1d37;
x86_l_1d2f:
	/* 0x1d2f: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d33:
	/* 0x1d33: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d37:
	/* 0x1d37: cmp    DWORD PTR [r15+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d3b:
	/* 0x1d3b: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1d3f:
	/* 0x1d3f: cmp    DWORD PTR [r15+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d43:
	/* 0x1d43: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1d46:
	/* 0x1d46: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1d49:
	/* 0x1d49: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d4c:
	/* 0x1d4c: jb     2b77 <generic_fexit_filter_arg+0x2b77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11127ULL;
	}
x86_l_1d52:
	/* 0x1d52: cmp    DWORD PTR [r15+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d56:
	/* 0x1d56: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1d5a:
	/* 0x1d5a: cmp    DWORD PTR [r15+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1d5e:
	/* 0x1d5e: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1d62:
	/* 0x1d62: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1d65:
	/* 0x1d65: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d68:
	/* 0x1d68: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1d6b:
	/* 0x1d6b: jb     2b72 <generic_fexit_filter_arg+0x2b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11122ULL;
	}
x86_l_1d71:
	/* 0x1d71: cmp    DWORD PTR [r15+0x20],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d75:
	/* 0x1d75: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1d79:
	/* 0x1d79: cmp    DWORD PTR [r15+0x24],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d7d:
	/* 0x1d7d: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1d81:
	/* 0x1d81: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1d84:
	/* 0x1d84: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d87:
	/* 0x1d87: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1d8a:
	/* 0x1d8a: jb     2b72 <generic_fexit_filter_arg+0x2b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11122ULL;
	}
x86_l_1d90:
	/* 0x1d90: cmp    DWORD PTR [r15+0x28],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d94:
	/* 0x1d94: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1d97:
	/* 0x1d97: cmp    DWORD PTR [r15+0x2c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1d9b:
	/* 0x1d9b: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1d9e:
	/* 0x1d9e: and    cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1da0:
	/* 0x1da0: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1da2:
	/* 0x1da2: jmp    2b72 <generic_fexit_filter_arg+0x2b72> */
	return 11122ULL;
x86_l_1da7:
	/* 0x1da7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1da9:
	/* 0x1da9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dac:
	/* 0x1dac: mov    eax,DWORD PTR [r15+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1db1:
	/* 0x1db1: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1db5:
	/* 0x1db5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dba:
	/* 0x1dba: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1dc6:
	/* 0x1dc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc8:
	/* 0x1dc8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dcb:
	/* 0x1dcb: je     2717 <generic_fexit_filter_arg+0x2717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10007ULL;
	}
x86_l_1dd1:
	/* 0x1dd1: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1dd4:
	/* 0x1dd4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd9:
	/* 0x1dd9: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dde:
	/* 0x1dde: je     1e25 <generic_fexit_filter_arg+0x1e25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e25;
	}
x86_l_1de0:
	/* 0x1de0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1de5:
	/* 0x1de5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1de7:
	/* 0x1de7: jmp    1df4 <generic_fexit_filter_arg+0x1df4> */
	goto x86_l_1df4;
x86_l_1de9:
	/* 0x1de9: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1dec:
	/* 0x1dec: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1def:
	/* 0x1def: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1df2:
	/* 0x1df2: je     1e25 <generic_fexit_filter_arg+0x1e25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e25;
	}
x86_l_1df4:
	/* 0x1df4: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1df6:
	/* 0x1df6: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1dfa:
	/* 0x1dfa: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1dfd:
	/* 0x1dfd: jae    1de9 <generic_fexit_filter_arg+0x1de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1de9;
	}
x86_l_1dff:
	/* 0x1dff: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1e03:
	/* 0x1e03: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1e06:
	/* 0x1e06: je     1e1d <generic_fexit_filter_arg+0x1e1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e1d;
	}
x86_l_1e08:
	/* 0x1e08: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1e0c:
	/* 0x1e0c: ja     1de9 <generic_fexit_filter_arg+0x1de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1de9;
	}
x86_l_1e0e:
	/* 0x1e0e: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1e12:
	/* 0x1e12: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1e16:
	/* 0x1e16: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1e19:
	/* 0x1e19: je     1df6 <generic_fexit_filter_arg+0x1df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df6;
	}
x86_l_1e1b:
	/* 0x1e1b: jmp    1de9 <generic_fexit_filter_arg+0x1de9> */
	goto x86_l_1de9;
x86_l_1e1d:
	/* 0x1e1d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e1f:
	/* 0x1e1f: jns    2a15 <generic_fexit_filter_arg+0x2a15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10773ULL;
	}
x86_l_1e25:
	/* 0x1e25: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e2a:
	/* 0x1e2a: cmp    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1e2e:
	/* 0x1e2e: jae    1e41 <generic_fexit_filter_arg+0x1e41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e41;
	}
x86_l_1e30:
	/* 0x1e30: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1e34:
	/* 0x1e34: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1e37:
	/* 0x1e37: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1e3b:
	/* 0x1e3b: jne    1dac <generic_fexit_filter_arg+0x1dac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dac;
	}
x86_l_1e41:
	/* 0x1e41: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e43:
	/* 0x1e43: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e48:
	/* 0x1e48: jmp    2f7d <generic_fexit_filter_arg+0x2f7d> */
	return 12157ULL;
x86_l_1e4d:
	/* 0x1e4d: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e50:
	/* 0x1e50: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1e55:
	/* 0x1e55: ja     22cd <generic_fexit_filter_arg+0x22cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8909ULL;
	}
x86_l_1e5b:
	/* 0x1e5b: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e5f:
	/* 0x1e5f: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1e65:
	/* 0x1e65: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1e68:
	/* 0x1e68: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1e6b:
	/* 0x1e6b: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1e6e:
	/* 0x1e6e: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1e70:
	/* 0x1e70: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1e72:
	/* 0x1e72: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1e75:
	/* 0x1e75: je     1e7d <generic_fexit_filter_arg+0x1e7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e7d;
	}
x86_l_1e77:
	/* 0x1e77: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1e79:
	/* 0x1e79: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1e7b:
	/* 0x1e7b: je     1e93 <generic_fexit_filter_arg+0x1e93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e93;
	}
x86_l_1e7d:
	/* 0x1e7d: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e80:
	/* 0x1e80: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1e82:
	/* 0x1e82: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e84:
	/* 0x1e84: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1e86:
	/* 0x1e86: add    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1e89:
	/* 0x1e89: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1e8d:
	/* 0x1e8d: ja     22e2 <generic_fexit_filter_arg+0x22e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8930ULL;
	}
x86_l_1e93:
	/* 0x1e93: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e97:
	/* 0x1e97: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1e9d:
	/* 0x1e9d: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1ea0:
	/* 0x1ea0: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1ea2:
	/* 0x1ea2: jmp    22f2 <generic_fexit_filter_arg+0x22f2> */
	return 8946ULL;
x86_l_1ea7:
	/* 0x1ea7: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1eab:
	/* 0x1eab: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1ead:
	/* 0x1ead: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_1eb3:
	/* 0x1eb3: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eb7:
	/* 0x1eb7: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1eba:
	/* 0x1eba: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12276ULL;
	}
x86_l_1ec0:
	/* 0x1ec0: mov    edx,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ec4:
	/* 0x1ec4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ec7:
	/* 0x1ec7: jle    21bf <generic_fexit_filter_arg+0x21bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8639ULL;
	}
x86_l_1ecd:
	/* 0x1ecd: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1ed0:
	/* 0x1ed0: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1ed3:
	/* 0x1ed3: jae    269b <generic_fexit_filter_arg+0x269b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9883ULL;
	}
x86_l_1ed9:
	/* 0x1ed9: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1edd:
	/* 0x1edd: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1edf:
	/* 0x1edf: jne    2793 <generic_fexit_filter_arg+0x2793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10131ULL;
	}
x86_l_1ee5:
	/* 0x1ee5: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_1eea:
	/* 0x1eea: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1eee:
	/* 0x1eee: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1ef0:
	/* 0x1ef0: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_1ef6:
	/* 0x1ef6: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1efa:
	/* 0x1efa: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1efd:
	/* 0x1efd: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12276ULL;
	}
x86_l_1f03:
	/* 0x1f03: mov    edx,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1f07:
	/* 0x1f07: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f0a:
	/* 0x1f0a: jle    21e2 <generic_fexit_filter_arg+0x21e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8674ULL;
	}
x86_l_1f10:
	/* 0x1f10: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1f13:
	/* 0x1f13: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f16:
	/* 0x1f16: jae    26b5 <generic_fexit_filter_arg+0x26b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9909ULL;
	}
x86_l_1f1c:
	/* 0x1f1c: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f20:
	/* 0x1f20: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1f22:
	/* 0x1f22: jne    27d2 <generic_fexit_filter_arg+0x27d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10194ULL;
	}
x86_l_1f28:
	/* 0x1f28: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_1f2d:
	/* 0x1f2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f30:
	/* 0x1f30: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1f33:
	/* 0x1f33: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f38:
	/* 0x1f38: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f3d:
	/* 0x1f3d: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f42:
	/* 0x1f42: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f45:
	/* 0x1f45: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_1f4a:
	/* 0x1f4a: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f4d:
	/* 0x1f4d: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1f4f:
	/* 0x1f4f: ja     1f59 <generic_fexit_filter_arg+0x1f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f59;
	}
x86_l_1f51:
	/* 0x1f51: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1f53:
	/* 0x1f53: jbe    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 639ULL;
	}
x86_l_1f59:
	/* 0x1f59: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f5d:
	/* 0x1f5d: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1f60:
	/* 0x1f60: jb     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 184ULL;
	}
x86_l_1f66:
	/* 0x1f66: mov    edi,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    esi,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f6e:
	/* 0x1f6e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1f71:
	/* 0x1f71: ja     2411 <generic_fexit_filter_arg+0x2411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9233ULL;
	}
x86_l_1f77:
	/* 0x1f77: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_1f7d:
	/* 0x1f7d: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1f81:
	/* 0x1f81: jae    2411 <generic_fexit_filter_arg+0x2411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9233ULL;
	}
x86_l_1f87:
	/* 0x1f87: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
	return 8073ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8073ULL: goto x86_l_1f89;
	case 8078ULL: goto x86_l_1f8e;
	case 8084ULL: goto x86_l_1f94;
	case 8086ULL: goto x86_l_1f96;
	case 8092ULL: goto x86_l_1f9c;
	case 8097ULL: goto x86_l_1fa1;
	case 8100ULL: goto x86_l_1fa4;
	case 8102ULL: goto x86_l_1fa6;
	case 8106ULL: goto x86_l_1faa;
	case 8108ULL: goto x86_l_1fac;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8118ULL: goto x86_l_1fb6;
	case 8121ULL: goto x86_l_1fb9;
	case 8127ULL: goto x86_l_1fbf;
	case 8131ULL: goto x86_l_1fc3;
	case 8135ULL: goto x86_l_1fc7;
	case 8138ULL: goto x86_l_1fca;
	case 8144ULL: goto x86_l_1fd0;
	case 8150ULL: goto x86_l_1fd6;
	case 8154ULL: goto x86_l_1fda;
	case 8160ULL: goto x86_l_1fe0;
	case 8163ULL: goto x86_l_1fe3;
	case 8167ULL: goto x86_l_1fe7;
	case 8169ULL: goto x86_l_1fe9;
	case 8173ULL: goto x86_l_1fed;
	case 8178ULL: goto x86_l_1ff2;
	case 8181ULL: goto x86_l_1ff5;
	case 8185ULL: goto x86_l_1ff9;
	case 8188ULL: goto x86_l_1ffc;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8198ULL: goto x86_l_2006;
	case 8201ULL: goto x86_l_2009;
	case 8207ULL: goto x86_l_200f;
	case 8211ULL: goto x86_l_2013;
	case 8215ULL: goto x86_l_2017;
	case 8218ULL: goto x86_l_201a;
	case 8220ULL: goto x86_l_201c;
	case 8223ULL: goto x86_l_201f;
	case 8229ULL: goto x86_l_2025;
	case 8232ULL: goto x86_l_2028;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8243ULL: goto x86_l_2033;
	case 8248ULL: goto x86_l_2038;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8258ULL: goto x86_l_2042;
	case 8261ULL: goto x86_l_2045;
	case 8267ULL: goto x86_l_204b;
	case 8270ULL: goto x86_l_204e;
	case 8276ULL: goto x86_l_2054;
	case 8280ULL: goto x86_l_2058;
	case 8284ULL: goto x86_l_205c;
	case 8287ULL: goto x86_l_205f;
	case 8289ULL: goto x86_l_2061;
	case 8292ULL: goto x86_l_2064;
	case 8298ULL: goto x86_l_206a;
	case 8301ULL: goto x86_l_206d;
	case 8306ULL: goto x86_l_2072;
	case 8312ULL: goto x86_l_2078;
	case 8315ULL: goto x86_l_207b;
	case 8321ULL: goto x86_l_2081;
	case 8326ULL: goto x86_l_2086;
	case 8328ULL: goto x86_l_2088;
	case 8331ULL: goto x86_l_208b;
	case 8333ULL: goto x86_l_208d;
	case 8336ULL: goto x86_l_2090;
	case 8338ULL: goto x86_l_2092;
	case 8342ULL: goto x86_l_2096;
	case 8345ULL: goto x86_l_2099;
	case 8347ULL: goto x86_l_209b;
	case 8350ULL: goto x86_l_209e;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8370ULL: goto x86_l_20b2;
	case 8377ULL: goto x86_l_20b9;
	case 8382ULL: goto x86_l_20be;
	case 8384ULL: goto x86_l_20c0;
	case 8387ULL: goto x86_l_20c3;
	case 8393ULL: goto x86_l_20c9;
	case 8396ULL: goto x86_l_20cc;
	case 8398ULL: goto x86_l_20ce;
	case 8406ULL: goto x86_l_20d6;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8421ULL: goto x86_l_20e5;
	case 8424ULL: goto x86_l_20e8;
	case 8430ULL: goto x86_l_20ee;
	case 8432ULL: goto x86_l_20f0;
	case 8435ULL: goto x86_l_20f3;
	case 8441ULL: goto x86_l_20f9;
	case 8445ULL: goto x86_l_20fd;
	case 8448ULL: goto x86_l_2100;
	case 8454ULL: goto x86_l_2106;
	case 8458ULL: goto x86_l_210a;
	case 8461ULL: goto x86_l_210d;
	case 8463ULL: goto x86_l_210f;
	case 8466ULL: goto x86_l_2112;
	case 8469ULL: goto x86_l_2115;
	case 8471ULL: goto x86_l_2117;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8493ULL: goto x86_l_212d;
	case 8495ULL: goto x86_l_212f;
	case 8498ULL: goto x86_l_2132;
	case 8504ULL: goto x86_l_2138;
	case 8507ULL: goto x86_l_213b;
	case 8513ULL: goto x86_l_2141;
	case 8519ULL: goto x86_l_2147;
	case 8523ULL: goto x86_l_214b;
	case 8529ULL: goto x86_l_2151;
	case 8532ULL: goto x86_l_2154;
	case 8538ULL: goto x86_l_215a;
	case 8543ULL: goto x86_l_215f;
	case 8546ULL: goto x86_l_2162;
	case 8551ULL: goto x86_l_2167;
	case 8557ULL: goto x86_l_216d;
	case 8560ULL: goto x86_l_2170;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8574ULL: goto x86_l_217e;
	case 8580ULL: goto x86_l_2184;
	case 8586ULL: goto x86_l_218a;
	case 8590ULL: goto x86_l_218e;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8605ULL: goto x86_l_219d;
	case 8610ULL: goto x86_l_21a2;
	case 8612ULL: goto x86_l_21a4;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8629ULL: goto x86_l_21b5;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8642ULL: goto x86_l_21c2;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8657ULL: goto x86_l_21d1;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8669ULL: goto x86_l_21dd;
	case 8674ULL: goto x86_l_21e2;
	case 8677ULL: goto x86_l_21e5;
	case 8683ULL: goto x86_l_21eb;
	case 8686ULL: goto x86_l_21ee;
	case 8692ULL: goto x86_l_21f4;
	case 8696ULL: goto x86_l_21f8;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8712ULL: goto x86_l_2208;
	case 8715ULL: goto x86_l_220b;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8726ULL: goto x86_l_2216;
	case 8728ULL: goto x86_l_2218;
	case 8730ULL: goto x86_l_221a;
	case 8732ULL: goto x86_l_221c;
	case 8736ULL: goto x86_l_2220;
	case 8740ULL: goto x86_l_2224;
	case 8742ULL: goto x86_l_2226;
	case 8748ULL: goto x86_l_222c;
	case 8753ULL: goto x86_l_2231;
	case 8761ULL: goto x86_l_2239;
	case 8763ULL: goto x86_l_223b;
	case 8765ULL: goto x86_l_223d;
	case 8769ULL: goto x86_l_2241;
	case 8773ULL: goto x86_l_2245;
	case 8777ULL: goto x86_l_2249;
	case 8780ULL: goto x86_l_224c;
	case 8782ULL: goto x86_l_224e;
	case 8785ULL: goto x86_l_2251;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8800ULL: goto x86_l_2260;
	case 8806ULL: goto x86_l_2266;
	case 8808ULL: goto x86_l_2268;
	case 8814ULL: goto x86_l_226e;
	case 8817ULL: goto x86_l_2271;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8833ULL: goto x86_l_2281;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8863ULL: goto x86_l_229f;
	case 8869ULL: goto x86_l_22a5;
	case 8872ULL: goto x86_l_22a8;
	case 8878ULL: goto x86_l_22ae;
	case 8881ULL: goto x86_l_22b1;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8904ULL: goto x86_l_22c8;
	case 8909ULL: goto x86_l_22cd;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8933ULL: goto x86_l_22e5;
	case 8935ULL: goto x86_l_22e7;
	case 8940ULL: goto x86_l_22ec;
	case 8943ULL: goto x86_l_22ef;
	case 8946ULL: goto x86_l_22f2;
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8965ULL: goto x86_l_2305;
	case 8969ULL: goto x86_l_2309;
	case 8973ULL: goto x86_l_230d;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8987ULL: goto x86_l_231b;
	case 8994ULL: goto x86_l_2322;
	case 8999ULL: goto x86_l_2327;
	case 9002ULL: goto x86_l_232a;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9012ULL: goto x86_l_2334;
	case 9019ULL: goto x86_l_233b;
	case 9022ULL: goto x86_l_233e;
	case 9024ULL: goto x86_l_2340;
	case 9027ULL: goto x86_l_2343;
	case 9033ULL: goto x86_l_2349;
	case 9038ULL: goto x86_l_234e;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9056ULL: goto x86_l_2360;
	case 9062ULL: goto x86_l_2366;
	case 9065ULL: goto x86_l_2369;
	case 9073ULL: goto x86_l_2371;
	case 9078ULL: goto x86_l_2376;
	case 9083ULL: goto x86_l_237b;
	case 9089ULL: goto x86_l_2381;
	case 9092ULL: goto x86_l_2384;
	case 9095ULL: goto x86_l_2387;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9109ULL: goto x86_l_2395;
	case 9111ULL: goto x86_l_2397;
	case 9113ULL: goto x86_l_2399;
	case 9115ULL: goto x86_l_239b;
	case 9121ULL: goto x86_l_23a1;
	case 9125ULL: goto x86_l_23a5;
	case 9128ULL: goto x86_l_23a8;
	case 9130ULL: goto x86_l_23aa;
	case 9136ULL: goto x86_l_23b0;
	case 9141ULL: goto x86_l_23b5;
	case 9149ULL: goto x86_l_23bd;
	case 9154ULL: goto x86_l_23c2;
	case 9157ULL: goto x86_l_23c5;
	case 9161ULL: goto x86_l_23c9;
	case 9163ULL: goto x86_l_23cb;
	case 9167ULL: goto x86_l_23cf;
	case 9170ULL: goto x86_l_23d2;
	case 9173ULL: goto x86_l_23d5;
	case 9176ULL: goto x86_l_23d8;
	case 9182ULL: goto x86_l_23de;
	case 9186ULL: goto x86_l_23e2;
	case 9190ULL: goto x86_l_23e6;
	case 9193ULL: goto x86_l_23e9;
	case 9199ULL: goto x86_l_23ef;
	case 9205ULL: goto x86_l_23f5;
	case 9209ULL: goto x86_l_23f9;
	case 9215ULL: goto x86_l_23ff;
	case 9218ULL: goto x86_l_2402;
	case 9222ULL: goto x86_l_2406;
	case 9224ULL: goto x86_l_2408;
	case 9228ULL: goto x86_l_240c;
	case 9233ULL: goto x86_l_2411;
	case 9235ULL: goto x86_l_2413;
	case 9240ULL: goto x86_l_2418;
	case 9242ULL: goto x86_l_241a;
	case 9244ULL: goto x86_l_241c;
	case 9250ULL: goto x86_l_2422;
	case 9253ULL: goto x86_l_2425;
	case 9259ULL: goto x86_l_242b;
	case 9263ULL: goto x86_l_242f;
	case 9267ULL: goto x86_l_2433;
	case 9270ULL: goto x86_l_2436;
	case 9276ULL: goto x86_l_243c;
	case 9282ULL: goto x86_l_2442;
	case 9286ULL: goto x86_l_2446;
	case 9292ULL: goto x86_l_244c;
	case 9294ULL: goto x86_l_244e;
	case 9299ULL: goto x86_l_2453;
	case 9305ULL: goto x86_l_2459;
	case 9307ULL: goto x86_l_245b;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9323ULL: goto x86_l_246b;
	case 9328ULL: goto x86_l_2470;
	case 9333ULL: goto x86_l_2475;
	case 9337ULL: goto x86_l_2479;
	case 9341ULL: goto x86_l_247d;
	case 9347ULL: goto x86_l_2483;
	case 9352ULL: goto x86_l_2488;
	case 9357ULL: goto x86_l_248d;
	case 9362ULL: goto x86_l_2492;
	case 9367ULL: goto x86_l_2497;
	case 9372ULL: goto x86_l_249c;
	case 9376ULL: goto x86_l_24a0;
	case 9380ULL: goto x86_l_24a4;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9394ULL: goto x86_l_24b2;
	case 9398ULL: goto x86_l_24b6;
	case 9401ULL: goto x86_l_24b9;
	case 9405ULL: goto x86_l_24bd;
	case 9408ULL: goto x86_l_24c0;
	case 9411ULL: goto x86_l_24c3;
	case 9414ULL: goto x86_l_24c6;
	case 9420ULL: goto x86_l_24cc;
	case 9424ULL: goto x86_l_24d0;
	case 9428ULL: goto x86_l_24d4;
	case 9431ULL: goto x86_l_24d7;
	case 9433ULL: goto x86_l_24d9;
	case 9436ULL: goto x86_l_24dc;
	case 9442ULL: goto x86_l_24e2;
	case 9445ULL: goto x86_l_24e5;
	case 9448ULL: goto x86_l_24e8;
	case 9451ULL: goto x86_l_24eb;
	case 9456ULL: goto x86_l_24f0;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9468ULL: goto x86_l_24fc;
	case 9471ULL: goto x86_l_24ff;
	case 9475ULL: goto x86_l_2503;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9487ULL: goto x86_l_250f;
	case 9489ULL: goto x86_l_2511;
	case 9497ULL: goto x86_l_2519;
	case 9499ULL: goto x86_l_251b;
	case 9501ULL: goto x86_l_251d;
	case 9506ULL: goto x86_l_2522;
	case 9510ULL: goto x86_l_2526;
	case 9514ULL: goto x86_l_252a;
	case 9516ULL: goto x86_l_252c;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9530ULL: goto x86_l_253a;
	case 9532ULL: goto x86_l_253c;
	case 9536ULL: goto x86_l_2540;
	case 9540ULL: goto x86_l_2544;
	case 9544ULL: goto x86_l_2548;
	case 9547ULL: goto x86_l_254b;
	case 9549ULL: goto x86_l_254d;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9568ULL: goto x86_l_2560;
	case 9570ULL: goto x86_l_2562;
	case 9576ULL: goto x86_l_2568;
	case 9579ULL: goto x86_l_256b;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9595ULL: goto x86_l_257b;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9626ULL: goto x86_l_259a;
	case 9629ULL: goto x86_l_259d;
	case 9635ULL: goto x86_l_25a3;
	case 9638ULL: goto x86_l_25a6;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9654ULL: goto x86_l_25b6;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9669ULL: goto x86_l_25c5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1f89:
	/* 0x1f89: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f8e:
	/* 0x1f8e: jg     2422 <generic_fexit_filter_arg+0x2422> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2422;
	}
x86_l_1f94:
	/* 0x1f94: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_1f96:
	/* 0x1f96: jle    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 639ULL;
	}
x86_l_1f9c:
	/* 0x1f9c: jmp    2422 <generic_fexit_filter_arg+0x2422> */
	goto x86_l_2422;
x86_l_1fa1:
	/* 0x1fa1: mov    edx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa4:
	/* 0x1fa4: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1fa6:
	/* 0x1fa6: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1faa:
	/* 0x1faa: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1fac:
	/* 0x1fac: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1faf:
	/* 0x1faf: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1fb2:
	/* 0x1fb2: mov    esi,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fb6:
	/* 0x1fb6: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1fb9:
	/* 0x1fb9: jb     2b77 <generic_fexit_filter_arg+0x2b77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11127ULL;
	}
x86_l_1fbf:
	/* 0x1fbf: mov    r8d,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fc3:
	/* 0x1fc3: mov    edi,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1fc7:
	/* 0x1fc7: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1fca:
	/* 0x1fca: ja     23c2 <generic_fexit_filter_arg+0x23c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_23c2;
	}
x86_l_1fd0:
	/* 0x1fd0: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_1fd6:
	/* 0x1fd6: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_1fda:
	/* 0x1fda: jae    23c2 <generic_fexit_filter_arg+0x23c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_23c2;
	}
x86_l_1fe0:
	/* 0x1fe0: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_1fe3:
	/* 0x1fe3: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1fe7:
	/* 0x1fe7: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1fe9:
	/* 0x1fe9: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1fed:
	/* 0x1fed: jmp    23cf <generic_fexit_filter_arg+0x23cf> */
	goto x86_l_23cf;
x86_l_1ff2:
	/* 0x1ff2: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1ff5:
	/* 0x1ff5: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1ff9:
	/* 0x1ff9: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1ffc:
	/* 0x1ffc: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2000:
	/* 0x2000: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2003:
	/* 0x2003: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2006:
	/* 0x2006: cmp    esi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 41ULL);
x86_l_2009:
	/* 0x2009: jb     2b72 <generic_fexit_filter_arg+0x2b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11122ULL;
	}
x86_l_200f:
	/* 0x200f: mov    r8,QWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2013:
	/* 0x2013: mov    rdi,QWORD PTR [r15+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2017:
	/* 0x2017: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_201a:
	/* 0x201a: je     2025 <generic_fexit_filter_arg+0x2025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2025;
	}
x86_l_201c:
	/* 0x201c: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_201f:
	/* 0x201f: jne    24af <generic_fexit_filter_arg+0x24af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24af;
	}
x86_l_2025:
	/* 0x2025: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_2028:
	/* 0x2028: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_202c:
	/* 0x202c: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_202f:
	/* 0x202f: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_2033:
	/* 0x2033: jmp    24bd <generic_fexit_filter_arg+0x24bd> */
	goto x86_l_24bd;
x86_l_2038:
	/* 0x2038: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_203b:
	/* 0x203b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2040:
	/* 0x2040: ja     204b <generic_fexit_filter_arg+0x204b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_204b;
	}
x86_l_2042:
	/* 0x2042: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_2045:
	/* 0x2045: jbe    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 639ULL;
	}
x86_l_204b:
	/* 0x204b: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_204e:
	/* 0x204e: jb     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 184ULL;
	}
x86_l_2054:
	/* 0x2054: mov    rdi,QWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2058:
	/* 0x2058: mov    rsi,QWORD PTR [r15+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_205c:
	/* 0x205c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_205f:
	/* 0x205f: je     206a <generic_fexit_filter_arg+0x206a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_206a;
	}
x86_l_2061:
	/* 0x2061: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2064:
	/* 0x2064: jne    25c2 <generic_fexit_filter_arg+0x25c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25c2;
	}
x86_l_206a:
	/* 0x206a: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_206d:
	/* 0x206d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2072:
	/* 0x2072: jg     25d5 <generic_fexit_filter_arg+0x25d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9685ULL;
	}
x86_l_2078:
	/* 0x2078: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_207b:
	/* 0x207b: jle    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 639ULL;
	}
x86_l_2081:
	/* 0x2081: jmp    25d5 <generic_fexit_filter_arg+0x25d5> */
	return 9685ULL;
x86_l_2086:
	/* 0x2086: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2088:
	/* 0x2088: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_208b:
	/* 0x208b: jne    2096 <generic_fexit_filter_arg+0x2096> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2096;
	}
x86_l_208d:
	/* 0x208d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2090:
	/* 0x2090: je     2096 <generic_fexit_filter_arg+0x2096> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2096;
	}
x86_l_2092:
	/* 0x2092: movzx  ebx,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2096:
	/* 0x2096: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2099:
	/* 0x2099: je     20a4 <generic_fexit_filter_arg+0x20a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20a4;
	}
x86_l_209b:
	/* 0x209b: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_209e:
	/* 0x209e: jne    24f0 <generic_fexit_filter_arg+0x24f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f0;
	}
x86_l_20a4:
	/* 0x20a4: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_20a9:
	/* 0x20a9: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_20ad:
	/* 0x20ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20b2:
	/* 0x20b2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_20b9:
	/* 0x20b9: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_20be:
	/* 0x20be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c0:
	/* 0x20c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20c3:
	/* 0x20c3: je     258 <generic_fexit_filter_arg+0x258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 600ULL;
	}
x86_l_20c9:
	/* 0x20c9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_20cc:
	/* 0x20cc: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_20ce:
	/* 0x20ce: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_20d6:
	/* 0x20d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20db:
	/* 0x20db: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_20e0:
	/* 0x20e0: jmp    1aed <generic_fexit_filter_arg+0x1aed> */
	return 6893ULL;
x86_l_20e5:
	/* 0x20e5: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e8:
	/* 0x20e8: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_20ee:
	/* 0x20ee: jmp    20f9 <generic_fexit_filter_arg+0x20f9> */
	goto x86_l_20f9;
x86_l_20f0:
	/* 0x20f0: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f3:
	/* 0x20f3: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_20f9:
	/* 0x20f9: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20fd:
	/* 0x20fd: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2100:
	/* 0x2100: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12276ULL;
	}
x86_l_2106:
	/* 0x2106: mov    esi,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_210a:
	/* 0x210a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_210d:
	/* 0x210d: jle    212a <generic_fexit_filter_arg+0x212a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_212a;
	}
x86_l_210f:
	/* 0x210f: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2112:
	/* 0x2112: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2115:
	/* 0x2115: jae    215f <generic_fexit_filter_arg+0x215f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_215f;
	}
x86_l_2117:
	/* 0x2117: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_211a:
	/* 0x211a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_211f:
	/* 0x211f: jne    28b5 <generic_fexit_filter_arg+0x28b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10421ULL;
	}
x86_l_2125:
	/* 0x2125: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_212a:
	/* 0x212a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_212d:
	/* 0x212d: je     217b <generic_fexit_filter_arg+0x217b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_217b;
	}
x86_l_212f:
	/* 0x212f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2132:
	/* 0x2132: jne    28b5 <generic_fexit_filter_arg+0x28b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10421ULL;
	}
x86_l_2138:
	/* 0x2138: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_213b:
	/* 0x213b: ja     28ac <generic_fexit_filter_arg+0x28ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10412ULL;
	}
x86_l_2141:
	/* 0x2141: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2147:
	/* 0x2147: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_214b:
	/* 0x214b: jae    28ac <generic_fexit_filter_arg+0x28ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10412ULL;
	}
x86_l_2151:
	/* 0x2151: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2154:
	/* 0x2154: jl     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 639ULL;
	}
x86_l_215a:
	/* 0x215a: jmp    28b5 <generic_fexit_filter_arg+0x28b5> */
	return 10421ULL;
x86_l_215f:
	/* 0x215f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2162:
	/* 0x2162: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2167:
	/* 0x2167: jne    28b5 <generic_fexit_filter_arg+0x28b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10421ULL;
	}
x86_l_216d:
	/* 0x216d: test   DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2170:
	/* 0x2170: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_2176:
	/* 0x2176: jmp    28b5 <generic_fexit_filter_arg+0x28b5> */
	return 10421ULL;
x86_l_217b:
	/* 0x217b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_217e:
	/* 0x217e: ja     28a1 <generic_fexit_filter_arg+0x28a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10401ULL;
	}
x86_l_2184:
	/* 0x2184: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_218a:
	/* 0x218a: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_218e:
	/* 0x218e: jae    28a1 <generic_fexit_filter_arg+0x28a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10401ULL;
	}
x86_l_2194:
	/* 0x2194: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2197:
	/* 0x2197: jg     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 639ULL;
	}
x86_l_219d:
	/* 0x219d: jmp    28b5 <generic_fexit_filter_arg+0x28b5> */
	return 10421ULL;
x86_l_21a2:
	/* 0x21a2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21a4:
	/* 0x21a4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21a9:
	/* 0x21a9: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21ae:
	/* 0x21ae: jmp    246b <generic_fexit_filter_arg+0x246b> */
	goto x86_l_246b;
x86_l_21b3:
	/* 0x21b3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21b5:
	/* 0x21b5: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21ba:
	/* 0x21ba: jmp    248d <generic_fexit_filter_arg+0x248d> */
	goto x86_l_248d;
x86_l_21bf:
	/* 0x21bf: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21c2:
	/* 0x21c2: je     2787 <generic_fexit_filter_arg+0x2787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10119ULL;
	}
x86_l_21c8:
	/* 0x21c8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21cb:
	/* 0x21cb: jne    2793 <generic_fexit_filter_arg+0x2793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10131ULL;
	}
x86_l_21d1:
	/* 0x21d1: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21d5:
	/* 0x21d5: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_21d7:
	/* 0x21d7: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_21dd:
	/* 0x21dd: jmp    2793 <generic_fexit_filter_arg+0x2793> */
	return 10131ULL;
x86_l_21e2:
	/* 0x21e2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21e5:
	/* 0x21e5: je     27c6 <generic_fexit_filter_arg+0x27c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10182ULL;
	}
x86_l_21eb:
	/* 0x21eb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21ee:
	/* 0x21ee: jne    27d2 <generic_fexit_filter_arg+0x27d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10194ULL;
	}
x86_l_21f4:
	/* 0x21f4: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21f8:
	/* 0x21f8: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_21fa:
	/* 0x21fa: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_2200:
	/* 0x2200: jmp    27d2 <generic_fexit_filter_arg+0x27d2> */
	return 10194ULL;
x86_l_2205:
	/* 0x2205: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2208:
	/* 0x2208: mov    WORD PTR [rcx],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_220b:
	/* 0x220b: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_220f:
	/* 0x220f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2214:
	/* 0x2214: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2216:
	/* 0x2216: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2218:
	/* 0x2218: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_221a:
	/* 0x221a: jbe    223d <generic_fexit_filter_arg+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_223d;
	}
x86_l_221c:
	/* 0x221c: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2220:
	/* 0x2220: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2224:
	/* 0x2224: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2226:
	/* 0x2226: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_222c:
	/* 0x222c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2231:
	/* 0x2231: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2239:
	/* 0x2239: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_223b:
	/* 0x223b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223d:
	/* 0x223d: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2241:
	/* 0x2241: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2245:
	/* 0x2245: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2249:
	/* 0x2249: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_224c:
	/* 0x224c: jg     228d <generic_fexit_filter_arg+0x228d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_228d;
	}
x86_l_224e:
	/* 0x224e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2251:
	/* 0x2251: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2256:
	/* 0x2256: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_225b:
	/* 0x225b: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2260:
	/* 0x2260: jg     272d <generic_fexit_filter_arg+0x272d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10029ULL;
	}
x86_l_2266:
	/* 0x2266: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2268:
	/* 0x2268: je     2ad3 <generic_fexit_filter_arg+0x2ad3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10963ULL;
	}
x86_l_226e:
	/* 0x226e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2271:
	/* 0x2271: jne    854 <generic_fexit_filter_arg+0x854> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2132ULL;
	}
x86_l_2277:
	/* 0x2277: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_227c:
	/* 0x227c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2281:
	/* 0x2281: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2288:
	/* 0x2288: jmp    2b1d <generic_fexit_filter_arg+0x2b1d> */
	return 11037ULL;
x86_l_228d:
	/* 0x228d: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2290:
	/* 0x2290: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2295:
	/* 0x2295: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_229a:
	/* 0x229a: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_229f:
	/* 0x229f: jg     2755 <generic_fexit_filter_arg+0x2755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10069ULL;
	}
x86_l_22a5:
	/* 0x22a5: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22a8:
	/* 0x22a8: je     2ae6 <generic_fexit_filter_arg+0x2ae6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10982ULL;
	}
x86_l_22ae:
	/* 0x22ae: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_22b1:
	/* 0x22b1: jne    854 <generic_fexit_filter_arg+0x854> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2132ULL;
	}
x86_l_22b7:
	/* 0x22b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22bc:
	/* 0x22bc: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22c1:
	/* 0x22c1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_22c8:
	/* 0x22c8: jmp    2b1d <generic_fexit_filter_arg+0x2b1d> */
	return 11037ULL;
x86_l_22cd:
	/* 0x22cd: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_22d0:
	/* 0x22d0: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_22d5:
	/* 0x22d5: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_22da:
	/* 0x22da: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_22df:
	/* 0x22df: cmovae esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_22e2:
	/* 0x22e2: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_22e5:
	/* 0x22e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22e7:
	/* 0x22e7: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_22ec:
	/* 0x22ec: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_22ef:
	/* 0x22ef: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_22f2:
	/* 0x22f2: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_22f4:
	/* 0x22f4: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_22f7:
	/* 0x22f7: mov    eax,DWORD PTR [r15+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_22fc:
	/* 0x22fc: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_22ff:
	/* 0x22ff: je     2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12140ULL;
	}
x86_l_2305:
	/* 0x2305: mov    DWORD PTR [rsp+0x7c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2309:
	/* 0x2309: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_230d:
	/* 0x230d: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2311:
	/* 0x2311: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2316:
	/* 0x2316: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_231b:
	/* 0x231b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2322:
	/* 0x2322: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2327:
	/* 0x2327: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_232a:
	/* 0x232a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_232c:
	/* 0x232c: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_232f:
	/* 0x232f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2334:
	/* 0x2334: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_233b:
	/* 0x233b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_233e:
	/* 0x233e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2340:
	/* 0x2340: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_2343:
	/* 0x2343: je     2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12140ULL;
	}
x86_l_2349:
	/* 0x2349: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_234e:
	/* 0x234e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2351:
	/* 0x2351: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2356:
	/* 0x2356: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_235b:
	/* 0x235b: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2360:
	/* 0x2360: je     2f7d <generic_fexit_filter_arg+0x2f7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12157ULL;
	}
x86_l_2366:
	/* 0x2366: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2369:
	/* 0x2369: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2371:
	/* 0x2371: movzx  ebx,WORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 124ULL);
x86_l_2376:
	/* 0x2376: cmp    DWORD PTR [rsp+0x28],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691845ULL);
x86_l_237b:
	/* 0x237b: jg     2a24 <generic_fexit_filter_arg+0x2a24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10788ULL;
	}
x86_l_2381:
	/* 0x2381: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2384:
	/* 0x2384: mov    BYTE PTR [rcx],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2387:
	/* 0x2387: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_238b:
	/* 0x238b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2390:
	/* 0x2390: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2395:
	/* 0x2395: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2397:
	/* 0x2397: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2399:
	/* 0x2399: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_239b:
	/* 0x239b: jbe    2a61 <generic_fexit_filter_arg+0x2a61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 10849ULL;
	}
x86_l_23a1:
	/* 0x23a1: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_23a5:
	/* 0x23a5: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_23a8:
	/* 0x23a8: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23aa:
	/* 0x23aa: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23b0:
	/* 0x23b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23b5:
	/* 0x23b5: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_23bd:
	/* 0x23bd: jmp    2a5d <generic_fexit_filter_arg+0x2a5d> */
	return 10845ULL;
x86_l_23c2:
	/* 0x23c2: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_23c5:
	/* 0x23c5: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_23c9:
	/* 0x23c9: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_23cb:
	/* 0x23cb: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_23cf:
	/* 0x23cf: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_23d2:
	/* 0x23d2: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_23d5:
	/* 0x23d5: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_23d8:
	/* 0x23d8: jb     2b72 <generic_fexit_filter_arg+0x2b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11122ULL;
	}
x86_l_23de:
	/* 0x23de: mov    r8d,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23e2:
	/* 0x23e2: mov    edi,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23e6:
	/* 0x23e6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_23e9:
	/* 0x23e9: ja     2805 <generic_fexit_filter_arg+0x2805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10245ULL;
	}
x86_l_23ef:
	/* 0x23ef: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_23f5:
	/* 0x23f5: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_23f9:
	/* 0x23f9: jae    2805 <generic_fexit_filter_arg+0x2805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10245ULL;
	}
x86_l_23ff:
	/* 0x23ff: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2402:
	/* 0x2402: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2406:
	/* 0x2406: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2408:
	/* 0x2408: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_240c:
	/* 0x240c: jmp    2812 <generic_fexit_filter_arg+0x2812> */
	return 10258ULL;
x86_l_2411:
	/* 0x2411: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2413:
	/* 0x2413: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2418:
	/* 0x2418: ja     2422 <generic_fexit_filter_arg+0x2422> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2422;
	}
x86_l_241a:
	/* 0x241a: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_241c:
	/* 0x241c: jbe    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 639ULL;
	}
x86_l_2422:
	/* 0x2422: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2425:
	/* 0x2425: jb     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 184ULL;
	}
x86_l_242b:
	/* 0x242b: mov    edi,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_242f:
	/* 0x242f: mov    esi,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2433:
	/* 0x2433: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2436:
	/* 0x2436: ja     2851 <generic_fexit_filter_arg+0x2851> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10321ULL;
	}
x86_l_243c:
	/* 0x243c: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2442:
	/* 0x2442: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2446:
	/* 0x2446: jae    2851 <generic_fexit_filter_arg+0x2851> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10321ULL;
	}
x86_l_244c:
	/* 0x244c: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_244e:
	/* 0x244e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2453:
	/* 0x2453: jg     2862 <generic_fexit_filter_arg+0x2862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10338ULL;
	}
x86_l_2459:
	/* 0x2459: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_245b:
	/* 0x245b: jle    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 639ULL;
	}
x86_l_2461:
	/* 0x2461: jmp    2862 <generic_fexit_filter_arg+0x2862> */
	return 10338ULL;
x86_l_2466:
	/* 0x2466: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_246b:
	/* 0x246b: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2470:
	/* 0x2470: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2475:
	/* 0x2475: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2479:
	/* 0x2479: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_247d:
	/* 0x247d: jbe    2d02 <generic_fexit_filter_arg+0x2d02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11522ULL;
	}
x86_l_2483:
	/* 0x2483: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_2488:
	/* 0x2488: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_248d:
	/* 0x248d: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2492:
	/* 0x2492: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2497:
	/* 0x2497: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_249c:
	/* 0x249c: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24a0:
	/* 0x24a0: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_24a4:
	/* 0x24a4: jbe    2d02 <generic_fexit_filter_arg+0x2d02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11522ULL;
	}
x86_l_24aa:
	/* 0x24aa: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_24af:
	/* 0x24af: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_24b2:
	/* 0x24b2: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_24b6:
	/* 0x24b6: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_24b9:
	/* 0x24b9: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_24bd:
	/* 0x24bd: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_24c0:
	/* 0x24c0: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_24c3:
	/* 0x24c3: cmp    esi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_24c6:
	/* 0x24c6: jb     2b72 <generic_fexit_filter_arg+0x2b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11122ULL;
	}
x86_l_24cc:
	/* 0x24cc: mov    rdi,QWORD PTR [r15+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_24d0:
	/* 0x24d0: mov    rsi,QWORD PTR [r15+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_24d4:
	/* 0x24d4: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_24d7:
	/* 0x24d7: je     24e2 <generic_fexit_filter_arg+0x24e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e2;
	}
x86_l_24d9:
	/* 0x24d9: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_24dc:
	/* 0x24dc: jne    295a <generic_fexit_filter_arg+0x295a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10586ULL;
	}
x86_l_24e2:
	/* 0x24e2: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_24e5:
	/* 0x24e5: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_24e8:
	/* 0x24e8: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_24eb:
	/* 0x24eb: jmp    2849 <generic_fexit_filter_arg+0x2849> */
	return 10313ULL;
x86_l_24f0:
	/* 0x24f0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24f2:
	/* 0x24f2: jmp    269 <generic_fexit_filter_arg+0x269> */
	return 617ULL;
x86_l_24f7:
	/* 0x24f7: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24fc:
	/* 0x24fc: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ff:
	/* 0x24ff: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2503:
	/* 0x2503: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2508:
	/* 0x2508: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_250d:
	/* 0x250d: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_250f:
	/* 0x250f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2511:
	/* 0x2511: movzx  esi,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_2519:
	/* 0x2519: cmp    esi,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_251b:
	/* 0x251b: jbe    253c <generic_fexit_filter_arg+0x253c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_253c;
	}
x86_l_251d:
	/* 0x251d: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2522:
	/* 0x2522: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2526:
	/* 0x2526: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_252a:
	/* 0x252a: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_252c:
	/* 0x252c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2532:
	/* 0x2532: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2537:
	/* 0x2537: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_253a:
	/* 0x253a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253c:
	/* 0x253c: mov    eax,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2540:
	/* 0x2540: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2544:
	/* 0x2544: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2548:
	/* 0x2548: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_254b:
	/* 0x254b: jg     2587 <generic_fexit_filter_arg+0x2587> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2587;
	}
x86_l_254d:
	/* 0x254d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2550:
	/* 0x2550: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2555:
	/* 0x2555: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_255a:
	/* 0x255a: jg     2968 <generic_fexit_filter_arg+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10600ULL;
	}
x86_l_2560:
	/* 0x2560: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2562:
	/* 0x2562: je     2c79 <generic_fexit_filter_arg+0x2c79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11385ULL;
	}
x86_l_2568:
	/* 0x2568: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_256b:
	/* 0x256b: jne    2d1b <generic_fexit_filter_arg+0x2d1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11547ULL;
	}
x86_l_2571:
	/* 0x2571: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2576:
	/* 0x2576: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_257b:
	/* 0x257b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2582:
	/* 0x2582: jmp    2cc3 <generic_fexit_filter_arg+0x2cc3> */
	return 11459ULL;
x86_l_2587:
	/* 0x2587: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_258a:
	/* 0x258a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_258f:
	/* 0x258f: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2594:
	/* 0x2594: jg     2990 <generic_fexit_filter_arg+0x2990> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10640ULL;
	}
x86_l_259a:
	/* 0x259a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_259d:
	/* 0x259d: je     2c8c <generic_fexit_filter_arg+0x2c8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11404ULL;
	}
x86_l_25a3:
	/* 0x25a3: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_25a6:
	/* 0x25a6: jne    2d1b <generic_fexit_filter_arg+0x2d1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11547ULL;
	}
x86_l_25ac:
	/* 0x25ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25b1:
	/* 0x25b1: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25b6:
	/* 0x25b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_25bd:
	/* 0x25bd: jmp    2cc3 <generic_fexit_filter_arg+0x2cc3> */
	return 11459ULL;
x86_l_25c2:
	/* 0x25c2: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_25c5:
	/* 0x25c5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 9674ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9674ULL: goto x86_l_25ca;
	case 9676ULL: goto x86_l_25cc;
	case 9679ULL: goto x86_l_25cf;
	case 9685ULL: goto x86_l_25d5;
	case 9688ULL: goto x86_l_25d8;
	case 9694ULL: goto x86_l_25de;
	case 9698ULL: goto x86_l_25e2;
	case 9702ULL: goto x86_l_25e6;
	case 9705ULL: goto x86_l_25e9;
	case 9707ULL: goto x86_l_25eb;
	case 9710ULL: goto x86_l_25ee;
	case 9716ULL: goto x86_l_25f4;
	case 9719ULL: goto x86_l_25f7;
	case 9725ULL: goto x86_l_25fd;
	case 9728ULL: goto x86_l_2600;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9743ULL: goto x86_l_260f;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9755ULL: goto x86_l_261b;
	case 9761ULL: goto x86_l_2621;
	case 9764ULL: goto x86_l_2624;
	case 9770ULL: goto x86_l_262a;
	case 9774ULL: goto x86_l_262e;
	case 9777ULL: goto x86_l_2631;
	case 9779ULL: goto x86_l_2633;
	case 9782ULL: goto x86_l_2636;
	case 9785ULL: goto x86_l_2639;
	case 9787ULL: goto x86_l_263b;
	case 9791ULL: goto x86_l_263f;
	case 9796ULL: goto x86_l_2644;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9810ULL: goto x86_l_2652;
	case 9816ULL: goto x86_l_2658;
	case 9819ULL: goto x86_l_265b;
	case 9825ULL: goto x86_l_2661;
	case 9828ULL: goto x86_l_2664;
	case 9830ULL: goto x86_l_2666;
	case 9833ULL: goto x86_l_2669;
	case 9839ULL: goto x86_l_266f;
	case 9843ULL: goto x86_l_2673;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9857ULL: goto x86_l_2681;
	case 9862ULL: goto x86_l_2686;
	case 9868ULL: goto x86_l_268c;
	case 9872ULL: goto x86_l_2690;
	case 9878ULL: goto x86_l_2696;
	case 9883ULL: goto x86_l_269b;
	case 9886ULL: goto x86_l_269e;
	case 9892ULL: goto x86_l_26a4;
	case 9896ULL: goto x86_l_26a8;
	case 9898ULL: goto x86_l_26aa;
	case 9904ULL: goto x86_l_26b0;
	case 9909ULL: goto x86_l_26b5;
	case 9912ULL: goto x86_l_26b8;
	case 9918ULL: goto x86_l_26be;
	case 9922ULL: goto x86_l_26c2;
	case 9924ULL: goto x86_l_26c4;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9945ULL: goto x86_l_26d9;
	case 9950ULL: goto x86_l_26de;
	case 9953ULL: goto x86_l_26e1;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9968ULL: goto x86_l_26f0;
	case 9973ULL: goto x86_l_26f5;
	case 9978ULL: goto x86_l_26fa;
	case 9981ULL: goto x86_l_26fd;
	case 9983ULL: goto x86_l_26ff;
	case 9986ULL: goto x86_l_2702;
	case 9992ULL: goto x86_l_2708;
	case 9996ULL: goto x86_l_270c;
	case 10002ULL: goto x86_l_2712;
	case 10007ULL: goto x86_l_2717;
	case 10009ULL: goto x86_l_2719;
	case 10014ULL: goto x86_l_271e;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10032ULL: goto x86_l_2730;
	case 10038ULL: goto x86_l_2736;
	case 10041ULL: goto x86_l_2739;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10064ULL: goto x86_l_2750;
	case 10069ULL: goto x86_l_2755;
	case 10072ULL: goto x86_l_2758;
	case 10078ULL: goto x86_l_275e;
	case 10081ULL: goto x86_l_2761;
	case 10087ULL: goto x86_l_2767;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10104ULL: goto x86_l_2778;
	case 10109ULL: goto x86_l_277d;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10123ULL: goto x86_l_278b;
	case 10125ULL: goto x86_l_278d;
	case 10131ULL: goto x86_l_2793;
	case 10134ULL: goto x86_l_2796;
	case 10140ULL: goto x86_l_279c;
	case 10144ULL: goto x86_l_27a0;
	case 10147ULL: goto x86_l_27a3;
	case 10153ULL: goto x86_l_27a9;
	case 10156ULL: goto x86_l_27ac;
	case 10159ULL: goto x86_l_27af;
	case 10165ULL: goto x86_l_27b5;
	case 10169ULL: goto x86_l_27b9;
	case 10171ULL: goto x86_l_27bb;
	case 10177ULL: goto x86_l_27c1;
	case 10182ULL: goto x86_l_27c6;
	case 10186ULL: goto x86_l_27ca;
	case 10188ULL: goto x86_l_27cc;
	case 10194ULL: goto x86_l_27d2;
	case 10197ULL: goto x86_l_27d5;
	case 10203ULL: goto x86_l_27db;
	case 10207ULL: goto x86_l_27df;
	case 10210ULL: goto x86_l_27e2;
	case 10216ULL: goto x86_l_27e8;
	case 10219ULL: goto x86_l_27eb;
	case 10222ULL: goto x86_l_27ee;
	case 10228ULL: goto x86_l_27f4;
	case 10232ULL: goto x86_l_27f8;
	case 10234ULL: goto x86_l_27fa;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10248ULL: goto x86_l_2808;
	case 10252ULL: goto x86_l_280c;
	case 10254ULL: goto x86_l_280e;
	case 10258ULL: goto x86_l_2812;
	case 10261ULL: goto x86_l_2815;
	case 10264ULL: goto x86_l_2818;
	case 10267ULL: goto x86_l_281b;
	case 10273ULL: goto x86_l_2821;
	case 10277ULL: goto x86_l_2825;
	case 10281ULL: goto x86_l_2829;
	case 10284ULL: goto x86_l_282c;
	case 10290ULL: goto x86_l_2832;
	case 10296ULL: goto x86_l_2838;
	case 10300ULL: goto x86_l_283c;
	case 10306ULL: goto x86_l_2842;
	case 10308ULL: goto x86_l_2844;
	case 10311ULL: goto x86_l_2847;
	case 10313ULL: goto x86_l_2849;
	case 10316ULL: goto x86_l_284c;
	case 10321ULL: goto x86_l_2851;
	case 10323ULL: goto x86_l_2853;
	case 10328ULL: goto x86_l_2858;
	case 10330ULL: goto x86_l_285a;
	case 10332ULL: goto x86_l_285c;
	case 10338ULL: goto x86_l_2862;
	case 10341ULL: goto x86_l_2865;
	case 10347ULL: goto x86_l_286b;
	case 10351ULL: goto x86_l_286f;
	case 10355ULL: goto x86_l_2873;
	case 10358ULL: goto x86_l_2876;
	case 10364ULL: goto x86_l_287c;
	case 10370ULL: goto x86_l_2882;
	case 10374ULL: goto x86_l_2886;
	case 10380ULL: goto x86_l_288c;
	case 10382ULL: goto x86_l_288e;
	case 10388ULL: goto x86_l_2894;
	case 10390ULL: goto x86_l_2896;
	case 10396ULL: goto x86_l_289c;
	case 10401ULL: goto x86_l_28a1;
	case 10404ULL: goto x86_l_28a4;
	case 10410ULL: goto x86_l_28aa;
	case 10412ULL: goto x86_l_28ac;
	case 10415ULL: goto x86_l_28af;
	case 10421ULL: goto x86_l_28b5;
	case 10424ULL: goto x86_l_28b8;
	case 10430ULL: goto x86_l_28be;
	case 10434ULL: goto x86_l_28c2;
	case 10437ULL: goto x86_l_28c5;
	case 10439ULL: goto x86_l_28c7;
	case 10442ULL: goto x86_l_28ca;
	case 10445ULL: goto x86_l_28cd;
	case 10447ULL: goto x86_l_28cf;
	case 10450ULL: goto x86_l_28d2;
	case 10455ULL: goto x86_l_28d7;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10469ULL: goto x86_l_28e5;
	case 10471ULL: goto x86_l_28e7;
	case 10474ULL: goto x86_l_28ea;
	case 10480ULL: goto x86_l_28f0;
	case 10483ULL: goto x86_l_28f3;
	case 10489ULL: goto x86_l_28f9;
	case 10495ULL: goto x86_l_28ff;
	case 10499ULL: goto x86_l_2903;
	case 10505ULL: goto x86_l_2909;
	case 10508ULL: goto x86_l_290c;
	case 10514ULL: goto x86_l_2912;
	case 10519ULL: goto x86_l_2917;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10533ULL: goto x86_l_2925;
	case 10536ULL: goto x86_l_2928;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10550ULL: goto x86_l_2936;
	case 10556ULL: goto x86_l_293c;
	case 10562ULL: goto x86_l_2942;
	case 10566ULL: goto x86_l_2946;
	case 10572ULL: goto x86_l_294c;
	case 10575ULL: goto x86_l_294f;
	case 10581ULL: goto x86_l_2955;
	case 10586ULL: goto x86_l_295a;
	case 10589ULL: goto x86_l_295d;
	case 10592ULL: goto x86_l_2960;
	case 10595ULL: goto x86_l_2963;
	case 10600ULL: goto x86_l_2968;
	case 10603ULL: goto x86_l_296b;
	case 10609ULL: goto x86_l_2971;
	case 10612ULL: goto x86_l_2974;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10628ULL: goto x86_l_2984;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10643ULL: goto x86_l_2993;
	case 10649ULL: goto x86_l_2999;
	case 10652ULL: goto x86_l_299c;
	case 10658ULL: goto x86_l_29a2;
	case 10663ULL: goto x86_l_29a7;
	case 10668ULL: goto x86_l_29ac;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10683ULL: goto x86_l_29bb;
	case 10689ULL: goto x86_l_29c1;
	case 10692ULL: goto x86_l_29c4;
	case 10698ULL: goto x86_l_29ca;
	case 10703ULL: goto x86_l_29cf;
	case 10706ULL: goto x86_l_29d2;
	case 10712ULL: goto x86_l_29d8;
	case 10715ULL: goto x86_l_29db;
	case 10721ULL: goto x86_l_29e1;
	case 10725ULL: goto x86_l_29e5;
	case 10727ULL: goto x86_l_29e7;
	case 10733ULL: goto x86_l_29ed;
	case 10738ULL: goto x86_l_29f2;
	case 10741ULL: goto x86_l_29f5;
	case 10747ULL: goto x86_l_29fb;
	case 10750ULL: goto x86_l_29fe;
	case 10756ULL: goto x86_l_2a04;
	case 10760ULL: goto x86_l_2a08;
	case 10762ULL: goto x86_l_2a0a;
	case 10768ULL: goto x86_l_2a10;
	case 10773ULL: goto x86_l_2a15;
	case 10778ULL: goto x86_l_2a1a;
	case 10783ULL: goto x86_l_2a1f;
	case 10788ULL: goto x86_l_2a24;
	case 10791ULL: goto x86_l_2a27;
	case 10794ULL: goto x86_l_2a2a;
	case 10798ULL: goto x86_l_2a2e;
	case 10803ULL: goto x86_l_2a33;
	case 10808ULL: goto x86_l_2a38;
	case 10810ULL: goto x86_l_2a3a;
	case 10812ULL: goto x86_l_2a3c;
	case 10814ULL: goto x86_l_2a3e;
	case 10816ULL: goto x86_l_2a40;
	case 10820ULL: goto x86_l_2a44;
	case 10824ULL: goto x86_l_2a48;
	case 10826ULL: goto x86_l_2a4a;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10845ULL: goto x86_l_2a5d;
	case 10847ULL: goto x86_l_2a5f;
	case 10849ULL: goto x86_l_2a61;
	case 10853ULL: goto x86_l_2a65;
	case 10857ULL: goto x86_l_2a69;
	case 10861ULL: goto x86_l_2a6d;
	case 10864ULL: goto x86_l_2a70;
	case 10866ULL: goto x86_l_2a72;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10880ULL: goto x86_l_2a80;
	case 10882ULL: goto x86_l_2a82;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10909ULL: goto x86_l_2a9d;
	case 10914ULL: goto x86_l_2aa2;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10928ULL: goto x86_l_2ab0;
	case 10931ULL: goto x86_l_2ab3;
	case 10937ULL: goto x86_l_2ab9;
	case 10940ULL: goto x86_l_2abc;
	case 10946ULL: goto x86_l_2ac2;
	case 10951ULL: goto x86_l_2ac7;
	case 10958ULL: goto x86_l_2ace;
	case 10963ULL: goto x86_l_2ad3;
	case 10968ULL: goto x86_l_2ad8;
	case 10975ULL: goto x86_l_2adf;
	case 10980ULL: goto x86_l_2ae4;
	case 10982ULL: goto x86_l_2ae6;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10999ULL: goto x86_l_2af7;
	case 11001ULL: goto x86_l_2af9;
	case 11006ULL: goto x86_l_2afe;
	case 11011ULL: goto x86_l_2b03;
	case 11018ULL: goto x86_l_2b0a;
	case 11020ULL: goto x86_l_2b0c;
	case 11025ULL: goto x86_l_2b11;
	case 11030ULL: goto x86_l_2b16;
	case 11037ULL: goto x86_l_2b1d;
	case 11039ULL: goto x86_l_2b1f;
	case 11042ULL: goto x86_l_2b22;
	case 11044ULL: goto x86_l_2b24;
	case 11047ULL: goto x86_l_2b27;
	case 11052ULL: goto x86_l_2b2c;
	case 11055ULL: goto x86_l_2b2f;
	case 11057ULL: goto x86_l_2b31;
	case 11059ULL: goto x86_l_2b33;
	case 11062ULL: goto x86_l_2b36;
	case 11065ULL: goto x86_l_2b39;
	case 11067ULL: goto x86_l_2b3b;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11079ULL: goto x86_l_2b47;
	case 11084ULL: goto x86_l_2b4c;
	case 11089ULL: goto x86_l_2b51;
	case 11093ULL: goto x86_l_2b55;
	case 11097ULL: goto x86_l_2b59;
	case 11103ULL: goto x86_l_2b5f;
	case 11108ULL: goto x86_l_2b64;
	case 11110ULL: goto x86_l_2b66;
	case 11113ULL: goto x86_l_2b69;
	case 11115ULL: goto x86_l_2b6b;
	case 11118ULL: goto x86_l_2b6e;
	case 11120ULL: goto x86_l_2b70;
	case 11122ULL: goto x86_l_2b72;
	case 11127ULL: goto x86_l_2b77;
	case 11129ULL: goto x86_l_2b79;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11144ULL: goto x86_l_2b88;
	case 11150ULL: goto x86_l_2b8e;
	case 11152ULL: goto x86_l_2b90;
	case 11156ULL: goto x86_l_2b94;
	case 11162ULL: goto x86_l_2b9a;
	case 11165ULL: goto x86_l_2b9d;
	case 11171ULL: goto x86_l_2ba3;
	case 11175ULL: goto x86_l_2ba7;
	case 11178ULL: goto x86_l_2baa;
	case 11180ULL: goto x86_l_2bac;
	case 11183ULL: goto x86_l_2baf;
	case 11186ULL: goto x86_l_2bb2;
	case 11188ULL: goto x86_l_2bb4;
	case 11191ULL: goto x86_l_2bb7;
	case 11197ULL: goto x86_l_2bbd;
	case 11200ULL: goto x86_l_2bc0;
	case 11206ULL: goto x86_l_2bc6;
	case 11210ULL: goto x86_l_2bca;
	case 11216ULL: goto x86_l_2bd0;
	case 11221ULL: goto x86_l_2bd5;
	case 11224ULL: goto x86_l_2bd8;
	case 11230ULL: goto x86_l_2bde;
	case 11233ULL: goto x86_l_2be1;
	case 11239ULL: goto x86_l_2be7;
	case 11242ULL: goto x86_l_2bea;
	case 11244ULL: goto x86_l_2bec;
	case 11247ULL: goto x86_l_2bef;
	case 11253ULL: goto x86_l_2bf5;
	case 11257ULL: goto x86_l_2bf9;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11272ULL: goto x86_l_2c08;
	case 11278ULL: goto x86_l_2c0e;
	case 11283ULL: goto x86_l_2c13;
	case 11286ULL: goto x86_l_2c16;
	case 11292ULL: goto x86_l_2c1c;
	case 11296ULL: goto x86_l_2c20;
	case 11298ULL: goto x86_l_2c22;
	case 11304ULL: goto x86_l_2c28;
	default: return 0xffffffffffffffffULL;
	}
x86_l_25ca:
	/* 0x25ca: ja     25d5 <generic_fexit_filter_arg+0x25d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25d5;
	}
x86_l_25cc:
	/* 0x25cc: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_25cf:
	/* 0x25cf: jbe    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 639ULL;
	}
x86_l_25d5:
	/* 0x25d5: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_25d8:
	/* 0x25d8: jb     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 184ULL;
	}
x86_l_25de:
	/* 0x25de: mov    rsi,QWORD PTR [r15+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25e2:
	/* 0x25e2: mov    rdx,QWORD PTR [r15+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25e6:
	/* 0x25e6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_25e9:
	/* 0x25e9: je     25f4 <generic_fexit_filter_arg+0x25f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25f4;
	}
x86_l_25eb:
	/* 0x25eb: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_25ee:
	/* 0x25ee: jne    29b8 <generic_fexit_filter_arg+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29b8;
	}
x86_l_25f4:
	/* 0x25f4: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_25f7:
	/* 0x25f7: jg     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 184ULL;
	}
x86_l_25fd:
	/* 0x25fd: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2600:
	/* 0x2600: jle    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 639ULL;
	}
x86_l_2606:
	/* 0x2606: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	return 184ULL;
x86_l_260b:
	/* 0x260b: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_260f:
	/* 0x260f: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_2615:
	/* 0x2615: jmp    2621 <generic_fexit_filter_arg+0x2621> */
	goto x86_l_2621;
x86_l_2617:
	/* 0x2617: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_261b:
	/* 0x261b: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_2621:
	/* 0x2621: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2624:
	/* 0x2624: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12276ULL;
	}
x86_l_262a:
	/* 0x262a: mov    rsi,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_262e:
	/* 0x262e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2631:
	/* 0x2631: jle    264f <generic_fexit_filter_arg+0x264f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_264f;
	}
x86_l_2633:
	/* 0x2633: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2636:
	/* 0x2636: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2639:
	/* 0x2639: jae    267e <generic_fexit_filter_arg+0x267e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_267e;
	}
x86_l_263b:
	/* 0x263b: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_263f:
	/* 0x263f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2644:
	/* 0x2644: jne    2b9a <generic_fexit_filter_arg+0x2b9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b9a;
	}
x86_l_264a:
	/* 0x264a: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_264f:
	/* 0x264f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2652:
	/* 0x2652: je     26fa <generic_fexit_filter_arg+0x26fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26fa;
	}
x86_l_2658:
	/* 0x2658: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_265b:
	/* 0x265b: jne    2b9a <generic_fexit_filter_arg+0x2b9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b9a;
	}
x86_l_2661:
	/* 0x2661: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2664:
	/* 0x2664: je     266f <generic_fexit_filter_arg+0x266f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_266f;
	}
x86_l_2666:
	/* 0x2666: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2669:
	/* 0x2669: jne    2b90 <generic_fexit_filter_arg+0x2b90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b90;
	}
x86_l_266f:
	/* 0x266f: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2673:
	/* 0x2673: jl     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 639ULL;
	}
x86_l_2679:
	/* 0x2679: jmp    2b9a <generic_fexit_filter_arg+0x2b9a> */
	goto x86_l_2b9a;
x86_l_267e:
	/* 0x267e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2681:
	/* 0x2681: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2686:
	/* 0x2686: jne    2b9a <generic_fexit_filter_arg+0x2b9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b9a;
	}
x86_l_268c:
	/* 0x268c: test   QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2690:
	/* 0x2690: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_2696:
	/* 0x2696: jmp    2b9a <generic_fexit_filter_arg+0x2b9a> */
	goto x86_l_2b9a;
x86_l_269b:
	/* 0x269b: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_269e:
	/* 0x269e: jne    2793 <generic_fexit_filter_arg+0x2793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2793;
	}
x86_l_26a4:
	/* 0x26a4: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_26a8:
	/* 0x26a8: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_26aa:
	/* 0x26aa: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_26b0:
	/* 0x26b0: jmp    2793 <generic_fexit_filter_arg+0x2793> */
	goto x86_l_2793;
x86_l_26b5:
	/* 0x26b5: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_26b8:
	/* 0x26b8: jne    27d2 <generic_fexit_filter_arg+0x27d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27d2;
	}
x86_l_26be:
	/* 0x26be: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26c2:
	/* 0x26c2: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_26c4:
	/* 0x26c4: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_26ca:
	/* 0x26ca: jmp    27d2 <generic_fexit_filter_arg+0x27d2> */
	goto x86_l_27d2;
x86_l_26cf:
	/* 0x26cf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26d4:
	/* 0x26d4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26d9:
	/* 0x26d9: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26de:
	/* 0x26de: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_26e1:
	/* 0x26e1: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_26e6:
	/* 0x26e6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26eb:
	/* 0x26eb: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f0:
	/* 0x26f0: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26f5:
	/* 0x26f5: jmp    1b2f <generic_fexit_filter_arg+0x1b2f> */
	return 6959ULL;
x86_l_26fa:
	/* 0x26fa: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_26fd:
	/* 0x26fd: je     2708 <generic_fexit_filter_arg+0x2708> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2708;
	}
x86_l_26ff:
	/* 0x26ff: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2702:
	/* 0x2702: jne    2b84 <generic_fexit_filter_arg+0x2b84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b84;
	}
x86_l_2708:
	/* 0x2708: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_270c:
	/* 0x270c: jg     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 639ULL;
	}
x86_l_2712:
	/* 0x2712: jmp    2b9a <generic_fexit_filter_arg+0x2b9a> */
	goto x86_l_2b9a;
x86_l_2717:
	/* 0x2717: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2719:
	/* 0x2719: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_271e:
	/* 0x271e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2723:
	/* 0x2723: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2728:
	/* 0x2728: jmp    2f7d <generic_fexit_filter_arg+0x2f7d> */
	return 12157ULL;
x86_l_272d:
	/* 0x272d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2730:
	/* 0x2730: je     2af9 <generic_fexit_filter_arg+0x2af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2af9;
	}
x86_l_2736:
	/* 0x2736: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2739:
	/* 0x2739: jne    854 <generic_fexit_filter_arg+0x854> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2132ULL;
	}
x86_l_273f:
	/* 0x273f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2744:
	/* 0x2744: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2749:
	/* 0x2749: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2750:
	/* 0x2750: jmp    2b1d <generic_fexit_filter_arg+0x2b1d> */
	goto x86_l_2b1d;
x86_l_2755:
	/* 0x2755: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2758:
	/* 0x2758: je     2b0c <generic_fexit_filter_arg+0x2b0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b0c;
	}
x86_l_275e:
	/* 0x275e: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2761:
	/* 0x2761: jne    854 <generic_fexit_filter_arg+0x854> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2132ULL;
	}
x86_l_2767:
	/* 0x2767: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_276c:
	/* 0x276c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2771:
	/* 0x2771: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2778:
	/* 0x2778: jmp    2b1d <generic_fexit_filter_arg+0x2b1d> */
	goto x86_l_2b1d;
x86_l_277d:
	/* 0x277d: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2782:
	/* 0x2782: jmp    2f6e <generic_fexit_filter_arg+0x2f6e> */
	return 12142ULL;
x86_l_2787:
	/* 0x2787: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_278b:
	/* 0x278b: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_278d:
	/* 0x278d: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_2793:
	/* 0x2793: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2796:
	/* 0x2796: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12276ULL;
	}
x86_l_279c:
	/* 0x279c: mov    edx,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27a0:
	/* 0x27a0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27a3:
	/* 0x27a3: jle    29cf <generic_fexit_filter_arg+0x29cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_29cf;
	}
x86_l_27a9:
	/* 0x27a9: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_27ac:
	/* 0x27ac: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_27af:
	/* 0x27af: jae    2c13 <generic_fexit_filter_arg+0x2c13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2c13;
	}
x86_l_27b5:
	/* 0x27b5: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_27b9:
	/* 0x27b9: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_27bb:
	/* 0x27bb: jne    2d83 <generic_fexit_filter_arg+0x2d83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11651ULL;
	}
x86_l_27c1:
	/* 0x27c1: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_27c6:
	/* 0x27c6: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27ca:
	/* 0x27ca: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_27cc:
	/* 0x27cc: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_27d2:
	/* 0x27d2: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_27d5:
	/* 0x27d5: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12276ULL;
	}
x86_l_27db:
	/* 0x27db: mov    edx,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27df:
	/* 0x27df: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27e2:
	/* 0x27e2: jle    29f2 <generic_fexit_filter_arg+0x29f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_29f2;
	}
x86_l_27e8:
	/* 0x27e8: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_27eb:
	/* 0x27eb: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_27ee:
	/* 0x27ee: jae    2c2d <generic_fexit_filter_arg+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11309ULL;
	}
x86_l_27f4:
	/* 0x27f4: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27f8:
	/* 0x27f8: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_27fa:
	/* 0x27fa: jne    2dc9 <generic_fexit_filter_arg+0x2dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11721ULL;
	}
x86_l_2800:
	/* 0x2800: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_2805:
	/* 0x2805: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2808:
	/* 0x2808: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_280c:
	/* 0x280c: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_280e:
	/* 0x280e: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2812:
	/* 0x2812: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2815:
	/* 0x2815: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2818:
	/* 0x2818: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_281b:
	/* 0x281b: jb     2b72 <generic_fexit_filter_arg+0x2b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b72;
	}
x86_l_2821:
	/* 0x2821: mov    edi,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2825:
	/* 0x2825: mov    esi,DWORD PTR [r15+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2829:
	/* 0x2829: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_282c:
	/* 0x282c: ja     2b64 <generic_fexit_filter_arg+0x2b64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b64;
	}
x86_l_2832:
	/* 0x2832: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2838:
	/* 0x2838: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_283c:
	/* 0x283c: jae    2b64 <generic_fexit_filter_arg+0x2b64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2b64;
	}
x86_l_2842:
	/* 0x2842: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2844:
	/* 0x2844: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_2847:
	/* 0x2847: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2849:
	/* 0x2849: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_284c:
	/* 0x284c: jmp    2b6e <generic_fexit_filter_arg+0x2b6e> */
	goto x86_l_2b6e;
x86_l_2851:
	/* 0x2851: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2853:
	/* 0x2853: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2858:
	/* 0x2858: ja     2862 <generic_fexit_filter_arg+0x2862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2862;
	}
x86_l_285a:
	/* 0x285a: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_285c:
	/* 0x285c: jbe    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 639ULL;
	}
x86_l_2862:
	/* 0x2862: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2865:
	/* 0x2865: jb     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 184ULL;
	}
x86_l_286b:
	/* 0x286b: mov    esi,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_286f:
	/* 0x286f: mov    edx,DWORD PTR [r15+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2873:
	/* 0x2873: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2876:
	/* 0x2876: ja     2c47 <generic_fexit_filter_arg+0x2c47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11335ULL;
	}
x86_l_287c:
	/* 0x287c: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2882:
	/* 0x2882: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2886:
	/* 0x2886: jae    2c47 <generic_fexit_filter_arg+0x2c47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11335ULL;
	}
x86_l_288c:
	/* 0x288c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_288e:
	/* 0x288e: jg     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 184ULL;
	}
x86_l_2894:
	/* 0x2894: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2896:
	/* 0x2896: jle    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 639ULL;
	}
x86_l_289c:
	/* 0x289c: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	return 184ULL;
x86_l_28a1:
	/* 0x28a1: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a4:
	/* 0x28a4: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_28aa:
	/* 0x28aa: jmp    28b5 <generic_fexit_filter_arg+0x28b5> */
	goto x86_l_28b5;
x86_l_28ac:
	/* 0x28ac: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28af:
	/* 0x28af: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_28b5:
	/* 0x28b5: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_28b8:
	/* 0x28b8: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12276ULL;
	}
x86_l_28be:
	/* 0x28be: mov    esi,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28c2:
	/* 0x28c2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28c5:
	/* 0x28c5: jle    28e2 <generic_fexit_filter_arg+0x28e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_28e2;
	}
x86_l_28c7:
	/* 0x28c7: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_28ca:
	/* 0x28ca: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_28cd:
	/* 0x28cd: jae    2917 <generic_fexit_filter_arg+0x2917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2917;
	}
x86_l_28cf:
	/* 0x28cf: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d2:
	/* 0x28d2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28d7:
	/* 0x28d7: jne    2e22 <generic_fexit_filter_arg+0x2e22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11810ULL;
	}
x86_l_28dd:
	/* 0x28dd: jmp    2f0b <generic_fexit_filter_arg+0x2f0b> */
	return 12043ULL;
x86_l_28e2:
	/* 0x28e2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28e5:
	/* 0x28e5: je     2933 <generic_fexit_filter_arg+0x2933> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2933;
	}
x86_l_28e7:
	/* 0x28e7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28ea:
	/* 0x28ea: jne    2e22 <generic_fexit_filter_arg+0x2e22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11810ULL;
	}
x86_l_28f0:
	/* 0x28f0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_28f3:
	/* 0x28f3: ja     2e19 <generic_fexit_filter_arg+0x2e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11801ULL;
	}
x86_l_28f9:
	/* 0x28f9: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_28ff:
	/* 0x28ff: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2903:
	/* 0x2903: jae    2e19 <generic_fexit_filter_arg+0x2e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11801ULL;
	}
x86_l_2909:
	/* 0x2909: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_290c:
	/* 0x290c: jl     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 639ULL;
	}
x86_l_2912:
	/* 0x2912: jmp    2e22 <generic_fexit_filter_arg+0x2e22> */
	return 11810ULL;
x86_l_2917:
	/* 0x2917: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_291a:
	/* 0x291a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_291f:
	/* 0x291f: jne    2e22 <generic_fexit_filter_arg+0x2e22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11810ULL;
	}
x86_l_2925:
	/* 0x2925: test   DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2928:
	/* 0x2928: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_292e:
	/* 0x292e: jmp    2e22 <generic_fexit_filter_arg+0x2e22> */
	return 11810ULL;
x86_l_2933:
	/* 0x2933: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2936:
	/* 0x2936: ja     2e0e <generic_fexit_filter_arg+0x2e0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11790ULL;
	}
x86_l_293c:
	/* 0x293c: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2942:
	/* 0x2942: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2946:
	/* 0x2946: jae    2e0e <generic_fexit_filter_arg+0x2e0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11790ULL;
	}
x86_l_294c:
	/* 0x294c: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294f:
	/* 0x294f: jg     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 639ULL;
	}
x86_l_2955:
	/* 0x2955: jmp    2e22 <generic_fexit_filter_arg+0x2e22> */
	return 11810ULL;
x86_l_295a:
	/* 0x295a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_295d:
	/* 0x295d: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2960:
	/* 0x2960: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2963:
	/* 0x2963: jmp    2b6b <generic_fexit_filter_arg+0x2b6b> */
	goto x86_l_2b6b;
x86_l_2968:
	/* 0x2968: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_296b:
	/* 0x296b: je     2c9f <generic_fexit_filter_arg+0x2c9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11423ULL;
	}
x86_l_2971:
	/* 0x2971: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2974:
	/* 0x2974: jne    2d1b <generic_fexit_filter_arg+0x2d1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11547ULL;
	}
x86_l_297a:
	/* 0x297a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_297f:
	/* 0x297f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2984:
	/* 0x2984: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_298b:
	/* 0x298b: jmp    2cc3 <generic_fexit_filter_arg+0x2cc3> */
	return 11459ULL;
x86_l_2990:
	/* 0x2990: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2993:
	/* 0x2993: je     2cb2 <generic_fexit_filter_arg+0x2cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11442ULL;
	}
x86_l_2999:
	/* 0x2999: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_299c:
	/* 0x299c: jne    2d1b <generic_fexit_filter_arg+0x2d1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11547ULL;
	}
x86_l_29a2:
	/* 0x29a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29a7:
	/* 0x29a7: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29ac:
	/* 0x29ac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_29b3:
	/* 0x29b3: jmp    2cc3 <generic_fexit_filter_arg+0x2cc3> */
	return 11459ULL;
x86_l_29b8:
	/* 0x29b8: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_29bb:
	/* 0x29bb: ja     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 184ULL;
	}
x86_l_29c1:
	/* 0x29c1: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_29c4:
	/* 0x29c4: jbe    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 639ULL;
	}
x86_l_29ca:
	/* 0x29ca: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	return 184ULL;
x86_l_29cf:
	/* 0x29cf: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29d2:
	/* 0x29d2: je     2d77 <generic_fexit_filter_arg+0x2d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11639ULL;
	}
x86_l_29d8:
	/* 0x29d8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29db:
	/* 0x29db: jne    2d83 <generic_fexit_filter_arg+0x2d83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11651ULL;
	}
x86_l_29e1:
	/* 0x29e1: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_29e5:
	/* 0x29e5: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_29e7:
	/* 0x29e7: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_29ed:
	/* 0x29ed: jmp    2d83 <generic_fexit_filter_arg+0x2d83> */
	return 11651ULL;
x86_l_29f2:
	/* 0x29f2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29f5:
	/* 0x29f5: je     2dbd <generic_fexit_filter_arg+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11709ULL;
	}
x86_l_29fb:
	/* 0x29fb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29fe:
	/* 0x29fe: jne    2dc9 <generic_fexit_filter_arg+0x2dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11721ULL;
	}
x86_l_2a04:
	/* 0x2a04: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a08:
	/* 0x2a08: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2a0a:
	/* 0x2a0a: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_2a10:
	/* 0x2a10: jmp    2dc9 <generic_fexit_filter_arg+0x2dc9> */
	return 11721ULL;
x86_l_2a15:
	/* 0x2a15: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2a1a:
	/* 0x2a1a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a1f:
	/* 0x2a1f: jmp    2f7d <generic_fexit_filter_arg+0x2f7d> */
	return 12157ULL;
x86_l_2a24:
	/* 0x2a24: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2a27:
	/* 0x2a27: mov    WORD PTR [rcx],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a2a:
	/* 0x2a2a: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2a2e:
	/* 0x2a2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a33:
	/* 0x2a33: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a38:
	/* 0x2a38: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2a3a:
	/* 0x2a3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3c:
	/* 0x2a3c: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_2a3e:
	/* 0x2a3e: jbe    2a61 <generic_fexit_filter_arg+0x2a61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2a61;
	}
x86_l_2a40:
	/* 0x2a40: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2a44:
	/* 0x2a44: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2a48:
	/* 0x2a48: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a4a:
	/* 0x2a4a: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a50:
	/* 0x2a50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a55:
	/* 0x2a55: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2a5d:
	/* 0x2a5d: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2a5f:
	/* 0x2a5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a61:
	/* 0x2a61: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2a65:
	/* 0x2a65: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a69:
	/* 0x2a69: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a6d:
	/* 0x2a6d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2a70:
	/* 0x2a70: jg     2aa2 <generic_fexit_filter_arg+0x2aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2aa2;
	}
x86_l_2a72:
	/* 0x2a72: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a75:
	/* 0x2a75: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a7a:
	/* 0x2a7a: jg     2d31 <generic_fexit_filter_arg+0x2d31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11569ULL;
	}
x86_l_2a80:
	/* 0x2a80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a82:
	/* 0x2a82: je     2f18 <generic_fexit_filter_arg+0x2f18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12056ULL;
	}
x86_l_2a88:
	/* 0x2a88: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a8b:
	/* 0x2a8b: jne    2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12140ULL;
	}
x86_l_2a91:
	/* 0x2a91: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a96:
	/* 0x2a96: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2a9d:
	/* 0x2a9d: jmp    2f4e <generic_fexit_filter_arg+0x2f4e> */
	return 12110ULL;
x86_l_2aa2:
	/* 0x2aa2: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2aa5:
	/* 0x2aa5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2aaa:
	/* 0x2aaa: jg     2d54 <generic_fexit_filter_arg+0x2d54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11604ULL;
	}
x86_l_2ab0:
	/* 0x2ab0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ab3:
	/* 0x2ab3: je     2f26 <generic_fexit_filter_arg+0x2f26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12070ULL;
	}
x86_l_2ab9:
	/* 0x2ab9: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2abc:
	/* 0x2abc: jne    2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12140ULL;
	}
x86_l_2ac2:
	/* 0x2ac2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2ace:
	/* 0x2ace: jmp    2f4e <generic_fexit_filter_arg+0x2f4e> */
	return 12110ULL;
x86_l_2ad3:
	/* 0x2ad3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ad8:
	/* 0x2ad8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2adf:
	/* 0x2adf: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ae4:
	/* 0x2ae4: jmp    2b1d <generic_fexit_filter_arg+0x2b1d> */
	goto x86_l_2b1d;
x86_l_2ae6:
	/* 0x2ae6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aeb:
	/* 0x2aeb: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2af0:
	/* 0x2af0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2af7:
	/* 0x2af7: jmp    2b1d <generic_fexit_filter_arg+0x2b1d> */
	goto x86_l_2b1d;
x86_l_2af9:
	/* 0x2af9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2afe:
	/* 0x2afe: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b03:
	/* 0x2b03: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2b0a:
	/* 0x2b0a: jmp    2b1d <generic_fexit_filter_arg+0x2b1d> */
	goto x86_l_2b1d;
x86_l_2b0c:
	/* 0x2b0c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b11:
	/* 0x2b11: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b16:
	/* 0x2b16: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2b1d:
	/* 0x2b1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1f:
	/* 0x2b1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b22:
	/* 0x2b22: je     2b3b <generic_fexit_filter_arg+0x2b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b3b;
	}
x86_l_2b24:
	/* 0x2b24: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2b27:
	/* 0x2b27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b2c:
	/* 0x2b2c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2b2f:
	/* 0x2b2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b31:
	/* 0x2b31: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b33:
	/* 0x2b33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b36:
	/* 0x2b36: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2b39:
	/* 0x2b39: jmp    2b3d <generic_fexit_filter_arg+0x2b3d> */
	goto x86_l_2b3d;
x86_l_2b3b:
	/* 0x2b3b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b3d:
	/* 0x2b3d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b42:
	/* 0x2b42: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b47:
	/* 0x2b47: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b4c:
	/* 0x2b4c: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b51:
	/* 0x2b51: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b55:
	/* 0x2b55: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2b59:
	/* 0x2b59: jbe    c91 <generic_fexit_filter_arg+0xc91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3217ULL;
	}
x86_l_2b5f:
	/* 0x2b5f: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_2b64:
	/* 0x2b64: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2b66:
	/* 0x2b66: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2b69:
	/* 0x2b69: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2b6b:
	/* 0x2b6b: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_2b6e:
	/* 0x2b6e: and    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2b70:
	/* 0x2b70: or     al,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2b72:
	/* 0x2b72: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b77:
	/* 0x2b77: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2b79:
	/* 0x2b79: je     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 639ULL;
	}
x86_l_2b7f:
	/* 0x2b7f: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	return 184ULL;
x86_l_2b84:
	/* 0x2b84: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b88:
	/* 0x2b88: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_2b8e:
	/* 0x2b8e: jmp    2b9a <generic_fexit_filter_arg+0x2b9a> */
	goto x86_l_2b9a;
x86_l_2b90:
	/* 0x2b90: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b94:
	/* 0x2b94: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_2b9a:
	/* 0x2b9a: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2b9d:
	/* 0x2b9d: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12276ULL;
	}
x86_l_2ba3:
	/* 0x2ba3: mov    rdx,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ba7:
	/* 0x2ba7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2baa:
	/* 0x2baa: jle    2bd5 <generic_fexit_filter_arg+0x2bd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2bd5;
	}
x86_l_2bac:
	/* 0x2bac: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2baf:
	/* 0x2baf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2bb2:
	/* 0x2bb2: jb     2c04 <generic_fexit_filter_arg+0x2c04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2c04;
	}
x86_l_2bb4:
	/* 0x2bb4: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2bb7:
	/* 0x2bb7: je     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 639ULL;
	}
x86_l_2bbd:
	/* 0x2bbd: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2bc0:
	/* 0x2bc0: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_2bc6:
	/* 0x2bc6: test   QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bca:
	/* 0x2bca: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_2bd0:
	/* 0x2bd0: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	return 12276ULL;
x86_l_2bd5:
	/* 0x2bd5: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bd8:
	/* 0x2bd8: je     2c5c <generic_fexit_filter_arg+0x2c5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11356ULL;
	}
x86_l_2bde:
	/* 0x2bde: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2be1:
	/* 0x2be1: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_2be7:
	/* 0x2be7: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2bea:
	/* 0x2bea: je     2bf5 <generic_fexit_filter_arg+0x2bf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bf5;
	}
x86_l_2bec:
	/* 0x2bec: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2bef:
	/* 0x2bef: jne    2fb4 <generic_fexit_filter_arg+0x2fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12212ULL;
	}
x86_l_2bf5:
	/* 0x2bf5: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf9:
	/* 0x2bf9: jl     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 639ULL;
	}
x86_l_2bff:
	/* 0x2bff: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	return 12276ULL;
x86_l_2c04:
	/* 0x2c04: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c08:
	/* 0x2c08: je     2f0b <generic_fexit_filter_arg+0x2f0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12043ULL;
	}
x86_l_2c0e:
	/* 0x2c0e: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	return 12276ULL;
x86_l_2c13:
	/* 0x2c13: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2c16:
	/* 0x2c16: jne    2d83 <generic_fexit_filter_arg+0x2d83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11651ULL;
	}
x86_l_2c1c:
	/* 0x2c1c: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2c20:
	/* 0x2c20: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2c22:
	/* 0x2c22: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_2c28:
	/* 0x2c28: jmp    2d83 <generic_fexit_filter_arg+0x2d83> */
	return 11651ULL;
	return 11309ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11309ULL: goto x86_l_2c2d;
	case 11312ULL: goto x86_l_2c30;
	case 11318ULL: goto x86_l_2c36;
	case 11322ULL: goto x86_l_2c3a;
	case 11324ULL: goto x86_l_2c3c;
	case 11330ULL: goto x86_l_2c42;
	case 11335ULL: goto x86_l_2c47;
	case 11337ULL: goto x86_l_2c49;
	case 11343ULL: goto x86_l_2c4f;
	case 11345ULL: goto x86_l_2c51;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11359ULL: goto x86_l_2c5f;
	case 11361ULL: goto x86_l_2c61;
	case 11364ULL: goto x86_l_2c64;
	case 11370ULL: goto x86_l_2c6a;
	case 11374ULL: goto x86_l_2c6e;
	case 11380ULL: goto x86_l_2c74;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11404ULL: goto x86_l_2c8c;
	case 11409ULL: goto x86_l_2c91;
	case 11414ULL: goto x86_l_2c96;
	case 11421ULL: goto x86_l_2c9d;
	case 11423ULL: goto x86_l_2c9f;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11440ULL: goto x86_l_2cb0;
	case 11442ULL: goto x86_l_2cb2;
	case 11447ULL: goto x86_l_2cb7;
	case 11452ULL: goto x86_l_2cbc;
	case 11459ULL: goto x86_l_2cc3;
	case 11461ULL: goto x86_l_2cc5;
	case 11464ULL: goto x86_l_2cc8;
	case 11466ULL: goto x86_l_2cca;
	case 11469ULL: goto x86_l_2ccd;
	case 11474ULL: goto x86_l_2cd2;
	case 11479ULL: goto x86_l_2cd7;
	case 11481ULL: goto x86_l_2cd9;
	case 11483ULL: goto x86_l_2cdb;
	case 11486ULL: goto x86_l_2cde;
	case 11489ULL: goto x86_l_2ce1;
	case 11491ULL: goto x86_l_2ce3;
	case 11493ULL: goto x86_l_2ce5;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11508ULL: goto x86_l_2cf4;
	case 11512ULL: goto x86_l_2cf8;
	case 11516ULL: goto x86_l_2cfc;
	case 11522ULL: goto x86_l_2d02;
	case 11532ULL: goto x86_l_2d0c;
	case 11536ULL: goto x86_l_2d10;
	case 11542ULL: goto x86_l_2d16;
	case 11547ULL: goto x86_l_2d1b;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11558ULL: goto x86_l_2d26;
	case 11562ULL: goto x86_l_2d2a;
	case 11564ULL: goto x86_l_2d2c;
	case 11569ULL: goto x86_l_2d31;
	case 11572ULL: goto x86_l_2d34;
	case 11578ULL: goto x86_l_2d3a;
	case 11581ULL: goto x86_l_2d3d;
	case 11587ULL: goto x86_l_2d43;
	case 11592ULL: goto x86_l_2d48;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11607ULL: goto x86_l_2d57;
	case 11613ULL: goto x86_l_2d5d;
	case 11616ULL: goto x86_l_2d60;
	case 11622ULL: goto x86_l_2d66;
	case 11627ULL: goto x86_l_2d6b;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11643ULL: goto x86_l_2d7b;
	case 11645ULL: goto x86_l_2d7d;
	case 11651ULL: goto x86_l_2d83;
	case 11654ULL: goto x86_l_2d86;
	case 11660ULL: goto x86_l_2d8c;
	case 11664ULL: goto x86_l_2d90;
	case 11667ULL: goto x86_l_2d93;
	case 11673ULL: goto x86_l_2d99;
	case 11676ULL: goto x86_l_2d9c;
	case 11679ULL: goto x86_l_2d9f;
	case 11685ULL: goto x86_l_2da5;
	case 11688ULL: goto x86_l_2da8;
	case 11694ULL: goto x86_l_2dae;
	case 11697ULL: goto x86_l_2db1;
	case 11703ULL: goto x86_l_2db7;
	case 11707ULL: goto x86_l_2dbb;
	case 11709ULL: goto x86_l_2dbd;
	case 11713ULL: goto x86_l_2dc1;
	case 11715ULL: goto x86_l_2dc3;
	case 11721ULL: goto x86_l_2dc9;
	case 11724ULL: goto x86_l_2dcc;
	case 11730ULL: goto x86_l_2dd2;
	case 11734ULL: goto x86_l_2dd6;
	case 11737ULL: goto x86_l_2dd9;
	case 11743ULL: goto x86_l_2ddf;
	case 11746ULL: goto x86_l_2de2;
	case 11749ULL: goto x86_l_2de5;
	case 11755ULL: goto x86_l_2deb;
	case 11758ULL: goto x86_l_2dee;
	case 11764ULL: goto x86_l_2df4;
	case 11767ULL: goto x86_l_2df7;
	case 11773ULL: goto x86_l_2dfd;
	case 11777ULL: goto x86_l_2e01;
	case 11779ULL: goto x86_l_2e03;
	case 11785ULL: goto x86_l_2e09;
	case 11790ULL: goto x86_l_2e0e;
	case 11793ULL: goto x86_l_2e11;
	case 11799ULL: goto x86_l_2e17;
	case 11801ULL: goto x86_l_2e19;
	case 11804ULL: goto x86_l_2e1c;
	case 11810ULL: goto x86_l_2e22;
	case 11813ULL: goto x86_l_2e25;
	case 11819ULL: goto x86_l_2e2b;
	case 11823ULL: goto x86_l_2e2f;
	case 11826ULL: goto x86_l_2e32;
	case 11828ULL: goto x86_l_2e34;
	case 11831ULL: goto x86_l_2e37;
	case 11834ULL: goto x86_l_2e3a;
	case 11836ULL: goto x86_l_2e3c;
	case 11839ULL: goto x86_l_2e3f;
	case 11845ULL: goto x86_l_2e45;
	case 11848ULL: goto x86_l_2e48;
	case 11854ULL: goto x86_l_2e4e;
	case 11857ULL: goto x86_l_2e51;
	case 11863ULL: goto x86_l_2e57;
	case 11868ULL: goto x86_l_2e5c;
	case 11871ULL: goto x86_l_2e5f;
	case 11873ULL: goto x86_l_2e61;
	case 11876ULL: goto x86_l_2e64;
	case 11882ULL: goto x86_l_2e6a;
	case 11885ULL: goto x86_l_2e6d;
	case 11891ULL: goto x86_l_2e73;
	case 11896ULL: goto x86_l_2e78;
	case 11899ULL: goto x86_l_2e7b;
	case 11905ULL: goto x86_l_2e81;
	case 11908ULL: goto x86_l_2e84;
	case 11914ULL: goto x86_l_2e8a;
	case 11919ULL: goto x86_l_2e8f;
	case 11922ULL: goto x86_l_2e92;
	case 11924ULL: goto x86_l_2e94;
	case 11929ULL: goto x86_l_2e99;
	case 11932ULL: goto x86_l_2e9c;
	case 11938ULL: goto x86_l_2ea2;
	case 11943ULL: goto x86_l_2ea7;
	case 11946ULL: goto x86_l_2eaa;
	case 11952ULL: goto x86_l_2eb0;
	case 11955ULL: goto x86_l_2eb3;
	case 11961ULL: goto x86_l_2eb9;
	case 11966ULL: goto x86_l_2ebe;
	case 11969ULL: goto x86_l_2ec1;
	case 11975ULL: goto x86_l_2ec7;
	case 11978ULL: goto x86_l_2eca;
	case 11984ULL: goto x86_l_2ed0;
	case 11988ULL: goto x86_l_2ed4;
	case 11990ULL: goto x86_l_2ed6;
	case 11993ULL: goto x86_l_2ed9;
	case 11999ULL: goto x86_l_2edf;
	case 12002ULL: goto x86_l_2ee2;
	case 12008ULL: goto x86_l_2ee8;
	case 12012ULL: goto x86_l_2eec;
	case 12014ULL: goto x86_l_2eee;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12029ULL: goto x86_l_2efd;
	case 12031ULL: goto x86_l_2eff;
	case 12035ULL: goto x86_l_2f03;
	case 12037ULL: goto x86_l_2f05;
	case 12043ULL: goto x86_l_2f0b;
	case 12045ULL: goto x86_l_2f0d;
	case 12048ULL: goto x86_l_2f10;
	case 12051ULL: goto x86_l_2f13;
	case 12056ULL: goto x86_l_2f18;
	case 12061ULL: goto x86_l_2f1d;
	case 12068ULL: goto x86_l_2f24;
	case 12070ULL: goto x86_l_2f26;
	case 12075ULL: goto x86_l_2f2b;
	case 12082ULL: goto x86_l_2f32;
	case 12084ULL: goto x86_l_2f34;
	case 12089ULL: goto x86_l_2f39;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12110ULL: goto x86_l_2f4e;
	case 12112ULL: goto x86_l_2f50;
	case 12115ULL: goto x86_l_2f53;
	case 12117ULL: goto x86_l_2f55;
	case 12120ULL: goto x86_l_2f58;
	case 12125ULL: goto x86_l_2f5d;
	case 12128ULL: goto x86_l_2f60;
	case 12130ULL: goto x86_l_2f62;
	case 12132ULL: goto x86_l_2f64;
	case 12135ULL: goto x86_l_2f67;
	case 12138ULL: goto x86_l_2f6a;
	case 12140ULL: goto x86_l_2f6c;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12161ULL: goto x86_l_2f81;
	case 12165ULL: goto x86_l_2f85;
	case 12171ULL: goto x86_l_2f8b;
	case 12181ULL: goto x86_l_2f95;
	case 12185ULL: goto x86_l_2f99;
	case 12190ULL: goto x86_l_2f9e;
	case 12196ULL: goto x86_l_2fa4;
	case 12198ULL: goto x86_l_2fa6;
	case 12201ULL: goto x86_l_2fa9;
	case 12204ULL: goto x86_l_2fac;
	case 12207ULL: goto x86_l_2faf;
	case 12212ULL: goto x86_l_2fb4;
	case 12216ULL: goto x86_l_2fb8;
	case 12222ULL: goto x86_l_2fbe;
	case 12224ULL: goto x86_l_2fc0;
	case 12228ULL: goto x86_l_2fc4;
	case 12234ULL: goto x86_l_2fca;
	case 12236ULL: goto x86_l_2fcc;
	case 12240ULL: goto x86_l_2fd0;
	case 12242ULL: goto x86_l_2fd2;
	case 12246ULL: goto x86_l_2fd6;
	case 12248ULL: goto x86_l_2fd8;
	case 12254ULL: goto x86_l_2fde;
	case 12256ULL: goto x86_l_2fe0;
	case 12259ULL: goto x86_l_2fe3;
	case 12265ULL: goto x86_l_2fe9;
	case 12267ULL: goto x86_l_2feb;
	case 12270ULL: goto x86_l_2fee;
	case 12276ULL: goto x86_l_2ff4;
	case 12279ULL: goto x86_l_2ff7;
	case 12282ULL: goto x86_l_2ffa;
	case 12288ULL: goto x86_l_3000;
	case 12293ULL: goto x86_l_3005;
	case 12298ULL: goto x86_l_300a;
	case 12301ULL: goto x86_l_300d;
	case 12303ULL: goto x86_l_300f;
	case 12304ULL: goto x86_l_3010;
	case 12306ULL: goto x86_l_3012;
	case 12308ULL: goto x86_l_3014;
	case 12311ULL: goto x86_l_3017;
	case 12314ULL: goto x86_l_301a;
	case 12317ULL: goto x86_l_301d;
	case 12319ULL: goto x86_l_301f;
	case 12322ULL: goto x86_l_3022;
	case 12326ULL: goto x86_l_3026;
	case 12329ULL: goto x86_l_3029;
	case 12331ULL: goto x86_l_302b;
	case 12336ULL: goto x86_l_3030;
	case 12339ULL: goto x86_l_3033;
	case 12341ULL: goto x86_l_3035;
	case 12346ULL: goto x86_l_303a;
	case 12350ULL: goto x86_l_303e;
	case 12353ULL: goto x86_l_3041;
	case 12356ULL: goto x86_l_3044;
	case 12360ULL: goto x86_l_3048;
	case 12364ULL: goto x86_l_304c;
	case 12368ULL: goto x86_l_3050;
	case 12371ULL: goto x86_l_3053;
	case 12375ULL: goto x86_l_3057;
	case 12379ULL: goto x86_l_305b;
	case 12383ULL: goto x86_l_305f;
	case 12386ULL: goto x86_l_3062;
	case 12388ULL: goto x86_l_3064;
	case 12392ULL: goto x86_l_3068;
	case 12396ULL: goto x86_l_306c;
	case 12399ULL: goto x86_l_306f;
	case 12401ULL: goto x86_l_3071;
	case 12403ULL: goto x86_l_3073;
	case 12405ULL: goto x86_l_3075;
	case 12406ULL: goto x86_l_3076;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2c2d:
	/* 0x2c2d: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2c30:
	/* 0x2c30: jne    2dc9 <generic_fexit_filter_arg+0x2dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2dc9;
	}
x86_l_2c36:
	/* 0x2c36: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c3a:
	/* 0x2c3a: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2c3c:
	/* 0x2c3c: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_2c42:
	/* 0x2c42: jmp    2dc9 <generic_fexit_filter_arg+0x2dc9> */
	goto x86_l_2dc9;
x86_l_2c47:
	/* 0x2c47: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2c49:
	/* 0x2c49: ja     b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 184ULL;
	}
x86_l_2c4f:
	/* 0x2c4f: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2c51:
	/* 0x2c51: jbe    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 639ULL;
	}
x86_l_2c57:
	/* 0x2c57: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	return 184ULL;
x86_l_2c5c:
	/* 0x2c5c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2c5f:
	/* 0x2c5f: je     2c6a <generic_fexit_filter_arg+0x2c6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c6a;
	}
x86_l_2c61:
	/* 0x2c61: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2c64:
	/* 0x2c64: jne    2fc0 <generic_fexit_filter_arg+0x2fc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fc0;
	}
x86_l_2c6a:
	/* 0x2c6a: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c6e:
	/* 0x2c6e: jg     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 639ULL;
	}
x86_l_2c74:
	/* 0x2c74: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2c79:
	/* 0x2c79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c7e:
	/* 0x2c7e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2c85:
	/* 0x2c85: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c8a:
	/* 0x2c8a: jmp    2cc3 <generic_fexit_filter_arg+0x2cc3> */
	goto x86_l_2cc3;
x86_l_2c8c:
	/* 0x2c8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c91:
	/* 0x2c91: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c96:
	/* 0x2c96: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2c9d:
	/* 0x2c9d: jmp    2cc3 <generic_fexit_filter_arg+0x2cc3> */
	goto x86_l_2cc3;
x86_l_2c9f:
	/* 0x2c9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ca4:
	/* 0x2ca4: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2cb0:
	/* 0x2cb0: jmp    2cc3 <generic_fexit_filter_arg+0x2cc3> */
	goto x86_l_2cc3;
x86_l_2cb2:
	/* 0x2cb2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cb7:
	/* 0x2cb7: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cbc:
	/* 0x2cbc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2cc3:
	/* 0x2cc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc5:
	/* 0x2cc5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cc8:
	/* 0x2cc8: je     2ce3 <generic_fexit_filter_arg+0x2ce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce3;
	}
x86_l_2cca:
	/* 0x2cca: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2ccd:
	/* 0x2ccd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cd2:
	/* 0x2cd2: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cd7:
	/* 0x2cd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd9:
	/* 0x2cd9: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cdb:
	/* 0x2cdb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cde:
	/* 0x2cde: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2ce1:
	/* 0x2ce1: jmp    2ce5 <generic_fexit_filter_arg+0x2ce5> */
	goto x86_l_2ce5;
x86_l_2ce3:
	/* 0x2ce3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ce5:
	/* 0x2ce5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cea:
	/* 0x2cea: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cef:
	/* 0x2cef: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cf4:
	/* 0x2cf4: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cf8:
	/* 0x2cf8: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2cfc:
	/* 0x2cfc: ja     26e <generic_fexit_filter_arg+0x26e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 622ULL;
	}
x86_l_2d02:
	/* 0x2d02: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_2d0c:
	/* 0x2d0c: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2d10:
	/* 0x2d10: jb     2fa4 <generic_fexit_filter_arg+0x2fa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2fa4;
	}
x86_l_2d16:
	/* 0x2d16: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_2d1b:
	/* 0x2d1b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d1d:
	/* 0x2d1d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d22:
	/* 0x2d22: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d26:
	/* 0x2d26: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2d2a:
	/* 0x2d2a: jbe    2d02 <generic_fexit_filter_arg+0x2d02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2d02;
	}
x86_l_2d2c:
	/* 0x2d2c: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_2d31:
	/* 0x2d31: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d34:
	/* 0x2d34: je     2f34 <generic_fexit_filter_arg+0x2f34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f34;
	}
x86_l_2d3a:
	/* 0x2d3a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2d3d:
	/* 0x2d3d: jne    2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f6c;
	}
x86_l_2d43:
	/* 0x2d43: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d48:
	/* 0x2d48: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2d4f:
	/* 0x2d4f: jmp    2f4e <generic_fexit_filter_arg+0x2f4e> */
	goto x86_l_2f4e;
x86_l_2d54:
	/* 0x2d54: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2d57:
	/* 0x2d57: je     2f42 <generic_fexit_filter_arg+0x2f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f42;
	}
x86_l_2d5d:
	/* 0x2d5d: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2d60:
	/* 0x2d60: jne    2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f6c;
	}
x86_l_2d66:
	/* 0x2d66: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d6b:
	/* 0x2d6b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2d72:
	/* 0x2d72: jmp    2f4e <generic_fexit_filter_arg+0x2f4e> */
	goto x86_l_2f4e;
x86_l_2d77:
	/* 0x2d77: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2d7b:
	/* 0x2d7b: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2d7d:
	/* 0x2d7d: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_2d83:
	/* 0x2d83: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_2d86:
	/* 0x2d86: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ff4;
	}
x86_l_2d8c:
	/* 0x2d8c: mov    ecx,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d90:
	/* 0x2d90: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d93:
	/* 0x2d93: jle    2ebe <generic_fexit_filter_arg+0x2ebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2ebe;
	}
x86_l_2d99:
	/* 0x2d99: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2d9c:
	/* 0x2d9c: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2d9f:
	/* 0x2d9f: jb     2ef9 <generic_fexit_filter_arg+0x2ef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ef9;
	}
x86_l_2da5:
	/* 0x2da5: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2da8:
	/* 0x2da8: je     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 639ULL;
	}
x86_l_2dae:
	/* 0x2dae: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2db1:
	/* 0x2db1: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_2db7:
	/* 0x2db7: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2dbb:
	/* 0x2dbb: jmp    2e01 <generic_fexit_filter_arg+0x2e01> */
	goto x86_l_2e01;
x86_l_2dbd:
	/* 0x2dbd: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2dc1:
	/* 0x2dc1: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2dc3:
	/* 0x2dc3: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_2dc9:
	/* 0x2dc9: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_2dcc:
	/* 0x2dcc: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ff4;
	}
x86_l_2dd2:
	/* 0x2dd2: mov    ecx,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2dd6:
	/* 0x2dd6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dd9:
	/* 0x2dd9: jle    2ed6 <generic_fexit_filter_arg+0x2ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2ed6;
	}
x86_l_2ddf:
	/* 0x2ddf: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2de2:
	/* 0x2de2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2de5:
	/* 0x2de5: jb     2eff <generic_fexit_filter_arg+0x2eff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2eff;
	}
x86_l_2deb:
	/* 0x2deb: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2dee:
	/* 0x2dee: je     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 639ULL;
	}
x86_l_2df4:
	/* 0x2df4: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2df7:
	/* 0x2df7: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_2dfd:
	/* 0x2dfd: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e01:
	/* 0x2e01: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2e03:
	/* 0x2e03: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_2e09:
	/* 0x2e09: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2e0e:
	/* 0x2e0e: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e11:
	/* 0x2e11: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_2e17:
	/* 0x2e17: jmp    2e22 <generic_fexit_filter_arg+0x2e22> */
	goto x86_l_2e22;
x86_l_2e19:
	/* 0x2e19: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e1c:
	/* 0x2e1c: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_2e22:
	/* 0x2e22: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2e25:
	/* 0x2e25: jb     2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ff4;
	}
x86_l_2e2b:
	/* 0x2e2b: mov    edx,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2e2f:
	/* 0x2e2f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e32:
	/* 0x2e32: jle    2e5c <generic_fexit_filter_arg+0x2e5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e5c;
	}
x86_l_2e34:
	/* 0x2e34: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2e37:
	/* 0x2e37: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2e3a:
	/* 0x2e3a: jb     2e8f <generic_fexit_filter_arg+0x2e8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e8f;
	}
x86_l_2e3c:
	/* 0x2e3c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2e3f:
	/* 0x2e3f: je     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 639ULL;
	}
x86_l_2e45:
	/* 0x2e45: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e48:
	/* 0x2e48: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_2e4e:
	/* 0x2e4e: test   DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e51:
	/* 0x2e51: jne    27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 639ULL;
	}
x86_l_2e57:
	/* 0x2e57: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2e5c:
	/* 0x2e5c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e5f:
	/* 0x2e5f: je     2e99 <generic_fexit_filter_arg+0x2e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e99;
	}
x86_l_2e61:
	/* 0x2e61: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e64:
	/* 0x2e64: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_2e6a:
	/* 0x2e6a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2e6d:
	/* 0x2e6d: ja     2fe0 <generic_fexit_filter_arg+0x2fe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fe0;
	}
x86_l_2e73:
	/* 0x2e73: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_2e78:
	/* 0x2e78: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2e7b:
	/* 0x2e7b: jae    2fe0 <generic_fexit_filter_arg+0x2fe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fe0;
	}
x86_l_2e81:
	/* 0x2e81: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e84:
	/* 0x2e84: jl     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 639ULL;
	}
x86_l_2e8a:
	/* 0x2e8a: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2e8f:
	/* 0x2e8f: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e92:
	/* 0x2e92: je     2f0b <generic_fexit_filter_arg+0x2f0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f0b;
	}
x86_l_2e94:
	/* 0x2e94: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2e99:
	/* 0x2e99: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2e9c:
	/* 0x2e9c: ja     2feb <generic_fexit_filter_arg+0x2feb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2feb;
	}
x86_l_2ea2:
	/* 0x2ea2: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_2ea7:
	/* 0x2ea7: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2eaa:
	/* 0x2eaa: jae    2feb <generic_fexit_filter_arg+0x2feb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2feb;
	}
x86_l_2eb0:
	/* 0x2eb0: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eb3:
	/* 0x2eb3: jg     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 639ULL;
	}
x86_l_2eb9:
	/* 0x2eb9: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2ebe:
	/* 0x2ebe: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ec1:
	/* 0x2ec1: je     2fcc <generic_fexit_filter_arg+0x2fcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fcc;
	}
x86_l_2ec7:
	/* 0x2ec7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2eca:
	/* 0x2eca: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_2ed0:
	/* 0x2ed0: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2ed4:
	/* 0x2ed4: jmp    2eec <generic_fexit_filter_arg+0x2eec> */
	goto x86_l_2eec;
x86_l_2ed6:
	/* 0x2ed6: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ed9:
	/* 0x2ed9: je     2fd2 <generic_fexit_filter_arg+0x2fd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd2;
	}
x86_l_2edf:
	/* 0x2edf: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ee2:
	/* 0x2ee2: jne    b8 <generic_fexit_filter_arg+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 184ULL;
	}
x86_l_2ee8:
	/* 0x2ee8: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2eec:
	/* 0x2eec: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2eee:
	/* 0x2eee: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_2ef4:
	/* 0x2ef4: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2ef9:
	/* 0x2ef9: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2efd:
	/* 0x2efd: jmp    2f03 <generic_fexit_filter_arg+0x2f03> */
	goto x86_l_2f03;
x86_l_2eff:
	/* 0x2eff: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f03:
	/* 0x2f03: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2f05:
	/* 0x2f05: jne    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ff4;
	}
x86_l_2f0b:
	/* 0x2f0b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f0d:
	/* 0x2f0d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2f10:
	/* 0x2f10: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_2f13:
	/* 0x2f13: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_2f18:
	/* 0x2f18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f1d:
	/* 0x2f1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2f24:
	/* 0x2f24: jmp    2f4e <generic_fexit_filter_arg+0x2f4e> */
	goto x86_l_2f4e;
x86_l_2f26:
	/* 0x2f26: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f2b:
	/* 0x2f2b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2f32:
	/* 0x2f32: jmp    2f4e <generic_fexit_filter_arg+0x2f4e> */
	goto x86_l_2f4e;
x86_l_2f34:
	/* 0x2f34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f39:
	/* 0x2f39: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2f40:
	/* 0x2f40: jmp    2f4e <generic_fexit_filter_arg+0x2f4e> */
	goto x86_l_2f4e;
x86_l_2f42:
	/* 0x2f42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f47:
	/* 0x2f47: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2f4e:
	/* 0x2f4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f50:
	/* 0x2f50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f53:
	/* 0x2f53: je     2f6c <generic_fexit_filter_arg+0x2f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f6c;
	}
x86_l_2f55:
	/* 0x2f55: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2f58:
	/* 0x2f58: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f5d:
	/* 0x2f5d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2f60:
	/* 0x2f60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f62:
	/* 0x2f62: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f64:
	/* 0x2f64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f67:
	/* 0x2f67: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2f6a:
	/* 0x2f6a: jmp    2f6e <generic_fexit_filter_arg+0x2f6e> */
	goto x86_l_2f6e;
x86_l_2f6c:
	/* 0x2f6c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f6e:
	/* 0x2f6e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f73:
	/* 0x2f73: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f78:
	/* 0x2f78: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f7d:
	/* 0x2f7d: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f81:
	/* 0x2f81: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2f85:
	/* 0x2f85: ja     269 <generic_fexit_filter_arg+0x269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 617ULL;
	}
x86_l_2f8b:
	/* 0x2f8b: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_2f95:
	/* 0x2f95: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2f99:
	/* 0x2f99: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2f9e:
	/* 0x2f9e: jae    26e <generic_fexit_filter_arg+0x26e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 622ULL;
	}
x86_l_2fa4:
	/* 0x2fa4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fa6:
	/* 0x2fa6: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2fa9:
	/* 0x2fa9: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2fac:
	/* 0x2fac: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2faf:
	/* 0x2faf: jmp    26e <generic_fexit_filter_arg+0x26e> */
	return 622ULL;
x86_l_2fb4:
	/* 0x2fb4: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb8:
	/* 0x2fb8: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_2fbe:
	/* 0x2fbe: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2fc0:
	/* 0x2fc0: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc4:
	/* 0x2fc4: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_2fca:
	/* 0x2fca: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2fcc:
	/* 0x2fcc: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2fd0:
	/* 0x2fd0: jmp    2fd6 <generic_fexit_filter_arg+0x2fd6> */
	goto x86_l_2fd6;
x86_l_2fd2:
	/* 0x2fd2: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fd6:
	/* 0x2fd6: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2fd8:
	/* 0x2fd8: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_2fde:
	/* 0x2fde: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2fe0:
	/* 0x2fe0: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe3:
	/* 0x2fe3: jb     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 639ULL;
	}
x86_l_2fe9:
	/* 0x2fe9: jmp    2ff4 <generic_fexit_filter_arg+0x2ff4> */
	goto x86_l_2ff4;
x86_l_2feb:
	/* 0x2feb: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fee:
	/* 0x2fee: ja     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 639ULL;
	}
x86_l_2ff4:
	/* 0x2ff4: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_2ff7:
	/* 0x2ff7: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2ffa:
	/* 0x2ffa: je     27f <generic_fexit_filter_arg+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 639ULL;
	}
x86_l_3000:
	/* 0x3000: jmp    b8 <generic_fexit_filter_arg+0xb8> */
	return 184ULL;
x86_l_3005:
	/* 0x3005: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_300a:
	/* 0x300a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_300d:
	/* 0x300d: je     3076 <native_bpf_strncasestr+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3076;
	}
x86_l_300f:
	/* 0x300f: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3010:
	/* 0x3010: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3012:
	/* 0x3012: jmp    301f <native_bpf_strncasestr+0x1a> */
	goto x86_l_301f;
x86_l_3014:
	/* 0x3014: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3017:
	/* 0x3017: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_301a:
	/* 0x301a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_301d:
	/* 0x301d: je     3075 <native_bpf_strncasestr+0x70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3075;
	}
x86_l_301f:
	/* 0x301f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3022:
	/* 0x3022: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_3026:
	/* 0x3026: cmp    r9,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RDX, X86_WIDTH_64);
x86_l_3029:
	/* 0x3029: jae    3014 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3014;
	}
x86_l_302b:
	/* 0x302b: movsx  r9d,BYTE PTR [rsi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_3030:
	/* 0x3030: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_3033:
	/* 0x3033: je     3073 <native_bpf_strncasestr+0x6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3073;
	}
x86_l_3035:
	/* 0x3035: movsx  r10d,BYTE PTR [rdi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_303a:
	/* 0x303a: lea    r11d,[r10-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_303e:
	/* 0x303e: mov    ebx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R10, X86_WIDTH_32);
x86_l_3041:
	/* 0x3041: or     ebx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_3044:
	/* 0x3044: cmp    r11d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 26ULL);
x86_l_3048:
	/* 0x3048: cmovae ebx,r10d */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R10, X86_WIDTH_32, X86_CC_AE);
x86_l_304c:
	/* 0x304c: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3050:
	/* 0x3050: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_3053:
	/* 0x3053: or     r11d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_3057:
	/* 0x3057: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_305b:
	/* 0x305b: cmovae r11d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_305f:
	/* 0x305f: cmp    ebx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R11, X86_WIDTH_32);
x86_l_3062:
	/* 0x3062: jne    3014 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3014;
	}
x86_l_3064:
	/* 0x3064: lea    r9,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3068:
	/* 0x3068: cmp    r8,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 99ULL);
x86_l_306c:
	/* 0x306c: mov    r8,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_64);
x86_l_306f:
	/* 0x306f: jb     3022 <native_bpf_strncasestr+0x1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3022;
	}
x86_l_3071:
	/* 0x3071: jmp    3014 <native_bpf_strncasestr+0xf> */
	goto x86_l_3014;
x86_l_3073:
	/* 0x3073: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3075:
	/* 0x3075: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3076:
	/* 0x3076: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11848U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1700ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1706ULL && __x86_pc <= 3353ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3357ULL && __x86_pc <= 4929ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4932ULL && __x86_pc <= 6539ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6541ULL && __x86_pc <= 8071ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8073ULL && __x86_pc <= 9669ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9674ULL && __x86_pc <= 11304ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11309ULL && __x86_pc <= 12406ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v53_generic_fexit_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

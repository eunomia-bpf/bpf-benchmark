extern char execve_map;
extern char fentry_calls;
extern char filter_map;
extern char process_call_heap;
extern char tg_mb_paths;
extern char tg_mb_sel_opts;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 7ULL: goto x86_l_7;
	case 10ULL: goto x86_l_a;
	case 18ULL: goto x86_l_12;
	case 23ULL: goto x86_l_17;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 40ULL: goto x86_l_28;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 54ULL: goto x86_l_36;
	case 56ULL: goto x86_l_38;
	case 61ULL: goto x86_l_3d;
	case 66ULL: goto x86_l_42;
	case 71ULL: goto x86_l_47;
	case 76ULL: goto x86_l_4c;
	case 81ULL: goto x86_l_51;
	case 86ULL: goto x86_l_56;
	case 88ULL: goto x86_l_58;
	case 92ULL: goto x86_l_5c;
	case 96ULL: goto x86_l_60;
	case 101ULL: goto x86_l_65;
	case 108ULL: goto x86_l_6c;
	case 113ULL: goto x86_l_71;
	case 115ULL: goto x86_l_73;
	case 118ULL: goto x86_l_76;
	case 120ULL: goto x86_l_78;
	case 125ULL: goto x86_l_7d;
	case 131ULL: goto x86_l_83;
	case 136ULL: goto x86_l_88;
	case 141ULL: goto x86_l_8d;
	case 146ULL: goto x86_l_92;
	case 151ULL: goto x86_l_97;
	case 156ULL: goto x86_l_9c;
	case 158ULL: goto x86_l_9e;
	case 164ULL: goto x86_l_a4;
	case 170ULL: goto x86_l_aa;
	case 175ULL: goto x86_l_af;
	case 180ULL: goto x86_l_b4;
	case 185ULL: goto x86_l_b9;
	case 190ULL: goto x86_l_be;
	case 195ULL: goto x86_l_c3;
	case 197ULL: goto x86_l_c5;
	case 201ULL: goto x86_l_c9;
	case 205ULL: goto x86_l_cd;
	case 210ULL: goto x86_l_d2;
	case 217ULL: goto x86_l_d9;
	case 222ULL: goto x86_l_de;
	case 224ULL: goto x86_l_e0;
	case 227ULL: goto x86_l_e3;
	case 229ULL: goto x86_l_e5;
	case 234ULL: goto x86_l_ea;
	case 240ULL: goto x86_l_f0;
	case 245ULL: goto x86_l_f5;
	case 250ULL: goto x86_l_fa;
	case 255ULL: goto x86_l_ff;
	case 260ULL: goto x86_l_104;
	case 265ULL: goto x86_l_109;
	case 267ULL: goto x86_l_10b;
	case 273ULL: goto x86_l_111;
	case 279ULL: goto x86_l_117;
	case 284ULL: goto x86_l_11c;
	case 289ULL: goto x86_l_121;
	case 294ULL: goto x86_l_126;
	case 299ULL: goto x86_l_12b;
	case 304ULL: goto x86_l_130;
	case 306ULL: goto x86_l_132;
	case 310ULL: goto x86_l_136;
	case 314ULL: goto x86_l_13a;
	case 319ULL: goto x86_l_13f;
	case 326ULL: goto x86_l_146;
	case 331ULL: goto x86_l_14b;
	case 333ULL: goto x86_l_14d;
	case 336ULL: goto x86_l_150;
	case 338ULL: goto x86_l_152;
	case 343ULL: goto x86_l_157;
	case 345ULL: goto x86_l_159;
	case 350ULL: goto x86_l_15e;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 365ULL: goto x86_l_16d;
	case 370ULL: goto x86_l_172;
	case 372ULL: goto x86_l_174;
	case 378ULL: goto x86_l_17a;
	case 384ULL: goto x86_l_180;
	case 389ULL: goto x86_l_185;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 404ULL: goto x86_l_194;
	case 409ULL: goto x86_l_199;
	case 411ULL: goto x86_l_19b;
	case 415ULL: goto x86_l_19f;
	case 419ULL: goto x86_l_1a3;
	case 424ULL: goto x86_l_1a8;
	case 431ULL: goto x86_l_1af;
	case 436ULL: goto x86_l_1b4;
	case 438ULL: goto x86_l_1b6;
	case 441ULL: goto x86_l_1b9;
	case 447ULL: goto x86_l_1bf;
	case 452ULL: goto x86_l_1c4;
	case 458ULL: goto x86_l_1ca;
	case 461ULL: goto x86_l_1cd;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 480ULL: goto x86_l_1e0;
	case 482ULL: goto x86_l_1e2;
	case 485ULL: goto x86_l_1e5;
	case 491ULL: goto x86_l_1eb;
	case 498ULL: goto x86_l_1f2;
	case 502ULL: goto x86_l_1f6;
	case 504ULL: goto x86_l_1f8;
	case 508ULL: goto x86_l_1fc;
	case 512ULL: goto x86_l_200;
	case 516ULL: goto x86_l_204;
	case 520ULL: goto x86_l_208;
	case 528ULL: goto x86_l_210;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 542ULL: goto x86_l_21e;
	case 545ULL: goto x86_l_221;
	case 548ULL: goto x86_l_224;
	case 554ULL: goto x86_l_22a;
	case 557ULL: goto x86_l_22d;
	case 563ULL: goto x86_l_233;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 578ULL: goto x86_l_242;
	case 585ULL: goto x86_l_249;
	case 590ULL: goto x86_l_24e;
	case 592ULL: goto x86_l_250;
	case 595ULL: goto x86_l_253;
	case 601ULL: goto x86_l_259;
	case 603ULL: goto x86_l_25b;
	case 605ULL: goto x86_l_25d;
	case 611ULL: goto x86_l_263;
	case 614ULL: goto x86_l_266;
	case 617ULL: goto x86_l_269;
	case 620ULL: goto x86_l_26c;
	case 626ULL: goto x86_l_272;
	case 630ULL: goto x86_l_276;
	case 636ULL: goto x86_l_27c;
	case 639ULL: goto x86_l_27f;
	case 644ULL: goto x86_l_284;
	case 647ULL: goto x86_l_287;
	case 649ULL: goto x86_l_289;
	case 656ULL: goto x86_l_290;
	case 659ULL: goto x86_l_293;
	case 663ULL: goto x86_l_297;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 677ULL: goto x86_l_2a5;
	case 682ULL: goto x86_l_2aa;
	case 685ULL: goto x86_l_2ad;
	case 687ULL: goto x86_l_2af;
	case 690ULL: goto x86_l_2b2;
	case 693ULL: goto x86_l_2b5;
	case 699ULL: goto x86_l_2bb;
	case 703ULL: goto x86_l_2bf;
	case 708ULL: goto x86_l_2c4;
	case 711ULL: goto x86_l_2c7;
	case 713ULL: goto x86_l_2c9;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 723ULL: goto x86_l_2d3;
	case 726ULL: goto x86_l_2d6;
	case 729ULL: goto x86_l_2d9;
	case 735ULL: goto x86_l_2df;
	case 737ULL: goto x86_l_2e1;
	case 747ULL: goto x86_l_2eb;
	case 751ULL: goto x86_l_2ef;
	case 757ULL: goto x86_l_2f5;
	case 760ULL: goto x86_l_2f8;
	case 765ULL: goto x86_l_2fd;
	case 767ULL: goto x86_l_2ff;
	case 772ULL: goto x86_l_304;
	case 780ULL: goto x86_l_30c;
	case 782ULL: goto x86_l_30e;
	case 786ULL: goto x86_l_312;
	case 790ULL: goto x86_l_316;
	case 794ULL: goto x86_l_31a;
	case 799ULL: goto x86_l_31f;
	case 802ULL: goto x86_l_322;
	case 807ULL: goto x86_l_327;
	case 810ULL: goto x86_l_32a;
	case 818ULL: goto x86_l_332;
	case 822ULL: goto x86_l_336;
	case 825ULL: goto x86_l_339;
	case 831ULL: goto x86_l_33f;
	case 833ULL: goto x86_l_341;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 845ULL: goto x86_l_34d;
	case 849ULL: goto x86_l_351;
	case 855ULL: goto x86_l_357;
	case 859ULL: goto x86_l_35b;
	case 863ULL: goto x86_l_35f;
	case 868ULL: goto x86_l_364;
	case 873ULL: goto x86_l_369;
	case 875ULL: goto x86_l_36b;
	case 879ULL: goto x86_l_36f;
	case 883ULL: goto x86_l_373;
	case 886ULL: goto x86_l_376;
	case 888ULL: goto x86_l_378;
	case 892ULL: goto x86_l_37c;
	case 895ULL: goto x86_l_37f;
	case 899ULL: goto x86_l_383;
	case 904ULL: goto x86_l_388;
	case 907ULL: goto x86_l_38b;
	case 911ULL: goto x86_l_38f;
	case 917ULL: goto x86_l_395;
	case 919ULL: goto x86_l_397;
	case 921ULL: goto x86_l_399;
	case 923ULL: goto x86_l_39b;
	case 928ULL: goto x86_l_3a0;
	case 933ULL: goto x86_l_3a5;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 948ULL: goto x86_l_3b4;
	case 950ULL: goto x86_l_3b6;
	case 955ULL: goto x86_l_3bb;
	case 958ULL: goto x86_l_3be;
	case 961ULL: goto x86_l_3c1;
	case 967ULL: goto x86_l_3c7;
	case 970ULL: goto x86_l_3ca;
	case 976ULL: goto x86_l_3d0;
	case 979ULL: goto x86_l_3d3;
	case 981ULL: goto x86_l_3d5;
	case 984ULL: goto x86_l_3d8;
	case 987ULL: goto x86_l_3db;
	case 992ULL: goto x86_l_3e0;
	case 995ULL: goto x86_l_3e3;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1006ULL: goto x86_l_3ee;
	case 1009ULL: goto x86_l_3f1;
	case 1013ULL: goto x86_l_3f5;
	case 1015ULL: goto x86_l_3f7;
	case 1017ULL: goto x86_l_3f9;
	case 1021ULL: goto x86_l_3fd;
	case 1023ULL: goto x86_l_3ff;
	case 1026ULL: goto x86_l_402;
	case 1032ULL: goto x86_l_408;
	case 1035ULL: goto x86_l_40b;
	case 1038ULL: goto x86_l_40e;
	case 1042ULL: goto x86_l_412;
	case 1046ULL: goto x86_l_416;
	case 1051ULL: goto x86_l_41b;
	case 1057ULL: goto x86_l_421;
	case 1063ULL: goto x86_l_427;
	case 1065ULL: goto x86_l_429;
	case 1068ULL: goto x86_l_42c;
	case 1071ULL: goto x86_l_42f;
	case 1077ULL: goto x86_l_435;
	case 1080ULL: goto x86_l_438;
	case 1083ULL: goto x86_l_43b;
	case 1089ULL: goto x86_l_441;
	case 1094ULL: goto x86_l_446;
	case 1099ULL: goto x86_l_44b;
	case 1104ULL: goto x86_l_450;
	case 1109ULL: goto x86_l_455;
	case 1114ULL: goto x86_l_45a;
	case 1118ULL: goto x86_l_45e;
	case 1123ULL: goto x86_l_463;
	case 1130ULL: goto x86_l_46a;
	case 1132ULL: goto x86_l_46c;
	case 1135ULL: goto x86_l_46f;
	case 1141ULL: goto x86_l_475;
	case 1143ULL: goto x86_l_477;
	case 1148ULL: goto x86_l_47c;
	case 1151ULL: goto x86_l_47f;
	case 1157ULL: goto x86_l_485;
	case 1160ULL: goto x86_l_488;
	case 1163ULL: goto x86_l_48b;
	case 1169ULL: goto x86_l_491;
	case 1173ULL: goto x86_l_495;
	case 1178ULL: goto x86_l_49a;
	case 1185ULL: goto x86_l_4a1;
	case 1188ULL: goto x86_l_4a4;
	case 1190ULL: goto x86_l_4a6;
	case 1193ULL: goto x86_l_4a9;
	case 1199ULL: goto x86_l_4af;
	case 1201ULL: goto x86_l_4b1;
	case 1206ULL: goto x86_l_4b6;
	case 1209ULL: goto x86_l_4b9;
	case 1215ULL: goto x86_l_4bf;
	case 1218ULL: goto x86_l_4c2;
	case 1221ULL: goto x86_l_4c5;
	case 1227ULL: goto x86_l_4cb;
	case 1231ULL: goto x86_l_4cf;
	case 1236ULL: goto x86_l_4d4;
	case 1243ULL: goto x86_l_4db;
	case 1246ULL: goto x86_l_4de;
	case 1248ULL: goto x86_l_4e0;
	case 1251ULL: goto x86_l_4e3;
	case 1257ULL: goto x86_l_4e9;
	case 1259ULL: goto x86_l_4eb;
	case 1264ULL: goto x86_l_4f0;
	case 1270ULL: goto x86_l_4f6;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1284ULL: goto x86_l_504;
	case 1288ULL: goto x86_l_508;
	case 1293ULL: goto x86_l_50d;
	case 1300ULL: goto x86_l_514;
	case 1303ULL: goto x86_l_517;
	case 1305ULL: goto x86_l_519;
	case 1308ULL: goto x86_l_51c;
	case 1314ULL: goto x86_l_522;
	case 1316ULL: goto x86_l_524;
	case 1321ULL: goto x86_l_529;
	case 1327ULL: goto x86_l_52f;
	case 1330ULL: goto x86_l_532;
	case 1335ULL: goto x86_l_537;
	case 1341ULL: goto x86_l_53d;
	case 1345ULL: goto x86_l_541;
	case 1350ULL: goto x86_l_546;
	case 1357ULL: goto x86_l_54d;
	case 1360ULL: goto x86_l_550;
	case 1362ULL: goto x86_l_552;
	case 1365ULL: goto x86_l_555;
	case 1371ULL: goto x86_l_55b;
	case 1373ULL: goto x86_l_55d;
	case 1378ULL: goto x86_l_562;
	case 1384ULL: goto x86_l_568;
	case 1387ULL: goto x86_l_56b;
	case 1392ULL: goto x86_l_570;
	case 1398ULL: goto x86_l_576;
	case 1402ULL: goto x86_l_57a;
	case 1407ULL: goto x86_l_57f;
	case 1414ULL: goto x86_l_586;
	case 1417ULL: goto x86_l_589;
	case 1419ULL: goto x86_l_58b;
	case 1422ULL: goto x86_l_58e;
	case 1428ULL: goto x86_l_594;
	case 1430ULL: goto x86_l_596;
	case 1435ULL: goto x86_l_59b;
	case 1441ULL: goto x86_l_5a1;
	case 1444ULL: goto x86_l_5a4;
	case 1449ULL: goto x86_l_5a9;
	case 1455ULL: goto x86_l_5af;
	case 1459ULL: goto x86_l_5b3;
	case 1464ULL: goto x86_l_5b8;
	case 1471ULL: goto x86_l_5bf;
	case 1474ULL: goto x86_l_5c2;
	case 1476ULL: goto x86_l_5c4;
	case 1479ULL: goto x86_l_5c7;
	case 1485ULL: goto x86_l_5cd;
	case 1487ULL: goto x86_l_5cf;
	case 1492ULL: goto x86_l_5d4;
	case 1498ULL: goto x86_l_5da;
	case 1501ULL: goto x86_l_5dd;
	case 1506ULL: goto x86_l_5e2;
	case 1512ULL: goto x86_l_5e8;
	case 1516ULL: goto x86_l_5ec;
	case 1521ULL: goto x86_l_5f1;
	case 1528ULL: goto x86_l_5f8;
	case 1531ULL: goto x86_l_5fb;
	case 1533ULL: goto x86_l_5fd;
	case 1536ULL: goto x86_l_600;
	case 1542ULL: goto x86_l_606;
	case 1544ULL: goto x86_l_608;
	case 1549ULL: goto x86_l_60d;
	case 1555ULL: goto x86_l_613;
	case 1558ULL: goto x86_l_616;
	case 1563ULL: goto x86_l_61b;
	case 1566ULL: goto x86_l_61e;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1591ULL: goto x86_l_637;
	case 1597ULL: goto x86_l_63d;
	case 1601ULL: goto x86_l_641;
	case 1606ULL: goto x86_l_646;
	case 1611ULL: goto x86_l_64b;
	case 1613ULL: goto x86_l_64d;
	case 1616ULL: goto x86_l_650;
	case 1622ULL: goto x86_l_656;
	case 1625ULL: goto x86_l_659;
	case 1628ULL: goto x86_l_65c;
	case 1634ULL: goto x86_l_662;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 88ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_12:
	/* 0x12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17:
	/* 0x17: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1e:
	/* 0x1e: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     1f9c <generic_fentry_process_filter+0x1f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8092ULL;
	}
x86_l_2e:
	/* 0x2e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_36:
	/* 0x36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38:
	/* 0x38: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3d:
	/* 0x3d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42:
	/* 0x42: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_47:
	/* 0x47: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_4c:
	/* 0x4c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_51:
	/* 0x51: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56:
	/* 0x56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58:
	/* 0x58: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5c:
	/* 0x5c: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_60:
	/* 0x60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_65:
	/* 0x65: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_6c:
	/* 0x6c: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_71:
	/* 0x71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73:
	/* 0x73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76:
	/* 0x76: je     83 <generic_fentry_process_filter+0x83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_83;
	}
x86_l_78:
	/* 0x78: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_7d:
	/* 0x7d: jne    1ca <generic_fentry_process_filter+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ca;
	}
x86_l_83:
	/* 0x83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_88:
	/* 0x88: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_8d:
	/* 0x8d: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_92:
	/* 0x92: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_97:
	/* 0x97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9c:
	/* 0x9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e:
	/* 0x9e: cmp    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_a4:
	/* 0xa4: je     1f9c <generic_fentry_process_filter+0x1f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8092ULL;
	}
x86_l_aa:
	/* 0xaa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_af:
	/* 0xaf: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_b4:
	/* 0xb4: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_b9:
	/* 0xb9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_be:
	/* 0xbe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c3:
	/* 0xc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5:
	/* 0xc5: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c9:
	/* 0xc9: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_cd:
	/* 0xcd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d2:
	/* 0xd2: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_d9:
	/* 0xd9: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_de:
	/* 0xde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0:
	/* 0xe0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e3:
	/* 0xe3: je     f0 <generic_fentry_process_filter+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f0;
	}
x86_l_e5:
	/* 0xe5: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ea:
	/* 0xea: jne    1ca <generic_fentry_process_filter+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ca;
	}
x86_l_f0:
	/* 0xf0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f5:
	/* 0xf5: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_fa:
	/* 0xfa: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_ff:
	/* 0xff: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_104:
	/* 0x104: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_109:
	/* 0x109: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b:
	/* 0x10b: cmp    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_111:
	/* 0x111: je     1f9c <generic_fentry_process_filter+0x1f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8092ULL;
	}
x86_l_117:
	/* 0x117: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11c:
	/* 0x11c: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_121:
	/* 0x121: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_126:
	/* 0x126: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12b:
	/* 0x12b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_130:
	/* 0x130: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_132:
	/* 0x132: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_136:
	/* 0x136: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_13a:
	/* 0x13a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13f:
	/* 0x13f: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_146:
	/* 0x146: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_14b:
	/* 0x14b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d:
	/* 0x14d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_150:
	/* 0x150: je     159 <generic_fentry_process_filter+0x159> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_159;
	}
x86_l_152:
	/* 0x152: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_157:
	/* 0x157: jne    1ca <generic_fentry_process_filter+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ca;
	}
x86_l_159:
	/* 0x159: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15e:
	/* 0x15e: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_163:
	/* 0x163: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_168:
	/* 0x168: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16d:
	/* 0x16d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_172:
	/* 0x172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174:
	/* 0x174: cmp    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_17a:
	/* 0x17a: je     1f9c <generic_fentry_process_filter+0x1f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8092ULL;
	}
x86_l_180:
	/* 0x180: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_185:
	/* 0x185: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_18a:
	/* 0x18a: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_18f:
	/* 0x18f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_194:
	/* 0x194: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_199:
	/* 0x199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b:
	/* 0x19b: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19f:
	/* 0x19f: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1a3:
	/* 0x1a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a8:
	/* 0x1a8: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1af:
	/* 0x1af: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1b4:
	/* 0x1b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6:
	/* 0x1b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b9:
	/* 0x1b9: je     39b <generic_fentry_process_filter+0x39b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39b;
	}
x86_l_1bf:
	/* 0x1bf: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1c4:
	/* 0x1c4: je     39b <generic_fentry_process_filter+0x39b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39b;
	}
x86_l_1ca:
	/* 0x1ca: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: lea    rsi,[r14+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_1d4:
	/* 0x1d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d9:
	/* 0x1d9: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_1e0:
	/* 0x1e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e2:
	/* 0x1e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e5:
	/* 0x1e5: je     1f9c <generic_fentry_process_filter+0x1f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8092ULL;
	}
x86_l_1eb:
	/* 0x1eb: mov    r12,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_1f2:
	/* 0x1f2: cmp    r12,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 6ULL);
x86_l_1f6:
	/* 0x1f6: jb     21b <generic_fentry_process_filter+0x21b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21b;
	}
x86_l_1f8:
	/* 0x1f8: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc:
	/* 0x1fc: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_200:
	/* 0x200: mov    rax,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_204:
	/* 0x204: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_208:
	/* 0x208: cmp    BYTE PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_210:
	/* 0x210: jne    1f89 <generic_fentry_process_filter+0x1f89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8073ULL;
	}
x86_l_216:
	/* 0x216: jmp    1f9c <generic_fentry_process_filter+0x1f9c> */
	return 8092ULL;
x86_l_21b:
	/* 0x21b: movsxd r15,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_21e:
	/* 0x21e: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_221:
	/* 0x221: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_224:
	/* 0x224: je     304 <generic_fentry_process_filter+0x304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_304;
	}
x86_l_22a:
	/* 0x22a: cmp    r12,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R15, X86_WIDTH_64);
x86_l_22d:
	/* 0x22d: jae    1f71 <generic_fentry_process_filter+0x1f71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8049ULL;
	}
x86_l_233:
	/* 0x233: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_238:
	/* 0x238: mov    DWORD PTR [rsp+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23d:
	/* 0x23d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_242:
	/* 0x242: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_sel_opts)));
x86_l_249:
	/* 0x249: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_24e:
	/* 0x24e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250:
	/* 0x250: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_253:
	/* 0x253: je     31f <generic_fentry_process_filter+0x31f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31f;
	}
x86_l_259:
	/* 0x259: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25b:
	/* 0x25b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_25d:
	/* 0x25d: je     31f <generic_fentry_process_filter+0x31f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31f;
	}
x86_l_263:
	/* 0x263: lea    ecx,[rdx-0x5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551611ULL);
x86_l_266:
	/* 0x266: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_269:
	/* 0x269: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_26c:
	/* 0x26c: ja     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8027ULL;
	}
x86_l_272:
	/* 0x272: cmp    DWORD PTR [rcx+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_276:
	/* 0x276: js     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8027ULL;
	}
x86_l_27c:
	/* 0x27c: mov    edi,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27f:
	/* 0x27f: mov    esi,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967295ULL);
x86_l_284:
	/* 0x284: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_287:
	/* 0x287: je     299 <generic_fentry_process_filter+0x299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_299;
	}
x86_l_289:
	/* 0x289: mov    r8,QWORD PTR [rcx+0x370] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 880ULL);
x86_l_290:
	/* 0x290: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_293:
	/* 0x293: bt     r8,rdi */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_297:
	/* 0x297: jb     2d6 <generic_fentry_process_filter+0x2d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2d6;
	}
x86_l_299:
	/* 0x299: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_29e:
	/* 0x29e: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_paths)));
x86_l_2a5:
	/* 0x2a5: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2aa:
	/* 0x2aa: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2ad:
	/* 0x2ad: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2af:
	/* 0x2af: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2b2:
	/* 0x2b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b5:
	/* 0x2b5: je     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8027ULL;
	}
x86_l_2bb:
	/* 0x2bb: lea    rsi,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2bf:
	/* 0x2bf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c4:
	/* 0x2c4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2c7:
	/* 0x2c7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2c9:
	/* 0x2c9: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2cc:
	/* 0x2cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cf:
	/* 0x2cf: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_2d3:
	/* 0x2d3: mov    edx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d6:
	/* 0x2d6: cmp    edx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 37ULL);
x86_l_2d9:
	/* 0x2d9: ja     7ff <generic_fentry_process_filter+0x7ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2047ULL;
	}
x86_l_2df:
	/* 0x2df: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2e1:
	/* 0x2e1: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_2eb:
	/* 0x2eb: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2ef:
	/* 0x2ef: jae    7ff <generic_fentry_process_filter+0x7ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2047ULL;
	}
x86_l_2f5:
	/* 0x2f5: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_2f8:
	/* 0x2f8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fd:
	/* 0x2fd: je     327 <generic_fentry_process_filter+0x327> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_327;
	}
x86_l_2ff:
	/* 0x2ff: jmp    1f5b <generic_fentry_process_filter+0x1f5b> */
	return 8027ULL;
x86_l_304:
	/* 0x304: mov    BYTE PTR [r14+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_30c:
	/* 0x30c: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e:
	/* 0x30e: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_312:
	/* 0x312: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_316:
	/* 0x316: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31a:
	/* 0x31a: jmp    1f89 <generic_fentry_process_filter+0x1f89> */
	return 8073ULL;
x86_l_31f:
	/* 0x31f: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_322:
	/* 0x322: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_327:
	/* 0x327: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_32a:
	/* 0x32a: lea    rsi,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_332:
	/* 0x332: mov    eax,DWORD PTR [rdx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_336:
	/* 0x336: lea    ebp,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_339:
	/* 0x339: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_33f:
	/* 0x33f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_341:
	/* 0x341: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_344:
	/* 0x344: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_349:
	/* 0x349: lea    r11,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34d:
	/* 0x34d: cmp    DWORD PTR [rax+rdx*1],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 5ULL);
x86_l_351:
	/* 0x351: jb     16f9 <generic_fentry_process_filter+0x16f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5881ULL;
	}
x86_l_357:
	/* 0x357: lea    r8d,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_35b:
	/* 0x35b: mov    r9d,DWORD PTR [r11+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_35f:
	/* 0x35f: mov    r10d,DWORD PTR [r11+rdx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_364:
	/* 0x364: mov    eax,DWORD PTR [r11+rdx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 8ULL);
x86_l_369:
	/* 0x369: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36b:
	/* 0x36b: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_36f:
	/* 0x36f: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_373:
	/* 0x373: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_376:
	/* 0x376: jbe    3bb <generic_fentry_process_filter+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3bb;
	}
x86_l_378:
	/* 0x378: lea    rax,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_37c:
	/* 0x37c: mov    rsi,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R10, X86_WIDTH_64);
x86_l_37f:
	/* 0x37f: and    rsi,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_AND, 1ULL);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rsp+0x48],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_388:
	/* 0x388: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_38b:
	/* 0x38b: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_38f:
	/* 0x38f: cmp    ebp,0x3d4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 980ULL);
x86_l_395:
	/* 0x395: jbe    3e8 <generic_fentry_process_filter+0x3e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3e8;
	}
x86_l_397:
	/* 0x397: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_399:
	/* 0x399: jmp    3f1 <generic_fentry_process_filter+0x3f1> */
	goto x86_l_3f1;
x86_l_39b:
	/* 0x39b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a0:
	/* 0x3a0: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_3a5:
	/* 0x3a5: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_3aa:
	/* 0x3aa: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3af:
	/* 0x3af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b4:
	/* 0x3b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b6:
	/* 0x3b6: jmp    1f9c <generic_fentry_process_filter+0x1f9c> */
	return 8092ULL;
x86_l_3bb:
	/* 0x3bb: mov    dil,sil */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_8);
x86_l_3be:
	/* 0x3be: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c1:
	/* 0x3c1: je     7e5 <generic_fentry_process_filter+0x7e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2021ULL;
	}
x86_l_3c7:
	/* 0x3c7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ca:
	/* 0x3ca: je     7ce <generic_fentry_process_filter+0x7ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1998ULL;
	}
x86_l_3d0:
	/* 0x3d0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3d3:
	/* 0x3d3: jne    378 <generic_fentry_process_filter+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_378;
	}
x86_l_3d5:
	/* 0x3d5: mov    eax,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R10, X86_WIDTH_32);
x86_l_3d8:
	/* 0x3d8: and    eax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_3db:
	/* 0x3db: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3e0:
	/* 0x3e0: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_3e3:
	/* 0x3e3: jmp    8a1 <generic_fentry_process_filter+0x8a1> */
	return 2209ULL;
x86_l_3e8:
	/* 0x3e8: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_3eb:
	/* 0x3eb: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_3ee:
	/* 0x3ee: mov    edi,DWORD PTR [rdx+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3f1:
	/* 0x3f1: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_3f5:
	/* 0x3f5: jne    41b <generic_fentry_process_filter+0x41b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_41b;
	}
x86_l_3f7:
	/* 0x3f7: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f9:
	/* 0x3f9: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_3fd:
	/* 0x3fd: jne    408 <generic_fentry_process_filter+0x408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_408;
	}
x86_l_3ff:
	/* 0x3ff: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_402:
	/* 0x402: jne    7c6 <generic_fentry_process_filter+0x7c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1990ULL;
	}
x86_l_408:
	/* 0x408: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_40b:
	/* 0x40b: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_40e:
	/* 0x40e: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_412:
	/* 0x412: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_416:
	/* 0x416: jmp    897 <generic_fentry_process_filter+0x897> */
	return 2199ULL;
x86_l_41b:
	/* 0x41b: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_421:
	/* 0x421: jne    64b <generic_fentry_process_filter+0x64b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_64b;
	}
x86_l_427:
	/* 0x427: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_429:
	/* 0x429: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_42c:
	/* 0x42c: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_42f:
	/* 0x42f: je     88c <generic_fentry_process_filter+0x88c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2188ULL;
	}
x86_l_435:
	/* 0x435: mov    eax,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_438:
	/* 0x438: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_43b:
	/* 0x43b: je     88c <generic_fentry_process_filter+0x88c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2188ULL;
	}
x86_l_441:
	/* 0x441: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_446:
	/* 0x446: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_44b:
	/* 0x44b: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_450:
	/* 0x450: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_455:
	/* 0x455: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45a:
	/* 0x45a: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45e:
	/* 0x45e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_463:
	/* 0x463: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_46a:
	/* 0x46a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46c:
	/* 0x46c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46f:
	/* 0x46f: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2151ULL;
	}
x86_l_475:
	/* 0x475: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_477:
	/* 0x477: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_47c:
	/* 0x47c: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_47f:
	/* 0x47f: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_485:
	/* 0x485: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_488:
	/* 0x488: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_48b:
	/* 0x48b: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_491:
	/* 0x491: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_495:
	/* 0x495: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_49a:
	/* 0x49a: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_4a1:
	/* 0x4a1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_4a4:
	/* 0x4a4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4a6:
	/* 0x4a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a9:
	/* 0x4a9: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2151ULL;
	}
x86_l_4af:
	/* 0x4af: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b1:
	/* 0x4b1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4b6:
	/* 0x4b6: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_4b9:
	/* 0x4b9: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_4bf:
	/* 0x4bf: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c2:
	/* 0x4c2: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_4c5:
	/* 0x4c5: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_4cb:
	/* 0x4cb: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4cf:
	/* 0x4cf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4d4:
	/* 0x4d4: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_4db:
	/* 0x4db: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_4de:
	/* 0x4de: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4e0:
	/* 0x4e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e3:
	/* 0x4e3: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2151ULL;
	}
x86_l_4e9:
	/* 0x4e9: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eb:
	/* 0x4eb: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4f0:
	/* 0x4f0: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_4f6:
	/* 0x4f6: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f9:
	/* 0x4f9: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4fe:
	/* 0x4fe: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_504:
	/* 0x504: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_508:
	/* 0x508: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_50d:
	/* 0x50d: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_514:
	/* 0x514: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_517:
	/* 0x517: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_519:
	/* 0x519: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51c:
	/* 0x51c: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2151ULL;
	}
x86_l_522:
	/* 0x522: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_524:
	/* 0x524: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_529:
	/* 0x529: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_52f:
	/* 0x52f: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_532:
	/* 0x532: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_537:
	/* 0x537: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_53d:
	/* 0x53d: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_541:
	/* 0x541: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_546:
	/* 0x546: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_54d:
	/* 0x54d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_550:
	/* 0x550: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_552:
	/* 0x552: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_555:
	/* 0x555: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2151ULL;
	}
x86_l_55b:
	/* 0x55b: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55d:
	/* 0x55d: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_562:
	/* 0x562: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_568:
	/* 0x568: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56b:
	/* 0x56b: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_570:
	/* 0x570: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_576:
	/* 0x576: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_57a:
	/* 0x57a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_57f:
	/* 0x57f: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_586:
	/* 0x586: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_589:
	/* 0x589: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_58b:
	/* 0x58b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_58e:
	/* 0x58e: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2151ULL;
	}
x86_l_594:
	/* 0x594: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_596:
	/* 0x596: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59b:
	/* 0x59b: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_5a1:
	/* 0x5a1: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a4:
	/* 0x5a4: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5a9:
	/* 0x5a9: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_5af:
	/* 0x5af: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b3:
	/* 0x5b3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5b8:
	/* 0x5b8: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_5bf:
	/* 0x5bf: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_5c2:
	/* 0x5c2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5c4:
	/* 0x5c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c7:
	/* 0x5c7: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2151ULL;
	}
x86_l_5cd:
	/* 0x5cd: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cf:
	/* 0x5cf: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d4:
	/* 0x5d4: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_5da:
	/* 0x5da: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dd:
	/* 0x5dd: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5e2:
	/* 0x5e2: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_5e8:
	/* 0x5e8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5ec:
	/* 0x5ec: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5f1:
	/* 0x5f1: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_5f8:
	/* 0x5f8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_5fb:
	/* 0x5fb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5fd:
	/* 0x5fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_600:
	/* 0x600: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2151ULL;
	}
x86_l_606:
	/* 0x606: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_608:
	/* 0x608: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_60d:
	/* 0x60d: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1957ULL;
	}
x86_l_613:
	/* 0x613: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_616:
	/* 0x616: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_61b:
	/* 0x61b: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_61e:
	/* 0x61e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_623:
	/* 0x623: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_628:
	/* 0x628: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62d:
	/* 0x62d: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_632:
	/* 0x632: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_637:
	/* 0x637: je     88c <generic_fentry_process_filter+0x88c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2188ULL;
	}
x86_l_63d:
	/* 0x63d: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_641:
	/* 0x641: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_646:
	/* 0x646: jmp    85b <generic_fentry_process_filter+0x85b> */
	return 2139ULL;
x86_l_64b:
	/* 0x64b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64d:
	/* 0x64d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_650:
	/* 0x650: je     7c6 <generic_fentry_process_filter+0x7c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1990ULL;
	}
x86_l_656:
	/* 0x656: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_659:
	/* 0x659: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_65c:
	/* 0x65c: je     88c <generic_fentry_process_filter+0x88c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2188ULL;
	}
x86_l_662:
	/* 0x662: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
	return 1637ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1637ULL: goto x86_l_665;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1672ULL: goto x86_l_688;
	case 1677ULL: goto x86_l_68d;
	case 1684ULL: goto x86_l_694;
	case 1686ULL: goto x86_l_696;
	case 1689ULL: goto x86_l_699;
	case 1695ULL: goto x86_l_69f;
	case 1698ULL: goto x86_l_6a2;
	case 1703ULL: goto x86_l_6a7;
	case 1709ULL: goto x86_l_6ad;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1725ULL: goto x86_l_6bd;
	case 1728ULL: goto x86_l_6c0;
	case 1730ULL: goto x86_l_6c2;
	case 1733ULL: goto x86_l_6c5;
	case 1739ULL: goto x86_l_6cb;
	case 1742ULL: goto x86_l_6ce;
	case 1747ULL: goto x86_l_6d3;
	case 1753ULL: goto x86_l_6d9;
	case 1757ULL: goto x86_l_6dd;
	case 1762ULL: goto x86_l_6e2;
	case 1769ULL: goto x86_l_6e9;
	case 1772ULL: goto x86_l_6ec;
	case 1774ULL: goto x86_l_6ee;
	case 1777ULL: goto x86_l_6f1;
	case 1783ULL: goto x86_l_6f7;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1797ULL: goto x86_l_705;
	case 1801ULL: goto x86_l_709;
	case 1806ULL: goto x86_l_70e;
	case 1813ULL: goto x86_l_715;
	case 1816ULL: goto x86_l_718;
	case 1818ULL: goto x86_l_71a;
	case 1821ULL: goto x86_l_71d;
	case 1827ULL: goto x86_l_723;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1837ULL: goto x86_l_72d;
	case 1841ULL: goto x86_l_731;
	case 1846ULL: goto x86_l_736;
	case 1853ULL: goto x86_l_73d;
	case 1856ULL: goto x86_l_740;
	case 1858ULL: goto x86_l_742;
	case 1861ULL: goto x86_l_745;
	case 1867ULL: goto x86_l_74b;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1877ULL: goto x86_l_755;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1893ULL: goto x86_l_765;
	case 1896ULL: goto x86_l_768;
	case 1898ULL: goto x86_l_76a;
	case 1901ULL: goto x86_l_76d;
	case 1907ULL: goto x86_l_773;
	case 1910ULL: goto x86_l_776;
	case 1915ULL: goto x86_l_77b;
	case 1917ULL: goto x86_l_77d;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1938ULL: goto x86_l_792;
	case 1941ULL: goto x86_l_795;
	case 1947ULL: goto x86_l_79b;
	case 1950ULL: goto x86_l_79e;
	case 1955ULL: goto x86_l_7a3;
	case 1957ULL: goto x86_l_7a5;
	case 1960ULL: goto x86_l_7a8;
	case 1965ULL: goto x86_l_7ad;
	case 1970ULL: goto x86_l_7b2;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1993ULL: goto x86_l_7c9;
	case 1998ULL: goto x86_l_7ce;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2013ULL: goto x86_l_7dd;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2024ULL: goto x86_l_7e8;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2035ULL: goto x86_l_7f3;
	case 2039ULL: goto x86_l_7f7;
	case 2042ULL: goto x86_l_7fa;
	case 2047ULL: goto x86_l_7ff;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2061ULL: goto x86_l_80d;
	case 2066ULL: goto x86_l_812;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2082ULL: goto x86_l_822;
	case 2085ULL: goto x86_l_825;
	case 2087ULL: goto x86_l_827;
	case 2090ULL: goto x86_l_82a;
	case 2092ULL: goto x86_l_82c;
	case 2095ULL: goto x86_l_82f;
	case 2100ULL: goto x86_l_834;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2130ULL: goto x86_l_852;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2146ULL: goto x86_l_862;
	case 2149ULL: goto x86_l_865;
	case 2151ULL: goto x86_l_867;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2163ULL: goto x86_l_873;
	case 2166ULL: goto x86_l_876;
	case 2171ULL: goto x86_l_87b;
	case 2176ULL: goto x86_l_880;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2188ULL: goto x86_l_88c;
	case 2192ULL: goto x86_l_890;
	case 2195ULL: goto x86_l_893;
	case 2199ULL: goto x86_l_897;
	case 2202ULL: goto x86_l_89a;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2213ULL: goto x86_l_8a5;
	case 2219ULL: goto x86_l_8ab;
	case 2222ULL: goto x86_l_8ae;
	case 2226ULL: goto x86_l_8b2;
	case 2232ULL: goto x86_l_8b8;
	case 2234ULL: goto x86_l_8ba;
	case 2237ULL: goto x86_l_8bd;
	case 2242ULL: goto x86_l_8c2;
	case 2244ULL: goto x86_l_8c4;
	case 2247ULL: goto x86_l_8c7;
	case 2249ULL: goto x86_l_8c9;
	case 2252ULL: goto x86_l_8cc;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2263ULL: goto x86_l_8d7;
	case 2267ULL: goto x86_l_8db;
	case 2269ULL: goto x86_l_8dd;
	case 2271ULL: goto x86_l_8df;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2282ULL: goto x86_l_8ea;
	case 2285ULL: goto x86_l_8ed;
	case 2291ULL: goto x86_l_8f3;
	case 2294ULL: goto x86_l_8f6;
	case 2297ULL: goto x86_l_8f9;
	case 2301ULL: goto x86_l_8fd;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2316ULL: goto x86_l_90c;
	case 2322ULL: goto x86_l_912;
	case 2324ULL: goto x86_l_914;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2338ULL: goto x86_l_922;
	case 2341ULL: goto x86_l_925;
	case 2344ULL: goto x86_l_928;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2359ULL: goto x86_l_937;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2373ULL: goto x86_l_945;
	case 2378ULL: goto x86_l_94a;
	case 2383ULL: goto x86_l_94f;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2399ULL: goto x86_l_95f;
	case 2401ULL: goto x86_l_961;
	case 2404ULL: goto x86_l_964;
	case 2410ULL: goto x86_l_96a;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2424ULL: goto x86_l_978;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2440ULL: goto x86_l_988;
	case 2443ULL: goto x86_l_98b;
	case 2445ULL: goto x86_l_98d;
	case 2448ULL: goto x86_l_990;
	case 2454ULL: goto x86_l_996;
	case 2457ULL: goto x86_l_999;
	case 2462ULL: goto x86_l_99e;
	case 2468ULL: goto x86_l_9a4;
	case 2472ULL: goto x86_l_9a8;
	case 2477ULL: goto x86_l_9ad;
	case 2484ULL: goto x86_l_9b4;
	case 2487ULL: goto x86_l_9b7;
	case 2489ULL: goto x86_l_9b9;
	case 2492ULL: goto x86_l_9bc;
	case 2498ULL: goto x86_l_9c2;
	case 2501ULL: goto x86_l_9c5;
	case 2506ULL: goto x86_l_9ca;
	case 2512ULL: goto x86_l_9d0;
	case 2516ULL: goto x86_l_9d4;
	case 2521ULL: goto x86_l_9d9;
	case 2528ULL: goto x86_l_9e0;
	case 2531ULL: goto x86_l_9e3;
	case 2533ULL: goto x86_l_9e5;
	case 2536ULL: goto x86_l_9e8;
	case 2542ULL: goto x86_l_9ee;
	case 2545ULL: goto x86_l_9f1;
	case 2550ULL: goto x86_l_9f6;
	case 2556ULL: goto x86_l_9fc;
	case 2560ULL: goto x86_l_a00;
	case 2565ULL: goto x86_l_a05;
	case 2572ULL: goto x86_l_a0c;
	case 2575ULL: goto x86_l_a0f;
	case 2577ULL: goto x86_l_a11;
	case 2580ULL: goto x86_l_a14;
	case 2586ULL: goto x86_l_a1a;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2600ULL: goto x86_l_a28;
	case 2604ULL: goto x86_l_a2c;
	case 2609ULL: goto x86_l_a31;
	case 2616ULL: goto x86_l_a38;
	case 2619ULL: goto x86_l_a3b;
	case 2621ULL: goto x86_l_a3d;
	case 2624ULL: goto x86_l_a40;
	case 2630ULL: goto x86_l_a46;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2644ULL: goto x86_l_a54;
	case 2648ULL: goto x86_l_a58;
	case 2653ULL: goto x86_l_a5d;
	case 2660ULL: goto x86_l_a64;
	case 2663ULL: goto x86_l_a67;
	case 2665ULL: goto x86_l_a69;
	case 2668ULL: goto x86_l_a6c;
	case 2674ULL: goto x86_l_a72;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2688ULL: goto x86_l_a80;
	case 2692ULL: goto x86_l_a84;
	case 2697ULL: goto x86_l_a89;
	case 2704ULL: goto x86_l_a90;
	case 2707ULL: goto x86_l_a93;
	case 2709ULL: goto x86_l_a95;
	case 2712ULL: goto x86_l_a98;
	case 2718ULL: goto x86_l_a9e;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2758ULL: goto x86_l_ac6;
	case 2764ULL: goto x86_l_acc;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2788ULL: goto x86_l_ae4;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2799ULL: goto x86_l_aef;
	case 2805ULL: goto x86_l_af5;
	case 2808ULL: goto x86_l_af8;
	case 2811ULL: goto x86_l_afb;
	case 2817ULL: goto x86_l_b01;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2831ULL: goto x86_l_b0f;
	case 2836ULL: goto x86_l_b14;
	case 2841ULL: goto x86_l_b19;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2857ULL: goto x86_l_b29;
	case 2859ULL: goto x86_l_b2b;
	case 2862ULL: goto x86_l_b2e;
	case 2868ULL: goto x86_l_b34;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2878ULL: goto x86_l_b3e;
	case 2884ULL: goto x86_l_b44;
	case 2887ULL: goto x86_l_b47;
	case 2890ULL: goto x86_l_b4a;
	case 2896ULL: goto x86_l_b50;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2912ULL: goto x86_l_b60;
	case 2915ULL: goto x86_l_b63;
	case 2917ULL: goto x86_l_b65;
	case 2920ULL: goto x86_l_b68;
	case 2926ULL: goto x86_l_b6e;
	case 2928ULL: goto x86_l_b70;
	case 2933ULL: goto x86_l_b75;
	case 2936ULL: goto x86_l_b78;
	case 2942ULL: goto x86_l_b7e;
	case 2945ULL: goto x86_l_b81;
	case 2948ULL: goto x86_l_b84;
	case 2954ULL: goto x86_l_b8a;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2970ULL: goto x86_l_b9a;
	case 2973ULL: goto x86_l_b9d;
	case 2975ULL: goto x86_l_b9f;
	case 2978ULL: goto x86_l_ba2;
	case 2984ULL: goto x86_l_ba8;
	case 2986ULL: goto x86_l_baa;
	case 2991ULL: goto x86_l_baf;
	case 2997ULL: goto x86_l_bb5;
	case 3000ULL: goto x86_l_bb8;
	case 3005ULL: goto x86_l_bbd;
	case 3011ULL: goto x86_l_bc3;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3027ULL: goto x86_l_bd3;
	case 3030ULL: goto x86_l_bd6;
	case 3032ULL: goto x86_l_bd8;
	case 3035ULL: goto x86_l_bdb;
	case 3041ULL: goto x86_l_be1;
	case 3043ULL: goto x86_l_be3;
	case 3048ULL: goto x86_l_be8;
	case 3054ULL: goto x86_l_bee;
	case 3057ULL: goto x86_l_bf1;
	case 3062ULL: goto x86_l_bf6;
	case 3068ULL: goto x86_l_bfc;
	case 3072ULL: goto x86_l_c00;
	case 3077ULL: goto x86_l_c05;
	case 3084ULL: goto x86_l_c0c;
	case 3087ULL: goto x86_l_c0f;
	case 3089ULL: goto x86_l_c11;
	case 3092ULL: goto x86_l_c14;
	case 3098ULL: goto x86_l_c1a;
	case 3100ULL: goto x86_l_c1c;
	case 3105ULL: goto x86_l_c21;
	case 3111ULL: goto x86_l_c27;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3125ULL: goto x86_l_c35;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3141ULL: goto x86_l_c45;
	case 3144ULL: goto x86_l_c48;
	case 3146ULL: goto x86_l_c4a;
	case 3149ULL: goto x86_l_c4d;
	case 3155ULL: goto x86_l_c53;
	case 3157ULL: goto x86_l_c55;
	case 3162ULL: goto x86_l_c5a;
	case 3168ULL: goto x86_l_c60;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3182ULL: goto x86_l_c6e;
	case 3186ULL: goto x86_l_c72;
	case 3191ULL: goto x86_l_c77;
	case 3198ULL: goto x86_l_c7e;
	case 3201ULL: goto x86_l_c81;
	case 3203ULL: goto x86_l_c83;
	case 3206ULL: goto x86_l_c86;
	case 3212ULL: goto x86_l_c8c;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3225ULL: goto x86_l_c99;
	case 3228ULL: goto x86_l_c9c;
	case 3233ULL: goto x86_l_ca1;
	case 3239ULL: goto x86_l_ca7;
	case 3243ULL: goto x86_l_cab;
	case 3248ULL: goto x86_l_cb0;
	case 3255ULL: goto x86_l_cb7;
	case 3258ULL: goto x86_l_cba;
	case 3260ULL: goto x86_l_cbc;
	case 3263ULL: goto x86_l_cbf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_665:
	/* 0x665: je     88c <generic_fentry_process_filter+0x88c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_88c;
	}
x86_l_66b:
	/* 0x66b: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_670:
	/* 0x670: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_675:
	/* 0x675: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67a:
	/* 0x67a: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_67f:
	/* 0x67f: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_684:
	/* 0x684: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_688:
	/* 0x688: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_68d:
	/* 0x68d: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_694:
	/* 0x694: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_696:
	/* 0x696: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_699:
	/* 0x699: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_867;
	}
x86_l_69f:
	/* 0x69f: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6a2:
	/* 0x6a2: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a7:
	/* 0x6a7: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7a5;
	}
x86_l_6ad:
	/* 0x6ad: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6b1:
	/* 0x6b1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6b6:
	/* 0x6b6: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_6bd:
	/* 0x6bd: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_6c0:
	/* 0x6c0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6c2:
	/* 0x6c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c5:
	/* 0x6c5: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_867;
	}
x86_l_6cb:
	/* 0x6cb: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6ce:
	/* 0x6ce: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6d3:
	/* 0x6d3: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7a5;
	}
x86_l_6d9:
	/* 0x6d9: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6dd:
	/* 0x6dd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6e2:
	/* 0x6e2: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_6e9:
	/* 0x6e9: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_6ec:
	/* 0x6ec: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6ee:
	/* 0x6ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f1:
	/* 0x6f1: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_867;
	}
x86_l_6f7:
	/* 0x6f7: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6fa:
	/* 0x6fa: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ff:
	/* 0x6ff: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7a5;
	}
x86_l_705:
	/* 0x705: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_709:
	/* 0x709: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_70e:
	/* 0x70e: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_715:
	/* 0x715: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_718:
	/* 0x718: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_71a:
	/* 0x71a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_71d:
	/* 0x71d: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_867;
	}
x86_l_723:
	/* 0x723: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_726:
	/* 0x726: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_72b:
	/* 0x72b: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7a5;
	}
x86_l_72d:
	/* 0x72d: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_731:
	/* 0x731: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_736:
	/* 0x736: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_73d:
	/* 0x73d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_740:
	/* 0x740: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_742:
	/* 0x742: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_745:
	/* 0x745: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_867;
	}
x86_l_74b:
	/* 0x74b: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_74e:
	/* 0x74e: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_753:
	/* 0x753: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7a5;
	}
x86_l_755:
	/* 0x755: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_759:
	/* 0x759: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_75e:
	/* 0x75e: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_765:
	/* 0x765: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_768:
	/* 0x768: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_76a:
	/* 0x76a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76d:
	/* 0x76d: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_867;
	}
x86_l_773:
	/* 0x773: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_776:
	/* 0x776: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_77b:
	/* 0x77b: je     7a5 <generic_fentry_process_filter+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7a5;
	}
x86_l_77d:
	/* 0x77d: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_781:
	/* 0x781: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_786:
	/* 0x786: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_78d:
	/* 0x78d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_790:
	/* 0x790: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_792:
	/* 0x792: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_795:
	/* 0x795: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_867;
	}
x86_l_79b:
	/* 0x79b: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_79e:
	/* 0x79e: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7a3:
	/* 0x7a3: jne    812 <generic_fentry_process_filter+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_812;
	}
x86_l_7a5:
	/* 0x7a5: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_7a8:
	/* 0x7a8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7ad:
	/* 0x7ad: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7b2:
	/* 0x7b2: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b7:
	/* 0x7b7: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7bc:
	/* 0x7bc: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c1:
	/* 0x7c1: jmp    88c <generic_fentry_process_filter+0x88c> */
	goto x86_l_88c;
x86_l_7c6:
	/* 0x7c6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c9:
	/* 0x7c9: jmp    89a <generic_fentry_process_filter+0x89a> */
	goto x86_l_89a;
x86_l_7ce:
	/* 0x7ce: mov    eax,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R10, X86_WIDTH_32);
x86_l_7d1:
	/* 0x7d1: and    eax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_7d4:
	/* 0x7d4: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7d9:
	/* 0x7d9: mov    DWORD PTR [rsp+0x50],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7dd:
	/* 0x7dd: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_7e0:
	/* 0x7e0: jmp    d6d <generic_fentry_process_filter+0xd6d> */
	return 3437ULL;
x86_l_7e5:
	/* 0x7e5: mov    eax,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R10, X86_WIDTH_32);
x86_l_7e8:
	/* 0x7e8: and    eax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_7eb:
	/* 0x7eb: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7f0:
	/* 0x7f0: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_7f3:
	/* 0x7f3: mov    DWORD PTR [rsp+0x50],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7f7:
	/* 0x7f7: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_7fa:
	/* 0x7fa: jmp    1235 <generic_fentry_process_filter+0x1235> */
	return 4661ULL;
x86_l_7ff:
	/* 0x7ff: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_802:
	/* 0x802: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_807:
	/* 0x807: jne    327 <generic_fentry_process_filter+0x327> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 807ULL;
	}
x86_l_80d:
	/* 0x80d: jmp    1f5b <generic_fentry_process_filter+0x1f5b> */
	return 8027ULL;
x86_l_812:
	/* 0x812: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_816:
	/* 0x816: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_81b:
	/* 0x81b: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_822:
	/* 0x822: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_825:
	/* 0x825: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_827:
	/* 0x827: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_82a:
	/* 0x82a: je     867 <generic_fentry_process_filter+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_867;
	}
x86_l_82c:
	/* 0x82c: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_82f:
	/* 0x82f: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_834:
	/* 0x834: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_837:
	/* 0x837: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_83c:
	/* 0x83c: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_841:
	/* 0x841: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_846:
	/* 0x846: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_84b:
	/* 0x84b: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_850:
	/* 0x850: je     88c <generic_fentry_process_filter+0x88c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_88c;
	}
x86_l_852:
	/* 0x852: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_856:
	/* 0x856: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_85b:
	/* 0x85b: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_862:
	/* 0x862: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_865:
	/* 0x865: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_867:
	/* 0x867: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_86a:
	/* 0x86a: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_86f:
	/* 0x86f: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_873:
	/* 0x873: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_876:
	/* 0x876: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_87b:
	/* 0x87b: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_880:
	/* 0x880: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_885:
	/* 0x885: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_88a:
	/* 0x88a: je     89a <generic_fentry_process_filter+0x89a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_89a;
	}
x86_l_88c:
	/* 0x88c: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_890:
	/* 0x890: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_893:
	/* 0x893: xor    r12b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_897:
	/* 0x897: or     r12b,al */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_89a:
	/* 0x89a: movzx  edi,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_89e:
	/* 0x89e: add    ebp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_8a1:
	/* 0x8a1: lea    rax,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8a5:
	/* 0x8a5: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_8ab:
	/* 0x8ab: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_8ae:
	/* 0x8ae: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_8b2:
	/* 0x8b2: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_8b8:
	/* 0x8b8: jbe    8c4 <generic_fentry_process_filter+0x8c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_8c4;
	}
x86_l_8ba:
	/* 0x8ba: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8bd:
	/* 0x8bd: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8c2:
	/* 0x8c2: jmp    8d7 <generic_fentry_process_filter+0x8d7> */
	goto x86_l_8d7;
x86_l_8c4:
	/* 0x8c4: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_8c7:
	/* 0x8c7: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_8c9:
	/* 0x8c9: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_8cc:
	/* 0x8cc: mov    edi,DWORD PTR [rdx+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_8cf:
	/* 0x8cf: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8d4:
	/* 0x8d4: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_8d7:
	/* 0x8d7: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_8db:
	/* 0x8db: jne    906 <generic_fentry_process_filter+0x906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_906;
	}
x86_l_8dd:
	/* 0x8dd: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8df:
	/* 0x8df: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_8e3:
	/* 0x8e3: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8e8:
	/* 0x8e8: jne    8f3 <generic_fentry_process_filter+0x8f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8f3;
	}
x86_l_8ea:
	/* 0x8ea: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_8ed:
	/* 0x8ed: jne    ada <generic_fentry_process_filter+0xada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ada;
	}
x86_l_8f3:
	/* 0x8f3: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_8f6:
	/* 0x8f6: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_8f9:
	/* 0x8f9: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_8fd:
	/* 0x8fd: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_901:
	/* 0x901: jmp    d5f <generic_fentry_process_filter+0xd5f> */
	return 3423ULL;
x86_l_906:
	/* 0x906: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_90c:
	/* 0x90c: je     ae2 <generic_fentry_process_filter+0xae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ae2;
	}
x86_l_912:
	/* 0x912: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_914:
	/* 0x914: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_917:
	/* 0x917: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_91c:
	/* 0x91c: je     ada <generic_fentry_process_filter+0xada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ada;
	}
x86_l_922:
	/* 0x922: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_925:
	/* 0x925: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_928:
	/* 0x928: je     d54 <generic_fentry_process_filter+0xd54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3412ULL;
	}
x86_l_92e:
	/* 0x92e: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_931:
	/* 0x931: je     d54 <generic_fentry_process_filter+0xd54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3412ULL;
	}
x86_l_937:
	/* 0x937: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_93b:
	/* 0x93b: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_940:
	/* 0x940: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_945:
	/* 0x945: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_94a:
	/* 0x94a: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_94f:
	/* 0x94f: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_953:
	/* 0x953: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_958:
	/* 0x958: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_95f:
	/* 0x95f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_961:
	/* 0x961: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_964:
	/* 0x964: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_96a:
	/* 0x96a: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_96d:
	/* 0x96d: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_972:
	/* 0x972: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_978:
	/* 0x978: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_97c:
	/* 0x97c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_981:
	/* 0x981: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_988:
	/* 0x988: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_98b:
	/* 0x98b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_98d:
	/* 0x98d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_990:
	/* 0x990: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_996:
	/* 0x996: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_999:
	/* 0x999: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_99e:
	/* 0x99e: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_9a4:
	/* 0x9a4: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9a8:
	/* 0x9a8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9ad:
	/* 0x9ad: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_9b4:
	/* 0x9b4: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_9b7:
	/* 0x9b7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_9b9:
	/* 0x9b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9bc:
	/* 0x9bc: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_9c2:
	/* 0x9c2: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9c5:
	/* 0x9c5: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9ca:
	/* 0x9ca: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_9d0:
	/* 0x9d0: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9d4:
	/* 0x9d4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9d9:
	/* 0x9d9: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_9e0:
	/* 0x9e0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_9e3:
	/* 0x9e3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_9e5:
	/* 0x9e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e8:
	/* 0x9e8: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_9ee:
	/* 0x9ee: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9f1:
	/* 0x9f1: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9f6:
	/* 0x9f6: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_9fc:
	/* 0x9fc: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a00:
	/* 0xa00: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a05:
	/* 0xa05: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a0c:
	/* 0xa0c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a0f:
	/* 0xa0f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a11:
	/* 0xa11: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a14:
	/* 0xa14: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_a1a:
	/* 0xa1a: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a1d:
	/* 0xa1d: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a22:
	/* 0xa22: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_a28:
	/* 0xa28: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a2c:
	/* 0xa2c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a31:
	/* 0xa31: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a38:
	/* 0xa38: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a3b:
	/* 0xa3b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a3d:
	/* 0xa3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a40:
	/* 0xa40: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_a46:
	/* 0xa46: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a49:
	/* 0xa49: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a4e:
	/* 0xa4e: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_a54:
	/* 0xa54: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a58:
	/* 0xa58: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a5d:
	/* 0xa5d: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a64:
	/* 0xa64: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a69:
	/* 0xa69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a6c:
	/* 0xa6c: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_a72:
	/* 0xa72: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a75:
	/* 0xa75: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a7a:
	/* 0xa7a: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_a80:
	/* 0xa80: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a84:
	/* 0xa84: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a89:
	/* 0xa89: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a90:
	/* 0xa90: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a93:
	/* 0xa93: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a95:
	/* 0xa95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a98:
	/* 0xa98: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_a9e:
	/* 0xa9e: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_aa1:
	/* 0xaa1: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aa6:
	/* 0xaa6: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_aa9:
	/* 0xaa9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aae:
	/* 0xaae: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ab3:
	/* 0xab3: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ab8:
	/* 0xab8: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_abd:
	/* 0xabd: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ac2:
	/* 0xac2: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ac6:
	/* 0xac6: je     d54 <generic_fentry_process_filter+0xd54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3412ULL;
	}
x86_l_acc:
	/* 0xacc: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ad0:
	/* 0xad0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ad5:
	/* 0xad5: jmp    cfd <generic_fentry_process_filter+0xcfd> */
	return 3325ULL;
x86_l_ada:
	/* 0xada: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_add:
	/* 0xadd: jmp    d62 <generic_fentry_process_filter+0xd62> */
	return 3426ULL;
x86_l_ae2:
	/* 0xae2: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae4:
	/* 0xae4: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_ae7:
	/* 0xae7: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aec:
	/* 0xaec: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_aef:
	/* 0xaef: je     d54 <generic_fentry_process_filter+0xd54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3412ULL;
	}
x86_l_af5:
	/* 0xaf5: mov    eax,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_af8:
	/* 0xaf8: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_afb:
	/* 0xafb: je     d54 <generic_fentry_process_filter+0xd54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3412ULL;
	}
x86_l_b01:
	/* 0xb01: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b05:
	/* 0xb05: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b0a:
	/* 0xb0a: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b0f:
	/* 0xb0f: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b14:
	/* 0xb14: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b19:
	/* 0xb19: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b1d:
	/* 0xb1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b22:
	/* 0xb22: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_b29:
	/* 0xb29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2b:
	/* 0xb2b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b2e:
	/* 0xb2e: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_b34:
	/* 0xb34: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b36:
	/* 0xb36: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b3b:
	/* 0xb3b: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b3e:
	/* 0xb3e: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_b44:
	/* 0xb44: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b47:
	/* 0xb47: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b4a:
	/* 0xb4a: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_b50:
	/* 0xb50: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b54:
	/* 0xb54: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b59:
	/* 0xb59: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_b60:
	/* 0xb60: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_b63:
	/* 0xb63: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b65:
	/* 0xb65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b68:
	/* 0xb68: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_b6e:
	/* 0xb6e: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b70:
	/* 0xb70: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b75:
	/* 0xb75: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b78:
	/* 0xb78: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_b7e:
	/* 0xb7e: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b81:
	/* 0xb81: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b84:
	/* 0xb84: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_b8a:
	/* 0xb8a: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b8e:
	/* 0xb8e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b93:
	/* 0xb93: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_b9a:
	/* 0xb9a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_b9d:
	/* 0xb9d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b9f:
	/* 0xb9f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ba2:
	/* 0xba2: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_ba8:
	/* 0xba8: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_baa:
	/* 0xbaa: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_baf:
	/* 0xbaf: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_bb5:
	/* 0xbb5: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb8:
	/* 0xbb8: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bbd:
	/* 0xbbd: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_bc3:
	/* 0xbc3: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_bc7:
	/* 0xbc7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bcc:
	/* 0xbcc: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_bd3:
	/* 0xbd3: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_bd6:
	/* 0xbd6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bd8:
	/* 0xbd8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bdb:
	/* 0xbdb: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_be1:
	/* 0xbe1: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be3:
	/* 0xbe3: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_be8:
	/* 0xbe8: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_bee:
	/* 0xbee: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf1:
	/* 0xbf1: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bf6:
	/* 0xbf6: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_bfc:
	/* 0xbfc: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c00:
	/* 0xc00: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c05:
	/* 0xc05: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c0c:
	/* 0xc0c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_c0f:
	/* 0xc0f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c11:
	/* 0xc11: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c14:
	/* 0xc14: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_c1a:
	/* 0xc1a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c1c:
	/* 0xc1c: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c21:
	/* 0xc21: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_c27:
	/* 0xc27: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c2a:
	/* 0xc2a: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c2f:
	/* 0xc2f: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_c35:
	/* 0xc35: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c39:
	/* 0xc39: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c3e:
	/* 0xc3e: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c45:
	/* 0xc45: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_c48:
	/* 0xc48: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c4a:
	/* 0xc4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c4d:
	/* 0xc4d: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_c53:
	/* 0xc53: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c55:
	/* 0xc55: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c5a:
	/* 0xc5a: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_c60:
	/* 0xc60: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c63:
	/* 0xc63: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c68:
	/* 0xc68: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_c6e:
	/* 0xc6e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c72:
	/* 0xc72: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c77:
	/* 0xc77: mov    rdi,QWORD PTR [rip+0x3cc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c7e:
	/* 0xc7e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_c81:
	/* 0xc81: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c83:
	/* 0xc83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c86:
	/* 0xc86: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
x86_l_c8c:
	/* 0xc8c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8e:
	/* 0xc8e: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c93:
	/* 0xc93: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_c99:
	/* 0xc99: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c9c:
	/* 0xc9c: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ca1:
	/* 0xca1: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3380ULL;
	}
x86_l_ca7:
	/* 0xca7: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_cab:
	/* 0xcab: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cb0:
	/* 0xcb0: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_cb7:
	/* 0xcb7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_cba:
	/* 0xcba: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cbc:
	/* 0xcbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cbf:
	/* 0xcbf: je     d09 <generic_fentry_process_filter+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3337ULL;
	}
	return 3265ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3265ULL: goto x86_l_cc1;
	case 3267ULL: goto x86_l_cc3;
	case 3272ULL: goto x86_l_cc8;
	case 3274ULL: goto x86_l_cca;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3285ULL: goto x86_l_cd5;
	case 3290ULL: goto x86_l_cda;
	case 3295ULL: goto x86_l_cdf;
	case 3300ULL: goto x86_l_ce4;
	case 3305ULL: goto x86_l_ce9;
	case 3310ULL: goto x86_l_cee;
	case 3314ULL: goto x86_l_cf2;
	case 3316ULL: goto x86_l_cf4;
	case 3320ULL: goto x86_l_cf8;
	case 3325ULL: goto x86_l_cfd;
	case 3332ULL: goto x86_l_d04;
	case 3335ULL: goto x86_l_d07;
	case 3337ULL: goto x86_l_d09;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3349ULL: goto x86_l_d15;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3362ULL: goto x86_l_d22;
	case 3367ULL: goto x86_l_d27;
	case 3372ULL: goto x86_l_d2c;
	case 3376ULL: goto x86_l_d30;
	case 3378ULL: goto x86_l_d32;
	case 3380ULL: goto x86_l_d34;
	case 3383ULL: goto x86_l_d37;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3403ULL: goto x86_l_d4b;
	case 3408ULL: goto x86_l_d50;
	case 3412ULL: goto x86_l_d54;
	case 3416ULL: goto x86_l_d58;
	case 3419ULL: goto x86_l_d5b;
	case 3423ULL: goto x86_l_d5f;
	case 3426ULL: goto x86_l_d62;
	case 3430ULL: goto x86_l_d66;
	case 3434ULL: goto x86_l_d6a;
	case 3437ULL: goto x86_l_d6d;
	case 3441ULL: goto x86_l_d71;
	case 3447ULL: goto x86_l_d77;
	case 3450ULL: goto x86_l_d7a;
	case 3454ULL: goto x86_l_d7e;
	case 3460ULL: goto x86_l_d84;
	case 3462ULL: goto x86_l_d86;
	case 3465ULL: goto x86_l_d89;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3475ULL: goto x86_l_d93;
	case 3477ULL: goto x86_l_d95;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3488ULL: goto x86_l_da0;
	case 3491ULL: goto x86_l_da3;
	case 3495ULL: goto x86_l_da7;
	case 3497ULL: goto x86_l_da9;
	case 3499ULL: goto x86_l_dab;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3525ULL: goto x86_l_dc5;
	case 3529ULL: goto x86_l_dc9;
	case 3533ULL: goto x86_l_dcd;
	case 3538ULL: goto x86_l_dd2;
	case 3544ULL: goto x86_l_dd8;
	case 3550ULL: goto x86_l_dde;
	case 3552ULL: goto x86_l_de0;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3566ULL: goto x86_l_dee;
	case 3569ULL: goto x86_l_df1;
	case 3572ULL: goto x86_l_df4;
	case 3578ULL: goto x86_l_dfa;
	case 3581ULL: goto x86_l_dfd;
	case 3587ULL: goto x86_l_e03;
	case 3591ULL: goto x86_l_e07;
	case 3596ULL: goto x86_l_e0c;
	case 3601ULL: goto x86_l_e11;
	case 3606ULL: goto x86_l_e16;
	case 3611ULL: goto x86_l_e1b;
	case 3615ULL: goto x86_l_e1f;
	case 3620ULL: goto x86_l_e24;
	case 3627ULL: goto x86_l_e2b;
	case 3629ULL: goto x86_l_e2d;
	case 3632ULL: goto x86_l_e30;
	case 3638ULL: goto x86_l_e36;
	case 3641ULL: goto x86_l_e39;
	case 3646ULL: goto x86_l_e3e;
	case 3652ULL: goto x86_l_e44;
	case 3656ULL: goto x86_l_e48;
	case 3661ULL: goto x86_l_e4d;
	case 3668ULL: goto x86_l_e54;
	case 3671ULL: goto x86_l_e57;
	case 3673ULL: goto x86_l_e59;
	case 3676ULL: goto x86_l_e5c;
	case 3682ULL: goto x86_l_e62;
	case 3685ULL: goto x86_l_e65;
	case 3690ULL: goto x86_l_e6a;
	case 3696ULL: goto x86_l_e70;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3712ULL: goto x86_l_e80;
	case 3715ULL: goto x86_l_e83;
	case 3717ULL: goto x86_l_e85;
	case 3720ULL: goto x86_l_e88;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3734ULL: goto x86_l_e96;
	case 3740ULL: goto x86_l_e9c;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3761ULL: goto x86_l_eb1;
	case 3764ULL: goto x86_l_eb4;
	case 3770ULL: goto x86_l_eba;
	case 3773ULL: goto x86_l_ebd;
	case 3778ULL: goto x86_l_ec2;
	case 3784ULL: goto x86_l_ec8;
	case 3788ULL: goto x86_l_ecc;
	case 3793ULL: goto x86_l_ed1;
	case 3800ULL: goto x86_l_ed8;
	case 3803ULL: goto x86_l_edb;
	case 3805ULL: goto x86_l_edd;
	case 3808ULL: goto x86_l_ee0;
	case 3814ULL: goto x86_l_ee6;
	case 3817ULL: goto x86_l_ee9;
	case 3822ULL: goto x86_l_eee;
	case 3828ULL: goto x86_l_ef4;
	case 3832ULL: goto x86_l_ef8;
	case 3837ULL: goto x86_l_efd;
	case 3844ULL: goto x86_l_f04;
	case 3847ULL: goto x86_l_f07;
	case 3849ULL: goto x86_l_f09;
	case 3852ULL: goto x86_l_f0c;
	case 3858ULL: goto x86_l_f12;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3872ULL: goto x86_l_f20;
	case 3876ULL: goto x86_l_f24;
	case 3881ULL: goto x86_l_f29;
	case 3888ULL: goto x86_l_f30;
	case 3891ULL: goto x86_l_f33;
	case 3893ULL: goto x86_l_f35;
	case 3896ULL: goto x86_l_f38;
	case 3902ULL: goto x86_l_f3e;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3916ULL: goto x86_l_f4c;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3932ULL: goto x86_l_f5c;
	case 3935ULL: goto x86_l_f5f;
	case 3937ULL: goto x86_l_f61;
	case 3940ULL: goto x86_l_f64;
	case 3946ULL: goto x86_l_f6a;
	case 3949ULL: goto x86_l_f6d;
	case 3954ULL: goto x86_l_f72;
	case 3957ULL: goto x86_l_f75;
	case 3962ULL: goto x86_l_f7a;
	case 3967ULL: goto x86_l_f7f;
	case 3972ULL: goto x86_l_f84;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3986ULL: goto x86_l_f92;
	case 3992ULL: goto x86_l_f98;
	case 3996ULL: goto x86_l_f9c;
	case 4001ULL: goto x86_l_fa1;
	case 4006ULL: goto x86_l_fa6;
	case 4009ULL: goto x86_l_fa9;
	case 4014ULL: goto x86_l_fae;
	case 4016ULL: goto x86_l_fb0;
	case 4019ULL: goto x86_l_fb3;
	case 4024ULL: goto x86_l_fb8;
	case 4027ULL: goto x86_l_fbb;
	case 4033ULL: goto x86_l_fc1;
	case 4036ULL: goto x86_l_fc4;
	case 4039ULL: goto x86_l_fc7;
	case 4045ULL: goto x86_l_fcd;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4064ULL: goto x86_l_fe0;
	case 4069ULL: goto x86_l_fe5;
	case 4073ULL: goto x86_l_fe9;
	case 4078ULL: goto x86_l_fee;
	case 4085ULL: goto x86_l_ff5;
	case 4087ULL: goto x86_l_ff7;
	case 4090ULL: goto x86_l_ffa;
	case 4096ULL: goto x86_l_1000;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4112ULL: goto x86_l_1010;
	case 4115ULL: goto x86_l_1013;
	case 4118ULL: goto x86_l_1016;
	case 4124ULL: goto x86_l_101c;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4140ULL: goto x86_l_102c;
	case 4143ULL: goto x86_l_102f;
	case 4145ULL: goto x86_l_1031;
	case 4148ULL: goto x86_l_1034;
	case 4154ULL: goto x86_l_103a;
	case 4156ULL: goto x86_l_103c;
	case 4161ULL: goto x86_l_1041;
	case 4164ULL: goto x86_l_1044;
	case 4170ULL: goto x86_l_104a;
	case 4173ULL: goto x86_l_104d;
	case 4176ULL: goto x86_l_1050;
	case 4182ULL: goto x86_l_1056;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4198ULL: goto x86_l_1066;
	case 4201ULL: goto x86_l_1069;
	case 4203ULL: goto x86_l_106b;
	case 4206ULL: goto x86_l_106e;
	case 4212ULL: goto x86_l_1074;
	case 4214ULL: goto x86_l_1076;
	case 4219ULL: goto x86_l_107b;
	case 4225ULL: goto x86_l_1081;
	case 4228ULL: goto x86_l_1084;
	case 4233ULL: goto x86_l_1089;
	case 4239ULL: goto x86_l_108f;
	case 4243ULL: goto x86_l_1093;
	case 4248ULL: goto x86_l_1098;
	case 4255ULL: goto x86_l_109f;
	case 4258ULL: goto x86_l_10a2;
	case 4260ULL: goto x86_l_10a4;
	case 4263ULL: goto x86_l_10a7;
	case 4269ULL: goto x86_l_10ad;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4282ULL: goto x86_l_10ba;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4296ULL: goto x86_l_10c8;
	case 4300ULL: goto x86_l_10cc;
	case 4305ULL: goto x86_l_10d1;
	case 4312ULL: goto x86_l_10d8;
	case 4315ULL: goto x86_l_10db;
	case 4317ULL: goto x86_l_10dd;
	case 4320ULL: goto x86_l_10e0;
	case 4326ULL: goto x86_l_10e6;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4339ULL: goto x86_l_10f3;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4353ULL: goto x86_l_1101;
	case 4357ULL: goto x86_l_1105;
	case 4362ULL: goto x86_l_110a;
	case 4369ULL: goto x86_l_1111;
	case 4372ULL: goto x86_l_1114;
	case 4374ULL: goto x86_l_1116;
	case 4377ULL: goto x86_l_1119;
	case 4383ULL: goto x86_l_111f;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4396ULL: goto x86_l_112c;
	case 4399ULL: goto x86_l_112f;
	case 4404ULL: goto x86_l_1134;
	case 4410ULL: goto x86_l_113a;
	case 4414ULL: goto x86_l_113e;
	case 4419ULL: goto x86_l_1143;
	case 4426ULL: goto x86_l_114a;
	case 4429ULL: goto x86_l_114d;
	case 4431ULL: goto x86_l_114f;
	case 4434ULL: goto x86_l_1152;
	case 4440ULL: goto x86_l_1158;
	case 4442ULL: goto x86_l_115a;
	case 4447ULL: goto x86_l_115f;
	case 4453ULL: goto x86_l_1165;
	case 4456ULL: goto x86_l_1168;
	case 4461ULL: goto x86_l_116d;
	case 4467ULL: goto x86_l_1173;
	case 4471ULL: goto x86_l_1177;
	case 4476ULL: goto x86_l_117c;
	case 4483ULL: goto x86_l_1183;
	case 4486ULL: goto x86_l_1186;
	case 4488ULL: goto x86_l_1188;
	case 4491ULL: goto x86_l_118b;
	case 4493ULL: goto x86_l_118d;
	case 4495ULL: goto x86_l_118f;
	case 4500ULL: goto x86_l_1194;
	case 4502ULL: goto x86_l_1196;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4513ULL: goto x86_l_11a1;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4528ULL: goto x86_l_11b0;
	case 4533ULL: goto x86_l_11b5;
	case 4538ULL: goto x86_l_11ba;
	case 4542ULL: goto x86_l_11be;
	case 4544ULL: goto x86_l_11c0;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4560ULL: goto x86_l_11d0;
	case 4563ULL: goto x86_l_11d3;
	case 4565ULL: goto x86_l_11d5;
	case 4568ULL: goto x86_l_11d8;
	case 4573ULL: goto x86_l_11dd;
	case 4577ULL: goto x86_l_11e1;
	case 4580ULL: goto x86_l_11e4;
	case 4585ULL: goto x86_l_11e9;
	case 4590ULL: goto x86_l_11ee;
	case 4595ULL: goto x86_l_11f3;
	case 4600ULL: goto x86_l_11f8;
	case 4604ULL: goto x86_l_11fc;
	case 4606ULL: goto x86_l_11fe;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4621ULL: goto x86_l_120d;
	case 4626ULL: goto x86_l_1212;
	case 4631ULL: goto x86_l_1217;
	case 4636ULL: goto x86_l_121c;
	case 4640ULL: goto x86_l_1220;
	case 4644ULL: goto x86_l_1224;
	case 4647ULL: goto x86_l_1227;
	case 4651ULL: goto x86_l_122b;
	case 4654ULL: goto x86_l_122e;
	case 4658ULL: goto x86_l_1232;
	case 4661ULL: goto x86_l_1235;
	case 4665ULL: goto x86_l_1239;
	case 4671ULL: goto x86_l_123f;
	case 4674ULL: goto x86_l_1242;
	case 4678ULL: goto x86_l_1246;
	case 4684ULL: goto x86_l_124c;
	case 4686ULL: goto x86_l_124e;
	case 4688ULL: goto x86_l_1250;
	case 4690ULL: goto x86_l_1252;
	case 4693ULL: goto x86_l_1255;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4705ULL: goto x86_l_1261;
	case 4707ULL: goto x86_l_1263;
	case 4709ULL: goto x86_l_1265;
	case 4713ULL: goto x86_l_1269;
	case 4718ULL: goto x86_l_126e;
	case 4720ULL: goto x86_l_1270;
	case 4722ULL: goto x86_l_1272;
	case 4725ULL: goto x86_l_1275;
	case 4731ULL: goto x86_l_127b;
	case 4734ULL: goto x86_l_127e;
	case 4737ULL: goto x86_l_1281;
	case 4741ULL: goto x86_l_1285;
	case 4745ULL: goto x86_l_1289;
	case 4750ULL: goto x86_l_128e;
	case 4756ULL: goto x86_l_1294;
	case 4762ULL: goto x86_l_129a;
	case 4764ULL: goto x86_l_129c;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4778ULL: goto x86_l_12aa;
	case 4781ULL: goto x86_l_12ad;
	case 4784ULL: goto x86_l_12b0;
	case 4790ULL: goto x86_l_12b6;
	case 4793ULL: goto x86_l_12b9;
	case 4799ULL: goto x86_l_12bf;
	case 4803ULL: goto x86_l_12c3;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4818ULL: goto x86_l_12d2;
	case 4822ULL: goto x86_l_12d6;
	case 4827ULL: goto x86_l_12db;
	case 4834ULL: goto x86_l_12e2;
	case 4836ULL: goto x86_l_12e4;
	case 4839ULL: goto x86_l_12e7;
	case 4845ULL: goto x86_l_12ed;
	case 4848ULL: goto x86_l_12f0;
	case 4853ULL: goto x86_l_12f5;
	case 4859ULL: goto x86_l_12fb;
	case 4863ULL: goto x86_l_12ff;
	case 4868ULL: goto x86_l_1304;
	default: return 0xffffffffffffffffULL;
	}
x86_l_cc1:
	/* 0xcc1: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc3:
	/* 0xcc3: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cc8:
	/* 0xcc8: je     d34 <generic_fentry_process_filter+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d34;
	}
x86_l_cca:
	/* 0xcca: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ccd:
	/* 0xccd: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cd2:
	/* 0xcd2: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_cd5:
	/* 0xcd5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cda:
	/* 0xcda: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cdf:
	/* 0xcdf: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce4:
	/* 0xce4: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce9:
	/* 0xce9: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cee:
	/* 0xcee: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_cf2:
	/* 0xcf2: je     d54 <generic_fentry_process_filter+0xd54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d54;
	}
x86_l_cf4:
	/* 0xcf4: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_cf8:
	/* 0xcf8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cfd:
	/* 0xcfd: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_d04:
	/* 0xd04: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d07:
	/* 0xd07: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d09:
	/* 0xd09: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d0c:
	/* 0xd0c: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d11:
	/* 0xd11: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_d15:
	/* 0xd15: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_d18:
	/* 0xd18: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d1d:
	/* 0xd1d: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d22:
	/* 0xd22: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d27:
	/* 0xd27: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d2c:
	/* 0xd2c: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d30:
	/* 0xd30: jne    d54 <generic_fentry_process_filter+0xd54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d54;
	}
x86_l_d32:
	/* 0xd32: jmp    d62 <generic_fentry_process_filter+0xd62> */
	goto x86_l_d62;
x86_l_d34:
	/* 0xd34: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_d37:
	/* 0xd37: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d3c:
	/* 0xd3c: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d41:
	/* 0xd41: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d46:
	/* 0xd46: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4b:
	/* 0xd4b: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d50:
	/* 0xd50: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d54:
	/* 0xd54: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_d58:
	/* 0xd58: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_d5b:
	/* 0xd5b: xor    r12b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_d5f:
	/* 0xd5f: or     r12b,al */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_d62:
	/* 0xd62: movzx  eax,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d66:
	/* 0xd66: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d6a:
	/* 0xd6a: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_d6d:
	/* 0xd6d: lea    rax,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d71:
	/* 0xd71: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_d77:
	/* 0xd77: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d7a:
	/* 0xd7a: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_d7e:
	/* 0xd7e: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_d84:
	/* 0xd84: jbe    d90 <generic_fentry_process_filter+0xd90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d90;
	}
x86_l_d86:
	/* 0xd86: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d89:
	/* 0xd89: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d8e:
	/* 0xd8e: jmp    da3 <generic_fentry_process_filter+0xda3> */
	goto x86_l_da3;
x86_l_d90:
	/* 0xd90: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_d93:
	/* 0xd93: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_d95:
	/* 0xd95: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_d98:
	/* 0xd98: mov    edi,DWORD PTR [rdx+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_d9b:
	/* 0xd9b: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_da0:
	/* 0xda0: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_da3:
	/* 0xda3: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_da7:
	/* 0xda7: jne    dd2 <generic_fentry_process_filter+0xdd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dd2;
	}
x86_l_da9:
	/* 0xda9: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dab:
	/* 0xdab: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_daf:
	/* 0xdaf: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_db4:
	/* 0xdb4: jne    dbf <generic_fentry_process_filter+0xdbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dbf;
	}
x86_l_db6:
	/* 0xdb6: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_db9:
	/* 0xdb9: jne    fa6 <generic_fentry_process_filter+0xfa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fa6;
	}
x86_l_dbf:
	/* 0xdbf: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_dc2:
	/* 0xdc2: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_dc5:
	/* 0xdc5: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_dc9:
	/* 0xdc9: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_dcd:
	/* 0xdcd: jmp    122b <generic_fentry_process_filter+0x122b> */
	goto x86_l_122b;
x86_l_dd2:
	/* 0xdd2: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_dd8:
	/* 0xdd8: je     fae <generic_fentry_process_filter+0xfae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fae;
	}
x86_l_dde:
	/* 0xdde: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de0:
	/* 0xde0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_de3:
	/* 0xde3: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_de8:
	/* 0xde8: je     fa6 <generic_fentry_process_filter+0xfa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fa6;
	}
x86_l_dee:
	/* 0xdee: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_df1:
	/* 0xdf1: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_df4:
	/* 0xdf4: je     1220 <generic_fentry_process_filter+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1220;
	}
x86_l_dfa:
	/* 0xdfa: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_dfd:
	/* 0xdfd: je     1220 <generic_fentry_process_filter+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1220;
	}
x86_l_e03:
	/* 0xe03: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e07:
	/* 0xe07: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e0c:
	/* 0xe0c: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e11:
	/* 0xe11: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e16:
	/* 0xe16: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e1b:
	/* 0xe1b: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e1f:
	/* 0xe1f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e24:
	/* 0xe24: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_e2b:
	/* 0xe2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2d:
	/* 0xe2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e30:
	/* 0xe30: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_e36:
	/* 0xe36: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e39:
	/* 0xe39: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e3e:
	/* 0xe3e: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_e44:
	/* 0xe44: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e48:
	/* 0xe48: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e4d:
	/* 0xe4d: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_e54:
	/* 0xe54: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e57:
	/* 0xe57: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e59:
	/* 0xe59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e5c:
	/* 0xe5c: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_e62:
	/* 0xe62: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e65:
	/* 0xe65: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e6a:
	/* 0xe6a: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_e70:
	/* 0xe70: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e74:
	/* 0xe74: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e79:
	/* 0xe79: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_e80:
	/* 0xe80: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e83:
	/* 0xe83: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e85:
	/* 0xe85: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e88:
	/* 0xe88: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_e8e:
	/* 0xe8e: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e91:
	/* 0xe91: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e96:
	/* 0xe96: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_e9c:
	/* 0xe9c: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ea0:
	/* 0xea0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ea5:
	/* 0xea5: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_eac:
	/* 0xeac: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_eaf:
	/* 0xeaf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_eb1:
	/* 0xeb1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eb4:
	/* 0xeb4: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_eba:
	/* 0xeba: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ebd:
	/* 0xebd: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ec2:
	/* 0xec2: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_ec8:
	/* 0xec8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ecc:
	/* 0xecc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ed1:
	/* 0xed1: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ed8:
	/* 0xed8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_edb:
	/* 0xedb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_edd:
	/* 0xedd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ee0:
	/* 0xee0: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_ee6:
	/* 0xee6: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ee9:
	/* 0xee9: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_eee:
	/* 0xeee: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_ef4:
	/* 0xef4: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ef8:
	/* 0xef8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_efd:
	/* 0xefd: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f04:
	/* 0xf04: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f07:
	/* 0xf07: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f09:
	/* 0xf09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0c:
	/* 0xf0c: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_f12:
	/* 0xf12: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f15:
	/* 0xf15: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f1a:
	/* 0xf1a: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_f20:
	/* 0xf20: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f24:
	/* 0xf24: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f29:
	/* 0xf29: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f30:
	/* 0xf30: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f33:
	/* 0xf33: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f35:
	/* 0xf35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f38:
	/* 0xf38: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_f3e:
	/* 0xf3e: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f41:
	/* 0xf41: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f46:
	/* 0xf46: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_f4c:
	/* 0xf4c: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f50:
	/* 0xf50: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f55:
	/* 0xf55: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f5c:
	/* 0xf5c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f5f:
	/* 0xf5f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f61:
	/* 0xf61: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f64:
	/* 0xf64: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_f6a:
	/* 0xf6a: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f6d:
	/* 0xf6d: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f72:
	/* 0xf72: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_f75:
	/* 0xf75: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f7a:
	/* 0xf7a: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f7f:
	/* 0xf7f: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f84:
	/* 0xf84: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f89:
	/* 0xf89: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f8e:
	/* 0xf8e: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f92:
	/* 0xf92: je     1220 <generic_fentry_process_filter+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1220;
	}
x86_l_f98:
	/* 0xf98: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f9c:
	/* 0xf9c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fa1:
	/* 0xfa1: jmp    11c9 <generic_fentry_process_filter+0x11c9> */
	goto x86_l_11c9;
x86_l_fa6:
	/* 0xfa6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fa9:
	/* 0xfa9: jmp    122e <generic_fentry_process_filter+0x122e> */
	goto x86_l_122e;
x86_l_fae:
	/* 0xfae: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb0:
	/* 0xfb0: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_fb3:
	/* 0xfb3: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fb8:
	/* 0xfb8: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_fbb:
	/* 0xfbb: je     1220 <generic_fentry_process_filter+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1220;
	}
x86_l_fc1:
	/* 0xfc1: mov    eax,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fc4:
	/* 0xfc4: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_fc7:
	/* 0xfc7: je     1220 <generic_fentry_process_filter+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1220;
	}
x86_l_fcd:
	/* 0xfcd: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fd1:
	/* 0xfd1: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd6:
	/* 0xfd6: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fdb:
	/* 0xfdb: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe0:
	/* 0xfe0: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fe5:
	/* 0xfe5: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe9:
	/* 0xfe9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fee:
	/* 0xfee: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ff5:
	/* 0xff5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff7:
	/* 0xff7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ffa:
	/* 0xffa: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_1000:
	/* 0x1000: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1002:
	/* 0x1002: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1007:
	/* 0x1007: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_100a:
	/* 0x100a: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_1010:
	/* 0x1010: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1013:
	/* 0x1013: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1016:
	/* 0x1016: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_101c:
	/* 0x101c: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1020:
	/* 0x1020: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1025:
	/* 0x1025: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_102c:
	/* 0x102c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_102f:
	/* 0x102f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1031:
	/* 0x1031: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1034:
	/* 0x1034: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_103a:
	/* 0x103a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_103c:
	/* 0x103c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1041:
	/* 0x1041: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1044:
	/* 0x1044: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_104a:
	/* 0x104a: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_104d:
	/* 0x104d: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1050:
	/* 0x1050: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_1056:
	/* 0x1056: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_105a:
	/* 0x105a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_105f:
	/* 0x105f: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1066:
	/* 0x1066: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1069:
	/* 0x1069: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_106b:
	/* 0x106b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_106e:
	/* 0x106e: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_1074:
	/* 0x1074: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1076:
	/* 0x1076: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_107b:
	/* 0x107b: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_1081:
	/* 0x1081: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1084:
	/* 0x1084: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1089:
	/* 0x1089: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_108f:
	/* 0x108f: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1093:
	/* 0x1093: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1098:
	/* 0x1098: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_109f:
	/* 0x109f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_10a2:
	/* 0x10a2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10a4:
	/* 0x10a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10a7:
	/* 0x10a7: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_10ad:
	/* 0x10ad: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10af:
	/* 0x10af: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10b4:
	/* 0x10b4: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_10ba:
	/* 0x10ba: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10bd:
	/* 0x10bd: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10c2:
	/* 0x10c2: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_10c8:
	/* 0x10c8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10cc:
	/* 0x10cc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10d1:
	/* 0x10d1: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_10d8:
	/* 0x10d8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_10db:
	/* 0x10db: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10dd:
	/* 0x10dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10e0:
	/* 0x10e0: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_10e6:
	/* 0x10e6: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e8:
	/* 0x10e8: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10ed:
	/* 0x10ed: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_10f3:
	/* 0x10f3: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f6:
	/* 0x10f6: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10fb:
	/* 0x10fb: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_1101:
	/* 0x1101: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1105:
	/* 0x1105: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_110a:
	/* 0x110a: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1111:
	/* 0x1111: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1114:
	/* 0x1114: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1116:
	/* 0x1116: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1119:
	/* 0x1119: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_111f:
	/* 0x111f: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1121:
	/* 0x1121: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1126:
	/* 0x1126: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_112c:
	/* 0x112c: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_112f:
	/* 0x112f: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1134:
	/* 0x1134: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_113a:
	/* 0x113a: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_113e:
	/* 0x113e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1143:
	/* 0x1143: mov    rdi,QWORD PTR [rip+0x3cc3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_114a:
	/* 0x114a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_114d:
	/* 0x114d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_114f:
	/* 0x114f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1152:
	/* 0x1152: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_1158:
	/* 0x1158: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115a:
	/* 0x115a: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_115f:
	/* 0x115f: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_1165:
	/* 0x1165: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1168:
	/* 0x1168: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_116d:
	/* 0x116d: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_1173:
	/* 0x1173: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1177:
	/* 0x1177: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_117c:
	/* 0x117c: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1183:
	/* 0x1183: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1186:
	/* 0x1186: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1188:
	/* 0x1188: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_118b:
	/* 0x118b: je     11d5 <generic_fentry_process_filter+0x11d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d5;
	}
x86_l_118d:
	/* 0x118d: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_118f:
	/* 0x118f: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1194:
	/* 0x1194: je     1200 <generic_fentry_process_filter+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1200;
	}
x86_l_1196:
	/* 0x1196: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1199:
	/* 0x1199: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_119e:
	/* 0x119e: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_11a1:
	/* 0x11a1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11a6:
	/* 0x11a6: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ab:
	/* 0x11ab: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b0:
	/* 0x11b0: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11b5:
	/* 0x11b5: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11ba:
	/* 0x11ba: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11be:
	/* 0x11be: je     1220 <generic_fentry_process_filter+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1220;
	}
x86_l_11c0:
	/* 0x11c0: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11c4:
	/* 0x11c4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11c9:
	/* 0x11c9: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_11d0:
	/* 0x11d0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_11d3:
	/* 0x11d3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11d5:
	/* 0x11d5: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11d8:
	/* 0x11d8: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11dd:
	/* 0x11dd: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_11e1:
	/* 0x11e1: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_11e4:
	/* 0x11e4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11e9:
	/* 0x11e9: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ee:
	/* 0x11ee: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11f3:
	/* 0x11f3: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11f8:
	/* 0x11f8: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11fc:
	/* 0x11fc: jne    1220 <generic_fentry_process_filter+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1220;
	}
x86_l_11fe:
	/* 0x11fe: jmp    122e <generic_fentry_process_filter+0x122e> */
	goto x86_l_122e;
x86_l_1200:
	/* 0x1200: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1203:
	/* 0x1203: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1208:
	/* 0x1208: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_120d:
	/* 0x120d: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1212:
	/* 0x1212: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1217:
	/* 0x1217: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_121c:
	/* 0x121c: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1220:
	/* 0x1220: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1224:
	/* 0x1224: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1227:
	/* 0x1227: xor    r12b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_122b:
	/* 0x122b: or     r12b,al */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_122e:
	/* 0x122e: movzx  r12d,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1232:
	/* 0x1232: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1235:
	/* 0x1235: lea    rax,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1239:
	/* 0x1239: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_123f:
	/* 0x123f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1242:
	/* 0x1242: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_1246:
	/* 0x1246: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_124c:
	/* 0x124c: jbe    1252 <generic_fentry_process_filter+0x1252> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1252;
	}
x86_l_124e:
	/* 0x124e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1250:
	/* 0x1250: jmp    1258 <generic_fentry_process_filter+0x1258> */
	goto x86_l_1258;
x86_l_1252:
	/* 0x1252: and    ebp,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1255:
	/* 0x1255: mov    ebp,DWORD PTR [rdx+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1258:
	/* 0x1258: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_125d:
	/* 0x125d: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_1261:
	/* 0x1261: jne    128e <generic_fentry_process_filter+0x128e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_128e;
	}
x86_l_1263:
	/* 0x1263: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1265:
	/* 0x1265: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1269:
	/* 0x1269: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_126e:
	/* 0x126e: jne    127b <generic_fentry_process_filter+0x127b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_127b;
	}
x86_l_1270:
	/* 0x1270: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1272:
	/* 0x1272: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1275:
	/* 0x1275: jne    16da <generic_fentry_process_filter+0x16da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5850ULL;
	}
x86_l_127b:
	/* 0x127b: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_127e:
	/* 0x127e: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1281:
	/* 0x1281: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1285:
	/* 0x1285: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1289:
	/* 0x1289: jmp    16c1 <generic_fentry_process_filter+0x16c1> */
	return 5825ULL;
x86_l_128e:
	/* 0x128e: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1294:
	/* 0x1294: je     1458 <generic_fentry_process_filter+0x1458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5208ULL;
	}
x86_l_129a:
	/* 0x129a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_129c:
	/* 0x129c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_129f:
	/* 0x129f: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12a4:
	/* 0x12a4: je     1697 <generic_fentry_process_filter+0x1697> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5783ULL;
	}
x86_l_12aa:
	/* 0x12aa: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_12ad:
	/* 0x12ad: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_12b0:
	/* 0x12b0: je     16b6 <generic_fentry_process_filter+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5814ULL;
	}
x86_l_12b6:
	/* 0x12b6: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_12b9:
	/* 0x12b9: je     16b6 <generic_fentry_process_filter+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5814ULL;
	}
x86_l_12bf:
	/* 0x12bf: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12c3:
	/* 0x12c3: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12c8:
	/* 0x12c8: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12cd:
	/* 0x12cd: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12d2:
	/* 0x12d2: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d6:
	/* 0x12d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12db:
	/* 0x12db: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_12e2:
	/* 0x12e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e4:
	/* 0x12e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12e7:
	/* 0x12e7: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5746ULL;
	}
x86_l_12ed:
	/* 0x12ed: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12f0:
	/* 0x12f0: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12f5:
	/* 0x12f5: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5787ULL;
	}
x86_l_12fb:
	/* 0x12fb: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_12ff:
	/* 0x12ff: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1304:
	/* 0x1304: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
	return 4875ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4875ULL: goto x86_l_130b;
	case 4878ULL: goto x86_l_130e;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4889ULL: goto x86_l_1319;
	case 4892ULL: goto x86_l_131c;
	case 4897ULL: goto x86_l_1321;
	case 4903ULL: goto x86_l_1327;
	case 4907ULL: goto x86_l_132b;
	case 4912ULL: goto x86_l_1330;
	case 4919ULL: goto x86_l_1337;
	case 4922ULL: goto x86_l_133a;
	case 4924ULL: goto x86_l_133c;
	case 4927ULL: goto x86_l_133f;
	case 4933ULL: goto x86_l_1345;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	case 4947ULL: goto x86_l_1353;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4963ULL: goto x86_l_1363;
	case 4966ULL: goto x86_l_1366;
	case 4968ULL: goto x86_l_1368;
	case 4971ULL: goto x86_l_136b;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4991ULL: goto x86_l_137f;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5007ULL: goto x86_l_138f;
	case 5010ULL: goto x86_l_1392;
	case 5012ULL: goto x86_l_1394;
	case 5015ULL: goto x86_l_1397;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5035ULL: goto x86_l_13ab;
	case 5039ULL: goto x86_l_13af;
	case 5044ULL: goto x86_l_13b4;
	case 5051ULL: goto x86_l_13bb;
	case 5054ULL: goto x86_l_13be;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5065ULL: goto x86_l_13c9;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5079ULL: goto x86_l_13d7;
	case 5083ULL: goto x86_l_13db;
	case 5088ULL: goto x86_l_13e0;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5100ULL: goto x86_l_13ec;
	case 5103ULL: goto x86_l_13ef;
	case 5109ULL: goto x86_l_13f5;
	case 5112ULL: goto x86_l_13f8;
	case 5117ULL: goto x86_l_13fd;
	case 5123ULL: goto x86_l_1403;
	case 5127ULL: goto x86_l_1407;
	case 5132ULL: goto x86_l_140c;
	case 5139ULL: goto x86_l_1413;
	case 5142ULL: goto x86_l_1416;
	case 5144ULL: goto x86_l_1418;
	case 5147ULL: goto x86_l_141b;
	case 5153ULL: goto x86_l_1421;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5174ULL: goto x86_l_1436;
	case 5179ULL: goto x86_l_143b;
	case 5184ULL: goto x86_l_1440;
	case 5188ULL: goto x86_l_1444;
	case 5194ULL: goto x86_l_144a;
	case 5198ULL: goto x86_l_144e;
	case 5203ULL: goto x86_l_1453;
	case 5208ULL: goto x86_l_1458;
	case 5210ULL: goto x86_l_145a;
	case 5213ULL: goto x86_l_145d;
	case 5218ULL: goto x86_l_1462;
	case 5221ULL: goto x86_l_1465;
	case 5227ULL: goto x86_l_146b;
	case 5230ULL: goto x86_l_146e;
	case 5233ULL: goto x86_l_1471;
	case 5239ULL: goto x86_l_1477;
	case 5243ULL: goto x86_l_147b;
	case 5248ULL: goto x86_l_1480;
	case 5253ULL: goto x86_l_1485;
	case 5258ULL: goto x86_l_148a;
	case 5262ULL: goto x86_l_148e;
	case 5267ULL: goto x86_l_1493;
	case 5274ULL: goto x86_l_149a;
	case 5276ULL: goto x86_l_149c;
	case 5279ULL: goto x86_l_149f;
	case 5285ULL: goto x86_l_14a5;
	case 5287ULL: goto x86_l_14a7;
	case 5292ULL: goto x86_l_14ac;
	case 5295ULL: goto x86_l_14af;
	case 5301ULL: goto x86_l_14b5;
	case 5304ULL: goto x86_l_14b8;
	case 5307ULL: goto x86_l_14bb;
	case 5313ULL: goto x86_l_14c1;
	case 5317ULL: goto x86_l_14c5;
	case 5322ULL: goto x86_l_14ca;
	case 5329ULL: goto x86_l_14d1;
	case 5332ULL: goto x86_l_14d4;
	case 5334ULL: goto x86_l_14d6;
	case 5337ULL: goto x86_l_14d9;
	case 5343ULL: goto x86_l_14df;
	case 5345ULL: goto x86_l_14e1;
	case 5350ULL: goto x86_l_14e6;
	case 5353ULL: goto x86_l_14e9;
	case 5359ULL: goto x86_l_14ef;
	case 5362ULL: goto x86_l_14f2;
	case 5365ULL: goto x86_l_14f5;
	case 5371ULL: goto x86_l_14fb;
	case 5375ULL: goto x86_l_14ff;
	case 5380ULL: goto x86_l_1504;
	case 5387ULL: goto x86_l_150b;
	case 5390ULL: goto x86_l_150e;
	case 5392ULL: goto x86_l_1510;
	case 5395ULL: goto x86_l_1513;
	case 5401ULL: goto x86_l_1519;
	case 5403ULL: goto x86_l_151b;
	case 5408ULL: goto x86_l_1520;
	case 5411ULL: goto x86_l_1523;
	case 5417ULL: goto x86_l_1529;
	case 5420ULL: goto x86_l_152c;
	case 5423ULL: goto x86_l_152f;
	case 5429ULL: goto x86_l_1535;
	case 5433ULL: goto x86_l_1539;
	case 5438ULL: goto x86_l_153e;
	case 5445ULL: goto x86_l_1545;
	case 5448ULL: goto x86_l_1548;
	case 5450ULL: goto x86_l_154a;
	case 5453ULL: goto x86_l_154d;
	case 5459ULL: goto x86_l_1553;
	case 5461ULL: goto x86_l_1555;
	case 5466ULL: goto x86_l_155a;
	case 5472ULL: goto x86_l_1560;
	case 5475ULL: goto x86_l_1563;
	case 5480ULL: goto x86_l_1568;
	case 5486ULL: goto x86_l_156e;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5502ULL: goto x86_l_157e;
	case 5505ULL: goto x86_l_1581;
	case 5507ULL: goto x86_l_1583;
	case 5510ULL: goto x86_l_1586;
	case 5516ULL: goto x86_l_158c;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5529ULL: goto x86_l_1599;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5543ULL: goto x86_l_15a7;
	case 5547ULL: goto x86_l_15ab;
	case 5552ULL: goto x86_l_15b0;
	case 5559ULL: goto x86_l_15b7;
	case 5562ULL: goto x86_l_15ba;
	case 5564ULL: goto x86_l_15bc;
	case 5567ULL: goto x86_l_15bf;
	case 5573ULL: goto x86_l_15c5;
	case 5575ULL: goto x86_l_15c7;
	case 5580ULL: goto x86_l_15cc;
	case 5586ULL: goto x86_l_15d2;
	case 5589ULL: goto x86_l_15d5;
	case 5594ULL: goto x86_l_15da;
	case 5600ULL: goto x86_l_15e0;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5621ULL: goto x86_l_15f5;
	case 5624ULL: goto x86_l_15f8;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5633ULL: goto x86_l_1601;
	case 5639ULL: goto x86_l_1607;
	case 5642ULL: goto x86_l_160a;
	case 5647ULL: goto x86_l_160f;
	case 5653ULL: goto x86_l_1615;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5669ULL: goto x86_l_1625;
	case 5672ULL: goto x86_l_1628;
	case 5674ULL: goto x86_l_162a;
	case 5677ULL: goto x86_l_162d;
	case 5679ULL: goto x86_l_162f;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5688ULL: goto x86_l_1638;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5699ULL: goto x86_l_1643;
	case 5704ULL: goto x86_l_1648;
	case 5709ULL: goto x86_l_164d;
	case 5714ULL: goto x86_l_1652;
	case 5719ULL: goto x86_l_1657;
	case 5723ULL: goto x86_l_165b;
	case 5725ULL: goto x86_l_165d;
	case 5729ULL: goto x86_l_1661;
	case 5734ULL: goto x86_l_1666;
	case 5741ULL: goto x86_l_166d;
	case 5744ULL: goto x86_l_1670;
	case 5746ULL: goto x86_l_1672;
	case 5748ULL: goto x86_l_1674;
	case 5753ULL: goto x86_l_1679;
	case 5757ULL: goto x86_l_167d;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5770ULL: goto x86_l_168a;
	case 5775ULL: goto x86_l_168f;
	case 5779ULL: goto x86_l_1693;
	case 5781ULL: goto x86_l_1695;
	case 5783ULL: goto x86_l_1697;
	case 5785ULL: goto x86_l_1699;
	case 5787ULL: goto x86_l_169b;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5814ULL: goto x86_l_16b6;
	case 5818ULL: goto x86_l_16ba;
	case 5821ULL: goto x86_l_16bd;
	case 5825ULL: goto x86_l_16c1;
	case 5828ULL: goto x86_l_16c4;
	case 5832ULL: goto x86_l_16c8;
	case 5836ULL: goto x86_l_16cc;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5845ULL: goto x86_l_16d5;
	case 5848ULL: goto x86_l_16d8;
	case 5850ULL: goto x86_l_16da;
	case 5854ULL: goto x86_l_16de;
	case 5857ULL: goto x86_l_16e1;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5881ULL: goto x86_l_16f9;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5892ULL: goto x86_l_1704;
	case 5896ULL: goto x86_l_1708;
	case 5899ULL: goto x86_l_170b;
	case 5905ULL: goto x86_l_1711;
	case 5911ULL: goto x86_l_1717;
	case 5915ULL: goto x86_l_171b;
	case 5919ULL: goto x86_l_171f;
	case 5924ULL: goto x86_l_1724;
	case 5928ULL: goto x86_l_1728;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5938ULL: goto x86_l_1732;
	case 5940ULL: goto x86_l_1734;
	case 5945ULL: goto x86_l_1739;
	case 5948ULL: goto x86_l_173c;
	case 5955ULL: goto x86_l_1743;
	case 5957ULL: goto x86_l_1745;
	case 5960ULL: goto x86_l_1748;
	case 5963ULL: goto x86_l_174b;
	case 5966ULL: goto x86_l_174e;
	case 5969ULL: goto x86_l_1751;
	case 5973ULL: goto x86_l_1755;
	case 5977ULL: goto x86_l_1759;
	case 5979ULL: goto x86_l_175b;
	case 5984ULL: goto x86_l_1760;
	case 5988ULL: goto x86_l_1764;
	case 5990ULL: goto x86_l_1766;
	case 5993ULL: goto x86_l_1769;
	case 5995ULL: goto x86_l_176b;
	case 5998ULL: goto x86_l_176e;
	case 6001ULL: goto x86_l_1771;
	case 6005ULL: goto x86_l_1775;
	case 6007ULL: goto x86_l_1777;
	case 6010ULL: goto x86_l_177a;
	case 6014ULL: goto x86_l_177e;
	case 6018ULL: goto x86_l_1782;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6033ULL: goto x86_l_1791;
	case 6035ULL: goto x86_l_1793;
	case 6038ULL: goto x86_l_1796;
	case 6042ULL: goto x86_l_179a;
	case 6046ULL: goto x86_l_179e;
	case 6048ULL: goto x86_l_17a0;
	case 6050ULL: goto x86_l_17a2;
	case 6052ULL: goto x86_l_17a4;
	case 6056ULL: goto x86_l_17a8;
	case 6060ULL: goto x86_l_17ac;
	case 6063ULL: goto x86_l_17af;
	case 6069ULL: goto x86_l_17b5;
	case 6072ULL: goto x86_l_17b8;
	case 6078ULL: goto x86_l_17be;
	case 6081ULL: goto x86_l_17c1;
	case 6084ULL: goto x86_l_17c4;
	case 6090ULL: goto x86_l_17ca;
	case 6092ULL: goto x86_l_17cc;
	case 6095ULL: goto x86_l_17cf;
	case 6098ULL: goto x86_l_17d2;
	case 6101ULL: goto x86_l_17d5;
	case 6104ULL: goto x86_l_17d8;
	case 6108ULL: goto x86_l_17dc;
	case 6112ULL: goto x86_l_17e0;
	case 6114ULL: goto x86_l_17e2;
	case 6119ULL: goto x86_l_17e7;
	case 6123ULL: goto x86_l_17eb;
	case 6125ULL: goto x86_l_17ed;
	case 6127ULL: goto x86_l_17ef;
	case 6129ULL: goto x86_l_17f1;
	case 6131ULL: goto x86_l_17f3;
	case 6134ULL: goto x86_l_17f6;
	case 6137ULL: goto x86_l_17f9;
	case 6140ULL: goto x86_l_17fc;
	case 6142ULL: goto x86_l_17fe;
	case 6146ULL: goto x86_l_1802;
	case 6150ULL: goto x86_l_1806;
	case 6152ULL: goto x86_l_1808;
	case 6157ULL: goto x86_l_180d;
	case 6164ULL: goto x86_l_1814;
	case 6166ULL: goto x86_l_1816;
	case 6169ULL: goto x86_l_1819;
	case 6172ULL: goto x86_l_181c;
	case 6175ULL: goto x86_l_181f;
	case 6178ULL: goto x86_l_1822;
	case 6182ULL: goto x86_l_1826;
	case 6186ULL: goto x86_l_182a;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6197ULL: goto x86_l_1835;
	case 6199ULL: goto x86_l_1837;
	case 6202ULL: goto x86_l_183a;
	case 6204ULL: goto x86_l_183c;
	case 6207ULL: goto x86_l_183f;
	case 6210ULL: goto x86_l_1842;
	case 6214ULL: goto x86_l_1846;
	case 6216ULL: goto x86_l_1848;
	case 6219ULL: goto x86_l_184b;
	case 6223ULL: goto x86_l_184f;
	case 6227ULL: goto x86_l_1853;
	case 6230ULL: goto x86_l_1856;
	case 6235ULL: goto x86_l_185b;
	case 6242ULL: goto x86_l_1862;
	case 6244ULL: goto x86_l_1864;
	case 6248ULL: goto x86_l_1868;
	case 6252ULL: goto x86_l_186c;
	case 6256ULL: goto x86_l_1870;
	case 6260ULL: goto x86_l_1874;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6271ULL: goto x86_l_187f;
	case 6273ULL: goto x86_l_1881;
	case 6276ULL: goto x86_l_1884;
	case 6279ULL: goto x86_l_1887;
	case 6281ULL: goto x86_l_1889;
	case 6284ULL: goto x86_l_188c;
	case 6287ULL: goto x86_l_188f;
	case 6291ULL: goto x86_l_1893;
	case 6294ULL: goto x86_l_1896;
	case 6297ULL: goto x86_l_1899;
	case 6301ULL: goto x86_l_189d;
	case 6305ULL: goto x86_l_18a1;
	case 6307ULL: goto x86_l_18a3;
	case 6310ULL: goto x86_l_18a6;
	case 6313ULL: goto x86_l_18a9;
	case 6315ULL: goto x86_l_18ab;
	case 6317ULL: goto x86_l_18ad;
	case 6320ULL: goto x86_l_18b0;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6327ULL: goto x86_l_18b7;
	case 6333ULL: goto x86_l_18bd;
	case 6336ULL: goto x86_l_18c0;
	case 6338ULL: goto x86_l_18c2;
	case 6341ULL: goto x86_l_18c5;
	case 6344ULL: goto x86_l_18c8;
	case 6349ULL: goto x86_l_18cd;
	case 6352ULL: goto x86_l_18d0;
	case 6354ULL: goto x86_l_18d2;
	case 6360ULL: goto x86_l_18d8;
	case 6362ULL: goto x86_l_18da;
	default: return 0xffffffffffffffffULL;
	}
x86_l_130b:
	/* 0x130b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_130e:
	/* 0x130e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1310:
	/* 0x1310: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1313:
	/* 0x1313: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_1319:
	/* 0x1319: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_131c:
	/* 0x131c: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1321:
	/* 0x1321: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1327:
	/* 0x1327: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_132b:
	/* 0x132b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1330:
	/* 0x1330: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1337:
	/* 0x1337: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_133a:
	/* 0x133a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_133c:
	/* 0x133c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_133f:
	/* 0x133f: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_1345:
	/* 0x1345: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1348:
	/* 0x1348: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_134d:
	/* 0x134d: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1353:
	/* 0x1353: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1357:
	/* 0x1357: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_135c:
	/* 0x135c: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1363:
	/* 0x1363: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1366:
	/* 0x1366: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1368:
	/* 0x1368: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_136b:
	/* 0x136b: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_1371:
	/* 0x1371: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1374:
	/* 0x1374: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1379:
	/* 0x1379: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_137f:
	/* 0x137f: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1383:
	/* 0x1383: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1388:
	/* 0x1388: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_138f:
	/* 0x138f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1392:
	/* 0x1392: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1394:
	/* 0x1394: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1397:
	/* 0x1397: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_139d:
	/* 0x139d: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13a0:
	/* 0x13a0: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13a5:
	/* 0x13a5: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_13ab:
	/* 0x13ab: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13af:
	/* 0x13af: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13b4:
	/* 0x13b4: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_13bb:
	/* 0x13bb: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13be:
	/* 0x13be: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13c0:
	/* 0x13c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13c3:
	/* 0x13c3: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_13c9:
	/* 0x13c9: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13cc:
	/* 0x13cc: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13d1:
	/* 0x13d1: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_13d7:
	/* 0x13d7: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13db:
	/* 0x13db: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13e0:
	/* 0x13e0: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_13e7:
	/* 0x13e7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13ea:
	/* 0x13ea: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13ec:
	/* 0x13ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13ef:
	/* 0x13ef: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_13f5:
	/* 0x13f5: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13f8:
	/* 0x13f8: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13fd:
	/* 0x13fd: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1403:
	/* 0x1403: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1407:
	/* 0x1407: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_140c:
	/* 0x140c: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1413:
	/* 0x1413: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1416:
	/* 0x1416: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1418:
	/* 0x1418: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_141b:
	/* 0x141b: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_1421:
	/* 0x1421: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1424:
	/* 0x1424: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1429:
	/* 0x1429: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_142c:
	/* 0x142c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1431:
	/* 0x1431: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1436:
	/* 0x1436: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_143b:
	/* 0x143b: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1440:
	/* 0x1440: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1444:
	/* 0x1444: je     16b6 <generic_fentry_process_filter+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16b6;
	}
x86_l_144a:
	/* 0x144a: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_144e:
	/* 0x144e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1453:
	/* 0x1453: jmp    1666 <generic_fentry_process_filter+0x1666> */
	goto x86_l_1666;
x86_l_1458:
	/* 0x1458: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_145a:
	/* 0x145a: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_145d:
	/* 0x145d: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1462:
	/* 0x1462: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1465:
	/* 0x1465: je     16b6 <generic_fentry_process_filter+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16b6;
	}
x86_l_146b:
	/* 0x146b: mov    eax,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_146e:
	/* 0x146e: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1471:
	/* 0x1471: je     16b6 <generic_fentry_process_filter+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16b6;
	}
x86_l_1477:
	/* 0x1477: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_147b:
	/* 0x147b: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1480:
	/* 0x1480: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1485:
	/* 0x1485: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_148a:
	/* 0x148a: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_148e:
	/* 0x148e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1493:
	/* 0x1493: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_149a:
	/* 0x149a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149c:
	/* 0x149c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_149f:
	/* 0x149f: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_14a5:
	/* 0x14a5: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a7:
	/* 0x14a7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14ac:
	/* 0x14ac: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_14af:
	/* 0x14af: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_14b5:
	/* 0x14b5: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b8:
	/* 0x14b8: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_14bb:
	/* 0x14bb: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_14c1:
	/* 0x14c1: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14c5:
	/* 0x14c5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14ca:
	/* 0x14ca: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_14d1:
	/* 0x14d1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_14d4:
	/* 0x14d4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14d6:
	/* 0x14d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14d9:
	/* 0x14d9: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_14df:
	/* 0x14df: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e1:
	/* 0x14e1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14e6:
	/* 0x14e6: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_14e9:
	/* 0x14e9: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_14ef:
	/* 0x14ef: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14f2:
	/* 0x14f2: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_14f5:
	/* 0x14f5: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_14fb:
	/* 0x14fb: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14ff:
	/* 0x14ff: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1504:
	/* 0x1504: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_150b:
	/* 0x150b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_150e:
	/* 0x150e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1510:
	/* 0x1510: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1513:
	/* 0x1513: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_1519:
	/* 0x1519: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151b:
	/* 0x151b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1520:
	/* 0x1520: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1523:
	/* 0x1523: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1529:
	/* 0x1529: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_152c:
	/* 0x152c: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_152f:
	/* 0x152f: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1535:
	/* 0x1535: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1539:
	/* 0x1539: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_153e:
	/* 0x153e: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1545:
	/* 0x1545: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1548:
	/* 0x1548: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_154a:
	/* 0x154a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154d:
	/* 0x154d: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_1553:
	/* 0x1553: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1555:
	/* 0x1555: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_155a:
	/* 0x155a: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1560:
	/* 0x1560: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1563:
	/* 0x1563: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1568:
	/* 0x1568: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_156e:
	/* 0x156e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1572:
	/* 0x1572: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1577:
	/* 0x1577: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_157e:
	/* 0x157e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1581:
	/* 0x1581: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1583:
	/* 0x1583: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1586:
	/* 0x1586: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_158c:
	/* 0x158c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158e:
	/* 0x158e: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1593:
	/* 0x1593: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1599:
	/* 0x1599: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_159c:
	/* 0x159c: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15a1:
	/* 0x15a1: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_15a7:
	/* 0x15a7: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15ab:
	/* 0x15ab: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15b0:
	/* 0x15b0: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_15b7:
	/* 0x15b7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_15ba:
	/* 0x15ba: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15bc:
	/* 0x15bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15bf:
	/* 0x15bf: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_15c5:
	/* 0x15c5: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c7:
	/* 0x15c7: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15cc:
	/* 0x15cc: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_15d2:
	/* 0x15d2: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d5:
	/* 0x15d5: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15da:
	/* 0x15da: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_15e0:
	/* 0x15e0: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15e4:
	/* 0x15e4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15e9:
	/* 0x15e9: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_15f0:
	/* 0x15f0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_15f3:
	/* 0x15f3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15f5:
	/* 0x15f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15f8:
	/* 0x15f8: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_15fa:
	/* 0x15fa: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15fc:
	/* 0x15fc: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1601:
	/* 0x1601: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1607:
	/* 0x1607: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_160a:
	/* 0x160a: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_160f:
	/* 0x160f: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1615:
	/* 0x1615: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1619:
	/* 0x1619: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_161e:
	/* 0x161e: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1625:
	/* 0x1625: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1628:
	/* 0x1628: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_162a:
	/* 0x162a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_162d:
	/* 0x162d: je     1672 <generic_fentry_process_filter+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_162f:
	/* 0x162f: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1631:
	/* 0x1631: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1636:
	/* 0x1636: je     169b <generic_fentry_process_filter+0x169b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_169b;
	}
x86_l_1638:
	/* 0x1638: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_163b:
	/* 0x163b: cmp    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1640:
	/* 0x1640: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1643:
	/* 0x1643: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1648:
	/* 0x1648: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_164d:
	/* 0x164d: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1652:
	/* 0x1652: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1657:
	/* 0x1657: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_165b:
	/* 0x165b: je     16b6 <generic_fentry_process_filter+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16b6;
	}
x86_l_165d:
	/* 0x165d: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1661:
	/* 0x1661: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1666:
	/* 0x1666: mov    rdi,QWORD PTR [rip+0x3cbf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_166d:
	/* 0x166d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1670:
	/* 0x1670: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1672:
	/* 0x1672: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1674:
	/* 0x1674: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1679:
	/* 0x1679: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_167d:
	/* 0x167d: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1680:
	/* 0x1680: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1685:
	/* 0x1685: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_168a:
	/* 0x168a: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_168f:
	/* 0x168f: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1693:
	/* 0x1693: jne    16b6 <generic_fentry_process_filter+0x16b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16b6;
	}
x86_l_1695:
	/* 0x1695: jmp    16da <generic_fentry_process_filter+0x16da> */
	goto x86_l_16da;
x86_l_1697:
	/* 0x1697: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1699:
	/* 0x1699: jmp    16c4 <generic_fentry_process_filter+0x16c4> */
	goto x86_l_16c4;
x86_l_169b:
	/* 0x169b: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_169e:
	/* 0x169e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16a3:
	/* 0x16a3: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16a8:
	/* 0x16a8: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ad:
	/* 0x16ad: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16b2:
	/* 0x16b2: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_16b6:
	/* 0x16b6: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_16ba:
	/* 0x16ba: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_16bd:
	/* 0x16bd: xor    bpl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_16c1:
	/* 0x16c1: or     bpl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_16c4:
	/* 0x16c4: movzx  ebp,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16c8:
	/* 0x16c8: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_16cc:
	/* 0x16cc: jne    16da <generic_fentry_process_filter+0x16da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16da;
	}
x86_l_16ce:
	/* 0x16ce: and    r12d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 80ULL);
x86_l_16d3:
	/* 0x16d3: and    edi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_32, X86_ALU_AND);
x86_l_16d5:
	/* 0x16d5: and    r12d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_16d8:
	/* 0x16d8: jmp    16e4 <generic_fentry_process_filter+0x16e4> */
	goto x86_l_16e4;
x86_l_16da:
	/* 0x16da: or     ebp,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 80ULL);
x86_l_16de:
	/* 0x16de: or     r12d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_16e1:
	/* 0x16e1: or     r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_16e4:
	/* 0x16e4: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_16e7:
	/* 0x16e7: je     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8027ULL;
	}
x86_l_16ed:
	/* 0x16ed: mov    eax,DWORD PTR [rdx+r11*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 8ULL);
x86_l_16f2:
	/* 0x16f2: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_16f5:
	/* 0x16f5: lea    r11d,[r8+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_16f9:
	/* 0x16f9: mov    eax,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R11, X86_WIDTH_32);
x86_l_16fc:
	/* 0x16fc: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1701:
	/* 0x1701: mov    eax,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1704:
	/* 0x1704: lea    edi,[r11+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1708:
	/* 0x1708: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_170b:
	/* 0x170b: je     1f27 <generic_fentry_process_filter+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7975ULL;
	}
x86_l_1711:
	/* 0x1711: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1717:
	/* 0x1717: lea    r8d,[r11+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_171b:
	/* 0x171b: mov    r10d,DWORD PTR [rdi+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_171f:
	/* 0x171f: mov    r9d,DWORD PTR [rdi+rdx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_1724:
	/* 0x1724: mov    esi,DWORD PTR [rdi+rdx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 8ULL);
x86_l_1728:
	/* 0x1728: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_172b:
	/* 0x172b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1730:
	/* 0x1730: jbe    17a2 <generic_fentry_process_filter+0x17a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_17a2;
	}
x86_l_1732:
	/* 0x1732: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1734:
	/* 0x1734: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1739:
	/* 0x1739: mov    r12,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_64);
x86_l_173c:
	/* 0x173c: cmp    r11d,0x3d8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 984ULL);
x86_l_1743:
	/* 0x1743: ja     174e <generic_fentry_process_filter+0x174e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_174e;
	}
x86_l_1745:
	/* 0x1745: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_1748:
	/* 0x1748: and    eax,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_174b:
	/* 0x174b: mov    eax,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_174e:
	/* 0x174e: mov    r11d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R10, X86_WIDTH_32);
x86_l_1751:
	/* 0x1751: and    r11d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1755:
	/* 0x1755: cmp    r11,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 9ULL);
x86_l_1759:
	/* 0x1759: ja     177e <generic_fentry_process_filter+0x177e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_177e;
	}
x86_l_175b:
	/* 0x175b: mov    r11d,DWORD PTR [r14+r11*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 2), 32ULL);
x86_l_1760:
	/* 0x1760: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1764:
	/* 0x1764: jne    176b <generic_fentry_process_filter+0x176b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_176b;
	}
x86_l_1766:
	/* 0x1766: cmp    eax,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R11, X86_WIDTH_32);
x86_l_1769:
	/* 0x1769: jne    177e <generic_fentry_process_filter+0x177e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_177e;
	}
x86_l_176b:
	/* 0x176b: xor    eax,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_176e:
	/* 0x176e: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_1771:
	/* 0x1771: xor    r11d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1775:
	/* 0x1775: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1777:
	/* 0x1777: or     r11d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_177a:
	/* 0x177a: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_177e:
	/* 0x177e: add    r12d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_1782:
	/* 0x1782: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1785:
	/* 0x1785: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_178a:
	/* 0x178a: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1791:
	/* 0x1791: jbe    17cc <generic_fentry_process_filter+0x17cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_17cc;
	}
x86_l_1793:
	/* 0x1793: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1796:
	/* 0x1796: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_179a:
	/* 0x179a: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_179e:
	/* 0x179e: jbe    17e2 <generic_fentry_process_filter+0x17e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_17e2;
	}
x86_l_17a0:
	/* 0x17a0: jmp    1802 <generic_fentry_process_filter+0x1802> */
	goto x86_l_1802;
x86_l_17a2:
	/* 0x17a2: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a4:
	/* 0x17a4: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_17a8:
	/* 0x17a8: sete   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_E);
x86_l_17ac:
	/* 0x17ac: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_17af:
	/* 0x17af: je     19c0 <generic_fentry_process_filter+0x19c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6592ULL;
	}
x86_l_17b5:
	/* 0x17b5: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_17b8:
	/* 0x17b8: je     19a1 <generic_fentry_process_filter+0x19a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6561ULL;
	}
x86_l_17be:
	/* 0x17be: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_17c1:
	/* 0x17c1: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_17c4:
	/* 0x17c4: jne    1732 <generic_fentry_process_filter+0x1732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1732;
	}
x86_l_17ca:
	/* 0x17ca: jmp    1782 <generic_fentry_process_filter+0x1782> */
	goto x86_l_1782;
x86_l_17cc:
	/* 0x17cc: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_17cf:
	/* 0x17cf: and    eax,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_17d2:
	/* 0x17d2: mov    eax,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17d5:
	/* 0x17d5: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_17d8:
	/* 0x17d8: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_17dc:
	/* 0x17dc: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_17e0:
	/* 0x17e0: ja     1802 <generic_fentry_process_filter+0x1802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1802;
	}
x86_l_17e2:
	/* 0x17e2: mov    ebp,DWORD PTR [r14+r13*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 32ULL);
x86_l_17e7:
	/* 0x17e7: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_17eb:
	/* 0x17eb: jne    17f1 <generic_fentry_process_filter+0x17f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17f1;
	}
x86_l_17ed:
	/* 0x17ed: cmp    eax,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_17ef:
	/* 0x17ef: jne    1802 <generic_fentry_process_filter+0x1802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1802;
	}
x86_l_17f1:
	/* 0x17f1: xor    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17f3:
	/* 0x17f3: mov    ebp,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R9, X86_WIDTH_32);
x86_l_17f6:
	/* 0x17f6: xor    ebp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_17f9:
	/* 0x17f9: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17fc:
	/* 0x17fc: or     ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_17fe:
	/* 0x17fe: setne  r11b */
	X86_SIM_L_EXEC_SETCC(X86_R11, X86_CC_NE);
x86_l_1802:
	/* 0x1802: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1806:
	/* 0x1806: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1808:
	/* 0x1808: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_180d:
	/* 0x180d: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1814:
	/* 0x1814: ja     181f <generic_fentry_process_filter+0x181f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_181f;
	}
x86_l_1816:
	/* 0x1816: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1819:
	/* 0x1819: and    eax,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_181c:
	/* 0x181c: mov    eax,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_181f:
	/* 0x181f: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1822:
	/* 0x1822: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1826:
	/* 0x1826: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_182a:
	/* 0x182a: ja     184f <generic_fentry_process_filter+0x184f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_184f;
	}
x86_l_182c:
	/* 0x182c: mov    r13d,DWORD PTR [r14+r13*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 32ULL);
x86_l_1831:
	/* 0x1831: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1835:
	/* 0x1835: jne    183c <generic_fentry_process_filter+0x183c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_183c;
	}
x86_l_1837:
	/* 0x1837: cmp    eax,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_183a:
	/* 0x183a: jne    184f <generic_fentry_process_filter+0x184f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_184f;
	}
x86_l_183c:
	/* 0x183c: xor    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_183f:
	/* 0x183f: mov    r13d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_32);
x86_l_1842:
	/* 0x1842: xor    r13d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1846:
	/* 0x1846: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1848:
	/* 0x1848: or     r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_184b:
	/* 0x184b: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_184f:
	/* 0x184f: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1853:
	/* 0x1853: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1856:
	/* 0x1856: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_185b:
	/* 0x185b: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1862:
	/* 0x1862: ja     186c <generic_fentry_process_filter+0x186c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_186c;
	}
x86_l_1864:
	/* 0x1864: and    r12d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1868:
	/* 0x1868: mov    eax,DWORD PTR [rdx+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_186c:
	/* 0x186c: and    r10d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1870:
	/* 0x1870: cmp    r10,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 9ULL);
x86_l_1874:
	/* 0x1874: ja     189d <generic_fentry_process_filter+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_189d;
	}
x86_l_1876:
	/* 0x1876: mov    r10d,DWORD PTR [r14+r10*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 2), 32ULL);
x86_l_187b:
	/* 0x187b: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_187f:
	/* 0x187f: jne    1889 <generic_fentry_process_filter+0x1889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1889;
	}
x86_l_1881:
	/* 0x1881: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1884:
	/* 0x1884: cmp    eax,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R10, X86_WIDTH_32);
x86_l_1887:
	/* 0x1887: jne    18ad <generic_fentry_process_filter+0x18ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18ad;
	}
x86_l_1889:
	/* 0x1889: xor    eax,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_188c:
	/* 0x188c: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_188f:
	/* 0x188f: xor    r10d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1893:
	/* 0x1893: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1896:
	/* 0x1896: or     r10d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1899:
	/* 0x1899: setne  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_NE);
x86_l_189d:
	/* 0x189d: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_18a1:
	/* 0x18a1: jne    18ad <generic_fentry_process_filter+0x18ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18ad;
	}
x86_l_18a3:
	/* 0x18a3: and    ebp,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R11, X86_WIDTH_32, X86_ALU_AND);
x86_l_18a6:
	/* 0x18a6: and    edi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_32, X86_ALU_AND);
x86_l_18a9:
	/* 0x18a9: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_18ab:
	/* 0x18ab: jmp    18b5 <generic_fentry_process_filter+0x18b5> */
	goto x86_l_18b5;
x86_l_18ad:
	/* 0x18ad: or     r13d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R11, X86_WIDTH_32, X86_ALU_OR);
x86_l_18b0:
	/* 0x18b0: or     ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_18b2:
	/* 0x18b2: or     ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_OR);
x86_l_18b5:
	/* 0x18b5: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_18b7:
	/* 0x18b7: je     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8027ULL;
	}
x86_l_18bd:
	/* 0x18bd: shl    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_18c0:
	/* 0x18c0: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_18c2:
	/* 0x18c2: and    edi,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_18c5:
	/* 0x18c5: add    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18c8:
	/* 0x18c8: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18cd:
	/* 0x18cd: add    eax,0xfffffff0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967280ULL);
x86_l_18d0:
	/* 0x18d0: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_18d2:
	/* 0x18d2: je     1f27 <generic_fentry_process_filter+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7975ULL;
	}
x86_l_18d8:
	/* 0x18d8: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_18da:
	/* 0x18da: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
	return 6367ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6384ULL: goto x86_l_18f0;
	case 6388ULL: goto x86_l_18f4;
	case 6392ULL: goto x86_l_18f8;
	case 6394ULL: goto x86_l_18fa;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6408ULL: goto x86_l_1908;
	case 6410ULL: goto x86_l_190a;
	case 6412ULL: goto x86_l_190c;
	case 6415ULL: goto x86_l_190f;
	case 6418ULL: goto x86_l_1912;
	case 6421ULL: goto x86_l_1915;
	case 6425ULL: goto x86_l_1919;
	case 6429ULL: goto x86_l_191d;
	case 6431ULL: goto x86_l_191f;
	case 6436ULL: goto x86_l_1924;
	case 6440ULL: goto x86_l_1928;
	case 6442ULL: goto x86_l_192a;
	case 6445ULL: goto x86_l_192d;
	case 6447ULL: goto x86_l_192f;
	case 6450ULL: goto x86_l_1932;
	case 6453ULL: goto x86_l_1935;
	case 6457ULL: goto x86_l_1939;
	case 6460ULL: goto x86_l_193c;
	case 6463ULL: goto x86_l_193f;
	case 6467ULL: goto x86_l_1943;
	case 6470ULL: goto x86_l_1946;
	case 6473ULL: goto x86_l_1949;
	case 6475ULL: goto x86_l_194b;
	case 6480ULL: goto x86_l_1950;
	case 6487ULL: goto x86_l_1957;
	case 6493ULL: goto x86_l_195d;
	case 6496ULL: goto x86_l_1960;
	case 6500ULL: goto x86_l_1964;
	case 6504ULL: goto x86_l_1968;
	case 6510ULL: goto x86_l_196e;
	case 6515ULL: goto x86_l_1973;
	case 6518ULL: goto x86_l_1976;
	case 6522ULL: goto x86_l_197a;
	case 6526ULL: goto x86_l_197e;
	case 6530ULL: goto x86_l_1982;
	case 6536ULL: goto x86_l_1988;
	case 6540ULL: goto x86_l_198c;
	case 6546ULL: goto x86_l_1992;
	case 6549ULL: goto x86_l_1995;
	case 6553ULL: goto x86_l_1999;
	case 6559ULL: goto x86_l_199f;
	case 6561ULL: goto x86_l_19a1;
	case 6564ULL: goto x86_l_19a4;
	case 6567ULL: goto x86_l_19a7;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6581ULL: goto x86_l_19b5;
	case 6587ULL: goto x86_l_19bb;
	case 6592ULL: goto x86_l_19c0;
	case 6594ULL: goto x86_l_19c2;
	case 6597ULL: goto x86_l_19c5;
	case 6600ULL: goto x86_l_19c8;
	case 6603ULL: goto x86_l_19cb;
	case 6608ULL: goto x86_l_19d0;
	case 6615ULL: goto x86_l_19d7;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6632ULL: goto x86_l_19e8;
	case 6635ULL: goto x86_l_19eb;
	case 6638ULL: goto x86_l_19ee;
	case 6642ULL: goto x86_l_19f2;
	case 6646ULL: goto x86_l_19f6;
	case 6648ULL: goto x86_l_19f8;
	case 6653ULL: goto x86_l_19fd;
	case 6657ULL: goto x86_l_1a01;
	case 6659ULL: goto x86_l_1a03;
	case 6662ULL: goto x86_l_1a06;
	case 6664ULL: goto x86_l_1a08;
	case 6667ULL: goto x86_l_1a0b;
	case 6670ULL: goto x86_l_1a0e;
	case 6674ULL: goto x86_l_1a12;
	case 6676ULL: goto x86_l_1a14;
	case 6679ULL: goto x86_l_1a17;
	case 6683ULL: goto x86_l_1a1b;
	case 6687ULL: goto x86_l_1a1f;
	case 6689ULL: goto x86_l_1a21;
	case 6694ULL: goto x86_l_1a26;
	case 6701ULL: goto x86_l_1a2d;
	case 6703ULL: goto x86_l_1a2f;
	case 6706ULL: goto x86_l_1a32;
	case 6709ULL: goto x86_l_1a35;
	case 6712ULL: goto x86_l_1a38;
	case 6715ULL: goto x86_l_1a3b;
	case 6719ULL: goto x86_l_1a3f;
	case 6723ULL: goto x86_l_1a43;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6734ULL: goto x86_l_1a4e;
	case 6736ULL: goto x86_l_1a50;
	case 6739ULL: goto x86_l_1a53;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6751ULL: goto x86_l_1a5f;
	case 6753ULL: goto x86_l_1a61;
	case 6756ULL: goto x86_l_1a64;
	case 6760ULL: goto x86_l_1a68;
	case 6764ULL: goto x86_l_1a6c;
	case 6767ULL: goto x86_l_1a6f;
	case 6772ULL: goto x86_l_1a74;
	case 6779ULL: goto x86_l_1a7b;
	case 6781ULL: goto x86_l_1a7d;
	case 6785ULL: goto x86_l_1a81;
	case 6789ULL: goto x86_l_1a85;
	case 6793ULL: goto x86_l_1a89;
	case 6797ULL: goto x86_l_1a8d;
	case 6799ULL: goto x86_l_1a8f;
	case 6804ULL: goto x86_l_1a94;
	case 6808ULL: goto x86_l_1a98;
	case 6810ULL: goto x86_l_1a9a;
	case 6813ULL: goto x86_l_1a9d;
	case 6816ULL: goto x86_l_1aa0;
	case 6818ULL: goto x86_l_1aa2;
	case 6821ULL: goto x86_l_1aa5;
	case 6824ULL: goto x86_l_1aa8;
	case 6828ULL: goto x86_l_1aac;
	case 6831ULL: goto x86_l_1aaf;
	case 6834ULL: goto x86_l_1ab2;
	case 6838ULL: goto x86_l_1ab6;
	case 6842ULL: goto x86_l_1aba;
	case 6844ULL: goto x86_l_1abc;
	case 6846ULL: goto x86_l_1abe;
	case 6849ULL: goto x86_l_1ac1;
	case 6852ULL: goto x86_l_1ac4;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6865ULL: goto x86_l_1ad1;
	case 6871ULL: goto x86_l_1ad7;
	case 6879ULL: goto x86_l_1adf;
	case 6882ULL: goto x86_l_1ae2;
	case 6886ULL: goto x86_l_1ae6;
	case 6890ULL: goto x86_l_1aea;
	case 6895ULL: goto x86_l_1aef;
	case 6898ULL: goto x86_l_1af2;
	case 6900ULL: goto x86_l_1af4;
	case 6906ULL: goto x86_l_1afa;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6916ULL: goto x86_l_1b04;
	case 6920ULL: goto x86_l_1b08;
	case 6925ULL: goto x86_l_1b0d;
	case 6930ULL: goto x86_l_1b12;
	case 6934ULL: goto x86_l_1b16;
	case 6938ULL: goto x86_l_1b1a;
	case 6940ULL: goto x86_l_1b1c;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6954ULL: goto x86_l_1b2a;
	case 6956ULL: goto x86_l_1b2c;
	case 6958ULL: goto x86_l_1b2e;
	case 6961ULL: goto x86_l_1b31;
	case 6964ULL: goto x86_l_1b34;
	case 6967ULL: goto x86_l_1b37;
	case 6971ULL: goto x86_l_1b3b;
	case 6975ULL: goto x86_l_1b3f;
	case 6977ULL: goto x86_l_1b41;
	case 6982ULL: goto x86_l_1b46;
	case 6986ULL: goto x86_l_1b4a;
	case 6988ULL: goto x86_l_1b4c;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6996ULL: goto x86_l_1b54;
	case 6999ULL: goto x86_l_1b57;
	case 7003ULL: goto x86_l_1b5b;
	case 7006ULL: goto x86_l_1b5e;
	case 7009ULL: goto x86_l_1b61;
	case 7013ULL: goto x86_l_1b65;
	case 7016ULL: goto x86_l_1b68;
	case 7019ULL: goto x86_l_1b6b;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7033ULL: goto x86_l_1b79;
	case 7039ULL: goto x86_l_1b7f;
	case 7042ULL: goto x86_l_1b82;
	case 7046ULL: goto x86_l_1b86;
	case 7050ULL: goto x86_l_1b8a;
	case 7056ULL: goto x86_l_1b90;
	case 7061ULL: goto x86_l_1b95;
	case 7064ULL: goto x86_l_1b98;
	case 7068ULL: goto x86_l_1b9c;
	case 7072ULL: goto x86_l_1ba0;
	case 7076ULL: goto x86_l_1ba4;
	case 7082ULL: goto x86_l_1baa;
	case 7086ULL: goto x86_l_1bae;
	case 7092ULL: goto x86_l_1bb4;
	case 7095ULL: goto x86_l_1bb7;
	case 7099ULL: goto x86_l_1bbb;
	case 7105ULL: goto x86_l_1bc1;
	case 7107ULL: goto x86_l_1bc3;
	case 7110ULL: goto x86_l_1bc6;
	case 7113ULL: goto x86_l_1bc9;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7127ULL: goto x86_l_1bd7;
	case 7133ULL: goto x86_l_1bdd;
	case 7138ULL: goto x86_l_1be2;
	case 7140ULL: goto x86_l_1be4;
	case 7143ULL: goto x86_l_1be7;
	case 7146ULL: goto x86_l_1bea;
	case 7149ULL: goto x86_l_1bed;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7164ULL: goto x86_l_1bfc;
	case 7170ULL: goto x86_l_1c02;
	case 7175ULL: goto x86_l_1c07;
	case 7178ULL: goto x86_l_1c0a;
	case 7181ULL: goto x86_l_1c0d;
	case 7184ULL: goto x86_l_1c10;
	case 7187ULL: goto x86_l_1c13;
	case 7191ULL: goto x86_l_1c17;
	case 7195ULL: goto x86_l_1c1b;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7206ULL: goto x86_l_1c26;
	case 7208ULL: goto x86_l_1c28;
	case 7211ULL: goto x86_l_1c2b;
	case 7213ULL: goto x86_l_1c2d;
	case 7216ULL: goto x86_l_1c30;
	case 7219ULL: goto x86_l_1c33;
	case 7223ULL: goto x86_l_1c37;
	case 7225ULL: goto x86_l_1c39;
	case 7228ULL: goto x86_l_1c3c;
	case 7232ULL: goto x86_l_1c40;
	case 7236ULL: goto x86_l_1c44;
	case 7238ULL: goto x86_l_1c46;
	case 7243ULL: goto x86_l_1c4b;
	case 7250ULL: goto x86_l_1c52;
	case 7252ULL: goto x86_l_1c54;
	case 7255ULL: goto x86_l_1c57;
	case 7258ULL: goto x86_l_1c5a;
	case 7261ULL: goto x86_l_1c5d;
	case 7264ULL: goto x86_l_1c60;
	case 7268ULL: goto x86_l_1c64;
	case 7272ULL: goto x86_l_1c68;
	case 7274ULL: goto x86_l_1c6a;
	case 7279ULL: goto x86_l_1c6f;
	case 7283ULL: goto x86_l_1c73;
	case 7285ULL: goto x86_l_1c75;
	case 7288ULL: goto x86_l_1c78;
	case 7290ULL: goto x86_l_1c7a;
	case 7293ULL: goto x86_l_1c7d;
	case 7296ULL: goto x86_l_1c80;
	case 7300ULL: goto x86_l_1c84;
	case 7302ULL: goto x86_l_1c86;
	case 7305ULL: goto x86_l_1c89;
	case 7309ULL: goto x86_l_1c8d;
	case 7313ULL: goto x86_l_1c91;
	case 7316ULL: goto x86_l_1c94;
	case 7321ULL: goto x86_l_1c99;
	case 7328ULL: goto x86_l_1ca0;
	case 7330ULL: goto x86_l_1ca2;
	case 7334ULL: goto x86_l_1ca6;
	case 7338ULL: goto x86_l_1caa;
	case 7342ULL: goto x86_l_1cae;
	case 7346ULL: goto x86_l_1cb2;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7357ULL: goto x86_l_1cbd;
	case 7359ULL: goto x86_l_1cbf;
	case 7362ULL: goto x86_l_1cc2;
	case 7365ULL: goto x86_l_1cc5;
	case 7367ULL: goto x86_l_1cc7;
	case 7370ULL: goto x86_l_1cca;
	case 7373ULL: goto x86_l_1ccd;
	case 7377ULL: goto x86_l_1cd1;
	case 7380ULL: goto x86_l_1cd4;
	case 7383ULL: goto x86_l_1cd7;
	case 7387ULL: goto x86_l_1cdb;
	case 7391ULL: goto x86_l_1cdf;
	case 7393ULL: goto x86_l_1ce1;
	case 7395ULL: goto x86_l_1ce3;
	case 7398ULL: goto x86_l_1ce6;
	case 7401ULL: goto x86_l_1ce9;
	case 7403ULL: goto x86_l_1ceb;
	case 7406ULL: goto x86_l_1cee;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7414ULL: goto x86_l_1cf6;
	case 7420ULL: goto x86_l_1cfc;
	case 7424ULL: goto x86_l_1d00;
	case 7427ULL: goto x86_l_1d03;
	case 7431ULL: goto x86_l_1d07;
	case 7434ULL: goto x86_l_1d0a;
	case 7438ULL: goto x86_l_1d0e;
	case 7443ULL: goto x86_l_1d13;
	case 7446ULL: goto x86_l_1d16;
	case 7448ULL: goto x86_l_1d18;
	case 7454ULL: goto x86_l_1d1e;
	case 7456ULL: goto x86_l_1d20;
	case 7462ULL: goto x86_l_1d26;
	case 7465ULL: goto x86_l_1d29;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7478ULL: goto x86_l_1d36;
	case 7481ULL: goto x86_l_1d39;
	case 7487ULL: goto x86_l_1d3f;
	case 7490ULL: goto x86_l_1d42;
	case 7496ULL: goto x86_l_1d48;
	case 7502ULL: goto x86_l_1d4e;
	case 7504ULL: goto x86_l_1d50;
	case 7507ULL: goto x86_l_1d53;
	case 7511ULL: goto x86_l_1d57;
	case 7515ULL: goto x86_l_1d5b;
	case 7518ULL: goto x86_l_1d5e;
	case 7522ULL: goto x86_l_1d62;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7537ULL: goto x86_l_1d71;
	case 7539ULL: goto x86_l_1d73;
	case 7542ULL: goto x86_l_1d76;
	case 7544ULL: goto x86_l_1d78;
	case 7547ULL: goto x86_l_1d7b;
	case 7550ULL: goto x86_l_1d7e;
	case 7553ULL: goto x86_l_1d81;
	case 7556ULL: goto x86_l_1d84;
	case 7559ULL: goto x86_l_1d87;
	case 7563ULL: goto x86_l_1d8b;
	case 7566ULL: goto x86_l_1d8e;
	case 7569ULL: goto x86_l_1d91;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7583ULL: goto x86_l_1d9f;
	case 7589ULL: goto x86_l_1da5;
	case 7592ULL: goto x86_l_1da8;
	case 7596ULL: goto x86_l_1dac;
	case 7600ULL: goto x86_l_1db0;
	case 7606ULL: goto x86_l_1db6;
	case 7611ULL: goto x86_l_1dbb;
	case 7614ULL: goto x86_l_1dbe;
	case 7618ULL: goto x86_l_1dc2;
	case 7622ULL: goto x86_l_1dc6;
	case 7625ULL: goto x86_l_1dc9;
	case 7631ULL: goto x86_l_1dcf;
	case 7634ULL: goto x86_l_1dd2;
	case 7640ULL: goto x86_l_1dd8;
	case 7643ULL: goto x86_l_1ddb;
	case 7646ULL: goto x86_l_1dde;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7657ULL: goto x86_l_1de9;
	case 7660ULL: goto x86_l_1dec;
	case 7662ULL: goto x86_l_1dee;
	case 7667ULL: goto x86_l_1df3;
	case 7674ULL: goto x86_l_1dfa;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7687ULL: goto x86_l_1e07;
	case 7690ULL: goto x86_l_1e0a;
	case 7693ULL: goto x86_l_1e0d;
	case 7696ULL: goto x86_l_1e10;
	case 7699ULL: goto x86_l_1e13;
	case 7704ULL: goto x86_l_1e18;
	case 7711ULL: goto x86_l_1e1f;
	case 7717ULL: goto x86_l_1e25;
	case 7722ULL: goto x86_l_1e2a;
	case 7725ULL: goto x86_l_1e2d;
	case 7729ULL: goto x86_l_1e31;
	case 7733ULL: goto x86_l_1e35;
	case 7736ULL: goto x86_l_1e38;
	case 7740ULL: goto x86_l_1e3c;
	case 7744ULL: goto x86_l_1e40;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7755ULL: goto x86_l_1e4b;
	case 7757ULL: goto x86_l_1e4d;
	case 7760ULL: goto x86_l_1e50;
	case 7762ULL: goto x86_l_1e52;
	case 7765ULL: goto x86_l_1e55;
	case 7768ULL: goto x86_l_1e58;
	case 7772ULL: goto x86_l_1e5c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_18df:
	/* 0x18df: lea    ebp,[rdi+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18e2:
	/* 0x18e2: mov    r12d,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_18e6:
	/* 0x18e6: mov    r11d,DWORD PTR [rax+rdx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_18eb:
	/* 0x18eb: mov    r9d,DWORD PTR [rax+rdx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 8ULL);
x86_l_18f0:
	/* 0x18f0: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_18f4:
	/* 0x18f4: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18f8:
	/* 0x18f8: jbe    1973 <generic_fentry_process_filter+0x1973> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1973;
	}
x86_l_18fa:
	/* 0x18fa: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18fd:
	/* 0x18fd: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1902:
	/* 0x1902: cmp    edi,0x3dc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 988ULL);
x86_l_1908:
	/* 0x1908: ja     1912 <generic_fentry_process_filter+0x1912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1912;
	}
x86_l_190a:
	/* 0x190a: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_190c:
	/* 0x190c: and    eax,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_190f:
	/* 0x190f: mov    eax,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1912:
	/* 0x1912: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1915:
	/* 0x1915: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1919:
	/* 0x1919: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_191d:
	/* 0x191d: ja     1943 <generic_fentry_process_filter+0x1943> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1943;
	}
x86_l_191f:
	/* 0x191f: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1924:
	/* 0x1924: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1928:
	/* 0x1928: jne    192f <generic_fentry_process_filter+0x192f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_192f;
	}
x86_l_192a:
	/* 0x192a: cmp    eax,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_192d:
	/* 0x192d: jne    1943 <generic_fentry_process_filter+0x1943> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1943;
	}
x86_l_192f:
	/* 0x192f: xor    eax,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1932:
	/* 0x1932: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1935:
	/* 0x1935: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1939:
	/* 0x1939: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_193c:
	/* 0x193c: or     r8d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_193f:
	/* 0x193f: setne  r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_NE);
x86_l_1943:
	/* 0x1943: add    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1946:
	/* 0x1946: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_1949:
	/* 0x1949: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_194b:
	/* 0x194b: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1950:
	/* 0x1950: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1957:
	/* 0x1957: jbe    19e2 <generic_fentry_process_filter+0x19e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_19e2;
	}
x86_l_195d:
	/* 0x195d: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1960:
	/* 0x1960: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1964:
	/* 0x1964: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1968:
	/* 0x1968: jbe    19f8 <generic_fentry_process_filter+0x19f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_19f8;
	}
x86_l_196e:
	/* 0x196e: jmp    1a1b <generic_fentry_process_filter+0x1a1b> */
	goto x86_l_1a1b;
x86_l_1973:
	/* 0x1973: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1976:
	/* 0x1976: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_197a:
	/* 0x197a: sete   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_E);
x86_l_197e:
	/* 0x197e: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_1982:
	/* 0x1982: je     1be2 <generic_fentry_process_filter+0x1be2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1be2;
	}
x86_l_1988:
	/* 0x1988: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_198c:
	/* 0x198c: je     1bc3 <generic_fentry_process_filter+0x1bc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bc3;
	}
x86_l_1992:
	/* 0x1992: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1995:
	/* 0x1995: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_1999:
	/* 0x1999: jne    18fa <generic_fentry_process_filter+0x18fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18fa;
	}
x86_l_199f:
	/* 0x199f: jmp    1949 <generic_fentry_process_filter+0x1949> */
	goto x86_l_1949;
x86_l_19a1:
	/* 0x19a1: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_19a4:
	/* 0x19a4: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_19a7:
	/* 0x19a7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19a9:
	/* 0x19a9: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_19ae:
	/* 0x19ae: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_19b5:
	/* 0x19b5: jbe    1816 <generic_fentry_process_filter+0x1816> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 6166ULL;
	}
x86_l_19bb:
	/* 0x19bb: jmp    181f <generic_fentry_process_filter+0x181f> */
	return 6175ULL;
x86_l_19c0:
	/* 0x19c0: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_19c2:
	/* 0x19c2: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_19c5:
	/* 0x19c5: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_19c8:
	/* 0x19c8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19cb:
	/* 0x19cb: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_19d0:
	/* 0x19d0: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_19d7:
	/* 0x19d7: jbe    1864 <generic_fentry_process_filter+0x1864> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 6244ULL;
	}
x86_l_19dd:
	/* 0x19dd: jmp    186c <generic_fentry_process_filter+0x186c> */
	return 6252ULL;
x86_l_19e2:
	/* 0x19e2: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_19e5:
	/* 0x19e5: and    eax,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_19e8:
	/* 0x19e8: mov    eax,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_19eb:
	/* 0x19eb: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_19ee:
	/* 0x19ee: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_19f2:
	/* 0x19f2: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_19f6:
	/* 0x19f6: ja     1a1b <generic_fentry_process_filter+0x1a1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a1b;
	}
x86_l_19f8:
	/* 0x19f8: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_19fd:
	/* 0x19fd: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1a01:
	/* 0x1a01: jne    1a08 <generic_fentry_process_filter+0x1a08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a08;
	}
x86_l_1a03:
	/* 0x1a03: cmp    eax,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_1a06:
	/* 0x1a06: jne    1a1b <generic_fentry_process_filter+0x1a1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a1b;
	}
x86_l_1a08:
	/* 0x1a08: xor    eax,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a0b:
	/* 0x1a0b: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1a0e:
	/* 0x1a0e: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1a12:
	/* 0x1a12: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a14:
	/* 0x1a14: or     r8d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1a17:
	/* 0x1a17: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1a1b:
	/* 0x1a1b: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1a1f:
	/* 0x1a1f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a21:
	/* 0x1a21: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1a26:
	/* 0x1a26: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1a2d:
	/* 0x1a2d: ja     1a38 <generic_fentry_process_filter+0x1a38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a38;
	}
x86_l_1a2f:
	/* 0x1a2f: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1a32:
	/* 0x1a32: and    eax,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1a35:
	/* 0x1a35: mov    eax,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a38:
	/* 0x1a38: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1a3b:
	/* 0x1a3b: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1a3f:
	/* 0x1a3f: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1a43:
	/* 0x1a43: ja     1a68 <generic_fentry_process_filter+0x1a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a68;
	}
x86_l_1a45:
	/* 0x1a45: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1a4a:
	/* 0x1a4a: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1a4e:
	/* 0x1a4e: jne    1a55 <generic_fentry_process_filter+0x1a55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a55;
	}
x86_l_1a50:
	/* 0x1a50: cmp    eax,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_1a53:
	/* 0x1a53: jne    1a68 <generic_fentry_process_filter+0x1a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a68;
	}
x86_l_1a55:
	/* 0x1a55: xor    eax,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a58:
	/* 0x1a58: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1a5b:
	/* 0x1a5b: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1a5f:
	/* 0x1a5f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a61:
	/* 0x1a61: or     r8d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1a64:
	/* 0x1a64: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1a68:
	/* 0x1a68: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1a6c:
	/* 0x1a6c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a6f:
	/* 0x1a6f: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1a74:
	/* 0x1a74: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1a7b:
	/* 0x1a7b: ja     1a85 <generic_fentry_process_filter+0x1a85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a85;
	}
x86_l_1a7d:
	/* 0x1a7d: and    r13d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1a81:
	/* 0x1a81: mov    eax,DWORD PTR [rdx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1a85:
	/* 0x1a85: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1a89:
	/* 0x1a89: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1a8d:
	/* 0x1a8d: ja     1ab6 <generic_fentry_process_filter+0x1ab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ab6;
	}
x86_l_1a8f:
	/* 0x1a8f: mov    r12d,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1a94:
	/* 0x1a94: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1a98:
	/* 0x1a98: jne    1aa2 <generic_fentry_process_filter+0x1aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1aa2;
	}
x86_l_1a9a:
	/* 0x1a9a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9d:
	/* 0x1a9d: cmp    eax,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1aa0:
	/* 0x1aa0: jne    1ac6 <generic_fentry_process_filter+0x1ac6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ac6;
	}
x86_l_1aa2:
	/* 0x1aa2: xor    eax,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aa5:
	/* 0x1aa5: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1aa8:
	/* 0x1aa8: xor    r12d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1aac:
	/* 0x1aac: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aaf:
	/* 0x1aaf: or     r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1ab2:
	/* 0x1ab2: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_1ab6:
	/* 0x1ab6: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1aba:
	/* 0x1aba: jne    1ac6 <generic_fentry_process_filter+0x1ac6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ac6;
	}
x86_l_1abc:
	/* 0x1abc: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1abe:
	/* 0x1abe: and    r10d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_32, X86_ALU_AND);
x86_l_1ac1:
	/* 0x1ac1: and    ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_AND);
x86_l_1ac4:
	/* 0x1ac4: jmp    1acf <generic_fentry_process_filter+0x1acf> */
	goto x86_l_1acf;
x86_l_1ac6:
	/* 0x1ac6: or     r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1ac9:
	/* 0x1ac9: or     ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_OR);
x86_l_1acc:
	/* 0x1acc: or     ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_1acf:
	/* 0x1acf: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1ad1:
	/* 0x1ad1: je     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8027ULL;
	}
x86_l_1ad7:
	/* 0x1ad7: lea    edi,[r9*4+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 2), 0ULL);
x86_l_1adf:
	/* 0x1adf: and    edi,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_1ae2:
	/* 0x1ae2: add    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1ae6:
	/* 0x1ae6: lea    esi,[rsi+r9*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 2), 0ULL);
x86_l_1aea:
	/* 0x1aea: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1aef:
	/* 0x1aef: add    eax,0xffffffe4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967268ULL);
x86_l_1af2:
	/* 0x1af2: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_1af4:
	/* 0x1af4: je     1f27 <generic_fentry_process_filter+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7975ULL;
	}
x86_l_1afa:
	/* 0x1afa: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_1afc:
	/* 0x1afc: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1b01:
	/* 0x1b01: lea    ebp,[rdi+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b04:
	/* 0x1b04: mov    r12d,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1b08:
	/* 0x1b08: mov    r11d,DWORD PTR [rax+rdx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_1b0d:
	/* 0x1b0d: mov    r9d,DWORD PTR [rax+rdx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 8ULL);
x86_l_1b12:
	/* 0x1b12: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_1b16:
	/* 0x1b16: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b1a:
	/* 0x1b1a: jbe    1b95 <generic_fentry_process_filter+0x1b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b95;
	}
x86_l_1b1c:
	/* 0x1b1c: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b1f:
	/* 0x1b1f: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1b24:
	/* 0x1b24: cmp    edi,0x3dc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 988ULL);
x86_l_1b2a:
	/* 0x1b2a: ja     1b34 <generic_fentry_process_filter+0x1b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b34;
	}
x86_l_1b2c:
	/* 0x1b2c: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1b2e:
	/* 0x1b2e: and    eax,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1b31:
	/* 0x1b31: mov    eax,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1b34:
	/* 0x1b34: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1b37:
	/* 0x1b37: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1b3b:
	/* 0x1b3b: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1b3f:
	/* 0x1b3f: ja     1b65 <generic_fentry_process_filter+0x1b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b65;
	}
x86_l_1b41:
	/* 0x1b41: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1b46:
	/* 0x1b46: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1b4a:
	/* 0x1b4a: jne    1b51 <generic_fentry_process_filter+0x1b51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b51;
	}
x86_l_1b4c:
	/* 0x1b4c: cmp    eax,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_1b4f:
	/* 0x1b4f: jne    1b65 <generic_fentry_process_filter+0x1b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b65;
	}
x86_l_1b51:
	/* 0x1b51: xor    eax,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b54:
	/* 0x1b54: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1b57:
	/* 0x1b57: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1b5b:
	/* 0x1b5b: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5e:
	/* 0x1b5e: or     r8d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b61:
	/* 0x1b61: setne  r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_NE);
x86_l_1b65:
	/* 0x1b65: add    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1b68:
	/* 0x1b68: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_1b6b:
	/* 0x1b6b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6d:
	/* 0x1b6d: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1b72:
	/* 0x1b72: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1b79:
	/* 0x1b79: jbe    1c07 <generic_fentry_process_filter+0x1c07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c07;
	}
x86_l_1b7f:
	/* 0x1b7f: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1b82:
	/* 0x1b82: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1b86:
	/* 0x1b86: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1b8a:
	/* 0x1b8a: jbe    1c1d <generic_fentry_process_filter+0x1c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c1d;
	}
x86_l_1b90:
	/* 0x1b90: jmp    1c40 <generic_fentry_process_filter+0x1c40> */
	goto x86_l_1c40;
x86_l_1b95:
	/* 0x1b95: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b98:
	/* 0x1b98: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1b9c:
	/* 0x1b9c: sete   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_E);
x86_l_1ba0:
	/* 0x1ba0: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_1ba4:
	/* 0x1ba4: je     1e05 <generic_fentry_process_filter+0x1e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e05;
	}
x86_l_1baa:
	/* 0x1baa: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_1bae:
	/* 0x1bae: je     1de6 <generic_fentry_process_filter+0x1de6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1de6;
	}
x86_l_1bb4:
	/* 0x1bb4: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1bb7:
	/* 0x1bb7: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_1bbb:
	/* 0x1bbb: jne    1b1c <generic_fentry_process_filter+0x1b1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b1c;
	}
x86_l_1bc1:
	/* 0x1bc1: jmp    1b6b <generic_fentry_process_filter+0x1b6b> */
	goto x86_l_1b6b;
x86_l_1bc3:
	/* 0x1bc3: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1bc6:
	/* 0x1bc6: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1bc9:
	/* 0x1bc9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bcb:
	/* 0x1bcb: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1bd0:
	/* 0x1bd0: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1bd7:
	/* 0x1bd7: jbe    1a2f <generic_fentry_process_filter+0x1a2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a2f;
	}
x86_l_1bdd:
	/* 0x1bdd: jmp    1a38 <generic_fentry_process_filter+0x1a38> */
	goto x86_l_1a38;
x86_l_1be2:
	/* 0x1be2: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1be4:
	/* 0x1be4: mov    ebp,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_32);
x86_l_1be7:
	/* 0x1be7: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1bea:
	/* 0x1bea: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1bed:
	/* 0x1bed: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bf0:
	/* 0x1bf0: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1bf5:
	/* 0x1bf5: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1bfc:
	/* 0x1bfc: jbe    1a7d <generic_fentry_process_filter+0x1a7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a7d;
	}
x86_l_1c02:
	/* 0x1c02: jmp    1a85 <generic_fentry_process_filter+0x1a85> */
	goto x86_l_1a85;
x86_l_1c07:
	/* 0x1c07: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1c0a:
	/* 0x1c0a: and    eax,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    eax,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c10:
	/* 0x1c10: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1c13:
	/* 0x1c13: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1c17:
	/* 0x1c17: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1c1b:
	/* 0x1c1b: ja     1c40 <generic_fentry_process_filter+0x1c40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c40;
	}
x86_l_1c1d:
	/* 0x1c1d: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1c22:
	/* 0x1c22: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1c26:
	/* 0x1c26: jne    1c2d <generic_fentry_process_filter+0x1c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c2d;
	}
x86_l_1c28:
	/* 0x1c28: cmp    eax,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_1c2b:
	/* 0x1c2b: jne    1c40 <generic_fentry_process_filter+0x1c40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c40;
	}
x86_l_1c2d:
	/* 0x1c2d: xor    eax,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c30:
	/* 0x1c30: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1c33:
	/* 0x1c33: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1c37:
	/* 0x1c37: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c39:
	/* 0x1c39: or     r8d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1c3c:
	/* 0x1c3c: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1c40:
	/* 0x1c40: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1c44:
	/* 0x1c44: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c46:
	/* 0x1c46: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1c4b:
	/* 0x1c4b: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1c52:
	/* 0x1c52: ja     1c5d <generic_fentry_process_filter+0x1c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c5d;
	}
x86_l_1c54:
	/* 0x1c54: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1c57:
	/* 0x1c57: and    eax,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1c5a:
	/* 0x1c5a: mov    eax,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c5d:
	/* 0x1c5d: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1c60:
	/* 0x1c60: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1c64:
	/* 0x1c64: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1c68:
	/* 0x1c68: ja     1c8d <generic_fentry_process_filter+0x1c8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c8d;
	}
x86_l_1c6a:
	/* 0x1c6a: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1c6f:
	/* 0x1c6f: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1c73:
	/* 0x1c73: jne    1c7a <generic_fentry_process_filter+0x1c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c7a;
	}
x86_l_1c75:
	/* 0x1c75: cmp    eax,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_1c78:
	/* 0x1c78: jne    1c8d <generic_fentry_process_filter+0x1c8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c8d;
	}
x86_l_1c7a:
	/* 0x1c7a: xor    eax,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c7d:
	/* 0x1c7d: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1c80:
	/* 0x1c80: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1c84:
	/* 0x1c84: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c86:
	/* 0x1c86: or     r8d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1c89:
	/* 0x1c89: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1c8d:
	/* 0x1c8d: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1c91:
	/* 0x1c91: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c94:
	/* 0x1c94: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1c99:
	/* 0x1c99: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1ca0:
	/* 0x1ca0: ja     1caa <generic_fentry_process_filter+0x1caa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1caa;
	}
x86_l_1ca2:
	/* 0x1ca2: and    r13d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1ca6:
	/* 0x1ca6: mov    eax,DWORD PTR [rdx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1caa:
	/* 0x1caa: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1cae:
	/* 0x1cae: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1cb2:
	/* 0x1cb2: ja     1cdb <generic_fentry_process_filter+0x1cdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1cdb;
	}
x86_l_1cb4:
	/* 0x1cb4: mov    r12d,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1cb9:
	/* 0x1cb9: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1cbd:
	/* 0x1cbd: jne    1cc7 <generic_fentry_process_filter+0x1cc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cc7;
	}
x86_l_1cbf:
	/* 0x1cbf: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cc2:
	/* 0x1cc2: cmp    eax,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1cc5:
	/* 0x1cc5: jne    1ceb <generic_fentry_process_filter+0x1ceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ceb;
	}
x86_l_1cc7:
	/* 0x1cc7: xor    eax,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cca:
	/* 0x1cca: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1ccd:
	/* 0x1ccd: xor    r12d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1cd1:
	/* 0x1cd1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cd4:
	/* 0x1cd4: or     r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1cd7:
	/* 0x1cd7: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_1cdb:
	/* 0x1cdb: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1cdf:
	/* 0x1cdf: jne    1ceb <generic_fentry_process_filter+0x1ceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ceb;
	}
x86_l_1ce1:
	/* 0x1ce1: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1ce3:
	/* 0x1ce3: and    r10d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_32, X86_ALU_AND);
x86_l_1ce6:
	/* 0x1ce6: and    ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_AND);
x86_l_1ce9:
	/* 0x1ce9: jmp    1cf4 <generic_fentry_process_filter+0x1cf4> */
	goto x86_l_1cf4;
x86_l_1ceb:
	/* 0x1ceb: or     r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1cee:
	/* 0x1cee: or     ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_OR);
x86_l_1cf1:
	/* 0x1cf1: or     ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_1cf4:
	/* 0x1cf4: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1cf6:
	/* 0x1cf6: je     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8027ULL;
	}
x86_l_1cfc:
	/* 0x1cfc: shl    r9d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_1d00:
	/* 0x1d00: add    esi,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d03:
	/* 0x1d03: and    r9d,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_1d07:
	/* 0x1d07: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_1d0a:
	/* 0x1d0a: add    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1d0e:
	/* 0x1d0e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d13:
	/* 0x1d13: add    eax,0xffffffd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967256ULL);
x86_l_1d16:
	/* 0x1d16: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_1d18:
	/* 0x1d18: je     1f27 <generic_fentry_process_filter+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7975ULL;
	}
x86_l_1d1e:
	/* 0x1d1e: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_1d20:
	/* 0x1d20: and    esi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1d26:
	/* 0x1d26: lea    eax,[rdi+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d29:
	/* 0x1d29: mov    r10d,DWORD PTR [rsi+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    r9d,DWORD PTR [rsi+rdx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_1d32:
	/* 0x1d32: mov    esi,DWORD PTR [rsi+rdx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 8ULL);
x86_l_1d36:
	/* 0x1d36: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_1d39:
	/* 0x1d39: jbe    1dbb <generic_fentry_process_filter+0x1dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1dbb;
	}
x86_l_1d3f:
	/* 0x1d3f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d42:
	/* 0x1d42: mov    r11d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 0ULL);
x86_l_1d48:
	/* 0x1d48: cmp    edi,0x3dc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 988ULL);
x86_l_1d4e:
	/* 0x1d4e: ja     1d5b <generic_fentry_process_filter+0x1d5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d5b;
	}
x86_l_1d50:
	/* 0x1d50: mov    r11d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RAX, X86_WIDTH_32);
x86_l_1d53:
	/* 0x1d53: and    r11d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1d57:
	/* 0x1d57: mov    r11d,DWORD PTR [rdx+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1d5b:
	/* 0x1d5b: mov    r12d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_32);
x86_l_1d5e:
	/* 0x1d5e: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1d62:
	/* 0x1d62: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1d66:
	/* 0x1d66: ja     1d8b <generic_fentry_process_filter+0x1d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d8b;
	}
x86_l_1d68:
	/* 0x1d68: mov    ebp,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1d6d:
	/* 0x1d6d: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1d71:
	/* 0x1d71: jne    1d78 <generic_fentry_process_filter+0x1d78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d78;
	}
x86_l_1d73:
	/* 0x1d73: cmp    r11d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RBP, X86_WIDTH_32);
x86_l_1d76:
	/* 0x1d76: jne    1d8b <generic_fentry_process_filter+0x1d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d8b;
	}
x86_l_1d78:
	/* 0x1d78: xor    r11d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d7b:
	/* 0x1d7b: mov    ebp,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R9, X86_WIDTH_32);
x86_l_1d7e:
	/* 0x1d7e: xor    ebp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1d81:
	/* 0x1d81: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d84:
	/* 0x1d84: or     ebp,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R11, X86_WIDTH_32, X86_ALU_OR);
x86_l_1d87:
	/* 0x1d87: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_1d8b:
	/* 0x1d8b: add    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1d8e:
	/* 0x1d8e: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_1d91:
	/* 0x1d91: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d93:
	/* 0x1d93: mov    ebp,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 0ULL);
x86_l_1d98:
	/* 0x1d98: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_1d9f:
	/* 0x1d9f: jbe    1e2a <generic_fentry_process_filter+0x1e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e2a;
	}
x86_l_1da5:
	/* 0x1da5: mov    r12d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_32);
x86_l_1da8:
	/* 0x1da8: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1dac:
	/* 0x1dac: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1db0:
	/* 0x1db0: jbe    1e42 <generic_fentry_process_filter+0x1e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e42;
	}
x86_l_1db6:
	/* 0x1db6: jmp    1e65 <generic_fentry_process_filter+0x1e65> */
	return 7781ULL;
x86_l_1dbb:
	/* 0x1dbb: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dbe:
	/* 0x1dbe: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1dc2:
	/* 0x1dc2: sete   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_E);
x86_l_1dc6:
	/* 0x1dc6: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1dc9:
	/* 0x1dc9: je     2043 <generic_fentry_process_filter+0x2043> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8259ULL;
	}
x86_l_1dcf:
	/* 0x1dcf: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1dd2:
	/* 0x1dd2: je     2023 <generic_fentry_process_filter+0x2023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8227ULL;
	}
x86_l_1dd8:
	/* 0x1dd8: mov    r11d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RAX, X86_WIDTH_32);
x86_l_1ddb:
	/* 0x1ddb: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_1dde:
	/* 0x1dde: jne    1d3f <generic_fentry_process_filter+0x1d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d3f;
	}
x86_l_1de4:
	/* 0x1de4: jmp    1d91 <generic_fentry_process_filter+0x1d91> */
	goto x86_l_1d91;
x86_l_1de6:
	/* 0x1de6: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1de9:
	/* 0x1de9: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1dec:
	/* 0x1dec: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dee:
	/* 0x1dee: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1df3:
	/* 0x1df3: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1dfa:
	/* 0x1dfa: jbe    1c54 <generic_fentry_process_filter+0x1c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c54;
	}
x86_l_1e00:
	/* 0x1e00: jmp    1c5d <generic_fentry_process_filter+0x1c5d> */
	goto x86_l_1c5d;
x86_l_1e05:
	/* 0x1e05: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1e07:
	/* 0x1e07: mov    ebp,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_32);
x86_l_1e0a:
	/* 0x1e0a: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1e0d:
	/* 0x1e0d: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1e10:
	/* 0x1e10: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e13:
	/* 0x1e13: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1e18:
	/* 0x1e18: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1e1f:
	/* 0x1e1f: jbe    1ca2 <generic_fentry_process_filter+0x1ca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1ca2;
	}
x86_l_1e25:
	/* 0x1e25: jmp    1caa <generic_fentry_process_filter+0x1caa> */
	goto x86_l_1caa;
x86_l_1e2a:
	/* 0x1e2a: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1e2d:
	/* 0x1e2d: and    r12d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1e31:
	/* 0x1e31: mov    ebp,DWORD PTR [rdx+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1e35:
	/* 0x1e35: mov    r12d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_32);
x86_l_1e38:
	/* 0x1e38: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1e3c:
	/* 0x1e3c: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1e40:
	/* 0x1e40: ja     1e65 <generic_fentry_process_filter+0x1e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7781ULL;
	}
x86_l_1e42:
	/* 0x1e42: mov    r12d,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1e47:
	/* 0x1e47: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1e4b:
	/* 0x1e4b: jne    1e52 <generic_fentry_process_filter+0x1e52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e52;
	}
x86_l_1e4d:
	/* 0x1e4d: cmp    ebp,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_1e50:
	/* 0x1e50: jne    1e65 <generic_fentry_process_filter+0x1e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7781ULL;
	}
x86_l_1e52:
	/* 0x1e52: xor    ebp,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e55:
	/* 0x1e55: mov    r12d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R9, X86_WIDTH_32);
x86_l_1e58:
	/* 0x1e58: xor    r12d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1e5c:
	/* 0x1e5c: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
	return 7774ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7774ULL: goto x86_l_1e5e;
	case 7777ULL: goto x86_l_1e61;
	case 7781ULL: goto x86_l_1e65;
	case 7785ULL: goto x86_l_1e69;
	case 7787ULL: goto x86_l_1e6b;
	case 7793ULL: goto x86_l_1e71;
	case 7800ULL: goto x86_l_1e78;
	case 7802ULL: goto x86_l_1e7a;
	case 7805ULL: goto x86_l_1e7d;
	case 7809ULL: goto x86_l_1e81;
	case 7813ULL: goto x86_l_1e85;
	case 7816ULL: goto x86_l_1e88;
	case 7820ULL: goto x86_l_1e8c;
	case 7824ULL: goto x86_l_1e90;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7835ULL: goto x86_l_1e9b;
	case 7837ULL: goto x86_l_1e9d;
	case 7840ULL: goto x86_l_1ea0;
	case 7842ULL: goto x86_l_1ea2;
	case 7845ULL: goto x86_l_1ea5;
	case 7848ULL: goto x86_l_1ea8;
	case 7852ULL: goto x86_l_1eac;
	case 7854ULL: goto x86_l_1eae;
	case 7857ULL: goto x86_l_1eb1;
	case 7861ULL: goto x86_l_1eb5;
	case 7865ULL: goto x86_l_1eb9;
	case 7868ULL: goto x86_l_1ebc;
	case 7874ULL: goto x86_l_1ec2;
	case 7881ULL: goto x86_l_1ec9;
	case 7883ULL: goto x86_l_1ecb;
	case 7887ULL: goto x86_l_1ecf;
	case 7891ULL: goto x86_l_1ed3;
	case 7895ULL: goto x86_l_1ed7;
	case 7899ULL: goto x86_l_1edb;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7910ULL: goto x86_l_1ee6;
	case 7912ULL: goto x86_l_1ee8;
	case 7915ULL: goto x86_l_1eeb;
	case 7918ULL: goto x86_l_1eee;
	case 7920ULL: goto x86_l_1ef0;
	case 7923ULL: goto x86_l_1ef3;
	case 7926ULL: goto x86_l_1ef6;
	case 7930ULL: goto x86_l_1efa;
	case 7933ULL: goto x86_l_1efd;
	case 7936ULL: goto x86_l_1f00;
	case 7940ULL: goto x86_l_1f04;
	case 7944ULL: goto x86_l_1f08;
	case 7946ULL: goto x86_l_1f0a;
	case 7948ULL: goto x86_l_1f0c;
	case 7951ULL: goto x86_l_1f0f;
	case 7954ULL: goto x86_l_1f12;
	case 7956ULL: goto x86_l_1f14;
	case 7959ULL: goto x86_l_1f17;
	case 7962ULL: goto x86_l_1f1a;
	case 7965ULL: goto x86_l_1f1d;
	case 7967ULL: goto x86_l_1f1f;
	case 7969ULL: goto x86_l_1f21;
	case 7972ULL: goto x86_l_1f24;
	case 7975ULL: goto x86_l_1f27;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7986ULL: goto x86_l_1f32;
	case 7992ULL: goto x86_l_1f38;
	case 7999ULL: goto x86_l_1f3f;
	case 8002ULL: goto x86_l_1f42;
	case 8011ULL: goto x86_l_1f4b;
	case 8019ULL: goto x86_l_1f53;
	case 8027ULL: goto x86_l_1f5b;
	case 8034ULL: goto x86_l_1f62;
	case 8037ULL: goto x86_l_1f65;
	case 8044ULL: goto x86_l_1f6c;
	case 8047ULL: goto x86_l_1f6f;
	case 8049ULL: goto x86_l_1f71;
	case 8051ULL: goto x86_l_1f73;
	case 8055ULL: goto x86_l_1f77;
	case 8059ULL: goto x86_l_1f7b;
	case 8063ULL: goto x86_l_1f7f;
	case 8071ULL: goto x86_l_1f87;
	case 8073ULL: goto x86_l_1f89;
	case 8078ULL: goto x86_l_1f8e;
	case 8085ULL: goto x86_l_1f95;
	case 8088ULL: goto x86_l_1f98;
	case 8090ULL: goto x86_l_1f9a;
	case 8092ULL: goto x86_l_1f9c;
	case 8094ULL: goto x86_l_1f9e;
	case 8098ULL: goto x86_l_1fa2;
	case 8100ULL: goto x86_l_1fa4;
	case 8101ULL: goto x86_l_1fa5;
	case 8106ULL: goto x86_l_1faa;
	case 8111ULL: goto x86_l_1faf;
	case 8118ULL: goto x86_l_1fb6;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8131ULL: goto x86_l_1fc3;
	case 8137ULL: goto x86_l_1fc9;
	case 8140ULL: goto x86_l_1fcc;
	case 8144ULL: goto x86_l_1fd0;
	case 8149ULL: goto x86_l_1fd5;
	case 8154ULL: goto x86_l_1fda;
	case 8157ULL: goto x86_l_1fdd;
	case 8159ULL: goto x86_l_1fdf;
	case 8162ULL: goto x86_l_1fe2;
	case 8168ULL: goto x86_l_1fe8;
	case 8172ULL: goto x86_l_1fec;
	case 8174ULL: goto x86_l_1fee;
	case 8179ULL: goto x86_l_1ff3;
	case 8182ULL: goto x86_l_1ff6;
	case 8188ULL: goto x86_l_1ffc;
	case 8190ULL: goto x86_l_1ffe;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8202ULL: goto x86_l_200a;
	case 8206ULL: goto x86_l_200e;
	case 8209ULL: goto x86_l_2011;
	case 8213ULL: goto x86_l_2015;
	case 8216ULL: goto x86_l_2018;
	case 8222ULL: goto x86_l_201e;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8233ULL: goto x86_l_2029;
	case 8235ULL: goto x86_l_202b;
	case 8241ULL: goto x86_l_2031;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8262ULL: goto x86_l_2046;
	case 8265ULL: goto x86_l_2049;
	case 8268ULL: goto x86_l_204c;
	case 8271ULL: goto x86_l_204f;
	case 8277ULL: goto x86_l_2055;
	case 8284ULL: goto x86_l_205c;
	case 8290ULL: goto x86_l_2062;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1e5e:
	/* 0x1e5e: or     r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e61:
	/* 0x1e61: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1e65:
	/* 0x1e65: add    r11d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1e69:
	/* 0x1e69: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e6b:
	/* 0x1e6b: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_1e71:
	/* 0x1e71: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_1e78:
	/* 0x1e78: ja     1e85 <generic_fentry_process_filter+0x1e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e85;
	}
x86_l_1e7a:
	/* 0x1e7a: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1e7d:
	/* 0x1e7d: and    r12d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1e81:
	/* 0x1e81: mov    r12d,DWORD PTR [rdx+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1e85:
	/* 0x1e85: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1e88:
	/* 0x1e88: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1e8c:
	/* 0x1e8c: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1e90:
	/* 0x1e90: ja     1eb5 <generic_fentry_process_filter+0x1eb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1eb5;
	}
x86_l_1e92:
	/* 0x1e92: mov    r13d,DWORD PTR [r14+r13*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 32ULL);
x86_l_1e97:
	/* 0x1e97: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1e9b:
	/* 0x1e9b: jne    1ea2 <generic_fentry_process_filter+0x1ea2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ea2;
	}
x86_l_1e9d:
	/* 0x1e9d: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_1ea0:
	/* 0x1ea0: jne    1eb5 <generic_fentry_process_filter+0x1eb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1eb5;
	}
x86_l_1ea2:
	/* 0x1ea2: xor    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ea5:
	/* 0x1ea5: mov    r13d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_32);
x86_l_1ea8:
	/* 0x1ea8: xor    r13d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1eac:
	/* 0x1eac: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eae:
	/* 0x1eae: or     r13d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_32, X86_ALU_OR);
x86_l_1eb1:
	/* 0x1eb1: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1eb5:
	/* 0x1eb5: add    r11d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1eb9:
	/* 0x1eb9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ebc:
	/* 0x1ebc: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_1ec2:
	/* 0x1ec2: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_1ec9:
	/* 0x1ec9: ja     1ed3 <generic_fentry_process_filter+0x1ed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ed3;
	}
x86_l_1ecb:
	/* 0x1ecb: and    r11d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1ecf:
	/* 0x1ecf: mov    r13d,DWORD PTR [rdx+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1ed3:
	/* 0x1ed3: and    r10d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1ed7:
	/* 0x1ed7: cmp    r10,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 9ULL);
x86_l_1edb:
	/* 0x1edb: ja     1f04 <generic_fentry_process_filter+0x1f04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f04;
	}
x86_l_1edd:
	/* 0x1edd: mov    r10d,DWORD PTR [r14+r10*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 2), 32ULL);
x86_l_1ee2:
	/* 0x1ee2: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1ee6:
	/* 0x1ee6: jne    1ef0 <generic_fentry_process_filter+0x1ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ef0;
	}
x86_l_1ee8:
	/* 0x1ee8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eeb:
	/* 0x1eeb: cmp    r13d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1eee:
	/* 0x1eee: jne    1f14 <generic_fentry_process_filter+0x1f14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f14;
	}
x86_l_1ef0:
	/* 0x1ef0: xor    r13d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ef3:
	/* 0x1ef3: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_1ef6:
	/* 0x1ef6: xor    r10d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1efa:
	/* 0x1efa: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1efd:
	/* 0x1efd: or     r10d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R13, X86_WIDTH_32, X86_ALU_OR);
x86_l_1f00:
	/* 0x1f00: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_1f04:
	/* 0x1f04: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1f08:
	/* 0x1f08: jne    1f14 <generic_fentry_process_filter+0x1f14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f14;
	}
x86_l_1f0a:
	/* 0x1f0a: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1f0c:
	/* 0x1f0c: and    r8d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R12, X86_WIDTH_32, X86_ALU_AND);
x86_l_1f0f:
	/* 0x1f0f: and    ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_AND);
x86_l_1f12:
	/* 0x1f12: jmp    1f1d <generic_fentry_process_filter+0x1f1d> */
	goto x86_l_1f1d;
x86_l_1f14:
	/* 0x1f14: or     r12d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1f17:
	/* 0x1f17: or     ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_1f1a:
	/* 0x1f1a: or     ebp,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_32, X86_ALU_OR);
x86_l_1f1d:
	/* 0x1f1d: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1f1f:
	/* 0x1f1f: je     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5b;
	}
x86_l_1f21:
	/* 0x1f21: and    esi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1f24:
	/* 0x1f24: lea    edi,[rax+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1f27:
	/* 0x1f27: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_1f29:
	/* 0x1f29: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1f2e:
	/* 0x1f2e: cmp    DWORD PTR [rax+rdx*1],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_1f32:
	/* 0x1f32: jne    1fc0 <generic_fentry_process_filter+0x1fc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fc0;
	}
x86_l_1f38:
	/* 0x1f38: mov    rax,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_1f3f:
	/* 0x1f3f: and    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_1f42:
	/* 0x1f42: mov    BYTE PTR [r14+rax*1+0x5ec1],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699073ULL);
x86_l_1f4b:
	/* 0x1f4b: mov    BYTE PTR [r14+0x5ee0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685249ULL);
x86_l_1f53:
	/* 0x1f53: mov    BYTE PTR [r14+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    rax,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_1f62:
	/* 0x1f62: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1f65:
	/* 0x1f65: mov    QWORD PTR [r14+0x5eb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_1f6c:
	/* 0x1f6c: cmp    rax,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1f6f:
	/* 0x1f6f: jbe    1faa <generic_fentry_process_filter+0x1faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1faa;
	}
x86_l_1f71:
	/* 0x1f71: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f73:
	/* 0x1f73: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f77:
	/* 0x1f77: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f7b:
	/* 0x1f7b: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f7f:
	/* 0x1f7f: cmp    BYTE PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_1f87:
	/* 0x1f87: je     1f9c <generic_fentry_process_filter+0x1f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f9c;
	}
x86_l_1f89:
	/* 0x1f89: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1f8e:
	/* 0x1f8e: mov    rsi,QWORD PTR [rip+0x3cbb] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_1f95:
	/* 0x1f95: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f98:
	/* 0x1f98: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f9a:
	/* 0x1f9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9c:
	/* 0x1f9c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f9e:
	/* 0x1f9e: add    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_1fa2:
	/* 0x1fa2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1fa4:
	/* 0x1fa4: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1fa5:
	/* 0x1fa5: jmp    2067 <generic_fentry_process_filter+0x2067> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1faa:
	/* 0x1faa: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1faf:
	/* 0x1faf: mov    rsi,QWORD PTR [rip+0x3cbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_1fb6:
	/* 0x1fb6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1fb9:
	/* 0x1fb9: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1fbe:
	/* 0x1fbe: jmp    1f9a <generic_fentry_process_filter+0x1f9a> */
	goto x86_l_1f9a;
x86_l_1fc0:
	/* 0x1fc0: add    edi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1fc3:
	/* 0x1fc3: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    esi,DWORD PTR [rdi+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1fcc:
	/* 0x1fcc: mov    eax,DWORD PTR [rdi+rdx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_1fd0:
	/* 0x1fd0: mov    r8d,DWORD PTR [rdi+rdx*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 8ULL);
x86_l_1fd5:
	/* 0x1fd5: mov    rdx,QWORD PTR [rdi+rdx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 12ULL);
x86_l_1fda:
	/* 0x1fda: test   r8d,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_32);
x86_l_1fdd:
	/* 0x1fdd: je     1ff3 <generic_fentry_process_filter+0x1ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff3;
	}
x86_l_1fdf:
	/* 0x1fdf: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1fe2:
	/* 0x1fe2: ja     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f5b;
	}
x86_l_1fe8:
	/* 0x1fe8: cmp    DWORD PTR [r14+0x44],r8d */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1fec:
	/* 0x1fec: jne    1ffc <generic_fentry_process_filter+0x1ffc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ffc;
	}
x86_l_1fee:
	/* 0x1fee: jmp    1f5b <generic_fentry_process_filter+0x1f5b> */
	goto x86_l_1f5b;
x86_l_1ff3:
	/* 0x1ff3: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1ff6:
	/* 0x1ff6: ja     1f5b <generic_fentry_process_filter+0x1f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f5b;
	}
x86_l_1ffc:
	/* 0x1ffc: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ffe:
	/* 0x1ffe: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2001:
	/* 0x2001: test   QWORD PTR [r14+rsi*8+0x48],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 3), 72ULL);
x86_l_2006:
	/* 0x2006: sete   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_E);
x86_l_200a:
	/* 0x200a: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_200e:
	/* 0x200e: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2011:
	/* 0x2011: cmove  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_E);
x86_l_2015:
	/* 0x2015: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_2018:
	/* 0x2018: je     1f38 <generic_fentry_process_filter+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f38;
	}
x86_l_201e:
	/* 0x201e: jmp    1f5b <generic_fentry_process_filter+0x1f5b> */
	goto x86_l_1f5b;
x86_l_2023:
	/* 0x2023: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_2026:
	/* 0x2026: mov    r11d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RAX, X86_WIDTH_32);
x86_l_2029:
	/* 0x2029: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_202b:
	/* 0x202b: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_2031:
	/* 0x2031: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_2038:
	/* 0x2038: jbe    1e7a <generic_fentry_process_filter+0x1e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e7a;
	}
x86_l_203e:
	/* 0x203e: jmp    1e85 <generic_fentry_process_filter+0x1e85> */
	goto x86_l_1e85;
x86_l_2043:
	/* 0x2043: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_2046:
	/* 0x2046: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_2049:
	/* 0x2049: mov    r11d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RAX, X86_WIDTH_32);
x86_l_204c:
	/* 0x204c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_204f:
	/* 0x204f: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_2055:
	/* 0x2055: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_205c:
	/* 0x205c: jbe    1ecb <generic_fentry_process_filter+0x1ecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1ecb;
	}
x86_l_2062:
	/* 0x2062: jmp    1ed3 <generic_fentry_process_filter+0x1ed3> */
	goto x86_l_1ed3;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 8220U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1634ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1637ULL && __x86_pc <= 3263ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3265ULL && __x86_pc <= 4868ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4875ULL && __x86_pc <= 6362ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6367ULL && __x86_pc <= 7772ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 7774ULL && __x86_pc <= 8290ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_process_filter_x86_chunk_5(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

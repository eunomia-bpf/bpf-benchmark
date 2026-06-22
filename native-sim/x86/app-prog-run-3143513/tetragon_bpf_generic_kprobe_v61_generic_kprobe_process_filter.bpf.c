extern char CONFIG_ITER_NUM;
extern char PARENTS_MAP_ENABLED;
extern char buffer_heap_map;
extern char execve_map;
extern char filter_map;
extern char kprobe_calls;
extern char process_call_heap;
extern char string_maps_heap;
extern char string_postfix_maps;
extern char string_postfix_maps_heap;
extern char string_prefix_maps;
extern char tg_errmetrics_map;
extern char tg_mb_paths;
extern char tg_mb_sel_opts;
extern char tg_mbset_gen;
extern char tg_mbset_map;
extern char tg_parents_bin;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_0(
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
	case 63ULL: goto x86_l_3f;
	case 65ULL: goto x86_l_41;
	case 68ULL: goto x86_l_44;
	case 73ULL: goto x86_l_49;
	case 80ULL: goto x86_l_50;
	case 85ULL: goto x86_l_55;
	case 90ULL: goto x86_l_5a;
	case 95ULL: goto x86_l_5f;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 112ULL: goto x86_l_70;
	case 116ULL: goto x86_l_74;
	case 120ULL: goto x86_l_78;
	case 127ULL: goto x86_l_7f;
	case 132ULL: goto x86_l_84;
	case 137ULL: goto x86_l_89;
	case 139ULL: goto x86_l_8b;
	case 142ULL: goto x86_l_8e;
	case 144ULL: goto x86_l_90;
	case 147ULL: goto x86_l_93;
	case 152ULL: goto x86_l_98;
	case 158ULL: goto x86_l_9e;
	case 163ULL: goto x86_l_a3;
	case 168ULL: goto x86_l_a8;
	case 171ULL: goto x86_l_ab;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 186ULL: goto x86_l_ba;
	case 191ULL: goto x86_l_bf;
	case 196ULL: goto x86_l_c4;
	case 198ULL: goto x86_l_c6;
	case 203ULL: goto x86_l_cb;
	case 206ULL: goto x86_l_ce;
	case 212ULL: goto x86_l_d4;
	case 219ULL: goto x86_l_db;
	case 224ULL: goto x86_l_e0;
	case 229ULL: goto x86_l_e5;
	case 234ULL: goto x86_l_ea;
	case 239ULL: goto x86_l_ef;
	case 244ULL: goto x86_l_f4;
	case 249ULL: goto x86_l_f9;
	case 251ULL: goto x86_l_fb;
	case 255ULL: goto x86_l_ff;
	case 259ULL: goto x86_l_103;
	case 266ULL: goto x86_l_10a;
	case 271ULL: goto x86_l_10f;
	case 276ULL: goto x86_l_114;
	case 278ULL: goto x86_l_116;
	case 281ULL: goto x86_l_119;
	case 283ULL: goto x86_l_11b;
	case 286ULL: goto x86_l_11e;
	case 291ULL: goto x86_l_123;
	case 297ULL: goto x86_l_129;
	case 302ULL: goto x86_l_12e;
	case 307ULL: goto x86_l_133;
	case 310ULL: goto x86_l_136;
	case 315ULL: goto x86_l_13b;
	case 320ULL: goto x86_l_140;
	case 325ULL: goto x86_l_145;
	case 330ULL: goto x86_l_14a;
	case 335ULL: goto x86_l_14f;
	case 337ULL: goto x86_l_151;
	case 342ULL: goto x86_l_156;
	case 345ULL: goto x86_l_159;
	case 351ULL: goto x86_l_15f;
	case 358ULL: goto x86_l_166;
	case 363ULL: goto x86_l_16b;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 378ULL: goto x86_l_17a;
	case 383ULL: goto x86_l_17f;
	case 388ULL: goto x86_l_184;
	case 390ULL: goto x86_l_186;
	case 394ULL: goto x86_l_18a;
	case 398ULL: goto x86_l_18e;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 415ULL: goto x86_l_19f;
	case 417ULL: goto x86_l_1a1;
	case 420ULL: goto x86_l_1a4;
	case 422ULL: goto x86_l_1a6;
	case 425ULL: goto x86_l_1a9;
	case 430ULL: goto x86_l_1ae;
	case 436ULL: goto x86_l_1b4;
	case 441ULL: goto x86_l_1b9;
	case 446ULL: goto x86_l_1be;
	case 449ULL: goto x86_l_1c1;
	case 454ULL: goto x86_l_1c6;
	case 459ULL: goto x86_l_1cb;
	case 464ULL: goto x86_l_1d0;
	case 469ULL: goto x86_l_1d5;
	case 474ULL: goto x86_l_1da;
	case 476ULL: goto x86_l_1dc;
	case 481ULL: goto x86_l_1e1;
	case 484ULL: goto x86_l_1e4;
	case 490ULL: goto x86_l_1ea;
	case 497ULL: goto x86_l_1f1;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 517ULL: goto x86_l_205;
	case 522ULL: goto x86_l_20a;
	case 527ULL: goto x86_l_20f;
	case 529ULL: goto x86_l_211;
	case 533ULL: goto x86_l_215;
	case 537ULL: goto x86_l_219;
	case 544ULL: goto x86_l_220;
	case 549ULL: goto x86_l_225;
	case 554ULL: goto x86_l_22a;
	case 556ULL: goto x86_l_22c;
	case 559ULL: goto x86_l_22f;
	case 561ULL: goto x86_l_231;
	case 564ULL: goto x86_l_234;
	case 569ULL: goto x86_l_239;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 585ULL: goto x86_l_249;
	case 588ULL: goto x86_l_24c;
	case 593ULL: goto x86_l_251;
	case 598ULL: goto x86_l_256;
	case 603ULL: goto x86_l_25b;
	case 608ULL: goto x86_l_260;
	case 613ULL: goto x86_l_265;
	case 615ULL: goto x86_l_267;
	case 620ULL: goto x86_l_26c;
	case 622ULL: goto x86_l_26e;
	case 625ULL: goto x86_l_271;
	case 632ULL: goto x86_l_278;
	case 637ULL: goto x86_l_27d;
	case 642ULL: goto x86_l_282;
	case 647ULL: goto x86_l_287;
	case 653ULL: goto x86_l_28d;
	case 658ULL: goto x86_l_292;
	case 660ULL: goto x86_l_294;
	case 664ULL: goto x86_l_298;
	case 672ULL: goto x86_l_2a0;
	case 677ULL: goto x86_l_2a5;
	case 679ULL: goto x86_l_2a7;
	case 687ULL: goto x86_l_2af;
	case 699ULL: goto x86_l_2bb;
	case 711ULL: goto x86_l_2c7;
	case 723ULL: goto x86_l_2d3;
	case 727ULL: goto x86_l_2d7;
	case 732ULL: goto x86_l_2dc;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 747ULL: goto x86_l_2eb;
	case 749ULL: goto x86_l_2ed;
	case 754ULL: goto x86_l_2f2;
	case 756ULL: goto x86_l_2f4;
	case 759ULL: goto x86_l_2f7;
	case 761ULL: goto x86_l_2f9;
	case 765ULL: goto x86_l_2fd;
	case 770ULL: goto x86_l_302;
	case 775ULL: goto x86_l_307;
	case 780ULL: goto x86_l_30c;
	case 785ULL: goto x86_l_311;
	case 789ULL: goto x86_l_315;
	case 794ULL: goto x86_l_31a;
	case 796ULL: goto x86_l_31c;
	case 800ULL: goto x86_l_320;
	case 802ULL: goto x86_l_322;
	case 804ULL: goto x86_l_324;
	case 809ULL: goto x86_l_329;
	case 812ULL: goto x86_l_32c;
	case 815ULL: goto x86_l_32f;
	case 822ULL: goto x86_l_336;
	case 827ULL: goto x86_l_33b;
	case 832ULL: goto x86_l_340;
	case 837ULL: goto x86_l_345;
	case 842ULL: goto x86_l_34a;
	case 846ULL: goto x86_l_34e;
	case 849ULL: goto x86_l_351;
	case 852ULL: goto x86_l_354;
	case 859ULL: goto x86_l_35b;
	case 864ULL: goto x86_l_360;
	case 866ULL: goto x86_l_362;
	case 870ULL: goto x86_l_366;
	case 878ULL: goto x86_l_36e;
	case 885ULL: goto x86_l_375;
	case 890ULL: goto x86_l_37a;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 908ULL: goto x86_l_38c;
	case 913ULL: goto x86_l_391;
	case 915ULL: goto x86_l_393;
	case 920ULL: goto x86_l_398;
	case 928ULL: goto x86_l_3a0;
	case 932ULL: goto x86_l_3a4;
	case 937ULL: goto x86_l_3a9;
	case 942ULL: goto x86_l_3ae;
	case 947ULL: goto x86_l_3b3;
	case 949ULL: goto x86_l_3b5;
	case 957ULL: goto x86_l_3bd;
	case 961ULL: goto x86_l_3c1;
	case 966ULL: goto x86_l_3c6;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 978ULL: goto x86_l_3d2;
	case 982ULL: goto x86_l_3d6;
	case 987ULL: goto x86_l_3db;
	case 992ULL: goto x86_l_3e0;
	case 995ULL: goto x86_l_3e3;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1005ULL: goto x86_l_3ed;
	case 1013ULL: goto x86_l_3f5;
	case 1020ULL: goto x86_l_3fc;
	case 1025ULL: goto x86_l_401;
	case 1030ULL: goto x86_l_406;
	case 1035ULL: goto x86_l_40b;
	case 1040ULL: goto x86_l_410;
	case 1042ULL: goto x86_l_412;
	case 1047ULL: goto x86_l_417;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1062ULL: goto x86_l_426;
	case 1067ULL: goto x86_l_42b;
	case 1072ULL: goto x86_l_430;
	case 1074ULL: goto x86_l_432;
	case 1079ULL: goto x86_l_437;
	case 1084ULL: goto x86_l_43c;
	case 1087ULL: goto x86_l_43f;
	case 1092ULL: goto x86_l_444;
	case 1097ULL: goto x86_l_449;
	case 1100ULL: goto x86_l_44c;
	case 1105ULL: goto x86_l_451;
	case 1107ULL: goto x86_l_453;
	case 1115ULL: goto x86_l_45b;
	case 1120ULL: goto x86_l_460;
	case 1128ULL: goto x86_l_468;
	case 1131ULL: goto x86_l_46b;
	case 1136ULL: goto x86_l_470;
	case 1144ULL: goto x86_l_478;
	case 1149ULL: goto x86_l_47d;
	case 1151ULL: goto x86_l_47f;
	case 1159ULL: goto x86_l_487;
	case 1167ULL: goto x86_l_48f;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1184ULL: goto x86_l_4a0;
	case 1188ULL: goto x86_l_4a4;
	case 1193ULL: goto x86_l_4a9;
	case 1195ULL: goto x86_l_4ab;
	case 1204ULL: goto x86_l_4b4;
	case 1211ULL: goto x86_l_4bb;
	case 1216ULL: goto x86_l_4c0;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1231ULL: goto x86_l_4cf;
	case 1233ULL: goto x86_l_4d1;
	case 1238ULL: goto x86_l_4d6;
	case 1241ULL: goto x86_l_4d9;
	case 1247ULL: goto x86_l_4df;
	case 1258ULL: goto x86_l_4ea;
	case 1262ULL: goto x86_l_4ee;
	case 1270ULL: goto x86_l_4f6;
	case 1275ULL: goto x86_l_4fb;
	case 1280ULL: goto x86_l_500;
	case 1285ULL: goto x86_l_505;
	case 1289ULL: goto x86_l_509;
	case 1294ULL: goto x86_l_50e;
	case 1296ULL: goto x86_l_510;
	case 1301ULL: goto x86_l_515;
	case 1309ULL: goto x86_l_51d;
	case 1313ULL: goto x86_l_521;
	case 1316ULL: goto x86_l_524;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1338ULL: goto x86_l_53a;
	case 1343ULL: goto x86_l_53f;
	case 1351ULL: goto x86_l_547;
	case 1355ULL: goto x86_l_54b;
	case 1358ULL: goto x86_l_54e;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1372ULL: goto x86_l_55c;
	case 1380ULL: goto x86_l_564;
	case 1385ULL: goto x86_l_569;
	case 1389ULL: goto x86_l_56d;
	case 1394ULL: goto x86_l_572;
	case 1399ULL: goto x86_l_577;
	case 1404ULL: goto x86_l_57c;
	case 1408ULL: goto x86_l_580;
	case 1413ULL: goto x86_l_585;
	case 1415ULL: goto x86_l_587;
	case 1417ULL: goto x86_l_589;
	case 1429ULL: goto x86_l_595;
	case 1437ULL: goto x86_l_59d;
	case 1445ULL: goto x86_l_5a5;
	case 1449ULL: goto x86_l_5a9;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1467ULL: goto x86_l_5bb;
	case 1471ULL: goto x86_l_5bf;
	case 1476ULL: goto x86_l_5c4;
	case 1478ULL: goto x86_l_5c6;
	case 1486ULL: goto x86_l_5ce;
	case 1491ULL: goto x86_l_5d3;
	case 1499ULL: goto x86_l_5db;
	case 1502ULL: goto x86_l_5de;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1527ULL: goto x86_l_5f7;
	case 1535ULL: goto x86_l_5ff;
	case 1543ULL: goto x86_l_607;
	case 1547ULL: goto x86_l_60b;
	case 1552ULL: goto x86_l_610;
	case 1557ULL: goto x86_l_615;
	case 1565ULL: goto x86_l_61d;
	case 1569ULL: goto x86_l_621;
	case 1574ULL: goto x86_l_626;
	case 1576ULL: goto x86_l_628;
	case 1584ULL: goto x86_l_630;
	case 1592ULL: goto x86_l_638;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1606ULL: goto x86_l_646;
	case 1614ULL: goto x86_l_64e;
	case 1618ULL: goto x86_l_652;
	case 1623ULL: goto x86_l_657;
	case 1625ULL: goto x86_l_659;
	case 1633ULL: goto x86_l_661;
	case 1641ULL: goto x86_l_669;
	case 1645ULL: goto x86_l_66d;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1663ULL: goto x86_l_67f;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1674ULL: goto x86_l_68a;
	case 1683ULL: goto x86_l_693;
	case 1690ULL: goto x86_l_69a;
	case 1695ULL: goto x86_l_69f;
	case 1700ULL: goto x86_l_6a4;
	case 1705ULL: goto x86_l_6a9;
	case 1710ULL: goto x86_l_6ae;
	case 1713ULL: goto x86_l_6b1;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1728ULL: goto x86_l_6c0;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
	case 1743ULL: goto x86_l_6cf;
	case 1748ULL: goto x86_l_6d4;
	case 1753ULL: goto x86_l_6d9;
	case 1755ULL: goto x86_l_6db;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1798ULL: goto x86_l_706;
	case 1807ULL: goto x86_l_70f;
	case 1809ULL: goto x86_l_711;
	case 1818ULL: goto x86_l_71a;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1851ULL: goto x86_l_73b;
	case 1856ULL: goto x86_l_740;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_a:
	/* 0xa: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x36c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
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
	/* 0x31: je     2572 <generic_kprobe_process_filter+0x2572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9586ULL;
	}
x86_l_37:
	/* 0x37: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_3f:
	/* 0x3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41:
	/* 0x41: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_44:
	/* 0x44: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_49:
	/* 0x49: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_50:
	/* 0x50: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_55:
	/* 0x55: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_5a:
	/* 0x5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f:
	/* 0x5f: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_64:
	/* 0x64: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_69:
	/* 0x69: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6e:
	/* 0x6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70:
	/* 0x70: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_74:
	/* 0x74: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_78:
	/* 0x78: mov    rdi,QWORD PTR [rip+0x36c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_7f:
	/* 0x7f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_84:
	/* 0x84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_89:
	/* 0x89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b:
	/* 0x8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8e:
	/* 0x8e: je     9e <generic_kprobe_process_filter+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9e;
	}
x86_l_90:
	/* 0x90: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_93:
	/* 0x93: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_98:
	/* 0x98: jne    ebe <generic_kprobe_process_filter+0xebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3774ULL;
	}
x86_l_9e:
	/* 0x9e: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_a3:
	/* 0xa3: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a8:
	/* 0xa8: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ab:
	/* 0xab: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b0:
	/* 0xb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b5:
	/* 0xb5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ba:
	/* 0xba: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_bf:
	/* 0xbf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c4:
	/* 0xc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6:
	/* 0xc6: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cb:
	/* 0xcb: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_ce:
	/* 0xce: je     267 <generic_kprobe_process_filter+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_267;
	}
x86_l_d4:
	/* 0xd4: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_db:
	/* 0xdb: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e0:
	/* 0xe0: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_e5:
	/* 0xe5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea:
	/* 0xea: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_ef:
	/* 0xef: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_f4:
	/* 0xf4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f9:
	/* 0xf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb:
	/* 0xfb: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ff:
	/* 0xff: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_103:
	/* 0x103: mov    rdi,QWORD PTR [rip+0x36c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_10a:
	/* 0x10a: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10f:
	/* 0x10f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_114:
	/* 0x114: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116:
	/* 0x116: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_119:
	/* 0x119: je     129 <generic_kprobe_process_filter+0x129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_129;
	}
x86_l_11b:
	/* 0x11b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_11e:
	/* 0x11e: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_123:
	/* 0x123: jne    ebe <generic_kprobe_process_filter+0xebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3774ULL;
	}
x86_l_129:
	/* 0x129: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_12e:
	/* 0x12e: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_133:
	/* 0x133: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_136:
	/* 0x136: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13b:
	/* 0x13b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_140:
	/* 0x140: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_145:
	/* 0x145: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_14a:
	/* 0x14a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14f:
	/* 0x14f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151:
	/* 0x151: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_156:
	/* 0x156: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_159:
	/* 0x159: je     267 <generic_kprobe_process_filter+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_267;
	}
x86_l_15f:
	/* 0x15f: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_166:
	/* 0x166: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16b:
	/* 0x16b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_170:
	/* 0x170: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_175:
	/* 0x175: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_17a:
	/* 0x17a: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_17f:
	/* 0x17f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_184:
	/* 0x184: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186:
	/* 0x186: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18a:
	/* 0x18a: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18e:
	/* 0x18e: mov    rdi,QWORD PTR [rip+0x36c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_195:
	/* 0x195: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19a:
	/* 0x19a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19f:
	/* 0x19f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1:
	/* 0x1a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a4:
	/* 0x1a4: je     1b4 <generic_kprobe_process_filter+0x1b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b4;
	}
x86_l_1a6:
	/* 0x1a6: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a9:
	/* 0x1a9: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1ae:
	/* 0x1ae: jne    ebe <generic_kprobe_process_filter+0xebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3774ULL;
	}
x86_l_1b4:
	/* 0x1b4: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_1b9:
	/* 0x1b9: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1be:
	/* 0x1be: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c1:
	/* 0x1c1: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c6:
	/* 0x1c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cb:
	/* 0x1cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d0:
	/* 0x1d0: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_1d5:
	/* 0x1d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da:
	/* 0x1da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc:
	/* 0x1dc: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e1:
	/* 0x1e1: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1e4:
	/* 0x1e4: je     267 <generic_kprobe_process_filter+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_267;
	}
x86_l_1ea:
	/* 0x1ea: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_1f1:
	/* 0x1f1: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f6:
	/* 0x1f6: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1fb:
	/* 0x1fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_200:
	/* 0x200: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_205:
	/* 0x205: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_20a:
	/* 0x20a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20f:
	/* 0x20f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211:
	/* 0x211: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_215:
	/* 0x215: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_219:
	/* 0x219: mov    rdi,QWORD PTR [rip+0x36c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_220:
	/* 0x220: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_225:
	/* 0x225: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22a:
	/* 0x22a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c:
	/* 0x22c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22f:
	/* 0x22f: je     23f <generic_kprobe_process_filter+0x23f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f;
	}
x86_l_231:
	/* 0x231: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_234:
	/* 0x234: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_239:
	/* 0x239: jne    ebe <generic_kprobe_process_filter+0xebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3774ULL;
	}
x86_l_23f:
	/* 0x23f: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_244:
	/* 0x244: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_249:
	/* 0x249: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24c:
	/* 0x24c: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_251:
	/* 0x251: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_256:
	/* 0x256: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25b:
	/* 0x25b: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_260:
	/* 0x260: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_265:
	/* 0x265: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_267:
	/* 0x267: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_26c:
	/* 0x26c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e:
	/* 0x26e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_271:
	/* 0x271: lea    rdx,[rax+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_278:
	/* 0x278: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_27d:
	/* 0x27d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_282:
	/* 0x282: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_287:
	/* 0x287: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_28d:
	/* 0x28d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_292:
	/* 0x292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294:
	/* 0x294: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_298:
	/* 0x298: mov    DWORD PTR [r12+0x5f10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24336ULL);
x86_l_2a0:
	/* 0x2a0: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2a5:
	/* 0x2a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7:
	/* 0x2a7: mov    QWORD PTR [r12+0x5f18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24344ULL);
x86_l_2af:
	/* 0x2af: mov    DWORD PTR [r12+0x5f20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104591043592192ULL);
x86_l_2bb:
	/* 0x2bb: mov    QWORD PTR [r12+0x5f28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104625403330560ULL);
x86_l_2c7:
	/* 0x2c7: mov    DWORD PTR [r12+0x5f30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104659763068928ULL);
x86_l_2d3:
	/* 0x2d3: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d7:
	/* 0x2d7: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2dc:
	/* 0x2dc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e1:
	/* 0x2e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e6:
	/* 0x2e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb:
	/* 0x2eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed:
	/* 0x2ed: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f2:
	/* 0x2f2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4:
	/* 0x2f4: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2f7:
	/* 0x2f7: je     366 <generic_kprobe_process_filter+0x366> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_366;
	}
x86_l_2f9:
	/* 0x2f9: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2fd:
	/* 0x2fd: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_302:
	/* 0x302: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_307:
	/* 0x307: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30c:
	/* 0x30c: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_311:
	/* 0x311: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_315:
	/* 0x315: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31a:
	/* 0x31a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c:
	/* 0x31c: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_320:
	/* 0x320: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_322:
	/* 0x322: je     366 <generic_kprobe_process_filter+0x366> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_366;
	}
x86_l_324:
	/* 0x324: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_329:
	/* 0x329: shl    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_32c:
	/* 0x32c: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32f:
	/* 0x32f: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_336:
	/* 0x336: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_33b:
	/* 0x33b: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_340:
	/* 0x340: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_345:
	/* 0x345: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_34a:
	/* 0x34a: mov    edx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_34e:
	/* 0x34e: shl    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_351:
	/* 0x351: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_354:
	/* 0x354: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_35b:
	/* 0x35b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_360:
	/* 0x360: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_362:
	/* 0x362: mov    ebx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_366:
	/* 0x366: mov    DWORD PTR [r12+0x5f34],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24372ULL);
x86_l_36e:
	/* 0x36e: lea    rdx,[r13+0xce0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3296ULL);
x86_l_375:
	/* 0x375: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_37a:
	/* 0x37a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37f:
	/* 0x37f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_384:
	/* 0x384: lea    rbx,[r12+0x5f60] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24416ULL);
x86_l_38c:
	/* 0x38c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_391:
	/* 0x391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_393:
	/* 0x393: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_398:
	/* 0x398: lea    rdi,[r12+0x5f68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24424ULL);
x86_l_3a0:
	/* 0x3a0: lea    rdx,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3a4:
	/* 0x3a4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a9:
	/* 0x3a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ae:
	/* 0x3ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b3:
	/* 0x3b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b5:
	/* 0x3b5: lea    rdi,[r12+0x5f70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24432ULL);
x86_l_3bd:
	/* 0x3bd: lea    rdx,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c1:
	/* 0x3c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c6:
	/* 0x3c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cb:
	/* 0x3cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d0:
	/* 0x3d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d2:
	/* 0x3d2: add    r15,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_3d6:
	/* 0x3d6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3db:
	/* 0x3db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e0:
	/* 0x3e0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3e3:
	/* 0x3e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e8:
	/* 0x3e8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3eb:
	/* 0x3eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ed:
	/* 0x3ed: lea    rbx,[r12+0x5f38] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24376ULL);
x86_l_3f5:
	/* 0x3f5: lea    rdx,[r13+0xd48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_3fc:
	/* 0x3fc: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_401:
	/* 0x401: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_406:
	/* 0x406: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40b:
	/* 0x40b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_410:
	/* 0x410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_412:
	/* 0x412: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_417:
	/* 0x417: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_41c:
	/* 0x41c: mov    edx,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 72ULL);
x86_l_421:
	/* 0x421: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_426:
	/* 0x426: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_42b:
	/* 0x42b: mov    esi,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 72ULL);
x86_l_430:
	/* 0x430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_432:
	/* 0x432: mov    edx,0x1a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 424ULL);
x86_l_437:
	/* 0x437: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_43c:
	/* 0x43c: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_43f:
	/* 0x43f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_444:
	/* 0x444: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_449:
	/* 0x449: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_44c:
	/* 0x44c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_451:
	/* 0x451: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_453:
	/* 0x453: lea    rdi,[r12+0x5f3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24380ULL);
x86_l_45b:
	/* 0x45b: mov    edx,0x470 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1136ULL);
x86_l_460:
	/* 0x460: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_468:
	/* 0x468: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_46b:
	/* 0x46b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_470:
	/* 0x470: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_478:
	/* 0x478: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_47d:
	/* 0x47d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47f:
	/* 0x47f: lea    rdi,[r12+0x5f40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24384ULL);
x86_l_487:
	/* 0x487: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_48f:
	/* 0x48f: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_493:
	/* 0x493: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_498:
	/* 0x498: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4a0:
	/* 0x4a0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a4:
	/* 0x4a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a9:
	/* 0x4a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ab:
	/* 0x4ab: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4b4:
	/* 0x4b4: lea    rdx,[r13+0xb38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_4bb:
	/* 0x4bb: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4c0:
	/* 0x4c0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4c5:
	/* 0x4c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ca:
	/* 0x4ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cf:
	/* 0x4cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d1:
	/* 0x4d1: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4d6:
	/* 0x4d6: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_4d9:
	/* 0x4d9: je     589 <generic_kprobe_process_filter+0x589> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_589;
	}
x86_l_4df:
	/* 0x4df: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_4ea:
	/* 0x4ea: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4ee:
	/* 0x4ee: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4f6:
	/* 0x4f6: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4fb:
	/* 0x4fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_500:
	/* 0x500: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_505:
	/* 0x505: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_509:
	/* 0x509: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_50e:
	/* 0x50e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_510:
	/* 0x510: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_515:
	/* 0x515: movsxd rcx,DWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 200ULL);
x86_l_51d:
	/* 0x51d: shl    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_521:
	/* 0x521: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_524:
	/* 0x524: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_52b:
	/* 0x52b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_530:
	/* 0x530: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_535:
	/* 0x535: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53a:
	/* 0x53a: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_53f:
	/* 0x53f: movsxd rdx,DWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 200ULL);
x86_l_547:
	/* 0x547: shl    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_54b:
	/* 0x54b: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_54e:
	/* 0x54e: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_555:
	/* 0x555: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_55a:
	/* 0x55a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55c:
	/* 0x55c: lea    rdi,[r12+0x5f44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24388ULL);
x86_l_564:
	/* 0x564: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_569:
	/* 0x569: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_56d:
	/* 0x56d: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_572:
	/* 0x572: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_577:
	/* 0x577: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_57c:
	/* 0x57c: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_580:
	/* 0x580: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_585:
	/* 0x585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_587:
	/* 0x587: jmp    595 <generic_kprobe_process_filter+0x595> */
	goto x86_l_595;
x86_l_589:
	/* 0x589: mov    DWORD PTR [r12+0x5f44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104745662414848ULL);
x86_l_595:
	/* 0x595: lea    rdi,[r12+0x5f48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24392ULL);
x86_l_59d:
	/* 0x59d: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5a5:
	/* 0x5a5: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_5a9:
	/* 0x5a9: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_5ae:
	/* 0x5ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5b3:
	/* 0x5b3: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5bb:
	/* 0x5bb: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_5bf:
	/* 0x5bf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5c4:
	/* 0x5c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c6:
	/* 0x5c6: lea    rdi,[r12+0x5f4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24396ULL);
x86_l_5ce:
	/* 0x5ce: mov    edx,0xa8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 168ULL);
x86_l_5d3:
	/* 0x5d3: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_5db:
	/* 0x5db: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5de:
	/* 0x5de: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5e3:
	/* 0x5e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e8:
	/* 0x5e8: add    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_5f0:
	/* 0x5f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5f5:
	/* 0x5f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f7:
	/* 0x5f7: lea    rdi,[r12+0x5f50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24400ULL);
x86_l_5ff:
	/* 0x5ff: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_607:
	/* 0x607: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_60b:
	/* 0x60b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_610:
	/* 0x610: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_615:
	/* 0x615: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_61d:
	/* 0x61d: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_621:
	/* 0x621: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_626:
	/* 0x626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_628:
	/* 0x628: lea    rdi,[r12+0x5f54] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24404ULL);
x86_l_630:
	/* 0x630: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_638:
	/* 0x638: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_63c:
	/* 0x63c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_641:
	/* 0x641: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_646:
	/* 0x646: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_64e:
	/* 0x64e: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_652:
	/* 0x652: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_657:
	/* 0x657: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_659:
	/* 0x659: lea    rdi,[r12+0x5f58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24408ULL);
x86_l_661:
	/* 0x661: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_669:
	/* 0x669: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_66d:
	/* 0x66d: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_672:
	/* 0x672: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_677:
	/* 0x677: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_67f:
	/* 0x67f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_683:
	/* 0x683: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_688:
	/* 0x688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68a:
	/* 0x68a: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_693:
	/* 0x693: add    r13,0xa50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2640ULL);
x86_l_69a:
	/* 0x69a: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_69f:
	/* 0x69f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6a4:
	/* 0x6a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6a9:
	/* 0x6a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ae:
	/* 0x6ae: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6b1:
	/* 0x6b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b3:
	/* 0x6b3: mov    edx,0x4a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1184ULL);
x86_l_6b8:
	/* 0x6b8: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6bd:
	/* 0x6bd: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6c0:
	/* 0x6c0: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6c5:
	/* 0x6c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ca:
	/* 0x6ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6cf:
	/* 0x6cf: add    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_6d4:
	/* 0x6d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d9:
	/* 0x6d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6db:
	/* 0x6db: lea    rdi,[r12+0x5f5c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24412ULL);
x86_l_6e3:
	/* 0x6e3: mov    edx,0xe8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 232ULL);
x86_l_6e8:
	/* 0x6e8: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6ed:
	/* 0x6ed: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6f0:
	/* 0x6f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6f5:
	/* 0x6f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6fa:
	/* 0x6fa: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_6ff:
	/* 0x6ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_704:
	/* 0x704: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_706:
	/* 0x706: cmp    DWORD PTR [r12+0x5f34],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104676942938113ULL);
x86_l_70f:
	/* 0x70f: jne    71a <generic_kprobe_process_filter+0x71a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_71a;
	}
x86_l_711:
	/* 0x711: or     BYTE PTR [r12+0x5f33],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 104672647970818ULL);
x86_l_71a:
	/* 0x71a: lea    rdi,[r12+0x5f78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24440ULL);
x86_l_722:
	/* 0x722: mov    edx,0x308 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 776ULL);
x86_l_727:
	/* 0x727: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_72c:
	/* 0x72c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_72e:
	/* 0x72e: call   3df6 <cwd_read_v61+0x1853> */
	X86_SIM_L_EXEC_CALL_MEMSET(776ULL);
x86_l_733:
	/* 0x733: lea    rax,[r12+0x6290] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25232ULL);
x86_l_73b:
	/* 0x73b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_740:
	/* 0x740: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
	return 1861ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1879ULL: goto x86_l_757;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1891ULL: goto x86_l_763;
	case 1894ULL: goto x86_l_766;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1919ULL: goto x86_l_77f;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1937ULL: goto x86_l_791;
	case 1944ULL: goto x86_l_798;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1959ULL: goto x86_l_7a7;
	case 1962ULL: goto x86_l_7aa;
	case 1965ULL: goto x86_l_7ad;
	case 1971ULL: goto x86_l_7b3;
	case 1974ULL: goto x86_l_7b6;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1997ULL: goto x86_l_7cd;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2011ULL: goto x86_l_7db;
	case 2018ULL: goto x86_l_7e2;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2043ULL: goto x86_l_7fb;
	case 2051ULL: goto x86_l_803;
	case 2055ULL: goto x86_l_807;
	case 2063ULL: goto x86_l_80f;
	case 2068ULL: goto x86_l_814;
	case 2073ULL: goto x86_l_819;
	case 2078ULL: goto x86_l_81e;
	case 2081ULL: goto x86_l_821;
	case 2083ULL: goto x86_l_823;
	case 2091ULL: goto x86_l_82b;
	case 2095ULL: goto x86_l_82f;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2110ULL: goto x86_l_83e;
	case 2115ULL: goto x86_l_843;
	case 2117ULL: goto x86_l_845;
	case 2123ULL: goto x86_l_84b;
	case 2129ULL: goto x86_l_851;
	case 2138ULL: goto x86_l_85a;
	case 2147ULL: goto x86_l_863;
	case 2155ULL: goto x86_l_86b;
	case 2167ULL: goto x86_l_877;
	case 2179ULL: goto x86_l_883;
	case 2191ULL: goto x86_l_88f;
	case 2199ULL: goto x86_l_897;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2218ULL: goto x86_l_8aa;
	case 2225ULL: goto x86_l_8b1;
	case 2229ULL: goto x86_l_8b5;
	case 2237ULL: goto x86_l_8bd;
	case 2241ULL: goto x86_l_8c1;
	case 2246ULL: goto x86_l_8c6;
	case 2251ULL: goto x86_l_8cb;
	case 2256ULL: goto x86_l_8d0;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2273ULL: goto x86_l_8e1;
	case 2278ULL: goto x86_l_8e6;
	case 2281ULL: goto x86_l_8e9;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2293ULL: goto x86_l_8f5;
	case 2296ULL: goto x86_l_8f8;
	case 2301ULL: goto x86_l_8fd;
	case 2304ULL: goto x86_l_900;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2327ULL: goto x86_l_917;
	case 2329ULL: goto x86_l_919;
	case 2334ULL: goto x86_l_91e;
	case 2339ULL: goto x86_l_923;
	case 2347ULL: goto x86_l_92b;
	case 2352ULL: goto x86_l_930;
	case 2355ULL: goto x86_l_933;
	case 2357ULL: goto x86_l_935;
	case 2365ULL: goto x86_l_93d;
	case 2369ULL: goto x86_l_941;
	case 2377ULL: goto x86_l_949;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2393ULL: goto x86_l_959;
	case 2399ULL: goto x86_l_95f;
	case 2404ULL: goto x86_l_964;
	case 2409ULL: goto x86_l_969;
	case 2417ULL: goto x86_l_971;
	case 2425ULL: goto x86_l_979;
	case 2433ULL: goto x86_l_981;
	case 2438ULL: goto x86_l_986;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2471ULL: goto x86_l_9a7;
	case 2479ULL: goto x86_l_9af;
	case 2485ULL: goto x86_l_9b5;
	case 2489ULL: goto x86_l_9b9;
	case 2494ULL: goto x86_l_9be;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2505ULL: goto x86_l_9c9;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2536ULL: goto x86_l_9e8;
	case 2538ULL: goto x86_l_9ea;
	case 2542ULL: goto x86_l_9ee;
	case 2547ULL: goto x86_l_9f3;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2562ULL: goto x86_l_a02;
	case 2565ULL: goto x86_l_a05;
	case 2567ULL: goto x86_l_a07;
	case 2575ULL: goto x86_l_a0f;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2591ULL: goto x86_l_a1f;
	case 2599ULL: goto x86_l_a27;
	case 2602ULL: goto x86_l_a2a;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2613ULL: goto x86_l_a35;
	case 2618ULL: goto x86_l_a3a;
	case 2620ULL: goto x86_l_a3c;
	case 2623ULL: goto x86_l_a3f;
	case 2627ULL: goto x86_l_a43;
	case 2630ULL: goto x86_l_a46;
	case 2634ULL: goto x86_l_a4a;
	case 2636ULL: goto x86_l_a4c;
	case 2639ULL: goto x86_l_a4f;
	case 2641ULL: goto x86_l_a51;
	case 2648ULL: goto x86_l_a58;
	case 2651ULL: goto x86_l_a5b;
	case 2657ULL: goto x86_l_a61;
	case 2663ULL: goto x86_l_a67;
	case 2669ULL: goto x86_l_a6d;
	case 2672ULL: goto x86_l_a70;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2684ULL: goto x86_l_a7c;
	case 2688ULL: goto x86_l_a80;
	case 2691ULL: goto x86_l_a83;
	case 2694ULL: goto x86_l_a86;
	case 2697ULL: goto x86_l_a89;
	case 2702ULL: goto x86_l_a8e;
	case 2704ULL: goto x86_l_a90;
	case 2712ULL: goto x86_l_a98;
	case 2715ULL: goto x86_l_a9b;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2734ULL: goto x86_l_aae;
	case 2737ULL: goto x86_l_ab1;
	case 2743ULL: goto x86_l_ab7;
	case 2748ULL: goto x86_l_abc;
	case 2753ULL: goto x86_l_ac1;
	case 2758ULL: goto x86_l_ac6;
	case 2761ULL: goto x86_l_ac9;
	case 2766ULL: goto x86_l_ace;
	case 2768ULL: goto x86_l_ad0;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2787ULL: goto x86_l_ae3;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2812ULL: goto x86_l_afc;
	case 2814ULL: goto x86_l_afe;
	case 2819ULL: goto x86_l_b03;
	case 2827ULL: goto x86_l_b0b;
	case 2831ULL: goto x86_l_b0f;
	case 2839ULL: goto x86_l_b17;
	case 2842ULL: goto x86_l_b1a;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2856ULL: goto x86_l_b28;
	case 2864ULL: goto x86_l_b30;
	case 2870ULL: goto x86_l_b36;
	case 2876ULL: goto x86_l_b3c;
	case 2882ULL: goto x86_l_b42;
	case 2885ULL: goto x86_l_b45;
	case 2893ULL: goto x86_l_b4d;
	case 2898ULL: goto x86_l_b52;
	case 2903ULL: goto x86_l_b57;
	case 2905ULL: goto x86_l_b59;
	case 2907ULL: goto x86_l_b5b;
	case 2910ULL: goto x86_l_b5e;
	case 2913ULL: goto x86_l_b61;
	case 2919ULL: goto x86_l_b67;
	case 2922ULL: goto x86_l_b6a;
	case 2924ULL: goto x86_l_b6c;
	case 2929ULL: goto x86_l_b71;
	case 2936ULL: goto x86_l_b78;
	case 2946ULL: goto x86_l_b82;
	case 2951ULL: goto x86_l_b87;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2968ULL: goto x86_l_b98;
	case 2970ULL: goto x86_l_b9a;
	case 2973ULL: goto x86_l_b9d;
	case 2979ULL: goto x86_l_ba3;
	case 2981ULL: goto x86_l_ba5;
	case 2986ULL: goto x86_l_baa;
	case 2990ULL: goto x86_l_bae;
	case 2995ULL: goto x86_l_bb3;
	case 3000ULL: goto x86_l_bb8;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3012ULL: goto x86_l_bc4;
	case 3017ULL: goto x86_l_bc9;
	case 3023ULL: goto x86_l_bcf;
	case 3028ULL: goto x86_l_bd4;
	case 3034ULL: goto x86_l_bda;
	case 3037ULL: goto x86_l_bdd;
	case 3043ULL: goto x86_l_be3;
	case 3046ULL: goto x86_l_be6;
	case 3052ULL: goto x86_l_bec;
	case 3062ULL: goto x86_l_bf6;
	case 3065ULL: goto x86_l_bf9;
	case 3073ULL: goto x86_l_c01;
	case 3076ULL: goto x86_l_c04;
	case 3081ULL: goto x86_l_c09;
	case 3088ULL: goto x86_l_c10;
	case 3090ULL: goto x86_l_c12;
	case 3095ULL: goto x86_l_c17;
	case 3100ULL: goto x86_l_c1c;
	case 3105ULL: goto x86_l_c21;
	case 3110ULL: goto x86_l_c26;
	case 3112ULL: goto x86_l_c28;
	case 3114ULL: goto x86_l_c2a;
	case 3116ULL: goto x86_l_c2c;
	case 3124ULL: goto x86_l_c34;
	case 3132ULL: goto x86_l_c3c;
	case 3140ULL: goto x86_l_c44;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3150ULL: goto x86_l_c4e;
	case 3152ULL: goto x86_l_c50;
	case 3160ULL: goto x86_l_c58;
	case 3163ULL: goto x86_l_c5b;
	case 3165ULL: goto x86_l_c5d;
	case 3172ULL: goto x86_l_c64;
	case 3180ULL: goto x86_l_c6c;
	case 3188ULL: goto x86_l_c74;
	case 3190ULL: goto x86_l_c76;
	case 3198ULL: goto x86_l_c7e;
	case 3200ULL: goto x86_l_c80;
	case 3205ULL: goto x86_l_c85;
	case 3207ULL: goto x86_l_c87;
	case 3215ULL: goto x86_l_c8f;
	case 3217ULL: goto x86_l_c91;
	case 3220ULL: goto x86_l_c94;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3239ULL: goto x86_l_ca7;
	case 3251ULL: goto x86_l_cb3;
	case 3253ULL: goto x86_l_cb5;
	case 3256ULL: goto x86_l_cb8;
	case 3264ULL: goto x86_l_cc0;
	case 3266ULL: goto x86_l_cc2;
	case 3269ULL: goto x86_l_cc5;
	case 3273ULL: goto x86_l_cc9;
	case 3279ULL: goto x86_l_ccf;
	case 3283ULL: goto x86_l_cd3;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3300ULL: goto x86_l_ce4;
	case 3308ULL: goto x86_l_cec;
	case 3313ULL: goto x86_l_cf1;
	case 3318ULL: goto x86_l_cf6;
	case 3326ULL: goto x86_l_cfe;
	case 3329ULL: goto x86_l_d01;
	case 3331ULL: goto x86_l_d03;
	case 3334ULL: goto x86_l_d06;
	case 3340ULL: goto x86_l_d0c;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3354ULL: goto x86_l_d1a;
	case 3364ULL: goto x86_l_d24;
	case 3369ULL: goto x86_l_d29;
	case 3376ULL: goto x86_l_d30;
	case 3381ULL: goto x86_l_d35;
	case 3386ULL: goto x86_l_d3a;
	case 3388ULL: goto x86_l_d3c;
	case 3391ULL: goto x86_l_d3f;
	case 3397ULL: goto x86_l_d45;
	case 3399ULL: goto x86_l_d47;
	case 3404ULL: goto x86_l_d4c;
	case 3412ULL: goto x86_l_d54;
	case 3419ULL: goto x86_l_d5b;
	case 3421ULL: goto x86_l_d5d;
	case 3426ULL: goto x86_l_d62;
	case 3431ULL: goto x86_l_d67;
	case 3436ULL: goto x86_l_d6c;
	case 3438ULL: goto x86_l_d6e;
	case 3440ULL: goto x86_l_d70;
	case 3443ULL: goto x86_l_d73;
	case 3447ULL: goto x86_l_d77;
	case 3455ULL: goto x86_l_d7f;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3466ULL: goto x86_l_d8a;
	case 3474ULL: goto x86_l_d92;
	case 3482ULL: goto x86_l_d9a;
	case 3487ULL: goto x86_l_d9f;
	case 3489ULL: goto x86_l_da1;
	case 3492ULL: goto x86_l_da4;
	case 3498ULL: goto x86_l_daa;
	case 3500ULL: goto x86_l_dac;
	case 3505ULL: goto x86_l_db1;
	case 3512ULL: goto x86_l_db8;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3534ULL: goto x86_l_dce;
	case 3539ULL: goto x86_l_dd3;
	case 3544ULL: goto x86_l_dd8;
	case 3546ULL: goto x86_l_dda;
	case 3549ULL: goto x86_l_ddd;
	case 3551ULL: goto x86_l_ddf;
	case 3553ULL: goto x86_l_de1;
	case 3558ULL: goto x86_l_de6;
	case 3566ULL: goto x86_l_dee;
	case 3573ULL: goto x86_l_df5;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3592ULL: goto x86_l_e08;
	case 3594ULL: goto x86_l_e0a;
	case 3599ULL: goto x86_l_e0f;
	case 3607ULL: goto x86_l_e17;
	case 3614ULL: goto x86_l_e1e;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3626ULL: goto x86_l_e2a;
	case 3631ULL: goto x86_l_e2f;
	case 3633ULL: goto x86_l_e31;
	case 3635ULL: goto x86_l_e33;
	case 3643ULL: goto x86_l_e3b;
	case 3646ULL: goto x86_l_e3e;
	case 3651ULL: goto x86_l_e43;
	case 3654ULL: goto x86_l_e46;
	case 3657ULL: goto x86_l_e49;
	case 3659ULL: goto x86_l_e4b;
	case 3662ULL: goto x86_l_e4e;
	case 3664ULL: goto x86_l_e50;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3678ULL: goto x86_l_e5e;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3712ULL: goto x86_l_e80;
	case 3715ULL: goto x86_l_e83;
	case 3721ULL: goto x86_l_e89;
	case 3723ULL: goto x86_l_e8b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_745:
	/* 0x745: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_74a:
	/* 0x74a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_74f:
	/* 0x74f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_754:
	/* 0x754: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_757:
	/* 0x757: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_759:
	/* 0x759: mov    edx,0x4a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1192ULL);
x86_l_75e:
	/* 0x75e: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_763:
	/* 0x763: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_766:
	/* 0x766: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_76b:
	/* 0x76b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_770:
	/* 0x770: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_775:
	/* 0x775: add    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_77a:
	/* 0x77a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_77f:
	/* 0x77f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_781:
	/* 0x781: mov    rbx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_786:
	/* 0x786: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_791:
	/* 0x791: mov    rdi,QWORD PTR [rip+0x36c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_798:
	/* 0x798: lea    rsi,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_7a0:
	/* 0x7a0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a5:
	/* 0x7a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a7:
	/* 0x7a7: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_7aa:
	/* 0x7aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ad:
	/* 0x7ad: je     b25 <generic_kprobe_process_filter+0xb25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b25;
	}
x86_l_7b3:
	/* 0x7b3: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_7b6:
	/* 0x7b6: mov    QWORD PTR [rsp+0xb8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_7be:
	/* 0x7be: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7c3:
	/* 0x7c3: mov    DWORD PTR [rcx+0x6410],0x1000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882258432ULL);
x86_l_7cd:
	/* 0x7cd: lea    r13,[rax+0x1000] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_7d4:
	/* 0x7d4: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_7d9:
	/* 0x7d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7db:
	/* 0x7db: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_7e2:
	/* 0x7e2: lea    rdi,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_7ea:
	/* 0x7ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7ef:
	/* 0x7ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7f4:
	/* 0x7f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f9:
	/* 0x7f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fb:
	/* 0x7fb: mov    rbp,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_803:
	/* 0x803: lea    r15,[rbx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_807:
	/* 0x807: lea    rdi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_80f:
	/* 0x80f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_814:
	/* 0x814: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_819:
	/* 0x819: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_81e:
	/* 0x81e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_821:
	/* 0x821: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_823:
	/* 0x823: mov    r14,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_82b:
	/* 0x82b: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_82f:
	/* 0x82f: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_834:
	/* 0x834: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_839:
	/* 0x839: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_83e:
	/* 0x83e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_843:
	/* 0x843: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_845:
	/* 0x845: cmp    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_84b:
	/* 0x84b: je     baa <generic_kprobe_process_filter+0xbaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_baa;
	}
x86_l_851:
	/* 0x851: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_85a:
	/* 0x85a: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_863:
	/* 0x863: mov    QWORD PTR [rsp+0x80],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_86b:
	/* 0x86b: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_877:
	/* 0x877: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_883:
	/* 0x883: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_88f:
	/* 0x88f: mov    QWORD PTR [rsp+0xd0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_897:
	/* 0x897: mov    QWORD PTR [rsp+0xa0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_89f:
	/* 0x89f: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8a4:
	/* 0x8a4: mov    eax,DWORD PTR [rax+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_8aa:
	/* 0x8aa: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_8b1:
	/* 0x8b1: lea    r13,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8b5:
	/* 0x8b5: mov    BYTE PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_8bd:
	/* 0x8bd: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_8c1:
	/* 0x8c1: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8c6:
	/* 0x8c6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8cb:
	/* 0x8cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8d0:
	/* 0x8d0: add    rbx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_8d4:
	/* 0x8d4: lea    r14,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8d9:
	/* 0x8d9: lea    r12,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_8e1:
	/* 0x8e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8e6:
	/* 0x8e6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8e9:
	/* 0x8e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8eb:
	/* 0x8eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8f0:
	/* 0x8f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8f5:
	/* 0x8f5: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_8f8:
	/* 0x8f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8fd:
	/* 0x8fd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_900:
	/* 0x900: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_902:
	/* 0x902: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_907:
	/* 0x907: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_90c:
	/* 0x90c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_90f:
	/* 0x90f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_914:
	/* 0x914: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_917:
	/* 0x917: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_919:
	/* 0x919: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_91e:
	/* 0x91e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_923:
	/* 0x923: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_92b:
	/* 0x92b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_930:
	/* 0x930: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_933:
	/* 0x933: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_935:
	/* 0x935: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_93d:
	/* 0x93d: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_941:
	/* 0x941: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_949:
	/* 0x949: mov    rax,QWORD PTR [rip+0x36c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_950:
	/* 0x950: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_953:
	/* 0x953: je     c09 <generic_kprobe_process_filter+0xc09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c09;
	}
x86_l_959:
	/* 0x959: mov    r14d,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2048ULL);
x86_l_95f:
	/* 0x95f: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_964:
	/* 0x964: lea    rbx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_969:
	/* 0x969: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_971:
	/* 0x971: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_979:
	/* 0x979: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_981:
	/* 0x981: cmp    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_986:
	/* 0x986: jne    993 <generic_kprobe_process_filter+0x993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_993;
	}
x86_l_988:
	/* 0x988: cmp    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 120ULL);
x86_l_98d:
	/* 0x98d: je     c2c <generic_kprobe_process_filter+0xc2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c2c;
	}
x86_l_993:
	/* 0x993: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_998:
	/* 0x998: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_9a0:
	/* 0x9a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a5:
	/* 0x9a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a7:
	/* 0x9a7: cmp    r15,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 200ULL);
x86_l_9af:
	/* 0x9af: je     abc <generic_kprobe_process_filter+0xabc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_abc;
	}
x86_l_9b5:
	/* 0x9b5: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b9:
	/* 0x9b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9be:
	/* 0x9be: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9c1:
	/* 0x9c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9c6:
	/* 0x9c6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_9c9:
	/* 0x9c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9cb:
	/* 0x9cb: cmp    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9d0:
	/* 0x9d0: je     abc <generic_kprobe_process_filter+0xabc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_abc;
	}
x86_l_9d6:
	/* 0x9d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9db:
	/* 0x9db: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9e0:
	/* 0x9e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e5:
	/* 0x9e5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_9e8:
	/* 0x9e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ea:
	/* 0x9ea: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_9ee:
	/* 0x9ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9f3:
	/* 0x9f3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9f8:
	/* 0x9f8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_9fd:
	/* 0x9fd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a02:
	/* 0xa02: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_a05:
	/* 0xa05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a07:
	/* 0xa07: mov    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a0f:
	/* 0xa0f: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a17:
	/* 0xa17: mov    r12d,DWORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_a1c:
	/* 0xa1c: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a1f:
	/* 0xa1f: mov    r13d,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a27:
	/* 0xa27: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_a2a:
	/* 0xa2a: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a2d:
	/* 0xa2d: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_a32:
	/* 0xa32: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_a35:
	/* 0xa35: add    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 88ULL);
x86_l_a3a:
	/* 0xa3a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3c:
	/* 0xa3c: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_a3f:
	/* 0xa3f: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_a43:
	/* 0xa43: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_a46:
	/* 0xa46: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_a4a:
	/* 0xa4a: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a4c:
	/* 0xa4c: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_a4f:
	/* 0xa4f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a51:
	/* 0xa51: mov    DWORD PTR [rsp+0xa8],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a58:
	/* 0xa58: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a5b:
	/* 0xa5b: jb     c34 <generic_kprobe_process_filter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c34;
	}
x86_l_a61:
	/* 0xa61: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_a67:
	/* 0xa67: ja     c34 <generic_kprobe_process_filter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c34;
	}
x86_l_a6d:
	/* 0xa6d: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_a70:
	/* 0xa70: jbe    a77 <generic_kprobe_process_filter+0xa77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_a77;
	}
x86_l_a72:
	/* 0xa72: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_a77:
	/* 0xa77: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a79:
	/* 0xa79: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_a7c:
	/* 0xa7c: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_a80:
	/* 0xa80: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a83:
	/* 0xa83: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a86:
	/* 0xa86: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a89:
	/* 0xa89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a8e:
	/* 0xa8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a90:
	/* 0xa90: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a98:
	/* 0xa98: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_a9b:
	/* 0xa9b: jbe    c34 <generic_kprobe_process_filter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c34;
	}
x86_l_aa1:
	/* 0xaa1: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_aa6:
	/* 0xaa6: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_aae:
	/* 0xaae: dec    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_ab1:
	/* 0xab1: jne    969 <generic_kprobe_process_filter+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_969;
	}
x86_l_ab7:
	/* 0xab7: jmp    c34 <generic_kprobe_process_filter+0xc34> */
	goto x86_l_c34;
x86_l_abc:
	/* 0xabc: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ac1:
	/* 0xac1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ac6:
	/* 0xac6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ac9:
	/* 0xac9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ace:
	/* 0xace: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad0:
	/* 0xad0: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ad8:
	/* 0xad8: cmp    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_add:
	/* 0xadd: je     c2c <generic_kprobe_process_filter+0xc2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c2c;
	}
x86_l_ae3:
	/* 0xae3: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_ae7:
	/* 0xae7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_aec:
	/* 0xaec: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_af4:
	/* 0xaf4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af9:
	/* 0xaf9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_afc:
	/* 0xafc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_afe:
	/* 0xafe: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b03:
	/* 0xb03: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b0b:
	/* 0xb0b: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_b0f:
	/* 0xb0f: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b17:
	/* 0xb17: dec    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_b1a:
	/* 0xb1a: jne    969 <generic_kprobe_process_filter+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_969;
	}
x86_l_b20:
	/* 0xb20: jmp    c34 <generic_kprobe_process_filter+0xc34> */
	goto x86_l_c34;
x86_l_b25:
	/* 0xb25: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_b28:
	/* 0xb28: mov    eax,DWORD PTR [r12+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_b30:
	/* 0xb30: lea    ecx,[rax-0x101] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551359ULL);
x86_l_b36:
	/* 0xb36: cmp    ecx,0xfffffeff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4294967039ULL);
x86_l_b3c:
	/* 0xb3c: jbe    ea5 <generic_kprobe_process_filter+0xea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3749ULL;
	}
x86_l_b42:
	/* 0xb42: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b45:
	/* 0xb45: lea    rdi,[r12+0x5f80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24448ULL);
x86_l_b4d:
	/* 0xb4d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b52:
	/* 0xb52: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b57:
	/* 0xb57: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_b59:
	/* 0xb59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5b:
	/* 0xb5b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_b5e:
	/* 0xb5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b61:
	/* 0xb61: je     d70 <generic_kprobe_process_filter+0xd70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d70;
	}
x86_l_b67:
	/* 0xb67: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_b6a:
	/* 0xb6a: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_b6c:
	/* 0xb6c: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b71:
	/* 0xb71: mov    WORD PTR [rsp+0x72],0xf */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 489626271759ULL);
x86_l_b78:
	/* 0xb78: movabs rax,0x400000168 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869544ULL);
x86_l_b82:
	/* 0xb82: mov    QWORD PTR [rsp+0x74],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_b87:
	/* 0xb87: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b8e:
	/* 0xb8e: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b93:
	/* 0xb93: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b98:
	/* 0xb98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9a:
	/* 0xb9a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9d:
	/* 0xb9d: je     d4c <generic_kprobe_process_filter+0xd4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d4c;
	}
x86_l_ba3:
	/* 0xba3: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ba5:
	/* 0xba5: jmp    d70 <generic_kprobe_process_filter+0xd70> */
	goto x86_l_d70;
x86_l_baa:
	/* 0xbaa: lea    rdx,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bae:
	/* 0xbae: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bb3:
	/* 0xbb3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bb8:
	/* 0xbb8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bbd:
	/* 0xbbd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bc2:
	/* 0xbc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc4:
	/* 0xbc4: cmp    QWORD PTR [rsp+0x70],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bc9:
	/* 0xbc9: je     851 <generic_kprobe_process_filter+0x851> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_851;
	}
x86_l_bcf:
	/* 0xbcf: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bd4:
	/* 0xbd4: mov    ecx,DWORD PTR [rdx+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_bda:
	/* 0xbda: lea    eax,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_bdd:
	/* 0xbdd: mov    DWORD PTR [rdx+0x6410],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_be3:
	/* 0xbe3: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_be6:
	/* 0xbe6: jg     13c0 <generic_kprobe_process_filter+0x13c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5056ULL;
	}
x86_l_bec:
	/* 0xbec: mov    DWORD PTR [rdx+0x6414],0xffffffdc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110041357090780ULL);
x86_l_bf6:
	/* 0xbf6: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_bf9:
	/* 0xbf9: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c01:
	/* 0xc01: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_c04:
	/* 0xc04: jmp    cc0 <generic_kprobe_process_filter+0xcc0> */
	goto x86_l_cc0;
x86_l_c09:
	/* 0xc09: lea    rsi,[rip+0x36d4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 14036ULL);
x86_l_c10:
	/* 0xc10: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c12:
	/* 0xc12: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c17:
	/* 0xc17: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_c1c:
	/* 0xc1c: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_c21:
	/* 0xc21: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_c26:
	/* 0xc26: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c28:
	/* 0xc28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2a:
	/* 0xc2a: jmp    c34 <generic_kprobe_process_filter+0xc34> */
	goto x86_l_c34;
x86_l_c2c:
	/* 0xc2c: mov    BYTE PTR [rsp+0xac],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 738734374913ULL);
x86_l_c34:
	/* 0xc34: mov    rbx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_c3c:
	/* 0xc3c: mov    rcx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_c44:
	/* 0xc44: cmp    rbx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_c47:
	/* 0xc47: mov    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c4c:
	/* 0xc4c: je     c9b <generic_kprobe_process_filter+0xc9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c9b;
	}
x86_l_c4e:
	/* 0xc4e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c50:
	/* 0xc50: cmp    BYTE PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_c58:
	/* 0xc58: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_c5b:
	/* 0xc5b: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c5d:
	/* 0xc5d: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c64:
	/* 0xc64: mov    DWORD PTR [r12+0x6410],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_c6c:
	/* 0xc6c: mov    DWORD PTR [r12+0x6414],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25620ULL);
x86_l_c74:
	/* 0xc74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c76:
	/* 0xc76: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c7e:
	/* 0xc7e: jle    c91 <generic_kprobe_process_filter+0xc91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c91;
	}
x86_l_c80:
	/* 0xc80: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_c85:
	/* 0xc85: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_c87:
	/* 0xc87: mov    DWORD PTR [r12+0x6410],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_c8f:
	/* 0xc8f: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_c91:
	/* 0xc91: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_c94:
	/* 0xc94: jne    cc0 <generic_kprobe_process_filter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cc0;
	}
x86_l_c96:
	/* 0xc96: jmp    e8b <generic_kprobe_process_filter+0xe8b> */
	goto x86_l_e8b;
x86_l_c9b:
	/* 0xc9b: mov    DWORD PTR [r12+0x6410],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882254336ULL);
x86_l_ca7:
	/* 0xca7: mov    DWORD PTR [r12+0x6414],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110037062123520ULL);
x86_l_cb3:
	/* 0xcb3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb5:
	/* 0xcb5: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_cb8:
	/* 0xcb8: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_cc0:
	/* 0xcc0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc2:
	/* 0xcc2: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_cc5:
	/* 0xcc5: sub    r14d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SUB, 127ULL);
x86_l_cc9:
	/* 0xcc9: mov    r15d,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 127ULL);
x86_l_ccf:
	/* 0xccf: cmovb  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_cd3:
	/* 0xcd3: cmovb  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_cd7:
	/* 0xcd7: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_cdc:
	/* 0xcdc: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_ce1:
	/* 0xce1: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_ce4:
	/* 0xce4: mov    DWORD PTR [r12+0x6410],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_cec:
	/* 0xcec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cf1:
	/* 0xcf1: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf6:
	/* 0xcf6: mov    esi,DWORD PTR [r12+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_cfe:
	/* 0xcfe: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_d01:
	/* 0xd01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d03:
	/* 0xd03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d06:
	/* 0xd06: je     e33 <generic_kprobe_process_filter+0xe33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e33;
	}
x86_l_d0c:
	/* 0xd0c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_d0e:
	/* 0xd0e: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d13:
	/* 0xd13: mov    WORD PTR [rsp+0x72],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 489626271752ULL);
x86_l_d1a:
	/* 0xd1a: movabs rax,0x4000002da */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869914ULL);
x86_l_d24:
	/* 0xd24: mov    QWORD PTR [rsp+0x74],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_d29:
	/* 0xd29: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_d30:
	/* 0xd30: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d35:
	/* 0xd35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d3a:
	/* 0xd3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3c:
	/* 0xd3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d3f:
	/* 0xd3f: je     e0f <generic_kprobe_process_filter+0xe0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e0f;
	}
x86_l_d45:
	/* 0xd45: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d47:
	/* 0xd47: jmp    e33 <generic_kprobe_process_filter+0xe33> */
	goto x86_l_e33;
x86_l_d4c:
	/* 0xd4c: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_d54:
	/* 0xd54: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_d5b:
	/* 0xd5b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d5d:
	/* 0xd5d: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d62:
	/* 0xd62: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d67:
	/* 0xd67: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d6c:
	/* 0xd6c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d6e:
	/* 0xd6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d70:
	/* 0xd70: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_d73:
	/* 0xd73: cmove  r15d,ebx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RBX, X86_WIDTH_32, X86_CC_E);
x86_l_d77:
	/* 0xd77: mov    DWORD PTR [r12+0x5f78],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24440ULL);
x86_l_d7f:
	/* 0xd7f: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_d82:
	/* 0xd82: mov    esi,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 127ULL);
x86_l_d87:
	/* 0xd87: cmovb  esi,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_d8a:
	/* 0xd8a: lea    rdi,[r12+0x6080] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24704ULL);
x86_l_d92:
	/* 0xd92: lea    rdx,[r12+0x6390] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25488ULL);
x86_l_d9a:
	/* 0xd9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d9f:
	/* 0xd9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da1:
	/* 0xda1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_da4:
	/* 0xda4: je     eb0 <generic_kprobe_process_filter+0xeb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3760ULL;
	}
x86_l_daa:
	/* 0xdaa: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_dac:
	/* 0xdac: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_db1:
	/* 0xdb1: mov    WORD PTR [rsp+0x72],0xf */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 489626271759ULL);
x86_l_db8:
	/* 0xdb8: movabs rax,0x40000016e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869550ULL);
x86_l_dc2:
	/* 0xdc2: mov    QWORD PTR [rsp+0x74],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_dc7:
	/* 0xdc7: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_dce:
	/* 0xdce: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_dd3:
	/* 0xdd3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dd8:
	/* 0xdd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dda:
	/* 0xdda: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ddd:
	/* 0xddd: je     de6 <generic_kprobe_process_filter+0xde6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de6;
	}
x86_l_ddf:
	/* 0xddf: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_de1:
	/* 0xde1: jmp    eb0 <generic_kprobe_process_filter+0xeb0> */
	return 3760ULL;
x86_l_de6:
	/* 0xde6: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_dee:
	/* 0xdee: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_df5:
	/* 0xdf5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_df7:
	/* 0xdf7: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_dfc:
	/* 0xdfc: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e01:
	/* 0xe01: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e06:
	/* 0xe06: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e08:
	/* 0xe08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0a:
	/* 0xe0a: jmp    eb0 <generic_kprobe_process_filter+0xeb0> */
	return 3760ULL;
x86_l_e0f:
	/* 0xe0f: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_e17:
	/* 0xe17: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_e1e:
	/* 0xe1e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e20:
	/* 0xe20: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e25:
	/* 0xe25: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e2a:
	/* 0xe2a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e2f:
	/* 0xe2f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e31:
	/* 0xe31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e33:
	/* 0xe33: lea    rdi,[r12+0x6390] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25488ULL);
x86_l_e3b:
	/* 0xe3b: add    rbx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e3e:
	/* 0xe3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e43:
	/* 0xe43: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_e46:
	/* 0xe46: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_e49:
	/* 0xe49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4b:
	/* 0xe4b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e4e:
	/* 0xe4e: je     e8b <generic_kprobe_process_filter+0xe8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e8b;
	}
x86_l_e50:
	/* 0xe50: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_e52:
	/* 0xe52: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e57:
	/* 0xe57: mov    WORD PTR [rsp+0x72],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 489626271752ULL);
x86_l_e5e:
	/* 0xe5e: movabs rax,0x4000002dc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869916ULL);
x86_l_e68:
	/* 0xe68: mov    QWORD PTR [rsp+0x74],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_e6d:
	/* 0xe6d: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_e74:
	/* 0xe74: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e79:
	/* 0xe79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e7e:
	/* 0xe7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e80:
	/* 0xe80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e83:
	/* 0xe83: je     137d <generic_kprobe_process_filter+0x137d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4989ULL;
	}
x86_l_e89:
	/* 0xe89: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_e8b:
	/* 0xe8b: mov    eax,DWORD PTR [r12+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
	return 3731ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3731ULL: goto x86_l_e93;
	case 3737ULL: goto x86_l_e99;
	case 3743ULL: goto x86_l_e9f;
	case 3749ULL: goto x86_l_ea5;
	case 3754ULL: goto x86_l_eaa;
	case 3760ULL: goto x86_l_eb0;
	case 3768ULL: goto x86_l_eb8;
	case 3774ULL: goto x86_l_ebe;
	case 3782ULL: goto x86_l_ec6;
	case 3789ULL: goto x86_l_ecd;
	case 3794ULL: goto x86_l_ed2;
	case 3796ULL: goto x86_l_ed4;
	case 3799ULL: goto x86_l_ed7;
	case 3805ULL: goto x86_l_edd;
	case 3813ULL: goto x86_l_ee5;
	case 3817ULL: goto x86_l_ee9;
	case 3823ULL: goto x86_l_eef;
	case 3826ULL: goto x86_l_ef2;
	case 3829ULL: goto x86_l_ef5;
	case 3835ULL: goto x86_l_efb;
	case 3838ULL: goto x86_l_efe;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3870ULL: goto x86_l_f1e;
	case 3875ULL: goto x86_l_f23;
	case 3883ULL: goto x86_l_f2b;
	case 3890ULL: goto x86_l_f32;
	case 3895ULL: goto x86_l_f37;
	case 3900ULL: goto x86_l_f3c;
	case 3902ULL: goto x86_l_f3e;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3916ULL: goto x86_l_f4c;
	case 3919ULL: goto x86_l_f4f;
	case 3921ULL: goto x86_l_f51;
	case 3923ULL: goto x86_l_f53;
	case 3929ULL: goto x86_l_f59;
	case 3933ULL: goto x86_l_f5d;
	case 3939ULL: goto x86_l_f63;
	case 3942ULL: goto x86_l_f66;
	case 3948ULL: goto x86_l_f6c;
	case 3953ULL: goto x86_l_f71;
	case 3956ULL: goto x86_l_f74;
	case 3962ULL: goto x86_l_f7a;
	case 3967ULL: goto x86_l_f7f;
	case 3970ULL: goto x86_l_f82;
	case 3976ULL: goto x86_l_f88;
	case 3981ULL: goto x86_l_f8d;
	case 3984ULL: goto x86_l_f90;
	case 3990ULL: goto x86_l_f96;
	case 3993ULL: goto x86_l_f99;
	case 3997ULL: goto x86_l_f9d;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4020ULL: goto x86_l_fb4;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4034ULL: goto x86_l_fc2;
	case 4040ULL: goto x86_l_fc8;
	case 4044ULL: goto x86_l_fcc;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4061ULL: goto x86_l_fdd;
	case 4063ULL: goto x86_l_fdf;
	case 4066ULL: goto x86_l_fe2;
	case 4072ULL: goto x86_l_fe8;
	case 4075ULL: goto x86_l_feb;
	case 4083ULL: goto x86_l_ff3;
	case 4086ULL: goto x86_l_ff6;
	case 4091ULL: goto x86_l_ffb;
	case 4095ULL: goto x86_l_fff;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4113ULL: goto x86_l_1011;
	case 4116ULL: goto x86_l_1014;
	case 4119ULL: goto x86_l_1017;
	case 4122ULL: goto x86_l_101a;
	case 4124ULL: goto x86_l_101c;
	case 4126ULL: goto x86_l_101e;
	case 4129ULL: goto x86_l_1021;
	case 4131ULL: goto x86_l_1023;
	case 4133ULL: goto x86_l_1025;
	case 4136ULL: goto x86_l_1028;
	case 4139ULL: goto x86_l_102b;
	case 4147ULL: goto x86_l_1033;
	case 4151ULL: goto x86_l_1037;
	case 4154ULL: goto x86_l_103a;
	case 4161ULL: goto x86_l_1041;
	case 4165ULL: goto x86_l_1045;
	case 4169ULL: goto x86_l_1049;
	case 4173ULL: goto x86_l_104d;
	case 4182ULL: goto x86_l_1056;
	case 4186ULL: goto x86_l_105a;
	case 4190ULL: goto x86_l_105e;
	case 4194ULL: goto x86_l_1062;
	case 4196ULL: goto x86_l_1064;
	case 4200ULL: goto x86_l_1068;
	case 4204ULL: goto x86_l_106c;
	case 4208ULL: goto x86_l_1070;
	case 4217ULL: goto x86_l_1079;
	case 4221ULL: goto x86_l_107d;
	case 4225ULL: goto x86_l_1081;
	case 4227ULL: goto x86_l_1083;
	case 4231ULL: goto x86_l_1087;
	case 4235ULL: goto x86_l_108b;
	case 4239ULL: goto x86_l_108f;
	case 4248ULL: goto x86_l_1098;
	case 4252ULL: goto x86_l_109c;
	case 4255ULL: goto x86_l_109f;
	case 4258ULL: goto x86_l_10a2;
	case 4260ULL: goto x86_l_10a4;
	case 4264ULL: goto x86_l_10a8;
	case 4266ULL: goto x86_l_10aa;
	case 4270ULL: goto x86_l_10ae;
	case 4274ULL: goto x86_l_10b2;
	case 4278ULL: goto x86_l_10b6;
	case 4287ULL: goto x86_l_10bf;
	case 4290ULL: goto x86_l_10c2;
	case 4294ULL: goto x86_l_10c6;
	case 4298ULL: goto x86_l_10ca;
	case 4302ULL: goto x86_l_10ce;
	case 4306ULL: goto x86_l_10d2;
	case 4310ULL: goto x86_l_10d6;
	case 4316ULL: goto x86_l_10dc;
	case 4325ULL: goto x86_l_10e5;
	case 4329ULL: goto x86_l_10e9;
	case 4331ULL: goto x86_l_10eb;
	case 4334ULL: goto x86_l_10ee;
	case 4337ULL: goto x86_l_10f1;
	case 4341ULL: goto x86_l_10f5;
	case 4346ULL: goto x86_l_10fa;
	case 4353ULL: goto x86_l_1101;
	case 4358ULL: goto x86_l_1106;
	case 4360ULL: goto x86_l_1108;
	case 4363ULL: goto x86_l_110b;
	case 4369ULL: goto x86_l_1111;
	case 4374ULL: goto x86_l_1116;
	case 4379ULL: goto x86_l_111b;
	case 4381ULL: goto x86_l_111d;
	case 4386ULL: goto x86_l_1122;
	case 4390ULL: goto x86_l_1126;
	case 4395ULL: goto x86_l_112b;
	case 4404ULL: goto x86_l_1134;
	case 4410ULL: goto x86_l_113a;
	case 4415ULL: goto x86_l_113f;
	case 4424ULL: goto x86_l_1148;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4435ULL: goto x86_l_1153;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4457ULL: goto x86_l_1169;
	case 4460ULL: goto x86_l_116c;
	case 4466ULL: goto x86_l_1172;
	case 4473ULL: goto x86_l_1179;
	case 4478ULL: goto x86_l_117e;
	case 4483ULL: goto x86_l_1183;
	case 4485ULL: goto x86_l_1185;
	case 4490ULL: goto x86_l_118a;
	case 4493ULL: goto x86_l_118d;
	case 4499ULL: goto x86_l_1193;
	case 4502ULL: goto x86_l_1196;
	case 4506ULL: goto x86_l_119a;
	case 4510ULL: goto x86_l_119e;
	case 4518ULL: goto x86_l_11a6;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4537ULL: goto x86_l_11b9;
	case 4540ULL: goto x86_l_11bc;
	case 4546ULL: goto x86_l_11c2;
	case 4549ULL: goto x86_l_11c5;
	case 4551ULL: goto x86_l_11c7;
	case 4553ULL: goto x86_l_11c9;
	case 4559ULL: goto x86_l_11cf;
	case 4563ULL: goto x86_l_11d3;
	case 4569ULL: goto x86_l_11d9;
	case 4572ULL: goto x86_l_11dc;
	case 4578ULL: goto x86_l_11e2;
	case 4583ULL: goto x86_l_11e7;
	case 4586ULL: goto x86_l_11ea;
	case 4592ULL: goto x86_l_11f0;
	case 4597ULL: goto x86_l_11f5;
	case 4600ULL: goto x86_l_11f8;
	case 4606ULL: goto x86_l_11fe;
	case 4611ULL: goto x86_l_1203;
	case 4614ULL: goto x86_l_1206;
	case 4620ULL: goto x86_l_120c;
	case 4623ULL: goto x86_l_120f;
	case 4627ULL: goto x86_l_1213;
	case 4634ULL: goto x86_l_121a;
	case 4639ULL: goto x86_l_121f;
	case 4641ULL: goto x86_l_1221;
	case 4644ULL: goto x86_l_1224;
	case 4650ULL: goto x86_l_122a;
	case 4653ULL: goto x86_l_122d;
	case 4656ULL: goto x86_l_1230;
	case 4659ULL: goto x86_l_1233;
	case 4665ULL: goto x86_l_1239;
	case 4669ULL: goto x86_l_123d;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4688ULL: goto x86_l_1250;
	case 4691ULL: goto x86_l_1253;
	case 4697ULL: goto x86_l_1259;
	case 4700ULL: goto x86_l_125c;
	case 4708ULL: goto x86_l_1264;
	case 4710ULL: goto x86_l_1266;
	case 4714ULL: goto x86_l_126a;
	case 4720ULL: goto x86_l_1270;
	case 4723ULL: goto x86_l_1273;
	case 4725ULL: goto x86_l_1275;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4734ULL: goto x86_l_127e;
	case 4736ULL: goto x86_l_1280;
	case 4738ULL: goto x86_l_1282;
	case 4741ULL: goto x86_l_1285;
	case 4743ULL: goto x86_l_1287;
	case 4745ULL: goto x86_l_1289;
	case 4748ULL: goto x86_l_128c;
	case 4751ULL: goto x86_l_128f;
	case 4758ULL: goto x86_l_1296;
	case 4762ULL: goto x86_l_129a;
	case 4765ULL: goto x86_l_129d;
	case 4772ULL: goto x86_l_12a4;
	case 4776ULL: goto x86_l_12a8;
	case 4780ULL: goto x86_l_12ac;
	case 4784ULL: goto x86_l_12b0;
	case 4793ULL: goto x86_l_12b9;
	case 4797ULL: goto x86_l_12bd;
	case 4801ULL: goto x86_l_12c1;
	case 4805ULL: goto x86_l_12c5;
	case 4807ULL: goto x86_l_12c7;
	case 4811ULL: goto x86_l_12cb;
	case 4815ULL: goto x86_l_12cf;
	case 4819ULL: goto x86_l_12d3;
	case 4828ULL: goto x86_l_12dc;
	case 4832ULL: goto x86_l_12e0;
	case 4836ULL: goto x86_l_12e4;
	case 4838ULL: goto x86_l_12e6;
	case 4842ULL: goto x86_l_12ea;
	case 4846ULL: goto x86_l_12ee;
	case 4850ULL: goto x86_l_12f2;
	case 4859ULL: goto x86_l_12fb;
	case 4863ULL: goto x86_l_12ff;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4871ULL: goto x86_l_1307;
	case 4875ULL: goto x86_l_130b;
	case 4877ULL: goto x86_l_130d;
	case 4881ULL: goto x86_l_1311;
	case 4885ULL: goto x86_l_1315;
	case 4889ULL: goto x86_l_1319;
	case 4898ULL: goto x86_l_1322;
	case 4901ULL: goto x86_l_1325;
	case 4905ULL: goto x86_l_1329;
	case 4909ULL: goto x86_l_132d;
	case 4913ULL: goto x86_l_1331;
	case 4917ULL: goto x86_l_1335;
	case 4921ULL: goto x86_l_1339;
	case 4927ULL: goto x86_l_133f;
	case 4934ULL: goto x86_l_1346;
	case 4938ULL: goto x86_l_134a;
	case 4940ULL: goto x86_l_134c;
	case 4943ULL: goto x86_l_134f;
	case 4946ULL: goto x86_l_1352;
	case 4950ULL: goto x86_l_1356;
	case 4957ULL: goto x86_l_135d;
	case 4962ULL: goto x86_l_1362;
	case 4965ULL: goto x86_l_1365;
	case 4967ULL: goto x86_l_1367;
	case 4970ULL: goto x86_l_136a;
	case 4976ULL: goto x86_l_1370;
	case 4981ULL: goto x86_l_1375;
	case 4984ULL: goto x86_l_1378;
	case 4989ULL: goto x86_l_137d;
	case 4997ULL: goto x86_l_1385;
	case 5004ULL: goto x86_l_138c;
	case 5006ULL: goto x86_l_138e;
	case 5011ULL: goto x86_l_1393;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5023ULL: goto x86_l_139f;
	case 5025ULL: goto x86_l_13a1;
	case 5033ULL: goto x86_l_13a9;
	case 5039ULL: goto x86_l_13af;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5066ULL: goto x86_l_13ca;
	case 5076ULL: goto x86_l_13d4;
	case 5084ULL: goto x86_l_13dc;
	case 5095ULL: goto x86_l_13e7;
	case 5100ULL: goto x86_l_13ec;
	case 5105ULL: goto x86_l_13f1;
	case 5108ULL: goto x86_l_13f4;
	case 5116ULL: goto x86_l_13fc;
	case 5121ULL: goto x86_l_1401;
	case 5125ULL: goto x86_l_1405;
	case 5132ULL: goto x86_l_140c;
	case 5134ULL: goto x86_l_140e;
	case 5137ULL: goto x86_l_1411;
	case 5143ULL: goto x86_l_1417;
	case 5148ULL: goto x86_l_141c;
	case 5153ULL: goto x86_l_1421;
	case 5159ULL: goto x86_l_1427;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5174ULL: goto x86_l_1436;
	case 5183ULL: goto x86_l_143f;
	case 5192ULL: goto x86_l_1448;
	case 5195ULL: goto x86_l_144b;
	case 5200ULL: goto x86_l_1450;
	case 5203ULL: goto x86_l_1453;
	case 5206ULL: goto x86_l_1456;
	case 5208ULL: goto x86_l_1458;
	case 5218ULL: goto x86_l_1462;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5230ULL: goto x86_l_146e;
	case 5235ULL: goto x86_l_1473;
	case 5241ULL: goto x86_l_1479;
	case 5245ULL: goto x86_l_147d;
	case 5249ULL: goto x86_l_1481;
	case 5257ULL: goto x86_l_1489;
	case 5261ULL: goto x86_l_148d;
	case 5265ULL: goto x86_l_1491;
	case 5273ULL: goto x86_l_1499;
	case 5277ULL: goto x86_l_149d;
	case 5281ULL: goto x86_l_14a1;
	case 5288ULL: goto x86_l_14a8;
	case 5292ULL: goto x86_l_14ac;
	case 5295ULL: goto x86_l_14af;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5308ULL: goto x86_l_14bc;
	case 5311ULL: goto x86_l_14bf;
	case 5314ULL: goto x86_l_14c2;
	case 5317ULL: goto x86_l_14c5;
	case 5320ULL: goto x86_l_14c8;
	case 5322ULL: goto x86_l_14ca;
	case 5330ULL: goto x86_l_14d2;
	case 5333ULL: goto x86_l_14d5;
	case 5337ULL: goto x86_l_14d9;
	case 5342ULL: goto x86_l_14de;
	case 5347ULL: goto x86_l_14e3;
	case 5352ULL: goto x86_l_14e8;
	case 5357ULL: goto x86_l_14ed;
	case 5362ULL: goto x86_l_14f2;
	case 5367ULL: goto x86_l_14f7;
	case 5372ULL: goto x86_l_14fc;
	case 5377ULL: goto x86_l_1501;
	case 5380ULL: goto x86_l_1504;
	case 5384ULL: goto x86_l_1508;
	case 5391ULL: goto x86_l_150f;
	case 5396ULL: goto x86_l_1514;
	case 5398ULL: goto x86_l_1516;
	case 5401ULL: goto x86_l_1519;
	case 5407ULL: goto x86_l_151f;
	case 5410ULL: goto x86_l_1522;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5427ULL: goto x86_l_1533;
	case 5429ULL: goto x86_l_1535;
	case 5432ULL: goto x86_l_1538;
	case 5438ULL: goto x86_l_153e;
	case 5441ULL: goto x86_l_1541;
	case 5446ULL: goto x86_l_1546;
	case 5449ULL: goto x86_l_1549;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5464ULL: goto x86_l_1558;
	case 5471ULL: goto x86_l_155f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e93:
	/* 0xe93: lea    ecx,[rax-0x101] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551359ULL);
x86_l_e99:
	/* 0xe99: cmp    ecx,0xfffffeff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4294967039ULL);
x86_l_e9f:
	/* 0xe9f: ja     b42 <generic_kprobe_process_filter+0xb42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2882ULL;
	}
x86_l_ea5:
	/* 0xea5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eaa:
	/* 0xeaa: mov    DWORD PTR [rax],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_eb0:
	/* 0xeb0: lea    rbx,[r12+0x5f10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24336ULL);
x86_l_eb8:
	/* 0xeb8: or     BYTE PTR [r12+0x1],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967312ULL);
x86_l_ebe:
	/* 0xebe: lea    rsi,[r12+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_ec6:
	/* 0xec6: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_ecd:
	/* 0xecd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ed2:
	/* 0xed2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed4:
	/* 0xed4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ed7:
	/* 0xed7: je     2572 <generic_kprobe_process_filter+0x2572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9586ULL;
	}
x86_l_edd:
	/* 0xedd: mov    r14,QWORD PTR [r12+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_ee5:
	/* 0xee5: cmp    r14,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 6ULL);
x86_l_ee9:
	/* 0xee9: jae    111b <generic_kprobe_process_filter+0x111b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_111b;
	}
x86_l_eef:
	/* 0xeef: movsxd rcx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_ef2:
	/* 0xef2: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_ef5:
	/* 0xef5: je     113f <generic_kprobe_process_filter+0x113f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113f;
	}
x86_l_efb:
	/* 0xefb: cmp    r14,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_efe:
	/* 0xefe: jae    111b <generic_kprobe_process_filter+0x111b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_111b;
	}
x86_l_f04:
	/* 0xf04: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f09:
	/* 0xf09: mov    QWORD PTR [rsp+0xd0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_f11:
	/* 0xf11: mov    QWORD PTR [rsp+0x60],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f16:
	/* 0xf16: mov    QWORD PTR [rsp+0xb8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_f1e:
	/* 0xf1e: mov    DWORD PTR [rsp+0x48],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f23:
	/* 0xf23: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_f2b:
	/* 0xf2b: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_sel_opts)));
x86_l_f32:
	/* 0xf32: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f37:
	/* 0xf37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f3c:
	/* 0xf3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3e:
	/* 0xf3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f41:
	/* 0xf41: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f46:
	/* 0xf46: je     115d <generic_kprobe_process_filter+0x115d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_115d;
	}
x86_l_f4c:
	/* 0xf4c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_f4f:
	/* 0xf4f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f51:
	/* 0xf51: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f53:
	/* 0xf53: je     115d <generic_kprobe_process_filter+0x115d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_115d;
	}
x86_l_f59:
	/* 0xf59: cmp    DWORD PTR [rbx+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_f5d:
	/* 0xf5d: js     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9498ULL;
	}
x86_l_f63:
	/* 0xf63: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_f66:
	/* 0xf66: ja     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9498ULL;
	}
x86_l_f6c:
	/* 0xf6c: mov    ecx,0x60 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 96ULL);
x86_l_f71:
	/* 0xf71: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f74:
	/* 0xf74: jb     1594 <generic_kprobe_process_filter+0x1594> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5524ULL;
	}
x86_l_f7a:
	/* 0xf7a: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_f7f:
	/* 0xf7f: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f82:
	/* 0xf82: jb     1501 <generic_kprobe_process_filter+0x1501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1501;
	}
x86_l_f88:
	/* 0xf88: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_f8d:
	/* 0xf8d: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f90:
	/* 0xf90: jae    251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9498ULL;
	}
x86_l_f96:
	/* 0xf96: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_f99:
	/* 0xf99: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_f9d:
	/* 0xf9d: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_fa4:
	/* 0xfa4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fa9:
	/* 0xfa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fab:
	/* 0xfab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fae:
	/* 0xfae: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_fb4:
	/* 0xfb4: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_fb7:
	/* 0xfb7: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fbc:
	/* 0xfbc: mov    eax,DWORD PTR [rax+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fbf:
	/* 0xfbf: cmp    eax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_fc2:
	/* 0xfc2: mov    r15d,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 127ULL);
x86_l_fc8:
	/* 0xfc8: cmovl  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_L);
x86_l_fcc:
	/* 0xfcc: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_fd3:
	/* 0xfd3: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fd8:
	/* 0xfd8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fdd:
	/* 0xfdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fdf:
	/* 0xfdf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fe2:
	/* 0xfe2: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_fe8:
	/* 0xfe8: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_feb:
	/* 0xfeb: lea    eax,[r15*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_ff3:
	/* 0xff3: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff6:
	/* 0xff6: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ffb:
	/* 0xffb: cmp    DWORD PTR [rax+0x6c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467968ULL);
x86_l_fff:
	/* 0xfff: jne    10e5 <generic_kprobe_process_filter+0x10e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10e5;
	}
x86_l_1005:
	/* 0x1005: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_100a:
	/* 0x100a: mov    ecx,DWORD PTR [r12+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_100f:
	/* 0x100f: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1011:
	/* 0x1011: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1014:
	/* 0x1014: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_1017:
	/* 0x1017: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_101a:
	/* 0x101a: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_101c:
	/* 0x101c: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_101e:
	/* 0x101e: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_1021:
	/* 0x1021: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1023:
	/* 0x1023: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1025:
	/* 0x1025: sub    edx,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1028:
	/* 0x1028: lea    esi,[rdx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_102b:
	/* 0x102b: lea    rdi,[r12+0x1f3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 499ULL);
x86_l_1033:
	/* 0x1033: lea    r8d,[rdx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1037:
	/* 0x1037: add    edx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4294967294ULL);
x86_l_103a:
	/* 0x103a: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_1041:
	/* 0x1041: lea    r10d,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1045:
	/* 0x1045: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1049:
	/* 0x1049: and    r10d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_104d:
	/* 0x104d: movzx  r10d,BYTE PTR [r12+r10*1+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 368ULL);
x86_l_1056:
	/* 0x1056: mov    BYTE PTR [rdi-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_105a:
	/* 0x105a: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_105e:
	/* 0x105e: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1062:
	/* 0x1062: je     10dc <generic_kprobe_process_filter+0x10dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10dc;
	}
x86_l_1064:
	/* 0x1064: lea    r11d,[rdx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1068:
	/* 0x1068: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_106c:
	/* 0x106c: and    r11d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_1070:
	/* 0x1070: movzx  r11d,BYTE PTR [r12+r11*1+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 368ULL);
x86_l_1079:
	/* 0x1079: mov    BYTE PTR [rdi-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_107d:
	/* 0x107d: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1081:
	/* 0x1081: je     10dc <generic_kprobe_process_filter+0x10dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10dc;
	}
x86_l_1083:
	/* 0x1083: lea    r10d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1087:
	/* 0x1087: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_108b:
	/* 0x108b: and    r10d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_108f:
	/* 0x108f: movzx  r10d,BYTE PTR [r12+r10*1+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 368ULL);
x86_l_1098:
	/* 0x1098: mov    BYTE PTR [rdi-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_109c:
	/* 0x109c: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_109f:
	/* 0x109f: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_10a2:
	/* 0x10a2: je     10dc <generic_kprobe_process_filter+0x10dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10dc;
	}
x86_l_10a4:
	/* 0x10a4: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_10a8:
	/* 0x10a8: je     10dc <generic_kprobe_process_filter+0x10dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10dc;
	}
x86_l_10aa:
	/* 0x10aa: lea    r10d,[rsi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_10ae:
	/* 0x10ae: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_10b2:
	/* 0x10b2: and    r10d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_10b6:
	/* 0x10b6: movzx  r10d,BYTE PTR [r12+r10*1+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 368ULL);
x86_l_10bf:
	/* 0x10bf: mov    BYTE PTR [rdi],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c2:
	/* 0x10c2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_10c6:
	/* 0x10c6: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_10ca:
	/* 0x10ca: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_10ce:
	/* 0x10ce: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_10d2:
	/* 0x10d2: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_10d6:
	/* 0x10d6: jne    1041 <generic_kprobe_process_filter+0x1041> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1041;
	}
x86_l_10dc:
	/* 0x10dc: mov    DWORD PTR [r12+0x6c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467969ULL);
x86_l_10e5:
	/* 0x10e5: cmp    r15d,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 127ULL);
x86_l_10e9:
	/* 0x10e9: ja     1111 <generic_kprobe_process_filter+0x1111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1111;
	}
x86_l_10eb:
	/* 0x10eb: movsxd rsi,r15d */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RSI, X86_R15, X86_WIDTH_64, X86_WIDTH_32);
x86_l_10ee:
	/* 0x10ee: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_10f1:
	/* 0x10f1: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_10f5:
	/* 0x10f5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10fa:
	/* 0x10fa: lea    rdx,[rax+0x1f0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_1101:
	/* 0x1101: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1106:
	/* 0x1106: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1108:
	/* 0x1108: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_110b:
	/* 0x110b: js     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9498ULL;
	}
x86_l_1111:
	/* 0x1111: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1116:
	/* 0x1116: jmp    1589 <generic_kprobe_process_filter+0x1589> */
	return 5513ULL;
x86_l_111b:
	/* 0x111b: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111d:
	/* 0x111d: mov    DWORD PTR [r12+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1122:
	/* 0x1122: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1126:
	/* 0x1126: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_112b:
	/* 0x112b: cmp    BYTE PTR [r12+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_1134:
	/* 0x1134: jne    255d <generic_kprobe_process_filter+0x255d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9565ULL;
	}
x86_l_113a:
	/* 0x113a: jmp    2572 <generic_kprobe_process_filter+0x2572> */
	return 9586ULL;
x86_l_113f:
	/* 0x113f: mov    BYTE PTR [r12+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_1148:
	/* 0x1148: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_114a:
	/* 0x114a: mov    DWORD PTR [r12+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_114f:
	/* 0x114f: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1153:
	/* 0x1153: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1158:
	/* 0x1158: jmp    255d <generic_kprobe_process_filter+0x255d> */
	return 9565ULL;
x86_l_115d:
	/* 0x115d: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1162:
	/* 0x1162: mov    rax,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&PARENTS_MAP_ENABLED)));
x86_l_1169:
	/* 0x1169: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116c:
	/* 0x116c: je     13f1 <generic_kprobe_process_filter+0x13f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f1;
	}
x86_l_1172:
	/* 0x1172: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_parents_bin)));
x86_l_1179:
	/* 0x1179: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_117e:
	/* 0x117e: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1183:
	/* 0x1183: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1185:
	/* 0x1185: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_118a:
	/* 0x118a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_118d:
	/* 0x118d: je     13f1 <generic_kprobe_process_filter+0x13f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f1;
	}
x86_l_1193:
	/* 0x1193: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1196:
	/* 0x1196: lea    eax,[r14+0x5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_119a:
	/* 0x119a: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_119e:
	/* 0x119e: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_11a6:
	/* 0x11a6: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_sel_opts)));
x86_l_11ad:
	/* 0x11ad: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11b2:
	/* 0x11b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11b7:
	/* 0x11b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b9:
	/* 0x11b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11bc:
	/* 0x11bc: je     13ec <generic_kprobe_process_filter+0x13ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ec;
	}
x86_l_11c2:
	/* 0x11c2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_11c5:
	/* 0x11c5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c7:
	/* 0x11c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11c9:
	/* 0x11c9: je     13ec <generic_kprobe_process_filter+0x13ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ec;
	}
x86_l_11cf:
	/* 0x11cf: cmp    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d3:
	/* 0x11d3: js     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9498ULL;
	}
x86_l_11d9:
	/* 0x11d9: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_11dc:
	/* 0x11dc: ja     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9498ULL;
	}
x86_l_11e2:
	/* 0x11e2: mov    ecx,0x60 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 96ULL);
x86_l_11e7:
	/* 0x11e7: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_11ea:
	/* 0x11ea: jb     16f4 <generic_kprobe_process_filter+0x16f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5876ULL;
	}
x86_l_11f0:
	/* 0x11f0: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_11f5:
	/* 0x11f5: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_11f8:
	/* 0x11f8: jb     1664 <generic_kprobe_process_filter+0x1664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5732ULL;
	}
x86_l_11fe:
	/* 0x11fe: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_1203:
	/* 0x1203: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1206:
	/* 0x1206: jae    251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9498ULL;
	}
x86_l_120c:
	/* 0x120c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_120f:
	/* 0x120f: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1213:
	/* 0x1213: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_121a:
	/* 0x121a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_121f:
	/* 0x121f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1221:
	/* 0x1221: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1224:
	/* 0x1224: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_122a:
	/* 0x122a: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_122d:
	/* 0x122d: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1230:
	/* 0x1230: cmp    eax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_1233:
	/* 0x1233: mov    r15d,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 127ULL);
x86_l_1239:
	/* 0x1239: cmovl  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_L);
x86_l_123d:
	/* 0x123d: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1244:
	/* 0x1244: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1249:
	/* 0x1249: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_124e:
	/* 0x124e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1250:
	/* 0x1250: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1253:
	/* 0x1253: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_1259:
	/* 0x1259: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_125c:
	/* 0x125c: lea    eax,[r15*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_1264:
	/* 0x1264: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1266:
	/* 0x1266: cmp    DWORD PTR [rbp+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_126a:
	/* 0x126a: jne    1346 <generic_kprobe_process_filter+0x1346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1346;
	}
x86_l_1270:
	/* 0x1270: mov    ecx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1273:
	/* 0x1273: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1275:
	/* 0x1275: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1278:
	/* 0x1278: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_127b:
	/* 0x127b: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_127e:
	/* 0x127e: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1280:
	/* 0x1280: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1282:
	/* 0x1282: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_1285:
	/* 0x1285: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1287:
	/* 0x1287: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1289:
	/* 0x1289: sub    edx,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_128c:
	/* 0x128c: lea    esi,[rdx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_128f:
	/* 0x128f: lea    rdi,[rbp+0x18b] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 395ULL);
x86_l_1296:
	/* 0x1296: lea    r8d,[rdx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_129a:
	/* 0x129a: add    edx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4294967294ULL);
x86_l_129d:
	/* 0x129d: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_12a4:
	/* 0x12a4: lea    r10d,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_12a8:
	/* 0x12a8: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_12ac:
	/* 0x12ac: and    r10d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_12b0:
	/* 0x12b0: movzx  r10d,BYTE PTR [rbp+r10*1+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 264ULL);
x86_l_12b9:
	/* 0x12b9: mov    BYTE PTR [rdi-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_12bd:
	/* 0x12bd: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_12c1:
	/* 0x12c1: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_12c5:
	/* 0x12c5: je     133f <generic_kprobe_process_filter+0x133f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133f;
	}
x86_l_12c7:
	/* 0x12c7: lea    r11d,[rdx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_12cb:
	/* 0x12cb: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_12cf:
	/* 0x12cf: and    r11d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_12d3:
	/* 0x12d3: movzx  r11d,BYTE PTR [rbp+r11*1+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 264ULL);
x86_l_12dc:
	/* 0x12dc: mov    BYTE PTR [rdi-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_12e0:
	/* 0x12e0: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12e4:
	/* 0x12e4: je     133f <generic_kprobe_process_filter+0x133f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133f;
	}
x86_l_12e6:
	/* 0x12e6: lea    r10d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_12ea:
	/* 0x12ea: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_12ee:
	/* 0x12ee: and    r10d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_12f2:
	/* 0x12f2: movzx  r10d,BYTE PTR [rbp+r10*1+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 264ULL);
x86_l_12fb:
	/* 0x12fb: mov    BYTE PTR [rdi-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_12ff:
	/* 0x12ff: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_1302:
	/* 0x1302: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1305:
	/* 0x1305: je     133f <generic_kprobe_process_filter+0x133f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133f;
	}
x86_l_1307:
	/* 0x1307: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_130b:
	/* 0x130b: je     133f <generic_kprobe_process_filter+0x133f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133f;
	}
x86_l_130d:
	/* 0x130d: lea    r10d,[rsi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1311:
	/* 0x1311: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1315:
	/* 0x1315: and    r10d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_1319:
	/* 0x1319: movzx  r10d,BYTE PTR [rbp+r10*1+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 264ULL);
x86_l_1322:
	/* 0x1322: mov    BYTE PTR [rdi],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1325:
	/* 0x1325: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1329:
	/* 0x1329: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_132d:
	/* 0x132d: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1331:
	/* 0x1331: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1335:
	/* 0x1335: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_1339:
	/* 0x1339: jne    12a4 <generic_kprobe_process_filter+0x12a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12a4;
	}
x86_l_133f:
	/* 0x133f: mov    DWORD PTR [rbp+0x4],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_1346:
	/* 0x1346: cmp    r15d,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 127ULL);
x86_l_134a:
	/* 0x134a: ja     1370 <generic_kprobe_process_filter+0x1370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1370;
	}
x86_l_134c:
	/* 0x134c: movsxd rsi,r15d */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RSI, X86_R15, X86_WIDTH_64, X86_WIDTH_32);
x86_l_134f:
	/* 0x134f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1352:
	/* 0x1352: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1356:
	/* 0x1356: add    rbp,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_135d:
	/* 0x135d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1362:
	/* 0x1362: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1365:
	/* 0x1365: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1367:
	/* 0x1367: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_136a:
	/* 0x136a: js     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9498ULL;
	}
x86_l_1370:
	/* 0x1370: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1375:
	/* 0x1375: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1378:
	/* 0x1378: jmp    16ec <generic_kprobe_process_filter+0x16ec> */
	return 5868ULL;
x86_l_137d:
	/* 0x137d: mov    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_1385:
	/* 0x1385: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_138c:
	/* 0x138c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_138e:
	/* 0x138e: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1393:
	/* 0x1393: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1398:
	/* 0x1398: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_139d:
	/* 0x139d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_139f:
	/* 0x139f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a1:
	/* 0x13a1: mov    eax,DWORD PTR [r12+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_13a9:
	/* 0x13a9: lea    ecx,[rax-0x101] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551359ULL);
x86_l_13af:
	/* 0x13af: cmp    ecx,0xfffffeff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4294967039ULL);
x86_l_13b5:
	/* 0x13b5: jbe    ea5 <generic_kprobe_process_filter+0xea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ea5;
	}
x86_l_13bb:
	/* 0x13bb: jmp    b42 <generic_kprobe_process_filter+0xb42> */
	return 2882ULL;
x86_l_13c0:
	/* 0x13c0: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_13c3:
	/* 0x13c3: add    r13,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_13ca:
	/* 0x13ca: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_13d4:
	/* 0x13d4: mov    QWORD PTR [r12+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_13dc:
	/* 0x13dc: mov    WORD PTR [r12+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_13e7:
	/* 0x13e7: jmp    851 <generic_kprobe_process_filter+0x851> */
	return 2129ULL;
x86_l_13ec:
	/* 0x13ec: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13f1:
	/* 0x13f1: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_13f4:
	/* 0x13f4: lea    rcx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_13fc:
	/* 0x13fc: mov    eax,DWORD PTR [r9+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_1401:
	/* 0x1401: lea    r12d,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1405:
	/* 0x1405: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_140c:
	/* 0x140c: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_140e:
	/* 0x140e: add    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1411:
	/* 0x1411: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1417:
	/* 0x1417: lea    rbp,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_141c:
	/* 0x141c: cmp    DWORD PTR [rcx+r9*1],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 5ULL);
x86_l_1421:
	/* 0x1421: jb     14f7 <generic_kprobe_process_filter+0x14f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_14f7;
	}
x86_l_1427:
	/* 0x1427: mov    edi,DWORD PTR [rbp+r9*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_142c:
	/* 0x142c: mov    r8d,DWORD PTR [rbp+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_1431:
	/* 0x1431: mov    edx,DWORD PTR [rbp+r9*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 8ULL);
x86_l_1436:
	/* 0x1436: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_143f:
	/* 0x143f: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1448:
	/* 0x1448: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_144b:
	/* 0x144b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1450:
	/* 0x1450: cmovb  ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_B);
x86_l_1453:
	/* 0x1453: cmp    edi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_1456:
	/* 0x1456: jne    146c <generic_kprobe_process_filter+0x146c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_146c;
	}
x86_l_1458:
	/* 0x1458: movabs rsi,0x100000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 4294967297ULL);
x86_l_1462:
	/* 0x1462: mov    QWORD PTR [rsp+0x70],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1467:
	/* 0x1467: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_146c:
	/* 0x146c: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_146e:
	/* 0x146e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1473:
	/* 0x1473: je     1e7b <generic_kprobe_process_filter+0x1e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7803ULL;
	}
x86_l_1479:
	/* 0x1479: lea    rdx,[r15+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_147d:
	/* 0x147d: test   r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_1481:
	/* 0x1481: mov    QWORD PTR [rsp+0xc0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1489:
	/* 0x1489: cmove  rdx,r15 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R15, X86_WIDTH_64, X86_CC_E);
x86_l_148d:
	/* 0x148d: lea    rsi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1491:
	/* 0x1491: mov    QWORD PTR [rsp+0xe0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1499:
	/* 0x1499: lea    r10d,[rax+r14*4] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 0ULL);
x86_l_149d:
	/* 0x149d: add    r10d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_14a1:
	/* 0x14a1: and    r10d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_14a8:
	/* 0x14a8: add    r10,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_14ac:
	/* 0x14ac: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_14af:
	/* 0x14af: cmp    rcx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 3ULL);
x86_l_14b3:
	/* 0x14b3: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14b8:
	/* 0x14b8: cmovb  rax,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_14bc:
	/* 0x14bc: mov    ecx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R10, X86_WIDTH_32);
x86_l_14bf:
	/* 0x14bf: and    ecx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_14c2:
	/* 0x14c2: mov    r11,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_64);
x86_l_14c5:
	/* 0x14c5: add    r11,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14c8:
	/* 0x14c8: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14ca:
	/* 0x14ca: lea    rcx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_14d2:
	/* 0x14d2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d5:
	/* 0x14d5: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14d9:
	/* 0x14d9: mov    QWORD PTR [rsp+0x40],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14de:
	/* 0x14de: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14e3:
	/* 0x14e3: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14e8:
	/* 0x14e8: mov    QWORD PTR [rsp+0x28],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14ed:
	/* 0x14ed: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14f2:
	/* 0x14f2: jmp    1a26 <generic_kprobe_process_filter+0x1a26> */
	return 6694ULL;
x86_l_14f7:
	/* 0x14f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14fc:
	/* 0x14fc: jmp    1eb6 <generic_kprobe_process_filter+0x1eb6> */
	return 7862ULL;
x86_l_1501:
	/* 0x1501: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1504:
	/* 0x1504: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1508:
	/* 0x1508: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_150f:
	/* 0x150f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1514:
	/* 0x1514: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1516:
	/* 0x1516: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1519:
	/* 0x1519: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_151f:
	/* 0x151f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1522:
	/* 0x1522: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1529:
	/* 0x1529: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_152e:
	/* 0x152e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1533:
	/* 0x1533: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1535:
	/* 0x1535: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1538:
	/* 0x1538: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_153e:
	/* 0x153e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1541:
	/* 0x1541: mov    edx,0x104 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 260ULL);
x86_l_1546:
	/* 0x1546: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1549:
	/* 0x1549: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_154b:
	/* 0x154b: call   4c24 <cwd_read_v61+0x2681> */
	X86_SIM_L_EXEC_CALL_MEMSET(260ULL);
x86_l_1550:
	/* 0x1550: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1555:
	/* 0x1555: mov    eax,DWORD PTR [rsi+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1558:
	/* 0x1558: lea    ecx,[rax*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 0ULL);
x86_l_155f:
	/* 0x155f: mov    DWORD PTR [rbp+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 5474ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5474ULL: goto x86_l_1562;
	case 5477ULL: goto x86_l_1565;
	case 5481ULL: goto x86_l_1569;
	case 5484ULL: goto x86_l_156c;
	case 5488ULL: goto x86_l_1570;
	case 5493ULL: goto x86_l_1575;
	case 5497ULL: goto x86_l_1579;
	case 5499ULL: goto x86_l_157b;
	case 5502ULL: goto x86_l_157e;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5519ULL: goto x86_l_158f;
	case 5524ULL: goto x86_l_1594;
	case 5532ULL: goto x86_l_159c;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5549ULL: goto x86_l_15ad;
	case 5551ULL: goto x86_l_15af;
	case 5554ULL: goto x86_l_15b2;
	case 5559ULL: goto x86_l_15b7;
	case 5565ULL: goto x86_l_15bd;
	case 5568ULL: goto x86_l_15c0;
	case 5575ULL: goto x86_l_15c7;
	case 5581ULL: goto x86_l_15cd;
	case 5589ULL: goto x86_l_15d5;
	case 5596ULL: goto x86_l_15dc;
	case 5599ULL: goto x86_l_15df;
	case 5605ULL: goto x86_l_15e5;
	case 5611ULL: goto x86_l_15eb;
	case 5614ULL: goto x86_l_15ee;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5629ULL: goto x86_l_15fd;
	case 5633ULL: goto x86_l_1601;
	case 5638ULL: goto x86_l_1606;
	case 5645ULL: goto x86_l_160d;
	case 5650ULL: goto x86_l_1612;
	case 5652ULL: goto x86_l_1614;
	case 5655ULL: goto x86_l_1617;
	case 5661ULL: goto x86_l_161d;
	case 5664ULL: goto x86_l_1620;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5676ULL: goto x86_l_162c;
	case 5678ULL: goto x86_l_162e;
	case 5681ULL: goto x86_l_1631;
	case 5683ULL: goto x86_l_1633;
	case 5686ULL: goto x86_l_1636;
	case 5689ULL: goto x86_l_1639;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5704ULL: goto x86_l_1648;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5714ULL: goto x86_l_1652;
	case 5720ULL: goto x86_l_1658;
	case 5723ULL: goto x86_l_165b;
	case 5725ULL: goto x86_l_165d;
	case 5727ULL: goto x86_l_165f;
	case 5732ULL: goto x86_l_1664;
	case 5735ULL: goto x86_l_1667;
	case 5739ULL: goto x86_l_166b;
	case 5746ULL: goto x86_l_1672;
	case 5751ULL: goto x86_l_1677;
	case 5753ULL: goto x86_l_1679;
	case 5756ULL: goto x86_l_167c;
	case 5762ULL: goto x86_l_1682;
	case 5765ULL: goto x86_l_1685;
	case 5772ULL: goto x86_l_168c;
	case 5777ULL: goto x86_l_1691;
	case 5782ULL: goto x86_l_1696;
	case 5784ULL: goto x86_l_1698;
	case 5787ULL: goto x86_l_169b;
	case 5793ULL: goto x86_l_16a1;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5804ULL: goto x86_l_16ac;
	case 5806ULL: goto x86_l_16ae;
	case 5811ULL: goto x86_l_16b3;
	case 5814ULL: goto x86_l_16b6;
	case 5821ULL: goto x86_l_16bd;
	case 5823ULL: goto x86_l_16bf;
	case 5826ULL: goto x86_l_16c2;
	case 5830ULL: goto x86_l_16c6;
	case 5833ULL: goto x86_l_16c9;
	case 5836ULL: goto x86_l_16cc;
	case 5840ULL: goto x86_l_16d0;
	case 5845ULL: goto x86_l_16d5;
	case 5849ULL: goto x86_l_16d9;
	case 5851ULL: goto x86_l_16db;
	case 5854ULL: goto x86_l_16de;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5884ULL: goto x86_l_16fc;
	case 5891ULL: goto x86_l_1703;
	case 5896ULL: goto x86_l_1708;
	case 5901ULL: goto x86_l_170d;
	case 5903ULL: goto x86_l_170f;
	case 5906ULL: goto x86_l_1712;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5922ULL: goto x86_l_1722;
	case 5928ULL: goto x86_l_1728;
	case 5936ULL: goto x86_l_1730;
	case 5943ULL: goto x86_l_1737;
	case 5946ULL: goto x86_l_173a;
	case 5952ULL: goto x86_l_1740;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5966ULL: goto x86_l_174e;
	case 5969ULL: goto x86_l_1751;
	case 5973ULL: goto x86_l_1755;
	case 5978ULL: goto x86_l_175a;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5992ULL: goto x86_l_1768;
	case 5995ULL: goto x86_l_176b;
	case 6001ULL: goto x86_l_1771;
	case 6004ULL: goto x86_l_1774;
	case 6008ULL: goto x86_l_1778;
	case 6013ULL: goto x86_l_177d;
	case 6020ULL: goto x86_l_1784;
	case 6022ULL: goto x86_l_1786;
	case 6025ULL: goto x86_l_1789;
	case 6027ULL: goto x86_l_178b;
	case 6030ULL: goto x86_l_178e;
	case 6033ULL: goto x86_l_1791;
	case 6035ULL: goto x86_l_1793;
	case 6043ULL: goto x86_l_179b;
	case 6047ULL: goto x86_l_179f;
	case 6050ULL: goto x86_l_17a2;
	case 6053ULL: goto x86_l_17a5;
	case 6059ULL: goto x86_l_17ab;
	case 6062ULL: goto x86_l_17ae;
	case 6064ULL: goto x86_l_17b0;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6077ULL: goto x86_l_17bd;
	case 6080ULL: goto x86_l_17c0;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6095ULL: goto x86_l_17cf;
	case 6099ULL: goto x86_l_17d3;
	case 6104ULL: goto x86_l_17d8;
	case 6111ULL: goto x86_l_17df;
	case 6116ULL: goto x86_l_17e4;
	case 6118ULL: goto x86_l_17e6;
	case 6121ULL: goto x86_l_17e9;
	case 6123ULL: goto x86_l_17eb;
	case 6126ULL: goto x86_l_17ee;
	case 6130ULL: goto x86_l_17f2;
	case 6135ULL: goto x86_l_17f7;
	case 6138ULL: goto x86_l_17fa;
	case 6140ULL: goto x86_l_17fc;
	case 6143ULL: goto x86_l_17ff;
	case 6145ULL: goto x86_l_1801;
	case 6148ULL: goto x86_l_1804;
	case 6151ULL: goto x86_l_1807;
	case 6153ULL: goto x86_l_1809;
	case 6158ULL: goto x86_l_180e;
	case 6166ULL: goto x86_l_1816;
	case 6170ULL: goto x86_l_181a;
	case 6173ULL: goto x86_l_181d;
	case 6176ULL: goto x86_l_1820;
	case 6178ULL: goto x86_l_1822;
	case 6181ULL: goto x86_l_1825;
	case 6183ULL: goto x86_l_1827;
	case 6185ULL: goto x86_l_1829;
	case 6193ULL: goto x86_l_1831;
	case 6196ULL: goto x86_l_1834;
	case 6201ULL: goto x86_l_1839;
	case 6208ULL: goto x86_l_1840;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6220ULL: goto x86_l_184c;
	case 6222ULL: goto x86_l_184e;
	case 6229ULL: goto x86_l_1855;
	case 6233ULL: goto x86_l_1859;
	case 6235ULL: goto x86_l_185b;
	case 6245ULL: goto x86_l_1865;
	case 6247ULL: goto x86_l_1867;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6266ULL: goto x86_l_187a;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6278ULL: goto x86_l_1886;
	case 6283ULL: goto x86_l_188b;
	case 6287ULL: goto x86_l_188f;
	case 6292ULL: goto x86_l_1894;
	case 6294ULL: goto x86_l_1896;
	case 6298ULL: goto x86_l_189a;
	case 6302ULL: goto x86_l_189e;
	case 6307ULL: goto x86_l_18a3;
	case 6309ULL: goto x86_l_18a5;
	case 6319ULL: goto x86_l_18af;
	case 6323ULL: goto x86_l_18b3;
	case 6325ULL: goto x86_l_18b5;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6339ULL: goto x86_l_18c3;
	case 6342ULL: goto x86_l_18c6;
	case 6348ULL: goto x86_l_18cc;
	case 6353ULL: goto x86_l_18d1;
	case 6359ULL: goto x86_l_18d7;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6393ULL: goto x86_l_18f9;
	case 6396ULL: goto x86_l_18fc;
	case 6398ULL: goto x86_l_18fe;
	case 6401ULL: goto x86_l_1901;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6417ULL: goto x86_l_1911;
	case 6419ULL: goto x86_l_1913;
	case 6422ULL: goto x86_l_1916;
	case 6424ULL: goto x86_l_1918;
	case 6427ULL: goto x86_l_191b;
	case 6430ULL: goto x86_l_191e;
	case 6432ULL: goto x86_l_1920;
	case 6440ULL: goto x86_l_1928;
	case 6444ULL: goto x86_l_192c;
	case 6447ULL: goto x86_l_192f;
	case 6450ULL: goto x86_l_1932;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6457ULL: goto x86_l_1939;
	case 6459ULL: goto x86_l_193b;
	case 6467ULL: goto x86_l_1943;
	case 6470ULL: goto x86_l_1946;
	case 6477ULL: goto x86_l_194d;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6489ULL: goto x86_l_1959;
	case 6491ULL: goto x86_l_195b;
	case 6498ULL: goto x86_l_1962;
	case 6502ULL: goto x86_l_1966;
	case 6504ULL: goto x86_l_1968;
	case 6514ULL: goto x86_l_1972;
	case 6516ULL: goto x86_l_1974;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6535ULL: goto x86_l_1987;
	case 6538ULL: goto x86_l_198a;
	case 6544ULL: goto x86_l_1990;
	case 6547ULL: goto x86_l_1993;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6559ULL: goto x86_l_199f;
	case 6561ULL: goto x86_l_19a1;
	case 6565ULL: goto x86_l_19a5;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6576ULL: goto x86_l_19b0;
	case 6586ULL: goto x86_l_19ba;
	case 6590ULL: goto x86_l_19be;
	case 6592ULL: goto x86_l_19c0;
	case 6595ULL: goto x86_l_19c3;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6609ULL: goto x86_l_19d1;
	case 6615ULL: goto x86_l_19d7;
	case 6620ULL: goto x86_l_19dc;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6634ULL: goto x86_l_19ea;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6654ULL: goto x86_l_19fe;
	case 6659ULL: goto x86_l_1a03;
	case 6662ULL: goto x86_l_1a06;
	case 6665ULL: goto x86_l_1a09;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6676ULL: goto x86_l_1a14;
	case 6681ULL: goto x86_l_1a19;
	case 6685ULL: goto x86_l_1a1d;
	case 6688ULL: goto x86_l_1a20;
	case 6694ULL: goto x86_l_1a26;
	case 6698ULL: goto x86_l_1a2a;
	case 6704ULL: goto x86_l_1a30;
	case 6710ULL: goto x86_l_1a36;
	case 6712ULL: goto x86_l_1a38;
	case 6716ULL: goto x86_l_1a3c;
	case 6722ULL: goto x86_l_1a42;
	case 6726ULL: goto x86_l_1a46;
	case 6732ULL: goto x86_l_1a4c;
	case 6735ULL: goto x86_l_1a4f;
	case 6738ULL: goto x86_l_1a52;
	case 6741ULL: goto x86_l_1a55;
	case 6743ULL: goto x86_l_1a57;
	case 6747ULL: goto x86_l_1a5b;
	case 6750ULL: goto x86_l_1a5e;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6765ULL: goto x86_l_1a6d;
	case 6772ULL: goto x86_l_1a74;
	case 6774ULL: goto x86_l_1a76;
	case 6777ULL: goto x86_l_1a79;
	case 6783ULL: goto x86_l_1a7f;
	case 6786ULL: goto x86_l_1a82;
	case 6788ULL: goto x86_l_1a84;
	case 6791ULL: goto x86_l_1a87;
	case 6797ULL: goto x86_l_1a8d;
	case 6800ULL: goto x86_l_1a90;
	case 6803ULL: goto x86_l_1a93;
	case 6809ULL: goto x86_l_1a99;
	case 6813ULL: goto x86_l_1a9d;
	case 6818ULL: goto x86_l_1aa2;
	case 6825ULL: goto x86_l_1aa9;
	case 6827ULL: goto x86_l_1aab;
	case 6830ULL: goto x86_l_1aae;
	case 6836ULL: goto x86_l_1ab4;
	case 6839ULL: goto x86_l_1ab7;
	case 6841ULL: goto x86_l_1ab9;
	case 6844ULL: goto x86_l_1abc;
	case 6850ULL: goto x86_l_1ac2;
	case 6853ULL: goto x86_l_1ac5;
	case 6856ULL: goto x86_l_1ac8;
	case 6862ULL: goto x86_l_1ace;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6878ULL: goto x86_l_1ade;
	case 6880ULL: goto x86_l_1ae0;
	case 6883ULL: goto x86_l_1ae3;
	case 6889ULL: goto x86_l_1ae9;
	case 6892ULL: goto x86_l_1aec;
	case 6894ULL: goto x86_l_1aee;
	case 6897ULL: goto x86_l_1af1;
	case 6903ULL: goto x86_l_1af7;
	case 6906ULL: goto x86_l_1afa;
	case 6909ULL: goto x86_l_1afd;
	case 6915ULL: goto x86_l_1b03;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6931ULL: goto x86_l_1b13;
	case 6933ULL: goto x86_l_1b15;
	case 6936ULL: goto x86_l_1b18;
	case 6942ULL: goto x86_l_1b1e;
	case 6945ULL: goto x86_l_1b21;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6956ULL: goto x86_l_1b2c;
	case 6959ULL: goto x86_l_1b2f;
	case 6962ULL: goto x86_l_1b32;
	case 6968ULL: goto x86_l_1b38;
	case 6972ULL: goto x86_l_1b3c;
	case 6977ULL: goto x86_l_1b41;
	case 6984ULL: goto x86_l_1b48;
	case 6986ULL: goto x86_l_1b4a;
	case 6989ULL: goto x86_l_1b4d;
	case 6995ULL: goto x86_l_1b53;
	case 6998ULL: goto x86_l_1b56;
	case 7000ULL: goto x86_l_1b58;
	case 7003ULL: goto x86_l_1b5b;
	case 7009ULL: goto x86_l_1b61;
	case 7012ULL: goto x86_l_1b64;
	case 7015ULL: goto x86_l_1b67;
	case 7021ULL: goto x86_l_1b6d;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7037ULL: goto x86_l_1b7d;
	case 7039ULL: goto x86_l_1b7f;
	case 7042ULL: goto x86_l_1b82;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7053ULL: goto x86_l_1b8d;
	case 7056ULL: goto x86_l_1b90;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7068ULL: goto x86_l_1b9c;
	case 7074ULL: goto x86_l_1ba2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1562:
	/* 0x1562: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1565:
	/* 0x1565: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1569:
	/* 0x1569: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_156c:
	/* 0x156c: lea    rdx,[rsi+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1570:
	/* 0x1570: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1575:
	/* 0x1575: movzx  esi,BYTE PTR [rsi+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 104ULL);
x86_l_1579:
	/* 0x1579: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157b:
	/* 0x157b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_157e:
	/* 0x157e: js     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9498ULL;
	}
x86_l_1584:
	/* 0x1584: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1589:
	/* 0x1589: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_158c:
	/* 0x158c: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_158f:
	/* 0x158f: jmp    1894 <generic_kprobe_process_filter+0x1894> */
	goto x86_l_1894;
x86_l_1594:
	/* 0x1594: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_159c:
	/* 0x159c: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_gen)));
x86_l_15a3:
	/* 0x15a3: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15a8:
	/* 0x15a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15ad:
	/* 0x15ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15af:
	/* 0x15af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15b2:
	/* 0x15b2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15b7:
	/* 0x15b7: je     1840 <generic_kprobe_process_filter+0x1840> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1840;
	}
x86_l_15bd:
	/* 0x15bd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c0:
	/* 0x15c0: cmp    rcx,QWORD PTR [rdx+0x378] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 888ULL);
x86_l_15c7:
	/* 0x15c7: je     1840 <generic_kprobe_process_filter+0x1840> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1840;
	}
x86_l_15cd:
	/* 0x15cd: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_15d5:
	/* 0x15d5: mov    rax,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_15dc:
	/* 0x15dc: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15df:
	/* 0x15df: je     17b7 <generic_kprobe_process_filter+0x17b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b7;
	}
x86_l_15e5:
	/* 0x15e5: mov    r12d,0x1869f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 99999ULL);
x86_l_15eb:
	/* 0x15eb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ee:
	/* 0x15ee: mov    rbx,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_15f5:
	/* 0x15f5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15fa:
	/* 0x15fa: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15fd:
	/* 0x15fd: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1601:
	/* 0x1601: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1606:
	/* 0x1606: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_160d:
	/* 0x160d: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1612:
	/* 0x1612: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1614:
	/* 0x1614: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1617:
	/* 0x1617: je     1829 <generic_kprobe_process_filter+0x1829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1829;
	}
x86_l_161d:
	/* 0x161d: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1620:
	/* 0x1620: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1624:
	/* 0x1624: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1629:
	/* 0x1629: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_162c:
	/* 0x162c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162e:
	/* 0x162e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1631:
	/* 0x1631: je     1648 <generic_kprobe_process_filter+0x1648> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1648;
	}
x86_l_1633:
	/* 0x1633: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1636:
	/* 0x1636: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1639:
	/* 0x1639: je     1648 <generic_kprobe_process_filter+0x1648> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1648;
	}
x86_l_163b:
	/* 0x163b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1640:
	/* 0x1640: or QWORD PTR [rcx+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_1648:
	/* 0x1648: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_164c:
	/* 0x164c: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_164f:
	/* 0x164f: cmp    rbp,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_1652:
	/* 0x1652: je     1829 <generic_kprobe_process_filter+0x1829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1829;
	}
x86_l_1658:
	/* 0x1658: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_165b:
	/* 0x165b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_165d:
	/* 0x165d: je     15f5 <generic_kprobe_process_filter+0x15f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f5;
	}
x86_l_165f:
	/* 0x165f: jmp    1829 <generic_kprobe_process_filter+0x1829> */
	goto x86_l_1829;
x86_l_1664:
	/* 0x1664: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1667:
	/* 0x1667: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_166b:
	/* 0x166b: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1672:
	/* 0x1672: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1677:
	/* 0x1677: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1679:
	/* 0x1679: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_167c:
	/* 0x167c: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_1682:
	/* 0x1682: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1685:
	/* 0x1685: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_168c:
	/* 0x168c: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1691:
	/* 0x1691: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1696:
	/* 0x1696: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1698:
	/* 0x1698: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_169b:
	/* 0x169b: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_16a1:
	/* 0x16a1: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_16a4:
	/* 0x16a4: mov    edx,0x104 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 260ULL);
x86_l_16a9:
	/* 0x16a9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_16ac:
	/* 0x16ac: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16ae:
	/* 0x16ae: call   4d87 <cwd_read_v61+0x27e4> */
	X86_SIM_L_EXEC_CALL_MEMSET(260ULL);
x86_l_16b3:
	/* 0x16b3: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b6:
	/* 0x16b6: lea    ecx,[rax*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 0ULL);
x86_l_16bd:
	/* 0x16bd: mov    DWORD PTR [rbx],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bf:
	/* 0x16bf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16c2:
	/* 0x16c2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_16c6:
	/* 0x16c6: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16c9:
	/* 0x16c9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_16cc:
	/* 0x16cc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16d0:
	/* 0x16d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16d5:
	/* 0x16d5: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16d9:
	/* 0x16d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16db:
	/* 0x16db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16de:
	/* 0x16de: js     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9498ULL;
	}
x86_l_16e4:
	/* 0x16e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e9:
	/* 0x16e9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_16ec:
	/* 0x16ec: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_16ef:
	/* 0x16ef: jmp    199f <generic_kprobe_process_filter+0x199f> */
	goto x86_l_199f;
x86_l_16f4:
	/* 0x16f4: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_16fc:
	/* 0x16fc: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_gen)));
x86_l_1703:
	/* 0x1703: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1708:
	/* 0x1708: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_170d:
	/* 0x170d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170f:
	/* 0x170f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1712:
	/* 0x1712: je     194d <generic_kprobe_process_filter+0x194d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_194d;
	}
x86_l_1718:
	/* 0x1718: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_171b:
	/* 0x171b: cmp    rcx,QWORD PTR [rbp+0x310] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 784ULL);
x86_l_1722:
	/* 0x1722: je     194d <generic_kprobe_process_filter+0x194d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_194d;
	}
x86_l_1728:
	/* 0x1728: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1730:
	/* 0x1730: mov    rax,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1737:
	/* 0x1737: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_173a:
	/* 0x173a: je     18d1 <generic_kprobe_process_filter+0x18d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18d1;
	}
x86_l_1740:
	/* 0x1740: mov    r12d,0x1869f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 99999ULL);
x86_l_1746:
	/* 0x1746: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1749:
	/* 0x1749: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_174e:
	/* 0x174e: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1751:
	/* 0x1751: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1755:
	/* 0x1755: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_175a:
	/* 0x175a: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1761:
	/* 0x1761: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1766:
	/* 0x1766: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1768:
	/* 0x1768: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_176b:
	/* 0x176b: je     193b <generic_kprobe_process_filter+0x193b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_193b;
	}
x86_l_1771:
	/* 0x1771: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1774:
	/* 0x1774: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1778:
	/* 0x1778: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_177d:
	/* 0x177d: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_1784:
	/* 0x1784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1786:
	/* 0x1786: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1789:
	/* 0x1789: je     179b <generic_kprobe_process_filter+0x179b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_179b;
	}
x86_l_178b:
	/* 0x178b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_178e:
	/* 0x178e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1791:
	/* 0x1791: je     179b <generic_kprobe_process_filter+0x179b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_179b;
	}
x86_l_1793:
	/* 0x1793: or QWORD PTR [rbp+0x308],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 776ULL);
x86_l_179b:
	/* 0x179b: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_179f:
	/* 0x179f: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_17a2:
	/* 0x17a2: cmp    rbx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_17a5:
	/* 0x17a5: je     193b <generic_kprobe_process_filter+0x193b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_193b;
	}
x86_l_17ab:
	/* 0x17ab: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_17ae:
	/* 0x17ae: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_17b0:
	/* 0x17b0: je     1749 <generic_kprobe_process_filter+0x1749> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1749;
	}
x86_l_17b2:
	/* 0x17b2: jmp    193b <generic_kprobe_process_filter+0x193b> */
	goto x86_l_193b;
x86_l_17b7:
	/* 0x17b7: mov    r12d,0x3ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_17bd:
	/* 0x17bd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17c0:
	/* 0x17c0: mov    rbx,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_17c7:
	/* 0x17c7: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17cc:
	/* 0x17cc: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17cf:
	/* 0x17cf: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17d3:
	/* 0x17d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17d8:
	/* 0x17d8: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_17df:
	/* 0x17df: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17e4:
	/* 0x17e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e6:
	/* 0x17e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17e9:
	/* 0x17e9: je     1829 <generic_kprobe_process_filter+0x1829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1829;
	}
x86_l_17eb:
	/* 0x17eb: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_17ee:
	/* 0x17ee: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17f2:
	/* 0x17f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17f7:
	/* 0x17f7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17fa:
	/* 0x17fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17fc:
	/* 0x17fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17ff:
	/* 0x17ff: je     1816 <generic_kprobe_process_filter+0x1816> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1816;
	}
x86_l_1801:
	/* 0x1801: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1804:
	/* 0x1804: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1807:
	/* 0x1807: je     1816 <generic_kprobe_process_filter+0x1816> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1816;
	}
x86_l_1809:
	/* 0x1809: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_180e:
	/* 0x180e: or QWORD PTR [rcx+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_1816:
	/* 0x1816: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_181a:
	/* 0x181a: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_181d:
	/* 0x181d: cmp    rbp,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_1820:
	/* 0x1820: je     1829 <generic_kprobe_process_filter+0x1829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1829;
	}
x86_l_1822:
	/* 0x1822: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_1825:
	/* 0x1825: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1827:
	/* 0x1827: je     17c7 <generic_kprobe_process_filter+0x17c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17c7;
	}
x86_l_1829:
	/* 0x1829: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1831:
	/* 0x1831: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1834:
	/* 0x1834: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1839:
	/* 0x1839: mov    QWORD PTR [rdx+0x378],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 888ULL);
x86_l_1840:
	/* 0x1840: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1844:
	/* 0x1844: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1849:
	/* 0x1849: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_184c:
	/* 0x184c: je     1867 <generic_kprobe_process_filter+0x1867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1867;
	}
x86_l_184e:
	/* 0x184e: mov    rcx,QWORD PTR [rdx+0x370] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 880ULL);
x86_l_1855:
	/* 0x1855: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1859:
	/* 0x1859: jae    1867 <generic_kprobe_process_filter+0x1867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1867;
	}
x86_l_185b:
	/* 0x185b: movabs rax,0xbadc0ffee */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 50159747054ULL);
x86_l_1865:
	/* 0x1865: jmp    1896 <generic_kprobe_process_filter+0x1896> */
	goto x86_l_1896;
x86_l_1867:
	/* 0x1867: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_paths)));
x86_l_186e:
	/* 0x186e: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1873:
	/* 0x1873: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1878:
	/* 0x1878: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187a:
	/* 0x187a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_187d:
	/* 0x187d: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_1883:
	/* 0x1883: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1886:
	/* 0x1886: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_188b:
	/* 0x188b: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_188f:
	/* 0x188f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1894:
	/* 0x1894: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1896:
	/* 0x1896: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189a:
	/* 0x189a: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_189e:
	/* 0x189e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18a3:
	/* 0x18a3: ja     18c3 <generic_kprobe_process_filter+0x18c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c3;
	}
x86_l_18a5:
	/* 0x18a5: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_18af:
	/* 0x18af: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_18b3:
	/* 0x18b3: jae    18c3 <generic_kprobe_process_filter+0x18c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18c3;
	}
x86_l_18b5:
	/* 0x18b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18b8:
	/* 0x18b8: jne    251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9498ULL;
	}
x86_l_18be:
	/* 0x18be: jmp    1162 <generic_kprobe_process_filter+0x1162> */
	return 4450ULL;
x86_l_18c3:
	/* 0x18c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18c6:
	/* 0x18c6: jne    1162 <generic_kprobe_process_filter+0x1162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4450ULL;
	}
x86_l_18cc:
	/* 0x18cc: jmp    251a <generic_kprobe_process_filter+0x251a> */
	return 9498ULL;
x86_l_18d1:
	/* 0x18d1: mov    r12d,0x3ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_18d7:
	/* 0x18d7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18da:
	/* 0x18da: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18df:
	/* 0x18df: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18e2:
	/* 0x18e2: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18e6:
	/* 0x18e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18eb:
	/* 0x18eb: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_18f2:
	/* 0x18f2: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18f7:
	/* 0x18f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f9:
	/* 0x18f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18fc:
	/* 0x18fc: je     193b <generic_kprobe_process_filter+0x193b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_193b;
	}
x86_l_18fe:
	/* 0x18fe: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1901:
	/* 0x1901: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1905:
	/* 0x1905: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_190a:
	/* 0x190a: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_1911:
	/* 0x1911: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1913:
	/* 0x1913: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1916:
	/* 0x1916: je     1928 <generic_kprobe_process_filter+0x1928> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1928;
	}
x86_l_1918:
	/* 0x1918: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_191b:
	/* 0x191b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_191e:
	/* 0x191e: je     1928 <generic_kprobe_process_filter+0x1928> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1928;
	}
x86_l_1920:
	/* 0x1920: or QWORD PTR [rbp+0x308],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 776ULL);
x86_l_1928:
	/* 0x1928: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_192c:
	/* 0x192c: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_192f:
	/* 0x192f: cmp    rbx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1932:
	/* 0x1932: je     193b <generic_kprobe_process_filter+0x193b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_193b;
	}
x86_l_1934:
	/* 0x1934: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1937:
	/* 0x1937: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1939:
	/* 0x1939: je     18da <generic_kprobe_process_filter+0x18da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18da;
	}
x86_l_193b:
	/* 0x193b: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1943:
	/* 0x1943: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1946:
	/* 0x1946: mov    QWORD PTR [rbp+0x310],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 784ULL);
x86_l_194d:
	/* 0x194d: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1951:
	/* 0x1951: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1956:
	/* 0x1956: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1959:
	/* 0x1959: je     1974 <generic_kprobe_process_filter+0x1974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1974;
	}
x86_l_195b:
	/* 0x195b: mov    rcx,QWORD PTR [rbp+0x308] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 776ULL);
x86_l_1962:
	/* 0x1962: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1966:
	/* 0x1966: jae    1974 <generic_kprobe_process_filter+0x1974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1974;
	}
x86_l_1968:
	/* 0x1968: movabs rax,0xbadc0ffee */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 50159747054ULL);
x86_l_1972:
	/* 0x1972: jmp    19a1 <generic_kprobe_process_filter+0x19a1> */
	goto x86_l_19a1;
x86_l_1974:
	/* 0x1974: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_paths)));
x86_l_197b:
	/* 0x197b: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1980:
	/* 0x1980: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1985:
	/* 0x1985: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1987:
	/* 0x1987: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_198a:
	/* 0x198a: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_1990:
	/* 0x1990: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1993:
	/* 0x1993: add    rbp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1997:
	/* 0x1997: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_199c:
	/* 0x199c: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_199f:
	/* 0x199f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a1:
	/* 0x19a1: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a5:
	/* 0x19a5: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_19a9:
	/* 0x19a9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ae:
	/* 0x19ae: ja     19ce <generic_kprobe_process_filter+0x19ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19ce;
	}
x86_l_19b0:
	/* 0x19b0: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_19ba:
	/* 0x19ba: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_19be:
	/* 0x19be: jae    19ce <generic_kprobe_process_filter+0x19ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19ce;
	}
x86_l_19c0:
	/* 0x19c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19c3:
	/* 0x19c3: jne    251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9498ULL;
	}
x86_l_19c9:
	/* 0x19c9: jmp    13f1 <generic_kprobe_process_filter+0x13f1> */
	return 5105ULL;
x86_l_19ce:
	/* 0x19ce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19d1:
	/* 0x19d1: jne    13f1 <generic_kprobe_process_filter+0x13f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5105ULL;
	}
x86_l_19d7:
	/* 0x19d7: jmp    251a <generic_kprobe_process_filter+0x251a> */
	return 9498ULL;
x86_l_19dc:
	/* 0x19dc: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19e1:
	/* 0x19e1: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19e6:
	/* 0x19e6: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19ea:
	/* 0x19ea: mov    r8,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19ef:
	/* 0x19ef: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19f4:
	/* 0x19f4: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19f9:
	/* 0x19f9: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19fe:
	/* 0x19fe: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a03:
	/* 0x1a03: cmp    edi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_1a06:
	/* 0x1a06: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1a09:
	/* 0x1a09: xor    r13b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1a0d:
	/* 0x1a0d: or     r13b,al */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a10:
	/* 0x1a10: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a14:
	/* 0x1a14: mov    DWORD PTR [rsp+r14*1+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 112ULL);
x86_l_1a19:
	/* 0x1a19: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a1d:
	/* 0x1a1d: cmp    rcx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1a20:
	/* 0x1a20: je     1e7b <generic_kprobe_process_filter+0x1e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7803ULL;
	}
x86_l_1a26:
	/* 0x1a26: lea    rax,[r10+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1a2a:
	/* 0x1a2a: cmp    rax,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1000ULL);
x86_l_1a30:
	/* 0x1a30: jbe    1c52 <generic_kprobe_process_filter+0x1c52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7250ULL;
	}
x86_l_1a36:
	/* 0x1a36: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a38:
	/* 0x1a38: test   r8b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 2ULL);
x86_l_1a3c:
	/* 0x1a3c: je     1c60 <generic_kprobe_process_filter+0x1c60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7264ULL;
	}
x86_l_1a42:
	/* 0x1a42: test   r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_1a46:
	/* 0x1a46: jne    1c82 <generic_kprobe_process_filter+0x1c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7298ULL;
	}
x86_l_1a4c:
	/* 0x1a4c: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1a52:
	/* 0x1a52: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a55:
	/* 0x1a55: je     1a03 <generic_kprobe_process_filter+0x1a03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a03;
	}
x86_l_1a57:
	/* 0x1a57: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a5b:
	/* 0x1a5b: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a5e:
	/* 0x1a5e: je     1a03 <generic_kprobe_process_filter+0x1a03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a03;
	}
x86_l_1a60:
	/* 0x1a60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a65:
	/* 0x1a65: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1a74:
	/* 0x1a74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a76:
	/* 0x1a76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a79:
	/* 0x1a79: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7744ULL;
	}
x86_l_1a7f:
	/* 0x1a7f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1a82:
	/* 0x1a82: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a84:
	/* 0x1a84: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a87:
	/* 0x1a87: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1a8d:
	/* 0x1a8d: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a90:
	/* 0x1a90: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a93:
	/* 0x1a93: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1a99:
	/* 0x1a99: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a9d:
	/* 0x1a9d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1aa9:
	/* 0x1aa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aab:
	/* 0x1aab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1aae:
	/* 0x1aae: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7744ULL;
	}
x86_l_1ab4:
	/* 0x1ab4: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1ab7:
	/* 0x1ab7: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab9:
	/* 0x1ab9: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1abc:
	/* 0x1abc: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1ac2:
	/* 0x1ac2: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ac5:
	/* 0x1ac5: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1ac8:
	/* 0x1ac8: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1ace:
	/* 0x1ace: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ad7:
	/* 0x1ad7: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1ade:
	/* 0x1ade: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae0:
	/* 0x1ae0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ae3:
	/* 0x1ae3: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7744ULL;
	}
x86_l_1ae9:
	/* 0x1ae9: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1aec:
	/* 0x1aec: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aee:
	/* 0x1aee: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1af1:
	/* 0x1af1: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1af7:
	/* 0x1af7: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1afa:
	/* 0x1afa: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1afd:
	/* 0x1afd: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1b03:
	/* 0x1b03: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b07:
	/* 0x1b07: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1b13:
	/* 0x1b13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b15:
	/* 0x1b15: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b18:
	/* 0x1b18: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7744ULL;
	}
x86_l_1b1e:
	/* 0x1b1e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1b21:
	/* 0x1b21: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b23:
	/* 0x1b23: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b26:
	/* 0x1b26: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1b2c:
	/* 0x1b2c: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b2f:
	/* 0x1b2f: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b32:
	/* 0x1b32: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1b38:
	/* 0x1b38: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b3c:
	/* 0x1b3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b41:
	/* 0x1b41: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1b48:
	/* 0x1b48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4a:
	/* 0x1b4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b4d:
	/* 0x1b4d: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7744ULL;
	}
x86_l_1b53:
	/* 0x1b53: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1b56:
	/* 0x1b56: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b58:
	/* 0x1b58: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b5b:
	/* 0x1b5b: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1b61:
	/* 0x1b61: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b64:
	/* 0x1b64: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b67:
	/* 0x1b67: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e1;
	}
x86_l_1b6d:
	/* 0x1b6d: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b71:
	/* 0x1b71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b76:
	/* 0x1b76: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1b7d:
	/* 0x1b7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b7f:
	/* 0x1b7f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b82:
	/* 0x1b82: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7744ULL;
	}
x86_l_1b88:
	/* 0x1b88: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1b8b:
	/* 0x1b8b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b8d:
	/* 0x1b8d: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b90:
	/* 0x1b90: je     19dc <generic_kprobe_process_filter+0x19dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19dc;
	}
x86_l_1b96:
	/* 0x1b96: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b99:
	/* 0x1b99: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b9c:
	/* 0x1b9c: je     19dc <generic_kprobe_process_filter+0x19dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19dc;
	}
x86_l_1ba2:
	/* 0x1ba2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
	return 7078ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7090ULL: goto x86_l_1bb2;
	case 7092ULL: goto x86_l_1bb4;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7106ULL: goto x86_l_1bc2;
	case 7109ULL: goto x86_l_1bc5;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7126ULL: goto x86_l_1bd6;
	case 7132ULL: goto x86_l_1bdc;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7148ULL: goto x86_l_1bec;
	case 7150ULL: goto x86_l_1bee;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7164ULL: goto x86_l_1bfc;
	case 7167ULL: goto x86_l_1bff;
	case 7169ULL: goto x86_l_1c01;
	case 7172ULL: goto x86_l_1c04;
	case 7178ULL: goto x86_l_1c0a;
	case 7181ULL: goto x86_l_1c0d;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7229ULL: goto x86_l_1c3d;
	case 7233ULL: goto x86_l_1c41;
	case 7238ULL: goto x86_l_1c46;
	case 7245ULL: goto x86_l_1c4d;
	case 7250ULL: goto x86_l_1c52;
	case 7254ULL: goto x86_l_1c56;
	case 7258ULL: goto x86_l_1c5a;
	case 7264ULL: goto x86_l_1c60;
	case 7266ULL: goto x86_l_1c62;
	case 7269ULL: goto x86_l_1c65;
	case 7271ULL: goto x86_l_1c67;
	case 7274ULL: goto x86_l_1c6a;
	case 7280ULL: goto x86_l_1c70;
	case 7283ULL: goto x86_l_1c73;
	case 7286ULL: goto x86_l_1c76;
	case 7289ULL: goto x86_l_1c79;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7306ULL: goto x86_l_1c8a;
	case 7308ULL: goto x86_l_1c8c;
	case 7311ULL: goto x86_l_1c8f;
	case 7317ULL: goto x86_l_1c95;
	case 7320ULL: goto x86_l_1c98;
	case 7323ULL: goto x86_l_1c9b;
	case 7329ULL: goto x86_l_1ca1;
	case 7332ULL: goto x86_l_1ca4;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7351ULL: goto x86_l_1cb7;
	case 7358ULL: goto x86_l_1cbe;
	case 7360ULL: goto x86_l_1cc0;
	case 7363ULL: goto x86_l_1cc3;
	case 7369ULL: goto x86_l_1cc9;
	case 7372ULL: goto x86_l_1ccc;
	case 7375ULL: goto x86_l_1ccf;
	case 7378ULL: goto x86_l_1cd2;
	case 7384ULL: goto x86_l_1cd8;
	case 7388ULL: goto x86_l_1cdc;
	case 7393ULL: goto x86_l_1ce1;
	case 7400ULL: goto x86_l_1ce8;
	case 7402ULL: goto x86_l_1cea;
	case 7405ULL: goto x86_l_1ced;
	case 7411ULL: goto x86_l_1cf3;
	case 7414ULL: goto x86_l_1cf6;
	case 7417ULL: goto x86_l_1cf9;
	case 7420ULL: goto x86_l_1cfc;
	case 7426ULL: goto x86_l_1d02;
	case 7430ULL: goto x86_l_1d06;
	case 7435ULL: goto x86_l_1d0b;
	case 7442ULL: goto x86_l_1d12;
	case 7444ULL: goto x86_l_1d14;
	case 7447ULL: goto x86_l_1d17;
	case 7453ULL: goto x86_l_1d1d;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7462ULL: goto x86_l_1d26;
	case 7468ULL: goto x86_l_1d2c;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7484ULL: goto x86_l_1d3c;
	case 7486ULL: goto x86_l_1d3e;
	case 7489ULL: goto x86_l_1d41;
	case 7495ULL: goto x86_l_1d47;
	case 7498ULL: goto x86_l_1d4a;
	case 7501ULL: goto x86_l_1d4d;
	case 7504ULL: goto x86_l_1d50;
	case 7510ULL: goto x86_l_1d56;
	case 7514ULL: goto x86_l_1d5a;
	case 7519ULL: goto x86_l_1d5f;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7531ULL: goto x86_l_1d6b;
	case 7537ULL: goto x86_l_1d71;
	case 7540ULL: goto x86_l_1d74;
	case 7543ULL: goto x86_l_1d77;
	case 7546ULL: goto x86_l_1d7a;
	case 7552ULL: goto x86_l_1d80;
	case 7556ULL: goto x86_l_1d84;
	case 7561ULL: goto x86_l_1d89;
	case 7568ULL: goto x86_l_1d90;
	case 7570ULL: goto x86_l_1d92;
	case 7573ULL: goto x86_l_1d95;
	case 7579ULL: goto x86_l_1d9b;
	case 7582ULL: goto x86_l_1d9e;
	case 7585ULL: goto x86_l_1da1;
	case 7588ULL: goto x86_l_1da4;
	case 7594ULL: goto x86_l_1daa;
	case 7598ULL: goto x86_l_1dae;
	case 7603ULL: goto x86_l_1db3;
	case 7610ULL: goto x86_l_1dba;
	case 7612ULL: goto x86_l_1dbc;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7622ULL: goto x86_l_1dc6;
	case 7625ULL: goto x86_l_1dc9;
	case 7628ULL: goto x86_l_1dcc;
	case 7631ULL: goto x86_l_1dcf;
	case 7637ULL: goto x86_l_1dd5;
	case 7641ULL: goto x86_l_1dd9;
	case 7646ULL: goto x86_l_1dde;
	case 7653ULL: goto x86_l_1de5;
	case 7655ULL: goto x86_l_1de7;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7665ULL: goto x86_l_1df1;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7679ULL: goto x86_l_1dff;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7693ULL: goto x86_l_1e0d;
	case 7698ULL: goto x86_l_1e12;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7714ULL: goto x86_l_1e22;
	case 7718ULL: goto x86_l_1e26;
	case 7723ULL: goto x86_l_1e2b;
	case 7730ULL: goto x86_l_1e32;
	case 7737ULL: goto x86_l_1e39;
	case 7739ULL: goto x86_l_1e3b;
	case 7744ULL: goto x86_l_1e40;
	case 7747ULL: goto x86_l_1e43;
	case 7751ULL: goto x86_l_1e47;
	case 7754ULL: goto x86_l_1e4a;
	case 7759ULL: goto x86_l_1e4f;
	case 7764ULL: goto x86_l_1e54;
	case 7769ULL: goto x86_l_1e59;
	case 7774ULL: goto x86_l_1e5e;
	case 7779ULL: goto x86_l_1e63;
	case 7784ULL: goto x86_l_1e68;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7803ULL: goto x86_l_1e7b;
	case 7807ULL: goto x86_l_1e7f;
	case 7811ULL: goto x86_l_1e83;
	case 7815ULL: goto x86_l_1e87;
	case 7819ULL: goto x86_l_1e8b;
	case 7822ULL: goto x86_l_1e8e;
	case 7824ULL: goto x86_l_1e90;
	case 7826ULL: goto x86_l_1e92;
	case 7828ULL: goto x86_l_1e94;
	case 7830ULL: goto x86_l_1e96;
	case 7832ULL: goto x86_l_1e98;
	case 7834ULL: goto x86_l_1e9a;
	case 7836ULL: goto x86_l_1e9c;
	case 7838ULL: goto x86_l_1e9e;
	case 7840ULL: goto x86_l_1ea0;
	case 7846ULL: goto x86_l_1ea6;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7862ULL: goto x86_l_1eb6;
	case 7864ULL: goto x86_l_1eb8;
	case 7870ULL: goto x86_l_1ebe;
	case 7874ULL: goto x86_l_1ec2;
	case 7877ULL: goto x86_l_1ec5;
	case 7880ULL: goto x86_l_1ec8;
	case 7886ULL: goto x86_l_1ece;
	case 7888ULL: goto x86_l_1ed0;
	case 7890ULL: goto x86_l_1ed2;
	case 7893ULL: goto x86_l_1ed5;
	case 7899ULL: goto x86_l_1edb;
	case 7901ULL: goto x86_l_1edd;
	case 7903ULL: goto x86_l_1edf;
	case 7905ULL: goto x86_l_1ee1;
	case 7910ULL: goto x86_l_1ee6;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7933ULL: goto x86_l_1efd;
	case 7942ULL: goto x86_l_1f06;
	case 7946ULL: goto x86_l_1f0a;
	case 7951ULL: goto x86_l_1f0f;
	case 7955ULL: goto x86_l_1f13;
	case 7959ULL: goto x86_l_1f17;
	case 7961ULL: goto x86_l_1f19;
	case 7971ULL: goto x86_l_1f23;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7985ULL: goto x86_l_1f31;
	case 7988ULL: goto x86_l_1f34;
	case 7994ULL: goto x86_l_1f3a;
	case 7997ULL: goto x86_l_1f3d;
	case 8000ULL: goto x86_l_1f40;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8018ULL: goto x86_l_1f52;
	case 8020ULL: goto x86_l_1f54;
	case 8028ULL: goto x86_l_1f5c;
	case 8033ULL: goto x86_l_1f61;
	case 8035ULL: goto x86_l_1f63;
	case 8040ULL: goto x86_l_1f68;
	case 8045ULL: goto x86_l_1f6d;
	case 8050ULL: goto x86_l_1f72;
	case 8052ULL: goto x86_l_1f74;
	case 8059ULL: goto x86_l_1f7b;
	case 8061ULL: goto x86_l_1f7d;
	case 8064ULL: goto x86_l_1f80;
	case 8067ULL: goto x86_l_1f83;
	case 8071ULL: goto x86_l_1f87;
	case 8076ULL: goto x86_l_1f8c;
	case 8080ULL: goto x86_l_1f90;
	case 8083ULL: goto x86_l_1f93;
	case 8087ULL: goto x86_l_1f97;
	case 8091ULL: goto x86_l_1f9b;
	case 8094ULL: goto x86_l_1f9e;
	case 8097ULL: goto x86_l_1fa1;
	case 8100ULL: goto x86_l_1fa4;
	case 8103ULL: goto x86_l_1fa7;
	case 8105ULL: goto x86_l_1fa9;
	case 8109ULL: goto x86_l_1fad;
	case 8112ULL: goto x86_l_1fb0;
	case 8115ULL: goto x86_l_1fb3;
	case 8119ULL: goto x86_l_1fb7;
	case 8122ULL: goto x86_l_1fba;
	case 8126ULL: goto x86_l_1fbe;
	case 8130ULL: goto x86_l_1fc2;
	case 8133ULL: goto x86_l_1fc5;
	case 8139ULL: goto x86_l_1fcb;
	case 8142ULL: goto x86_l_1fce;
	case 8144ULL: goto x86_l_1fd0;
	case 8150ULL: goto x86_l_1fd6;
	case 8152ULL: goto x86_l_1fd8;
	case 8155ULL: goto x86_l_1fdb;
	case 8159ULL: goto x86_l_1fdf;
	case 8163ULL: goto x86_l_1fe3;
	case 8167ULL: goto x86_l_1fe7;
	case 8170ULL: goto x86_l_1fea;
	case 8173ULL: goto x86_l_1fed;
	case 8175ULL: goto x86_l_1fef;
	case 8179ULL: goto x86_l_1ff3;
	case 8182ULL: goto x86_l_1ff6;
	case 8185ULL: goto x86_l_1ff9;
	case 8189ULL: goto x86_l_1ffd;
	case 8192ULL: goto x86_l_2000;
	case 8196ULL: goto x86_l_2004;
	case 8200ULL: goto x86_l_2008;
	case 8204ULL: goto x86_l_200c;
	case 8206ULL: goto x86_l_200e;
	case 8209ULL: goto x86_l_2011;
	case 8211ULL: goto x86_l_2013;
	case 8217ULL: goto x86_l_2019;
	case 8219ULL: goto x86_l_201b;
	case 8222ULL: goto x86_l_201e;
	case 8226ULL: goto x86_l_2022;
	case 8230ULL: goto x86_l_2026;
	case 8234ULL: goto x86_l_202a;
	case 8237ULL: goto x86_l_202d;
	case 8240ULL: goto x86_l_2030;
	case 8242ULL: goto x86_l_2032;
	case 8246ULL: goto x86_l_2036;
	case 8249ULL: goto x86_l_2039;
	case 8252ULL: goto x86_l_203c;
	case 8256ULL: goto x86_l_2040;
	case 8259ULL: goto x86_l_2043;
	case 8263ULL: goto x86_l_2047;
	case 8267ULL: goto x86_l_204b;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8276ULL: goto x86_l_2054;
	case 8278ULL: goto x86_l_2056;
	case 8284ULL: goto x86_l_205c;
	case 8286ULL: goto x86_l_205e;
	case 8289ULL: goto x86_l_2061;
	case 8293ULL: goto x86_l_2065;
	case 8297ULL: goto x86_l_2069;
	case 8301ULL: goto x86_l_206d;
	case 8303ULL: goto x86_l_206f;
	case 8305ULL: goto x86_l_2071;
	case 8307ULL: goto x86_l_2073;
	case 8310ULL: goto x86_l_2076;
	case 8313ULL: goto x86_l_2079;
	case 8315ULL: goto x86_l_207b;
	case 8318ULL: goto x86_l_207e;
	case 8320ULL: goto x86_l_2080;
	case 8323ULL: goto x86_l_2083;
	case 8327ULL: goto x86_l_2087;
	case 8331ULL: goto x86_l_208b;
	case 8335ULL: goto x86_l_208f;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8347ULL: goto x86_l_209b;
	case 8349ULL: goto x86_l_209d;
	case 8351ULL: goto x86_l_209f;
	case 8353ULL: goto x86_l_20a1;
	case 8355ULL: goto x86_l_20a3;
	case 8357ULL: goto x86_l_20a5;
	case 8359ULL: goto x86_l_20a7;
	case 8361ULL: goto x86_l_20a9;
	case 8363ULL: goto x86_l_20ab;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8375ULL: goto x86_l_20b7;
	case 8378ULL: goto x86_l_20ba;
	case 8382ULL: goto x86_l_20be;
	case 8385ULL: goto x86_l_20c1;
	case 8388ULL: goto x86_l_20c4;
	case 8391ULL: goto x86_l_20c7;
	case 8394ULL: goto x86_l_20ca;
	case 8400ULL: goto x86_l_20d0;
	case 8402ULL: goto x86_l_20d2;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8418ULL: goto x86_l_20e2;
	case 8424ULL: goto x86_l_20e8;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8438ULL: goto x86_l_20f6;
	case 8443ULL: goto x86_l_20fb;
	case 8445ULL: goto x86_l_20fd;
	case 8450ULL: goto x86_l_2102;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8457ULL: goto x86_l_2109;
	case 8459ULL: goto x86_l_210b;
	case 8463ULL: goto x86_l_210f;
	case 8465ULL: goto x86_l_2111;
	case 8467ULL: goto x86_l_2113;
	case 8470ULL: goto x86_l_2116;
	case 8472ULL: goto x86_l_2118;
	case 8474ULL: goto x86_l_211a;
	case 8476ULL: goto x86_l_211c;
	case 8481ULL: goto x86_l_2121;
	case 8484ULL: goto x86_l_2124;
	case 8486ULL: goto x86_l_2126;
	case 8489ULL: goto x86_l_2129;
	case 8493ULL: goto x86_l_212d;
	case 8495ULL: goto x86_l_212f;
	case 8498ULL: goto x86_l_2132;
	case 8502ULL: goto x86_l_2136;
	case 8505ULL: goto x86_l_2139;
	case 8509ULL: goto x86_l_213d;
	case 8511ULL: goto x86_l_213f;
	case 8513ULL: goto x86_l_2141;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8527ULL: goto x86_l_214f;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8541ULL: goto x86_l_215d;
	case 8546ULL: goto x86_l_2162;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8560ULL: goto x86_l_2170;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ba6:
	/* 0x1ba6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bab:
	/* 0x1bab: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1bb2:
	/* 0x1bb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb4:
	/* 0x1bb4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bb7:
	/* 0x1bb7: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bbc:
	/* 0x1bbc: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1bc2:
	/* 0x1bc2: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1bc5:
	/* 0x1bc5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc7:
	/* 0x1bc7: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1bca:
	/* 0x1bca: je     19dc <generic_kprobe_process_filter+0x19dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6620ULL;
	}
x86_l_1bd0:
	/* 0x1bd0: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bd3:
	/* 0x1bd3: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1bd6:
	/* 0x1bd6: je     19dc <generic_kprobe_process_filter+0x19dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6620ULL;
	}
x86_l_1bdc:
	/* 0x1bdc: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1be0:
	/* 0x1be0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1be5:
	/* 0x1be5: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1bec:
	/* 0x1bec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bee:
	/* 0x1bee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bf1:
	/* 0x1bf1: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bf6:
	/* 0x1bf6: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1bfc:
	/* 0x1bfc: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1bff:
	/* 0x1bff: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c01:
	/* 0x1c01: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1c04:
	/* 0x1c04: je     19dc <generic_kprobe_process_filter+0x19dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6620ULL;
	}
x86_l_1c0a:
	/* 0x1c0a: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c0d:
	/* 0x1c0d: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1c10:
	/* 0x1c10: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c15:
	/* 0x1c15: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c1a:
	/* 0x1c1a: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    r8,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c23:
	/* 0x1c23: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c28:
	/* 0x1c28: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c2d:
	/* 0x1c2d: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c32:
	/* 0x1c32: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c37:
	/* 0x1c37: je     1a03 <generic_kprobe_process_filter+0x1a03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6659ULL;
	}
x86_l_1c3d:
	/* 0x1c3d: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c41:
	/* 0x1c41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c46:
	/* 0x1c46: mov    rcx,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1c4d:
	/* 0x1c4d: jmp    1e32 <generic_kprobe_process_filter+0x1e32> */
	goto x86_l_1e32;
x86_l_1c52:
	/* 0x1c52: mov    ebx,DWORD PTR [r11+r14*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1c56:
	/* 0x1c56: test   r8b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 2ULL);
x86_l_1c5a:
	/* 0x1c5a: jne    1a42 <generic_kprobe_process_filter+0x1a42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6722ULL;
	}
x86_l_1c60:
	/* 0x1c60: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c62:
	/* 0x1c62: cmp    edi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1c65:
	/* 0x1c65: jne    1c70 <generic_kprobe_process_filter+0x1c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c70;
	}
x86_l_1c67:
	/* 0x1c67: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1c6a:
	/* 0x1c6a: jne    1e73 <generic_kprobe_process_filter+0x1e73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e73;
	}
x86_l_1c70:
	/* 0x1c70: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1c73:
	/* 0x1c73: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1c76:
	/* 0x1c76: cmp    edi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_1c79:
	/* 0x1c79: setne  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_NE);
x86_l_1c7d:
	/* 0x1c7d: jmp    1a0d <generic_kprobe_process_filter+0x1a0d> */
	return 6669ULL;
x86_l_1c82:
	/* 0x1c82: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c8a:
	/* 0x1c8a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c8c:
	/* 0x1c8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c8f:
	/* 0x1c8f: je     1e73 <generic_kprobe_process_filter+0x1e73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e73;
	}
x86_l_1c95:
	/* 0x1c95: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1c98:
	/* 0x1c98: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1c9b:
	/* 0x1c9b: je     1a03 <generic_kprobe_process_filter+0x1a03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6659ULL;
	}
x86_l_1ca1:
	/* 0x1ca1: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1ca4:
	/* 0x1ca4: je     1a03 <generic_kprobe_process_filter+0x1a03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6659ULL;
	}
x86_l_1caa:
	/* 0x1caa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1caf:
	/* 0x1caf: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1cbe:
	/* 0x1cbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc0:
	/* 0x1cc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cc3:
	/* 0x1cc3: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1cc9:
	/* 0x1cc9: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1ccc:
	/* 0x1ccc: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ccf:
	/* 0x1ccf: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1cd2:
	/* 0x1cd2: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6625ULL;
	}
x86_l_1cd8:
	/* 0x1cd8: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1ce8:
	/* 0x1ce8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cea:
	/* 0x1cea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ced:
	/* 0x1ced: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1cf3:
	/* 0x1cf3: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1cf6:
	/* 0x1cf6: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1cf9:
	/* 0x1cf9: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1cfc:
	/* 0x1cfc: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6625ULL;
	}
x86_l_1d02:
	/* 0x1d02: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d06:
	/* 0x1d06: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d0b:
	/* 0x1d0b: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1d12:
	/* 0x1d12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d14:
	/* 0x1d14: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d17:
	/* 0x1d17: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1d1d:
	/* 0x1d1d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1d20:
	/* 0x1d20: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d23:
	/* 0x1d23: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1d26:
	/* 0x1d26: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6625ULL;
	}
x86_l_1d2c:
	/* 0x1d2c: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d30:
	/* 0x1d30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d35:
	/* 0x1d35: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1d3c:
	/* 0x1d3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3e:
	/* 0x1d3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d41:
	/* 0x1d41: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1d47:
	/* 0x1d47: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1d4a:
	/* 0x1d4a: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d4d:
	/* 0x1d4d: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1d50:
	/* 0x1d50: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6625ULL;
	}
x86_l_1d56:
	/* 0x1d56: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d5f:
	/* 0x1d5f: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1d66:
	/* 0x1d66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d68:
	/* 0x1d68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d6b:
	/* 0x1d6b: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1d71:
	/* 0x1d71: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1d74:
	/* 0x1d74: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d77:
	/* 0x1d77: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1d7a:
	/* 0x1d7a: je     19e1 <generic_kprobe_process_filter+0x19e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6625ULL;
	}
x86_l_1d80:
	/* 0x1d80: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d84:
	/* 0x1d84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d89:
	/* 0x1d89: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1d90:
	/* 0x1d90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d92:
	/* 0x1d92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d95:
	/* 0x1d95: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1d9b:
	/* 0x1d9b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1d9e:
	/* 0x1d9e: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1da1:
	/* 0x1da1: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1da4:
	/* 0x1da4: je     19dc <generic_kprobe_process_filter+0x19dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6620ULL;
	}
x86_l_1daa:
	/* 0x1daa: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1dae:
	/* 0x1dae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1db3:
	/* 0x1db3: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1dba:
	/* 0x1dba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbc:
	/* 0x1dbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dbf:
	/* 0x1dbf: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dc4:
	/* 0x1dc4: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1dc6:
	/* 0x1dc6: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1dc9:
	/* 0x1dc9: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1dcc:
	/* 0x1dcc: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1dcf:
	/* 0x1dcf: je     19dc <generic_kprobe_process_filter+0x19dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6620ULL;
	}
x86_l_1dd5:
	/* 0x1dd5: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1dd9:
	/* 0x1dd9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dde:
	/* 0x1dde: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1de5:
	/* 0x1de5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de7:
	/* 0x1de7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dea:
	/* 0x1dea: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1def:
	/* 0x1def: je     1e40 <generic_kprobe_process_filter+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1df1:
	/* 0x1df1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1df4:
	/* 0x1df4: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1df7:
	/* 0x1df7: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1dfa:
	/* 0x1dfa: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dff:
	/* 0x1dff: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e03:
	/* 0x1e03: mov    r8,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e08:
	/* 0x1e08: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e12:
	/* 0x1e12: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e17:
	/* 0x1e17: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e1c:
	/* 0x1e1c: je     1a03 <generic_kprobe_process_filter+0x1a03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6659ULL;
	}
x86_l_1e22:
	/* 0x1e22: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e26:
	/* 0x1e26: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e2b:
	/* 0x1e2b: mov    rcx,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1e32:
	/* 0x1e32: mov    rdi,QWORD PTR [rip+0x36d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1e39:
	/* 0x1e39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3b:
	/* 0x1e3b: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e40:
	/* 0x1e40: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e43:
	/* 0x1e43: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e47:
	/* 0x1e47: cmp    edi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1e4a:
	/* 0x1e4a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e4f:
	/* 0x1e4f: mov    r8,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e54:
	/* 0x1e54: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e59:
	/* 0x1e59: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e5e:
	/* 0x1e5e: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e63:
	/* 0x1e63: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e68:
	/* 0x1e68: jne    1a03 <generic_kprobe_process_filter+0x1a03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6659ULL;
	}
x86_l_1e6e:
	/* 0x1e6e: jmp    1a10 <generic_kprobe_process_filter+0x1a10> */
	return 6672ULL;
x86_l_1e73:
	/* 0x1e73: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e76:
	/* 0x1e76: jmp    1a10 <generic_kprobe_process_filter+0x1a10> */
	return 6672ULL;
x86_l_1e7b:
	/* 0x1e7b: mov    esi,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e7f:
	/* 0x1e7f: mov    ecx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1e83:
	/* 0x1e83: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1e87:
	/* 0x1e87: mov    edx,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1e8b:
	/* 0x1e8b: cmp    edi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_1e8e:
	/* 0x1e8e: jne    1e98 <generic_kprobe_process_filter+0x1e98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e98;
	}
x86_l_1e90:
	/* 0x1e90: and    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1e92:
	/* 0x1e92: and    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_AND);
x86_l_1e94:
	/* 0x1e94: and    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_AND);
x86_l_1e96:
	/* 0x1e96: jmp    1e9e <generic_kprobe_process_filter+0x1e9e> */
	goto x86_l_1e9e;
x86_l_1e98:
	/* 0x1e98: or     ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e9a:
	/* 0x1e9a: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e9c:
	/* 0x1e9c: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e9e:
	/* 0x1e9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ea0:
	/* 0x1ea0: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_1ea6:
	/* 0x1ea6: add    r12d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    ecx,DWORD PTR [r9+rbp*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 8ULL);
x86_l_1eaf:
	/* 0x1eaf: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1eb2:
	/* 0x1eb2: lea    ebp,[r12+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_1eb6:
	/* 0x1eb6: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1eb8:
	/* 0x1eb8: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1ebe:
	/* 0x1ebe: mov    ebx,DWORD PTR [rcx+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1ec2:
	/* 0x1ec2: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1ec5:
	/* 0x1ec5: add    ebx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 4294967292ULL);
x86_l_1ec8:
	/* 0x1ec8: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_1ece:
	/* 0x1ece: jmp    1edb <generic_kprobe_process_filter+0x1edb> */
	goto x86_l_1edb;
x86_l_1ed0:
	/* 0x1ed0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ed2:
	/* 0x1ed2: dec    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1ed5:
	/* 0x1ed5: je     20d0 <generic_kprobe_process_filter+0x20d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20d0;
	}
x86_l_1edb:
	/* 0x1edb: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_1edd:
	/* 0x1edd: je     1ed0 <generic_kprobe_process_filter+0x1ed0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ed0;
	}
x86_l_1edf:
	/* 0x1edf: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1ee1:
	/* 0x1ee1: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1ee6:
	/* 0x1ee6: mov    ecx,DWORD PTR [rax+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1eea:
	/* 0x1eea: mov    r15d,DWORD PTR [rax+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_1eef:
	/* 0x1eef: mov    r13d,DWORD PTR [rax+r9*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 8ULL);
x86_l_1ef4:
	/* 0x1ef4: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1efd:
	/* 0x1efd: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1f06:
	/* 0x1f06: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1f0a:
	/* 0x1f0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f0f:
	/* 0x1f0f: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1f13:
	/* 0x1f13: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_1f17:
	/* 0x1f17: jne    1f2d <generic_kprobe_process_filter+0x1f2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f2d;
	}
x86_l_1f19:
	/* 0x1f19: movabs rdx,0x100000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 4294967297ULL);
x86_l_1f23:
	/* 0x1f23: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f28:
	/* 0x1f28: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f2d:
	/* 0x1f2d: lea    r12d,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f31:
	/* 0x1f31: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1f34:
	/* 0x1f34: je     2087 <generic_kprobe_process_filter+0x2087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2087;
	}
x86_l_1f3a:
	/* 0x1f3a: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1f3d:
	/* 0x1f3d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1f40:
	/* 0x1f40: jb     1f72 <generic_kprobe_process_filter+0x1f72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f72;
	}
x86_l_1f42:
	/* 0x1f42: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1f45:
	/* 0x1f45: cmp    rax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 3ULL);
x86_l_1f49:
	/* 0x1f49: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1f4e:
	/* 0x1f4e: cmovae rax,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_64, X86_CC_AE);
x86_l_1f52:
	/* 0x1f52: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f54:
	/* 0x1f54: lea    rdx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_1f5c:
	/* 0x1f5c: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f61:
	/* 0x1f61: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f63:
	/* 0x1f63: call   5648 <cwd_read_v61+0x30a5> */
	X86_SIM_L_EXEC_CALL_MEMSET_REG(1024ULL);
x86_l_1f68:
	/* 0x1f68: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f6d:
	/* 0x1f6d: jmp    2087 <generic_kprobe_process_filter+0x2087> */
	goto x86_l_2087;
x86_l_1f72:
	/* 0x1f72: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f74:
	/* 0x1f74: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1f7b:
	/* 0x1f7b: ja     1f87 <generic_kprobe_process_filter+0x1f87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f87;
	}
x86_l_1f7d:
	/* 0x1f7d: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_1f80:
	/* 0x1f80: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1f83:
	/* 0x1f83: mov    esi,DWORD PTR [r9+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1f87:
	/* 0x1f87: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f8c:
	/* 0x1f8c: mov    edx,DWORD PTR [rdx+rcx*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 32ULL);
x86_l_1f90:
	/* 0x1f90: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1f93:
	/* 0x1f93: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_1f97:
	/* 0x1f97: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1f9b:
	/* 0x1f9b: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_1f9e:
	/* 0x1f9e: xor    ecx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1fa1:
	/* 0x1fa1: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_1fa4:
	/* 0x1fa4: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fa7:
	/* 0x1fa7: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1fa9:
	/* 0x1fa9: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_1fad:
	/* 0x1fad: or     sil,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1fb0:
	/* 0x1fb0: or     r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fb3:
	/* 0x1fb3: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1fb7:
	/* 0x1fb7: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1fba:
	/* 0x1fba: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fbe:
	/* 0x1fbe: mov    DWORD PTR [rsp+0x70],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1fc2:
	/* 0x1fc2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fc5:
	/* 0x1fc5: je     2087 <generic_kprobe_process_filter+0x2087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2087;
	}
x86_l_1fcb:
	/* 0x1fcb: lea    edi,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fce:
	/* 0x1fce: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fd0:
	/* 0x1fd0: cmp    edi,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 1000ULL);
x86_l_1fd6:
	/* 0x1fd6: ja     1fdf <generic_kprobe_process_filter+0x1fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fdf;
	}
x86_l_1fd8:
	/* 0x1fd8: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1fdb:
	/* 0x1fdb: mov    esi,DWORD PTR [r9+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1fdf:
	/* 0x1fdf: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_1fe3:
	/* 0x1fe3: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1fe7:
	/* 0x1fe7: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_1fea:
	/* 0x1fea: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fed:
	/* 0x1fed: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1fef:
	/* 0x1fef: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_1ff3:
	/* 0x1ff3: or     sil,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ff6:
	/* 0x1ff6: or     r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1ff9:
	/* 0x1ff9: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1ffd:
	/* 0x1ffd: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_2000:
	/* 0x2000: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2004:
	/* 0x2004: mov    DWORD PTR [rsp+0x74],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_2008:
	/* 0x2008: cmp    rax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1ULL);
x86_l_200c:
	/* 0x200c: je     2087 <generic_kprobe_process_filter+0x2087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2087;
	}
x86_l_200e:
	/* 0x200e: lea    edi,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2011:
	/* 0x2011: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2013:
	/* 0x2013: cmp    edi,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 1000ULL);
x86_l_2019:
	/* 0x2019: ja     2022 <generic_kprobe_process_filter+0x2022> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2022;
	}
x86_l_201b:
	/* 0x201b: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_201e:
	/* 0x201e: mov    esi,DWORD PTR [r9+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2022:
	/* 0x2022: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_2026:
	/* 0x2026: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_202a:
	/* 0x202a: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_202d:
	/* 0x202d: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2030:
	/* 0x2030: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2032:
	/* 0x2032: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_2036:
	/* 0x2036: or     sil,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2039:
	/* 0x2039: or     r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_203c:
	/* 0x203c: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_2040:
	/* 0x2040: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_2043:
	/* 0x2043: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2047:
	/* 0x2047: mov    DWORD PTR [rsp+0x78],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_204b:
	/* 0x204b: cmp    rax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2ULL);
x86_l_204f:
	/* 0x204f: je     2087 <generic_kprobe_process_filter+0x2087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2087;
	}
x86_l_2051:
	/* 0x2051: add    ebp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2054:
	/* 0x2054: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2056:
	/* 0x2056: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_205c:
	/* 0x205c: ja     2065 <generic_kprobe_process_filter+0x2065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2065;
	}
x86_l_205e:
	/* 0x205e: and    ebp,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_2061:
	/* 0x2061: mov    eax,DWORD PTR [r9+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2065:
	/* 0x2065: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_2069:
	/* 0x2069: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_206d:
	/* 0x206d: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_206f:
	/* 0x206f: xor    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2071:
	/* 0x2071: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2073:
	/* 0x2073: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2076:
	/* 0x2076: or     al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2079:
	/* 0x2079: or     ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_207b:
	/* 0x207b: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_207e:
	/* 0x207e: and    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2080:
	/* 0x2080: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2083:
	/* 0x2083: mov    DWORD PTR [rsp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2087:
	/* 0x2087: mov    esi,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_208b:
	/* 0x208b: mov    ecx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_208f:
	/* 0x208f: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2093:
	/* 0x2093: mov    edx,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2097:
	/* 0x2097: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_209b:
	/* 0x209b: jne    20a5 <generic_kprobe_process_filter+0x20a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20a5;
	}
x86_l_209d:
	/* 0x209d: and    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_AND);
x86_l_209f:
	/* 0x209f: and    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_AND);
x86_l_20a1:
	/* 0x20a1: and    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_AND);
x86_l_20a3:
	/* 0x20a3: jmp    20ab <generic_kprobe_process_filter+0x20ab> */
	goto x86_l_20ab;
x86_l_20a5:
	/* 0x20a5: or     ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_20a7:
	/* 0x20a7: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_20a9:
	/* 0x20a9: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_20ab:
	/* 0x20ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ad:
	/* 0x20ad: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_20b3:
	/* 0x20b3: shl    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_20b7:
	/* 0x20b7: sub    ebx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_20ba:
	/* 0x20ba: and    r13d,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_20be:
	/* 0x20be: add    r13d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20c1:
	/* 0x20c1: add    ebx,0xfffffff4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 4294967284ULL);
x86_l_20c4:
	/* 0x20c4: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_20c7:
	/* 0x20c7: dec    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_20ca:
	/* 0x20ca: jne    1edb <generic_kprobe_process_filter+0x1edb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1edb;
	}
x86_l_20d0:
	/* 0x20d0: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_20d2:
	/* 0x20d2: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_20d8:
	/* 0x20d8: lea    ebx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20db:
	/* 0x20db: cmp    DWORD PTR [rcx+r9*1],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_20e0:
	/* 0x20e0: je     213f <generic_kprobe_process_filter+0x213f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_213f;
	}
x86_l_20e2:
	/* 0x20e2: and    ebx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_20e8:
	/* 0x20e8: mov    ecx,DWORD PTR [rbx+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_20ec:
	/* 0x20ec: mov    edx,DWORD PTR [rbx+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_20f1:
	/* 0x20f1: mov    edi,DWORD PTR [rbx+r9*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 8ULL);
x86_l_20f6:
	/* 0x20f6: mov    rax,QWORD PTR [rbx+r9*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 12ULL);
x86_l_20fb:
	/* 0x20fb: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_20fd:
	/* 0x20fd: mov    r8,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2102:
	/* 0x2102: je     2113 <generic_kprobe_process_filter+0x2113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2113;
	}
x86_l_2104:
	/* 0x2104: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2106:
	/* 0x2106: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2109:
	/* 0x2109: ja     2136 <generic_kprobe_process_filter+0x2136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2136;
	}
x86_l_210b:
	/* 0x210b: cmp    DWORD PTR [r8+0x44],edi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_210f:
	/* 0x210f: jne    211c <generic_kprobe_process_filter+0x211c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_211c;
	}
x86_l_2111:
	/* 0x2111: jmp    2136 <generic_kprobe_process_filter+0x2136> */
	goto x86_l_2136;
x86_l_2113:
	/* 0x2113: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2116:
	/* 0x2116: jbe    211c <generic_kprobe_process_filter+0x211c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_211c;
	}
x86_l_2118:
	/* 0x2118: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_211a:
	/* 0x211a: jmp    2136 <generic_kprobe_process_filter+0x2136> */
	goto x86_l_2136;
x86_l_211c:
	/* 0x211c: and    rax,QWORD PTR [r8+rcx*8+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R8, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 72ULL);
x86_l_2121:
	/* 0x2121: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2124:
	/* 0x2124: jne    212f <generic_kprobe_process_filter+0x212f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_212f;
	}
x86_l_2126:
	/* 0x2126: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2129:
	/* 0x2129: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_212d:
	/* 0x212d: jmp    2136 <generic_kprobe_process_filter+0x2136> */
	goto x86_l_2136;
x86_l_212f:
	/* 0x212f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2132:
	/* 0x2132: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_2136:
	/* 0x2136: add    ebp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2139:
	/* 0x2139: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_213d:
	/* 0x213d: mov    ebx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_213f:
	/* 0x213f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2141:
	/* 0x2141: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9498ULL;
	}
x86_l_2147:
	/* 0x2147: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_2149:
	/* 0x2149: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_214f:
	/* 0x214f: lea    eax,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2152:
	/* 0x2152: cmp    DWORD PTR [rcx+r9*1],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_2157:
	/* 0x2157: je     241e <generic_kprobe_process_filter+0x241e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9246ULL;
	}
x86_l_215d:
	/* 0x215d: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2162:
	/* 0x2162: mov    r14d,DWORD PTR [rax+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_2166:
	/* 0x2166: mov    ebp,DWORD PTR [rax+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_216b:
	/* 0x216b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2170:
	/* 0x2170: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 8562ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8570ULL: goto x86_l_217a;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8587ULL: goto x86_l_218b;
	case 8589ULL: goto x86_l_218d;
	case 8594ULL: goto x86_l_2192;
	case 8597ULL: goto x86_l_2195;
	case 8603ULL: goto x86_l_219b;
	case 8607ULL: goto x86_l_219f;
	case 8609ULL: goto x86_l_21a1;
	case 8613ULL: goto x86_l_21a5;
	case 8619ULL: goto x86_l_21ab;
	case 8624ULL: goto x86_l_21b0;
	case 8627ULL: goto x86_l_21b3;
	case 8634ULL: goto x86_l_21ba;
	case 8638ULL: goto x86_l_21be;
	case 8640ULL: goto x86_l_21c0;
	case 8643ULL: goto x86_l_21c3;
	case 8645ULL: goto x86_l_21c5;
	case 8647ULL: goto x86_l_21c7;
	case 8650ULL: goto x86_l_21ca;
	case 8652ULL: goto x86_l_21cc;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8665ULL: goto x86_l_21d9;
	case 8672ULL: goto x86_l_21e0;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8681ULL: goto x86_l_21e9;
	case 8683ULL: goto x86_l_21eb;
	case 8685ULL: goto x86_l_21ed;
	case 8688ULL: goto x86_l_21f0;
	case 8690ULL: goto x86_l_21f2;
	case 8695ULL: goto x86_l_21f7;
	case 8702ULL: goto x86_l_21fe;
	case 8706ULL: goto x86_l_2202;
	case 8708ULL: goto x86_l_2204;
	case 8711ULL: goto x86_l_2207;
	case 8713ULL: goto x86_l_2209;
	case 8715ULL: goto x86_l_220b;
	case 8718ULL: goto x86_l_220e;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8732ULL: goto x86_l_221c;
	case 8736ULL: goto x86_l_2220;
	case 8738ULL: goto x86_l_2222;
	case 8741ULL: goto x86_l_2225;
	case 8743ULL: goto x86_l_2227;
	case 8745ULL: goto x86_l_2229;
	case 8748ULL: goto x86_l_222c;
	case 8750ULL: goto x86_l_222e;
	case 8755ULL: goto x86_l_2233;
	case 8762ULL: goto x86_l_223a;
	case 8766ULL: goto x86_l_223e;
	case 8768ULL: goto x86_l_2240;
	case 8771ULL: goto x86_l_2243;
	case 8773ULL: goto x86_l_2245;
	case 8775ULL: goto x86_l_2247;
	case 8778ULL: goto x86_l_224a;
	case 8780ULL: goto x86_l_224c;
	case 8785ULL: goto x86_l_2251;
	case 8792ULL: goto x86_l_2258;
	case 8796ULL: goto x86_l_225c;
	case 8798ULL: goto x86_l_225e;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8805ULL: goto x86_l_2265;
	case 8808ULL: goto x86_l_2268;
	case 8810ULL: goto x86_l_226a;
	case 8815ULL: goto x86_l_226f;
	case 8822ULL: goto x86_l_2276;
	case 8826ULL: goto x86_l_227a;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8833ULL: goto x86_l_2281;
	case 8835ULL: goto x86_l_2283;
	case 8838ULL: goto x86_l_2286;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8852ULL: goto x86_l_2294;
	case 8856ULL: goto x86_l_2298;
	case 8858ULL: goto x86_l_229a;
	case 8861ULL: goto x86_l_229d;
	case 8863ULL: goto x86_l_229f;
	case 8865ULL: goto x86_l_22a1;
	case 8868ULL: goto x86_l_22a4;
	case 8870ULL: goto x86_l_22a6;
	case 8875ULL: goto x86_l_22ab;
	case 8882ULL: goto x86_l_22b2;
	case 8886ULL: goto x86_l_22b6;
	case 8888ULL: goto x86_l_22b8;
	case 8891ULL: goto x86_l_22bb;
	case 8893ULL: goto x86_l_22bd;
	case 8895ULL: goto x86_l_22bf;
	case 8898ULL: goto x86_l_22c2;
	case 8900ULL: goto x86_l_22c4;
	case 8905ULL: goto x86_l_22c9;
	case 8912ULL: goto x86_l_22d0;
	case 8916ULL: goto x86_l_22d4;
	case 8918ULL: goto x86_l_22d6;
	case 8921ULL: goto x86_l_22d9;
	case 8923ULL: goto x86_l_22db;
	case 8925ULL: goto x86_l_22dd;
	case 8928ULL: goto x86_l_22e0;
	case 8930ULL: goto x86_l_22e2;
	case 8935ULL: goto x86_l_22e7;
	case 8942ULL: goto x86_l_22ee;
	case 8946ULL: goto x86_l_22f2;
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8953ULL: goto x86_l_22f9;
	case 8955ULL: goto x86_l_22fb;
	case 8958ULL: goto x86_l_22fe;
	case 8960ULL: goto x86_l_2300;
	case 8965ULL: goto x86_l_2305;
	case 8972ULL: goto x86_l_230c;
	case 8976ULL: goto x86_l_2310;
	case 8978ULL: goto x86_l_2312;
	case 8981ULL: goto x86_l_2315;
	case 8983ULL: goto x86_l_2317;
	case 8985ULL: goto x86_l_2319;
	case 8988ULL: goto x86_l_231c;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 9002ULL: goto x86_l_232a;
	case 9006ULL: goto x86_l_232e;
	case 9008ULL: goto x86_l_2330;
	case 9011ULL: goto x86_l_2333;
	case 9013ULL: goto x86_l_2335;
	case 9015ULL: goto x86_l_2337;
	case 9018ULL: goto x86_l_233a;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9032ULL: goto x86_l_2348;
	case 9036ULL: goto x86_l_234c;
	case 9038ULL: goto x86_l_234e;
	case 9041ULL: goto x86_l_2351;
	case 9043ULL: goto x86_l_2353;
	case 9045ULL: goto x86_l_2355;
	case 9048ULL: goto x86_l_2358;
	case 9050ULL: goto x86_l_235a;
	case 9055ULL: goto x86_l_235f;
	case 9062ULL: goto x86_l_2366;
	case 9065ULL: goto x86_l_2369;
	case 9067ULL: goto x86_l_236b;
	case 9070ULL: goto x86_l_236e;
	case 9072ULL: goto x86_l_2370;
	case 9074ULL: goto x86_l_2372;
	case 9077ULL: goto x86_l_2375;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9091ULL: goto x86_l_2383;
	case 9094ULL: goto x86_l_2386;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9101ULL: goto x86_l_238d;
	case 9103ULL: goto x86_l_238f;
	case 9106ULL: goto x86_l_2392;
	case 9108ULL: goto x86_l_2394;
	case 9110ULL: goto x86_l_2396;
	case 9117ULL: goto x86_l_239d;
	case 9123ULL: goto x86_l_23a3;
	case 9125ULL: goto x86_l_23a5;
	case 9128ULL: goto x86_l_23a8;
	case 9130ULL: goto x86_l_23aa;
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9140ULL: goto x86_l_23b4;
	case 9142ULL: goto x86_l_23b6;
	case 9144ULL: goto x86_l_23b8;
	case 9151ULL: goto x86_l_23bf;
	case 9157ULL: goto x86_l_23c5;
	case 9163ULL: goto x86_l_23cb;
	case 9166ULL: goto x86_l_23ce;
	case 9168ULL: goto x86_l_23d0;
	case 9174ULL: goto x86_l_23d6;
	case 9179ULL: goto x86_l_23db;
	case 9182ULL: goto x86_l_23de;
	case 9188ULL: goto x86_l_23e4;
	case 9190ULL: goto x86_l_23e6;
	case 9197ULL: goto x86_l_23ed;
	case 9203ULL: goto x86_l_23f3;
	case 9209ULL: goto x86_l_23f9;
	case 9212ULL: goto x86_l_23fc;
	case 9214ULL: goto x86_l_23fe;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9228ULL: goto x86_l_240c;
	case 9234ULL: goto x86_l_2412;
	case 9237ULL: goto x86_l_2415;
	case 9244ULL: goto x86_l_241c;
	case 9246ULL: goto x86_l_241e;
	case 9248ULL: goto x86_l_2420;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9266ULL: goto x86_l_2432;
	case 9273ULL: goto x86_l_2439;
	case 9276ULL: goto x86_l_243c;
	case 9284ULL: goto x86_l_2444;
	case 9291ULL: goto x86_l_244b;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9306ULL: goto x86_l_245a;
	case 9311ULL: goto x86_l_245f;
	case 9315ULL: goto x86_l_2463;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9335ULL: goto x86_l_2477;
	case 9337ULL: goto x86_l_2479;
	case 9341ULL: goto x86_l_247d;
	case 9345ULL: goto x86_l_2481;
	case 9352ULL: goto x86_l_2488;
	case 9357ULL: goto x86_l_248d;
	case 9362ULL: goto x86_l_2492;
	case 9364ULL: goto x86_l_2494;
	case 9367ULL: goto x86_l_2497;
	case 9373ULL: goto x86_l_249d;
	case 9375ULL: goto x86_l_249f;
	case 9377ULL: goto x86_l_24a1;
	case 9381ULL: goto x86_l_24a5;
	case 9383ULL: goto x86_l_24a7;
	case 9388ULL: goto x86_l_24ac;
	case 9391ULL: goto x86_l_24af;
	case 9393ULL: goto x86_l_24b1;
	case 9395ULL: goto x86_l_24b3;
	case 9399ULL: goto x86_l_24b7;
	case 9401ULL: goto x86_l_24b9;
	case 9406ULL: goto x86_l_24be;
	case 9411ULL: goto x86_l_24c3;
	case 9416ULL: goto x86_l_24c8;
	case 9419ULL: goto x86_l_24cb;
	case 9422ULL: goto x86_l_24ce;
	case 9425ULL: goto x86_l_24d1;
	case 9427ULL: goto x86_l_24d3;
	case 9430ULL: goto x86_l_24d6;
	case 9432ULL: goto x86_l_24d8;
	case 9434ULL: goto x86_l_24da;
	case 9437ULL: goto x86_l_24dd;
	case 9439ULL: goto x86_l_24df;
	case 9442ULL: goto x86_l_24e2;
	case 9444ULL: goto x86_l_24e4;
	case 9449ULL: goto x86_l_24e9;
	case 9460ULL: goto x86_l_24f4;
	case 9465ULL: goto x86_l_24f9;
	case 9472ULL: goto x86_l_2500;
	case 9478ULL: goto x86_l_2506;
	case 9480ULL: goto x86_l_2508;
	case 9483ULL: goto x86_l_250b;
	case 9485ULL: goto x86_l_250d;
	case 9491ULL: goto x86_l_2513;
	case 9498ULL: goto x86_l_251a;
	case 9503ULL: goto x86_l_251f;
	case 9510ULL: goto x86_l_2526;
	case 9513ULL: goto x86_l_2529;
	case 9520ULL: goto x86_l_2530;
	case 9528ULL: goto x86_l_2538;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9537ULL: goto x86_l_2541;
	case 9540ULL: goto x86_l_2544;
	case 9544ULL: goto x86_l_2548;
	case 9548ULL: goto x86_l_254c;
	case 9555ULL: goto x86_l_2553;
	case 9563ULL: goto x86_l_255b;
	case 9565ULL: goto x86_l_255d;
	case 9572ULL: goto x86_l_2564;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9582ULL: goto x86_l_256e;
	case 9584ULL: goto x86_l_2570;
	case 9586ULL: goto x86_l_2572;
	case 9588ULL: goto x86_l_2574;
	case 9595ULL: goto x86_l_257b;
	case 9597ULL: goto x86_l_257d;
	case 9598ULL: goto x86_l_257e;
	case 9603ULL: goto x86_l_2583;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9635ULL: goto x86_l_25a3;
	case 9636ULL: goto x86_l_25a4;
	case 9638ULL: goto x86_l_25a6;
	case 9640ULL: goto x86_l_25a8;
	case 9642ULL: goto x86_l_25aa;
	case 9644ULL: goto x86_l_25ac;
	case 9645ULL: goto x86_l_25ad;
	case 9649ULL: goto x86_l_25b1;
	case 9652ULL: goto x86_l_25b4;
	case 9656ULL: goto x86_l_25b8;
	case 9660ULL: goto x86_l_25bc;
	case 9664ULL: goto x86_l_25c0;
	case 9667ULL: goto x86_l_25c3;
	case 9669ULL: goto x86_l_25c5;
	case 9673ULL: goto x86_l_25c9;
	case 9679ULL: goto x86_l_25cf;
	case 9683ULL: goto x86_l_25d3;
	case 9688ULL: goto x86_l_25d8;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9703ULL: goto x86_l_25e7;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9716ULL: goto x86_l_25f4;
	case 9721ULL: goto x86_l_25f9;
	case 9726ULL: goto x86_l_25fe;
	case 9731ULL: goto x86_l_2603;
	case 9736ULL: goto x86_l_2608;
	case 9741ULL: goto x86_l_260d;
	case 9744ULL: goto x86_l_2610;
	case 9746ULL: goto x86_l_2612;
	case 9751ULL: goto x86_l_2617;
	case 9757ULL: goto x86_l_261d;
	case 9762ULL: goto x86_l_2622;
	case 9767ULL: goto x86_l_2627;
	case 9772ULL: goto x86_l_262c;
	case 9777ULL: goto x86_l_2631;
	case 9780ULL: goto x86_l_2634;
	case 9782ULL: goto x86_l_2636;
	case 9786ULL: goto x86_l_263a;
	case 9791ULL: goto x86_l_263f;
	case 9796ULL: goto x86_l_2644;
	case 9801ULL: goto x86_l_2649;
	case 9806ULL: goto x86_l_264e;
	case 9809ULL: goto x86_l_2651;
	case 9811ULL: goto x86_l_2653;
	case 9815ULL: goto x86_l_2657;
	case 9819ULL: goto x86_l_265b;
	case 9823ULL: goto x86_l_265f;
	case 9826ULL: goto x86_l_2662;
	case 9830ULL: goto x86_l_2666;
	case 9832ULL: goto x86_l_2668;
	case 9834ULL: goto x86_l_266a;
	case 9837ULL: goto x86_l_266d;
	case 9840ULL: goto x86_l_2670;
	case 9845ULL: goto x86_l_2675;
	case 9847ULL: goto x86_l_2677;
	case 9850ULL: goto x86_l_267a;
	case 9854ULL: goto x86_l_267e;
	case 9856ULL: goto x86_l_2680;
	case 9860ULL: goto x86_l_2684;
	case 9862ULL: goto x86_l_2686;
	case 9865ULL: goto x86_l_2689;
	case 9867ULL: goto x86_l_268b;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9878ULL: goto x86_l_2696;
	case 9884ULL: goto x86_l_269c;
	case 9891ULL: goto x86_l_26a3;
	case 9897ULL: goto x86_l_26a9;
	case 9900ULL: goto x86_l_26ac;
	case 9902ULL: goto x86_l_26ae;
	case 9907ULL: goto x86_l_26b3;
	case 9909ULL: goto x86_l_26b5;
	case 9912ULL: goto x86_l_26b8;
	case 9916ULL: goto x86_l_26bc;
	case 9920ULL: goto x86_l_26c0;
	case 9923ULL: goto x86_l_26c3;
	case 9926ULL: goto x86_l_26c6;
	case 9931ULL: goto x86_l_26cb;
	case 9933ULL: goto x86_l_26cd;
	case 9937ULL: goto x86_l_26d1;
	case 9940ULL: goto x86_l_26d4;
	case 9945ULL: goto x86_l_26d9;
	case 9947ULL: goto x86_l_26db;
	case 9952ULL: goto x86_l_26e0;
	case 9955ULL: goto x86_l_26e3;
	case 9957ULL: goto x86_l_26e5;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9971ULL: goto x86_l_26f3;
	case 9976ULL: goto x86_l_26f8;
	case 9981ULL: goto x86_l_26fd;
	case 9983ULL: goto x86_l_26ff;
	case 9987ULL: goto x86_l_2703;
	case 9992ULL: goto x86_l_2708;
	case 9994ULL: goto x86_l_270a;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2172:
	/* 0x2172: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2176:
	/* 0x2176: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_217a:
	/* 0x217a: mov    rdi,QWORD PTR [rip+0x36e9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2181:
	/* 0x2181: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2186:
	/* 0x2186: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_218b:
	/* 0x218b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218d:
	/* 0x218d: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2192:
	/* 0x2192: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2195:
	/* 0x2195: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251a;
	}
x86_l_219b:
	/* 0x219b: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_219f:
	/* 0x219f: je     21d1 <generic_kprobe_process_filter+0x21d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21d1;
	}
x86_l_21a1:
	/* 0x21a1: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_21a5:
	/* 0x21a5: jne    251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_251a;
	}
x86_l_21ab:
	/* 0x21ab: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21b0:
	/* 0x21b0: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_21b3:
	/* 0x21b3: add    rcx,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_21ba:
	/* 0x21ba: test   bpl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_21be:
	/* 0x21be: jne    21fe <generic_kprobe_process_filter+0x21fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21fe;
	}
x86_l_21c0:
	/* 0x21c0: mov    edx,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21c3:
	/* 0x21c3: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_21c5:
	/* 0x21c5: je     21f7 <generic_kprobe_process_filter+0x21f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f7;
	}
x86_l_21c7:
	/* 0x21c7: cmp    edx,DWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_21ca:
	/* 0x21ca: je     21fe <generic_kprobe_process_filter+0x21fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21fe;
	}
x86_l_21cc:
	/* 0x21cc: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_21d1:
	/* 0x21d1: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21d6:
	/* 0x21d6: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_21d9:
	/* 0x21d9: add    rcx,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_21e0:
	/* 0x21e0: test   bpl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_21e4:
	/* 0x21e4: je     221c <generic_kprobe_process_filter+0x221c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_221c;
	}
x86_l_21e6:
	/* 0x21e6: mov    edx,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21e9:
	/* 0x21e9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_21eb:
	/* 0x21eb: je     2215 <generic_kprobe_process_filter+0x2215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2215;
	}
x86_l_21ed:
	/* 0x21ed: cmp    edx,DWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_21f0:
	/* 0x21f0: je     221c <generic_kprobe_process_filter+0x221c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_221c;
	}
x86_l_21f2:
	/* 0x21f2: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_21f7:
	/* 0x21f7: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_21fe:
	/* 0x21fe: test   bpl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 2ULL);
x86_l_2202:
	/* 0x2202: jne    223a <generic_kprobe_process_filter+0x223a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_223a;
	}
x86_l_2204:
	/* 0x2204: mov    edx,DWORD PTR [rax+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2207:
	/* 0x2207: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2209:
	/* 0x2209: je     2233 <generic_kprobe_process_filter+0x2233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2233;
	}
x86_l_220b:
	/* 0x220b: cmp    edx,DWORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_220e:
	/* 0x220e: je     223a <generic_kprobe_process_filter+0x223a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223a;
	}
x86_l_2210:
	/* 0x2210: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_2215:
	/* 0x2215: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_221c:
	/* 0x221c: test   bpl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 2ULL);
x86_l_2220:
	/* 0x2220: je     2258 <generic_kprobe_process_filter+0x2258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2258;
	}
x86_l_2222:
	/* 0x2222: mov    edx,DWORD PTR [rax+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2225:
	/* 0x2225: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2227:
	/* 0x2227: je     2251 <generic_kprobe_process_filter+0x2251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2251;
	}
x86_l_2229:
	/* 0x2229: cmp    edx,DWORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_222c:
	/* 0x222c: je     2258 <generic_kprobe_process_filter+0x2258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2258;
	}
x86_l_222e:
	/* 0x222e: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_2233:
	/* 0x2233: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_223a:
	/* 0x223a: test   bpl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 4ULL);
x86_l_223e:
	/* 0x223e: jne    2276 <generic_kprobe_process_filter+0x2276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2276;
	}
x86_l_2240:
	/* 0x2240: mov    edx,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2243:
	/* 0x2243: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2245:
	/* 0x2245: je     226f <generic_kprobe_process_filter+0x226f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_226f;
	}
x86_l_2247:
	/* 0x2247: cmp    edx,DWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 40ULL);
x86_l_224a:
	/* 0x224a: je     2276 <generic_kprobe_process_filter+0x2276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2276;
	}
x86_l_224c:
	/* 0x224c: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_2251:
	/* 0x2251: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2258:
	/* 0x2258: test   bpl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 4ULL);
x86_l_225c:
	/* 0x225c: je     2294 <generic_kprobe_process_filter+0x2294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2294;
	}
x86_l_225e:
	/* 0x225e: mov    edx,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2261:
	/* 0x2261: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2263:
	/* 0x2263: je     228d <generic_kprobe_process_filter+0x228d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228d;
	}
x86_l_2265:
	/* 0x2265: cmp    edx,DWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 40ULL);
x86_l_2268:
	/* 0x2268: je     2294 <generic_kprobe_process_filter+0x2294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2294;
	}
x86_l_226a:
	/* 0x226a: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_226f:
	/* 0x226f: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2276:
	/* 0x2276: test   bpl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 8ULL);
x86_l_227a:
	/* 0x227a: jne    22b2 <generic_kprobe_process_filter+0x22b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22b2;
	}
x86_l_227c:
	/* 0x227c: mov    edx,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_227f:
	/* 0x227f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2281:
	/* 0x2281: je     22ab <generic_kprobe_process_filter+0x22ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22ab;
	}
x86_l_2283:
	/* 0x2283: cmp    edx,DWORD PTR [rsi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_2286:
	/* 0x2286: je     22b2 <generic_kprobe_process_filter+0x22b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22b2;
	}
x86_l_2288:
	/* 0x2288: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_228d:
	/* 0x228d: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2294:
	/* 0x2294: test   bpl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 8ULL);
x86_l_2298:
	/* 0x2298: je     22d0 <generic_kprobe_process_filter+0x22d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22d0;
	}
x86_l_229a:
	/* 0x229a: mov    edx,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_229d:
	/* 0x229d: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_229f:
	/* 0x229f: je     22c9 <generic_kprobe_process_filter+0x22c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c9;
	}
x86_l_22a1:
	/* 0x22a1: cmp    edx,DWORD PTR [rsi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_22a4:
	/* 0x22a4: je     22d0 <generic_kprobe_process_filter+0x22d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22d0;
	}
x86_l_22a6:
	/* 0x22a6: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_22ab:
	/* 0x22ab: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_22b2:
	/* 0x22b2: test   bpl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 16ULL);
x86_l_22b6:
	/* 0x22b6: jne    22ee <generic_kprobe_process_filter+0x22ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22ee;
	}
x86_l_22b8:
	/* 0x22b8: mov    edx,DWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22bb:
	/* 0x22bb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_22bd:
	/* 0x22bd: je     22e7 <generic_kprobe_process_filter+0x22e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22e7;
	}
x86_l_22bf:
	/* 0x22bf: cmp    edx,DWORD PTR [rsi+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_22c2:
	/* 0x22c2: je     22ee <generic_kprobe_process_filter+0x22ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22ee;
	}
x86_l_22c4:
	/* 0x22c4: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_22c9:
	/* 0x22c9: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_22d0:
	/* 0x22d0: test   bpl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 16ULL);
x86_l_22d4:
	/* 0x22d4: je     230c <generic_kprobe_process_filter+0x230c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_230c;
	}
x86_l_22d6:
	/* 0x22d6: mov    edx,DWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22d9:
	/* 0x22d9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_22db:
	/* 0x22db: je     2305 <generic_kprobe_process_filter+0x2305> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2305;
	}
x86_l_22dd:
	/* 0x22dd: cmp    edx,DWORD PTR [rsi+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_22e0:
	/* 0x22e0: je     230c <generic_kprobe_process_filter+0x230c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_230c;
	}
x86_l_22e2:
	/* 0x22e2: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_22e7:
	/* 0x22e7: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_22ee:
	/* 0x22ee: test   bpl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 32ULL);
x86_l_22f2:
	/* 0x22f2: jne    232a <generic_kprobe_process_filter+0x232a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_232a;
	}
x86_l_22f4:
	/* 0x22f4: mov    edx,DWORD PTR [rax+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_22f7:
	/* 0x22f7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_22f9:
	/* 0x22f9: je     2323 <generic_kprobe_process_filter+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2323;
	}
x86_l_22fb:
	/* 0x22fb: cmp    edx,DWORD PTR [rsi+0x34] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 52ULL);
x86_l_22fe:
	/* 0x22fe: je     232a <generic_kprobe_process_filter+0x232a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_232a;
	}
x86_l_2300:
	/* 0x2300: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_2305:
	/* 0x2305: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_230c:
	/* 0x230c: test   bpl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 32ULL);
x86_l_2310:
	/* 0x2310: je     2348 <generic_kprobe_process_filter+0x2348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2348;
	}
x86_l_2312:
	/* 0x2312: mov    edx,DWORD PTR [rax+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2315:
	/* 0x2315: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2317:
	/* 0x2317: je     2341 <generic_kprobe_process_filter+0x2341> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2341;
	}
x86_l_2319:
	/* 0x2319: cmp    edx,DWORD PTR [rsi+0x34] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 52ULL);
x86_l_231c:
	/* 0x231c: je     2348 <generic_kprobe_process_filter+0x2348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2348;
	}
x86_l_231e:
	/* 0x231e: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_2323:
	/* 0x2323: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_232a:
	/* 0x232a: test   bpl,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 64ULL);
x86_l_232e:
	/* 0x232e: jne    2366 <generic_kprobe_process_filter+0x2366> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2366;
	}
x86_l_2330:
	/* 0x2330: mov    edx,DWORD PTR [rax+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2333:
	/* 0x2333: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2335:
	/* 0x2335: je     235f <generic_kprobe_process_filter+0x235f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235f;
	}
x86_l_2337:
	/* 0x2337: cmp    edx,DWORD PTR [rsi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 56ULL);
x86_l_233a:
	/* 0x233a: je     2366 <generic_kprobe_process_filter+0x2366> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2366;
	}
x86_l_233c:
	/* 0x233c: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_2341:
	/* 0x2341: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2348:
	/* 0x2348: test   bpl,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 64ULL);
x86_l_234c:
	/* 0x234c: je     2383 <generic_kprobe_process_filter+0x2383> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2383;
	}
x86_l_234e:
	/* 0x234e: mov    edx,DWORD PTR [rax+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2351:
	/* 0x2351: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2353:
	/* 0x2353: je     237c <generic_kprobe_process_filter+0x237c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237c;
	}
x86_l_2355:
	/* 0x2355: cmp    edx,DWORD PTR [rsi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 56ULL);
x86_l_2358:
	/* 0x2358: je     2383 <generic_kprobe_process_filter+0x2383> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2383;
	}
x86_l_235a:
	/* 0x235a: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_235f:
	/* 0x235f: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2366:
	/* 0x2366: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_2369:
	/* 0x2369: js     239d <generic_kprobe_process_filter+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_239d;
	}
x86_l_236b:
	/* 0x236b: mov    edx,DWORD PTR [rax+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_236e:
	/* 0x236e: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2370:
	/* 0x2370: je     2396 <generic_kprobe_process_filter+0x2396> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2396;
	}
x86_l_2372:
	/* 0x2372: cmp    edx,DWORD PTR [rsi+0x3c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2375:
	/* 0x2375: je     239d <generic_kprobe_process_filter+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_239d;
	}
x86_l_2377:
	/* 0x2377: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_237c:
	/* 0x237c: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2383:
	/* 0x2383: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_2386:
	/* 0x2386: jns    23bf <generic_kprobe_process_filter+0x23bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_23bf;
	}
x86_l_2388:
	/* 0x2388: mov    edx,DWORD PTR [rax+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_238b:
	/* 0x238b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_238d:
	/* 0x238d: je     23b8 <generic_kprobe_process_filter+0x23b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23b8;
	}
x86_l_238f:
	/* 0x238f: cmp    edx,DWORD PTR [rsi+0x3c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2392:
	/* 0x2392: je     23bf <generic_kprobe_process_filter+0x23bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23bf;
	}
x86_l_2394:
	/* 0x2394: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_2396:
	/* 0x2396: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_239d:
	/* 0x239d: test   ebp,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 256ULL);
x86_l_23a3:
	/* 0x23a3: jne    23ed <generic_kprobe_process_filter+0x23ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23ed;
	}
x86_l_23a5:
	/* 0x23a5: mov    edx,DWORD PTR [rax+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23a8:
	/* 0x23a8: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_23aa:
	/* 0x23aa: je     23e6 <generic_kprobe_process_filter+0x23e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23e6;
	}
x86_l_23ac:
	/* 0x23ac: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23b1:
	/* 0x23b1: cmp    edx,DWORD PTR [rsi+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 64ULL);
x86_l_23b4:
	/* 0x23b4: je     23ed <generic_kprobe_process_filter+0x23ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ed;
	}
x86_l_23b6:
	/* 0x23b6: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_23b8:
	/* 0x23b8: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_23bf:
	/* 0x23bf: test   ebp,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 256ULL);
x86_l_23c5:
	/* 0x23c5: je     2500 <generic_kprobe_process_filter+0x2500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2500;
	}
x86_l_23cb:
	/* 0x23cb: mov    edx,DWORD PTR [rax+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23ce:
	/* 0x23ce: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_23d0:
	/* 0x23d0: je     24f9 <generic_kprobe_process_filter+0x24f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f9;
	}
x86_l_23d6:
	/* 0x23d6: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23db:
	/* 0x23db: cmp    edx,DWORD PTR [rsi+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 64ULL);
x86_l_23de:
	/* 0x23de: je     2500 <generic_kprobe_process_filter+0x2500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2500;
	}
x86_l_23e4:
	/* 0x23e4: jmp    2412 <generic_kprobe_process_filter+0x2412> */
	goto x86_l_2412;
x86_l_23e6:
	/* 0x23e6: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_23ed:
	/* 0x23ed: test   ebp,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 512ULL);
x86_l_23f3:
	/* 0x23f3: jne    251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_251a;
	}
x86_l_23f9:
	/* 0x23f9: mov    eax,DWORD PTR [rax+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_23fc:
	/* 0x23fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23fe:
	/* 0x23fe: je     2513 <generic_kprobe_process_filter+0x2513> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2513;
	}
x86_l_2404:
	/* 0x2404: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2409:
	/* 0x2409: cmp    eax,DWORD PTR [rdx+0x44] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 68ULL);
x86_l_240c:
	/* 0x240c: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251a;
	}
x86_l_2412:
	/* 0x2412: add    ebx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_2415:
	/* 0x2415: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_241c:
	/* 0x241c: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_241e:
	/* 0x241e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2420:
	/* 0x2420: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2426:
	/* 0x2426: cmp    DWORD PTR [rcx+r9*1],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_242b:
	/* 0x242b: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2430:
	/* 0x2430: jne    2457 <generic_kprobe_process_filter+0x2457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2457;
	}
x86_l_2432:
	/* 0x2432: mov    rax,QWORD PTR [rcx+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_2439:
	/* 0x2439: and    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_243c:
	/* 0x243c: mov    BYTE PTR [rcx+rax*1+0x5ec1],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699073ULL);
x86_l_2444:
	/* 0x2444: mov    BYTE PTR [rcx+0x5ee0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685249ULL);
x86_l_244b:
	/* 0x244b: mov    BYTE PTR [rcx+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_2452:
	/* 0x2452: jmp    251a <generic_kprobe_process_filter+0x251a> */
	goto x86_l_251a;
x86_l_2457:
	/* 0x2457: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_245a:
	/* 0x245a: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_245f:
	/* 0x245f: mov    r14d,DWORD PTR [rax+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_2463:
	/* 0x2463: mov    ebx,DWORD PTR [rax+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_2468:
	/* 0x2468: mov    ebp,DWORD PTR [rax+r9*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 8ULL);
x86_l_246d:
	/* 0x246d: mov    r15,QWORD PTR [rax+r9*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 12ULL);
x86_l_2472:
	/* 0x2472: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2477:
	/* 0x2477: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2479:
	/* 0x2479: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_247d:
	/* 0x247d: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2481:
	/* 0x2481: mov    rdi,QWORD PTR [rip+0x36e9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2488:
	/* 0x2488: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_248d:
	/* 0x248d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2492:
	/* 0x2492: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2494:
	/* 0x2494: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2497:
	/* 0x2497: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251a;
	}
x86_l_249d:
	/* 0x249d: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_249f:
	/* 0x249f: je     24b3 <generic_kprobe_process_filter+0x24b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24b3;
	}
x86_l_24a1:
	/* 0x24a1: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_24a5:
	/* 0x24a5: ja     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_251a;
	}
x86_l_24a7:
	/* 0x24a7: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24ac:
	/* 0x24ac: cmp    DWORD PTR [rcx+0x44],ebp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_24af:
	/* 0x24af: jne    24b9 <generic_kprobe_process_filter+0x24b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24b9;
	}
x86_l_24b1:
	/* 0x24b1: jmp    251a <generic_kprobe_process_filter+0x251a> */
	goto x86_l_251a;
x86_l_24b3:
	/* 0x24b3: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_24b7:
	/* 0x24b7: ja     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_251a;
	}
x86_l_24b9:
	/* 0x24b9: mov    rax,QWORD PTR [rax+r14*8+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 80ULL);
x86_l_24be:
	/* 0x24be: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24c3:
	/* 0x24c3: mov    rcx,QWORD PTR [rcx+r14*8+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 72ULL);
x86_l_24c8:
	/* 0x24c8: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_24cb:
	/* 0x24cb: xor    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_24ce:
	/* 0x24ce: test   rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_24d1:
	/* 0x24d1: je     24da <generic_kprobe_process_filter+0x24da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24da;
	}
x86_l_24d3:
	/* 0x24d3: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_24d6:
	/* 0x24d6: jne    251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_251a;
	}
x86_l_24d8:
	/* 0x24d8: jmp    24e4 <generic_kprobe_process_filter+0x24e4> */
	goto x86_l_24e4;
x86_l_24da:
	/* 0x24da: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_24dd:
	/* 0x24dd: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251a;
	}
x86_l_24df:
	/* 0x24df: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_24e2:
	/* 0x24e2: jne    251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_251a;
	}
x86_l_24e4:
	/* 0x24e4: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24e9:
	/* 0x24e9: mov    QWORD PTR [rcx+0x5ef0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161985ULL);
x86_l_24f4:
	/* 0x24f4: jmp    2432 <generic_kprobe_process_filter+0x2432> */
	goto x86_l_2432;
x86_l_24f9:
	/* 0x24f9: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2500:
	/* 0x2500: test   ebp,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 512ULL);
x86_l_2506:
	/* 0x2506: je     251a <generic_kprobe_process_filter+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251a;
	}
x86_l_2508:
	/* 0x2508: mov    eax,DWORD PTR [rax+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_250b:
	/* 0x250b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_250d:
	/* 0x250d: jne    2404 <generic_kprobe_process_filter+0x2404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2404;
	}
x86_l_2513:
	/* 0x2513: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_251a:
	/* 0x251a: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_251f:
	/* 0x251f: mov    rax,QWORD PTR [rcx+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_2526:
	/* 0x2526: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2529:
	/* 0x2529: mov    QWORD PTR [rcx+0x5eb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_2530:
	/* 0x2530: cmp    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 208ULL);
x86_l_2538:
	/* 0x2538: jbe    2583 <generic_kprobe_process_filter+0x2583> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2583;
	}
x86_l_253a:
	/* 0x253a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_253f:
	/* 0x253f: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2541:
	/* 0x2541: mov    DWORD PTR [rcx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2544:
	/* 0x2544: mov    rax,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2548:
	/* 0x2548: mov    QWORD PTR [rcx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_254c:
	/* 0x254c: cmp    BYTE PTR [rcx+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_2553:
	/* 0x2553: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_255b:
	/* 0x255b: je     2572 <generic_kprobe_process_filter+0x2572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2572;
	}
x86_l_255d:
	/* 0x255d: mov    rsi,QWORD PTR [rip+0x36e5] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_2564:
	/* 0x2564: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2566:
	/* 0x2566: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_256b:
	/* 0x256b: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_256e:
	/* 0x256e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2570:
	/* 0x2570: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2572:
	/* 0x2572: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2574:
	/* 0x2574: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_257b:
	/* 0x257b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_257d:
	/* 0x257d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_257e:
	/* 0x257e: jmp    2752 <cwd_read_v61+0x1af> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2583:
	/* 0x2583: mov    rsi,QWORD PTR [rip+0x36e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_258a:
	/* 0x258a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_258f:
	/* 0x258f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2594:
	/* 0x2594: mov    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_259c:
	/* 0x259c: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_25a1:
	/* 0x25a1: jmp    2570 <generic_kprobe_process_filter+0x2570> */
	goto x86_l_2570;
x86_l_25a3:
	/* 0x25a3: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_25a4:
	/* 0x25a4: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_25a6:
	/* 0x25a6: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_25a8:
	/* 0x25a8: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_25aa:
	/* 0x25aa: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_25ac:
	/* 0x25ac: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_25ad:
	/* 0x25ad: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_25b1:
	/* 0x25b1: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_25b4:
	/* 0x25b4: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25b8:
	/* 0x25b8: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25bc:
	/* 0x25bc: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25c0:
	/* 0x25c0: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_25c3:
	/* 0x25c3: jne    25cf <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25cf;
	}
x86_l_25c5:
	/* 0x25c5: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_25c9:
	/* 0x25c9: je     273a <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10042ULL;
	}
x86_l_25cf:
	/* 0x25cf: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25d3:
	/* 0x25d3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25d8:
	/* 0x25d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25dd:
	/* 0x25dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25e2:
	/* 0x25e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25e7:
	/* 0x25e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e9:
	/* 0x25e9: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_25ee:
	/* 0x25ee: je     26e5 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26e5;
	}
x86_l_25f4:
	/* 0x25f4: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25f9:
	/* 0x25f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25fe:
	/* 0x25fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2603:
	/* 0x2603: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2608:
	/* 0x2608: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_260d:
	/* 0x260d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2610:
	/* 0x2610: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2612:
	/* 0x2612: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2617:
	/* 0x2617: je     26e5 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26e5;
	}
x86_l_261d:
	/* 0x261d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2622:
	/* 0x2622: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2627:
	/* 0x2627: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_262c:
	/* 0x262c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2631:
	/* 0x2631: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2634:
	/* 0x2634: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2636:
	/* 0x2636: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_263a:
	/* 0x263a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_263f:
	/* 0x263f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2644:
	/* 0x2644: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2649:
	/* 0x2649: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_264e:
	/* 0x264e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2651:
	/* 0x2651: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2653:
	/* 0x2653: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2657:
	/* 0x2657: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_265b:
	/* 0x265b: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_265f:
	/* 0x265f: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2662:
	/* 0x2662: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2666:
	/* 0x2666: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2668:
	/* 0x2668: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_266a:
	/* 0x266a: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_266d:
	/* 0x266d: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2670:
	/* 0x2670: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2675:
	/* 0x2675: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2677:
	/* 0x2677: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_267a:
	/* 0x267a: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_267e:
	/* 0x267e: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2680:
	/* 0x2680: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2684:
	/* 0x2684: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2686:
	/* 0x2686: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2689:
	/* 0x2689: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_268b:
	/* 0x268b: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_268e:
	/* 0x268e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2693:
	/* 0x2693: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2696:
	/* 0x2696: jb     2743 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10051ULL;
	}
x86_l_269c:
	/* 0x269c: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_26a3:
	/* 0x26a3: ja     2743 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10051ULL;
	}
x86_l_26a9:
	/* 0x26a9: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_26ac:
	/* 0x26ac: jbe    26b3 <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_26b3;
	}
x86_l_26ae:
	/* 0x26ae: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_26b3:
	/* 0x26b3: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26b5:
	/* 0x26b5: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_26b8:
	/* 0x26b8: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_26bc:
	/* 0x26bc: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_26c0:
	/* 0x26c0: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26c3:
	/* 0x26c3: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26c6:
	/* 0x26c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26cb:
	/* 0x26cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26cd:
	/* 0x26cd: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26d1:
	/* 0x26d1: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_26d4:
	/* 0x26d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26d9:
	/* 0x26d9: jbe    2743 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 10051ULL;
	}
x86_l_26db:
	/* 0x26db: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26e0:
	/* 0x26e0: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26e3:
	/* 0x26e3: jmp    2736 <cwd_read_v61+0x193> */
	return 10038ULL;
x86_l_26e5:
	/* 0x26e5: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26e9:
	/* 0x26e9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ee:
	/* 0x26ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26f3:
	/* 0x26f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26f8:
	/* 0x26f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26fd:
	/* 0x26fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ff:
	/* 0x26ff: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2703:
	/* 0x2703: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2708:
	/* 0x2708: je     273a <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10042ULL;
	}
x86_l_270a:
	/* 0x270a: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_270e:
	/* 0x270e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2713:
	/* 0x2713: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 10008ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10008ULL: goto x86_l_2718;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10030ULL: goto x86_l_272e;
	case 10034ULL: goto x86_l_2732;
	case 10038ULL: goto x86_l_2736;
	case 10040ULL: goto x86_l_2738;
	case 10042ULL: goto x86_l_273a;
	case 10046ULL: goto x86_l_273e;
	case 10051ULL: goto x86_l_2743;
	case 10055ULL: goto x86_l_2747;
	case 10056ULL: goto x86_l_2748;
	case 10058ULL: goto x86_l_274a;
	case 10060ULL: goto x86_l_274c;
	case 10062ULL: goto x86_l_274e;
	case 10064ULL: goto x86_l_2750;
	case 10065ULL: goto x86_l_2751;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2718:
	/* 0x2718: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_271b:
	/* 0x271b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2720:
	/* 0x2720: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2723:
	/* 0x2723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2725:
	/* 0x2725: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272a:
	/* 0x272a: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_272e:
	/* 0x272e: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2732:
	/* 0x2732: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2736:
	/* 0x2736: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2738:
	/* 0x2738: jmp    2743 <cwd_read_v61+0x1a0> */
	goto x86_l_2743;
x86_l_273a:
	/* 0x273a: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_273e:
	/* 0x273e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2743:
	/* 0x2743: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2747:
	/* 0x2747: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2748:
	/* 0x2748: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_274a:
	/* 0x274a: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_274c:
	/* 0x274c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_274e:
	/* 0x274e: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2750:
	/* 0x2750: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2751:
	/* 0x2751: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 9296U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1856ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1861ULL && __x86_pc <= 3723ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3731ULL && __x86_pc <= 5471ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5474ULL && __x86_pc <= 7074ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7078ULL && __x86_pc <= 8560ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8562ULL && __x86_pc <= 10003ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10008ULL && __x86_pc <= 10065ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_filter_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

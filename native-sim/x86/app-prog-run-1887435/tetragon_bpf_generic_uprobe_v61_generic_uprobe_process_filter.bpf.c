extern char CONFIG_ITER_NUM;
extern char PARENTS_MAP_ENABLED;
extern char buffer_heap_map;
extern char execve_map;
extern char filter_map;
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
extern char uprobe_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_0(
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
	case 63ULL: goto x86_l_3f;
	case 65ULL: goto x86_l_41;
	case 70ULL: goto x86_l_46;
	case 75ULL: goto x86_l_4b;
	case 80ULL: goto x86_l_50;
	case 85ULL: goto x86_l_55;
	case 90ULL: goto x86_l_5a;
	case 95ULL: goto x86_l_5f;
	case 97ULL: goto x86_l_61;
	case 101ULL: goto x86_l_65;
	case 108ULL: goto x86_l_6c;
	case 113ULL: goto x86_l_71;
	case 120ULL: goto x86_l_78;
	case 128ULL: goto x86_l_80;
	case 130ULL: goto x86_l_82;
	case 133ULL: goto x86_l_85;
	case 135ULL: goto x86_l_87;
	case 138ULL: goto x86_l_8a;
	case 143ULL: goto x86_l_8f;
	case 149ULL: goto x86_l_95;
	case 154ULL: goto x86_l_9a;
	case 159ULL: goto x86_l_9f;
	case 164ULL: goto x86_l_a4;
	case 169ULL: goto x86_l_a9;
	case 174ULL: goto x86_l_ae;
	case 176ULL: goto x86_l_b0;
	case 182ULL: goto x86_l_b6;
	case 188ULL: goto x86_l_bc;
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 203ULL: goto x86_l_cb;
	case 208ULL: goto x86_l_d0;
	case 213ULL: goto x86_l_d5;
	case 215ULL: goto x86_l_d7;
	case 219ULL: goto x86_l_db;
	case 226ULL: goto x86_l_e2;
	case 231ULL: goto x86_l_e7;
	case 238ULL: goto x86_l_ee;
	case 246ULL: goto x86_l_f6;
	case 248ULL: goto x86_l_f8;
	case 251ULL: goto x86_l_fb;
	case 253ULL: goto x86_l_fd;
	case 256ULL: goto x86_l_100;
	case 261ULL: goto x86_l_105;
	case 267ULL: goto x86_l_10b;
	case 272ULL: goto x86_l_110;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 287ULL: goto x86_l_11f;
	case 292ULL: goto x86_l_124;
	case 294ULL: goto x86_l_126;
	case 300ULL: goto x86_l_12c;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 316ULL: goto x86_l_13c;
	case 321ULL: goto x86_l_141;
	case 326ULL: goto x86_l_146;
	case 331ULL: goto x86_l_14b;
	case 333ULL: goto x86_l_14d;
	case 337ULL: goto x86_l_151;
	case 344ULL: goto x86_l_158;
	case 349ULL: goto x86_l_15d;
	case 356ULL: goto x86_l_164;
	case 364ULL: goto x86_l_16c;
	case 366ULL: goto x86_l_16e;
	case 369ULL: goto x86_l_171;
	case 371ULL: goto x86_l_173;
	case 374ULL: goto x86_l_176;
	case 379ULL: goto x86_l_17b;
	case 385ULL: goto x86_l_181;
	case 390ULL: goto x86_l_186;
	case 395ULL: goto x86_l_18b;
	case 400ULL: goto x86_l_190;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 412ULL: goto x86_l_19c;
	case 418ULL: goto x86_l_1a2;
	case 420ULL: goto x86_l_1a4;
	case 425ULL: goto x86_l_1a9;
	case 430ULL: goto x86_l_1ae;
	case 435ULL: goto x86_l_1b3;
	case 440ULL: goto x86_l_1b8;
	case 445ULL: goto x86_l_1bd;
	case 447ULL: goto x86_l_1bf;
	case 451ULL: goto x86_l_1c3;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 470ULL: goto x86_l_1d6;
	case 478ULL: goto x86_l_1de;
	case 480ULL: goto x86_l_1e0;
	case 483ULL: goto x86_l_1e3;
	case 485ULL: goto x86_l_1e5;
	case 488ULL: goto x86_l_1e8;
	case 493ULL: goto x86_l_1ed;
	case 499ULL: goto x86_l_1f3;
	case 504ULL: goto x86_l_1f8;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 519ULL: goto x86_l_207;
	case 524ULL: goto x86_l_20c;
	case 526ULL: goto x86_l_20e;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 541ULL: goto x86_l_21d;
	case 544ULL: goto x86_l_220;
	case 551ULL: goto x86_l_227;
	case 556ULL: goto x86_l_22c;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 568ULL: goto x86_l_238;
	case 572ULL: goto x86_l_23c;
	case 579ULL: goto x86_l_243;
	case 584ULL: goto x86_l_248;
	case 586ULL: goto x86_l_24a;
	case 593ULL: goto x86_l_251;
	case 604ULL: goto x86_l_25c;
	case 615ULL: goto x86_l_267;
	case 626ULL: goto x86_l_272;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 643ULL: goto x86_l_283;
	case 648ULL: goto x86_l_288;
	case 650ULL: goto x86_l_28a;
	case 652ULL: goto x86_l_28c;
	case 661ULL: goto x86_l_295;
	case 663ULL: goto x86_l_297;
	case 668ULL: goto x86_l_29c;
	case 676ULL: goto x86_l_2a4;
	case 680ULL: goto x86_l_2a8;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 692ULL: goto x86_l_2b4;
	case 697ULL: goto x86_l_2b9;
	case 699ULL: goto x86_l_2bb;
	case 704ULL: goto x86_l_2c0;
	case 712ULL: goto x86_l_2c8;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 722ULL: goto x86_l_2d2;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 739ULL: goto x86_l_2e3;
	case 741ULL: goto x86_l_2e5;
	case 745ULL: goto x86_l_2e9;
	case 752ULL: goto x86_l_2f0;
	case 759ULL: goto x86_l_2f7;
	case 763ULL: goto x86_l_2fb;
	case 770ULL: goto x86_l_302;
	case 774ULL: goto x86_l_306;
	case 781ULL: goto x86_l_30d;
	case 785ULL: goto x86_l_311;
	case 792ULL: goto x86_l_318;
	case 799ULL: goto x86_l_31f;
	case 802ULL: goto x86_l_322;
	case 808ULL: goto x86_l_328;
	case 812ULL: goto x86_l_32c;
	case 816ULL: goto x86_l_330;
	case 820ULL: goto x86_l_334;
	case 824ULL: goto x86_l_338;
	case 828ULL: goto x86_l_33c;
	case 832ULL: goto x86_l_340;
	case 836ULL: goto x86_l_344;
	case 840ULL: goto x86_l_348;
	case 847ULL: goto x86_l_34f;
	case 854ULL: goto x86_l_356;
	case 861ULL: goto x86_l_35d;
	case 868ULL: goto x86_l_364;
	case 872ULL: goto x86_l_368;
	case 879ULL: goto x86_l_36f;
	case 886ULL: goto x86_l_376;
	case 889ULL: goto x86_l_379;
	case 891ULL: goto x86_l_37b;
	case 895ULL: goto x86_l_37f;
	case 899ULL: goto x86_l_383;
	case 907ULL: goto x86_l_38b;
	case 914ULL: goto x86_l_392;
	case 916ULL: goto x86_l_394;
	case 919ULL: goto x86_l_397;
	case 926ULL: goto x86_l_39e;
	case 932ULL: goto x86_l_3a4;
	case 939ULL: goto x86_l_3ab;
	case 945ULL: goto x86_l_3b1;
	case 952ULL: goto x86_l_3b8;
	case 955ULL: goto x86_l_3bb;
	case 962ULL: goto x86_l_3c2;
	case 965ULL: goto x86_l_3c5;
	case 972ULL: goto x86_l_3cc;
	case 975ULL: goto x86_l_3cf;
	case 982ULL: goto x86_l_3d6;
	case 989ULL: goto x86_l_3dd;
	case 992ULL: goto x86_l_3e0;
	case 994ULL: goto x86_l_3e2;
	case 1001ULL: goto x86_l_3e9;
	case 1004ULL: goto x86_l_3ec;
	case 1010ULL: goto x86_l_3f2;
	case 1016ULL: goto x86_l_3f8;
	case 1023ULL: goto x86_l_3ff;
	case 1026ULL: goto x86_l_402;
	case 1028ULL: goto x86_l_404;
	case 1030ULL: goto x86_l_406;
	case 1041ULL: goto x86_l_411;
	case 1044ULL: goto x86_l_414;
	case 1046ULL: goto x86_l_416;
	case 1054ULL: goto x86_l_41e;
	case 1061ULL: goto x86_l_425;
	case 1066ULL: goto x86_l_42a;
	case 1071ULL: goto x86_l_42f;
	case 1073ULL: goto x86_l_431;
	case 1078ULL: goto x86_l_436;
	case 1085ULL: goto x86_l_43d;
	case 1090ULL: goto x86_l_442;
	case 1097ULL: goto x86_l_449;
	case 1102ULL: goto x86_l_44e;
	case 1110ULL: goto x86_l_456;
	case 1115ULL: goto x86_l_45b;
	case 1118ULL: goto x86_l_45e;
	case 1120ULL: goto x86_l_460;
	case 1125ULL: goto x86_l_465;
	case 1130ULL: goto x86_l_46a;
	case 1138ULL: goto x86_l_472;
	case 1143ULL: goto x86_l_477;
	case 1148ULL: goto x86_l_47c;
	case 1150ULL: goto x86_l_47e;
	case 1155ULL: goto x86_l_483;
	case 1166ULL: goto x86_l_48e;
	case 1171ULL: goto x86_l_493;
	case 1178ULL: goto x86_l_49a;
	case 1186ULL: goto x86_l_4a2;
	case 1188ULL: goto x86_l_4a4;
	case 1191ULL: goto x86_l_4a7;
	case 1197ULL: goto x86_l_4ad;
	case 1200ULL: goto x86_l_4b0;
	case 1205ULL: goto x86_l_4b5;
	case 1216ULL: goto x86_l_4c0;
	case 1223ULL: goto x86_l_4c7;
	case 1228ULL: goto x86_l_4cc;
	case 1230ULL: goto x86_l_4ce;
	case 1237ULL: goto x86_l_4d5;
	case 1242ULL: goto x86_l_4da;
	case 1250ULL: goto x86_l_4e2;
	case 1255ULL: goto x86_l_4e7;
	case 1257ULL: goto x86_l_4e9;
	case 1265ULL: goto x86_l_4f1;
	case 1269ULL: goto x86_l_4f5;
	case 1274ULL: goto x86_l_4fa;
	case 1282ULL: goto x86_l_502;
	case 1287ULL: goto x86_l_507;
	case 1290ULL: goto x86_l_50a;
	case 1292ULL: goto x86_l_50c;
	case 1300ULL: goto x86_l_514;
	case 1304ULL: goto x86_l_518;
	case 1309ULL: goto x86_l_51d;
	case 1314ULL: goto x86_l_522;
	case 1319ULL: goto x86_l_527;
	case 1321ULL: goto x86_l_529;
	case 1327ULL: goto x86_l_52f;
	case 1333ULL: goto x86_l_535;
	case 1337ULL: goto x86_l_539;
	case 1341ULL: goto x86_l_53d;
	case 1350ULL: goto x86_l_546;
	case 1359ULL: goto x86_l_54f;
	case 1364ULL: goto x86_l_554;
	case 1373ULL: goto x86_l_55d;
	case 1385ULL: goto x86_l_569;
	case 1397ULL: goto x86_l_575;
	case 1402ULL: goto x86_l_57a;
	case 1410ULL: goto x86_l_582;
	case 1418ULL: goto x86_l_58a;
	case 1423ULL: goto x86_l_58f;
	case 1430ULL: goto x86_l_596;
	case 1437ULL: goto x86_l_59d;
	case 1445ULL: goto x86_l_5a5;
	case 1449ULL: goto x86_l_5a9;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1464ULL: goto x86_l_5b8;
	case 1467ULL: goto x86_l_5bb;
	case 1469ULL: goto x86_l_5bd;
	case 1474ULL: goto x86_l_5c2;
	case 1479ULL: goto x86_l_5c7;
	case 1484ULL: goto x86_l_5cc;
	case 1487ULL: goto x86_l_5cf;
	case 1489ULL: goto x86_l_5d1;
	case 1494ULL: goto x86_l_5d6;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1505ULL: goto x86_l_5e1;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1528ULL: goto x86_l_5f8;
	case 1530ULL: goto x86_l_5fa;
	case 1538ULL: goto x86_l_602;
	case 1542ULL: goto x86_l_606;
	case 1550ULL: goto x86_l_60e;
	case 1557ULL: goto x86_l_615;
	case 1560ULL: goto x86_l_618;
	case 1566ULL: goto x86_l_61e;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1589ULL: goto x86_l_635;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1615ULL: goto x86_l_64f;
	case 1620ULL: goto x86_l_654;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1635ULL: goto x86_l_663;
	case 1643ULL: goto x86_l_66b;
	case 1649ULL: goto x86_l_671;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1669ULL: goto x86_l_685;
	case 1671ULL: goto x86_l_687;
	case 1676ULL: goto x86_l_68c;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1695ULL: goto x86_l_69f;
	case 1700ULL: goto x86_l_6a4;
	case 1703ULL: goto x86_l_6a7;
	case 1705ULL: goto x86_l_6a9;
	case 1709ULL: goto x86_l_6ad;
	case 1714ULL: goto x86_l_6b2;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1730ULL: goto x86_l_6c2;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1745ULL: goto x86_l_6d1;
	case 1752ULL: goto x86_l_6d8;
	case 1755ULL: goto x86_l_6db;
	case 1762ULL: goto x86_l_6e2;
	case 1764ULL: goto x86_l_6e4;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1774ULL: goto x86_l_6ee;
	case 1782ULL: goto x86_l_6f6;
	case 1785ULL: goto x86_l_6f9;
	case 1787ULL: goto x86_l_6fb;
	case 1791ULL: goto x86_l_6ff;
	case 1793ULL: goto x86_l_701;
	case 1796ULL: goto x86_l_704;
	case 1799ULL: goto x86_l_707;
	case 1802ULL: goto x86_l_70a;
	case 1805ULL: goto x86_l_70d;
	case 1813ULL: goto x86_l_715;
	case 1816ULL: goto x86_l_718;
	case 1822ULL: goto x86_l_71e;
	case 1828ULL: goto x86_l_724;
	case 1834ULL: goto x86_l_72a;
	case 1836ULL: goto x86_l_72c;
	case 1842ULL: goto x86_l_732;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1855ULL: goto x86_l_73f;
	case 1859ULL: goto x86_l_743;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1869ULL: goto x86_l_74d;
	case 1877ULL: goto x86_l_755;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1892ULL: goto x86_l_764;
	case 1898ULL: goto x86_l_76a;
	case 1903ULL: goto x86_l_76f;
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
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x30a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     2290 <generic_uprobe_process_filter+0x2290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8848ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_3f:
	/* 0x3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41:
	/* 0x41: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_46:
	/* 0x46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b:
	/* 0x4b: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_50:
	/* 0x50: add    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_55:
	/* 0x55: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5a:
	/* 0x5a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5f:
	/* 0x5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61:
	/* 0x61: mov    eax,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_65:
	/* 0x65: mov    DWORD PTR [rsp+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6c:
	/* 0x6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_71:
	/* 0x71: mov    rdi,QWORD PTR [rip+0x30a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_78:
	/* 0x78: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_80:
	/* 0x80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82:
	/* 0x82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85:
	/* 0x85: je     95 <generic_uprobe_process_filter+0x95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_95;
	}
x86_l_87:
	/* 0x87: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_8f:
	/* 0x8f: jne    be0 <generic_uprobe_process_filter+0xbe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3040ULL;
	}
x86_l_95:
	/* 0x95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9a:
	/* 0x9a: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_9f:
	/* 0x9f: add    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_a4:
	/* 0xa4: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a9:
	/* 0xa9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae:
	/* 0xae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0:
	/* 0xb0: cmp    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_b6:
	/* 0xb6: je     20e <generic_uprobe_process_filter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_bc:
	/* 0xbc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c1:
	/* 0xc1: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_c6:
	/* 0xc6: add    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_cb:
	/* 0xcb: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d0:
	/* 0xd0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d5:
	/* 0xd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7:
	/* 0xd7: mov    eax,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_db:
	/* 0xdb: mov    DWORD PTR [rsp+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e2:
	/* 0xe2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e7:
	/* 0xe7: mov    rdi,QWORD PTR [rip+0x30a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ee:
	/* 0xee: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f6:
	/* 0xf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8:
	/* 0xf8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: je     10b <generic_uprobe_process_filter+0x10b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b;
	}
x86_l_fd:
	/* 0xfd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_100:
	/* 0x100: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_105:
	/* 0x105: jne    be0 <generic_uprobe_process_filter+0xbe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3040ULL;
	}
x86_l_10b:
	/* 0x10b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_110:
	/* 0x110: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_115:
	/* 0x115: add    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_11a:
	/* 0x11a: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11f:
	/* 0x11f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_124:
	/* 0x124: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126:
	/* 0x126: cmp    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_12c:
	/* 0x12c: je     20e <generic_uprobe_process_filter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_132:
	/* 0x132: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_137:
	/* 0x137: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_13c:
	/* 0x13c: add    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_141:
	/* 0x141: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_146:
	/* 0x146: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14b:
	/* 0x14b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d:
	/* 0x14d: mov    eax,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_151:
	/* 0x151: mov    DWORD PTR [rsp+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_158:
	/* 0x158: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15d:
	/* 0x15d: mov    rdi,QWORD PTR [rip+0x30a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_164:
	/* 0x164: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_16c:
	/* 0x16c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e:
	/* 0x16e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_171:
	/* 0x171: je     181 <generic_uprobe_process_filter+0x181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_181;
	}
x86_l_173:
	/* 0x173: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_176:
	/* 0x176: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_17b:
	/* 0x17b: jne    be0 <generic_uprobe_process_filter+0xbe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3040ULL;
	}
x86_l_181:
	/* 0x181: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_186:
	/* 0x186: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_18b:
	/* 0x18b: add    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_190:
	/* 0x190: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_195:
	/* 0x195: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19a:
	/* 0x19a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c:
	/* 0x19c: cmp    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1a2:
	/* 0x1a2: je     20e <generic_uprobe_process_filter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_1a4:
	/* 0x1a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a9:
	/* 0x1a9: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_1ae:
	/* 0x1ae: add    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_1b3:
	/* 0x1b3: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b8:
	/* 0x1b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bd:
	/* 0x1bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf:
	/* 0x1bf: mov    eax,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1c3:
	/* 0x1c3: mov    DWORD PTR [rsp+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ca:
	/* 0x1ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cf:
	/* 0x1cf: mov    rdi,QWORD PTR [rip+0x30a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1d6:
	/* 0x1d6: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1de:
	/* 0x1de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0:
	/* 0x1e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e3:
	/* 0x1e3: je     1f3 <generic_uprobe_process_filter+0x1f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f3;
	}
x86_l_1e5:
	/* 0x1e5: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1e8:
	/* 0x1e8: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1ed:
	/* 0x1ed: jne    be0 <generic_uprobe_process_filter+0xbe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3040ULL;
	}
x86_l_1f3:
	/* 0x1f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f8:
	/* 0x1f8: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_1fd:
	/* 0x1fd: add    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_202:
	/* 0x202: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_207:
	/* 0x207: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20c:
	/* 0x20c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e:
	/* 0x20e: mov    QWORD PTR [rsp+0xb8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_216:
	/* 0x216: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_21b:
	/* 0x21b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d:
	/* 0x21d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_220:
	/* 0x220: lea    rdx,[rax+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_227:
	/* 0x227: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22c:
	/* 0x22c: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_231:
	/* 0x231: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_236:
	/* 0x236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_238:
	/* 0x238: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23c:
	/* 0x23c: mov    DWORD PTR [r14+0x5f10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24336ULL);
x86_l_243:
	/* 0x243: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_248:
	/* 0x248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a:
	/* 0x24a: mov    QWORD PTR [r14+0x5f18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24344ULL);
x86_l_251:
	/* 0x251: mov    DWORD PTR [r14+0x5f20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104591043592192ULL);
x86_l_25c:
	/* 0x25c: mov    QWORD PTR [r14+0x5f28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104625403330560ULL);
x86_l_267:
	/* 0x267: mov    DWORD PTR [r14+0x5f30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104659763068928ULL);
x86_l_272:
	/* 0x272: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_276:
	/* 0x276: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27b:
	/* 0x27b: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_283:
	/* 0x283: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_288:
	/* 0x288: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a:
	/* 0x28a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28c:
	/* 0x28c: cmp    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_295:
	/* 0x295: je     2e9 <generic_uprobe_process_filter+0x2e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e9;
	}
x86_l_297:
	/* 0x297: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29c:
	/* 0x29c: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2a4:
	/* 0x2a4: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2a8:
	/* 0x2a8: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2ad:
	/* 0x2ad: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b2:
	/* 0x2b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4:
	/* 0x2b4: cmp    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2b9:
	/* 0x2b9: je     2e9 <generic_uprobe_process_filter+0x2e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e9;
	}
x86_l_2bb:
	/* 0x2bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c0:
	/* 0x2c0: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c8:
	/* 0x2c8: mov    edx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2cc:
	/* 0x2cc: shl    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_2cf:
	/* 0x2cf: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d2:
	/* 0x2d2: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_2d9:
	/* 0x2d9: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2de:
	/* 0x2de: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e3:
	/* 0x2e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e5:
	/* 0x2e5: mov    ebx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e9:
	/* 0x2e9: mov    DWORD PTR [r14+0x5f34],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24372ULL);
x86_l_2f0:
	/* 0x2f0: mov    rax,QWORD PTR [r13+0xce0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3296ULL);
x86_l_2f7:
	/* 0x2f7: mov    rcx,QWORD PTR [rax+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2fb:
	/* 0x2fb: mov    QWORD PTR [r14+0x5f68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24424ULL);
x86_l_302:
	/* 0x302: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_306:
	/* 0x306: mov    QWORD PTR [r14+0x5f70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24432ULL);
x86_l_30d:
	/* 0x30d: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_311:
	/* 0x311: mov    QWORD PTR [r14+0x5f60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24416ULL);
x86_l_318:
	/* 0x318: mov    rax,QWORD PTR [r13+0xd48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_31f:
	/* 0x31f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_322:
	/* 0x322: je     411 <generic_uprobe_process_filter+0x411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_411;
	}
x86_l_328:
	/* 0x328: mov    r8,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32c:
	/* 0x32c: mov    r9,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_330:
	/* 0x330: mov    r10,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_334:
	/* 0x334: mov    rdi,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_338:
	/* 0x338: mov    rsi,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33c:
	/* 0x33c: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_340:
	/* 0x340: mov    rcx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_344:
	/* 0x344: mov    rax,QWORD PTR [rax+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_348:
	/* 0x348: mov    r8d,DWORD PTR [r8+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_34f:
	/* 0x34f: mov    DWORD PTR [r14+0x5f38],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24376ULL);
x86_l_356:
	/* 0x356: mov    r8d,DWORD PTR [r9+0x470] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1136ULL);
x86_l_35d:
	/* 0x35d: mov    DWORD PTR [r14+0x5f3c],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24380ULL);
x86_l_364:
	/* 0x364: mov    r8d,DWORD PTR [r10+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_368:
	/* 0x368: mov    DWORD PTR [r14+0x5f40],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24384ULL);
x86_l_36f:
	/* 0x36f: mov    r8,QWORD PTR [r13+0xb38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_376:
	/* 0x376: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_379:
	/* 0x379: je     394 <generic_uprobe_process_filter+0x394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_394;
	}
x86_l_37b:
	/* 0x37b: movsxd r9,DWORD PTR [r8+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_37f:
	/* 0x37f: shl    r9,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_383:
	/* 0x383: mov    r8,QWORD PTR [r8+r9*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 144ULL);
x86_l_38b:
	/* 0x38b: mov    r8d,DWORD PTR [r8+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_392:
	/* 0x392: jmp    397 <generic_uprobe_process_filter+0x397> */
	goto x86_l_397;
x86_l_394:
	/* 0x394: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_397:
	/* 0x397: mov    DWORD PTR [r14+0x5f44],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24388ULL);
x86_l_39e:
	/* 0x39e: mov    edi,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3a4:
	/* 0x3a4: mov    DWORD PTR [r14+0x5f48],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24392ULL);
x86_l_3ab:
	/* 0x3ab: mov    esi,DWORD PTR [rsi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3b1:
	/* 0x3b1: mov    DWORD PTR [r14+0x5f4c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24396ULL);
x86_l_3b8:
	/* 0x3b8: mov    edx,DWORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3bb:
	/* 0x3bb: mov    DWORD PTR [r14+0x5f50],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24400ULL);
x86_l_3c2:
	/* 0x3c2: mov    ecx,DWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c5:
	/* 0x3c5: mov    DWORD PTR [r14+0x5f54],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24404ULL);
x86_l_3cc:
	/* 0x3cc: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cf:
	/* 0x3cf: mov    DWORD PTR [r14+0x5f58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24408ULL);
x86_l_3d6:
	/* 0x3d6: mov    rax,QWORD PTR [r13+0xa50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_3dd:
	/* 0x3dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e0:
	/* 0x3e0: je     406 <generic_uprobe_process_filter+0x406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_406;
	}
x86_l_3e2:
	/* 0x3e2: mov    rax,QWORD PTR [rax+0x4a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1184ULL);
x86_l_3e9:
	/* 0x3e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ec:
	/* 0x3ec: je     8c1 <generic_uprobe_process_filter+0x8c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2241ULL;
	}
x86_l_3f2:
	/* 0x3f2: mov    eax,DWORD PTR [rax+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3f8:
	/* 0x3f8: mov    DWORD PTR [r14+0x5f5c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24412ULL);
x86_l_3ff:
	/* 0x3ff: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_402:
	/* 0x402: je     416 <generic_uprobe_process_filter+0x416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_416;
	}
x86_l_404:
	/* 0x404: jmp    41e <generic_uprobe_process_filter+0x41e> */
	goto x86_l_41e;
x86_l_406:
	/* 0x406: mov    DWORD PTR [r14+0x5f5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104848741629952ULL);
x86_l_411:
	/* 0x411: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_414:
	/* 0x414: jne    41e <generic_uprobe_process_filter+0x41e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_41e;
	}
x86_l_416:
	/* 0x416: or     BYTE PTR [r14+0x5f33],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 104672647970818ULL);
x86_l_41e:
	/* 0x41e: lea    rdi,[r14+0x5f78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24440ULL);
x86_l_425:
	/* 0x425: mov    edx,0x308 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 776ULL);
x86_l_42a:
	/* 0x42a: mov    QWORD PTR [rsp+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_42f:
	/* 0x42f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_431:
	/* 0x431: call   34dd <cwd_read_v61+0x1221> */
	X86_SIM_L_EXEC_CALL_MEMSET(776ULL);
x86_l_436:
	/* 0x436: lea    rax,[r14+0x6290] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25232ULL);
x86_l_43d:
	/* 0x43d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_442:
	/* 0x442: add    r13,0xa50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2640ULL);
x86_l_449:
	/* 0x449: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44e:
	/* 0x44e: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_456:
	/* 0x456: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45b:
	/* 0x45b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_45e:
	/* 0x45e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_460:
	/* 0x460: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_465:
	/* 0x465: mov    edx,0x4a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1192ULL);
x86_l_46a:
	/* 0x46a: add    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 160ULL);
x86_l_472:
	/* 0x472: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_477:
	/* 0x477: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47c:
	/* 0x47c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47e:
	/* 0x47e: mov    rbx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_483:
	/* 0x483: mov    DWORD PTR [rsp+0xcc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_48e:
	/* 0x48e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_493:
	/* 0x493: mov    rdi,QWORD PTR [rip+0x30a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_49a:
	/* 0x49a: lea    rsi,[rsp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_4a2:
	/* 0x4a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a4:
	/* 0x4a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a7:
	/* 0x4a7: je     a4a <generic_uprobe_process_filter+0xa4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2634ULL;
	}
x86_l_4ad:
	/* 0x4ad: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4b0:
	/* 0x4b0: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4b5:
	/* 0x4b5: mov    DWORD PTR [r14+0x6410],0x1000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882258432ULL);
x86_l_4c0:
	/* 0x4c0: lea    r14,[rax+0x1000] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_4c7:
	/* 0x4c7: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_4cc:
	/* 0x4cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ce:
	/* 0x4ce: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_4d5:
	/* 0x4d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4da:
	/* 0x4da: lea    rdi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_4e2:
	/* 0x4e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e7:
	/* 0x4e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e9:
	/* 0x4e9: mov    rbp,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_4f1:
	/* 0x4f1: lea    r15,[rbx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4f5:
	/* 0x4f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fa:
	/* 0x4fa: lea    rdi,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_502:
	/* 0x502: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_507:
	/* 0x507: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_50a:
	/* 0x50a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50c:
	/* 0x50c: mov    r13,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_514:
	/* 0x514: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_518:
	/* 0x518: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51d:
	/* 0x51d: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_522:
	/* 0x522: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_527:
	/* 0x527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_529:
	/* 0x529: cmp    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_52f:
	/* 0x52f: je     7d4 <generic_uprobe_process_filter+0x7d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2004ULL;
	}
x86_l_535:
	/* 0x535: add    rbx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_539:
	/* 0x539: lea    r13,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53d:
	/* 0x53d: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_546:
	/* 0x546: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_54f:
	/* 0x54f: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_554:
	/* 0x554: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_55d:
	/* 0x55d: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_569:
	/* 0x569: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_575:
	/* 0x575: lea    r12,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_57a:
	/* 0x57a: mov    QWORD PTR [rsp+0xc0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_582:
	/* 0x582: mov    QWORD PTR [rsp+0x90],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_58a:
	/* 0x58a: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_58f:
	/* 0x58f: mov    eax,DWORD PTR [r14+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_596:
	/* 0x596: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_59d:
	/* 0x59d: mov    BYTE PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_5a5:
	/* 0x5a5: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_5a9:
	/* 0x5a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5ae:
	/* 0x5ae: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5b3:
	/* 0x5b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b8:
	/* 0x5b8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5bb:
	/* 0x5bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bd:
	/* 0x5bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5c2:
	/* 0x5c2: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5c7:
	/* 0x5c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cc:
	/* 0x5cc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5cf:
	/* 0x5cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d1:
	/* 0x5d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d6:
	/* 0x5d6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_5d9:
	/* 0x5d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5de:
	/* 0x5de: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5e1:
	/* 0x5e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e3:
	/* 0x5e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e8:
	/* 0x5e8: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5f0:
	/* 0x5f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f5:
	/* 0x5f5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5f8:
	/* 0x5f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fa:
	/* 0x5fa: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_602:
	/* 0x602: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_606:
	/* 0x606: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_60e:
	/* 0x60e: mov    rax,QWORD PTR [rip+0x30a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_615:
	/* 0x615: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_618:
	/* 0x618: je     826 <generic_uprobe_process_filter+0x826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2086ULL;
	}
x86_l_61e:
	/* 0x61e: mov    ebp,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2048ULL);
x86_l_623:
	/* 0x623: lea    rbx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_628:
	/* 0x628: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_62d:
	/* 0x62d: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_635:
	/* 0x635: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_63d:
	/* 0x63d: cmp    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_642:
	/* 0x642: jne    64f <generic_uprobe_process_filter+0x64f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_64f;
	}
x86_l_644:
	/* 0x644: cmp    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 104ULL);
x86_l_649:
	/* 0x649: je     85a <generic_uprobe_process_filter+0x85a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2138ULL;
	}
x86_l_64f:
	/* 0x64f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_654:
	/* 0x654: lea    rdi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_65c:
	/* 0x65c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_661:
	/* 0x661: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_663:
	/* 0x663: cmp    r15,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 240ULL);
x86_l_66b:
	/* 0x66b: je     76f <generic_uprobe_process_filter+0x76f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_76f;
	}
x86_l_671:
	/* 0x671: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_675:
	/* 0x675: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_67a:
	/* 0x67a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_67d:
	/* 0x67d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_682:
	/* 0x682: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_685:
	/* 0x685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_687:
	/* 0x687: cmp    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_68c:
	/* 0x68c: je     76f <generic_uprobe_process_filter+0x76f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_76f;
	}
x86_l_692:
	/* 0x692: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_697:
	/* 0x697: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_69f:
	/* 0x69f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a4:
	/* 0x6a4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6a7:
	/* 0x6a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a9:
	/* 0x6a9: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_6ad:
	/* 0x6ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b2:
	/* 0x6b2: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6ba:
	/* 0x6ba: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6bf:
	/* 0x6bf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6c2:
	/* 0x6c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c4:
	/* 0x6c4: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6c9:
	/* 0x6c9: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6d1:
	/* 0x6d1: mov    ecx,DWORD PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_6d8:
	/* 0x6d8: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_6db:
	/* 0x6db: mov    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6e2:
	/* 0x6e2: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_6e4:
	/* 0x6e4: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6e6:
	/* 0x6e6: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_6eb:
	/* 0x6eb: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_6ee:
	/* 0x6ee: add    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 168ULL);
x86_l_6f6:
	/* 0x6f6: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f9:
	/* 0x6f9: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_6fb:
	/* 0x6fb: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_6ff:
	/* 0x6ff: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_701:
	/* 0x701: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_704:
	/* 0x704: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_707:
	/* 0x707: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_70a:
	/* 0x70a: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_70d:
	/* 0x70d: mov    DWORD PTR [rsp+0x98],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_715:
	/* 0x715: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_718:
	/* 0x718: jb     862 <generic_uprobe_process_filter+0x862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2146ULL;
	}
x86_l_71e:
	/* 0x71e: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_724:
	/* 0x724: ja     862 <generic_uprobe_process_filter+0x862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2146ULL;
	}
x86_l_72a:
	/* 0x72a: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_72c:
	/* 0x72c: jbe    906 <generic_uprobe_process_filter+0x906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2310ULL;
	}
x86_l_732:
	/* 0x732: lea    r15,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_736:
	/* 0x736: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_73b:
	/* 0x73b: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_73f:
	/* 0x73f: lea    rdi,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_743:
	/* 0x743: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_746:
	/* 0x746: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_74b:
	/* 0x74b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74d:
	/* 0x74d: mov    QWORD PTR [rsp+0x90],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_755:
	/* 0x755: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_75d:
	/* 0x75d: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_762:
	/* 0x762: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_764:
	/* 0x764: jne    628 <generic_uprobe_process_filter+0x628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_628;
	}
x86_l_76a:
	/* 0x76a: jmp    862 <generic_uprobe_process_filter+0x862> */
	return 2146ULL;
x86_l_76f:
	/* 0x76f: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 1908ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1923ULL: goto x86_l_783;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1942ULL: goto x86_l_796;
	case 1946ULL: goto x86_l_79a;
	case 1951ULL: goto x86_l_79f;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1964ULL: goto x86_l_7ac;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1979ULL: goto x86_l_7bb;
	case 1983ULL: goto x86_l_7bf;
	case 1991ULL: goto x86_l_7c7;
	case 1993ULL: goto x86_l_7c9;
	case 1999ULL: goto x86_l_7cf;
	case 2004ULL: goto x86_l_7d4;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2018ULL: goto x86_l_7e2;
	case 2023ULL: goto x86_l_7e7;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2047ULL: goto x86_l_7ff;
	case 2050ULL: goto x86_l_802;
	case 2056ULL: goto x86_l_808;
	case 2059ULL: goto x86_l_80b;
	case 2065ULL: goto x86_l_811;
	case 2075ULL: goto x86_l_81b;
	case 2078ULL: goto x86_l_81e;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2098ULL: goto x86_l_832;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2110ULL: goto x86_l_83e;
	case 2112ULL: goto x86_l_840;
	case 2120ULL: goto x86_l_848;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2133ULL: goto x86_l_855;
	case 2138ULL: goto x86_l_85a;
	case 2146ULL: goto x86_l_862;
	case 2154ULL: goto x86_l_86a;
	case 2162ULL: goto x86_l_872;
	case 2165ULL: goto x86_l_875;
	case 2171ULL: goto x86_l_87b;
	case 2173ULL: goto x86_l_87d;
	case 2181ULL: goto x86_l_885;
	case 2184ULL: goto x86_l_888;
	case 2186ULL: goto x86_l_88a;
	case 2193ULL: goto x86_l_891;
	case 2200ULL: goto x86_l_898;
	case 2207ULL: goto x86_l_89f;
	case 2209ULL: goto x86_l_8a1;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2225ULL: goto x86_l_8b1;
	case 2227ULL: goto x86_l_8b3;
	case 2230ULL: goto x86_l_8b6;
	case 2236ULL: goto x86_l_8bc;
	case 2241ULL: goto x86_l_8c1;
	case 2252ULL: goto x86_l_8cc;
	case 2255ULL: goto x86_l_8cf;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2269ULL: goto x86_l_8dd;
	case 2276ULL: goto x86_l_8e4;
	case 2286ULL: goto x86_l_8ee;
	case 2294ULL: goto x86_l_8f6;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2314ULL: goto x86_l_90a;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2325ULL: goto x86_l_915;
	case 2327ULL: goto x86_l_917;
	case 2335ULL: goto x86_l_91f;
	case 2343ULL: goto x86_l_927;
	case 2351ULL: goto x86_l_92f;
	case 2354ULL: goto x86_l_932;
	case 2360ULL: goto x86_l_938;
	case 2371ULL: goto x86_l_943;
	case 2382ULL: goto x86_l_94e;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2404ULL: goto x86_l_964;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2421ULL: goto x86_l_975;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2448ULL: goto x86_l_990;
	case 2450ULL: goto x86_l_992;
	case 2453ULL: goto x86_l_995;
	case 2455ULL: goto x86_l_997;
	case 2457ULL: goto x86_l_999;
	case 2462ULL: goto x86_l_99e;
	case 2469ULL: goto x86_l_9a5;
	case 2479ULL: goto x86_l_9af;
	case 2484ULL: goto x86_l_9b4;
	case 2489ULL: goto x86_l_9b9;
	case 2496ULL: goto x86_l_9c0;
	case 2501ULL: goto x86_l_9c5;
	case 2503ULL: goto x86_l_9c7;
	case 2506ULL: goto x86_l_9ca;
	case 2508ULL: goto x86_l_9cc;
	case 2510ULL: goto x86_l_9ce;
	case 2512ULL: goto x86_l_9d0;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2535ULL: goto x86_l_9e7;
	case 2540ULL: goto x86_l_9ec;
	case 2548ULL: goto x86_l_9f4;
	case 2550ULL: goto x86_l_9f6;
	case 2552ULL: goto x86_l_9f8;
	case 2559ULL: goto x86_l_9ff;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2569ULL: goto x86_l_a09;
	case 2572ULL: goto x86_l_a0c;
	case 2574ULL: goto x86_l_a0e;
	case 2577ULL: goto x86_l_a11;
	case 2579ULL: goto x86_l_a13;
	case 2581ULL: goto x86_l_a15;
	case 2586ULL: goto x86_l_a1a;
	case 2593ULL: goto x86_l_a21;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2627ULL: goto x86_l_a43;
	case 2630ULL: goto x86_l_a46;
	case 2632ULL: goto x86_l_a48;
	case 2634ULL: goto x86_l_a4a;
	case 2641ULL: goto x86_l_a51;
	case 2647ULL: goto x86_l_a57;
	case 2653ULL: goto x86_l_a5d;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2666ULL: goto x86_l_a6a;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2690ULL: goto x86_l_a82;
	case 2695ULL: goto x86_l_a87;
	case 2702ULL: goto x86_l_a8e;
	case 2707ULL: goto x86_l_a93;
	case 2715ULL: goto x86_l_a9b;
	case 2717ULL: goto x86_l_a9d;
	case 2719ULL: goto x86_l_a9f;
	case 2726ULL: goto x86_l_aa6;
	case 2732ULL: goto x86_l_aac;
	case 2738ULL: goto x86_l_ab2;
	case 2740ULL: goto x86_l_ab4;
	case 2743ULL: goto x86_l_ab7;
	case 2750ULL: goto x86_l_abe;
	case 2755ULL: goto x86_l_ac3;
	case 2757ULL: goto x86_l_ac5;
	case 2762ULL: goto x86_l_aca;
	case 2764ULL: goto x86_l_acc;
	case 2767ULL: goto x86_l_acf;
	case 2770ULL: goto x86_l_ad2;
	case 2772ULL: goto x86_l_ad4;
	case 2775ULL: goto x86_l_ad7;
	case 2777ULL: goto x86_l_ad9;
	case 2782ULL: goto x86_l_ade;
	case 2789ULL: goto x86_l_ae5;
	case 2799ULL: goto x86_l_aef;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2823ULL: goto x86_l_b07;
	case 2826ULL: goto x86_l_b0a;
	case 2828ULL: goto x86_l_b0c;
	case 2830ULL: goto x86_l_b0e;
	case 2832ULL: goto x86_l_b10;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2855ULL: goto x86_l_b27;
	case 2860ULL: goto x86_l_b2c;
	case 2868ULL: goto x86_l_b34;
	case 2870ULL: goto x86_l_b36;
	case 2872ULL: goto x86_l_b38;
	case 2875ULL: goto x86_l_b3b;
	case 2879ULL: goto x86_l_b3f;
	case 2886ULL: goto x86_l_b46;
	case 2889ULL: goto x86_l_b49;
	case 2894ULL: goto x86_l_b4e;
	case 2897ULL: goto x86_l_b51;
	case 2904ULL: goto x86_l_b58;
	case 2911ULL: goto x86_l_b5f;
	case 2916ULL: goto x86_l_b64;
	case 2918ULL: goto x86_l_b66;
	case 2921ULL: goto x86_l_b69;
	case 2929ULL: goto x86_l_b71;
	case 2931ULL: goto x86_l_b73;
	case 2933ULL: goto x86_l_b75;
	case 2938ULL: goto x86_l_b7a;
	case 2945ULL: goto x86_l_b81;
	case 2955ULL: goto x86_l_b8b;
	case 2960ULL: goto x86_l_b90;
	case 2965ULL: goto x86_l_b95;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2979ULL: goto x86_l_ba3;
	case 2982ULL: goto x86_l_ba6;
	case 2984ULL: goto x86_l_ba8;
	case 2986ULL: goto x86_l_baa;
	case 2988ULL: goto x86_l_bac;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3011ULL: goto x86_l_bc3;
	case 3016ULL: goto x86_l_bc8;
	case 3024ULL: goto x86_l_bd0;
	case 3026ULL: goto x86_l_bd2;
	case 3028ULL: goto x86_l_bd4;
	case 3035ULL: goto x86_l_bdb;
	case 3040ULL: goto x86_l_be0;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3059ULL: goto x86_l_bf3;
	case 3061ULL: goto x86_l_bf5;
	case 3064ULL: goto x86_l_bf8;
	case 3070ULL: goto x86_l_bfe;
	case 3077ULL: goto x86_l_c05;
	case 3081ULL: goto x86_l_c09;
	case 3087ULL: goto x86_l_c0f;
	case 3090ULL: goto x86_l_c12;
	case 3093ULL: goto x86_l_c15;
	case 3099ULL: goto x86_l_c1b;
	case 3102ULL: goto x86_l_c1e;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3121ULL: goto x86_l_c31;
	case 3129ULL: goto x86_l_c39;
	case 3133ULL: goto x86_l_c3d;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3163ULL: goto x86_l_c5b;
	case 3166ULL: goto x86_l_c5e;
	case 3171ULL: goto x86_l_c63;
	case 3177ULL: goto x86_l_c69;
	case 3180ULL: goto x86_l_c6c;
	case 3182ULL: goto x86_l_c6e;
	case 3184ULL: goto x86_l_c70;
	case 3190ULL: goto x86_l_c76;
	case 3195ULL: goto x86_l_c7b;
	case 3201ULL: goto x86_l_c81;
	case 3204ULL: goto x86_l_c84;
	case 3210ULL: goto x86_l_c8a;
	case 3215ULL: goto x86_l_c8f;
	case 3218ULL: goto x86_l_c92;
	case 3224ULL: goto x86_l_c98;
	case 3229ULL: goto x86_l_c9d;
	case 3232ULL: goto x86_l_ca0;
	case 3238ULL: goto x86_l_ca6;
	case 3243ULL: goto x86_l_cab;
	case 3246ULL: goto x86_l_cae;
	case 3252ULL: goto x86_l_cb4;
	case 3255ULL: goto x86_l_cb7;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3271ULL: goto x86_l_cc7;
	case 3273ULL: goto x86_l_cc9;
	case 3276ULL: goto x86_l_ccc;
	case 3282ULL: goto x86_l_cd2;
	case 3285ULL: goto x86_l_cd5;
	case 3289ULL: goto x86_l_cd9;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3300ULL: goto x86_l_ce4;
	case 3305ULL: goto x86_l_ce9;
	case 3312ULL: goto x86_l_cf0;
	case 3320ULL: goto x86_l_cf8;
	case 3322ULL: goto x86_l_cfa;
	case 3325ULL: goto x86_l_cfd;
	case 3331ULL: goto x86_l_d03;
	case 3338ULL: goto x86_l_d0a;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3351ULL: goto x86_l_d17;
	case 3356ULL: goto x86_l_d1c;
	case 3360ULL: goto x86_l_d20;
	case 3362ULL: goto x86_l_d22;
	case 3364ULL: goto x86_l_d24;
	case 3366ULL: goto x86_l_d26;
	case 3369ULL: goto x86_l_d29;
	case 3371ULL: goto x86_l_d2b;
	case 3373ULL: goto x86_l_d2d;
	case 3375ULL: goto x86_l_d2f;
	case 3377ULL: goto x86_l_d31;
	case 3379ULL: goto x86_l_d33;
	case 3381ULL: goto x86_l_d35;
	case 3384ULL: goto x86_l_d38;
	case 3391ULL: goto x86_l_d3f;
	case 3395ULL: goto x86_l_d43;
	case 3398ULL: goto x86_l_d46;
	case 3405ULL: goto x86_l_d4d;
	case 3410ULL: goto x86_l_d52;
	case 3414ULL: goto x86_l_d56;
	case 3418ULL: goto x86_l_d5a;
	case 3422ULL: goto x86_l_d5e;
	case 3431ULL: goto x86_l_d67;
	case 3435ULL: goto x86_l_d6b;
	case 3439ULL: goto x86_l_d6f;
	case 3443ULL: goto x86_l_d73;
	case 3449ULL: goto x86_l_d79;
	case 3453ULL: goto x86_l_d7d;
	case 3457ULL: goto x86_l_d81;
	case 3461ULL: goto x86_l_d85;
	case 3470ULL: goto x86_l_d8e;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3483ULL: goto x86_l_d9b;
	case 3485ULL: goto x86_l_d9d;
	case 3489ULL: goto x86_l_da1;
	case 3493ULL: goto x86_l_da5;
	case 3497ULL: goto x86_l_da9;
	case 3506ULL: goto x86_l_db2;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3516ULL: goto x86_l_dbc;
	case 3518ULL: goto x86_l_dbe;
	case 3522ULL: goto x86_l_dc2;
	case 3524ULL: goto x86_l_dc4;
	case 3528ULL: goto x86_l_dc8;
	case 3532ULL: goto x86_l_dcc;
	case 3536ULL: goto x86_l_dd0;
	case 3545ULL: goto x86_l_dd9;
	case 3548ULL: goto x86_l_ddc;
	case 3552ULL: goto x86_l_de0;
	case 3556ULL: goto x86_l_de4;
	case 3560ULL: goto x86_l_de8;
	case 3564ULL: goto x86_l_dec;
	case 3568ULL: goto x86_l_df0;
	case 3574ULL: goto x86_l_df6;
	case 3582ULL: goto x86_l_dfe;
	case 3587ULL: goto x86_l_e03;
	case 3590ULL: goto x86_l_e06;
	case 3592ULL: goto x86_l_e08;
	case 3595ULL: goto x86_l_e0b;
	case 3599ULL: goto x86_l_e0f;
	case 3606ULL: goto x86_l_e16;
	case 3611ULL: goto x86_l_e1b;
	case 3613ULL: goto x86_l_e1d;
	case 3616ULL: goto x86_l_e20;
	case 3618ULL: goto x86_l_e22;
	case 3621ULL: goto x86_l_e25;
	case 3624ULL: goto x86_l_e28;
	case 3627ULL: goto x86_l_e2b;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3641ULL: goto x86_l_e39;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3652ULL: goto x86_l_e44;
	case 3656ULL: goto x86_l_e48;
	case 3660ULL: goto x86_l_e4c;
	case 3664ULL: goto x86_l_e50;
	case 3672ULL: goto x86_l_e58;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3691ULL: goto x86_l_e6b;
	case 3694ULL: goto x86_l_e6e;
	case 3698ULL: goto x86_l_e72;
	default: return 0xffffffffffffffffULL;
	}
x86_l_774:
	/* 0x774: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_779:
	/* 0x779: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_77c:
	/* 0x77c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_781:
	/* 0x781: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_783:
	/* 0x783: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_78b:
	/* 0x78b: cmp    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 88ULL);
x86_l_790:
	/* 0x790: je     85a <generic_uprobe_process_filter+0x85a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_85a;
	}
x86_l_796:
	/* 0x796: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_79a:
	/* 0x79a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_79f:
	/* 0x79f: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7a4:
	/* 0x7a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a9:
	/* 0x7a9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7ac:
	/* 0x7ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ae:
	/* 0x7ae: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7b3:
	/* 0x7b3: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7bb:
	/* 0x7bb: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7bf:
	/* 0x7bf: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7c7:
	/* 0x7c7: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_7c9:
	/* 0x7c9: jne    628 <generic_uprobe_process_filter+0x628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1576ULL;
	}
x86_l_7cf:
	/* 0x7cf: jmp    862 <generic_uprobe_process_filter+0x862> */
	goto x86_l_862;
x86_l_7d4:
	/* 0x7d4: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7d8:
	/* 0x7d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7dd:
	/* 0x7dd: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7e2:
	/* 0x7e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e7:
	/* 0x7e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e9:
	/* 0x7e9: cmp    QWORD PTR [rsp+0x60],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7ee:
	/* 0x7ee: je     535 <generic_uprobe_process_filter+0x535> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1333ULL;
	}
x86_l_7f4:
	/* 0x7f4: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7f9:
	/* 0x7f9: mov    ecx,DWORD PTR [rdx+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_7ff:
	/* 0x7ff: lea    eax,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_802:
	/* 0x802: mov    DWORD PTR [rdx+0x6410],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_808:
	/* 0x808: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_80b:
	/* 0x80b: jg     8da <generic_uprobe_process_filter+0x8da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_8da;
	}
x86_l_811:
	/* 0x811: mov    DWORD PTR [rdx+0x6414],0xffffffdc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110041357090780ULL);
x86_l_81b:
	/* 0x81b: mov    rbx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R14, X86_WIDTH_64);
x86_l_81e:
	/* 0x81e: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_821:
	/* 0x821: jmp    953 <generic_uprobe_process_filter+0x953> */
	goto x86_l_953;
x86_l_826:
	/* 0x826: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_82b:
	/* 0x82b: lea    rsi,[rip+0x30b1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 12465ULL);
x86_l_832:
	/* 0x832: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_837:
	/* 0x837: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_83c:
	/* 0x83c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_83e:
	/* 0x83e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_840:
	/* 0x840: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_848:
	/* 0x848: mov    rcx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_850:
	/* 0x850: cmp    rbx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_853:
	/* 0x853: jne    87b <generic_uprobe_process_filter+0x87b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_87b;
	}
x86_l_855:
	/* 0x855: jmp    938 <generic_uprobe_process_filter+0x938> */
	goto x86_l_938;
x86_l_85a:
	/* 0x85a: mov    BYTE PTR [rsp+0x9c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898177ULL);
x86_l_862:
	/* 0x862: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_86a:
	/* 0x86a: mov    rcx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_872:
	/* 0x872: cmp    rbx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_875:
	/* 0x875: je     938 <generic_uprobe_process_filter+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_938;
	}
x86_l_87b:
	/* 0x87b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_87d:
	/* 0x87d: cmp    BYTE PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_885:
	/* 0x885: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_888:
	/* 0x888: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_88a:
	/* 0x88a: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_891:
	/* 0x891: mov    DWORD PTR [r14+0x6410],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_898:
	/* 0x898: mov    DWORD PTR [r14+0x6414],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25620ULL);
x86_l_89f:
	/* 0x89f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8a1:
	/* 0x8a1: jle    8b3 <generic_uprobe_process_filter+0x8b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_8b3;
	}
x86_l_8a3:
	/* 0x8a3: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_8a8:
	/* 0x8a8: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8aa:
	/* 0x8aa: mov    DWORD PTR [r14+0x6410],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_8b1:
	/* 0x8b1: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_8b3:
	/* 0x8b3: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_8b6:
	/* 0x8b6: jne    953 <generic_uprobe_process_filter+0x953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_953;
	}
x86_l_8bc:
	/* 0x8bc: jmp    a4a <generic_uprobe_process_filter+0xa4a> */
	goto x86_l_a4a;
x86_l_8c1:
	/* 0x8c1: mov    DWORD PTR [r14+0x5f5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104848741629952ULL);
x86_l_8cc:
	/* 0x8cc: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_8cf:
	/* 0x8cf: je     416 <generic_uprobe_process_filter+0x416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1046ULL;
	}
x86_l_8d5:
	/* 0x8d5: jmp    41e <generic_uprobe_process_filter+0x41e> */
	return 1054ULL;
x86_l_8da:
	/* 0x8da: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_8dd:
	/* 0x8dd: add    r14,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_8e4:
	/* 0x8e4: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_8ee:
	/* 0x8ee: mov    QWORD PTR [r12+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_8f6:
	/* 0x8f6: mov    WORD PTR [r12+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_901:
	/* 0x901: jmp    535 <generic_uprobe_process_filter+0x535> */
	return 1333ULL;
x86_l_906:
	/* 0x906: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_90a:
	/* 0x90a: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_90d:
	/* 0x90d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_912:
	/* 0x912: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_915:
	/* 0x915: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_917:
	/* 0x917: mov    QWORD PTR [rsp+0x90],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_91f:
	/* 0x91f: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_927:
	/* 0x927: mov    rcx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_92f:
	/* 0x92f: cmp    rbx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_932:
	/* 0x932: jne    87b <generic_uprobe_process_filter+0x87b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_87b;
	}
x86_l_938:
	/* 0x938: mov    DWORD PTR [r14+0x6410],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882254336ULL);
x86_l_943:
	/* 0x943: mov    DWORD PTR [r14+0x6414],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110037062123520ULL);
x86_l_94e:
	/* 0x94e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_950:
	/* 0x950: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_953:
	/* 0x953: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_955:
	/* 0x955: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_958:
	/* 0x958: sub    r15d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SUB, 127ULL);
x86_l_95c:
	/* 0x95c: mov    ebp,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_961:
	/* 0x961: cmovb  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_964:
	/* 0x964: cmovb  r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_968:
	/* 0x968: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_96d:
	/* 0x96d: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_972:
	/* 0x972: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_975:
	/* 0x975: mov    DWORD PTR [r14+0x6410],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_97c:
	/* 0x97c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_981:
	/* 0x981: mov    esi,DWORD PTR [r14+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_988:
	/* 0x988: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_98d:
	/* 0x98d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_990:
	/* 0x990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_992:
	/* 0x992: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_995:
	/* 0x995: je     9f8 <generic_uprobe_process_filter+0x9f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9f8;
	}
x86_l_997:
	/* 0x997: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_999:
	/* 0x999: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_99e:
	/* 0x99e: mov    WORD PTR [rsp+0x62],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 420906795016ULL);
x86_l_9a5:
	/* 0x9a5: movabs rax,0x4000002da */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869914ULL);
x86_l_9af:
	/* 0x9af: mov    QWORD PTR [rsp+0x64],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_9b4:
	/* 0x9b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9b9:
	/* 0x9b9: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9c0:
	/* 0x9c0: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9c5:
	/* 0x9c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c7:
	/* 0x9c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9ca:
	/* 0x9ca: je     9d0 <generic_uprobe_process_filter+0x9d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9d0;
	}
x86_l_9cc:
	/* 0x9cc: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9ce:
	/* 0x9ce: jmp    9f8 <generic_uprobe_process_filter+0x9f8> */
	goto x86_l_9f8;
x86_l_9d0:
	/* 0x9d0: mov    DWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_9db:
	/* 0x9db: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9e0:
	/* 0x9e0: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9e7:
	/* 0x9e7: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9ec:
	/* 0x9ec: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_9f4:
	/* 0x9f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f6:
	/* 0x9f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f8:
	/* 0x9f8: lea    rdi,[r14+0x6390] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25488ULL);
x86_l_9ff:
	/* 0x9ff: add    rbx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a02:
	/* 0xa02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a07:
	/* 0xa07: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_a09:
	/* 0xa09: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a0c:
	/* 0xa0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0e:
	/* 0xa0e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a11:
	/* 0xa11: je     a4a <generic_uprobe_process_filter+0xa4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a4a;
	}
x86_l_a13:
	/* 0xa13: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_a15:
	/* 0xa15: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a1a:
	/* 0xa1a: mov    WORD PTR [rsp+0x62],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 420906795016ULL);
x86_l_a21:
	/* 0xa21: movabs rax,0x4000002dc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869916ULL);
x86_l_a2b:
	/* 0xa2b: mov    QWORD PTR [rsp+0x64],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_a30:
	/* 0xa30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a35:
	/* 0xa35: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a3c:
	/* 0xa3c: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a41:
	/* 0xa41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a43:
	/* 0xa43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a46:
	/* 0xa46: je     a77 <generic_uprobe_process_filter+0xa77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a77;
	}
x86_l_a48:
	/* 0xa48: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a4a:
	/* 0xa4a: mov    eax,DWORD PTR [r14+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_a51:
	/* 0xa51: lea    ecx,[rax-0x101] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551359ULL);
x86_l_a57:
	/* 0xa57: cmp    ecx,0xfffffeff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4294967039ULL);
x86_l_a5d:
	/* 0xa5d: ja     ab4 <generic_uprobe_process_filter+0xab4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ab4;
	}
x86_l_a5f:
	/* 0xa5f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a64:
	/* 0xa64: mov    DWORD PTR [rax],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_a6a:
	/* 0xa6a: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a72:
	/* 0xa72: jmp    bd4 <generic_uprobe_process_filter+0xbd4> */
	goto x86_l_bd4;
x86_l_a77:
	/* 0xa77: mov    DWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_a82:
	/* 0xa82: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a87:
	/* 0xa87: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a8e:
	/* 0xa8e: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a93:
	/* 0xa93: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a9b:
	/* 0xa9b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a9d:
	/* 0xa9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9f:
	/* 0xa9f: mov    eax,DWORD PTR [r14+0x6410] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25616ULL);
x86_l_aa6:
	/* 0xaa6: lea    ecx,[rax-0x101] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551359ULL);
x86_l_aac:
	/* 0xaac: cmp    ecx,0xfffffeff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4294967039ULL);
x86_l_ab2:
	/* 0xab2: jbe    a5f <generic_uprobe_process_filter+0xa5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_a5f;
	}
x86_l_ab4:
	/* 0xab4: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ab7:
	/* 0xab7: lea    rdi,[r14+0x5f80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24448ULL);
x86_l_abe:
	/* 0xabe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ac3:
	/* 0xac3: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_ac5:
	/* 0xac5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aca:
	/* 0xaca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_acc:
	/* 0xacc: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_acf:
	/* 0xacf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad2:
	/* 0xad2: je     b38 <generic_uprobe_process_filter+0xb38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b38;
	}
x86_l_ad4:
	/* 0xad4: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_ad7:
	/* 0xad7: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_ad9:
	/* 0xad9: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ade:
	/* 0xade: mov    WORD PTR [rsp+0x62],0xf */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 420906795023ULL);
x86_l_ae5:
	/* 0xae5: movabs rax,0x400000181 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869569ULL);
x86_l_aef:
	/* 0xaef: mov    QWORD PTR [rsp+0x64],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_af4:
	/* 0xaf4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af9:
	/* 0xaf9: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b00:
	/* 0xb00: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b05:
	/* 0xb05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b07:
	/* 0xb07: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b0a:
	/* 0xb0a: je     b10 <generic_uprobe_process_filter+0xb10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b10;
	}
x86_l_b0c:
	/* 0xb0c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b0e:
	/* 0xb0e: jmp    b38 <generic_uprobe_process_filter+0xb38> */
	goto x86_l_b38;
x86_l_b10:
	/* 0xb10: mov    DWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_b1b:
	/* 0xb1b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b20:
	/* 0xb20: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b27:
	/* 0xb27: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b2c:
	/* 0xb2c: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b34:
	/* 0xb34: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b36:
	/* 0xb36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b38:
	/* 0xb38: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_b3b:
	/* 0xb3b: cmove  r15d,ebx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RBX, X86_WIDTH_32, X86_CC_E);
x86_l_b3f:
	/* 0xb3f: mov    DWORD PTR [r14+0x5f78],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24440ULL);
x86_l_b46:
	/* 0xb46: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_b49:
	/* 0xb49: mov    esi,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 127ULL);
x86_l_b4e:
	/* 0xb4e: cmovb  esi,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_b51:
	/* 0xb51: lea    rdi,[r14+0x6080] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24704ULL);
x86_l_b58:
	/* 0xb58: lea    rdx,[r14+0x6390] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25488ULL);
x86_l_b5f:
	/* 0xb5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b64:
	/* 0xb64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b66:
	/* 0xb66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b69:
	/* 0xb69: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_b71:
	/* 0xb71: je     bd4 <generic_uprobe_process_filter+0xbd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bd4;
	}
x86_l_b73:
	/* 0xb73: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_b75:
	/* 0xb75: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b7a:
	/* 0xb7a: mov    WORD PTR [rsp+0x62],0xf */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 420906795023ULL);
x86_l_b81:
	/* 0xb81: movabs rax,0x400000187 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869575ULL);
x86_l_b8b:
	/* 0xb8b: mov    QWORD PTR [rsp+0x64],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_b90:
	/* 0xb90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b95:
	/* 0xb95: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b9c:
	/* 0xb9c: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ba1:
	/* 0xba1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba3:
	/* 0xba3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ba6:
	/* 0xba6: je     bac <generic_uprobe_process_filter+0xbac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bac;
	}
x86_l_ba8:
	/* 0xba8: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_baa:
	/* 0xbaa: jmp    bd4 <generic_uprobe_process_filter+0xbd4> */
	goto x86_l_bd4;
x86_l_bac:
	/* 0xbac: mov    DWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_bb7:
	/* 0xbb7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bbc:
	/* 0xbbc: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_bc3:
	/* 0xbc3: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bc8:
	/* 0xbc8: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_bd0:
	/* 0xbd0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd2:
	/* 0xbd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd4:
	/* 0xbd4: lea    r15,[r14+0x5f10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24336ULL);
x86_l_bdb:
	/* 0xbdb: or     BYTE PTR [r14+0x1],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967312ULL);
x86_l_be0:
	/* 0xbe0: lea    rsi,[r14+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_be7:
	/* 0xbe7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bec:
	/* 0xbec: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_bf3:
	/* 0xbf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf5:
	/* 0xbf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bf8:
	/* 0xbf8: je     2290 <generic_uprobe_process_filter+0x2290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8848ULL;
	}
x86_l_bfe:
	/* 0xbfe: mov    rbp,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_c05:
	/* 0xc05: cmp    rbp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 6ULL);
x86_l_c09:
	/* 0xc09: jae    e41 <generic_uprobe_process_filter+0xe41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e41;
	}
x86_l_c0f:
	/* 0xc0f: movsxd rcx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_c12:
	/* 0xc12: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_c15:
	/* 0xc15: je     e63 <generic_uprobe_process_filter+0xe63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e63;
	}
x86_l_c1b:
	/* 0xc1b: cmp    rbp,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_c1e:
	/* 0xc1e: jae    e41 <generic_uprobe_process_filter+0xe41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e41;
	}
x86_l_c24:
	/* 0xc24: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c29:
	/* 0xc29: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c31:
	/* 0xc31: mov    QWORD PTR [rsp+0xb8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c39:
	/* 0xc39: mov    DWORD PTR [rsp+0x58],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c3d:
	/* 0xc3d: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_c48:
	/* 0xc48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c4d:
	/* 0xc4d: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_sel_opts)));
x86_l_c54:
	/* 0xc54: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c59:
	/* 0xc59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5b:
	/* 0xc5b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c5e:
	/* 0xc5e: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c63:
	/* 0xc63: je     e7f <generic_uprobe_process_filter+0xe7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3711ULL;
	}
x86_l_c69:
	/* 0xc69: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_c6c:
	/* 0xc6c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6e:
	/* 0xc6e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c70:
	/* 0xc70: je     e7f <generic_uprobe_process_filter+0xe7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3711ULL;
	}
x86_l_c76:
	/* 0xc76: cmp    DWORD PTR [r15+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_c7b:
	/* 0xc7b: js     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8765ULL;
	}
x86_l_c81:
	/* 0xc81: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c84:
	/* 0xc84: ja     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8765ULL;
	}
x86_l_c8a:
	/* 0xc8a: mov    ecx,0x60 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 96ULL);
x86_l_c8f:
	/* 0xc8f: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_c92:
	/* 0xc92: jb     19e9 <generic_uprobe_process_filter+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6633ULL;
	}
x86_l_c98:
	/* 0xc98: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_c9d:
	/* 0xc9d: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ca0:
	/* 0xca0: jb     195c <generic_uprobe_process_filter+0x195c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6492ULL;
	}
x86_l_ca6:
	/* 0xca6: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_cab:
	/* 0xcab: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_cae:
	/* 0xcae: jae    223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8765ULL;
	}
x86_l_cb4:
	/* 0xcb4: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_cb7:
	/* 0xcb7: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_cbb:
	/* 0xcbb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cc0:
	/* 0xcc0: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_cc7:
	/* 0xcc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc9:
	/* 0xcc9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ccc:
	/* 0xccc: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_cd2:
	/* 0xcd2: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_cd5:
	/* 0xcd5: mov    eax,DWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_cd9:
	/* 0xcd9: cmp    eax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_cdc:
	/* 0xcdc: mov    ebx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_ce1:
	/* 0xce1: cmovl  ebx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RAX, X86_WIDTH_32, X86_CC_L);
x86_l_ce4:
	/* 0xce4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce9:
	/* 0xce9: mov    rdi,QWORD PTR [rip+0x30b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_cf0:
	/* 0xcf0: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_cf8:
	/* 0xcf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cfa:
	/* 0xcfa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cfd:
	/* 0xcfd: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_d03:
	/* 0xd03: lea    ecx,[rbx*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 3), 0ULL);
x86_l_d0a:
	/* 0xd0a: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d0c:
	/* 0xd0c: cmp    DWORD PTR [r15+0x6c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467968ULL);
x86_l_d11:
	/* 0xd11: jne    e03 <generic_uprobe_process_filter+0xe03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e03;
	}
x86_l_d17:
	/* 0xd17: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d1c:
	/* 0xd1c: mov    edx,DWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d20:
	/* 0xd20: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_d22:
	/* 0xd22: sub    ecx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_d24:
	/* 0xd24: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_d26:
	/* 0xd26: and    esi,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_d29:
	/* 0xd29: add    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d2b:
	/* 0xd2b: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d2d:
	/* 0xd2d: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_d2f:
	/* 0xd2f: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d31:
	/* 0xd31: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d33:
	/* 0xd33: sub    esi,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_d35:
	/* 0xd35: lea    edi,[rsi-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_d38:
	/* 0xd38: lea    r8,[r15+0x1f3] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 499ULL);
x86_l_d3f:
	/* 0xd3f: lea    r9d,[rsi-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_d43:
	/* 0xd43: add    esi,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 4294967294ULL);
x86_l_d46:
	/* 0xd46: mov    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_d4d:
	/* 0xd4d: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d52:
	/* 0xd52: lea    r11d,[rdx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_d56:
	/* 0xd56: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_d5a:
	/* 0xd5a: and    r11d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_d5e:
	/* 0xd5e: movzx  r11d,BYTE PTR [r15+r11*1+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 368ULL);
x86_l_d67:
	/* 0xd67: mov    BYTE PTR [r8-0x3],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_d6b:
	/* 0xd6b: lea    r11,[rcx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_d6f:
	/* 0xd6f: cmp    r11,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_d73:
	/* 0xd73: je     df6 <generic_uprobe_process_filter+0xdf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df6;
	}
x86_l_d79:
	/* 0xd79: lea    r15d,[rsi+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_d7d:
	/* 0xd7d: add    r15d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_d81:
	/* 0xd81: and    r15d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_d85:
	/* 0xd85: movzx  r15d,BYTE PTR [r12+r15*1+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_8), 368ULL);
x86_l_d8e:
	/* 0xd8e: mov    BYTE PTR [r8-0x2],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_d92:
	/* 0xd92: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d97:
	/* 0xd97: cmp    r11,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d9b:
	/* 0xd9b: je     df6 <generic_uprobe_process_filter+0xdf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df6;
	}
x86_l_d9d:
	/* 0xd9d: lea    r11d,[r9+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_da1:
	/* 0xda1: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_da5:
	/* 0xda5: and    r11d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_da9:
	/* 0xda9: movzx  r11d,BYTE PTR [r15+r11*1+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 368ULL);
x86_l_db2:
	/* 0xdb2: mov    BYTE PTR [r8-0x1],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_db6:
	/* 0xdb6: mov    r11,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RCX, X86_WIDTH_64);
x86_l_db9:
	/* 0xdb9: add    r11,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dbc:
	/* 0xdbc: je     df6 <generic_uprobe_process_filter+0xdf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df6;
	}
x86_l_dbe:
	/* 0xdbe: cmp    r10,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_dc2:
	/* 0xdc2: je     df6 <generic_uprobe_process_filter+0xdf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df6;
	}
x86_l_dc4:
	/* 0xdc4: lea    r11d,[rdi+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_dc8:
	/* 0xdc8: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_dcc:
	/* 0xdcc: and    r11d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_dd0:
	/* 0xdd0: movzx  r11d,BYTE PTR [r15+r11*1+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 368ULL);
x86_l_dd9:
	/* 0xdd9: mov    BYTE PTR [r8],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ddc:
	/* 0xddc: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_de0:
	/* 0xde0: lea    r11,[rcx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_de4:
	/* 0xde4: add    r11,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_de8:
	/* 0xde8: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_dec:
	/* 0xdec: cmp    r11,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_df0:
	/* 0xdf0: jne    d52 <generic_uprobe_process_filter+0xd52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d52;
	}
x86_l_df6:
	/* 0xdf6: mov    DWORD PTR [r15+0x6c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467969ULL);
x86_l_dfe:
	/* 0xdfe: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e03:
	/* 0xe03: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_e06:
	/* 0xe06: ja     e31 <generic_uprobe_process_filter+0xe31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e31;
	}
x86_l_e08:
	/* 0xe08: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e0b:
	/* 0xe0b: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_e0f:
	/* 0xe0f: lea    rdx,[r15+0x1f0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_e16:
	/* 0xe16: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e1b:
	/* 0xe1b: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_e1d:
	/* 0xe1d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_e20:
	/* 0xe20: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e22:
	/* 0xe22: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_e25:
	/* 0xe25: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_e28:
	/* 0xe28: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_e2b:
	/* 0xe2b: js     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8765ULL;
	}
x86_l_e31:
	/* 0xe31: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e36:
	/* 0xe36: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_e39:
	/* 0xe39: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e3c:
	/* 0xe3c: jmp    1dd5 <generic_uprobe_process_filter+0x1dd5> */
	return 7637ULL;
x86_l_e41:
	/* 0xe41: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e44:
	/* 0xe44: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e48:
	/* 0xe48: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e4c:
	/* 0xe4c: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e50:
	/* 0xe50: cmp    BYTE PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_e58:
	/* 0xe58: jne    227d <generic_uprobe_process_filter+0x227d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8829ULL;
	}
x86_l_e5e:
	/* 0xe5e: jmp    2290 <generic_uprobe_process_filter+0x2290> */
	return 8848ULL;
x86_l_e63:
	/* 0xe63: mov    BYTE PTR [r14+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_e6b:
	/* 0xe6b: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6e:
	/* 0xe6e: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e72:
	/* 0xe72: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 3702ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3702ULL: goto x86_l_e76;
	case 3706ULL: goto x86_l_e7a;
	case 3711ULL: goto x86_l_e7f;
	case 3716ULL: goto x86_l_e84;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	case 3732ULL: goto x86_l_e94;
	case 3737ULL: goto x86_l_e99;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3765ULL: goto x86_l_eb5;
	case 3768ULL: goto x86_l_eb8;
	case 3771ULL: goto x86_l_ebb;
	case 3775ULL: goto x86_l_ebf;
	case 3786ULL: goto x86_l_eca;
	case 3791ULL: goto x86_l_ecf;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3805ULL: goto x86_l_edd;
	case 3808ULL: goto x86_l_ee0;
	case 3814ULL: goto x86_l_ee6;
	case 3817ULL: goto x86_l_ee9;
	case 3819ULL: goto x86_l_eeb;
	case 3821ULL: goto x86_l_eed;
	case 3827ULL: goto x86_l_ef3;
	case 3832ULL: goto x86_l_ef8;
	case 3838ULL: goto x86_l_efe;
	case 3841ULL: goto x86_l_f01;
	case 3847ULL: goto x86_l_f07;
	case 3852ULL: goto x86_l_f0c;
	case 3855ULL: goto x86_l_f0f;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3869ULL: goto x86_l_f1d;
	case 3875ULL: goto x86_l_f23;
	case 3880ULL: goto x86_l_f28;
	case 3883ULL: goto x86_l_f2b;
	case 3889ULL: goto x86_l_f31;
	case 3892ULL: goto x86_l_f34;
	case 3896ULL: goto x86_l_f38;
	case 3901ULL: goto x86_l_f3d;
	case 3908ULL: goto x86_l_f44;
	case 3910ULL: goto x86_l_f46;
	case 3913ULL: goto x86_l_f49;
	case 3919ULL: goto x86_l_f4f;
	case 3922ULL: goto x86_l_f52;
	case 3926ULL: goto x86_l_f56;
	case 3929ULL: goto x86_l_f59;
	case 3934ULL: goto x86_l_f5e;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3949ULL: goto x86_l_f6d;
	case 3957ULL: goto x86_l_f75;
	case 3959ULL: goto x86_l_f77;
	case 3962ULL: goto x86_l_f7a;
	case 3968ULL: goto x86_l_f80;
	case 3975ULL: goto x86_l_f87;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3988ULL: goto x86_l_f94;
	case 3993ULL: goto x86_l_f99;
	case 3997ULL: goto x86_l_f9d;
	case 3999ULL: goto x86_l_f9f;
	case 4001ULL: goto x86_l_fa1;
	case 4003ULL: goto x86_l_fa3;
	case 4006ULL: goto x86_l_fa6;
	case 4008ULL: goto x86_l_fa8;
	case 4010ULL: goto x86_l_faa;
	case 4012ULL: goto x86_l_fac;
	case 4014ULL: goto x86_l_fae;
	case 4016ULL: goto x86_l_fb0;
	case 4018ULL: goto x86_l_fb2;
	case 4021ULL: goto x86_l_fb5;
	case 4028ULL: goto x86_l_fbc;
	case 4032ULL: goto x86_l_fc0;
	case 4035ULL: goto x86_l_fc3;
	case 4042ULL: goto x86_l_fca;
	case 4046ULL: goto x86_l_fce;
	case 4050ULL: goto x86_l_fd2;
	case 4054ULL: goto x86_l_fd6;
	case 4063ULL: goto x86_l_fdf;
	case 4067ULL: goto x86_l_fe3;
	case 4071ULL: goto x86_l_fe7;
	case 4075ULL: goto x86_l_feb;
	case 4077ULL: goto x86_l_fed;
	case 4081ULL: goto x86_l_ff1;
	case 4085ULL: goto x86_l_ff5;
	case 4089ULL: goto x86_l_ff9;
	case 4098ULL: goto x86_l_1002;
	case 4102ULL: goto x86_l_1006;
	case 4106ULL: goto x86_l_100a;
	case 4108ULL: goto x86_l_100c;
	case 4112ULL: goto x86_l_1010;
	case 4116ULL: goto x86_l_1014;
	case 4120ULL: goto x86_l_1018;
	case 4129ULL: goto x86_l_1021;
	case 4133ULL: goto x86_l_1025;
	case 4136ULL: goto x86_l_1028;
	case 4139ULL: goto x86_l_102b;
	case 4141ULL: goto x86_l_102d;
	case 4145ULL: goto x86_l_1031;
	case 4147ULL: goto x86_l_1033;
	case 4151ULL: goto x86_l_1037;
	case 4155ULL: goto x86_l_103b;
	case 4159ULL: goto x86_l_103f;
	case 4168ULL: goto x86_l_1048;
	case 4171ULL: goto x86_l_104b;
	case 4175ULL: goto x86_l_104f;
	case 4179ULL: goto x86_l_1053;
	case 4183ULL: goto x86_l_1057;
	case 4187ULL: goto x86_l_105b;
	case 4191ULL: goto x86_l_105f;
	case 4197ULL: goto x86_l_1065;
	case 4205ULL: goto x86_l_106d;
	case 4210ULL: goto x86_l_1072;
	case 4213ULL: goto x86_l_1075;
	case 4215ULL: goto x86_l_1077;
	case 4218ULL: goto x86_l_107a;
	case 4222ULL: goto x86_l_107e;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4236ULL: goto x86_l_108c;
	case 4239ULL: goto x86_l_108f;
	case 4242ULL: goto x86_l_1092;
	case 4244ULL: goto x86_l_1094;
	case 4247ULL: goto x86_l_1097;
	case 4250ULL: goto x86_l_109a;
	case 4253ULL: goto x86_l_109d;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4267ULL: goto x86_l_10ab;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4280ULL: goto x86_l_10b8;
	case 4282ULL: goto x86_l_10ba;
	case 4290ULL: goto x86_l_10c2;
	case 4295ULL: goto x86_l_10c7;
	case 4298ULL: goto x86_l_10ca;
	case 4304ULL: goto x86_l_10d0;
	case 4306ULL: goto x86_l_10d2;
	case 4309ULL: goto x86_l_10d5;
	case 4315ULL: goto x86_l_10db;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4330ULL: goto x86_l_10ea;
	case 4338ULL: goto x86_l_10f2;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4352ULL: goto x86_l_1100;
	case 4361ULL: goto x86_l_1109;
	case 4370ULL: goto x86_l_1112;
	case 4373ULL: goto x86_l_1115;
	case 4378ULL: goto x86_l_111a;
	case 4381ULL: goto x86_l_111d;
	case 4384ULL: goto x86_l_1120;
	case 4386ULL: goto x86_l_1122;
	case 4396ULL: goto x86_l_112c;
	case 4401ULL: goto x86_l_1131;
	case 4406ULL: goto x86_l_1136;
	case 4408ULL: goto x86_l_1138;
	case 4413ULL: goto x86_l_113d;
	case 4419ULL: goto x86_l_1143;
	case 4423ULL: goto x86_l_1147;
	case 4427ULL: goto x86_l_114b;
	case 4430ULL: goto x86_l_114e;
	case 4434ULL: goto x86_l_1152;
	case 4438ULL: goto x86_l_1156;
	case 4446ULL: goto x86_l_115e;
	case 4449ULL: goto x86_l_1161;
	case 4452ULL: goto x86_l_1164;
	case 4458ULL: goto x86_l_116a;
	case 4462ULL: goto x86_l_116e;
	case 4465ULL: goto x86_l_1171;
	case 4469ULL: goto x86_l_1175;
	case 4474ULL: goto x86_l_117a;
	case 4478ULL: goto x86_l_117e;
	case 4480ULL: goto x86_l_1180;
	case 4483ULL: goto x86_l_1183;
	case 4486ULL: goto x86_l_1186;
	case 4489ULL: goto x86_l_1189;
	case 4491ULL: goto x86_l_118b;
	case 4499ULL: goto x86_l_1193;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4537ULL: goto x86_l_11b9;
	case 4542ULL: goto x86_l_11be;
	case 4547ULL: goto x86_l_11c3;
	case 4551ULL: goto x86_l_11c7;
	case 4556ULL: goto x86_l_11cc;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4579ULL: goto x86_l_11e3;
	case 4582ULL: goto x86_l_11e6;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4601ULL: goto x86_l_11f9;
	case 4604ULL: goto x86_l_11fc;
	case 4610ULL: goto x86_l_1202;
	case 4614ULL: goto x86_l_1206;
	case 4620ULL: goto x86_l_120c;
	case 4626ULL: goto x86_l_1212;
	case 4629ULL: goto x86_l_1215;
	case 4633ULL: goto x86_l_1219;
	case 4639ULL: goto x86_l_121f;
	case 4643ULL: goto x86_l_1223;
	case 4649ULL: goto x86_l_1229;
	case 4651ULL: goto x86_l_122b;
	case 4654ULL: goto x86_l_122e;
	case 4657ULL: goto x86_l_1231;
	case 4659ULL: goto x86_l_1233;
	case 4662ULL: goto x86_l_1236;
	case 4665ULL: goto x86_l_1239;
	case 4667ULL: goto x86_l_123b;
	case 4672ULL: goto x86_l_1240;
	case 4679ULL: goto x86_l_1247;
	case 4687ULL: goto x86_l_124f;
	case 4689ULL: goto x86_l_1251;
	case 4692ULL: goto x86_l_1254;
	case 4698ULL: goto x86_l_125a;
	case 4700ULL: goto x86_l_125c;
	case 4703ULL: goto x86_l_125f;
	case 4709ULL: goto x86_l_1265;
	case 4712ULL: goto x86_l_1268;
	case 4715ULL: goto x86_l_126b;
	case 4721ULL: goto x86_l_1271;
	case 4725ULL: goto x86_l_1275;
	case 4730ULL: goto x86_l_127a;
	case 4737ULL: goto x86_l_1281;
	case 4740ULL: goto x86_l_1284;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4751ULL: goto x86_l_128f;
	case 4753ULL: goto x86_l_1291;
	case 4756ULL: goto x86_l_1294;
	case 4762ULL: goto x86_l_129a;
	case 4765ULL: goto x86_l_129d;
	case 4768ULL: goto x86_l_12a0;
	case 4774ULL: goto x86_l_12a6;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4790ULL: goto x86_l_12b6;
	case 4793ULL: goto x86_l_12b9;
	case 4795ULL: goto x86_l_12bb;
	case 4798ULL: goto x86_l_12be;
	case 4804ULL: goto x86_l_12c4;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4815ULL: goto x86_l_12cf;
	case 4818ULL: goto x86_l_12d2;
	case 4821ULL: goto x86_l_12d5;
	case 4827ULL: goto x86_l_12db;
	case 4831ULL: goto x86_l_12df;
	case 4836ULL: goto x86_l_12e4;
	case 4843ULL: goto x86_l_12eb;
	case 4846ULL: goto x86_l_12ee;
	case 4848ULL: goto x86_l_12f0;
	case 4851ULL: goto x86_l_12f3;
	case 4857ULL: goto x86_l_12f9;
	case 4859ULL: goto x86_l_12fb;
	case 4862ULL: goto x86_l_12fe;
	case 4868ULL: goto x86_l_1304;
	case 4871ULL: goto x86_l_1307;
	case 4874ULL: goto x86_l_130a;
	case 4880ULL: goto x86_l_1310;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4896ULL: goto x86_l_1320;
	case 4899ULL: goto x86_l_1323;
	case 4901ULL: goto x86_l_1325;
	case 4904ULL: goto x86_l_1328;
	case 4910ULL: goto x86_l_132e;
	case 4912ULL: goto x86_l_1330;
	case 4915ULL: goto x86_l_1333;
	case 4921ULL: goto x86_l_1339;
	case 4924ULL: goto x86_l_133c;
	case 4927ULL: goto x86_l_133f;
	case 4933ULL: goto x86_l_1345;
	case 4937ULL: goto x86_l_1349;
	case 4942ULL: goto x86_l_134e;
	case 4949ULL: goto x86_l_1355;
	case 4952ULL: goto x86_l_1358;
	case 4954ULL: goto x86_l_135a;
	case 4957ULL: goto x86_l_135d;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4970ULL: goto x86_l_136a;
	case 4973ULL: goto x86_l_136d;
	case 4979ULL: goto x86_l_1373;
	case 4982ULL: goto x86_l_1376;
	case 4985ULL: goto x86_l_1379;
	case 4991ULL: goto x86_l_137f;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5007ULL: goto x86_l_138f;
	case 5010ULL: goto x86_l_1392;
	case 5012ULL: goto x86_l_1394;
	case 5015ULL: goto x86_l_1397;
	case 5020ULL: goto x86_l_139c;
	case 5025ULL: goto x86_l_13a1;
	case 5031ULL: goto x86_l_13a7;
	case 5033ULL: goto x86_l_13a9;
	case 5036ULL: goto x86_l_13ac;
	case 5042ULL: goto x86_l_13b2;
	case 5045ULL: goto x86_l_13b5;
	case 5048ULL: goto x86_l_13b8;
	case 5054ULL: goto x86_l_13be;
	case 5058ULL: goto x86_l_13c2;
	case 5063ULL: goto x86_l_13c7;
	case 5070ULL: goto x86_l_13ce;
	case 5073ULL: goto x86_l_13d1;
	case 5075ULL: goto x86_l_13d3;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5088ULL: goto x86_l_13e0;
	case 5094ULL: goto x86_l_13e6;
	case 5096ULL: goto x86_l_13e8;
	case 5099ULL: goto x86_l_13eb;
	case 5105ULL: goto x86_l_13f1;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5130ULL: goto x86_l_140a;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5150ULL: goto x86_l_141e;
	case 5155ULL: goto x86_l_1423;
	case 5160ULL: goto x86_l_1428;
	case 5166ULL: goto x86_l_142e;
	case 5170ULL: goto x86_l_1432;
	case 5175ULL: goto x86_l_1437;
	case 5180ULL: goto x86_l_143c;
	case 5184ULL: goto x86_l_1440;
	case 5188ULL: goto x86_l_1444;
	case 5194ULL: goto x86_l_144a;
	case 5196ULL: goto x86_l_144c;
	case 5199ULL: goto x86_l_144f;
	case 5201ULL: goto x86_l_1451;
	case 5204ULL: goto x86_l_1454;
	case 5210ULL: goto x86_l_145a;
	case 5213ULL: goto x86_l_145d;
	case 5216ULL: goto x86_l_1460;
	case 5219ULL: goto x86_l_1463;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5231ULL: goto x86_l_146f;
	case 5234ULL: goto x86_l_1472;
	case 5240ULL: goto x86_l_1478;
	case 5243ULL: goto x86_l_147b;
	case 5246ULL: goto x86_l_147e;
	case 5252ULL: goto x86_l_1484;
	case 5255ULL: goto x86_l_1487;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5273ULL: goto x86_l_1499;
	case 5281ULL: goto x86_l_14a1;
	case 5283ULL: goto x86_l_14a3;
	case 5286ULL: goto x86_l_14a6;
	case 5292ULL: goto x86_l_14ac;
	case 5295ULL: goto x86_l_14af;
	case 5298ULL: goto x86_l_14b2;
	case 5304ULL: goto x86_l_14b8;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5320ULL: goto x86_l_14c8;
	case 5323ULL: goto x86_l_14cb;
	case 5325ULL: goto x86_l_14cd;
	case 5328ULL: goto x86_l_14d0;
	case 5334ULL: goto x86_l_14d6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e76:
	/* 0xe76: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e7a:
	/* 0xe7a: jmp    227d <generic_uprobe_process_filter+0x227d> */
	return 8829ULL;
x86_l_e7f:
	/* 0xe7f: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e84:
	/* 0xe84: mov    rax,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&PARENTS_MAP_ENABLED)));
x86_l_e8b:
	/* 0xe8b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e8e:
	/* 0xe8e: je     10b8 <generic_uprobe_process_filter+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b8;
	}
x86_l_e94:
	/* 0xe94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e99:
	/* 0xe99: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_parents_bin)));
x86_l_ea0:
	/* 0xea0: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ea5:
	/* 0xea5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea7:
	/* 0xea7: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eac:
	/* 0xeac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eaf:
	/* 0xeaf: je     10b8 <generic_uprobe_process_filter+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b8;
	}
x86_l_eb5:
	/* 0xeb5: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_eb8:
	/* 0xeb8: lea    eax,[rbp+0x5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_ebb:
	/* 0xebb: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ebf:
	/* 0xebf: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_eca:
	/* 0xeca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ecf:
	/* 0xecf: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_sel_opts)));
x86_l_ed6:
	/* 0xed6: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_edb:
	/* 0xedb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_edd:
	/* 0xedd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ee0:
	/* 0xee0: je     10b3 <generic_uprobe_process_filter+0x10b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b3;
	}
x86_l_ee6:
	/* 0xee6: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_ee9:
	/* 0xee9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eeb:
	/* 0xeeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eed:
	/* 0xeed: je     10b3 <generic_uprobe_process_filter+0x10b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b3;
	}
x86_l_ef3:
	/* 0xef3: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef8:
	/* 0xef8: js     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8765ULL;
	}
x86_l_efe:
	/* 0xefe: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_f01:
	/* 0xf01: ja     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8765ULL;
	}
x86_l_f07:
	/* 0xf07: mov    ecx,0x60 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 96ULL);
x86_l_f0c:
	/* 0xf0c: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f0f:
	/* 0xf0f: jb     1c38 <generic_uprobe_process_filter+0x1c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7224ULL;
	}
x86_l_f15:
	/* 0xf15: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_f1a:
	/* 0xf1a: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f1d:
	/* 0xf1d: jb     1ba8 <generic_uprobe_process_filter+0x1ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7080ULL;
	}
x86_l_f23:
	/* 0xf23: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_f28:
	/* 0xf28: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f2b:
	/* 0xf2b: jae    223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8765ULL;
	}
x86_l_f31:
	/* 0xf31: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_f34:
	/* 0xf34: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_f38:
	/* 0xf38: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f3d:
	/* 0xf3d: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_f44:
	/* 0xf44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f46:
	/* 0xf46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f49:
	/* 0xf49: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_f4f:
	/* 0xf4f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f52:
	/* 0xf52: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f56:
	/* 0xf56: cmp    eax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_f59:
	/* 0xf59: mov    ebx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_f5e:
	/* 0xf5e: cmovl  ebx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RAX, X86_WIDTH_32, X86_CC_L);
x86_l_f61:
	/* 0xf61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f66:
	/* 0xf66: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_f6d:
	/* 0xf6d: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f75:
	/* 0xf75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f77:
	/* 0xf77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7a:
	/* 0xf7a: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_f80:
	/* 0xf80: lea    ecx,[rbx*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 3), 0ULL);
x86_l_f87:
	/* 0xf87: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f89:
	/* 0xf89: cmp    DWORD PTR [r13+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_f8e:
	/* 0xf8e: jne    1072 <generic_uprobe_process_filter+0x1072> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1072;
	}
x86_l_f94:
	/* 0xf94: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f99:
	/* 0xf99: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9d:
	/* 0xf9d: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_f9f:
	/* 0xf9f: sub    ecx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fa1:
	/* 0xfa1: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_fa3:
	/* 0xfa3: and    esi,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_fa6:
	/* 0xfa6: add    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fa8:
	/* 0xfa8: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_faa:
	/* 0xfaa: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_fac:
	/* 0xfac: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_fae:
	/* 0xfae: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fb0:
	/* 0xfb0: sub    esi,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fb2:
	/* 0xfb2: lea    edi,[rsi-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_fb5:
	/* 0xfb5: lea    r8,[r13+0x18b] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 395ULL);
x86_l_fbc:
	/* 0xfbc: lea    r9d,[rsi-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_fc0:
	/* 0xfc0: add    esi,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 4294967294ULL);
x86_l_fc3:
	/* 0xfc3: mov    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_fca:
	/* 0xfca: lea    r11d,[rdx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_fce:
	/* 0xfce: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_fd2:
	/* 0xfd2: and    r11d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_fd6:
	/* 0xfd6: movzx  r11d,BYTE PTR [r13+r11*1+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 264ULL);
x86_l_fdf:
	/* 0xfdf: mov    BYTE PTR [r8-0x3],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_fe3:
	/* 0xfe3: lea    r11,[rcx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_fe7:
	/* 0xfe7: cmp    r11,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_feb:
	/* 0xfeb: je     1065 <generic_uprobe_process_filter+0x1065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1065;
	}
x86_l_fed:
	/* 0xfed: lea    r15d,[rsi+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_ff1:
	/* 0xff1: add    r15d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_ff5:
	/* 0xff5: and    r15d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_ff9:
	/* 0xff9: movzx  r15d,BYTE PTR [r13+r15*1+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_8), 264ULL);
x86_l_1002:
	/* 0x1002: mov    BYTE PTR [r8-0x2],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1006:
	/* 0x1006: cmp    r11,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_100a:
	/* 0x100a: je     1065 <generic_uprobe_process_filter+0x1065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1065;
	}
x86_l_100c:
	/* 0x100c: lea    r11d,[r9+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_1010:
	/* 0x1010: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1014:
	/* 0x1014: and    r11d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_1018:
	/* 0x1018: movzx  r11d,BYTE PTR [r13+r11*1+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 264ULL);
x86_l_1021:
	/* 0x1021: mov    BYTE PTR [r8-0x1],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1025:
	/* 0x1025: mov    r11,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RCX, X86_WIDTH_64);
x86_l_1028:
	/* 0x1028: add    r11,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_ADD);
x86_l_102b:
	/* 0x102b: je     1065 <generic_uprobe_process_filter+0x1065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1065;
	}
x86_l_102d:
	/* 0x102d: cmp    r10,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_1031:
	/* 0x1031: je     1065 <generic_uprobe_process_filter+0x1065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1065;
	}
x86_l_1033:
	/* 0x1033: lea    r11d,[rdi+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_1037:
	/* 0x1037: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_103b:
	/* 0x103b: and    r11d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_103f:
	/* 0x103f: movzx  r11d,BYTE PTR [r13+r11*1+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 264ULL);
x86_l_1048:
	/* 0x1048: mov    BYTE PTR [r8],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104b:
	/* 0x104b: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_104f:
	/* 0x104f: lea    r11,[rcx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_1053:
	/* 0x1053: add    r11,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1057:
	/* 0x1057: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_105b:
	/* 0x105b: cmp    r11,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_105f:
	/* 0x105f: jne    fca <generic_uprobe_process_filter+0xfca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fca;
	}
x86_l_1065:
	/* 0x1065: mov    DWORD PTR [r13+0x4],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_106d:
	/* 0x106d: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1072:
	/* 0x1072: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_1075:
	/* 0x1075: ja     10a3 <generic_uprobe_process_filter+0x10a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10a3;
	}
x86_l_1077:
	/* 0x1077: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_107a:
	/* 0x107a: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_107e:
	/* 0x107e: add    r13,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_1085:
	/* 0x1085: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_108a:
	/* 0x108a: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_108c:
	/* 0x108c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_108f:
	/* 0x108f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1092:
	/* 0x1092: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1094:
	/* 0x1094: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1097:
	/* 0x1097: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_109a:
	/* 0x109a: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_109d:
	/* 0x109d: js     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8765ULL;
	}
x86_l_10a3:
	/* 0x10a3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10a8:
	/* 0x10a8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_10ab:
	/* 0x10ab: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_10ae:
	/* 0x10ae: jmp    1faf <generic_uprobe_process_filter+0x1faf> */
	return 8111ULL;
x86_l_10b3:
	/* 0x10b3: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b8:
	/* 0x10b8: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_10ba:
	/* 0x10ba: lea    rcx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_10c2:
	/* 0x10c2: mov    eax,DWORD PTR [r9+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_10c7:
	/* 0x10c7: lea    edx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_10ca:
	/* 0x10ca: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_10d0:
	/* 0x10d0: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10d2:
	/* 0x10d2: add    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_10d5:
	/* 0x10d5: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_10db:
	/* 0x10db: lea    r10,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10df:
	/* 0x10df: cmp    DWORD PTR [rcx+r9*1],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 5ULL);
x86_l_10e4:
	/* 0x10e4: jb     16a7 <generic_uprobe_process_filter+0x16a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5799ULL;
	}
x86_l_10ea:
	/* 0x10ea: mov    QWORD PTR [rsp+0xd0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_10f2:
	/* 0x10f2: mov    edi,DWORD PTR [r10+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_10f6:
	/* 0x10f6: mov    r8d,DWORD PTR [r10+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_10fb:
	/* 0x10fb: mov    edx,DWORD PTR [r10+r9*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 8ULL);
x86_l_1100:
	/* 0x1100: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1109:
	/* 0x1109: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1112:
	/* 0x1112: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1115:
	/* 0x1115: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_111a:
	/* 0x111a: cmovb  ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_B);
x86_l_111d:
	/* 0x111d: cmp    edi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_1120:
	/* 0x1120: jne    1136 <generic_uprobe_process_filter+0x1136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1136;
	}
x86_l_1122:
	/* 0x1122: movabs rsi,0x100000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 4294967297ULL);
x86_l_112c:
	/* 0x112c: mov    QWORD PTR [rsp+0x60],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1131:
	/* 0x1131: mov    QWORD PTR [rsp+0x68],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1136:
	/* 0x1136: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1138:
	/* 0x1138: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_113d:
	/* 0x113d: je     16ae <generic_uprobe_process_filter+0x16ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5806ULL;
	}
x86_l_1143:
	/* 0x1143: lea    rdx,[rbx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1147:
	/* 0x1147: test   r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_114b:
	/* 0x114b: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_114e:
	/* 0x114e: cmove  rdx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBX, X86_WIDTH_64, X86_CC_E);
x86_l_1152:
	/* 0x1152: lea    rsi,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1156:
	/* 0x1156: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_115e:
	/* 0x115e: lea    esi,[rax+rbp*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_1161:
	/* 0x1161: add    esi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1164:
	/* 0x1164: and    esi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_116a:
	/* 0x116a: add    rsi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_116e:
	/* 0x116e: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1171:
	/* 0x1171: cmp    rcx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 3ULL);
x86_l_1175:
	/* 0x1175: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_117a:
	/* 0x117a: cmovb  rax,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_117e:
	/* 0x117e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1180:
	/* 0x1180: and    ecx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1183:
	/* 0x1183: mov    r11,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_64);
x86_l_1186:
	/* 0x1186: add    r11,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1189:
	/* 0x1189: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_118b:
	/* 0x118b: lea    rcx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_1193:
	/* 0x1193: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1195:
	/* 0x1195: mov    QWORD PTR [rsp+0x18],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_119a:
	/* 0x119a: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_119e:
	/* 0x119e: mov    QWORD PTR [rsp+0x48],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11a3:
	/* 0x11a3: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11a8:
	/* 0x11a8: mov    QWORD PTR [rsp+0x38],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11ad:
	/* 0x11ad: mov    QWORD PTR [rsp+0x30],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11b2:
	/* 0x11b2: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11b7:
	/* 0x11b7: jmp    1202 <generic_uprobe_process_filter+0x1202> */
	goto x86_l_1202;
x86_l_11b9:
	/* 0x11b9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11be:
	/* 0x11be: mov    r10,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11c3:
	/* 0x11c3: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11c7:
	/* 0x11c7: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11cc:
	/* 0x11cc: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11d1:
	/* 0x11d1: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d6:
	/* 0x11d6: mov    r11,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11db:
	/* 0x11db: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11e0:
	/* 0x11e0: cmp    edi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_11e3:
	/* 0x11e3: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_11e6:
	/* 0x11e6: xor    r13b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_11ea:
	/* 0x11ea: or     r13b,al */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_11ed:
	/* 0x11ed: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11f1:
	/* 0x11f1: mov    DWORD PTR [rsp+rbp*1+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 96ULL);
x86_l_11f5:
	/* 0x11f5: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_11f9:
	/* 0x11f9: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_11fc:
	/* 0x11fc: je     16ae <generic_uprobe_process_filter+0x16ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5806ULL;
	}
x86_l_1202:
	/* 0x1202: lea    rax,[rsi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1206:
	/* 0x1206: cmp    rax,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1000ULL);
x86_l_120c:
	/* 0x120c: jbe    143c <generic_uprobe_process_filter+0x143c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_143c;
	}
x86_l_1212:
	/* 0x1212: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1215:
	/* 0x1215: test   r8b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 2ULL);
x86_l_1219:
	/* 0x1219: je     144a <generic_uprobe_process_filter+0x144a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_144a;
	}
x86_l_121f:
	/* 0x121f: test   r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_1223:
	/* 0x1223: jne    146c <generic_uprobe_process_filter+0x146c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_146c;
	}
x86_l_1229:
	/* 0x1229: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_122b:
	/* 0x122b: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_122e:
	/* 0x122e: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1231:
	/* 0x1231: je     11e0 <generic_uprobe_process_filter+0x11e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e0;
	}
x86_l_1233:
	/* 0x1233: mov    eax,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1236:
	/* 0x1236: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1239:
	/* 0x1239: je     11e0 <generic_uprobe_process_filter+0x11e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e0;
	}
x86_l_123b:
	/* 0x123b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1240:
	/* 0x1240: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1247:
	/* 0x1247: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_124f:
	/* 0x124f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1251:
	/* 0x1251: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1254:
	/* 0x1254: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_125a:
	/* 0x125a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125c:
	/* 0x125c: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_125f:
	/* 0x125f: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_1265:
	/* 0x1265: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1268:
	/* 0x1268: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_126b:
	/* 0x126b: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_1271:
	/* 0x1271: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1275:
	/* 0x1275: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_127a:
	/* 0x127a: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1281:
	/* 0x1281: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1284:
	/* 0x1284: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1286:
	/* 0x1286: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1289:
	/* 0x1289: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_128f:
	/* 0x128f: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1291:
	/* 0x1291: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1294:
	/* 0x1294: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_129a:
	/* 0x129a: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_129d:
	/* 0x129d: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_12a0:
	/* 0x12a0: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_12a6:
	/* 0x12a6: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_12aa:
	/* 0x12aa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12af:
	/* 0x12af: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_12b6:
	/* 0x12b6: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_12b9:
	/* 0x12b9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12bb:
	/* 0x12bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12be:
	/* 0x12be: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_12c4:
	/* 0x12c4: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c6:
	/* 0x12c6: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_12c9:
	/* 0x12c9: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_12cf:
	/* 0x12cf: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d2:
	/* 0x12d2: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_12d5:
	/* 0x12d5: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_12db:
	/* 0x12db: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_12df:
	/* 0x12df: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12e4:
	/* 0x12e4: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_12eb:
	/* 0x12eb: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_12ee:
	/* 0x12ee: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12f0:
	/* 0x12f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12f3:
	/* 0x12f3: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_12f9:
	/* 0x12f9: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12fb:
	/* 0x12fb: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_12fe:
	/* 0x12fe: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_1304:
	/* 0x1304: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1307:
	/* 0x1307: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_130a:
	/* 0x130a: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_1310:
	/* 0x1310: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1314:
	/* 0x1314: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1319:
	/* 0x1319: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1320:
	/* 0x1320: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1323:
	/* 0x1323: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1325:
	/* 0x1325: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1328:
	/* 0x1328: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_132e:
	/* 0x132e: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1330:
	/* 0x1330: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1333:
	/* 0x1333: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_1339:
	/* 0x1339: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_133c:
	/* 0x133c: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_133f:
	/* 0x133f: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_1345:
	/* 0x1345: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1349:
	/* 0x1349: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_134e:
	/* 0x134e: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1355:
	/* 0x1355: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1358:
	/* 0x1358: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_135a:
	/* 0x135a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_135d:
	/* 0x135d: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_1363:
	/* 0x1363: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1368:
	/* 0x1368: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_136a:
	/* 0x136a: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_136d:
	/* 0x136d: je     15bb <generic_uprobe_process_filter+0x15bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5563ULL;
	}
x86_l_1373:
	/* 0x1373: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1376:
	/* 0x1376: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1379:
	/* 0x1379: je     15bb <generic_uprobe_process_filter+0x15bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5563ULL;
	}
x86_l_137f:
	/* 0x137f: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1383:
	/* 0x1383: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1388:
	/* 0x1388: mov    rdi,QWORD PTR [rip+0x30ad] */
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
	/* 0x1397: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_139c:
	/* 0x139c: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13a1:
	/* 0x13a1: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_13a7:
	/* 0x13a7: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13a9:
	/* 0x13a9: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_13ac:
	/* 0x13ac: je     15bb <generic_uprobe_process_filter+0x15bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5563ULL;
	}
x86_l_13b2:
	/* 0x13b2: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13b5:
	/* 0x13b5: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_13b8:
	/* 0x13b8: je     15bb <generic_uprobe_process_filter+0x15bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5563ULL;
	}
x86_l_13be:
	/* 0x13be: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13c2:
	/* 0x13c2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13c7:
	/* 0x13c7: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_13ce:
	/* 0x13ce: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13d1:
	/* 0x13d1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13d3:
	/* 0x13d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13d6:
	/* 0x13d6: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13db:
	/* 0x13db: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13e0:
	/* 0x13e0: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_13e6:
	/* 0x13e6: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e8:
	/* 0x13e8: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_13eb:
	/* 0x13eb: je     15bb <generic_uprobe_process_filter+0x15bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5563ULL;
	}
x86_l_13f1:
	/* 0x13f1: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13f4:
	/* 0x13f4: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_13f7:
	/* 0x13f7: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13fc:
	/* 0x13fc: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1401:
	/* 0x1401: mov    r10,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1406:
	/* 0x1406: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_140a:
	/* 0x140a: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_140f:
	/* 0x140f: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1414:
	/* 0x1414: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1419:
	/* 0x1419: mov    r11,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_141e:
	/* 0x141e: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1423:
	/* 0x1423: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1428:
	/* 0x1428: je     11e0 <generic_uprobe_process_filter+0x11e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e0;
	}
x86_l_142e:
	/* 0x142e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1432:
	/* 0x1432: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1437:
	/* 0x1437: jmp    1659 <generic_uprobe_process_filter+0x1659> */
	return 5721ULL;
x86_l_143c:
	/* 0x143c: mov    r12d,DWORD PTR [r11+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1440:
	/* 0x1440: test   r8b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 2ULL);
x86_l_1444:
	/* 0x1444: jne    121f <generic_uprobe_process_filter+0x121f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_121f;
	}
x86_l_144a:
	/* 0x144a: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_144c:
	/* 0x144c: cmp    edi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_144f:
	/* 0x144f: jne    145a <generic_uprobe_process_filter+0x145a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_145a;
	}
x86_l_1451:
	/* 0x1451: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1454:
	/* 0x1454: jne    15f1 <generic_uprobe_process_filter+0x15f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5617ULL;
	}
x86_l_145a:
	/* 0x145a: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_145d:
	/* 0x145d: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1460:
	/* 0x1460: cmp    edi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_1463:
	/* 0x1463: setne  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_NE);
x86_l_1467:
	/* 0x1467: jmp    11ea <generic_uprobe_process_filter+0x11ea> */
	goto x86_l_11ea;
x86_l_146c:
	/* 0x146c: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146f:
	/* 0x146f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1472:
	/* 0x1472: je     15f1 <generic_uprobe_process_filter+0x15f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5617ULL;
	}
x86_l_1478:
	/* 0x1478: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_147b:
	/* 0x147b: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_147e:
	/* 0x147e: je     11e0 <generic_uprobe_process_filter+0x11e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e0;
	}
x86_l_1484:
	/* 0x1484: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1487:
	/* 0x1487: je     11e0 <generic_uprobe_process_filter+0x11e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e0;
	}
x86_l_148d:
	/* 0x148d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1492:
	/* 0x1492: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1499:
	/* 0x1499: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_14a1:
	/* 0x14a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a3:
	/* 0x14a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a6:
	/* 0x14a6: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_14ac:
	/* 0x14ac: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14af:
	/* 0x14af: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_14b2:
	/* 0x14b2: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b9;
	}
x86_l_14b8:
	/* 0x14b8: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14bc:
	/* 0x14bc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14c1:
	/* 0x14c1: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_14c8:
	/* 0x14c8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_14cb:
	/* 0x14cb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14cd:
	/* 0x14cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14d0:
	/* 0x14d0: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5743ULL;
	}
x86_l_14d6:
	/* 0x14d6: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
	return 5337ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5337ULL: goto x86_l_14d9;
	case 5340ULL: goto x86_l_14dc;
	case 5346ULL: goto x86_l_14e2;
	case 5350ULL: goto x86_l_14e6;
	case 5355ULL: goto x86_l_14eb;
	case 5362ULL: goto x86_l_14f2;
	case 5365ULL: goto x86_l_14f5;
	case 5367ULL: goto x86_l_14f7;
	case 5370ULL: goto x86_l_14fa;
	case 5376ULL: goto x86_l_1500;
	case 5379ULL: goto x86_l_1503;
	case 5382ULL: goto x86_l_1506;
	case 5388ULL: goto x86_l_150c;
	case 5392ULL: goto x86_l_1510;
	case 5397ULL: goto x86_l_1515;
	case 5404ULL: goto x86_l_151c;
	case 5407ULL: goto x86_l_151f;
	case 5409ULL: goto x86_l_1521;
	case 5412ULL: goto x86_l_1524;
	case 5418ULL: goto x86_l_152a;
	case 5421ULL: goto x86_l_152d;
	case 5424ULL: goto x86_l_1530;
	case 5430ULL: goto x86_l_1536;
	case 5434ULL: goto x86_l_153a;
	case 5439ULL: goto x86_l_153f;
	case 5446ULL: goto x86_l_1546;
	case 5449ULL: goto x86_l_1549;
	case 5451ULL: goto x86_l_154b;
	case 5454ULL: goto x86_l_154e;
	case 5460ULL: goto x86_l_1554;
	case 5463ULL: goto x86_l_1557;
	case 5466ULL: goto x86_l_155a;
	case 5472ULL: goto x86_l_1560;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5488ULL: goto x86_l_1570;
	case 5491ULL: goto x86_l_1573;
	case 5493ULL: goto x86_l_1575;
	case 5496ULL: goto x86_l_1578;
	case 5502ULL: goto x86_l_157e;
	case 5507ULL: goto x86_l_1583;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5515ULL: goto x86_l_158b;
	case 5519ULL: goto x86_l_158f;
	case 5524ULL: goto x86_l_1594;
	case 5531ULL: goto x86_l_159b;
	case 5534ULL: goto x86_l_159e;
	case 5536ULL: goto x86_l_15a0;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5549ULL: goto x86_l_15ad;
	case 5555ULL: goto x86_l_15b3;
	case 5558ULL: goto x86_l_15b6;
	case 5561ULL: goto x86_l_15b9;
	case 5563ULL: goto x86_l_15bb;
	case 5568ULL: goto x86_l_15c0;
	case 5573ULL: goto x86_l_15c5;
	case 5578ULL: goto x86_l_15ca;
	case 5582ULL: goto x86_l_15ce;
	case 5587ULL: goto x86_l_15d3;
	case 5592ULL: goto x86_l_15d8;
	case 5597ULL: goto x86_l_15dd;
	case 5602ULL: goto x86_l_15e2;
	case 5607ULL: goto x86_l_15e7;
	case 5612ULL: goto x86_l_15ec;
	case 5617ULL: goto x86_l_15f1;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5629ULL: goto x86_l_15fd;
	case 5634ULL: goto x86_l_1602;
	case 5641ULL: goto x86_l_1609;
	case 5644ULL: goto x86_l_160c;
	case 5646ULL: goto x86_l_160e;
	case 5649ULL: goto x86_l_1611;
	case 5654ULL: goto x86_l_1616;
	case 5659ULL: goto x86_l_161b;
	case 5661ULL: goto x86_l_161d;
	case 5664ULL: goto x86_l_1620;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5712ULL: goto x86_l_1650;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5728ULL: goto x86_l_1660;
	case 5731ULL: goto x86_l_1663;
	case 5733ULL: goto x86_l_1665;
	case 5738ULL: goto x86_l_166a;
	case 5743ULL: goto x86_l_166f;
	case 5746ULL: goto x86_l_1672;
	case 5750ULL: goto x86_l_1676;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5778ULL: goto x86_l_1692;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5804ULL: goto x86_l_16ac;
	case 5806ULL: goto x86_l_16ae;
	case 5810ULL: goto x86_l_16b2;
	case 5814ULL: goto x86_l_16b6;
	case 5818ULL: goto x86_l_16ba;
	case 5822ULL: goto x86_l_16be;
	case 5825ULL: goto x86_l_16c1;
	case 5827ULL: goto x86_l_16c3;
	case 5829ULL: goto x86_l_16c5;
	case 5831ULL: goto x86_l_16c7;
	case 5833ULL: goto x86_l_16c9;
	case 5835ULL: goto x86_l_16cb;
	case 5837ULL: goto x86_l_16cd;
	case 5839ULL: goto x86_l_16cf;
	case 5841ULL: goto x86_l_16d1;
	case 5849ULL: goto x86_l_16d9;
	case 5851ULL: goto x86_l_16db;
	case 5857ULL: goto x86_l_16e1;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5872ULL: goto x86_l_16f0;
	case 5875ULL: goto x86_l_16f3;
	case 5881ULL: goto x86_l_16f9;
	case 5885ULL: goto x86_l_16fd;
	case 5889ULL: goto x86_l_1701;
	case 5892ULL: goto x86_l_1704;
	case 5898ULL: goto x86_l_170a;
	case 5900ULL: goto x86_l_170c;
	case 5902ULL: goto x86_l_170e;
	case 5905ULL: goto x86_l_1711;
	case 5911ULL: goto x86_l_1717;
	case 5913ULL: goto x86_l_1719;
	case 5915ULL: goto x86_l_171b;
	case 5918ULL: goto x86_l_171e;
	case 5923ULL: goto x86_l_1723;
	case 5927ULL: goto x86_l_1727;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5946ULL: goto x86_l_173a;
	case 5955ULL: goto x86_l_1743;
	case 5959ULL: goto x86_l_1747;
	case 5964ULL: goto x86_l_174c;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5973ULL: goto x86_l_1755;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5997ULL: goto x86_l_176d;
	case 6000ULL: goto x86_l_1770;
	case 6006ULL: goto x86_l_1776;
	case 6009ULL: goto x86_l_1779;
	case 6012ULL: goto x86_l_177c;
	case 6014ULL: goto x86_l_177e;
	case 6017ULL: goto x86_l_1781;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6030ULL: goto x86_l_178e;
	case 6032ULL: goto x86_l_1790;
	case 6040ULL: goto x86_l_1798;
	case 6045ULL: goto x86_l_179d;
	case 6047ULL: goto x86_l_179f;
	case 6052ULL: goto x86_l_17a4;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6064ULL: goto x86_l_17b0;
	case 6071ULL: goto x86_l_17b7;
	case 6073ULL: goto x86_l_17b9;
	case 6076ULL: goto x86_l_17bc;
	case 6079ULL: goto x86_l_17bf;
	case 6083ULL: goto x86_l_17c3;
	case 6088ULL: goto x86_l_17c8;
	case 6091ULL: goto x86_l_17cb;
	case 6094ULL: goto x86_l_17ce;
	case 6098ULL: goto x86_l_17d2;
	case 6100ULL: goto x86_l_17d4;
	case 6103ULL: goto x86_l_17d7;
	case 6106ULL: goto x86_l_17da;
	case 6109ULL: goto x86_l_17dd;
	case 6111ULL: goto x86_l_17df;
	case 6115ULL: goto x86_l_17e3;
	case 6118ULL: goto x86_l_17e6;
	case 6121ULL: goto x86_l_17e9;
	case 6125ULL: goto x86_l_17ed;
	case 6128ULL: goto x86_l_17f0;
	case 6132ULL: goto x86_l_17f4;
	case 6136ULL: goto x86_l_17f8;
	case 6139ULL: goto x86_l_17fb;
	case 6145ULL: goto x86_l_1801;
	case 6149ULL: goto x86_l_1805;
	case 6151ULL: goto x86_l_1807;
	case 6157ULL: goto x86_l_180d;
	case 6159ULL: goto x86_l_180f;
	case 6162ULL: goto x86_l_1812;
	case 6166ULL: goto x86_l_1816;
	case 6169ULL: goto x86_l_1819;
	case 6173ULL: goto x86_l_181d;
	case 6176ULL: goto x86_l_1820;
	case 6179ULL: goto x86_l_1823;
	case 6181ULL: goto x86_l_1825;
	case 6185ULL: goto x86_l_1829;
	case 6188ULL: goto x86_l_182c;
	case 6191ULL: goto x86_l_182f;
	case 6195ULL: goto x86_l_1833;
	case 6198ULL: goto x86_l_1836;
	case 6202ULL: goto x86_l_183a;
	case 6206ULL: goto x86_l_183e;
	case 6210ULL: goto x86_l_1842;
	case 6212ULL: goto x86_l_1844;
	case 6216ULL: goto x86_l_1848;
	case 6218ULL: goto x86_l_184a;
	case 6224ULL: goto x86_l_1850;
	case 6226ULL: goto x86_l_1852;
	case 6229ULL: goto x86_l_1855;
	case 6233ULL: goto x86_l_1859;
	case 6236ULL: goto x86_l_185c;
	case 6240ULL: goto x86_l_1860;
	case 6243ULL: goto x86_l_1863;
	case 6246ULL: goto x86_l_1866;
	case 6248ULL: goto x86_l_1868;
	case 6252ULL: goto x86_l_186c;
	case 6255ULL: goto x86_l_186f;
	case 6258ULL: goto x86_l_1872;
	case 6262ULL: goto x86_l_1876;
	case 6265ULL: goto x86_l_1879;
	case 6269ULL: goto x86_l_187d;
	case 6273ULL: goto x86_l_1881;
	case 6277ULL: goto x86_l_1885;
	case 6279ULL: goto x86_l_1887;
	case 6283ULL: goto x86_l_188b;
	case 6285ULL: goto x86_l_188d;
	case 6292ULL: goto x86_l_1894;
	case 6294ULL: goto x86_l_1896;
	case 6298ULL: goto x86_l_189a;
	case 6302ULL: goto x86_l_189e;
	case 6305ULL: goto x86_l_18a1;
	case 6309ULL: goto x86_l_18a5;
	case 6311ULL: goto x86_l_18a7;
	case 6313ULL: goto x86_l_18a9;
	case 6315ULL: goto x86_l_18ab;
	case 6318ULL: goto x86_l_18ae;
	case 6321ULL: goto x86_l_18b1;
	case 6323ULL: goto x86_l_18b3;
	case 6326ULL: goto x86_l_18b6;
	case 6328ULL: goto x86_l_18b8;
	case 6331ULL: goto x86_l_18bb;
	case 6335ULL: goto x86_l_18bf;
	case 6339ULL: goto x86_l_18c3;
	case 6343ULL: goto x86_l_18c7;
	case 6347ULL: goto x86_l_18cb;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6356ULL: goto x86_l_18d4;
	case 6358ULL: goto x86_l_18d6;
	case 6360ULL: goto x86_l_18d8;
	case 6362ULL: goto x86_l_18da;
	case 6364ULL: goto x86_l_18dc;
	case 6366ULL: goto x86_l_18de;
	case 6368ULL: goto x86_l_18e0;
	case 6370ULL: goto x86_l_18e2;
	case 6372ULL: goto x86_l_18e4;
	case 6378ULL: goto x86_l_18ea;
	case 6382ULL: goto x86_l_18ee;
	case 6385ULL: goto x86_l_18f1;
	case 6389ULL: goto x86_l_18f5;
	case 6392ULL: goto x86_l_18f8;
	case 6395ULL: goto x86_l_18fb;
	case 6398ULL: goto x86_l_18fe;
	case 6401ULL: goto x86_l_1901;
	case 6407ULL: goto x86_l_1907;
	case 6410ULL: goto x86_l_190a;
	case 6416ULL: goto x86_l_1910;
	case 6420ULL: goto x86_l_1914;
	case 6425ULL: goto x86_l_1919;
	case 6431ULL: goto x86_l_191f;
	case 6438ULL: goto x86_l_1926;
	case 6443ULL: goto x86_l_192b;
	case 6448ULL: goto x86_l_1930;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6460ULL: goto x86_l_193c;
	case 6466ULL: goto x86_l_1942;
	case 6468ULL: goto x86_l_1944;
	case 6471ULL: goto x86_l_1947;
	case 6477ULL: goto x86_l_194d;
	case 6481ULL: goto x86_l_1951;
	case 6487ULL: goto x86_l_1957;
	case 6492ULL: goto x86_l_195c;
	case 6495ULL: goto x86_l_195f;
	case 6499ULL: goto x86_l_1963;
	case 6504ULL: goto x86_l_1968;
	case 6511ULL: goto x86_l_196f;
	case 6513ULL: goto x86_l_1971;
	case 6516ULL: goto x86_l_1974;
	case 6522ULL: goto x86_l_197a;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6537ULL: goto x86_l_1989;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6550ULL: goto x86_l_1996;
	case 6556ULL: goto x86_l_199c;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6567ULL: goto x86_l_19a7;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6578ULL: goto x86_l_19b2;
	case 6581ULL: goto x86_l_19b5;
	case 6583ULL: goto x86_l_19b7;
	case 6586ULL: goto x86_l_19ba;
	case 6590ULL: goto x86_l_19be;
	case 6594ULL: goto x86_l_19c2;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6606ULL: goto x86_l_19ce;
	case 6609ULL: goto x86_l_19d1;
	case 6615ULL: goto x86_l_19d7;
	case 6620ULL: goto x86_l_19dc;
	case 6623ULL: goto x86_l_19df;
	case 6626ULL: goto x86_l_19e2;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6656ULL: goto x86_l_1a00;
	case 6664ULL: goto x86_l_1a08;
	case 6666ULL: goto x86_l_1a0a;
	case 6669ULL: goto x86_l_1a0d;
	case 6675ULL: goto x86_l_1a13;
	case 6678ULL: goto x86_l_1a16;
	case 6685ULL: goto x86_l_1a1d;
	case 6691ULL: goto x86_l_1a23;
	case 6696ULL: goto x86_l_1a28;
	case 6703ULL: goto x86_l_1a2f;
	case 6706ULL: goto x86_l_1a32;
	case 6712ULL: goto x86_l_1a38;
	case 6718ULL: goto x86_l_1a3e;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6729ULL: goto x86_l_1a49;
	case 6733ULL: goto x86_l_1a4d;
	case 6738ULL: goto x86_l_1a52;
	case 6745ULL: goto x86_l_1a59;
	case 6750ULL: goto x86_l_1a5e;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6761ULL: goto x86_l_1a69;
	case 6764ULL: goto x86_l_1a6c;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6780ULL: goto x86_l_1a7c;
	case 6782ULL: goto x86_l_1a7e;
	case 6785ULL: goto x86_l_1a81;
	case 6787ULL: goto x86_l_1a83;
	case 6790ULL: goto x86_l_1a86;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6808ULL: goto x86_l_1a98;
	case 6812ULL: goto x86_l_1a9c;
	case 6815ULL: goto x86_l_1a9f;
	case 6818ULL: goto x86_l_1aa2;
	case 6824ULL: goto x86_l_1aa8;
	case 6827ULL: goto x86_l_1aab;
	case 6829ULL: goto x86_l_1aad;
	case 6831ULL: goto x86_l_1aaf;
	case 6836ULL: goto x86_l_1ab4;
	case 6839ULL: goto x86_l_1ab7;
	case 6841ULL: goto x86_l_1ab9;
	case 6843ULL: goto x86_l_1abb;
	case 6845ULL: goto x86_l_1abd;
	case 6850ULL: goto x86_l_1ac2;
	case 6853ULL: goto x86_l_1ac5;
	case 6855ULL: goto x86_l_1ac7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14d9:
	/* 0x14d9: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_14dc:
	/* 0x14dc: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4537ULL;
	}
x86_l_14e2:
	/* 0x14e2: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14e6:
	/* 0x14e6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14eb:
	/* 0x14eb: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_14f2:
	/* 0x14f2: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_14f5:
	/* 0x14f5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14f7:
	/* 0x14f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14fa:
	/* 0x14fa: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166f;
	}
x86_l_1500:
	/* 0x1500: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1503:
	/* 0x1503: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1506:
	/* 0x1506: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4537ULL;
	}
x86_l_150c:
	/* 0x150c: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1510:
	/* 0x1510: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1515:
	/* 0x1515: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_151c:
	/* 0x151c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_151f:
	/* 0x151f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1521:
	/* 0x1521: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1524:
	/* 0x1524: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166f;
	}
x86_l_152a:
	/* 0x152a: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_152d:
	/* 0x152d: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1530:
	/* 0x1530: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4537ULL;
	}
x86_l_1536:
	/* 0x1536: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_153a:
	/* 0x153a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_153f:
	/* 0x153f: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1546:
	/* 0x1546: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1549:
	/* 0x1549: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_154b:
	/* 0x154b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154e:
	/* 0x154e: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166f;
	}
x86_l_1554:
	/* 0x1554: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1557:
	/* 0x1557: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_155a:
	/* 0x155a: je     11b9 <generic_uprobe_process_filter+0x11b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4537ULL;
	}
x86_l_1560:
	/* 0x1560: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1564:
	/* 0x1564: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1569:
	/* 0x1569: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1570:
	/* 0x1570: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1573:
	/* 0x1573: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1575:
	/* 0x1575: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1578:
	/* 0x1578: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166f;
	}
x86_l_157e:
	/* 0x157e: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1583:
	/* 0x1583: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1586:
	/* 0x1586: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1589:
	/* 0x1589: je     15bb <generic_uprobe_process_filter+0x15bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15bb;
	}
x86_l_158b:
	/* 0x158b: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_158f:
	/* 0x158f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1594:
	/* 0x1594: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_159b:
	/* 0x159b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_159e:
	/* 0x159e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15a0:
	/* 0x15a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15a3:
	/* 0x15a3: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a8:
	/* 0x15a8: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15ad:
	/* 0x15ad: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166f;
	}
x86_l_15b3:
	/* 0x15b3: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_15b6:
	/* 0x15b6: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_15b9:
	/* 0x15b9: jne    15f9 <generic_uprobe_process_filter+0x15f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15f9;
	}
x86_l_15bb:
	/* 0x15bb: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15c0:
	/* 0x15c0: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15c5:
	/* 0x15c5: mov    r10,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15ca:
	/* 0x15ca: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15ce:
	/* 0x15ce: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15d3:
	/* 0x15d3: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15d8:
	/* 0x15d8: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15dd:
	/* 0x15dd: mov    r11,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15e2:
	/* 0x15e2: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15e7:
	/* 0x15e7: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15ec:
	/* 0x15ec: jmp    11e0 <generic_uprobe_process_filter+0x11e0> */
	return 4576ULL;
x86_l_15f1:
	/* 0x15f1: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f4:
	/* 0x15f4: jmp    11ed <generic_uprobe_process_filter+0x11ed> */
	return 4589ULL;
x86_l_15f9:
	/* 0x15f9: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15fd:
	/* 0x15fd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1602:
	/* 0x1602: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1609:
	/* 0x1609: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_160c:
	/* 0x160c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_160e:
	/* 0x160e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1611:
	/* 0x1611: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1616:
	/* 0x1616: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_161b:
	/* 0x161b: je     166f <generic_uprobe_process_filter+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166f;
	}
x86_l_161d:
	/* 0x161d: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1620:
	/* 0x1620: cmp    r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1623:
	/* 0x1623: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1628:
	/* 0x1628: mov    r10,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_162d:
	/* 0x162d: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1631:
	/* 0x1631: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1636:
	/* 0x1636: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_163b:
	/* 0x163b: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1640:
	/* 0x1640: mov    r11,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1645:
	/* 0x1645: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_164a:
	/* 0x164a: je     11e0 <generic_uprobe_process_filter+0x11e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4576ULL;
	}
x86_l_1650:
	/* 0x1650: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1654:
	/* 0x1654: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1659:
	/* 0x1659: mov    rdi,QWORD PTR [rip+0x30ad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1660:
	/* 0x1660: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1663:
	/* 0x1663: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1665:
	/* 0x1665: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_166a:
	/* 0x166a: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_166f:
	/* 0x166f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1672:
	/* 0x1672: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1676:
	/* 0x1676: cmp    edi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1679:
	/* 0x1679: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_167e:
	/* 0x167e: mov    r10,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1683:
	/* 0x1683: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1688:
	/* 0x1688: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_168d:
	/* 0x168d: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1692:
	/* 0x1692: mov    r11,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1697:
	/* 0x1697: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_169c:
	/* 0x169c: jne    11e0 <generic_uprobe_process_filter+0x11e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4576ULL;
	}
x86_l_16a2:
	/* 0x16a2: jmp    11ed <generic_uprobe_process_filter+0x11ed> */
	return 4589ULL;
x86_l_16a7:
	/* 0x16a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16ac:
	/* 0x16ac: jmp    16f0 <generic_uprobe_process_filter+0x16f0> */
	goto x86_l_16f0;
x86_l_16ae:
	/* 0x16ae: mov    esi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_16b2:
	/* 0x16b2: mov    ecx,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_16b6:
	/* 0x16b6: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16ba:
	/* 0x16ba: mov    edx,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_16be:
	/* 0x16be: cmp    edi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_16c1:
	/* 0x16c1: jne    16cb <generic_uprobe_process_filter+0x16cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16cb;
	}
x86_l_16c3:
	/* 0x16c3: and    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_AND);
x86_l_16c5:
	/* 0x16c5: and    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_AND);
x86_l_16c7:
	/* 0x16c7: and    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_AND);
x86_l_16c9:
	/* 0x16c9: jmp    16d1 <generic_uprobe_process_filter+0x16d1> */
	goto x86_l_16d1;
x86_l_16cb:
	/* 0x16cb: or     ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_16cd:
	/* 0x16cd: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_16cf:
	/* 0x16cf: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_16d1:
	/* 0x16d1: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_16d9:
	/* 0x16d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16db:
	/* 0x16db: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_16e1:
	/* 0x16e1: add    edx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_16e4:
	/* 0x16e4: mov    ecx,DWORD PTR [r9+r10*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 8ULL);
x86_l_16e9:
	/* 0x16e9: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_16ec:
	/* 0x16ec: lea    r10d,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_16f0:
	/* 0x16f0: mov    ecx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R10, X86_WIDTH_32);
x86_l_16f3:
	/* 0x16f3: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_16f9:
	/* 0x16f9: mov    ebp,DWORD PTR [rcx+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_16fd:
	/* 0x16fd: add    r10d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1701:
	/* 0x1701: add    ebp,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4294967292ULL);
x86_l_1704:
	/* 0x1704: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_170a:
	/* 0x170a: jmp    1717 <generic_uprobe_process_filter+0x1717> */
	goto x86_l_1717;
x86_l_170c:
	/* 0x170c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_170e:
	/* 0x170e: dec    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1711:
	/* 0x1711: je     1907 <generic_uprobe_process_filter+0x1907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1907;
	}
x86_l_1717:
	/* 0x1717: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1719:
	/* 0x1719: je     170c <generic_uprobe_process_filter+0x170c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_170c;
	}
x86_l_171b:
	/* 0x171b: mov    eax,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R10, X86_WIDTH_32);
x86_l_171e:
	/* 0x171e: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1723:
	/* 0x1723: mov    ecx,DWORD PTR [rax+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1727:
	/* 0x1727: mov    ebx,DWORD PTR [rax+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_172c:
	/* 0x172c: mov    r13d,DWORD PTR [rax+r9*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 8ULL);
x86_l_1731:
	/* 0x1731: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_173a:
	/* 0x173a: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1743:
	/* 0x1743: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1747:
	/* 0x1747: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_174c:
	/* 0x174c: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1750:
	/* 0x1750: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1753:
	/* 0x1753: jne    1769 <generic_uprobe_process_filter+0x1769> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1769;
	}
x86_l_1755:
	/* 0x1755: movabs rdx,0x100000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 4294967297ULL);
x86_l_175f:
	/* 0x175f: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1764:
	/* 0x1764: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1769:
	/* 0x1769: lea    r15d,[r10+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_176d:
	/* 0x176d: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1770:
	/* 0x1770: je     18bf <generic_uprobe_process_filter+0x18bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18bf;
	}
x86_l_1776:
	/* 0x1776: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1779:
	/* 0x1779: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_177c:
	/* 0x177c: jb     17ae <generic_uprobe_process_filter+0x17ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17ae;
	}
x86_l_177e:
	/* 0x177e: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1781:
	/* 0x1781: cmp    rax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 3ULL);
x86_l_1785:
	/* 0x1785: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_178a:
	/* 0x178a: cmovae rax,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_64, X86_CC_AE);
x86_l_178e:
	/* 0x178e: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1790:
	/* 0x1790: lea    rdx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_1798:
	/* 0x1798: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_179d:
	/* 0x179d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_179f:
	/* 0x179f: call   4858 <cwd_read_v61+0x259c> */
	X86_SIM_L_EXEC_CALL_MEMSET_REG(1024ULL);
x86_l_17a4:
	/* 0x17a4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17a9:
	/* 0x17a9: jmp    18bf <generic_uprobe_process_filter+0x18bf> */
	goto x86_l_18bf;
x86_l_17ae:
	/* 0x17ae: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b0:
	/* 0x17b0: cmp    r15d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1000ULL);
x86_l_17b7:
	/* 0x17b7: ja     17c3 <generic_uprobe_process_filter+0x17c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_17c3;
	}
x86_l_17b9:
	/* 0x17b9: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_17bc:
	/* 0x17bc: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_17bf:
	/* 0x17bf: mov    esi,DWORD PTR [r9+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_17c3:
	/* 0x17c3: mov    edx,DWORD PTR [r14+rcx*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 32ULL);
x86_l_17c8:
	/* 0x17c8: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_17cb:
	/* 0x17cb: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_17ce:
	/* 0x17ce: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_17d2:
	/* 0x17d2: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_17d4:
	/* 0x17d4: xor    ecx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_17d7:
	/* 0x17d7: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_17da:
	/* 0x17da: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17dd:
	/* 0x17dd: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_17df:
	/* 0x17df: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_17e3:
	/* 0x17e3: or     sil,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_17e6:
	/* 0x17e6: or     r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_17e9:
	/* 0x17e9: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_17ed:
	/* 0x17ed: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_17f0:
	/* 0x17f0: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_17f4:
	/* 0x17f4: mov    DWORD PTR [rsp+0x60],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_17f8:
	/* 0x17f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17fb:
	/* 0x17fb: je     18bf <generic_uprobe_process_filter+0x18bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18bf;
	}
x86_l_1801:
	/* 0x1801: lea    edi,[r10+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1805:
	/* 0x1805: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1807:
	/* 0x1807: cmp    edi,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 1000ULL);
x86_l_180d:
	/* 0x180d: ja     1816 <generic_uprobe_process_filter+0x1816> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1816;
	}
x86_l_180f:
	/* 0x180f: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1812:
	/* 0x1812: mov    esi,DWORD PTR [r9+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1816:
	/* 0x1816: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1819:
	/* 0x1819: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_181d:
	/* 0x181d: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_1820:
	/* 0x1820: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1823:
	/* 0x1823: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1825:
	/* 0x1825: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_1829:
	/* 0x1829: or     sil,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_182c:
	/* 0x182c: or     r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_182f:
	/* 0x182f: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1833:
	/* 0x1833: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1836:
	/* 0x1836: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_183a:
	/* 0x183a: mov    DWORD PTR [rsp+0x64],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_183e:
	/* 0x183e: cmp    rax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1ULL);
x86_l_1842:
	/* 0x1842: je     18bf <generic_uprobe_process_filter+0x18bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18bf;
	}
x86_l_1844:
	/* 0x1844: lea    edi,[r10+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1848:
	/* 0x1848: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184a:
	/* 0x184a: cmp    edi,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 1000ULL);
x86_l_1850:
	/* 0x1850: ja     1859 <generic_uprobe_process_filter+0x1859> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1859;
	}
x86_l_1852:
	/* 0x1852: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1855:
	/* 0x1855: mov    esi,DWORD PTR [r9+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1859:
	/* 0x1859: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_185c:
	/* 0x185c: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1860:
	/* 0x1860: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_1863:
	/* 0x1863: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1866:
	/* 0x1866: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1868:
	/* 0x1868: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_186c:
	/* 0x186c: or     sil,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_186f:
	/* 0x186f: or     r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1872:
	/* 0x1872: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1876:
	/* 0x1876: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1879:
	/* 0x1879: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_187d:
	/* 0x187d: mov    DWORD PTR [rsp+0x68],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1881:
	/* 0x1881: cmp    rax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 2ULL);
x86_l_1885:
	/* 0x1885: je     18bf <generic_uprobe_process_filter+0x18bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18bf;
	}
x86_l_1887:
	/* 0x1887: add    r10d,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_188b:
	/* 0x188b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_188d:
	/* 0x188d: cmp    r10d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 1000ULL);
x86_l_1894:
	/* 0x1894: ja     189e <generic_uprobe_process_filter+0x189e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_189e;
	}
x86_l_1896:
	/* 0x1896: and    r10d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_189a:
	/* 0x189a: mov    eax,DWORD PTR [r9+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_189e:
	/* 0x189e: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_18a1:
	/* 0x18a1: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_18a5:
	/* 0x18a5: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_18a7:
	/* 0x18a7: xor    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18a9:
	/* 0x18a9: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_18ab:
	/* 0x18ab: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_18ae:
	/* 0x18ae: or     al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_18b1:
	/* 0x18b1: or     ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_18b3:
	/* 0x18b3: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_18b6:
	/* 0x18b6: and    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_18b8:
	/* 0x18b8: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18bb:
	/* 0x18bb: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_18bf:
	/* 0x18bf: mov    esi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18c3:
	/* 0x18c3: mov    ecx,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_18c7:
	/* 0x18c7: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_18cb:
	/* 0x18cb: mov    edx,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_18cf:
	/* 0x18cf: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_18d2:
	/* 0x18d2: jne    18dc <generic_uprobe_process_filter+0x18dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18dc;
	}
x86_l_18d4:
	/* 0x18d4: and    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_AND);
x86_l_18d6:
	/* 0x18d6: and    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_AND);
x86_l_18d8:
	/* 0x18d8: and    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_AND);
x86_l_18da:
	/* 0x18da: jmp    18e2 <generic_uprobe_process_filter+0x18e2> */
	goto x86_l_18e2;
x86_l_18dc:
	/* 0x18dc: or     ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_18de:
	/* 0x18de: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_18e0:
	/* 0x18e0: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_18e2:
	/* 0x18e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18e4:
	/* 0x18e4: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_18ea:
	/* 0x18ea: shl    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_18ee:
	/* 0x18ee: sub    ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_18f1:
	/* 0x18f1: and    r13d,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_18f5:
	/* 0x18f5: add    r13d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18f8:
	/* 0x18f8: add    ebp,0xfffffff4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4294967284ULL);
x86_l_18fb:
	/* 0x18fb: mov    r10d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R13, X86_WIDTH_32);
x86_l_18fe:
	/* 0x18fe: dec    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1901:
	/* 0x1901: jne    1717 <generic_uprobe_process_filter+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1717;
	}
x86_l_1907:
	/* 0x1907: mov    ecx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R10, X86_WIDTH_32);
x86_l_190a:
	/* 0x190a: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1910:
	/* 0x1910: lea    r13d,[r10+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1914:
	/* 0x1914: cmp    DWORD PTR [rcx+r9*1],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_1919:
	/* 0x1919: je     1ae2 <generic_uprobe_process_filter+0x1ae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6882ULL;
	}
x86_l_191f:
	/* 0x191f: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1926:
	/* 0x1926: mov    ecx,DWORD PTR [r13+r9*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_192b:
	/* 0x192b: mov    edx,DWORD PTR [r13+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_1930:
	/* 0x1930: mov    edi,DWORD PTR [r13+r9*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 8ULL);
x86_l_1935:
	/* 0x1935: mov    rax,QWORD PTR [r13+r9*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 12ULL);
x86_l_193a:
	/* 0x193a: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_193c:
	/* 0x193c: je     1ab4 <generic_uprobe_process_filter+0x1ab4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ab4;
	}
x86_l_1942:
	/* 0x1942: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1944:
	/* 0x1944: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1947:
	/* 0x1947: ja     1ad7 <generic_uprobe_process_filter+0x1ad7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6871ULL;
	}
x86_l_194d:
	/* 0x194d: cmp    DWORD PTR [r14+0x44],edi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1951:
	/* 0x1951: jne    1abd <generic_uprobe_process_filter+0x1abd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1abd;
	}
x86_l_1957:
	/* 0x1957: jmp    1ad7 <generic_uprobe_process_filter+0x1ad7> */
	return 6871ULL;
x86_l_195c:
	/* 0x195c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_195f:
	/* 0x195f: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1963:
	/* 0x1963: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1968:
	/* 0x1968: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_196f:
	/* 0x196f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1971:
	/* 0x1971: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1974:
	/* 0x1974: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_197a:
	/* 0x197a: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_197d:
	/* 0x197d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1982:
	/* 0x1982: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1989:
	/* 0x1989: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1991:
	/* 0x1991: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1993:
	/* 0x1993: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1996:
	/* 0x1996: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_199c:
	/* 0x199c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_199f:
	/* 0x199f: mov    edx,0x104 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 260ULL);
x86_l_19a4:
	/* 0x19a4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_19a7:
	/* 0x19a7: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19a9:
	/* 0x19a9: call   4a6f <cwd_read_v61+0x27b3> */
	X86_SIM_L_EXEC_CALL_MEMSET(260ULL);
x86_l_19ae:
	/* 0x19ae: mov    eax,DWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_19b2:
	/* 0x19b2: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_19b5:
	/* 0x19b5: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b7:
	/* 0x19b7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19ba:
	/* 0x19ba: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_19be:
	/* 0x19be: lea    rdx,[r15+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_19c2:
	/* 0x19c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19c7:
	/* 0x19c7: movzx  esi,BYTE PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 104ULL);
x86_l_19cc:
	/* 0x19cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ce:
	/* 0x19ce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19d1:
	/* 0x19d1: js     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8765ULL;
	}
x86_l_19d7:
	/* 0x19d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19dc:
	/* 0x19dc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_19df:
	/* 0x19df: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_19e2:
	/* 0x19e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e4:
	/* 0x19e4: jmp    1dd7 <generic_uprobe_process_filter+0x1dd7> */
	return 7639ULL;
x86_l_19e9:
	/* 0x19e9: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_19f4:
	/* 0x19f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19f9:
	/* 0x19f9: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_gen)));
x86_l_1a00:
	/* 0x1a00: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a08:
	/* 0x1a08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0a:
	/* 0x1a0a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a0d:
	/* 0x1a0d: je     1d86 <generic_uprobe_process_filter+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_1a13:
	/* 0x1a13: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a16:
	/* 0x1a16: cmp    rcx,QWORD PTR [r15+0x378] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 888ULL);
x86_l_1a1d:
	/* 0x1a1d: je     1d86 <generic_uprobe_process_filter+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_1a23:
	/* 0x1a23: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a28:
	/* 0x1a28: mov    rax,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1a2f:
	/* 0x1a2f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a32:
	/* 0x1a32: je     1d03 <generic_uprobe_process_filter+0x1d03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7427ULL;
	}
x86_l_1a38:
	/* 0x1a38: mov    r12d,0x1869f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 99999ULL);
x86_l_1a3e:
	/* 0x1a3e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a41:
	/* 0x1a41: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a46:
	/* 0x1a46: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a49:
	/* 0x1a49: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a4d:
	/* 0x1a4d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a52:
	/* 0x1a52: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1a59:
	/* 0x1a59: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a5e:
	/* 0x1a5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a60:
	/* 0x1a60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a63:
	/* 0x1a63: je     1d72 <generic_uprobe_process_filter+0x1d72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7538ULL;
	}
x86_l_1a69:
	/* 0x1a69: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a6c:
	/* 0x1a6c: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a70:
	/* 0x1a70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a75:
	/* 0x1a75: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_1a7c:
	/* 0x1a7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7e:
	/* 0x1a7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a81:
	/* 0x1a81: je     1a98 <generic_uprobe_process_filter+0x1a98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a98;
	}
x86_l_1a83:
	/* 0x1a83: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a86:
	/* 0x1a86: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a89:
	/* 0x1a89: je     1a98 <generic_uprobe_process_filter+0x1a98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a98;
	}
x86_l_1a8b:
	/* 0x1a8b: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a90:
	/* 0x1a90: or QWORD PTR [rcx+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_1a98:
	/* 0x1a98: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_1a9c:
	/* 0x1a9c: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_1a9f:
	/* 0x1a9f: cmp    rbx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1aa2:
	/* 0x1aa2: je     1d72 <generic_uprobe_process_filter+0x1d72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7538ULL;
	}
x86_l_1aa8:
	/* 0x1aa8: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1aab:
	/* 0x1aab: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1aad:
	/* 0x1aad: je     1a41 <generic_uprobe_process_filter+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a41;
	}
x86_l_1aaf:
	/* 0x1aaf: jmp    1d72 <generic_uprobe_process_filter+0x1d72> */
	return 7538ULL;
x86_l_1ab4:
	/* 0x1ab4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ab7:
	/* 0x1ab7: jbe    1abd <generic_uprobe_process_filter+0x1abd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1abd;
	}
x86_l_1ab9:
	/* 0x1ab9: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1abb:
	/* 0x1abb: jmp    1ad7 <generic_uprobe_process_filter+0x1ad7> */
	return 6871ULL;
x86_l_1abd:
	/* 0x1abd: and    rax,QWORD PTR [r14+rcx*8+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 72ULL);
x86_l_1ac2:
	/* 0x1ac2: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1ac5:
	/* 0x1ac5: jne    1ad0 <generic_uprobe_process_filter+0x1ad0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6864ULL;
	}
x86_l_1ac7:
	/* 0x1ac7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 6858ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6858ULL: goto x86_l_1aca;
	case 6862ULL: goto x86_l_1ace;
	case 6864ULL: goto x86_l_1ad0;
	case 6867ULL: goto x86_l_1ad3;
	case 6871ULL: goto x86_l_1ad7;
	case 6875ULL: goto x86_l_1adb;
	case 6879ULL: goto x86_l_1adf;
	case 6882ULL: goto x86_l_1ae2;
	case 6884ULL: goto x86_l_1ae4;
	case 6890ULL: goto x86_l_1aea;
	case 6893ULL: goto x86_l_1aed;
	case 6899ULL: goto x86_l_1af3;
	case 6903ULL: goto x86_l_1af7;
	case 6908ULL: goto x86_l_1afc;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6935ULL: goto x86_l_1b17;
	case 6939ULL: goto x86_l_1b1b;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6970ULL: goto x86_l_1b3a;
	case 6976ULL: goto x86_l_1b40;
	case 6979ULL: goto x86_l_1b43;
	case 6981ULL: goto x86_l_1b45;
	case 6984ULL: goto x86_l_1b48;
	case 6990ULL: goto x86_l_1b4e;
	case 6993ULL: goto x86_l_1b51;
	case 7000ULL: goto x86_l_1b58;
	case 7003ULL: goto x86_l_1b5b;
	case 7009ULL: goto x86_l_1b61;
	case 7012ULL: goto x86_l_1b64;
	case 7014ULL: goto x86_l_1b66;
	case 7020ULL: goto x86_l_1b6c;
	case 7024ULL: goto x86_l_1b70;
	case 7030ULL: goto x86_l_1b76;
	case 7035ULL: goto x86_l_1b7b;
	case 7038ULL: goto x86_l_1b7e;
	case 7045ULL: goto x86_l_1b85;
	case 7048ULL: goto x86_l_1b88;
	case 7054ULL: goto x86_l_1b8e;
	case 7057ULL: goto x86_l_1b91;
	case 7059ULL: goto x86_l_1b93;
	case 7065ULL: goto x86_l_1b99;
	case 7069ULL: goto x86_l_1b9d;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7083ULL: goto x86_l_1bab;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7099ULL: goto x86_l_1bbb;
	case 7101ULL: goto x86_l_1bbd;
	case 7104ULL: goto x86_l_1bc0;
	case 7110ULL: goto x86_l_1bc6;
	case 7113ULL: goto x86_l_1bc9;
	case 7118ULL: goto x86_l_1bce;
	case 7125ULL: goto x86_l_1bd5;
	case 7133ULL: goto x86_l_1bdd;
	case 7135ULL: goto x86_l_1bdf;
	case 7138ULL: goto x86_l_1be2;
	case 7144ULL: goto x86_l_1be8;
	case 7147ULL: goto x86_l_1beb;
	case 7152ULL: goto x86_l_1bf0;
	case 7155ULL: goto x86_l_1bf3;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7166ULL: goto x86_l_1bfe;
	case 7169ULL: goto x86_l_1c01;
	case 7171ULL: goto x86_l_1c03;
	case 7174ULL: goto x86_l_1c06;
	case 7178ULL: goto x86_l_1c0a;
	case 7181ULL: goto x86_l_1c0d;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7195ULL: goto x86_l_1c1b;
	case 7197ULL: goto x86_l_1c1d;
	case 7200ULL: goto x86_l_1c20;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7214ULL: goto x86_l_1c2e;
	case 7217ULL: goto x86_l_1c31;
	case 7219ULL: goto x86_l_1c33;
	case 7224ULL: goto x86_l_1c38;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7247ULL: goto x86_l_1c4f;
	case 7255ULL: goto x86_l_1c57;
	case 7257ULL: goto x86_l_1c59;
	case 7260ULL: goto x86_l_1c5c;
	case 7266ULL: goto x86_l_1c62;
	case 7269ULL: goto x86_l_1c65;
	case 7276ULL: goto x86_l_1c6c;
	case 7282ULL: goto x86_l_1c72;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7299ULL: goto x86_l_1c83;
	case 7302ULL: goto x86_l_1c86;
	case 7308ULL: goto x86_l_1c8c;
	case 7314ULL: goto x86_l_1c92;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7325ULL: goto x86_l_1c9d;
	case 7329ULL: goto x86_l_1ca1;
	case 7334ULL: goto x86_l_1ca6;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7348ULL: goto x86_l_1cb4;
	case 7351ULL: goto x86_l_1cb7;
	case 7357ULL: goto x86_l_1cbd;
	case 7360ULL: goto x86_l_1cc0;
	case 7364ULL: goto x86_l_1cc4;
	case 7369ULL: goto x86_l_1cc9;
	case 7376ULL: goto x86_l_1cd0;
	case 7378ULL: goto x86_l_1cd2;
	case 7381ULL: goto x86_l_1cd5;
	case 7383ULL: goto x86_l_1cd7;
	case 7386ULL: goto x86_l_1cda;
	case 7389ULL: goto x86_l_1cdd;
	case 7391ULL: goto x86_l_1cdf;
	case 7399ULL: goto x86_l_1ce7;
	case 7403ULL: goto x86_l_1ceb;
	case 7406ULL: goto x86_l_1cee;
	case 7409ULL: goto x86_l_1cf1;
	case 7415ULL: goto x86_l_1cf7;
	case 7418ULL: goto x86_l_1cfa;
	case 7420ULL: goto x86_l_1cfc;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7433ULL: goto x86_l_1d09;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7444ULL: goto x86_l_1d14;
	case 7448ULL: goto x86_l_1d18;
	case 7453ULL: goto x86_l_1d1d;
	case 7460ULL: goto x86_l_1d24;
	case 7465ULL: goto x86_l_1d29;
	case 7467ULL: goto x86_l_1d2b;
	case 7470ULL: goto x86_l_1d2e;
	case 7472ULL: goto x86_l_1d30;
	case 7475ULL: goto x86_l_1d33;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7491ULL: goto x86_l_1d43;
	case 7493ULL: goto x86_l_1d45;
	case 7496ULL: goto x86_l_1d48;
	case 7498ULL: goto x86_l_1d4a;
	case 7501ULL: goto x86_l_1d4d;
	case 7504ULL: goto x86_l_1d50;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7519ULL: goto x86_l_1d5f;
	case 7523ULL: goto x86_l_1d63;
	case 7526ULL: goto x86_l_1d66;
	case 7529ULL: goto x86_l_1d69;
	case 7531ULL: goto x86_l_1d6b;
	case 7534ULL: goto x86_l_1d6e;
	case 7536ULL: goto x86_l_1d70;
	case 7538ULL: goto x86_l_1d72;
	case 7543ULL: goto x86_l_1d77;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7558ULL: goto x86_l_1d86;
	case 7562ULL: goto x86_l_1d8a;
	case 7567ULL: goto x86_l_1d8f;
	case 7570ULL: goto x86_l_1d92;
	case 7572ULL: goto x86_l_1d94;
	case 7579ULL: goto x86_l_1d9b;
	case 7583ULL: goto x86_l_1d9f;
	case 7585ULL: goto x86_l_1da1;
	case 7595ULL: goto x86_l_1dab;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7616ULL: goto x86_l_1dc0;
	case 7619ULL: goto x86_l_1dc3;
	case 7625ULL: goto x86_l_1dc9;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7637ULL: goto x86_l_1dd5;
	case 7639ULL: goto x86_l_1dd7;
	case 7643ULL: goto x86_l_1ddb;
	case 7647ULL: goto x86_l_1ddf;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7664ULL: goto x86_l_1df0;
	case 7668ULL: goto x86_l_1df4;
	case 7670ULL: goto x86_l_1df6;
	case 7673ULL: goto x86_l_1df9;
	case 7679ULL: goto x86_l_1dff;
	case 7684ULL: goto x86_l_1e04;
	case 7687ULL: goto x86_l_1e07;
	case 7693ULL: goto x86_l_1e0d;
	case 7698ULL: goto x86_l_1e12;
	case 7705ULL: goto x86_l_1e19;
	case 7708ULL: goto x86_l_1e1c;
	case 7710ULL: goto x86_l_1e1e;
	case 7713ULL: goto x86_l_1e21;
	case 7715ULL: goto x86_l_1e23;
	case 7717ULL: goto x86_l_1e25;
	case 7721ULL: goto x86_l_1e29;
	case 7723ULL: goto x86_l_1e2b;
	case 7728ULL: goto x86_l_1e30;
	case 7735ULL: goto x86_l_1e37;
	case 7738ULL: goto x86_l_1e3a;
	case 7740ULL: goto x86_l_1e3c;
	case 7743ULL: goto x86_l_1e3f;
	case 7745ULL: goto x86_l_1e41;
	case 7747ULL: goto x86_l_1e43;
	case 7751ULL: goto x86_l_1e47;
	case 7753ULL: goto x86_l_1e49;
	case 7758ULL: goto x86_l_1e4e;
	case 7765ULL: goto x86_l_1e55;
	case 7768ULL: goto x86_l_1e58;
	case 7770ULL: goto x86_l_1e5a;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7777ULL: goto x86_l_1e61;
	case 7781ULL: goto x86_l_1e65;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7800ULL: goto x86_l_1e78;
	case 7803ULL: goto x86_l_1e7b;
	case 7805ULL: goto x86_l_1e7d;
	case 7807ULL: goto x86_l_1e7f;
	case 7811ULL: goto x86_l_1e83;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7825ULL: goto x86_l_1e91;
	case 7828ULL: goto x86_l_1e94;
	case 7834ULL: goto x86_l_1e9a;
	case 7837ULL: goto x86_l_1e9d;
	case 7839ULL: goto x86_l_1e9f;
	case 7845ULL: goto x86_l_1ea5;
	case 7849ULL: goto x86_l_1ea9;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7867ULL: goto x86_l_1ebb;
	case 7870ULL: goto x86_l_1ebe;
	case 7876ULL: goto x86_l_1ec4;
	case 7879ULL: goto x86_l_1ec7;
	case 7881ULL: goto x86_l_1ec9;
	case 7887ULL: goto x86_l_1ecf;
	case 7891ULL: goto x86_l_1ed3;
	case 7897ULL: goto x86_l_1ed9;
	case 7902ULL: goto x86_l_1ede;
	case 7908ULL: goto x86_l_1ee4;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7919ULL: goto x86_l_1eef;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7935ULL: goto x86_l_1eff;
	case 7940ULL: goto x86_l_1f04;
	case 7942ULL: goto x86_l_1f06;
	case 7945ULL: goto x86_l_1f09;
	case 7947ULL: goto x86_l_1f0b;
	case 7950ULL: goto x86_l_1f0e;
	case 7954ULL: goto x86_l_1f12;
	case 7959ULL: goto x86_l_1f17;
	case 7966ULL: goto x86_l_1f1e;
	case 7968ULL: goto x86_l_1f20;
	case 7971ULL: goto x86_l_1f23;
	case 7973ULL: goto x86_l_1f25;
	case 7976ULL: goto x86_l_1f28;
	case 7979ULL: goto x86_l_1f2b;
	case 7981ULL: goto x86_l_1f2d;
	case 7989ULL: goto x86_l_1f35;
	case 7993ULL: goto x86_l_1f39;
	case 7996ULL: goto x86_l_1f3c;
	case 7999ULL: goto x86_l_1f3f;
	case 8001ULL: goto x86_l_1f41;
	case 8004ULL: goto x86_l_1f44;
	case 8006ULL: goto x86_l_1f46;
	case 8008ULL: goto x86_l_1f48;
	case 8013ULL: goto x86_l_1f4d;
	case 8016ULL: goto x86_l_1f50;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8041ULL: goto x86_l_1f69;
	case 8043ULL: goto x86_l_1f6b;
	case 8050ULL: goto x86_l_1f72;
	case 8054ULL: goto x86_l_1f76;
	case 8056ULL: goto x86_l_1f78;
	case 8066ULL: goto x86_l_1f82;
	case 8068ULL: goto x86_l_1f84;
	case 8073ULL: goto x86_l_1f89;
	case 8080ULL: goto x86_l_1f90;
	case 8085ULL: goto x86_l_1f95;
	case 8087ULL: goto x86_l_1f97;
	case 8090ULL: goto x86_l_1f9a;
	case 8096ULL: goto x86_l_1fa0;
	case 8100ULL: goto x86_l_1fa4;
	case 8105ULL: goto x86_l_1fa9;
	case 8108ULL: goto x86_l_1fac;
	case 8111ULL: goto x86_l_1faf;
	case 8113ULL: goto x86_l_1fb1;
	case 8117ULL: goto x86_l_1fb5;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8138ULL: goto x86_l_1fca;
	case 8142ULL: goto x86_l_1fce;
	case 8144ULL: goto x86_l_1fd0;
	case 8147ULL: goto x86_l_1fd3;
	case 8153ULL: goto x86_l_1fd9;
	case 8158ULL: goto x86_l_1fde;
	case 8161ULL: goto x86_l_1fe1;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8179ULL: goto x86_l_1ff3;
	case 8182ULL: goto x86_l_1ff6;
	case 8184ULL: goto x86_l_1ff8;
	case 8187ULL: goto x86_l_1ffb;
	case 8189ULL: goto x86_l_1ffd;
	case 8191ULL: goto x86_l_1fff;
	case 8195ULL: goto x86_l_2003;
	case 8197ULL: goto x86_l_2005;
	case 8202ULL: goto x86_l_200a;
	case 8209ULL: goto x86_l_2011;
	case 8212ULL: goto x86_l_2014;
	case 8214ULL: goto x86_l_2016;
	case 8217ULL: goto x86_l_2019;
	case 8219ULL: goto x86_l_201b;
	case 8221ULL: goto x86_l_201d;
	case 8225ULL: goto x86_l_2021;
	case 8227ULL: goto x86_l_2023;
	case 8232ULL: goto x86_l_2028;
	case 8239ULL: goto x86_l_202f;
	case 8242ULL: goto x86_l_2032;
	case 8244ULL: goto x86_l_2034;
	case 8247ULL: goto x86_l_2037;
	case 8249ULL: goto x86_l_2039;
	case 8251ULL: goto x86_l_203b;
	case 8255ULL: goto x86_l_203f;
	case 8257ULL: goto x86_l_2041;
	case 8262ULL: goto x86_l_2046;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8274ULL: goto x86_l_2052;
	case 8277ULL: goto x86_l_2055;
	case 8279ULL: goto x86_l_2057;
	case 8281ULL: goto x86_l_2059;
	case 8285ULL: goto x86_l_205d;
	case 8287ULL: goto x86_l_205f;
	case 8292ULL: goto x86_l_2064;
	case 8299ULL: goto x86_l_206b;
	case 8302ULL: goto x86_l_206e;
	case 8304ULL: goto x86_l_2070;
	case 8307ULL: goto x86_l_2073;
	case 8309ULL: goto x86_l_2075;
	case 8311ULL: goto x86_l_2077;
	case 8315ULL: goto x86_l_207b;
	case 8317ULL: goto x86_l_207d;
	case 8322ULL: goto x86_l_2082;
	case 8329ULL: goto x86_l_2089;
	case 8332ULL: goto x86_l_208c;
	case 8334ULL: goto x86_l_208e;
	case 8337ULL: goto x86_l_2091;
	case 8339ULL: goto x86_l_2093;
	case 8341ULL: goto x86_l_2095;
	case 8345ULL: goto x86_l_2099;
	case 8347ULL: goto x86_l_209b;
	case 8352ULL: goto x86_l_20a0;
	case 8359ULL: goto x86_l_20a7;
	case 8361ULL: goto x86_l_20a9;
	case 8363ULL: goto x86_l_20ab;
	case 8366ULL: goto x86_l_20ae;
	case 8368ULL: goto x86_l_20b0;
	case 8370ULL: goto x86_l_20b2;
	case 8374ULL: goto x86_l_20b6;
	case 8376ULL: goto x86_l_20b8;
	case 8381ULL: goto x86_l_20bd;
	case 8388ULL: goto x86_l_20c4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1aca:
	/* 0x1aca: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_1ace:
	/* 0x1ace: jmp    1ad7 <generic_uprobe_process_filter+0x1ad7> */
	goto x86_l_1ad7;
x86_l_1ad0:
	/* 0x1ad0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ad3:
	/* 0x1ad3: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_1ad7:
	/* 0x1ad7: add    r10d,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1adb:
	/* 0x1adb: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1adf:
	/* 0x1adf: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1ae2:
	/* 0x1ae2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ae4:
	/* 0x1ae4: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_1aea:
	/* 0x1aea: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_1aed:
	/* 0x1aed: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1af3:
	/* 0x1af3: lea    eax,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1af7:
	/* 0x1af7: cmp    DWORD PTR [rcx+r9*1],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_1afc:
	/* 0x1afc: je     2155 <generic_uprobe_process_filter+0x2155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8533ULL;
	}
x86_l_1b02:
	/* 0x1b02: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1b07:
	/* 0x1b07: mov    ebp,DWORD PTR [rax+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1b0b:
	/* 0x1b0b: mov    ebx,DWORD PTR [rax+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_1b10:
	/* 0x1b10: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1b15:
	/* 0x1b15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b17:
	/* 0x1b17: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b1f:
	/* 0x1b1f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b24:
	/* 0x1b24: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1b2b:
	/* 0x1b2b: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b30:
	/* 0x1b30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b32:
	/* 0x1b32: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b37:
	/* 0x1b37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b3a:
	/* 0x1b3a: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_1b40:
	/* 0x1b40: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1b43:
	/* 0x1b43: je     1b7b <generic_uprobe_process_filter+0x1b7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b7b;
	}
x86_l_1b45:
	/* 0x1b45: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1b48:
	/* 0x1b48: jne    223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8765ULL;
	}
x86_l_1b4e:
	/* 0x1b4e: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1b51:
	/* 0x1b51: add    rcx,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_1b58:
	/* 0x1b58: test   bl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 1ULL);
x86_l_1b5b:
	/* 0x1b5b: jne    1e19 <generic_uprobe_process_filter+0x1e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e19;
	}
x86_l_1b61:
	/* 0x1b61: mov    edx,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b64:
	/* 0x1b64: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1b66:
	/* 0x1b66: je     1e12 <generic_uprobe_process_filter+0x1e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e12;
	}
x86_l_1b6c:
	/* 0x1b6c: cmp    edx,DWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_1b70:
	/* 0x1b70: je     1e19 <generic_uprobe_process_filter+0x1e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e19;
	}
x86_l_1b76:
	/* 0x1b76: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_1b7b:
	/* 0x1b7b: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1b7e:
	/* 0x1b7e: add    rcx,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_1b85:
	/* 0x1b85: test   bl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 1ULL);
x86_l_1b88:
	/* 0x1b88: je     1e37 <generic_uprobe_process_filter+0x1e37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e37;
	}
x86_l_1b8e:
	/* 0x1b8e: mov    edx,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b91:
	/* 0x1b91: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1b93:
	/* 0x1b93: je     1e30 <generic_uprobe_process_filter+0x1e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e30;
	}
x86_l_1b99:
	/* 0x1b99: cmp    edx,DWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_1b9d:
	/* 0x1b9d: je     1e37 <generic_uprobe_process_filter+0x1e37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e37;
	}
x86_l_1ba3:
	/* 0x1ba3: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_1ba8:
	/* 0x1ba8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1bab:
	/* 0x1bab: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1baf:
	/* 0x1baf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1bbb:
	/* 0x1bbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bbd:
	/* 0x1bbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bc0:
	/* 0x1bc0: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_1bc6:
	/* 0x1bc6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1bc9:
	/* 0x1bc9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bce:
	/* 0x1bce: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1bd5:
	/* 0x1bd5: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1bdd:
	/* 0x1bdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bdf:
	/* 0x1bdf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1be2:
	/* 0x1be2: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_1be8:
	/* 0x1be8: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1beb:
	/* 0x1beb: mov    edx,0x104 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 260ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1bf3:
	/* 0x1bf3: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bf5:
	/* 0x1bf5: call   4cbb <cwd_read_v61+0x29ff> */
	X86_SIM_L_EXEC_CALL_MEMSET(260ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bfe:
	/* 0x1bfe: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1c01:
	/* 0x1c01: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c03:
	/* 0x1c03: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c06:
	/* 0x1c06: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1c0a:
	/* 0x1c0a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c0d:
	/* 0x1c0d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c11:
	/* 0x1c11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c16:
	/* 0x1c16: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1c1b:
	/* 0x1c1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1d:
	/* 0x1c1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c20:
	/* 0x1c20: js     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8765ULL;
	}
x86_l_1c26:
	/* 0x1c26: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c2b:
	/* 0x1c2b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c2e:
	/* 0x1c2e: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1c31:
	/* 0x1c31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c33:
	/* 0x1c33: jmp    1fb1 <generic_uprobe_process_filter+0x1fb1> */
	goto x86_l_1fb1;
x86_l_1c38:
	/* 0x1c38: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_1c43:
	/* 0x1c43: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c48:
	/* 0x1c48: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_gen)));
x86_l_1c4f:
	/* 0x1c4f: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c57:
	/* 0x1c57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c59:
	/* 0x1c59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c5c:
	/* 0x1c5c: je     1f5c <generic_uprobe_process_filter+0x1f5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5c;
	}
x86_l_1c62:
	/* 0x1c62: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c65:
	/* 0x1c65: cmp    rcx,QWORD PTR [r13+0x310] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 784ULL);
x86_l_1c6c:
	/* 0x1c6c: je     1f5c <generic_uprobe_process_filter+0x1f5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5c;
	}
x86_l_1c72:
	/* 0x1c72: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c77:
	/* 0x1c77: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c7c:
	/* 0x1c7c: mov    rax,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1c83:
	/* 0x1c83: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c86:
	/* 0x1c86: je     1ede <generic_uprobe_process_filter+0x1ede> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ede;
	}
x86_l_1c8c:
	/* 0x1c8c: mov    r12d,0x1869f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 99999ULL);
x86_l_1c92:
	/* 0x1c92: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c95:
	/* 0x1c95: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c9d:
	/* 0x1c9d: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ca1:
	/* 0x1ca1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ca6:
	/* 0x1ca6: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1cad:
	/* 0x1cad: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1cb2:
	/* 0x1cb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb4:
	/* 0x1cb4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cb7:
	/* 0x1cb7: je     1f48 <generic_uprobe_process_filter+0x1f48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f48;
	}
x86_l_1cbd:
	/* 0x1cbd: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1cc0:
	/* 0x1cc0: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1cc4:
	/* 0x1cc4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cc9:
	/* 0x1cc9: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_1cd0:
	/* 0x1cd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd2:
	/* 0x1cd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cd5:
	/* 0x1cd5: je     1ce7 <generic_uprobe_process_filter+0x1ce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ce7;
	}
x86_l_1cd7:
	/* 0x1cd7: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cda:
	/* 0x1cda: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cdd:
	/* 0x1cdd: je     1ce7 <generic_uprobe_process_filter+0x1ce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ce7;
	}
x86_l_1cdf:
	/* 0x1cdf: or QWORD PTR [r13+0x308],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 776ULL);
x86_l_1ce7:
	/* 0x1ce7: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_1ceb:
	/* 0x1ceb: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_1cee:
	/* 0x1cee: cmp    rbx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1cf1:
	/* 0x1cf1: je     1f48 <generic_uprobe_process_filter+0x1f48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f48;
	}
x86_l_1cf7:
	/* 0x1cf7: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1cfa:
	/* 0x1cfa: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1cfc:
	/* 0x1cfc: je     1c95 <generic_uprobe_process_filter+0x1c95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c95;
	}
x86_l_1cfe:
	/* 0x1cfe: jmp    1f48 <generic_uprobe_process_filter+0x1f48> */
	goto x86_l_1f48;
x86_l_1d03:
	/* 0x1d03: mov    r12d,0x3ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_1d09:
	/* 0x1d09: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d0c:
	/* 0x1d0c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d11:
	/* 0x1d11: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d14:
	/* 0x1d14: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d18:
	/* 0x1d18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d1d:
	/* 0x1d1d: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1d24:
	/* 0x1d24: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d29:
	/* 0x1d29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2b:
	/* 0x1d2b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d2e:
	/* 0x1d2e: je     1d72 <generic_uprobe_process_filter+0x1d72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d72;
	}
x86_l_1d30:
	/* 0x1d30: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1d33:
	/* 0x1d33: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d37:
	/* 0x1d37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d3c:
	/* 0x1d3c: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_1d43:
	/* 0x1d43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d45:
	/* 0x1d45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d48:
	/* 0x1d48: je     1d5f <generic_uprobe_process_filter+0x1d5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d5f;
	}
x86_l_1d4a:
	/* 0x1d4a: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d4d:
	/* 0x1d4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d50:
	/* 0x1d50: je     1d5f <generic_uprobe_process_filter+0x1d5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d5f;
	}
x86_l_1d52:
	/* 0x1d52: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d57:
	/* 0x1d57: or QWORD PTR [rcx+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_1d5f:
	/* 0x1d5f: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_1d63:
	/* 0x1d63: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_1d66:
	/* 0x1d66: cmp    rbx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1d69:
	/* 0x1d69: je     1d72 <generic_uprobe_process_filter+0x1d72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d72;
	}
x86_l_1d6b:
	/* 0x1d6b: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1d6e:
	/* 0x1d6e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1d70:
	/* 0x1d70: je     1d0c <generic_uprobe_process_filter+0x1d0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d0c;
	}
x86_l_1d72:
	/* 0x1d72: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d77:
	/* 0x1d77: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    QWORD PTR [r15+0x378],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 888ULL);
x86_l_1d86:
	/* 0x1d86: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d8a:
	/* 0x1d8a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1d8f:
	/* 0x1d8f: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1d92:
	/* 0x1d92: je     1dad <generic_uprobe_process_filter+0x1dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dad;
	}
x86_l_1d94:
	/* 0x1d94: mov    rcx,QWORD PTR [r15+0x370] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 880ULL);
x86_l_1d9b:
	/* 0x1d9b: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1d9f:
	/* 0x1d9f: jae    1dad <generic_uprobe_process_filter+0x1dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1dad;
	}
x86_l_1da1:
	/* 0x1da1: movabs rax,0xbadc0ffee */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 50159747054ULL);
x86_l_1dab:
	/* 0x1dab: jmp    1dd7 <generic_uprobe_process_filter+0x1dd7> */
	goto x86_l_1dd7;
x86_l_1dad:
	/* 0x1dad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1db2:
	/* 0x1db2: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_paths)));
x86_l_1db9:
	/* 0x1db9: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1dbe:
	/* 0x1dbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc0:
	/* 0x1dc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dc3:
	/* 0x1dc3: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_1dc9:
	/* 0x1dc9: lea    rsi,[r15+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1dd2:
	/* 0x1dd2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1dd5:
	/* 0x1dd5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1dd7:
	/* 0x1dd7: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ddb:
	/* 0x1ddb: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1de4:
	/* 0x1de4: ja     1e04 <generic_uprobe_process_filter+0x1e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e04;
	}
x86_l_1de6:
	/* 0x1de6: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1df0:
	/* 0x1df0: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1df4:
	/* 0x1df4: jae    1e04 <generic_uprobe_process_filter+0x1e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e04;
	}
x86_l_1df6:
	/* 0x1df6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1df9:
	/* 0x1df9: jne    223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8765ULL;
	}
x86_l_1dff:
	/* 0x1dff: jmp    e84 <generic_uprobe_process_filter+0xe84> */
	return 3716ULL;
x86_l_1e04:
	/* 0x1e04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e07:
	/* 0x1e07: jne    e84 <generic_uprobe_process_filter+0xe84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3716ULL;
	}
x86_l_1e0d:
	/* 0x1e0d: jmp    223d <generic_uprobe_process_filter+0x223d> */
	return 8765ULL;
x86_l_1e12:
	/* 0x1e12: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1e19:
	/* 0x1e19: test   bl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 2ULL);
x86_l_1e1c:
	/* 0x1e1c: jne    1e55 <generic_uprobe_process_filter+0x1e55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e55;
	}
x86_l_1e1e:
	/* 0x1e1e: mov    edx,DWORD PTR [rax+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1e21:
	/* 0x1e21: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1e23:
	/* 0x1e23: je     1e4e <generic_uprobe_process_filter+0x1e4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e4e;
	}
x86_l_1e25:
	/* 0x1e25: cmp    edx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e29:
	/* 0x1e29: je     1e55 <generic_uprobe_process_filter+0x1e55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e55;
	}
x86_l_1e2b:
	/* 0x1e2b: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_1e30:
	/* 0x1e30: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1e37:
	/* 0x1e37: test   bl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 2ULL);
x86_l_1e3a:
	/* 0x1e3a: je     1e73 <generic_uprobe_process_filter+0x1e73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e73;
	}
x86_l_1e3c:
	/* 0x1e3c: mov    edx,DWORD PTR [rax+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1e3f:
	/* 0x1e3f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1e41:
	/* 0x1e41: je     1e6c <generic_uprobe_process_filter+0x1e6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e6c;
	}
x86_l_1e43:
	/* 0x1e43: cmp    edx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e47:
	/* 0x1e47: je     1e73 <generic_uprobe_process_filter+0x1e73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e73;
	}
x86_l_1e49:
	/* 0x1e49: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_1e4e:
	/* 0x1e4e: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1e55:
	/* 0x1e55: test   bl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 4ULL);
x86_l_1e58:
	/* 0x1e58: jne    1e91 <generic_uprobe_process_filter+0x1e91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e91;
	}
x86_l_1e5a:
	/* 0x1e5a: mov    edx,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e5d:
	/* 0x1e5d: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1e5f:
	/* 0x1e5f: je     1e8a <generic_uprobe_process_filter+0x1e8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e8a;
	}
x86_l_1e61:
	/* 0x1e61: cmp    edx,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 40ULL);
x86_l_1e65:
	/* 0x1e65: je     1e91 <generic_uprobe_process_filter+0x1e91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e91;
	}
x86_l_1e67:
	/* 0x1e67: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_1e6c:
	/* 0x1e6c: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1e73:
	/* 0x1e73: test   bl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 4ULL);
x86_l_1e76:
	/* 0x1e76: je     1ebb <generic_uprobe_process_filter+0x1ebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ebb;
	}
x86_l_1e78:
	/* 0x1e78: mov    edx,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e7b:
	/* 0x1e7b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1e7d:
	/* 0x1e7d: je     1eb4 <generic_uprobe_process_filter+0x1eb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eb4;
	}
x86_l_1e7f:
	/* 0x1e7f: cmp    edx,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 40ULL);
x86_l_1e83:
	/* 0x1e83: je     1ebb <generic_uprobe_process_filter+0x1ebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ebb;
	}
x86_l_1e85:
	/* 0x1e85: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_1e8a:
	/* 0x1e8a: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1e91:
	/* 0x1e91: test   bl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 8ULL);
x86_l_1e94:
	/* 0x1e94: jne    1ff3 <generic_uprobe_process_filter+0x1ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ff3;
	}
x86_l_1e9a:
	/* 0x1e9a: mov    edx,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1e9d:
	/* 0x1e9d: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1e9f:
	/* 0x1e9f: je     1fec <generic_uprobe_process_filter+0x1fec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fec;
	}
x86_l_1ea5:
	/* 0x1ea5: cmp    edx,DWORD PTR [r14+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1ea9:
	/* 0x1ea9: je     1ff3 <generic_uprobe_process_filter+0x1ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff3;
	}
x86_l_1eaf:
	/* 0x1eaf: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_1eb4:
	/* 0x1eb4: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1ebb:
	/* 0x1ebb: test   bl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 8ULL);
x86_l_1ebe:
	/* 0x1ebe: je     2011 <generic_uprobe_process_filter+0x2011> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2011;
	}
x86_l_1ec4:
	/* 0x1ec4: mov    edx,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1ec7:
	/* 0x1ec7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1ec9:
	/* 0x1ec9: je     200a <generic_uprobe_process_filter+0x200a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_200a;
	}
x86_l_1ecf:
	/* 0x1ecf: cmp    edx,DWORD PTR [r14+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1ed3:
	/* 0x1ed3: je     2011 <generic_uprobe_process_filter+0x2011> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2011;
	}
x86_l_1ed9:
	/* 0x1ed9: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_1ede:
	/* 0x1ede: mov    r12d,0x3ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_1ee4:
	/* 0x1ee4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee7:
	/* 0x1ee7: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eec:
	/* 0x1eec: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eef:
	/* 0x1eef: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ef3:
	/* 0x1ef3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ef8:
	/* 0x1ef8: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1eff:
	/* 0x1eff: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f04:
	/* 0x1f04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f06:
	/* 0x1f06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f09:
	/* 0x1f09: je     1f48 <generic_uprobe_process_filter+0x1f48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f48;
	}
x86_l_1f0b:
	/* 0x1f0b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1f0e:
	/* 0x1f0e: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f12:
	/* 0x1f12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f17:
	/* 0x1f17: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_1f1e:
	/* 0x1f1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f20:
	/* 0x1f20: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f23:
	/* 0x1f23: je     1f35 <generic_uprobe_process_filter+0x1f35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f35;
	}
x86_l_1f25:
	/* 0x1f25: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f28:
	/* 0x1f28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f2b:
	/* 0x1f2b: je     1f35 <generic_uprobe_process_filter+0x1f35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f35;
	}
x86_l_1f2d:
	/* 0x1f2d: or QWORD PTR [r13+0x308],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 776ULL);
x86_l_1f35:
	/* 0x1f35: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_1f39:
	/* 0x1f39: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_1f3c:
	/* 0x1f3c: cmp    rbx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1f3f:
	/* 0x1f3f: je     1f48 <generic_uprobe_process_filter+0x1f48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f48;
	}
x86_l_1f41:
	/* 0x1f41: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1f44:
	/* 0x1f44: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1f46:
	/* 0x1f46: je     1ee7 <generic_uprobe_process_filter+0x1ee7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ee7;
	}
x86_l_1f48:
	/* 0x1f48: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f4d:
	/* 0x1f4d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f50:
	/* 0x1f50: mov    QWORD PTR [r13+0x310],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 784ULL);
x86_l_1f57:
	/* 0x1f57: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f5c:
	/* 0x1f5c: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f61:
	/* 0x1f61: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1f66:
	/* 0x1f66: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1f69:
	/* 0x1f69: je     1f84 <generic_uprobe_process_filter+0x1f84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f84;
	}
x86_l_1f6b:
	/* 0x1f6b: mov    rcx,QWORD PTR [r13+0x308] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 776ULL);
x86_l_1f72:
	/* 0x1f72: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1f76:
	/* 0x1f76: jae    1f84 <generic_uprobe_process_filter+0x1f84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f84;
	}
x86_l_1f78:
	/* 0x1f78: movabs rax,0xbadc0ffee */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 50159747054ULL);
x86_l_1f82:
	/* 0x1f82: jmp    1fb1 <generic_uprobe_process_filter+0x1fb1> */
	goto x86_l_1fb1;
x86_l_1f84:
	/* 0x1f84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f89:
	/* 0x1f89: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_paths)));
x86_l_1f90:
	/* 0x1f90: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f95:
	/* 0x1f95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f97:
	/* 0x1f97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f9a:
	/* 0x1f9a: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8765ULL;
	}
x86_l_1fa0:
	/* 0x1fa0: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1fa4:
	/* 0x1fa4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1fa9:
	/* 0x1fa9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1fac:
	/* 0x1fac: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1faf:
	/* 0x1faf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1fb1:
	/* 0x1fb1: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fb5:
	/* 0x1fb5: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1fb9:
	/* 0x1fb9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fbe:
	/* 0x1fbe: ja     1fde <generic_uprobe_process_filter+0x1fde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fde;
	}
x86_l_1fc0:
	/* 0x1fc0: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1fca:
	/* 0x1fca: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1fce:
	/* 0x1fce: jae    1fde <generic_uprobe_process_filter+0x1fde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fde;
	}
x86_l_1fd0:
	/* 0x1fd0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fd3:
	/* 0x1fd3: jne    223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8765ULL;
	}
x86_l_1fd9:
	/* 0x1fd9: jmp    10b8 <generic_uprobe_process_filter+0x10b8> */
	return 4280ULL;
x86_l_1fde:
	/* 0x1fde: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fe1:
	/* 0x1fe1: jne    10b8 <generic_uprobe_process_filter+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4280ULL;
	}
x86_l_1fe7:
	/* 0x1fe7: jmp    223d <generic_uprobe_process_filter+0x223d> */
	return 8765ULL;
x86_l_1fec:
	/* 0x1fec: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1ff3:
	/* 0x1ff3: test   bl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 16ULL);
x86_l_1ff6:
	/* 0x1ff6: jne    202f <generic_uprobe_process_filter+0x202f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_202f;
	}
x86_l_1ff8:
	/* 0x1ff8: mov    edx,DWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ffb:
	/* 0x1ffb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1ffd:
	/* 0x1ffd: je     2028 <generic_uprobe_process_filter+0x2028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2028;
	}
x86_l_1fff:
	/* 0x1fff: cmp    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_2003:
	/* 0x2003: je     202f <generic_uprobe_process_filter+0x202f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_202f;
	}
x86_l_2005:
	/* 0x2005: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_200a:
	/* 0x200a: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2011:
	/* 0x2011: test   bl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 16ULL);
x86_l_2014:
	/* 0x2014: je     204d <generic_uprobe_process_filter+0x204d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_204d;
	}
x86_l_2016:
	/* 0x2016: mov    edx,DWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2019:
	/* 0x2019: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_201b:
	/* 0x201b: je     2046 <generic_uprobe_process_filter+0x2046> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2046;
	}
x86_l_201d:
	/* 0x201d: cmp    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_2021:
	/* 0x2021: je     204d <generic_uprobe_process_filter+0x204d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_204d;
	}
x86_l_2023:
	/* 0x2023: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_2028:
	/* 0x2028: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_202f:
	/* 0x202f: test   bl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 32ULL);
x86_l_2032:
	/* 0x2032: jne    206b <generic_uprobe_process_filter+0x206b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_206b;
	}
x86_l_2034:
	/* 0x2034: mov    edx,DWORD PTR [rax+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2037:
	/* 0x2037: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2039:
	/* 0x2039: je     2064 <generic_uprobe_process_filter+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2064;
	}
x86_l_203b:
	/* 0x203b: cmp    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 52ULL);
x86_l_203f:
	/* 0x203f: je     206b <generic_uprobe_process_filter+0x206b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_206b;
	}
x86_l_2041:
	/* 0x2041: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_2046:
	/* 0x2046: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_204d:
	/* 0x204d: test   bl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 32ULL);
x86_l_2050:
	/* 0x2050: je     2089 <generic_uprobe_process_filter+0x2089> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2089;
	}
x86_l_2052:
	/* 0x2052: mov    edx,DWORD PTR [rax+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2055:
	/* 0x2055: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2057:
	/* 0x2057: je     2082 <generic_uprobe_process_filter+0x2082> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2082;
	}
x86_l_2059:
	/* 0x2059: cmp    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 52ULL);
x86_l_205d:
	/* 0x205d: je     2089 <generic_uprobe_process_filter+0x2089> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2089;
	}
x86_l_205f:
	/* 0x205f: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_2064:
	/* 0x2064: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_206b:
	/* 0x206b: test   bl,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 64ULL);
x86_l_206e:
	/* 0x206e: jne    20a7 <generic_uprobe_process_filter+0x20a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20a7;
	}
x86_l_2070:
	/* 0x2070: mov    edx,DWORD PTR [rax+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2073:
	/* 0x2073: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2075:
	/* 0x2075: je     20a0 <generic_uprobe_process_filter+0x20a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20a0;
	}
x86_l_2077:
	/* 0x2077: cmp    edx,DWORD PTR [r14+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 56ULL);
x86_l_207b:
	/* 0x207b: je     20a7 <generic_uprobe_process_filter+0x20a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20a7;
	}
x86_l_207d:
	/* 0x207d: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_2082:
	/* 0x2082: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2089:
	/* 0x2089: test   bl,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 64ULL);
x86_l_208c:
	/* 0x208c: je     20c4 <generic_uprobe_process_filter+0x20c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c4;
	}
x86_l_208e:
	/* 0x208e: mov    edx,DWORD PTR [rax+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2091:
	/* 0x2091: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2093:
	/* 0x2093: je     20bd <generic_uprobe_process_filter+0x20bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20bd;
	}
x86_l_2095:
	/* 0x2095: cmp    edx,DWORD PTR [r14+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 56ULL);
x86_l_2099:
	/* 0x2099: je     20c4 <generic_uprobe_process_filter+0x20c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c4;
	}
x86_l_209b:
	/* 0x209b: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_20a0:
	/* 0x20a0: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_20a7:
	/* 0x20a7: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_20a9:
	/* 0x20a9: js     20de <generic_uprobe_process_filter+0x20de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8414ULL;
	}
x86_l_20ab:
	/* 0x20ab: mov    edx,DWORD PTR [rax+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_20ae:
	/* 0x20ae: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_20b0:
	/* 0x20b0: je     20d7 <generic_uprobe_process_filter+0x20d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8407ULL;
	}
x86_l_20b2:
	/* 0x20b2: cmp    edx,DWORD PTR [r14+0x3c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_20b6:
	/* 0x20b6: je     20de <generic_uprobe_process_filter+0x20de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8414ULL;
	}
x86_l_20b8:
	/* 0x20b8: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	return 8519ULL;
x86_l_20bd:
	/* 0x20bd: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_20c4:
	/* 0x20c4: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
	return 8390ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8390ULL: goto x86_l_20c6;
	case 8392ULL: goto x86_l_20c8;
	case 8395ULL: goto x86_l_20cb;
	case 8397ULL: goto x86_l_20cd;
	case 8399ULL: goto x86_l_20cf;
	case 8403ULL: goto x86_l_20d3;
	case 8405ULL: goto x86_l_20d5;
	case 8407ULL: goto x86_l_20d7;
	case 8414ULL: goto x86_l_20de;
	case 8420ULL: goto x86_l_20e4;
	case 8422ULL: goto x86_l_20e6;
	case 8425ULL: goto x86_l_20e9;
	case 8427ULL: goto x86_l_20eb;
	case 8429ULL: goto x86_l_20ed;
	case 8433ULL: goto x86_l_20f1;
	case 8435ULL: goto x86_l_20f3;
	case 8437ULL: goto x86_l_20f5;
	case 8444ULL: goto x86_l_20fc;
	case 8450ULL: goto x86_l_2102;
	case 8456ULL: goto x86_l_2108;
	case 8459ULL: goto x86_l_210b;
	case 8461ULL: goto x86_l_210d;
	case 8467ULL: goto x86_l_2113;
	case 8471ULL: goto x86_l_2117;
	case 8477ULL: goto x86_l_211d;
	case 8479ULL: goto x86_l_211f;
	case 8486ULL: goto x86_l_2126;
	case 8492ULL: goto x86_l_212c;
	case 8498ULL: goto x86_l_2132;
	case 8501ULL: goto x86_l_2135;
	case 8503ULL: goto x86_l_2137;
	case 8509ULL: goto x86_l_213d;
	case 8513ULL: goto x86_l_2141;
	case 8519ULL: goto x86_l_2147;
	case 8523ULL: goto x86_l_214b;
	case 8530ULL: goto x86_l_2152;
	case 8533ULL: goto x86_l_2155;
	case 8535ULL: goto x86_l_2157;
	case 8541ULL: goto x86_l_215d;
	case 8546ULL: goto x86_l_2162;
	case 8548ULL: goto x86_l_2164;
	case 8555ULL: goto x86_l_216b;
	case 8558ULL: goto x86_l_216e;
	case 8567ULL: goto x86_l_2177;
	case 8575ULL: goto x86_l_217f;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8591ULL: goto x86_l_218f;
	case 8596ULL: goto x86_l_2194;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8610ULL: goto x86_l_21a2;
	case 8615ULL: goto x86_l_21a7;
	case 8620ULL: goto x86_l_21ac;
	case 8622ULL: goto x86_l_21ae;
	case 8626ULL: goto x86_l_21b2;
	case 8630ULL: goto x86_l_21b6;
	case 8635ULL: goto x86_l_21bb;
	case 8642ULL: goto x86_l_21c2;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8652ULL: goto x86_l_21cc;
	case 8654ULL: goto x86_l_21ce;
	case 8656ULL: goto x86_l_21d0;
	case 8658ULL: goto x86_l_21d2;
	case 8662ULL: goto x86_l_21d6;
	case 8664ULL: goto x86_l_21d8;
	case 8668ULL: goto x86_l_21dc;
	case 8670ULL: goto x86_l_21de;
	case 8672ULL: goto x86_l_21e0;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8691ULL: goto x86_l_21f3;
	case 8694ULL: goto x86_l_21f6;
	case 8697ULL: goto x86_l_21f9;
	case 8699ULL: goto x86_l_21fb;
	case 8702ULL: goto x86_l_21fe;
	case 8704ULL: goto x86_l_2200;
	case 8706ULL: goto x86_l_2202;
	case 8709ULL: goto x86_l_2205;
	case 8711ULL: goto x86_l_2207;
	case 8714ULL: goto x86_l_220a;
	case 8716ULL: goto x86_l_220c;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8739ULL: goto x86_l_2223;
	case 8745ULL: goto x86_l_2229;
	case 8747ULL: goto x86_l_222b;
	case 8750ULL: goto x86_l_222e;
	case 8752ULL: goto x86_l_2230;
	case 8758ULL: goto x86_l_2236;
	case 8765ULL: goto x86_l_223d;
	case 8772ULL: goto x86_l_2244;
	case 8775ULL: goto x86_l_2247;
	case 8782ULL: goto x86_l_224e;
	case 8790ULL: goto x86_l_2256;
	case 8792ULL: goto x86_l_2258;
	case 8797ULL: goto x86_l_225d;
	case 8799ULL: goto x86_l_225f;
	case 8803ULL: goto x86_l_2263;
	case 8807ULL: goto x86_l_2267;
	case 8811ULL: goto x86_l_226b;
	case 8819ULL: goto x86_l_2273;
	case 8827ULL: goto x86_l_227b;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8841ULL: goto x86_l_2289;
	case 8844ULL: goto x86_l_228c;
	case 8846ULL: goto x86_l_228e;
	case 8848ULL: goto x86_l_2290;
	case 8850ULL: goto x86_l_2292;
	case 8857ULL: goto x86_l_2299;
	case 8859ULL: goto x86_l_229b;
	case 8860ULL: goto x86_l_229c;
	case 8865ULL: goto x86_l_22a1;
	case 8870ULL: goto x86_l_22a6;
	case 8877ULL: goto x86_l_22ad;
	case 8885ULL: goto x86_l_22b5;
	case 8890ULL: goto x86_l_22ba;
	case 8892ULL: goto x86_l_22bc;
	case 8894ULL: goto x86_l_22be;
	case 8896ULL: goto x86_l_22c0;
	case 8898ULL: goto x86_l_22c2;
	case 8899ULL: goto x86_l_22c3;
	case 8903ULL: goto x86_l_22c7;
	case 8906ULL: goto x86_l_22ca;
	case 8910ULL: goto x86_l_22ce;
	case 8914ULL: goto x86_l_22d2;
	case 8918ULL: goto x86_l_22d6;
	case 8921ULL: goto x86_l_22d9;
	case 8923ULL: goto x86_l_22db;
	case 8927ULL: goto x86_l_22df;
	case 8933ULL: goto x86_l_22e5;
	case 8938ULL: goto x86_l_22ea;
	case 8943ULL: goto x86_l_22ef;
	case 8948ULL: goto x86_l_22f4;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8961ULL: goto x86_l_2301;
	case 8965ULL: goto x86_l_2305;
	case 8970ULL: goto x86_l_230a;
	case 8975ULL: goto x86_l_230f;
	case 8980ULL: goto x86_l_2314;
	case 8983ULL: goto x86_l_2317;
	case 8985ULL: goto x86_l_2319;
	case 8990ULL: goto x86_l_231e;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9011ULL: goto x86_l_2333;
	case 9014ULL: goto x86_l_2336;
	case 9016ULL: goto x86_l_2338;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9030ULL: goto x86_l_2346;
	case 9035ULL: goto x86_l_234b;
	case 9038ULL: goto x86_l_234e;
	case 9040ULL: goto x86_l_2350;
	case 9044ULL: goto x86_l_2354;
	case 9048ULL: goto x86_l_2358;
	case 9052ULL: goto x86_l_235c;
	case 9055ULL: goto x86_l_235f;
	case 9058ULL: goto x86_l_2362;
	case 9060ULL: goto x86_l_2364;
	case 9062ULL: goto x86_l_2366;
	case 9064ULL: goto x86_l_2368;
	case 9067ULL: goto x86_l_236b;
	case 9072ULL: goto x86_l_2370;
	case 9075ULL: goto x86_l_2373;
	case 9077ULL: goto x86_l_2375;
	case 9081ULL: goto x86_l_2379;
	case 9084ULL: goto x86_l_237c;
	case 9088ULL: goto x86_l_2380;
	case 9091ULL: goto x86_l_2383;
	case 9093ULL: goto x86_l_2385;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9107ULL: goto x86_l_2393;
	case 9113ULL: goto x86_l_2399;
	case 9120ULL: goto x86_l_23a0;
	case 9126ULL: goto x86_l_23a6;
	case 9128ULL: goto x86_l_23a8;
	case 9134ULL: goto x86_l_23ae;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	case 9147ULL: goto x86_l_23bb;
	case 9151ULL: goto x86_l_23bf;
	case 9154ULL: goto x86_l_23c2;
	case 9159ULL: goto x86_l_23c7;
	case 9161ULL: goto x86_l_23c9;
	case 9165ULL: goto x86_l_23cd;
	case 9170ULL: goto x86_l_23d2;
	case 9174ULL: goto x86_l_23d6;
	case 9176ULL: goto x86_l_23d8;
	case 9178ULL: goto x86_l_23da;
	case 9182ULL: goto x86_l_23de;
	case 9187ULL: goto x86_l_23e3;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9199ULL: goto x86_l_23ef;
	case 9203ULL: goto x86_l_23f3;
	case 9208ULL: goto x86_l_23f8;
	case 9210ULL: goto x86_l_23fa;
	case 9214ULL: goto x86_l_23fe;
	case 9218ULL: goto x86_l_2402;
	case 9223ULL: goto x86_l_2407;
	case 9228ULL: goto x86_l_240c;
	case 9231ULL: goto x86_l_240f;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9242ULL: goto x86_l_241a;
	case 9246ULL: goto x86_l_241e;
	case 9250ULL: goto x86_l_2422;
	case 9252ULL: goto x86_l_2424;
	case 9254ULL: goto x86_l_2426;
	case 9258ULL: goto x86_l_242a;
	case 9263ULL: goto x86_l_242f;
	case 9267ULL: goto x86_l_2433;
	case 9268ULL: goto x86_l_2434;
	case 9270ULL: goto x86_l_2436;
	case 9272ULL: goto x86_l_2438;
	case 9274ULL: goto x86_l_243a;
	case 9275ULL: goto x86_l_243b;
	case 9279ULL: goto x86_l_243f;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9290ULL: goto x86_l_244a;
	case 9292ULL: goto x86_l_244c;
	case 9297ULL: goto x86_l_2451;
	case 9301ULL: goto x86_l_2455;
	default: return 0xffffffffffffffffULL;
	}
x86_l_20c6:
	/* 0x20c6: jns    20fc <generic_uprobe_process_filter+0x20fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_20fc;
	}
x86_l_20c8:
	/* 0x20c8: mov    edx,DWORD PTR [rax+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_20cb:
	/* 0x20cb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_20cd:
	/* 0x20cd: je     20f5 <generic_uprobe_process_filter+0x20f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f5;
	}
x86_l_20cf:
	/* 0x20cf: cmp    edx,DWORD PTR [r14+0x3c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_20d3:
	/* 0x20d3: je     20fc <generic_uprobe_process_filter+0x20fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20fc;
	}
x86_l_20d5:
	/* 0x20d5: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	goto x86_l_2147;
x86_l_20d7:
	/* 0x20d7: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_20de:
	/* 0x20de: test   ebx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_32, 256ULL);
x86_l_20e4:
	/* 0x20e4: jne    2126 <generic_uprobe_process_filter+0x2126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2126;
	}
x86_l_20e6:
	/* 0x20e6: mov    edx,DWORD PTR [rax+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20e9:
	/* 0x20e9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_20eb:
	/* 0x20eb: je     211f <generic_uprobe_process_filter+0x211f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_211f;
	}
x86_l_20ed:
	/* 0x20ed: cmp    edx,DWORD PTR [r14+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 64ULL);
x86_l_20f1:
	/* 0x20f1: je     2126 <generic_uprobe_process_filter+0x2126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2126;
	}
x86_l_20f3:
	/* 0x20f3: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	goto x86_l_2147;
x86_l_20f5:
	/* 0x20f5: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_20fc:
	/* 0x20fc: test   ebx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_32, 256ULL);
x86_l_2102:
	/* 0x2102: je     2223 <generic_uprobe_process_filter+0x2223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2223;
	}
x86_l_2108:
	/* 0x2108: mov    edx,DWORD PTR [rax+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_210b:
	/* 0x210b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_210d:
	/* 0x210d: je     221c <generic_uprobe_process_filter+0x221c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_221c;
	}
x86_l_2113:
	/* 0x2113: cmp    edx,DWORD PTR [r14+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 64ULL);
x86_l_2117:
	/* 0x2117: je     2223 <generic_uprobe_process_filter+0x2223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2223;
	}
x86_l_211d:
	/* 0x211d: jmp    2147 <generic_uprobe_process_filter+0x2147> */
	goto x86_l_2147;
x86_l_211f:
	/* 0x211f: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2126:
	/* 0x2126: test   ebx,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_32, 512ULL);
x86_l_212c:
	/* 0x212c: jne    223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_223d;
	}
x86_l_2132:
	/* 0x2132: mov    eax,DWORD PTR [rax+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2135:
	/* 0x2135: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2137:
	/* 0x2137: je     2236 <generic_uprobe_process_filter+0x2236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2236;
	}
x86_l_213d:
	/* 0x213d: cmp    eax,DWORD PTR [r14+0x44] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 68ULL);
x86_l_2141:
	/* 0x2141: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223d;
	}
x86_l_2147:
	/* 0x2147: add    r13d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_214b:
	/* 0x214b: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2152:
	/* 0x2152: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2155:
	/* 0x2155: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2157:
	/* 0x2157: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_215d:
	/* 0x215d: cmp    DWORD PTR [rcx+r9*1],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_2162:
	/* 0x2162: jne    218c <generic_uprobe_process_filter+0x218c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_218c;
	}
x86_l_2164:
	/* 0x2164: mov    rax,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_216b:
	/* 0x216b: and    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_216e:
	/* 0x216e: mov    BYTE PTR [r14+rax*1+0x5ec1],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699073ULL);
x86_l_2177:
	/* 0x2177: mov    BYTE PTR [r14+0x5ee0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685249ULL);
x86_l_217f:
	/* 0x217f: mov    BYTE PTR [r14+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_2187:
	/* 0x2187: jmp    223d <generic_uprobe_process_filter+0x223d> */
	goto x86_l_223d;
x86_l_218c:
	/* 0x218c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_218f:
	/* 0x218f: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2194:
	/* 0x2194: mov    r15d,DWORD PTR [rax+r9*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_2198:
	/* 0x2198: mov    ebx,DWORD PTR [rax+r9*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 4ULL);
x86_l_219d:
	/* 0x219d: mov    ebp,DWORD PTR [rax+r9*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 8ULL);
x86_l_21a2:
	/* 0x21a2: mov    r12,QWORD PTR [rax+r9*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 12ULL);
x86_l_21a7:
	/* 0x21a7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_21ac:
	/* 0x21ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ae:
	/* 0x21ae: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_21b2:
	/* 0x21b2: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21b6:
	/* 0x21b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21bb:
	/* 0x21bb: mov    rdi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_21c2:
	/* 0x21c2: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21c7:
	/* 0x21c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c9:
	/* 0x21c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21cc:
	/* 0x21cc: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223d;
	}
x86_l_21ce:
	/* 0x21ce: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_21d0:
	/* 0x21d0: je     21e0 <generic_uprobe_process_filter+0x21e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21e0;
	}
x86_l_21d2:
	/* 0x21d2: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_21d6:
	/* 0x21d6: ja     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_223d;
	}
x86_l_21d8:
	/* 0x21d8: cmp    DWORD PTR [r14+0x44],ebp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_21dc:
	/* 0x21dc: jne    21e6 <generic_uprobe_process_filter+0x21e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21e6;
	}
x86_l_21de:
	/* 0x21de: jmp    223d <generic_uprobe_process_filter+0x223d> */
	goto x86_l_223d;
x86_l_21e0:
	/* 0x21e0: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_21e4:
	/* 0x21e4: ja     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_223d;
	}
x86_l_21e6:
	/* 0x21e6: mov    rax,QWORD PTR [rax+r15*8+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 80ULL);
x86_l_21eb:
	/* 0x21eb: mov    rcx,QWORD PTR [r14+r15*8+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 72ULL);
x86_l_21f0:
	/* 0x21f0: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_21f3:
	/* 0x21f3: xor    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_21f6:
	/* 0x21f6: test   rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21f9:
	/* 0x21f9: je     2202 <generic_uprobe_process_filter+0x2202> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2202;
	}
x86_l_21fb:
	/* 0x21fb: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_21fe:
	/* 0x21fe: jne    223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_223d;
	}
x86_l_2200:
	/* 0x2200: jmp    220c <generic_uprobe_process_filter+0x220c> */
	goto x86_l_220c;
x86_l_2202:
	/* 0x2202: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2205:
	/* 0x2205: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223d;
	}
x86_l_2207:
	/* 0x2207: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_220a:
	/* 0x220a: jne    223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_223d;
	}
x86_l_220c:
	/* 0x220c: mov    QWORD PTR [r14+0x5ef0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161985ULL);
x86_l_2217:
	/* 0x2217: jmp    2164 <generic_uprobe_process_filter+0x2164> */
	goto x86_l_2164;
x86_l_221c:
	/* 0x221c: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2223:
	/* 0x2223: test   ebx,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_32, 512ULL);
x86_l_2229:
	/* 0x2229: je     223d <generic_uprobe_process_filter+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223d;
	}
x86_l_222b:
	/* 0x222b: mov    eax,DWORD PTR [rax+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_222e:
	/* 0x222e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2230:
	/* 0x2230: jne    213d <generic_uprobe_process_filter+0x213d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_213d;
	}
x86_l_2236:
	/* 0x2236: mov    QWORD PTR [rcx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_223d:
	/* 0x223d: mov    rax,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_2244:
	/* 0x2244: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2247:
	/* 0x2247: mov    QWORD PTR [r14+0x5eb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_224e:
	/* 0x224e: cmp    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 192ULL);
x86_l_2256:
	/* 0x2256: jbe    22a1 <generic_uprobe_process_filter+0x22a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_22a1;
	}
x86_l_2258:
	/* 0x2258: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_225d:
	/* 0x225d: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225f:
	/* 0x225f: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2263:
	/* 0x2263: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2267:
	/* 0x2267: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_226b:
	/* 0x226b: cmp    BYTE PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_2273:
	/* 0x2273: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_227b:
	/* 0x227b: je     2290 <generic_uprobe_process_filter+0x2290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2290;
	}
x86_l_227d:
	/* 0x227d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2282:
	/* 0x2282: mov    rsi,QWORD PTR [rip+0x30c1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_2289:
	/* 0x2289: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_228c:
	/* 0x228c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_228e:
	/* 0x228e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2290:
	/* 0x2290: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2292:
	/* 0x2292: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_2299:
	/* 0x2299: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_229b:
	/* 0x229b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_229c:
	/* 0x229c: jmp    2457 <cwd_read_v61+0x19b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_22a1:
	/* 0x22a1: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_22a6:
	/* 0x22a6: mov    rsi,QWORD PTR [rip+0x30c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_22ad:
	/* 0x22ad: mov    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_22b5:
	/* 0x22b5: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_22ba:
	/* 0x22ba: jmp    228e <generic_uprobe_process_filter+0x228e> */
	goto x86_l_228e;
x86_l_22bc:
	/* 0x22bc: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_22be:
	/* 0x22be: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_22c0:
	/* 0x22c0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_22c2:
	/* 0x22c2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_22c3:
	/* 0x22c3: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_22c7:
	/* 0x22c7: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_22ca:
	/* 0x22ca: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22ce:
	/* 0x22ce: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22d2:
	/* 0x22d2: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22d6:
	/* 0x22d6: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_22d9:
	/* 0x22d9: jne    22e5 <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22e5;
	}
x86_l_22db:
	/* 0x22db: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_22df:
	/* 0x22df: je     2426 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2426;
	}
x86_l_22e5:
	/* 0x22e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22ea:
	/* 0x22ea: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22ef:
	/* 0x22ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f4:
	/* 0x22f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f6:
	/* 0x22f6: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_22fb:
	/* 0x22fb: je     23da <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23da;
	}
x86_l_2301:
	/* 0x2301: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2305:
	/* 0x2305: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_230a:
	/* 0x230a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_230f:
	/* 0x230f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2314:
	/* 0x2314: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2317:
	/* 0x2317: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2319:
	/* 0x2319: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_231e:
	/* 0x231e: je     23da <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23da;
	}
x86_l_2324:
	/* 0x2324: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2329:
	/* 0x2329: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_232e:
	/* 0x232e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2333:
	/* 0x2333: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2336:
	/* 0x2336: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2338:
	/* 0x2338: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_233c:
	/* 0x233c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2341:
	/* 0x2341: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2346:
	/* 0x2346: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_234b:
	/* 0x234b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_234e:
	/* 0x234e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2350:
	/* 0x2350: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2354:
	/* 0x2354: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2358:
	/* 0x2358: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_235c:
	/* 0x235c: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_235f:
	/* 0x235f: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2362:
	/* 0x2362: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2364:
	/* 0x2364: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2366:
	/* 0x2366: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2368:
	/* 0x2368: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_236b:
	/* 0x236b: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2370:
	/* 0x2370: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2373:
	/* 0x2373: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2375:
	/* 0x2375: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_2379:
	/* 0x2379: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_237c:
	/* 0x237c: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2380:
	/* 0x2380: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2383:
	/* 0x2383: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_2385:
	/* 0x2385: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2388:
	/* 0x2388: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_238b:
	/* 0x238b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2390:
	/* 0x2390: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2393:
	/* 0x2393: jb     242f <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_242f;
	}
x86_l_2399:
	/* 0x2399: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_23a0:
	/* 0x23a0: ja     242f <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_242f;
	}
x86_l_23a6:
	/* 0x23a6: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_23a8:
	/* 0x23a8: jbe    243b <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_243b;
	}
x86_l_23ae:
	/* 0x23ae: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_23b2:
	/* 0x23b2: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_23b7:
	/* 0x23b7: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23bb:
	/* 0x23bb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_23bf:
	/* 0x23bf: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_23c2:
	/* 0x23c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23c7:
	/* 0x23c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c9:
	/* 0x23c9: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23cd:
	/* 0x23cd: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23d2:
	/* 0x23d2: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23d6:
	/* 0x23d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23d8:
	/* 0x23d8: jmp    242f <cwd_read_v61+0x173> */
	goto x86_l_242f;
x86_l_23da:
	/* 0x23da: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23de:
	/* 0x23de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23e3:
	/* 0x23e3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23e8:
	/* 0x23e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23ed:
	/* 0x23ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ef:
	/* 0x23ef: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23f3:
	/* 0x23f3: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_23f8:
	/* 0x23f8: je     2426 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2426;
	}
x86_l_23fa:
	/* 0x23fa: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23fe:
	/* 0x23fe: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2402:
	/* 0x2402: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2407:
	/* 0x2407: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_240c:
	/* 0x240c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_240f:
	/* 0x240f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2411:
	/* 0x2411: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2416:
	/* 0x2416: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_241a:
	/* 0x241a: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_241e:
	/* 0x241e: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2422:
	/* 0x2422: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2424:
	/* 0x2424: jmp    242f <cwd_read_v61+0x173> */
	goto x86_l_242f;
x86_l_2426:
	/* 0x2426: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_242a:
	/* 0x242a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_242f:
	/* 0x242f: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2433:
	/* 0x2433: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2434:
	/* 0x2434: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2436:
	/* 0x2436: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2438:
	/* 0x2438: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_243a:
	/* 0x243a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_243b:
	/* 0x243b: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_243f:
	/* 0x243f: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2442:
	/* 0x2442: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2447:
	/* 0x2447: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_244a:
	/* 0x244a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244c:
	/* 0x244c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2451:
	/* 0x2451: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2455:
	/* 0x2455: jmp    242f <cwd_read_v61+0x173> */
	goto x86_l_242f;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 8612U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1903ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1908ULL && __x86_pc <= 3698ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3702ULL && __x86_pc <= 5334ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5337ULL && __x86_pc <= 6855ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6858ULL && __x86_pc <= 8388ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8390ULL && __x86_pc <= 9301ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_generic_uprobe_process_filter_x86_chunk_5(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

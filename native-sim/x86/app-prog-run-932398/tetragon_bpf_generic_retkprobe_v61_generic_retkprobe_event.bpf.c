extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char execve_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char retkprobe_calls;
extern char retprobe_map;
extern char socktrack_map;
extern char tg_ipv6_ext_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 17ULL: goto x86_l_11;
	case 25ULL: goto x86_l_19;
	case 36ULL: goto x86_l_24;
	case 41ULL: goto x86_l_29;
	case 48ULL: goto x86_l_30;
	case 56ULL: goto x86_l_38;
	case 58ULL: goto x86_l_3a;
	case 60ULL: goto x86_l_3c;
	case 63ULL: goto x86_l_3f;
	case 69ULL: goto x86_l_45;
	case 72ULL: goto x86_l_48;
	case 75ULL: goto x86_l_4b;
	case 82ULL: goto x86_l_52;
	case 94ULL: goto x86_l_5e;
	case 99ULL: goto x86_l_63;
	case 106ULL: goto x86_l_6a;
	case 108ULL: goto x86_l_6c;
	case 111ULL: goto x86_l_6f;
	case 117ULL: goto x86_l_75;
	case 120ULL: goto x86_l_78;
	case 122ULL: goto x86_l_7a;
	case 126ULL: goto x86_l_7e;
	case 131ULL: goto x86_l_83;
	case 133ULL: goto x86_l_85;
	case 137ULL: goto x86_l_89;
	case 139ULL: goto x86_l_8b;
	case 143ULL: goto x86_l_8f;
	case 147ULL: goto x86_l_93;
	case 152ULL: goto x86_l_98;
	case 154ULL: goto x86_l_9a;
	case 157ULL: goto x86_l_9d;
	case 161ULL: goto x86_l_a1;
	case 165ULL: goto x86_l_a5;
	case 170ULL: goto x86_l_aa;
	case 175ULL: goto x86_l_af;
	case 180ULL: goto x86_l_b4;
	case 187ULL: goto x86_l_bb;
	case 192ULL: goto x86_l_c0;
	case 194ULL: goto x86_l_c2;
	case 197ULL: goto x86_l_c5;
	case 203ULL: goto x86_l_cb;
	case 206ULL: goto x86_l_ce;
	case 210ULL: goto x86_l_d2;
	case 218ULL: goto x86_l_da;
	case 222ULL: goto x86_l_de;
	case 230ULL: goto x86_l_e6;
	case 235ULL: goto x86_l_eb;
	case 242ULL: goto x86_l_f2;
	case 247ULL: goto x86_l_f7;
	case 249ULL: goto x86_l_f9;
	case 256ULL: goto x86_l_100;
	case 260ULL: goto x86_l_104;
	case 264ULL: goto x86_l_108;
	case 267ULL: goto x86_l_10b;
	case 269ULL: goto x86_l_10d;
	case 273ULL: goto x86_l_111;
	case 283ULL: goto x86_l_11b;
	case 291ULL: goto x86_l_123;
	case 302ULL: goto x86_l_12e;
	case 307ULL: goto x86_l_133;
	case 314ULL: goto x86_l_13a;
	case 322ULL: goto x86_l_142;
	case 324ULL: goto x86_l_144;
	case 327ULL: goto x86_l_147;
	case 333ULL: goto x86_l_14d;
	case 339ULL: goto x86_l_153;
	case 345ULL: goto x86_l_159;
	case 356ULL: goto x86_l_164;
	case 358ULL: goto x86_l_166;
	case 364ULL: goto x86_l_16c;
	case 370ULL: goto x86_l_172;
	case 375ULL: goto x86_l_177;
	case 381ULL: goto x86_l_17d;
	case 388ULL: goto x86_l_184;
	case 391ULL: goto x86_l_187;
	case 399ULL: goto x86_l_18f;
	case 405ULL: goto x86_l_195;
	case 413ULL: goto x86_l_19d;
	case 417ULL: goto x86_l_1a1;
	case 426ULL: goto x86_l_1aa;
	case 434ULL: goto x86_l_1b2;
	case 439ULL: goto x86_l_1b7;
	case 445ULL: goto x86_l_1bd;
	case 450ULL: goto x86_l_1c2;
	case 458ULL: goto x86_l_1ca;
	case 464ULL: goto x86_l_1d0;
	case 469ULL: goto x86_l_1d5;
	case 474ULL: goto x86_l_1da;
	case 479ULL: goto x86_l_1df;
	case 487ULL: goto x86_l_1e7;
	case 489ULL: goto x86_l_1e9;
	case 494ULL: goto x86_l_1ee;
	case 496ULL: goto x86_l_1f0;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 510ULL: goto x86_l_1fe;
	case 513ULL: goto x86_l_201;
	case 517ULL: goto x86_l_205;
	case 520ULL: goto x86_l_208;
	case 524ULL: goto x86_l_20c;
	case 529ULL: goto x86_l_211;
	case 536ULL: goto x86_l_218;
	case 542ULL: goto x86_l_21e;
	case 545ULL: goto x86_l_221;
	case 549ULL: goto x86_l_225;
	case 554ULL: goto x86_l_22a;
	case 558ULL: goto x86_l_22e;
	case 562ULL: goto x86_l_232;
	case 567ULL: goto x86_l_237;
	case 572ULL: goto x86_l_23c;
	case 575ULL: goto x86_l_23f;
	case 577ULL: goto x86_l_241;
	case 582ULL: goto x86_l_246;
	case 584ULL: goto x86_l_248;
	case 590ULL: goto x86_l_24e;
	case 593ULL: goto x86_l_251;
	case 596ULL: goto x86_l_254;
	case 602ULL: goto x86_l_25a;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 615ULL: goto x86_l_267;
	case 621ULL: goto x86_l_26d;
	case 626ULL: goto x86_l_272;
	case 629ULL: goto x86_l_275;
	case 633ULL: goto x86_l_279;
	case 637ULL: goto x86_l_27d;
	case 641ULL: goto x86_l_281;
	case 644ULL: goto x86_l_284;
	case 650ULL: goto x86_l_28a;
	case 653ULL: goto x86_l_28d;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 666ULL: goto x86_l_29a;
	case 669ULL: goto x86_l_29d;
	case 673ULL: goto x86_l_2a1;
	case 677ULL: goto x86_l_2a5;
	case 682ULL: goto x86_l_2aa;
	case 687ULL: goto x86_l_2af;
	case 694ULL: goto x86_l_2b6;
	case 702ULL: goto x86_l_2be;
	case 707ULL: goto x86_l_2c3;
	case 709ULL: goto x86_l_2c5;
	case 711ULL: goto x86_l_2c7;
	case 716ULL: goto x86_l_2cc;
	case 723ULL: goto x86_l_2d3;
	case 728ULL: goto x86_l_2d8;
	case 737ULL: goto x86_l_2e1;
	case 741ULL: goto x86_l_2e5;
	case 745ULL: goto x86_l_2e9;
	case 753ULL: goto x86_l_2f1;
	case 755ULL: goto x86_l_2f3;
	case 759ULL: goto x86_l_2f7;
	case 761ULL: goto x86_l_2f9;
	case 765ULL: goto x86_l_2fd;
	case 771ULL: goto x86_l_303;
	case 775ULL: goto x86_l_307;
	case 781ULL: goto x86_l_30d;
	case 786ULL: goto x86_l_312;
	case 791ULL: goto x86_l_317;
	case 796ULL: goto x86_l_31c;
	case 801ULL: goto x86_l_321;
	case 803ULL: goto x86_l_323;
	case 808ULL: goto x86_l_328;
	case 813ULL: goto x86_l_32d;
	case 815ULL: goto x86_l_32f;
	case 818ULL: goto x86_l_332;
	case 823ULL: goto x86_l_337;
	case 827ULL: goto x86_l_33b;
	case 832ULL: goto x86_l_340;
	case 836ULL: goto x86_l_344;
	case 839ULL: goto x86_l_347;
	case 844ULL: goto x86_l_34c;
	case 848ULL: goto x86_l_350;
	case 854ULL: goto x86_l_356;
	case 858ULL: goto x86_l_35a;
	case 864ULL: goto x86_l_360;
	case 869ULL: goto x86_l_365;
	case 874ULL: goto x86_l_36a;
	case 879ULL: goto x86_l_36f;
	case 881ULL: goto x86_l_371;
	case 893ULL: goto x86_l_37d;
	case 901ULL: goto x86_l_385;
	case 909ULL: goto x86_l_38d;
	case 911ULL: goto x86_l_38f;
	case 915ULL: goto x86_l_393;
	case 920ULL: goto x86_l_398;
	case 925ULL: goto x86_l_39d;
	case 930ULL: goto x86_l_3a2;
	case 935ULL: goto x86_l_3a7;
	case 940ULL: goto x86_l_3ac;
	case 942ULL: goto x86_l_3ae;
	case 947ULL: goto x86_l_3b3;
	case 951ULL: goto x86_l_3b7;
	case 956ULL: goto x86_l_3bc;
	case 961ULL: goto x86_l_3c1;
	case 972ULL: goto x86_l_3cc;
	case 977ULL: goto x86_l_3d1;
	case 984ULL: goto x86_l_3d8;
	case 992ULL: goto x86_l_3e0;
	case 994ULL: goto x86_l_3e2;
	case 997ULL: goto x86_l_3e5;
	case 1003ULL: goto x86_l_3eb;
	case 1006ULL: goto x86_l_3ee;
	case 1012ULL: goto x86_l_3f4;
	case 1017ULL: goto x86_l_3f9;
	case 1022ULL: goto x86_l_3fe;
	case 1024ULL: goto x86_l_400;
	case 1031ULL: goto x86_l_407;
	case 1036ULL: goto x86_l_40c;
	case 1044ULL: goto x86_l_414;
	case 1049ULL: goto x86_l_419;
	case 1051ULL: goto x86_l_41b;
	case 1059ULL: goto x86_l_423;
	case 1063ULL: goto x86_l_427;
	case 1071ULL: goto x86_l_42f;
	case 1076ULL: goto x86_l_434;
	case 1080ULL: goto x86_l_438;
	case 1085ULL: goto x86_l_43d;
	case 1093ULL: goto x86_l_445;
	case 1098ULL: goto x86_l_44a;
	case 1106ULL: goto x86_l_452;
	case 1108ULL: goto x86_l_454;
	case 1116ULL: goto x86_l_45c;
	case 1120ULL: goto x86_l_460;
	case 1125ULL: goto x86_l_465;
	case 1130ULL: goto x86_l_46a;
	case 1135ULL: goto x86_l_46f;
	case 1137ULL: goto x86_l_471;
	case 1143ULL: goto x86_l_477;
	case 1149ULL: goto x86_l_47d;
	case 1151ULL: goto x86_l_47f;
	case 1156ULL: goto x86_l_484;
	case 1158ULL: goto x86_l_486;
	case 1161ULL: goto x86_l_489;
	case 1166ULL: goto x86_l_48e;
	case 1171ULL: goto x86_l_493;
	case 1175ULL: goto x86_l_497;
	case 1180ULL: goto x86_l_49c;
	case 1185ULL: goto x86_l_4a1;
	case 1190ULL: goto x86_l_4a6;
	case 1192ULL: goto x86_l_4a8;
	case 1197ULL: goto x86_l_4ad;
	case 1202ULL: goto x86_l_4b2;
	case 1204ULL: goto x86_l_4b4;
	case 1207ULL: goto x86_l_4b7;
	case 1214ULL: goto x86_l_4be;
	case 1224ULL: goto x86_l_4c8;
	case 1232ULL: goto x86_l_4d0;
	case 1243ULL: goto x86_l_4db;
	case 1249ULL: goto x86_l_4e1;
	case 1258ULL: goto x86_l_4ea;
	case 1267ULL: goto x86_l_4f3;
	case 1272ULL: goto x86_l_4f8;
	case 1277ULL: goto x86_l_4fd;
	case 1282ULL: goto x86_l_502;
	case 1291ULL: goto x86_l_50b;
	case 1300ULL: goto x86_l_514;
	case 1309ULL: goto x86_l_51d;
	case 1314ULL: goto x86_l_522;
	case 1319ULL: goto x86_l_527;
	case 1324ULL: goto x86_l_52c;
	case 1329ULL: goto x86_l_531;
	case 1334ULL: goto x86_l_536;
	case 1338ULL: goto x86_l_53a;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1353ULL: goto x86_l_549;
	case 1356ULL: goto x86_l_54c;
	case 1358ULL: goto x86_l_54e;
	case 1363ULL: goto x86_l_553;
	case 1366ULL: goto x86_l_556;
	case 1371ULL: goto x86_l_55b;
	case 1379ULL: goto x86_l_563;
	case 1381ULL: goto x86_l_565;
	case 1386ULL: goto x86_l_56a;
	case 1389ULL: goto x86_l_56d;
	case 1394ULL: goto x86_l_572;
	case 1402ULL: goto x86_l_57a;
	case 1404ULL: goto x86_l_57c;
	case 1409ULL: goto x86_l_581;
	case 1412ULL: goto x86_l_584;
	case 1417ULL: goto x86_l_589;
	case 1422ULL: goto x86_l_58e;
	case 1424ULL: goto x86_l_590;
	case 1429ULL: goto x86_l_595;
	case 1433ULL: goto x86_l_599;
	case 1438ULL: goto x86_l_59e;
	case 1445ULL: goto x86_l_5a5;
	case 1448ULL: goto x86_l_5a8;
	case 1454ULL: goto x86_l_5ae;
	case 1460ULL: goto x86_l_5b4;
	case 1465ULL: goto x86_l_5b9;
	case 1470ULL: goto x86_l_5be;
	case 1475ULL: goto x86_l_5c3;
	case 1480ULL: goto x86_l_5c8;
	case 1482ULL: goto x86_l_5ca;
	case 1487ULL: goto x86_l_5cf;
	case 1493ULL: goto x86_l_5d5;
	case 1498ULL: goto x86_l_5da;
	case 1506ULL: goto x86_l_5e2;
	case 1511ULL: goto x86_l_5e7;
	case 1513ULL: goto x86_l_5e9;
	case 1521ULL: goto x86_l_5f1;
	case 1527ULL: goto x86_l_5f7;
	case 1531ULL: goto x86_l_5fb;
	case 1536ULL: goto x86_l_600;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1551ULL: goto x86_l_60f;
	case 1556ULL: goto x86_l_614;
	case 1562ULL: goto x86_l_61a;
	case 1567ULL: goto x86_l_61f;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1583ULL: goto x86_l_62f;
	case 1585ULL: goto x86_l_631;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1599ULL: goto x86_l_63f;
	case 1604ULL: goto x86_l_644;
	case 1607ULL: goto x86_l_647;
	case 1609ULL: goto x86_l_649;
	case 1614ULL: goto x86_l_64e;
	case 1619ULL: goto x86_l_653;
	case 1623ULL: goto x86_l_657;
	case 1626ULL: goto x86_l_65a;
	case 1630ULL: goto x86_l_65e;
	case 1632ULL: goto x86_l_660;
	case 1634ULL: goto x86_l_662;
	case 1639ULL: goto x86_l_667;
	case 1642ULL: goto x86_l_66a;
	case 1647ULL: goto x86_l_66f;
	case 1650ULL: goto x86_l_672;
	case 1652ULL: goto x86_l_674;
	case 1656ULL: goto x86_l_678;
	case 1658ULL: goto x86_l_67a;
	case 1661ULL: goto x86_l_67d;
	case 1664ULL: goto x86_l_680;
	case 1667ULL: goto x86_l_683;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1678ULL: goto x86_l_68e;
	case 1684ULL: goto x86_l_694;
	case 1690ULL: goto x86_l_69a;
	case 1696ULL: goto x86_l_6a0;
	case 1698ULL: goto x86_l_6a2;
	case 1704ULL: goto x86_l_6a8;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1717ULL: goto x86_l_6b5;
	case 1721ULL: goto x86_l_6b9;
	case 1724ULL: goto x86_l_6bc;
	case 1729ULL: goto x86_l_6c1;
	case 1731ULL: goto x86_l_6c3;
	case 1736ULL: goto x86_l_6c8;
	case 1744ULL: goto x86_l_6d0;
	case 1749ULL: goto x86_l_6d5;
	case 1752ULL: goto x86_l_6d8;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1785ULL: goto x86_l_6f9;
	case 1790ULL: goto x86_l_6fe;
	case 1795ULL: goto x86_l_703;
	case 1801ULL: goto x86_l_709;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1823ULL: goto x86_l_71f;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1839ULL: goto x86_l_72f;
	case 1844ULL: goto x86_l_734;
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
	/* 0xa: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    rax,QWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_19:
	/* 0x19: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_24:
	/* 0x24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29:
	/* 0x29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_30:
	/* 0x30: lea    rsi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_38:
	/* 0x38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a:
	/* 0x3a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c:
	/* 0x3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: je     2d0d <generic_retkprobe_event+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_45:
	/* 0x45: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_48:
	/* 0x48: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4b:
	/* 0x4b: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_52:
	/* 0x52: mov    DWORD PTR [r12+0x5ef8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104419244900352ULL);
x86_l_5e:
	/* 0x5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63:
	/* 0x63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_6a:
	/* 0x6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c:
	/* 0x6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: je     2d0d <generic_retkprobe_event+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_75:
	/* 0x75: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_78:
	/* 0x78: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a:
	/* 0x7a: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7e:
	/* 0x7e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_83:
	/* 0x83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85:
	/* 0x85: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_89:
	/* 0x89: jne    8f <generic_retkprobe_event+0x8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8f;
	}
x86_l_8b:
	/* 0x8b: mov    rax,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8f:
	/* 0x8f: mov    QWORD PTR [rbx+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_93:
	/* 0x93: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_98:
	/* 0x98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a:
	/* 0x9a: mov    DWORD PTR [rbx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_9d:
	/* 0x9d: mov    rax,QWORD PTR [rbx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a1:
	/* 0xa1: mov    rcx,QWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a5:
	/* 0xa5: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aa:
	/* 0xaa: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_af:
	/* 0xaf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b4:
	/* 0xb4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_bb:
	/* 0xbb: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c0:
	/* 0xc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2:
	/* 0xc2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c5:
	/* 0xc5: je     2d0d <generic_retkprobe_event+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_cb:
	/* 0xcb: mov    r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce:
	/* 0xce: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d2:
	/* 0xd2: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_da:
	/* 0xda: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de:
	/* 0xde: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e6:
	/* 0xe6: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_eb:
	/* 0xeb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_f2:
	/* 0xf2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f7:
	/* 0xf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9:
	/* 0xf9: mov    QWORD PTR [rbx+0x90],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_100:
	/* 0x100: mov    ebp,DWORD PTR [r15+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_104:
	/* 0x104: mov    r14d,DWORD PTR [r15+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_108:
	/* 0x108: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_10b:
	/* 0x10b: je     177 <generic_retkprobe_event+0x177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_177;
	}
x86_l_10d:
	/* 0x10d: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_111:
	/* 0x111: mov    DWORD PTR [rbx+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_11b:
	/* 0x11b: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_123:
	/* 0x123: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_12e:
	/* 0x12e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_133:
	/* 0x133: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_13a:
	/* 0x13a: lea    rsi,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_142:
	/* 0x142: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144:
	/* 0x144: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_147:
	/* 0x147: je     272 <generic_retkprobe_event+0x272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272;
	}
x86_l_14d:
	/* 0x14d: mov    ecx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_153:
	/* 0x153: mov    DWORD PTR [rax+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_159:
	/* 0x159: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_164:
	/* 0x164: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_166:
	/* 0x166: je     2cc <generic_retkprobe_event+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cc;
	}
x86_l_16c:
	/* 0x16c: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_172:
	/* 0x172: jmp    275 <generic_retkprobe_event+0x275> */
	goto x86_l_275;
x86_l_177:
	/* 0x177: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_17d:
	/* 0x17d: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_184:
	/* 0x184: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_187:
	/* 0x187: mov    QWORD PTR [rsp+0xf0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_18f:
	/* 0x18f: jne    28c0 <generic_retkprobe_event+0x28c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10432ULL;
	}
x86_l_195:
	/* 0x195: mov    DWORD PTR [r12+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_19d:
	/* 0x19d: lea    rbp,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a1:
	/* 0x1a1: cmp    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1aa:
	/* 0x1aa: mov    QWORD PTR [rsp+0xb0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1b2:
	/* 0x1b2: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b7:
	/* 0x1b7: je     32f <generic_retkprobe_event+0x32f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f;
	}
x86_l_1bd:
	/* 0x1bd: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c2:
	/* 0x1c2: mov    r12,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1ca:
	/* 0x1ca: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1d0:
	/* 0x1d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d5:
	/* 0x1d5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1da:
	/* 0x1da: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1df:
	/* 0x1df: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e7:
	/* 0x1e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9:
	/* 0x1e9: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1ee:
	/* 0x1ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f0:
	/* 0x1f0: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10946ULL;
	}
x86_l_1f6:
	/* 0x1f6: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1fb:
	/* 0x1fb: cmp    rsi,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1fe:
	/* 0x1fe: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_201:
	/* 0x201: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_205:
	/* 0x205: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_208:
	/* 0x208: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_20c:
	/* 0x20c: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_211:
	/* 0x211: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_218:
	/* 0x218: ja     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10946ULL;
	}
x86_l_21e:
	/* 0x21e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_221:
	/* 0x221: add    r14,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_225:
	/* 0x225: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22a:
	/* 0x22a: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e:
	/* 0x22e: lea    rdi,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_232:
	/* 0x232: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_237:
	/* 0x237: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23c:
	/* 0x23c: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_23f:
	/* 0x23f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241:
	/* 0x241: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_246:
	/* 0x246: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_248:
	/* 0x248: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10946ULL;
	}
x86_l_24e:
	/* 0x24e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_251:
	/* 0x251: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_254:
	/* 0x254: je     9b3 <generic_retkprobe_event+0x9b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2483ULL;
	}
x86_l_25a:
	/* 0x25a: sub    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_25d:
	/* 0x25d: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_262:
	/* 0x262: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_267:
	/* 0x267: jne    9bf <generic_retkprobe_event+0x9bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2495ULL;
	}
x86_l_26d:
	/* 0x26d: jmp    332 <generic_retkprobe_event+0x332> */
	goto x86_l_332;
x86_l_272:
	/* 0x272: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_275:
	/* 0x275: mov    ebp,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_279:
	/* 0x279: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_27d:
	/* 0x27d: mov    eax,DWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_281:
	/* 0x281: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_284:
	/* 0x284: je     288b <generic_retkprobe_event+0x288b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10379ULL;
	}
x86_l_28a:
	/* 0x28a: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_28d:
	/* 0x28d: jne    28a1 <generic_retkprobe_event+0x28a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10401ULL;
	}
x86_l_293:
	/* 0x293: mov    eax,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_296:
	/* 0x296: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29a:
	/* 0x29a: mov    eax,DWORD PTR [rbx+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_29d:
	/* 0x29d: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2a1:
	/* 0x2a1: mov    rax,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a5:
	/* 0x2a5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2aa:
	/* 0x2aa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2af:
	/* 0x2af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2b6:
	/* 0x2b6: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2be:
	/* 0x2be: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c3:
	/* 0x2c3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c5:
	/* 0x2c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7:
	/* 0x2c7: jmp    28a1 <generic_retkprobe_event+0x28a1> */
	return 10401ULL;
x86_l_2cc:
	/* 0x2cc: lea    rcx,[rax+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_2d3:
	/* 0x2d3: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d8:
	/* 0x2d8: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2e1:
	/* 0x2e1: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_2e5:
	/* 0x2e5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e9:
	/* 0x2e9: mov    QWORD PTR [rsp+0xb0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2f1:
	/* 0x2f1: jle    34c <generic_retkprobe_event+0x34c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_34c;
	}
x86_l_2f3:
	/* 0x2f3: cmp    r14d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 42ULL);
x86_l_2f7:
	/* 0x2f7: je     371 <generic_retkprobe_event+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_2f9:
	/* 0x2f9: cmp    r14d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 37ULL);
x86_l_2fd:
	/* 0x2fd: je     38f <generic_retkprobe_event+0x38f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38f;
	}
x86_l_303:
	/* 0x303: cmp    r14d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 24ULL);
x86_l_307:
	/* 0x307: jne    811 <generic_retkprobe_event+0x811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2065ULL;
	}
x86_l_30d:
	/* 0x30d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_312:
	/* 0x312: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_317:
	/* 0x317: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31c:
	/* 0x31c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_321:
	/* 0x321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_323:
	/* 0x323: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_328:
	/* 0x328: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32d:
	/* 0x32d: jmp    360 <generic_retkprobe_event+0x360> */
	goto x86_l_360;
x86_l_32f:
	/* 0x32f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_332:
	/* 0x332: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_337:
	/* 0x337: mov    DWORD PTR [rax+rbp*1],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_33b:
	/* 0x33b: mov    DWORD PTR [rax+rbp*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_340:
	/* 0x340: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_344:
	/* 0x344: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_347:
	/* 0x347: jmp    2acf <generic_retkprobe_event+0x2acf> */
	return 10959ULL;
x86_l_34c:
	/* 0x34c: cmp    r14d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 15ULL);
x86_l_350:
	/* 0x350: je     761 <generic_retkprobe_event+0x761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1889ULL;
	}
x86_l_356:
	/* 0x356: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_35a:
	/* 0x35a: jne    811 <generic_retkprobe_event+0x811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2065ULL;
	}
x86_l_360:
	/* 0x360: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_365:
	/* 0x365: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36a:
	/* 0x36a: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36f:
	/* 0x36f: jmp    3a7 <generic_retkprobe_event+0x3a7> */
	goto x86_l_3a7;
x86_l_371:
	/* 0x371: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_37d:
	/* 0x37d: mov    QWORD PTR [rsp+0x90],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_385:
	/* 0x385: lea    rax,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_38d:
	/* 0x38d: jmp    3b7 <generic_retkprobe_event+0x3b7> */
	goto x86_l_3b7;
x86_l_38f:
	/* 0x38f: add    rbp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_393:
	/* 0x393: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_398:
	/* 0x398: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39d:
	/* 0x39d: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3a2:
	/* 0x3a2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a7:
	/* 0x3a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ac:
	/* 0x3ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ae:
	/* 0x3ae: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b3:
	/* 0x3b3: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_3b7:
	/* 0x3b7: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3bc:
	/* 0x3bc: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c1:
	/* 0x3c1: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_3cc:
	/* 0x3cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d1:
	/* 0x3d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_3d8:
	/* 0x3d8: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_3e0:
	/* 0x3e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e2:
	/* 0x3e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e5:
	/* 0x3e5: je     486 <generic_retkprobe_event+0x486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_486;
	}
x86_l_3eb:
	/* 0x3eb: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3ee:
	/* 0x3ee: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_3f4:
	/* 0x3f4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f9:
	/* 0x3f9: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_3fe:
	/* 0x3fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_400:
	/* 0x400: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_407:
	/* 0x407: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40c:
	/* 0x40c: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_414:
	/* 0x414: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_419:
	/* 0x419: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41b:
	/* 0x41b: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_423:
	/* 0x423: lea    rax,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_427:
	/* 0x427: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_42f:
	/* 0x42f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_434:
	/* 0x434: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_438:
	/* 0x438: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43d:
	/* 0x43d: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_445:
	/* 0x445: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44a:
	/* 0x44a: mov    QWORD PTR [rsp+0xe0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_452:
	/* 0x452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_454:
	/* 0x454: mov    r13,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_45c:
	/* 0x45c: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_460:
	/* 0x460: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_465:
	/* 0x465: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_46a:
	/* 0x46a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46f:
	/* 0x46f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_471:
	/* 0x471: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_477:
	/* 0x477: mov    r14d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4096ULL);
x86_l_47d:
	/* 0x47d: je     493 <generic_retkprobe_event+0x493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_493;
	}
x86_l_47f:
	/* 0x47f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_484:
	/* 0x484: jmp    4e1 <generic_retkprobe_event+0x4e1> */
	goto x86_l_4e1;
x86_l_486:
	/* 0x486: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_489:
	/* 0x489: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48e:
	/* 0x48e: jmp    9aa <generic_retkprobe_event+0x9aa> */
	return 2474ULL;
x86_l_493:
	/* 0x493: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_497:
	/* 0x497: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_49c:
	/* 0x49c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4a1:
	/* 0x4a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a6:
	/* 0x4a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a8:
	/* 0x4a8: cmp    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4ad:
	/* 0x4ad: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b2:
	/* 0x4b2: je     4e1 <generic_retkprobe_event+0x4e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e1;
	}
x86_l_4b4:
	/* 0x4b4: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_4b7:
	/* 0x4b7: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_4be:
	/* 0x4be: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_4c8:
	/* 0x4c8: mov    QWORD PTR [r12+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_4d0:
	/* 0x4d0: mov    WORD PTR [r12+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_4db:
	/* 0x4db: mov    r14d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4086ULL);
x86_l_4e1:
	/* 0x4e1: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4ea:
	/* 0x4ea: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4f3:
	/* 0x4f3: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4f8:
	/* 0x4f8: lea    r12,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4fd:
	/* 0x4fd: lea    r13,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_502:
	/* 0x502: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_50b:
	/* 0x50b: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_514:
	/* 0x514: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_51d:
	/* 0x51d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_522:
	/* 0x522: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_527:
	/* 0x527: mov    DWORD PTR [rsp+0x78],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_52c:
	/* 0x52c: lea    r14,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_531:
	/* 0x531: mov    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_536:
	/* 0x536: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_53a:
	/* 0x53a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53f:
	/* 0x53f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_544:
	/* 0x544: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_549:
	/* 0x549: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_54c:
	/* 0x54c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54e:
	/* 0x54e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_553:
	/* 0x553: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_556:
	/* 0x556: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55b:
	/* 0x55b: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_563:
	/* 0x563: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_565:
	/* 0x565: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_56a:
	/* 0x56a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_56d:
	/* 0x56d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_572:
	/* 0x572: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_57a:
	/* 0x57a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57c:
	/* 0x57c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_581:
	/* 0x581: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_584:
	/* 0x584: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_589:
	/* 0x589: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58e:
	/* 0x58e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_590:
	/* 0x590: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_595:
	/* 0x595: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_599:
	/* 0x599: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_59e:
	/* 0x59e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5a5:
	/* 0x5a5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a8:
	/* 0x5a8: je     742 <generic_retkprobe_event+0x742> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1858ULL;
	}
x86_l_5ae:
	/* 0x5ae: mov    r14d,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2048ULL);
x86_l_5b4:
	/* 0x5b4: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5b9:
	/* 0x5b9: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5be:
	/* 0x5be: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5c3:
	/* 0x5c3: cmp    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_5c8:
	/* 0x5c8: jne    5d5 <generic_retkprobe_event+0x5d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5d5;
	}
x86_l_5ca:
	/* 0x5ca: cmp    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_5cf:
	/* 0x5cf: je     8b3 <generic_retkprobe_event+0x8b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2227ULL;
	}
x86_l_5d5:
	/* 0x5d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5da:
	/* 0x5da: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5e2:
	/* 0x5e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e7:
	/* 0x5e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e9:
	/* 0x5e9: cmp    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 168ULL);
x86_l_5f1:
	/* 0x5f1: je     6e3 <generic_retkprobe_event+0x6e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e3;
	}
x86_l_5f7:
	/* 0x5f7: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5fb:
	/* 0x5fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_600:
	/* 0x600: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_605:
	/* 0x605: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60a:
	/* 0x60a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60f:
	/* 0x60f: cmp    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_614:
	/* 0x614: je     6e3 <generic_retkprobe_event+0x6e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e3;
	}
x86_l_61a:
	/* 0x61a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_61f:
	/* 0x61f: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_627:
	/* 0x627: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62c:
	/* 0x62c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_62f:
	/* 0x62f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_631:
	/* 0x631: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_635:
	/* 0x635: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_63a:
	/* 0x63a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_63f:
	/* 0x63f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_644:
	/* 0x644: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_647:
	/* 0x647: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_649:
	/* 0x649: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_64e:
	/* 0x64e: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_653:
	/* 0x653: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_657:
	/* 0x657: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_65a:
	/* 0x65a: mov    esi,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_65e:
	/* 0x65e: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_660:
	/* 0x660: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_662:
	/* 0x662: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_667:
	/* 0x667: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_66a:
	/* 0x66a: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_66f:
	/* 0x66f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_672:
	/* 0x672: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_674:
	/* 0x674: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_678:
	/* 0x678: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_67a:
	/* 0x67a: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_67d:
	/* 0x67d: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_680:
	/* 0x680: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_683:
	/* 0x683: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_686:
	/* 0x686: mov    DWORD PTR [rsp+0x78],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_68b:
	/* 0x68b: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_68e:
	/* 0x68e: jb     8b8 <generic_retkprobe_event+0x8b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2232ULL;
	}
x86_l_694:
	/* 0x694: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_69a:
	/* 0x69a: ja     8b8 <generic_retkprobe_event+0x8b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2232ULL;
	}
x86_l_6a0:
	/* 0x6a0: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_6a2:
	/* 0x6a2: jbe    be3 <generic_retkprobe_event+0xbe3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3043ULL;
	}
x86_l_6a8:
	/* 0x6a8: lea    r13,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6ac:
	/* 0x6ac: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_6b1:
	/* 0x6b1: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6b5:
	/* 0x6b5: lea    rdi,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6b9:
	/* 0x6b9: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6bc:
	/* 0x6bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6c1:
	/* 0x6c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c3:
	/* 0x6c3: mov    QWORD PTR [rsp+0x70],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6c8:
	/* 0x6c8: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_6d0:
	/* 0x6d0: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6d5:
	/* 0x6d5: dec    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_6d8:
	/* 0x6d8: jne    5b4 <generic_retkprobe_event+0x5b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5b4;
	}
x86_l_6de:
	/* 0x6de: jmp    8b8 <generic_retkprobe_event+0x8b8> */
	return 2232ULL;
x86_l_6e3:
	/* 0x6e3: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6e8:
	/* 0x6e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6ed:
	/* 0x6ed: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6f2:
	/* 0x6f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f7:
	/* 0x6f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f9:
	/* 0x6f9: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6fe:
	/* 0x6fe: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_703:
	/* 0x703: je     8b3 <generic_retkprobe_event+0x8b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2227ULL;
	}
x86_l_709:
	/* 0x709: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_70d:
	/* 0x70d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_712:
	/* 0x712: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_717:
	/* 0x717: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_71c:
	/* 0x71c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_71f:
	/* 0x71f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_721:
	/* 0x721: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_726:
	/* 0x726: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_72b:
	/* 0x72b: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_72f:
	/* 0x72f: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_734:
	/* 0x734: dec    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_DEC, 1);
	return 1847ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1847ULL: goto x86_l_737;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1882ULL: goto x86_l_75a;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1929ULL: goto x86_l_789;
	case 1935ULL: goto x86_l_78f;
	case 1946ULL: goto x86_l_79a;
	case 1951ULL: goto x86_l_79f;
	case 1958ULL: goto x86_l_7a6;
	case 1966ULL: goto x86_l_7ae;
	case 1968ULL: goto x86_l_7b0;
	case 1971ULL: goto x86_l_7b3;
	case 1977ULL: goto x86_l_7b9;
	case 1980ULL: goto x86_l_7bc;
	case 1984ULL: goto x86_l_7c0;
	case 1988ULL: goto x86_l_7c4;
	case 1994ULL: goto x86_l_7ca;
	case 1998ULL: goto x86_l_7ce;
	case 2004ULL: goto x86_l_7d4;
	case 2008ULL: goto x86_l_7d8;
	case 2014ULL: goto x86_l_7de;
	case 2018ULL: goto x86_l_7e2;
	case 2024ULL: goto x86_l_7e8;
	case 2028ULL: goto x86_l_7ec;
	case 2034ULL: goto x86_l_7f2;
	case 2038ULL: goto x86_l_7f6;
	case 2044ULL: goto x86_l_7fc;
	case 2054ULL: goto x86_l_806;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2074ULL: goto x86_l_81a;
	case 2080ULL: goto x86_l_820;
	case 2083ULL: goto x86_l_823;
	case 2093ULL: goto x86_l_82d;
	case 2097ULL: goto x86_l_831;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2131ULL: goto x86_l_853;
	case 2139ULL: goto x86_l_85b;
	case 2141ULL: goto x86_l_85d;
	case 2144ULL: goto x86_l_860;
	case 2147ULL: goto x86_l_863;
	case 2153ULL: goto x86_l_869;
	case 2157ULL: goto x86_l_86d;
	case 2163ULL: goto x86_l_873;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2178ULL: goto x86_l_882;
	case 2182ULL: goto x86_l_886;
	case 2188ULL: goto x86_l_88c;
	case 2192ULL: goto x86_l_890;
	case 2195ULL: goto x86_l_893;
	case 2201ULL: goto x86_l_899;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2232ULL: goto x86_l_8b8;
	case 2237ULL: goto x86_l_8bd;
	case 2242ULL: goto x86_l_8c2;
	case 2244ULL: goto x86_l_8c4;
	case 2247ULL: goto x86_l_8c7;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2257ULL: goto x86_l_8d1;
	case 2261ULL: goto x86_l_8d5;
	case 2267ULL: goto x86_l_8db;
	case 2270ULL: goto x86_l_8de;
	case 2272ULL: goto x86_l_8e0;
	case 2276ULL: goto x86_l_8e4;
	case 2279ULL: goto x86_l_8e7;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2294ULL: goto x86_l_8f6;
	case 2300ULL: goto x86_l_8fc;
	case 2303ULL: goto x86_l_8ff;
	case 2305ULL: goto x86_l_901;
	case 2308ULL: goto x86_l_904;
	case 2310ULL: goto x86_l_906;
	case 2313ULL: goto x86_l_909;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2328ULL: goto x86_l_918;
	case 2335ULL: goto x86_l_91f;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2350ULL: goto x86_l_92e;
	case 2352ULL: goto x86_l_930;
	case 2356ULL: goto x86_l_934;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2373ULL: goto x86_l_945;
	case 2378ULL: goto x86_l_94a;
	case 2386ULL: goto x86_l_952;
	case 2388ULL: goto x86_l_954;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2414ULL: goto x86_l_96e;
	case 2419ULL: goto x86_l_973;
	case 2424ULL: goto x86_l_978;
	case 2429ULL: goto x86_l_97d;
	case 2434ULL: goto x86_l_982;
	case 2436ULL: goto x86_l_984;
	case 2440ULL: goto x86_l_988;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2462ULL: goto x86_l_99e;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2474ULL: goto x86_l_9aa;
	case 2478ULL: goto x86_l_9ae;
	case 2483ULL: goto x86_l_9b3;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2495ULL: goto x86_l_9bf;
	case 2504ULL: goto x86_l_9c8;
	case 2506ULL: goto x86_l_9ca;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2522ULL: goto x86_l_9da;
	case 2526ULL: goto x86_l_9de;
	case 2532ULL: goto x86_l_9e4;
	case 2537ULL: goto x86_l_9e9;
	case 2542ULL: goto x86_l_9ee;
	case 2547ULL: goto x86_l_9f3;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2556ULL: goto x86_l_9fc;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2575ULL: goto x86_l_a0f;
	case 2578ULL: goto x86_l_a12;
	case 2582ULL: goto x86_l_a16;
	case 2585ULL: goto x86_l_a19;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2601ULL: goto x86_l_a29;
	case 2603ULL: goto x86_l_a2b;
	case 2607ULL: goto x86_l_a2f;
	case 2610ULL: goto x86_l_a32;
	case 2615ULL: goto x86_l_a37;
	case 2619ULL: goto x86_l_a3b;
	case 2623ULL: goto x86_l_a3f;
	case 2628ULL: goto x86_l_a44;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2643ULL: goto x86_l_a53;
	case 2645ULL: goto x86_l_a55;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2657ULL: goto x86_l_a61;
	case 2659ULL: goto x86_l_a63;
	case 2662ULL: goto x86_l_a66;
	case 2667ULL: goto x86_l_a6b;
	case 2670ULL: goto x86_l_a6e;
	case 2676ULL: goto x86_l_a74;
	case 2679ULL: goto x86_l_a77;
	case 2682ULL: goto x86_l_a7a;
	case 2688ULL: goto x86_l_a80;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2707ULL: goto x86_l_a93;
	case 2713ULL: goto x86_l_a99;
	case 2717ULL: goto x86_l_a9d;
	case 2721ULL: goto x86_l_aa1;
	case 2727ULL: goto x86_l_aa7;
	case 2731ULL: goto x86_l_aab;
	case 2737ULL: goto x86_l_ab1;
	case 2741ULL: goto x86_l_ab5;
	case 2747ULL: goto x86_l_abb;
	case 2751ULL: goto x86_l_abf;
	case 2757ULL: goto x86_l_ac5;
	case 2760ULL: goto x86_l_ac8;
	case 2765ULL: goto x86_l_acd;
	case 2770ULL: goto x86_l_ad2;
	case 2777ULL: goto x86_l_ad9;
	case 2784ULL: goto x86_l_ae0;
	case 2789ULL: goto x86_l_ae5;
	case 2794ULL: goto x86_l_aea;
	case 2799ULL: goto x86_l_aef;
	case 2802ULL: goto x86_l_af2;
	case 2804ULL: goto x86_l_af4;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2828ULL: goto x86_l_b0c;
	case 2835ULL: goto x86_l_b13;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2855ULL: goto x86_l_b27;
	case 2862ULL: goto x86_l_b2e;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2880ULL: goto x86_l_b40;
	case 2882ULL: goto x86_l_b42;
	case 2889ULL: goto x86_l_b49;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2909ULL: goto x86_l_b5d;
	case 2916ULL: goto x86_l_b64;
	case 2924ULL: goto x86_l_b6c;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2936ULL: goto x86_l_b78;
	case 2943ULL: goto x86_l_b7f;
	case 2948ULL: goto x86_l_b84;
	case 2955ULL: goto x86_l_b8b;
	case 2963ULL: goto x86_l_b93;
	case 2971ULL: goto x86_l_b9b;
	case 2979ULL: goto x86_l_ba3;
	case 2987ULL: goto x86_l_bab;
	case 2990ULL: goto x86_l_bae;
	case 2996ULL: goto x86_l_bb4;
	case 2999ULL: goto x86_l_bb7;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3022ULL: goto x86_l_bce;
	case 3027ULL: goto x86_l_bd3;
	case 3030ULL: goto x86_l_bd6;
	case 3035ULL: goto x86_l_bdb;
	case 3038ULL: goto x86_l_bde;
	case 3043ULL: goto x86_l_be3;
	case 3047ULL: goto x86_l_be7;
	case 3050ULL: goto x86_l_bea;
	case 3055ULL: goto x86_l_bef;
	case 3058ULL: goto x86_l_bf2;
	case 3060ULL: goto x86_l_bf4;
	case 3065ULL: goto x86_l_bf9;
	case 3070ULL: goto x86_l_bfe;
	case 3074ULL: goto x86_l_c02;
	case 3080ULL: goto x86_l_c08;
	case 3084ULL: goto x86_l_c0c;
	case 3090ULL: goto x86_l_c12;
	case 3094ULL: goto x86_l_c16;
	case 3100ULL: goto x86_l_c1c;
	case 3104ULL: goto x86_l_c20;
	case 3108ULL: goto x86_l_c24;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3123ULL: goto x86_l_c33;
	case 3126ULL: goto x86_l_c36;
	case 3130ULL: goto x86_l_c3a;
	case 3136ULL: goto x86_l_c40;
	case 3140ULL: goto x86_l_c44;
	case 3143ULL: goto x86_l_c47;
	case 3149ULL: goto x86_l_c4d;
	case 3153ULL: goto x86_l_c51;
	case 3159ULL: goto x86_l_c57;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3172ULL: goto x86_l_c64;
	case 3177ULL: goto x86_l_c69;
	case 3182ULL: goto x86_l_c6e;
	case 3185ULL: goto x86_l_c71;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3210ULL: goto x86_l_c8a;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3222ULL: goto x86_l_c96;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3241ULL: goto x86_l_ca9;
	case 3244ULL: goto x86_l_cac;
	case 3247ULL: goto x86_l_caf;
	case 3253ULL: goto x86_l_cb5;
	case 3258ULL: goto x86_l_cba;
	case 3262ULL: goto x86_l_cbe;
	case 3268ULL: goto x86_l_cc4;
	case 3272ULL: goto x86_l_cc8;
	case 3275ULL: goto x86_l_ccb;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3308ULL: goto x86_l_cec;
	case 3314ULL: goto x86_l_cf2;
	case 3318ULL: goto x86_l_cf6;
	case 3324ULL: goto x86_l_cfc;
	case 3328ULL: goto x86_l_d00;
	case 3332ULL: goto x86_l_d04;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3346ULL: goto x86_l_d12;
	case 3351ULL: goto x86_l_d17;
	case 3356ULL: goto x86_l_d1c;
	case 3364ULL: goto x86_l_d24;
	case 3372ULL: goto x86_l_d2c;
	case 3380ULL: goto x86_l_d34;
	case 3388ULL: goto x86_l_d3c;
	case 3396ULL: goto x86_l_d44;
	case 3404ULL: goto x86_l_d4c;
	case 3412ULL: goto x86_l_d54;
	case 3420ULL: goto x86_l_d5c;
	case 3428ULL: goto x86_l_d64;
	case 3436ULL: goto x86_l_d6c;
	case 3444ULL: goto x86_l_d74;
	case 3452ULL: goto x86_l_d7c;
	case 3460ULL: goto x86_l_d84;
	case 3467ULL: goto x86_l_d8b;
	case 3472ULL: goto x86_l_d90;
	case 3477ULL: goto x86_l_d95;
	case 3480ULL: goto x86_l_d98;
	case 3482ULL: goto x86_l_d9a;
	case 3485ULL: goto x86_l_d9d;
	case 3491ULL: goto x86_l_da3;
	case 3496ULL: goto x86_l_da8;
	case 3501ULL: goto x86_l_dad;
	case 3506ULL: goto x86_l_db2;
	case 3511ULL: goto x86_l_db7;
	case 3514ULL: goto x86_l_dba;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3525ULL: goto x86_l_dc5;
	case 3529ULL: goto x86_l_dc9;
	case 3532ULL: goto x86_l_dcc;
	case 3539ULL: goto x86_l_dd3;
	case 3544ULL: goto x86_l_dd8;
	case 3551ULL: goto x86_l_ddf;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3572ULL: goto x86_l_df4;
	case 3574ULL: goto x86_l_df6;
	case 3580ULL: goto x86_l_dfc;
	case 3582ULL: goto x86_l_dfe;
	case 3587ULL: goto x86_l_e03;
	case 3591ULL: goto x86_l_e07;
	case 3597ULL: goto x86_l_e0d;
	case 3601ULL: goto x86_l_e11;
	case 3607ULL: goto x86_l_e17;
	case 3611ULL: goto x86_l_e1b;
	case 3617ULL: goto x86_l_e21;
	case 3628ULL: goto x86_l_e2c;
	case 3630ULL: goto x86_l_e2e;
	case 3636ULL: goto x86_l_e34;
	case 3641ULL: goto x86_l_e39;
	case 3646ULL: goto x86_l_e3e;
	case 3651ULL: goto x86_l_e43;
	case 3653ULL: goto x86_l_e45;
	case 3657ULL: goto x86_l_e49;
	case 3659ULL: goto x86_l_e4b;
	case 3663ULL: goto x86_l_e4f;
	case 3669ULL: goto x86_l_e55;
	case 3674ULL: goto x86_l_e5a;
	case 3679ULL: goto x86_l_e5f;
	case 3684ULL: goto x86_l_e64;
	case 3689ULL: goto x86_l_e69;
	default: return 0xffffffffffffffffULL;
	}
x86_l_737:
	/* 0x737: jne    5b4 <generic_retkprobe_event+0x5b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1460ULL;
	}
x86_l_73d:
	/* 0x73d: jmp    8b8 <generic_retkprobe_event+0x8b8> */
	goto x86_l_8b8;
x86_l_742:
	/* 0x742: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_747:
	/* 0x747: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_74e:
	/* 0x74e: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_753:
	/* 0x753: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_758:
	/* 0x758: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75a:
	/* 0x75a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75c:
	/* 0x75c: jmp    8b8 <generic_retkprobe_event+0x8b8> */
	goto x86_l_8b8;
x86_l_761:
	/* 0x761: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_766:
	/* 0x766: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_76b:
	/* 0x76b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_770:
	/* 0x770: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_775:
	/* 0x775: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_77a:
	/* 0x77a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_77c:
	/* 0x77c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_781:
	/* 0x781: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_786:
	/* 0x786: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_789:
	/* 0x789: jne    3bc <generic_retkprobe_event+0x3bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 956ULL;
	}
x86_l_78f:
	/* 0x78f: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_79a:
	/* 0x79a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_79f:
	/* 0x79f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_7a6:
	/* 0x7a6: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7ae:
	/* 0x7ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b0:
	/* 0x7b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b3:
	/* 0x7b3: je     1ba8 <generic_retkprobe_event+0x1ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7080ULL;
	}
x86_l_7b9:
	/* 0x7b9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7bc:
	/* 0x7bc: cmp    r14d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 25ULL);
x86_l_7c0:
	/* 0x7c0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c4:
	/* 0x7c4: jg     cba <generic_retkprobe_event+0xcba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_cba;
	}
x86_l_7ca:
	/* 0x7ca: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_7ce:
	/* 0x7ce: jle    e03 <generic_retkprobe_event+0xe03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e03;
	}
x86_l_7d4:
	/* 0x7d4: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_7d8:
	/* 0x7d8: jle    10da <generic_retkprobe_event+0x10da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4314ULL;
	}
x86_l_7de:
	/* 0x7de: cmp    r14d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 21ULL);
x86_l_7e2:
	/* 0x7e2: je     19c3 <generic_retkprobe_event+0x19c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6595ULL;
	}
x86_l_7e8:
	/* 0x7e8: cmp    r14d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 22ULL);
x86_l_7ec:
	/* 0x7ec: je     193f <generic_retkprobe_event+0x193f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6463ULL;
	}
x86_l_7f2:
	/* 0x7f2: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_7f6:
	/* 0x7f6: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_7fc:
	/* 0x7fc: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_806:
	/* 0x806: mov    DWORD PTR [rcx+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_80c:
	/* 0x80c: jmp    e6f <generic_retkprobe_event+0xe6f> */
	return 3695ULL;
x86_l_811:
	/* 0x811: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_816:
	/* 0x816: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_81a:
	/* 0x81a: ja     78f <generic_retkprobe_event+0x78f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_78f;
	}
x86_l_820:
	/* 0x820: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_823:
	/* 0x823: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_82d:
	/* 0x82d: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_831:
	/* 0x831: jae    78f <generic_retkprobe_event+0x78f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_78f;
	}
x86_l_837:
	/* 0x837: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_83c:
	/* 0x83c: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_847:
	/* 0x847: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_84c:
	/* 0x84c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_853:
	/* 0x853: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_85b:
	/* 0x85b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85d:
	/* 0x85d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_860:
	/* 0x860: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_863:
	/* 0x863: je     1ebc <generic_retkprobe_event+0x1ebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7868ULL;
	}
x86_l_869:
	/* 0x869: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_86d:
	/* 0x86d: jle    a8f <generic_retkprobe_event+0xa8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_a8f;
	}
x86_l_873:
	/* 0x873: cmp    r14d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 30ULL);
x86_l_877:
	/* 0x877: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_87c:
	/* 0x87c: jle    bfe <generic_retkprobe_event+0xbfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_bfe;
	}
x86_l_882:
	/* 0x882: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_886:
	/* 0x886: jg     ce8 <generic_retkprobe_event+0xce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ce8;
	}
x86_l_88c:
	/* 0x88c: lea    eax,[r14-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_890:
	/* 0x890: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_893:
	/* 0x893: jae    119a <generic_retkprobe_event+0x119a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4506ULL;
	}
x86_l_899:
	/* 0x899: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_89f:
	/* 0x89f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8a4:
	/* 0x8a4: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8a9:
	/* 0x8a9: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_8ae:
	/* 0x8ae: jmp    e94 <generic_retkprobe_event+0xe94> */
	return 3732ULL;
x86_l_8b3:
	/* 0x8b3: mov    BYTE PTR [rsp+0x7c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944705ULL);
x86_l_8b8:
	/* 0x8b8: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8bd:
	/* 0x8bd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8c2:
	/* 0x8c2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c4:
	/* 0x8c4: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_8c7:
	/* 0x8c7: je     906 <generic_retkprobe_event+0x906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_906;
	}
x86_l_8c9:
	/* 0x8c9: cmp    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_8ce:
	/* 0x8ce: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_8d1:
	/* 0x8d1: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8d5:
	/* 0x8d5: mov    r13d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4096ULL);
x86_l_8db:
	/* 0x8db: sub    r13d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8de:
	/* 0x8de: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_8e0:
	/* 0x8e0: cmovle r13d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_8e4:
	/* 0x8e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8e7:
	/* 0x8e7: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8eb:
	/* 0x8eb: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f0:
	/* 0x8f0: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_8f6:
	/* 0x8f6: je     9a7 <generic_retkprobe_event+0x9a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a7;
	}
x86_l_8fc:
	/* 0x8fc: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_8ff:
	/* 0x8ff: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_901:
	/* 0x901: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_904:
	/* 0x904: jmp    918 <generic_retkprobe_event+0x918> */
	goto x86_l_918;
x86_l_906:
	/* 0x906: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_909:
	/* 0x909: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90d:
	/* 0x90d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_912:
	/* 0x912: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_918:
	/* 0x918: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_91f:
	/* 0x91f: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_926:
	/* 0x926: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_92b:
	/* 0x92b: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_92e:
	/* 0x92e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_930:
	/* 0x930: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_934:
	/* 0x934: mov    DWORD PTR [rax+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_93b:
	/* 0x93b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_940:
	/* 0x940: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_945:
	/* 0x945: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_94a:
	/* 0x94a: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_952:
	/* 0x952: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_954:
	/* 0x954: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_959:
	/* 0x959: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_95e:
	/* 0x95e: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_962:
	/* 0x962: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_967:
	/* 0x967: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_96c:
	/* 0x96c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96e:
	/* 0x96e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_973:
	/* 0x973: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_978:
	/* 0x978: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_97d:
	/* 0x97d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_982:
	/* 0x982: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_984:
	/* 0x984: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_988:
	/* 0x988: mov    DWORD PTR [rcx+r13*1+0xa0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 160ULL);
x86_l_990:
	/* 0x990: movzx  eax,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_995:
	/* 0x995: mov    WORD PTR [rcx+r13*1+0xa4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R13, 0), 164ULL);
x86_l_99e:
	/* 0x99e: add    r13d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_9a2:
	/* 0x9a2: jmp    2845 <generic_retkprobe_event+0x2845> */
	return 10309ULL;
x86_l_9a7:
	/* 0x9a7: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9aa:
	/* 0x9aa: mov    ebp,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9ae:
	/* 0x9ae: jmp    284e <generic_retkprobe_event+0x284e> */
	return 10318ULL;
x86_l_9b3:
	/* 0x9b3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b5:
	/* 0x9b5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ba:
	/* 0x9ba: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9bf:
	/* 0x9bf: cmp    QWORD PTR [rsp+0x80],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813889ULL);
x86_l_9c8:
	/* 0x9c8: jne    9d2 <generic_retkprobe_event+0x9d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9d2;
	}
x86_l_9ca:
	/* 0x9ca: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_9cd:
	/* 0x9cd: jmp    332 <generic_retkprobe_event+0x332> */
	return 818ULL;
x86_l_9d2:
	/* 0x9d2: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9da:
	/* 0x9da: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9de:
	/* 0x9de: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_9e4:
	/* 0x9e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9e9:
	/* 0x9e9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9ee:
	/* 0x9ee: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9f3:
	/* 0x9f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f5:
	/* 0x9f5: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_9fa:
	/* 0x9fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9fc:
	/* 0x9fc: js     a85 <generic_retkprobe_event+0xa85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a85;
	}
x86_l_a02:
	/* 0xa02: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a07:
	/* 0xa07: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a0c:
	/* 0xa0c: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a0f:
	/* 0xa0f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_a12:
	/* 0xa12: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_a16:
	/* 0xa16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a19:
	/* 0xa19: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_a1d:
	/* 0xa1d: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_a22:
	/* 0xa22: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_a29:
	/* 0xa29: ja     a85 <generic_retkprobe_event+0xa85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a85;
	}
x86_l_a2b:
	/* 0xa2b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a2f:
	/* 0xa2f: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a32:
	/* 0xa32: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a37:
	/* 0xa37: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a3b:
	/* 0xa3b: lea    rdi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_a3f:
	/* 0xa3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a44:
	/* 0xa44: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a49:
	/* 0xa49: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a4e:
	/* 0xa4e: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a53:
	/* 0xa53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a55:
	/* 0xa55: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a5a:
	/* 0xa5a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_a5f:
	/* 0xa5f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a61:
	/* 0xa61: js     a85 <generic_retkprobe_event+0xa85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a85;
	}
x86_l_a63:
	/* 0xa63: add    r14,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a66:
	/* 0xa66: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6b:
	/* 0xa6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a6e:
	/* 0xa6e: je     15d3 <generic_retkprobe_event+0x15d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5587ULL;
	}
x86_l_a74:
	/* 0xa74: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a77:
	/* 0xa77: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_a7a:
	/* 0xa7a: jne    15d6 <generic_retkprobe_event+0x15d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5590ULL;
	}
x86_l_a80:
	/* 0xa80: jmp    169e <generic_retkprobe_event+0x169e> */
	return 5790ULL;
x86_l_a85:
	/* 0xa85: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a8a:
	/* 0xa8a: jmp    2acc <generic_retkprobe_event+0x2acc> */
	return 10956ULL;
x86_l_a8f:
	/* 0xa8f: cmp    r14d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 9ULL);
x86_l_a93:
	/* 0xa93: jg     c2f <generic_retkprobe_event+0xc2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_c2f;
	}
x86_l_a99:
	/* 0xa99: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_a9d:
	/* 0xa9d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa1:
	/* 0xaa1: jle    e45 <generic_retkprobe_event+0xe45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e45;
	}
x86_l_aa7:
	/* 0xaa7: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_aab:
	/* 0xaab: je     136b <generic_retkprobe_event+0x136b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4971ULL;
	}
x86_l_ab1:
	/* 0xab1: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_ab5:
	/* 0xab5: je     c8e <generic_retkprobe_event+0xc8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c8e;
	}
x86_l_abb:
	/* 0xabb: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_abf:
	/* 0xabf: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_ac5:
	/* 0xac5: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ac8:
	/* 0xac8: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_acd:
	/* 0xacd: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ad2:
	/* 0xad2: mov    QWORD PTR [rcx+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_ad9:
	/* 0xad9: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_ae0:
	/* 0xae0: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae5:
	/* 0xae5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_aea:
	/* 0xaea: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_aef:
	/* 0xaef: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_af2:
	/* 0xaf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af4:
	/* 0xaf4: lea    rdi,[r14+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_afb:
	/* 0xafb: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_b00:
	/* 0xb00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b05:
	/* 0xb05: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_b0a:
	/* 0xb0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0c:
	/* 0xb0c: lea    rdi,[r14+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_b13:
	/* 0xb13: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_b1b:
	/* 0xb1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b20:
	/* 0xb20: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b25:
	/* 0xb25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b27:
	/* 0xb27: lea    rdi,[r14+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_b2e:
	/* 0xb2e: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_b36:
	/* 0xb36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b3b:
	/* 0xb3b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b40:
	/* 0xb40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b42:
	/* 0xb42: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_b49:
	/* 0xb49: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_b51:
	/* 0xb51: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b56:
	/* 0xb56: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b5b:
	/* 0xb5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5d:
	/* 0xb5d: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b64:
	/* 0xb64: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_b6c:
	/* 0xb6c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b71:
	/* 0xb71: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b76:
	/* 0xb76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b78:
	/* 0xb78: lea    r13,[r14+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_b7f:
	/* 0xb7f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b84:
	/* 0xb84: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b8b:
	/* 0xb8b: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_b93:
	/* 0xb93: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b9b:
	/* 0xb9b: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_ba3:
	/* 0xba3: movzx  eax,WORD PTR [r14+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_bab:
	/* 0xbab: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_bae:
	/* 0xbae: je     1d10 <generic_retkprobe_event+0x1d10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7440ULL;
	}
x86_l_bb4:
	/* 0xbb4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bb7:
	/* 0xbb7: jne    1d35 <generic_retkprobe_event+0x1d35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7477ULL;
	}
x86_l_bbd:
	/* 0xbbd: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bc2:
	/* 0xbc2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bc7:
	/* 0xbc7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bcc:
	/* 0xbcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bce:
	/* 0xbce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bd3:
	/* 0xbd3: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_bd6:
	/* 0xbd6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bdb:
	/* 0xbdb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_bde:
	/* 0xbde: jmp    1d33 <generic_retkprobe_event+0x1d33> */
	return 7475ULL;
x86_l_be3:
	/* 0xbe3: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_be7:
	/* 0xbe7: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bea:
	/* 0xbea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bef:
	/* 0xbef: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_bf2:
	/* 0xbf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf4:
	/* 0xbf4: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bf9:
	/* 0xbf9: jmp    8b8 <generic_retkprobe_event+0x8b8> */
	goto x86_l_8b8;
x86_l_bfe:
	/* 0xbfe: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_c02:
	/* 0xc02: jg     e2e <generic_retkprobe_event+0xe2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_e2e;
	}
x86_l_c08:
	/* 0xc08: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_c0c:
	/* 0xc0c: je     11e5 <generic_retkprobe_event+0x11e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4581ULL;
	}
x86_l_c12:
	/* 0xc12: cmp    r14d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 25ULL);
x86_l_c16:
	/* 0xc16: je     12ab <generic_retkprobe_event+0x12ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4779ULL;
	}
x86_l_c1c:
	/* 0xc1c: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_c20:
	/* 0xc20: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c24:
	/* 0xc24: je     e55 <generic_retkprobe_event+0xe55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e55;
	}
x86_l_c2a:
	/* 0xc2a: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_c2f:
	/* 0xc2f: lea    eax,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_c33:
	/* 0xc33: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c36:
	/* 0xc36: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c3a:
	/* 0xc3a: jb     e55 <generic_retkprobe_event+0xe55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e55;
	}
x86_l_c40:
	/* 0xc40: lea    eax,[r14-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_c44:
	/* 0xc44: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c47:
	/* 0xc47: jb     e7a <generic_retkprobe_event+0xe7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3706ULL;
	}
x86_l_c4d:
	/* 0xc4d: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_c51:
	/* 0xc51: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_c57:
	/* 0xc57: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c5c:
	/* 0xc5c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c61:
	/* 0xc61: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_c64:
	/* 0xc64: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c69:
	/* 0xc69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c6e:
	/* 0xc6e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c71:
	/* 0xc71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c73:
	/* 0xc73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c78:
	/* 0xc78: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c7d:
	/* 0xc7d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c80:
	/* 0xc80: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_c83:
	/* 0xc83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c88:
	/* 0xc88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8a:
	/* 0xc8a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8e:
	/* 0xc8e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c93:
	/* 0xc93: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_c96:
	/* 0xc96: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_c9d:
	/* 0xc9d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ca2:
	/* 0xca2: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_ca7:
	/* 0xca7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca9:
	/* 0xca9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_cac:
	/* 0xcac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_caf:
	/* 0xcaf: jns    152d <generic_retkprobe_event+0x152d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5421ULL;
	}
x86_l_cb5:
	/* 0xcb5: jmp    1ebc <generic_retkprobe_event+0x1ebc> */
	return 7868ULL;
x86_l_cba:
	/* 0xcba: cmp    r14d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 32ULL);
x86_l_cbe:
	/* 0xcbe: jle    ff5 <generic_retkprobe_event+0xff5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4085ULL;
	}
x86_l_cc4:
	/* 0xcc4: lea    edx,[r14-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_cc8:
	/* 0xcc8: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_ccb:
	/* 0xccb: jae    e9f <generic_retkprobe_event+0xe9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3743ULL;
	}
x86_l_cd1:
	/* 0xcd1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd6:
	/* 0xcd6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cdb:
	/* 0xcdb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ce0:
	/* 0xce0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_ce3:
	/* 0xce3: jmp    e69 <generic_retkprobe_event+0xe69> */
	goto x86_l_e69;
x86_l_ce8:
	/* 0xce8: cmp    r14d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 39ULL);
x86_l_cec:
	/* 0xcec: je     1500 <generic_retkprobe_event+0x1500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5376ULL;
	}
x86_l_cf2:
	/* 0xcf2: cmp    r14d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 40ULL);
x86_l_cf6:
	/* 0xcf6: je     1545 <generic_retkprobe_event+0x1545> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5445ULL;
	}
x86_l_cfc:
	/* 0xcfc: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_d00:
	/* 0xd00: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d04:
	/* 0xd04: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_d0a:
	/* 0xd0a: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_d0d:
	/* 0xd0d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d12:
	/* 0xd12: mov    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_d17:
	/* 0xd17: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1c:
	/* 0xd1c: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_d24:
	/* 0xd24: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d2c:
	/* 0xd2c: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_d34:
	/* 0xd34: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_d3c:
	/* 0xd3c: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_d44:
	/* 0xd44: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_d4c:
	/* 0xd4c: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_d54:
	/* 0xd54: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_d5c:
	/* 0xd5c: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d64:
	/* 0xd64: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_d6c:
	/* 0xd6c: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_d74:
	/* 0xd74: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_d7c:
	/* 0xd7c: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d84:
	/* 0xd84: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d8b:
	/* 0xd8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d90:
	/* 0xd90: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_d95:
	/* 0xd95: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d98:
	/* 0xd98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9a:
	/* 0xd9a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d9d:
	/* 0xd9d: js     1eeb <generic_retkprobe_event+0x1eeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7915ULL;
	}
x86_l_da3:
	/* 0xda3: lea    r13,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_da8:
	/* 0xda8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dad:
	/* 0xdad: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_db2:
	/* 0xdb2: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_db7:
	/* 0xdb7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_dba:
	/* 0xdba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbc:
	/* 0xdbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dbf:
	/* 0xdbf: js     1eeb <generic_retkprobe_event+0x1eeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7915ULL;
	}
x86_l_dc5:
	/* 0xdc5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dc9:
	/* 0xdc9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_dcc:
	/* 0xdcc: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_dd3:
	/* 0xdd3: cmp    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_dd8:
	/* 0xdd8: sete   BYTE PTR [rax+0x9e] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 158ULL);
x86_l_ddf:
	/* 0xddf: je     1ec5 <generic_retkprobe_event+0x1ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7877ULL;
	}
x86_l_de5:
	/* 0xde5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_dea:
	/* 0xdea: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_def:
	/* 0xdef: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_df2:
	/* 0xdf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df4:
	/* 0xdf4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_df6:
	/* 0xdf6: js     1eeb <generic_retkprobe_event+0x1eeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7915ULL;
	}
x86_l_dfc:
	/* 0xdfc: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_dfe:
	/* 0xdfe: jmp    1ee1 <generic_retkprobe_event+0x1ee1> */
	return 7905ULL;
x86_l_e03:
	/* 0xe03: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_e07:
	/* 0xe07: jg     10af <generic_retkprobe_event+0x10af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4271ULL;
	}
x86_l_e0d:
	/* 0xe0d: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_e11:
	/* 0xe11: je     16a6 <generic_retkprobe_event+0x16a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5798ULL;
	}
x86_l_e17:
	/* 0xe17: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_e1b:
	/* 0xe1b: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_e21:
	/* 0xe21: mov    QWORD PTR [rax+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_e2c:
	/* 0xe2c: jmp    e6f <generic_retkprobe_event+0xe6f> */
	return 3695ULL;
x86_l_e2e:
	/* 0xe2e: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_e34:
	/* 0xe34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e39:
	/* 0xe39: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e3e:
	/* 0xe3e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e43:
	/* 0xe43: jmp    e94 <generic_retkprobe_event+0xe94> */
	return 3732ULL;
x86_l_e45:
	/* 0xe45: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_e49:
	/* 0xe49: je     e7a <generic_retkprobe_event+0xe7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3706ULL;
	}
x86_l_e4b:
	/* 0xe4b: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_e4f:
	/* 0xe4f: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_e55:
	/* 0xe55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e5a:
	/* 0xe5a: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e5f:
	/* 0xe5f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e64:
	/* 0xe64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e69:
	/* 0xe69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 3691ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3691ULL: goto x86_l_e6b;
	case 3695ULL: goto x86_l_e6f;
	case 3701ULL: goto x86_l_e75;
	case 3706ULL: goto x86_l_e7a;
	case 3712ULL: goto x86_l_e80;
	case 3717ULL: goto x86_l_e85;
	case 3722ULL: goto x86_l_e8a;
	case 3727ULL: goto x86_l_e8f;
	case 3732ULL: goto x86_l_e94;
	case 3734ULL: goto x86_l_e96;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3747ULL: goto x86_l_ea3;
	case 3753ULL: goto x86_l_ea9;
	case 3757ULL: goto x86_l_ead;
	case 3763ULL: goto x86_l_eb3;
	case 3768ULL: goto x86_l_eb8;
	case 3771ULL: goto x86_l_ebb;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3793ULL: goto x86_l_ed1;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3803ULL: goto x86_l_edb;
	case 3809ULL: goto x86_l_ee1;
	case 3813ULL: goto x86_l_ee5;
	case 3820ULL: goto x86_l_eec;
	case 3827ULL: goto x86_l_ef3;
	case 3832ULL: goto x86_l_ef8;
	case 3837ULL: goto x86_l_efd;
	case 3842ULL: goto x86_l_f02;
	case 3844ULL: goto x86_l_f04;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3868ULL: goto x86_l_f1c;
	case 3875ULL: goto x86_l_f23;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3902ULL: goto x86_l_f3e;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3920ULL: goto x86_l_f50;
	case 3922ULL: goto x86_l_f52;
	case 3929ULL: goto x86_l_f59;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3947ULL: goto x86_l_f6b;
	case 3949ULL: goto x86_l_f6d;
	case 3956ULL: goto x86_l_f74;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3976ULL: goto x86_l_f88;
	case 3983ULL: goto x86_l_f8f;
	case 3988ULL: goto x86_l_f94;
	case 3995ULL: goto x86_l_f9b;
	case 4003ULL: goto x86_l_fa3;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4022ULL: goto x86_l_fb6;
	case 4029ULL: goto x86_l_fbd;
	case 4032ULL: goto x86_l_fc0;
	case 4038ULL: goto x86_l_fc6;
	case 4041ULL: goto x86_l_fc9;
	case 4047ULL: goto x86_l_fcf;
	case 4052ULL: goto x86_l_fd4;
	case 4057ULL: goto x86_l_fd9;
	case 4062ULL: goto x86_l_fde;
	case 4064ULL: goto x86_l_fe0;
	case 4069ULL: goto x86_l_fe5;
	case 4072ULL: goto x86_l_fe8;
	case 4077ULL: goto x86_l_fed;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4089ULL: goto x86_l_ff9;
	case 4095ULL: goto x86_l_fff;
	case 4099ULL: goto x86_l_1003;
	case 4105ULL: goto x86_l_1009;
	case 4110ULL: goto x86_l_100e;
	case 4118ULL: goto x86_l_1016;
	case 4126ULL: goto x86_l_101e;
	case 4134ULL: goto x86_l_1026;
	case 4142ULL: goto x86_l_102e;
	case 4150ULL: goto x86_l_1036;
	case 4158ULL: goto x86_l_103e;
	case 4166ULL: goto x86_l_1046;
	case 4174ULL: goto x86_l_104e;
	case 4182ULL: goto x86_l_1056;
	case 4189ULL: goto x86_l_105d;
	case 4196ULL: goto x86_l_1064;
	case 4200ULL: goto x86_l_1068;
	case 4205ULL: goto x86_l_106d;
	case 4210ULL: goto x86_l_1072;
	case 4212ULL: goto x86_l_1074;
	case 4215ULL: goto x86_l_1077;
	case 4221ULL: goto x86_l_107d;
	case 4225ULL: goto x86_l_1081;
	case 4228ULL: goto x86_l_1084;
	case 4235ULL: goto x86_l_108b;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4252ULL: goto x86_l_109c;
	case 4255ULL: goto x86_l_109f;
	case 4257ULL: goto x86_l_10a1;
	case 4260ULL: goto x86_l_10a4;
	case 4266ULL: goto x86_l_10aa;
	case 4271ULL: goto x86_l_10af;
	case 4275ULL: goto x86_l_10b3;
	case 4281ULL: goto x86_l_10b9;
	case 4285ULL: goto x86_l_10bd;
	case 4291ULL: goto x86_l_10c3;
	case 4296ULL: goto x86_l_10c8;
	case 4299ULL: goto x86_l_10cb;
	case 4304ULL: goto x86_l_10d0;
	case 4306ULL: goto x86_l_10d2;
	case 4309ULL: goto x86_l_10d5;
	case 4314ULL: goto x86_l_10da;
	case 4318ULL: goto x86_l_10de;
	case 4324ULL: goto x86_l_10e4;
	case 4328ULL: goto x86_l_10e8;
	case 4334ULL: goto x86_l_10ee;
	case 4343ULL: goto x86_l_10f7;
	case 4346ULL: goto x86_l_10fa;
	case 4353ULL: goto x86_l_1101;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4392ULL: goto x86_l_1128;
	case 4397ULL: goto x86_l_112d;
	case 4399ULL: goto x86_l_112f;
	case 4403ULL: goto x86_l_1133;
	case 4410ULL: goto x86_l_113a;
	case 4415ULL: goto x86_l_113f;
	case 4420ULL: goto x86_l_1144;
	case 4423ULL: goto x86_l_1147;
	case 4426ULL: goto x86_l_114a;
	case 4428ULL: goto x86_l_114c;
	case 4432ULL: goto x86_l_1150;
	case 4439ULL: goto x86_l_1157;
	case 4446ULL: goto x86_l_115e;
	case 4451ULL: goto x86_l_1163;
	case 4456ULL: goto x86_l_1168;
	case 4458ULL: goto x86_l_116a;
	case 4462ULL: goto x86_l_116e;
	case 4469ULL: goto x86_l_1175;
	case 4476ULL: goto x86_l_117c;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4489ULL: goto x86_l_1189;
	case 4491ULL: goto x86_l_118b;
	case 4495ULL: goto x86_l_118f;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4510ULL: goto x86_l_119e;
	case 4514ULL: goto x86_l_11a2;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4528ULL: goto x86_l_11b0;
	case 4536ULL: goto x86_l_11b8;
	case 4539ULL: goto x86_l_11bb;
	case 4545ULL: goto x86_l_11c1;
	case 4548ULL: goto x86_l_11c4;
	case 4555ULL: goto x86_l_11cb;
	case 4557ULL: goto x86_l_11cd;
	case 4562ULL: goto x86_l_11d2;
	case 4564ULL: goto x86_l_11d4;
	case 4567ULL: goto x86_l_11d7;
	case 4570ULL: goto x86_l_11da;
	case 4576ULL: goto x86_l_11e0;
	case 4581ULL: goto x86_l_11e5;
	case 4584ULL: goto x86_l_11e8;
	case 4593ULL: goto x86_l_11f1;
	case 4602ULL: goto x86_l_11fa;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4633ULL: goto x86_l_1219;
	case 4638ULL: goto x86_l_121e;
	case 4640ULL: goto x86_l_1220;
	case 4644ULL: goto x86_l_1224;
	case 4648ULL: goto x86_l_1228;
	case 4653ULL: goto x86_l_122d;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4667ULL: goto x86_l_123b;
	case 4670ULL: goto x86_l_123e;
	case 4676ULL: goto x86_l_1244;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4694ULL: goto x86_l_1256;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4705ULL: goto x86_l_1261;
	case 4707ULL: goto x86_l_1263;
	case 4714ULL: goto x86_l_126a;
	case 4718ULL: goto x86_l_126e;
	case 4725ULL: goto x86_l_1275;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4737ULL: goto x86_l_1281;
	case 4739ULL: goto x86_l_1283;
	case 4747ULL: goto x86_l_128b;
	case 4750ULL: goto x86_l_128e;
	case 4754ULL: goto x86_l_1292;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4768ULL: goto x86_l_12a0;
	case 4770ULL: goto x86_l_12a2;
	case 4774ULL: goto x86_l_12a6;
	case 4779ULL: goto x86_l_12ab;
	case 4784ULL: goto x86_l_12b0;
	case 4787ULL: goto x86_l_12b3;
	case 4792ULL: goto x86_l_12b8;
	case 4797ULL: goto x86_l_12bd;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4813ULL: goto x86_l_12cd;
	case 4815ULL: goto x86_l_12cf;
	case 4823ULL: goto x86_l_12d7;
	case 4825ULL: goto x86_l_12d9;
	case 4831ULL: goto x86_l_12df;
	case 4834ULL: goto x86_l_12e2;
	case 4840ULL: goto x86_l_12e8;
	case 4844ULL: goto x86_l_12ec;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4860ULL: goto x86_l_12fc;
	case 4865ULL: goto x86_l_1301;
	case 4868ULL: goto x86_l_1304;
	case 4870ULL: goto x86_l_1306;
	case 4875ULL: goto x86_l_130b;
	case 4880ULL: goto x86_l_1310;
	case 4885ULL: goto x86_l_1315;
	case 4890ULL: goto x86_l_131a;
	case 4892ULL: goto x86_l_131c;
	case 4897ULL: goto x86_l_1321;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4934ULL: goto x86_l_1346;
	case 4941ULL: goto x86_l_134d;
	case 4947ULL: goto x86_l_1353;
	case 4951ULL: goto x86_l_1357;
	case 4954ULL: goto x86_l_135a;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4971ULL: goto x86_l_136b;
	case 4976ULL: goto x86_l_1370;
	case 4981ULL: goto x86_l_1375;
	case 4988ULL: goto x86_l_137c;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5008ULL: goto x86_l_1390;
	case 5010ULL: goto x86_l_1392;
	case 5017ULL: goto x86_l_1399;
	case 5021ULL: goto x86_l_139d;
	case 5026ULL: goto x86_l_13a2;
	case 5031ULL: goto x86_l_13a7;
	case 5033ULL: goto x86_l_13a9;
	case 5040ULL: goto x86_l_13b0;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5057ULL: goto x86_l_13c1;
	case 5059ULL: goto x86_l_13c3;
	case 5066ULL: goto x86_l_13ca;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5085ULL: goto x86_l_13dd;
	case 5094ULL: goto x86_l_13e6;
	case 5101ULL: goto x86_l_13ed;
	case 5106ULL: goto x86_l_13f2;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5118ULL: goto x86_l_13fe;
	case 5125ULL: goto x86_l_1405;
	case 5130ULL: goto x86_l_140a;
	case 5138ULL: goto x86_l_1412;
	case 5143ULL: goto x86_l_1417;
	case 5145ULL: goto x86_l_1419;
	case 5154ULL: goto x86_l_1422;
	case 5159ULL: goto x86_l_1427;
	case 5164ULL: goto x86_l_142c;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5180ULL: goto x86_l_143c;
	case 5182ULL: goto x86_l_143e;
	case 5190ULL: goto x86_l_1446;
	case 5193ULL: goto x86_l_1449;
	case 5196ULL: goto x86_l_144c;
	case 5202ULL: goto x86_l_1452;
	case 5205ULL: goto x86_l_1455;
	case 5211ULL: goto x86_l_145b;
	case 5216ULL: goto x86_l_1460;
	case 5221ULL: goto x86_l_1465;
	case 5229ULL: goto x86_l_146d;
	case 5234ULL: goto x86_l_1472;
	case 5236ULL: goto x86_l_1474;
	case 5244ULL: goto x86_l_147c;
	case 5248ULL: goto x86_l_1480;
	case 5255ULL: goto x86_l_1487;
	case 5264ULL: goto x86_l_1490;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5281ULL: goto x86_l_14a1;
	case 5288ULL: goto x86_l_14a8;
	case 5296ULL: goto x86_l_14b0;
	case 5304ULL: goto x86_l_14b8;
	case 5312ULL: goto x86_l_14c0;
	case 5317ULL: goto x86_l_14c5;
	case 5322ULL: goto x86_l_14ca;
	case 5324ULL: goto x86_l_14cc;
	case 5328ULL: goto x86_l_14d0;
	case 5333ULL: goto x86_l_14d5;
	case 5336ULL: goto x86_l_14d8;
	case 5341ULL: goto x86_l_14dd;
	case 5344ULL: goto x86_l_14e0;
	case 5346ULL: goto x86_l_14e2;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5366ULL: goto x86_l_14f6;
	case 5371ULL: goto x86_l_14fb;
	case 5376ULL: goto x86_l_1500;
	case 5381ULL: goto x86_l_1505;
	case 5386ULL: goto x86_l_150a;
	case 5390ULL: goto x86_l_150e;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5407ULL: goto x86_l_151f;
	case 5409ULL: goto x86_l_1521;
	case 5412ULL: goto x86_l_1524;
	case 5415ULL: goto x86_l_1527;
	case 5421ULL: goto x86_l_152d;
	case 5425ULL: goto x86_l_1531;
	case 5430ULL: goto x86_l_1536;
	case 5432ULL: goto x86_l_1538;
	case 5436ULL: goto x86_l_153c;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5461ULL: goto x86_l_1555;
	case 5469ULL: goto x86_l_155d;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5486ULL: goto x86_l_156e;
	case 5489ULL: goto x86_l_1571;
	case 5492ULL: goto x86_l_1574;
	case 5494ULL: goto x86_l_1576;
	case 5497ULL: goto x86_l_1579;
	case 5501ULL: goto x86_l_157d;
	case 5507ULL: goto x86_l_1583;
	case 5511ULL: goto x86_l_1587;
	case 5514ULL: goto x86_l_158a;
	case 5520ULL: goto x86_l_1590;
	case 5523ULL: goto x86_l_1593;
	case 5529ULL: goto x86_l_1599;
	case 5534ULL: goto x86_l_159e;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5549ULL: goto x86_l_15ad;
	case 5551ULL: goto x86_l_15af;
	case 5555ULL: goto x86_l_15b3;
	case 5559ULL: goto x86_l_15b7;
	case 5566ULL: goto x86_l_15be;
	case 5573ULL: goto x86_l_15c5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e6b:
	/* 0xe6b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6f:
	/* 0xe6f: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_e75:
	/* 0xe75: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_e7a:
	/* 0xe7a: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_e80:
	/* 0xe80: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e85:
	/* 0xe85: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e8a:
	/* 0xe8a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8f:
	/* 0xe8f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e94:
	/* 0xe94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e96:
	/* 0xe96: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e9a:
	/* 0xe9a: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_e9f:
	/* 0xe9f: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_ea3:
	/* 0xea3: je     1aa6 <generic_retkprobe_event+0x1aa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6822ULL;
	}
x86_l_ea9:
	/* 0xea9: cmp    r14d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 41ULL);
x86_l_ead:
	/* 0xead: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_eb3:
	/* 0xeb3: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb8:
	/* 0xeb8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_ebb:
	/* 0xebb: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_ebf:
	/* 0xebf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ec4:
	/* 0xec4: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ec9:
	/* 0xec9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ece:
	/* 0xece: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_ed1:
	/* 0xed1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed3:
	/* 0xed3: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ed8:
	/* 0xed8: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_edb:
	/* 0xedb: je     1f6e <generic_retkprobe_event+0x1f6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8046ULL;
	}
x86_l_ee1:
	/* 0xee1: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee5:
	/* 0xee5: mov    QWORD PTR [rbp+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_eec:
	/* 0xeec: lea    rdi,[rbp+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_ef3:
	/* 0xef3: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ef8:
	/* 0xef8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_efd:
	/* 0xefd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f02:
	/* 0xf02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f04:
	/* 0xf04: lea    rdi,[rbp+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_f0b:
	/* 0xf0b: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_f10:
	/* 0xf10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f15:
	/* 0xf15: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_f1a:
	/* 0xf1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1c:
	/* 0xf1c: lea    rdi,[rbp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_f23:
	/* 0xf23: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_f2b:
	/* 0xf2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f30:
	/* 0xf30: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f35:
	/* 0xf35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f37:
	/* 0xf37: lea    rdi,[rbp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_f3e:
	/* 0xf3e: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_f46:
	/* 0xf46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f4b:
	/* 0xf4b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f50:
	/* 0xf50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f52:
	/* 0xf52: lea    rdi,[rbp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_f59:
	/* 0xf59: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_f61:
	/* 0xf61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f66:
	/* 0xf66: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f6b:
	/* 0xf6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6d:
	/* 0xf6d: lea    rdi,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_f74:
	/* 0xf74: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_f7c:
	/* 0xf7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f81:
	/* 0xf81: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f86:
	/* 0xf86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f88:
	/* 0xf88: lea    r13,[rbp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_f8f:
	/* 0xf8f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f94:
	/* 0xf94: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9b:
	/* 0xf9b: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_fa3:
	/* 0xfa3: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_fab:
	/* 0xfab: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fae:
	/* 0xfae: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_fb6:
	/* 0xfb6: movzx  eax,WORD PTR [rbp+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_fbd:
	/* 0xfbd: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_fc0:
	/* 0xfc0: je     1efd <generic_retkprobe_event+0x1efd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7933ULL;
	}
x86_l_fc6:
	/* 0xfc6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fc9:
	/* 0xfc9: jne    1f22 <generic_retkprobe_event+0x1f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7970ULL;
	}
x86_l_fcf:
	/* 0xfcf: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fd4:
	/* 0xfd4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fd9:
	/* 0xfd9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fde:
	/* 0xfde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe0:
	/* 0xfe0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fe5:
	/* 0xfe5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_fe8:
	/* 0xfe8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fed:
	/* 0xfed: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ff0:
	/* 0xff0: jmp    1f20 <generic_retkprobe_event+0x1f20> */
	return 7968ULL;
x86_l_ff5:
	/* 0xff5: cmp    r14d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 26ULL);
x86_l_ff9:
	/* 0xff9: je     1b34 <generic_retkprobe_event+0x1b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6964ULL;
	}
x86_l_fff:
	/* 0xfff: cmp    r14d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 27ULL);
x86_l_1003:
	/* 0x1003: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_1009:
	/* 0x1009: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_100e:
	/* 0x100e: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1016:
	/* 0x1016: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_101e:
	/* 0x101e: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1026:
	/* 0x1026: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_102e:
	/* 0x102e: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1036:
	/* 0x1036: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_103e:
	/* 0x103e: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1046:
	/* 0x1046: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_104e:
	/* 0x104e: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1056:
	/* 0x1056: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_105d:
	/* 0x105d: lea    rdi,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1064:
	/* 0x1064: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1068:
	/* 0x1068: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_106d:
	/* 0x106d: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1072:
	/* 0x1072: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1074:
	/* 0x1074: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1077:
	/* 0x1077: js     1ba8 <generic_retkprobe_event+0x1ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7080ULL;
	}
x86_l_107d:
	/* 0x107d: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1081:
	/* 0x1081: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1084:
	/* 0x1084: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_108b:
	/* 0x108b: add    rbp,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_1092:
	/* 0x1092: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1097:
	/* 0x1097: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_109c:
	/* 0x109c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_109f:
	/* 0x109f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a1:
	/* 0x10a1: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_10a4:
	/* 0x10a4: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_10aa:
	/* 0x10aa: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_10af:
	/* 0x10af: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_10b3:
	/* 0x10b3: je     1745 <generic_retkprobe_event+0x1745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5957ULL;
	}
x86_l_10b9:
	/* 0x10b9: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_10bd:
	/* 0x10bd: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_10c3:
	/* 0x10c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10c8:
	/* 0x10c8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10cb:
	/* 0x10cb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10d0:
	/* 0x10d0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d2:
	/* 0x10d2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_10d5:
	/* 0x10d5: jmp    e94 <generic_retkprobe_event+0xe94> */
	goto x86_l_e94;
x86_l_10da:
	/* 0x10da: cmp    r14d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 19ULL);
x86_l_10de:
	/* 0x10de: je     1a56 <generic_retkprobe_event+0x1a56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6742ULL;
	}
x86_l_10e4:
	/* 0x10e4: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_10e8:
	/* 0x10e8: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_10ee:
	/* 0x10ee: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_10f7:
	/* 0x10f7: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_10fa:
	/* 0x10fa: lea    r12,[rbp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1101:
	/* 0x1101: lea    rdx,[rbp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1108:
	/* 0x1108: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_110d:
	/* 0x110d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1112:
	/* 0x1112: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1117:
	/* 0x1117: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1119:
	/* 0x1119: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_111e:
	/* 0x111e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1123:
	/* 0x1123: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1128:
	/* 0x1128: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_112d:
	/* 0x112d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112f:
	/* 0x112f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1133:
	/* 0x1133: lea    rdi,[rax+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_113a:
	/* 0x113a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_113f:
	/* 0x113f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1144:
	/* 0x1144: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1147:
	/* 0x1147: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_114a:
	/* 0x114a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114c:
	/* 0x114c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1150:
	/* 0x1150: lea    rdi,[rax+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_1157:
	/* 0x1157: lea    rdx,[rbp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_115e:
	/* 0x115e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1163:
	/* 0x1163: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1168:
	/* 0x1168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116a:
	/* 0x116a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116e:
	/* 0x116e: add    rdi,0x124 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_1175:
	/* 0x1175: add    rbp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_117c:
	/* 0x117c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1181:
	/* 0x1181: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1186:
	/* 0x1186: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1189:
	/* 0x1189: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118b:
	/* 0x118b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_118f:
	/* 0x118f: mov    r13d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 152ULL);
x86_l_1195:
	/* 0x1195: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_119a:
	/* 0x119a: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_119e:
	/* 0x119e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a2:
	/* 0x11a2: jne    283f <generic_retkprobe_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10303ULL;
	}
x86_l_11a8:
	/* 0x11a8: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ad:
	/* 0x11ad: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11b0:
	/* 0x11b0: add    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 176ULL);
x86_l_11b8:
	/* 0x11b8: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11bb:
	/* 0x11bb: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11c1:
	/* 0x11c1: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_11c4:
	/* 0x11c4: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_11cb:
	/* 0x11cb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11cd:
	/* 0x11cd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_11d2:
	/* 0x11d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d4:
	/* 0x11d4: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_11d7:
	/* 0x11d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11da:
	/* 0x11da: jns    152d <generic_retkprobe_event+0x152d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_152d;
	}
x86_l_11e0:
	/* 0x11e0: jmp    1ebc <generic_retkprobe_event+0x1ebc> */
	return 7868ULL;
x86_l_11e5:
	/* 0x11e5: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_11e8:
	/* 0x11e8: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_11f1:
	/* 0x11f1: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_11fa:
	/* 0x11fa: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_11ff:
	/* 0x11ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1201:
	/* 0x1201: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1205:
	/* 0x1205: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_120a:
	/* 0x120a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_120f:
	/* 0x120f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1214:
	/* 0x1214: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1219:
	/* 0x1219: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_121e:
	/* 0x121e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1220:
	/* 0x1220: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1224:
	/* 0x1224: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1228:
	/* 0x1228: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_122d:
	/* 0x122d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1234:
	/* 0x1234: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1239:
	/* 0x1239: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123b:
	/* 0x123b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_123e:
	/* 0x123e: je     1bb4 <generic_retkprobe_event+0x1bb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7092ULL;
	}
x86_l_1244:
	/* 0x1244: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1247:
	/* 0x1247: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_124c:
	/* 0x124c: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1251:
	/* 0x1251: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1256:
	/* 0x1256: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1259:
	/* 0x1259: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_125e:
	/* 0x125e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1261:
	/* 0x1261: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1263:
	/* 0x1263: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_126a:
	/* 0x126a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_126e:
	/* 0x126e: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1275:
	/* 0x1275: lea    esi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1279:
	/* 0x1279: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_127e:
	/* 0x127e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1281:
	/* 0x1281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1283:
	/* 0x1283: lea    rdi,[r13*1+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_128b:
	/* 0x128b: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_128e:
	/* 0x128e: lea    rdx,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1292:
	/* 0x1292: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1296:
	/* 0x1296: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_129b:
	/* 0x129b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12a0:
	/* 0x12a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a2:
	/* 0x12a2: add    r13,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_12a6:
	/* 0x12a6: jmp    1ef1 <generic_retkprobe_event+0x1ef1> */
	return 7921ULL;
x86_l_12ab:
	/* 0x12ab: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b0:
	/* 0x12b0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_12b3:
	/* 0x12b3: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b8:
	/* 0x12b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12bd:
	/* 0x12bd: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_12c5:
	/* 0x12c5: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_12ca:
	/* 0x12ca: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_12cd:
	/* 0x12cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cf:
	/* 0x12cf: movzx  eax,BYTE PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 168ULL);
x86_l_12d7:
	/* 0x12d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12d9:
	/* 0x12d9: je     1bd3 <generic_retkprobe_event+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_12df:
	/* 0x12df: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e2:
	/* 0x12e2: jne    1dc1 <generic_retkprobe_event+0x1dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7617ULL;
	}
x86_l_12e8:
	/* 0x12e8: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_12ec:
	/* 0x12ec: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_12f2:
	/* 0x12f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12f7:
	/* 0x12f7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12fc:
	/* 0x12fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1301:
	/* 0x1301: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1304:
	/* 0x1304: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1306:
	/* 0x1306: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_130b:
	/* 0x130b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1310:
	/* 0x1310: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1315:
	/* 0x1315: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_131a:
	/* 0x131a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131c:
	/* 0x131c: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1321:
	/* 0x1321: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1325:
	/* 0x1325: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_132a:
	/* 0x132a: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1332:
	/* 0x1332: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1337:
	/* 0x1337: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1339:
	/* 0x1339: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_133e:
	/* 0x133e: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1346:
	/* 0x1346: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_134d:
	/* 0x134d: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1353:
	/* 0x1353: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_1357:
	/* 0x1357: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_135a:
	/* 0x135a: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1361:
	/* 0x1361: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1366:
	/* 0x1366: jmp    1c37 <generic_retkprobe_event+0x1c37> */
	return 7223ULL;
x86_l_136b:
	/* 0x136b: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1370:
	/* 0x1370: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1375:
	/* 0x1375: lea    rdi,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_137c:
	/* 0x137c: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1383:
	/* 0x1383: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1388:
	/* 0x1388: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_138d:
	/* 0x138d: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_1390:
	/* 0x1390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1392:
	/* 0x1392: lea    rdi,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1399:
	/* 0x1399: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_139d:
	/* 0x139d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13a2:
	/* 0x13a2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13a7:
	/* 0x13a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a9:
	/* 0x13a9: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_13b0:
	/* 0x13b0: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_13b7:
	/* 0x13b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13bc:
	/* 0x13bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13c1:
	/* 0x13c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c3:
	/* 0x13c3: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_13ca:
	/* 0x13ca: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_13d1:
	/* 0x13d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13d6:
	/* 0x13d6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13db:
	/* 0x13db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dd:
	/* 0x13dd: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_13e6:
	/* 0x13e6: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_13ed:
	/* 0x13ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13f2:
	/* 0x13f2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13f7:
	/* 0x13f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13fc:
	/* 0x13fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fe:
	/* 0x13fe: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1405:
	/* 0x1405: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_140a:
	/* 0x140a: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1412:
	/* 0x1412: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1417:
	/* 0x1417: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1419:
	/* 0x1419: movzx  r12d,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_1422:
	/* 0x1422: add    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_1427:
	/* 0x1427: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_142c:
	/* 0x142c: lea    rdi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1434:
	/* 0x1434: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1439:
	/* 0x1439: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_143c:
	/* 0x143c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143e:
	/* 0x143e: movzx  eax,BYTE PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 164ULL);
x86_l_1446:
	/* 0x1446: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_1449:
	/* 0x1449: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_144c:
	/* 0x144c: je     1c6a <generic_retkprobe_event+0x1c6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7274ULL;
	}
x86_l_1452:
	/* 0x1452: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1455:
	/* 0x1455: jne    2830 <generic_retkprobe_event+0x2830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10288ULL;
	}
x86_l_145b:
	/* 0x145b: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1460:
	/* 0x1460: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1465:
	/* 0x1465: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_146d:
	/* 0x146d: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1472:
	/* 0x1472: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1474:
	/* 0x1474: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_147c:
	/* 0x147c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1480:
	/* 0x1480: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1487:
	/* 0x1487: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_1490:
	/* 0x1490: lea    r13,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1497:
	/* 0x1497: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_149c:
	/* 0x149c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a1:
	/* 0x14a1: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a8:
	/* 0x14a8: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_14b0:
	/* 0x14b0: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_14b8:
	/* 0x14b8: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_14c0:
	/* 0x14c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c5:
	/* 0x14c5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14ca:
	/* 0x14ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14cc:
	/* 0x14cc: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14d0:
	/* 0x14d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14d5:
	/* 0x14d5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_14d8:
	/* 0x14d8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14dd:
	/* 0x14dd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_14e0:
	/* 0x14e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e2:
	/* 0x14e2: lea    rdx,[rbp+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_14e9:
	/* 0x14e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14ee:
	/* 0x14ee: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_14f6:
	/* 0x14f6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_14fb:
	/* 0x14fb: jmp    26db <generic_retkprobe_event+0x26db> */
	return 9947ULL;
x86_l_1500:
	/* 0x1500: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1505:
	/* 0x1505: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_150a:
	/* 0x150a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_150e:
	/* 0x150e: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1515:
	/* 0x1515: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_151a:
	/* 0x151a: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_151f:
	/* 0x151f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1521:
	/* 0x1521: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1524:
	/* 0x1524: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1527:
	/* 0x1527: js     1ebc <generic_retkprobe_event+0x1ebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7868ULL;
	}
x86_l_152d:
	/* 0x152d: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1531:
	/* 0x1531: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1536:
	/* 0x1536: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1538:
	/* 0x1538: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_153c:
	/* 0x153c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1540:
	/* 0x1540: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_1545:
	/* 0x1545: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1548:
	/* 0x1548: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_154d:
	/* 0x154d: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1555:
	/* 0x1555: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_155d:
	/* 0x155d: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1564:
	/* 0x1564: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1569:
	/* 0x1569: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_156e:
	/* 0x156e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1571:
	/* 0x1571: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_1574:
	/* 0x1574: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1576:
	/* 0x1576: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1579:
	/* 0x1579: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_157d:
	/* 0x157d: js     1e23 <generic_retkprobe_event+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7715ULL;
	}
x86_l_1583:
	/* 0x1583: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1587:
	/* 0x1587: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_158a:
	/* 0x158a: je     1dd7 <generic_retkprobe_event+0x1dd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7639ULL;
	}
x86_l_1590:
	/* 0x1590: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1593:
	/* 0x1593: jne    1e0f <generic_retkprobe_event+0x1e0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7695ULL;
	}
x86_l_1599:
	/* 0x1599: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_159e:
	/* 0x159e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15a3:
	/* 0x15a3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15a8:
	/* 0x15a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15ad:
	/* 0x15ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15af:
	/* 0x15af: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15b3:
	/* 0x15b3: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b7:
	/* 0x15b7: mov    QWORD PTR [rdi+0xa4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_15be:
	/* 0x15be: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_15c5:
	/* 0x15c5: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
	return 5577ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5577ULL: goto x86_l_15c9;
	case 5582ULL: goto x86_l_15ce;
	case 5587ULL: goto x86_l_15d3;
	case 5590ULL: goto x86_l_15d6;
	case 5599ULL: goto x86_l_15df;
	case 5605ULL: goto x86_l_15e5;
	case 5613ULL: goto x86_l_15ed;
	case 5617ULL: goto x86_l_15f1;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5633ULL: goto x86_l_1601;
	case 5638ULL: goto x86_l_1606;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5647ULL: goto x86_l_160f;
	case 5653ULL: goto x86_l_1615;
	case 5658ULL: goto x86_l_161a;
	case 5661ULL: goto x86_l_161d;
	case 5664ULL: goto x86_l_1620;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5676ULL: goto x86_l_162c;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5692ULL: goto x86_l_163c;
	case 5697ULL: goto x86_l_1641;
	case 5703ULL: goto x86_l_1647;
	case 5706ULL: goto x86_l_164a;
	case 5711ULL: goto x86_l_164f;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5726ULL: goto x86_l_165e;
	case 5729ULL: goto x86_l_1661;
	case 5734ULL: goto x86_l_1666;
	case 5739ULL: goto x86_l_166b;
	case 5741ULL: goto x86_l_166d;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5750ULL: goto x86_l_1676;
	case 5756ULL: goto x86_l_167c;
	case 5759ULL: goto x86_l_167f;
	case 5762ULL: goto x86_l_1682;
	case 5768ULL: goto x86_l_1688;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5785ULL: goto x86_l_1699;
	case 5790ULL: goto x86_l_169e;
	case 5793ULL: goto x86_l_16a1;
	case 5798ULL: goto x86_l_16a6;
	case 5803ULL: goto x86_l_16ab;
	case 5812ULL: goto x86_l_16b4;
	case 5821ULL: goto x86_l_16bd;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5837ULL: goto x86_l_16cd;
	case 5842ULL: goto x86_l_16d2;
	case 5847ULL: goto x86_l_16d7;
	case 5850ULL: goto x86_l_16da;
	case 5852ULL: goto x86_l_16dc;
	case 5857ULL: goto x86_l_16e1;
	case 5863ULL: goto x86_l_16e7;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5878ULL: goto x86_l_16f6;
	case 5883ULL: goto x86_l_16fb;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5898ULL: goto x86_l_170a;
	case 5901ULL: goto x86_l_170d;
	case 5904ULL: goto x86_l_1710;
	case 5906ULL: goto x86_l_1712;
	case 5911ULL: goto x86_l_1717;
	case 5913ULL: goto x86_l_1719;
	case 5915ULL: goto x86_l_171b;
	case 5920ULL: goto x86_l_1720;
	case 5927ULL: goto x86_l_1727;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5938ULL: goto x86_l_1732;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5952ULL: goto x86_l_1740;
	case 5957ULL: goto x86_l_1745;
	case 5964ULL: goto x86_l_174c;
	case 5967ULL: goto x86_l_174f;
	case 5974ULL: goto x86_l_1756;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5995ULL: goto x86_l_176b;
	case 5999ULL: goto x86_l_176f;
	case 6006ULL: goto x86_l_1776;
	case 6010ULL: goto x86_l_177a;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6022ULL: goto x86_l_1786;
	case 6026ULL: goto x86_l_178a;
	case 6033ULL: goto x86_l_1791;
	case 6037ULL: goto x86_l_1795;
	case 6042ULL: goto x86_l_179a;
	case 6047ULL: goto x86_l_179f;
	case 6049ULL: goto x86_l_17a1;
	case 6053ULL: goto x86_l_17a5;
	case 6060ULL: goto x86_l_17ac;
	case 6064ULL: goto x86_l_17b0;
	case 6069ULL: goto x86_l_17b5;
	case 6074ULL: goto x86_l_17ba;
	case 6076ULL: goto x86_l_17bc;
	case 6080ULL: goto x86_l_17c0;
	case 6087ULL: goto x86_l_17c7;
	case 6091ULL: goto x86_l_17cb;
	case 6096ULL: goto x86_l_17d0;
	case 6101ULL: goto x86_l_17d5;
	case 6103ULL: goto x86_l_17d7;
	case 6107ULL: goto x86_l_17db;
	case 6114ULL: goto x86_l_17e2;
	case 6118ULL: goto x86_l_17e6;
	case 6123ULL: goto x86_l_17eb;
	case 6128ULL: goto x86_l_17f0;
	case 6130ULL: goto x86_l_17f2;
	case 6134ULL: goto x86_l_17f6;
	case 6141ULL: goto x86_l_17fd;
	case 6145ULL: goto x86_l_1801;
	case 6150ULL: goto x86_l_1806;
	case 6155ULL: goto x86_l_180b;
	case 6157ULL: goto x86_l_180d;
	case 6161ULL: goto x86_l_1811;
	case 6168ULL: goto x86_l_1818;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6188ULL: goto x86_l_182c;
	case 6198ULL: goto x86_l_1836;
	case 6202ULL: goto x86_l_183a;
	case 6209ULL: goto x86_l_1841;
	case 6213ULL: goto x86_l_1845;
	case 6218ULL: goto x86_l_184a;
	case 6223ULL: goto x86_l_184f;
	case 6225ULL: goto x86_l_1851;
	case 6229ULL: goto x86_l_1855;
	case 6236ULL: goto x86_l_185c;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6250ULL: goto x86_l_186a;
	case 6252ULL: goto x86_l_186c;
	case 6256ULL: goto x86_l_1870;
	case 6263ULL: goto x86_l_1877;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6279ULL: goto x86_l_1887;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6298ULL: goto x86_l_189a;
	case 6305ULL: goto x86_l_18a1;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6323ULL: goto x86_l_18b3;
	case 6325ULL: goto x86_l_18b5;
	case 6330ULL: goto x86_l_18ba;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6345ULL: goto x86_l_18c9;
	case 6348ULL: goto x86_l_18cc;
	case 6353ULL: goto x86_l_18d1;
	case 6355ULL: goto x86_l_18d3;
	case 6359ULL: goto x86_l_18d7;
	case 6366ULL: goto x86_l_18de;
	case 6373ULL: goto x86_l_18e5;
	case 6378ULL: goto x86_l_18ea;
	case 6383ULL: goto x86_l_18ef;
	case 6385ULL: goto x86_l_18f1;
	case 6389ULL: goto x86_l_18f5;
	case 6396ULL: goto x86_l_18fc;
	case 6403ULL: goto x86_l_1903;
	case 6408ULL: goto x86_l_1908;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6419ULL: goto x86_l_1913;
	case 6426ULL: goto x86_l_191a;
	case 6433ULL: goto x86_l_1921;
	case 6438ULL: goto x86_l_1926;
	case 6443ULL: goto x86_l_192b;
	case 6446ULL: goto x86_l_192e;
	case 6448ULL: goto x86_l_1930;
	case 6452ULL: goto x86_l_1934;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6470ULL: goto x86_l_1946;
	case 6475ULL: goto x86_l_194b;
	case 6480ULL: goto x86_l_1950;
	case 6485ULL: goto x86_l_1955;
	case 6487ULL: goto x86_l_1957;
	case 6491ULL: goto x86_l_195b;
	case 6498ULL: goto x86_l_1962;
	case 6505ULL: goto x86_l_1969;
	case 6510ULL: goto x86_l_196e;
	case 6515ULL: goto x86_l_1973;
	case 6517ULL: goto x86_l_1975;
	case 6521ULL: goto x86_l_1979;
	case 6528ULL: goto x86_l_1980;
	case 6535ULL: goto x86_l_1987;
	case 6540ULL: goto x86_l_198c;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6551ULL: goto x86_l_1997;
	case 6558ULL: goto x86_l_199e;
	case 6565ULL: goto x86_l_19a5;
	case 6570ULL: goto x86_l_19aa;
	case 6575ULL: goto x86_l_19af;
	case 6578ULL: goto x86_l_19b2;
	case 6580ULL: goto x86_l_19b4;
	case 6584ULL: goto x86_l_19b8;
	case 6590ULL: goto x86_l_19be;
	case 6595ULL: goto x86_l_19c3;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6616ULL: goto x86_l_19d8;
	case 6620ULL: goto x86_l_19dc;
	case 6627ULL: goto x86_l_19e3;
	case 6631ULL: goto x86_l_19e7;
	case 6636ULL: goto x86_l_19ec;
	case 6641ULL: goto x86_l_19f1;
	case 6643ULL: goto x86_l_19f3;
	case 6647ULL: goto x86_l_19f7;
	case 6654ULL: goto x86_l_19fe;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6668ULL: goto x86_l_1a0c;
	case 6670ULL: goto x86_l_1a0e;
	case 6674ULL: goto x86_l_1a12;
	case 6681ULL: goto x86_l_1a19;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6697ULL: goto x86_l_1a29;
	case 6701ULL: goto x86_l_1a2d;
	case 6708ULL: goto x86_l_1a34;
	case 6712ULL: goto x86_l_1a38;
	case 6717ULL: goto x86_l_1a3d;
	case 6722ULL: goto x86_l_1a42;
	case 6725ULL: goto x86_l_1a45;
	case 6727ULL: goto x86_l_1a47;
	case 6731ULL: goto x86_l_1a4b;
	case 6737ULL: goto x86_l_1a51;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6760ULL: goto x86_l_1a68;
	case 6762ULL: goto x86_l_1a6a;
	case 6766ULL: goto x86_l_1a6e;
	case 6773ULL: goto x86_l_1a75;
	case 6777ULL: goto x86_l_1a79;
	case 6782ULL: goto x86_l_1a7e;
	case 6787ULL: goto x86_l_1a83;
	case 6789ULL: goto x86_l_1a85;
	case 6793ULL: goto x86_l_1a89;
	case 6800ULL: goto x86_l_1a90;
	case 6804ULL: goto x86_l_1a94;
	case 6809ULL: goto x86_l_1a99;
	case 6814ULL: goto x86_l_1a9e;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6826ULL: goto x86_l_1aaa;
	case 6831ULL: goto x86_l_1aaf;
	case 6836ULL: goto x86_l_1ab4;
	case 6841ULL: goto x86_l_1ab9;
	case 6843ULL: goto x86_l_1abb;
	case 6847ULL: goto x86_l_1abf;
	case 6851ULL: goto x86_l_1ac3;
	case 6857ULL: goto x86_l_1ac9;
	case 6861ULL: goto x86_l_1acd;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	case 6878ULL: goto x86_l_1ade;
	case 6882ULL: goto x86_l_1ae2;
	case 6886ULL: goto x86_l_1ae6;
	case 6892ULL: goto x86_l_1aec;
	case 6896ULL: goto x86_l_1af0;
	case 6901ULL: goto x86_l_1af5;
	case 6906ULL: goto x86_l_1afa;
	case 6911ULL: goto x86_l_1aff;
	case 6914ULL: goto x86_l_1b02;
	case 6916ULL: goto x86_l_1b04;
	case 6920ULL: goto x86_l_1b08;
	case 6927ULL: goto x86_l_1b0f;
	case 6932ULL: goto x86_l_1b14;
	case 6937ULL: goto x86_l_1b19;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6949ULL: goto x86_l_1b25;
	case 6953ULL: goto x86_l_1b29;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6977ULL: goto x86_l_1b41;
	case 6985ULL: goto x86_l_1b49;
	case 6993ULL: goto x86_l_1b51;
	case 7001ULL: goto x86_l_1b59;
	case 7009ULL: goto x86_l_1b61;
	case 7017ULL: goto x86_l_1b69;
	case 7025ULL: goto x86_l_1b71;
	case 7033ULL: goto x86_l_1b79;
	case 7041ULL: goto x86_l_1b81;
	case 7044ULL: goto x86_l_1b84;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7061ULL: goto x86_l_1b95;
	case 7066ULL: goto x86_l_1b9a;
	case 7069ULL: goto x86_l_1b9d;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7080ULL: goto x86_l_1ba8;
	case 7083ULL: goto x86_l_1bab;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7099ULL: goto x86_l_1bbb;
	case 7104ULL: goto x86_l_1bc0;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7118ULL: goto x86_l_1bce;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7151ULL: goto x86_l_1bef;
	case 7155ULL: goto x86_l_1bf3;
	case 7160ULL: goto x86_l_1bf8;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7176ULL: goto x86_l_1c08;
	case 7178ULL: goto x86_l_1c0a;
	case 7183ULL: goto x86_l_1c0f;
	case 7191ULL: goto x86_l_1c17;
	case 7198ULL: goto x86_l_1c1e;
	case 7204ULL: goto x86_l_1c24;
	case 7208ULL: goto x86_l_1c28;
	case 7211ULL: goto x86_l_1c2b;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7226ULL: goto x86_l_1c3a;
	case 7228ULL: goto x86_l_1c3c;
	case 7230ULL: goto x86_l_1c3e;
	case 7232ULL: goto x86_l_1c40;
	case 7239ULL: goto x86_l_1c47;
	case 7246ULL: goto x86_l_1c4e;
	case 7250ULL: goto x86_l_1c52;
	case 7253ULL: goto x86_l_1c55;
	case 7258ULL: goto x86_l_1c5a;
	case 7269ULL: goto x86_l_1c65;
	case 7274ULL: goto x86_l_1c6a;
	case 7279ULL: goto x86_l_1c6f;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7297ULL: goto x86_l_1c81;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7324ULL: goto x86_l_1c9c;
	case 7327ULL: goto x86_l_1c9f;
	case 7333ULL: goto x86_l_1ca5;
	case 7336ULL: goto x86_l_1ca8;
	case 7340ULL: goto x86_l_1cac;
	case 7344ULL: goto x86_l_1cb0;
	case 7348ULL: goto x86_l_1cb4;
	case 7351ULL: goto x86_l_1cb7;
	case 7355ULL: goto x86_l_1cbb;
	case 7360ULL: goto x86_l_1cc0;
	case 7365ULL: goto x86_l_1cc5;
	case 7368ULL: goto x86_l_1cc8;
	case 7373ULL: goto x86_l_1ccd;
	case 7375ULL: goto x86_l_1ccf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15c9:
	/* 0x15c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15ce:
	/* 0x15ce: jmp    1e05 <generic_retkprobe_event+0x1e05> */
	return 7685ULL;
x86_l_15d3:
	/* 0x15d3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d6:
	/* 0x15d6: cmp    QWORD PTR [rsp+0x80],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813891ULL);
x86_l_15df:
	/* 0x15df: jb     169e <generic_retkprobe_event+0x169e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_169e;
	}
x86_l_15e5:
	/* 0x15e5: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15ed:
	/* 0x15ed: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15f1:
	/* 0x15f1: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_15f7:
	/* 0x15f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15fc:
	/* 0x15fc: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1601:
	/* 0x1601: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1606:
	/* 0x1606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1608:
	/* 0x1608: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_160d:
	/* 0x160d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_160f:
	/* 0x160f: js     1bc0 <generic_retkprobe_event+0x1bc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1bc0;
	}
x86_l_1615:
	/* 0x1615: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_161a:
	/* 0x161a: cmp    rbp,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_161d:
	/* 0x161d: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1620:
	/* 0x1620: cmovb  rax,rbp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_1624:
	/* 0x1624: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1629:
	/* 0x1629: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_162c:
	/* 0x162c: cmovne rbp,rax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_64, X86_CC_NE);
x86_l_1630:
	/* 0x1630: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_1635:
	/* 0x1635: cmp    rbp,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4094ULL);
x86_l_163c:
	/* 0x163c: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1641:
	/* 0x1641: ja     1bc5 <generic_retkprobe_event+0x1bc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bc5;
	}
x86_l_1647:
	/* 0x1647: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_164a:
	/* 0x164a: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_164f:
	/* 0x164f: add    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1653:
	/* 0x1653: mov    QWORD PTR [rsp+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1658:
	/* 0x1658: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_165e:
	/* 0x165e: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1661:
	/* 0x1661: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1666:
	/* 0x1666: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_166b:
	/* 0x166b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_166d:
	/* 0x166d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166f:
	/* 0x166f: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1674:
	/* 0x1674: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1676:
	/* 0x1676: js     1bc5 <generic_retkprobe_event+0x1bc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1bc5;
	}
x86_l_167c:
	/* 0x167c: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_167f:
	/* 0x167f: add    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1682:
	/* 0x1682: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1688:
	/* 0x1688: je     1fee <generic_retkprobe_event+0x1fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8174ULL;
	}
x86_l_168e:
	/* 0x168e: sub    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 8ULL);
x86_l_1693:
	/* 0x1693: jne    1ff5 <generic_retkprobe_event+0x1ff5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8181ULL;
	}
x86_l_1699:
	/* 0x1699: jmp    2000 <generic_retkprobe_event+0x2000> */
	return 8192ULL;
x86_l_169e:
	/* 0x169e: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_16a1:
	/* 0x16a1: jmp    332 <generic_retkprobe_event+0x332> */
	return 818ULL;
x86_l_16a6:
	/* 0x16a6: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ab:
	/* 0x16ab: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_16b4:
	/* 0x16b4: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_16bd:
	/* 0x16bd: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_16c3:
	/* 0x16c3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16c8:
	/* 0x16c8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16cd:
	/* 0x16cd: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16d2:
	/* 0x16d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16d7:
	/* 0x16d7: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_16da:
	/* 0x16da: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16dc:
	/* 0x16dc: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16e1:
	/* 0x16e1: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_16e7:
	/* 0x16e7: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_16ed:
	/* 0x16ed: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16f2:
	/* 0x16f2: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_16f6:
	/* 0x16f6: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16fb:
	/* 0x16fb: add    r14,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1702:
	/* 0x1702: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1707:
	/* 0x1707: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_170a:
	/* 0x170a: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_170d:
	/* 0x170d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1710:
	/* 0x1710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1712:
	/* 0x1712: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1717:
	/* 0x1717: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1719:
	/* 0x1719: js     1735 <generic_retkprobe_event+0x1735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1735;
	}
x86_l_171b:
	/* 0x171b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1720:
	/* 0x1720: mov    DWORD PTR [rax+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1727:
	/* 0x1727: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_172b:
	/* 0x172b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1730:
	/* 0x1730: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1732:
	/* 0x1732: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1735:
	/* 0x1735: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_173a:
	/* 0x173a: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1740:
	/* 0x1740: jmp    2836 <generic_retkprobe_event+0x2836> */
	return 10294ULL;
x86_l_1745:
	/* 0x1745: lea    r13,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_174c:
	/* 0x174c: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_174f:
	/* 0x174f: lea    r12,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_1756:
	/* 0x1756: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_175a:
	/* 0x175a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_175f:
	/* 0x175f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1764:
	/* 0x1764: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1769:
	/* 0x1769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176b:
	/* 0x176b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_176f:
	/* 0x176f: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1776:
	/* 0x1776: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_177a:
	/* 0x177a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_177f:
	/* 0x177f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1784:
	/* 0x1784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1786:
	/* 0x1786: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_178a:
	/* 0x178a: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1791:
	/* 0x1791: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1795:
	/* 0x1795: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_179a:
	/* 0x179a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_179f:
	/* 0x179f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a1:
	/* 0x17a1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17a5:
	/* 0x17a5: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_17ac:
	/* 0x17ac: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17b0:
	/* 0x17b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17b5:
	/* 0x17b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17ba:
	/* 0x17ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17bc:
	/* 0x17bc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c0:
	/* 0x17c0: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_17c7:
	/* 0x17c7: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17cb:
	/* 0x17cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d0:
	/* 0x17d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17d5:
	/* 0x17d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d7:
	/* 0x17d7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17db:
	/* 0x17db: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17e2:
	/* 0x17e2: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17e6:
	/* 0x17e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17eb:
	/* 0x17eb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17f0:
	/* 0x17f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f2:
	/* 0x17f2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17f6:
	/* 0x17f6: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_17fd:
	/* 0x17fd: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1801:
	/* 0x1801: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1806:
	/* 0x1806: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_180b:
	/* 0x180b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180d:
	/* 0x180d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1811:
	/* 0x1811: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1818:
	/* 0x1818: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_181c:
	/* 0x181c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1821:
	/* 0x1821: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1826:
	/* 0x1826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1828:
	/* 0x1828: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_182c:
	/* 0x182c: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1836:
	/* 0x1836: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_183a:
	/* 0x183a: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1841:
	/* 0x1841: lea    rdx,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1845:
	/* 0x1845: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_184a:
	/* 0x184a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_184f:
	/* 0x184f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1851:
	/* 0x1851: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1855:
	/* 0x1855: lea    rdi,[rax+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_185c:
	/* 0x185c: lea    rdx,[rbp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1860:
	/* 0x1860: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1865:
	/* 0x1865: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_186a:
	/* 0x186a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186c:
	/* 0x186c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1870:
	/* 0x1870: lea    rdi,[rax+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1877:
	/* 0x1877: lea    rdx,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_187b:
	/* 0x187b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1880:
	/* 0x1880: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1885:
	/* 0x1885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1887:
	/* 0x1887: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_188b:
	/* 0x188b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1890:
	/* 0x1890: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1893:
	/* 0x1893: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1898:
	/* 0x1898: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189a:
	/* 0x189a: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_18a1:
	/* 0x18a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a6:
	/* 0x18a6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18ab:
	/* 0x18ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18b0:
	/* 0x18b0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_18b3:
	/* 0x18b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b5:
	/* 0x18b5: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18ba:
	/* 0x18ba: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18c1:
	/* 0x18c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18c6:
	/* 0x18c6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_18c9:
	/* 0x18c9: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_18cc:
	/* 0x18cc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18d1:
	/* 0x18d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d3:
	/* 0x18d3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d7:
	/* 0x18d7: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_18de:
	/* 0x18de: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_18e5:
	/* 0x18e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ea:
	/* 0x18ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18ef:
	/* 0x18ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f1:
	/* 0x18f1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f5:
	/* 0x18f5: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_18fc:
	/* 0x18fc: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1903:
	/* 0x1903: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1908:
	/* 0x1908: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_190d:
	/* 0x190d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190f:
	/* 0x190f: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1913:
	/* 0x1913: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_191a:
	/* 0x191a: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1921:
	/* 0x1921: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1926:
	/* 0x1926: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_192b:
	/* 0x192b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_192e:
	/* 0x192e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1930:
	/* 0x1930: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1934:
	/* 0x1934: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_193a:
	/* 0x193a: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_193f:
	/* 0x193f: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1946:
	/* 0x1946: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_194b:
	/* 0x194b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1950:
	/* 0x1950: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1955:
	/* 0x1955: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1957:
	/* 0x1957: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_195b:
	/* 0x195b: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1962:
	/* 0x1962: lea    rdx,[rbp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1969:
	/* 0x1969: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_196e:
	/* 0x196e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1973:
	/* 0x1973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1975:
	/* 0x1975: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1979:
	/* 0x1979: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1980:
	/* 0x1980: lea    rdx,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1987:
	/* 0x1987: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_198c:
	/* 0x198c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1991:
	/* 0x1991: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1993:
	/* 0x1993: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1997:
	/* 0x1997: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_199e:
	/* 0x199e: add    rbp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_19a5:
	/* 0x19a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19aa:
	/* 0x19aa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19af:
	/* 0x19af: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_19b2:
	/* 0x19b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b4:
	/* 0x19b4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b8:
	/* 0x19b8: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_19be:
	/* 0x19be: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_19c3:
	/* 0x19c3: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19c7:
	/* 0x19c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19cc:
	/* 0x19cc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d1:
	/* 0x19d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19d6:
	/* 0x19d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d8:
	/* 0x19d8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19dc:
	/* 0x19dc: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19e3:
	/* 0x19e3: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_19e7:
	/* 0x19e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19ec:
	/* 0x19ec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19f1:
	/* 0x19f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f3:
	/* 0x19f3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f7:
	/* 0x19f7: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_19fe:
	/* 0x19fe: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a02:
	/* 0x1a02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a07:
	/* 0x1a07: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a0c:
	/* 0x1a0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0e:
	/* 0x1a0e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a12:
	/* 0x1a12: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a19:
	/* 0x1a19: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a22:
	/* 0x1a22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a27:
	/* 0x1a27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a29:
	/* 0x1a29: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2d:
	/* 0x1a2d: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1a34:
	/* 0x1a34: add    rbp,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1a38:
	/* 0x1a38: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a3d:
	/* 0x1a3d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a42:
	/* 0x1a42: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a45:
	/* 0x1a45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a47:
	/* 0x1a47: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a4b:
	/* 0x1a4b: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_1a51:
	/* 0x1a51: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_1a56:
	/* 0x1a56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a60:
	/* 0x1a60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a65:
	/* 0x1a65: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a68:
	/* 0x1a68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6a:
	/* 0x1a6a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a6e:
	/* 0x1a6e: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a75:
	/* 0x1a75: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a79:
	/* 0x1a79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a83:
	/* 0x1a83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a85:
	/* 0x1a85: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a89:
	/* 0x1a89: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1a90:
	/* 0x1a90: add    rbp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1a94:
	/* 0x1a94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a99:
	/* 0x1a99: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a9e:
	/* 0x1a9e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1aa1:
	/* 0x1aa1: jmp    1b23 <generic_retkprobe_event+0x1b23> */
	goto x86_l_1b23;
x86_l_1aa6:
	/* 0x1aa6: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1aaa:
	/* 0x1aaa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aaf:
	/* 0x1aaf: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ab4:
	/* 0x1ab4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ab9:
	/* 0x1ab9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1abb:
	/* 0x1abb: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1abf:
	/* 0x1abf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1ac9:
	/* 0x1ac9: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1acd:
	/* 0x1acd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ad2:
	/* 0x1ad2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ad7:
	/* 0x1ad7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1adc:
	/* 0x1adc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ade:
	/* 0x1ade: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae6:
	/* 0x1ae6: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1aec:
	/* 0x1aec: add    rbp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1af0:
	/* 0x1af0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1af5:
	/* 0x1af5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1afa:
	/* 0x1afa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aff:
	/* 0x1aff: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b02:
	/* 0x1b02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b04:
	/* 0x1b04: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b08:
	/* 0x1b08: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1b0f:
	/* 0x1b0f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b14:
	/* 0x1b14: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1b19:
	/* 0x1b19: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b23:
	/* 0x1b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b25:
	/* 0x1b25: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b29:
	/* 0x1b29: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_1b2f:
	/* 0x1b2f: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_1b34:
	/* 0x1b34: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b39:
	/* 0x1b39: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b41:
	/* 0x1b41: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b49:
	/* 0x1b49: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1b51:
	/* 0x1b51: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1b59:
	/* 0x1b59: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1b61:
	/* 0x1b61: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b69:
	/* 0x1b69: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1b71:
	/* 0x1b71: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b79:
	/* 0x1b79: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1b81:
	/* 0x1b81: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1b84:
	/* 0x1b84: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b90:
	/* 0x1b90: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b95:
	/* 0x1b95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b9d:
	/* 0x1b9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b9f:
	/* 0x1b9f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ba2:
	/* 0x1ba2: je     1e31 <generic_retkprobe_event+0x1e31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7729ULL;
	}
x86_l_1ba8:
	/* 0x1ba8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bab:
	/* 0x1bab: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1baf:
	/* 0x1baf: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_1bb4:
	/* 0x1bb4: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1bbb:
	/* 0x1bbb: jmp    1ef1 <generic_retkprobe_event+0x1ef1> */
	return 7921ULL;
x86_l_1bc0:
	/* 0x1bc0: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bca:
	/* 0x1bca: mov    DWORD PTR [r15+rbp*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1bce:
	/* 0x1bce: jmp    2acf <generic_retkprobe_event+0x2acf> */
	return 10959ULL;
x86_l_1bd3:
	/* 0x1bd3: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1bde:
	/* 0x1bde: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1be3:
	/* 0x1be3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1be8:
	/* 0x1be8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bed:
	/* 0x1bed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bef:
	/* 0x1bef: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bf8:
	/* 0x1bf8: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c00:
	/* 0x1c00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c05:
	/* 0x1c05: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c08:
	/* 0x1c08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0a:
	/* 0x1c0a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c17:
	/* 0x1c17: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1c24:
	/* 0x1c24: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_1c28:
	/* 0x1c28: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1c2b:
	/* 0x1c2b: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1c32:
	/* 0x1c32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c37:
	/* 0x1c37: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1c3a:
	/* 0x1c3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3c:
	/* 0x1c3c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c3e:
	/* 0x1c3e: js     1c5a <generic_retkprobe_event+0x1c5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c5a;
	}
x86_l_1c40:
	/* 0x1c40: mov    DWORD PTR [r14+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1c47:
	/* 0x1c47: mov    DWORD PTR [r14+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c4e:
	/* 0x1c4e: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c52:
	/* 0x1c52: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1c55:
	/* 0x1c55: jmp    2836 <generic_retkprobe_event+0x2836> */
	return 10294ULL;
x86_l_1c5a:
	/* 0x1c5a: mov    DWORD PTR [r14+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_1c65:
	/* 0x1c65: jmp    2836 <generic_retkprobe_event+0x2836> */
	return 10294ULL;
x86_l_1c6a:
	/* 0x1c6a: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c6f:
	/* 0x1c6f: movzx  r14d,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_1c78:
	/* 0x1c78: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c7d:
	/* 0x1c7d: lea    r12,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1c81:
	/* 0x1c81: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c89:
	/* 0x1c89: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1c95:
	/* 0x1c95: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c9a:
	/* 0x1c9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9c:
	/* 0x1c9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c9f:
	/* 0x1c9f: je     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9867ULL;
	}
x86_l_1ca5:
	/* 0x1ca5: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1ca8:
	/* 0x1ca8: mov    WORD PTR [rax],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cac:
	/* 0x1cac: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1cb0:
	/* 0x1cb0: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1cb7:
	/* 0x1cb7: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1cbb:
	/* 0x1cbb: lea    rdx,[r12+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1cc0:
	/* 0x1cc0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_1cc8:
	/* 0x1cc8: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1ccd:
	/* 0x1ccd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ccf:
	/* 0x1ccf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 7378ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7378ULL: goto x86_l_1cd2;
	case 7384ULL: goto x86_l_1cd8;
	case 7389ULL: goto x86_l_1cdd;
	case 7392ULL: goto x86_l_1ce0;
	case 7398ULL: goto x86_l_1ce6;
	case 7400ULL: goto x86_l_1ce8;
	case 7406ULL: goto x86_l_1cee;
	case 7409ULL: goto x86_l_1cf1;
	case 7415ULL: goto x86_l_1cf7;
	case 7418ULL: goto x86_l_1cfa;
	case 7424ULL: goto x86_l_1d00;
	case 7431ULL: goto x86_l_1d07;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7445ULL: goto x86_l_1d15;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7457ULL: goto x86_l_1d21;
	case 7462ULL: goto x86_l_1d26;
	case 7467ULL: goto x86_l_1d2b;
	case 7470ULL: goto x86_l_1d2e;
	case 7475ULL: goto x86_l_1d33;
	case 7477ULL: goto x86_l_1d35;
	case 7481ULL: goto x86_l_1d39;
	case 7488ULL: goto x86_l_1d40;
	case 7493ULL: goto x86_l_1d45;
	case 7497ULL: goto x86_l_1d49;
	case 7502ULL: goto x86_l_1d4e;
	case 7507ULL: goto x86_l_1d53;
	case 7510ULL: goto x86_l_1d56;
	case 7512ULL: goto x86_l_1d58;
	case 7515ULL: goto x86_l_1d5b;
	case 7522ULL: goto x86_l_1d62;
	case 7527ULL: goto x86_l_1d67;
	case 7532ULL: goto x86_l_1d6c;
	case 7535ULL: goto x86_l_1d6f;
	case 7537ULL: goto x86_l_1d71;
	case 7545ULL: goto x86_l_1d79;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7577ULL: goto x86_l_1d99;
	case 7582ULL: goto x86_l_1d9e;
	case 7584ULL: goto x86_l_1da0;
	case 7587ULL: goto x86_l_1da3;
	case 7593ULL: goto x86_l_1da9;
	case 7595ULL: goto x86_l_1dab;
	case 7598ULL: goto x86_l_1dae;
	case 7602ULL: goto x86_l_1db2;
	case 7606ULL: goto x86_l_1db6;
	case 7609ULL: goto x86_l_1db9;
	case 7612ULL: goto x86_l_1dbc;
	case 7617ULL: goto x86_l_1dc1;
	case 7628ULL: goto x86_l_1dcc;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7646ULL: goto x86_l_1dde;
	case 7651ULL: goto x86_l_1de3;
	case 7656ULL: goto x86_l_1de8;
	case 7661ULL: goto x86_l_1ded;
	case 7664ULL: goto x86_l_1df0;
	case 7666ULL: goto x86_l_1df2;
	case 7669ULL: goto x86_l_1df5;
	case 7676ULL: goto x86_l_1dfc;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7693ULL: goto x86_l_1e0d;
	case 7695ULL: goto x86_l_1e0f;
	case 7699ULL: goto x86_l_1e13;
	case 7706ULL: goto x86_l_1e1a;
	case 7715ULL: goto x86_l_1e23;
	case 7721ULL: goto x86_l_1e29;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7733ULL: goto x86_l_1e35;
	case 7740ULL: goto x86_l_1e3c;
	case 7745ULL: goto x86_l_1e41;
	case 7750ULL: goto x86_l_1e46;
	case 7755ULL: goto x86_l_1e4b;
	case 7757ULL: goto x86_l_1e4d;
	case 7760ULL: goto x86_l_1e50;
	case 7766ULL: goto x86_l_1e56;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7785ULL: goto x86_l_1e69;
	case 7787ULL: goto x86_l_1e6b;
	case 7791ULL: goto x86_l_1e6f;
	case 7798ULL: goto x86_l_1e76;
	case 7803ULL: goto x86_l_1e7b;
	case 7808ULL: goto x86_l_1e80;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7820ULL: goto x86_l_1e8c;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7842ULL: goto x86_l_1ea2;
	case 7844ULL: goto x86_l_1ea4;
	case 7850ULL: goto x86_l_1eaa;
	case 7853ULL: goto x86_l_1ead;
	case 7855ULL: goto x86_l_1eaf;
	case 7857ULL: goto x86_l_1eb1;
	case 7862ULL: goto x86_l_1eb6;
	case 7865ULL: goto x86_l_1eb9;
	case 7868ULL: goto x86_l_1ebc;
	case 7872ULL: goto x86_l_1ec0;
	case 7877ULL: goto x86_l_1ec5;
	case 7881ULL: goto x86_l_1ec9;
	case 7886ULL: goto x86_l_1ece;
	case 7891ULL: goto x86_l_1ed3;
	case 7894ULL: goto x86_l_1ed6;
	case 7896ULL: goto x86_l_1ed8;
	case 7899ULL: goto x86_l_1edb;
	case 7901ULL: goto x86_l_1edd;
	case 7903ULL: goto x86_l_1edf;
	case 7905ULL: goto x86_l_1ee1;
	case 7909ULL: goto x86_l_1ee5;
	case 7915ULL: goto x86_l_1eeb;
	case 7921ULL: goto x86_l_1ef1;
	case 7925ULL: goto x86_l_1ef5;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7943ULL: goto x86_l_1f07;
	case 7948ULL: goto x86_l_1f0c;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7960ULL: goto x86_l_1f18;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7970ULL: goto x86_l_1f22;
	case 7974ULL: goto x86_l_1f26;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8003ULL: goto x86_l_1f43;
	case 8005ULL: goto x86_l_1f45;
	case 8008ULL: goto x86_l_1f48;
	case 8015ULL: goto x86_l_1f4f;
	case 8020ULL: goto x86_l_1f54;
	case 8025ULL: goto x86_l_1f59;
	case 8028ULL: goto x86_l_1f5c;
	case 8030ULL: goto x86_l_1f5e;
	case 8037ULL: goto x86_l_1f65;
	case 8046ULL: goto x86_l_1f6e;
	case 8050ULL: goto x86_l_1f72;
	case 8057ULL: goto x86_l_1f79;
	case 8062ULL: goto x86_l_1f7e;
	case 8067ULL: goto x86_l_1f83;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8081ULL: goto x86_l_1f91;
	case 8084ULL: goto x86_l_1f94;
	case 8090ULL: goto x86_l_1f9a;
	case 8092ULL: goto x86_l_1f9c;
	case 8096ULL: goto x86_l_1fa0;
	case 8100ULL: goto x86_l_1fa4;
	case 8104ULL: goto x86_l_1fa8;
	case 8107ULL: goto x86_l_1fab;
	case 8111ULL: goto x86_l_1faf;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8125ULL: goto x86_l_1fbd;
	case 8128ULL: goto x86_l_1fc0;
	case 8130ULL: goto x86_l_1fc2;
	case 8135ULL: goto x86_l_1fc7;
	case 8141ULL: goto x86_l_1fcd;
	case 8148ULL: goto x86_l_1fd4;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8169ULL: goto x86_l_1fe9;
	case 8174ULL: goto x86_l_1fee;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8190ULL: goto x86_l_1ffe;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8200ULL: goto x86_l_2008;
	case 8205ULL: goto x86_l_200d;
	case 8213ULL: goto x86_l_2015;
	case 8217ULL: goto x86_l_2019;
	case 8223ULL: goto x86_l_201f;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8238ULL: goto x86_l_202e;
	case 8240ULL: goto x86_l_2030;
	case 8245ULL: goto x86_l_2035;
	case 8247ULL: goto x86_l_2037;
	case 8253ULL: goto x86_l_203d;
	case 8258ULL: goto x86_l_2042;
	case 8263ULL: goto x86_l_2047;
	case 8266ULL: goto x86_l_204a;
	case 8269ULL: goto x86_l_204d;
	case 8273ULL: goto x86_l_2051;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8283ULL: goto x86_l_205b;
	case 8288ULL: goto x86_l_2060;
	case 8295ULL: goto x86_l_2067;
	case 8301ULL: goto x86_l_206d;
	case 8304ULL: goto x86_l_2070;
	case 8307ULL: goto x86_l_2073;
	case 8312ULL: goto x86_l_2078;
	case 8315ULL: goto x86_l_207b;
	case 8321ULL: goto x86_l_2081;
	case 8326ULL: goto x86_l_2086;
	case 8331ULL: goto x86_l_208b;
	case 8336ULL: goto x86_l_2090;
	case 8338ULL: goto x86_l_2092;
	case 8340ULL: goto x86_l_2094;
	case 8345ULL: goto x86_l_2099;
	case 8347ULL: goto x86_l_209b;
	case 8353ULL: goto x86_l_20a1;
	case 8356ULL: goto x86_l_20a4;
	case 8362ULL: goto x86_l_20aa;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8379ULL: goto x86_l_20bb;
	case 8384ULL: goto x86_l_20c0;
	case 8389ULL: goto x86_l_20c5;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8406ULL: goto x86_l_20d6;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8420ULL: goto x86_l_20e4;
	case 8426ULL: goto x86_l_20ea;
	case 8436ULL: goto x86_l_20f4;
	case 8440ULL: goto x86_l_20f8;
	case 8446ULL: goto x86_l_20fe;
	case 8450ULL: goto x86_l_2102;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8465ULL: goto x86_l_2111;
	case 8468ULL: goto x86_l_2114;
	case 8473ULL: goto x86_l_2119;
	case 8475ULL: goto x86_l_211b;
	case 8478ULL: goto x86_l_211e;
	case 8484ULL: goto x86_l_2124;
	case 8489ULL: goto x86_l_2129;
	case 8492ULL: goto x86_l_212c;
	case 8494ULL: goto x86_l_212e;
	case 8496ULL: goto x86_l_2130;
	case 8498ULL: goto x86_l_2132;
	case 8501ULL: goto x86_l_2135;
	case 8503ULL: goto x86_l_2137;
	case 8506ULL: goto x86_l_213a;
	case 8508ULL: goto x86_l_213c;
	case 8515ULL: goto x86_l_2143;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8524ULL: goto x86_l_214c;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8531ULL: goto x86_l_2153;
	case 8536ULL: goto x86_l_2158;
	case 8538ULL: goto x86_l_215a;
	case 8545ULL: goto x86_l_2161;
	case 8549ULL: goto x86_l_2165;
	case 8551ULL: goto x86_l_2167;
	case 8556ULL: goto x86_l_216c;
	case 8563ULL: goto x86_l_2173;
	case 8568ULL: goto x86_l_2178;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8580ULL: goto x86_l_2184;
	case 8585ULL: goto x86_l_2189;
	case 8592ULL: goto x86_l_2190;
	case 8597ULL: goto x86_l_2195;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8619ULL: goto x86_l_21ab;
	case 8623ULL: goto x86_l_21af;
	case 8629ULL: goto x86_l_21b5;
	case 8639ULL: goto x86_l_21bf;
	case 8643ULL: goto x86_l_21c3;
	case 8649ULL: goto x86_l_21c9;
	case 8653ULL: goto x86_l_21cd;
	case 8658ULL: goto x86_l_21d2;
	case 8663ULL: goto x86_l_21d7;
	case 8668ULL: goto x86_l_21dc;
	case 8671ULL: goto x86_l_21df;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8681ULL: goto x86_l_21e9;
	case 8687ULL: goto x86_l_21ef;
	case 8692ULL: goto x86_l_21f4;
	case 8695ULL: goto x86_l_21f7;
	case 8697ULL: goto x86_l_21f9;
	case 8699ULL: goto x86_l_21fb;
	case 8701ULL: goto x86_l_21fd;
	case 8704ULL: goto x86_l_2200;
	case 8706ULL: goto x86_l_2202;
	case 8709ULL: goto x86_l_2205;
	case 8711ULL: goto x86_l_2207;
	case 8718ULL: goto x86_l_220e;
	case 8722ULL: goto x86_l_2212;
	case 8724ULL: goto x86_l_2214;
	case 8727ULL: goto x86_l_2217;
	case 8729ULL: goto x86_l_2219;
	case 8732ULL: goto x86_l_221c;
	case 8734ULL: goto x86_l_221e;
	case 8739ULL: goto x86_l_2223;
	case 8741ULL: goto x86_l_2225;
	case 8748ULL: goto x86_l_222c;
	case 8752ULL: goto x86_l_2230;
	case 8754ULL: goto x86_l_2232;
	case 8759ULL: goto x86_l_2237;
	case 8766ULL: goto x86_l_223e;
	case 8771ULL: goto x86_l_2243;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8785ULL: goto x86_l_2251;
	case 8790ULL: goto x86_l_2256;
	case 8792ULL: goto x86_l_2258;
	case 8797ULL: goto x86_l_225d;
	case 8802ULL: goto x86_l_2262;
	case 8807ULL: goto x86_l_2267;
	case 8812ULL: goto x86_l_226c;
	case 8816ULL: goto x86_l_2270;
	case 8822ULL: goto x86_l_2276;
	case 8832ULL: goto x86_l_2280;
	case 8836ULL: goto x86_l_2284;
	case 8842ULL: goto x86_l_228a;
	case 8846ULL: goto x86_l_228e;
	case 8851ULL: goto x86_l_2293;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8871ULL: goto x86_l_22a7;
	case 8874ULL: goto x86_l_22aa;
	case 8880ULL: goto x86_l_22b0;
	case 8885ULL: goto x86_l_22b5;
	case 8888ULL: goto x86_l_22b8;
	case 8890ULL: goto x86_l_22ba;
	case 8892ULL: goto x86_l_22bc;
	case 8894ULL: goto x86_l_22be;
	case 8897ULL: goto x86_l_22c1;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	case 8904ULL: goto x86_l_22c8;
	case 8911ULL: goto x86_l_22cf;
	case 8915ULL: goto x86_l_22d3;
	case 8917ULL: goto x86_l_22d5;
	case 8920ULL: goto x86_l_22d8;
	case 8922ULL: goto x86_l_22da;
	case 8925ULL: goto x86_l_22dd;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8934ULL: goto x86_l_22e6;
	case 8941ULL: goto x86_l_22ed;
	case 8945ULL: goto x86_l_22f1;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8959ULL: goto x86_l_22ff;
	case 8964ULL: goto x86_l_2304;
	case 8966ULL: goto x86_l_2306;
	case 8971ULL: goto x86_l_230b;
	case 8978ULL: goto x86_l_2312;
	case 8983ULL: goto x86_l_2317;
	case 8985ULL: goto x86_l_2319;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 9000ULL: goto x86_l_2328;
	case 9005ULL: goto x86_l_232d;
	case 9009ULL: goto x86_l_2331;
	case 9015ULL: goto x86_l_2337;
	case 9025ULL: goto x86_l_2341;
	case 9029ULL: goto x86_l_2345;
	case 9035ULL: goto x86_l_234b;
	case 9039ULL: goto x86_l_234f;
	case 9044ULL: goto x86_l_2354;
	case 9049ULL: goto x86_l_2359;
	case 9054ULL: goto x86_l_235e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1cd2:
	/* 0x1cd2: js     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9867ULL;
	}
x86_l_1cd8:
	/* 0x1cd8: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1cdd:
	/* 0x1cdd: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1ce0:
	/* 0x1ce0: jg     1fb4 <generic_retkprobe_event+0x1fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1fb4;
	}
x86_l_1ce6:
	/* 0x1ce6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ce8:
	/* 0x1ce8: je     1fdd <generic_retkprobe_event+0x1fdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fdd;
	}
x86_l_1cee:
	/* 0x1cee: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1cf1:
	/* 0x1cf1: je     1fdd <generic_retkprobe_event+0x1fdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fdd;
	}
x86_l_1cf7:
	/* 0x1cf7: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1cfa:
	/* 0x1cfa: jne    217a <generic_retkprobe_event+0x217a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_217a;
	}
x86_l_1d00:
	/* 0x1d00: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1d07:
	/* 0x1d07: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1d0b:
	/* 0x1d0b: jmp    20d1 <generic_retkprobe_event+0x20d1> */
	goto x86_l_20d1;
x86_l_1d10:
	/* 0x1d10: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d15:
	/* 0x1d15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d1a:
	/* 0x1d1a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d1f:
	/* 0x1d1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d21:
	/* 0x1d21: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d26:
	/* 0x1d26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d2b:
	/* 0x1d2b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1d2e:
	/* 0x1d2e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d33:
	/* 0x1d33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d35:
	/* 0x1d35: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d39:
	/* 0x1d39: lea    rdi,[r14+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1d40:
	/* 0x1d40: lea    r13,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d45:
	/* 0x1d45: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1d49:
	/* 0x1d49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d4e:
	/* 0x1d4e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d53:
	/* 0x1d53: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d56:
	/* 0x1d56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d58:
	/* 0x1d58: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1d5b:
	/* 0x1d5b: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1d62:
	/* 0x1d62: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d67:
	/* 0x1d67: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d6c:
	/* 0x1d6c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d6f:
	/* 0x1d6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d71:
	/* 0x1d71: movzx  eax,WORD PTR [r14+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1d79:
	/* 0x1d79: movbe  WORD PTR [r14+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1d83:
	/* 0x1d83: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d88:
	/* 0x1d88: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d92:
	/* 0x1d92: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1d99:
	/* 0x1d99: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d9e:
	/* 0x1d9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da0:
	/* 0x1da0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1da3:
	/* 0x1da3: je     2830 <generic_retkprobe_event+0x2830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10288ULL;
	}
x86_l_1da9:
	/* 0x1da9: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dab:
	/* 0x1dab: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dae:
	/* 0x1dae: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1db2:
	/* 0x1db2: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1db6:
	/* 0x1db6: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1db9:
	/* 0x1db9: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1dbc:
	/* 0x1dbc: jmp    2830 <generic_retkprobe_event+0x2830> */
	return 10288ULL;
x86_l_1dc1:
	/* 0x1dc1: mov    QWORD PTR [r14+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1dd2:
	/* 0x1dd2: jmp    2836 <generic_retkprobe_event+0x2836> */
	return 10294ULL;
x86_l_1dd7:
	/* 0x1dd7: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1dde:
	/* 0x1dde: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de3:
	/* 0x1de3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1de8:
	/* 0x1de8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ded:
	/* 0x1ded: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_1df0:
	/* 0x1df0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df2:
	/* 0x1df2: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1df5:
	/* 0x1df5: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_1dfc:
	/* 0x1dfc: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1e00:
	/* 0x1e00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e05:
	/* 0x1e05: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e0a:
	/* 0x1e0a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e0d:
	/* 0x1e0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0f:
	/* 0x1e0f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e13:
	/* 0x1e13: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1e1a:
	/* 0x1e1a: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1e23:
	/* 0x1e23: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_1e29:
	/* 0x1e29: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_1e2c:
	/* 0x1e2c: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_1e31:
	/* 0x1e31: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e35:
	/* 0x1e35: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1e3c:
	/* 0x1e3c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e41:
	/* 0x1e41: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e46:
	/* 0x1e46: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1e4b:
	/* 0x1e4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4d:
	/* 0x1e4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e50:
	/* 0x1e50: js     1ba8 <generic_retkprobe_event+0x1ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7080ULL;
	}
x86_l_1e56:
	/* 0x1e56: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5a:
	/* 0x1e5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e5f:
	/* 0x1e5f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e64:
	/* 0x1e64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e69:
	/* 0x1e69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6b:
	/* 0x1e6b: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e6f:
	/* 0x1e6f: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1e76:
	/* 0x1e76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e7b:
	/* 0x1e7b: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1e80:
	/* 0x1e80: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1e85:
	/* 0x1e85: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e8a:
	/* 0x1e8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8c:
	/* 0x1e8c: add    rbp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_1e90:
	/* 0x1e90: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e95:
	/* 0x1e95: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e9a:
	/* 0x1e9a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e9f:
	/* 0x1e9f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1ea2:
	/* 0x1ea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea4:
	/* 0x1ea4: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_1eaa:
	/* 0x1eaa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ead:
	/* 0x1ead: jne    1ebc <generic_retkprobe_event+0x1ebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ebc;
	}
x86_l_1eaf:
	/* 0x1eaf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eb1:
	/* 0x1eb1: cmp    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1eb6:
	/* 0x1eb6: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1eb9:
	/* 0x1eb9: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ebc:
	/* 0x1ebc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ec0:
	/* 0x1ec0: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_1ec5:
	/* 0x1ec5: add    r12,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1ec9:
	/* 0x1ec9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ece:
	/* 0x1ece: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_1ed3:
	/* 0x1ed3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ed6:
	/* 0x1ed6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed8:
	/* 0x1ed8: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1edb:
	/* 0x1edb: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_1edd:
	/* 0x1edd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1edf:
	/* 0x1edf: js     1eeb <generic_retkprobe_event+0x1eeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1eeb;
	}
x86_l_1ee1:
	/* 0x1ee1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee5:
	/* 0x1ee5: mov    BYTE PTR [rcx+0x9f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_1eeb:
	/* 0x1eeb: mov    r13d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 112ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ef5:
	/* 0x1ef5: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_1ef8:
	/* 0x1ef8: jmp    283f <generic_retkprobe_event+0x283f> */
	return 10303ULL;
x86_l_1efd:
	/* 0x1efd: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f02:
	/* 0x1f02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f07:
	/* 0x1f07: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f0c:
	/* 0x1f0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0e:
	/* 0x1f0e: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f13:
	/* 0x1f13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f18:
	/* 0x1f18: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1f1b:
	/* 0x1f1b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f20:
	/* 0x1f20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f22:
	/* 0x1f22: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f26:
	/* 0x1f26: lea    rdi,[rbp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1f2d:
	/* 0x1f2d: lea    r13,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f32:
	/* 0x1f32: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1f36:
	/* 0x1f36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f40:
	/* 0x1f40: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f43:
	/* 0x1f43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f45:
	/* 0x1f45: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1f48:
	/* 0x1f48: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1f4f:
	/* 0x1f4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f54:
	/* 0x1f54: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f59:
	/* 0x1f59: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1f5c:
	/* 0x1f5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f5e:
	/* 0x1f5e: movzx  eax,WORD PTR [rbp+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1f65:
	/* 0x1f65: movbe  WORD PTR [rbp+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f72:
	/* 0x1f72: mov    rax,QWORD PTR [rax+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1f79:
	/* 0x1f79: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f7e:
	/* 0x1f7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f83:
	/* 0x1f83: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1f8a:
	/* 0x1f8a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f8f:
	/* 0x1f8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f91:
	/* 0x1f91: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f94:
	/* 0x1f94: je     2830 <generic_retkprobe_event+0x2830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10288ULL;
	}
x86_l_1f9a:
	/* 0x1f9a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    DWORD PTR [r14+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fa4:
	/* 0x1fa4: mov    QWORD PTR [r14+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fa8:
	/* 0x1fa8: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fab:
	/* 0x1fab: mov    DWORD PTR [r14+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1faf:
	/* 0x1faf: jmp    2830 <generic_retkprobe_event+0x2830> */
	return 10288ULL;
x86_l_1fb4:
	/* 0x1fb4: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_1fb7:
	/* 0x1fb7: je     20c0 <generic_retkprobe_event+0x20c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c0;
	}
x86_l_1fbd:
	/* 0x1fbd: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1fc0:
	/* 0x1fc0: je     1fdd <generic_retkprobe_event+0x1fdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fdd;
	}
x86_l_1fc2:
	/* 0x1fc2: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_1fc7:
	/* 0x1fc7: jne    217a <generic_retkprobe_event+0x217a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_217a;
	}
x86_l_1fcd:
	/* 0x1fcd: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_1fd4:
	/* 0x1fd4: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_1fd8:
	/* 0x1fd8: jmp    20d1 <generic_retkprobe_event+0x20d1> */
	goto x86_l_20d1;
x86_l_1fdd:
	/* 0x1fdd: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_1fe2:
	/* 0x1fe2: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1fe9:
	/* 0x1fe9: jmp    20cc <generic_retkprobe_event+0x20cc> */
	goto x86_l_20cc;
x86_l_1fee:
	/* 0x1fee: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ff0:
	/* 0x1ff0: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ff5:
	/* 0x1ff5: cmp    QWORD PTR [rsp+0x80],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813891ULL);
x86_l_1ffe:
	/* 0x1ffe: jne    200d <generic_retkprobe_event+0x200d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_200d;
	}
x86_l_2000:
	/* 0x2000: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_2003:
	/* 0x2003: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2008:
	/* 0x2008: jmp    332 <generic_retkprobe_event+0x332> */
	return 818ULL;
x86_l_200d:
	/* 0x200d: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2015:
	/* 0x2015: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2019:
	/* 0x2019: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_201f:
	/* 0x201f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2024:
	/* 0x2024: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2029:
	/* 0x2029: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_202e:
	/* 0x202e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2030:
	/* 0x2030: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2035:
	/* 0x2035: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2037:
	/* 0x2037: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10946ULL;
	}
x86_l_203d:
	/* 0x203d: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2042:
	/* 0x2042: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2047:
	/* 0x2047: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_204a:
	/* 0x204a: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_204d:
	/* 0x204d: cmovb  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2051:
	/* 0x2051: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2054:
	/* 0x2054: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2057:
	/* 0x2057: cmovne rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_NE);
x86_l_205b:
	/* 0x205b: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2060:
	/* 0x2060: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_2067:
	/* 0x2067: ja     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10946ULL;
	}
x86_l_206d:
	/* 0x206d: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_2070:
	/* 0x2070: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2073:
	/* 0x2073: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2078:
	/* 0x2078: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_207b:
	/* 0x207b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2081:
	/* 0x2081: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2086:
	/* 0x2086: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_208b:
	/* 0x208b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2090:
	/* 0x2090: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2092:
	/* 0x2092: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2094:
	/* 0x2094: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2099:
	/* 0x2099: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_209b:
	/* 0x209b: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10946ULL;
	}
x86_l_20a1:
	/* 0x20a1: add    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20a4:
	/* 0x20a4: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_20aa:
	/* 0x20aa: je     23dc <generic_retkprobe_event+0x23dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9180ULL;
	}
x86_l_20b0:
	/* 0x20b0: sub    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 8ULL);
x86_l_20b5:
	/* 0x20b5: jne    23e3 <generic_retkprobe_event+0x23e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9187ULL;
	}
x86_l_20bb:
	/* 0x20bb: jmp    2000 <generic_retkprobe_event+0x2000> */
	goto x86_l_2000;
x86_l_20c0:
	/* 0x20c0: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_20c5:
	/* 0x20c5: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_20cc:
	/* 0x20cc: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_20d1:
	/* 0x20d1: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20d6:
	/* 0x20d6: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20db:
	/* 0x20db: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_20e0:
	/* 0x20e0: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_20e4:
	/* 0x20e4: ja     2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10577ULL;
	}
x86_l_20ea:
	/* 0x20ea: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_20f4:
	/* 0x20f4: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_20f8:
	/* 0x20f8: jae    2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10577ULL;
	}
x86_l_20fe:
	/* 0x20fe: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2102:
	/* 0x2102: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2107:
	/* 0x2107: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_210c:
	/* 0x210c: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2111:
	/* 0x2111: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2114:
	/* 0x2114: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2119:
	/* 0x2119: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211b:
	/* 0x211b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_211e:
	/* 0x211e: js     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9867ULL;
	}
x86_l_2124:
	/* 0x2124: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2129:
	/* 0x2129: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_212c:
	/* 0x212c: jg     2149 <generic_retkprobe_event+0x2149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2149;
	}
x86_l_212e:
	/* 0x212e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2130:
	/* 0x2130: je     2167 <generic_retkprobe_event+0x2167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2167;
	}
x86_l_2132:
	/* 0x2132: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2135:
	/* 0x2135: je     2167 <generic_retkprobe_event+0x2167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2167;
	}
x86_l_2137:
	/* 0x2137: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_213a:
	/* 0x213a: jne    2197 <generic_retkprobe_event+0x2197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2197;
	}
x86_l_213c:
	/* 0x213c: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2143:
	/* 0x2143: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2147:
	/* 0x2147: jmp    219c <generic_retkprobe_event+0x219c> */
	goto x86_l_219c;
x86_l_2149:
	/* 0x2149: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_214c:
	/* 0x214c: je     2184 <generic_retkprobe_event+0x2184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2184;
	}
x86_l_214e:
	/* 0x214e: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2151:
	/* 0x2151: je     2167 <generic_retkprobe_event+0x2167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2167;
	}
x86_l_2153:
	/* 0x2153: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2158:
	/* 0x2158: jne    2197 <generic_retkprobe_event+0x2197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2197;
	}
x86_l_215a:
	/* 0x215a: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2161:
	/* 0x2161: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2165:
	/* 0x2165: jmp    219c <generic_retkprobe_event+0x219c> */
	goto x86_l_219c;
x86_l_2167:
	/* 0x2167: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_216c:
	/* 0x216c: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2173:
	/* 0x2173: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2178:
	/* 0x2178: jmp    219c <generic_retkprobe_event+0x219c> */
	goto x86_l_219c;
x86_l_217a:
	/* 0x217a: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_217f:
	/* 0x217f: jmp    20d1 <generic_retkprobe_event+0x20d1> */
	goto x86_l_20d1;
x86_l_2184:
	/* 0x2184: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2189:
	/* 0x2189: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2190:
	/* 0x2190: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2195:
	/* 0x2195: jmp    219c <generic_retkprobe_event+0x219c> */
	goto x86_l_219c;
x86_l_2197:
	/* 0x2197: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_219c:
	/* 0x219c: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_21a1:
	/* 0x21a1: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a6:
	/* 0x21a6: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_21ab:
	/* 0x21ab: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_21af:
	/* 0x21af: ja     2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10577ULL;
	}
x86_l_21b5:
	/* 0x21b5: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_21bf:
	/* 0x21bf: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_21c3:
	/* 0x21c3: jae    2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10577ULL;
	}
x86_l_21c9:
	/* 0x21c9: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_21cd:
	/* 0x21cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21d2:
	/* 0x21d2: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21d7:
	/* 0x21d7: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_21dc:
	/* 0x21dc: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_21df:
	/* 0x21df: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_21e4:
	/* 0x21e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e6:
	/* 0x21e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21e9:
	/* 0x21e9: js     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9867ULL;
	}
x86_l_21ef:
	/* 0x21ef: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_21f4:
	/* 0x21f4: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_21f7:
	/* 0x21f7: jg     2214 <generic_retkprobe_event+0x2214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2214;
	}
x86_l_21f9:
	/* 0x21f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21fb:
	/* 0x21fb: je     2232 <generic_retkprobe_event+0x2232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2232;
	}
x86_l_21fd:
	/* 0x21fd: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2200:
	/* 0x2200: je     2232 <generic_retkprobe_event+0x2232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2232;
	}
x86_l_2202:
	/* 0x2202: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2205:
	/* 0x2205: jne    2258 <generic_retkprobe_event+0x2258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2258;
	}
x86_l_2207:
	/* 0x2207: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_220e:
	/* 0x220e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2212:
	/* 0x2212: jmp    225d <generic_retkprobe_event+0x225d> */
	goto x86_l_225d;
x86_l_2214:
	/* 0x2214: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2217:
	/* 0x2217: je     2245 <generic_retkprobe_event+0x2245> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2245;
	}
x86_l_2219:
	/* 0x2219: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_221c:
	/* 0x221c: je     2232 <generic_retkprobe_event+0x2232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2232;
	}
x86_l_221e:
	/* 0x221e: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2223:
	/* 0x2223: jne    2258 <generic_retkprobe_event+0x2258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2258;
	}
x86_l_2225:
	/* 0x2225: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_222c:
	/* 0x222c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2230:
	/* 0x2230: jmp    225d <generic_retkprobe_event+0x225d> */
	goto x86_l_225d;
x86_l_2232:
	/* 0x2232: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2237:
	/* 0x2237: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_223e:
	/* 0x223e: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2243:
	/* 0x2243: jmp    225d <generic_retkprobe_event+0x225d> */
	goto x86_l_225d;
x86_l_2245:
	/* 0x2245: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_224a:
	/* 0x224a: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2251:
	/* 0x2251: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2256:
	/* 0x2256: jmp    225d <generic_retkprobe_event+0x225d> */
	goto x86_l_225d;
x86_l_2258:
	/* 0x2258: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_225d:
	/* 0x225d: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2262:
	/* 0x2262: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2267:
	/* 0x2267: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_226c:
	/* 0x226c: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2270:
	/* 0x2270: ja     2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10577ULL;
	}
x86_l_2276:
	/* 0x2276: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2280:
	/* 0x2280: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2284:
	/* 0x2284: jae    2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10577ULL;
	}
x86_l_228a:
	/* 0x228a: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_228e:
	/* 0x228e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2293:
	/* 0x2293: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2298:
	/* 0x2298: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_229d:
	/* 0x229d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_22a0:
	/* 0x22a0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_22a5:
	/* 0x22a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a7:
	/* 0x22a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22aa:
	/* 0x22aa: js     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9867ULL;
	}
x86_l_22b0:
	/* 0x22b0: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_22b5:
	/* 0x22b5: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_22b8:
	/* 0x22b8: jg     22d5 <generic_retkprobe_event+0x22d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_22d5;
	}
x86_l_22ba:
	/* 0x22ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22bc:
	/* 0x22bc: je     22f3 <generic_retkprobe_event+0x22f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22f3;
	}
x86_l_22be:
	/* 0x22be: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_22c1:
	/* 0x22c1: je     22f3 <generic_retkprobe_event+0x22f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22f3;
	}
x86_l_22c3:
	/* 0x22c3: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_22c6:
	/* 0x22c6: jne    2319 <generic_retkprobe_event+0x2319> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2319;
	}
x86_l_22c8:
	/* 0x22c8: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_22cf:
	/* 0x22cf: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_22d3:
	/* 0x22d3: jmp    231e <generic_retkprobe_event+0x231e> */
	goto x86_l_231e;
x86_l_22d5:
	/* 0x22d5: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_22d8:
	/* 0x22d8: je     2306 <generic_retkprobe_event+0x2306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2306;
	}
x86_l_22da:
	/* 0x22da: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_22dd:
	/* 0x22dd: je     22f3 <generic_retkprobe_event+0x22f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22f3;
	}
x86_l_22df:
	/* 0x22df: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_22e4:
	/* 0x22e4: jne    2319 <generic_retkprobe_event+0x2319> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2319;
	}
x86_l_22e6:
	/* 0x22e6: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_22ed:
	/* 0x22ed: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_22f1:
	/* 0x22f1: jmp    231e <generic_retkprobe_event+0x231e> */
	goto x86_l_231e;
x86_l_22f3:
	/* 0x22f3: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_22f8:
	/* 0x22f8: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_22ff:
	/* 0x22ff: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2304:
	/* 0x2304: jmp    231e <generic_retkprobe_event+0x231e> */
	goto x86_l_231e;
x86_l_2306:
	/* 0x2306: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_230b:
	/* 0x230b: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2312:
	/* 0x2312: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2317:
	/* 0x2317: jmp    231e <generic_retkprobe_event+0x231e> */
	goto x86_l_231e;
x86_l_2319:
	/* 0x2319: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_231e:
	/* 0x231e: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2323:
	/* 0x2323: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2328:
	/* 0x2328: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_232d:
	/* 0x232d: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2331:
	/* 0x2331: ja     2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10577ULL;
	}
x86_l_2337:
	/* 0x2337: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2341:
	/* 0x2341: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2345:
	/* 0x2345: jae    2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10577ULL;
	}
x86_l_234b:
	/* 0x234b: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_234f:
	/* 0x234f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2354:
	/* 0x2354: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2359:
	/* 0x2359: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_235e:
	/* 0x235e: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
	return 9057ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9057ULL: goto x86_l_2361;
	case 9062ULL: goto x86_l_2366;
	case 9064ULL: goto x86_l_2368;
	case 9067ULL: goto x86_l_236b;
	case 9073ULL: goto x86_l_2371;
	case 9078ULL: goto x86_l_2376;
	case 9081ULL: goto x86_l_2379;
	case 9083ULL: goto x86_l_237b;
	case 9085ULL: goto x86_l_237d;
	case 9087ULL: goto x86_l_237f;
	case 9090ULL: goto x86_l_2382;
	case 9092ULL: goto x86_l_2384;
	case 9095ULL: goto x86_l_2387;
	case 9101ULL: goto x86_l_238d;
	case 9108ULL: goto x86_l_2394;
	case 9112ULL: goto x86_l_2398;
	case 9117ULL: goto x86_l_239d;
	case 9120ULL: goto x86_l_23a0;
	case 9126ULL: goto x86_l_23a6;
	case 9129ULL: goto x86_l_23a9;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9142ULL: goto x86_l_23b6;
	case 9149ULL: goto x86_l_23bd;
	case 9153ULL: goto x86_l_23c1;
	case 9158ULL: goto x86_l_23c6;
	case 9163ULL: goto x86_l_23cb;
	case 9170ULL: goto x86_l_23d2;
	case 9175ULL: goto x86_l_23d7;
	case 9180ULL: goto x86_l_23dc;
	case 9182ULL: goto x86_l_23de;
	case 9187ULL: goto x86_l_23e3;
	case 9196ULL: goto x86_l_23ec;
	case 9202ULL: goto x86_l_23f2;
	case 9210ULL: goto x86_l_23fa;
	case 9214ULL: goto x86_l_23fe;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9230ULL: goto x86_l_240e;
	case 9235ULL: goto x86_l_2413;
	case 9237ULL: goto x86_l_2415;
	case 9242ULL: goto x86_l_241a;
	case 9244ULL: goto x86_l_241c;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9263ULL: goto x86_l_242f;
	case 9266ULL: goto x86_l_2432;
	case 9270ULL: goto x86_l_2436;
	case 9273ULL: goto x86_l_2439;
	case 9277ULL: goto x86_l_243d;
	case 9282ULL: goto x86_l_2442;
	case 9286ULL: goto x86_l_2446;
	case 9293ULL: goto x86_l_244d;
	case 9299ULL: goto x86_l_2453;
	case 9302ULL: goto x86_l_2456;
	case 9305ULL: goto x86_l_2459;
	case 9308ULL: goto x86_l_245c;
	case 9314ULL: goto x86_l_2462;
	case 9319ULL: goto x86_l_2467;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9333ULL: goto x86_l_2475;
	case 9335ULL: goto x86_l_2477;
	case 9340ULL: goto x86_l_247c;
	case 9342ULL: goto x86_l_247e;
	case 9348ULL: goto x86_l_2484;
	case 9352ULL: goto x86_l_2488;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9375ULL: goto x86_l_249f;
	case 9380ULL: goto x86_l_24a4;
	case 9385ULL: goto x86_l_24a9;
	case 9392ULL: goto x86_l_24b0;
	case 9397ULL: goto x86_l_24b5;
	case 9399ULL: goto x86_l_24b7;
	case 9404ULL: goto x86_l_24bc;
	case 9409ULL: goto x86_l_24c1;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9423ULL: goto x86_l_24cf;
	case 9429ULL: goto x86_l_24d5;
	case 9439ULL: goto x86_l_24df;
	case 9443ULL: goto x86_l_24e3;
	case 9449ULL: goto x86_l_24e9;
	case 9453ULL: goto x86_l_24ed;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9468ULL: goto x86_l_24fc;
	case 9471ULL: goto x86_l_24ff;
	case 9476ULL: goto x86_l_2504;
	case 9478ULL: goto x86_l_2506;
	case 9481ULL: goto x86_l_2509;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9495ULL: goto x86_l_2517;
	case 9497ULL: goto x86_l_2519;
	case 9499ULL: goto x86_l_251b;
	case 9501ULL: goto x86_l_251d;
	case 9504ULL: goto x86_l_2520;
	case 9506ULL: goto x86_l_2522;
	case 9509ULL: goto x86_l_2525;
	case 9511ULL: goto x86_l_2527;
	case 9518ULL: goto x86_l_252e;
	case 9522ULL: goto x86_l_2532;
	case 9524ULL: goto x86_l_2534;
	case 9527ULL: goto x86_l_2537;
	case 9529ULL: goto x86_l_2539;
	case 9532ULL: goto x86_l_253c;
	case 9534ULL: goto x86_l_253e;
	case 9539ULL: goto x86_l_2543;
	case 9541ULL: goto x86_l_2545;
	case 9548ULL: goto x86_l_254c;
	case 9552ULL: goto x86_l_2550;
	case 9554ULL: goto x86_l_2552;
	case 9559ULL: goto x86_l_2557;
	case 9566ULL: goto x86_l_255e;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9597ULL: goto x86_l_257d;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9616ULL: goto x86_l_2590;
	case 9622ULL: goto x86_l_2596;
	case 9632ULL: goto x86_l_25a0;
	case 9636ULL: goto x86_l_25a4;
	case 9642ULL: goto x86_l_25aa;
	case 9646ULL: goto x86_l_25ae;
	case 9651ULL: goto x86_l_25b3;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9664ULL: goto x86_l_25c0;
	case 9669ULL: goto x86_l_25c5;
	case 9671ULL: goto x86_l_25c7;
	case 9674ULL: goto x86_l_25ca;
	case 9680ULL: goto x86_l_25d0;
	case 9685ULL: goto x86_l_25d5;
	case 9688ULL: goto x86_l_25d8;
	case 9690ULL: goto x86_l_25da;
	case 9692ULL: goto x86_l_25dc;
	case 9694ULL: goto x86_l_25de;
	case 9697ULL: goto x86_l_25e1;
	case 9699ULL: goto x86_l_25e3;
	case 9702ULL: goto x86_l_25e6;
	case 9704ULL: goto x86_l_25e8;
	case 9711ULL: goto x86_l_25ef;
	case 9715ULL: goto x86_l_25f3;
	case 9717ULL: goto x86_l_25f5;
	case 9720ULL: goto x86_l_25f8;
	case 9722ULL: goto x86_l_25fa;
	case 9725ULL: goto x86_l_25fd;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9734ULL: goto x86_l_2606;
	case 9741ULL: goto x86_l_260d;
	case 9745ULL: goto x86_l_2611;
	case 9747ULL: goto x86_l_2613;
	case 9752ULL: goto x86_l_2618;
	case 9759ULL: goto x86_l_261f;
	case 9764ULL: goto x86_l_2624;
	case 9766ULL: goto x86_l_2626;
	case 9771ULL: goto x86_l_262b;
	case 9778ULL: goto x86_l_2632;
	case 9783ULL: goto x86_l_2637;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9800ULL: goto x86_l_2648;
	case 9805ULL: goto x86_l_264d;
	case 9809ULL: goto x86_l_2651;
	case 9815ULL: goto x86_l_2657;
	case 9825ULL: goto x86_l_2661;
	case 9829ULL: goto x86_l_2665;
	case 9835ULL: goto x86_l_266b;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9857ULL: goto x86_l_2681;
	case 9860ULL: goto x86_l_2684;
	case 9865ULL: goto x86_l_2689;
	case 9867ULL: goto x86_l_268b;
	case 9869ULL: goto x86_l_268d;
	case 9876ULL: goto x86_l_2694;
	case 9879ULL: goto x86_l_2697;
	case 9883ULL: goto x86_l_269b;
	case 9891ULL: goto x86_l_26a3;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9916ULL: goto x86_l_26bc;
	case 9921ULL: goto x86_l_26c1;
	case 9923ULL: goto x86_l_26c3;
	case 9930ULL: goto x86_l_26ca;
	case 9934ULL: goto x86_l_26ce;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9947ULL: goto x86_l_26db;
	case 9949ULL: goto x86_l_26dd;
	case 9957ULL: goto x86_l_26e5;
	case 9960ULL: goto x86_l_26e8;
	case 9962ULL: goto x86_l_26ea;
	case 9965ULL: goto x86_l_26ed;
	case 9971ULL: goto x86_l_26f3;
	case 9976ULL: goto x86_l_26f8;
	case 9985ULL: goto x86_l_2701;
	case 9989ULL: goto x86_l_2705;
	case 9993ULL: goto x86_l_2709;
	case 10000ULL: goto x86_l_2710;
	case 10005ULL: goto x86_l_2715;
	case 10010ULL: goto x86_l_271a;
	case 10012ULL: goto x86_l_271c;
	case 10019ULL: goto x86_l_2723;
	case 10023ULL: goto x86_l_2727;
	case 10027ULL: goto x86_l_272b;
	case 10032ULL: goto x86_l_2730;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10048ULL: goto x86_l_2740;
	case 10052ULL: goto x86_l_2744;
	case 10056ULL: goto x86_l_2748;
	case 10063ULL: goto x86_l_274f;
	case 10068ULL: goto x86_l_2754;
	case 10073ULL: goto x86_l_2759;
	case 10075ULL: goto x86_l_275b;
	case 10082ULL: goto x86_l_2762;
	case 10086ULL: goto x86_l_2766;
	case 10090ULL: goto x86_l_276a;
	case 10095ULL: goto x86_l_276f;
	case 10100ULL: goto x86_l_2774;
	case 10102ULL: goto x86_l_2776;
	case 10104ULL: goto x86_l_2778;
	case 10108ULL: goto x86_l_277c;
	case 10118ULL: goto x86_l_2786;
	case 10122ULL: goto x86_l_278a;
	case 10129ULL: goto x86_l_2791;
	case 10136ULL: goto x86_l_2798;
	case 10145ULL: goto x86_l_27a1;
	case 10154ULL: goto x86_l_27aa;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10179ULL: goto x86_l_27c3;
	case 10181ULL: goto x86_l_27c5;
	case 10187ULL: goto x86_l_27cb;
	case 10189ULL: goto x86_l_27cd;
	case 10194ULL: goto x86_l_27d2;
	case 10199ULL: goto x86_l_27d7;
	case 10203ULL: goto x86_l_27db;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10223ULL: goto x86_l_27ef;
	case 10231ULL: goto x86_l_27f7;
	case 10235ULL: goto x86_l_27fb;
	case 10239ULL: goto x86_l_27ff;
	case 10246ULL: goto x86_l_2806;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10258ULL: goto x86_l_2812;
	case 10261ULL: goto x86_l_2815;
	case 10268ULL: goto x86_l_281c;
	case 10272ULL: goto x86_l_2820;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10288ULL: goto x86_l_2830;
	case 10294ULL: goto x86_l_2836;
	case 10298ULL: goto x86_l_283a;
	case 10303ULL: goto x86_l_283f;
	case 10309ULL: goto x86_l_2845;
	case 10312ULL: goto x86_l_2848;
	case 10316ULL: goto x86_l_284c;
	case 10318ULL: goto x86_l_284e;
	case 10325ULL: goto x86_l_2855;
	case 10329ULL: goto x86_l_2859;
	case 10332ULL: goto x86_l_285c;
	case 10334ULL: goto x86_l_285e;
	case 10344ULL: goto x86_l_2868;
	case 10354ULL: goto x86_l_2872;
	case 10362ULL: goto x86_l_287a;
	case 10366ULL: goto x86_l_287e;
	case 10370ULL: goto x86_l_2882;
	case 10373ULL: goto x86_l_2885;
	case 10379ULL: goto x86_l_288b;
	case 10384ULL: goto x86_l_2890;
	case 10391ULL: goto x86_l_2897;
	case 10399ULL: goto x86_l_289f;
	case 10401ULL: goto x86_l_28a1;
	case 10408ULL: goto x86_l_28a8;
	case 10415ULL: goto x86_l_28af;
	case 10418ULL: goto x86_l_28b2;
	case 10426ULL: goto x86_l_28ba;
	case 10432ULL: goto x86_l_28c0;
	case 10435ULL: goto x86_l_28c3;
	case 10441ULL: goto x86_l_28c9;
	case 10449ULL: goto x86_l_28d1;
	case 10452ULL: goto x86_l_28d4;
	case 10460ULL: goto x86_l_28dc;
	case 10464ULL: goto x86_l_28e0;
	case 10472ULL: goto x86_l_28e8;
	case 10476ULL: goto x86_l_28ec;
	case 10480ULL: goto x86_l_28f0;
	case 10487ULL: goto x86_l_28f7;
	case 10490ULL: goto x86_l_28fa;
	case 10496ULL: goto x86_l_2900;
	case 10500ULL: goto x86_l_2904;
	case 10504ULL: goto x86_l_2908;
	case 10508ULL: goto x86_l_290c;
	case 10514ULL: goto x86_l_2912;
	case 10519ULL: goto x86_l_2917;
	case 10522ULL: goto x86_l_291a;
	case 10530ULL: goto x86_l_2922;
	case 10532ULL: goto x86_l_2924;
	case 10537ULL: goto x86_l_2929;
	case 10539ULL: goto x86_l_292b;
	case 10541ULL: goto x86_l_292d;
	case 10545ULL: goto x86_l_2931;
	case 10549ULL: goto x86_l_2935;
	case 10551ULL: goto x86_l_2937;
	case 10554ULL: goto x86_l_293a;
	case 10557ULL: goto x86_l_293d;
	case 10561ULL: goto x86_l_2941;
	case 10564ULL: goto x86_l_2944;
	case 10572ULL: goto x86_l_294c;
	case 10577ULL: goto x86_l_2951;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10606ULL: goto x86_l_296e;
	case 10612ULL: goto x86_l_2974;
	case 10620ULL: goto x86_l_297c;
	case 10624ULL: goto x86_l_2980;
	case 10630ULL: goto x86_l_2986;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10645ULL: goto x86_l_2995;
	case 10647ULL: goto x86_l_2997;
	case 10652ULL: goto x86_l_299c;
	case 10654ULL: goto x86_l_299e;
	case 10660ULL: goto x86_l_29a4;
	case 10665ULL: goto x86_l_29a9;
	case 10670ULL: goto x86_l_29ae;
	case 10673ULL: goto x86_l_29b1;
	case 10676ULL: goto x86_l_29b4;
	case 10680ULL: goto x86_l_29b8;
	case 10683ULL: goto x86_l_29bb;
	case 10687ULL: goto x86_l_29bf;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10704ULL: goto x86_l_29d0;
	case 10710ULL: goto x86_l_29d6;
	case 10714ULL: goto x86_l_29da;
	case 10717ULL: goto x86_l_29dd;
	case 10721ULL: goto x86_l_29e1;
	case 10727ULL: goto x86_l_29e7;
	case 10732ULL: goto x86_l_29ec;
	case 10737ULL: goto x86_l_29f1;
	case 10742ULL: goto x86_l_29f6;
	case 10747ULL: goto x86_l_29fb;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10756ULL: goto x86_l_2a04;
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10773ULL: goto x86_l_2a15;
	case 10775ULL: goto x86_l_2a17;
	case 10780ULL: goto x86_l_2a1c;
	case 10782ULL: goto x86_l_2a1e;
	case 10787ULL: goto x86_l_2a23;
	case 10789ULL: goto x86_l_2a25;
	case 10794ULL: goto x86_l_2a2a;
	case 10803ULL: goto x86_l_2a33;
	case 10809ULL: goto x86_l_2a39;
	case 10817ULL: goto x86_l_2a41;
	case 10821ULL: goto x86_l_2a45;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2361:
	/* 0x2361: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2366:
	/* 0x2366: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2368:
	/* 0x2368: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_236b:
	/* 0x236b: js     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_268b;
	}
x86_l_2371:
	/* 0x2371: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2376:
	/* 0x2376: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2379:
	/* 0x2379: jg     239d <generic_retkprobe_event+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_239d;
	}
x86_l_237b:
	/* 0x237b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_237d:
	/* 0x237d: je     23c6 <generic_retkprobe_event+0x23c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23c6;
	}
x86_l_237f:
	/* 0x237f: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2382:
	/* 0x2382: je     23c6 <generic_retkprobe_event+0x23c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23c6;
	}
x86_l_2384:
	/* 0x2384: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2387:
	/* 0x2387: jne    24b7 <generic_retkprobe_event+0x24b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24b7;
	}
x86_l_238d:
	/* 0x238d: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2394:
	/* 0x2394: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2398:
	/* 0x2398: jmp    24bc <generic_retkprobe_event+0x24bc> */
	goto x86_l_24bc;
x86_l_239d:
	/* 0x239d: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_23a0:
	/* 0x23a0: je     24a4 <generic_retkprobe_event+0x24a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a4;
	}
x86_l_23a6:
	/* 0x23a6: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_23a9:
	/* 0x23a9: je     23c6 <generic_retkprobe_event+0x23c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23c6;
	}
x86_l_23ab:
	/* 0x23ab: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_23b0:
	/* 0x23b0: jne    24b7 <generic_retkprobe_event+0x24b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24b7;
	}
x86_l_23b6:
	/* 0x23b6: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_23bd:
	/* 0x23bd: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_23c1:
	/* 0x23c1: jmp    24bc <generic_retkprobe_event+0x24bc> */
	goto x86_l_24bc;
x86_l_23c6:
	/* 0x23c6: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_23cb:
	/* 0x23cb: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_23d2:
	/* 0x23d2: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_23d7:
	/* 0x23d7: jmp    24bc <generic_retkprobe_event+0x24bc> */
	goto x86_l_24bc;
x86_l_23dc:
	/* 0x23dc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23de:
	/* 0x23de: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23e3:
	/* 0x23e3: cmp    QWORD PTR [rsp+0x80],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813893ULL);
x86_l_23ec:
	/* 0x23ec: jb     2000 <generic_retkprobe_event+0x2000> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8192ULL;
	}
x86_l_23f2:
	/* 0x23f2: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_23fa:
	/* 0x23fa: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23fe:
	/* 0x23fe: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2404:
	/* 0x2404: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2409:
	/* 0x2409: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_240e:
	/* 0x240e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2413:
	/* 0x2413: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2415:
	/* 0x2415: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_241a:
	/* 0x241a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_241c:
	/* 0x241c: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10946ULL;
	}
x86_l_2422:
	/* 0x2422: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2427:
	/* 0x2427: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_242c:
	/* 0x242c: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_242f:
	/* 0x242f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2432:
	/* 0x2432: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2436:
	/* 0x2436: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2439:
	/* 0x2439: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_243d:
	/* 0x243d: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2442:
	/* 0x2442: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2446:
	/* 0x2446: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_244d:
	/* 0x244d: ja     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10946ULL;
	}
x86_l_2453:
	/* 0x2453: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2456:
	/* 0x2456: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2459:
	/* 0x2459: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_245c:
	/* 0x245c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2462:
	/* 0x2462: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2467:
	/* 0x2467: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_246c:
	/* 0x246c: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2471:
	/* 0x2471: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2475:
	/* 0x2475: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2477:
	/* 0x2477: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_247c:
	/* 0x247c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_247e:
	/* 0x247e: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10946ULL;
	}
x86_l_2484:
	/* 0x2484: add    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2488:
	/* 0x2488: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_248e:
	/* 0x248e: je     295e <generic_retkprobe_event+0x295e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_295e;
	}
x86_l_2494:
	/* 0x2494: sub    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 8ULL);
x86_l_2499:
	/* 0x2499: jne    2965 <generic_retkprobe_event+0x2965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2965;
	}
x86_l_249f:
	/* 0x249f: jmp    2000 <generic_retkprobe_event+0x2000> */
	return 8192ULL;
x86_l_24a4:
	/* 0x24a4: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_24a9:
	/* 0x24a9: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_24b0:
	/* 0x24b0: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24b5:
	/* 0x24b5: jmp    24bc <generic_retkprobe_event+0x24bc> */
	goto x86_l_24bc;
x86_l_24b7:
	/* 0x24b7: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_24bc:
	/* 0x24bc: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24c1:
	/* 0x24c1: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24c6:
	/* 0x24c6: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_24cb:
	/* 0x24cb: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_24cf:
	/* 0x24cf: ja     2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2951;
	}
x86_l_24d5:
	/* 0x24d5: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_24df:
	/* 0x24df: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_24e3:
	/* 0x24e3: jae    2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2951;
	}
x86_l_24e9:
	/* 0x24e9: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_24ed:
	/* 0x24ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24f2:
	/* 0x24f2: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24f7:
	/* 0x24f7: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_24fc:
	/* 0x24fc: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_24ff:
	/* 0x24ff: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2504:
	/* 0x2504: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2506:
	/* 0x2506: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2509:
	/* 0x2509: js     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_268b;
	}
x86_l_250f:
	/* 0x250f: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2514:
	/* 0x2514: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2517:
	/* 0x2517: jg     2534 <generic_retkprobe_event+0x2534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2534;
	}
x86_l_2519:
	/* 0x2519: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_251b:
	/* 0x251b: je     2552 <generic_retkprobe_event+0x2552> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2552;
	}
x86_l_251d:
	/* 0x251d: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2520:
	/* 0x2520: je     2552 <generic_retkprobe_event+0x2552> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2552;
	}
x86_l_2522:
	/* 0x2522: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2525:
	/* 0x2525: jne    2578 <generic_retkprobe_event+0x2578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2578;
	}
x86_l_2527:
	/* 0x2527: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_252e:
	/* 0x252e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2532:
	/* 0x2532: jmp    257d <generic_retkprobe_event+0x257d> */
	goto x86_l_257d;
x86_l_2534:
	/* 0x2534: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2537:
	/* 0x2537: je     2565 <generic_retkprobe_event+0x2565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2565;
	}
x86_l_2539:
	/* 0x2539: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_253c:
	/* 0x253c: je     2552 <generic_retkprobe_event+0x2552> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2552;
	}
x86_l_253e:
	/* 0x253e: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2543:
	/* 0x2543: jne    2578 <generic_retkprobe_event+0x2578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2578;
	}
x86_l_2545:
	/* 0x2545: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_254c:
	/* 0x254c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2550:
	/* 0x2550: jmp    257d <generic_retkprobe_event+0x257d> */
	goto x86_l_257d;
x86_l_2552:
	/* 0x2552: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2557:
	/* 0x2557: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_255e:
	/* 0x255e: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2563:
	/* 0x2563: jmp    257d <generic_retkprobe_event+0x257d> */
	goto x86_l_257d;
x86_l_2565:
	/* 0x2565: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_256a:
	/* 0x256a: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2571:
	/* 0x2571: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2576:
	/* 0x2576: jmp    257d <generic_retkprobe_event+0x257d> */
	goto x86_l_257d;
x86_l_2578:
	/* 0x2578: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_257d:
	/* 0x257d: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2582:
	/* 0x2582: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2587:
	/* 0x2587: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_258c:
	/* 0x258c: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2590:
	/* 0x2590: ja     2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2951;
	}
x86_l_2596:
	/* 0x2596: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_25a0:
	/* 0x25a0: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_25a4:
	/* 0x25a4: jae    2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2951;
	}
x86_l_25aa:
	/* 0x25aa: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_25ae:
	/* 0x25ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25b3:
	/* 0x25b3: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25b8:
	/* 0x25b8: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_25bd:
	/* 0x25bd: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_25c0:
	/* 0x25c0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_25c5:
	/* 0x25c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25c7:
	/* 0x25c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25ca:
	/* 0x25ca: js     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_268b;
	}
x86_l_25d0:
	/* 0x25d0: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_25d5:
	/* 0x25d5: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_25d8:
	/* 0x25d8: jg     25f5 <generic_retkprobe_event+0x25f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_25f5;
	}
x86_l_25da:
	/* 0x25da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25dc:
	/* 0x25dc: je     2613 <generic_retkprobe_event+0x2613> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2613;
	}
x86_l_25de:
	/* 0x25de: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_25e1:
	/* 0x25e1: je     2613 <generic_retkprobe_event+0x2613> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2613;
	}
x86_l_25e3:
	/* 0x25e3: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_25e6:
	/* 0x25e6: jne    2639 <generic_retkprobe_event+0x2639> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2639;
	}
x86_l_25e8:
	/* 0x25e8: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_25ef:
	/* 0x25ef: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_25f3:
	/* 0x25f3: jmp    263e <generic_retkprobe_event+0x263e> */
	goto x86_l_263e;
x86_l_25f5:
	/* 0x25f5: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_25f8:
	/* 0x25f8: je     2626 <generic_retkprobe_event+0x2626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2626;
	}
x86_l_25fa:
	/* 0x25fa: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_25fd:
	/* 0x25fd: je     2613 <generic_retkprobe_event+0x2613> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2613;
	}
x86_l_25ff:
	/* 0x25ff: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2604:
	/* 0x2604: jne    2639 <generic_retkprobe_event+0x2639> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2639;
	}
x86_l_2606:
	/* 0x2606: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_260d:
	/* 0x260d: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2611:
	/* 0x2611: jmp    263e <generic_retkprobe_event+0x263e> */
	goto x86_l_263e;
x86_l_2613:
	/* 0x2613: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2618:
	/* 0x2618: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_261f:
	/* 0x261f: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2624:
	/* 0x2624: jmp    263e <generic_retkprobe_event+0x263e> */
	goto x86_l_263e;
x86_l_2626:
	/* 0x2626: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_262b:
	/* 0x262b: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2632:
	/* 0x2632: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2637:
	/* 0x2637: jmp    263e <generic_retkprobe_event+0x263e> */
	goto x86_l_263e;
x86_l_2639:
	/* 0x2639: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_263e:
	/* 0x263e: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2643:
	/* 0x2643: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2648:
	/* 0x2648: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_264d:
	/* 0x264d: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2651:
	/* 0x2651: ja     2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2951;
	}
x86_l_2657:
	/* 0x2657: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2661:
	/* 0x2661: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2665:
	/* 0x2665: jae    2951 <generic_retkprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2951;
	}
x86_l_266b:
	/* 0x266b: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_266f:
	/* 0x266f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2674:
	/* 0x2674: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2679:
	/* 0x2679: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_267e:
	/* 0x267e: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2681:
	/* 0x2681: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2684:
	/* 0x2684: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2689:
	/* 0x2689: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268b:
	/* 0x268b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_268d:
	/* 0x268d: mov    BYTE PTR [rsp+0xc0],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2694:
	/* 0x2694: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2697:
	/* 0x2697: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_269b:
	/* 0x269b: mov    WORD PTR [r14+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_26a3:
	/* 0x26a3: mov    WORD PTR [r14+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_26ad:
	/* 0x26ad: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b2:
	/* 0x26b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26b7:
	/* 0x26b7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26bc:
	/* 0x26bc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26c1:
	/* 0x26c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c3:
	/* 0x26c3: lea    rdi,[r14+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_26ca:
	/* 0x26ca: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_26ce:
	/* 0x26ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26d3:
	/* 0x26d3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26d8:
	/* 0x26d8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_26db:
	/* 0x26db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26dd:
	/* 0x26dd: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_26e5:
	/* 0x26e5: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_26e8:
	/* 0x26e8: je     2732 <generic_retkprobe_event+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2732;
	}
x86_l_26ea:
	/* 0x26ea: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_26ed:
	/* 0x26ed: jne    2778 <generic_retkprobe_event+0x2778> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2778;
	}
x86_l_26f3:
	/* 0x26f3: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26f8:
	/* 0x26f8: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_2701:
	/* 0x2701: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2705:
	/* 0x2705: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2709:
	/* 0x2709: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2710:
	/* 0x2710: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2715:
	/* 0x2715: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_271a:
	/* 0x271a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271c:
	/* 0x271c: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2723:
	/* 0x2723: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2727:
	/* 0x2727: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_272b:
	/* 0x272b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2730:
	/* 0x2730: jmp    276f <generic_retkprobe_event+0x276f> */
	goto x86_l_276f;
x86_l_2732:
	/* 0x2732: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2737:
	/* 0x2737: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_2740:
	/* 0x2740: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2744:
	/* 0x2744: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2748:
	/* 0x2748: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_274f:
	/* 0x274f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2754:
	/* 0x2754: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2759:
	/* 0x2759: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275b:
	/* 0x275b: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2762:
	/* 0x2762: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2766:
	/* 0x2766: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_276a:
	/* 0x276a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_276f:
	/* 0x276f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2774:
	/* 0x2774: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2776:
	/* 0x2776: jmp    2786 <generic_retkprobe_event+0x2786> */
	goto x86_l_2786;
x86_l_2778:
	/* 0x2778: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_277c:
	/* 0x277c: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_2786:
	/* 0x2786: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_278a:
	/* 0x278a: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_2791:
	/* 0x2791: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2798:
	/* 0x2798: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_27a1:
	/* 0x27a1: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_27aa:
	/* 0x27aa: add    rbp,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_27b1:
	/* 0x27b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27b6:
	/* 0x27b6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27bb:
	/* 0x27bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27c0:
	/* 0x27c0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_27c3:
	/* 0x27c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27c5:
	/* 0x27c5: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_27cb:
	/* 0x27cb: je     2830 <generic_retkprobe_event+0x2830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2830;
	}
x86_l_27cd:
	/* 0x27cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27d2:
	/* 0x27d2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27d7:
	/* 0x27d7: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_27db:
	/* 0x27db: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_27e3:
	/* 0x27e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27e8:
	/* 0x27e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ea:
	/* 0x27ea: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27ef:
	/* 0x27ef: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_27f7:
	/* 0x27f7: lea    rdx,[r14+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_27fb:
	/* 0x27fb: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ff:
	/* 0x27ff: lea    rdi,[r13+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2806:
	/* 0x2806: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_280b:
	/* 0x280b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2810:
	/* 0x2810: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2812:
	/* 0x2812: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2815:
	/* 0x2815: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_281c:
	/* 0x281c: lea    rdx,[r14+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2820:
	/* 0x2820: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2824:
	/* 0x2824: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2829:
	/* 0x2829: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_282e:
	/* 0x282e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2830:
	/* 0x2830: mov    r13d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 64ULL);
x86_l_2836:
	/* 0x2836: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_283a:
	/* 0x283a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_283f:
	/* 0x283f: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_2845:
	/* 0x2845: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_2848:
	/* 0x2848: mov    ebp,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_284c:
	/* 0x284c: js     285e <generic_retkprobe_event+0x285e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_285e;
	}
x86_l_284e:
	/* 0x284e: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2855:
	/* 0x2855: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2859:
	/* 0x2859: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_285c:
	/* 0x285c: jmp    2872 <generic_retkprobe_event+0x2872> */
	goto x86_l_2872;
x86_l_285e:
	/* 0x285e: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_2868:
	/* 0x2868: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_2872:
	/* 0x2872: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_287a:
	/* 0x287a: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_287e:
	/* 0x287e: mov    eax,DWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2882:
	/* 0x2882: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2885:
	/* 0x2885: jne    28a <generic_retkprobe_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 650ULL;
	}
x86_l_288b:
	/* 0x288b: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2890:
	/* 0x2890: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2897:
	/* 0x2897: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_289f:
	/* 0x289f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a1:
	/* 0x28a1: and    r14d,0x1fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_28a8:
	/* 0x28a8: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_28af:
	/* 0x28af: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_28b2:
	/* 0x28b2: mov    QWORD PTR [rsp+0xf0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_28ba:
	/* 0x28ba: je     195 <generic_retkprobe_event+0x195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 405ULL;
	}
x86_l_28c0:
	/* 0x28c0: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_28c3:
	/* 0x28c3: jne    2add <generic_retkprobe_event+0x2add> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10973ULL;
	}
x86_l_28c9:
	/* 0x28c9: mov    QWORD PTR [rsp+0x80],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_28d1:
	/* 0x28d1: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_28d4:
	/* 0x28d4: mov    DWORD PTR [r12+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_28dc:
	/* 0x28dc: lea    rbx,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_28e0:
	/* 0x28e0: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_28e8:
	/* 0x28e8: lea    r13,[r12+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_28ec:
	/* 0x28ec: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_28f0:
	/* 0x28f0: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_28f7:
	/* 0x28f7: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_28fa:
	/* 0x28fa: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_2900:
	/* 0x2900: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_2904:
	/* 0x2904: lea    rdi,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2908:
	/* 0x2908: add    rdi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_290c:
	/* 0x290c: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_2912:
	/* 0x2912: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2917:
	/* 0x2917: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_291a:
	/* 0x291a: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2922:
	/* 0x2922: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2924:
	/* 0x2924: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2929:
	/* 0x2929: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_292b:
	/* 0x292b: js     293a <generic_retkprobe_event+0x293a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_293a;
	}
x86_l_292d:
	/* 0x292d: mov    DWORD PTR [r13+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2931:
	/* 0x2931: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2935:
	/* 0x2935: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2937:
	/* 0x2937: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_293a:
	/* 0x293a: add    r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_293d:
	/* 0x293d: mov    DWORD PTR [r13+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2941:
	/* 0x2941: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2944:
	/* 0x2944: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_294c:
	/* 0x294c: jmp    2add <generic_retkprobe_event+0x2add> */
	return 10973ULL;
x86_l_2951:
	/* 0x2951: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2959:
	/* 0x2959: jmp    268d <generic_retkprobe_event+0x268d> */
	goto x86_l_268d;
x86_l_295e:
	/* 0x295e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2960:
	/* 0x2960: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2965:
	/* 0x2965: cmp    QWORD PTR [rsp+0x80],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813893ULL);
x86_l_296e:
	/* 0x296e: je     2000 <generic_retkprobe_event+0x2000> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8192ULL;
	}
x86_l_2974:
	/* 0x2974: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_297c:
	/* 0x297c: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2980:
	/* 0x2980: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2986:
	/* 0x2986: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_298b:
	/* 0x298b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2990:
	/* 0x2990: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2995:
	/* 0x2995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2997:
	/* 0x2997: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_299c:
	/* 0x299c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_299e:
	/* 0x299e: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10946ULL;
	}
x86_l_29a4:
	/* 0x29a4: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29a9:
	/* 0x29a9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29ae:
	/* 0x29ae: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_29b1:
	/* 0x29b1: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_29b4:
	/* 0x29b4: cmovb  r15,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_29b8:
	/* 0x29b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29bb:
	/* 0x29bb: cmovne rdx,r15 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R15, X86_WIDTH_64, X86_CC_NE);
x86_l_29bf:
	/* 0x29bf: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_29c4:
	/* 0x29c4: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29c9:
	/* 0x29c9: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_29d0:
	/* 0x29d0: ja     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10946ULL;
	}
x86_l_29d6:
	/* 0x29d6: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29da:
	/* 0x29da: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29dd:
	/* 0x29dd: mov    QWORD PTR [rsp],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29e1:
	/* 0x29e1: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_29e7:
	/* 0x29e7: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_29ec:
	/* 0x29ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29f1:
	/* 0x29f1: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29f6:
	/* 0x29f6: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29fb:
	/* 0x29fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29fd:
	/* 0x29fd: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a02:
	/* 0x2a02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a04:
	/* 0x2a04: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10946ULL;
	}
x86_l_2a0a:
	/* 0x2a0a: add    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2a0f:
	/* 0x2a0f: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a15:
	/* 0x2a15: je     2a23 <generic_retkprobe_event+0x2a23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a23;
	}
x86_l_2a17:
	/* 0x2a17: sub    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 8ULL);
x86_l_2a1c:
	/* 0x2a1c: jne    2a2a <generic_retkprobe_event+0x2a2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a2a;
	}
x86_l_2a1e:
	/* 0x2a1e: jmp    2000 <generic_retkprobe_event+0x2000> */
	return 8192ULL;
x86_l_2a23:
	/* 0x2a23: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a25:
	/* 0x2a25: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a2a:
	/* 0x2a2a: cmp    QWORD PTR [rsp+0x80],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813895ULL);
x86_l_2a33:
	/* 0x2a33: jb     2000 <generic_retkprobe_event+0x2000> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8192ULL;
	}
x86_l_2a39:
	/* 0x2a39: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2a41:
	/* 0x2a41: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2a45:
	/* 0x2a45: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
	return 10827ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10842ULL: goto x86_l_2a5a;
	case 10844ULL: goto x86_l_2a5c;
	case 10849ULL: goto x86_l_2a61;
	case 10851ULL: goto x86_l_2a63;
	case 10853ULL: goto x86_l_2a65;
	case 10858ULL: goto x86_l_2a6a;
	case 10863ULL: goto x86_l_2a6f;
	case 10866ULL: goto x86_l_2a72;
	case 10869ULL: goto x86_l_2a75;
	case 10873ULL: goto x86_l_2a79;
	case 10876ULL: goto x86_l_2a7c;
	case 10880ULL: goto x86_l_2a80;
	case 10885ULL: goto x86_l_2a85;
	case 10892ULL: goto x86_l_2a8c;
	case 10894ULL: goto x86_l_2a8e;
	case 10899ULL: goto x86_l_2a93;
	case 10903ULL: goto x86_l_2a97;
	case 10909ULL: goto x86_l_2a9d;
	case 10914ULL: goto x86_l_2aa2;
	case 10919ULL: goto x86_l_2aa7;
	case 10924ULL: goto x86_l_2aac;
	case 10927ULL: goto x86_l_2aaf;
	case 10929ULL: goto x86_l_2ab1;
	case 10934ULL: goto x86_l_2ab6;
	case 10936ULL: goto x86_l_2ab8;
	case 10938ULL: goto x86_l_2aba;
	case 10941ULL: goto x86_l_2abd;
	case 10946ULL: goto x86_l_2ac2;
	case 10951ULL: goto x86_l_2ac7;
	case 10956ULL: goto x86_l_2acc;
	case 10959ULL: goto x86_l_2acf;
	case 10962ULL: goto x86_l_2ad2;
	case 10965ULL: goto x86_l_2ad5;
	case 10973ULL: goto x86_l_2add;
	case 10978ULL: goto x86_l_2ae2;
	case 10980ULL: goto x86_l_2ae4;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10993ULL: goto x86_l_2af1;
	case 11001ULL: goto x86_l_2af9;
	case 11009ULL: goto x86_l_2b01;
	case 11014ULL: goto x86_l_2b06;
	case 11016ULL: goto x86_l_2b08;
	case 11023ULL: goto x86_l_2b0f;
	case 11027ULL: goto x86_l_2b13;
	case 11032ULL: goto x86_l_2b18;
	case 11039ULL: goto x86_l_2b1f;
	case 11044ULL: goto x86_l_2b24;
	case 11046ULL: goto x86_l_2b26;
	case 11049ULL: goto x86_l_2b29;
	case 11051ULL: goto x86_l_2b2b;
	case 11054ULL: goto x86_l_2b2e;
	case 11059ULL: goto x86_l_2b33;
	case 11065ULL: goto x86_l_2b39;
	case 11070ULL: goto x86_l_2b3e;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11090ULL: goto x86_l_2b52;
	case 11092ULL: goto x86_l_2b54;
	case 11098ULL: goto x86_l_2b5a;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11119ULL: goto x86_l_2b6f;
	case 11127ULL: goto x86_l_2b77;
	case 11132ULL: goto x86_l_2b7c;
	case 11134ULL: goto x86_l_2b7e;
	case 11141ULL: goto x86_l_2b85;
	case 11145ULL: goto x86_l_2b89;
	case 11150ULL: goto x86_l_2b8e;
	case 11157ULL: goto x86_l_2b95;
	case 11162ULL: goto x86_l_2b9a;
	case 11164ULL: goto x86_l_2b9c;
	case 11167ULL: goto x86_l_2b9f;
	case 11169ULL: goto x86_l_2ba1;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11183ULL: goto x86_l_2baf;
	case 11188ULL: goto x86_l_2bb4;
	case 11193ULL: goto x86_l_2bb9;
	case 11198ULL: goto x86_l_2bbe;
	case 11203ULL: goto x86_l_2bc3;
	case 11208ULL: goto x86_l_2bc8;
	case 11210ULL: goto x86_l_2bca;
	case 11216ULL: goto x86_l_2bd0;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11232ULL: goto x86_l_2be0;
	case 11237ULL: goto x86_l_2be5;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11252ULL: goto x86_l_2bf4;
	case 11259ULL: goto x86_l_2bfb;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11282ULL: goto x86_l_2c12;
	case 11285ULL: goto x86_l_2c15;
	case 11287ULL: goto x86_l_2c17;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11301ULL: goto x86_l_2c25;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11316ULL: goto x86_l_2c34;
	case 11321ULL: goto x86_l_2c39;
	case 11326ULL: goto x86_l_2c3e;
	case 11328ULL: goto x86_l_2c40;
	case 11334ULL: goto x86_l_2c46;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11359ULL: goto x86_l_2c5f;
	case 11364ULL: goto x86_l_2c64;
	case 11366ULL: goto x86_l_2c66;
	case 11373ULL: goto x86_l_2c6d;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11396ULL: goto x86_l_2c84;
	case 11399ULL: goto x86_l_2c87;
	case 11401ULL: goto x86_l_2c89;
	case 11404ULL: goto x86_l_2c8c;
	case 11409ULL: goto x86_l_2c91;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11421ULL: goto x86_l_2c9d;
	case 11426ULL: goto x86_l_2ca2;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11438ULL: goto x86_l_2cae;
	case 11441ULL: goto x86_l_2cb1;
	case 11447ULL: goto x86_l_2cb7;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11458ULL: goto x86_l_2cc2;
	case 11462ULL: goto x86_l_2cc6;
	case 11465ULL: goto x86_l_2cc9;
	case 11467ULL: goto x86_l_2ccb;
	case 11470ULL: goto x86_l_2cce;
	case 11473ULL: goto x86_l_2cd1;
	case 11477ULL: goto x86_l_2cd5;
	case 11481ULL: goto x86_l_2cd9;
	case 11488ULL: goto x86_l_2ce0;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11502ULL: goto x86_l_2cee;
	case 11506ULL: goto x86_l_2cf2;
	case 11511ULL: goto x86_l_2cf7;
	case 11518ULL: goto x86_l_2cfe;
	case 11521ULL: goto x86_l_2d01;
	case 11526ULL: goto x86_l_2d06;
	case 11528ULL: goto x86_l_2d08;
	case 11533ULL: goto x86_l_2d0d;
	case 11535ULL: goto x86_l_2d0f;
	case 11542ULL: goto x86_l_2d16;
	case 11544ULL: goto x86_l_2d18;
	case 11545ULL: goto x86_l_2d19;
	case 11550ULL: goto x86_l_2d1e;
	case 11552ULL: goto x86_l_2d20;
	case 11554ULL: goto x86_l_2d22;
	case 11556ULL: goto x86_l_2d24;
	case 11557ULL: goto x86_l_2d25;
	case 11561ULL: goto x86_l_2d29;
	case 11564ULL: goto x86_l_2d2c;
	case 11568ULL: goto x86_l_2d30;
	case 11572ULL: goto x86_l_2d34;
	case 11576ULL: goto x86_l_2d38;
	case 11579ULL: goto x86_l_2d3b;
	case 11581ULL: goto x86_l_2d3d;
	case 11585ULL: goto x86_l_2d41;
	case 11591ULL: goto x86_l_2d47;
	case 11596ULL: goto x86_l_2d4c;
	case 11601ULL: goto x86_l_2d51;
	case 11606ULL: goto x86_l_2d56;
	case 11608ULL: goto x86_l_2d58;
	case 11613ULL: goto x86_l_2d5d;
	case 11619ULL: goto x86_l_2d63;
	case 11623ULL: goto x86_l_2d67;
	case 11628ULL: goto x86_l_2d6c;
	case 11633ULL: goto x86_l_2d71;
	case 11638ULL: goto x86_l_2d76;
	case 11641ULL: goto x86_l_2d79;
	case 11643ULL: goto x86_l_2d7b;
	case 11648ULL: goto x86_l_2d80;
	case 11654ULL: goto x86_l_2d86;
	case 11659ULL: goto x86_l_2d8b;
	case 11664ULL: goto x86_l_2d90;
	case 11669ULL: goto x86_l_2d95;
	case 11672ULL: goto x86_l_2d98;
	case 11674ULL: goto x86_l_2d9a;
	case 11678ULL: goto x86_l_2d9e;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11696ULL: goto x86_l_2db0;
	case 11698ULL: goto x86_l_2db2;
	case 11702ULL: goto x86_l_2db6;
	case 11706ULL: goto x86_l_2dba;
	case 11710ULL: goto x86_l_2dbe;
	case 11713ULL: goto x86_l_2dc1;
	case 11716ULL: goto x86_l_2dc4;
	case 11718ULL: goto x86_l_2dc6;
	case 11720ULL: goto x86_l_2dc8;
	case 11722ULL: goto x86_l_2dca;
	case 11725ULL: goto x86_l_2dcd;
	case 11730ULL: goto x86_l_2dd2;
	case 11733ULL: goto x86_l_2dd5;
	case 11735ULL: goto x86_l_2dd7;
	case 11739ULL: goto x86_l_2ddb;
	case 11742ULL: goto x86_l_2dde;
	case 11746ULL: goto x86_l_2de2;
	case 11749ULL: goto x86_l_2de5;
	case 11751ULL: goto x86_l_2de7;
	case 11754ULL: goto x86_l_2dea;
	case 11757ULL: goto x86_l_2ded;
	case 11762ULL: goto x86_l_2df2;
	case 11765ULL: goto x86_l_2df5;
	case 11771ULL: goto x86_l_2dfb;
	case 11778ULL: goto x86_l_2e02;
	case 11784ULL: goto x86_l_2e08;
	case 11786ULL: goto x86_l_2e0a;
	case 11792ULL: goto x86_l_2e10;
	case 11796ULL: goto x86_l_2e14;
	case 11801ULL: goto x86_l_2e19;
	case 11805ULL: goto x86_l_2e1d;
	case 11809ULL: goto x86_l_2e21;
	case 11812ULL: goto x86_l_2e24;
	case 11817ULL: goto x86_l_2e29;
	case 11819ULL: goto x86_l_2e2b;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11832ULL: goto x86_l_2e38;
	case 11834ULL: goto x86_l_2e3a;
	case 11836ULL: goto x86_l_2e3c;
	case 11840ULL: goto x86_l_2e40;
	case 11845ULL: goto x86_l_2e45;
	case 11850ULL: goto x86_l_2e4a;
	case 11855ULL: goto x86_l_2e4f;
	case 11857ULL: goto x86_l_2e51;
	case 11861ULL: goto x86_l_2e55;
	case 11866ULL: goto x86_l_2e5a;
	case 11868ULL: goto x86_l_2e5c;
	case 11872ULL: goto x86_l_2e60;
	case 11876ULL: goto x86_l_2e64;
	case 11881ULL: goto x86_l_2e69;
	case 11886ULL: goto x86_l_2e6e;
	case 11889ULL: goto x86_l_2e71;
	case 11891ULL: goto x86_l_2e73;
	case 11896ULL: goto x86_l_2e78;
	case 11900ULL: goto x86_l_2e7c;
	case 11904ULL: goto x86_l_2e80;
	case 11908ULL: goto x86_l_2e84;
	case 11910ULL: goto x86_l_2e86;
	case 11912ULL: goto x86_l_2e88;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11925ULL: goto x86_l_2e95;
	case 11926ULL: goto x86_l_2e96;
	case 11928ULL: goto x86_l_2e98;
	case 11930ULL: goto x86_l_2e9a;
	case 11932ULL: goto x86_l_2e9c;
	case 11933ULL: goto x86_l_2e9d;
	case 11937ULL: goto x86_l_2ea1;
	case 11940ULL: goto x86_l_2ea4;
	case 11945ULL: goto x86_l_2ea9;
	case 11948ULL: goto x86_l_2eac;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11959ULL: goto x86_l_2eb7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a4b:
	/* 0x2a4b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a50:
	/* 0x2a50: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a55:
	/* 0x2a55: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a5a:
	/* 0x2a5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5c:
	/* 0x2a5c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a61:
	/* 0x2a61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a63:
	/* 0x2a63: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ac2;
	}
x86_l_2a65:
	/* 0x2a65: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a6a:
	/* 0x2a6a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a6f:
	/* 0x2a6f: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2a72:
	/* 0x2a72: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2a75:
	/* 0x2a75: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_2a79:
	/* 0x2a79: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2a7c:
	/* 0x2a7c: cmove  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_2a80:
	/* 0x2a80: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2a85:
	/* 0x2a85: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_2a8c:
	/* 0x2a8c: ja     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ac2;
	}
x86_l_2a8e:
	/* 0x2a8e: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a93:
	/* 0x2a93: add    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a97:
	/* 0x2a97: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a9d:
	/* 0x2a9d: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2aa2:
	/* 0x2aa2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aa7:
	/* 0x2aa7: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2aac:
	/* 0x2aac: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2aaf:
	/* 0x2aaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab1:
	/* 0x2ab1: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2ab6:
	/* 0x2ab6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ab8:
	/* 0x2ab8: js     2ac2 <generic_retkprobe_event+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ac2;
	}
x86_l_2aba:
	/* 0x2aba: add    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2abd:
	/* 0x2abd: jmp    2003 <generic_retkprobe_event+0x2003> */
	return 8195ULL;
x86_l_2ac2:
	/* 0x2ac2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2acc:
	/* 0x2acc: mov    DWORD PTR [rax+rbp*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2acf:
	/* 0x2acf: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ad2:
	/* 0x2ad2: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_2ad5:
	/* 0x2ad5: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2add:
	/* 0x2add: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2ae2:
	/* 0x2ae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae4:
	/* 0x2ae4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2ae7:
	/* 0x2ae7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2aec:
	/* 0x2aec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2af1:
	/* 0x2af1: lea    rdx,[r12+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_2af9:
	/* 0x2af9: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b01:
	/* 0x2b01: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b06:
	/* 0x2b06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b08:
	/* 0x2b08: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b0f:
	/* 0x2b0f: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b13:
	/* 0x2b13: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b18:
	/* 0x2b18: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2b1f:
	/* 0x2b1f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b24:
	/* 0x2b24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b26:
	/* 0x2b26: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b29:
	/* 0x2b29: je     2b39 <generic_retkprobe_event+0x2b39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b39;
	}
x86_l_2b2b:
	/* 0x2b2b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2b2e:
	/* 0x2b2e: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2b33:
	/* 0x2b33: jne    2cb1 <generic_retkprobe_event+0x2cb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cb1;
	}
x86_l_2b39:
	/* 0x2b39: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b3e:
	/* 0x2b3e: add    r12,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_2b45:
	/* 0x2b45: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b4a:
	/* 0x2b4a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b52:
	/* 0x2b52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b54:
	/* 0x2b54: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2b5a:
	/* 0x2b5a: je     2cae <generic_retkprobe_event+0x2cae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cae;
	}
x86_l_2b60:
	/* 0x2b60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b65:
	/* 0x2b65: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2b6a:
	/* 0x2b6a: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2b6f:
	/* 0x2b6f: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b77:
	/* 0x2b77: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b7c:
	/* 0x2b7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7e:
	/* 0x2b7e: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b85:
	/* 0x2b85: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b89:
	/* 0x2b89: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b8e:
	/* 0x2b8e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2b95:
	/* 0x2b95: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b9a:
	/* 0x2b9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9c:
	/* 0x2b9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b9f:
	/* 0x2b9f: je     2baf <generic_retkprobe_event+0x2baf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2baf;
	}
x86_l_2ba1:
	/* 0x2ba1: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2ba4:
	/* 0x2ba4: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2ba9:
	/* 0x2ba9: jne    2cb1 <generic_retkprobe_event+0x2cb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cb1;
	}
x86_l_2baf:
	/* 0x2baf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bb4:
	/* 0x2bb4: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2bb9:
	/* 0x2bb9: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2bbe:
	/* 0x2bbe: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bc3:
	/* 0x2bc3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bc8:
	/* 0x2bc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bca:
	/* 0x2bca: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2bd0:
	/* 0x2bd0: je     2cae <generic_retkprobe_event+0x2cae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cae;
	}
x86_l_2bd6:
	/* 0x2bd6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bdb:
	/* 0x2bdb: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2be0:
	/* 0x2be0: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2be5:
	/* 0x2be5: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2bed:
	/* 0x2bed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bf2:
	/* 0x2bf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf4:
	/* 0x2bf4: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2bfb:
	/* 0x2bfb: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bff:
	/* 0x2bff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c04:
	/* 0x2c04: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2c0b:
	/* 0x2c0b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c10:
	/* 0x2c10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c12:
	/* 0x2c12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c15:
	/* 0x2c15: je     2c25 <generic_retkprobe_event+0x2c25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c25;
	}
x86_l_2c17:
	/* 0x2c17: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c1a:
	/* 0x2c1a: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2c1f:
	/* 0x2c1f: jne    2cb1 <generic_retkprobe_event+0x2cb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cb1;
	}
x86_l_2c25:
	/* 0x2c25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c2a:
	/* 0x2c2a: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2c2f:
	/* 0x2c2f: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2c34:
	/* 0x2c34: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c39:
	/* 0x2c39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c3e:
	/* 0x2c3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c40:
	/* 0x2c40: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2c46:
	/* 0x2c46: je     2cae <generic_retkprobe_event+0x2cae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cae;
	}
x86_l_2c48:
	/* 0x2c48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c4d:
	/* 0x2c4d: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2c52:
	/* 0x2c52: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2c57:
	/* 0x2c57: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c5f:
	/* 0x2c5f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c64:
	/* 0x2c64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c66:
	/* 0x2c66: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c6d:
	/* 0x2c6d: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c71:
	/* 0x2c71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c76:
	/* 0x2c76: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2c7d:
	/* 0x2c7d: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c82:
	/* 0x2c82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c84:
	/* 0x2c84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c87:
	/* 0x2c87: je     2c93 <generic_retkprobe_event+0x2c93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c93;
	}
x86_l_2c89:
	/* 0x2c89: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c8c:
	/* 0x2c8c: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2c91:
	/* 0x2c91: jne    2cb1 <generic_retkprobe_event+0x2cb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cb1;
	}
x86_l_2c93:
	/* 0x2c93: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c98:
	/* 0x2c98: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2c9d:
	/* 0x2c9d: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2ca2:
	/* 0x2ca2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ca7:
	/* 0x2ca7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cac:
	/* 0x2cac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cae:
	/* 0x2cae: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cb1:
	/* 0x2cb1: mov    DWORD PTR [rbx],0x10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 269ULL);
x86_l_2cb7:
	/* 0x2cb7: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cbb:
	/* 0x2cbb: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2cc0:
	/* 0x2cc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc2:
	/* 0x2cc2: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cc6:
	/* 0x2cc6: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2cc9:
	/* 0x2cc9: je     2cd9 <generic_retkprobe_event+0x2cd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cd9;
	}
x86_l_2ccb:
	/* 0x2ccb: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cce:
	/* 0x2cce: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd1:
	/* 0x2cd1: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cd5:
	/* 0x2cd5: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cd9:
	/* 0x2cd9: mov    DWORD PTR [rbx+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2ce0:
	/* 0x2ce0: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2ce8:
	/* 0x2ce8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cea:
	/* 0x2cea: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2cee:
	/* 0x2cee: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cf2:
	/* 0x2cf2: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2cf7:
	/* 0x2cf7: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_2cfe:
	/* 0x2cfe: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2d01:
	/* 0x2d01: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2d06:
	/* 0x2d06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d08:
	/* 0x2d08: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2d0d:
	/* 0x2d0d: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2d0f:
	/* 0x2d0f: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_2d16:
	/* 0x2d16: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2d18:
	/* 0x2d18: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2d19:
	/* 0x2d19: jmp    2eb9 <cwd_read_v61+0x19b> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_2d1e:
	/* 0x2d1e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2d20:
	/* 0x2d20: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2d22:
	/* 0x2d22: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2d24:
	/* 0x2d24: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2d25:
	/* 0x2d25: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_2d29:
	/* 0x2d29: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2d2c:
	/* 0x2d2c: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d30:
	/* 0x2d30: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d34:
	/* 0x2d34: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d38:
	/* 0x2d38: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2d3b:
	/* 0x2d3b: jne    2d47 <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d47;
	}
x86_l_2d3d:
	/* 0x2d3d: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2d41:
	/* 0x2d41: je     2e88 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e88;
	}
x86_l_2d47:
	/* 0x2d47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d4c:
	/* 0x2d4c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d51:
	/* 0x2d51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d56:
	/* 0x2d56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d58:
	/* 0x2d58: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2d5d:
	/* 0x2d5d: je     2e3c <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e3c;
	}
x86_l_2d63:
	/* 0x2d63: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d67:
	/* 0x2d67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d6c:
	/* 0x2d6c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d71:
	/* 0x2d71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d76:
	/* 0x2d76: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d79:
	/* 0x2d79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d7b:
	/* 0x2d7b: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d80:
	/* 0x2d80: je     2e3c <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e3c;
	}
x86_l_2d86:
	/* 0x2d86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d8b:
	/* 0x2d8b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d90:
	/* 0x2d90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d95:
	/* 0x2d95: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d98:
	/* 0x2d98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9a:
	/* 0x2d9a: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2d9e:
	/* 0x2d9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2da3:
	/* 0x2da3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da8:
	/* 0x2da8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2dad:
	/* 0x2dad: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2db0:
	/* 0x2db0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db2:
	/* 0x2db2: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2db6:
	/* 0x2db6: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dba:
	/* 0x2dba: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2dbe:
	/* 0x2dbe: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2dc1:
	/* 0x2dc1: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dc4:
	/* 0x2dc4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dc6:
	/* 0x2dc6: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2dc8:
	/* 0x2dc8: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dca:
	/* 0x2dca: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2dcd:
	/* 0x2dcd: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2dd2:
	/* 0x2dd2: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dd5:
	/* 0x2dd5: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2dd7:
	/* 0x2dd7: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_2ddb:
	/* 0x2ddb: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_2dde:
	/* 0x2dde: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2de2:
	/* 0x2de2: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2de5:
	/* 0x2de5: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_2de7:
	/* 0x2de7: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dea:
	/* 0x2dea: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ded:
	/* 0x2ded: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2df2:
	/* 0x2df2: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2df5:
	/* 0x2df5: jb     2e91 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e91;
	}
x86_l_2dfb:
	/* 0x2dfb: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_2e02:
	/* 0x2e02: ja     2e91 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e91;
	}
x86_l_2e08:
	/* 0x2e08: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2e0a:
	/* 0x2e0a: jbe    2e9d <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2e9d;
	}
x86_l_2e10:
	/* 0x2e10: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e14:
	/* 0x2e14: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e19:
	/* 0x2e19: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e1d:
	/* 0x2e1d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e21:
	/* 0x2e21: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2e24:
	/* 0x2e24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e29:
	/* 0x2e29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2b:
	/* 0x2e2b: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e2f:
	/* 0x2e2f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e34:
	/* 0x2e34: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e38:
	/* 0x2e38: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e3a:
	/* 0x2e3a: jmp    2e91 <cwd_read_v61+0x173> */
	goto x86_l_2e91;
x86_l_2e3c:
	/* 0x2e3c: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e40:
	/* 0x2e40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e45:
	/* 0x2e45: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e4a:
	/* 0x2e4a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e4f:
	/* 0x2e4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e51:
	/* 0x2e51: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e55:
	/* 0x2e55: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2e5a:
	/* 0x2e5a: je     2e88 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e88;
	}
x86_l_2e5c:
	/* 0x2e5c: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e60:
	/* 0x2e60: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2e64:
	/* 0x2e64: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e69:
	/* 0x2e69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e6e:
	/* 0x2e6e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2e71:
	/* 0x2e71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e73:
	/* 0x2e73: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e78:
	/* 0x2e78: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e7c:
	/* 0x2e7c: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2e80:
	/* 0x2e80: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e84:
	/* 0x2e84: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e86:
	/* 0x2e86: jmp    2e91 <cwd_read_v61+0x173> */
	goto x86_l_2e91;
x86_l_2e88:
	/* 0x2e88: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_2e8c:
	/* 0x2e8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e91:
	/* 0x2e91: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2e95:
	/* 0x2e95: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2e96:
	/* 0x2e96: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2e98:
	/* 0x2e98: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2e9a:
	/* 0x2e9a: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2e9c:
	/* 0x2e9c: ret */
	return 0xffffffffffffffffULL;
x86_l_2e9d:
	/* 0x2e9d: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ea1:
	/* 0x2ea1: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ea4:
	/* 0x2ea4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea9:
	/* 0x2ea9: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2eac:
	/* 0x2eac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eae:
	/* 0x2eae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eb3:
	/* 0x2eb3: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2eb7:
	/* 0x2eb7: jmp    2e91 <cwd_read_v61+0x173> */
	goto x86_l_2e91;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10324U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1844ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1847ULL && __x86_pc <= 3689ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3691ULL && __x86_pc <= 5573ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5577ULL && __x86_pc <= 7375ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7378ULL && __x86_pc <= 9054ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9057ULL && __x86_pc <= 10821ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10827ULL && __x86_pc <= 11959ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

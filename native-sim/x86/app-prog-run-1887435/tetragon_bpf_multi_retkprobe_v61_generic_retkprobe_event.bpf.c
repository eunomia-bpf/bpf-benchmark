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

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_0(
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
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 85ULL: goto x86_l_55;
	case 92ULL: goto x86_l_5c;
	case 99ULL: goto x86_l_63;
	case 104ULL: goto x86_l_68;
	case 111ULL: goto x86_l_6f;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 122ULL: goto x86_l_7a;
	case 125ULL: goto x86_l_7d;
	case 127ULL: goto x86_l_7f;
	case 131ULL: goto x86_l_83;
	case 136ULL: goto x86_l_88;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 144ULL: goto x86_l_90;
	case 148ULL: goto x86_l_94;
	case 152ULL: goto x86_l_98;
	case 157ULL: goto x86_l_9d;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 167ULL: goto x86_l_a7;
	case 171ULL: goto x86_l_ab;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 186ULL: goto x86_l_ba;
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 200ULL: goto x86_l_c8;
	case 203ULL: goto x86_l_cb;
	case 209ULL: goto x86_l_d1;
	case 217ULL: goto x86_l_d9;
	case 220ULL: goto x86_l_dc;
	case 224ULL: goto x86_l_e0;
	case 232ULL: goto x86_l_e8;
	case 236ULL: goto x86_l_ec;
	case 241ULL: goto x86_l_f1;
	case 248ULL: goto x86_l_f8;
	case 253ULL: goto x86_l_fd;
	case 255ULL: goto x86_l_ff;
	case 262ULL: goto x86_l_106;
	case 266ULL: goto x86_l_10a;
	case 270ULL: goto x86_l_10e;
	case 273ULL: goto x86_l_111;
	case 278ULL: goto x86_l_116;
	case 283ULL: goto x86_l_11b;
	case 289ULL: goto x86_l_121;
	case 300ULL: goto x86_l_12c;
	case 308ULL: goto x86_l_134;
	case 319ULL: goto x86_l_13f;
	case 324ULL: goto x86_l_144;
	case 331ULL: goto x86_l_14b;
	case 339ULL: goto x86_l_153;
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 350ULL: goto x86_l_15e;
	case 356ULL: goto x86_l_164;
	case 362ULL: goto x86_l_16a;
	case 373ULL: goto x86_l_175;
	case 379ULL: goto x86_l_17b;
	case 381ULL: goto x86_l_17d;
	case 387ULL: goto x86_l_183;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 408ULL: goto x86_l_198;
	case 412ULL: goto x86_l_19c;
	case 416ULL: goto x86_l_1a0;
	case 424ULL: goto x86_l_1a8;
	case 430ULL: goto x86_l_1ae;
	case 434ULL: goto x86_l_1b2;
	case 440ULL: goto x86_l_1b8;
	case 444ULL: goto x86_l_1bc;
	case 450ULL: goto x86_l_1c2;
	case 454ULL: goto x86_l_1c6;
	case 460ULL: goto x86_l_1cc;
	case 465ULL: goto x86_l_1d1;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 480ULL: goto x86_l_1e0;
	case 482ULL: goto x86_l_1e2;
	case 487ULL: goto x86_l_1e7;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 503ULL: goto x86_l_1f7;
	case 510ULL: goto x86_l_1fe;
	case 513ULL: goto x86_l_201;
	case 519ULL: goto x86_l_207;
	case 527ULL: goto x86_l_20f;
	case 530ULL: goto x86_l_212;
	case 534ULL: goto x86_l_216;
	case 542ULL: goto x86_l_21e;
	case 545ULL: goto x86_l_221;
	case 551ULL: goto x86_l_227;
	case 554ULL: goto x86_l_22a;
	case 562ULL: goto x86_l_232;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 591ULL: goto x86_l_24f;
	case 593ULL: goto x86_l_251;
	case 598ULL: goto x86_l_256;
	case 600ULL: goto x86_l_258;
	case 606ULL: goto x86_l_25e;
	case 611ULL: goto x86_l_263;
	case 614ULL: goto x86_l_266;
	case 617ULL: goto x86_l_269;
	case 620ULL: goto x86_l_26c;
	case 624ULL: goto x86_l_270;
	case 627ULL: goto x86_l_273;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 643ULL: goto x86_l_283;
	case 649ULL: goto x86_l_289;
	case 653ULL: goto x86_l_28d;
	case 657ULL: goto x86_l_291;
	case 661ULL: goto x86_l_295;
	case 666ULL: goto x86_l_29a;
	case 671ULL: goto x86_l_29f;
	case 674ULL: goto x86_l_2a2;
	case 676ULL: goto x86_l_2a4;
	case 681ULL: goto x86_l_2a9;
	case 683ULL: goto x86_l_2ab;
	case 689ULL: goto x86_l_2b1;
	case 692ULL: goto x86_l_2b4;
	case 695ULL: goto x86_l_2b7;
	case 701ULL: goto x86_l_2bd;
	case 704ULL: goto x86_l_2c0;
	case 709ULL: goto x86_l_2c5;
	case 715ULL: goto x86_l_2cb;
	case 717ULL: goto x86_l_2cd;
	case 720ULL: goto x86_l_2d0;
	case 725ULL: goto x86_l_2d5;
	case 730ULL: goto x86_l_2da;
	case 734ULL: goto x86_l_2de;
	case 738ULL: goto x86_l_2e2;
	case 741ULL: goto x86_l_2e5;
	case 747ULL: goto x86_l_2eb;
	case 750ULL: goto x86_l_2ee;
	case 756ULL: goto x86_l_2f4;
	case 761ULL: goto x86_l_2f9;
	case 765ULL: goto x86_l_2fd;
	case 770ULL: goto x86_l_302;
	case 774ULL: goto x86_l_306;
	case 779ULL: goto x86_l_30b;
	case 784ULL: goto x86_l_310;
	case 789ULL: goto x86_l_315;
	case 796ULL: goto x86_l_31c;
	case 804ULL: goto x86_l_324;
	case 809ULL: goto x86_l_329;
	case 811ULL: goto x86_l_32b;
	case 813ULL: goto x86_l_32d;
	case 818ULL: goto x86_l_332;
	case 821ULL: goto x86_l_335;
	case 825ULL: goto x86_l_339;
	case 830ULL: goto x86_l_33e;
	case 834ULL: goto x86_l_342;
	case 837ULL: goto x86_l_345;
	case 842ULL: goto x86_l_34a;
	case 846ULL: goto x86_l_34e;
	case 852ULL: goto x86_l_354;
	case 856ULL: goto x86_l_358;
	case 862ULL: goto x86_l_35e;
	case 867ULL: goto x86_l_363;
	case 872ULL: goto x86_l_368;
	case 877ULL: goto x86_l_36d;
	case 879ULL: goto x86_l_36f;
	case 891ULL: goto x86_l_37b;
	case 899ULL: goto x86_l_383;
	case 907ULL: goto x86_l_38b;
	case 909ULL: goto x86_l_38d;
	case 913ULL: goto x86_l_391;
	case 918ULL: goto x86_l_396;
	case 923ULL: goto x86_l_39b;
	case 928ULL: goto x86_l_3a0;
	case 933ULL: goto x86_l_3a5;
	case 938ULL: goto x86_l_3aa;
	case 940ULL: goto x86_l_3ac;
	case 945ULL: goto x86_l_3b1;
	case 949ULL: goto x86_l_3b5;
	case 954ULL: goto x86_l_3ba;
	case 965ULL: goto x86_l_3c5;
	case 970ULL: goto x86_l_3ca;
	case 977ULL: goto x86_l_3d1;
	case 985ULL: goto x86_l_3d9;
	case 987ULL: goto x86_l_3db;
	case 990ULL: goto x86_l_3de;
	case 996ULL: goto x86_l_3e4;
	case 999ULL: goto x86_l_3e7;
	case 1003ULL: goto x86_l_3eb;
	case 1010ULL: goto x86_l_3f2;
	case 1015ULL: goto x86_l_3f7;
	case 1017ULL: goto x86_l_3f9;
	case 1024ULL: goto x86_l_400;
	case 1029ULL: goto x86_l_405;
	case 1037ULL: goto x86_l_40d;
	case 1042ULL: goto x86_l_412;
	case 1044ULL: goto x86_l_414;
	case 1052ULL: goto x86_l_41c;
	case 1056ULL: goto x86_l_420;
	case 1064ULL: goto x86_l_428;
	case 1069ULL: goto x86_l_42d;
	case 1073ULL: goto x86_l_431;
	case 1078ULL: goto x86_l_436;
	case 1086ULL: goto x86_l_43e;
	case 1091ULL: goto x86_l_443;
	case 1096ULL: goto x86_l_448;
	case 1098ULL: goto x86_l_44a;
	case 1106ULL: goto x86_l_452;
	case 1110ULL: goto x86_l_456;
	case 1115ULL: goto x86_l_45b;
	case 1120ULL: goto x86_l_460;
	case 1125ULL: goto x86_l_465;
	case 1127ULL: goto x86_l_467;
	case 1133ULL: goto x86_l_46d;
	case 1138ULL: goto x86_l_472;
	case 1140ULL: goto x86_l_474;
	case 1144ULL: goto x86_l_478;
	case 1149ULL: goto x86_l_47d;
	case 1154ULL: goto x86_l_482;
	case 1159ULL: goto x86_l_487;
	case 1161ULL: goto x86_l_489;
	case 1166ULL: goto x86_l_48e;
	case 1168ULL: goto x86_l_490;
	case 1171ULL: goto x86_l_493;
	case 1178ULL: goto x86_l_49a;
	case 1188ULL: goto x86_l_4a4;
	case 1196ULL: goto x86_l_4ac;
	case 1207ULL: goto x86_l_4b7;
	case 1212ULL: goto x86_l_4bc;
	case 1221ULL: goto x86_l_4c5;
	case 1230ULL: goto x86_l_4ce;
	case 1235ULL: goto x86_l_4d3;
	case 1240ULL: goto x86_l_4d8;
	case 1245ULL: goto x86_l_4dd;
	case 1254ULL: goto x86_l_4e6;
	case 1263ULL: goto x86_l_4ef;
	case 1272ULL: goto x86_l_4f8;
	case 1280ULL: goto x86_l_500;
	case 1285ULL: goto x86_l_505;
	case 1292ULL: goto x86_l_50c;
	case 1297ULL: goto x86_l_511;
	case 1305ULL: goto x86_l_519;
	case 1309ULL: goto x86_l_51d;
	case 1314ULL: goto x86_l_522;
	case 1319ULL: goto x86_l_527;
	case 1324ULL: goto x86_l_52c;
	case 1327ULL: goto x86_l_52f;
	case 1329ULL: goto x86_l_531;
	case 1334ULL: goto x86_l_536;
	case 1337ULL: goto x86_l_539;
	case 1342ULL: goto x86_l_53e;
	case 1350ULL: goto x86_l_546;
	case 1352ULL: goto x86_l_548;
	case 1357ULL: goto x86_l_54d;
	case 1360ULL: goto x86_l_550;
	case 1363ULL: goto x86_l_553;
	case 1368ULL: goto x86_l_558;
	case 1373ULL: goto x86_l_55d;
	case 1375ULL: goto x86_l_55f;
	case 1380ULL: goto x86_l_564;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1393ULL: goto x86_l_571;
	case 1395ULL: goto x86_l_573;
	case 1400ULL: goto x86_l_578;
	case 1404ULL: goto x86_l_57c;
	case 1409ULL: goto x86_l_581;
	case 1416ULL: goto x86_l_588;
	case 1419ULL: goto x86_l_58b;
	case 1425ULL: goto x86_l_591;
	case 1430ULL: goto x86_l_596;
	case 1435ULL: goto x86_l_59b;
	case 1440ULL: goto x86_l_5a0;
	case 1445ULL: goto x86_l_5a5;
	case 1450ULL: goto x86_l_5aa;
	case 1455ULL: goto x86_l_5af;
	case 1457ULL: goto x86_l_5b1;
	case 1462ULL: goto x86_l_5b6;
	case 1468ULL: goto x86_l_5bc;
	case 1473ULL: goto x86_l_5c1;
	case 1481ULL: goto x86_l_5c9;
	case 1486ULL: goto x86_l_5ce;
	case 1488ULL: goto x86_l_5d0;
	case 1496ULL: goto x86_l_5d8;
	case 1502ULL: goto x86_l_5de;
	case 1506ULL: goto x86_l_5e2;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1521ULL: goto x86_l_5f1;
	case 1524ULL: goto x86_l_5f4;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1537ULL: goto x86_l_601;
	case 1542ULL: goto x86_l_606;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1558ULL: goto x86_l_616;
	case 1560ULL: goto x86_l_618;
	case 1564ULL: goto x86_l_61c;
	case 1569ULL: goto x86_l_621;
	case 1574ULL: goto x86_l_626;
	case 1579ULL: goto x86_l_62b;
	case 1582ULL: goto x86_l_62e;
	case 1584ULL: goto x86_l_630;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1598ULL: goto x86_l_63e;
	case 1601ULL: goto x86_l_641;
	case 1608ULL: goto x86_l_648;
	case 1610ULL: goto x86_l_64a;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1628ULL: goto x86_l_65c;
	case 1630ULL: goto x86_l_65e;
	case 1634ULL: goto x86_l_662;
	case 1636ULL: goto x86_l_664;
	case 1639ULL: goto x86_l_667;
	case 1642ULL: goto x86_l_66a;
	case 1645ULL: goto x86_l_66d;
	case 1648ULL: goto x86_l_670;
	case 1656ULL: goto x86_l_678;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1670ULL: goto x86_l_686;
	case 1676ULL: goto x86_l_68c;
	case 1682ULL: goto x86_l_692;
	case 1684ULL: goto x86_l_694;
	case 1690ULL: goto x86_l_69a;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1703ULL: goto x86_l_6a7;
	case 1707ULL: goto x86_l_6ab;
	case 1710ULL: goto x86_l_6ae;
	case 1715ULL: goto x86_l_6b3;
	case 1717ULL: goto x86_l_6b5;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1735ULL: goto x86_l_6c7;
	case 1740ULL: goto x86_l_6cc;
	case 1742ULL: goto x86_l_6ce;
	case 1748ULL: goto x86_l_6d4;
	case 1753ULL: goto x86_l_6d9;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1775ULL: goto x86_l_6ef;
	case 1780ULL: goto x86_l_6f4;
	case 1785ULL: goto x86_l_6f9;
	case 1791ULL: goto x86_l_6ff;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1811ULL: goto x86_l_713;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1827ULL: goto x86_l_723;
	case 1832ULL: goto x86_l_728;
	case 1837ULL: goto x86_l_72d;
	case 1839ULL: goto x86_l_72f;
	case 1845ULL: goto x86_l_735;
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
	/* 0x3f: je     2d2f <generic_retkprobe_event+0x2d2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11567ULL;
	}
x86_l_45:
	/* 0x45: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_48:
	/* 0x48: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4b:
	/* 0x4b: mov    eax,0xae */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 174ULL);
x86_l_50:
	/* 0x50: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55:
	/* 0x55: lea    rsi,[r15+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_5c:
	/* 0x5c: mov    DWORD PTR [r15+0x5ef8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_63:
	/* 0x63: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_68:
	/* 0x68: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_6f:
	/* 0x6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71:
	/* 0x71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_74:
	/* 0x74: je     2d2f <generic_retkprobe_event+0x2d2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11567ULL;
	}
x86_l_7a:
	/* 0x7a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_7d:
	/* 0x7d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f:
	/* 0x7f: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_83:
	/* 0x83: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_88:
	/* 0x88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a:
	/* 0x8a: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_8e:
	/* 0x8e: jne    94 <generic_retkprobe_event+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_94;
	}
x86_l_90:
	/* 0x90: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_94:
	/* 0x94: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_98:
	/* 0x98: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_9d:
	/* 0x9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f:
	/* 0x9f: mov    DWORD PTR [r14+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_a3:
	/* 0xa3: mov    rax,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a7:
	/* 0xa7: mov    rcx,QWORD PTR [r14+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ab:
	/* 0xab: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b0:
	/* 0xb0: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b5:
	/* 0xb5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ba:
	/* 0xba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_c1:
	/* 0xc1: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c6:
	/* 0xc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8:
	/* 0xc8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cb:
	/* 0xcb: je     2d2f <generic_retkprobe_event+0x2d2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11567ULL;
	}
x86_l_d1:
	/* 0xd1: mov    QWORD PTR [rsp+0xe0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_d9:
	/* 0xd9: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dc:
	/* 0xdc: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e0:
	/* 0xe0: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e8:
	/* 0xe8: mov    rbp,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec:
	/* 0xec: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f1:
	/* 0xf1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_f8:
	/* 0xf8: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fd:
	/* 0xfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff:
	/* 0xff: mov    QWORD PTR [r14+0x90],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_106:
	/* 0x106: mov    ebx,DWORD PTR [r13+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10a:
	/* 0x10a: mov    r12d,DWORD PTR [r13+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_10e:
	/* 0x10e: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_111:
	/* 0x111: mov    QWORD PTR [rsp+0x30],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_116:
	/* 0x116: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11b:
	/* 0x11b: je     1f1 <generic_retkprobe_event+0x1f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f1;
	}
x86_l_121:
	/* 0x121: mov    DWORD PTR [r14+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_12c:
	/* 0x12c: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_134:
	/* 0x134: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_13f:
	/* 0x13f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_144:
	/* 0x144: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_14b:
	/* 0x14b: lea    rsi,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_153:
	/* 0x153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155:
	/* 0x155: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_158:
	/* 0x158: je     2cd <generic_retkprobe_event+0x2cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cd;
	}
x86_l_15e:
	/* 0x15e: mov    ecx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_164:
	/* 0x164: mov    DWORD PTR [rax+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16a:
	/* 0x16a: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_175:
	/* 0x175: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_17b:
	/* 0x17b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_17d:
	/* 0x17d: jne    2d0 <generic_retkprobe_event+0x2d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d0;
	}
x86_l_183:
	/* 0x183: lea    rcx,[rax+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_18a:
	/* 0x18a: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_198:
	/* 0x198: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_19c:
	/* 0x19c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a0:
	/* 0x1a0: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a8:
	/* 0x1a8: jle    34a <generic_retkprobe_event+0x34a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_34a;
	}
x86_l_1ae:
	/* 0x1ae: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_1b2:
	/* 0x1b2: je     36f <generic_retkprobe_event+0x36f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36f;
	}
x86_l_1b8:
	/* 0x1b8: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_1bc:
	/* 0x1bc: je     38d <generic_retkprobe_event+0x38d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38d;
	}
x86_l_1c2:
	/* 0x1c2: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_1c6:
	/* 0x1c6: jne    824 <generic_retkprobe_event+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_1cc:
	/* 0x1cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d1:
	/* 0x1d1: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d6:
	/* 0x1d6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1db:
	/* 0x1db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e0:
	/* 0x1e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e2:
	/* 0x1e2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e7:
	/* 0x1e7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ec:
	/* 0x1ec: jmp    35e <generic_retkprobe_event+0x35e> */
	goto x86_l_35e;
x86_l_1f1:
	/* 0x1f1: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_1f7:
	/* 0x1f7: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1fe:
	/* 0x1fe: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_201:
	/* 0x201: jne    afe <generic_retkprobe_event+0xafe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2814ULL;
	}
x86_l_207:
	/* 0x207: mov    DWORD PTR [r15+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_20f:
	/* 0x20f: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_212:
	/* 0x212: lea    rbp,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_216:
	/* 0x216: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_21e:
	/* 0x21e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_221:
	/* 0x221: je     332 <generic_retkprobe_event+0x332> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_332;
	}
x86_l_227:
	/* 0x227: mov    rbx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R14, X86_WIDTH_64);
x86_l_22a:
	/* 0x22a: mov    r14,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_232:
	/* 0x232: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_238:
	/* 0x238: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23d:
	/* 0x23d: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_242:
	/* 0x242: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_247:
	/* 0x247: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_24f:
	/* 0x24f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251:
	/* 0x251: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_256:
	/* 0x256: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_258:
	/* 0x258: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_25e:
	/* 0x25e: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_263:
	/* 0x263: cmp    rsi,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_266:
	/* 0x266: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_269:
	/* 0x269: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_26c:
	/* 0x26c: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_270:
	/* 0x270: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_273:
	/* 0x273: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_277:
	/* 0x277: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_27c:
	/* 0x27c: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_283:
	/* 0x283: ja     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10988ULL;
	}
x86_l_289:
	/* 0x289: add    rbx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_28d:
	/* 0x28d: mov    QWORD PTR [rsp],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_291:
	/* 0x291: lea    rdi,[r15+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_295:
	/* 0x295: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29a:
	/* 0x29a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29f:
	/* 0x29f: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2a2:
	/* 0x2a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4:
	/* 0x2a4: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a9:
	/* 0x2a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ab:
	/* 0x2ab: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_2b1:
	/* 0x2b1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2b4:
	/* 0x2b4: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_2b7:
	/* 0x2b7: je     8d7 <generic_retkprobe_event+0x8d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2263ULL;
	}
x86_l_2bd:
	/* 0x2bd: sub    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2c0:
	/* 0x2c0: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c5:
	/* 0x2c5: jne    8de <generic_retkprobe_event+0x8de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2270ULL;
	}
x86_l_2cb:
	/* 0x2cb: jmp    335 <generic_retkprobe_event+0x335> */
	goto x86_l_335;
x86_l_2cd:
	/* 0x2cd: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d0:
	/* 0x2d0: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d5:
	/* 0x2d5: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2da:
	/* 0x2da: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2de:
	/* 0x2de: mov    eax,DWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e2:
	/* 0x2e2: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2e5:
	/* 0x2e5: je     ad1 <generic_retkprobe_event+0xad1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2769ULL;
	}
x86_l_2eb:
	/* 0x2eb: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2ee:
	/* 0x2ee: jne    ae7 <generic_retkprobe_event+0xae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2791ULL;
	}
x86_l_2f4:
	/* 0x2f4: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f9:
	/* 0x2f9: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2fd:
	/* 0x2fd: mov    eax,DWORD PTR [r12+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_302:
	/* 0x302: mov    DWORD PTR [rsp+0x4c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_306:
	/* 0x306: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30b:
	/* 0x30b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_310:
	/* 0x310: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_315:
	/* 0x315: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_31c:
	/* 0x31c: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_324:
	/* 0x324: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_329:
	/* 0x329: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32b:
	/* 0x32b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d:
	/* 0x32d: jmp    ae7 <generic_retkprobe_event+0xae7> */
	return 2791ULL;
x86_l_332:
	/* 0x332: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_335:
	/* 0x335: mov    DWORD PTR [r15+rbp*1],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_339:
	/* 0x339: mov    DWORD PTR [r15+rbp*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_33e:
	/* 0x33e: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_342:
	/* 0x342: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_345:
	/* 0x345: jmp    2af0 <generic_retkprobe_event+0x2af0> */
	return 10992ULL;
x86_l_34a:
	/* 0x34a: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_34e:
	/* 0x34e: je     76a <generic_retkprobe_event+0x76a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1898ULL;
	}
x86_l_354:
	/* 0x354: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_358:
	/* 0x358: jne    824 <generic_retkprobe_event+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_35e:
	/* 0x35e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_363:
	/* 0x363: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_368:
	/* 0x368: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_36d:
	/* 0x36d: jmp    3a5 <generic_retkprobe_event+0x3a5> */
	goto x86_l_3a5;
x86_l_36f:
	/* 0x36f: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_37b:
	/* 0x37b: mov    QWORD PTR [rsp+0x98],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_383:
	/* 0x383: lea    rax,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_38b:
	/* 0x38b: jmp    3b5 <generic_retkprobe_event+0x3b5> */
	goto x86_l_3b5;
x86_l_38d:
	/* 0x38d: add    r13,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_391:
	/* 0x391: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_396:
	/* 0x396: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39b:
	/* 0x39b: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3a0:
	/* 0x3a0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a5:
	/* 0x3a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aa:
	/* 0x3aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac:
	/* 0x3ac: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b1:
	/* 0x3b1: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_3b5:
	/* 0x3b5: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ba:
	/* 0x3ba: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_3c5:
	/* 0x3c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ca:
	/* 0x3ca: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_3d1:
	/* 0x3d1: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_3d9:
	/* 0x3d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3db:
	/* 0x3db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3de:
	/* 0x3de: je     73a <generic_retkprobe_event+0x73a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1850ULL;
	}
x86_l_3e4:
	/* 0x3e4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3e7:
	/* 0x3e7: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3eb:
	/* 0x3eb: lea    r14,[rax+0x1000] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_3f2:
	/* 0x3f2: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_3f7:
	/* 0x3f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f9:
	/* 0x3f9: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_400:
	/* 0x400: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_405:
	/* 0x405: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_40d:
	/* 0x40d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_412:
	/* 0x412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_414:
	/* 0x414: mov    r13,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_41c:
	/* 0x41c: lea    rax,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_420:
	/* 0x420: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_428:
	/* 0x428: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42d:
	/* 0x42d: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_431:
	/* 0x431: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_436:
	/* 0x436: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_43e:
	/* 0x43e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_443:
	/* 0x443: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_448:
	/* 0x448: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44a:
	/* 0x44a: mov    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_452:
	/* 0x452: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_456:
	/* 0x456: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45b:
	/* 0x45b: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_460:
	/* 0x460: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_465:
	/* 0x465: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_467:
	/* 0x467: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_46d:
	/* 0x46d: mov    ebx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4096ULL);
x86_l_472:
	/* 0x472: jne    4bc <generic_retkprobe_event+0x4bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4bc;
	}
x86_l_474:
	/* 0x474: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_478:
	/* 0x478: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_47d:
	/* 0x47d: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_482:
	/* 0x482: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_487:
	/* 0x487: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489:
	/* 0x489: cmp    QWORD PTR [rsp+0x48],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_48e:
	/* 0x48e: je     4bc <generic_retkprobe_event+0x4bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc;
	}
x86_l_490:
	/* 0x490: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_493:
	/* 0x493: add    r14,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_49a:
	/* 0x49a: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_4a4:
	/* 0x4a4: mov    QWORD PTR [r12+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_4ac:
	/* 0x4ac: mov    WORD PTR [r12+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_4b7:
	/* 0x4b7: mov    ebx,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4086ULL);
x86_l_4bc:
	/* 0x4bc: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4c5:
	/* 0x4c5: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4ce:
	/* 0x4ce: mov    QWORD PTR [rsp+0x58],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4d3:
	/* 0x4d3: lea    r12,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d8:
	/* 0x4d8: lea    rbp,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4dd:
	/* 0x4dd: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4e6:
	/* 0x4e6: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4ef:
	/* 0x4ef: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4f8:
	/* 0x4f8: mov    QWORD PTR [rsp+0xf0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_500:
	/* 0x500: mov    QWORD PTR [rsp+0x78],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_505:
	/* 0x505: mov    DWORD PTR [rsp+0x80],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_50c:
	/* 0x50c: lea    rbx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_511:
	/* 0x511: mov    BYTE PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_519:
	/* 0x519: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_51d:
	/* 0x51d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_522:
	/* 0x522: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_527:
	/* 0x527: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52c:
	/* 0x52c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_52f:
	/* 0x52f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_531:
	/* 0x531: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_536:
	/* 0x536: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_539:
	/* 0x539: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53e:
	/* 0x53e: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_546:
	/* 0x546: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_548:
	/* 0x548: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_54d:
	/* 0x54d: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_550:
	/* 0x550: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_553:
	/* 0x553: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_558:
	/* 0x558: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55d:
	/* 0x55d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55f:
	/* 0x55f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_564:
	/* 0x564: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_567:
	/* 0x567: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56c:
	/* 0x56c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_571:
	/* 0x571: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_573:
	/* 0x573: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_578:
	/* 0x578: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_57c:
	/* 0x57c: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_581:
	/* 0x581: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_588:
	/* 0x588: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58b:
	/* 0x58b: je     74b <generic_retkprobe_event+0x74b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1867ULL;
	}
x86_l_591:
	/* 0x591: mov    ebx,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2048ULL);
x86_l_596:
	/* 0x596: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_59b:
	/* 0x59b: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5a0:
	/* 0x5a0: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5a5:
	/* 0x5a5: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5aa:
	/* 0x5aa: cmp    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_5af:
	/* 0x5af: jne    5bc <generic_retkprobe_event+0x5bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5bc;
	}
x86_l_5b1:
	/* 0x5b1: cmp    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 80ULL);
x86_l_5b6:
	/* 0x5b6: je     8ca <generic_retkprobe_event+0x8ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2250ULL;
	}
x86_l_5bc:
	/* 0x5bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5c1:
	/* 0x5c1: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5c9:
	/* 0x5c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ce:
	/* 0x5ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d0:
	/* 0x5d0: cmp    rbp,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 176ULL);
x86_l_5d8:
	/* 0x5d8: je     6d9 <generic_retkprobe_event+0x6d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6d9;
	}
x86_l_5de:
	/* 0x5de: lea    r13,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e2:
	/* 0x5e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e7:
	/* 0x5e7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ec:
	/* 0x5ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f1:
	/* 0x5f1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5f4:
	/* 0x5f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f6:
	/* 0x5f6: cmp    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5fb:
	/* 0x5fb: je     6d9 <generic_retkprobe_event+0x6d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6d9;
	}
x86_l_601:
	/* 0x601: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_606:
	/* 0x606: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_60e:
	/* 0x60e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_613:
	/* 0x613: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_616:
	/* 0x616: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_618:
	/* 0x618: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_61c:
	/* 0x61c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_621:
	/* 0x621: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_626:
	/* 0x626: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_62b:
	/* 0x62b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_62e:
	/* 0x62e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_630:
	/* 0x630: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_635:
	/* 0x635: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_63a:
	/* 0x63a: mov    ecx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_63e:
	/* 0x63e: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_641:
	/* 0x641: mov    esi,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_648:
	/* 0x648: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_64a:
	/* 0x64a: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_64c:
	/* 0x64c: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_651:
	/* 0x651: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_654:
	/* 0x654: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_659:
	/* 0x659: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65c:
	/* 0x65c: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_65e:
	/* 0x65e: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_662:
	/* 0x662: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_664:
	/* 0x664: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_667:
	/* 0x667: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_66a:
	/* 0x66a: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_66d:
	/* 0x66d: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_670:
	/* 0x670: mov    DWORD PTR [rsp+0x80],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_678:
	/* 0x678: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_67b:
	/* 0x67b: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_680:
	/* 0x680: jb     9a8 <generic_retkprobe_event+0x9a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2472ULL;
	}
x86_l_686:
	/* 0x686: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_68c:
	/* 0x68c: ja     9a8 <generic_retkprobe_event+0x9a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2472ULL;
	}
x86_l_692:
	/* 0x692: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_694:
	/* 0x694: jbe    cca <generic_retkprobe_event+0xcca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3274ULL;
	}
x86_l_69a:
	/* 0x69a: lea    r13,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_69e:
	/* 0x69e: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_6a3:
	/* 0x6a3: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6a7:
	/* 0x6a7: lea    rdi,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6ab:
	/* 0x6ab: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6ae:
	/* 0x6ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b3:
	/* 0x6b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b5:
	/* 0x6b5: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6ba:
	/* 0x6ba: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6bf:
	/* 0x6bf: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_6c7:
	/* 0x6c7: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6cc:
	/* 0x6cc: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_6ce:
	/* 0x6ce: jne    59b <generic_retkprobe_event+0x59b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_59b;
	}
x86_l_6d4:
	/* 0x6d4: jmp    9a8 <generic_retkprobe_event+0x9a8> */
	return 2472ULL;
x86_l_6d9:
	/* 0x6d9: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6de:
	/* 0x6de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6e3:
	/* 0x6e3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e8:
	/* 0x6e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ed:
	/* 0x6ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ef:
	/* 0x6ef: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6f4:
	/* 0x6f4: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6f9:
	/* 0x6f9: je     99b <generic_retkprobe_event+0x99b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2459ULL;
	}
x86_l_6ff:
	/* 0x6ff: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_703:
	/* 0x703: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_708:
	/* 0x708: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_70b:
	/* 0x70b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_710:
	/* 0x710: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_713:
	/* 0x713: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_715:
	/* 0x715: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_71a:
	/* 0x71a: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_71f:
	/* 0x71f: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_723:
	/* 0x723: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_728:
	/* 0x728: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_72d:
	/* 0x72d: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_72f:
	/* 0x72f: jne    59b <generic_retkprobe_event+0x59b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_59b;
	}
x86_l_735:
	/* 0x735: jmp    9a8 <generic_retkprobe_event+0x9a8> */
	return 2472ULL;
	return 1850ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1850ULL: goto x86_l_73a;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1872ULL: goto x86_l_750;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1891ULL: goto x86_l_763;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1903ULL: goto x86_l_76f;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1923ULL: goto x86_l_783;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1938ULL: goto x86_l_792;
	case 1944ULL: goto x86_l_798;
	case 1955ULL: goto x86_l_7a3;
	case 1960ULL: goto x86_l_7a8;
	case 1967ULL: goto x86_l_7af;
	case 1975ULL: goto x86_l_7b7;
	case 1977ULL: goto x86_l_7b9;
	case 1979ULL: goto x86_l_7bb;
	case 1982ULL: goto x86_l_7be;
	case 1988ULL: goto x86_l_7c4;
	case 1992ULL: goto x86_l_7c8;
	case 1996ULL: goto x86_l_7cc;
	case 2002ULL: goto x86_l_7d2;
	case 2006ULL: goto x86_l_7d6;
	case 2012ULL: goto x86_l_7dc;
	case 2016ULL: goto x86_l_7e0;
	case 2022ULL: goto x86_l_7e6;
	case 2026ULL: goto x86_l_7ea;
	case 2032ULL: goto x86_l_7f0;
	case 2036ULL: goto x86_l_7f4;
	case 2042ULL: goto x86_l_7fa;
	case 2046ULL: goto x86_l_7fe;
	case 2051ULL: goto x86_l_803;
	case 2057ULL: goto x86_l_809;
	case 2067ULL: goto x86_l_813;
	case 2074ULL: goto x86_l_81a;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2093ULL: goto x86_l_82d;
	case 2099ULL: goto x86_l_833;
	case 2102ULL: goto x86_l_836;
	case 2112ULL: goto x86_l_840;
	case 2116ULL: goto x86_l_844;
	case 2122ULL: goto x86_l_84a;
	case 2127ULL: goto x86_l_84f;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2150ULL: goto x86_l_866;
	case 2158ULL: goto x86_l_86e;
	case 2160ULL: goto x86_l_870;
	case 2162ULL: goto x86_l_872;
	case 2165ULL: goto x86_l_875;
	case 2171ULL: goto x86_l_87b;
	case 2175ULL: goto x86_l_87f;
	case 2180ULL: goto x86_l_884;
	case 2186ULL: goto x86_l_88a;
	case 2190ULL: goto x86_l_88e;
	case 2195ULL: goto x86_l_893;
	case 2201ULL: goto x86_l_899;
	case 2205ULL: goto x86_l_89d;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2219ULL: goto x86_l_8ab;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2258ULL: goto x86_l_8d2;
	case 2263ULL: goto x86_l_8d7;
	case 2265ULL: goto x86_l_8d9;
	case 2270ULL: goto x86_l_8de;
	case 2279ULL: goto x86_l_8e7;
	case 2281ULL: goto x86_l_8e9;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2297ULL: goto x86_l_8f9;
	case 2301ULL: goto x86_l_8fd;
	case 2307ULL: goto x86_l_903;
	case 2312ULL: goto x86_l_908;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2331ULL: goto x86_l_91b;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2376ULL: goto x86_l_948;
	case 2382ULL: goto x86_l_94e;
	case 2386ULL: goto x86_l_952;
	case 2389ULL: goto x86_l_955;
	case 2393ULL: goto x86_l_959;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2410ULL: goto x86_l_96a;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2419ULL: goto x86_l_973;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2436ULL: goto x86_l_984;
	case 2442ULL: goto x86_l_98a;
	case 2445ULL: goto x86_l_98d;
	case 2448ULL: goto x86_l_990;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2467ULL: goto x86_l_9a3;
	case 2472ULL: goto x86_l_9a8;
	case 2477ULL: goto x86_l_9ad;
	case 2485ULL: goto x86_l_9b5;
	case 2487ULL: goto x86_l_9b7;
	case 2490ULL: goto x86_l_9ba;
	case 2492ULL: goto x86_l_9bc;
	case 2500ULL: goto x86_l_9c4;
	case 2503ULL: goto x86_l_9c7;
	case 2510ULL: goto x86_l_9ce;
	case 2515ULL: goto x86_l_9d3;
	case 2517ULL: goto x86_l_9d5;
	case 2519ULL: goto x86_l_9d7;
	case 2522ULL: goto x86_l_9da;
	case 2525ULL: goto x86_l_9dd;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2540ULL: goto x86_l_9ec;
	case 2542ULL: goto x86_l_9ee;
	case 2544ULL: goto x86_l_9f0;
	case 2547ULL: goto x86_l_9f3;
	case 2549ULL: goto x86_l_9f5;
	case 2551ULL: goto x86_l_9f7;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2567ULL: goto x86_l_a07;
	case 2573ULL: goto x86_l_a0d;
	case 2578ULL: goto x86_l_a12;
	case 2580ULL: goto x86_l_a14;
	case 2582ULL: goto x86_l_a16;
	case 2586ULL: goto x86_l_a1a;
	case 2592ULL: goto x86_l_a20;
	case 2597ULL: goto x86_l_a25;
	case 2602ULL: goto x86_l_a2a;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2614ULL: goto x86_l_a36;
	case 2619ULL: goto x86_l_a3b;
	case 2624ULL: goto x86_l_a40;
	case 2628ULL: goto x86_l_a44;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2640ULL: goto x86_l_a50;
	case 2645ULL: goto x86_l_a55;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2662ULL: goto x86_l_a66;
	case 2666ULL: goto x86_l_a6a;
	case 2673ULL: goto x86_l_a71;
	case 2678ULL: goto x86_l_a76;
	case 2686ULL: goto x86_l_a7e;
	case 2689ULL: goto x86_l_a81;
	case 2695ULL: goto x86_l_a87;
	case 2699ULL: goto x86_l_a8b;
	case 2701ULL: goto x86_l_a8d;
	case 2703ULL: goto x86_l_a8f;
	case 2713ULL: goto x86_l_a99;
	case 2723ULL: goto x86_l_aa3;
	case 2725ULL: goto x86_l_aa5;
	case 2727ULL: goto x86_l_aa7;
	case 2731ULL: goto x86_l_aab;
	case 2737ULL: goto x86_l_ab1;
	case 2741ULL: goto x86_l_ab5;
	case 2744ULL: goto x86_l_ab8;
	case 2752ULL: goto x86_l_ac0;
	case 2756ULL: goto x86_l_ac4;
	case 2760ULL: goto x86_l_ac8;
	case 2763ULL: goto x86_l_acb;
	case 2769ULL: goto x86_l_ad1;
	case 2774ULL: goto x86_l_ad6;
	case 2781ULL: goto x86_l_add;
	case 2789ULL: goto x86_l_ae5;
	case 2791ULL: goto x86_l_ae7;
	case 2798ULL: goto x86_l_aee;
	case 2805ULL: goto x86_l_af5;
	case 2808ULL: goto x86_l_af8;
	case 2814ULL: goto x86_l_afe;
	case 2817ULL: goto x86_l_b01;
	case 2823ULL: goto x86_l_b07;
	case 2831ULL: goto x86_l_b0f;
	case 2835ULL: goto x86_l_b13;
	case 2843ULL: goto x86_l_b1b;
	case 2847ULL: goto x86_l_b1f;
	case 2851ULL: goto x86_l_b23;
	case 2858ULL: goto x86_l_b2a;
	case 2864ULL: goto x86_l_b30;
	case 2868ULL: goto x86_l_b34;
	case 2872ULL: goto x86_l_b38;
	case 2876ULL: goto x86_l_b3c;
	case 2882ULL: goto x86_l_b42;
	case 2887ULL: goto x86_l_b47;
	case 2890ULL: goto x86_l_b4a;
	case 2898ULL: goto x86_l_b52;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2907ULL: goto x86_l_b5b;
	case 2909ULL: goto x86_l_b5d;
	case 2913ULL: goto x86_l_b61;
	case 2917ULL: goto x86_l_b65;
	case 2919ULL: goto x86_l_b67;
	case 2922ULL: goto x86_l_b6a;
	case 2925ULL: goto x86_l_b6d;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2938ULL: goto x86_l_b7a;
	case 2944ULL: goto x86_l_b80;
	case 2948ULL: goto x86_l_b84;
	case 2952ULL: goto x86_l_b88;
	case 2958ULL: goto x86_l_b8e;
	case 2962ULL: goto x86_l_b92;
	case 2968ULL: goto x86_l_b98;
	case 2972ULL: goto x86_l_b9c;
	case 2978ULL: goto x86_l_ba2;
	case 2983ULL: goto x86_l_ba7;
	case 2987ULL: goto x86_l_bab;
	case 2993ULL: goto x86_l_bb1;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3009ULL: goto x86_l_bc1;
	case 3016ULL: goto x86_l_bc8;
	case 3021ULL: goto x86_l_bcd;
	case 3026ULL: goto x86_l_bd2;
	case 3031ULL: goto x86_l_bd7;
	case 3034ULL: goto x86_l_bda;
	case 3036ULL: goto x86_l_bdc;
	case 3043ULL: goto x86_l_be3;
	case 3048ULL: goto x86_l_be8;
	case 3053ULL: goto x86_l_bed;
	case 3058ULL: goto x86_l_bf2;
	case 3060ULL: goto x86_l_bf4;
	case 3067ULL: goto x86_l_bfb;
	case 3075ULL: goto x86_l_c03;
	case 3080ULL: goto x86_l_c08;
	case 3085ULL: goto x86_l_c0d;
	case 3087ULL: goto x86_l_c0f;
	case 3094ULL: goto x86_l_c16;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3114ULL: goto x86_l_c2a;
	case 3121ULL: goto x86_l_c31;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3139ULL: goto x86_l_c43;
	case 3141ULL: goto x86_l_c45;
	case 3148ULL: goto x86_l_c4c;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3168ULL: goto x86_l_c60;
	case 3175ULL: goto x86_l_c67;
	case 3180ULL: goto x86_l_c6c;
	case 3187ULL: goto x86_l_c73;
	case 3195ULL: goto x86_l_c7b;
	case 3203ULL: goto x86_l_c83;
	case 3211ULL: goto x86_l_c8b;
	case 3218ULL: goto x86_l_c92;
	case 3221ULL: goto x86_l_c95;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3246ULL: goto x86_l_cae;
	case 3251ULL: goto x86_l_cb3;
	case 3253ULL: goto x86_l_cb5;
	case 3258ULL: goto x86_l_cba;
	case 3261ULL: goto x86_l_cbd;
	case 3266ULL: goto x86_l_cc2;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3278ULL: goto x86_l_cce;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3289ULL: goto x86_l_cd9;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3305ULL: goto x86_l_ce9;
	case 3310ULL: goto x86_l_cee;
	case 3314ULL: goto x86_l_cf2;
	case 3320ULL: goto x86_l_cf8;
	case 3324ULL: goto x86_l_cfc;
	case 3330ULL: goto x86_l_d02;
	case 3334ULL: goto x86_l_d06;
	case 3340ULL: goto x86_l_d0c;
	case 3344ULL: goto x86_l_d10;
	case 3348ULL: goto x86_l_d14;
	case 3354ULL: goto x86_l_d1a;
	case 3359ULL: goto x86_l_d1f;
	case 3364ULL: goto x86_l_d24;
	case 3367ULL: goto x86_l_d27;
	case 3371ULL: goto x86_l_d2b;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3385ULL: goto x86_l_d39;
	case 3391ULL: goto x86_l_d3f;
	case 3395ULL: goto x86_l_d43;
	case 3401ULL: goto x86_l_d49;
	case 3406ULL: goto x86_l_d4e;
	case 3411ULL: goto x86_l_d53;
	case 3416ULL: goto x86_l_d58;
	case 3421ULL: goto x86_l_d5d;
	case 3424ULL: goto x86_l_d60;
	case 3426ULL: goto x86_l_d62;
	case 3431ULL: goto x86_l_d67;
	case 3436ULL: goto x86_l_d6c;
	case 3439ULL: goto x86_l_d6f;
	case 3444ULL: goto x86_l_d74;
	case 3446ULL: goto x86_l_d76;
	case 3450ULL: goto x86_l_d7a;
	case 3455ULL: goto x86_l_d7f;
	case 3458ULL: goto x86_l_d82;
	case 3465ULL: goto x86_l_d89;
	case 3470ULL: goto x86_l_d8e;
	case 3475ULL: goto x86_l_d93;
	case 3477ULL: goto x86_l_d95;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3489ULL: goto x86_l_da1;
	case 3494ULL: goto x86_l_da6;
	case 3498ULL: goto x86_l_daa;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3533ULL: goto x86_l_dcd;
	case 3536ULL: goto x86_l_dd0;
	case 3538ULL: goto x86_l_dd2;
	case 3542ULL: goto x86_l_dd6;
	case 3547ULL: goto x86_l_ddb;
	case 3552ULL: goto x86_l_de0;
	case 3556ULL: goto x86_l_de4;
	case 3562ULL: goto x86_l_dea;
	case 3566ULL: goto x86_l_dee;
	case 3572ULL: goto x86_l_df4;
	case 3576ULL: goto x86_l_df8;
	case 3580ULL: goto x86_l_dfc;
	case 3586ULL: goto x86_l_e02;
	case 3591ULL: goto x86_l_e07;
	case 3596ULL: goto x86_l_e0c;
	case 3601ULL: goto x86_l_e11;
	case 3609ULL: goto x86_l_e19;
	case 3617ULL: goto x86_l_e21;
	case 3625ULL: goto x86_l_e29;
	case 3633ULL: goto x86_l_e31;
	case 3641ULL: goto x86_l_e39;
	case 3649ULL: goto x86_l_e41;
	case 3657ULL: goto x86_l_e49;
	case 3665ULL: goto x86_l_e51;
	case 3673ULL: goto x86_l_e59;
	case 3681ULL: goto x86_l_e61;
	case 3689ULL: goto x86_l_e69;
	case 3697ULL: goto x86_l_e71;
	case 3705ULL: goto x86_l_e79;
	default: return 0xffffffffffffffffULL;
	}
x86_l_73a:
	/* 0x73a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73c:
	/* 0x73c: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_741:
	/* 0x741: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_746:
	/* 0x746: jmp    aab <generic_retkprobe_event+0xaab> */
	goto x86_l_aab;
x86_l_74b:
	/* 0x74b: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_750:
	/* 0x750: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_757:
	/* 0x757: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_75c:
	/* 0x75c: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_761:
	/* 0x761: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_763:
	/* 0x763: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_765:
	/* 0x765: jmp    9a3 <generic_retkprobe_event+0x9a3> */
	goto x86_l_9a3;
x86_l_76a:
	/* 0x76a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_76f:
	/* 0x76f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_774:
	/* 0x774: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_779:
	/* 0x779: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_77e:
	/* 0x77e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_783:
	/* 0x783: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_785:
	/* 0x785: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_78a:
	/* 0x78a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_78f:
	/* 0x78f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_792:
	/* 0x792: jne    3ba <generic_retkprobe_event+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 954ULL;
	}
x86_l_798:
	/* 0x798: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_7a3:
	/* 0x7a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a8:
	/* 0x7a8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_7af:
	/* 0x7af: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7b7:
	/* 0x7b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b9:
	/* 0x7b9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7bb:
	/* 0x7bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7be:
	/* 0x7be: je     ce5 <generic_retkprobe_event+0xce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ce5;
	}
x86_l_7c4:
	/* 0x7c4: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_7c8:
	/* 0x7c8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7cc:
	/* 0x7cc: jg     da6 <generic_retkprobe_event+0xda6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_da6;
	}
x86_l_7d2:
	/* 0x7d2: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_7d6:
	/* 0x7d6: jle    ef8 <generic_retkprobe_event+0xef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3832ULL;
	}
x86_l_7dc:
	/* 0x7dc: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_7e0:
	/* 0x7e0: jle    11f9 <generic_retkprobe_event+0x11f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4601ULL;
	}
x86_l_7e6:
	/* 0x7e6: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_7ea:
	/* 0x7ea: je     1ab8 <generic_retkprobe_event+0x1ab8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6840ULL;
	}
x86_l_7f0:
	/* 0x7f0: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_7f4:
	/* 0x7f4: je     1a35 <generic_retkprobe_event+0x1a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6709ULL;
	}
x86_l_7fa:
	/* 0x7fa: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_7fe:
	/* 0x7fe: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_803:
	/* 0x803: jne    1cac <generic_retkprobe_event+0x1cac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7340ULL;
	}
x86_l_809:
	/* 0x809: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_813:
	/* 0x813: mov    DWORD PTR [rcx+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_81a:
	/* 0x81a: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_81f:
	/* 0x81f: jmp    1cac <generic_retkprobe_event+0x1cac> */
	return 7340ULL;
x86_l_824:
	/* 0x824: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_829:
	/* 0x829: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_82d:
	/* 0x82d: ja     798 <generic_retkprobe_event+0x798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_798;
	}
x86_l_833:
	/* 0x833: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_836:
	/* 0x836: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_840:
	/* 0x840: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_844:
	/* 0x844: jae    798 <generic_retkprobe_event+0x798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_798;
	}
x86_l_84a:
	/* 0x84a: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_84f:
	/* 0x84f: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_85a:
	/* 0x85a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_85f:
	/* 0x85f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_866:
	/* 0x866: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_86e:
	/* 0x86e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_870:
	/* 0x870: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_872:
	/* 0x872: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_875:
	/* 0x875: je     201d <generic_retkprobe_event+0x201d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8221ULL;
	}
x86_l_87b:
	/* 0x87b: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_87f:
	/* 0x87f: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_884:
	/* 0x884: jle    b76 <generic_retkprobe_event+0xb76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b76;
	}
x86_l_88a:
	/* 0x88a: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_88e:
	/* 0x88e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_893:
	/* 0x893: jle    cee <generic_retkprobe_event+0xcee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_cee;
	}
x86_l_899:
	/* 0x899: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_89d:
	/* 0x89d: jg     de0 <generic_retkprobe_event+0xde0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_de0;
	}
x86_l_8a3:
	/* 0x8a3: lea    eax,[r12-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_8a8:
	/* 0x8a8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8ab:
	/* 0x8ab: jae    12bc <generic_retkprobe_event+0x12bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4796ULL;
	}
x86_l_8b1:
	/* 0x8b1: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_8b6:
	/* 0x8b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8bb:
	/* 0x8bb: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c0:
	/* 0x8c0: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_8c5:
	/* 0x8c5: jmp    f98 <generic_retkprobe_event+0xf98> */
	return 3992ULL;
x86_l_8ca:
	/* 0x8ca: mov    BYTE PTR [rsp+0x84],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 566935683073ULL);
x86_l_8d2:
	/* 0x8d2: jmp    9a8 <generic_retkprobe_event+0x9a8> */
	goto x86_l_9a8;
x86_l_8d7:
	/* 0x8d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d9:
	/* 0x8d9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8de:
	/* 0x8de: cmp    QWORD PTR [rsp+0x88],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552257ULL);
x86_l_8e7:
	/* 0x8e7: jne    8f1 <generic_retkprobe_event+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8f1;
	}
x86_l_8e9:
	/* 0x8e9: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_8ec:
	/* 0x8ec: jmp    335 <generic_retkprobe_event+0x335> */
	return 821ULL;
x86_l_8f1:
	/* 0x8f1: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8f9:
	/* 0x8f9: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8fd:
	/* 0x8fd: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_903:
	/* 0x903: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_908:
	/* 0x908: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_90d:
	/* 0x90d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_912:
	/* 0x912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_914:
	/* 0x914: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_919:
	/* 0x919: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_91b:
	/* 0x91b: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_921:
	/* 0x921: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_926:
	/* 0x926: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_92b:
	/* 0x92b: cmp    r14,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_92e:
	/* 0x92e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_931:
	/* 0x931: cmovb  r12,r14 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R14, X86_WIDTH_64, X86_CC_B);
x86_l_935:
	/* 0x935: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_938:
	/* 0x938: cmovne r14,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_93c:
	/* 0x93c: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_941:
	/* 0x941: cmp    r14,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4094ULL);
x86_l_948:
	/* 0x948: ja     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10988ULL;
	}
x86_l_94e:
	/* 0x94e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_952:
	/* 0x952: add    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_955:
	/* 0x955: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_959:
	/* 0x959: lea    rdi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_95d:
	/* 0x95d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_962:
	/* 0x962: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_967:
	/* 0x967: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_96a:
	/* 0x96a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96c:
	/* 0x96c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_971:
	/* 0x971: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_973:
	/* 0x973: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_979:
	/* 0x979: add    rbx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_97c:
	/* 0x97c: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_981:
	/* 0x981: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_984:
	/* 0x984: je     1703 <generic_retkprobe_event+0x1703> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5891ULL;
	}
x86_l_98a:
	/* 0x98a: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_98d:
	/* 0x98d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_990:
	/* 0x990: jne    1706 <generic_retkprobe_event+0x1706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5894ULL;
	}
x86_l_996:
	/* 0x996: jmp    2145 <generic_retkprobe_event+0x2145> */
	return 8517ULL;
x86_l_99b:
	/* 0x99b: mov    BYTE PTR [rsp+0x84],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 566935683073ULL);
x86_l_9a3:
	/* 0x9a3: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9a8:
	/* 0x9a8: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9ad:
	/* 0x9ad: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_9b5:
	/* 0x9b5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b7:
	/* 0x9b7: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_9ba:
	/* 0x9ba: je     9f5 <generic_retkprobe_event+0x9f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9f5;
	}
x86_l_9bc:
	/* 0x9bc: cmp    BYTE PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_9c4:
	/* 0x9c4: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_9c7:
	/* 0x9c7: mov    edx,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9ce:
	/* 0x9ce: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_9d3:
	/* 0x9d3: sub    ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9d5:
	/* 0x9d5: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_9d7:
	/* 0x9d7: cmovle ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_9da:
	/* 0x9da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9dd:
	/* 0x9dd: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e1:
	/* 0x9e1: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9e6:
	/* 0x9e6: je     aa5 <generic_retkprobe_event+0xaa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aa5;
	}
x86_l_9ec:
	/* 0x9ec: mov    bl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_8);
x86_l_9ee:
	/* 0x9ee: add    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9f0:
	/* 0x9f0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9f3:
	/* 0x9f3: jmp    a00 <generic_retkprobe_event+0xa00> */
	goto x86_l_a00;
x86_l_9f5:
	/* 0x9f5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f7:
	/* 0x9f7: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9fb:
	/* 0x9fb: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a00:
	/* 0xa00: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_a07:
	/* 0xa07: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a0d:
	/* 0xa0d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a12:
	/* 0xa12: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_a14:
	/* 0xa14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a16:
	/* 0xa16: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1a:
	/* 0xa1a: mov    DWORD PTR [rax+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_a20:
	/* 0xa20: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a25:
	/* 0xa25: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a2a:
	/* 0xa2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a2f:
	/* 0xa2f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a34:
	/* 0xa34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a36:
	/* 0xa36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a3b:
	/* 0xa3b: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a40:
	/* 0xa40: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_a44:
	/* 0xa44: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a49:
	/* 0xa49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a4e:
	/* 0xa4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a50:
	/* 0xa50: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a55:
	/* 0xa55: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a5a:
	/* 0xa5a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a5f:
	/* 0xa5f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_a64:
	/* 0xa64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a66:
	/* 0xa66: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a6a:
	/* 0xa6a: mov    DWORD PTR [rcx+rbp*1+0xa0],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 160ULL);
x86_l_a71:
	/* 0xa71: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_a76:
	/* 0xa76: mov    WORD PTR [rcx+rbp*1+0xa4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_RBP, 0), 164ULL);
x86_l_a7e:
	/* 0xa7e: add    ebp,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_a81:
	/* 0xa81: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_a87:
	/* 0xa87: mov    ebx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a8b:
	/* 0xa8b: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_a8d:
	/* 0xa8d: jns    aab <generic_retkprobe_event+0xaab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_aab;
	}
x86_l_a8f:
	/* 0xa8f: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_a99:
	/* 0xa99: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_aa3:
	/* 0xaa3: jmp    ab8 <generic_retkprobe_event+0xab8> */
	goto x86_l_ab8;
x86_l_aa5:
	/* 0xaa5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa7:
	/* 0xaa7: mov    ebx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_aab:
	/* 0xaab: and    ebp,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_ab1:
	/* 0xab1: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ab5:
	/* 0xab5: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_ab8:
	/* 0xab8: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ac0:
	/* 0xac0: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ac4:
	/* 0xac4: mov    eax,DWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ac8:
	/* 0xac8: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_acb:
	/* 0xacb: jne    2eb <generic_retkprobe_event+0x2eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 747ULL;
	}
x86_l_ad1:
	/* 0xad1: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_ad6:
	/* 0xad6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_add:
	/* 0xadd: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_ae5:
	/* 0xae5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae7:
	/* 0xae7: and    r14d,0x1fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_aee:
	/* 0xaee: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_af5:
	/* 0xaf5: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_af8:
	/* 0xaf8: je     207 <generic_retkprobe_event+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 519ULL;
	}
x86_l_afe:
	/* 0xafe: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_b01:
	/* 0xb01: jne    2afb <generic_retkprobe_event+0x2afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11003ULL;
	}
x86_l_b07:
	/* 0xb07: mov    DWORD PTR [r15+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_b0f:
	/* 0xb0f: lea    rbx,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b13:
	/* 0xb13: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_b1b:
	/* 0xb1b: lea    r13,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_b1f:
	/* 0xb1f: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b23:
	/* 0xb23: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_b2a:
	/* 0xb2a: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_b30:
	/* 0xb30: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_b34:
	/* 0xb34: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_b38:
	/* 0xb38: add    rdi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_b3c:
	/* 0xb3c: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_b42:
	/* 0xb42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b47:
	/* 0xb47: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_b4a:
	/* 0xb4a: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b52:
	/* 0xb52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b54:
	/* 0xb54: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_b59:
	/* 0xb59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b5b:
	/* 0xb5b: js     b6a <generic_retkprobe_event+0xb6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b6a;
	}
x86_l_b5d:
	/* 0xb5d: mov    DWORD PTR [r13+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b61:
	/* 0xb61: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b65:
	/* 0xb65: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_b67:
	/* 0xb67: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_b6a:
	/* 0xb6a: add    r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b6d:
	/* 0xb6d: mov    DWORD PTR [r13+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b71:
	/* 0xb71: jmp    2af6 <generic_retkprobe_event+0x2af6> */
	return 10998ULL;
x86_l_b76:
	/* 0xb76: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_b7a:
	/* 0xb7a: jg     d1f <generic_retkprobe_event+0xd1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d1f;
	}
x86_l_b80:
	/* 0xb80: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_b84:
	/* 0xb84: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b88:
	/* 0xb88: jle    f46 <generic_retkprobe_event+0xf46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3910ULL;
	}
x86_l_b8e:
	/* 0xb8e: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_b92:
	/* 0xb92: je     148d <generic_retkprobe_event+0x148d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5261ULL;
	}
x86_l_b98:
	/* 0xb98: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_b9c:
	/* 0xb9c: je     d7a <generic_retkprobe_event+0xd7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d7a;
	}
x86_l_ba2:
	/* 0xba2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ba7:
	/* 0xba7: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_bab:
	/* 0xbab: jne    2026 <generic_retkprobe_event+0x2026> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8230ULL;
	}
x86_l_bb1:
	/* 0xbb1: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_bb5:
	/* 0xbb5: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bba:
	/* 0xbba: mov    QWORD PTR [rcx+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_bc1:
	/* 0xbc1: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_bc8:
	/* 0xbc8: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bcd:
	/* 0xbcd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bd2:
	/* 0xbd2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_bd7:
	/* 0xbd7: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_bda:
	/* 0xbda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bdc:
	/* 0xbdc: lea    rdi,[rbx+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_be3:
	/* 0xbe3: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_be8:
	/* 0xbe8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bed:
	/* 0xbed: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_bf2:
	/* 0xbf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf4:
	/* 0xbf4: lea    rdi,[rbx+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_bfb:
	/* 0xbfb: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_c03:
	/* 0xc03: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c08:
	/* 0xc08: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c0d:
	/* 0xc0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0f:
	/* 0xc0f: lea    rdi,[rbx+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c16:
	/* 0xc16: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_c1e:
	/* 0xc1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c23:
	/* 0xc23: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c28:
	/* 0xc28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2a:
	/* 0xc2a: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_c31:
	/* 0xc31: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_c39:
	/* 0xc39: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c3e:
	/* 0xc3e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c43:
	/* 0xc43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c45:
	/* 0xc45: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_c4c:
	/* 0xc4c: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_c54:
	/* 0xc54: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c59:
	/* 0xc59: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c5e:
	/* 0xc5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c60:
	/* 0xc60: lea    r13,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_c67:
	/* 0xc67: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c6c:
	/* 0xc6c: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c73:
	/* 0xc73: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c7b:
	/* 0xc7b: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c83:
	/* 0xc83: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c8b:
	/* 0xc8b: movzx  eax,WORD PTR [rbx+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_c92:
	/* 0xc92: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_c95:
	/* 0xc95: je     1e01 <generic_retkprobe_event+0x1e01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7681ULL;
	}
x86_l_c9b:
	/* 0xc9b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c9e:
	/* 0xc9e: jne    1e26 <generic_retkprobe_event+0x1e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7718ULL;
	}
x86_l_ca4:
	/* 0xca4: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ca9:
	/* 0xca9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cae:
	/* 0xcae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cb3:
	/* 0xcb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb5:
	/* 0xcb5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cba:
	/* 0xcba: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_cbd:
	/* 0xcbd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cc2:
	/* 0xcc2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_cc5:
	/* 0xcc5: jmp    1e24 <generic_retkprobe_event+0x1e24> */
	return 7716ULL;
x86_l_cca:
	/* 0xcca: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_cce:
	/* 0xcce: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cd1:
	/* 0xcd1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd6:
	/* 0xcd6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_cd9:
	/* 0xcd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdb:
	/* 0xcdb: mov    QWORD PTR [rsp+0x78],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ce0:
	/* 0xce0: jmp    9a8 <generic_retkprobe_event+0x9a8> */
	goto x86_l_9a8;
x86_l_ce5:
	/* 0xce5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce9:
	/* 0xce9: jmp    1ca7 <generic_retkprobe_event+0x1ca7> */
	return 7335ULL;
x86_l_cee:
	/* 0xcee: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_cf2:
	/* 0xcf2: jg     f30 <generic_retkprobe_event+0xf30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3888ULL;
	}
x86_l_cf8:
	/* 0xcf8: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_cfc:
	/* 0xcfc: je     1307 <generic_retkprobe_event+0x1307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4871ULL;
	}
x86_l_d02:
	/* 0xd02: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_d06:
	/* 0xd06: je     13cf <generic_retkprobe_event+0x13cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5071ULL;
	}
x86_l_d0c:
	/* 0xd0c: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_d10:
	/* 0xd10: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d14:
	/* 0xd14: je     f56 <generic_retkprobe_event+0xf56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3926ULL;
	}
x86_l_d1a:
	/* 0xd1a: jmp    2026 <generic_retkprobe_event+0x2026> */
	return 8230ULL;
x86_l_d1f:
	/* 0xd1f: lea    eax,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_d24:
	/* 0xd24: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d27:
	/* 0xd27: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d2b:
	/* 0xd2b: jb     f56 <generic_retkprobe_event+0xf56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3926ULL;
	}
x86_l_d31:
	/* 0xd31: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_d36:
	/* 0xd36: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d39:
	/* 0xd39: jb     f7f <generic_retkprobe_event+0xf7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3967ULL;
	}
x86_l_d3f:
	/* 0xd3f: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_d43:
	/* 0xd43: jne    2026 <generic_retkprobe_event+0x2026> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8230ULL;
	}
x86_l_d49:
	/* 0xd49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d4e:
	/* 0xd4e: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d53:
	/* 0xd53: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d58:
	/* 0xd58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d5d:
	/* 0xd5d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d60:
	/* 0xd60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d62:
	/* 0xd62: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d67:
	/* 0xd67: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d6c:
	/* 0xd6c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d6f:
	/* 0xd6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d74:
	/* 0xd74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d76:
	/* 0xd76: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7a:
	/* 0xd7a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7f:
	/* 0xd7f: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_d82:
	/* 0xd82: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_d89:
	/* 0xd89: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_d8e:
	/* 0xd8e: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_d93:
	/* 0xd93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d95:
	/* 0xd95: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_d98:
	/* 0xd98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d9b:
	/* 0xd9b: jns    1658 <generic_retkprobe_event+0x1658> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5720ULL;
	}
x86_l_da1:
	/* 0xda1: jmp    1cbd <generic_retkprobe_event+0x1cbd> */
	return 7357ULL;
x86_l_da6:
	/* 0xda6: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_daa:
	/* 0xdaa: jle    1102 <generic_retkprobe_event+0x1102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4354ULL;
	}
x86_l_db0:
	/* 0xdb0: lea    edx,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_db5:
	/* 0xdb5: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_db8:
	/* 0xdb8: jae    fa8 <generic_retkprobe_event+0xfa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4008ULL;
	}
x86_l_dbe:
	/* 0xdbe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dc3:
	/* 0xdc3: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc8:
	/* 0xdc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dcd:
	/* 0xdcd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_dd0:
	/* 0xdd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd2:
	/* 0xdd2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd6:
	/* 0xdd6: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_ddb:
	/* 0xddb: jmp    1ca7 <generic_retkprobe_event+0x1ca7> */
	return 7335ULL;
x86_l_de0:
	/* 0xde0: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_de4:
	/* 0xde4: je     162b <generic_retkprobe_event+0x162b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5675ULL;
	}
x86_l_dea:
	/* 0xdea: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_dee:
	/* 0xdee: je     1674 <generic_retkprobe_event+0x1674> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5748ULL;
	}
x86_l_df4:
	/* 0xdf4: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_df8:
	/* 0xdf8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dfc:
	/* 0xdfc: jne    2026 <generic_retkprobe_event+0x2026> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8230ULL;
	}
x86_l_e02:
	/* 0xe02: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e07:
	/* 0xe07: mov    BYTE PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e0c:
	/* 0xe0c: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e11:
	/* 0xe11: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_e19:
	/* 0xe19: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e21:
	/* 0xe21: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_e29:
	/* 0xe29: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_e31:
	/* 0xe31: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e39:
	/* 0xe39: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_e41:
	/* 0xe41: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_e49:
	/* 0xe49: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_e51:
	/* 0xe51: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_e59:
	/* 0xe59: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_e61:
	/* 0xe61: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_e69:
	/* 0xe69: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e71:
	/* 0xe71: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e79:
	/* 0xe79: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 3712ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3712ULL: goto x86_l_e80;
	case 3717ULL: goto x86_l_e85;
	case 3722ULL: goto x86_l_e8a;
	case 3725ULL: goto x86_l_e8d;
	case 3727ULL: goto x86_l_e8f;
	case 3730ULL: goto x86_l_e92;
	case 3736ULL: goto x86_l_e98;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3761ULL: goto x86_l_eb1;
	case 3764ULL: goto x86_l_eb4;
	case 3770ULL: goto x86_l_eba;
	case 3774ULL: goto x86_l_ebe;
	case 3777ULL: goto x86_l_ec1;
	case 3784ULL: goto x86_l_ec8;
	case 3789ULL: goto x86_l_ecd;
	case 3796ULL: goto x86_l_ed4;
	case 3802ULL: goto x86_l_eda;
	case 3807ULL: goto x86_l_edf;
	case 3812ULL: goto x86_l_ee4;
	case 3815ULL: goto x86_l_ee7;
	case 3817ULL: goto x86_l_ee9;
	case 3819ULL: goto x86_l_eeb;
	case 3825ULL: goto x86_l_ef1;
	case 3827ULL: goto x86_l_ef3;
	case 3832ULL: goto x86_l_ef8;
	case 3836ULL: goto x86_l_efc;
	case 3842ULL: goto x86_l_f02;
	case 3846ULL: goto x86_l_f06;
	case 3852ULL: goto x86_l_f0c;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3867ULL: goto x86_l_f1b;
	case 3878ULL: goto x86_l_f26;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3893ULL: goto x86_l_f35;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3910ULL: goto x86_l_f46;
	case 3914ULL: goto x86_l_f4a;
	case 3916ULL: goto x86_l_f4c;
	case 3920ULL: goto x86_l_f50;
	case 3926ULL: goto x86_l_f56;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3941ULL: goto x86_l_f65;
	case 3946ULL: goto x86_l_f6a;
	case 3948ULL: goto x86_l_f6c;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3962ULL: goto x86_l_f7a;
	case 3967ULL: goto x86_l_f7f;
	case 3972ULL: goto x86_l_f84;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3992ULL: goto x86_l_f98;
	case 3994ULL: goto x86_l_f9a;
	case 3998ULL: goto x86_l_f9e;
	case 4003ULL: goto x86_l_fa3;
	case 4008ULL: goto x86_l_fa8;
	case 4012ULL: goto x86_l_fac;
	case 4018ULL: goto x86_l_fb2;
	case 4022ULL: goto x86_l_fb6;
	case 4027ULL: goto x86_l_fbb;
	case 4033ULL: goto x86_l_fc1;
	case 4037ULL: goto x86_l_fc5;
	case 4040ULL: goto x86_l_fc8;
	case 4044ULL: goto x86_l_fcc;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4062ULL: goto x86_l_fde;
	case 4064ULL: goto x86_l_fe0;
	case 4069ULL: goto x86_l_fe5;
	case 4072ULL: goto x86_l_fe8;
	case 4078ULL: goto x86_l_fee;
	case 4082ULL: goto x86_l_ff2;
	case 4089ULL: goto x86_l_ff9;
	case 4096ULL: goto x86_l_1000;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4113ULL: goto x86_l_1011;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4135ULL: goto x86_l_1027;
	case 4137ULL: goto x86_l_1029;
	case 4144ULL: goto x86_l_1030;
	case 4152ULL: goto x86_l_1038;
	case 4157ULL: goto x86_l_103d;
	case 4162ULL: goto x86_l_1042;
	case 4164ULL: goto x86_l_1044;
	case 4171ULL: goto x86_l_104b;
	case 4179ULL: goto x86_l_1053;
	case 4184ULL: goto x86_l_1058;
	case 4189ULL: goto x86_l_105d;
	case 4191ULL: goto x86_l_105f;
	case 4198ULL: goto x86_l_1066;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4216ULL: goto x86_l_1078;
	case 4218ULL: goto x86_l_107a;
	case 4225ULL: goto x86_l_1081;
	case 4233ULL: goto x86_l_1089;
	case 4238ULL: goto x86_l_108e;
	case 4243ULL: goto x86_l_1093;
	case 4245ULL: goto x86_l_1095;
	case 4252ULL: goto x86_l_109c;
	case 4257ULL: goto x86_l_10a1;
	case 4264ULL: goto x86_l_10a8;
	case 4272ULL: goto x86_l_10b0;
	case 4280ULL: goto x86_l_10b8;
	case 4283ULL: goto x86_l_10bb;
	case 4291ULL: goto x86_l_10c3;
	case 4298ULL: goto x86_l_10ca;
	case 4301ULL: goto x86_l_10cd;
	case 4307ULL: goto x86_l_10d3;
	case 4310ULL: goto x86_l_10d6;
	case 4316ULL: goto x86_l_10dc;
	case 4321ULL: goto x86_l_10e1;
	case 4326ULL: goto x86_l_10e6;
	case 4331ULL: goto x86_l_10eb;
	case 4333ULL: goto x86_l_10ed;
	case 4338ULL: goto x86_l_10f2;
	case 4341ULL: goto x86_l_10f5;
	case 4346ULL: goto x86_l_10fa;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4358ULL: goto x86_l_1106;
	case 4364ULL: goto x86_l_110c;
	case 4368ULL: goto x86_l_1110;
	case 4373ULL: goto x86_l_1115;
	case 4379ULL: goto x86_l_111b;
	case 4383ULL: goto x86_l_111f;
	case 4388ULL: goto x86_l_1124;
	case 4396ULL: goto x86_l_112c;
	case 4404ULL: goto x86_l_1134;
	case 4412ULL: goto x86_l_113c;
	case 4420ULL: goto x86_l_1144;
	case 4428ULL: goto x86_l_114c;
	case 4436ULL: goto x86_l_1154;
	case 4444ULL: goto x86_l_115c;
	case 4452ULL: goto x86_l_1164;
	case 4460ULL: goto x86_l_116c;
	case 4467ULL: goto x86_l_1173;
	case 4474ULL: goto x86_l_117a;
	case 4478ULL: goto x86_l_117e;
	case 4483ULL: goto x86_l_1183;
	case 4488ULL: goto x86_l_1188;
	case 4490ULL: goto x86_l_118a;
	case 4493ULL: goto x86_l_118d;
	case 4499ULL: goto x86_l_1193;
	case 4503ULL: goto x86_l_1197;
	case 4506ULL: goto x86_l_119a;
	case 4513ULL: goto x86_l_11a1;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4533ULL: goto x86_l_11b5;
	case 4535ULL: goto x86_l_11b7;
	case 4538ULL: goto x86_l_11ba;
	case 4543ULL: goto x86_l_11bf;
	case 4548ULL: goto x86_l_11c4;
	case 4552ULL: goto x86_l_11c8;
	case 4558ULL: goto x86_l_11ce;
	case 4562ULL: goto x86_l_11d2;
	case 4567ULL: goto x86_l_11d7;
	case 4573ULL: goto x86_l_11dd;
	case 4578ULL: goto x86_l_11e2;
	case 4580ULL: goto x86_l_11e4;
	case 4585ULL: goto x86_l_11e9;
	case 4587ULL: goto x86_l_11eb;
	case 4590ULL: goto x86_l_11ee;
	case 4592ULL: goto x86_l_11f0;
	case 4596ULL: goto x86_l_11f4;
	case 4601ULL: goto x86_l_11f9;
	case 4605ULL: goto x86_l_11fd;
	case 4611ULL: goto x86_l_1203;
	case 4615ULL: goto x86_l_1207;
	case 4620ULL: goto x86_l_120c;
	case 4626ULL: goto x86_l_1212;
	case 4635ULL: goto x86_l_121b;
	case 4642ULL: goto x86_l_1222;
	case 4649ULL: goto x86_l_1229;
	case 4654ULL: goto x86_l_122e;
	case 4659ULL: goto x86_l_1233;
	case 4664ULL: goto x86_l_1238;
	case 4666ULL: goto x86_l_123a;
	case 4671ULL: goto x86_l_123f;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4688ULL: goto x86_l_1250;
	case 4692ULL: goto x86_l_1254;
	case 4699ULL: goto x86_l_125b;
	case 4704ULL: goto x86_l_1260;
	case 4709ULL: goto x86_l_1265;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4719ULL: goto x86_l_126f;
	case 4723ULL: goto x86_l_1273;
	case 4730ULL: goto x86_l_127a;
	case 4737ULL: goto x86_l_1281;
	case 4742ULL: goto x86_l_1286;
	case 4747ULL: goto x86_l_128b;
	case 4749ULL: goto x86_l_128d;
	case 4753ULL: goto x86_l_1291;
	case 4760ULL: goto x86_l_1298;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4777ULL: goto x86_l_12a9;
	case 4780ULL: goto x86_l_12ac;
	case 4782ULL: goto x86_l_12ae;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4796ULL: goto x86_l_12bc;
	case 4800ULL: goto x86_l_12c0;
	case 4804ULL: goto x86_l_12c4;
	case 4810ULL: goto x86_l_12ca;
	case 4815ULL: goto x86_l_12cf;
	case 4818ULL: goto x86_l_12d2;
	case 4826ULL: goto x86_l_12da;
	case 4829ULL: goto x86_l_12dd;
	case 4835ULL: goto x86_l_12e3;
	case 4838ULL: goto x86_l_12e6;
	case 4845ULL: goto x86_l_12ed;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4854ULL: goto x86_l_12f6;
	case 4857ULL: goto x86_l_12f9;
	case 4860ULL: goto x86_l_12fc;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4880ULL: goto x86_l_1310;
	case 4889ULL: goto x86_l_1319;
	case 4894ULL: goto x86_l_131e;
	case 4896ULL: goto x86_l_1320;
	case 4900ULL: goto x86_l_1324;
	case 4905ULL: goto x86_l_1329;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4920ULL: goto x86_l_1338;
	case 4925ULL: goto x86_l_133d;
	case 4927ULL: goto x86_l_133f;
	case 4931ULL: goto x86_l_1343;
	case 4935ULL: goto x86_l_1347;
	case 4940ULL: goto x86_l_134c;
	case 4947ULL: goto x86_l_1353;
	case 4952ULL: goto x86_l_1358;
	case 4954ULL: goto x86_l_135a;
	case 4957ULL: goto x86_l_135d;
	case 4963ULL: goto x86_l_1363;
	case 4965ULL: goto x86_l_1365;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4988ULL: goto x86_l_137c;
	case 4990ULL: goto x86_l_137e;
	case 4996ULL: goto x86_l_1384;
	case 5000ULL: goto x86_l_1388;
	case 5007ULL: goto x86_l_138f;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5018ULL: goto x86_l_139a;
	case 5020ULL: goto x86_l_139c;
	case 5025ULL: goto x86_l_13a1;
	case 5029ULL: goto x86_l_13a5;
	case 5033ULL: goto x86_l_13a9;
	case 5037ULL: goto x86_l_13ad;
	case 5041ULL: goto x86_l_13b1;
	case 5046ULL: goto x86_l_13b6;
	case 5051ULL: goto x86_l_13bb;
	case 5053ULL: goto x86_l_13bd;
	case 5057ULL: goto x86_l_13c1;
	case 5061ULL: goto x86_l_13c5;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5075ULL: goto x86_l_13d3;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5088ULL: goto x86_l_13e0;
	case 5096ULL: goto x86_l_13e8;
	case 5101ULL: goto x86_l_13ed;
	case 5104ULL: goto x86_l_13f0;
	case 5106ULL: goto x86_l_13f2;
	case 5114ULL: goto x86_l_13fa;
	case 5116ULL: goto x86_l_13fc;
	case 5122ULL: goto x86_l_1402;
	case 5125ULL: goto x86_l_1405;
	case 5131ULL: goto x86_l_140b;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5150ULL: goto x86_l_141e;
	case 5155ULL: goto x86_l_1423;
	case 5158ULL: goto x86_l_1426;
	case 5160ULL: goto x86_l_1428;
	case 5165ULL: goto x86_l_142d;
	case 5170ULL: goto x86_l_1432;
	case 5175ULL: goto x86_l_1437;
	case 5180ULL: goto x86_l_143c;
	case 5182ULL: goto x86_l_143e;
	case 5187ULL: goto x86_l_1443;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5204ULL: goto x86_l_1454;
	case 5209ULL: goto x86_l_1459;
	case 5211ULL: goto x86_l_145b;
	case 5216ULL: goto x86_l_1460;
	case 5224ULL: goto x86_l_1468;
	case 5231ULL: goto x86_l_146f;
	case 5237ULL: goto x86_l_1475;
	case 5241ULL: goto x86_l_1479;
	case 5244ULL: goto x86_l_147c;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5261ULL: goto x86_l_148d;
	case 5265ULL: goto x86_l_1491;
	case 5270ULL: goto x86_l_1496;
	case 5277ULL: goto x86_l_149d;
	case 5284ULL: goto x86_l_14a4;
	case 5289ULL: goto x86_l_14a9;
	case 5294ULL: goto x86_l_14ae;
	case 5297ULL: goto x86_l_14b1;
	case 5299ULL: goto x86_l_14b3;
	case 5306ULL: goto x86_l_14ba;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5320ULL: goto x86_l_14c8;
	case 5322ULL: goto x86_l_14ca;
	case 5329ULL: goto x86_l_14d1;
	case 5336ULL: goto x86_l_14d8;
	case 5341ULL: goto x86_l_14dd;
	case 5346ULL: goto x86_l_14e2;
	case 5348ULL: goto x86_l_14e4;
	case 5355ULL: goto x86_l_14eb;
	case 5362ULL: goto x86_l_14f2;
	case 5367ULL: goto x86_l_14f7;
	case 5372ULL: goto x86_l_14fc;
	case 5374ULL: goto x86_l_14fe;
	case 5383ULL: goto x86_l_1507;
	case 5390ULL: goto x86_l_150e;
	case 5395ULL: goto x86_l_1513;
	case 5400ULL: goto x86_l_1518;
	case 5405ULL: goto x86_l_151d;
	case 5407ULL: goto x86_l_151f;
	case 5414ULL: goto x86_l_1526;
	case 5419ULL: goto x86_l_152b;
	case 5427ULL: goto x86_l_1533;
	case 5432ULL: goto x86_l_1538;
	case 5434ULL: goto x86_l_153a;
	case 5443ULL: goto x86_l_1543;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5461ULL: goto x86_l_1555;
	case 5466ULL: goto x86_l_155a;
	case 5469ULL: goto x86_l_155d;
	case 5471ULL: goto x86_l_155f;
	case 5479ULL: goto x86_l_1567;
	case 5482ULL: goto x86_l_156a;
	case 5485ULL: goto x86_l_156d;
	case 5491ULL: goto x86_l_1573;
	case 5494ULL: goto x86_l_1576;
	case 5500ULL: goto x86_l_157c;
	case 5504ULL: goto x86_l_1580;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5528ULL: goto x86_l_1598;
	case 5533ULL: goto x86_l_159d;
	case 5535ULL: goto x86_l_159f;
	case 5543ULL: goto x86_l_15a7;
	case 5547ULL: goto x86_l_15ab;
	case 5554ULL: goto x86_l_15b2;
	case 5563ULL: goto x86_l_15bb;
	case 5570ULL: goto x86_l_15c2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e80:
	/* 0xe80: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e85:
	/* 0xe85: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e8a:
	/* 0xe8a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e8d:
	/* 0xe8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8f:
	/* 0xe8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e92:
	/* 0xe92: js     2018 <generic_retkprobe_event+0x2018> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8216ULL;
	}
x86_l_e98:
	/* 0xe98: lea    r13,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_e9d:
	/* 0xe9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ea2:
	/* 0xea2: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ea7:
	/* 0xea7: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_eac:
	/* 0xeac: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_eaf:
	/* 0xeaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb1:
	/* 0xeb1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eb4:
	/* 0xeb4: js     2018 <generic_retkprobe_event+0x2018> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8216ULL;
	}
x86_l_eba:
	/* 0xeba: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ebe:
	/* 0xebe: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ec1:
	/* 0xec1: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_ec8:
	/* 0xec8: cmp    BYTE PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_ecd:
	/* 0xecd: sete   BYTE PTR [rax+0x9e] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 158ULL);
x86_l_ed4:
	/* 0xed4: je     1ff2 <generic_retkprobe_event+0x1ff2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8178ULL;
	}
x86_l_eda:
	/* 0xeda: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_edf:
	/* 0xedf: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_ee4:
	/* 0xee4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ee7:
	/* 0xee7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee9:
	/* 0xee9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eeb:
	/* 0xeeb: js     2018 <generic_retkprobe_event+0x2018> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8216ULL;
	}
x86_l_ef1:
	/* 0xef1: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_ef3:
	/* 0xef3: jmp    200e <generic_retkprobe_event+0x200e> */
	return 8206ULL;
x86_l_ef8:
	/* 0xef8: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_efc:
	/* 0xefc: jg     11c4 <generic_retkprobe_event+0x11c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_11c4;
	}
x86_l_f02:
	/* 0xf02: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f06:
	/* 0xf06: je     17d0 <generic_retkprobe_event+0x17d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6096ULL;
	}
x86_l_f0c:
	/* 0xf0c: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f10:
	/* 0xf10: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f15:
	/* 0xf15: jne    1cac <generic_retkprobe_event+0x1cac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7340ULL;
	}
x86_l_f1b:
	/* 0xf1b: mov    QWORD PTR [rax+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_f26:
	/* 0xf26: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_f2b:
	/* 0xf2b: jmp    1cac <generic_retkprobe_event+0x1cac> */
	return 7340ULL;
x86_l_f30:
	/* 0xf30: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_f35:
	/* 0xf35: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f3a:
	/* 0xf3a: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f3f:
	/* 0xf3f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f44:
	/* 0xf44: jmp    f98 <generic_retkprobe_event+0xf98> */
	goto x86_l_f98;
x86_l_f46:
	/* 0xf46: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_f4a:
	/* 0xf4a: je     f7f <generic_retkprobe_event+0xf7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f7f;
	}
x86_l_f4c:
	/* 0xf4c: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f50:
	/* 0xf50: jne    2026 <generic_retkprobe_event+0x2026> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8230ULL;
	}
x86_l_f56:
	/* 0xf56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f5b:
	/* 0xf5b: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f60:
	/* 0xf60: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f65:
	/* 0xf65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f6a:
	/* 0xf6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6c:
	/* 0xf6c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f70:
	/* 0xf70: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_f75:
	/* 0xf75: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f7a:
	/* 0xf7a: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_f7f:
	/* 0xf7f: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_f84:
	/* 0xf84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f89:
	/* 0xf89: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8e:
	/* 0xf8e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f93:
	/* 0xf93: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f98:
	/* 0xf98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9a:
	/* 0xf9a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9e:
	/* 0xf9e: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fa3:
	/* 0xfa3: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_fa8:
	/* 0xfa8: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_fac:
	/* 0xfac: je     1b9a <generic_retkprobe_event+0x1b9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7066ULL;
	}
x86_l_fb2:
	/* 0xfb2: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_fb6:
	/* 0xfb6: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fbb:
	/* 0xfbb: jne    1cac <generic_retkprobe_event+0x1cac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7340ULL;
	}
x86_l_fc1:
	/* 0xfc1: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fc5:
	/* 0xfc5: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_fc8:
	/* 0xfc8: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_fcc:
	/* 0xfcc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fd1:
	/* 0xfd1: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fd6:
	/* 0xfd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fdb:
	/* 0xfdb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_fde:
	/* 0xfde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe0:
	/* 0xfe0: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fe5:
	/* 0xfe5: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_fe8:
	/* 0xfe8: je     20a1 <generic_retkprobe_event+0x20a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8353ULL;
	}
x86_l_fee:
	/* 0xfee: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff2:
	/* 0xff2: mov    QWORD PTR [rbx+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_ff9:
	/* 0xff9: lea    rdi,[rbx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_1000:
	/* 0x1000: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1005:
	/* 0x1005: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_100a:
	/* 0x100a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_100f:
	/* 0x100f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1011:
	/* 0x1011: lea    rdi,[rbx+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_1018:
	/* 0x1018: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_101d:
	/* 0x101d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1022:
	/* 0x1022: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1027:
	/* 0x1027: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1029:
	/* 0x1029: lea    rdi,[rbx+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1030:
	/* 0x1030: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1038:
	/* 0x1038: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_103d:
	/* 0x103d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1042:
	/* 0x1042: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1044:
	/* 0x1044: lea    rdi,[rbx+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_104b:
	/* 0x104b: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1053:
	/* 0x1053: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1058:
	/* 0x1058: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_105d:
	/* 0x105d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_105f:
	/* 0x105f: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1066:
	/* 0x1066: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_106e:
	/* 0x106e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1073:
	/* 0x1073: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1078:
	/* 0x1078: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107a:
	/* 0x107a: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1081:
	/* 0x1081: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1089:
	/* 0x1089: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_108e:
	/* 0x108e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1093:
	/* 0x1093: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1095:
	/* 0x1095: lea    r13,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_109c:
	/* 0x109c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10a1:
	/* 0x10a1: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a8:
	/* 0x10a8: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10b0:
	/* 0x10b0: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10b8:
	/* 0x10b8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10bb:
	/* 0x10bb: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10c3:
	/* 0x10c3: movzx  eax,WORD PTR [rbx+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_10ca:
	/* 0x10ca: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_10cd:
	/* 0x10cd: je     2030 <generic_retkprobe_event+0x2030> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8240ULL;
	}
x86_l_10d3:
	/* 0x10d3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10d6:
	/* 0x10d6: jne    2055 <generic_retkprobe_event+0x2055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8277ULL;
	}
x86_l_10dc:
	/* 0x10dc: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10e1:
	/* 0x10e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10e6:
	/* 0x10e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10eb:
	/* 0x10eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ed:
	/* 0x10ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10f2:
	/* 0x10f2: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_10f5:
	/* 0x10f5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10fa:
	/* 0x10fa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10fd:
	/* 0x10fd: jmp    2053 <generic_retkprobe_event+0x2053> */
	return 8275ULL;
x86_l_1102:
	/* 0x1102: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_1106:
	/* 0x1106: je     1c27 <generic_retkprobe_event+0x1c27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7207ULL;
	}
x86_l_110c:
	/* 0x110c: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_1110:
	/* 0x1110: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1115:
	/* 0x1115: jne    1cac <generic_retkprobe_event+0x1cac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7340ULL;
	}
x86_l_111b:
	/* 0x111b: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_111f:
	/* 0x111f: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1124:
	/* 0x1124: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_112c:
	/* 0x112c: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1134:
	/* 0x1134: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_113c:
	/* 0x113c: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1144:
	/* 0x1144: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_114c:
	/* 0x114c: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1154:
	/* 0x1154: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_115c:
	/* 0x115c: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1164:
	/* 0x1164: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_116c:
	/* 0x116c: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1173:
	/* 0x1173: lea    rdi,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_117a:
	/* 0x117a: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_117e:
	/* 0x117e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1183:
	/* 0x1183: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1188:
	/* 0x1188: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118a:
	/* 0x118a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_118d:
	/* 0x118d: js     1fdd <generic_retkprobe_event+0x1fdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8157ULL;
	}
x86_l_1193:
	/* 0x1193: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1197:
	/* 0x1197: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_119a:
	/* 0x119a: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_11a1:
	/* 0x11a1: add    r13,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_11a8:
	/* 0x11a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11ad:
	/* 0x11ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11b2:
	/* 0x11b2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_11b5:
	/* 0x11b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b7:
	/* 0x11b7: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_11ba:
	/* 0x11ba: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_11bf:
	/* 0x11bf: jmp    1fe3 <generic_retkprobe_event+0x1fe3> */
	return 8163ULL;
x86_l_11c4:
	/* 0x11c4: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_11c8:
	/* 0x11c8: je     1865 <generic_retkprobe_event+0x1865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6245ULL;
	}
x86_l_11ce:
	/* 0x11ce: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_11d2:
	/* 0x11d2: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11d7:
	/* 0x11d7: jne    1cac <generic_retkprobe_event+0x1cac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7340ULL;
	}
x86_l_11dd:
	/* 0x11dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11e2:
	/* 0x11e2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e4:
	/* 0x11e4: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11e9:
	/* 0x11e9: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11eb:
	/* 0x11eb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_11ee:
	/* 0x11ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f0:
	/* 0x11f0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f4:
	/* 0x11f4: jmp    1cac <generic_retkprobe_event+0x1cac> */
	return 7340ULL;
x86_l_11f9:
	/* 0x11f9: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_11fd:
	/* 0x11fd: je     1b4a <generic_retkprobe_event+0x1b4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6986ULL;
	}
x86_l_1203:
	/* 0x1203: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_1207:
	/* 0x1207: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_120c:
	/* 0x120c: jne    1cac <generic_retkprobe_event+0x1cac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7340ULL;
	}
x86_l_1212:
	/* 0x1212: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_121b:
	/* 0x121b: lea    r12,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1222:
	/* 0x1222: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1229:
	/* 0x1229: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_122e:
	/* 0x122e: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1233:
	/* 0x1233: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1238:
	/* 0x1238: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123a:
	/* 0x123a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_123f:
	/* 0x123f: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1244:
	/* 0x1244: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1249:
	/* 0x1249: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_124e:
	/* 0x124e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1250:
	/* 0x1250: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1254:
	/* 0x1254: lea    rdi,[rax+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_125b:
	/* 0x125b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1260:
	/* 0x1260: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1265:
	/* 0x1265: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1268:
	/* 0x1268: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_126d:
	/* 0x126d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126f:
	/* 0x126f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1273:
	/* 0x1273: lea    rdi,[rax+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_127a:
	/* 0x127a: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1281:
	/* 0x1281: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1286:
	/* 0x1286: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_128b:
	/* 0x128b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128d:
	/* 0x128d: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1291:
	/* 0x1291: add    rdi,0x124 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_1298:
	/* 0x1298: add    r13,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_129f:
	/* 0x129f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12a4:
	/* 0x12a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a9:
	/* 0x12a9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_12ac:
	/* 0x12ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ae:
	/* 0x12ae: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b2:
	/* 0x12b2: mov    ebp,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 152ULL);
x86_l_12b7:
	/* 0x12b7: jmp    1cac <generic_retkprobe_event+0x1cac> */
	return 7340ULL;
x86_l_12bc:
	/* 0x12bc: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_12c0:
	/* 0x12c0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c4:
	/* 0x12c4: jne    2026 <generic_retkprobe_event+0x2026> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8230ULL;
	}
x86_l_12ca:
	/* 0x12ca: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12cf:
	/* 0x12cf: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12d2:
	/* 0x12d2: add    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 224ULL);
x86_l_12da:
	/* 0x12da: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12dd:
	/* 0x12dd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12e3:
	/* 0x12e3: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_12e6:
	/* 0x12e6: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_12ed:
	/* 0x12ed: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12ef:
	/* 0x12ef: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_12f4:
	/* 0x12f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f6:
	/* 0x12f6: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_12f9:
	/* 0x12f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12fc:
	/* 0x12fc: jns    1658 <generic_retkprobe_event+0x1658> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5720ULL;
	}
x86_l_1302:
	/* 0x1302: jmp    1cbd <generic_retkprobe_event+0x1cbd> */
	return 7357ULL;
x86_l_1307:
	/* 0x1307: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1310:
	/* 0x1310: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1319:
	/* 0x1319: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_131e:
	/* 0x131e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1320:
	/* 0x1320: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1324:
	/* 0x1324: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1329:
	/* 0x1329: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_132e:
	/* 0x132e: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1333:
	/* 0x1333: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1338:
	/* 0x1338: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_133d:
	/* 0x133d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_133f:
	/* 0x133f: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1343:
	/* 0x1343: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1347:
	/* 0x1347: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_134c:
	/* 0x134c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1353:
	/* 0x1353: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1358:
	/* 0x1358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135a:
	/* 0x135a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_135d:
	/* 0x135d: je     1cb6 <generic_retkprobe_event+0x1cb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7350ULL;
	}
x86_l_1363:
	/* 0x1363: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1365:
	/* 0x1365: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_136a:
	/* 0x136a: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_136f:
	/* 0x136f: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1374:
	/* 0x1374: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1379:
	/* 0x1379: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_137c:
	/* 0x137c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_137e:
	/* 0x137e: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1384:
	/* 0x1384: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1388:
	/* 0x1388: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_138f:
	/* 0x138f: lea    esi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1392:
	/* 0x1392: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1397:
	/* 0x1397: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_139a:
	/* 0x139a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139c:
	/* 0x139c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a1:
	/* 0x13a1: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_13a5:
	/* 0x13a5: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_13a9:
	/* 0x13a9: lea    rdx,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_13ad:
	/* 0x13ad: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_13b1:
	/* 0x13b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13b6:
	/* 0x13b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13bb:
	/* 0x13bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13bd:
	/* 0x13bd: add    rbp,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_13c1:
	/* 0x13c1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c5:
	/* 0x13c5: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13ca:
	/* 0x13ca: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_13cf:
	/* 0x13cf: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_13d3:
	/* 0x13d3: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_13d6:
	/* 0x13d6: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13db:
	/* 0x13db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13e0:
	/* 0x13e0: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13e8:
	/* 0x13e8: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_13ed:
	/* 0x13ed: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_13f0:
	/* 0x13f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f2:
	/* 0x13f2: movzx  eax,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 176ULL);
x86_l_13fa:
	/* 0x13fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13fc:
	/* 0x13fc: je     1ccb <generic_retkprobe_event+0x1ccb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7371ULL;
	}
x86_l_1402:
	/* 0x1402: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1405:
	/* 0x1405: jne    1eb3 <generic_retkprobe_event+0x1eb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7859ULL;
	}
x86_l_140b:
	/* 0x140b: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_140f:
	/* 0x140f: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1414:
	/* 0x1414: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1419:
	/* 0x1419: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_141e:
	/* 0x141e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1423:
	/* 0x1423: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1426:
	/* 0x1426: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1428:
	/* 0x1428: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_142d:
	/* 0x142d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1432:
	/* 0x1432: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1437:
	/* 0x1437: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_143c:
	/* 0x143c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143e:
	/* 0x143e: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1443:
	/* 0x1443: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1447:
	/* 0x1447: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_144c:
	/* 0x144c: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1454:
	/* 0x1454: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1459:
	/* 0x1459: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145b:
	/* 0x145b: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1460:
	/* 0x1460: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1468:
	/* 0x1468: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_146f:
	/* 0x146f: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1475:
	/* 0x1475: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_1479:
	/* 0x1479: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_147c:
	/* 0x147c: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1483:
	/* 0x1483: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1488:
	/* 0x1488: jmp    1d2e <generic_retkprobe_event+0x1d2e> */
	return 7470ULL;
x86_l_148d:
	/* 0x148d: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1491:
	/* 0x1491: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1496:
	/* 0x1496: lea    rdi,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_149d:
	/* 0x149d: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14a4:
	/* 0x14a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a9:
	/* 0x14a9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14ae:
	/* 0x14ae: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_14b1:
	/* 0x14b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b3:
	/* 0x14b3: lea    rdi,[rbx+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_14ba:
	/* 0x14ba: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14be:
	/* 0x14be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c3:
	/* 0x14c3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14c8:
	/* 0x14c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ca:
	/* 0x14ca: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_14d1:
	/* 0x14d1: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14d8:
	/* 0x14d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14dd:
	/* 0x14dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14e2:
	/* 0x14e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e4:
	/* 0x14e4: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_14eb:
	/* 0x14eb: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_14f2:
	/* 0x14f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14f7:
	/* 0x14f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14fc:
	/* 0x14fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fe:
	/* 0x14fe: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1507:
	/* 0x1507: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_150e:
	/* 0x150e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1513:
	/* 0x1513: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1518:
	/* 0x1518: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_151d:
	/* 0x151d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151f:
	/* 0x151f: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1526:
	/* 0x1526: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_152b:
	/* 0x152b: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1533:
	/* 0x1533: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1538:
	/* 0x1538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153a:
	/* 0x153a: movzx  r12d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1543:
	/* 0x1543: add    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1548:
	/* 0x1548: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_154d:
	/* 0x154d: lea    rdi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1555:
	/* 0x1555: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_155a:
	/* 0x155a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_155d:
	/* 0x155d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155f:
	/* 0x155f: movzx  eax,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_1567:
	/* 0x1567: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_156a:
	/* 0x156a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_156d:
	/* 0x156d: je     1d60 <generic_retkprobe_event+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7520ULL;
	}
x86_l_1573:
	/* 0x1573: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1576:
	/* 0x1576: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_157c:
	/* 0x157c: mov    ebx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1580:
	/* 0x1580: jne    2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10609ULL;
	}
x86_l_1586:
	/* 0x1586: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_158b:
	/* 0x158b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1590:
	/* 0x1590: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1598:
	/* 0x1598: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_159d:
	/* 0x159d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159f:
	/* 0x159f: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_15a7:
	/* 0x15a7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ab:
	/* 0x15ab: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_15b2:
	/* 0x15b2: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_15bb:
	/* 0x15bb: lea    r13,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_15c2:
	/* 0x15c2: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
	return 5575ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5575ULL: goto x86_l_15c7;
	case 5580ULL: goto x86_l_15cc;
	case 5587ULL: goto x86_l_15d3;
	case 5595ULL: goto x86_l_15db;
	case 5603ULL: goto x86_l_15e3;
	case 5611ULL: goto x86_l_15eb;
	case 5616ULL: goto x86_l_15f0;
	case 5621ULL: goto x86_l_15f5;
	case 5623ULL: goto x86_l_15f7;
	case 5627ULL: goto x86_l_15fb;
	case 5632ULL: goto x86_l_1600;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5643ULL: goto x86_l_160b;
	case 5645ULL: goto x86_l_160d;
	case 5652ULL: goto x86_l_1614;
	case 5657ULL: goto x86_l_1619;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5689ULL: goto x86_l_1639;
	case 5696ULL: goto x86_l_1640;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5714ULL: goto x86_l_1652;
	case 5720ULL: goto x86_l_1658;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5730ULL: goto x86_l_1662;
	case 5734ULL: goto x86_l_1666;
	case 5738ULL: goto x86_l_166a;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5753ULL: goto x86_l_1679;
	case 5761ULL: goto x86_l_1681;
	case 5769ULL: goto x86_l_1689;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5786ULL: goto x86_l_169a;
	case 5789ULL: goto x86_l_169d;
	case 5792ULL: goto x86_l_16a0;
	case 5794ULL: goto x86_l_16a2;
	case 5797ULL: goto x86_l_16a5;
	case 5801ULL: goto x86_l_16a9;
	case 5807ULL: goto x86_l_16af;
	case 5811ULL: goto x86_l_16b3;
	case 5815ULL: goto x86_l_16b7;
	case 5818ULL: goto x86_l_16ba;
	case 5824ULL: goto x86_l_16c0;
	case 5827ULL: goto x86_l_16c3;
	case 5833ULL: goto x86_l_16c9;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5855ULL: goto x86_l_16df;
	case 5859ULL: goto x86_l_16e3;
	case 5863ULL: goto x86_l_16e7;
	case 5870ULL: goto x86_l_16ee;
	case 5877ULL: goto x86_l_16f5;
	case 5881ULL: goto x86_l_16f9;
	case 5886ULL: goto x86_l_16fe;
	case 5891ULL: goto x86_l_1703;
	case 5894ULL: goto x86_l_1706;
	case 5903ULL: goto x86_l_170f;
	case 5909ULL: goto x86_l_1715;
	case 5914ULL: goto x86_l_171a;
	case 5922ULL: goto x86_l_1722;
	case 5926ULL: goto x86_l_1726;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5949ULL: goto x86_l_173d;
	case 5954ULL: goto x86_l_1742;
	case 5956ULL: goto x86_l_1744;
	case 5962ULL: goto x86_l_174a;
	case 5967ULL: goto x86_l_174f;
	case 5970ULL: goto x86_l_1752;
	case 5973ULL: goto x86_l_1755;
	case 5977ULL: goto x86_l_1759;
	case 5982ULL: goto x86_l_175e;
	case 5985ULL: goto x86_l_1761;
	case 5989ULL: goto x86_l_1765;
	case 5994ULL: goto x86_l_176a;
	case 6001ULL: goto x86_l_1771;
	case 6007ULL: goto x86_l_1777;
	case 6010ULL: goto x86_l_177a;
	case 6015ULL: goto x86_l_177f;
	case 6019ULL: goto x86_l_1783;
	case 6024ULL: goto x86_l_1788;
	case 6030ULL: goto x86_l_178e;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6043ULL: goto x86_l_179b;
	case 6046ULL: goto x86_l_179e;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6055ULL: goto x86_l_17a7;
	case 6061ULL: goto x86_l_17ad;
	case 6065ULL: goto x86_l_17b1;
	case 6068ULL: goto x86_l_17b4;
	case 6074ULL: goto x86_l_17ba;
	case 6080ULL: goto x86_l_17c0;
	case 6085ULL: goto x86_l_17c5;
	case 6091ULL: goto x86_l_17cb;
	case 6096ULL: goto x86_l_17d0;
	case 6100ULL: goto x86_l_17d4;
	case 6109ULL: goto x86_l_17dd;
	case 6118ULL: goto x86_l_17e6;
	case 6123ULL: goto x86_l_17eb;
	case 6128ULL: goto x86_l_17f0;
	case 6133ULL: goto x86_l_17f5;
	case 6138ULL: goto x86_l_17fa;
	case 6143ULL: goto x86_l_17ff;
	case 6146ULL: goto x86_l_1802;
	case 6148ULL: goto x86_l_1804;
	case 6153ULL: goto x86_l_1809;
	case 6160ULL: goto x86_l_1810;
	case 6166ULL: goto x86_l_1816;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6182ULL: goto x86_l_1826;
	case 6187ULL: goto x86_l_182b;
	case 6190ULL: goto x86_l_182e;
	case 6193ULL: goto x86_l_1831;
	case 6196ULL: goto x86_l_1834;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6205ULL: goto x86_l_183d;
	case 6207ULL: goto x86_l_183f;
	case 6212ULL: goto x86_l_1844;
	case 6219ULL: goto x86_l_184b;
	case 6223ULL: goto x86_l_184f;
	case 6226ULL: goto x86_l_1852;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6252ULL: goto x86_l_186c;
	case 6256ULL: goto x86_l_1870;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6271ULL: goto x86_l_187f;
	case 6273ULL: goto x86_l_1881;
	case 6277ULL: goto x86_l_1885;
	case 6284ULL: goto x86_l_188c;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6300ULL: goto x86_l_189c;
	case 6304ULL: goto x86_l_18a0;
	case 6311ULL: goto x86_l_18a7;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6327ULL: goto x86_l_18b7;
	case 6331ULL: goto x86_l_18bb;
	case 6338ULL: goto x86_l_18c2;
	case 6342ULL: goto x86_l_18c6;
	case 6347ULL: goto x86_l_18cb;
	case 6352ULL: goto x86_l_18d0;
	case 6354ULL: goto x86_l_18d2;
	case 6358ULL: goto x86_l_18d6;
	case 6365ULL: goto x86_l_18dd;
	case 6369ULL: goto x86_l_18e1;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6381ULL: goto x86_l_18ed;
	case 6385ULL: goto x86_l_18f1;
	case 6392ULL: goto x86_l_18f8;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6408ULL: goto x86_l_1908;
	case 6412ULL: goto x86_l_190c;
	case 6419ULL: goto x86_l_1913;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6435ULL: goto x86_l_1923;
	case 6439ULL: goto x86_l_1927;
	case 6446ULL: goto x86_l_192e;
	case 6450ULL: goto x86_l_1932;
	case 6455ULL: goto x86_l_1937;
	case 6460ULL: goto x86_l_193c;
	case 6462ULL: goto x86_l_193e;
	case 6466ULL: goto x86_l_1942;
	case 6476ULL: goto x86_l_194c;
	case 6480ULL: goto x86_l_1950;
	case 6487ULL: goto x86_l_1957;
	case 6491ULL: goto x86_l_195b;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6503ULL: goto x86_l_1967;
	case 6507ULL: goto x86_l_196b;
	case 6511ULL: goto x86_l_196f;
	case 6518ULL: goto x86_l_1976;
	case 6522ULL: goto x86_l_197a;
	case 6526ULL: goto x86_l_197e;
	case 6533ULL: goto x86_l_1985;
	case 6537ULL: goto x86_l_1989;
	case 6541ULL: goto x86_l_198d;
	case 6548ULL: goto x86_l_1994;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6565ULL: goto x86_l_19a5;
	case 6570ULL: goto x86_l_19aa;
	case 6573ULL: goto x86_l_19ad;
	case 6575ULL: goto x86_l_19af;
	case 6580ULL: goto x86_l_19b4;
	case 6587ULL: goto x86_l_19bb;
	case 6592ULL: goto x86_l_19c0;
	case 6595ULL: goto x86_l_19c3;
	case 6600ULL: goto x86_l_19c8;
	case 6602ULL: goto x86_l_19ca;
	case 6606ULL: goto x86_l_19ce;
	case 6613ULL: goto x86_l_19d5;
	case 6620ULL: goto x86_l_19dc;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6632ULL: goto x86_l_19e8;
	case 6636ULL: goto x86_l_19ec;
	case 6643ULL: goto x86_l_19f3;
	case 6650ULL: goto x86_l_19fa;
	case 6655ULL: goto x86_l_19ff;
	case 6660ULL: goto x86_l_1a04;
	case 6662ULL: goto x86_l_1a06;
	case 6666ULL: goto x86_l_1a0a;
	case 6673ULL: goto x86_l_1a11;
	case 6680ULL: goto x86_l_1a18;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6693ULL: goto x86_l_1a25;
	case 6695ULL: goto x86_l_1a27;
	case 6699ULL: goto x86_l_1a2b;
	case 6704ULL: goto x86_l_1a30;
	case 6709ULL: goto x86_l_1a35;
	case 6716ULL: goto x86_l_1a3c;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6731ULL: goto x86_l_1a4b;
	case 6733ULL: goto x86_l_1a4d;
	case 6737ULL: goto x86_l_1a51;
	case 6744ULL: goto x86_l_1a58;
	case 6751ULL: goto x86_l_1a5f;
	case 6756ULL: goto x86_l_1a64;
	case 6761ULL: goto x86_l_1a69;
	case 6763ULL: goto x86_l_1a6b;
	case 6767ULL: goto x86_l_1a6f;
	case 6774ULL: goto x86_l_1a76;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6791ULL: goto x86_l_1a87;
	case 6793ULL: goto x86_l_1a89;
	case 6797ULL: goto x86_l_1a8d;
	case 6804ULL: goto x86_l_1a94;
	case 6811ULL: goto x86_l_1a9b;
	case 6816ULL: goto x86_l_1aa0;
	case 6821ULL: goto x86_l_1aa5;
	case 6824ULL: goto x86_l_1aa8;
	case 6826ULL: goto x86_l_1aaa;
	case 6830ULL: goto x86_l_1aae;
	case 6835ULL: goto x86_l_1ab3;
	case 6840ULL: goto x86_l_1ab8;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6859ULL: goto x86_l_1acb;
	case 6861ULL: goto x86_l_1acd;
	case 6865ULL: goto x86_l_1ad1;
	case 6872ULL: goto x86_l_1ad8;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6888ULL: goto x86_l_1ae8;
	case 6892ULL: goto x86_l_1aec;
	case 6899ULL: goto x86_l_1af3;
	case 6903ULL: goto x86_l_1af7;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6915ULL: goto x86_l_1b03;
	case 6919ULL: goto x86_l_1b07;
	case 6926ULL: goto x86_l_1b0e;
	case 6930ULL: goto x86_l_1b12;
	case 6935ULL: goto x86_l_1b17;
	case 6940ULL: goto x86_l_1b1c;
	case 6942ULL: goto x86_l_1b1e;
	case 6946ULL: goto x86_l_1b22;
	case 6953ULL: goto x86_l_1b29;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6970ULL: goto x86_l_1b3a;
	case 6972ULL: goto x86_l_1b3c;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6986ULL: goto x86_l_1b4a;
	case 6991ULL: goto x86_l_1b4f;
	case 6996ULL: goto x86_l_1b54;
	case 7001ULL: goto x86_l_1b59;
	case 7004ULL: goto x86_l_1b5c;
	case 7006ULL: goto x86_l_1b5e;
	case 7010ULL: goto x86_l_1b62;
	case 7017ULL: goto x86_l_1b69;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7033ULL: goto x86_l_1b79;
	case 7037ULL: goto x86_l_1b7d;
	case 7044ULL: goto x86_l_1b84;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7061ULL: goto x86_l_1b95;
	case 7066ULL: goto x86_l_1b9a;
	case 7070ULL: goto x86_l_1b9e;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7085ULL: goto x86_l_1bad;
	case 7087ULL: goto x86_l_1baf;
	case 7091ULL: goto x86_l_1bb3;
	case 7095ULL: goto x86_l_1bb7;
	case 7101ULL: goto x86_l_1bbd;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7122ULL: goto x86_l_1bd2;
	case 7126ULL: goto x86_l_1bd6;
	case 7130ULL: goto x86_l_1bda;
	case 7136ULL: goto x86_l_1be0;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7150ULL: goto x86_l_1bee;
	case 7155ULL: goto x86_l_1bf3;
	case 7158ULL: goto x86_l_1bf6;
	case 7160ULL: goto x86_l_1bf8;
	case 7164ULL: goto x86_l_1bfc;
	case 7171ULL: goto x86_l_1c03;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7193ULL: goto x86_l_1c19;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7207ULL: goto x86_l_1c27;
	case 7212ULL: goto x86_l_1c2c;
	case 7220ULL: goto x86_l_1c34;
	case 7228ULL: goto x86_l_1c3c;
	case 7236ULL: goto x86_l_1c44;
	case 7244ULL: goto x86_l_1c4c;
	case 7252ULL: goto x86_l_1c54;
	case 7260ULL: goto x86_l_1c5c;
	case 7268ULL: goto x86_l_1c64;
	case 7276ULL: goto x86_l_1c6c;
	case 7284ULL: goto x86_l_1c74;
	case 7287ULL: goto x86_l_1c77;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7304ULL: goto x86_l_1c88;
	case 7309ULL: goto x86_l_1c8d;
	case 7312ULL: goto x86_l_1c90;
	case 7314ULL: goto x86_l_1c92;
	case 7317ULL: goto x86_l_1c95;
	case 7323ULL: goto x86_l_1c9b;
	case 7325ULL: goto x86_l_1c9d;
	case 7329ULL: goto x86_l_1ca1;
	case 7335ULL: goto x86_l_1ca7;
	case 7340ULL: goto x86_l_1cac;
	case 7345ULL: goto x86_l_1cb1;
	case 7350ULL: goto x86_l_1cb6;
	case 7357ULL: goto x86_l_1cbd;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7371ULL: goto x86_l_1ccb;
	case 7376ULL: goto x86_l_1cd0;
	case 7381ULL: goto x86_l_1cd5;
	case 7386ULL: goto x86_l_1cda;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15c7:
	/* 0x15c7: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15cc:
	/* 0x15cc: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d3:
	/* 0x15d3: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_15db:
	/* 0x15db: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15e3:
	/* 0x15e3: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_15eb:
	/* 0x15eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f0:
	/* 0x15f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15f5:
	/* 0x15f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f7:
	/* 0x15f7: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15fb:
	/* 0x15fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1600:
	/* 0x1600: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1603:
	/* 0x1603: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1608:
	/* 0x1608: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_160b:
	/* 0x160b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160d:
	/* 0x160d: lea    rdx,[rbp+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1614:
	/* 0x1614: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1619:
	/* 0x1619: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1621:
	/* 0x1621: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1626:
	/* 0x1626: jmp    280d <generic_retkprobe_event+0x280d> */
	return 10253ULL;
x86_l_162b:
	/* 0x162b: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1630:
	/* 0x1630: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1635:
	/* 0x1635: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1639:
	/* 0x1639: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1640:
	/* 0x1640: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1645:
	/* 0x1645: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_164a:
	/* 0x164a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164c:
	/* 0x164c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_164f:
	/* 0x164f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1652:
	/* 0x1652: js     1cbd <generic_retkprobe_event+0x1cbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cbd;
	}
x86_l_1658:
	/* 0x1658: lea    eax,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_165b:
	/* 0x165b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1660:
	/* 0x1660: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1662:
	/* 0x1662: add    rbp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1666:
	/* 0x1666: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166a:
	/* 0x166a: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_166f:
	/* 0x166f: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_1674:
	/* 0x1674: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1679:
	/* 0x1679: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1681:
	/* 0x1681: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1689:
	/* 0x1689: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1690:
	/* 0x1690: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1695:
	/* 0x1695: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_169a:
	/* 0x169a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_169d:
	/* 0x169d: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_16a0:
	/* 0x16a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a2:
	/* 0x16a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16a5:
	/* 0x16a5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a9:
	/* 0x16a9: js     1f3b <generic_retkprobe_event+0x1f3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7995ULL;
	}
x86_l_16af:
	/* 0x16af: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_16b3:
	/* 0x16b3: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16b7:
	/* 0x16b7: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_16ba:
	/* 0x16ba: je     1ee0 <generic_retkprobe_event+0x1ee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7904ULL;
	}
x86_l_16c0:
	/* 0x16c0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16c3:
	/* 0x16c3: jne    1f18 <generic_retkprobe_event+0x1f18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7960ULL;
	}
x86_l_16c9:
	/* 0x16c9: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16ce:
	/* 0x16ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16d3:
	/* 0x16d3: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16d8:
	/* 0x16d8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16dd:
	/* 0x16dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16df:
	/* 0x16df: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16e3:
	/* 0x16e3: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e7:
	/* 0x16e7: mov    QWORD PTR [rdi+0xa4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_16ee:
	/* 0x16ee: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_16f5:
	/* 0x16f5: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_16f9:
	/* 0x16f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16fe:
	/* 0x16fe: jmp    1f0e <generic_retkprobe_event+0x1f0e> */
	return 7950ULL;
x86_l_1703:
	/* 0x1703: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1706:
	/* 0x1706: cmp    QWORD PTR [rsp+0x88],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552259ULL);
x86_l_170f:
	/* 0x170f: jb     2145 <generic_retkprobe_event+0x2145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8517ULL;
	}
x86_l_1715:
	/* 0x1715: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_171a:
	/* 0x171a: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1722:
	/* 0x1722: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1726:
	/* 0x1726: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_172c:
	/* 0x172c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1731:
	/* 0x1731: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1736:
	/* 0x1736: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_173b:
	/* 0x173b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173d:
	/* 0x173d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1742:
	/* 0x1742: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1744:
	/* 0x1744: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_174a:
	/* 0x174a: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_174f:
	/* 0x174f: cmp    r14,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1752:
	/* 0x1752: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1755:
	/* 0x1755: cmovb  rax,r14 */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R14, X86_WIDTH_64, X86_CC_B);
x86_l_1759:
	/* 0x1759: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_175e:
	/* 0x175e: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1761:
	/* 0x1761: cmovne r14,rax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_64, X86_CC_NE);
x86_l_1765:
	/* 0x1765: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_176a:
	/* 0x176a: cmp    r14,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4094ULL);
x86_l_1771:
	/* 0x1771: ja     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10988ULL;
	}
x86_l_1777:
	/* 0x1777: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_177a:
	/* 0x177a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_177f:
	/* 0x177f: add    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1783:
	/* 0x1783: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1788:
	/* 0x1788: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_178e:
	/* 0x178e: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1791:
	/* 0x1791: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1796:
	/* 0x1796: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_179b:
	/* 0x179b: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_179e:
	/* 0x179e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a0:
	/* 0x17a0: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_17a5:
	/* 0x17a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17a7:
	/* 0x17a7: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_17ad:
	/* 0x17ad: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17b1:
	/* 0x17b1: add    rbx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17b4:
	/* 0x17b4: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_17ba:
	/* 0x17ba: je     2133 <generic_retkprobe_event+0x2133> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8499ULL;
	}
x86_l_17c0:
	/* 0x17c0: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_17c5:
	/* 0x17c5: jne    213a <generic_retkprobe_event+0x213a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8506ULL;
	}
x86_l_17cb:
	/* 0x17cb: jmp    2145 <generic_retkprobe_event+0x2145> */
	return 8517ULL;
x86_l_17d0:
	/* 0x17d0: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17d4:
	/* 0x17d4: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_17dd:
	/* 0x17dd: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_17e6:
	/* 0x17e6: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_17eb:
	/* 0x17eb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17f0:
	/* 0x17f0: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17f5:
	/* 0x17f5: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17fa:
	/* 0x17fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17ff:
	/* 0x17ff: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1802:
	/* 0x1802: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1804:
	/* 0x1804: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1809:
	/* 0x1809: cmp    r14,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4095ULL);
x86_l_1810:
	/* 0x1810: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1816:
	/* 0x1816: cmovb  r12,r14 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R14, X86_WIDTH_64, X86_CC_B);
x86_l_181a:
	/* 0x181a: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_181f:
	/* 0x181f: add    rbx,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1826:
	/* 0x1826: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_182b:
	/* 0x182b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_182e:
	/* 0x182e: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1831:
	/* 0x1831: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1834:
	/* 0x1834: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1836:
	/* 0x1836: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_183b:
	/* 0x183b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_183d:
	/* 0x183d: js     1855 <generic_retkprobe_event+0x1855> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1855;
	}
x86_l_183f:
	/* 0x183f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1844:
	/* 0x1844: mov    DWORD PTR [rax+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_184b:
	/* 0x184b: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_184f:
	/* 0x184f: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1852:
	/* 0x1852: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1855:
	/* 0x1855: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_185a:
	/* 0x185a: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1860:
	/* 0x1860: jmp    20e1 <generic_retkprobe_event+0x20e1> */
	return 8417ULL;
x86_l_1865:
	/* 0x1865: lea    r12,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_186c:
	/* 0x186c: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1870:
	/* 0x1870: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1875:
	/* 0x1875: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_187a:
	/* 0x187a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_187f:
	/* 0x187f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1881:
	/* 0x1881: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1885:
	/* 0x1885: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_188c:
	/* 0x188c: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1890:
	/* 0x1890: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1895:
	/* 0x1895: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_189a:
	/* 0x189a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189c:
	/* 0x189c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a0:
	/* 0x18a0: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_18a7:
	/* 0x18a7: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18ab:
	/* 0x18ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18b0:
	/* 0x18b0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18b5:
	/* 0x18b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b7:
	/* 0x18b7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18bb:
	/* 0x18bb: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_18c2:
	/* 0x18c2: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18c6:
	/* 0x18c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18cb:
	/* 0x18cb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18d0:
	/* 0x18d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d2:
	/* 0x18d2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d6:
	/* 0x18d6: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_18dd:
	/* 0x18dd: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18e1:
	/* 0x18e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e6:
	/* 0x18e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18eb:
	/* 0x18eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ed:
	/* 0x18ed: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f1:
	/* 0x18f1: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_18f8:
	/* 0x18f8: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_18fc:
	/* 0x18fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1901:
	/* 0x1901: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1906:
	/* 0x1906: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1908:
	/* 0x1908: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190c:
	/* 0x190c: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1913:
	/* 0x1913: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1917:
	/* 0x1917: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_191c:
	/* 0x191c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1921:
	/* 0x1921: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1923:
	/* 0x1923: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1927:
	/* 0x1927: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_192e:
	/* 0x192e: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1932:
	/* 0x1932: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1937:
	/* 0x1937: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_193c:
	/* 0x193c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193e:
	/* 0x193e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1942:
	/* 0x1942: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_194c:
	/* 0x194c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1950:
	/* 0x1950: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1957:
	/* 0x1957: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_195b:
	/* 0x195b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1960:
	/* 0x1960: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1965:
	/* 0x1965: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1967:
	/* 0x1967: mov    rcx,QWORD PTR [r13+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_196b:
	/* 0x196b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196f:
	/* 0x196f: mov    QWORD PTR [rax+0xcc],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1976:
	/* 0x1976: mov    rcx,QWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_197a:
	/* 0x197a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197e:
	/* 0x197e: mov    QWORD PTR [rax+0xd4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1985:
	/* 0x1985: mov    rcx,QWORD PTR [r13+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1989:
	/* 0x1989: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_198d:
	/* 0x198d: mov    QWORD PTR [rax+0xc4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1994:
	/* 0x1994: add    r13,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_199b:
	/* 0x199b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a0:
	/* 0x19a0: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19a5:
	/* 0x19a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19aa:
	/* 0x19aa: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_19ad:
	/* 0x19ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19af:
	/* 0x19af: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19b4:
	/* 0x19b4: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_19bb:
	/* 0x19bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19c0:
	/* 0x19c0: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_19c3:
	/* 0x19c3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19c8:
	/* 0x19c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ca:
	/* 0x19ca: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ce:
	/* 0x19ce: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_19d5:
	/* 0x19d5: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_19dc:
	/* 0x19dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19e1:
	/* 0x19e1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19e6:
	/* 0x19e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e8:
	/* 0x19e8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ec:
	/* 0x19ec: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_19f3:
	/* 0x19f3: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_19fa:
	/* 0x19fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19ff:
	/* 0x19ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a04:
	/* 0x1a04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a06:
	/* 0x1a06: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a0a:
	/* 0x1a0a: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1a11:
	/* 0x1a11: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1a18:
	/* 0x1a18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a22:
	/* 0x1a22: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1a25:
	/* 0x1a25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a27:
	/* 0x1a27: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_1a30:
	/* 0x1a30: jmp    1ca7 <generic_retkprobe_event+0x1ca7> */
	goto x86_l_1ca7;
x86_l_1a35:
	/* 0x1a35: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1a3c:
	/* 0x1a3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a41:
	/* 0x1a41: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a46:
	/* 0x1a46: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a4b:
	/* 0x1a4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4d:
	/* 0x1a4d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a51:
	/* 0x1a51: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a58:
	/* 0x1a58: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1a5f:
	/* 0x1a5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a64:
	/* 0x1a64: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a69:
	/* 0x1a69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6b:
	/* 0x1a6b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a6f:
	/* 0x1a6f: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1a76:
	/* 0x1a76: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a82:
	/* 0x1a82: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a87:
	/* 0x1a87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a89:
	/* 0x1a89: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8d:
	/* 0x1a8d: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1a94:
	/* 0x1a94: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aa0:
	/* 0x1aa0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aa5:
	/* 0x1aa5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1aa8:
	/* 0x1aa8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aaa:
	/* 0x1aaa: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aae:
	/* 0x1aae: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1ab3:
	/* 0x1ab3: jmp    1ca7 <generic_retkprobe_event+0x1ca7> */
	goto x86_l_1ca7;
x86_l_1ab8:
	/* 0x1ab8: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1abc:
	/* 0x1abc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1acb:
	/* 0x1acb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acd:
	/* 0x1acd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ad1:
	/* 0x1ad1: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ad8:
	/* 0x1ad8: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1adc:
	/* 0x1adc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ae6:
	/* 0x1ae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae8:
	/* 0x1ae8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aec:
	/* 0x1aec: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1af3:
	/* 0x1af3: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1af7:
	/* 0x1af7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1afc:
	/* 0x1afc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b01:
	/* 0x1b01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b03:
	/* 0x1b03: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b07:
	/* 0x1b07: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1b0e:
	/* 0x1b0e: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b12:
	/* 0x1b12: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b17:
	/* 0x1b17: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b1c:
	/* 0x1b1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b1e:
	/* 0x1b1e: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b22:
	/* 0x1b22: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1b29:
	/* 0x1b29: add    r13,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1b2d:
	/* 0x1b2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b32:
	/* 0x1b32: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b37:
	/* 0x1b37: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b3a:
	/* 0x1b3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3c:
	/* 0x1b3c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b40:
	/* 0x1b40: mov    ebp,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_1b45:
	/* 0x1b45: jmp    1ca7 <generic_retkprobe_event+0x1ca7> */
	goto x86_l_1ca7;
x86_l_1b4a:
	/* 0x1b4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b4f:
	/* 0x1b4f: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b54:
	/* 0x1b54: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b59:
	/* 0x1b59: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b5c:
	/* 0x1b5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5e:
	/* 0x1b5e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b62:
	/* 0x1b62: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b69:
	/* 0x1b69: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b6d:
	/* 0x1b6d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b72:
	/* 0x1b72: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b77:
	/* 0x1b77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b79:
	/* 0x1b79: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b7d:
	/* 0x1b7d: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1b84:
	/* 0x1b84: add    r13,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1b88:
	/* 0x1b88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b92:
	/* 0x1b92: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b95:
	/* 0x1b95: jmp    1c17 <generic_retkprobe_event+0x1c17> */
	goto x86_l_1c17;
x86_l_1b9a:
	/* 0x1b9a: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b9e:
	/* 0x1b9e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ba3:
	/* 0x1ba3: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bad:
	/* 0x1bad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1baf:
	/* 0x1baf: mov    ecx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bb3:
	/* 0x1bb3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1bbd:
	/* 0x1bbd: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bc6:
	/* 0x1bc6: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bcb:
	/* 0x1bcb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bd0:
	/* 0x1bd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd2:
	/* 0x1bd2: mov    ecx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bd6:
	/* 0x1bd6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bda:
	/* 0x1bda: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1be0:
	/* 0x1be0: add    r13,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1be4:
	/* 0x1be4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1be9:
	/* 0x1be9: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bee:
	/* 0x1bee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1bf6:
	/* 0x1bf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf8:
	/* 0x1bf8: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bfc:
	/* 0x1bfc: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1c03:
	/* 0x1c03: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1c08:
	/* 0x1c08: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1c0d:
	/* 0x1c0d: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1c12:
	/* 0x1c12: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c17:
	/* 0x1c17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c19:
	/* 0x1c19: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1c22:
	/* 0x1c22: jmp    1ca7 <generic_retkprobe_event+0x1ca7> */
	goto x86_l_1ca7;
x86_l_1c27:
	/* 0x1c27: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c2c:
	/* 0x1c2c: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1c34:
	/* 0x1c34: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1c3c:
	/* 0x1c3c: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1c44:
	/* 0x1c44: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c4c:
	/* 0x1c4c: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1c54:
	/* 0x1c54: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c5c:
	/* 0x1c5c: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1c64:
	/* 0x1c64: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c6c:
	/* 0x1c6c: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1c74:
	/* 0x1c74: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1c77:
	/* 0x1c77: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c83:
	/* 0x1c83: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c88:
	/* 0x1c88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c8d:
	/* 0x1c8d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c90:
	/* 0x1c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c92:
	/* 0x1c92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c95:
	/* 0x1c95: je     1f4a <generic_retkprobe_event+0x1f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8010ULL;
	}
x86_l_1c9b:
	/* 0x1c9b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c9d:
	/* 0x1c9d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca1:
	/* 0x1ca1: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1ca7:
	/* 0x1ca7: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cac:
	/* 0x1cac: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cb1:
	/* 0x1cb1: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_1cb6:
	/* 0x1cb6: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1cbd:
	/* 0x1cbd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc1:
	/* 0x1cc1: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cc6:
	/* 0x1cc6: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_1ccb:
	/* 0x1ccb: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd0:
	/* 0x1cd0: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1cd5:
	/* 0x1cd5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cda:
	/* 0x1cda: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
	return 7391ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7391ULL: goto x86_l_1cdf;
	case 7396ULL: goto x86_l_1ce4;
	case 7398ULL: goto x86_l_1ce6;
	case 7402ULL: goto x86_l_1cea;
	case 7407ULL: goto x86_l_1cef;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7423ULL: goto x86_l_1cff;
	case 7425ULL: goto x86_l_1d01;
	case 7430ULL: goto x86_l_1d06;
	case 7438ULL: goto x86_l_1d0e;
	case 7445ULL: goto x86_l_1d15;
	case 7451ULL: goto x86_l_1d1b;
	case 7455ULL: goto x86_l_1d1f;
	case 7458ULL: goto x86_l_1d22;
	case 7465ULL: goto x86_l_1d29;
	case 7470ULL: goto x86_l_1d2e;
	case 7473ULL: goto x86_l_1d31;
	case 7475ULL: goto x86_l_1d33;
	case 7477ULL: goto x86_l_1d35;
	case 7479ULL: goto x86_l_1d37;
	case 7486ULL: goto x86_l_1d3e;
	case 7493ULL: goto x86_l_1d45;
	case 7497ULL: goto x86_l_1d49;
	case 7500ULL: goto x86_l_1d4c;
	case 7505ULL: goto x86_l_1d51;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7525ULL: goto x86_l_1d65;
	case 7533ULL: goto x86_l_1d6d;
	case 7536ULL: goto x86_l_1d70;
	case 7540ULL: goto x86_l_1d74;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7567ULL: goto x86_l_1d8f;
	case 7570ULL: goto x86_l_1d92;
	case 7576ULL: goto x86_l_1d98;
	case 7579ULL: goto x86_l_1d9b;
	case 7582ULL: goto x86_l_1d9e;
	case 7586ULL: goto x86_l_1da2;
	case 7590ULL: goto x86_l_1da6;
	case 7593ULL: goto x86_l_1da9;
	case 7597ULL: goto x86_l_1dad;
	case 7601ULL: goto x86_l_1db1;
	case 7606ULL: goto x86_l_1db6;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7616ULL: goto x86_l_1dc0;
	case 7619ULL: goto x86_l_1dc3;
	case 7625ULL: goto x86_l_1dc9;
	case 7630ULL: goto x86_l_1dce;
	case 7633ULL: goto x86_l_1dd1;
	case 7639ULL: goto x86_l_1dd7;
	case 7641ULL: goto x86_l_1dd9;
	case 7647ULL: goto x86_l_1ddf;
	case 7650ULL: goto x86_l_1de2;
	case 7656ULL: goto x86_l_1de8;
	case 7659ULL: goto x86_l_1deb;
	case 7665ULL: goto x86_l_1df1;
	case 7672ULL: goto x86_l_1df8;
	case 7676ULL: goto x86_l_1dfc;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7691ULL: goto x86_l_1e0b;
	case 7696ULL: goto x86_l_1e10;
	case 7698ULL: goto x86_l_1e12;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7711ULL: goto x86_l_1e1f;
	case 7716ULL: goto x86_l_1e24;
	case 7718ULL: goto x86_l_1e26;
	case 7722ULL: goto x86_l_1e2a;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7738ULL: goto x86_l_1e3a;
	case 7743ULL: goto x86_l_1e3f;
	case 7748ULL: goto x86_l_1e44;
	case 7751ULL: goto x86_l_1e47;
	case 7753ULL: goto x86_l_1e49;
	case 7756ULL: goto x86_l_1e4c;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7773ULL: goto x86_l_1e5d;
	case 7776ULL: goto x86_l_1e60;
	case 7778ULL: goto x86_l_1e62;
	case 7785ULL: goto x86_l_1e69;
	case 7794ULL: goto x86_l_1e72;
	case 7799ULL: goto x86_l_1e77;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7816ULL: goto x86_l_1e88;
	case 7821ULL: goto x86_l_1e8d;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7828ULL: goto x86_l_1e94;
	case 7830ULL: goto x86_l_1e96;
	case 7835ULL: goto x86_l_1e9b;
	case 7838ULL: goto x86_l_1e9e;
	case 7842ULL: goto x86_l_1ea2;
	case 7846ULL: goto x86_l_1ea6;
	case 7849ULL: goto x86_l_1ea9;
	case 7852ULL: goto x86_l_1eac;
	case 7857ULL: goto x86_l_1eb1;
	case 7859ULL: goto x86_l_1eb3;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7890ULL: goto x86_l_1ed2;
	case 7894ULL: goto x86_l_1ed6;
	case 7899ULL: goto x86_l_1edb;
	case 7904ULL: goto x86_l_1ee0;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7921ULL: goto x86_l_1ef1;
	case 7926ULL: goto x86_l_1ef6;
	case 7929ULL: goto x86_l_1ef9;
	case 7931ULL: goto x86_l_1efb;
	case 7934ULL: goto x86_l_1efe;
	case 7941ULL: goto x86_l_1f05;
	case 7945ULL: goto x86_l_1f09;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7958ULL: goto x86_l_1f16;
	case 7960ULL: goto x86_l_1f18;
	case 7964ULL: goto x86_l_1f1c;
	case 7971ULL: goto x86_l_1f23;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7991ULL: goto x86_l_1f37;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8014ULL: goto x86_l_1f4e;
	case 8021ULL: goto x86_l_1f55;
	case 8026ULL: goto x86_l_1f5a;
	case 8031ULL: goto x86_l_1f5f;
	case 8036ULL: goto x86_l_1f64;
	case 8038ULL: goto x86_l_1f66;
	case 8041ULL: goto x86_l_1f69;
	case 8047ULL: goto x86_l_1f6f;
	case 8051ULL: goto x86_l_1f73;
	case 8056ULL: goto x86_l_1f78;
	case 8061ULL: goto x86_l_1f7d;
	case 8066ULL: goto x86_l_1f82;
	case 8068ULL: goto x86_l_1f84;
	case 8072ULL: goto x86_l_1f88;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8094ULL: goto x86_l_1f9e;
	case 8099ULL: goto x86_l_1fa3;
	case 8101ULL: goto x86_l_1fa5;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8115ULL: goto x86_l_1fb3;
	case 8120ULL: goto x86_l_1fb8;
	case 8123ULL: goto x86_l_1fbb;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8133ULL: goto x86_l_1fc5;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8149ULL: goto x86_l_1fd5;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8159ULL: goto x86_l_1fdf;
	case 8163ULL: goto x86_l_1fe3;
	case 8169ULL: goto x86_l_1fe9;
	case 8173ULL: goto x86_l_1fed;
	case 8178ULL: goto x86_l_1ff2;
	case 8182ULL: goto x86_l_1ff6;
	case 8187ULL: goto x86_l_1ffb;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8197ULL: goto x86_l_2005;
	case 8200ULL: goto x86_l_2008;
	case 8202ULL: goto x86_l_200a;
	case 8204ULL: goto x86_l_200c;
	case 8206ULL: goto x86_l_200e;
	case 8210ULL: goto x86_l_2012;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8235ULL: goto x86_l_202b;
	case 8240ULL: goto x86_l_2030;
	case 8245ULL: goto x86_l_2035;
	case 8250ULL: goto x86_l_203a;
	case 8255ULL: goto x86_l_203f;
	case 8257ULL: goto x86_l_2041;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8270ULL: goto x86_l_204e;
	case 8275ULL: goto x86_l_2053;
	case 8277ULL: goto x86_l_2055;
	case 8281ULL: goto x86_l_2059;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8307ULL: goto x86_l_2073;
	case 8310ULL: goto x86_l_2076;
	case 8312ULL: goto x86_l_2078;
	case 8315ULL: goto x86_l_207b;
	case 8322ULL: goto x86_l_2082;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8335ULL: goto x86_l_208f;
	case 8337ULL: goto x86_l_2091;
	case 8344ULL: goto x86_l_2098;
	case 8353ULL: goto x86_l_20a1;
	case 8357ULL: goto x86_l_20a5;
	case 8364ULL: goto x86_l_20ac;
	case 8369ULL: goto x86_l_20b1;
	case 8374ULL: goto x86_l_20b6;
	case 8381ULL: goto x86_l_20bd;
	case 8386ULL: goto x86_l_20c2;
	case 8388ULL: goto x86_l_20c4;
	case 8391ULL: goto x86_l_20c7;
	case 8393ULL: goto x86_l_20c9;
	case 8395ULL: goto x86_l_20cb;
	case 8398ULL: goto x86_l_20ce;
	case 8402ULL: goto x86_l_20d2;
	case 8406ULL: goto x86_l_20d6;
	case 8409ULL: goto x86_l_20d9;
	case 8412ULL: goto x86_l_20dc;
	case 8417ULL: goto x86_l_20e1;
	case 8421ULL: goto x86_l_20e5;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8444ULL: goto x86_l_20fc;
	case 8450ULL: goto x86_l_2102;
	case 8453ULL: goto x86_l_2105;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8466ULL: goto x86_l_2112;
	case 8473ULL: goto x86_l_2119;
	case 8477ULL: goto x86_l_211d;
	case 8482ULL: goto x86_l_2122;
	case 8487ULL: goto x86_l_2127;
	case 8494ULL: goto x86_l_212e;
	case 8499ULL: goto x86_l_2133;
	case 8501ULL: goto x86_l_2135;
	case 8506ULL: goto x86_l_213a;
	case 8515ULL: goto x86_l_2143;
	case 8517ULL: goto x86_l_2145;
	case 8520ULL: goto x86_l_2148;
	case 8525ULL: goto x86_l_214d;
	case 8533ULL: goto x86_l_2155;
	case 8537ULL: goto x86_l_2159;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8553ULL: goto x86_l_2169;
	case 8558ULL: goto x86_l_216e;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8567ULL: goto x86_l_2177;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8583ULL: goto x86_l_2187;
	case 8586ULL: goto x86_l_218a;
	case 8589ULL: goto x86_l_218d;
	case 8593ULL: goto x86_l_2191;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8603ULL: goto x86_l_219b;
	case 8608ULL: goto x86_l_21a0;
	case 8615ULL: goto x86_l_21a7;
	case 8621ULL: goto x86_l_21ad;
	case 8624ULL: goto x86_l_21b0;
	case 8628ULL: goto x86_l_21b4;
	case 8633ULL: goto x86_l_21b9;
	case 8637ULL: goto x86_l_21bd;
	case 8643ULL: goto x86_l_21c3;
	case 8646ULL: goto x86_l_21c6;
	case 8651ULL: goto x86_l_21cb;
	case 8656ULL: goto x86_l_21d0;
	case 8659ULL: goto x86_l_21d3;
	case 8661ULL: goto x86_l_21d5;
	case 8666ULL: goto x86_l_21da;
	case 8668ULL: goto x86_l_21dc;
	case 8674ULL: goto x86_l_21e2;
	case 8677ULL: goto x86_l_21e5;
	case 8683ULL: goto x86_l_21eb;
	case 8689ULL: goto x86_l_21f1;
	case 8694ULL: goto x86_l_21f6;
	case 8700ULL: goto x86_l_21fc;
	case 8705ULL: goto x86_l_2201;
	case 8710ULL: goto x86_l_2206;
	case 8717ULL: goto x86_l_220d;
	case 8722ULL: goto x86_l_2212;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8741ULL: goto x86_l_2225;
	case 8747ULL: goto x86_l_222b;
	case 8757ULL: goto x86_l_2235;
	case 8761ULL: goto x86_l_2239;
	case 8767ULL: goto x86_l_223f;
	case 8771ULL: goto x86_l_2243;
	case 8776ULL: goto x86_l_2248;
	case 8781ULL: goto x86_l_224d;
	case 8784ULL: goto x86_l_2250;
	case 8787ULL: goto x86_l_2253;
	case 8792ULL: goto x86_l_2258;
	case 8794ULL: goto x86_l_225a;
	case 8797ULL: goto x86_l_225d;
	case 8803ULL: goto x86_l_2263;
	case 8808ULL: goto x86_l_2268;
	case 8811ULL: goto x86_l_226b;
	case 8813ULL: goto x86_l_226d;
	case 8815ULL: goto x86_l_226f;
	case 8817ULL: goto x86_l_2271;
	case 8820ULL: goto x86_l_2274;
	case 8822ULL: goto x86_l_2276;
	case 8825ULL: goto x86_l_2279;
	case 8827ULL: goto x86_l_227b;
	case 8834ULL: goto x86_l_2282;
	case 8838ULL: goto x86_l_2286;
	case 8840ULL: goto x86_l_2288;
	case 8843ULL: goto x86_l_228b;
	case 8845ULL: goto x86_l_228d;
	case 8848ULL: goto x86_l_2290;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8857ULL: goto x86_l_2299;
	case 8864ULL: goto x86_l_22a0;
	case 8868ULL: goto x86_l_22a4;
	case 8870ULL: goto x86_l_22a6;
	case 8875ULL: goto x86_l_22ab;
	case 8882ULL: goto x86_l_22b2;
	case 8887ULL: goto x86_l_22b7;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8899ULL: goto x86_l_22c3;
	case 8904ULL: goto x86_l_22c8;
	case 8911ULL: goto x86_l_22cf;
	case 8916ULL: goto x86_l_22d4;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8938ULL: goto x86_l_22ea;
	case 8942ULL: goto x86_l_22ee;
	case 8948ULL: goto x86_l_22f4;
	case 8958ULL: goto x86_l_22fe;
	case 8962ULL: goto x86_l_2302;
	case 8968ULL: goto x86_l_2308;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8985ULL: goto x86_l_2319;
	case 8988ULL: goto x86_l_231c;
	case 8993ULL: goto x86_l_2321;
	case 8995ULL: goto x86_l_2323;
	case 8998ULL: goto x86_l_2326;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9012ULL: goto x86_l_2334;
	case 9014ULL: goto x86_l_2336;
	case 9016ULL: goto x86_l_2338;
	case 9018ULL: goto x86_l_233a;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9026ULL: goto x86_l_2342;
	case 9028ULL: goto x86_l_2344;
	case 9035ULL: goto x86_l_234b;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9044ULL: goto x86_l_2354;
	case 9046ULL: goto x86_l_2356;
	case 9049ULL: goto x86_l_2359;
	case 9051ULL: goto x86_l_235b;
	case 9056ULL: goto x86_l_2360;
	case 9058ULL: goto x86_l_2362;
	case 9065ULL: goto x86_l_2369;
	case 9069ULL: goto x86_l_236d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1cdf:
	/* 0x1cdf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ce4:
	/* 0x1ce4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce6:
	/* 0x1ce6: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1cea:
	/* 0x1cea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cef:
	/* 0x1cef: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1cf7:
	/* 0x1cf7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1cff:
	/* 0x1cff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d01:
	/* 0x1d01: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d06:
	/* 0x1d06: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1d0e:
	/* 0x1d0e: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1d15:
	/* 0x1d15: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1d1b:
	/* 0x1d1b: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_1d1f:
	/* 0x1d1f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d22:
	/* 0x1d22: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1d29:
	/* 0x1d29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d2e:
	/* 0x1d2e: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1d31:
	/* 0x1d31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d33:
	/* 0x1d33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d35:
	/* 0x1d35: js     1d51 <generic_retkprobe_event+0x1d51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d51;
	}
x86_l_1d37:
	/* 0x1d37: mov    DWORD PTR [rbx+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1d3e:
	/* 0x1d3e: mov    DWORD PTR [rbx+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d45:
	/* 0x1d45: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d49:
	/* 0x1d49: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1d4c:
	/* 0x1d4c: jmp    1ec3 <generic_retkprobe_event+0x1ec3> */
	goto x86_l_1ec3;
x86_l_1d51:
	/* 0x1d51: mov    DWORD PTR [rbx+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_1d5b:
	/* 0x1d5b: jmp    1ec3 <generic_retkprobe_event+0x1ec3> */
	goto x86_l_1ec3;
x86_l_1d60:
	/* 0x1d60: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d65:
	/* 0x1d65: movzx  ebx,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1d70:
	/* 0x1d70: lea    r14,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1d74:
	/* 0x1d74: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1d7c:
	/* 0x1d7c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d81:
	/* 0x1d81: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1d88:
	/* 0x1d88: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d8d:
	/* 0x1d8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8f:
	/* 0x1d8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d92:
	/* 0x1d92: je     27c0 <generic_retkprobe_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10176ULL;
	}
x86_l_1d98:
	/* 0x1d98: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1d9b:
	/* 0x1d9b: mov    WORD PTR [rax],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d9e:
	/* 0x1d9e: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1da2:
	/* 0x1da2: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1da6:
	/* 0x1da6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1da9:
	/* 0x1da9: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1dad:
	/* 0x1dad: lea    rdx,[r14+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1db1:
	/* 0x1db1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1db6:
	/* 0x1db6: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1db9:
	/* 0x1db9: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1dbe:
	/* 0x1dbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc0:
	/* 0x1dc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dc3:
	/* 0x1dc3: js     27c0 <generic_retkprobe_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10176ULL;
	}
x86_l_1dc9:
	/* 0x1dc9: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1dce:
	/* 0x1dce: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1dd1:
	/* 0x1dd1: jg     20f9 <generic_retkprobe_event+0x20f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_20f9;
	}
x86_l_1dd7:
	/* 0x1dd7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dd9:
	/* 0x1dd9: je     2122 <generic_retkprobe_event+0x2122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2122;
	}
x86_l_1ddf:
	/* 0x1ddf: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1de2:
	/* 0x1de2: je     2122 <generic_retkprobe_event+0x2122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2122;
	}
x86_l_1de8:
	/* 0x1de8: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1deb:
	/* 0x1deb: jne    22b9 <generic_retkprobe_event+0x22b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22b9;
	}
x86_l_1df1:
	/* 0x1df1: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1df8:
	/* 0x1df8: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1dfc:
	/* 0x1dfc: jmp    2212 <generic_retkprobe_event+0x2212> */
	goto x86_l_2212;
x86_l_1e01:
	/* 0x1e01: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e06:
	/* 0x1e06: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e0b:
	/* 0x1e0b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e10:
	/* 0x1e10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e12:
	/* 0x1e12: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e17:
	/* 0x1e17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e1c:
	/* 0x1e1c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1e1f:
	/* 0x1e1f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e24:
	/* 0x1e24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e26:
	/* 0x1e26: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e2a:
	/* 0x1e2a: lea    rdi,[rbx+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1e31:
	/* 0x1e31: lea    r13,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e36:
	/* 0x1e36: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1e3a:
	/* 0x1e3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e3f:
	/* 0x1e3f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e44:
	/* 0x1e44: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e47:
	/* 0x1e47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e49:
	/* 0x1e49: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e4c:
	/* 0x1e4c: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1e53:
	/* 0x1e53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e58:
	/* 0x1e58: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e5d:
	/* 0x1e5d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1e60:
	/* 0x1e60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e62:
	/* 0x1e62: movzx  eax,WORD PTR [rbx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1e69:
	/* 0x1e69: movbe  WORD PTR [rbx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1e72:
	/* 0x1e72: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e77:
	/* 0x1e77: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e7c:
	/* 0x1e7c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e81:
	/* 0x1e81: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1e88:
	/* 0x1e88: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e8d:
	/* 0x1e8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8f:
	/* 0x1e8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e92:
	/* 0x1e92: je     1eac <generic_retkprobe_event+0x1eac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eac;
	}
x86_l_1e94:
	/* 0x1e94: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e96:
	/* 0x1e96: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e9b:
	/* 0x1e9b: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e9e:
	/* 0x1e9e: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea2:
	/* 0x1ea2: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ea9:
	/* 0x1ea9: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1eac:
	/* 0x1eac: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_1eb1:
	/* 0x1eb1: jmp    1ec3 <generic_retkprobe_event+0x1ec3> */
	goto x86_l_1ec3;
x86_l_1eb3:
	/* 0x1eb3: mov    QWORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1ebe:
	/* 0x1ebe: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ec7:
	/* 0x1ec7: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1ed2:
	/* 0x1ed2: mov    ebx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ed6:
	/* 0x1ed6: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1edb:
	/* 0x1edb: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_1ee0:
	/* 0x1ee0: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1ee7:
	/* 0x1ee7: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eec:
	/* 0x1eec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ef6:
	/* 0x1ef6: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1ef9:
	/* 0x1ef9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1efb:
	/* 0x1efb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1efe:
	/* 0x1efe: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_1f05:
	/* 0x1f05: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1f09:
	/* 0x1f09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f0e:
	/* 0x1f0e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f13:
	/* 0x1f13: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f16:
	/* 0x1f16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f18:
	/* 0x1f18: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f1c:
	/* 0x1f1c: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1f23:
	/* 0x1f23: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1f2c:
	/* 0x1f2c: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f31:
	/* 0x1f31: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1f37:
	/* 0x1f37: mov    ebx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1f40:
	/* 0x1f40: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f45:
	/* 0x1f45: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_1f4a:
	/* 0x1f4a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f4e:
	/* 0x1f4e: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1f55:
	/* 0x1f55: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f5a:
	/* 0x1f5a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f5f:
	/* 0x1f5f: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1f64:
	/* 0x1f64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f66:
	/* 0x1f66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f69:
	/* 0x1f69: js     1c9b <generic_retkprobe_event+0x1c9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7323ULL;
	}
x86_l_1f6f:
	/* 0x1f6f: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f73:
	/* 0x1f73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f78:
	/* 0x1f78: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f7d:
	/* 0x1f7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f82:
	/* 0x1f82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f84:
	/* 0x1f84: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f88:
	/* 0x1f88: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1f8f:
	/* 0x1f8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f94:
	/* 0x1f94: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1f99:
	/* 0x1f99: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1f9e:
	/* 0x1f9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa3:
	/* 0x1fa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa5:
	/* 0x1fa5: add    r13,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_1fa9:
	/* 0x1fa9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fae:
	/* 0x1fae: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fb3:
	/* 0x1fb3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fb8:
	/* 0x1fb8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1fbb:
	/* 0x1fbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fbd:
	/* 0x1fbd: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_1fc2:
	/* 0x1fc2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fc5:
	/* 0x1fc5: jne    1c9d <generic_retkprobe_event+0x1c9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7325ULL;
	}
x86_l_1fcb:
	/* 0x1fcb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fcd:
	/* 0x1fcd: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1fd2:
	/* 0x1fd2: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1fd5:
	/* 0x1fd5: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fd8:
	/* 0x1fd8: jmp    1c9d <generic_retkprobe_event+0x1c9d> */
	return 7325ULL;
x86_l_1fdd:
	/* 0x1fdd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fdf:
	/* 0x1fdf: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe3:
	/* 0x1fe3: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1fe9:
	/* 0x1fe9: mov    ebx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fed:
	/* 0x1fed: jmp    1cac <generic_retkprobe_event+0x1cac> */
	return 7340ULL;
x86_l_1ff2:
	/* 0x1ff2: add    r12,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1ff6:
	/* 0x1ff6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_2000:
	/* 0x2000: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2003:
	/* 0x2003: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2005:
	/* 0x2005: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2008:
	/* 0x2008: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_200a:
	/* 0x200a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_200c:
	/* 0x200c: js     2018 <generic_retkprobe_event+0x2018> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2018;
	}
x86_l_200e:
	/* 0x200e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2012:
	/* 0x2012: mov    BYTE PTR [rcx+0x9f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_2018:
	/* 0x2018: mov    ebp,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 112ULL);
x86_l_201d:
	/* 0x201d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2021:
	/* 0x2021: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2026:
	/* 0x2026: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_202b:
	/* 0x202b: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_2030:
	/* 0x2030: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2035:
	/* 0x2035: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_203a:
	/* 0x203a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_203f:
	/* 0x203f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2041:
	/* 0x2041: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2046:
	/* 0x2046: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_204b:
	/* 0x204b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_204e:
	/* 0x204e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2053:
	/* 0x2053: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2055:
	/* 0x2055: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2059:
	/* 0x2059: lea    rdi,[rbx+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2060:
	/* 0x2060: lea    r13,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2065:
	/* 0x2065: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2069:
	/* 0x2069: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_206e:
	/* 0x206e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2073:
	/* 0x2073: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2076:
	/* 0x2076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2078:
	/* 0x2078: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_207b:
	/* 0x207b: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_2082:
	/* 0x2082: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2087:
	/* 0x2087: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_208c:
	/* 0x208c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_208f:
	/* 0x208f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2091:
	/* 0x2091: movzx  eax,WORD PTR [rbx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2098:
	/* 0x2098: movbe  WORD PTR [rbx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_20a1:
	/* 0x20a1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a5:
	/* 0x20a5: mov    rax,QWORD PTR [rax+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_20ac:
	/* 0x20ac: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20b1:
	/* 0x20b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20b6:
	/* 0x20b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_20bd:
	/* 0x20bd: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20c2:
	/* 0x20c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c4:
	/* 0x20c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20c7:
	/* 0x20c7: je     20dc <generic_retkprobe_event+0x20dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20dc;
	}
x86_l_20c9:
	/* 0x20c9: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20cb:
	/* 0x20cb: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20ce:
	/* 0x20ce: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20d2:
	/* 0x20d2: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20d6:
	/* 0x20d6: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20d9:
	/* 0x20d9: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_20dc:
	/* 0x20dc: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_20e1:
	/* 0x20e1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e5:
	/* 0x20e5: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_20eb:
	/* 0x20eb: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20f0:
	/* 0x20f0: mov    ebx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20f4:
	/* 0x20f4: jmp    1cac <generic_retkprobe_event+0x1cac> */
	return 7340ULL;
x86_l_20f9:
	/* 0x20f9: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_20fc:
	/* 0x20fc: je     2201 <generic_retkprobe_event+0x2201> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2201;
	}
x86_l_2102:
	/* 0x2102: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2105:
	/* 0x2105: je     2122 <generic_retkprobe_event+0x2122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2122;
	}
x86_l_2107:
	/* 0x2107: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_210c:
	/* 0x210c: jne    22b9 <generic_retkprobe_event+0x22b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22b9;
	}
x86_l_2112:
	/* 0x2112: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2119:
	/* 0x2119: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_211d:
	/* 0x211d: jmp    2212 <generic_retkprobe_event+0x2212> */
	goto x86_l_2212;
x86_l_2122:
	/* 0x2122: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2127:
	/* 0x2127: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_212e:
	/* 0x212e: jmp    220d <generic_retkprobe_event+0x220d> */
	goto x86_l_220d;
x86_l_2133:
	/* 0x2133: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2135:
	/* 0x2135: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_213a:
	/* 0x213a: cmp    QWORD PTR [rsp+0x88],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552259ULL);
x86_l_2143:
	/* 0x2143: jne    214d <generic_retkprobe_event+0x214d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_214d;
	}
x86_l_2145:
	/* 0x2145: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_2148:
	/* 0x2148: jmp    335 <generic_retkprobe_event+0x335> */
	return 821ULL;
x86_l_214d:
	/* 0x214d: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2155:
	/* 0x2155: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2159:
	/* 0x2159: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_215f:
	/* 0x215f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2164:
	/* 0x2164: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2169:
	/* 0x2169: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_216e:
	/* 0x216e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2170:
	/* 0x2170: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2175:
	/* 0x2175: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2177:
	/* 0x2177: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_217d:
	/* 0x217d: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2182:
	/* 0x2182: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2187:
	/* 0x2187: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_218a:
	/* 0x218a: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_218d:
	/* 0x218d: cmovb  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2191:
	/* 0x2191: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2194:
	/* 0x2194: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2197:
	/* 0x2197: cmovne rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_NE);
x86_l_219b:
	/* 0x219b: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_21a0:
	/* 0x21a0: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_21a7:
	/* 0x21a7: ja     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10988ULL;
	}
x86_l_21ad:
	/* 0x21ad: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_21b0:
	/* 0x21b0: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21b4:
	/* 0x21b4: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_21b9:
	/* 0x21b9: mov    QWORD PTR [rsp],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21bd:
	/* 0x21bd: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_21c3:
	/* 0x21c3: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21c6:
	/* 0x21c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21cb:
	/* 0x21cb: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21d0:
	/* 0x21d0: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_21d3:
	/* 0x21d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d5:
	/* 0x21d5: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_21da:
	/* 0x21da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21dc:
	/* 0x21dc: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_21e2:
	/* 0x21e2: add    rbx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21e5:
	/* 0x21e5: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_21eb:
	/* 0x21eb: je     2515 <generic_retkprobe_event+0x2515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9493ULL;
	}
x86_l_21f1:
	/* 0x21f1: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_21f6:
	/* 0x21f6: jne    251c <generic_retkprobe_event+0x251c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9500ULL;
	}
x86_l_21fc:
	/* 0x21fc: jmp    2145 <generic_retkprobe_event+0x2145> */
	goto x86_l_2145;
x86_l_2201:
	/* 0x2201: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2206:
	/* 0x2206: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_220d:
	/* 0x220d: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2212:
	/* 0x2212: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2217:
	/* 0x2217: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_221c:
	/* 0x221c: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2221:
	/* 0x2221: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2225:
	/* 0x2225: ja     2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10628ULL;
	}
x86_l_222b:
	/* 0x222b: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2235:
	/* 0x2235: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2239:
	/* 0x2239: jae    2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10628ULL;
	}
x86_l_223f:
	/* 0x223f: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2243:
	/* 0x2243: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2248:
	/* 0x2248: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_224d:
	/* 0x224d: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2250:
	/* 0x2250: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2253:
	/* 0x2253: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2258:
	/* 0x2258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225a:
	/* 0x225a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_225d:
	/* 0x225d: js     27c0 <generic_retkprobe_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10176ULL;
	}
x86_l_2263:
	/* 0x2263: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2268:
	/* 0x2268: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_226b:
	/* 0x226b: jg     2288 <generic_retkprobe_event+0x2288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2288;
	}
x86_l_226d:
	/* 0x226d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_226f:
	/* 0x226f: je     22a6 <generic_retkprobe_event+0x22a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a6;
	}
x86_l_2271:
	/* 0x2271: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2274:
	/* 0x2274: je     22a6 <generic_retkprobe_event+0x22a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a6;
	}
x86_l_2276:
	/* 0x2276: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2279:
	/* 0x2279: jne    22d6 <generic_retkprobe_event+0x22d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22d6;
	}
x86_l_227b:
	/* 0x227b: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2282:
	/* 0x2282: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2286:
	/* 0x2286: jmp    22db <generic_retkprobe_event+0x22db> */
	goto x86_l_22db;
x86_l_2288:
	/* 0x2288: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_228b:
	/* 0x228b: je     22c3 <generic_retkprobe_event+0x22c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c3;
	}
x86_l_228d:
	/* 0x228d: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2290:
	/* 0x2290: je     22a6 <generic_retkprobe_event+0x22a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a6;
	}
x86_l_2292:
	/* 0x2292: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2297:
	/* 0x2297: jne    22d6 <generic_retkprobe_event+0x22d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22d6;
	}
x86_l_2299:
	/* 0x2299: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_22a0:
	/* 0x22a0: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_22a4:
	/* 0x22a4: jmp    22db <generic_retkprobe_event+0x22db> */
	goto x86_l_22db;
x86_l_22a6:
	/* 0x22a6: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_22ab:
	/* 0x22ab: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_22b2:
	/* 0x22b2: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_22b7:
	/* 0x22b7: jmp    22db <generic_retkprobe_event+0x22db> */
	goto x86_l_22db;
x86_l_22b9:
	/* 0x22b9: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_22be:
	/* 0x22be: jmp    2212 <generic_retkprobe_event+0x2212> */
	goto x86_l_2212;
x86_l_22c3:
	/* 0x22c3: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_22c8:
	/* 0x22c8: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_22cf:
	/* 0x22cf: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_22d4:
	/* 0x22d4: jmp    22db <generic_retkprobe_event+0x22db> */
	goto x86_l_22db;
x86_l_22d6:
	/* 0x22d6: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_22db:
	/* 0x22db: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22e0:
	/* 0x22e0: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e5:
	/* 0x22e5: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_22ea:
	/* 0x22ea: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_22ee:
	/* 0x22ee: ja     2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10628ULL;
	}
x86_l_22f4:
	/* 0x22f4: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_22fe:
	/* 0x22fe: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2302:
	/* 0x2302: jae    2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10628ULL;
	}
x86_l_2308:
	/* 0x2308: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_230c:
	/* 0x230c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2311:
	/* 0x2311: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2316:
	/* 0x2316: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2319:
	/* 0x2319: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_231c:
	/* 0x231c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2321:
	/* 0x2321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2323:
	/* 0x2323: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2326:
	/* 0x2326: js     27c0 <generic_retkprobe_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10176ULL;
	}
x86_l_232c:
	/* 0x232c: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2331:
	/* 0x2331: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2334:
	/* 0x2334: jg     2351 <generic_retkprobe_event+0x2351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2351;
	}
x86_l_2336:
	/* 0x2336: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2338:
	/* 0x2338: je     236f <generic_retkprobe_event+0x236f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9071ULL;
	}
x86_l_233a:
	/* 0x233a: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_233d:
	/* 0x233d: je     236f <generic_retkprobe_event+0x236f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9071ULL;
	}
x86_l_233f:
	/* 0x233f: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2342:
	/* 0x2342: jne    2395 <generic_retkprobe_event+0x2395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9109ULL;
	}
x86_l_2344:
	/* 0x2344: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_234b:
	/* 0x234b: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_234f:
	/* 0x234f: jmp    239a <generic_retkprobe_event+0x239a> */
	return 9114ULL;
x86_l_2351:
	/* 0x2351: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2354:
	/* 0x2354: je     2382 <generic_retkprobe_event+0x2382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9090ULL;
	}
x86_l_2356:
	/* 0x2356: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2359:
	/* 0x2359: je     236f <generic_retkprobe_event+0x236f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9071ULL;
	}
x86_l_235b:
	/* 0x235b: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2360:
	/* 0x2360: jne    2395 <generic_retkprobe_event+0x2395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9109ULL;
	}
x86_l_2362:
	/* 0x2362: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2369:
	/* 0x2369: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_236d:
	/* 0x236d: jmp    239a <generic_retkprobe_event+0x239a> */
	return 9114ULL;
	return 9071ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9083ULL: goto x86_l_237b;
	case 9088ULL: goto x86_l_2380;
	case 9090ULL: goto x86_l_2382;
	case 9095ULL: goto x86_l_2387;
	case 9102ULL: goto x86_l_238e;
	case 9107ULL: goto x86_l_2393;
	case 9109ULL: goto x86_l_2395;
	case 9114ULL: goto x86_l_239a;
	case 9119ULL: goto x86_l_239f;
	case 9124ULL: goto x86_l_23a4;
	case 9129ULL: goto x86_l_23a9;
	case 9133ULL: goto x86_l_23ad;
	case 9139ULL: goto x86_l_23b3;
	case 9149ULL: goto x86_l_23bd;
	case 9153ULL: goto x86_l_23c1;
	case 9159ULL: goto x86_l_23c7;
	case 9163ULL: goto x86_l_23cb;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9176ULL: goto x86_l_23d8;
	case 9179ULL: goto x86_l_23db;
	case 9184ULL: goto x86_l_23e0;
	case 9186ULL: goto x86_l_23e2;
	case 9189ULL: goto x86_l_23e5;
	case 9195ULL: goto x86_l_23eb;
	case 9200ULL: goto x86_l_23f0;
	case 9203ULL: goto x86_l_23f3;
	case 9205ULL: goto x86_l_23f5;
	case 9207ULL: goto x86_l_23f7;
	case 9209ULL: goto x86_l_23f9;
	case 9212ULL: goto x86_l_23fc;
	case 9214ULL: goto x86_l_23fe;
	case 9217ULL: goto x86_l_2401;
	case 9219ULL: goto x86_l_2403;
	case 9226ULL: goto x86_l_240a;
	case 9230ULL: goto x86_l_240e;
	case 9232ULL: goto x86_l_2410;
	case 9235ULL: goto x86_l_2413;
	case 9237ULL: goto x86_l_2415;
	case 9240ULL: goto x86_l_2418;
	case 9242ULL: goto x86_l_241a;
	case 9247ULL: goto x86_l_241f;
	case 9249ULL: goto x86_l_2421;
	case 9256ULL: goto x86_l_2428;
	case 9260ULL: goto x86_l_242c;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9274ULL: goto x86_l_243a;
	case 9279ULL: goto x86_l_243f;
	case 9281ULL: goto x86_l_2441;
	case 9286ULL: goto x86_l_2446;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9300ULL: goto x86_l_2454;
	case 9305ULL: goto x86_l_2459;
	case 9310ULL: goto x86_l_245e;
	case 9315ULL: goto x86_l_2463;
	case 9320ULL: goto x86_l_2468;
	case 9324ULL: goto x86_l_246c;
	case 9330ULL: goto x86_l_2472;
	case 9340ULL: goto x86_l_247c;
	case 9344ULL: goto x86_l_2480;
	case 9350ULL: goto x86_l_2486;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9367ULL: goto x86_l_2497;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9377ULL: goto x86_l_24a1;
	case 9380ULL: goto x86_l_24a4;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9394ULL: goto x86_l_24b2;
	case 9396ULL: goto x86_l_24b4;
	case 9398ULL: goto x86_l_24b6;
	case 9400ULL: goto x86_l_24b8;
	case 9403ULL: goto x86_l_24bb;
	case 9405ULL: goto x86_l_24bd;
	case 9408ULL: goto x86_l_24c0;
	case 9414ULL: goto x86_l_24c6;
	case 9421ULL: goto x86_l_24cd;
	case 9425ULL: goto x86_l_24d1;
	case 9430ULL: goto x86_l_24d6;
	case 9433ULL: goto x86_l_24d9;
	case 9439ULL: goto x86_l_24df;
	case 9442ULL: goto x86_l_24e2;
	case 9444ULL: goto x86_l_24e4;
	case 9449ULL: goto x86_l_24e9;
	case 9455ULL: goto x86_l_24ef;
	case 9462ULL: goto x86_l_24f6;
	case 9466ULL: goto x86_l_24fa;
	case 9471ULL: goto x86_l_24ff;
	case 9476ULL: goto x86_l_2504;
	case 9483ULL: goto x86_l_250b;
	case 9488ULL: goto x86_l_2510;
	case 9493ULL: goto x86_l_2515;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9509ULL: goto x86_l_2525;
	case 9515ULL: goto x86_l_252b;
	case 9523ULL: goto x86_l_2533;
	case 9527ULL: goto x86_l_2537;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9543ULL: goto x86_l_2547;
	case 9548ULL: goto x86_l_254c;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9557ULL: goto x86_l_2555;
	case 9563ULL: goto x86_l_255b;
	case 9568ULL: goto x86_l_2560;
	case 9573ULL: goto x86_l_2565;
	case 9576ULL: goto x86_l_2568;
	case 9579ULL: goto x86_l_256b;
	case 9583ULL: goto x86_l_256f;
	case 9586ULL: goto x86_l_2572;
	case 9590ULL: goto x86_l_2576;
	case 9595ULL: goto x86_l_257b;
	case 9600ULL: goto x86_l_2580;
	case 9607ULL: goto x86_l_2587;
	case 9613ULL: goto x86_l_258d;
	case 9616ULL: goto x86_l_2590;
	case 9620ULL: goto x86_l_2594;
	case 9623ULL: goto x86_l_2597;
	case 9629ULL: goto x86_l_259d;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9649ULL: goto x86_l_25b1;
	case 9654ULL: goto x86_l_25b6;
	case 9656ULL: goto x86_l_25b8;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9673ULL: goto x86_l_25c9;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9707ULL: goto x86_l_25eb;
	case 9712ULL: goto x86_l_25f0;
	case 9714ULL: goto x86_l_25f2;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9738ULL: goto x86_l_260a;
	case 9744ULL: goto x86_l_2610;
	case 9754ULL: goto x86_l_261a;
	case 9758ULL: goto x86_l_261e;
	case 9764ULL: goto x86_l_2624;
	case 9768ULL: goto x86_l_2628;
	case 9773ULL: goto x86_l_262d;
	case 9778ULL: goto x86_l_2632;
	case 9781ULL: goto x86_l_2635;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9791ULL: goto x86_l_263f;
	case 9794ULL: goto x86_l_2642;
	case 9800ULL: goto x86_l_2648;
	case 9805ULL: goto x86_l_264d;
	case 9808ULL: goto x86_l_2650;
	case 9810ULL: goto x86_l_2652;
	case 9812ULL: goto x86_l_2654;
	case 9814ULL: goto x86_l_2656;
	case 9817ULL: goto x86_l_2659;
	case 9819ULL: goto x86_l_265b;
	case 9822ULL: goto x86_l_265e;
	case 9824ULL: goto x86_l_2660;
	case 9831ULL: goto x86_l_2667;
	case 9835ULL: goto x86_l_266b;
	case 9837ULL: goto x86_l_266d;
	case 9840ULL: goto x86_l_2670;
	case 9842ULL: goto x86_l_2672;
	case 9845ULL: goto x86_l_2675;
	case 9847ULL: goto x86_l_2677;
	case 9852ULL: goto x86_l_267c;
	case 9854ULL: goto x86_l_267e;
	case 9861ULL: goto x86_l_2685;
	case 9865ULL: goto x86_l_2689;
	case 9867ULL: goto x86_l_268b;
	case 9872ULL: goto x86_l_2690;
	case 9879ULL: goto x86_l_2697;
	case 9884ULL: goto x86_l_269c;
	case 9886ULL: goto x86_l_269e;
	case 9891ULL: goto x86_l_26a3;
	case 9898ULL: goto x86_l_26aa;
	case 9903ULL: goto x86_l_26af;
	case 9905ULL: goto x86_l_26b1;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9929ULL: goto x86_l_26c9;
	case 9935ULL: goto x86_l_26cf;
	case 9945ULL: goto x86_l_26d9;
	case 9949ULL: goto x86_l_26dd;
	case 9955ULL: goto x86_l_26e3;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9969ULL: goto x86_l_26f1;
	case 9972ULL: goto x86_l_26f4;
	case 9975ULL: goto x86_l_26f7;
	case 9980ULL: goto x86_l_26fc;
	case 9982ULL: goto x86_l_26fe;
	case 9985ULL: goto x86_l_2701;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 9999ULL: goto x86_l_270f;
	case 10001ULL: goto x86_l_2711;
	case 10003ULL: goto x86_l_2713;
	case 10005ULL: goto x86_l_2715;
	case 10008ULL: goto x86_l_2718;
	case 10010ULL: goto x86_l_271a;
	case 10013ULL: goto x86_l_271d;
	case 10015ULL: goto x86_l_271f;
	case 10022ULL: goto x86_l_2726;
	case 10026ULL: goto x86_l_272a;
	case 10028ULL: goto x86_l_272c;
	case 10031ULL: goto x86_l_272f;
	case 10033ULL: goto x86_l_2731;
	case 10036ULL: goto x86_l_2734;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10045ULL: goto x86_l_273d;
	case 10052ULL: goto x86_l_2744;
	case 10056ULL: goto x86_l_2748;
	case 10058ULL: goto x86_l_274a;
	case 10063ULL: goto x86_l_274f;
	case 10070ULL: goto x86_l_2756;
	case 10075ULL: goto x86_l_275b;
	case 10077ULL: goto x86_l_275d;
	case 10082ULL: goto x86_l_2762;
	case 10089ULL: goto x86_l_2769;
	case 10094ULL: goto x86_l_276e;
	case 10096ULL: goto x86_l_2770;
	case 10101ULL: goto x86_l_2775;
	case 10106ULL: goto x86_l_277a;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10120ULL: goto x86_l_2788;
	case 10126ULL: goto x86_l_278e;
	case 10136ULL: goto x86_l_2798;
	case 10140ULL: goto x86_l_279c;
	case 10146ULL: goto x86_l_27a2;
	case 10150ULL: goto x86_l_27a6;
	case 10155ULL: goto x86_l_27ab;
	case 10160ULL: goto x86_l_27b0;
	case 10163ULL: goto x86_l_27b3;
	case 10166ULL: goto x86_l_27b6;
	case 10171ULL: goto x86_l_27bb;
	case 10174ULL: goto x86_l_27be;
	case 10176ULL: goto x86_l_27c0;
	case 10178ULL: goto x86_l_27c2;
	case 10185ULL: goto x86_l_27c9;
	case 10188ULL: goto x86_l_27cc;
	case 10192ULL: goto x86_l_27d0;
	case 10199ULL: goto x86_l_27d7;
	case 10208ULL: goto x86_l_27e0;
	case 10212ULL: goto x86_l_27e4;
	case 10217ULL: goto x86_l_27e9;
	case 10222ULL: goto x86_l_27ee;
	case 10227ULL: goto x86_l_27f3;
	case 10229ULL: goto x86_l_27f5;
	case 10236ULL: goto x86_l_27fc;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10250ULL: goto x86_l_280a;
	case 10253ULL: goto x86_l_280d;
	case 10255ULL: goto x86_l_280f;
	case 10263ULL: goto x86_l_2817;
	case 10266ULL: goto x86_l_281a;
	case 10268ULL: goto x86_l_281c;
	case 10271ULL: goto x86_l_281f;
	case 10277ULL: goto x86_l_2825;
	case 10282ULL: goto x86_l_282a;
	case 10291ULL: goto x86_l_2833;
	case 10295ULL: goto x86_l_2837;
	case 10299ULL: goto x86_l_283b;
	case 10306ULL: goto x86_l_2842;
	case 10311ULL: goto x86_l_2847;
	case 10316ULL: goto x86_l_284c;
	case 10318ULL: goto x86_l_284e;
	case 10325ULL: goto x86_l_2855;
	case 10329ULL: goto x86_l_2859;
	case 10333ULL: goto x86_l_285d;
	case 10338ULL: goto x86_l_2862;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10354ULL: goto x86_l_2872;
	case 10358ULL: goto x86_l_2876;
	case 10362ULL: goto x86_l_287a;
	case 10369ULL: goto x86_l_2881;
	case 10374ULL: goto x86_l_2886;
	case 10379ULL: goto x86_l_288b;
	case 10381ULL: goto x86_l_288d;
	case 10388ULL: goto x86_l_2894;
	case 10392ULL: goto x86_l_2898;
	case 10396ULL: goto x86_l_289c;
	case 10401ULL: goto x86_l_28a1;
	case 10406ULL: goto x86_l_28a6;
	case 10408ULL: goto x86_l_28a8;
	case 10410ULL: goto x86_l_28aa;
	case 10414ULL: goto x86_l_28ae;
	case 10424ULL: goto x86_l_28b8;
	case 10428ULL: goto x86_l_28bc;
	case 10435ULL: goto x86_l_28c3;
	case 10442ULL: goto x86_l_28ca;
	case 10451ULL: goto x86_l_28d3;
	case 10460ULL: goto x86_l_28dc;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10477ULL: goto x86_l_28ed;
	case 10482ULL: goto x86_l_28f2;
	case 10485ULL: goto x86_l_28f5;
	case 10487ULL: goto x86_l_28f7;
	case 10493ULL: goto x86_l_28fd;
	case 10495ULL: goto x86_l_28ff;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10509ULL: goto x86_l_290d;
	case 10517ULL: goto x86_l_2915;
	case 10522ULL: goto x86_l_291a;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10537ULL: goto x86_l_2929;
	case 10541ULL: goto x86_l_292d;
	case 10545ULL: goto x86_l_2931;
	case 10552ULL: goto x86_l_2938;
	case 10557ULL: goto x86_l_293d;
	case 10562ULL: goto x86_l_2942;
	case 10564ULL: goto x86_l_2944;
	case 10567ULL: goto x86_l_2947;
	case 10574ULL: goto x86_l_294e;
	case 10578ULL: goto x86_l_2952;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10592ULL: goto x86_l_2960;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10605ULL: goto x86_l_296d;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10628ULL: goto x86_l_2984;
	case 10636ULL: goto x86_l_298c;
	case 10641ULL: goto x86_l_2991;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10657ULL: goto x86_l_29a1;
	case 10663ULL: goto x86_l_29a7;
	case 10671ULL: goto x86_l_29af;
	case 10675ULL: goto x86_l_29b3;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10698ULL: goto x86_l_29ca;
	case 10703ULL: goto x86_l_29cf;
	case 10705ULL: goto x86_l_29d1;
	case 10711ULL: goto x86_l_29d7;
	case 10716ULL: goto x86_l_29dc;
	case 10721ULL: goto x86_l_29e1;
	case 10724ULL: goto x86_l_29e4;
	case 10727ULL: goto x86_l_29e7;
	case 10731ULL: goto x86_l_29eb;
	case 10734ULL: goto x86_l_29ee;
	case 10738ULL: goto x86_l_29f2;
	case 10743ULL: goto x86_l_29f7;
	case 10747ULL: goto x86_l_29fb;
	case 10754ULL: goto x86_l_2a02;
	case 10760ULL: goto x86_l_2a08;
	case 10765ULL: goto x86_l_2a0d;
	case 10768ULL: goto x86_l_2a10;
	case 10771ULL: goto x86_l_2a13;
	case 10777ULL: goto x86_l_2a19;
	case 10780ULL: goto x86_l_2a1c;
	case 10785ULL: goto x86_l_2a21;
	case 10790ULL: goto x86_l_2a26;
	default: return 0xffffffffffffffffULL;
	}
x86_l_236f:
	/* 0x236f: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2374:
	/* 0x2374: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_237b:
	/* 0x237b: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2380:
	/* 0x2380: jmp    239a <generic_retkprobe_event+0x239a> */
	goto x86_l_239a;
x86_l_2382:
	/* 0x2382: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2387:
	/* 0x2387: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_238e:
	/* 0x238e: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2393:
	/* 0x2393: jmp    239a <generic_retkprobe_event+0x239a> */
	goto x86_l_239a;
x86_l_2395:
	/* 0x2395: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_239a:
	/* 0x239a: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_239f:
	/* 0x239f: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a4:
	/* 0x23a4: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_23a9:
	/* 0x23a9: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_23ad:
	/* 0x23ad: ja     2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2984;
	}
x86_l_23b3:
	/* 0x23b3: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_23bd:
	/* 0x23bd: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_23c1:
	/* 0x23c1: jae    2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2984;
	}
x86_l_23c7:
	/* 0x23c7: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_23cb:
	/* 0x23cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23d0:
	/* 0x23d0: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23d5:
	/* 0x23d5: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23d8:
	/* 0x23d8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23db:
	/* 0x23db: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_23e0:
	/* 0x23e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23e2:
	/* 0x23e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23e5:
	/* 0x23e5: js     27c0 <generic_retkprobe_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27c0;
	}
x86_l_23eb:
	/* 0x23eb: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_23f0:
	/* 0x23f0: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_23f3:
	/* 0x23f3: jg     2410 <generic_retkprobe_event+0x2410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2410;
	}
x86_l_23f5:
	/* 0x23f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23f7:
	/* 0x23f7: je     242e <generic_retkprobe_event+0x242e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_242e;
	}
x86_l_23f9:
	/* 0x23f9: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_23fc:
	/* 0x23fc: je     242e <generic_retkprobe_event+0x242e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_242e;
	}
x86_l_23fe:
	/* 0x23fe: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2401:
	/* 0x2401: jne    2454 <generic_retkprobe_event+0x2454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2454;
	}
x86_l_2403:
	/* 0x2403: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_240a:
	/* 0x240a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_240e:
	/* 0x240e: jmp    2459 <generic_retkprobe_event+0x2459> */
	goto x86_l_2459;
x86_l_2410:
	/* 0x2410: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2413:
	/* 0x2413: je     2441 <generic_retkprobe_event+0x2441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2441;
	}
x86_l_2415:
	/* 0x2415: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2418:
	/* 0x2418: je     242e <generic_retkprobe_event+0x242e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_242e;
	}
x86_l_241a:
	/* 0x241a: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_241f:
	/* 0x241f: jne    2454 <generic_retkprobe_event+0x2454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2454;
	}
x86_l_2421:
	/* 0x2421: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2428:
	/* 0x2428: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_242c:
	/* 0x242c: jmp    2459 <generic_retkprobe_event+0x2459> */
	goto x86_l_2459;
x86_l_242e:
	/* 0x242e: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2433:
	/* 0x2433: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_243a:
	/* 0x243a: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_243f:
	/* 0x243f: jmp    2459 <generic_retkprobe_event+0x2459> */
	goto x86_l_2459;
x86_l_2441:
	/* 0x2441: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2446:
	/* 0x2446: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_244d:
	/* 0x244d: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2452:
	/* 0x2452: jmp    2459 <generic_retkprobe_event+0x2459> */
	goto x86_l_2459;
x86_l_2454:
	/* 0x2454: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2459:
	/* 0x2459: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_245e:
	/* 0x245e: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2463:
	/* 0x2463: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2468:
	/* 0x2468: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_246c:
	/* 0x246c: ja     2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2984;
	}
x86_l_2472:
	/* 0x2472: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_247c:
	/* 0x247c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2480:
	/* 0x2480: jae    2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2984;
	}
x86_l_2486:
	/* 0x2486: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_248a:
	/* 0x248a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_248f:
	/* 0x248f: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2494:
	/* 0x2494: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2497:
	/* 0x2497: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_249a:
	/* 0x249a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_249f:
	/* 0x249f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a1:
	/* 0x24a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24a4:
	/* 0x24a4: js     27c0 <generic_retkprobe_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27c0;
	}
x86_l_24aa:
	/* 0x24aa: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_24af:
	/* 0x24af: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_24b2:
	/* 0x24b2: jg     24d6 <generic_retkprobe_event+0x24d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_24d6;
	}
x86_l_24b4:
	/* 0x24b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b6:
	/* 0x24b6: je     24ff <generic_retkprobe_event+0x24ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ff;
	}
x86_l_24b8:
	/* 0x24b8: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_24bb:
	/* 0x24bb: je     24ff <generic_retkprobe_event+0x24ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ff;
	}
x86_l_24bd:
	/* 0x24bd: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_24c0:
	/* 0x24c0: jne    25f2 <generic_retkprobe_event+0x25f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25f2;
	}
x86_l_24c6:
	/* 0x24c6: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_24cd:
	/* 0x24cd: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_24d1:
	/* 0x24d1: jmp    25f7 <generic_retkprobe_event+0x25f7> */
	goto x86_l_25f7;
x86_l_24d6:
	/* 0x24d6: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_24d9:
	/* 0x24d9: je     25df <generic_retkprobe_event+0x25df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25df;
	}
x86_l_24df:
	/* 0x24df: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_24e2:
	/* 0x24e2: je     24ff <generic_retkprobe_event+0x24ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ff;
	}
x86_l_24e4:
	/* 0x24e4: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_24e9:
	/* 0x24e9: jne    25f2 <generic_retkprobe_event+0x25f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25f2;
	}
x86_l_24ef:
	/* 0x24ef: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_24f6:
	/* 0x24f6: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_24fa:
	/* 0x24fa: jmp    25f7 <generic_retkprobe_event+0x25f7> */
	goto x86_l_25f7;
x86_l_24ff:
	/* 0x24ff: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2504:
	/* 0x2504: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_250b:
	/* 0x250b: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2510:
	/* 0x2510: jmp    25f7 <generic_retkprobe_event+0x25f7> */
	goto x86_l_25f7;
x86_l_2515:
	/* 0x2515: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2517:
	/* 0x2517: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_251c:
	/* 0x251c: cmp    QWORD PTR [rsp+0x88],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552261ULL);
x86_l_2525:
	/* 0x2525: jb     2145 <generic_retkprobe_event+0x2145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8517ULL;
	}
x86_l_252b:
	/* 0x252b: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2533:
	/* 0x2533: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2537:
	/* 0x2537: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_253d:
	/* 0x253d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2542:
	/* 0x2542: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2547:
	/* 0x2547: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_254c:
	/* 0x254c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254e:
	/* 0x254e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2553:
	/* 0x2553: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2555:
	/* 0x2555: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_255b:
	/* 0x255b: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2560:
	/* 0x2560: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2565:
	/* 0x2565: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2568:
	/* 0x2568: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_256b:
	/* 0x256b: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_256f:
	/* 0x256f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2572:
	/* 0x2572: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_2576:
	/* 0x2576: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_257b:
	/* 0x257b: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2580:
	/* 0x2580: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_2587:
	/* 0x2587: ja     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10988ULL;
	}
x86_l_258d:
	/* 0x258d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2590:
	/* 0x2590: add    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2594:
	/* 0x2594: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_2597:
	/* 0x2597: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_259d:
	/* 0x259d: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25a0:
	/* 0x25a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25a5:
	/* 0x25a5: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25aa:
	/* 0x25aa: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25af:
	/* 0x25af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b1:
	/* 0x25b1: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25b6:
	/* 0x25b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25b8:
	/* 0x25b8: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_25be:
	/* 0x25be: add    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_25c3:
	/* 0x25c3: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_25c9:
	/* 0x25c9: je     2991 <generic_retkprobe_event+0x2991> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2991;
	}
x86_l_25cf:
	/* 0x25cf: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_25d4:
	/* 0x25d4: jne    2998 <generic_retkprobe_event+0x2998> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2998;
	}
x86_l_25da:
	/* 0x25da: jmp    2145 <generic_retkprobe_event+0x2145> */
	return 8517ULL;
x86_l_25df:
	/* 0x25df: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_25e4:
	/* 0x25e4: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_25eb:
	/* 0x25eb: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_25f0:
	/* 0x25f0: jmp    25f7 <generic_retkprobe_event+0x25f7> */
	goto x86_l_25f7;
x86_l_25f2:
	/* 0x25f2: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_25f7:
	/* 0x25f7: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25fc:
	/* 0x25fc: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2601:
	/* 0x2601: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2606:
	/* 0x2606: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_260a:
	/* 0x260a: ja     2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2984;
	}
x86_l_2610:
	/* 0x2610: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_261a:
	/* 0x261a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_261e:
	/* 0x261e: jae    2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2984;
	}
x86_l_2624:
	/* 0x2624: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2628:
	/* 0x2628: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_262d:
	/* 0x262d: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2632:
	/* 0x2632: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2635:
	/* 0x2635: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2638:
	/* 0x2638: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_263d:
	/* 0x263d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263f:
	/* 0x263f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2642:
	/* 0x2642: js     27c0 <generic_retkprobe_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27c0;
	}
x86_l_2648:
	/* 0x2648: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_264d:
	/* 0x264d: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2650:
	/* 0x2650: jg     266d <generic_retkprobe_event+0x266d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_266d;
	}
x86_l_2652:
	/* 0x2652: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2654:
	/* 0x2654: je     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_268b;
	}
x86_l_2656:
	/* 0x2656: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2659:
	/* 0x2659: je     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_268b;
	}
x86_l_265b:
	/* 0x265b: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_265e:
	/* 0x265e: jne    26b1 <generic_retkprobe_event+0x26b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26b1;
	}
x86_l_2660:
	/* 0x2660: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2667:
	/* 0x2667: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_266b:
	/* 0x266b: jmp    26b6 <generic_retkprobe_event+0x26b6> */
	goto x86_l_26b6;
x86_l_266d:
	/* 0x266d: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2670:
	/* 0x2670: je     269e <generic_retkprobe_event+0x269e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_269e;
	}
x86_l_2672:
	/* 0x2672: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2675:
	/* 0x2675: je     268b <generic_retkprobe_event+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_268b;
	}
x86_l_2677:
	/* 0x2677: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_267c:
	/* 0x267c: jne    26b1 <generic_retkprobe_event+0x26b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26b1;
	}
x86_l_267e:
	/* 0x267e: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2685:
	/* 0x2685: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2689:
	/* 0x2689: jmp    26b6 <generic_retkprobe_event+0x26b6> */
	goto x86_l_26b6;
x86_l_268b:
	/* 0x268b: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2690:
	/* 0x2690: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2697:
	/* 0x2697: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_269c:
	/* 0x269c: jmp    26b6 <generic_retkprobe_event+0x26b6> */
	goto x86_l_26b6;
x86_l_269e:
	/* 0x269e: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_26a3:
	/* 0x26a3: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_26aa:
	/* 0x26aa: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_26af:
	/* 0x26af: jmp    26b6 <generic_retkprobe_event+0x26b6> */
	goto x86_l_26b6;
x86_l_26b1:
	/* 0x26b1: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_26b6:
	/* 0x26b6: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26bb:
	/* 0x26bb: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26c0:
	/* 0x26c0: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_26c5:
	/* 0x26c5: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_26c9:
	/* 0x26c9: ja     2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2984;
	}
x86_l_26cf:
	/* 0x26cf: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_26d9:
	/* 0x26d9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_26dd:
	/* 0x26dd: jae    2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2984;
	}
x86_l_26e3:
	/* 0x26e3: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_26e7:
	/* 0x26e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26ec:
	/* 0x26ec: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26f1:
	/* 0x26f1: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26f4:
	/* 0x26f4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26f7:
	/* 0x26f7: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_26fc:
	/* 0x26fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26fe:
	/* 0x26fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2701:
	/* 0x2701: js     27c0 <generic_retkprobe_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27c0;
	}
x86_l_2707:
	/* 0x2707: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_270c:
	/* 0x270c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_270f:
	/* 0x270f: jg     272c <generic_retkprobe_event+0x272c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_272c;
	}
x86_l_2711:
	/* 0x2711: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2713:
	/* 0x2713: je     274a <generic_retkprobe_event+0x274a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_274a;
	}
x86_l_2715:
	/* 0x2715: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2718:
	/* 0x2718: je     274a <generic_retkprobe_event+0x274a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_274a;
	}
x86_l_271a:
	/* 0x271a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_271d:
	/* 0x271d: jne    2770 <generic_retkprobe_event+0x2770> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2770;
	}
x86_l_271f:
	/* 0x271f: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2726:
	/* 0x2726: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_272a:
	/* 0x272a: jmp    2775 <generic_retkprobe_event+0x2775> */
	goto x86_l_2775;
x86_l_272c:
	/* 0x272c: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_272f:
	/* 0x272f: je     275d <generic_retkprobe_event+0x275d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_275d;
	}
x86_l_2731:
	/* 0x2731: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2734:
	/* 0x2734: je     274a <generic_retkprobe_event+0x274a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_274a;
	}
x86_l_2736:
	/* 0x2736: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_273b:
	/* 0x273b: jne    2770 <generic_retkprobe_event+0x2770> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2770;
	}
x86_l_273d:
	/* 0x273d: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2744:
	/* 0x2744: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2748:
	/* 0x2748: jmp    2775 <generic_retkprobe_event+0x2775> */
	goto x86_l_2775;
x86_l_274a:
	/* 0x274a: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_274f:
	/* 0x274f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2756:
	/* 0x2756: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_275b:
	/* 0x275b: jmp    2775 <generic_retkprobe_event+0x2775> */
	goto x86_l_2775;
x86_l_275d:
	/* 0x275d: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2762:
	/* 0x2762: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2769:
	/* 0x2769: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_276e:
	/* 0x276e: jmp    2775 <generic_retkprobe_event+0x2775> */
	goto x86_l_2775;
x86_l_2770:
	/* 0x2770: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2775:
	/* 0x2775: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_277a:
	/* 0x277a: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_277f:
	/* 0x277f: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2784:
	/* 0x2784: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2788:
	/* 0x2788: ja     2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2984;
	}
x86_l_278e:
	/* 0x278e: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2798:
	/* 0x2798: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_279c:
	/* 0x279c: jae    2984 <generic_retkprobe_event+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2984;
	}
x86_l_27a2:
	/* 0x27a2: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_27a6:
	/* 0x27a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27ab:
	/* 0x27ab: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27b0:
	/* 0x27b0: add    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27b3:
	/* 0x27b3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_27b6:
	/* 0x27b6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_27bb:
	/* 0x27bb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_27be:
	/* 0x27be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27c0:
	/* 0x27c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27c2:
	/* 0x27c2: mov    BYTE PTR [rsp+0xc0],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_27c9:
	/* 0x27c9: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_27cc:
	/* 0x27cc: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d0:
	/* 0x27d0: mov    WORD PTR [rbx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_27d7:
	/* 0x27d7: mov    WORD PTR [rbx+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_27e0:
	/* 0x27e0: lea    rdx,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27e4:
	/* 0x27e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27e9:
	/* 0x27e9: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27ee:
	/* 0x27ee: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27f3:
	/* 0x27f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f5:
	/* 0x27f5: lea    rdi,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_27fc:
	/* 0x27fc: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2800:
	/* 0x2800: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2805:
	/* 0x2805: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_280a:
	/* 0x280a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_280d:
	/* 0x280d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_280f:
	/* 0x280f: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_2817:
	/* 0x2817: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_281a:
	/* 0x281a: je     2864 <generic_retkprobe_event+0x2864> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2864;
	}
x86_l_281c:
	/* 0x281c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_281f:
	/* 0x281f: jne    28aa <generic_retkprobe_event+0x28aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28aa;
	}
x86_l_2825:
	/* 0x2825: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_282a:
	/* 0x282a: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_2833:
	/* 0x2833: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2837:
	/* 0x2837: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_283b:
	/* 0x283b: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2842:
	/* 0x2842: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2847:
	/* 0x2847: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_284c:
	/* 0x284c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_284e:
	/* 0x284e: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2855:
	/* 0x2855: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2859:
	/* 0x2859: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_285d:
	/* 0x285d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2862:
	/* 0x2862: jmp    28a1 <generic_retkprobe_event+0x28a1> */
	goto x86_l_28a1;
x86_l_2864:
	/* 0x2864: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2869:
	/* 0x2869: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_2872:
	/* 0x2872: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2876:
	/* 0x2876: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_287a:
	/* 0x287a: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2881:
	/* 0x2881: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2886:
	/* 0x2886: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_288b:
	/* 0x288b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288d:
	/* 0x288d: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2894:
	/* 0x2894: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2898:
	/* 0x2898: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_289c:
	/* 0x289c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28a1:
	/* 0x28a1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_28a6:
	/* 0x28a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a8:
	/* 0x28a8: jmp    28b8 <generic_retkprobe_event+0x28b8> */
	goto x86_l_28b8;
x86_l_28aa:
	/* 0x28aa: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28ae:
	/* 0x28ae: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_28b8:
	/* 0x28b8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28bc:
	/* 0x28bc: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_28c3:
	/* 0x28c3: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_28ca:
	/* 0x28ca: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_28d3:
	/* 0x28d3: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_28dc:
	/* 0x28dc: add    rbp,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_28e3:
	/* 0x28e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28e8:
	/* 0x28e8: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28ed:
	/* 0x28ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28f2:
	/* 0x28f2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_28f5:
	/* 0x28f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f7:
	/* 0x28f7: cmp    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_28fd:
	/* 0x28fd: je     2962 <generic_retkprobe_event+0x2962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2962;
	}
x86_l_28ff:
	/* 0x28ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2904:
	/* 0x2904: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2909:
	/* 0x2909: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_290d:
	/* 0x290d: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2915:
	/* 0x2915: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_291a:
	/* 0x291a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291c:
	/* 0x291c: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2921:
	/* 0x2921: mov    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2929:
	/* 0x2929: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_292d:
	/* 0x292d: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2931:
	/* 0x2931: lea    rdi,[r13+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2938:
	/* 0x2938: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_293d:
	/* 0x293d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2942:
	/* 0x2942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2944:
	/* 0x2944: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2947:
	/* 0x2947: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_294e:
	/* 0x294e: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2952:
	/* 0x2952: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2956:
	/* 0x2956: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_295b:
	/* 0x295b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2960:
	/* 0x2960: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2962:
	/* 0x2962: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2967:
	/* 0x2967: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_296d:
	/* 0x296d: mov    ebx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2971:
	/* 0x2971: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_2976:
	/* 0x2976: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297a:
	/* 0x297a: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_297f:
	/* 0x297f: jmp    a8b <generic_retkprobe_event+0xa8b> */
	return 2699ULL;
x86_l_2984:
	/* 0x2984: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_298c:
	/* 0x298c: jmp    27c2 <generic_retkprobe_event+0x27c2> */
	goto x86_l_27c2;
x86_l_2991:
	/* 0x2991: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2993:
	/* 0x2993: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2998:
	/* 0x2998: cmp    QWORD PTR [rsp+0x88],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552261ULL);
x86_l_29a1:
	/* 0x29a1: je     2145 <generic_retkprobe_event+0x2145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8517ULL;
	}
x86_l_29a7:
	/* 0x29a7: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_29af:
	/* 0x29af: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29b3:
	/* 0x29b3: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_29b9:
	/* 0x29b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29be:
	/* 0x29be: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29c3:
	/* 0x29c3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_29c8:
	/* 0x29c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ca:
	/* 0x29ca: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_29cf:
	/* 0x29cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29d1:
	/* 0x29d1: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10988ULL;
	}
x86_l_29d7:
	/* 0x29d7: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29dc:
	/* 0x29dc: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29e1:
	/* 0x29e1: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_29e4:
	/* 0x29e4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_29e7:
	/* 0x29e7: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_29eb:
	/* 0x29eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29ee:
	/* 0x29ee: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_29f2:
	/* 0x29f2: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_29f7:
	/* 0x29f7: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29fb:
	/* 0x29fb: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_2a02:
	/* 0x2a02: ja     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10988ULL;
	}
x86_l_2a08:
	/* 0x2a08: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a0d:
	/* 0x2a0d: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a10:
	/* 0x2a10: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_2a13:
	/* 0x2a13: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a19:
	/* 0x2a19: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a1c:
	/* 0x2a1c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a21:
	/* 0x2a21: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a26:
	/* 0x2a26: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 10794ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10794ULL: goto x86_l_2a2a;
	case 10796ULL: goto x86_l_2a2c;
	case 10801ULL: goto x86_l_2a31;
	case 10803ULL: goto x86_l_2a33;
	case 10809ULL: goto x86_l_2a39;
	case 10813ULL: goto x86_l_2a3d;
	case 10819ULL: goto x86_l_2a43;
	case 10821ULL: goto x86_l_2a45;
	case 10826ULL: goto x86_l_2a4a;
	case 10828ULL: goto x86_l_2a4c;
	case 10833ULL: goto x86_l_2a51;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10849ULL: goto x86_l_2a61;
	case 10855ULL: goto x86_l_2a67;
	case 10863ULL: goto x86_l_2a6f;
	case 10867ULL: goto x86_l_2a73;
	case 10873ULL: goto x86_l_2a79;
	case 10878ULL: goto x86_l_2a7e;
	case 10883ULL: goto x86_l_2a83;
	case 10888ULL: goto x86_l_2a88;
	case 10890ULL: goto x86_l_2a8a;
	case 10895ULL: goto x86_l_2a8f;
	case 10897ULL: goto x86_l_2a91;
	case 10899ULL: goto x86_l_2a93;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10912ULL: goto x86_l_2aa0;
	case 10915ULL: goto x86_l_2aa3;
	case 10919ULL: goto x86_l_2aa7;
	case 10922ULL: goto x86_l_2aaa;
	case 10926ULL: goto x86_l_2aae;
	case 10931ULL: goto x86_l_2ab3;
	case 10938ULL: goto x86_l_2aba;
	case 10940ULL: goto x86_l_2abc;
	case 10944ULL: goto x86_l_2ac0;
	case 10947ULL: goto x86_l_2ac3;
	case 10953ULL: goto x86_l_2ac9;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10969ULL: goto x86_l_2ad9;
	case 10971ULL: goto x86_l_2adb;
	case 10976ULL: goto x86_l_2ae0;
	case 10978ULL: goto x86_l_2ae2;
	case 10980ULL: goto x86_l_2ae4;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10992ULL: goto x86_l_2af0;
	case 10995ULL: goto x86_l_2af3;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11008ULL: goto x86_l_2b00;
	case 11010ULL: goto x86_l_2b02;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11031ULL: goto x86_l_2b17;
	case 11039ULL: goto x86_l_2b1f;
	case 11044ULL: goto x86_l_2b24;
	case 11046ULL: goto x86_l_2b26;
	case 11053ULL: goto x86_l_2b2d;
	case 11057ULL: goto x86_l_2b31;
	case 11062ULL: goto x86_l_2b36;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11076ULL: goto x86_l_2b44;
	case 11079ULL: goto x86_l_2b47;
	case 11081ULL: goto x86_l_2b49;
	case 11084ULL: goto x86_l_2b4c;
	case 11089ULL: goto x86_l_2b51;
	case 11095ULL: goto x86_l_2b57;
	case 11100ULL: goto x86_l_2b5c;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11117ULL: goto x86_l_2b6d;
	case 11120ULL: goto x86_l_2b70;
	case 11122ULL: goto x86_l_2b72;
	case 11128ULL: goto x86_l_2b78;
	case 11134ULL: goto x86_l_2b7e;
	case 11139ULL: goto x86_l_2b83;
	case 11144ULL: goto x86_l_2b88;
	case 11149ULL: goto x86_l_2b8d;
	case 11157ULL: goto x86_l_2b95;
	case 11162ULL: goto x86_l_2b9a;
	case 11164ULL: goto x86_l_2b9c;
	case 11171ULL: goto x86_l_2ba3;
	case 11175ULL: goto x86_l_2ba7;
	case 11180ULL: goto x86_l_2bac;
	case 11187ULL: goto x86_l_2bb3;
	case 11192ULL: goto x86_l_2bb8;
	case 11194ULL: goto x86_l_2bba;
	case 11197ULL: goto x86_l_2bbd;
	case 11199ULL: goto x86_l_2bbf;
	case 11202ULL: goto x86_l_2bc2;
	case 11207ULL: goto x86_l_2bc7;
	case 11213ULL: goto x86_l_2bcd;
	case 11218ULL: goto x86_l_2bd2;
	case 11223ULL: goto x86_l_2bd7;
	case 11228ULL: goto x86_l_2bdc;
	case 11233ULL: goto x86_l_2be1;
	case 11238ULL: goto x86_l_2be6;
	case 11240ULL: goto x86_l_2be8;
	case 11246ULL: goto x86_l_2bee;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11262ULL: goto x86_l_2bfe;
	case 11267ULL: goto x86_l_2c03;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11282ULL: goto x86_l_2c12;
	case 11289ULL: goto x86_l_2c19;
	case 11293ULL: goto x86_l_2c1d;
	case 11298ULL: goto x86_l_2c22;
	case 11305ULL: goto x86_l_2c29;
	case 11310ULL: goto x86_l_2c2e;
	case 11312ULL: goto x86_l_2c30;
	case 11315ULL: goto x86_l_2c33;
	case 11317ULL: goto x86_l_2c35;
	case 11320ULL: goto x86_l_2c38;
	case 11325ULL: goto x86_l_2c3d;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11358ULL: goto x86_l_2c5e;
	case 11364ULL: goto x86_l_2c64;
	case 11366ULL: goto x86_l_2c66;
	case 11371ULL: goto x86_l_2c6b;
	case 11376ULL: goto x86_l_2c70;
	case 11381ULL: goto x86_l_2c75;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11396ULL: goto x86_l_2c84;
	case 11403ULL: goto x86_l_2c8b;
	case 11407ULL: goto x86_l_2c8f;
	case 11412ULL: goto x86_l_2c94;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11426ULL: goto x86_l_2ca2;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11441ULL: goto x86_l_2cb1;
	case 11446ULL: goto x86_l_2cb6;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11461ULL: goto x86_l_2cc5;
	case 11466ULL: goto x86_l_2cca;
	case 11468ULL: goto x86_l_2ccc;
	case 11471ULL: goto x86_l_2ccf;
	case 11476ULL: goto x86_l_2cd4;
	case 11482ULL: goto x86_l_2cda;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11493ULL: goto x86_l_2ce5;
	case 11497ULL: goto x86_l_2ce9;
	case 11500ULL: goto x86_l_2cec;
	case 11502ULL: goto x86_l_2cee;
	case 11505ULL: goto x86_l_2cf1;
	case 11508ULL: goto x86_l_2cf4;
	case 11512ULL: goto x86_l_2cf8;
	case 11516ULL: goto x86_l_2cfc;
	case 11523ULL: goto x86_l_2d03;
	case 11527ULL: goto x86_l_2d07;
	case 11531ULL: goto x86_l_2d0b;
	case 11535ULL: goto x86_l_2d0f;
	case 11540ULL: goto x86_l_2d14;
	case 11547ULL: goto x86_l_2d1b;
	case 11555ULL: goto x86_l_2d23;
	case 11560ULL: goto x86_l_2d28;
	case 11562ULL: goto x86_l_2d2a;
	case 11567ULL: goto x86_l_2d2f;
	case 11569ULL: goto x86_l_2d31;
	case 11576ULL: goto x86_l_2d38;
	case 11578ULL: goto x86_l_2d3a;
	case 11579ULL: goto x86_l_2d3b;
	case 11584ULL: goto x86_l_2d40;
	case 11586ULL: goto x86_l_2d42;
	case 11588ULL: goto x86_l_2d44;
	case 11590ULL: goto x86_l_2d46;
	case 11591ULL: goto x86_l_2d47;
	case 11595ULL: goto x86_l_2d4b;
	case 11598ULL: goto x86_l_2d4e;
	case 11602ULL: goto x86_l_2d52;
	case 11606ULL: goto x86_l_2d56;
	case 11610ULL: goto x86_l_2d5a;
	case 11613ULL: goto x86_l_2d5d;
	case 11615ULL: goto x86_l_2d5f;
	case 11619ULL: goto x86_l_2d63;
	case 11625ULL: goto x86_l_2d69;
	case 11630ULL: goto x86_l_2d6e;
	case 11635ULL: goto x86_l_2d73;
	case 11640ULL: goto x86_l_2d78;
	case 11642ULL: goto x86_l_2d7a;
	case 11647ULL: goto x86_l_2d7f;
	case 11653ULL: goto x86_l_2d85;
	case 11657ULL: goto x86_l_2d89;
	case 11662ULL: goto x86_l_2d8e;
	case 11667ULL: goto x86_l_2d93;
	case 11672ULL: goto x86_l_2d98;
	case 11675ULL: goto x86_l_2d9b;
	case 11677ULL: goto x86_l_2d9d;
	case 11682ULL: goto x86_l_2da2;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11698ULL: goto x86_l_2db2;
	case 11703ULL: goto x86_l_2db7;
	case 11706ULL: goto x86_l_2dba;
	case 11708ULL: goto x86_l_2dbc;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11722ULL: goto x86_l_2dca;
	case 11727ULL: goto x86_l_2dcf;
	case 11730ULL: goto x86_l_2dd2;
	case 11732ULL: goto x86_l_2dd4;
	case 11736ULL: goto x86_l_2dd8;
	case 11740ULL: goto x86_l_2ddc;
	case 11744ULL: goto x86_l_2de0;
	case 11747ULL: goto x86_l_2de3;
	case 11750ULL: goto x86_l_2de6;
	case 11752ULL: goto x86_l_2de8;
	case 11754ULL: goto x86_l_2dea;
	case 11756ULL: goto x86_l_2dec;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11767ULL: goto x86_l_2df7;
	case 11769ULL: goto x86_l_2df9;
	case 11773ULL: goto x86_l_2dfd;
	case 11776ULL: goto x86_l_2e00;
	case 11780ULL: goto x86_l_2e04;
	case 11783ULL: goto x86_l_2e07;
	case 11785ULL: goto x86_l_2e09;
	case 11788ULL: goto x86_l_2e0c;
	case 11791ULL: goto x86_l_2e0f;
	case 11796ULL: goto x86_l_2e14;
	case 11799ULL: goto x86_l_2e17;
	case 11805ULL: goto x86_l_2e1d;
	case 11812ULL: goto x86_l_2e24;
	case 11818ULL: goto x86_l_2e2a;
	case 11820ULL: goto x86_l_2e2c;
	case 11826ULL: goto x86_l_2e32;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11839ULL: goto x86_l_2e3f;
	case 11843ULL: goto x86_l_2e43;
	case 11846ULL: goto x86_l_2e46;
	case 11851ULL: goto x86_l_2e4b;
	case 11853ULL: goto x86_l_2e4d;
	case 11857ULL: goto x86_l_2e51;
	case 11862ULL: goto x86_l_2e56;
	case 11866ULL: goto x86_l_2e5a;
	case 11868ULL: goto x86_l_2e5c;
	case 11870ULL: goto x86_l_2e5e;
	case 11874ULL: goto x86_l_2e62;
	case 11879ULL: goto x86_l_2e67;
	case 11884ULL: goto x86_l_2e6c;
	case 11889ULL: goto x86_l_2e71;
	case 11891ULL: goto x86_l_2e73;
	case 11895ULL: goto x86_l_2e77;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11906ULL: goto x86_l_2e82;
	case 11910ULL: goto x86_l_2e86;
	case 11915ULL: goto x86_l_2e8b;
	case 11920ULL: goto x86_l_2e90;
	case 11923ULL: goto x86_l_2e93;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11934ULL: goto x86_l_2e9e;
	case 11938ULL: goto x86_l_2ea2;
	case 11942ULL: goto x86_l_2ea6;
	case 11944ULL: goto x86_l_2ea8;
	case 11946ULL: goto x86_l_2eaa;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11959ULL: goto x86_l_2eb7;
	case 11960ULL: goto x86_l_2eb8;
	case 11962ULL: goto x86_l_2eba;
	case 11964ULL: goto x86_l_2ebc;
	case 11966ULL: goto x86_l_2ebe;
	case 11967ULL: goto x86_l_2ebf;
	case 11971ULL: goto x86_l_2ec3;
	case 11974ULL: goto x86_l_2ec6;
	case 11979ULL: goto x86_l_2ecb;
	case 11982ULL: goto x86_l_2ece;
	case 11984ULL: goto x86_l_2ed0;
	case 11989ULL: goto x86_l_2ed5;
	case 11993ULL: goto x86_l_2ed9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a2a:
	/* 0x2a2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2c:
	/* 0x2a2c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a31:
	/* 0x2a31: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a33:
	/* 0x2a33: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2aec;
	}
x86_l_2a39:
	/* 0x2a39: add    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a3d:
	/* 0x2a3d: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2a43:
	/* 0x2a43: je     2a51 <generic_retkprobe_event+0x2a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a51;
	}
x86_l_2a45:
	/* 0x2a45: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_2a4a:
	/* 0x2a4a: jne    2a58 <generic_retkprobe_event+0x2a58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a58;
	}
x86_l_2a4c:
	/* 0x2a4c: jmp    2145 <generic_retkprobe_event+0x2145> */
	return 8517ULL;
x86_l_2a51:
	/* 0x2a51: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a53:
	/* 0x2a53: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a58:
	/* 0x2a58: cmp    QWORD PTR [rsp+0x88],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552263ULL);
x86_l_2a61:
	/* 0x2a61: jb     2145 <generic_retkprobe_event+0x2145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8517ULL;
	}
x86_l_2a67:
	/* 0x2a67: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2a6f:
	/* 0x2a6f: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2a73:
	/* 0x2a73: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2a79:
	/* 0x2a79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a7e:
	/* 0x2a7e: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a83:
	/* 0x2a83: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a88:
	/* 0x2a88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8a:
	/* 0x2a8a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a8f:
	/* 0x2a8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a91:
	/* 0x2a91: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2aec;
	}
x86_l_2a93:
	/* 0x2a93: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a98:
	/* 0x2a98: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a9d:
	/* 0x2a9d: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2aa0:
	/* 0x2aa0: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2aa3:
	/* 0x2aa3: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_2aa7:
	/* 0x2aa7: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2aaa:
	/* 0x2aaa: cmove  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_2aae:
	/* 0x2aae: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2ab3:
	/* 0x2ab3: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_2aba:
	/* 0x2aba: ja     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2aec;
	}
x86_l_2abc:
	/* 0x2abc: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ac0:
	/* 0x2ac0: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ac3:
	/* 0x2ac3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2ac9:
	/* 0x2ac9: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2acc:
	/* 0x2acc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ad1:
	/* 0x2ad1: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ad6:
	/* 0x2ad6: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2ad9:
	/* 0x2ad9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2adb:
	/* 0x2adb: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2ae0:
	/* 0x2ae0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ae2:
	/* 0x2ae2: js     2aec <generic_retkprobe_event+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2aec;
	}
x86_l_2ae4:
	/* 0x2ae4: add    r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ae7:
	/* 0x2ae7: jmp    335 <generic_retkprobe_event+0x335> */
	return 821ULL;
x86_l_2aec:
	/* 0x2aec: mov    DWORD PTR [r15+rbp*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2af0:
	/* 0x2af0: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2af3:
	/* 0x2af3: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_2af6:
	/* 0x2af6: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2afb:
	/* 0x2afb: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2b00:
	/* 0x2b00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b02:
	/* 0x2b02: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2b05:
	/* 0x2b05: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b0a:
	/* 0x2b0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b0f:
	/* 0x2b0f: lea    rdx,[r12+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_2b17:
	/* 0x2b17: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b1f:
	/* 0x2b1f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b24:
	/* 0x2b24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b26:
	/* 0x2b26: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b2d:
	/* 0x2b2d: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b31:
	/* 0x2b31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b36:
	/* 0x2b36: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2b3d:
	/* 0x2b3d: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b42:
	/* 0x2b42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b44:
	/* 0x2b44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b47:
	/* 0x2b47: je     2b57 <generic_retkprobe_event+0x2b57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b57;
	}
x86_l_2b49:
	/* 0x2b49: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2b4c:
	/* 0x2b4c: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2b51:
	/* 0x2b51: jne    2ccf <generic_retkprobe_event+0x2ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ccf;
	}
x86_l_2b57:
	/* 0x2b57: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b5c:
	/* 0x2b5c: add    r12,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_2b63:
	/* 0x2b63: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b68:
	/* 0x2b68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b6d:
	/* 0x2b6d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b70:
	/* 0x2b70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b72:
	/* 0x2b72: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2b78:
	/* 0x2b78: je     2ccc <generic_retkprobe_event+0x2ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ccc;
	}
x86_l_2b7e:
	/* 0x2b7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b83:
	/* 0x2b83: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2b88:
	/* 0x2b88: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2b8d:
	/* 0x2b8d: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b95:
	/* 0x2b95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b9a:
	/* 0x2b9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9c:
	/* 0x2b9c: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2ba3:
	/* 0x2ba3: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ba7:
	/* 0x2ba7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bac:
	/* 0x2bac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2bb3:
	/* 0x2bb3: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bb8:
	/* 0x2bb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bba:
	/* 0x2bba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bbd:
	/* 0x2bbd: je     2bcd <generic_retkprobe_event+0x2bcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bcd;
	}
x86_l_2bbf:
	/* 0x2bbf: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2bc2:
	/* 0x2bc2: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2bc7:
	/* 0x2bc7: jne    2ccf <generic_retkprobe_event+0x2ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ccf;
	}
x86_l_2bcd:
	/* 0x2bcd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bd2:
	/* 0x2bd2: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2bd7:
	/* 0x2bd7: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2bdc:
	/* 0x2bdc: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2be1:
	/* 0x2be1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2be6:
	/* 0x2be6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be8:
	/* 0x2be8: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2bee:
	/* 0x2bee: je     2ccc <generic_retkprobe_event+0x2ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ccc;
	}
x86_l_2bf4:
	/* 0x2bf4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bf9:
	/* 0x2bf9: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2bfe:
	/* 0x2bfe: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2c03:
	/* 0x2c03: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c0b:
	/* 0x2c0b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c10:
	/* 0x2c10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c12:
	/* 0x2c12: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c19:
	/* 0x2c19: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c1d:
	/* 0x2c1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c22:
	/* 0x2c22: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2c29:
	/* 0x2c29: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c2e:
	/* 0x2c2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c30:
	/* 0x2c30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c33:
	/* 0x2c33: je     2c43 <generic_retkprobe_event+0x2c43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c43;
	}
x86_l_2c35:
	/* 0x2c35: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c38:
	/* 0x2c38: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2c3d:
	/* 0x2c3d: jne    2ccf <generic_retkprobe_event+0x2ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ccf;
	}
x86_l_2c43:
	/* 0x2c43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c48:
	/* 0x2c48: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2c4d:
	/* 0x2c4d: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2c52:
	/* 0x2c52: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c57:
	/* 0x2c57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c5c:
	/* 0x2c5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5e:
	/* 0x2c5e: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2c64:
	/* 0x2c64: je     2ccc <generic_retkprobe_event+0x2ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ccc;
	}
x86_l_2c66:
	/* 0x2c66: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c6b:
	/* 0x2c6b: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2c70:
	/* 0x2c70: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2c75:
	/* 0x2c75: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c7d:
	/* 0x2c7d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c82:
	/* 0x2c82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c84:
	/* 0x2c84: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c8b:
	/* 0x2c8b: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c94:
	/* 0x2c94: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2c9b:
	/* 0x2c9b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ca0:
	/* 0x2ca0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca2:
	/* 0x2ca2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca5:
	/* 0x2ca5: je     2cb1 <generic_retkprobe_event+0x2cb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cb1;
	}
x86_l_2ca7:
	/* 0x2ca7: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2caa:
	/* 0x2caa: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2caf:
	/* 0x2caf: jne    2ccf <generic_retkprobe_event+0x2ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ccf;
	}
x86_l_2cb1:
	/* 0x2cb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2cbb:
	/* 0x2cbb: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2cc0:
	/* 0x2cc0: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2cc5:
	/* 0x2cc5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cca:
	/* 0x2cca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ccc:
	/* 0x2ccc: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ccf:
	/* 0x2ccf: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cd4:
	/* 0x2cd4: mov    DWORD PTR [rbx],0x10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 269ULL);
x86_l_2cda:
	/* 0x2cda: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cde:
	/* 0x2cde: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2ce3:
	/* 0x2ce3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce5:
	/* 0x2ce5: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ce9:
	/* 0x2ce9: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2cec:
	/* 0x2cec: je     2cfc <generic_retkprobe_event+0x2cfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cfc;
	}
x86_l_2cee:
	/* 0x2cee: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf1:
	/* 0x2cf1: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf4:
	/* 0x2cf4: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cf8:
	/* 0x2cf8: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cfc:
	/* 0x2cfc: mov    DWORD PTR [rbx+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2d03:
	/* 0x2d03: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d07:
	/* 0x2d07: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d0b:
	/* 0x2d0b: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2d14:
	/* 0x2d14: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_2d1b:
	/* 0x2d1b: mov    rdi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2d23:
	/* 0x2d23: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2d28:
	/* 0x2d28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2a:
	/* 0x2d2a: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2d2f:
	/* 0x2d2f: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2d31:
	/* 0x2d31: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_2d38:
	/* 0x2d38: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2d3a:
	/* 0x2d3a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2d3b:
	/* 0x2d3b: jmp    2edb <cwd_read_v61+0x19b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2d40:
	/* 0x2d40: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2d42:
	/* 0x2d42: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2d44:
	/* 0x2d44: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2d46:
	/* 0x2d46: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2d47:
	/* 0x2d47: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_2d4b:
	/* 0x2d4b: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2d4e:
	/* 0x2d4e: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d52:
	/* 0x2d52: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d56:
	/* 0x2d56: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d5a:
	/* 0x2d5a: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2d5d:
	/* 0x2d5d: jne    2d69 <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d69;
	}
x86_l_2d5f:
	/* 0x2d5f: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2d63:
	/* 0x2d63: je     2eaa <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eaa;
	}
x86_l_2d69:
	/* 0x2d69: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d6e:
	/* 0x2d6e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d73:
	/* 0x2d73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d78:
	/* 0x2d78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d7a:
	/* 0x2d7a: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2d7f:
	/* 0x2d7f: je     2e5e <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e5e;
	}
x86_l_2d85:
	/* 0x2d85: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d89:
	/* 0x2d89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d8e:
	/* 0x2d8e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d93:
	/* 0x2d93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d98:
	/* 0x2d98: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d9b:
	/* 0x2d9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9d:
	/* 0x2d9d: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da2:
	/* 0x2da2: je     2e5e <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e5e;
	}
x86_l_2da8:
	/* 0x2da8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dad:
	/* 0x2dad: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2db2:
	/* 0x2db2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2db7:
	/* 0x2db7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2dba:
	/* 0x2dba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dbc:
	/* 0x2dbc: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2dc0:
	/* 0x2dc0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dc5:
	/* 0x2dc5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dca:
	/* 0x2dca: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2dcf:
	/* 0x2dcf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2dd2:
	/* 0x2dd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd4:
	/* 0x2dd4: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dd8:
	/* 0x2dd8: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ddc:
	/* 0x2ddc: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2de0:
	/* 0x2de0: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2de3:
	/* 0x2de3: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2de6:
	/* 0x2de6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de8:
	/* 0x2de8: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2dea:
	/* 0x2dea: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dec:
	/* 0x2dec: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2def:
	/* 0x2def: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2df4:
	/* 0x2df4: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df7:
	/* 0x2df7: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2df9:
	/* 0x2df9: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_2dfd:
	/* 0x2dfd: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_2e00:
	/* 0x2e00: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2e04:
	/* 0x2e04: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e07:
	/* 0x2e07: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_2e09:
	/* 0x2e09: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e0c:
	/* 0x2e0c: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e0f:
	/* 0x2e0f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e14:
	/* 0x2e14: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2e17:
	/* 0x2e17: jb     2eb3 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2eb3;
	}
x86_l_2e1d:
	/* 0x2e1d: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_2e24:
	/* 0x2e24: ja     2eb3 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2eb3;
	}
x86_l_2e2a:
	/* 0x2e2a: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2e2c:
	/* 0x2e2c: jbe    2ebf <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ebf;
	}
x86_l_2e32:
	/* 0x2e32: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e36:
	/* 0x2e36: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e3b:
	/* 0x2e3b: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e3f:
	/* 0x2e3f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e43:
	/* 0x2e43: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2e46:
	/* 0x2e46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e4b:
	/* 0x2e4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4d:
	/* 0x2e4d: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e51:
	/* 0x2e51: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e56:
	/* 0x2e56: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e5a:
	/* 0x2e5a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e5c:
	/* 0x2e5c: jmp    2eb3 <cwd_read_v61+0x173> */
	goto x86_l_2eb3;
x86_l_2e5e:
	/* 0x2e5e: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e62:
	/* 0x2e62: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e67:
	/* 0x2e67: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e6c:
	/* 0x2e6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e71:
	/* 0x2e71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e73:
	/* 0x2e73: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e77:
	/* 0x2e77: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2e7c:
	/* 0x2e7c: je     2eaa <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eaa;
	}
x86_l_2e7e:
	/* 0x2e7e: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e82:
	/* 0x2e82: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2e86:
	/* 0x2e86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e8b:
	/* 0x2e8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e90:
	/* 0x2e90: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2e93:
	/* 0x2e93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e95:
	/* 0x2e95: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e9e:
	/* 0x2e9e: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2ea2:
	/* 0x2ea2: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ea6:
	/* 0x2ea6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ea8:
	/* 0x2ea8: jmp    2eb3 <cwd_read_v61+0x173> */
	goto x86_l_2eb3;
x86_l_2eaa:
	/* 0x2eaa: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_2eae:
	/* 0x2eae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eb3:
	/* 0x2eb3: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2eb7:
	/* 0x2eb7: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2eb8:
	/* 0x2eb8: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2eba:
	/* 0x2eba: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2ebc:
	/* 0x2ebc: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2ebe:
	/* 0x2ebe: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2ebf:
	/* 0x2ebf: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ec3:
	/* 0x2ec3: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ec6:
	/* 0x2ec6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ecb:
	/* 0x2ecb: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2ece:
	/* 0x2ece: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed0:
	/* 0x2ed0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ed5:
	/* 0x2ed5: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ed9:
	/* 0x2ed9: jmp    2eb3 <cwd_read_v61+0x173> */
	goto x86_l_2eb3;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10384U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1845ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1850ULL && __x86_pc <= 3705ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3712ULL && __x86_pc <= 5570ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5575ULL && __x86_pc <= 7386ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7391ULL && __x86_pc <= 9069ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9071ULL && __x86_pc <= 10790ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10794ULL && __x86_pc <= 11993ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

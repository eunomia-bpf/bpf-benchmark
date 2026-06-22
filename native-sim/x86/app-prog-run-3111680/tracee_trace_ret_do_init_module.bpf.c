extern char args_map;
extern char binary_filter_version;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char mnt_ns_filter_version;
extern char pid_filter_version;
extern char pid_ns_filter_version;
extern char proc_info_map;
extern char process_tree_map_version;
extern char scratch_map;
extern char stack_addresses;
extern char sys_32_to_64_map;
extern char task_info_map;
extern char uid_filter_version;
extern char uts_ns_filter_version;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 18ULL: goto x86_l_12;
	case 28ULL: goto x86_l_1c;
	case 33ULL: goto x86_l_21;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 40ULL: goto x86_l_28;
	case 44ULL: goto x86_l_2c;
	case 51ULL: goto x86_l_33;
	case 54ULL: goto x86_l_36;
	case 59ULL: goto x86_l_3b;
	case 61ULL: goto x86_l_3d;
	case 64ULL: goto x86_l_40;
	case 70ULL: goto x86_l_46;
	case 73ULL: goto x86_l_49;
	case 81ULL: goto x86_l_51;
	case 86ULL: goto x86_l_56;
	case 88ULL: goto x86_l_58;
	case 90ULL: goto x86_l_5a;
	case 93ULL: goto x86_l_5d;
	case 97ULL: goto x86_l_61;
	case 104ULL: goto x86_l_68;
	case 107ULL: goto x86_l_6b;
	case 112ULL: goto x86_l_70;
	case 114ULL: goto x86_l_72;
	case 126ULL: goto x86_l_7e;
	case 138ULL: goto x86_l_8a;
	case 150ULL: goto x86_l_96;
	case 162ULL: goto x86_l_a2;
	case 167ULL: goto x86_l_a7;
	case 169ULL: goto x86_l_a9;
	case 172ULL: goto x86_l_ac;
	case 177ULL: goto x86_l_b1;
	case 179ULL: goto x86_l_b3;
	case 182ULL: goto x86_l_b6;
	case 186ULL: goto x86_l_ba;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 204ULL: goto x86_l_cc;
	case 206ULL: goto x86_l_ce;
	case 213ULL: goto x86_l_d5;
	case 218ULL: goto x86_l_da;
	case 220ULL: goto x86_l_dc;
	case 225ULL: goto x86_l_e1;
	case 227ULL: goto x86_l_e3;
	case 230ULL: goto x86_l_e6;
	case 235ULL: goto x86_l_eb;
	case 237ULL: goto x86_l_ed;
	case 240ULL: goto x86_l_f0;
	case 242ULL: goto x86_l_f2;
	case 245ULL: goto x86_l_f5;
	case 247ULL: goto x86_l_f7;
	case 251ULL: goto x86_l_fb;
	case 254ULL: goto x86_l_fe;
	case 259ULL: goto x86_l_103;
	case 264ULL: goto x86_l_108;
	case 269ULL: goto x86_l_10d;
	case 272ULL: goto x86_l_110;
	case 274ULL: goto x86_l_112;
	case 278ULL: goto x86_l_116;
	case 280ULL: goto x86_l_118;
	case 284ULL: goto x86_l_11c;
	case 286ULL: goto x86_l_11e;
	case 293ULL: goto x86_l_125;
	case 298ULL: goto x86_l_12a;
	case 303ULL: goto x86_l_12f;
	case 305ULL: goto x86_l_131;
	case 308ULL: goto x86_l_134;
	case 310ULL: goto x86_l_136;
	case 312ULL: goto x86_l_138;
	case 314ULL: goto x86_l_13a;
	case 319ULL: goto x86_l_13f;
	case 330ULL: goto x86_l_14a;
	case 338ULL: goto x86_l_152;
	case 346ULL: goto x86_l_15a;
	case 353ULL: goto x86_l_161;
	case 361ULL: goto x86_l_169;
	case 366ULL: goto x86_l_16e;
	case 368ULL: goto x86_l_170;
	case 376ULL: goto x86_l_178;
	case 379ULL: goto x86_l_17b;
	case 385ULL: goto x86_l_181;
	case 388ULL: goto x86_l_184;
	case 395ULL: goto x86_l_18b;
	case 403ULL: goto x86_l_193;
	case 408ULL: goto x86_l_198;
	case 410ULL: goto x86_l_19a;
	case 418ULL: goto x86_l_1a2;
	case 421ULL: goto x86_l_1a5;
	case 427ULL: goto x86_l_1ab;
	case 438ULL: goto x86_l_1b6;
	case 447ULL: goto x86_l_1bf;
	case 459ULL: goto x86_l_1cb;
	case 471ULL: goto x86_l_1d7;
	case 483ULL: goto x86_l_1e3;
	case 495ULL: goto x86_l_1ef;
	case 507ULL: goto x86_l_1fb;
	case 519ULL: goto x86_l_207;
	case 531ULL: goto x86_l_213;
	case 543ULL: goto x86_l_21f;
	case 551ULL: goto x86_l_227;
	case 560ULL: goto x86_l_230;
	case 569ULL: goto x86_l_239;
	case 578ULL: goto x86_l_242;
	case 587ULL: goto x86_l_24b;
	case 596ULL: goto x86_l_254;
	case 605ULL: goto x86_l_25d;
	case 614ULL: goto x86_l_266;
	case 623ULL: goto x86_l_26f;
	case 632ULL: goto x86_l_278;
	case 641ULL: goto x86_l_281;
	case 650ULL: goto x86_l_28a;
	case 659ULL: goto x86_l_293;
	case 668ULL: goto x86_l_29c;
	case 673ULL: goto x86_l_2a1;
	case 675ULL: goto x86_l_2a3;
	case 680ULL: goto x86_l_2a8;
	case 684ULL: goto x86_l_2ac;
	case 689ULL: goto x86_l_2b1;
	case 698ULL: goto x86_l_2ba;
	case 703ULL: goto x86_l_2bf;
	case 705ULL: goto x86_l_2c1;
	case 709ULL: goto x86_l_2c5;
	case 714ULL: goto x86_l_2ca;
	case 716ULL: goto x86_l_2cc;
	case 722ULL: goto x86_l_2d2;
	case 727ULL: goto x86_l_2d7;
	case 732ULL: goto x86_l_2dc;
	case 739ULL: goto x86_l_2e3;
	case 746ULL: goto x86_l_2ea;
	case 754ULL: goto x86_l_2f2;
	case 759ULL: goto x86_l_2f7;
	case 761ULL: goto x86_l_2f9;
	case 769ULL: goto x86_l_301;
	case 772ULL: goto x86_l_304;
	case 774ULL: goto x86_l_306;
	case 779ULL: goto x86_l_30b;
	case 786ULL: goto x86_l_312;
	case 793ULL: goto x86_l_319;
	case 801ULL: goto x86_l_321;
	case 806ULL: goto x86_l_326;
	case 808ULL: goto x86_l_328;
	case 816ULL: goto x86_l_330;
	case 819ULL: goto x86_l_333;
	case 825ULL: goto x86_l_339;
	case 833ULL: goto x86_l_341;
	case 838ULL: goto x86_l_346;
	case 844ULL: goto x86_l_34c;
	case 849ULL: goto x86_l_351;
	case 851ULL: goto x86_l_353;
	case 859ULL: goto x86_l_35b;
	case 864ULL: goto x86_l_360;
	case 871ULL: goto x86_l_367;
	case 875ULL: goto x86_l_36b;
	case 883ULL: goto x86_l_373;
	case 890ULL: goto x86_l_37a;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 902ULL: goto x86_l_386;
	case 905ULL: goto x86_l_389;
	case 911ULL: goto x86_l_38f;
	case 914ULL: goto x86_l_392;
	case 918ULL: goto x86_l_396;
	case 921ULL: goto x86_l_399;
	case 932ULL: goto x86_l_3a4;
	case 943ULL: goto x86_l_3af;
	case 954ULL: goto x86_l_3ba;
	case 965ULL: goto x86_l_3c5;
	case 976ULL: goto x86_l_3d0;
	case 987ULL: goto x86_l_3db;
	case 998ULL: goto x86_l_3e6;
	case 1009ULL: goto x86_l_3f1;
	case 1020ULL: goto x86_l_3fc;
	case 1031ULL: goto x86_l_407;
	case 1042ULL: goto x86_l_412;
	case 1053ULL: goto x86_l_41d;
	case 1064ULL: goto x86_l_428;
	case 1075ULL: goto x86_l_433;
	case 1086ULL: goto x86_l_43e;
	case 1097ULL: goto x86_l_449;
	case 1108ULL: goto x86_l_454;
	case 1119ULL: goto x86_l_45f;
	case 1130ULL: goto x86_l_46a;
	case 1141ULL: goto x86_l_475;
	case 1152ULL: goto x86_l_480;
	case 1163ULL: goto x86_l_48b;
	case 1174ULL: goto x86_l_496;
	case 1185ULL: goto x86_l_4a1;
	case 1196ULL: goto x86_l_4ac;
	case 1207ULL: goto x86_l_4b7;
	case 1218ULL: goto x86_l_4c2;
	case 1229ULL: goto x86_l_4cd;
	case 1240ULL: goto x86_l_4d8;
	case 1251ULL: goto x86_l_4e3;
	case 1259ULL: goto x86_l_4eb;
	case 1267ULL: goto x86_l_4f3;
	case 1275ULL: goto x86_l_4fb;
	case 1283ULL: goto x86_l_503;
	case 1291ULL: goto x86_l_50b;
	case 1299ULL: goto x86_l_513;
	case 1307ULL: goto x86_l_51b;
	case 1315ULL: goto x86_l_523;
	case 1323ULL: goto x86_l_52b;
	case 1331ULL: goto x86_l_533;
	case 1339ULL: goto x86_l_53b;
	case 1347ULL: goto x86_l_543;
	case 1355ULL: goto x86_l_54b;
	case 1363ULL: goto x86_l_553;
	case 1371ULL: goto x86_l_55b;
	case 1378ULL: goto x86_l_562;
	case 1385ULL: goto x86_l_569;
	case 1388ULL: goto x86_l_56c;
	case 1393ULL: goto x86_l_571;
	case 1398ULL: goto x86_l_576;
	case 1401ULL: goto x86_l_579;
	case 1403ULL: goto x86_l_57b;
	case 1408ULL: goto x86_l_580;
	case 1413ULL: goto x86_l_585;
	case 1416ULL: goto x86_l_588;
	case 1418ULL: goto x86_l_58a;
	case 1426ULL: goto x86_l_592;
	case 1429ULL: goto x86_l_595;
	case 1435ULL: goto x86_l_59b;
	case 1440ULL: goto x86_l_5a0;
	case 1447ULL: goto x86_l_5a7;
	case 1451ULL: goto x86_l_5ab;
	case 1459ULL: goto x86_l_5b3;
	case 1466ULL: goto x86_l_5ba;
	case 1471ULL: goto x86_l_5bf;
	case 1476ULL: goto x86_l_5c4;
	case 1482ULL: goto x86_l_5ca;
	case 1484ULL: goto x86_l_5cc;
	case 1487ULL: goto x86_l_5cf;
	case 1493ULL: goto x86_l_5d5;
	case 1496ULL: goto x86_l_5d8;
	case 1500ULL: goto x86_l_5dc;
	case 1503ULL: goto x86_l_5df;
	case 1514ULL: goto x86_l_5ea;
	case 1525ULL: goto x86_l_5f5;
	case 1536ULL: goto x86_l_600;
	case 1547ULL: goto x86_l_60b;
	case 1558ULL: goto x86_l_616;
	case 1569ULL: goto x86_l_621;
	case 1580ULL: goto x86_l_62c;
	case 1591ULL: goto x86_l_637;
	case 1602ULL: goto x86_l_642;
	case 1610ULL: goto x86_l_64a;
	case 1618ULL: goto x86_l_652;
	case 1626ULL: goto x86_l_65a;
	case 1634ULL: goto x86_l_662;
	case 1642ULL: goto x86_l_66a;
	case 1650ULL: goto x86_l_672;
	case 1658ULL: goto x86_l_67a;
	case 1666ULL: goto x86_l_682;
	case 1674ULL: goto x86_l_68a;
	case 1682ULL: goto x86_l_692;
	case 1690ULL: goto x86_l_69a;
	case 1698ULL: goto x86_l_6a2;
	case 1706ULL: goto x86_l_6aa;
	case 1714ULL: goto x86_l_6b2;
	case 1722ULL: goto x86_l_6ba;
	case 1729ULL: goto x86_l_6c1;
	case 1736ULL: goto x86_l_6c8;
	case 1739ULL: goto x86_l_6cb;
	case 1744ULL: goto x86_l_6d0;
	case 1749ULL: goto x86_l_6d5;
	case 1752ULL: goto x86_l_6d8;
	case 1754ULL: goto x86_l_6da;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1767ULL: goto x86_l_6e7;
	case 1769ULL: goto x86_l_6e9;
	case 1777ULL: goto x86_l_6f1;
	case 1780ULL: goto x86_l_6f4;
	case 1786ULL: goto x86_l_6fa;
	case 1789ULL: goto x86_l_6fd;
	case 1797ULL: goto x86_l_705;
	case 1801ULL: goto x86_l_709;
	case 1804ULL: goto x86_l_70c;
	case 1809ULL: goto x86_l_711;
	case 1814ULL: goto x86_l_716;
	case 1819ULL: goto x86_l_71b;
	case 1822ULL: goto x86_l_71e;
	case 1824ULL: goto x86_l_720;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1837ULL: goto x86_l_72d;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1850ULL: goto x86_l_73a;
	case 1855ULL: goto x86_l_73f;
	case 1857ULL: goto x86_l_741;
	case 1861ULL: goto x86_l_745;
	case 1865ULL: goto x86_l_749;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1885ULL: goto x86_l_75d;
	case 1889ULL: goto x86_l_761;
	case 1893ULL: goto x86_l_765;
	case 1896ULL: goto x86_l_768;
	case 1901ULL: goto x86_l_76d;
	case 1906ULL: goto x86_l_772;
	case 1911ULL: goto x86_l_777;
	case 1913ULL: goto x86_l_779;
	case 1916ULL: goto x86_l_77c;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1929ULL: goto x86_l_789;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1950ULL: goto x86_l_79e;
	case 1952ULL: goto x86_l_7a0;
	case 1956ULL: goto x86_l_7a4;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1969ULL: goto x86_l_7b1;
	case 1974ULL: goto x86_l_7b6;
	case 1977ULL: goto x86_l_7b9;
	case 1979ULL: goto x86_l_7bb;
	case 1982ULL: goto x86_l_7be;
	case 1986ULL: goto x86_l_7c2;
	case 1990ULL: goto x86_l_7c6;
	case 1994ULL: goto x86_l_7ca;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2014ULL: goto x86_l_7de;
	case 2017ULL: goto x86_l_7e1;
	case 2021ULL: goto x86_l_7e5;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2039ULL: goto x86_l_7f7;
	case 2042ULL: goto x86_l_7fa;
	case 2044ULL: goto x86_l_7fc;
	case 2048ULL: goto x86_l_800;
	case 2052ULL: goto x86_l_804;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2072ULL: goto x86_l_818;
	case 2076ULL: goto x86_l_81c;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2097ULL: goto x86_l_831;
	case 2099ULL: goto x86_l_833;
	case 2102ULL: goto x86_l_836;
	case 2106ULL: goto x86_l_83a;
	case 2110ULL: goto x86_l_83e;
	case 2114ULL: goto x86_l_842;
	case 2117ULL: goto x86_l_845;
	case 2122ULL: goto x86_l_84a;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2134ULL: goto x86_l_856;
	case 2137ULL: goto x86_l_859;
	case 2141ULL: goto x86_l_85d;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2162ULL: goto x86_l_872;
	case 2164ULL: goto x86_l_874;
	case 2168ULL: goto x86_l_878;
	case 2171ULL: goto x86_l_87b;
	case 2176ULL: goto x86_l_880;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2189ULL: goto x86_l_88d;
	case 2191ULL: goto x86_l_88f;
	case 2194ULL: goto x86_l_892;
	case 2198ULL: goto x86_l_896;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 232ULL);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0x98],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_12:
	/* 0x12: movabs rbx,0x2fa00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 3272765079552ULL);
x86_l_1c:
	/* 0x1c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_21:
	/* 0x21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23:
	/* 0x23: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25:
	/* 0x25: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_28:
	/* 0x28: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c:
	/* 0x2c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_33:
	/* 0x33: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_36:
	/* 0x36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b:
	/* 0x3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d:
	/* 0x3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40:
	/* 0x40: je     255a <trace_ret_do_init_module+0x255a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9562ULL;
	}
x86_l_46:
	/* 0x46: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49:
	/* 0x49: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_51:
	/* 0x51: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_56:
	/* 0x56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58:
	/* 0x58: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a:
	/* 0x5a: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61:
	/* 0x61: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_68:
	/* 0x68: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6b:
	/* 0x6b: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_70:
	/* 0x70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72:
	/* 0x72: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_7e:
	/* 0x7e: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_8a:
	/* 0x8a: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_96:
	/* 0x96: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_a2:
	/* 0xa2: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_a7:
	/* 0xa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9:
	/* 0xa9: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_ac:
	/* 0xac: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_b1:
	/* 0xb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3:
	/* 0xb3: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_b6:
	/* 0xb6: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ba:
	/* 0xba: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c2:
	/* 0xc2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c7:
	/* 0xc7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cc:
	/* 0xcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce:
	/* 0xce: test   DWORD PTR [rsp],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2097152ULL);
x86_l_d5:
	/* 0xd5: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_da:
	/* 0xda: jne    13f <trace_ret_do_init_module+0x13f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13f;
	}
x86_l_dc:
	/* 0xdc: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_e1:
	/* 0xe1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3:
	/* 0xe3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e6:
	/* 0xe6: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_eb:
	/* 0xeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed:
	/* 0xed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0:
	/* 0xf0: je     f7 <trace_ret_do_init_module+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f7;
	}
x86_l_f2:
	/* 0xf2: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f5:
	/* 0xf5: jmp    f7 <trace_ret_do_init_module+0xf7> */
	goto x86_l_f7;
x86_l_f7:
	/* 0xf7: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fb:
	/* 0xfb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_103:
	/* 0x103: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_108:
	/* 0x108: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10d:
	/* 0x10d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_110:
	/* 0x110: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112:
	/* 0x112: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_116:
	/* 0x116: jne    11e <trace_ret_do_init_module+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11e;
	}
x86_l_118:
	/* 0x118: mov    ebp,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11c:
	/* 0x11c: jmp    13f <trace_ret_do_init_module+0x13f> */
	goto x86_l_13f;
x86_l_11e:
	/* 0x11e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_125:
	/* 0x125: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_12a:
	/* 0x12a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f:
	/* 0x12f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131:
	/* 0x131: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_134:
	/* 0x134: je     13a <trace_ret_do_init_module+0x13a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a;
	}
x86_l_136:
	/* 0x136: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_138:
	/* 0x138: jmp    13f <trace_ret_do_init_module+0x13f> */
	goto x86_l_13f;
x86_l_13a:
	/* 0x13a: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_13f:
	/* 0x13f: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_14a:
	/* 0x14a: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_152:
	/* 0x152: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_15a:
	/* 0x15a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_161:
	/* 0x161: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_169:
	/* 0x169: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e:
	/* 0x16e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170:
	/* 0x170: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_178:
	/* 0x178: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17b:
	/* 0x17b: je     255a <trace_ret_do_init_module+0x255a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9562ULL;
	}
x86_l_181:
	/* 0x181: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_18b:
	/* 0x18b: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_193:
	/* 0x193: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_198:
	/* 0x198: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a:
	/* 0x19a: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a2:
	/* 0x1a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: je     255a <trace_ret_do_init_module+0x255a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9562ULL;
	}
x86_l_1ab:
	/* 0x1ab: mov    WORD PTR [r12+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_1b6:
	/* 0x1b6: mov    BYTE PTR [r12+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [r12+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_1cb:
	/* 0x1cb: mov    QWORD PTR [r12+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_1d7:
	/* 0x1d7: mov    QWORD PTR [r12+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_1e3:
	/* 0x1e3: mov    QWORD PTR [r12+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1ef:
	/* 0x1ef: mov    QWORD PTR [r12+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1fb:
	/* 0x1fb: mov    QWORD PTR [r12+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_207:
	/* 0x207: mov    QWORD PTR [r12+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_213:
	/* 0x213: mov    QWORD PTR [r12+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_21f:
	/* 0x21f: mov    QWORD PTR [r12+0x7dd0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_227:
	/* 0x227: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_230:
	/* 0x230: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_239:
	/* 0x239: mov    QWORD PTR [r12+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_242:
	/* 0x242: mov    QWORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_24b:
	/* 0x24b: mov    QWORD PTR [r12+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_254:
	/* 0x254: mov    QWORD PTR [r12+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_25d:
	/* 0x25d: mov    QWORD PTR [r12+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_266:
	/* 0x266: mov    QWORD PTR [r12+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_26f:
	/* 0x26f: mov    QWORD PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_278:
	/* 0x278: mov    QWORD PTR [r12+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_281:
	/* 0x281: mov    QWORD PTR [r12+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_28a:
	/* 0x28a: mov    QWORD PTR [r12+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_293:
	/* 0x293: mov    QWORD PTR [r12+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_29c:
	/* 0x29c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2a1:
	/* 0x2a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3:
	/* 0x2a3: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a8:
	/* 0x2a8: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2ac:
	/* 0x2ac: mov    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b1:
	/* 0x2b1: mov    DWORD PTR [r12+0x70],0x310 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337936ULL);
x86_l_2ba:
	/* 0x2ba: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2bf:
	/* 0x2bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1:
	/* 0x2c1: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c5:
	/* 0x2c5: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2ca:
	/* 0x2ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc:
	/* 0x2cc: mov    WORD PTR [r12+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2d2:
	/* 0x2d2: mov    DWORD PTR [r12+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_2d7:
	/* 0x2d7: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2dc:
	/* 0x2dc: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2e3:
	/* 0x2e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_2ea:
	/* 0x2ea: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2f2:
	/* 0x2f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f7:
	/* 0x2f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9:
	/* 0x2f9: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_301:
	/* 0x301: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_304:
	/* 0x304: je     360 <trace_ret_do_init_module+0x360> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_360;
	}
x86_l_306:
	/* 0x306: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30b:
	/* 0x30b: mov    DWORD PTR [rsp+0x8c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_312:
	/* 0x312: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_319:
	/* 0x319: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_321:
	/* 0x321: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_326:
	/* 0x326: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_328:
	/* 0x328: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_330:
	/* 0x330: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_333:
	/* 0x333: je     5a0 <trace_ret_do_init_module+0x5a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a0;
	}
x86_l_339:
	/* 0x339: mov    r14,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_341:
	/* 0x341: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_346:
	/* 0x346: jne    b43 <trace_ret_do_init_module+0xb43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2883ULL;
	}
x86_l_34c:
	/* 0x34c: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_351:
	/* 0x351: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_353:
	/* 0x353: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_35b:
	/* 0x35b: jmp    bec <trace_ret_do_init_module+0xbec> */
	return 3052ULL;
x86_l_360:
	/* 0x360: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_367:
	/* 0x367: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_36b:
	/* 0x36b: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_373:
	/* 0x373: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_37a:
	/* 0x37a: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_37f:
	/* 0x37f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_384:
	/* 0x384: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_386:
	/* 0x386: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_389:
	/* 0x389: je     255a <trace_ret_do_init_module+0x255a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9562ULL;
	}
x86_l_38f:
	/* 0x38f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_392:
	/* 0x392: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_396:
	/* 0x396: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_399:
	/* 0x399: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_3a4:
	/* 0x3a4: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_3af:
	/* 0x3af: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_3ba:
	/* 0x3ba: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_3c5:
	/* 0x3c5: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_3d0:
	/* 0x3d0: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_3db:
	/* 0x3db: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_3e6:
	/* 0x3e6: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_3f1:
	/* 0x3f1: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_3fc:
	/* 0x3fc: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_407:
	/* 0x407: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_412:
	/* 0x412: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_41d:
	/* 0x41d: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_428:
	/* 0x428: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_43e:
	/* 0x43e: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_449:
	/* 0x449: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_454:
	/* 0x454: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_45f:
	/* 0x45f: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_46a:
	/* 0x46a: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_475:
	/* 0x475: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_480:
	/* 0x480: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_48b:
	/* 0x48b: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_496:
	/* 0x496: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_4a1:
	/* 0x4a1: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_4ac:
	/* 0x4ac: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_4b7:
	/* 0x4b7: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_4c2:
	/* 0x4c2: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_4cd:
	/* 0x4cd: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_4d8:
	/* 0x4d8: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_4e3:
	/* 0x4e3: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_4eb:
	/* 0x4eb: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4f3:
	/* 0x4f3: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4fb:
	/* 0x4fb: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_503:
	/* 0x503: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_50b:
	/* 0x50b: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_513:
	/* 0x513: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_51b:
	/* 0x51b: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_523:
	/* 0x523: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_52b:
	/* 0x52b: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_533:
	/* 0x533: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_53b:
	/* 0x53b: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_543:
	/* 0x543: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_54b:
	/* 0x54b: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_553:
	/* 0x553: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_55b:
	/* 0x55b: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_562:
	/* 0x562: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_569:
	/* 0x569: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_56c:
	/* 0x56c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_571:
	/* 0x571: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_576:
	/* 0x576: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_579:
	/* 0x579: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57b:
	/* 0x57b: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_580:
	/* 0x580: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_585:
	/* 0x585: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_588:
	/* 0x588: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58a:
	/* 0x58a: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_592:
	/* 0x592: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_595:
	/* 0x595: jne    306 <trace_ret_do_init_module+0x306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_306;
	}
x86_l_59b:
	/* 0x59b: jmp    255a <trace_ret_do_init_module+0x255a> */
	return 9562ULL;
x86_l_5a0:
	/* 0x5a0: mov    eax,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_5a7:
	/* 0x5a7: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5ab:
	/* 0x5ab: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5b3:
	/* 0x5b3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_5ba:
	/* 0x5ba: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5bf:
	/* 0x5bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c4:
	/* 0x5c4: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_5ca:
	/* 0x5ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cc:
	/* 0x5cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5cf:
	/* 0x5cf: je     255a <trace_ret_do_init_module+0x255a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9562ULL;
	}
x86_l_5d5:
	/* 0x5d5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5d8:
	/* 0x5d8: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5dc:
	/* 0x5dc: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5df:
	/* 0x5df: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_5ea:
	/* 0x5ea: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_5f5:
	/* 0x5f5: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_600:
	/* 0x600: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_60b:
	/* 0x60b: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_616:
	/* 0x616: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_621:
	/* 0x621: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_62c:
	/* 0x62c: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_637:
	/* 0x637: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_642:
	/* 0x642: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_64a:
	/* 0x64a: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_652:
	/* 0x652: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_65a:
	/* 0x65a: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_662:
	/* 0x662: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_66a:
	/* 0x66a: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_672:
	/* 0x672: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_67a:
	/* 0x67a: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_682:
	/* 0x682: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_68a:
	/* 0x68a: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_692:
	/* 0x692: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_69a:
	/* 0x69a: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6a2:
	/* 0x6a2: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6aa:
	/* 0x6aa: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6b2:
	/* 0x6b2: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6ba:
	/* 0x6ba: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c1:
	/* 0x6c1: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_6c8:
	/* 0x6c8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6cb:
	/* 0x6cb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6d0:
	/* 0x6d0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6d5:
	/* 0x6d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6d8:
	/* 0x6d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6da:
	/* 0x6da: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6df:
	/* 0x6df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6e4:
	/* 0x6e4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6e7:
	/* 0x6e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e9:
	/* 0x6e9: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6f1:
	/* 0x6f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f4:
	/* 0x6f4: je     255a <trace_ret_do_init_module+0x255a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9562ULL;
	}
x86_l_6fa:
	/* 0x6fa: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6fd:
	/* 0x6fd: mov    rbx,QWORD PTR [r12+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_705:
	/* 0x705: lea    r13,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_709:
	/* 0x709: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_70c:
	/* 0x70c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_711:
	/* 0x711: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_716:
	/* 0x716: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_71b:
	/* 0x71b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_71e:
	/* 0x71e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_720:
	/* 0x720: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_724:
	/* 0x724: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_729:
	/* 0x729: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_72d:
	/* 0x72d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_730:
	/* 0x730: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_735:
	/* 0x735: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_73a:
	/* 0x73a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_73f:
	/* 0x73f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_741:
	/* 0x741: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_745:
	/* 0x745: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_749:
	/* 0x749: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_74c:
	/* 0x74c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_751:
	/* 0x751: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_756:
	/* 0x756: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_75b:
	/* 0x75b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75d:
	/* 0x75d: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_761:
	/* 0x761: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_765:
	/* 0x765: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_768:
	/* 0x768: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_76d:
	/* 0x76d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_772:
	/* 0x772: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_777:
	/* 0x777: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_779:
	/* 0x779: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77c:
	/* 0x77c: mov    DWORD PTR [r15+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_780:
	/* 0x780: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_785:
	/* 0x785: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_789:
	/* 0x789: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_78c:
	/* 0x78c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_791:
	/* 0x791: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_796:
	/* 0x796: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_79b:
	/* 0x79b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_79e:
	/* 0x79e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a0:
	/* 0x7a0: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a4:
	/* 0x7a4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7a7:
	/* 0x7a7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7ac:
	/* 0x7ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b1:
	/* 0x7b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7b6:
	/* 0x7b6: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_7b9:
	/* 0x7b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bb:
	/* 0x7bb: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7be:
	/* 0x7be: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7c2:
	/* 0x7c2: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7c6:
	/* 0x7c6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7ca:
	/* 0x7ca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7cd:
	/* 0x7cd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7d2:
	/* 0x7d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7d7:
	/* 0x7d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7dc:
	/* 0x7dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7de:
	/* 0x7de: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e1:
	/* 0x7e1: mov    DWORD PTR [r15+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7e5:
	/* 0x7e5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7e8:
	/* 0x7e8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7ed:
	/* 0x7ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f2:
	/* 0x7f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f7:
	/* 0x7f7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7fa:
	/* 0x7fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fc:
	/* 0x7fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_800:
	/* 0x800: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_804:
	/* 0x804: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_807:
	/* 0x807: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_80c:
	/* 0x80c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_811:
	/* 0x811: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_816:
	/* 0x816: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_818:
	/* 0x818: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81c:
	/* 0x81c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_81f:
	/* 0x81f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_824:
	/* 0x824: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_829:
	/* 0x829: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_82e:
	/* 0x82e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_831:
	/* 0x831: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_833:
	/* 0x833: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_836:
	/* 0x836: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_83a:
	/* 0x83a: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_83e:
	/* 0x83e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_842:
	/* 0x842: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_845:
	/* 0x845: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_84a:
	/* 0x84a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_84f:
	/* 0x84f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_854:
	/* 0x854: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_856:
	/* 0x856: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_859:
	/* 0x859: mov    DWORD PTR [r15+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_85d:
	/* 0x85d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_860:
	/* 0x860: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_865:
	/* 0x865: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_86a:
	/* 0x86a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_86f:
	/* 0x86f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_872:
	/* 0x872: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_874:
	/* 0x874: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_878:
	/* 0x878: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_87b:
	/* 0x87b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_880:
	/* 0x880: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_885:
	/* 0x885: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_88a:
	/* 0x88a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_88d:
	/* 0x88d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88f:
	/* 0x88f: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_892:
	/* 0x892: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_896:
	/* 0x896: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
	return 2202ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2202ULL: goto x86_l_89a;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2214ULL: goto x86_l_8a6;
	case 2219ULL: goto x86_l_8ab;
	case 2224ULL: goto x86_l_8b0;
	case 2226ULL: goto x86_l_8b2;
	case 2230ULL: goto x86_l_8b6;
	case 2234ULL: goto x86_l_8ba;
	case 2237ULL: goto x86_l_8bd;
	case 2242ULL: goto x86_l_8c2;
	case 2247ULL: goto x86_l_8c7;
	case 2252ULL: goto x86_l_8cc;
	case 2254ULL: goto x86_l_8ce;
	case 2258ULL: goto x86_l_8d2;
	case 2262ULL: goto x86_l_8d6;
	case 2265ULL: goto x86_l_8d9;
	case 2270ULL: goto x86_l_8de;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2283ULL: goto x86_l_8eb;
	case 2285ULL: goto x86_l_8ed;
	case 2289ULL: goto x86_l_8f1;
	case 2292ULL: goto x86_l_8f4;
	case 2297ULL: goto x86_l_8f9;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2310ULL: goto x86_l_906;
	case 2312ULL: goto x86_l_908;
	case 2315ULL: goto x86_l_90b;
	case 2319ULL: goto x86_l_90f;
	case 2323ULL: goto x86_l_913;
	case 2327ULL: goto x86_l_917;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2347ULL: goto x86_l_92b;
	case 2351ULL: goto x86_l_92f;
	case 2355ULL: goto x86_l_933;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2373ULL: goto x86_l_945;
	case 2375ULL: goto x86_l_947;
	case 2379ULL: goto x86_l_94b;
	case 2381ULL: goto x86_l_94d;
	case 2384ULL: goto x86_l_950;
	case 2389ULL: goto x86_l_955;
	case 2394ULL: goto x86_l_95a;
	case 2399ULL: goto x86_l_95f;
	case 2402ULL: goto x86_l_962;
	case 2404ULL: goto x86_l_964;
	case 2408ULL: goto x86_l_968;
	case 2411ULL: goto x86_l_96b;
	case 2416ULL: goto x86_l_970;
	case 2421ULL: goto x86_l_975;
	case 2426ULL: goto x86_l_97a;
	case 2429ULL: goto x86_l_97d;
	case 2431ULL: goto x86_l_97f;
	case 2434ULL: goto x86_l_982;
	case 2438ULL: goto x86_l_986;
	case 2442ULL: goto x86_l_98a;
	case 2446ULL: goto x86_l_98e;
	case 2449ULL: goto x86_l_991;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2466ULL: goto x86_l_9a2;
	case 2469ULL: goto x86_l_9a5;
	case 2473ULL: goto x86_l_9a9;
	case 2477ULL: goto x86_l_9ad;
	case 2482ULL: goto x86_l_9b2;
	case 2489ULL: goto x86_l_9b9;
	case 2492ULL: goto x86_l_9bc;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2510ULL: goto x86_l_9ce;
	case 2512ULL: goto x86_l_9d0;
	case 2516ULL: goto x86_l_9d4;
	case 2520ULL: goto x86_l_9d8;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2540ULL: goto x86_l_9ec;
	case 2544ULL: goto x86_l_9f0;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2563ULL: goto x86_l_a03;
	case 2568ULL: goto x86_l_a08;
	case 2570ULL: goto x86_l_a0a;
	case 2574ULL: goto x86_l_a0e;
	case 2578ULL: goto x86_l_a12;
	case 2583ULL: goto x86_l_a17;
	case 2585ULL: goto x86_l_a19;
	case 2589ULL: goto x86_l_a1d;
	case 2593ULL: goto x86_l_a21;
	case 2596ULL: goto x86_l_a24;
	case 2601ULL: goto x86_l_a29;
	case 2606ULL: goto x86_l_a2e;
	case 2611ULL: goto x86_l_a33;
	case 2613ULL: goto x86_l_a35;
	case 2617ULL: goto x86_l_a39;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2629ULL: goto x86_l_a45;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2649ULL: goto x86_l_a59;
	case 2653ULL: goto x86_l_a5d;
	case 2657ULL: goto x86_l_a61;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2682ULL: goto x86_l_a7a;
	case 2684ULL: goto x86_l_a7c;
	case 2688ULL: goto x86_l_a80;
	case 2692ULL: goto x86_l_a84;
	case 2695ULL: goto x86_l_a87;
	case 2700ULL: goto x86_l_a8c;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2713ULL: goto x86_l_a99;
	case 2715ULL: goto x86_l_a9b;
	case 2719ULL: goto x86_l_a9f;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2734ULL: goto x86_l_aae;
	case 2738ULL: goto x86_l_ab2;
	case 2746ULL: goto x86_l_aba;
	case 2751ULL: goto x86_l_abf;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2763ULL: goto x86_l_acb;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2784ULL: goto x86_l_ae0;
	case 2786ULL: goto x86_l_ae2;
	case 2790ULL: goto x86_l_ae6;
	case 2793ULL: goto x86_l_ae9;
	case 2798ULL: goto x86_l_aee;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2810ULL: goto x86_l_afa;
	case 2814ULL: goto x86_l_afe;
	case 2817ULL: goto x86_l_b01;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2830ULL: goto x86_l_b0e;
	case 2835ULL: goto x86_l_b13;
	case 2837ULL: goto x86_l_b15;
	case 2841ULL: goto x86_l_b19;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2854ULL: goto x86_l_b26;
	case 2859ULL: goto x86_l_b2b;
	case 2862ULL: goto x86_l_b2e;
	case 2864ULL: goto x86_l_b30;
	case 2872ULL: goto x86_l_b38;
	case 2877ULL: goto x86_l_b3d;
	case 2883ULL: goto x86_l_b43;
	case 2891ULL: goto x86_l_b4b;
	case 2896ULL: goto x86_l_b50;
	case 2903ULL: goto x86_l_b57;
	case 2908ULL: goto x86_l_b5c;
	case 2913ULL: goto x86_l_b61;
	case 2918ULL: goto x86_l_b66;
	case 2923ULL: goto x86_l_b6b;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2935ULL: goto x86_l_b77;
	case 2940ULL: goto x86_l_b7c;
	case 2945ULL: goto x86_l_b81;
	case 2950ULL: goto x86_l_b86;
	case 2955ULL: goto x86_l_b8b;
	case 2957ULL: goto x86_l_b8d;
	case 2962ULL: goto x86_l_b92;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2975ULL: goto x86_l_b9f;
	case 2980ULL: goto x86_l_ba4;
	case 2985ULL: goto x86_l_ba9;
	case 2987ULL: goto x86_l_bab;
	case 2991ULL: goto x86_l_baf;
	case 2994ULL: goto x86_l_bb2;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3011ULL: goto x86_l_bc3;
	case 3015ULL: goto x86_l_bc7;
	case 3018ULL: goto x86_l_bca;
	case 3020ULL: goto x86_l_bcc;
	case 3024ULL: goto x86_l_bd0;
	case 3027ULL: goto x86_l_bd3;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3042ULL: goto x86_l_be2;
	case 3044ULL: goto x86_l_be4;
	case 3048ULL: goto x86_l_be8;
	case 3050ULL: goto x86_l_bea;
	case 3052ULL: goto x86_l_bec;
	case 3056ULL: goto x86_l_bf0;
	case 3064ULL: goto x86_l_bf8;
	case 3068ULL: goto x86_l_bfc;
	case 3072ULL: goto x86_l_c00;
	case 3079ULL: goto x86_l_c07;
	case 3084ULL: goto x86_l_c0c;
	case 3089ULL: goto x86_l_c11;
	case 3091ULL: goto x86_l_c13;
	case 3094ULL: goto x86_l_c16;
	case 3096ULL: goto x86_l_c18;
	case 3099ULL: goto x86_l_c1b;
	case 3106ULL: goto x86_l_c22;
	case 3109ULL: goto x86_l_c25;
	case 3112ULL: goto x86_l_c28;
	case 3114ULL: goto x86_l_c2a;
	case 3118ULL: goto x86_l_c2e;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3133ULL: goto x86_l_c3d;
	case 3144ULL: goto x86_l_c48;
	case 3151ULL: goto x86_l_c4f;
	case 3156ULL: goto x86_l_c54;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3175ULL: goto x86_l_c67;
	case 3178ULL: goto x86_l_c6a;
	case 3180ULL: goto x86_l_c6c;
	case 3183ULL: goto x86_l_c6f;
	case 3186ULL: goto x86_l_c72;
	case 3191ULL: goto x86_l_c77;
	case 3193ULL: goto x86_l_c79;
	case 3196ULL: goto x86_l_c7c;
	case 3198ULL: goto x86_l_c7e;
	case 3202ULL: goto x86_l_c82;
	case 3209ULL: goto x86_l_c89;
	case 3212ULL: goto x86_l_c8c;
	case 3219ULL: goto x86_l_c93;
	case 3223ULL: goto x86_l_c97;
	case 3227ULL: goto x86_l_c9b;
	case 3234ULL: goto x86_l_ca2;
	case 3241ULL: goto x86_l_ca9;
	case 3245ULL: goto x86_l_cad;
	case 3252ULL: goto x86_l_cb4;
	case 3256ULL: goto x86_l_cb8;
	case 3263ULL: goto x86_l_cbf;
	case 3267ULL: goto x86_l_cc3;
	case 3274ULL: goto x86_l_cca;
	case 3278ULL: goto x86_l_cce;
	case 3285ULL: goto x86_l_cd5;
	case 3292ULL: goto x86_l_cdc;
	case 3299ULL: goto x86_l_ce3;
	case 3307ULL: goto x86_l_ceb;
	case 3315ULL: goto x86_l_cf3;
	case 3317ULL: goto x86_l_cf5;
	case 3321ULL: goto x86_l_cf9;
	case 3329ULL: goto x86_l_d01;
	case 3333ULL: goto x86_l_d05;
	case 3338ULL: goto x86_l_d0a;
	case 3340ULL: goto x86_l_d0c;
	case 3342ULL: goto x86_l_d0e;
	case 3349ULL: goto x86_l_d15;
	case 3357ULL: goto x86_l_d1d;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3375ULL: goto x86_l_d2f;
	case 3378ULL: goto x86_l_d32;
	case 3384ULL: goto x86_l_d38;
	case 3392ULL: goto x86_l_d40;
	case 3399ULL: goto x86_l_d47;
	case 3402ULL: goto x86_l_d4a;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3411ULL: goto x86_l_d53;
	case 3414ULL: goto x86_l_d56;
	case 3417ULL: goto x86_l_d59;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3434ULL: goto x86_l_d6a;
	case 3437ULL: goto x86_l_d6d;
	case 3439ULL: goto x86_l_d6f;
	case 3447ULL: goto x86_l_d77;
	case 3449ULL: goto x86_l_d79;
	case 3456ULL: goto x86_l_d80;
	case 3459ULL: goto x86_l_d83;
	case 3462ULL: goto x86_l_d86;
	case 3465ULL: goto x86_l_d89;
	case 3472ULL: goto x86_l_d90;
	case 3475ULL: goto x86_l_d93;
	case 3478ULL: goto x86_l_d96;
	case 3485ULL: goto x86_l_d9d;
	case 3488ULL: goto x86_l_da0;
	case 3490ULL: goto x86_l_da2;
	case 3494ULL: goto x86_l_da6;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3503ULL: goto x86_l_daf;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3516ULL: goto x86_l_dbc;
	case 3524ULL: goto x86_l_dc4;
	case 3531ULL: goto x86_l_dcb;
	case 3534ULL: goto x86_l_dce;
	case 3542ULL: goto x86_l_dd6;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3551ULL: goto x86_l_ddf;
	case 3554ULL: goto x86_l_de2;
	case 3561ULL: goto x86_l_de9;
	case 3564ULL: goto x86_l_dec;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3579ULL: goto x86_l_dfb;
	case 3582ULL: goto x86_l_dfe;
	case 3588ULL: goto x86_l_e04;
	case 3594ULL: goto x86_l_e0a;
	case 3601ULL: goto x86_l_e11;
	case 3606ULL: goto x86_l_e16;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3625ULL: goto x86_l_e29;
	case 3630ULL: goto x86_l_e2e;
	case 3635ULL: goto x86_l_e33;
	case 3642ULL: goto x86_l_e3a;
	case 3645ULL: goto x86_l_e3d;
	case 3650ULL: goto x86_l_e42;
	case 3652ULL: goto x86_l_e44;
	case 3655ULL: goto x86_l_e47;
	case 3659ULL: goto x86_l_e4b;
	case 3663ULL: goto x86_l_e4f;
	case 3670ULL: goto x86_l_e56;
	case 3673ULL: goto x86_l_e59;
	case 3675ULL: goto x86_l_e5b;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3686ULL: goto x86_l_e66;
	case 3688ULL: goto x86_l_e68;
	case 3691ULL: goto x86_l_e6b;
	case 3693ULL: goto x86_l_e6d;
	case 3696ULL: goto x86_l_e70;
	case 3700ULL: goto x86_l_e74;
	case 3703ULL: goto x86_l_e77;
	case 3705ULL: goto x86_l_e79;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3718ULL: goto x86_l_e86;
	case 3722ULL: goto x86_l_e8a;
	case 3725ULL: goto x86_l_e8d;
	case 3728ULL: goto x86_l_e90;
	case 3730ULL: goto x86_l_e92;
	case 3734ULL: goto x86_l_e96;
	case 3736ULL: goto x86_l_e98;
	case 3739ULL: goto x86_l_e9b;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3749ULL: goto x86_l_ea5;
	case 3753ULL: goto x86_l_ea9;
	case 3757ULL: goto x86_l_ead;
	case 3764ULL: goto x86_l_eb4;
	case 3767ULL: goto x86_l_eb7;
	case 3769ULL: goto x86_l_eb9;
	case 3774ULL: goto x86_l_ebe;
	case 3777ULL: goto x86_l_ec1;
	case 3782ULL: goto x86_l_ec6;
	case 3785ULL: goto x86_l_ec9;
	case 3787ULL: goto x86_l_ecb;
	case 3790ULL: goto x86_l_ece;
	case 3792ULL: goto x86_l_ed0;
	case 3795ULL: goto x86_l_ed3;
	case 3799ULL: goto x86_l_ed7;
	case 3802ULL: goto x86_l_eda;
	case 3804ULL: goto x86_l_edc;
	case 3811ULL: goto x86_l_ee3;
	case 3818ULL: goto x86_l_eea;
	default: return 0xffffffffffffffffULL;
	}
x86_l_89a:
	/* 0x89a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_89e:
	/* 0x89e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8a1:
	/* 0x8a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8a6:
	/* 0x8a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8ab:
	/* 0x8ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b0:
	/* 0x8b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b2:
	/* 0x8b2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b6:
	/* 0x8b6: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_8ba:
	/* 0x8ba: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8bd:
	/* 0x8bd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8c2:
	/* 0x8c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8c7:
	/* 0x8c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8cc:
	/* 0x8cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ce:
	/* 0x8ce: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8d2:
	/* 0x8d2: lea    rbx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8d6:
	/* 0x8d6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8d9:
	/* 0x8d9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8de:
	/* 0x8de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8e3:
	/* 0x8e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8e8:
	/* 0x8e8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_8eb:
	/* 0x8eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ed:
	/* 0x8ed: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f1:
	/* 0x8f1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8f4:
	/* 0x8f4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8f9:
	/* 0x8f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8fe:
	/* 0x8fe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_903:
	/* 0x903: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_906:
	/* 0x906: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_908:
	/* 0x908: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90b:
	/* 0x90b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_90f:
	/* 0x90f: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_913:
	/* 0x913: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_917:
	/* 0x917: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_91a:
	/* 0x91a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_91f:
	/* 0x91f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_924:
	/* 0x924: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_929:
	/* 0x929: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92b:
	/* 0x92b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92f:
	/* 0x92f: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_933:
	/* 0x933: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_936:
	/* 0x936: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_93b:
	/* 0x93b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_940:
	/* 0x940: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_945:
	/* 0x945: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_947:
	/* 0x947: cmp    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_94b:
	/* 0x94b: jne    9a9 <trace_ret_do_init_module+0x9a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9a9;
	}
x86_l_94d:
	/* 0x94d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_950:
	/* 0x950: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_955:
	/* 0x955: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_95a:
	/* 0x95a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_95f:
	/* 0x95f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_962:
	/* 0x962: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_964:
	/* 0x964: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_968:
	/* 0x968: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_96b:
	/* 0x96b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_970:
	/* 0x970: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_975:
	/* 0x975: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_97a:
	/* 0x97a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_97d:
	/* 0x97d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97f:
	/* 0x97f: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_982:
	/* 0x982: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_986:
	/* 0x986: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_98a:
	/* 0x98a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_98e:
	/* 0x98e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_991:
	/* 0x991: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_996:
	/* 0x996: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_99b:
	/* 0x99b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9a0:
	/* 0x9a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a2:
	/* 0x9a2: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9a5:
	/* 0x9a5: mov    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9a9:
	/* 0x9a9: mov    DWORD PTR [r15+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ad:
	/* 0x9ad: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9b2:
	/* 0x9b2: lea    r13,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9b9:
	/* 0x9b9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9bc:
	/* 0x9bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9c1:
	/* 0x9c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9c6:
	/* 0x9c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9cb:
	/* 0x9cb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_9ce:
	/* 0x9ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d0:
	/* 0x9d0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d4:
	/* 0x9d4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9d8:
	/* 0x9d8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9db:
	/* 0x9db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9e0:
	/* 0x9e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9e5:
	/* 0x9e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ea:
	/* 0x9ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ec:
	/* 0x9ec: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f0:
	/* 0x9f0: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9f5:
	/* 0x9f5: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_9fa:
	/* 0x9fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9ff:
	/* 0x9ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a03:
	/* 0xa03: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a08:
	/* 0xa08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0a:
	/* 0xa0a: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a0e:
	/* 0xa0e: mov    DWORD PTR [r15+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a12:
	/* 0xa12: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_a17:
	/* 0xa17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a19:
	/* 0xa19: mov    DWORD PTR [r15+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a1d:
	/* 0xa1d: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a21:
	/* 0xa21: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a24:
	/* 0xa24: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a29:
	/* 0xa29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a2e:
	/* 0xa2e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a33:
	/* 0xa33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a35:
	/* 0xa35: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a39:
	/* 0xa39: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a3c:
	/* 0xa3c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a41:
	/* 0xa41: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a45:
	/* 0xa45: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a48:
	/* 0xa48: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a4d:
	/* 0xa4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a52:
	/* 0xa52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a57:
	/* 0xa57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a59:
	/* 0xa59: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5d:
	/* 0xa5d: mov    QWORD PTR [r15+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a61:
	/* 0xa61: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a65:
	/* 0xa65: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a68:
	/* 0xa68: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a6d:
	/* 0xa6d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a72:
	/* 0xa72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a77:
	/* 0xa77: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a7a:
	/* 0xa7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7c:
	/* 0xa7c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a80:
	/* 0xa80: mov    QWORD PTR [r15+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a84:
	/* 0xa84: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a87:
	/* 0xa87: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a8c:
	/* 0xa8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a91:
	/* 0xa91: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a96:
	/* 0xa96: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a99:
	/* 0xa99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9b:
	/* 0xa9b: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_a9f:
	/* 0xa9f: je     aa6 <trace_ret_do_init_module+0xaa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aa6;
	}
x86_l_aa1:
	/* 0xaa1: or     BYTE PTR [r15+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_aa6:
	/* 0xaa6: mov    QWORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_aae:
	/* 0xaae: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ab2:
	/* 0xab2: mov    QWORD PTR [r15+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_aba:
	/* 0xaba: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_abf:
	/* 0xabf: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_ac4:
	/* 0xac4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ac9:
	/* 0xac9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_acb:
	/* 0xacb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ace:
	/* 0xace: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ad3:
	/* 0xad3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ad8:
	/* 0xad8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_add:
	/* 0xadd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ae0:
	/* 0xae0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae2:
	/* 0xae2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae6:
	/* 0xae6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ae9:
	/* 0xae9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_aee:
	/* 0xaee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_af3:
	/* 0xaf3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af8:
	/* 0xaf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_afa:
	/* 0xafa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_afe:
	/* 0xafe: mov    rbx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSP, X86_WIDTH_64);
x86_l_b01:
	/* 0xb01: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_b06:
	/* 0xb06: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b0b:
	/* 0xb0b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b0e:
	/* 0xb0e: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_b13:
	/* 0xb13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b15:
	/* 0xb15: add    r15,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_b19:
	/* 0xb19: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_b1e:
	/* 0xb1e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_b23:
	/* 0xb23: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_b26:
	/* 0xb26: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b2b:
	/* 0xb2b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b2e:
	/* 0xb2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b30:
	/* 0xb30: mov    r14,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b38:
	/* 0xb38: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_b3d:
	/* 0xb3d: je     34c <trace_ret_do_init_module+0x34c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 844ULL;
	}
x86_l_b43:
	/* 0xb43: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_b4b:
	/* 0xb4b: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_b50:
	/* 0xb50: add    rdx,QWORD PTR [rbx+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_b57:
	/* 0xb57: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b5c:
	/* 0xb5c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b61:
	/* 0xb61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b66:
	/* 0xb66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b6b:
	/* 0xb6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6d:
	/* 0xb6d: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b72:
	/* 0xb72: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b77:
	/* 0xb77: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b7c:
	/* 0xb7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b81:
	/* 0xb81: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b86:
	/* 0xb86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b8b:
	/* 0xb8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8d:
	/* 0xb8d: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b92:
	/* 0xb92: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b95:
	/* 0xb95: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b9a:
	/* 0xb9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b9f:
	/* 0xb9f: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ba4:
	/* 0xba4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ba9:
	/* 0xba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bab:
	/* 0xbab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_baf:
	/* 0xbaf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bb2:
	/* 0xbb2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bb7:
	/* 0xbb7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bbc:
	/* 0xbbc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bc1:
	/* 0xbc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc3:
	/* 0xbc3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc7:
	/* 0xbc7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_bca:
	/* 0xbca: je     bea <trace_ret_do_init_module+0xbea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bea;
	}
x86_l_bcc:
	/* 0xbcc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bd0:
	/* 0xbd0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bd3:
	/* 0xbd3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bd8:
	/* 0xbd8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bdd:
	/* 0xbdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_be2:
	/* 0xbe2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be4:
	/* 0xbe4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be8:
	/* 0xbe8: jmp    bec <trace_ret_do_init_module+0xbec> */
	goto x86_l_bec;
x86_l_bea:
	/* 0xbea: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bec:
	/* 0xbec: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf0:
	/* 0xbf0: mov    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bf8:
	/* 0xbf8: mov    QWORD PTR [r15+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bfc:
	/* 0xbfc: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c00:
	/* 0xc00: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_c07:
	/* 0xc07: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c0c:
	/* 0xc0c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c11:
	/* 0xc11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c13:
	/* 0xc13: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c16:
	/* 0xc16: je     c2e <trace_ret_do_init_module+0xc2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c2e;
	}
x86_l_c18:
	/* 0xc18: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c1b:
	/* 0xc1b: mov    BYTE PTR [r15+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_c22:
	/* 0xc22: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_c25:
	/* 0xc25: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c28:
	/* 0xc28: jne    c2e <trace_ret_do_init_module+0xc2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c2e;
	}
x86_l_c2a:
	/* 0xc2a: or     BYTE PTR [rbx+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_c2e:
	/* 0xc2e: movzx  eax,WORD PTR [rbx+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c32:
	/* 0xc32: cmp    ax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_c37:
	/* 0xc37: jne    252b <trace_ret_do_init_module+0x252b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9515ULL;
	}
x86_l_c3d:
	/* 0xc3d: mov    QWORD PTR [rbx+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_c48:
	/* 0xc48: mov    DWORD PTR [rsp],0x310 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 784ULL);
x86_l_c4f:
	/* 0xc4f: mov    WORD PTR [rsp+0x68],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c54:
	/* 0xc54: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_c5b:
	/* 0xc5b: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c60:
	/* 0xc60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c65:
	/* 0xc65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c67:
	/* 0xc67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c6a:
	/* 0xc6a: je     cd5 <trace_ret_do_init_module+0xcd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd5;
	}
x86_l_c6c:
	/* 0xc6c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c6f:
	/* 0xc6f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c72:
	/* 0xc72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c77:
	/* 0xc77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c79:
	/* 0xc79: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c7c:
	/* 0xc7c: je     cd5 <trace_ret_do_init_module+0xcd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd5;
	}
x86_l_c7e:
	/* 0xc7e: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c82:
	/* 0xc82: mov    QWORD PTR [rbx+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_c89:
	/* 0xc89: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8c:
	/* 0xc8c: mov    QWORD PTR [rbx+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c93:
	/* 0xc93: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c97:
	/* 0xc97: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c9b:
	/* 0xc9b: mov    QWORD PTR [rbx+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_ca2:
	/* 0xca2: mov    QWORD PTR [rbx+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_ca9:
	/* 0xca9: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cad:
	/* 0xcad: mov    QWORD PTR [rbx+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_cb4:
	/* 0xcb4: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cb8:
	/* 0xcb8: mov    QWORD PTR [rbx+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_cbf:
	/* 0xcbf: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cc3:
	/* 0xcc3: mov    QWORD PTR [rbx+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_cca:
	/* 0xcca: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cce:
	/* 0xcce: mov    QWORD PTR [rbx+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_cd5:
	/* 0xcd5: mov    rax,QWORD PTR [rbx+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_cdc:
	/* 0xcdc: mov    QWORD PTR [rbx+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ce3:
	/* 0xce3: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ceb:
	/* 0xceb: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_cf3:
	/* 0xcf3: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf5:
	/* 0xcf5: lea    rcx,[r15+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cf9:
	/* 0xcf9: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_d01:
	/* 0xd01: cmp    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_d05:
	/* 0xd05: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d0a:
	/* 0xd0a: jne    d28 <trace_ret_do_init_module+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d28;
	}
x86_l_d0c:
	/* 0xd0c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d0e:
	/* 0xd0e: and    QWORD PTR [r15+0x80],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_d15:
	/* 0xd15: mov    rbx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_d1d:
	/* 0xd1d: jne    14c1 <trace_ret_do_init_module+0x14c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5313ULL;
	}
x86_l_d23:
	/* 0xd23: jmp    14db <trace_ret_do_init_module+0x14db> */
	return 5339ULL;
x86_l_d28:
	/* 0xd28: mov    rax,QWORD PTR [r15+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_d2f:
	/* 0xd2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d32:
	/* 0xd32: je     edc <trace_ret_do_init_module+0xedc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_edc;
	}
x86_l_d38:
	/* 0xd38: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d40:
	/* 0xd40: movzx  ecx,BYTE PTR [rcx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_d47:
	/* 0xd47: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_d4a:
	/* 0xd4a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d4c:
	/* 0xd4c: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_d4f:
	/* 0xd4f: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_d53:
	/* 0xd53: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d56:
	/* 0xd56: neg    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d59:
	/* 0xd59: xor    rbp,QWORD PTR [r15+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_d60:
	/* 0xd60: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d63:
	/* 0xd63: mov    rax,QWORD PTR [r15+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d6a:
	/* 0xd6a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d6d:
	/* 0xd6d: je     d96 <trace_ret_do_init_module+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d96;
	}
x86_l_d6f:
	/* 0xd6f: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d77:
	/* 0xd77: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d79:
	/* 0xd79: cmp    BYTE PTR [rcx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_d80:
	/* 0xd80: sete   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_E);
x86_l_d83:
	/* 0xd83: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d86:
	/* 0xd86: neg    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d89:
	/* 0xd89: xor    rdx,QWORD PTR [r15+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_d90:
	/* 0xd90: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d93:
	/* 0xd93: and    rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d96:
	/* 0xd96: mov    rax,QWORD PTR [r15+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_d9d:
	/* 0xd9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_da0:
	/* 0xda0: je     dbc <trace_ret_do_init_module+0xdbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dbc;
	}
x86_l_da2:
	/* 0xda2: mov    ecx,DWORD PTR [r15+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_da6:
	/* 0xda6: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_da9:
	/* 0xda9: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_dac:
	/* 0xdac: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_daf:
	/* 0xdaf: xor    rcx,QWORD PTR [r15+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_db6:
	/* 0xdb6: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_db9:
	/* 0xdb9: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dbc:
	/* 0xdbc: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_dc4:
	/* 0xdc4: mov    rax,QWORD PTR [r15+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_dcb:
	/* 0xdcb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dce:
	/* 0xdce: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_dd6:
	/* 0xdd6: je     def <trace_ret_do_init_module+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_def;
	}
x86_l_dd8:
	/* 0xdd8: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ddb:
	/* 0xddb: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ddf:
	/* 0xddf: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_de2:
	/* 0xde2: xor    rcx,QWORD PTR [r15+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_de9:
	/* 0xde9: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dec:
	/* 0xdec: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_def:
	/* 0xdef: movzx  r13d,WORD PTR [r15+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_df4:
	/* 0xdf4: mov    rbx,QWORD PTR [r15+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_dfb:
	/* 0xdfb: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_dfe:
	/* 0xdfe: mov    WORD PTR [rsp+0x50],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e04:
	/* 0xe04: je     f42 <trace_ret_do_init_module+0xf42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3906ULL;
	}
x86_l_e0a:
	/* 0xe0a: mov    rax,QWORD PTR [r15+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_e11:
	/* 0xe11: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e16:
	/* 0xe16: mov    rax,QWORD PTR [r15+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_e1d:
	/* 0xe1d: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e22:
	/* 0xe22: mov    rax,QWORD PTR [r15+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_e29:
	/* 0xe29: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e2e:
	/* 0xe2e: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e33:
	/* 0xe33: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_e3a:
	/* 0xe3a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e3d:
	/* 0xe3d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e42:
	/* 0xe42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e44:
	/* 0xe44: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_e47:
	/* 0xe47: mov    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e4b:
	/* 0xe4b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e4f:
	/* 0xe4f: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e56:
	/* 0xe56: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_e59:
	/* 0xe59: je     e79 <trace_ret_do_init_module+0xe79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e79;
	}
x86_l_e5b:
	/* 0xe5b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e5e:
	/* 0xe5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e63:
	/* 0xe63: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_e66:
	/* 0xe66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e68:
	/* 0xe68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e6b:
	/* 0xe6b: je     e79 <trace_ret_do_init_module+0xe79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e79;
	}
x86_l_e6d:
	/* 0xe6d: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e70:
	/* 0xe70: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e74:
	/* 0xe74: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e77:
	/* 0xe77: jmp    e7c <trace_ret_do_init_module+0xe7c> */
	goto x86_l_e7c;
x86_l_e79:
	/* 0xe79: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7c:
	/* 0xe7c: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e81:
	/* 0xe81: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e86:
	/* 0xe86: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e8a:
	/* 0xe8a: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e8d:
	/* 0xe8d: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e90:
	/* 0xe90: jb     ea5 <trace_ret_do_init_module+0xea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ea5;
	}
x86_l_e92:
	/* 0xe92: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e96:
	/* 0xe96: je     e9d <trace_ret_do_init_module+0xe9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e9d;
	}
x86_l_e98:
	/* 0xe98: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e9b:
	/* 0xe9b: jbe    ea5 <trace_ret_do_init_module+0xea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ea5;
	}
x86_l_e9d:
	/* 0xe9d: and    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 112ULL);
x86_l_ea2:
	/* 0xea2: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_ea5:
	/* 0xea5: mov    eax,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ea9:
	/* 0xea9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ead:
	/* 0xead: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_eb4:
	/* 0xeb4: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_eb7:
	/* 0xeb7: je     ef8 <trace_ret_do_init_module+0xef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3832ULL;
	}
x86_l_eb9:
	/* 0xeb9: mov    QWORD PTR [rsp+0x60],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ebe:
	/* 0xebe: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ec1:
	/* 0xec1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ec6:
	/* 0xec6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ec9:
	/* 0xec9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ecb:
	/* 0xecb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ece:
	/* 0xece: je     f08 <trace_ret_do_init_module+0xf08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3848ULL;
	}
x86_l_ed0:
	/* 0xed0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ed3:
	/* 0xed3: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed7:
	/* 0xed7: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_eda:
	/* 0xeda: jmp    f0a <trace_ret_do_init_module+0xf0a> */
	return 3850ULL;
x86_l_edc:
	/* 0xedc: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ee3:
	/* 0xee3: mov    rax,QWORD PTR [r15+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_eea:
	/* 0xeea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 3821ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3821ULL: goto x86_l_eed;
	case 3827ULL: goto x86_l_ef3;
	case 3832ULL: goto x86_l_ef8;
	case 3834ULL: goto x86_l_efa;
	case 3837ULL: goto x86_l_efd;
	case 3841ULL: goto x86_l_f01;
	case 3844ULL: goto x86_l_f04;
	case 3846ULL: goto x86_l_f06;
	case 3848ULL: goto x86_l_f08;
	case 3850ULL: goto x86_l_f0a;
	case 3855ULL: goto x86_l_f0f;
	case 3860ULL: goto x86_l_f14;
	case 3863ULL: goto x86_l_f17;
	case 3867ULL: goto x86_l_f1b;
	case 3870ULL: goto x86_l_f1e;
	case 3872ULL: goto x86_l_f20;
	case 3876ULL: goto x86_l_f24;
	case 3878ULL: goto x86_l_f26;
	case 3881ULL: goto x86_l_f29;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3891ULL: goto x86_l_f33;
	case 3894ULL: goto x86_l_f36;
	case 3897ULL: goto x86_l_f39;
	case 3900ULL: goto x86_l_f3c;
	case 3906ULL: goto x86_l_f42;
	case 3914ULL: goto x86_l_f4a;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3927ULL: goto x86_l_f57;
	case 3931ULL: goto x86_l_f5b;
	case 3938ULL: goto x86_l_f62;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3953ULL: goto x86_l_f71;
	case 3960ULL: goto x86_l_f78;
	case 3967ULL: goto x86_l_f7f;
	case 3971ULL: goto x86_l_f83;
	case 3978ULL: goto x86_l_f8a;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3988ULL: goto x86_l_f94;
	case 3991ULL: goto x86_l_f97;
	case 3995ULL: goto x86_l_f9b;
	case 3999ULL: goto x86_l_f9f;
	case 4006ULL: goto x86_l_fa6;
	case 4009ULL: goto x86_l_fa9;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4019ULL: goto x86_l_fb3;
	case 4021ULL: goto x86_l_fb5;
	case 4024ULL: goto x86_l_fb8;
	case 4026ULL: goto x86_l_fba;
	case 4029ULL: goto x86_l_fbd;
	case 4033ULL: goto x86_l_fc1;
	case 4036ULL: goto x86_l_fc4;
	case 4038ULL: goto x86_l_fc6;
	case 4040ULL: goto x86_l_fc8;
	case 4043ULL: goto x86_l_fcb;
	case 4047ULL: goto x86_l_fcf;
	case 4050ULL: goto x86_l_fd2;
	case 4053ULL: goto x86_l_fd5;
	case 4055ULL: goto x86_l_fd7;
	case 4061ULL: goto x86_l_fdd;
	case 4063ULL: goto x86_l_fdf;
	case 4067ULL: goto x86_l_fe3;
	case 4073ULL: goto x86_l_fe9;
	case 4075ULL: goto x86_l_feb;
	case 4078ULL: goto x86_l_fee;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4091ULL: goto x86_l_ffb;
	case 4094ULL: goto x86_l_ffe;
	case 4102ULL: goto x86_l_1006;
	case 4108ULL: goto x86_l_100c;
	case 4113ULL: goto x86_l_1011;
	case 4120ULL: goto x86_l_1018;
	case 4123ULL: goto x86_l_101b;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4138ULL: goto x86_l_102a;
	case 4140ULL: goto x86_l_102c;
	case 4144ULL: goto x86_l_1030;
	case 4148ULL: goto x86_l_1034;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4168ULL: goto x86_l_1048;
	case 4172ULL: goto x86_l_104c;
	case 4177ULL: goto x86_l_1051;
	case 4182ULL: goto x86_l_1056;
	case 4187ULL: goto x86_l_105b;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4198ULL: goto x86_l_1066;
	case 4202ULL: goto x86_l_106a;
	case 4206ULL: goto x86_l_106e;
	case 4213ULL: goto x86_l_1075;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4232ULL: goto x86_l_1088;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4243ULL: goto x86_l_1093;
	case 4245ULL: goto x86_l_1095;
	case 4252ULL: goto x86_l_109c;
	case 4255ULL: goto x86_l_109f;
	case 4257ULL: goto x86_l_10a1;
	case 4260ULL: goto x86_l_10a4;
	case 4264ULL: goto x86_l_10a8;
	case 4269ULL: goto x86_l_10ad;
	case 4271ULL: goto x86_l_10af;
	case 4274ULL: goto x86_l_10b2;
	case 4276ULL: goto x86_l_10b4;
	case 4279ULL: goto x86_l_10b7;
	case 4283ULL: goto x86_l_10bb;
	case 4286ULL: goto x86_l_10be;
	case 4288ULL: goto x86_l_10c0;
	case 4290ULL: goto x86_l_10c2;
	case 4293ULL: goto x86_l_10c5;
	case 4296ULL: goto x86_l_10c8;
	case 4299ULL: goto x86_l_10cb;
	case 4302ULL: goto x86_l_10ce;
	case 4310ULL: goto x86_l_10d6;
	case 4316ULL: goto x86_l_10dc;
	case 4323ULL: goto x86_l_10e3;
	case 4327ULL: goto x86_l_10e7;
	case 4330ULL: goto x86_l_10ea;
	case 4335ULL: goto x86_l_10ef;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4347ULL: goto x86_l_10fb;
	case 4351ULL: goto x86_l_10ff;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4369ULL: goto x86_l_1111;
	case 4372ULL: goto x86_l_1114;
	case 4374ULL: goto x86_l_1116;
	case 4377ULL: goto x86_l_1119;
	case 4381ULL: goto x86_l_111d;
	case 4385ULL: goto x86_l_1121;
	case 4389ULL: goto x86_l_1125;
	case 4392ULL: goto x86_l_1128;
	case 4397ULL: goto x86_l_112d;
	case 4402ULL: goto x86_l_1132;
	case 4407ULL: goto x86_l_1137;
	case 4409ULL: goto x86_l_1139;
	case 4413ULL: goto x86_l_113d;
	case 4417ULL: goto x86_l_1141;
	case 4420ULL: goto x86_l_1144;
	case 4425ULL: goto x86_l_1149;
	case 4430ULL: goto x86_l_114e;
	case 4435ULL: goto x86_l_1153;
	case 4437ULL: goto x86_l_1155;
	case 4440ULL: goto x86_l_1158;
	case 4444ULL: goto x86_l_115c;
	case 4451ULL: goto x86_l_1163;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4470ULL: goto x86_l_1176;
	case 4473ULL: goto x86_l_1179;
	case 4478ULL: goto x86_l_117e;
	case 4481ULL: goto x86_l_1181;
	case 4483ULL: goto x86_l_1183;
	case 4490ULL: goto x86_l_118a;
	case 4493ULL: goto x86_l_118d;
	case 4495ULL: goto x86_l_118f;
	case 4498ULL: goto x86_l_1192;
	case 4502ULL: goto x86_l_1196;
	case 4507ULL: goto x86_l_119b;
	case 4509ULL: goto x86_l_119d;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4517ULL: goto x86_l_11a5;
	case 4521ULL: goto x86_l_11a9;
	case 4524ULL: goto x86_l_11ac;
	case 4526ULL: goto x86_l_11ae;
	case 4528ULL: goto x86_l_11b0;
	case 4531ULL: goto x86_l_11b3;
	case 4534ULL: goto x86_l_11b6;
	case 4537ULL: goto x86_l_11b9;
	case 4540ULL: goto x86_l_11bc;
	case 4548ULL: goto x86_l_11c4;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4566ULL: goto x86_l_11d6;
	case 4569ULL: goto x86_l_11d9;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4586ULL: goto x86_l_11ea;
	case 4590ULL: goto x86_l_11ee;
	case 4593ULL: goto x86_l_11f1;
	case 4598ULL: goto x86_l_11f6;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4610ULL: goto x86_l_1202;
	case 4614ULL: goto x86_l_1206;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4627ULL: goto x86_l_1213;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4637ULL: goto x86_l_121d;
	case 4641ULL: goto x86_l_1221;
	case 4646ULL: goto x86_l_1226;
	case 4651ULL: goto x86_l_122b;
	case 4654ULL: goto x86_l_122e;
	case 4659ULL: goto x86_l_1233;
	case 4662ULL: goto x86_l_1236;
	case 4664ULL: goto x86_l_1238;
	case 4671ULL: goto x86_l_123f;
	case 4678ULL: goto x86_l_1246;
	case 4683ULL: goto x86_l_124b;
	case 4690ULL: goto x86_l_1252;
	case 4693ULL: goto x86_l_1255;
	case 4698ULL: goto x86_l_125a;
	case 4701ULL: goto x86_l_125d;
	case 4703ULL: goto x86_l_125f;
	case 4710ULL: goto x86_l_1266;
	case 4713ULL: goto x86_l_1269;
	case 4715ULL: goto x86_l_126b;
	case 4718ULL: goto x86_l_126e;
	case 4723ULL: goto x86_l_1273;
	case 4726ULL: goto x86_l_1276;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4733ULL: goto x86_l_127d;
	case 4736ULL: goto x86_l_1280;
	case 4740ULL: goto x86_l_1284;
	case 4743ULL: goto x86_l_1287;
	case 4745ULL: goto x86_l_1289;
	case 4747ULL: goto x86_l_128b;
	case 4750ULL: goto x86_l_128e;
	case 4753ULL: goto x86_l_1291;
	case 4756ULL: goto x86_l_1294;
	case 4759ULL: goto x86_l_1297;
	case 4765ULL: goto x86_l_129d;
	case 4773ULL: goto x86_l_12a5;
	case 4779ULL: goto x86_l_12ab;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4793ULL: goto x86_l_12b9;
	case 4796ULL: goto x86_l_12bc;
	case 4801ULL: goto x86_l_12c1;
	case 4803ULL: goto x86_l_12c3;
	case 4810ULL: goto x86_l_12ca;
	case 4817ULL: goto x86_l_12d1;
	case 4822ULL: goto x86_l_12d6;
	case 4829ULL: goto x86_l_12dd;
	case 4832ULL: goto x86_l_12e0;
	case 4837ULL: goto x86_l_12e5;
	case 4840ULL: goto x86_l_12e8;
	case 4842ULL: goto x86_l_12ea;
	case 4849ULL: goto x86_l_12f1;
	case 4852ULL: goto x86_l_12f4;
	case 4854ULL: goto x86_l_12f6;
	case 4857ULL: goto x86_l_12f9;
	case 4862ULL: goto x86_l_12fe;
	case 4865ULL: goto x86_l_1301;
	case 4867ULL: goto x86_l_1303;
	case 4870ULL: goto x86_l_1306;
	case 4872ULL: goto x86_l_1308;
	case 4875ULL: goto x86_l_130b;
	case 4879ULL: goto x86_l_130f;
	case 4882ULL: goto x86_l_1312;
	case 4884ULL: goto x86_l_1314;
	case 4886ULL: goto x86_l_1316;
	case 4889ULL: goto x86_l_1319;
	case 4892ULL: goto x86_l_131c;
	case 4895ULL: goto x86_l_131f;
	case 4898ULL: goto x86_l_1322;
	case 4904ULL: goto x86_l_1328;
	case 4911ULL: goto x86_l_132f;
	case 4914ULL: goto x86_l_1332;
	case 4916ULL: goto x86_l_1334;
	case 4920ULL: goto x86_l_1338;
	case 4923ULL: goto x86_l_133b;
	case 4930ULL: goto x86_l_1342;
	case 4936ULL: goto x86_l_1348;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4956ULL: goto x86_l_135c;
	case 4958ULL: goto x86_l_135e;
	case 4965ULL: goto x86_l_1365;
	case 4968ULL: goto x86_l_1368;
	case 4970ULL: goto x86_l_136a;
	case 4973ULL: goto x86_l_136d;
	case 4976ULL: goto x86_l_1370;
	case 4981ULL: goto x86_l_1375;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4988ULL: goto x86_l_137c;
	case 4991ULL: goto x86_l_137f;
	case 4995ULL: goto x86_l_1383;
	case 4998ULL: goto x86_l_1386;
	case 5000ULL: goto x86_l_1388;
	case 5002ULL: goto x86_l_138a;
	case 5005ULL: goto x86_l_138d;
	case 5008ULL: goto x86_l_1390;
	case 5011ULL: goto x86_l_1393;
	case 5014ULL: goto x86_l_1396;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5026ULL: goto x86_l_13a2;
	case 5033ULL: goto x86_l_13a9;
	case 5038ULL: goto x86_l_13ae;
	case 5045ULL: goto x86_l_13b5;
	case 5048ULL: goto x86_l_13b8;
	case 5053ULL: goto x86_l_13bd;
	case 5056ULL: goto x86_l_13c0;
	case 5058ULL: goto x86_l_13c2;
	case 5065ULL: goto x86_l_13c9;
	case 5068ULL: goto x86_l_13cc;
	case 5070ULL: goto x86_l_13ce;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5086ULL: goto x86_l_13de;
	case 5088ULL: goto x86_l_13e0;
	case 5091ULL: goto x86_l_13e3;
	case 5093ULL: goto x86_l_13e5;
	case 5096ULL: goto x86_l_13e8;
	case 5100ULL: goto x86_l_13ec;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5107ULL: goto x86_l_13f3;
	case 5110ULL: goto x86_l_13f6;
	case 5113ULL: goto x86_l_13f9;
	case 5116ULL: goto x86_l_13fc;
	case 5119ULL: goto x86_l_13ff;
	case 5126ULL: goto x86_l_1406;
	case 5129ULL: goto x86_l_1409;
	case 5135ULL: goto x86_l_140f;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5154ULL: goto x86_l_1422;
	case 5157ULL: goto x86_l_1425;
	case 5162ULL: goto x86_l_142a;
	case 5165ULL: goto x86_l_142d;
	case 5167ULL: goto x86_l_142f;
	case 5174ULL: goto x86_l_1436;
	case 5177ULL: goto x86_l_1439;
	case 5179ULL: goto x86_l_143b;
	case 5182ULL: goto x86_l_143e;
	case 5190ULL: goto x86_l_1446;
	case 5194ULL: goto x86_l_144a;
	case 5199ULL: goto x86_l_144f;
	case 5202ULL: goto x86_l_1452;
	case 5204ULL: goto x86_l_1454;
	case 5207ULL: goto x86_l_1457;
	case 5209ULL: goto x86_l_1459;
	case 5217ULL: goto x86_l_1461;
	case 5221ULL: goto x86_l_1465;
	case 5226ULL: goto x86_l_146a;
	case 5229ULL: goto x86_l_146d;
	case 5231ULL: goto x86_l_146f;
	case 5234ULL: goto x86_l_1472;
	case 5236ULL: goto x86_l_1474;
	case 5239ULL: goto x86_l_1477;
	case 5243ULL: goto x86_l_147b;
	case 5246ULL: goto x86_l_147e;
	case 5248ULL: goto x86_l_1480;
	case 5250ULL: goto x86_l_1482;
	case 5253ULL: goto x86_l_1485;
	case 5256ULL: goto x86_l_1488;
	case 5259ULL: goto x86_l_148b;
	case 5262ULL: goto x86_l_148e;
	case 5270ULL: goto x86_l_1496;
	case 5277ULL: goto x86_l_149d;
	case 5280ULL: goto x86_l_14a0;
	case 5282ULL: goto x86_l_14a2;
	case 5286ULL: goto x86_l_14a6;
	case 5289ULL: goto x86_l_14a9;
	case 5296ULL: goto x86_l_14b0;
	case 5303ULL: goto x86_l_14b7;
	case 5311ULL: goto x86_l_14bf;
	case 5313ULL: goto x86_l_14c1;
	case 5320ULL: goto x86_l_14c8;
	case 5323ULL: goto x86_l_14cb;
	case 5331ULL: goto x86_l_14d3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_eed:
	/* 0xeed: jne    d6f <trace_ret_do_init_module+0xd6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3439ULL;
	}
x86_l_ef3:
	/* 0xef3: jmp    d96 <trace_ret_do_init_module+0xd96> */
	return 3478ULL;
x86_l_ef8:
	/* 0xef8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_efa:
	/* 0xefa: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_efd:
	/* 0xefd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f01:
	/* 0xf01: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f04:
	/* 0xf04: jae    f20 <trace_ret_do_init_module+0xf20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f20;
	}
x86_l_f06:
	/* 0xf06: jmp    f33 <trace_ret_do_init_module+0xf33> */
	goto x86_l_f33;
x86_l_f08:
	/* 0xf08: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f0a:
	/* 0xf0a: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f0f:
	/* 0xf0f: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f14:
	/* 0xf14: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f17:
	/* 0xf17: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1b:
	/* 0xf1b: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f1e:
	/* 0xf1e: jb     f33 <trace_ret_do_init_module+0xf33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f33;
	}
x86_l_f20:
	/* 0xf20: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f24:
	/* 0xf24: je     f2b <trace_ret_do_init_module+0xf2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f2b;
	}
x86_l_f26:
	/* 0xf26: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f29:
	/* 0xf29: jbe    f33 <trace_ret_do_init_module+0xf33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f33;
	}
x86_l_f2b:
	/* 0xf2b: and    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 112ULL);
x86_l_f30:
	/* 0xf30: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_f33:
	/* 0xf33: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f36:
	/* 0xf36: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f39:
	/* 0xf39: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_f3c:
	/* 0xf3c: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_f42:
	/* 0xf42: cmp    QWORD PTR [r15+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_f4a:
	/* 0xf4a: je     ffe <trace_ret_do_init_module+0xffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ffe;
	}
x86_l_f50:
	/* 0xf50: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_f55:
	/* 0xf55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f57:
	/* 0xf57: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f5b:
	/* 0xf5b: mov    rbx,QWORD PTR [r15+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_f62:
	/* 0xf62: mov    rax,QWORD PTR [r15+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_f69:
	/* 0xf69: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f6e:
	/* 0xf6e: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_f71:
	/* 0xf71: mov    r13,QWORD PTR [r15+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_f78:
	/* 0xf78: mov    r12,QWORD PTR [r15+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_f7f:
	/* 0xf7f: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f83:
	/* 0xf83: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_f8a:
	/* 0xf8a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f8d:
	/* 0xf8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f92:
	/* 0xf92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f94:
	/* 0xf94: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f97:
	/* 0xf97: mov    eax,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f9b:
	/* 0xf9b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9f:
	/* 0xf9f: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fa6:
	/* 0xfa6: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_fa9:
	/* 0xfa9: je     fc6 <trace_ret_do_init_module+0xfc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fc6;
	}
x86_l_fab:
	/* 0xfab: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fae:
	/* 0xfae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fb3:
	/* 0xfb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb5:
	/* 0xfb5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fb8:
	/* 0xfb8: je     fc6 <trace_ret_do_init_module+0xfc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fc6;
	}
x86_l_fba:
	/* 0xfba: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fbd:
	/* 0xfbd: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fc1:
	/* 0xfc1: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fc4:
	/* 0xfc4: jmp    fc8 <trace_ret_do_init_module+0xfc8> */
	goto x86_l_fc8;
x86_l_fc6:
	/* 0xfc6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fc8:
	/* 0xfc8: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fcb:
	/* 0xfcb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fcf:
	/* 0xfcf: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_fd2:
	/* 0xfd2: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_fd5:
	/* 0xfd5: jae    fdf <trace_ret_do_init_module+0xfdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_fdf;
	}
x86_l_fd7:
	/* 0xfd7: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_fdd:
	/* 0xfdd: jmp    ff8 <trace_ret_do_init_module+0xff8> */
	goto x86_l_ff8;
x86_l_fdf:
	/* 0xfdf: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fe3:
	/* 0xfe3: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_fe9:
	/* 0xfe9: je     ff0 <trace_ret_do_init_module+0xff0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ff0;
	}
x86_l_feb:
	/* 0xfeb: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_fee:
	/* 0xfee: jbe    ff8 <trace_ret_do_init_module+0xff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ff8;
	}
x86_l_ff0:
	/* 0xff0: and    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 96ULL);
x86_l_ff5:
	/* 0xff5: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_ff8:
	/* 0xff8: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ffb:
	/* 0xffb: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ffe:
	/* 0xffe: cmp    QWORD PTR [r15+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1006:
	/* 0x1006: je     10ce <trace_ret_do_init_module+0x10ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10ce;
	}
x86_l_100c:
	/* 0x100c: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1011:
	/* 0x1011: add    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1018:
	/* 0x1018: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_101b:
	/* 0x101b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1020:
	/* 0x1020: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1025:
	/* 0x1025: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_102a:
	/* 0x102a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102c:
	/* 0x102c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1030:
	/* 0x1030: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1034:
	/* 0x1034: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1037:
	/* 0x1037: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_103c:
	/* 0x103c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1041:
	/* 0x1041: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1046:
	/* 0x1046: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1048:
	/* 0x1048: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104c:
	/* 0x104c: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1051:
	/* 0x1051: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1056:
	/* 0x1056: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_105b:
	/* 0x105b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_105f:
	/* 0x105f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1064:
	/* 0x1064: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1066:
	/* 0x1066: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_106a:
	/* 0x106a: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_106e:
	/* 0x106e: mov    rbx,QWORD PTR [r15+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_1075:
	/* 0x1075: mov    r14,QWORD PTR [r15+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_107c:
	/* 0x107c: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1081:
	/* 0x1081: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_1088:
	/* 0x1088: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_108b:
	/* 0x108b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1090:
	/* 0x1090: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1093:
	/* 0x1093: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1095:
	/* 0x1095: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_109c:
	/* 0x109c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_109f:
	/* 0x109f: je     10c0 <trace_ret_do_init_module+0x10c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c0;
	}
x86_l_10a1:
	/* 0x10a1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10a4:
	/* 0x10a4: lea    rsi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10a8:
	/* 0x10a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10ad:
	/* 0x10ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10af:
	/* 0x10af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10b2:
	/* 0x10b2: je     10c0 <trace_ret_do_init_module+0x10c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c0;
	}
x86_l_10b4:
	/* 0x10b4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b7:
	/* 0x10b7: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10bb:
	/* 0x10bb: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10be:
	/* 0x10be: jmp    10c2 <trace_ret_do_init_module+0x10c2> */
	goto x86_l_10c2;
x86_l_10c0:
	/* 0x10c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c2:
	/* 0x10c2: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10c5:
	/* 0x10c5: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_10c8:
	/* 0x10c8: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10cb:
	/* 0x10cb: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_10ce:
	/* 0x10ce: cmp    QWORD PTR [r15+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_10d6:
	/* 0x10d6: je     11bc <trace_ret_do_init_module+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11bc;
	}
x86_l_10dc:
	/* 0x10dc: mov    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_10e3:
	/* 0x10e3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10e7:
	/* 0x10e7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10ea:
	/* 0x10ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10ef:
	/* 0x10ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10f4:
	/* 0x10f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10f9:
	/* 0x10f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fb:
	/* 0x10fb: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ff:
	/* 0x10ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1102:
	/* 0x1102: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1107:
	/* 0x1107: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_110c:
	/* 0x110c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1111:
	/* 0x1111: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1114:
	/* 0x1114: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1116:
	/* 0x1116: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1119:
	/* 0x1119: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_111d:
	/* 0x111d: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1121:
	/* 0x1121: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1125:
	/* 0x1125: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1128:
	/* 0x1128: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_112d:
	/* 0x112d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1132:
	/* 0x1132: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1137:
	/* 0x1137: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1139:
	/* 0x1139: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113d:
	/* 0x113d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1141:
	/* 0x1141: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1144:
	/* 0x1144: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1149:
	/* 0x1149: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_114e:
	/* 0x114e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1153:
	/* 0x1153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1155:
	/* 0x1155: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1158:
	/* 0x1158: mov    DWORD PTR [r15+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_115c:
	/* 0x115c: mov    rbx,QWORD PTR [r15+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1163:
	/* 0x1163: mov    r14,QWORD PTR [r15+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_116a:
	/* 0x116a: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116f:
	/* 0x116f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1176:
	/* 0x1176: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1179:
	/* 0x1179: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_117e:
	/* 0x117e: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1181:
	/* 0x1181: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1183:
	/* 0x1183: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_118a:
	/* 0x118a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_118d:
	/* 0x118d: je     11ae <trace_ret_do_init_module+0x11ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ae;
	}
x86_l_118f:
	/* 0x118f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1192:
	/* 0x1192: lea    rsi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1196:
	/* 0x1196: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_119b:
	/* 0x119b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119d:
	/* 0x119d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11a0:
	/* 0x11a0: je     11ae <trace_ret_do_init_module+0x11ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ae;
	}
x86_l_11a2:
	/* 0x11a2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a5:
	/* 0x11a5: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a9:
	/* 0x11a9: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11ac:
	/* 0x11ac: jmp    11b0 <trace_ret_do_init_module+0x11b0> */
	goto x86_l_11b0;
x86_l_11ae:
	/* 0x11ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11b0:
	/* 0x11b0: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11b3:
	/* 0x11b3: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_11b6:
	/* 0x11b6: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11b9:
	/* 0x11b9: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_11bc:
	/* 0x11bc: cmp    QWORD PTR [r15+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_11c4:
	/* 0x11c4: je     129d <trace_ret_do_init_module+0x129d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_129d;
	}
x86_l_11ca:
	/* 0x11ca: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_11cf:
	/* 0x11cf: add    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_11d6:
	/* 0x11d6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11d9:
	/* 0x11d9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11de:
	/* 0x11de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11e3:
	/* 0x11e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11e8:
	/* 0x11e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ea:
	/* 0x11ea: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ee:
	/* 0x11ee: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11f1:
	/* 0x11f1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11f6:
	/* 0x11f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11fb:
	/* 0x11fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1200:
	/* 0x1200: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1202:
	/* 0x1202: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1206:
	/* 0x1206: mov    r12,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSP, X86_WIDTH_64);
x86_l_1209:
	/* 0x1209: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_120e:
	/* 0x120e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1213:
	/* 0x1213: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1216:
	/* 0x1216: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_121b:
	/* 0x121b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121d:
	/* 0x121d: lea    rbx,[r15+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1221:
	/* 0x1221: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1226:
	/* 0x1226: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_122b:
	/* 0x122b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_122e:
	/* 0x122e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1233:
	/* 0x1233: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1236:
	/* 0x1236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1238:
	/* 0x1238: mov    r14,QWORD PTR [r15+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_123f:
	/* 0x123f: mov    r12,QWORD PTR [r15+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1246:
	/* 0x1246: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124b:
	/* 0x124b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1252:
	/* 0x1252: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1255:
	/* 0x1255: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_125a:
	/* 0x125a: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_125d:
	/* 0x125d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125f:
	/* 0x125f: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1266:
	/* 0x1266: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1269:
	/* 0x1269: je     1289 <trace_ret_do_init_module+0x1289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1289;
	}
x86_l_126b:
	/* 0x126b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_126e:
	/* 0x126e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1273:
	/* 0x1273: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1276:
	/* 0x1276: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1278:
	/* 0x1278: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_127b:
	/* 0x127b: je     1289 <trace_ret_do_init_module+0x1289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1289;
	}
x86_l_127d:
	/* 0x127d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1280:
	/* 0x1280: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1284:
	/* 0x1284: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1287:
	/* 0x1287: jmp    128b <trace_ret_do_init_module+0x128b> */
	goto x86_l_128b;
x86_l_1289:
	/* 0x1289: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_128b:
	/* 0x128b: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_128e:
	/* 0x128e: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1291:
	/* 0x1291: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1294:
	/* 0x1294: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1297:
	/* 0x1297: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_129d:
	/* 0x129d: cmp    QWORD PTR [r15+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_12a5:
	/* 0x12a5: je     1328 <trace_ret_do_init_module+0x1328> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1328;
	}
x86_l_12ab:
	/* 0x12ab: lea    rbx,[r15+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_12af:
	/* 0x12af: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_12b4:
	/* 0x12b4: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_12b9:
	/* 0x12b9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12bc:
	/* 0x12bc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12c1:
	/* 0x12c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c3:
	/* 0x12c3: mov    r14,QWORD PTR [r15+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_12ca:
	/* 0x12ca: mov    r12,QWORD PTR [r15+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_12d1:
	/* 0x12d1: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d6:
	/* 0x12d6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_12dd:
	/* 0x12dd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_12e0:
	/* 0x12e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e5:
	/* 0x12e5: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12e8:
	/* 0x12e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ea:
	/* 0x12ea: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12f1:
	/* 0x12f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12f4:
	/* 0x12f4: je     1314 <trace_ret_do_init_module+0x1314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1314;
	}
x86_l_12f6:
	/* 0x12f6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12f9:
	/* 0x12f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12fe:
	/* 0x12fe: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1301:
	/* 0x1301: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1303:
	/* 0x1303: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1306:
	/* 0x1306: je     1314 <trace_ret_do_init_module+0x1314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1314;
	}
x86_l_1308:
	/* 0x1308: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_130b:
	/* 0x130b: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130f:
	/* 0x130f: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1312:
	/* 0x1312: jmp    1316 <trace_ret_do_init_module+0x1316> */
	goto x86_l_1316;
x86_l_1314:
	/* 0x1314: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1316:
	/* 0x1316: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1319:
	/* 0x1319: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_131c:
	/* 0x131c: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_131f:
	/* 0x131f: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1322:
	/* 0x1322: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1328:
	/* 0x1328: mov    rbx,QWORD PTR [r15+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_132f:
	/* 0x132f: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1332:
	/* 0x1332: je     1396 <trace_ret_do_init_module+0x1396> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1396;
	}
x86_l_1334:
	/* 0x1334: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1338:
	/* 0x1338: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_133b:
	/* 0x133b: mov    r14,QWORD PTR [r15+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1342:
	/* 0x1342: mov    WORD PTR [rsp+0x48],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1348:
	/* 0x1348: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_134f:
	/* 0x134f: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1354:
	/* 0x1354: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1359:
	/* 0x1359: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_135c:
	/* 0x135c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135e:
	/* 0x135e: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1365:
	/* 0x1365: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1368:
	/* 0x1368: je     1388 <trace_ret_do_init_module+0x1388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1388;
	}
x86_l_136a:
	/* 0x136a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_136d:
	/* 0x136d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1370:
	/* 0x1370: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1375:
	/* 0x1375: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1377:
	/* 0x1377: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_137a:
	/* 0x137a: je     1388 <trace_ret_do_init_module+0x1388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1388;
	}
x86_l_137c:
	/* 0x137c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137f:
	/* 0x137f: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1383:
	/* 0x1383: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1386:
	/* 0x1386: jmp    138a <trace_ret_do_init_module+0x138a> */
	goto x86_l_138a;
x86_l_1388:
	/* 0x1388: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_138a:
	/* 0x138a: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_138d:
	/* 0x138d: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1390:
	/* 0x1390: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1393:
	/* 0x1393: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1396:
	/* 0x1396: mov    rbx,QWORD PTR [r15+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_139d:
	/* 0x139d: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_13a0:
	/* 0x13a0: je     13ff <trace_ret_do_init_module+0x13ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ff;
	}
x86_l_13a2:
	/* 0x13a2: mov    r14,QWORD PTR [r15+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_13a9:
	/* 0x13a9: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ae:
	/* 0x13ae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_13b5:
	/* 0x13b5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_13b8:
	/* 0x13b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13bd:
	/* 0x13bd: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13c0:
	/* 0x13c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c2:
	/* 0x13c2: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13c9:
	/* 0x13c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13cc:
	/* 0x13cc: je     13f1 <trace_ret_do_init_module+0x13f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f1;
	}
x86_l_13ce:
	/* 0x13ce: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13d1:
	/* 0x13d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d6:
	/* 0x13d6: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_13de:
	/* 0x13de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e0:
	/* 0x13e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13e3:
	/* 0x13e3: je     13f1 <trace_ret_do_init_module+0x13f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f1;
	}
x86_l_13e5:
	/* 0x13e5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e8:
	/* 0x13e8: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ec:
	/* 0x13ec: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13ef:
	/* 0x13ef: jmp    13f3 <trace_ret_do_init_module+0x13f3> */
	goto x86_l_13f3;
x86_l_13f1:
	/* 0x13f1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f3:
	/* 0x13f3: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13f6:
	/* 0x13f6: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_13f9:
	/* 0x13f9: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13fc:
	/* 0x13fc: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_13ff:
	/* 0x13ff: mov    r14,QWORD PTR [r15+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1406:
	/* 0x1406: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1409:
	/* 0x1409: je     148e <trace_ret_do_init_module+0x148e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148e;
	}
x86_l_140f:
	/* 0x140f: mov    r12,QWORD PTR [r15+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1416:
	/* 0x1416: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141b:
	/* 0x141b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1422:
	/* 0x1422: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1425:
	/* 0x1425: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_142a:
	/* 0x142a: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_142d:
	/* 0x142d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142f:
	/* 0x142f: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1436:
	/* 0x1436: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1439:
	/* 0x1439: je     1480 <trace_ret_do_init_module+0x1480> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1480;
	}
x86_l_143b:
	/* 0x143b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_143e:
	/* 0x143e: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1446:
	/* 0x1446: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_144a:
	/* 0x144a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_144f:
	/* 0x144f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1452:
	/* 0x1452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1454:
	/* 0x1454: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1457:
	/* 0x1457: jne    1474 <trace_ret_do_init_module+0x1474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1474;
	}
x86_l_1459:
	/* 0x1459: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1461:
	/* 0x1461: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1465:
	/* 0x1465: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_146a:
	/* 0x146a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_146d:
	/* 0x146d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146f:
	/* 0x146f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1472:
	/* 0x1472: je     1480 <trace_ret_do_init_module+0x1480> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1480;
	}
x86_l_1474:
	/* 0x1474: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1477:
	/* 0x1477: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_147b:
	/* 0x147b: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_147e:
	/* 0x147e: jmp    1482 <trace_ret_do_init_module+0x1482> */
	goto x86_l_1482;
x86_l_1480:
	/* 0x1480: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1482:
	/* 0x1482: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1485:
	/* 0x1485: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1488:
	/* 0x1488: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_148b:
	/* 0x148b: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_148e:
	/* 0x148e: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1496:
	/* 0x1496: mov    rax,QWORD PTR [r15+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_149d:
	/* 0x149d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a0:
	/* 0x14a0: je     14a9 <trace_ret_do_init_module+0x14a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a9;
	}
x86_l_14a2:
	/* 0x14a2: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_14a6:
	/* 0x14a6: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14a9:
	/* 0x14a9: and    rbp,QWORD PTR [r15+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_14b0:
	/* 0x14b0: and    QWORD PTR [r15+0x80],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_14b7:
	/* 0x14b7: mov    rbx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_14bf:
	/* 0x14bf: je     14db <trace_ret_do_init_module+0x14db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5339ULL;
	}
x86_l_14c1:
	/* 0x14c1: mov    DWORD PTR [rsp],0x40000000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1073741824ULL);
x86_l_14c8:
	/* 0x14c8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_14cb:
	/* 0x14cb: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_14d3:
	/* 0x14d3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
	return 5334ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5334ULL: goto x86_l_14d6;
	case 5339ULL: goto x86_l_14db;
	case 5343ULL: goto x86_l_14df;
	case 5346ULL: goto x86_l_14e2;
	case 5351ULL: goto x86_l_14e7;
	case 5356ULL: goto x86_l_14ec;
	case 5361ULL: goto x86_l_14f1;
	case 5363ULL: goto x86_l_14f3;
	case 5367ULL: goto x86_l_14f7;
	case 5371ULL: goto x86_l_14fb;
	case 5374ULL: goto x86_l_14fe;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5389ULL: goto x86_l_150d;
	case 5391ULL: goto x86_l_150f;
	case 5395ULL: goto x86_l_1513;
	case 5403ULL: goto x86_l_151b;
	case 5413ULL: goto x86_l_1525;
	case 5421ULL: goto x86_l_152d;
	case 5432ULL: goto x86_l_1538;
	case 5443ULL: goto x86_l_1543;
	case 5454ULL: goto x86_l_154e;
	case 5465ULL: goto x86_l_1559;
	case 5476ULL: goto x86_l_1564;
	case 5487ULL: goto x86_l_156f;
	case 5498ULL: goto x86_l_157a;
	case 5509ULL: goto x86_l_1585;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5544ULL: goto x86_l_15a8;
	case 5549ULL: goto x86_l_15ad;
	case 5554ULL: goto x86_l_15b2;
	case 5556ULL: goto x86_l_15b4;
	case 5559ULL: goto x86_l_15b7;
	case 5565ULL: goto x86_l_15bd;
	case 5568ULL: goto x86_l_15c0;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5578ULL: goto x86_l_15ca;
	case 5581ULL: goto x86_l_15cd;
	case 5587ULL: goto x86_l_15d3;
	case 5591ULL: goto x86_l_15d7;
	case 5598ULL: goto x86_l_15de;
	case 5601ULL: goto x86_l_15e1;
	case 5608ULL: goto x86_l_15e8;
	case 5615ULL: goto x86_l_15ef;
	case 5619ULL: goto x86_l_15f3;
	case 5626ULL: goto x86_l_15fa;
	case 5630ULL: goto x86_l_15fe;
	case 5637ULL: goto x86_l_1605;
	case 5641ULL: goto x86_l_1609;
	case 5648ULL: goto x86_l_1610;
	case 5652ULL: goto x86_l_1614;
	case 5659ULL: goto x86_l_161b;
	case 5663ULL: goto x86_l_161f;
	case 5667ULL: goto x86_l_1623;
	case 5674ULL: goto x86_l_162a;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5688ULL: goto x86_l_1638;
	case 5692ULL: goto x86_l_163c;
	case 5700ULL: goto x86_l_1644;
	case 5705ULL: goto x86_l_1649;
	case 5707ULL: goto x86_l_164b;
	case 5709ULL: goto x86_l_164d;
	case 5711ULL: goto x86_l_164f;
	case 5714ULL: goto x86_l_1652;
	case 5721ULL: goto x86_l_1659;
	case 5727ULL: goto x86_l_165f;
	case 5732ULL: goto x86_l_1664;
	case 5739ULL: goto x86_l_166b;
	case 5742ULL: goto x86_l_166e;
	case 5748ULL: goto x86_l_1674;
	case 5756ULL: goto x86_l_167c;
	case 5763ULL: goto x86_l_1683;
	case 5766ULL: goto x86_l_1686;
	case 5768ULL: goto x86_l_1688;
	case 5771ULL: goto x86_l_168b;
	case 5775ULL: goto x86_l_168f;
	case 5778ULL: goto x86_l_1692;
	case 5781ULL: goto x86_l_1695;
	case 5788ULL: goto x86_l_169c;
	case 5791ULL: goto x86_l_169f;
	case 5798ULL: goto x86_l_16a6;
	case 5801ULL: goto x86_l_16a9;
	case 5803ULL: goto x86_l_16ab;
	case 5811ULL: goto x86_l_16b3;
	case 5813ULL: goto x86_l_16b5;
	case 5820ULL: goto x86_l_16bc;
	case 5823ULL: goto x86_l_16bf;
	case 5826ULL: goto x86_l_16c2;
	case 5829ULL: goto x86_l_16c5;
	case 5836ULL: goto x86_l_16cc;
	case 5839ULL: goto x86_l_16cf;
	case 5842ULL: goto x86_l_16d2;
	case 5849ULL: goto x86_l_16d9;
	case 5852ULL: goto x86_l_16dc;
	case 5854ULL: goto x86_l_16de;
	case 5858ULL: goto x86_l_16e2;
	case 5861ULL: goto x86_l_16e5;
	case 5864ULL: goto x86_l_16e8;
	case 5867ULL: goto x86_l_16eb;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5888ULL: goto x86_l_1700;
	case 5895ULL: goto x86_l_1707;
	case 5898ULL: goto x86_l_170a;
	case 5903ULL: goto x86_l_170f;
	case 5905ULL: goto x86_l_1711;
	case 5908ULL: goto x86_l_1714;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5922ULL: goto x86_l_1722;
	case 5925ULL: goto x86_l_1725;
	case 5928ULL: goto x86_l_1728;
	case 5933ULL: goto x86_l_172d;
	case 5940ULL: goto x86_l_1734;
	case 5943ULL: goto x86_l_1737;
	case 5948ULL: goto x86_l_173c;
	case 5954ULL: goto x86_l_1742;
	case 5961ULL: goto x86_l_1749;
	case 5969ULL: goto x86_l_1751;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5997ULL: goto x86_l_176d;
	case 6004ULL: goto x86_l_1774;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6014ULL: goto x86_l_177e;
	case 6017ULL: goto x86_l_1781;
	case 6021ULL: goto x86_l_1785;
	case 6025ULL: goto x86_l_1789;
	case 6032ULL: goto x86_l_1790;
	case 6035ULL: goto x86_l_1793;
	case 6037ULL: goto x86_l_1795;
	case 6040ULL: goto x86_l_1798;
	case 6045ULL: goto x86_l_179d;
	case 6048ULL: goto x86_l_17a0;
	case 6050ULL: goto x86_l_17a2;
	case 6053ULL: goto x86_l_17a5;
	case 6055ULL: goto x86_l_17a7;
	case 6058ULL: goto x86_l_17aa;
	case 6062ULL: goto x86_l_17ae;
	case 6065ULL: goto x86_l_17b1;
	case 6067ULL: goto x86_l_17b3;
	case 6070ULL: goto x86_l_17b6;
	case 6075ULL: goto x86_l_17bb;
	case 6080ULL: goto x86_l_17c0;
	case 6084ULL: goto x86_l_17c4;
	case 6087ULL: goto x86_l_17c7;
	case 6090ULL: goto x86_l_17ca;
	case 6092ULL: goto x86_l_17cc;
	case 6096ULL: goto x86_l_17d0;
	case 6098ULL: goto x86_l_17d2;
	case 6101ULL: goto x86_l_17d5;
	case 6103ULL: goto x86_l_17d7;
	case 6111ULL: goto x86_l_17df;
	case 6114ULL: goto x86_l_17e2;
	case 6118ULL: goto x86_l_17e6;
	case 6122ULL: goto x86_l_17ea;
	case 6129ULL: goto x86_l_17f1;
	case 6132ULL: goto x86_l_17f4;
	case 6134ULL: goto x86_l_17f6;
	case 6139ULL: goto x86_l_17fb;
	case 6142ULL: goto x86_l_17fe;
	case 6147ULL: goto x86_l_1803;
	case 6150ULL: goto x86_l_1806;
	case 6152ULL: goto x86_l_1808;
	case 6155ULL: goto x86_l_180b;
	case 6157ULL: goto x86_l_180d;
	case 6160ULL: goto x86_l_1810;
	case 6164ULL: goto x86_l_1814;
	case 6167ULL: goto x86_l_1817;
	case 6169ULL: goto x86_l_1819;
	case 6176ULL: goto x86_l_1820;
	case 6183ULL: goto x86_l_1827;
	case 6186ULL: goto x86_l_182a;
	case 6192ULL: goto x86_l_1830;
	case 6197ULL: goto x86_l_1835;
	case 6199ULL: goto x86_l_1837;
	case 6201ULL: goto x86_l_1839;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6213ULL: goto x86_l_1845;
	case 6216ULL: goto x86_l_1848;
	case 6220ULL: goto x86_l_184c;
	case 6223ULL: goto x86_l_184f;
	case 6225ULL: goto x86_l_1851;
	case 6229ULL: goto x86_l_1855;
	case 6231ULL: goto x86_l_1857;
	case 6234ULL: goto x86_l_185a;
	case 6236ULL: goto x86_l_185c;
	case 6244ULL: goto x86_l_1864;
	case 6247ULL: goto x86_l_1867;
	case 6250ULL: goto x86_l_186a;
	case 6253ULL: goto x86_l_186d;
	case 6256ULL: goto x86_l_1870;
	case 6264ULL: goto x86_l_1878;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6277ULL: goto x86_l_1885;
	case 6281ULL: goto x86_l_1889;
	case 6288ULL: goto x86_l_1890;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6307ULL: goto x86_l_18a3;
	case 6314ULL: goto x86_l_18aa;
	case 6319ULL: goto x86_l_18af;
	case 6323ULL: goto x86_l_18b3;
	case 6330ULL: goto x86_l_18ba;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6340ULL: goto x86_l_18c4;
	case 6343ULL: goto x86_l_18c7;
	case 6347ULL: goto x86_l_18cb;
	case 6351ULL: goto x86_l_18cf;
	case 6358ULL: goto x86_l_18d6;
	case 6361ULL: goto x86_l_18d9;
	case 6363ULL: goto x86_l_18db;
	case 6366ULL: goto x86_l_18de;
	case 6371ULL: goto x86_l_18e3;
	case 6373ULL: goto x86_l_18e5;
	case 6376ULL: goto x86_l_18e8;
	case 6378ULL: goto x86_l_18ea;
	case 6381ULL: goto x86_l_18ed;
	case 6385ULL: goto x86_l_18f1;
	case 6388ULL: goto x86_l_18f4;
	case 6390ULL: goto x86_l_18f6;
	case 6392ULL: goto x86_l_18f8;
	case 6395ULL: goto x86_l_18fb;
	case 6399ULL: goto x86_l_18ff;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6407ULL: goto x86_l_1907;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6421ULL: goto x86_l_1915;
	case 6423ULL: goto x86_l_1917;
	case 6427ULL: goto x86_l_191b;
	case 6433ULL: goto x86_l_1921;
	case 6435ULL: goto x86_l_1923;
	case 6438ULL: goto x86_l_1926;
	case 6440ULL: goto x86_l_1928;
	case 6445ULL: goto x86_l_192d;
	case 6448ULL: goto x86_l_1930;
	case 6451ULL: goto x86_l_1933;
	case 6454ULL: goto x86_l_1936;
	case 6462ULL: goto x86_l_193e;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6480ULL: goto x86_l_1950;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6493ULL: goto x86_l_195d;
	case 6498ULL: goto x86_l_1962;
	case 6500ULL: goto x86_l_1964;
	case 6504ULL: goto x86_l_1968;
	case 6508ULL: goto x86_l_196c;
	case 6511ULL: goto x86_l_196f;
	case 6516ULL: goto x86_l_1974;
	case 6521ULL: goto x86_l_1979;
	case 6526ULL: goto x86_l_197e;
	case 6528ULL: goto x86_l_1980;
	case 6532ULL: goto x86_l_1984;
	case 6537ULL: goto x86_l_1989;
	case 6542ULL: goto x86_l_198e;
	case 6547ULL: goto x86_l_1993;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6558ULL: goto x86_l_199e;
	case 6562ULL: goto x86_l_19a2;
	case 6566ULL: goto x86_l_19a6;
	case 6573ULL: goto x86_l_19ad;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6592ULL: goto x86_l_19c0;
	case 6595ULL: goto x86_l_19c3;
	case 6600ULL: goto x86_l_19c8;
	case 6603ULL: goto x86_l_19cb;
	case 6605ULL: goto x86_l_19cd;
	case 6612ULL: goto x86_l_19d4;
	case 6615ULL: goto x86_l_19d7;
	case 6617ULL: goto x86_l_19d9;
	case 6620ULL: goto x86_l_19dc;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6631ULL: goto x86_l_19e7;
	case 6634ULL: goto x86_l_19ea;
	case 6636ULL: goto x86_l_19ec;
	case 6639ULL: goto x86_l_19ef;
	case 6643ULL: goto x86_l_19f3;
	case 6646ULL: goto x86_l_19f6;
	case 6648ULL: goto x86_l_19f8;
	case 6650ULL: goto x86_l_19fa;
	case 6653ULL: goto x86_l_19fd;
	case 6656ULL: goto x86_l_1a00;
	case 6659ULL: goto x86_l_1a03;
	case 6662ULL: goto x86_l_1a06;
	case 6670ULL: goto x86_l_1a0e;
	case 6676ULL: goto x86_l_1a14;
	case 6683ULL: goto x86_l_1a1b;
	case 6687ULL: goto x86_l_1a1f;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6700ULL: goto x86_l_1a2c;
	case 6705ULL: goto x86_l_1a31;
	case 6707ULL: goto x86_l_1a33;
	case 6711ULL: goto x86_l_1a37;
	case 6714ULL: goto x86_l_1a3a;
	case 6719ULL: goto x86_l_1a3f;
	case 6724ULL: goto x86_l_1a44;
	case 6729ULL: goto x86_l_1a49;
	case 6732ULL: goto x86_l_1a4c;
	case 6734ULL: goto x86_l_1a4e;
	case 6737ULL: goto x86_l_1a51;
	case 6741ULL: goto x86_l_1a55;
	case 6745ULL: goto x86_l_1a59;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6769ULL: goto x86_l_1a71;
	case 6773ULL: goto x86_l_1a75;
	case 6777ULL: goto x86_l_1a79;
	case 6780ULL: goto x86_l_1a7c;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6797ULL: goto x86_l_1a8d;
	case 6800ULL: goto x86_l_1a90;
	case 6804ULL: goto x86_l_1a94;
	case 6811ULL: goto x86_l_1a9b;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6830ULL: goto x86_l_1aae;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6841ULL: goto x86_l_1ab9;
	case 6843ULL: goto x86_l_1abb;
	case 6850ULL: goto x86_l_1ac2;
	case 6853ULL: goto x86_l_1ac5;
	case 6855ULL: goto x86_l_1ac7;
	case 6858ULL: goto x86_l_1aca;
	case 6862ULL: goto x86_l_1ace;
	case 6867ULL: goto x86_l_1ad3;
	case 6869ULL: goto x86_l_1ad5;
	case 6872ULL: goto x86_l_1ad8;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6886ULL: goto x86_l_1ae6;
	case 6888ULL: goto x86_l_1ae8;
	case 6891ULL: goto x86_l_1aeb;
	case 6894ULL: goto x86_l_1aee;
	case 6897ULL: goto x86_l_1af1;
	case 6900ULL: goto x86_l_1af4;
	case 6908ULL: goto x86_l_1afc;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6926ULL: goto x86_l_1b0e;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6946ULL: goto x86_l_1b22;
	case 6950ULL: goto x86_l_1b26;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6963ULL: goto x86_l_1b33;
	case 6968ULL: goto x86_l_1b38;
	case 6970ULL: goto x86_l_1b3a;
	case 6974ULL: goto x86_l_1b3e;
	case 6977ULL: goto x86_l_1b41;
	case 6982ULL: goto x86_l_1b46;
	case 6987ULL: goto x86_l_1b4b;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14d6:
	/* 0x14d6: call   0 <trace_ret_do_init_module> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 5339ULL);
	__x86_sim_call_depth++;
	return 9579ULL;
x86_l_14db:
	/* 0x14db: lea    rdx,[rbx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_14df:
	/* 0x14df: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14e2:
	/* 0x14e2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14e7:
	/* 0x14e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14ec:
	/* 0x14ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14f1:
	/* 0x14f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f3:
	/* 0x14f3: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f7:
	/* 0x14f7: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14fb:
	/* 0x14fb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14fe:
	/* 0x14fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1503:
	/* 0x1503: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1508:
	/* 0x1508: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_150d:
	/* 0x150d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150f:
	/* 0x150f: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1513:
	/* 0x1513: mov    DWORD PTR [r15+0x70],0x2fa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337914ULL);
x86_l_151b:
	/* 0x151b: mov    WORD PTR [r15+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_1525:
	/* 0x1525: mov    BYTE PTR [r15+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_152d:
	/* 0x152d: mov    QWORD PTR [r15+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_1538:
	/* 0x1538: mov    QWORD PTR [r15+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_1543:
	/* 0x1543: mov    QWORD PTR [r15+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_154e:
	/* 0x154e: mov    QWORD PTR [r15+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1559:
	/* 0x1559: mov    QWORD PTR [r15+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1564:
	/* 0x1564: mov    QWORD PTR [r15+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_156f:
	/* 0x156f: mov    QWORD PTR [r15+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_157a:
	/* 0x157a: mov    QWORD PTR [r15+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1585:
	/* 0x1585: mov    QWORD PTR [r15+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_1590:
	/* 0x1590: movzx  eax,WORD PTR [r15+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_1595:
	/* 0x1595: mov    DWORD PTR [rsp],0x2fa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 762ULL);
x86_l_159c:
	/* 0x159c: mov    WORD PTR [rsp+0x48],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15a1:
	/* 0x15a1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_15a8:
	/* 0x15a8: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15ad:
	/* 0x15ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15b2:
	/* 0x15b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b4:
	/* 0x15b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15b7:
	/* 0x15b7: je     255a <trace_ret_do_init_module+0x255a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9562ULL;
	}
x86_l_15bd:
	/* 0x15bd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_15c0:
	/* 0x15c0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_15c3:
	/* 0x15c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15c8:
	/* 0x15c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ca:
	/* 0x15ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15cd:
	/* 0x15cd: je     255a <trace_ret_do_init_module+0x255a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9562ULL;
	}
x86_l_15d3:
	/* 0x15d3: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d7:
	/* 0x15d7: mov    QWORD PTR [r15+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_15de:
	/* 0x15de: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e1:
	/* 0x15e1: mov    QWORD PTR [r15+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_15e8:
	/* 0x15e8: mov    QWORD PTR [r15+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_15ef:
	/* 0x15ef: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15f3:
	/* 0x15f3: mov    QWORD PTR [r15+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_15fa:
	/* 0x15fa: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15fe:
	/* 0x15fe: mov    QWORD PTR [r15+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_1605:
	/* 0x1605: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1609:
	/* 0x1609: mov    QWORD PTR [r15+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_1610:
	/* 0x1610: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1614:
	/* 0x1614: mov    QWORD PTR [r15+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_161b:
	/* 0x161b: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161f:
	/* 0x161f: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1623:
	/* 0x1623: mov    QWORD PTR [r15+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_162a:
	/* 0x162a: mov    QWORD PTR [r15+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_1631:
	/* 0x1631: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1636:
	/* 0x1636: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1638:
	/* 0x1638: cmp    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_163c:
	/* 0x163c: mov    QWORD PTR [rsp+0x80],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1644:
	/* 0x1644: mov    QWORD PTR [rsp+0x60],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1649:
	/* 0x1649: jne    1664 <trace_ret_do_init_module+0x1664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1664;
	}
x86_l_164b:
	/* 0x164b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_164d:
	/* 0x164d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_164f:
	/* 0x164f: and    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1652:
	/* 0x1652: mov    QWORD PTR [r15+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1659:
	/* 0x1659: jne    1df8 <trace_ret_do_init_module+0x1df8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7672ULL;
	}
x86_l_165f:
	/* 0x165f: jmp    255c <trace_ret_do_init_module+0x255c> */
	return 9564ULL;
x86_l_1664:
	/* 0x1664: mov    rax,QWORD PTR [r15+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_166b:
	/* 0x166b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_166e:
	/* 0x166e: je     1819 <trace_ret_do_init_module+0x1819> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1819;
	}
x86_l_1674:
	/* 0x1674: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_167c:
	/* 0x167c: movzx  ecx,BYTE PTR [rcx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_1683:
	/* 0x1683: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_1686:
	/* 0x1686: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1688:
	/* 0x1688: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_168b:
	/* 0x168b: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_168f:
	/* 0x168f: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1692:
	/* 0x1692: neg    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1695:
	/* 0x1695: xor    rbp,QWORD PTR [r15+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_169c:
	/* 0x169c: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_169f:
	/* 0x169f: mov    rax,QWORD PTR [r15+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_16a6:
	/* 0x16a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16a9:
	/* 0x16a9: je     16d2 <trace_ret_do_init_module+0x16d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16d2;
	}
x86_l_16ab:
	/* 0x16ab: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16b3:
	/* 0x16b3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b5:
	/* 0x16b5: cmp    BYTE PTR [rcx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_16bc:
	/* 0x16bc: sete   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_E);
x86_l_16bf:
	/* 0x16bf: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_16c2:
	/* 0x16c2: neg    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_16c5:
	/* 0x16c5: xor    rdx,QWORD PTR [r15+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_16cc:
	/* 0x16cc: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16cf:
	/* 0x16cf: and    rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_16d2:
	/* 0x16d2: mov    rax,QWORD PTR [r15+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_16d9:
	/* 0x16d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16dc:
	/* 0x16dc: je     16f8 <trace_ret_do_init_module+0x16f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16f8;
	}
x86_l_16de:
	/* 0x16de: mov    ecx,DWORD PTR [r15+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_16e2:
	/* 0x16e2: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_16e5:
	/* 0x16e5: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_16e8:
	/* 0x16e8: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_16eb:
	/* 0x16eb: xor    rcx,QWORD PTR [r15+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_16f2:
	/* 0x16f2: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16f5:
	/* 0x16f5: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_16f8:
	/* 0x16f8: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1700:
	/* 0x1700: mov    rax,QWORD PTR [r15+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_1707:
	/* 0x1707: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_170a:
	/* 0x170a: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_170f:
	/* 0x170f: je     1728 <trace_ret_do_init_module+0x1728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1728;
	}
x86_l_1711:
	/* 0x1711: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1714:
	/* 0x1714: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1718:
	/* 0x1718: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_171b:
	/* 0x171b: xor    rcx,QWORD PTR [r15+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_1722:
	/* 0x1722: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1725:
	/* 0x1725: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1728:
	/* 0x1728: movzx  eax,WORD PTR [r15+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_172d:
	/* 0x172d: mov    r13,QWORD PTR [r15+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_1734:
	/* 0x1734: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1737:
	/* 0x1737: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_173c:
	/* 0x173c: je     1870 <trace_ret_do_init_module+0x1870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1870;
	}
x86_l_1742:
	/* 0x1742: mov    rcx,QWORD PTR [r15+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_1749:
	/* 0x1749: mov    QWORD PTR [rsp+0xd0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1751:
	/* 0x1751: mov    rcx,QWORD PTR [r15+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_1758:
	/* 0x1758: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_175d:
	/* 0x175d: mov    rcx,QWORD PTR [r15+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_1764:
	/* 0x1764: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1769:
	/* 0x1769: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_176d:
	/* 0x176d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_1774:
	/* 0x1774: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1777:
	/* 0x1777: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_177c:
	/* 0x177c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177e:
	/* 0x177e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1781:
	/* 0x1781: mov    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1785:
	/* 0x1785: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1789:
	/* 0x1789: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1790:
	/* 0x1790: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1793:
	/* 0x1793: je     17b3 <trace_ret_do_init_module+0x17b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b3;
	}
x86_l_1795:
	/* 0x1795: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1798:
	/* 0x1798: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_179d:
	/* 0x179d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17a0:
	/* 0x17a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a2:
	/* 0x17a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17a5:
	/* 0x17a5: je     17b3 <trace_ret_do_init_module+0x17b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b3;
	}
x86_l_17a7:
	/* 0x17a7: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17aa:
	/* 0x17aa: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ae:
	/* 0x17ae: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_17b1:
	/* 0x17b1: jmp    17b6 <trace_ret_do_init_module+0x17b6> */
	goto x86_l_17b6;
x86_l_17b3:
	/* 0x17b3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b6:
	/* 0x17b6: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17bb:
	/* 0x17bb: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17c0:
	/* 0x17c0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c4:
	/* 0x17c4: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_17c7:
	/* 0x17c7: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_17ca:
	/* 0x17ca: jb     17e2 <trace_ret_do_init_module+0x17e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17e2;
	}
x86_l_17cc:
	/* 0x17cc: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_17d0:
	/* 0x17d0: je     17d7 <trace_ret_do_init_module+0x17d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17d7;
	}
x86_l_17d2:
	/* 0x17d2: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_17d5:
	/* 0x17d5: jbe    17e2 <trace_ret_do_init_module+0x17e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_17e2;
	}
x86_l_17d7:
	/* 0x17d7: and    r14,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 208ULL);
x86_l_17df:
	/* 0x17df: or     r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_17e2:
	/* 0x17e2: mov    eax,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17e6:
	/* 0x17e6: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17ea:
	/* 0x17ea: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_17f1:
	/* 0x17f1: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_17f4:
	/* 0x17f4: je     1835 <trace_ret_do_init_module+0x1835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1835;
	}
x86_l_17f6:
	/* 0x17f6: mov    QWORD PTR [rsp+0x58],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17fb:
	/* 0x17fb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_17fe:
	/* 0x17fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1803:
	/* 0x1803: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1806:
	/* 0x1806: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1808:
	/* 0x1808: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_180b:
	/* 0x180b: je     1839 <trace_ret_do_init_module+0x1839> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1839;
	}
x86_l_180d:
	/* 0x180d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1810:
	/* 0x1810: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1814:
	/* 0x1814: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1817:
	/* 0x1817: jmp    183b <trace_ret_do_init_module+0x183b> */
	goto x86_l_183b;
x86_l_1819:
	/* 0x1819: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1820:
	/* 0x1820: mov    rax,QWORD PTR [r15+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1827:
	/* 0x1827: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_182a:
	/* 0x182a: jne    16ab <trace_ret_do_init_module+0x16ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16ab;
	}
x86_l_1830:
	/* 0x1830: jmp    16d2 <trace_ret_do_init_module+0x16d2> */
	goto x86_l_16d2;
x86_l_1835:
	/* 0x1835: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1837:
	/* 0x1837: jmp    1845 <trace_ret_do_init_module+0x1845> */
	goto x86_l_1845;
x86_l_1839:
	/* 0x1839: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_183b:
	/* 0x183b: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1840:
	/* 0x1840: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1845:
	/* 0x1845: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1848:
	/* 0x1848: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_184c:
	/* 0x184c: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_184f:
	/* 0x184f: jb     1867 <trace_ret_do_init_module+0x1867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1867;
	}
x86_l_1851:
	/* 0x1851: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1855:
	/* 0x1855: je     185c <trace_ret_do_init_module+0x185c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_185c;
	}
x86_l_1857:
	/* 0x1857: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_185a:
	/* 0x185a: jbe    1867 <trace_ret_do_init_module+0x1867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1867;
	}
x86_l_185c:
	/* 0x185c: and    r14,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 208ULL);
x86_l_1864:
	/* 0x1864: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1867:
	/* 0x1867: or     r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_186a:
	/* 0x186a: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_186d:
	/* 0x186d: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1870:
	/* 0x1870: cmp    QWORD PTR [r15+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_1878:
	/* 0x1878: je     190f <trace_ret_do_init_module+0x190f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_190f;
	}
x86_l_187e:
	/* 0x187e: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1883:
	/* 0x1883: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1885:
	/* 0x1885: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1889:
	/* 0x1889: mov    rbx,QWORD PTR [r15+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1890:
	/* 0x1890: mov    rax,QWORD PTR [r15+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_1897:
	/* 0x1897: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_189c:
	/* 0x189c: mov    r13,QWORD PTR [r15+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_18a3:
	/* 0x18a3: mov    r12,QWORD PTR [r15+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_18aa:
	/* 0x18aa: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_18af:
	/* 0x18af: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b3:
	/* 0x18b3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_18ba:
	/* 0x18ba: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_18bd:
	/* 0x18bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18c2:
	/* 0x18c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c4:
	/* 0x18c4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_18c7:
	/* 0x18c7: mov    eax,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18cb:
	/* 0x18cb: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18cf:
	/* 0x18cf: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_18d6:
	/* 0x18d6: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_18d9:
	/* 0x18d9: je     18f6 <trace_ret_do_init_module+0x18f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f6;
	}
x86_l_18db:
	/* 0x18db: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_18de:
	/* 0x18de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18e3:
	/* 0x18e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e5:
	/* 0x18e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18e8:
	/* 0x18e8: je     18f6 <trace_ret_do_init_module+0x18f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f6;
	}
x86_l_18ea:
	/* 0x18ea: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ed:
	/* 0x18ed: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f1:
	/* 0x18f1: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_18f4:
	/* 0x18f4: jmp    18f8 <trace_ret_do_init_module+0x18f8> */
	goto x86_l_18f8;
x86_l_18f6:
	/* 0x18f6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18f8:
	/* 0x18f8: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_18fb:
	/* 0x18fb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ff:
	/* 0x18ff: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1902:
	/* 0x1902: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1905:
	/* 0x1905: jae    1917 <trace_ret_do_init_module+0x1917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1917;
	}
x86_l_1907:
	/* 0x1907: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_190d:
	/* 0x190d: jmp    1930 <trace_ret_do_init_module+0x1930> */
	goto x86_l_1930;
x86_l_190f:
	/* 0x190f: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1915:
	/* 0x1915: jmp    1936 <trace_ret_do_init_module+0x1936> */
	goto x86_l_1936;
x86_l_1917:
	/* 0x1917: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_191b:
	/* 0x191b: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1921:
	/* 0x1921: je     1928 <trace_ret_do_init_module+0x1928> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1928;
	}
x86_l_1923:
	/* 0x1923: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1926:
	/* 0x1926: jbe    1930 <trace_ret_do_init_module+0x1930> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1930;
	}
x86_l_1928:
	/* 0x1928: and    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 88ULL);
x86_l_192d:
	/* 0x192d: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1930:
	/* 0x1930: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1933:
	/* 0x1933: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1936:
	/* 0x1936: cmp    QWORD PTR [r15+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_193e:
	/* 0x193e: je     1a06 <trace_ret_do_init_module+0x1a06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a06;
	}
x86_l_1944:
	/* 0x1944: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1949:
	/* 0x1949: add    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1950:
	/* 0x1950: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1953:
	/* 0x1953: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1958:
	/* 0x1958: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_195d:
	/* 0x195d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1962:
	/* 0x1962: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1964:
	/* 0x1964: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1968:
	/* 0x1968: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_196c:
	/* 0x196c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_196f:
	/* 0x196f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1974:
	/* 0x1974: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1979:
	/* 0x1979: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_197e:
	/* 0x197e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1980:
	/* 0x1980: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1984:
	/* 0x1984: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1989:
	/* 0x1989: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_198e:
	/* 0x198e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1993:
	/* 0x1993: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1997:
	/* 0x1997: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_199c:
	/* 0x199c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199e:
	/* 0x199e: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19a2:
	/* 0x19a2: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_19a6:
	/* 0x19a6: mov    rbx,QWORD PTR [r15+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_19ad:
	/* 0x19ad: mov    r14,QWORD PTR [r15+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_19b4:
	/* 0x19b4: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b9:
	/* 0x19b9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_19c0:
	/* 0x19c0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_19c3:
	/* 0x19c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19c8:
	/* 0x19c8: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_19cb:
	/* 0x19cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19cd:
	/* 0x19cd: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_19d4:
	/* 0x19d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19d7:
	/* 0x19d7: je     19f8 <trace_ret_do_init_module+0x19f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f8;
	}
x86_l_19d9:
	/* 0x19d9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_19dc:
	/* 0x19dc: lea    rsi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_19e0:
	/* 0x19e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19e5:
	/* 0x19e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e7:
	/* 0x19e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19ea:
	/* 0x19ea: je     19f8 <trace_ret_do_init_module+0x19f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f8;
	}
x86_l_19ec:
	/* 0x19ec: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ef:
	/* 0x19ef: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19f3:
	/* 0x19f3: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_19f6:
	/* 0x19f6: jmp    19fa <trace_ret_do_init_module+0x19fa> */
	goto x86_l_19fa;
x86_l_19f8:
	/* 0x19f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19fa:
	/* 0x19fa: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_19fd:
	/* 0x19fd: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1a00:
	/* 0x1a00: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a03:
	/* 0x1a03: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1a06:
	/* 0x1a06: cmp    QWORD PTR [r15+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1a0e:
	/* 0x1a0e: je     1af4 <trace_ret_do_init_module+0x1af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af4;
	}
x86_l_1a14:
	/* 0x1a14: mov    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1a1b:
	/* 0x1a1b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a1f:
	/* 0x1a1f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a22:
	/* 0x1a22: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a27:
	/* 0x1a27: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a31:
	/* 0x1a31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a33:
	/* 0x1a33: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a37:
	/* 0x1a37: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a3a:
	/* 0x1a3a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a3f:
	/* 0x1a3f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a44:
	/* 0x1a44: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a49:
	/* 0x1a49: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1a4c:
	/* 0x1a4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4e:
	/* 0x1a4e: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a51:
	/* 0x1a51: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1a55:
	/* 0x1a55: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a59:
	/* 0x1a59: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a5d:
	/* 0x1a5d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a60:
	/* 0x1a60: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a65:
	/* 0x1a65: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a6a:
	/* 0x1a6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a6f:
	/* 0x1a6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a71:
	/* 0x1a71: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a75:
	/* 0x1a75: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1a79:
	/* 0x1a79: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a7c:
	/* 0x1a7c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a81:
	/* 0x1a81: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a86:
	/* 0x1a86: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a8b:
	/* 0x1a8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8d:
	/* 0x1a8d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a90:
	/* 0x1a90: mov    DWORD PTR [r15+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a94:
	/* 0x1a94: mov    rbx,QWORD PTR [r15+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    r14,QWORD PTR [r15+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa7:
	/* 0x1aa7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1aae:
	/* 0x1aae: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1ab1:
	/* 0x1ab1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ab6:
	/* 0x1ab6: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1ab9:
	/* 0x1ab9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1abb:
	/* 0x1abb: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1ac2:
	/* 0x1ac2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ac5:
	/* 0x1ac5: je     1ae6 <trace_ret_do_init_module+0x1ae6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae6;
	}
x86_l_1ac7:
	/* 0x1ac7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1aca:
	/* 0x1aca: lea    rsi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ace:
	/* 0x1ace: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ad3:
	/* 0x1ad3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad5:
	/* 0x1ad5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ad8:
	/* 0x1ad8: je     1ae6 <trace_ret_do_init_module+0x1ae6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae6;
	}
x86_l_1ada:
	/* 0x1ada: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1add:
	/* 0x1add: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ae1:
	/* 0x1ae1: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1ae4:
	/* 0x1ae4: jmp    1ae8 <trace_ret_do_init_module+0x1ae8> */
	goto x86_l_1ae8;
x86_l_1ae6:
	/* 0x1ae6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae8:
	/* 0x1ae8: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1aeb:
	/* 0x1aeb: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1aee:
	/* 0x1aee: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1af1:
	/* 0x1af1: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1af4:
	/* 0x1af4: cmp    QWORD PTR [r15+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1afc:
	/* 0x1afc: je     1bd3 <trace_ret_do_init_module+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1b02:
	/* 0x1b02: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1b07:
	/* 0x1b07: add    rdx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1b0e:
	/* 0x1b0e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b11:
	/* 0x1b11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b16:
	/* 0x1b16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b20:
	/* 0x1b20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b22:
	/* 0x1b22: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b26:
	/* 0x1b26: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b29:
	/* 0x1b29: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b2e:
	/* 0x1b2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b33:
	/* 0x1b33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b38:
	/* 0x1b38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3a:
	/* 0x1b3a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b3e:
	/* 0x1b3e: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_1b41:
	/* 0x1b41: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1b46:
	/* 0x1b46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b4b:
	/* 0x1b4b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b4e:
	/* 0x1b4e: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1b53:
	/* 0x1b53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 6997ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6997ULL: goto x86_l_1b55;
	case 7001ULL: goto x86_l_1b59;
	case 7006ULL: goto x86_l_1b5e;
	case 7011ULL: goto x86_l_1b63;
	case 7014ULL: goto x86_l_1b66;
	case 7019ULL: goto x86_l_1b6b;
	case 7022ULL: goto x86_l_1b6e;
	case 7024ULL: goto x86_l_1b70;
	case 7031ULL: goto x86_l_1b77;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7047ULL: goto x86_l_1b87;
	case 7054ULL: goto x86_l_1b8e;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7067ULL: goto x86_l_1b9b;
	case 7074ULL: goto x86_l_1ba2;
	case 7077ULL: goto x86_l_1ba5;
	case 7079ULL: goto x86_l_1ba7;
	case 7082ULL: goto x86_l_1baa;
	case 7087ULL: goto x86_l_1baf;
	case 7090ULL: goto x86_l_1bb2;
	case 7092ULL: goto x86_l_1bb4;
	case 7095ULL: goto x86_l_1bb7;
	case 7097ULL: goto x86_l_1bb9;
	case 7100ULL: goto x86_l_1bbc;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7109ULL: goto x86_l_1bc5;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7117ULL: goto x86_l_1bcd;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7131ULL: goto x86_l_1bdb;
	case 7137ULL: goto x86_l_1be1;
	case 7143ULL: goto x86_l_1be7;
	case 7147ULL: goto x86_l_1beb;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7160ULL: goto x86_l_1bf8;
	case 7165ULL: goto x86_l_1bfd;
	case 7167ULL: goto x86_l_1bff;
	case 7174ULL: goto x86_l_1c06;
	case 7181ULL: goto x86_l_1c0d;
	case 7186ULL: goto x86_l_1c12;
	case 7193ULL: goto x86_l_1c19;
	case 7196ULL: goto x86_l_1c1c;
	case 7201ULL: goto x86_l_1c21;
	case 7204ULL: goto x86_l_1c24;
	case 7206ULL: goto x86_l_1c26;
	case 7213ULL: goto x86_l_1c2d;
	case 7216ULL: goto x86_l_1c30;
	case 7218ULL: goto x86_l_1c32;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7229ULL: goto x86_l_1c3d;
	case 7231ULL: goto x86_l_1c3f;
	case 7234ULL: goto x86_l_1c42;
	case 7236ULL: goto x86_l_1c44;
	case 7239ULL: goto x86_l_1c47;
	case 7243ULL: goto x86_l_1c4b;
	case 7246ULL: goto x86_l_1c4e;
	case 7248ULL: goto x86_l_1c50;
	case 7250ULL: goto x86_l_1c52;
	case 7253ULL: goto x86_l_1c55;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7262ULL: goto x86_l_1c5e;
	case 7268ULL: goto x86_l_1c64;
	case 7275ULL: goto x86_l_1c6b;
	case 7278ULL: goto x86_l_1c6e;
	case 7280ULL: goto x86_l_1c70;
	case 7284ULL: goto x86_l_1c74;
	case 7287ULL: goto x86_l_1c77;
	case 7294ULL: goto x86_l_1c7e;
	case 7300ULL: goto x86_l_1c84;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	case 7329ULL: goto x86_l_1ca1;
	case 7332ULL: goto x86_l_1ca4;
	case 7334ULL: goto x86_l_1ca6;
	case 7337ULL: goto x86_l_1ca9;
	case 7340ULL: goto x86_l_1cac;
	case 7345ULL: goto x86_l_1cb1;
	case 7347ULL: goto x86_l_1cb3;
	case 7350ULL: goto x86_l_1cb6;
	case 7352ULL: goto x86_l_1cb8;
	case 7355ULL: goto x86_l_1cbb;
	case 7359ULL: goto x86_l_1cbf;
	case 7362ULL: goto x86_l_1cc2;
	case 7364ULL: goto x86_l_1cc4;
	case 7366ULL: goto x86_l_1cc6;
	case 7369ULL: goto x86_l_1cc9;
	case 7372ULL: goto x86_l_1ccc;
	case 7375ULL: goto x86_l_1ccf;
	case 7378ULL: goto x86_l_1cd2;
	case 7385ULL: goto x86_l_1cd9;
	case 7388ULL: goto x86_l_1cdc;
	case 7390ULL: goto x86_l_1cde;
	case 7397ULL: goto x86_l_1ce5;
	case 7402ULL: goto x86_l_1cea;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7417ULL: goto x86_l_1cf9;
	case 7420ULL: goto x86_l_1cfc;
	case 7422ULL: goto x86_l_1cfe;
	case 7429ULL: goto x86_l_1d05;
	case 7432ULL: goto x86_l_1d08;
	case 7434ULL: goto x86_l_1d0a;
	case 7437ULL: goto x86_l_1d0d;
	case 7442ULL: goto x86_l_1d12;
	case 7450ULL: goto x86_l_1d1a;
	case 7452ULL: goto x86_l_1d1c;
	case 7455ULL: goto x86_l_1d1f;
	case 7457ULL: goto x86_l_1d21;
	case 7460ULL: goto x86_l_1d24;
	case 7464ULL: goto x86_l_1d28;
	case 7467ULL: goto x86_l_1d2b;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7474ULL: goto x86_l_1d32;
	case 7477ULL: goto x86_l_1d35;
	case 7480ULL: goto x86_l_1d38;
	case 7483ULL: goto x86_l_1d3b;
	case 7490ULL: goto x86_l_1d42;
	case 7493ULL: goto x86_l_1d45;
	case 7495ULL: goto x86_l_1d47;
	case 7502ULL: goto x86_l_1d4e;
	case 7507ULL: goto x86_l_1d53;
	case 7514ULL: goto x86_l_1d5a;
	case 7517ULL: goto x86_l_1d5d;
	case 7522ULL: goto x86_l_1d62;
	case 7525ULL: goto x86_l_1d65;
	case 7527ULL: goto x86_l_1d67;
	case 7534ULL: goto x86_l_1d6e;
	case 7537ULL: goto x86_l_1d71;
	case 7539ULL: goto x86_l_1d73;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7559ULL: goto x86_l_1d87;
	case 7561ULL: goto x86_l_1d89;
	case 7564ULL: goto x86_l_1d8c;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7585ULL: goto x86_l_1da1;
	case 7588ULL: goto x86_l_1da4;
	case 7590ULL: goto x86_l_1da6;
	case 7593ULL: goto x86_l_1da9;
	case 7597ULL: goto x86_l_1dad;
	case 7600ULL: goto x86_l_1db0;
	case 7602ULL: goto x86_l_1db2;
	case 7604ULL: goto x86_l_1db4;
	case 7607ULL: goto x86_l_1db7;
	case 7610ULL: goto x86_l_1dba;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7623ULL: goto x86_l_1dc7;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7633ULL: goto x86_l_1dd1;
	case 7637ULL: goto x86_l_1dd5;
	case 7640ULL: goto x86_l_1dd8;
	case 7642ULL: goto x86_l_1dda;
	case 7649ULL: goto x86_l_1de1;
	case 7656ULL: goto x86_l_1de8;
	case 7659ULL: goto x86_l_1deb;
	case 7666ULL: goto x86_l_1df2;
	case 7672ULL: goto x86_l_1df8;
	case 7680ULL: goto x86_l_1e00;
	case 7686ULL: goto x86_l_1e06;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7705ULL: goto x86_l_1e19;
	case 7714ULL: goto x86_l_1e22;
	case 7722ULL: goto x86_l_1e2a;
	case 7730ULL: goto x86_l_1e32;
	case 7737ULL: goto x86_l_1e39;
	case 7743ULL: goto x86_l_1e3f;
	case 7751ULL: goto x86_l_1e47;
	case 7755ULL: goto x86_l_1e4b;
	case 7758ULL: goto x86_l_1e4e;
	case 7765ULL: goto x86_l_1e55;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7783ULL: goto x86_l_1e67;
	case 7787ULL: goto x86_l_1e6b;
	case 7794ULL: goto x86_l_1e72;
	case 7799ULL: goto x86_l_1e77;
	case 7801ULL: goto x86_l_1e79;
	case 7803ULL: goto x86_l_1e7b;
	case 7805ULL: goto x86_l_1e7d;
	case 7813ULL: goto x86_l_1e85;
	case 7820ULL: goto x86_l_1e8c;
	case 7822ULL: goto x86_l_1e8e;
	case 7830ULL: goto x86_l_1e96;
	case 7838ULL: goto x86_l_1e9e;
	case 7841ULL: goto x86_l_1ea1;
	case 7849ULL: goto x86_l_1ea9;
	case 7856ULL: goto x86_l_1eb0;
	case 7858ULL: goto x86_l_1eb2;
	case 7860ULL: goto x86_l_1eb4;
	case 7868ULL: goto x86_l_1ebc;
	case 7871ULL: goto x86_l_1ebf;
	case 7876ULL: goto x86_l_1ec4;
	case 7882ULL: goto x86_l_1eca;
	case 7891ULL: goto x86_l_1ed3;
	case 7899ULL: goto x86_l_1edb;
	case 7907ULL: goto x86_l_1ee3;
	case 7914ULL: goto x86_l_1eea;
	case 7916ULL: goto x86_l_1eec;
	case 7919ULL: goto x86_l_1eef;
	case 7926ULL: goto x86_l_1ef6;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7944ULL: goto x86_l_1f08;
	case 7948ULL: goto x86_l_1f0c;
	case 7955ULL: goto x86_l_1f13;
	case 7960ULL: goto x86_l_1f18;
	case 7963ULL: goto x86_l_1f1b;
	case 7965ULL: goto x86_l_1f1d;
	case 7967ULL: goto x86_l_1f1f;
	case 7969ULL: goto x86_l_1f21;
	case 7977ULL: goto x86_l_1f29;
	case 7984ULL: goto x86_l_1f30;
	case 7986ULL: goto x86_l_1f32;
	case 7994ULL: goto x86_l_1f3a;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8013ULL: goto x86_l_1f4d;
	case 8020ULL: goto x86_l_1f54;
	case 8022ULL: goto x86_l_1f56;
	case 8024ULL: goto x86_l_1f58;
	case 8032ULL: goto x86_l_1f60;
	case 8035ULL: goto x86_l_1f63;
	case 8040ULL: goto x86_l_1f68;
	case 8046ULL: goto x86_l_1f6e;
	case 8055ULL: goto x86_l_1f77;
	case 8063ULL: goto x86_l_1f7f;
	case 8071ULL: goto x86_l_1f87;
	case 8077ULL: goto x86_l_1f8d;
	case 8079ULL: goto x86_l_1f8f;
	case 8083ULL: goto x86_l_1f93;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8108ULL: goto x86_l_1fac;
	case 8112ULL: goto x86_l_1fb0;
	case 8119ULL: goto x86_l_1fb7;
	case 8124ULL: goto x86_l_1fbc;
	case 8127ULL: goto x86_l_1fbf;
	case 8129ULL: goto x86_l_1fc1;
	case 8131ULL: goto x86_l_1fc3;
	case 8133ULL: goto x86_l_1fc5;
	case 8141ULL: goto x86_l_1fcd;
	case 8148ULL: goto x86_l_1fd4;
	case 8150ULL: goto x86_l_1fd6;
	case 8158ULL: goto x86_l_1fde;
	case 8166ULL: goto x86_l_1fe6;
	case 8169ULL: goto x86_l_1fe9;
	case 8177ULL: goto x86_l_1ff1;
	case 8184ULL: goto x86_l_1ff8;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8199ULL: goto x86_l_2007;
	case 8207ULL: goto x86_l_200f;
	case 8214ULL: goto x86_l_2016;
	case 8216ULL: goto x86_l_2018;
	case 8225ULL: goto x86_l_2021;
	case 8231ULL: goto x86_l_2027;
	case 8233ULL: goto x86_l_2029;
	case 8237ULL: goto x86_l_202d;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8264ULL: goto x86_l_2048;
	case 8266ULL: goto x86_l_204a;
	case 8269ULL: goto x86_l_204d;
	case 8271ULL: goto x86_l_204f;
	case 8274ULL: goto x86_l_2052;
	case 8282ULL: goto x86_l_205a;
	case 8289ULL: goto x86_l_2061;
	case 8296ULL: goto x86_l_2068;
	case 8300ULL: goto x86_l_206c;
	case 8303ULL: goto x86_l_206f;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8318ULL: goto x86_l_207e;
	case 8321ULL: goto x86_l_2081;
	case 8323ULL: goto x86_l_2083;
	case 8327ULL: goto x86_l_2087;
	case 8335ULL: goto x86_l_208f;
	case 8339ULL: goto x86_l_2093;
	case 8342ULL: goto x86_l_2096;
	case 8347ULL: goto x86_l_209b;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8359ULL: goto x86_l_20a7;
	case 8363ULL: goto x86_l_20ab;
	case 8367ULL: goto x86_l_20af;
	case 8370ULL: goto x86_l_20b2;
	case 8375ULL: goto x86_l_20b7;
	case 8380ULL: goto x86_l_20bc;
	case 8385ULL: goto x86_l_20c1;
	case 8387ULL: goto x86_l_20c3;
	case 8391ULL: goto x86_l_20c7;
	case 8396ULL: goto x86_l_20cc;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8409ULL: goto x86_l_20d9;
	case 8414ULL: goto x86_l_20de;
	case 8416ULL: goto x86_l_20e0;
	case 8419ULL: goto x86_l_20e3;
	case 8423ULL: goto x86_l_20e7;
	case 8427ULL: goto x86_l_20eb;
	case 8430ULL: goto x86_l_20ee;
	case 8435ULL: goto x86_l_20f3;
	case 8440ULL: goto x86_l_20f8;
	case 8445ULL: goto x86_l_20fd;
	case 8448ULL: goto x86_l_2100;
	case 8450ULL: goto x86_l_2102;
	case 8454ULL: goto x86_l_2106;
	case 8457ULL: goto x86_l_2109;
	case 8462ULL: goto x86_l_210e;
	case 8467ULL: goto x86_l_2113;
	case 8472ULL: goto x86_l_2118;
	case 8475ULL: goto x86_l_211b;
	case 8477ULL: goto x86_l_211d;
	case 8480ULL: goto x86_l_2120;
	case 8484ULL: goto x86_l_2124;
	case 8488ULL: goto x86_l_2128;
	case 8492ULL: goto x86_l_212c;
	case 8495ULL: goto x86_l_212f;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8510ULL: goto x86_l_213e;
	case 8512ULL: goto x86_l_2140;
	case 8515ULL: goto x86_l_2143;
	case 8519ULL: goto x86_l_2147;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8532ULL: goto x86_l_2154;
	case 8537ULL: goto x86_l_2159;
	case 8540ULL: goto x86_l_215c;
	case 8542ULL: goto x86_l_215e;
	case 8546ULL: goto x86_l_2162;
	case 8550ULL: goto x86_l_2166;
	case 8553ULL: goto x86_l_2169;
	case 8558ULL: goto x86_l_216e;
	case 8563ULL: goto x86_l_2173;
	case 8568ULL: goto x86_l_2178;
	case 8570ULL: goto x86_l_217a;
	case 8574ULL: goto x86_l_217e;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8587ULL: goto x86_l_218b;
	case 8592ULL: goto x86_l_2190;
	case 8595ULL: goto x86_l_2193;
	case 8597ULL: goto x86_l_2195;
	case 8600ULL: goto x86_l_2198;
	case 8604ULL: goto x86_l_219c;
	case 8608ULL: goto x86_l_21a0;
	case 8612ULL: goto x86_l_21a4;
	case 8615ULL: goto x86_l_21a7;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8630ULL: goto x86_l_21b6;
	case 8632ULL: goto x86_l_21b8;
	case 8635ULL: goto x86_l_21bb;
	case 8639ULL: goto x86_l_21bf;
	case 8642ULL: goto x86_l_21c2;
	case 8647ULL: goto x86_l_21c7;
	case 8652ULL: goto x86_l_21cc;
	case 8657ULL: goto x86_l_21d1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b55:
	/* 0x1b55: lea    rbx,[r15+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1b59:
	/* 0x1b59: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b5e:
	/* 0x1b5e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b63:
	/* 0x1b63: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b66:
	/* 0x1b66: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b6b:
	/* 0x1b6b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b6e:
	/* 0x1b6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b70:
	/* 0x1b70: mov    r14,QWORD PTR [r15+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1b77:
	/* 0x1b77: mov    r12,QWORD PTR [r15+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1b7e:
	/* 0x1b7e: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1b83:
	/* 0x1b83: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b87:
	/* 0x1b87: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1b8e:
	/* 0x1b8e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1b91:
	/* 0x1b91: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b96:
	/* 0x1b96: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1b99:
	/* 0x1b99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b9b:
	/* 0x1b9b: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1ba2:
	/* 0x1ba2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ba5:
	/* 0x1ba5: je     1bc5 <trace_ret_do_init_module+0x1bc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bc5;
	}
x86_l_1ba7:
	/* 0x1ba7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1baa:
	/* 0x1baa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1baf:
	/* 0x1baf: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1bb2:
	/* 0x1bb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb4:
	/* 0x1bb4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bb7:
	/* 0x1bb7: je     1bc5 <trace_ret_do_init_module+0x1bc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bc5;
	}
x86_l_1bb9:
	/* 0x1bb9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bbc:
	/* 0x1bbc: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bc0:
	/* 0x1bc0: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1bc3:
	/* 0x1bc3: jmp    1bc7 <trace_ret_do_init_module+0x1bc7> */
	goto x86_l_1bc7;
x86_l_1bc5:
	/* 0x1bc5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bc7:
	/* 0x1bc7: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1bca:
	/* 0x1bca: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1bcd:
	/* 0x1bcd: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1bd0:
	/* 0x1bd0: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1bd3:
	/* 0x1bd3: cmp    QWORD PTR [r15+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1bdb:
	/* 0x1bdb: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1be1:
	/* 0x1be1: je     1c64 <trace_ret_do_init_module+0x1c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c64;
	}
x86_l_1be7:
	/* 0x1be7: lea    rbx,[r15+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1beb:
	/* 0x1beb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1bf5:
	/* 0x1bf5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1bf8:
	/* 0x1bf8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1bfd:
	/* 0x1bfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bff:
	/* 0x1bff: mov    r14,QWORD PTR [r15+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1c06:
	/* 0x1c06: mov    r12,QWORD PTR [r15+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c12:
	/* 0x1c12: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1c19:
	/* 0x1c19: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1c1c:
	/* 0x1c1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c21:
	/* 0x1c21: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c24:
	/* 0x1c24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c26:
	/* 0x1c26: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1c2d:
	/* 0x1c2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c30:
	/* 0x1c30: je     1c50 <trace_ret_do_init_module+0x1c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c50;
	}
x86_l_1c32:
	/* 0x1c32: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c35:
	/* 0x1c35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c3a:
	/* 0x1c3a: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1c3d:
	/* 0x1c3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3f:
	/* 0x1c3f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c42:
	/* 0x1c42: je     1c50 <trace_ret_do_init_module+0x1c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c50;
	}
x86_l_1c44:
	/* 0x1c44: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c47:
	/* 0x1c47: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c4b:
	/* 0x1c4b: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c4e:
	/* 0x1c4e: jmp    1c52 <trace_ret_do_init_module+0x1c52> */
	goto x86_l_1c52;
x86_l_1c50:
	/* 0x1c50: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c52:
	/* 0x1c52: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c55:
	/* 0x1c55: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1c58:
	/* 0x1c58: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c5b:
	/* 0x1c5b: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1c5e:
	/* 0x1c5e: movzx  r13d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1c64:
	/* 0x1c64: mov    rbx,QWORD PTR [r15+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1c6b:
	/* 0x1c6b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1c6e:
	/* 0x1c6e: je     1cd2 <trace_ret_do_init_module+0x1cd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cd2;
	}
x86_l_1c70:
	/* 0x1c70: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c74:
	/* 0x1c74: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c77:
	/* 0x1c77: mov    r14,QWORD PTR [r15+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    WORD PTR [rsp+0x48],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c84:
	/* 0x1c84: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1c8b:
	/* 0x1c8b: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c90:
	/* 0x1c90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c95:
	/* 0x1c95: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c98:
	/* 0x1c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9a:
	/* 0x1c9a: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1ca1:
	/* 0x1ca1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ca4:
	/* 0x1ca4: je     1cc4 <trace_ret_do_init_module+0x1cc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cc4;
	}
x86_l_1ca6:
	/* 0x1ca6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ca9:
	/* 0x1ca9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1cac:
	/* 0x1cac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cb1:
	/* 0x1cb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb3:
	/* 0x1cb3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cb6:
	/* 0x1cb6: je     1cc4 <trace_ret_do_init_module+0x1cc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cc4;
	}
x86_l_1cb8:
	/* 0x1cb8: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cbb:
	/* 0x1cbb: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cbf:
	/* 0x1cbf: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1cc2:
	/* 0x1cc2: jmp    1cc6 <trace_ret_do_init_module+0x1cc6> */
	goto x86_l_1cc6;
x86_l_1cc4:
	/* 0x1cc4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cc6:
	/* 0x1cc6: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1cc9:
	/* 0x1cc9: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1ccc:
	/* 0x1ccc: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ccf:
	/* 0x1ccf: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1cd2:
	/* 0x1cd2: mov    rbx,QWORD PTR [r15+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1cd9:
	/* 0x1cd9: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1cdc:
	/* 0x1cdc: je     1d3b <trace_ret_do_init_module+0x1d3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d3b;
	}
x86_l_1cde:
	/* 0x1cde: mov    r14,QWORD PTR [r15+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1ce5:
	/* 0x1ce5: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cea:
	/* 0x1cea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1cf1:
	/* 0x1cf1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1cf4:
	/* 0x1cf4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cf9:
	/* 0x1cf9: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1cfc:
	/* 0x1cfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cfe:
	/* 0x1cfe: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1d05:
	/* 0x1d05: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d08:
	/* 0x1d08: je     1d2d <trace_ret_do_init_module+0x1d2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d2d;
	}
x86_l_1d0a:
	/* 0x1d0a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1d0d:
	/* 0x1d0d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d12:
	/* 0x1d12: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1d1a:
	/* 0x1d1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1c:
	/* 0x1d1c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d1f:
	/* 0x1d1f: je     1d2d <trace_ret_do_init_module+0x1d2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d2d;
	}
x86_l_1d21:
	/* 0x1d21: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d24:
	/* 0x1d24: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d28:
	/* 0x1d28: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d2b:
	/* 0x1d2b: jmp    1d2f <trace_ret_do_init_module+0x1d2f> */
	goto x86_l_1d2f;
x86_l_1d2d:
	/* 0x1d2d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d2f:
	/* 0x1d2f: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d32:
	/* 0x1d32: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d35:
	/* 0x1d35: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d38:
	/* 0x1d38: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d3b:
	/* 0x1d3b: mov    r14,QWORD PTR [r15+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1d42:
	/* 0x1d42: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1d45:
	/* 0x1d45: je     1dc0 <trace_ret_do_init_module+0x1dc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dc0;
	}
x86_l_1d47:
	/* 0x1d47: mov    r12,QWORD PTR [r15+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1d4e:
	/* 0x1d4e: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d53:
	/* 0x1d53: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1d5a:
	/* 0x1d5a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1d5d:
	/* 0x1d5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d62:
	/* 0x1d62: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d65:
	/* 0x1d65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d67:
	/* 0x1d67: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1d6e:
	/* 0x1d6e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d71:
	/* 0x1d71: je     1db2 <trace_ret_do_init_module+0x1db2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1db2;
	}
x86_l_1d73:
	/* 0x1d73: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1d76:
	/* 0x1d76: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d7b:
	/* 0x1d7b: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d84:
	/* 0x1d84: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d87:
	/* 0x1d87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d89:
	/* 0x1d89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d8c:
	/* 0x1d8c: jne    1da6 <trace_ret_do_init_module+0x1da6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1da6;
	}
x86_l_1d8e:
	/* 0x1d8e: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d93:
	/* 0x1d93: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d97:
	/* 0x1d97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d9c:
	/* 0x1d9c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d9f:
	/* 0x1d9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da1:
	/* 0x1da1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1da4:
	/* 0x1da4: je     1db2 <trace_ret_do_init_module+0x1db2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1db2;
	}
x86_l_1da6:
	/* 0x1da6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1da9:
	/* 0x1da9: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dad:
	/* 0x1dad: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1db0:
	/* 0x1db0: jmp    1db4 <trace_ret_do_init_module+0x1db4> */
	goto x86_l_1db4;
x86_l_1db2:
	/* 0x1db2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1db4:
	/* 0x1db4: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1db7:
	/* 0x1db7: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1dba:
	/* 0x1dba: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1dbd:
	/* 0x1dbd: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1dc0:
	/* 0x1dc0: mov    rax,QWORD PTR [r15+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1dc7:
	/* 0x1dc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dca:
	/* 0x1dca: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1dcf:
	/* 0x1dcf: je     1dd8 <trace_ret_do_init_module+0x1dd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dd8;
	}
x86_l_1dd1:
	/* 0x1dd1: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1dd5:
	/* 0x1dd5: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1dd8:
	/* 0x1dd8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dda:
	/* 0x1dda: and    rbp,QWORD PTR [r15+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1de1:
	/* 0x1de1: mov    rcx,QWORD PTR [r15+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1de8:
	/* 0x1de8: and    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1deb:
	/* 0x1deb: mov    QWORD PTR [r15+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1df2:
	/* 0x1df2: je     255c <trace_ret_do_init_module+0x255c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9564ULL;
	}
x86_l_1df8:
	/* 0x1df8: movzx  eax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e00:
	/* 0x1e00: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1e06:
	/* 0x1e06: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e13:
	/* 0x1e13: ja     1ff8 <trace_ret_do_init_module+0x1ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ff8;
	}
x86_l_1e19:
	/* 0x1e19: mov    BYTE PTR [r15+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1e22:
	/* 0x1e22: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e2a:
	/* 0x1e2a: mov    WORD PTR [r15+0x7d8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1e32:
	/* 0x1e32: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1e39:
	/* 0x1e39: ja     1ebc <trace_ret_do_init_module+0x1ebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ebc;
	}
x86_l_1e3f:
	/* 0x1e3f: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1e47:
	/* 0x1e47: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e4b:
	/* 0x1e4b: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e4e:
	/* 0x1e4e: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1e55:
	/* 0x1e55: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e5a:
	/* 0x1e5a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e5f:
	/* 0x1e5f: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e67:
	/* 0x1e67: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1e6b:
	/* 0x1e6b: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1e72:
	/* 0x1e72: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e77:
	/* 0x1e77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e79:
	/* 0x1e79: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e7b:
	/* 0x1e7b: jle    1eb4 <trace_ret_do_init_module+0x1eb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1eb4;
	}
x86_l_1e7d:
	/* 0x1e7d: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e85:
	/* 0x1e85: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1e8c:
	/* 0x1e8c: ja     1ebc <trace_ret_do_init_module+0x1ebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ebc;
	}
x86_l_1e8e:
	/* 0x1e8e: mov    DWORD PTR [rcx+r15*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_1e96:
	/* 0x1e96: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1e9e:
	/* 0x1e9e: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1ea1:
	/* 0x1ea1: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ea9:
	/* 0x1ea9: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1eb2:
	/* 0x1eb2: jmp    1ebc <trace_ret_do_init_module+0x1ebc> */
	goto x86_l_1ebc;
x86_l_1eb4:
	/* 0x1eb4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ebc:
	/* 0x1ebc: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ebf:
	/* 0x1ebf: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1ec4:
	/* 0x1ec4: ja     1ff8 <trace_ret_do_init_module+0x1ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ff8;
	}
x86_l_1eca:
	/* 0x1eca: mov    BYTE PTR [r15+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_1ed3:
	/* 0x1ed3: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1edb:
	/* 0x1edb: mov    WORD PTR [r15+0x7d8e],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32142ULL);
x86_l_1ee3:
	/* 0x1ee3: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1eea:
	/* 0x1eea: ja     1f60 <trace_ret_do_init_module+0x1f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f60;
	}
x86_l_1eec:
	/* 0x1eec: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1eef:
	/* 0x1eef: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1ef6:
	/* 0x1ef6: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1efb:
	/* 0x1efb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f00:
	/* 0x1f00: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f08:
	/* 0x1f08: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1f0c:
	/* 0x1f0c: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1f13:
	/* 0x1f13: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f18:
	/* 0x1f18: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1f1b:
	/* 0x1f1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1d:
	/* 0x1f1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f1f:
	/* 0x1f1f: jle    1f58 <trace_ret_do_init_module+0x1f58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f58;
	}
x86_l_1f21:
	/* 0x1f21: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f29:
	/* 0x1f29: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1f30:
	/* 0x1f30: ja     1f60 <trace_ret_do_init_module+0x1f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f60;
	}
x86_l_1f32:
	/* 0x1f32: mov    DWORD PTR [rcx+r15*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_1f3a:
	/* 0x1f3a: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f42:
	/* 0x1f42: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1f45:
	/* 0x1f45: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f4d:
	/* 0x1f4d: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1f54:
	/* 0x1f54: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1f56:
	/* 0x1f56: jmp    1f60 <trace_ret_do_init_module+0x1f60> */
	goto x86_l_1f60;
x86_l_1f58:
	/* 0x1f58: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f60:
	/* 0x1f60: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1f63:
	/* 0x1f63: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1f68:
	/* 0x1f68: ja     1ff8 <trace_ret_do_init_module+0x1ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ff8;
	}
x86_l_1f6e:
	/* 0x1f6e: mov    BYTE PTR [r15+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_1f77:
	/* 0x1f77: movzx  eax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f7f:
	/* 0x1f7f: mov    WORD PTR [r15+0x7d90],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32144ULL);
x86_l_1f87:
	/* 0x1f87: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1f8d:
	/* 0x1f8d: ja     1ff8 <trace_ret_do_init_module+0x1ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ff8;
	}
x86_l_1f8f:
	/* 0x1f8f: lea    rcx,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1f93:
	/* 0x1f93: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1f9f:
	/* 0x1f9f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1fa4:
	/* 0x1fa4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fac:
	/* 0x1fac: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1fb0:
	/* 0x1fb0: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1fb7:
	/* 0x1fb7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1fbc:
	/* 0x1fbc: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1fbf:
	/* 0x1fbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc1:
	/* 0x1fc1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fc3:
	/* 0x1fc3: jle    1ff8 <trace_ret_do_init_module+0x1ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ff8;
	}
x86_l_1fc5:
	/* 0x1fc5: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fcd:
	/* 0x1fcd: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1fd4:
	/* 0x1fd4: ja     1ff8 <trace_ret_do_init_module+0x1ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ff8;
	}
x86_l_1fd6:
	/* 0x1fd6: mov    DWORD PTR [rcx+r15*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_1fde:
	/* 0x1fde: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1fe6:
	/* 0x1fe6: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1fe9:
	/* 0x1fe9: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ff1:
	/* 0x1ff1: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1ff8:
	/* 0x1ff8: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2000:
	/* 0x2000: mov    eax,DWORD PTR [rax+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2003:
	/* 0x2003: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2007:
	/* 0x2007: movzx  ebx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_200f:
	/* 0x200f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2016:
	/* 0x2016: ja     2061 <trace_ret_do_init_module+0x2061> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2061;
	}
x86_l_2018:
	/* 0x2018: mov    BYTE PTR [r15+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_2021:
	/* 0x2021: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_2027:
	/* 0x2027: ja     2061 <trace_ret_do_init_module+0x2061> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2061;
	}
x86_l_2029:
	/* 0x2029: lea    rdi,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_202d:
	/* 0x202d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2034:
	/* 0x2034: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2039:
	/* 0x2039: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_203e:
	/* 0x203e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2043:
	/* 0x2043: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2048:
	/* 0x2048: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204a:
	/* 0x204a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_204d:
	/* 0x204d: js     2061 <trace_ret_do_init_module+0x2061> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2061;
	}
x86_l_204f:
	/* 0x204f: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2052:
	/* 0x2052: mov    WORD PTR [r15+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_205a:
	/* 0x205a: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2061:
	/* 0x2061: mov    rbx,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_2068:
	/* 0x2068: lea    r13,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_206c:
	/* 0x206c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_206f:
	/* 0x206f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2074:
	/* 0x2074: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2079:
	/* 0x2079: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_207e:
	/* 0x207e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2081:
	/* 0x2081: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2083:
	/* 0x2083: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2087:
	/* 0x2087: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_208f:
	/* 0x208f: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2093:
	/* 0x2093: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2096:
	/* 0x2096: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_209b:
	/* 0x209b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20a0:
	/* 0x20a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20a5:
	/* 0x20a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a7:
	/* 0x20a7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ab:
	/* 0x20ab: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_20af:
	/* 0x20af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20b2:
	/* 0x20b2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20b7:
	/* 0x20b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20bc:
	/* 0x20bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20c1:
	/* 0x20c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c3:
	/* 0x20c3: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20c7:
	/* 0x20c7: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20cc:
	/* 0x20cc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20cf:
	/* 0x20cf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_20d4:
	/* 0x20d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20d9:
	/* 0x20d9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20de:
	/* 0x20de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e0:
	/* 0x20e0: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e3:
	/* 0x20e3: mov    DWORD PTR [r15+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_20e7:
	/* 0x20e7: lea    rbp,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20eb:
	/* 0x20eb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20ee:
	/* 0x20ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20f3:
	/* 0x20f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20f8:
	/* 0x20f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20fd:
	/* 0x20fd: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2100:
	/* 0x2100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2102:
	/* 0x2102: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2106:
	/* 0x2106: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2109:
	/* 0x2109: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_210e:
	/* 0x210e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2113:
	/* 0x2113: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2118:
	/* 0x2118: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_211b:
	/* 0x211b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211d:
	/* 0x211d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2120:
	/* 0x2120: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2124:
	/* 0x2124: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2128:
	/* 0x2128: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_212c:
	/* 0x212c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_212f:
	/* 0x212f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2134:
	/* 0x2134: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2139:
	/* 0x2139: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_213e:
	/* 0x213e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2140:
	/* 0x2140: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2143:
	/* 0x2143: mov    DWORD PTR [r15+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2147:
	/* 0x2147: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_214a:
	/* 0x214a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_214f:
	/* 0x214f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2154:
	/* 0x2154: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2159:
	/* 0x2159: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_215c:
	/* 0x215c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_215e:
	/* 0x215e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2162:
	/* 0x2162: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2166:
	/* 0x2166: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2169:
	/* 0x2169: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_216e:
	/* 0x216e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2173:
	/* 0x2173: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2178:
	/* 0x2178: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217a:
	/* 0x217a: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_217e:
	/* 0x217e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2181:
	/* 0x2181: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2186:
	/* 0x2186: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_218b:
	/* 0x218b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2190:
	/* 0x2190: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2193:
	/* 0x2193: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2195:
	/* 0x2195: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2198:
	/* 0x2198: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_219c:
	/* 0x219c: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_21a0:
	/* 0x21a0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_21a4:
	/* 0x21a4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21a7:
	/* 0x21a7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_21ac:
	/* 0x21ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21b1:
	/* 0x21b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21b6:
	/* 0x21b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b8:
	/* 0x21b8: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21bb:
	/* 0x21bb: mov    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21bf:
	/* 0x21bf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21c2:
	/* 0x21c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21c7:
	/* 0x21c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21cc:
	/* 0x21cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21d1:
	/* 0x21d1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
	return 8660ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8660ULL: goto x86_l_21d4;
	case 8662ULL: goto x86_l_21d6;
	case 8666ULL: goto x86_l_21da;
	case 8669ULL: goto x86_l_21dd;
	case 8674ULL: goto x86_l_21e2;
	case 8679ULL: goto x86_l_21e7;
	case 8684ULL: goto x86_l_21ec;
	case 8687ULL: goto x86_l_21ef;
	case 8689ULL: goto x86_l_21f1;
	case 8692ULL: goto x86_l_21f4;
	case 8696ULL: goto x86_l_21f8;
	case 8700ULL: goto x86_l_21fc;
	case 8704ULL: goto x86_l_2200;
	case 8707ULL: goto x86_l_2203;
	case 8712ULL: goto x86_l_2208;
	case 8717ULL: goto x86_l_220d;
	case 8722ULL: goto x86_l_2212;
	case 8724ULL: goto x86_l_2214;
	case 8728ULL: goto x86_l_2218;
	case 8732ULL: goto x86_l_221c;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8752ULL: goto x86_l_2230;
	case 8755ULL: goto x86_l_2233;
	case 8760ULL: goto x86_l_2238;
	case 8763ULL: goto x86_l_223b;
	case 8768ULL: goto x86_l_2240;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8783ULL: goto x86_l_224f;
	case 8787ULL: goto x86_l_2253;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8800ULL: goto x86_l_2260;
	case 8805ULL: goto x86_l_2265;
	case 8808ULL: goto x86_l_2268;
	case 8810ULL: goto x86_l_226a;
	case 8813ULL: goto x86_l_226d;
	case 8817ULL: goto x86_l_2271;
	case 8821ULL: goto x86_l_2275;
	case 8825ULL: goto x86_l_2279;
	case 8828ULL: goto x86_l_227c;
	case 8833ULL: goto x86_l_2281;
	case 8838ULL: goto x86_l_2286;
	case 8843ULL: goto x86_l_228b;
	case 8845ULL: goto x86_l_228d;
	case 8849ULL: goto x86_l_2291;
	case 8853ULL: goto x86_l_2295;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8866ULL: goto x86_l_22a2;
	case 8871ULL: goto x86_l_22a7;
	case 8873ULL: goto x86_l_22a9;
	case 8876ULL: goto x86_l_22ac;
	case 8878ULL: goto x86_l_22ae;
	case 8881ULL: goto x86_l_22b1;
	case 8886ULL: goto x86_l_22b6;
	case 8891ULL: goto x86_l_22bb;
	case 8896ULL: goto x86_l_22c0;
	case 8899ULL: goto x86_l_22c3;
	case 8901ULL: goto x86_l_22c5;
	case 8905ULL: goto x86_l_22c9;
	case 8908ULL: goto x86_l_22cc;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8926ULL: goto x86_l_22de;
	case 8928ULL: goto x86_l_22e0;
	case 8931ULL: goto x86_l_22e3;
	case 8935ULL: goto x86_l_22e7;
	case 8939ULL: goto x86_l_22eb;
	case 8943ULL: goto x86_l_22ef;
	case 8946ULL: goto x86_l_22f2;
	case 8951ULL: goto x86_l_22f7;
	case 8956ULL: goto x86_l_22fc;
	case 8961ULL: goto x86_l_2301;
	case 8963ULL: goto x86_l_2303;
	case 8966ULL: goto x86_l_2306;
	case 8970ULL: goto x86_l_230a;
	case 8974ULL: goto x86_l_230e;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 8999ULL: goto x86_l_2327;
	case 9002ULL: goto x86_l_232a;
	case 9004ULL: goto x86_l_232c;
	case 9008ULL: goto x86_l_2330;
	case 9012ULL: goto x86_l_2334;
	case 9015ULL: goto x86_l_2337;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9030ULL: goto x86_l_2346;
	case 9032ULL: goto x86_l_2348;
	case 9036ULL: goto x86_l_234c;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9062ULL: goto x86_l_2366;
	case 9066ULL: goto x86_l_236a;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9077ULL: goto x86_l_2375;
	case 9081ULL: goto x86_l_2379;
	case 9085ULL: goto x86_l_237d;
	case 9088ULL: goto x86_l_2380;
	case 9093ULL: goto x86_l_2385;
	case 9098ULL: goto x86_l_238a;
	case 9103ULL: goto x86_l_238f;
	case 9105ULL: goto x86_l_2391;
	case 9109ULL: goto x86_l_2395;
	case 9113ULL: goto x86_l_2399;
	case 9121ULL: goto x86_l_23a1;
	case 9125ULL: goto x86_l_23a5;
	case 9128ULL: goto x86_l_23a8;
	case 9133ULL: goto x86_l_23ad;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	case 9145ULL: goto x86_l_23b9;
	case 9149ULL: goto x86_l_23bd;
	case 9153ULL: goto x86_l_23c1;
	case 9157ULL: goto x86_l_23c5;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9170ULL: goto x86_l_23d2;
	case 9175ULL: goto x86_l_23d7;
	case 9178ULL: goto x86_l_23da;
	case 9180ULL: goto x86_l_23dc;
	case 9184ULL: goto x86_l_23e0;
	case 9188ULL: goto x86_l_23e4;
	case 9191ULL: goto x86_l_23e7;
	case 9196ULL: goto x86_l_23ec;
	case 9201ULL: goto x86_l_23f1;
	case 9206ULL: goto x86_l_23f6;
	case 9209ULL: goto x86_l_23f9;
	case 9211ULL: goto x86_l_23fb;
	case 9215ULL: goto x86_l_23ff;
	case 9217ULL: goto x86_l_2401;
	case 9222ULL: goto x86_l_2406;
	case 9230ULL: goto x86_l_240e;
	case 9234ULL: goto x86_l_2412;
	case 9242ULL: goto x86_l_241a;
	case 9247ULL: goto x86_l_241f;
	case 9252ULL: goto x86_l_2424;
	case 9257ULL: goto x86_l_2429;
	case 9259ULL: goto x86_l_242b;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9272ULL: goto x86_l_2438;
	case 9277ULL: goto x86_l_243d;
	case 9280ULL: goto x86_l_2440;
	case 9282ULL: goto x86_l_2442;
	case 9286ULL: goto x86_l_2446;
	case 9289ULL: goto x86_l_2449;
	case 9294ULL: goto x86_l_244e;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9306ULL: goto x86_l_245a;
	case 9310ULL: goto x86_l_245e;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9323ULL: goto x86_l_246b;
	case 9326ULL: goto x86_l_246e;
	case 9331ULL: goto x86_l_2473;
	case 9333ULL: goto x86_l_2475;
	case 9337ULL: goto x86_l_2479;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9358ULL: goto x86_l_248e;
	case 9360ULL: goto x86_l_2490;
	case 9368ULL: goto x86_l_2498;
	case 9376ULL: goto x86_l_24a0;
	case 9380ULL: goto x86_l_24a4;
	case 9385ULL: goto x86_l_24a9;
	case 9390ULL: goto x86_l_24ae;
	case 9395ULL: goto x86_l_24b3;
	case 9397ULL: goto x86_l_24b5;
	case 9405ULL: goto x86_l_24bd;
	case 9413ULL: goto x86_l_24c5;
	case 9417ULL: goto x86_l_24c9;
	case 9419ULL: goto x86_l_24cb;
	case 9426ULL: goto x86_l_24d2;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9444ULL: goto x86_l_24e4;
	case 9446ULL: goto x86_l_24e6;
	case 9448ULL: goto x86_l_24e8;
	case 9450ULL: goto x86_l_24ea;
	case 9453ULL: goto x86_l_24ed;
	case 9460ULL: goto x86_l_24f4;
	case 9465ULL: goto x86_l_24f9;
	case 9470ULL: goto x86_l_24fe;
	case 9473ULL: goto x86_l_2501;
	case 9479ULL: goto x86_l_2507;
	case 9483ULL: goto x86_l_250b;
	case 9490ULL: goto x86_l_2512;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9505ULL: goto x86_l_2521;
	case 9508ULL: goto x86_l_2524;
	case 9511ULL: goto x86_l_2527;
	case 9513ULL: goto x86_l_2529;
	case 9515ULL: goto x86_l_252b;
	case 9522ULL: goto x86_l_2532;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9541ULL: goto x86_l_2545;
	case 9543ULL: goto x86_l_2547;
	case 9546ULL: goto x86_l_254a;
	case 9548ULL: goto x86_l_254c;
	case 9553ULL: goto x86_l_2551;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9564ULL: goto x86_l_255c;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9580ULL: goto x86_l_256c;
	case 9582ULL: goto x86_l_256e;
	case 9584ULL: goto x86_l_2570;
	case 9586ULL: goto x86_l_2572;
	case 9588ULL: goto x86_l_2574;
	case 9589ULL: goto x86_l_2575;
	case 9593ULL: goto x86_l_2579;
	case 9596ULL: goto x86_l_257c;
	case 9599ULL: goto x86_l_257f;
	case 9603ULL: goto x86_l_2583;
	case 9612ULL: goto x86_l_258c;
	case 9619ULL: goto x86_l_2593;
	case 9630ULL: goto x86_l_259e;
	case 9641ULL: goto x86_l_25a9;
	case 9652ULL: goto x86_l_25b4;
	case 9663ULL: goto x86_l_25bf;
	case 9674ULL: goto x86_l_25ca;
	case 9685ULL: goto x86_l_25d5;
	case 9696ULL: goto x86_l_25e0;
	case 9707ULL: goto x86_l_25eb;
	case 9712ULL: goto x86_l_25f0;
	case 9715ULL: goto x86_l_25f3;
	case 9719ULL: goto x86_l_25f7;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9739ULL: goto x86_l_260b;
	case 9743ULL: goto x86_l_260f;
	case 9747ULL: goto x86_l_2613;
	case 9755ULL: goto x86_l_261b;
	case 9762ULL: goto x86_l_2622;
	case 9764ULL: goto x86_l_2624;
	case 9773ULL: goto x86_l_262d;
	case 9779ULL: goto x86_l_2633;
	case 9781ULL: goto x86_l_2635;
	case 9789ULL: goto x86_l_263d;
	case 9792ULL: goto x86_l_2640;
	case 9797ULL: goto x86_l_2645;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9814ULL: goto x86_l_2656;
	case 9817ULL: goto x86_l_2659;
	case 9819ULL: goto x86_l_265b;
	case 9822ULL: goto x86_l_265e;
	case 9830ULL: goto x86_l_2666;
	case 9837ULL: goto x86_l_266d;
	case 9841ULL: goto x86_l_2671;
	case 9848ULL: goto x86_l_2678;
	case 9856ULL: goto x86_l_2680;
	case 9863ULL: goto x86_l_2687;
	case 9869ULL: goto x86_l_268d;
	case 9878ULL: goto x86_l_2696;
	case 9886ULL: goto x86_l_269e;
	case 9889ULL: goto x86_l_26a1;
	case 9892ULL: goto x86_l_26a4;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9907ULL: goto x86_l_26b3;
	case 9909ULL: goto x86_l_26b5;
	case 9912ULL: goto x86_l_26b8;
	case 9914ULL: goto x86_l_26ba;
	case 9918ULL: goto x86_l_26be;
	case 9921ULL: goto x86_l_26c1;
	case 9926ULL: goto x86_l_26c6;
	case 9928ULL: goto x86_l_26c8;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9948ULL: goto x86_l_26dc;
	case 9951ULL: goto x86_l_26df;
	case 9953ULL: goto x86_l_26e1;
	case 9958ULL: goto x86_l_26e6;
	case 9961ULL: goto x86_l_26e9;
	case 9964ULL: goto x86_l_26ec;
	case 9966ULL: goto x86_l_26ee;
	case 9969ULL: goto x86_l_26f1;
	case 9971ULL: goto x86_l_26f3;
	case 9975ULL: goto x86_l_26f7;
	case 9978ULL: goto x86_l_26fa;
	case 9986ULL: goto x86_l_2702;
	case 9993ULL: goto x86_l_2709;
	case 9997ULL: goto x86_l_270d;
	case 10006ULL: goto x86_l_2716;
	case 10013ULL: goto x86_l_271d;
	case 10015ULL: goto x86_l_271f;
	case 10024ULL: goto x86_l_2728;
	case 10031ULL: goto x86_l_272f;
	case 10033ULL: goto x86_l_2731;
	case 10037ULL: goto x86_l_2735;
	case 10044ULL: goto x86_l_273c;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10059ULL: goto x86_l_274b;
	case 10062ULL: goto x86_l_274e;
	case 10064ULL: goto x86_l_2750;
	case 10067ULL: goto x86_l_2753;
	case 10069ULL: goto x86_l_2755;
	case 10073ULL: goto x86_l_2759;
	case 10082ULL: goto x86_l_2762;
	case 10090ULL: goto x86_l_276a;
	case 10094ULL: goto x86_l_276e;
	case 10101ULL: goto x86_l_2775;
	case 10109ULL: goto x86_l_277d;
	case 10116ULL: goto x86_l_2784;
	case 10118ULL: goto x86_l_2786;
	case 10127ULL: goto x86_l_278f;
	case 10131ULL: goto x86_l_2793;
	case 10138ULL: goto x86_l_279a;
	case 10141ULL: goto x86_l_279d;
	case 10146ULL: goto x86_l_27a2;
	case 10151ULL: goto x86_l_27a7;
	case 10156ULL: goto x86_l_27ac;
	case 10158ULL: goto x86_l_27ae;
	case 10161ULL: goto x86_l_27b1;
	case 10163ULL: goto x86_l_27b3;
	case 10166ULL: goto x86_l_27b6;
	case 10171ULL: goto x86_l_27bb;
	case 10173ULL: goto x86_l_27bd;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10189ULL: goto x86_l_27cd;
	case 10196ULL: goto x86_l_27d4;
	case 10198ULL: goto x86_l_27d6;
	case 10203ULL: goto x86_l_27db;
	case 10206ULL: goto x86_l_27de;
	case 10209ULL: goto x86_l_27e1;
	case 10211ULL: goto x86_l_27e3;
	case 10214ULL: goto x86_l_27e6;
	case 10216ULL: goto x86_l_27e8;
	case 10220ULL: goto x86_l_27ec;
	case 10224ULL: goto x86_l_27f0;
	case 10232ULL: goto x86_l_27f8;
	case 10239ULL: goto x86_l_27ff;
	case 10243ULL: goto x86_l_2803;
	case 10250ULL: goto x86_l_280a;
	case 10254ULL: goto x86_l_280e;
	case 10257ULL: goto x86_l_2811;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10272ULL: goto x86_l_2820;
	case 10275ULL: goto x86_l_2823;
	case 10277ULL: goto x86_l_2825;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10290ULL: goto x86_l_2832;
	case 10293ULL: goto x86_l_2835;
	case 10298ULL: goto x86_l_283a;
	case 10303ULL: goto x86_l_283f;
	case 10308ULL: goto x86_l_2844;
	case 10310ULL: goto x86_l_2846;
	case 10314ULL: goto x86_l_284a;
	case 10318ULL: goto x86_l_284e;
	case 10321ULL: goto x86_l_2851;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10336ULL: goto x86_l_2860;
	default: return 0xffffffffffffffffULL;
	}
x86_l_21d4:
	/* 0x21d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d6:
	/* 0x21d6: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21da:
	/* 0x21da: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21dd:
	/* 0x21dd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_21e2:
	/* 0x21e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21e7:
	/* 0x21e7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21ec:
	/* 0x21ec: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_21ef:
	/* 0x21ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f1:
	/* 0x21f1: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21f4:
	/* 0x21f4: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_21f8:
	/* 0x21f8: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_21fc:
	/* 0x21fc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2200:
	/* 0x2200: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2203:
	/* 0x2203: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2208:
	/* 0x2208: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_220d:
	/* 0x220d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2212:
	/* 0x2212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2214:
	/* 0x2214: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2218:
	/* 0x2218: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_221c:
	/* 0x221c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_221f:
	/* 0x221f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2224:
	/* 0x2224: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2229:
	/* 0x2229: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_222e:
	/* 0x222e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2230:
	/* 0x2230: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2233:
	/* 0x2233: lea    r13,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2238:
	/* 0x2238: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_223b:
	/* 0x223b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2240:
	/* 0x2240: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2245:
	/* 0x2245: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_224a:
	/* 0x224a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_224d:
	/* 0x224d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_224f:
	/* 0x224f: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2253:
	/* 0x2253: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2256:
	/* 0x2256: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_225b:
	/* 0x225b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2260:
	/* 0x2260: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2265:
	/* 0x2265: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2268:
	/* 0x2268: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226a:
	/* 0x226a: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226d:
	/* 0x226d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2271:
	/* 0x2271: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2275:
	/* 0x2275: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2279:
	/* 0x2279: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_227c:
	/* 0x227c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2281:
	/* 0x2281: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2286:
	/* 0x2286: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_228b:
	/* 0x228b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228d:
	/* 0x228d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2291:
	/* 0x2291: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2295:
	/* 0x2295: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2298:
	/* 0x2298: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_229d:
	/* 0x229d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22a2:
	/* 0x22a2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22a7:
	/* 0x22a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a9:
	/* 0x22a9: cmp    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_22ac:
	/* 0x22ac: jne    230a <trace_ret_do_init_module+0x230a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_230a;
	}
x86_l_22ae:
	/* 0x22ae: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22b1:
	/* 0x22b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22b6:
	/* 0x22b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22bb:
	/* 0x22bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22c0:
	/* 0x22c0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_22c3:
	/* 0x22c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c5:
	/* 0x22c5: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c9:
	/* 0x22c9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22cc:
	/* 0x22cc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22d1:
	/* 0x22d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22d6:
	/* 0x22d6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22db:
	/* 0x22db: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_22de:
	/* 0x22de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e0:
	/* 0x22e0: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e3:
	/* 0x22e3: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_22e7:
	/* 0x22e7: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_22eb:
	/* 0x22eb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22ef:
	/* 0x22ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22f2:
	/* 0x22f2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22f7:
	/* 0x22f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22fc:
	/* 0x22fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2301:
	/* 0x2301: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2303:
	/* 0x2303: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2306:
	/* 0x2306: mov    DWORD PTR [r15+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_230a:
	/* 0x230a: mov    DWORD PTR [r15+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_230e:
	/* 0x230e: lea    r13,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2315:
	/* 0x2315: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2318:
	/* 0x2318: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_231d:
	/* 0x231d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2322:
	/* 0x2322: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2327:
	/* 0x2327: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_232a:
	/* 0x232a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_232c:
	/* 0x232c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2330:
	/* 0x2330: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2334:
	/* 0x2334: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2337:
	/* 0x2337: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_233c:
	/* 0x233c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2341:
	/* 0x2341: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2346:
	/* 0x2346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2348:
	/* 0x2348: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_234c:
	/* 0x234c: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2351:
	/* 0x2351: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2356:
	/* 0x2356: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_235b:
	/* 0x235b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_235f:
	/* 0x235f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2364:
	/* 0x2364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2366:
	/* 0x2366: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_236a:
	/* 0x236a: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_236e:
	/* 0x236e: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2373:
	/* 0x2373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2375:
	/* 0x2375: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2379:
	/* 0x2379: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_237d:
	/* 0x237d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2380:
	/* 0x2380: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2385:
	/* 0x2385: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_238a:
	/* 0x238a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_238f:
	/* 0x238f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2391:
	/* 0x2391: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2395:
	/* 0x2395: mov    QWORD PTR [r15+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2399:
	/* 0x2399: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_23a1:
	/* 0x23a1: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_23a5:
	/* 0x23a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23a8:
	/* 0x23a8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23ad:
	/* 0x23ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23b2:
	/* 0x23b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b7:
	/* 0x23b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b9:
	/* 0x23b9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23bd:
	/* 0x23bd: mov    QWORD PTR [r15+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23c1:
	/* 0x23c1: add    r12,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_23c5:
	/* 0x23c5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23c8:
	/* 0x23c8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23cd:
	/* 0x23cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23d2:
	/* 0x23d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23d7:
	/* 0x23d7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_23da:
	/* 0x23da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23dc:
	/* 0x23dc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e0:
	/* 0x23e0: mov    QWORD PTR [r15+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_23e4:
	/* 0x23e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23e7:
	/* 0x23e7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_23ec:
	/* 0x23ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23f1:
	/* 0x23f1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23f6:
	/* 0x23f6: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_23f9:
	/* 0x23f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23fb:
	/* 0x23fb: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_23ff:
	/* 0x23ff: je     2406 <trace_ret_do_init_module+0x2406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2406;
	}
x86_l_2401:
	/* 0x2401: or     BYTE PTR [r15+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_2406:
	/* 0x2406: mov    QWORD PTR [r15+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_240e:
	/* 0x240e: lea    rdi,[r15+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2412:
	/* 0x2412: mov    QWORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_241a:
	/* 0x241a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_241f:
	/* 0x241f: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2424:
	/* 0x2424: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2429:
	/* 0x2429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242b:
	/* 0x242b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_242e:
	/* 0x242e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2433:
	/* 0x2433: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2438:
	/* 0x2438: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_243d:
	/* 0x243d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2440:
	/* 0x2440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2442:
	/* 0x2442: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2446:
	/* 0x2446: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2449:
	/* 0x2449: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_244e:
	/* 0x244e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2453:
	/* 0x2453: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2458:
	/* 0x2458: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_245a:
	/* 0x245a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_245e:
	/* 0x245e: mov    rbx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSP, X86_WIDTH_64);
x86_l_2461:
	/* 0x2461: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_2466:
	/* 0x2466: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_246b:
	/* 0x246b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_246e:
	/* 0x246e: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2473:
	/* 0x2473: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2475:
	/* 0x2475: add    r15,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_2479:
	/* 0x2479: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_247e:
	/* 0x247e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2483:
	/* 0x2483: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2486:
	/* 0x2486: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_248b:
	/* 0x248b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_248e:
	/* 0x248e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2490:
	/* 0x2490: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2498:
	/* 0x2498: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_24a0:
	/* 0x24a0: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a4:
	/* 0x24a4: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_24a9:
	/* 0x24a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24ae:
	/* 0x24ae: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_24b3:
	/* 0x24b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b5:
	/* 0x24b5: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_24bd:
	/* 0x24bd: mov    r14,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_24c5:
	/* 0x24c5: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_24c9:
	/* 0x24c9: je     24ed <trace_ret_do_init_module+0x24ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ed;
	}
x86_l_24cb:
	/* 0x24cb: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_24d2:
	/* 0x24d2: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_24d7:
	/* 0x24d7: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_24dc:
	/* 0x24dc: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_24e1:
	/* 0x24e1: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_24e4:
	/* 0x24e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e6:
	/* 0x24e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24e8:
	/* 0x24e8: js     24ed <trace_ret_do_init_module+0x24ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24ed;
	}
x86_l_24ea:
	/* 0x24ea: mov    DWORD PTR [rbx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_24ed:
	/* 0x24ed: movzx  eax,WORD PTR [rbx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24f4:
	/* 0x24f4: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_24f9:
	/* 0x24f9: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_24fe:
	/* 0x24fe: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2501:
	/* 0x2501: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_2507:
	/* 0x2507: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_250b:
	/* 0x250b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_2512:
	/* 0x2512: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2517:
	/* 0x2517: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_251c:
	/* 0x251c: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2521:
	/* 0x2521: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2524:
	/* 0x2524: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2527:
	/* 0x2527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2529:
	/* 0x2529: jmp    255c <trace_ret_do_init_module+0x255c> */
	goto x86_l_255c;
x86_l_252b:
	/* 0x252b: lea    rdi,[rbx+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_2532:
	/* 0x2532: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2536:
	/* 0x2536: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_253b:
	/* 0x253b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2540:
	/* 0x2540: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2545:
	/* 0x2545: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2547:
	/* 0x2547: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_254a:
	/* 0x254a: jne    255a <trace_ret_do_init_module+0x255a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_255a;
	}
x86_l_254c:
	/* 0x254c: movzx  eax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2551:
	/* 0x2551: mov    WORD PTR [rbx+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_2555:
	/* 0x2555: jmp    c3d <trace_ret_do_init_module+0xc3d> */
	return 3133ULL;
x86_l_255a:
	/* 0x255a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_255c:
	/* 0x255c: add    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_2563:
	/* 0x2563: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2565:
	/* 0x2565: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2566:
	/* 0x2566: jmp    2cde <lkm_seeker_send_to_userspace+0x773> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_256b:
	/* 0x256b: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_256c:
	/* 0x256c: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_256e:
	/* 0x256e: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2570:
	/* 0x2570: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_2572:
	/* 0x2572: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2574:
	/* 0x2574: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2575:
	/* 0x2575: sub    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 104ULL);
x86_l_2579:
	/* 0x2579: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_257c:
	/* 0x257c: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_257f:
	/* 0x257f: mov    rax,QWORD PTR [rdx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2583:
	/* 0x2583: mov    WORD PTR [rax+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_258c:
	/* 0x258c: mov    BYTE PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_2593:
	/* 0x2593: mov    QWORD PTR [rax+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_259e:
	/* 0x259e: mov    QWORD PTR [rax+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_25a9:
	/* 0x25a9: mov    QWORD PTR [rax+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_25b4:
	/* 0x25b4: mov    QWORD PTR [rax+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_25bf:
	/* 0x25bf: mov    QWORD PTR [rax+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_25ca:
	/* 0x25ca: mov    QWORD PTR [rax+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_25d5:
	/* 0x25d5: mov    QWORD PTR [rax+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_25e0:
	/* 0x25e0: mov    QWORD PTR [rax+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_25eb:
	/* 0x25eb: mov    QWORD PTR [rsp+0x60],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25f0:
	/* 0x25f0: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_25f3:
	/* 0x25f3: lea    rdx,[rdi+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25f7:
	/* 0x25f7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_25fa:
	/* 0x25fa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25ff:
	/* 0x25ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2604:
	/* 0x2604: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2609:
	/* 0x2609: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260b:
	/* 0x260b: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_260f:
	/* 0x260f: mov    r13,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2613:
	/* 0x2613: movzx  ebp,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_261b:
	/* 0x261b: cmp    rbp,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 31999ULL);
x86_l_2622:
	/* 0x2622: ja     266d <lkm_seeker_send_to_userspace+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_266d;
	}
x86_l_2624:
	/* 0x2624: mov    BYTE PTR [r13+rbp*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 588410519552ULL);
x86_l_262d:
	/* 0x262d: cmp    ebp,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 31991ULL);
x86_l_2633:
	/* 0x2633: ja     266d <lkm_seeker_send_to_userspace+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_266d;
	}
x86_l_2635:
	/* 0x2635: lea    rdi,[r13*1+0x8a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 138ULL);
x86_l_263d:
	/* 0x263d: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2640:
	/* 0x2640: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2645:
	/* 0x2645: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_264a:
	/* 0x264a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_264f:
	/* 0x264f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2654:
	/* 0x2654: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2656:
	/* 0x2656: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2659:
	/* 0x2659: js     266d <lkm_seeker_send_to_userspace+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_266d;
	}
x86_l_265b:
	/* 0x265b: add    ebp,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_265e:
	/* 0x265e: mov    WORD PTR [r13+0x7d8a],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2666:
	/* 0x2666: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_266d:
	/* 0x266d: mov    r13,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2671:
	/* 0x2671: mov    DWORD PTR [rsp],0x38 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2678:
	/* 0x2678: movzx  ebp,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2680:
	/* 0x2680: cmp    rbp,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 27899ULL);
x86_l_2687:
	/* 0x2687: ja     2709 <lkm_seeker_send_to_userspace+0x19e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2709;
	}
x86_l_268d:
	/* 0x268d: mov    BYTE PTR [r13+rbp*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 588410519553ULL);
x86_l_2696:
	/* 0x2696: lea    rdi,[rbp*1+0x8a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 138ULL);
x86_l_269e:
	/* 0x269e: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26a1:
	/* 0x26a1: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_26a4:
	/* 0x26a4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_26a9:
	/* 0x26a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26ae:
	/* 0x26ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26b3:
	/* 0x26b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b5:
	/* 0x26b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26b8:
	/* 0x26b8: jne    2709 <lkm_seeker_send_to_userspace+0x19e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2709;
	}
x86_l_26ba:
	/* 0x26ba: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26be:
	/* 0x26be: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26c1:
	/* 0x26c1: cmp    eax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4096ULL);
x86_l_26c6:
	/* 0x26c6: jb     26d4 <lkm_seeker_send_to_userspace+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_26d4;
	}
x86_l_26c8:
	/* 0x26c8: mov    DWORD PTR [rsp],0xfff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4095ULL);
x86_l_26cf:
	/* 0x26cf: mov    eax,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4095ULL);
x86_l_26d4:
	/* 0x26d4: lea    rdi,[rbp*1+0x8e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 142ULL);
x86_l_26dc:
	/* 0x26dc: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26df:
	/* 0x26df: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_26e1:
	/* 0x26e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26e6:
	/* 0x26e6: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26e9:
	/* 0x26e9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_26ec:
	/* 0x26ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ee:
	/* 0x26ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26f1:
	/* 0x26f1: jne    2709 <lkm_seeker_send_to_userspace+0x19e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2709;
	}
x86_l_26f3:
	/* 0x26f3: add    rbp,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_26f7:
	/* 0x26f7: add    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26fa:
	/* 0x26fa: mov    WORD PTR [r13+0x7d8a],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2702:
	/* 0x2702: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2709:
	/* 0x2709: mov    r12,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_270d:
	/* 0x270d: movzx  r13d,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2716:
	/* 0x2716: cmp    r13,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31999ULL);
x86_l_271d:
	/* 0x271d: ja     276a <lkm_seeker_send_to_userspace+0x1ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_276a;
	}
x86_l_271f:
	/* 0x271f: mov    BYTE PTR [r12+r13*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R13, 0), 588410519554ULL);
x86_l_2728:
	/* 0x2728: cmp    r13d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31995ULL);
x86_l_272f:
	/* 0x272f: ja     276a <lkm_seeker_send_to_userspace+0x1ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_276a;
	}
x86_l_2731:
	/* 0x2731: lea    rdi,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2735:
	/* 0x2735: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_273c:
	/* 0x273c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2741:
	/* 0x2741: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2746:
	/* 0x2746: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_274b:
	/* 0x274b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_274e:
	/* 0x274e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2750:
	/* 0x2750: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2753:
	/* 0x2753: js     276a <lkm_seeker_send_to_userspace+0x1ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_276a;
	}
x86_l_2755:
	/* 0x2755: add    r13d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2759:
	/* 0x2759: mov    WORD PTR [r12+0x7d8a],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2762:
	/* 0x2762: inc    BYTE PTR [r12+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_276a:
	/* 0x276a: mov    r15,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_276e:
	/* 0x276e: mov    DWORD PTR [rsp],0x19 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_2775:
	/* 0x2775: movzx  r12d,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_277d:
	/* 0x277d: cmp    r12,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 27899ULL);
x86_l_2784:
	/* 0x2784: ja     27ff <lkm_seeker_send_to_userspace+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_27ff;
	}
x86_l_2786:
	/* 0x2786: mov    BYTE PTR [r15+r12*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R12, 0), 588410519555ULL);
x86_l_278f:
	/* 0x278f: lea    rdi,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2793:
	/* 0x2793: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_279a:
	/* 0x279a: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_279d:
	/* 0x279d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_27a2:
	/* 0x27a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27a7:
	/* 0x27a7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27ac:
	/* 0x27ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ae:
	/* 0x27ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27b1:
	/* 0x27b1: jne    27ff <lkm_seeker_send_to_userspace+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27ff;
	}
x86_l_27b3:
	/* 0x27b3: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b6:
	/* 0x27b6: cmp    eax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4096ULL);
x86_l_27bb:
	/* 0x27bb: jb     27c9 <lkm_seeker_send_to_userspace+0x25e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_27c9;
	}
x86_l_27bd:
	/* 0x27bd: mov    DWORD PTR [rsp],0xfff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4095ULL);
x86_l_27c4:
	/* 0x27c4: mov    eax,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4095ULL);
x86_l_27c9:
	/* 0x27c9: lea    rdi,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_27cd:
	/* 0x27cd: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_27d4:
	/* 0x27d4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_27d6:
	/* 0x27d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27db:
	/* 0x27db: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27de:
	/* 0x27de: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_27e1:
	/* 0x27e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e3:
	/* 0x27e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27e6:
	/* 0x27e6: jne    27ff <lkm_seeker_send_to_userspace+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27ff;
	}
x86_l_27e8:
	/* 0x27e8: add    r12,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_27ec:
	/* 0x27ec: add    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27f0:
	/* 0x27f0: mov    WORD PTR [r15+0x7d8a],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_27f8:
	/* 0x27f8: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_27ff:
	/* 0x27ff: mov    r14,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2803:
	/* 0x2803: mov    r15,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_280a:
	/* 0x280a: lea    rbp,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_280e:
	/* 0x280e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2811:
	/* 0x2811: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2816:
	/* 0x2816: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_281b:
	/* 0x281b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2820:
	/* 0x2820: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2823:
	/* 0x2823: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2825:
	/* 0x2825: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2829:
	/* 0x2829: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_282e:
	/* 0x282e: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2832:
	/* 0x2832: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2835:
	/* 0x2835: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_283a:
	/* 0x283a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_283f:
	/* 0x283f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2844:
	/* 0x2844: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2846:
	/* 0x2846: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_284a:
	/* 0x284a: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_284e:
	/* 0x284e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2851:
	/* 0x2851: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2856:
	/* 0x2856: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_285b:
	/* 0x285b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2860:
	/* 0x2860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 10338ULL;
}

static __noinline __u64 tracee_trace_ret_do_init_module_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10338ULL: goto x86_l_2862;
	case 10342ULL: goto x86_l_2866;
	case 10346ULL: goto x86_l_286a;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10364ULL: goto x86_l_287c;
	case 10366ULL: goto x86_l_287e;
	case 10369ULL: goto x86_l_2881;
	case 10373ULL: goto x86_l_2885;
	case 10378ULL: goto x86_l_288a;
	case 10382ULL: goto x86_l_288e;
	case 10385ULL: goto x86_l_2891;
	case 10390ULL: goto x86_l_2896;
	case 10395ULL: goto x86_l_289b;
	case 10400ULL: goto x86_l_28a0;
	case 10403ULL: goto x86_l_28a3;
	case 10405ULL: goto x86_l_28a5;
	case 10409ULL: goto x86_l_28a9;
	case 10412ULL: goto x86_l_28ac;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10430ULL: goto x86_l_28be;
	case 10432ULL: goto x86_l_28c0;
	case 10435ULL: goto x86_l_28c3;
	case 10439ULL: goto x86_l_28c7;
	case 10443ULL: goto x86_l_28cb;
	case 10447ULL: goto x86_l_28cf;
	case 10450ULL: goto x86_l_28d2;
	case 10455ULL: goto x86_l_28d7;
	case 10460ULL: goto x86_l_28dc;
	case 10465ULL: goto x86_l_28e1;
	case 10467ULL: goto x86_l_28e3;
	case 10470ULL: goto x86_l_28e6;
	case 10474ULL: goto x86_l_28ea;
	case 10477ULL: goto x86_l_28ed;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10492ULL: goto x86_l_28fc;
	case 10495ULL: goto x86_l_28ff;
	case 10497ULL: goto x86_l_2901;
	case 10501ULL: goto x86_l_2905;
	case 10505ULL: goto x86_l_2909;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10518ULL: goto x86_l_2916;
	case 10523ULL: goto x86_l_291b;
	case 10525ULL: goto x86_l_291d;
	case 10529ULL: goto x86_l_2921;
	case 10532ULL: goto x86_l_2924;
	case 10537ULL: goto x86_l_2929;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10550ULL: goto x86_l_2936;
	case 10552ULL: goto x86_l_2938;
	case 10555ULL: goto x86_l_293b;
	case 10559ULL: goto x86_l_293f;
	case 10563ULL: goto x86_l_2943;
	case 10567ULL: goto x86_l_2947;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10585ULL: goto x86_l_2959;
	case 10587ULL: goto x86_l_295b;
	case 10590ULL: goto x86_l_295e;
	case 10594ULL: goto x86_l_2962;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10615ULL: goto x86_l_2977;
	case 10617ULL: goto x86_l_2979;
	case 10621ULL: goto x86_l_297d;
	case 10624ULL: goto x86_l_2980;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10639ULL: goto x86_l_298f;
	case 10642ULL: goto x86_l_2992;
	case 10644ULL: goto x86_l_2994;
	case 10647ULL: goto x86_l_2997;
	case 10651ULL: goto x86_l_299b;
	case 10655ULL: goto x86_l_299f;
	case 10659ULL: goto x86_l_29a3;
	case 10662ULL: goto x86_l_29a6;
	case 10667ULL: goto x86_l_29ab;
	case 10672ULL: goto x86_l_29b0;
	case 10677ULL: goto x86_l_29b5;
	case 10679ULL: goto x86_l_29b7;
	case 10683ULL: goto x86_l_29bb;
	case 10687ULL: goto x86_l_29bf;
	case 10690ULL: goto x86_l_29c2;
	case 10695ULL: goto x86_l_29c7;
	case 10700ULL: goto x86_l_29cc;
	case 10705ULL: goto x86_l_29d1;
	case 10707ULL: goto x86_l_29d3;
	case 10710ULL: goto x86_l_29d6;
	case 10714ULL: goto x86_l_29da;
	case 10717ULL: goto x86_l_29dd;
	case 10722ULL: goto x86_l_29e2;
	case 10727ULL: goto x86_l_29e7;
	case 10732ULL: goto x86_l_29ec;
	case 10735ULL: goto x86_l_29ef;
	case 10737ULL: goto x86_l_29f1;
	case 10741ULL: goto x86_l_29f5;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10762ULL: goto x86_l_2a0a;
	case 10764ULL: goto x86_l_2a0c;
	case 10767ULL: goto x86_l_2a0f;
	case 10771ULL: goto x86_l_2a13;
	case 10775ULL: goto x86_l_2a17;
	case 10779ULL: goto x86_l_2a1b;
	case 10782ULL: goto x86_l_2a1e;
	case 10787ULL: goto x86_l_2a23;
	case 10792ULL: goto x86_l_2a28;
	case 10797ULL: goto x86_l_2a2d;
	case 10799ULL: goto x86_l_2a2f;
	case 10803ULL: goto x86_l_2a33;
	case 10807ULL: goto x86_l_2a37;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10820ULL: goto x86_l_2a44;
	case 10825ULL: goto x86_l_2a49;
	case 10827ULL: goto x86_l_2a4b;
	case 10830ULL: goto x86_l_2a4e;
	case 10832ULL: goto x86_l_2a50;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10845ULL: goto x86_l_2a5d;
	case 10850ULL: goto x86_l_2a62;
	case 10853ULL: goto x86_l_2a65;
	case 10855ULL: goto x86_l_2a67;
	case 10859ULL: goto x86_l_2a6b;
	case 10862ULL: goto x86_l_2a6e;
	case 10867ULL: goto x86_l_2a73;
	case 10872ULL: goto x86_l_2a78;
	case 10877ULL: goto x86_l_2a7d;
	case 10880ULL: goto x86_l_2a80;
	case 10882ULL: goto x86_l_2a82;
	case 10885ULL: goto x86_l_2a85;
	case 10889ULL: goto x86_l_2a89;
	case 10893ULL: goto x86_l_2a8d;
	case 10897ULL: goto x86_l_2a91;
	case 10900ULL: goto x86_l_2a94;
	case 10905ULL: goto x86_l_2a99;
	case 10910ULL: goto x86_l_2a9e;
	case 10915ULL: goto x86_l_2aa3;
	case 10917ULL: goto x86_l_2aa5;
	case 10920ULL: goto x86_l_2aa8;
	case 10924ULL: goto x86_l_2aac;
	case 10928ULL: goto x86_l_2ab0;
	case 10933ULL: goto x86_l_2ab5;
	case 10940ULL: goto x86_l_2abc;
	case 10943ULL: goto x86_l_2abf;
	case 10948ULL: goto x86_l_2ac4;
	case 10953ULL: goto x86_l_2ac9;
	case 10958ULL: goto x86_l_2ace;
	case 10961ULL: goto x86_l_2ad1;
	case 10963ULL: goto x86_l_2ad3;
	case 10967ULL: goto x86_l_2ad7;
	case 10971ULL: goto x86_l_2adb;
	case 10974ULL: goto x86_l_2ade;
	case 10979ULL: goto x86_l_2ae3;
	case 10984ULL: goto x86_l_2ae8;
	case 10989ULL: goto x86_l_2aed;
	case 10991ULL: goto x86_l_2aef;
	case 10995ULL: goto x86_l_2af3;
	case 11000ULL: goto x86_l_2af8;
	case 11005ULL: goto x86_l_2afd;
	case 11010ULL: goto x86_l_2b02;
	case 11014ULL: goto x86_l_2b06;
	case 11019ULL: goto x86_l_2b0b;
	case 11021ULL: goto x86_l_2b0d;
	case 11025ULL: goto x86_l_2b11;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11036ULL: goto x86_l_2b1c;
	case 11040ULL: goto x86_l_2b20;
	case 11044ULL: goto x86_l_2b24;
	case 11047ULL: goto x86_l_2b27;
	case 11052ULL: goto x86_l_2b2c;
	case 11057ULL: goto x86_l_2b31;
	case 11062ULL: goto x86_l_2b36;
	case 11064ULL: goto x86_l_2b38;
	case 11068ULL: goto x86_l_2b3c;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11081ULL: goto x86_l_2b49;
	case 11084ULL: goto x86_l_2b4c;
	case 11089ULL: goto x86_l_2b51;
	case 11094ULL: goto x86_l_2b56;
	case 11099ULL: goto x86_l_2b5b;
	case 11101ULL: goto x86_l_2b5d;
	case 11105ULL: goto x86_l_2b61;
	case 11109ULL: goto x86_l_2b65;
	case 11113ULL: goto x86_l_2b69;
	case 11116ULL: goto x86_l_2b6c;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11134ULL: goto x86_l_2b7e;
	case 11136ULL: goto x86_l_2b80;
	case 11140ULL: goto x86_l_2b84;
	case 11144ULL: goto x86_l_2b88;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11157ULL: goto x86_l_2b95;
	case 11162ULL: goto x86_l_2b9a;
	case 11165ULL: goto x86_l_2b9d;
	case 11167ULL: goto x86_l_2b9f;
	case 11171ULL: goto x86_l_2ba3;
	case 11173ULL: goto x86_l_2ba5;
	case 11178ULL: goto x86_l_2baa;
	case 11186ULL: goto x86_l_2bb2;
	case 11190ULL: goto x86_l_2bb6;
	case 11198ULL: goto x86_l_2bbe;
	case 11203ULL: goto x86_l_2bc3;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11215ULL: goto x86_l_2bcf;
	case 11218ULL: goto x86_l_2bd2;
	case 11223ULL: goto x86_l_2bd7;
	case 11228ULL: goto x86_l_2bdc;
	case 11233ULL: goto x86_l_2be1;
	case 11236ULL: goto x86_l_2be4;
	case 11238ULL: goto x86_l_2be6;
	case 11242ULL: goto x86_l_2bea;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11255ULL: goto x86_l_2bf7;
	case 11260ULL: goto x86_l_2bfc;
	case 11262ULL: goto x86_l_2bfe;
	case 11266ULL: goto x86_l_2c02;
	case 11269ULL: goto x86_l_2c05;
	case 11274ULL: goto x86_l_2c0a;
	case 11279ULL: goto x86_l_2c0f;
	case 11282ULL: goto x86_l_2c12;
	case 11287ULL: goto x86_l_2c17;
	case 11289ULL: goto x86_l_2c19;
	case 11293ULL: goto x86_l_2c1d;
	case 11298ULL: goto x86_l_2c22;
	case 11303ULL: goto x86_l_2c27;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11314ULL: goto x86_l_2c32;
	case 11316ULL: goto x86_l_2c34;
	case 11320ULL: goto x86_l_2c38;
	case 11324ULL: goto x86_l_2c3c;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11342ULL: goto x86_l_2c4e;
	case 11346ULL: goto x86_l_2c52;
	case 11350ULL: goto x86_l_2c56;
	case 11355ULL: goto x86_l_2c5b;
	case 11357ULL: goto x86_l_2c5d;
	case 11360ULL: goto x86_l_2c60;
	case 11364ULL: goto x86_l_2c64;
	case 11366ULL: goto x86_l_2c66;
	case 11370ULL: goto x86_l_2c6a;
	case 11372ULL: goto x86_l_2c6c;
	case 11376ULL: goto x86_l_2c70;
	case 11383ULL: goto x86_l_2c77;
	case 11388ULL: goto x86_l_2c7c;
	case 11393ULL: goto x86_l_2c81;
	case 11397ULL: goto x86_l_2c85;
	case 11399ULL: goto x86_l_2c87;
	case 11403ULL: goto x86_l_2c8b;
	case 11405ULL: goto x86_l_2c8d;
	case 11407ULL: goto x86_l_2c8f;
	case 11410ULL: goto x86_l_2c92;
	case 11417ULL: goto x86_l_2c99;
	case 11422ULL: goto x86_l_2c9e;
	case 11427ULL: goto x86_l_2ca3;
	case 11430ULL: goto x86_l_2ca6;
	case 11436ULL: goto x86_l_2cac;
	case 11440ULL: goto x86_l_2cb0;
	case 11444ULL: goto x86_l_2cb4;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11461ULL: goto x86_l_2cc5;
	case 11465ULL: goto x86_l_2cc9;
	case 11469ULL: goto x86_l_2ccd;
	case 11471ULL: goto x86_l_2ccf;
	case 11475ULL: goto x86_l_2cd3;
	case 11476ULL: goto x86_l_2cd4;
	case 11478ULL: goto x86_l_2cd6;
	case 11480ULL: goto x86_l_2cd8;
	case 11482ULL: goto x86_l_2cda;
	case 11484ULL: goto x86_l_2cdc;
	case 11485ULL: goto x86_l_2cdd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2862:
	/* 0x2862: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2866:
	/* 0x2866: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_286a:
	/* 0x286a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_286d:
	/* 0x286d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2872:
	/* 0x2872: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2877:
	/* 0x2877: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_287c:
	/* 0x287c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287e:
	/* 0x287e: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2881:
	/* 0x2881: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2885:
	/* 0x2885: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_288a:
	/* 0x288a: lea    r12,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_288e:
	/* 0x288e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2891:
	/* 0x2891: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2896:
	/* 0x2896: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_289b:
	/* 0x289b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28a0:
	/* 0x28a0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_28a3:
	/* 0x28a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a5:
	/* 0x28a5: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a9:
	/* 0x28a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28ac:
	/* 0x28ac: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_28b1:
	/* 0x28b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28b6:
	/* 0x28b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28bb:
	/* 0x28bb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_28be:
	/* 0x28be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c0:
	/* 0x28c0: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28c3:
	/* 0x28c3: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_28c7:
	/* 0x28c7: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_28cb:
	/* 0x28cb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28cf:
	/* 0x28cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28d2:
	/* 0x28d2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_28d7:
	/* 0x28d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28dc:
	/* 0x28dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28e1:
	/* 0x28e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e3:
	/* 0x28e3: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e6:
	/* 0x28e6: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28ea:
	/* 0x28ea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28ed:
	/* 0x28ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28f2:
	/* 0x28f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28f7:
	/* 0x28f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28fc:
	/* 0x28fc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_28ff:
	/* 0x28ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2901:
	/* 0x2901: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2905:
	/* 0x2905: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2909:
	/* 0x2909: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_290c:
	/* 0x290c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2911:
	/* 0x2911: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2916:
	/* 0x2916: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_291b:
	/* 0x291b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291d:
	/* 0x291d: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2921:
	/* 0x2921: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2924:
	/* 0x2924: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2929:
	/* 0x2929: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_292e:
	/* 0x292e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2933:
	/* 0x2933: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2936:
	/* 0x2936: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2938:
	/* 0x2938: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_293b:
	/* 0x293b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_293f:
	/* 0x293f: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2943:
	/* 0x2943: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2947:
	/* 0x2947: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_294a:
	/* 0x294a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_294f:
	/* 0x294f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2954:
	/* 0x2954: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2959:
	/* 0x2959: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_295b:
	/* 0x295b: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295e:
	/* 0x295e: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2962:
	/* 0x2962: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2965:
	/* 0x2965: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_296a:
	/* 0x296a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_296f:
	/* 0x296f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2974:
	/* 0x2974: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2977:
	/* 0x2977: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2979:
	/* 0x2979: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297d:
	/* 0x297d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2980:
	/* 0x2980: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2985:
	/* 0x2985: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_298a:
	/* 0x298a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_298f:
	/* 0x298f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2992:
	/* 0x2992: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2994:
	/* 0x2994: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2997:
	/* 0x2997: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_299b:
	/* 0x299b: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_299f:
	/* 0x299f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29a3:
	/* 0x29a3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29a6:
	/* 0x29a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29ab:
	/* 0x29ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29b0:
	/* 0x29b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29b5:
	/* 0x29b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b7:
	/* 0x29b7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29bb:
	/* 0x29bb: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_29bf:
	/* 0x29bf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29c2:
	/* 0x29c2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_29c7:
	/* 0x29c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29cc:
	/* 0x29cc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29d1:
	/* 0x29d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d3:
	/* 0x29d3: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29d6:
	/* 0x29d6: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29da:
	/* 0x29da: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29dd:
	/* 0x29dd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29e2:
	/* 0x29e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29e7:
	/* 0x29e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29ec:
	/* 0x29ec: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_29ef:
	/* 0x29ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f1:
	/* 0x29f1: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29f5:
	/* 0x29f5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29f8:
	/* 0x29f8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_29fd:
	/* 0x29fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a02:
	/* 0x2a02: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a07:
	/* 0x2a07: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a0a:
	/* 0x2a0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0c:
	/* 0x2a0c: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a0f:
	/* 0x2a0f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2a13:
	/* 0x2a13: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a17:
	/* 0x2a17: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a1b:
	/* 0x2a1b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a1e:
	/* 0x2a1e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a23:
	/* 0x2a23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a28:
	/* 0x2a28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a2d:
	/* 0x2a2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2f:
	/* 0x2a2f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a33:
	/* 0x2a33: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2a37:
	/* 0x2a37: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a3a:
	/* 0x2a3a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a3f:
	/* 0x2a3f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a44:
	/* 0x2a44: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a49:
	/* 0x2a49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4b:
	/* 0x2a4b: cmp    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_2a4e:
	/* 0x2a4e: jne    2aac <lkm_seeker_send_to_userspace+0x541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2aac;
	}
x86_l_2a50:
	/* 0x2a50: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a53:
	/* 0x2a53: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a58:
	/* 0x2a58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a5d:
	/* 0x2a5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a62:
	/* 0x2a62: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a65:
	/* 0x2a65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a67:
	/* 0x2a67: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a6e:
	/* 0x2a6e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a73:
	/* 0x2a73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a78:
	/* 0x2a78: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a7d:
	/* 0x2a7d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a80:
	/* 0x2a80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a82:
	/* 0x2a82: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a85:
	/* 0x2a85: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2a89:
	/* 0x2a89: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a8d:
	/* 0x2a8d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a91:
	/* 0x2a91: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a94:
	/* 0x2a94: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2a99:
	/* 0x2a99: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a9e:
	/* 0x2a9e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2aa3:
	/* 0x2aa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa5:
	/* 0x2aa5: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aac:
	/* 0x2aac: mov    DWORD PTR [r14+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ab0:
	/* 0x2ab0: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2ab5:
	/* 0x2ab5: lea    rbp,[r15+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2abc:
	/* 0x2abc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2abf:
	/* 0x2abf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ac4:
	/* 0x2ac4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ac9:
	/* 0x2ac9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ace:
	/* 0x2ace: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2ad1:
	/* 0x2ad1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad3:
	/* 0x2ad3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad7:
	/* 0x2ad7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2adb:
	/* 0x2adb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ade:
	/* 0x2ade: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ae3:
	/* 0x2ae3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ae8:
	/* 0x2ae8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aed:
	/* 0x2aed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aef:
	/* 0x2aef: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af3:
	/* 0x2af3: lea    rdi,[rsp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2af8:
	/* 0x2af8: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2afd:
	/* 0x2afd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b02:
	/* 0x2b02: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b06:
	/* 0x2b06: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b0b:
	/* 0x2b0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0d:
	/* 0x2b0d: mov    eax,DWORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2b11:
	/* 0x2b11: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2b15:
	/* 0x2b15: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2b1a:
	/* 0x2b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1c:
	/* 0x2b1c: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b20:
	/* 0x2b20: lea    rdx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b24:
	/* 0x2b24: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b27:
	/* 0x2b27: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b2c:
	/* 0x2b2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b31:
	/* 0x2b31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b36:
	/* 0x2b36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b38:
	/* 0x2b38: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b3c:
	/* 0x2b3c: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b40:
	/* 0x2b40: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b45:
	/* 0x2b45: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2b49:
	/* 0x2b49: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b4c:
	/* 0x2b4c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b51:
	/* 0x2b51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b56:
	/* 0x2b56: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b5b:
	/* 0x2b5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5d:
	/* 0x2b5d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b61:
	/* 0x2b61: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b65:
	/* 0x2b65: add    r13,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2b69:
	/* 0x2b69: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b6c:
	/* 0x2b6c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b71:
	/* 0x2b71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b76:
	/* 0x2b76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b7b:
	/* 0x2b7b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b7e:
	/* 0x2b7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b80:
	/* 0x2b80: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b84:
	/* 0x2b84: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b88:
	/* 0x2b88: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b8b:
	/* 0x2b8b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2b90:
	/* 0x2b90: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b95:
	/* 0x2b95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b9a:
	/* 0x2b9a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2b9d:
	/* 0x2b9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9f:
	/* 0x2b9f: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ba3:
	/* 0x2ba3: je     2baa <lkm_seeker_send_to_userspace+0x63f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2baa;
	}
x86_l_2ba5:
	/* 0x2ba5: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_2baa:
	/* 0x2baa: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_2bb2:
	/* 0x2bb2: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2bbe:
	/* 0x2bbe: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2bc3:
	/* 0x2bc3: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2bc8:
	/* 0x2bc8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2bcd:
	/* 0x2bcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bcf:
	/* 0x2bcf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bd2:
	/* 0x2bd2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2bd7:
	/* 0x2bd7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bdc:
	/* 0x2bdc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2be1:
	/* 0x2be1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2be4:
	/* 0x2be4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be6:
	/* 0x2be6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bea:
	/* 0x2bea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bed:
	/* 0x2bed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2bf2:
	/* 0x2bf2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bf7:
	/* 0x2bf7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bfc:
	/* 0x2bfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bfe:
	/* 0x2bfe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c02:
	/* 0x2c02: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_2c05:
	/* 0x2c05: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_2c0a:
	/* 0x2c0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c0f:
	/* 0x2c0f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2c12:
	/* 0x2c12: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2c17:
	/* 0x2c17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c19:
	/* 0x2c19: add    r14,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_2c1d:
	/* 0x2c1d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2c22:
	/* 0x2c22: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c27:
	/* 0x2c27: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2c2a:
	/* 0x2c2a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c2f:
	/* 0x2c2f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c32:
	/* 0x2c32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c34:
	/* 0x2c34: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c38:
	/* 0x2c38: mov    rdx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c3c:
	/* 0x2c3c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c40:
	/* 0x2c40: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2c45:
	/* 0x2c45: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c4a:
	/* 0x2c4a: mov    rdi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c4e:
	/* 0x2c4e: mov    rdx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c52:
	/* 0x2c52: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c56:
	/* 0x2c56: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2c5b:
	/* 0x2c5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5d:
	/* 0x2c5d: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c60:
	/* 0x2c60: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_2c64:
	/* 0x2c64: jne    2c6c <lkm_seeker_send_to_userspace+0x701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c6c;
	}
x86_l_2c66:
	/* 0x2c66: mov    rcx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c6a:
	/* 0x2c6a: jmp    2c92 <lkm_seeker_send_to_userspace+0x727> */
	goto x86_l_2c92;
x86_l_2c6c:
	/* 0x2c6c: mov    rcx,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c70:
	/* 0x2c70: mov    rsi,QWORD PTR [rip+0x36c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_2c77:
	/* 0x2c77: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2c7c:
	/* 0x2c7c: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_2c81:
	/* 0x2c81: mov    rdi,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c85:
	/* 0x2c85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c87:
	/* 0x2c87: mov    rcx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c8b:
	/* 0x2c8b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c8d:
	/* 0x2c8d: js     2c92 <lkm_seeker_send_to_userspace+0x727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c92;
	}
x86_l_2c8f:
	/* 0x2c8f: mov    DWORD PTR [rcx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2c92:
	/* 0x2c92: movzx  eax,WORD PTR [rcx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c99:
	/* 0x2c99: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_2c9e:
	/* 0x2c9e: mov    edx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 32000ULL);
x86_l_2ca3:
	/* 0x2ca3: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2ca6:
	/* 0x2ca6: add    edx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_2cac:
	/* 0x2cac: mov    rdi,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cb0:
	/* 0x2cb0: movzx  r8d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2cb4:
	/* 0x2cb4: mov    rsi,QWORD PTR [rip+0x36c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_2cbb:
	/* 0x2cbb: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2cc0:
	/* 0x2cc0: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2cc5:
	/* 0x2cc5: mov    rcx,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cc9:
	/* 0x2cc9: mov    rdi,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ccd:
	/* 0x2ccd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ccf:
	/* 0x2ccf: add    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_2cd3:
	/* 0x2cd3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2cd4:
	/* 0x2cd4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2cd6:
	/* 0x2cd6: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2cd8:
	/* 0x2cd8: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2cda:
	/* 0x2cda: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2cdc:
	/* 0x2cdc: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2cdd:
	/* 0x2cdd: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_ret_do_init_module_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10392U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2198ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2202ULL && __x86_pc <= 3818ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3821ULL && __x86_pc <= 5331ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5334ULL && __x86_pc <= 6995ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6997ULL && __x86_pc <= 8657ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8660ULL && __x86_pc <= 10336ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10338ULL && __x86_pc <= 11485ULL)
			__x86_pc = tracee_trace_ret_do_init_module_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

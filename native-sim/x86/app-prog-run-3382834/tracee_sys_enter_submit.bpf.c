extern char binary_filter_version;
extern char bufs;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char fd_arg_path_map;
extern char mnt_ns_filter_version;
extern char pid_filter_version;
extern char pid_ns_filter_version;
extern char proc_info_map;
extern char process_tree_map_version;
extern char scratch_map;
extern char stack_addresses;
extern char sys_32_to_64_map;
extern char sys_enter_tails;
extern char task_info_map;
extern char uid_filter_version;
extern char uts_ns_filter_version;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tracee_sys_enter_submit_x86_chunk_0(
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
	case 25ULL: goto x86_l_19;
	case 27ULL: goto x86_l_1b;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 40ULL: goto x86_l_28;
	case 44ULL: goto x86_l_2c;
	case 49ULL: goto x86_l_31;
	case 54ULL: goto x86_l_36;
	case 59ULL: goto x86_l_3b;
	case 64ULL: goto x86_l_40;
	case 66ULL: goto x86_l_42;
	case 74ULL: goto x86_l_4a;
	case 79ULL: goto x86_l_4f;
	case 81ULL: goto x86_l_51;
	case 86ULL: goto x86_l_56;
	case 88ULL: goto x86_l_58;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 98ULL: goto x86_l_62;
	case 101ULL: goto x86_l_65;
	case 103ULL: goto x86_l_67;
	case 106ULL: goto x86_l_6a;
	case 108ULL: goto x86_l_6c;
	case 112ULL: goto x86_l_70;
	case 117ULL: goto x86_l_75;
	case 122ULL: goto x86_l_7a;
	case 127ULL: goto x86_l_7f;
	case 132ULL: goto x86_l_84;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 142ULL: goto x86_l_8e;
	case 144ULL: goto x86_l_90;
	case 148ULL: goto x86_l_94;
	case 150ULL: goto x86_l_96;
	case 157ULL: goto x86_l_9d;
	case 162ULL: goto x86_l_a2;
	case 167ULL: goto x86_l_a7;
	case 169ULL: goto x86_l_a9;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 176ULL: goto x86_l_b0;
	case 178ULL: goto x86_l_b2;
	case 183ULL: goto x86_l_b7;
	case 191ULL: goto x86_l_bf;
	case 198ULL: goto x86_l_c6;
	case 203ULL: goto x86_l_cb;
	case 208ULL: goto x86_l_d0;
	case 210ULL: goto x86_l_d2;
	case 213ULL: goto x86_l_d5;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 229ULL: goto x86_l_e5;
	case 234ULL: goto x86_l_ea;
	case 239ULL: goto x86_l_ef;
	case 241ULL: goto x86_l_f1;
	case 244ULL: goto x86_l_f4;
	case 250ULL: goto x86_l_fa;
	case 253ULL: goto x86_l_fd;
	case 263ULL: goto x86_l_107;
	case 271ULL: goto x86_l_10f;
	case 282ULL: goto x86_l_11a;
	case 293ULL: goto x86_l_125;
	case 304ULL: goto x86_l_130;
	case 315ULL: goto x86_l_13b;
	case 326ULL: goto x86_l_146;
	case 337ULL: goto x86_l_151;
	case 348ULL: goto x86_l_15c;
	case 359ULL: goto x86_l_167;
	case 366ULL: goto x86_l_16e;
	case 374ULL: goto x86_l_176;
	case 382ULL: goto x86_l_17e;
	case 390ULL: goto x86_l_186;
	case 398ULL: goto x86_l_18e;
	case 406ULL: goto x86_l_196;
	case 414ULL: goto x86_l_19e;
	case 422ULL: goto x86_l_1a6;
	case 430ULL: goto x86_l_1ae;
	case 438ULL: goto x86_l_1b6;
	case 446ULL: goto x86_l_1be;
	case 454ULL: goto x86_l_1c6;
	case 462ULL: goto x86_l_1ce;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 477ULL: goto x86_l_1dd;
	case 481ULL: goto x86_l_1e1;
	case 485ULL: goto x86_l_1e5;
	case 489ULL: goto x86_l_1e9;
	case 497ULL: goto x86_l_1f1;
	case 502ULL: goto x86_l_1f6;
	case 504ULL: goto x86_l_1f8;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 514ULL: goto x86_l_202;
	case 519ULL: goto x86_l_207;
	case 523ULL: goto x86_l_20b;
	case 527ULL: goto x86_l_20f;
	case 531ULL: goto x86_l_213;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 548ULL: goto x86_l_224;
	case 550ULL: goto x86_l_226;
	case 555ULL: goto x86_l_22b;
	case 558ULL: goto x86_l_22e;
	case 560ULL: goto x86_l_230;
	case 564ULL: goto x86_l_234;
	case 571ULL: goto x86_l_23b;
	case 578ULL: goto x86_l_242;
	case 586ULL: goto x86_l_24a;
	case 591ULL: goto x86_l_24f;
	case 593ULL: goto x86_l_251;
	case 596ULL: goto x86_l_254;
	case 599ULL: goto x86_l_257;
	case 605ULL: goto x86_l_25d;
	case 609ULL: goto x86_l_261;
	case 615ULL: goto x86_l_267;
	case 620ULL: goto x86_l_26c;
	case 622ULL: goto x86_l_26e;
	case 627ULL: goto x86_l_273;
	case 631ULL: goto x86_l_277;
	case 635ULL: goto x86_l_27b;
	case 643ULL: goto x86_l_283;
	case 650ULL: goto x86_l_28a;
	case 655ULL: goto x86_l_28f;
	case 660ULL: goto x86_l_294;
	case 662ULL: goto x86_l_296;
	case 665ULL: goto x86_l_299;
	case 671ULL: goto x86_l_29f;
	case 674ULL: goto x86_l_2a2;
	case 678ULL: goto x86_l_2a6;
	case 682ULL: goto x86_l_2aa;
	case 693ULL: goto x86_l_2b5;
	case 704ULL: goto x86_l_2c0;
	case 715ULL: goto x86_l_2cb;
	case 726ULL: goto x86_l_2d6;
	case 737ULL: goto x86_l_2e1;
	case 748ULL: goto x86_l_2ec;
	case 759ULL: goto x86_l_2f7;
	case 770ULL: goto x86_l_302;
	case 781ULL: goto x86_l_30d;
	case 792ULL: goto x86_l_318;
	case 803ULL: goto x86_l_323;
	case 814ULL: goto x86_l_32e;
	case 825ULL: goto x86_l_339;
	case 836ULL: goto x86_l_344;
	case 847ULL: goto x86_l_34f;
	case 858ULL: goto x86_l_35a;
	case 869ULL: goto x86_l_365;
	case 880ULL: goto x86_l_370;
	case 891ULL: goto x86_l_37b;
	case 902ULL: goto x86_l_386;
	case 913ULL: goto x86_l_391;
	case 924ULL: goto x86_l_39c;
	case 935ULL: goto x86_l_3a7;
	case 946ULL: goto x86_l_3b2;
	case 957ULL: goto x86_l_3bd;
	case 968ULL: goto x86_l_3c8;
	case 979ULL: goto x86_l_3d3;
	case 990ULL: goto x86_l_3de;
	case 1001ULL: goto x86_l_3e9;
	case 1012ULL: goto x86_l_3f4;
	case 1020ULL: goto x86_l_3fc;
	case 1028ULL: goto x86_l_404;
	case 1036ULL: goto x86_l_40c;
	case 1044ULL: goto x86_l_414;
	case 1052ULL: goto x86_l_41c;
	case 1060ULL: goto x86_l_424;
	case 1068ULL: goto x86_l_42c;
	case 1076ULL: goto x86_l_434;
	case 1084ULL: goto x86_l_43c;
	case 1092ULL: goto x86_l_444;
	case 1100ULL: goto x86_l_44c;
	case 1108ULL: goto x86_l_454;
	case 1116ULL: goto x86_l_45c;
	case 1124ULL: goto x86_l_464;
	case 1132ULL: goto x86_l_46c;
	case 1139ULL: goto x86_l_473;
	case 1146ULL: goto x86_l_47a;
	case 1151ULL: goto x86_l_47f;
	case 1156ULL: goto x86_l_484;
	case 1161ULL: goto x86_l_489;
	case 1164ULL: goto x86_l_48c;
	case 1166ULL: goto x86_l_48e;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1179ULL: goto x86_l_49b;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1189ULL: goto x86_l_4a5;
	case 1195ULL: goto x86_l_4ab;
	case 1200ULL: goto x86_l_4b0;
	case 1207ULL: goto x86_l_4b7;
	case 1211ULL: goto x86_l_4bb;
	case 1219ULL: goto x86_l_4c3;
	case 1226ULL: goto x86_l_4ca;
	case 1231ULL: goto x86_l_4cf;
	case 1236ULL: goto x86_l_4d4;
	case 1241ULL: goto x86_l_4d9;
	case 1243ULL: goto x86_l_4db;
	case 1246ULL: goto x86_l_4de;
	case 1252ULL: goto x86_l_4e4;
	case 1255ULL: goto x86_l_4e7;
	case 1263ULL: goto x86_l_4ef;
	case 1267ULL: goto x86_l_4f3;
	case 1271ULL: goto x86_l_4f7;
	case 1282ULL: goto x86_l_502;
	case 1293ULL: goto x86_l_50d;
	case 1304ULL: goto x86_l_518;
	case 1315ULL: goto x86_l_523;
	case 1326ULL: goto x86_l_52e;
	case 1337ULL: goto x86_l_539;
	case 1348ULL: goto x86_l_544;
	case 1359ULL: goto x86_l_54f;
	case 1370ULL: goto x86_l_55a;
	case 1378ULL: goto x86_l_562;
	case 1386ULL: goto x86_l_56a;
	case 1394ULL: goto x86_l_572;
	case 1402ULL: goto x86_l_57a;
	case 1410ULL: goto x86_l_582;
	case 1418ULL: goto x86_l_58a;
	case 1426ULL: goto x86_l_592;
	case 1434ULL: goto x86_l_59a;
	case 1442ULL: goto x86_l_5a2;
	case 1450ULL: goto x86_l_5aa;
	case 1458ULL: goto x86_l_5b2;
	case 1466ULL: goto x86_l_5ba;
	case 1474ULL: goto x86_l_5c2;
	case 1482ULL: goto x86_l_5ca;
	case 1490ULL: goto x86_l_5d2;
	case 1497ULL: goto x86_l_5d9;
	case 1504ULL: goto x86_l_5e0;
	case 1509ULL: goto x86_l_5e5;
	case 1514ULL: goto x86_l_5ea;
	case 1519ULL: goto x86_l_5ef;
	case 1522ULL: goto x86_l_5f2;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1534ULL: goto x86_l_5fe;
	case 1537ULL: goto x86_l_601;
	case 1539ULL: goto x86_l_603;
	case 1542ULL: goto x86_l_606;
	case 1548ULL: goto x86_l_60c;
	case 1551ULL: goto x86_l_60f;
	case 1558ULL: goto x86_l_616;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1578ULL: goto x86_l_62a;
	case 1583ULL: goto x86_l_62f;
	case 1586ULL: goto x86_l_632;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1601ULL: goto x86_l_641;
	case 1605ULL: goto x86_l_645;
	case 1610ULL: goto x86_l_64a;
	case 1615ULL: goto x86_l_64f;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1672ULL: goto x86_l_688;
	case 1677ULL: goto x86_l_68d;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1692ULL: goto x86_l_69c;
	case 1694ULL: goto x86_l_69e;
	case 1698ULL: goto x86_l_6a2;
	case 1701ULL: goto x86_l_6a5;
	case 1709ULL: goto x86_l_6ad;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1723ULL: goto x86_l_6bb;
	case 1728ULL: goto x86_l_6c0;
	case 1733ULL: goto x86_l_6c5;
	case 1736ULL: goto x86_l_6c8;
	case 1738ULL: goto x86_l_6ca;
	case 1743ULL: goto x86_l_6cf;
	case 1748ULL: goto x86_l_6d4;
	case 1753ULL: goto x86_l_6d9;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1766ULL: goto x86_l_6e6;
	case 1768ULL: goto x86_l_6e8;
	case 1772ULL: goto x86_l_6ec;
	case 1776ULL: goto x86_l_6f0;
	case 1780ULL: goto x86_l_6f4;
	case 1784ULL: goto x86_l_6f8;
	case 1789ULL: goto x86_l_6fd;
	case 1794ULL: goto x86_l_702;
	case 1799ULL: goto x86_l_707;
	case 1804ULL: goto x86_l_70c;
	case 1806ULL: goto x86_l_70e;
	case 1810ULL: goto x86_l_712;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1836ULL: goto x86_l_72c;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1897ULL: goto x86_l_769;
	case 1899ULL: goto x86_l_76b;
	case 1903ULL: goto x86_l_76f;
	case 1907ULL: goto x86_l_773;
	case 1911ULL: goto x86_l_777;
	case 1915ULL: goto x86_l_77b;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1937ULL: goto x86_l_791;
	case 1941ULL: goto x86_l_795;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1967ULL: goto x86_l_7af;
	case 1969ULL: goto x86_l_7b1;
	case 1974ULL: goto x86_l_7b6;
	case 1979ULL: goto x86_l_7bb;
	case 1984ULL: goto x86_l_7c0;
	case 1989ULL: goto x86_l_7c5;
	case 1994ULL: goto x86_l_7ca;
	case 1997ULL: goto x86_l_7cd;
	case 1999ULL: goto x86_l_7cf;
	case 2003ULL: goto x86_l_7d3;
	case 2007ULL: goto x86_l_7d7;
	case 2011ULL: goto x86_l_7db;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2035ULL: goto x86_l_7f3;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2046ULL: goto x86_l_7fe;
	case 2051ULL: goto x86_l_803;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2066ULL: goto x86_l_812;
	case 2068ULL: goto x86_l_814;
	case 2071ULL: goto x86_l_817;
	case 2075ULL: goto x86_l_81b;
	case 2080ULL: goto x86_l_820;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2104ULL: goto x86_l_838;
	case 2107ULL: goto x86_l_83b;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
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
	/* 0xa: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_11:
	/* 0x11: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_19:
	/* 0x19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b:
	/* 0x1b: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1e:
	/* 0x1e: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c:
	/* 0x2c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31:
	/* 0x31: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_36:
	/* 0x36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b:
	/* 0x3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40:
	/* 0x40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42:
	/* 0x42: test   DWORD PTR [rsp+0x40],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274880004096ULL);
x86_l_4a:
	/* 0x4a: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_4f:
	/* 0x4f: jne    b7 <sys_enter_submit+0xb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b7;
	}
x86_l_51:
	/* 0x51: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_56:
	/* 0x56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58:
	/* 0x58: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5b:
	/* 0x5b: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_60:
	/* 0x60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62:
	/* 0x62: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65:
	/* 0x65: je     6c <sys_enter_submit+0x6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c;
	}
x86_l_67:
	/* 0x67: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6a:
	/* 0x6a: jmp    6c <sys_enter_submit+0x6c> */
	goto x86_l_6c;
x86_l_6c:
	/* 0x6c: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_70:
	/* 0x70: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_75:
	/* 0x75: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7a:
	/* 0x7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f:
	/* 0x7f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_84:
	/* 0x84: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_87:
	/* 0x87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89:
	/* 0x89: test   BYTE PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_8e:
	/* 0x8e: jne    96 <sys_enter_submit+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_96;
	}
x86_l_90:
	/* 0x90: mov    ebx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_94:
	/* 0x94: jmp    b7 <sys_enter_submit+0xb7> */
	goto x86_l_b7;
x86_l_96:
	/* 0x96: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_9d:
	/* 0x9d: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a2:
	/* 0xa2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a7:
	/* 0xa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9:
	/* 0xa9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac:
	/* 0xac: je     b2 <sys_enter_submit+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b2;
	}
x86_l_ae:
	/* 0xae: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b0:
	/* 0xb0: jmp    b7 <sys_enter_submit+0xb7> */
	goto x86_l_b7;
x86_l_b2:
	/* 0xb2: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_b7:
	/* 0xb7: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_bf:
	/* 0xbf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_c6:
	/* 0xc6: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cb:
	/* 0xcb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d0:
	/* 0xd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2:
	/* 0xd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d5:
	/* 0xd5: je     1f13 <sys_enter_submit+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7955ULL;
	}
x86_l_db:
	/* 0xdb: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_de:
	/* 0xde: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_e5:
	/* 0xe5: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ea:
	/* 0xea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef:
	/* 0xef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1:
	/* 0xf1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f4:
	/* 0xf4: je     1f13 <sys_enter_submit+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7955ULL;
	}
x86_l_fa:
	/* 0xfa: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_fd:
	/* 0xfd: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_107:
	/* 0x107: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_10f:
	/* 0x10f: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_11a:
	/* 0x11a: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_125:
	/* 0x125: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_130:
	/* 0x130: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_13b:
	/* 0x13b: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_146:
	/* 0x146: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_151:
	/* 0x151: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_15c:
	/* 0x15c: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_167:
	/* 0x167: mov    QWORD PTR [r14+0x7dd0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_16e:
	/* 0x16e: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_176:
	/* 0x176: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17e:
	/* 0x17e: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_186:
	/* 0x186: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_18e:
	/* 0x18e: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_196:
	/* 0x196: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_19e:
	/* 0x19e: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a6:
	/* 0x1a6: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1ae:
	/* 0x1ae: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b6:
	/* 0x1b6: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1be:
	/* 0x1be: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1ce:
	/* 0x1ce: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1d6:
	/* 0x1d6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1db:
	/* 0x1db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd:
	/* 0x1dd: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e1:
	/* 0x1e1: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1e5:
	/* 0x1e5: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e9:
	/* 0x1e9: mov    DWORD PTR [r14+0x70],0x31b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337947ULL);
x86_l_1f1:
	/* 0x1f1: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1f6:
	/* 0x1f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8:
	/* 0x1f8: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fb:
	/* 0x1fb: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_200:
	/* 0x200: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202:
	/* 0x202: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_207:
	/* 0x207: mov    DWORD PTR [r14+0x74],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_20b:
	/* 0x20b: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_20f:
	/* 0x20f: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_213:
	/* 0x213: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_21a:
	/* 0x21a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21f:
	/* 0x21f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_224:
	/* 0x224: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226:
	/* 0x226: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b:
	/* 0x22b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22e:
	/* 0x22e: je     273 <sys_enter_submit+0x273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_273;
	}
x86_l_230:
	/* 0x230: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_234:
	/* 0x234: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_23b:
	/* 0x23b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_242:
	/* 0x242: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_24a:
	/* 0x24a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24f:
	/* 0x24f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251:
	/* 0x251: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_254:
	/* 0x254: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_257:
	/* 0x257: je     4b0 <sys_enter_submit+0x4b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b0;
	}
x86_l_25d:
	/* 0x25d: test   BYTE PTR [rbp+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_261:
	/* 0x261: jne    ad0 <sys_enter_submit+0xad0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2768ULL;
	}
x86_l_267:
	/* 0x267: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_26c:
	/* 0x26c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e:
	/* 0x26e: jmp    b7a <sys_enter_submit+0xb7a> */
	return 2938ULL;
x86_l_273:
	/* 0x273: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_277:
	/* 0x277: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27b:
	/* 0x27b: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_283:
	/* 0x283: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_28a:
	/* 0x28a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28f:
	/* 0x28f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_294:
	/* 0x294: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_296:
	/* 0x296: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_299:
	/* 0x299: je     1f13 <sys_enter_submit+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7955ULL;
	}
x86_l_29f:
	/* 0x29f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2a2:
	/* 0x2a2: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a6:
	/* 0x2a6: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2aa:
	/* 0x2aa: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2b5:
	/* 0x2b5: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2c0:
	/* 0x2c0: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2cb:
	/* 0x2cb: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2d6:
	/* 0x2d6: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2e1:
	/* 0x2e1: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_2ec:
	/* 0x2ec: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_2f7:
	/* 0x2f7: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_302:
	/* 0x302: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_30d:
	/* 0x30d: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_318:
	/* 0x318: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_323:
	/* 0x323: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_32e:
	/* 0x32e: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_339:
	/* 0x339: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_344:
	/* 0x344: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_34f:
	/* 0x34f: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_35a:
	/* 0x35a: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_365:
	/* 0x365: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_370:
	/* 0x370: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_37b:
	/* 0x37b: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_386:
	/* 0x386: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_391:
	/* 0x391: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_39c:
	/* 0x39c: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3a7:
	/* 0x3a7: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3b2:
	/* 0x3b2: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3bd:
	/* 0x3bd: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3c8:
	/* 0x3c8: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3d3:
	/* 0x3d3: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3de:
	/* 0x3de: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_3e9:
	/* 0x3e9: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3f4:
	/* 0x3f4: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3fc:
	/* 0x3fc: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_404:
	/* 0x404: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_40c:
	/* 0x40c: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_414:
	/* 0x414: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_41c:
	/* 0x41c: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_424:
	/* 0x424: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_42c:
	/* 0x42c: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_434:
	/* 0x434: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_43c:
	/* 0x43c: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_444:
	/* 0x444: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_44c:
	/* 0x44c: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_454:
	/* 0x454: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_45c:
	/* 0x45c: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_464:
	/* 0x464: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_46c:
	/* 0x46c: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_473:
	/* 0x473: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_47a:
	/* 0x47a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_47f:
	/* 0x47f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_484:
	/* 0x484: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_489:
	/* 0x489: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_48c:
	/* 0x48c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48e:
	/* 0x48e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_493:
	/* 0x493: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_498:
	/* 0x498: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_49b:
	/* 0x49b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d:
	/* 0x49d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a2:
	/* 0x4a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a5:
	/* 0x4a5: jne    230 <sys_enter_submit+0x230> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_230;
	}
x86_l_4ab:
	/* 0x4ab: jmp    1f13 <sys_enter_submit+0x1f13> */
	return 7955ULL;
x86_l_4b0:
	/* 0x4b0: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4b7:
	/* 0x4b7: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4bb:
	/* 0x4bb: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4c3:
	/* 0x4c3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4ca:
	/* 0x4ca: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4cf:
	/* 0x4cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d4:
	/* 0x4d4: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4d9:
	/* 0x4d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4db:
	/* 0x4db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4de:
	/* 0x4de: je     1f13 <sys_enter_submit+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7955ULL;
	}
x86_l_4e4:
	/* 0x4e4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4e7:
	/* 0x4e7: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4ef:
	/* 0x4ef: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4f3:
	/* 0x4f3: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4f7:
	/* 0x4f7: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_502:
	/* 0x502: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_50d:
	/* 0x50d: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_518:
	/* 0x518: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_523:
	/* 0x523: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_52e:
	/* 0x52e: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_539:
	/* 0x539: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_544:
	/* 0x544: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_54f:
	/* 0x54f: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_55a:
	/* 0x55a: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_562:
	/* 0x562: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_56a:
	/* 0x56a: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_572:
	/* 0x572: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_57a:
	/* 0x57a: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_582:
	/* 0x582: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_58a:
	/* 0x58a: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_592:
	/* 0x592: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_59a:
	/* 0x59a: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5a2:
	/* 0x5a2: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5aa:
	/* 0x5aa: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5b2:
	/* 0x5b2: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5ba:
	/* 0x5ba: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5c2:
	/* 0x5c2: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5ca:
	/* 0x5ca: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5d2:
	/* 0x5d2: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d9:
	/* 0x5d9: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5e0:
	/* 0x5e0: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5e5:
	/* 0x5e5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ea:
	/* 0x5ea: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5ef:
	/* 0x5ef: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_5f2:
	/* 0x5f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f4:
	/* 0x5f4: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5f9:
	/* 0x5f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fe:
	/* 0x5fe: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_601:
	/* 0x601: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_603:
	/* 0x603: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_606:
	/* 0x606: je     1f13 <sys_enter_submit+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7955ULL;
	}
x86_l_60c:
	/* 0x60c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_60f:
	/* 0x60f: mov    r12,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_616:
	/* 0x616: lea    r13,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_61b:
	/* 0x61b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_620:
	/* 0x620: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_625:
	/* 0x625: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62a:
	/* 0x62a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62f:
	/* 0x62f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_632:
	/* 0x632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_634:
	/* 0x634: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_639:
	/* 0x639: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_641:
	/* 0x641: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_645:
	/* 0x645: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_64a:
	/* 0x64a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64f:
	/* 0x64f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_654:
	/* 0x654: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_659:
	/* 0x659: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65b:
	/* 0x65b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_660:
	/* 0x660: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_664:
	/* 0x664: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_669:
	/* 0x669: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_66e:
	/* 0x66e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_673:
	/* 0x673: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_678:
	/* 0x678: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67a:
	/* 0x67a: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_67f:
	/* 0x67f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_684:
	/* 0x684: lea    rdx,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_688:
	/* 0x688: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_68d:
	/* 0x68d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_692:
	/* 0x692: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_697:
	/* 0x697: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_69c:
	/* 0x69c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69e:
	/* 0x69e: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6a2:
	/* 0x6a2: mov    DWORD PTR [rbx+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6a5:
	/* 0x6a5: mov    QWORD PTR [rsp+0x90],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6ad:
	/* 0x6ad: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6b1:
	/* 0x6b1: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6b6:
	/* 0x6b6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6bb:
	/* 0x6bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c0:
	/* 0x6c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c5:
	/* 0x6c5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6c8:
	/* 0x6c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ca:
	/* 0x6ca: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6cf:
	/* 0x6cf: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6d4:
	/* 0x6d4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6d9:
	/* 0x6d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6de:
	/* 0x6de: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6e3:
	/* 0x6e3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6e6:
	/* 0x6e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e8:
	/* 0x6e8: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6ec:
	/* 0x6ec: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6f0:
	/* 0x6f0: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_6f4:
	/* 0x6f4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6f8:
	/* 0x6f8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6fd:
	/* 0x6fd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_702:
	/* 0x702: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_707:
	/* 0x707: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_70c:
	/* 0x70c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70e:
	/* 0x70e: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_712:
	/* 0x712: mov    DWORD PTR [rbx+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_715:
	/* 0x715: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_71a:
	/* 0x71a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_71f:
	/* 0x71f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_724:
	/* 0x724: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_729:
	/* 0x729: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_72c:
	/* 0x72c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72e:
	/* 0x72e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_733:
	/* 0x733: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_737:
	/* 0x737: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_73c:
	/* 0x73c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_741:
	/* 0x741: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_746:
	/* 0x746: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_74b:
	/* 0x74b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74d:
	/* 0x74d: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_752:
	/* 0x752: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_757:
	/* 0x757: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_75c:
	/* 0x75c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_761:
	/* 0x761: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_766:
	/* 0x766: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_769:
	/* 0x769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76b:
	/* 0x76b: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_76f:
	/* 0x76f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_773:
	/* 0x773: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_777:
	/* 0x777: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_77b:
	/* 0x77b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_780:
	/* 0x780: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_785:
	/* 0x785: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_78a:
	/* 0x78a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_78f:
	/* 0x78f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_791:
	/* 0x791: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_795:
	/* 0x795: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_798:
	/* 0x798: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_79d:
	/* 0x79d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7a2:
	/* 0x7a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7a7:
	/* 0x7a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ac:
	/* 0x7ac: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7af:
	/* 0x7af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b1:
	/* 0x7b1: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7b6:
	/* 0x7b6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7bb:
	/* 0x7bb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7c0:
	/* 0x7c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7c5:
	/* 0x7c5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7ca:
	/* 0x7ca: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_7cd:
	/* 0x7cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cf:
	/* 0x7cf: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7d3:
	/* 0x7d3: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7d7:
	/* 0x7d7: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_7db:
	/* 0x7db: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7df:
	/* 0x7df: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7e4:
	/* 0x7e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7e9:
	/* 0x7e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7ee:
	/* 0x7ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f3:
	/* 0x7f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f5:
	/* 0x7f5: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7fa:
	/* 0x7fa: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_7fe:
	/* 0x7fe: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_803:
	/* 0x803: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_808:
	/* 0x808: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_80d:
	/* 0x80d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_812:
	/* 0x812: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_814:
	/* 0x814: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_817:
	/* 0x817: mov    ebx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_81b:
	/* 0x81b: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_820:
	/* 0x820: lea    r13,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_824:
	/* 0x824: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_829:
	/* 0x829: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_82e:
	/* 0x82e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_833:
	/* 0x833: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_838:
	/* 0x838: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_83b:
	/* 0x83b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83d:
	/* 0x83d: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_842:
	/* 0x842: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_847:
	/* 0x847: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_84c:
	/* 0x84c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 2129ULL;
}

static __noinline __u64 tracee_sys_enter_submit_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2129ULL: goto x86_l_851;
	case 2134ULL: goto x86_l_856;
	case 2137ULL: goto x86_l_859;
	case 2139ULL: goto x86_l_85b;
	case 2143ULL: goto x86_l_85f;
	case 2147ULL: goto x86_l_863;
	case 2151ULL: goto x86_l_867;
	case 2155ULL: goto x86_l_86b;
	case 2160ULL: goto x86_l_870;
	case 2165ULL: goto x86_l_875;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2177ULL: goto x86_l_881;
	case 2182ULL: goto x86_l_886;
	case 2186ULL: goto x86_l_88a;
	case 2191ULL: goto x86_l_88f;
	case 2196ULL: goto x86_l_894;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2208ULL: goto x86_l_8a0;
	case 2212ULL: goto x86_l_8a4;
	case 2214ULL: goto x86_l_8a6;
	case 2219ULL: goto x86_l_8ab;
	case 2224ULL: goto x86_l_8b0;
	case 2229ULL: goto x86_l_8b5;
	case 2234ULL: goto x86_l_8ba;
	case 2237ULL: goto x86_l_8bd;
	case 2239ULL: goto x86_l_8bf;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2259ULL: goto x86_l_8d3;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2269ULL: goto x86_l_8dd;
	case 2273ULL: goto x86_l_8e1;
	case 2277ULL: goto x86_l_8e5;
	case 2281ULL: goto x86_l_8e9;
	case 2285ULL: goto x86_l_8ed;
	case 2290ULL: goto x86_l_8f2;
	case 2295ULL: goto x86_l_8f7;
	case 2300ULL: goto x86_l_8fc;
	case 2305ULL: goto x86_l_901;
	case 2307ULL: goto x86_l_903;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2321ULL: goto x86_l_911;
	case 2329ULL: goto x86_l_919;
	case 2336ULL: goto x86_l_920;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2351ULL: goto x86_l_92f;
	case 2356ULL: goto x86_l_934;
	case 2359ULL: goto x86_l_937;
	case 2361ULL: goto x86_l_939;
	case 2366ULL: goto x86_l_93e;
	case 2370ULL: goto x86_l_942;
	case 2375ULL: goto x86_l_947;
	case 2380ULL: goto x86_l_94c;
	case 2385ULL: goto x86_l_951;
	case 2390ULL: goto x86_l_956;
	case 2392ULL: goto x86_l_958;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2422ULL: goto x86_l_976;
	case 2424ULL: goto x86_l_978;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2438ULL: goto x86_l_986;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2449ULL: goto x86_l_991;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2471ULL: goto x86_l_9a7;
	case 2476ULL: goto x86_l_9ac;
	case 2480ULL: goto x86_l_9b0;
	case 2488ULL: goto x86_l_9b8;
	case 2492ULL: goto x86_l_9bc;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2524ULL: goto x86_l_9dc;
	case 2529ULL: goto x86_l_9e1;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2575ULL: goto x86_l_a0f;
	case 2580ULL: goto x86_l_a14;
	case 2585ULL: goto x86_l_a19;
	case 2588ULL: goto x86_l_a1c;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2598ULL: goto x86_l_a26;
	case 2600ULL: goto x86_l_a28;
	case 2604ULL: goto x86_l_a2c;
	case 2612ULL: goto x86_l_a34;
	case 2616ULL: goto x86_l_a38;
	case 2624ULL: goto x86_l_a40;
	case 2629ULL: goto x86_l_a45;
	case 2634ULL: goto x86_l_a4a;
	case 2639ULL: goto x86_l_a4f;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2651ULL: goto x86_l_a5b;
	case 2656ULL: goto x86_l_a60;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2666ULL: goto x86_l_a6a;
	case 2671ULL: goto x86_l_a6f;
	case 2676ULL: goto x86_l_a74;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2716ULL: goto x86_l_a9c;
	case 2721ULL: goto x86_l_aa1;
	case 2723ULL: goto x86_l_aa3;
	case 2726ULL: goto x86_l_aa6;
	case 2730ULL: goto x86_l_aaa;
	case 2735ULL: goto x86_l_aaf;
	case 2740ULL: goto x86_l_ab4;
	case 2745ULL: goto x86_l_ab9;
	case 2748ULL: goto x86_l_abc;
	case 2750ULL: goto x86_l_abe;
	case 2758ULL: goto x86_l_ac6;
	case 2762ULL: goto x86_l_aca;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2780ULL: goto x86_l_adc;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2800ULL: goto x86_l_af0;
	case 2802ULL: goto x86_l_af2;
	case 2807ULL: goto x86_l_af7;
	case 2812ULL: goto x86_l_afc;
	case 2817ULL: goto x86_l_b01;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2834ULL: goto x86_l_b12;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2849ULL: goto x86_l_b21;
	case 2854ULL: goto x86_l_b26;
	case 2859ULL: goto x86_l_b2b;
	case 2864ULL: goto x86_l_b30;
	case 2866ULL: goto x86_l_b32;
	case 2871ULL: goto x86_l_b37;
	case 2876ULL: goto x86_l_b3c;
	case 2881ULL: goto x86_l_b41;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2893ULL: goto x86_l_b4d;
	case 2898ULL: goto x86_l_b52;
	case 2901ULL: goto x86_l_b55;
	case 2903ULL: goto x86_l_b57;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2936ULL: goto x86_l_b78;
	case 2938ULL: goto x86_l_b7a;
	case 2942ULL: goto x86_l_b7e;
	case 2946ULL: goto x86_l_b82;
	case 2950ULL: goto x86_l_b86;
	case 2957ULL: goto x86_l_b8d;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2969ULL: goto x86_l_b99;
	case 2972ULL: goto x86_l_b9c;
	case 2974ULL: goto x86_l_b9e;
	case 2977ULL: goto x86_l_ba1;
	case 2983ULL: goto x86_l_ba7;
	case 2986ULL: goto x86_l_baa;
	case 2989ULL: goto x86_l_bad;
	case 2991ULL: goto x86_l_baf;
	case 2996ULL: goto x86_l_bb4;
	case 3001ULL: goto x86_l_bb9;
	case 3005ULL: goto x86_l_bbd;
	case 3011ULL: goto x86_l_bc3;
	case 3022ULL: goto x86_l_bce;
	case 3029ULL: goto x86_l_bd5;
	case 3032ULL: goto x86_l_bd8;
	case 3036ULL: goto x86_l_bdc;
	case 3046ULL: goto x86_l_be6;
	case 3054ULL: goto x86_l_bee;
	case 3062ULL: goto x86_l_bf6;
	case 3070ULL: goto x86_l_bfe;
	case 3078ULL: goto x86_l_c06;
	case 3086ULL: goto x86_l_c0e;
	case 3094ULL: goto x86_l_c16;
	case 3102ULL: goto x86_l_c1e;
	case 3110ULL: goto x86_l_c26;
	case 3117ULL: goto x86_l_c2d;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3137ULL: goto x86_l_c41;
	case 3142ULL: goto x86_l_c46;
	case 3149ULL: goto x86_l_c4d;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3161ULL: goto x86_l_c59;
	case 3164ULL: goto x86_l_c5c;
	case 3170ULL: goto x86_l_c62;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3183ULL: goto x86_l_c6f;
	case 3185ULL: goto x86_l_c71;
	case 3188ULL: goto x86_l_c74;
	case 3194ULL: goto x86_l_c7a;
	case 3198ULL: goto x86_l_c7e;
	case 3205ULL: goto x86_l_c85;
	case 3208ULL: goto x86_l_c88;
	case 3215ULL: goto x86_l_c8f;
	case 3222ULL: goto x86_l_c96;
	case 3226ULL: goto x86_l_c9a;
	case 3233ULL: goto x86_l_ca1;
	case 3237ULL: goto x86_l_ca5;
	case 3244ULL: goto x86_l_cac;
	case 3248ULL: goto x86_l_cb0;
	case 3255ULL: goto x86_l_cb7;
	case 3259ULL: goto x86_l_cbb;
	case 3266ULL: goto x86_l_cc2;
	case 3270ULL: goto x86_l_cc6;
	case 3274ULL: goto x86_l_cca;
	case 3281ULL: goto x86_l_cd1;
	case 3288ULL: goto x86_l_cd8;
	case 3291ULL: goto x86_l_cdb;
	case 3295ULL: goto x86_l_cdf;
	case 3303ULL: goto x86_l_ce7;
	case 3311ULL: goto x86_l_cef;
	case 3313ULL: goto x86_l_cf1;
	case 3316ULL: goto x86_l_cf4;
	case 3319ULL: goto x86_l_cf7;
	case 3326ULL: goto x86_l_cfe;
	case 3334ULL: goto x86_l_d06;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3352ULL: goto x86_l_d18;
	case 3355ULL: goto x86_l_d1b;
	case 3361ULL: goto x86_l_d21;
	case 3368ULL: goto x86_l_d28;
	case 3371ULL: goto x86_l_d2b;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3381ULL: goto x86_l_d35;
	case 3384ULL: goto x86_l_d38;
	case 3387ULL: goto x86_l_d3b;
	case 3394ULL: goto x86_l_d42;
	case 3397ULL: goto x86_l_d45;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3409ULL: goto x86_l_d51;
	case 3411ULL: goto x86_l_d53;
	case 3418ULL: goto x86_l_d5a;
	case 3421ULL: goto x86_l_d5d;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3434ULL: goto x86_l_d6a;
	case 3437ULL: goto x86_l_d6d;
	case 3440ULL: goto x86_l_d70;
	case 3447ULL: goto x86_l_d77;
	case 3450ULL: goto x86_l_d7a;
	case 3452ULL: goto x86_l_d7c;
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
	case 3493ULL: goto x86_l_da5;
	case 3498ULL: goto x86_l_daa;
	case 3502ULL: goto x86_l_dae;
	case 3505ULL: goto x86_l_db1;
	case 3512ULL: goto x86_l_db8;
	case 3515ULL: goto x86_l_dbb;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3530ULL: goto x86_l_dca;
	case 3533ULL: goto x86_l_dcd;
	case 3539ULL: goto x86_l_dd3;
	case 3547ULL: goto x86_l_ddb;
	case 3553ULL: goto x86_l_de1;
	case 3560ULL: goto x86_l_de8;
	case 3568ULL: goto x86_l_df0;
	case 3575ULL: goto x86_l_df7;
	case 3583ULL: goto x86_l_dff;
	case 3590ULL: goto x86_l_e06;
	case 3598ULL: goto x86_l_e0e;
	case 3604ULL: goto x86_l_e14;
	case 3611ULL: goto x86_l_e1b;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3623ULL: goto x86_l_e27;
	case 3626ULL: goto x86_l_e2a;
	case 3630ULL: goto x86_l_e2e;
	case 3635ULL: goto x86_l_e33;
	case 3642ULL: goto x86_l_e3a;
	case 3645ULL: goto x86_l_e3d;
	case 3647ULL: goto x86_l_e3f;
	case 3652ULL: goto x86_l_e44;
	case 3657ULL: goto x86_l_e49;
	case 3660ULL: goto x86_l_e4c;
	case 3662ULL: goto x86_l_e4e;
	case 3665ULL: goto x86_l_e51;
	case 3667ULL: goto x86_l_e53;
	case 3670ULL: goto x86_l_e56;
	case 3674ULL: goto x86_l_e5a;
	case 3677ULL: goto x86_l_e5d;
	case 3679ULL: goto x86_l_e5f;
	case 3682ULL: goto x86_l_e62;
	case 3690ULL: goto x86_l_e6a;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3706ULL: goto x86_l_e7a;
	case 3709ULL: goto x86_l_e7d;
	case 3711ULL: goto x86_l_e7f;
	case 3715ULL: goto x86_l_e83;
	case 3717ULL: goto x86_l_e85;
	case 3720ULL: goto x86_l_e88;
	case 3722ULL: goto x86_l_e8a;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3749ULL: goto x86_l_ea5;
	case 3752ULL: goto x86_l_ea8;
	case 3754ULL: goto x86_l_eaa;
	case 3762ULL: goto x86_l_eb2;
	case 3767ULL: goto x86_l_eb7;
	case 3772ULL: goto x86_l_ebc;
	case 3775ULL: goto x86_l_ebf;
	case 3777ULL: goto x86_l_ec1;
	case 3780ULL: goto x86_l_ec4;
	case 3782ULL: goto x86_l_ec6;
	case 3785ULL: goto x86_l_ec9;
	case 3789ULL: goto x86_l_ecd;
	case 3792ULL: goto x86_l_ed0;
	case 3794ULL: goto x86_l_ed2;
	case 3801ULL: goto x86_l_ed9;
	case 3808ULL: goto x86_l_ee0;
	case 3811ULL: goto x86_l_ee3;
	case 3817ULL: goto x86_l_ee9;
	case 3822ULL: goto x86_l_eee;
	case 3824ULL: goto x86_l_ef0;
	case 3827ULL: goto x86_l_ef3;
	case 3832ULL: goto x86_l_ef8;
	case 3835ULL: goto x86_l_efb;
	case 3837ULL: goto x86_l_efd;
	case 3839ULL: goto x86_l_eff;
	case 3841ULL: goto x86_l_f01;
	case 3849ULL: goto x86_l_f09;
	case 3857ULL: goto x86_l_f11;
	case 3860ULL: goto x86_l_f14;
	case 3865ULL: goto x86_l_f19;
	case 3868ULL: goto x86_l_f1c;
	case 3870ULL: goto x86_l_f1e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_851:
	/* 0x851: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_856:
	/* 0x856: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_859:
	/* 0x859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85b:
	/* 0x85b: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_85f:
	/* 0x85f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_863:
	/* 0x863: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_867:
	/* 0x867: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_86b:
	/* 0x86b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_870:
	/* 0x870: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_875:
	/* 0x875: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_87a:
	/* 0x87a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_87f:
	/* 0x87f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_881:
	/* 0x881: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_886:
	/* 0x886: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_88a:
	/* 0x88a: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_88f:
	/* 0x88f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_894:
	/* 0x894: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_899:
	/* 0x899: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_89e:
	/* 0x89e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a0:
	/* 0x8a0: cmp    ebx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 64ULL);
x86_l_8a4:
	/* 0x8a4: jne    90c <sys_enter_submit+0x90c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_90c;
	}
x86_l_8a6:
	/* 0x8a6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8ab:
	/* 0x8ab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8b0:
	/* 0x8b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b5:
	/* 0x8b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ba:
	/* 0x8ba: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_8bd:
	/* 0x8bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8bf:
	/* 0x8bf: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8c4:
	/* 0x8c4: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8c9:
	/* 0x8c9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8ce:
	/* 0x8ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8d3:
	/* 0x8d3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8d8:
	/* 0x8d8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8db:
	/* 0x8db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8dd:
	/* 0x8dd: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8e1:
	/* 0x8e1: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8e5:
	/* 0x8e5: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_8e9:
	/* 0x8e9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8ed:
	/* 0x8ed: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8f2:
	/* 0x8f2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8f7:
	/* 0x8f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8fc:
	/* 0x8fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_901:
	/* 0x901: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_903:
	/* 0x903: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_907:
	/* 0x907: mov    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_90c:
	/* 0x90c: mov    DWORD PTR [r12+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_911:
	/* 0x911: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_919:
	/* 0x919: lea    rbp,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_920:
	/* 0x920: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_925:
	/* 0x925: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_92a:
	/* 0x92a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_92f:
	/* 0x92f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_934:
	/* 0x934: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_937:
	/* 0x937: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_939:
	/* 0x939: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_93e:
	/* 0x93e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_942:
	/* 0x942: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_947:
	/* 0x947: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_94c:
	/* 0x94c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_951:
	/* 0x951: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_956:
	/* 0x956: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_958:
	/* 0x958: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_95d:
	/* 0x95d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_962:
	/* 0x962: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_967:
	/* 0x967: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_96c:
	/* 0x96c: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_971:
	/* 0x971: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_976:
	/* 0x976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_978:
	/* 0x978: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_97c:
	/* 0x97c: mov    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_981:
	/* 0x981: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_986:
	/* 0x986: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_988:
	/* 0x988: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_98d:
	/* 0x98d: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_991:
	/* 0x991: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_996:
	/* 0x996: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_99b:
	/* 0x99b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9a0:
	/* 0x9a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a5:
	/* 0x9a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a7:
	/* 0x9a7: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9ac:
	/* 0x9ac: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b0:
	/* 0x9b0: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9b8:
	/* 0x9b8: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9bc:
	/* 0x9bc: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9c1:
	/* 0x9c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9c6:
	/* 0x9c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9cb:
	/* 0x9cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d0:
	/* 0x9d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d2:
	/* 0x9d2: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9d7:
	/* 0x9d7: mov    QWORD PTR [r12+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9dc:
	/* 0x9dc: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9e1:
	/* 0x9e1: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9e5:
	/* 0x9e5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9ea:
	/* 0x9ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9ef:
	/* 0x9ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9f4:
	/* 0x9f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f9:
	/* 0x9f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fb:
	/* 0x9fb: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a00:
	/* 0xa00: mov    QWORD PTR [r12+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a05:
	/* 0xa05: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a0a:
	/* 0xa0a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a0f:
	/* 0xa0f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a14:
	/* 0xa14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a19:
	/* 0xa19: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a1c:
	/* 0xa1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1e:
	/* 0xa1e: test   BYTE PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_a23:
	/* 0xa23: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_a26:
	/* 0xa26: je     a2c <sys_enter_submit+0xa2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a2c;
	}
x86_l_a28:
	/* 0xa28: or     BYTE PTR [rbx+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_a2c:
	/* 0xa2c: mov    QWORD PTR [rbx+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_a34:
	/* 0xa34: lea    rdi,[rbx+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a38:
	/* 0xa38: mov    QWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_a40:
	/* 0xa40: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a45:
	/* 0xa45: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_a4a:
	/* 0xa4a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a4f:
	/* 0xa4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a51:
	/* 0xa51: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a56:
	/* 0xa56: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a5b:
	/* 0xa5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a60:
	/* 0xa60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a65:
	/* 0xa65: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a68:
	/* 0xa68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6a:
	/* 0xa6a: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a6f:
	/* 0xa6f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a74:
	/* 0xa74: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a79:
	/* 0xa79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a7e:
	/* 0xa7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a83:
	/* 0xa83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a85:
	/* 0xa85: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a8a:
	/* 0xa8a: lea    rbp,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a8f:
	/* 0xa8f: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_a94:
	/* 0xa94: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a99:
	/* 0xa99: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_a9c:
	/* 0xa9c: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_aa1:
	/* 0xaa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa3:
	/* 0xaa3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aa6:
	/* 0xaa6: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_aaa:
	/* 0xaaa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_aaf:
	/* 0xaaf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_ab4:
	/* 0xab4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ab9:
	/* 0xab9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_abc:
	/* 0xabc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abe:
	/* 0xabe: mov    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ac6:
	/* 0xac6: test   BYTE PTR [rbp+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_aca:
	/* 0xaca: je     267 <sys_enter_submit+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 615ULL;
	}
x86_l_ad0:
	/* 0xad0: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_ad5:
	/* 0xad5: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_adc:
	/* 0xadc: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ae1:
	/* 0xae1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ae6:
	/* 0xae6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aeb:
	/* 0xaeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af0:
	/* 0xaf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af2:
	/* 0xaf2: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_af7:
	/* 0xaf7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_afc:
	/* 0xafc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b01:
	/* 0xb01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b06:
	/* 0xb06: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b0b:
	/* 0xb0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b10:
	/* 0xb10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b12:
	/* 0xb12: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b17:
	/* 0xb17: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b1c:
	/* 0xb1c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b21:
	/* 0xb21: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b26:
	/* 0xb26: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b2b:
	/* 0xb2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b30:
	/* 0xb30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b32:
	/* 0xb32: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b37:
	/* 0xb37: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b3c:
	/* 0xb3c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b41:
	/* 0xb41: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b46:
	/* 0xb46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b4b:
	/* 0xb4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4d:
	/* 0xb4d: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b52:
	/* 0xb52: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_b55:
	/* 0xb55: je     b78 <sys_enter_submit+0xb78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b78;
	}
x86_l_b57:
	/* 0xb57: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b5b:
	/* 0xb5b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b60:
	/* 0xb60: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b65:
	/* 0xb65: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b6a:
	/* 0xb6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b6f:
	/* 0xb6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b71:
	/* 0xb71: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b76:
	/* 0xb76: jmp    b7a <sys_enter_submit+0xb7a> */
	goto x86_l_b7a;
x86_l_b78:
	/* 0xb78: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b7a:
	/* 0xb7a: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b7e:
	/* 0xb7e: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b82:
	/* 0xb82: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b86:
	/* 0xb86: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_b8d:
	/* 0xb8d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b92:
	/* 0xb92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b97:
	/* 0xb97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b99:
	/* 0xb99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9c:
	/* 0xb9c: je     bb4 <sys_enter_submit+0xbb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb4;
	}
x86_l_b9e:
	/* 0xb9e: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ba1:
	/* 0xba1: mov    BYTE PTR [rbx+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_ba7:
	/* 0xba7: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_baa:
	/* 0xbaa: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_bad:
	/* 0xbad: jne    bb4 <sys_enter_submit+0xbb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bb4;
	}
x86_l_baf:
	/* 0xbaf: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_bb4:
	/* 0xbb4: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_bb9:
	/* 0xbb9: cmp    ax,WORD PTR [rbp+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_bbd:
	/* 0xbbd: jne    1b82 <sys_enter_submit+0x1b82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7042ULL;
	}
x86_l_bc3:
	/* 0xbc3: mov    QWORD PTR [r14+0x80],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 554050781183ULL);
x86_l_bce:
	/* 0xbce: lea    rax,[r14+0x7d8c] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_bd5:
	/* 0xbd5: mov    ecx,DWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bd8:
	/* 0xbd8: mov    DWORD PTR [r14+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bdc:
	/* 0xbdc: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_be6:
	/* 0xbe6: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_bee:
	/* 0xbee: mov    QWORD PTR [rax+0x38],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244813135871ULL);
x86_l_bf6:
	/* 0xbf6: mov    QWORD PTR [rax+0x30],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 210453397503ULL);
x86_l_bfe:
	/* 0xbfe: mov    QWORD PTR [rax+0x28],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176093659135ULL);
x86_l_c06:
	/* 0xc06: mov    QWORD PTR [rax+0x20],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 141733920767ULL);
x86_l_c0e:
	/* 0xc0e: mov    QWORD PTR [rax+0x18],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 107374182399ULL);
x86_l_c16:
	/* 0xc16: mov    QWORD PTR [rax+0x10],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 73014444031ULL);
x86_l_c1e:
	/* 0xc1e: mov    QWORD PTR [rax+0x8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38654705663ULL);
x86_l_c26:
	/* 0xc26: mov    QWORD PTR [rax],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_c2d:
	/* 0xc2d: mov    QWORD PTR [r14+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_c38:
	/* 0xc38: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c3d:
	/* 0xc3d: mov    DWORD PTR [rsp+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c41:
	/* 0xc41: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c46:
	/* 0xc46: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_c4d:
	/* 0xc4d: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c52:
	/* 0xc52: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c57:
	/* 0xc57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c59:
	/* 0xc59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c5c:
	/* 0xc5c: je     1f13 <sys_enter_submit+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7955ULL;
	}
x86_l_c62:
	/* 0xc62: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c65:
	/* 0xc65: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c6a:
	/* 0xc6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c6f:
	/* 0xc6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c71:
	/* 0xc71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c74:
	/* 0xc74: je     1f13 <sys_enter_submit+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7955ULL;
	}
x86_l_c7a:
	/* 0xc7a: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c7e:
	/* 0xc7e: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_c85:
	/* 0xc85: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c88:
	/* 0xc88: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c8f:
	/* 0xc8f: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c96:
	/* 0xc96: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c9a:
	/* 0xc9a: mov    QWORD PTR [r14+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_ca1:
	/* 0xca1: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ca5:
	/* 0xca5: mov    QWORD PTR [r14+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_cac:
	/* 0xcac: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cb0:
	/* 0xcb0: mov    QWORD PTR [r14+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_cb7:
	/* 0xcb7: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cbb:
	/* 0xcbb: mov    QWORD PTR [r14+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_cc2:
	/* 0xcc2: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc6:
	/* 0xcc6: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cca:
	/* 0xcca: mov    QWORD PTR [r14+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_cd1:
	/* 0xcd1: mov    QWORD PTR [r14+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_cd8:
	/* 0xcd8: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cdb:
	/* 0xcdb: cmp    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_cdf:
	/* 0xcdf: mov    QWORD PTR [rsp+0x98],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ce7:
	/* 0xce7: mov    QWORD PTR [rsp+0xb8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_cef:
	/* 0xcef: jne    d11 <sys_enter_submit+0xd11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d11;
	}
x86_l_cf1:
	/* 0xcf1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cf4:
	/* 0xcf4: and    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_cf7:
	/* 0xcf7: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cfe:
	/* 0xcfe: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_d06:
	/* 0xd06: jne    1541 <sys_enter_submit+0x1541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5441ULL;
	}
x86_l_d0c:
	/* 0xd0c: jmp    1efc <sys_enter_submit+0x1efc> */
	return 7932ULL;
x86_l_d11:
	/* 0xd11: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_d18:
	/* 0xd18: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d1b:
	/* 0xd1b: je     ed2 <sys_enter_submit+0xed2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ed2;
	}
x86_l_d21:
	/* 0xd21: movzx  ecx,BYTE PTR [rbx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_d28:
	/* 0xd28: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_d2b:
	/* 0xd2b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d2e:
	/* 0xd2e: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_d31:
	/* 0xd31: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_d35:
	/* 0xd35: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d38:
	/* 0xd38: neg    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d3b:
	/* 0xd3b: xor    r15,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_d42:
	/* 0xd42: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d45:
	/* 0xd45: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d4c:
	/* 0xd4c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d4f:
	/* 0xd4f: je     d70 <sys_enter_submit+0xd70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d70;
	}
x86_l_d51:
	/* 0xd51: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d53:
	/* 0xd53: cmp    BYTE PTR [rbx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_d5a:
	/* 0xd5a: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_d5d:
	/* 0xd5d: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d60:
	/* 0xd60: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d63:
	/* 0xd63: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_d6a:
	/* 0xd6a: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d6d:
	/* 0xd6d: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d70:
	/* 0xd70: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_d77:
	/* 0xd77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d7a:
	/* 0xd7a: je     d96 <sys_enter_submit+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d96;
	}
x86_l_d7c:
	/* 0xd7c: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_d80:
	/* 0xd80: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d83:
	/* 0xd83: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_d86:
	/* 0xd86: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d89:
	/* 0xd89: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_d90:
	/* 0xd90: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d93:
	/* 0xd93: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d96:
	/* 0xd96: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_d9d:
	/* 0xd9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_da0:
	/* 0xda0: je     dbe <sys_enter_submit+0xdbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dbe;
	}
x86_l_da2:
	/* 0xda2: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_da5:
	/* 0xda5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_daa:
	/* 0xdaa: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_dae:
	/* 0xdae: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_db1:
	/* 0xdb1: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_db8:
	/* 0xdb8: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dbb:
	/* 0xdbb: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dbe:
	/* 0xdbe: movzx  r13d,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_dc3:
	/* 0xdc3: mov    rbx,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_dca:
	/* 0xdca: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_dcd:
	/* 0xdcd: mov    WORD PTR [rsp+0x18],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dd3:
	/* 0xdd3: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ddb:
	/* 0xddb: je     f43 <sys_enter_submit+0xf43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3907ULL;
	}
x86_l_de1:
	/* 0xde1: mov    rax,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_de8:
	/* 0xde8: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_df0:
	/* 0xdf0: mov    rax,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_df7:
	/* 0xdf7: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_dff:
	/* 0xdff: mov    rax,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_e06:
	/* 0xe06: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_e0e:
	/* 0xe0e: mov    WORD PTR [rsp+0x40],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e14:
	/* 0xe14: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_e1b:
	/* 0xe1b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e20:
	/* 0xe20: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e25:
	/* 0xe25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e27:
	/* 0xe27: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_e2a:
	/* 0xe2a: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e2e:
	/* 0xe2e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e33:
	/* 0xe33: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e3a:
	/* 0xe3a: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_e3d:
	/* 0xe3d: je     e5f <sys_enter_submit+0xe5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e5f;
	}
x86_l_e3f:
	/* 0xe3f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e44:
	/* 0xe44: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e49:
	/* 0xe49: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_e4c:
	/* 0xe4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4e:
	/* 0xe4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e51:
	/* 0xe51: je     e5f <sys_enter_submit+0xe5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e5f;
	}
x86_l_e53:
	/* 0xe53: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e56:
	/* 0xe56: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e5a:
	/* 0xe5a: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e5d:
	/* 0xe5d: jmp    e62 <sys_enter_submit+0xe62> */
	goto x86_l_e62;
x86_l_e5f:
	/* 0xe5f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e62:
	/* 0xe62: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_e6a:
	/* 0xe6a: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e72:
	/* 0xe72: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e77:
	/* 0xe77: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e7a:
	/* 0xe7a: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e7d:
	/* 0xe7d: jb     e95 <sys_enter_submit+0xe95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e95;
	}
x86_l_e7f:
	/* 0xe7f: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e83:
	/* 0xe83: je     e8a <sys_enter_submit+0xe8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e8a;
	}
x86_l_e85:
	/* 0xe85: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e88:
	/* 0xe88: jbe    e95 <sys_enter_submit+0xe95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e95;
	}
x86_l_e8a:
	/* 0xe8a: and    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_e92:
	/* 0xe92: or     r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_e95:
	/* 0xe95: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e99:
	/* 0xe99: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e9e:
	/* 0xe9e: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ea5:
	/* 0xea5: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_ea8:
	/* 0xea8: je     eee <sys_enter_submit+0xeee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eee;
	}
x86_l_eaa:
	/* 0xeaa: mov    QWORD PTR [rsp+0x90],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_eb2:
	/* 0xeb2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_eb7:
	/* 0xeb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ebc:
	/* 0xebc: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_ebf:
	/* 0xebf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec1:
	/* 0xec1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec4:
	/* 0xec4: je     eff <sys_enter_submit+0xeff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eff;
	}
x86_l_ec6:
	/* 0xec6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec9:
	/* 0xec9: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ecd:
	/* 0xecd: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ed0:
	/* 0xed0: jmp    f01 <sys_enter_submit+0xf01> */
	goto x86_l_f01;
x86_l_ed2:
	/* 0xed2: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ed9:
	/* 0xed9: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_ee0:
	/* 0xee0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ee3:
	/* 0xee3: jne    d51 <sys_enter_submit+0xd51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d51;
	}
x86_l_ee9:
	/* 0xee9: jmp    d70 <sys_enter_submit+0xd70> */
	goto x86_l_d70;
x86_l_eee:
	/* 0xeee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ef0:
	/* 0xef0: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ef3:
	/* 0xef3: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ef8:
	/* 0xef8: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_efb:
	/* 0xefb: jae    f1e <sys_enter_submit+0xf1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f1e;
	}
x86_l_efd:
	/* 0xefd: jmp    f34 <sys_enter_submit+0xf34> */
	return 3892ULL;
x86_l_eff:
	/* 0xeff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f01:
	/* 0xf01: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_f09:
	/* 0xf09: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f11:
	/* 0xf11: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f14:
	/* 0xf14: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f19:
	/* 0xf19: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f1c:
	/* 0xf1c: jb     f34 <sys_enter_submit+0xf34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3892ULL;
	}
x86_l_f1e:
	/* 0xf1e: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
	return 3874ULL;
}

static __noinline __u64 tracee_sys_enter_submit_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3874ULL: goto x86_l_f22;
	case 3876ULL: goto x86_l_f24;
	case 3879ULL: goto x86_l_f27;
	case 3881ULL: goto x86_l_f29;
	case 3889ULL: goto x86_l_f31;
	case 3892ULL: goto x86_l_f34;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3901ULL: goto x86_l_f3d;
	case 3907ULL: goto x86_l_f43;
	case 3915ULL: goto x86_l_f4b;
	case 3921ULL: goto x86_l_f51;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3932ULL: goto x86_l_f5c;
	case 3939ULL: goto x86_l_f63;
	case 3946ULL: goto x86_l_f6a;
	case 3954ULL: goto x86_l_f72;
	case 3961ULL: goto x86_l_f79;
	case 3964ULL: goto x86_l_f7c;
	case 3971ULL: goto x86_l_f83;
	case 3976ULL: goto x86_l_f88;
	case 3983ULL: goto x86_l_f8f;
	case 3988ULL: goto x86_l_f94;
	case 3993ULL: goto x86_l_f99;
	case 3995ULL: goto x86_l_f9b;
	case 3998ULL: goto x86_l_f9e;
	case 4002ULL: goto x86_l_fa2;
	case 4007ULL: goto x86_l_fa7;
	case 4014ULL: goto x86_l_fae;
	case 4017ULL: goto x86_l_fb1;
	case 4019ULL: goto x86_l_fb3;
	case 4024ULL: goto x86_l_fb8;
	case 4029ULL: goto x86_l_fbd;
	case 4031ULL: goto x86_l_fbf;
	case 4034ULL: goto x86_l_fc2;
	case 4036ULL: goto x86_l_fc4;
	case 4039ULL: goto x86_l_fc7;
	case 4043ULL: goto x86_l_fcb;
	case 4046ULL: goto x86_l_fce;
	case 4048ULL: goto x86_l_fd0;
	case 4050ULL: goto x86_l_fd2;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4061ULL: goto x86_l_fdd;
	case 4064ULL: goto x86_l_fe0;
	case 4066ULL: goto x86_l_fe2;
	case 4070ULL: goto x86_l_fe6;
	case 4072ULL: goto x86_l_fe8;
	case 4075ULL: goto x86_l_feb;
	case 4077ULL: goto x86_l_fed;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4091ULL: goto x86_l_ffb;
	case 4094ULL: goto x86_l_ffe;
	case 4100ULL: goto x86_l_1004;
	case 4108ULL: goto x86_l_100c;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4126ULL: goto x86_l_101e;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4157ULL: goto x86_l_103d;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4172ULL: goto x86_l_104c;
	case 4177ULL: goto x86_l_1051;
	case 4179ULL: goto x86_l_1053;
	case 4184ULL: goto x86_l_1058;
	case 4189ULL: goto x86_l_105d;
	case 4194ULL: goto x86_l_1062;
	case 4199ULL: goto x86_l_1067;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4211ULL: goto x86_l_1073;
	case 4215ULL: goto x86_l_1077;
	case 4219ULL: goto x86_l_107b;
	case 4226ULL: goto x86_l_1082;
	case 4233ULL: goto x86_l_1089;
	case 4239ULL: goto x86_l_108f;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4256ULL: goto x86_l_10a0;
	case 4259ULL: goto x86_l_10a3;
	case 4261ULL: goto x86_l_10a5;
	case 4268ULL: goto x86_l_10ac;
	case 4271ULL: goto x86_l_10af;
	case 4273ULL: goto x86_l_10b1;
	case 4276ULL: goto x86_l_10b4;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4287ULL: goto x86_l_10bf;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4295ULL: goto x86_l_10c7;
	case 4299ULL: goto x86_l_10cb;
	case 4302ULL: goto x86_l_10ce;
	case 4304ULL: goto x86_l_10d0;
	case 4306ULL: goto x86_l_10d2;
	case 4309ULL: goto x86_l_10d5;
	case 4312ULL: goto x86_l_10d8;
	case 4315ULL: goto x86_l_10db;
	case 4318ULL: goto x86_l_10de;
	case 4324ULL: goto x86_l_10e4;
	case 4332ULL: goto x86_l_10ec;
	case 4338ULL: goto x86_l_10f2;
	case 4345ULL: goto x86_l_10f9;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4369ULL: goto x86_l_1111;
	case 4371ULL: goto x86_l_1113;
	case 4376ULL: goto x86_l_1118;
	case 4381ULL: goto x86_l_111d;
	case 4386ULL: goto x86_l_1122;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4399ULL: goto x86_l_112f;
	case 4401ULL: goto x86_l_1131;
	case 4405ULL: goto x86_l_1135;
	case 4409ULL: goto x86_l_1139;
	case 4413ULL: goto x86_l_113d;
	case 4417ULL: goto x86_l_1141;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4437ULL: goto x86_l_1155;
	case 4439ULL: goto x86_l_1157;
	case 4444ULL: goto x86_l_115c;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4468ULL: goto x86_l_1174;
	case 4470ULL: goto x86_l_1176;
	case 4474ULL: goto x86_l_117a;
	case 4478ULL: goto x86_l_117e;
	case 4485ULL: goto x86_l_1185;
	case 4492ULL: goto x86_l_118c;
	case 4498ULL: goto x86_l_1192;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4518ULL: goto x86_l_11a6;
	case 4520ULL: goto x86_l_11a8;
	case 4527ULL: goto x86_l_11af;
	case 4530ULL: goto x86_l_11b2;
	case 4532ULL: goto x86_l_11b4;
	case 4535ULL: goto x86_l_11b7;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4546ULL: goto x86_l_11c2;
	case 4549ULL: goto x86_l_11c5;
	case 4551ULL: goto x86_l_11c7;
	case 4554ULL: goto x86_l_11ca;
	case 4558ULL: goto x86_l_11ce;
	case 4561ULL: goto x86_l_11d1;
	case 4563ULL: goto x86_l_11d3;
	case 4565ULL: goto x86_l_11d5;
	case 4568ULL: goto x86_l_11d8;
	case 4571ULL: goto x86_l_11db;
	case 4574ULL: goto x86_l_11de;
	case 4577ULL: goto x86_l_11e1;
	case 4583ULL: goto x86_l_11e7;
	case 4591ULL: goto x86_l_11ef;
	case 4597ULL: goto x86_l_11f5;
	case 4602ULL: goto x86_l_11fa;
	case 4609ULL: goto x86_l_1201;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4631ULL: goto x86_l_1217;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4646ULL: goto x86_l_1226;
	case 4651ULL: goto x86_l_122b;
	case 4656ULL: goto x86_l_1230;
	case 4658ULL: goto x86_l_1232;
	case 4663ULL: goto x86_l_1237;
	case 4668ULL: goto x86_l_123c;
	case 4673ULL: goto x86_l_1241;
	case 4678ULL: goto x86_l_1246;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4688ULL: goto x86_l_1250;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4713ULL: goto x86_l_1269;
	case 4715ULL: goto x86_l_126b;
	case 4722ULL: goto x86_l_1272;
	case 4729ULL: goto x86_l_1279;
	case 4735ULL: goto x86_l_127f;
	case 4742ULL: goto x86_l_1286;
	case 4747ULL: goto x86_l_128b;
	case 4752ULL: goto x86_l_1290;
	case 4755ULL: goto x86_l_1293;
	case 4757ULL: goto x86_l_1295;
	case 4764ULL: goto x86_l_129c;
	case 4767ULL: goto x86_l_129f;
	case 4769ULL: goto x86_l_12a1;
	case 4772ULL: goto x86_l_12a4;
	case 4777ULL: goto x86_l_12a9;
	case 4780ULL: goto x86_l_12ac;
	case 4782ULL: goto x86_l_12ae;
	case 4785ULL: goto x86_l_12b1;
	case 4787ULL: goto x86_l_12b3;
	case 4790ULL: goto x86_l_12b6;
	case 4794ULL: goto x86_l_12ba;
	case 4797ULL: goto x86_l_12bd;
	case 4799ULL: goto x86_l_12bf;
	case 4801ULL: goto x86_l_12c1;
	case 4804ULL: goto x86_l_12c4;
	case 4807ULL: goto x86_l_12c7;
	case 4810ULL: goto x86_l_12ca;
	case 4813ULL: goto x86_l_12cd;
	case 4819ULL: goto x86_l_12d3;
	case 4827ULL: goto x86_l_12db;
	case 4833ULL: goto x86_l_12e1;
	case 4837ULL: goto x86_l_12e5;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4857ULL: goto x86_l_12f9;
	case 4864ULL: goto x86_l_1300;
	case 4871ULL: goto x86_l_1307;
	case 4877ULL: goto x86_l_130d;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4894ULL: goto x86_l_131e;
	case 4897ULL: goto x86_l_1321;
	case 4899ULL: goto x86_l_1323;
	case 4906ULL: goto x86_l_132a;
	case 4909ULL: goto x86_l_132d;
	case 4911ULL: goto x86_l_132f;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4922ULL: goto x86_l_133a;
	case 4924ULL: goto x86_l_133c;
	case 4927ULL: goto x86_l_133f;
	case 4929ULL: goto x86_l_1341;
	case 4932ULL: goto x86_l_1344;
	case 4936ULL: goto x86_l_1348;
	case 4939ULL: goto x86_l_134b;
	case 4941ULL: goto x86_l_134d;
	case 4943ULL: goto x86_l_134f;
	case 4951ULL: goto x86_l_1357;
	case 4954ULL: goto x86_l_135a;
	case 4957ULL: goto x86_l_135d;
	case 4960ULL: goto x86_l_1360;
	case 4963ULL: goto x86_l_1363;
	case 4969ULL: goto x86_l_1369;
	case 4976ULL: goto x86_l_1370;
	case 4979ULL: goto x86_l_1373;
	case 4981ULL: goto x86_l_1375;
	case 4986ULL: goto x86_l_137a;
	case 4994ULL: goto x86_l_1382;
	case 5001ULL: goto x86_l_1389;
	case 5004ULL: goto x86_l_138c;
	case 5006ULL: goto x86_l_138e;
	case 5010ULL: goto x86_l_1392;
	case 5014ULL: goto x86_l_1396;
	case 5021ULL: goto x86_l_139d;
	case 5027ULL: goto x86_l_13a3;
	case 5034ULL: goto x86_l_13aa;
	case 5039ULL: goto x86_l_13af;
	case 5044ULL: goto x86_l_13b4;
	case 5047ULL: goto x86_l_13b7;
	case 5049ULL: goto x86_l_13b9;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5061ULL: goto x86_l_13c5;
	case 5064ULL: goto x86_l_13c8;
	case 5069ULL: goto x86_l_13cd;
	case 5074ULL: goto x86_l_13d2;
	case 5076ULL: goto x86_l_13d4;
	case 5079ULL: goto x86_l_13d7;
	case 5081ULL: goto x86_l_13d9;
	case 5084ULL: goto x86_l_13dc;
	case 5088ULL: goto x86_l_13e0;
	case 5091ULL: goto x86_l_13e3;
	case 5093ULL: goto x86_l_13e5;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5101ULL: goto x86_l_13ed;
	case 5104ULL: goto x86_l_13f0;
	case 5107ULL: goto x86_l_13f3;
	case 5113ULL: goto x86_l_13f9;
	case 5120ULL: goto x86_l_1400;
	case 5123ULL: goto x86_l_1403;
	case 5125ULL: goto x86_l_1405;
	case 5132ULL: goto x86_l_140c;
	case 5138ULL: goto x86_l_1412;
	case 5145ULL: goto x86_l_1419;
	case 5150ULL: goto x86_l_141e;
	case 5155ULL: goto x86_l_1423;
	case 5158ULL: goto x86_l_1426;
	case 5160ULL: goto x86_l_1428;
	case 5167ULL: goto x86_l_142f;
	case 5170ULL: goto x86_l_1432;
	case 5172ULL: goto x86_l_1434;
	case 5175ULL: goto x86_l_1437;
	case 5179ULL: goto x86_l_143b;
	case 5184ULL: goto x86_l_1440;
	case 5186ULL: goto x86_l_1442;
	case 5189ULL: goto x86_l_1445;
	case 5191ULL: goto x86_l_1447;
	case 5194ULL: goto x86_l_144a;
	case 5198ULL: goto x86_l_144e;
	case 5201ULL: goto x86_l_1451;
	case 5203ULL: goto x86_l_1453;
	case 5205ULL: goto x86_l_1455;
	case 5208ULL: goto x86_l_1458;
	case 5211ULL: goto x86_l_145b;
	case 5214ULL: goto x86_l_145e;
	case 5217ULL: goto x86_l_1461;
	case 5223ULL: goto x86_l_1467;
	case 5230ULL: goto x86_l_146e;
	case 5233ULL: goto x86_l_1471;
	case 5239ULL: goto x86_l_1477;
	case 5246ULL: goto x86_l_147e;
	case 5252ULL: goto x86_l_1484;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5269ULL: goto x86_l_1495;
	case 5272ULL: goto x86_l_1498;
	case 5274ULL: goto x86_l_149a;
	case 5281ULL: goto x86_l_14a1;
	case 5284ULL: goto x86_l_14a4;
	case 5286ULL: goto x86_l_14a6;
	case 5289ULL: goto x86_l_14a9;
	case 5294ULL: goto x86_l_14ae;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5306ULL: goto x86_l_14ba;
	case 5308ULL: goto x86_l_14bc;
	case 5311ULL: goto x86_l_14bf;
	case 5313ULL: goto x86_l_14c1;
	case 5318ULL: goto x86_l_14c6;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	case 5332ULL: goto x86_l_14d4;
	case 5335ULL: goto x86_l_14d7;
	case 5337ULL: goto x86_l_14d9;
	case 5340ULL: goto x86_l_14dc;
	case 5344ULL: goto x86_l_14e0;
	case 5347ULL: goto x86_l_14e3;
	case 5349ULL: goto x86_l_14e5;
	case 5351ULL: goto x86_l_14e7;
	case 5354ULL: goto x86_l_14ea;
	case 5357ULL: goto x86_l_14ed;
	case 5360ULL: goto x86_l_14f0;
	case 5363ULL: goto x86_l_14f3;
	case 5371ULL: goto x86_l_14fb;
	case 5378ULL: goto x86_l_1502;
	case 5381ULL: goto x86_l_1505;
	case 5389ULL: goto x86_l_150d;
	case 5391ULL: goto x86_l_150f;
	case 5396ULL: goto x86_l_1514;
	case 5400ULL: goto x86_l_1518;
	case 5403ULL: goto x86_l_151b;
	case 5410ULL: goto x86_l_1522;
	case 5417ULL: goto x86_l_1529;
	case 5420ULL: goto x86_l_152c;
	case 5427ULL: goto x86_l_1533;
	case 5435ULL: goto x86_l_153b;
	case 5441ULL: goto x86_l_1541;
	case 5444ULL: goto x86_l_1544;
	case 5448ULL: goto x86_l_1548;
	case 5454ULL: goto x86_l_154e;
	case 5462ULL: goto x86_l_1556;
	case 5465ULL: goto x86_l_1559;
	case 5470ULL: goto x86_l_155e;
	case 5472ULL: goto x86_l_1560;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f22:
	/* 0xf22: je     f29 <sys_enter_submit+0xf29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f29;
	}
x86_l_f24:
	/* 0xf24: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f27:
	/* 0xf27: jbe    f34 <sys_enter_submit+0xf34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f34;
	}
x86_l_f29:
	/* 0xf29: and    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 192ULL);
x86_l_f31:
	/* 0xf31: or     rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_f34:
	/* 0xf34: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f37:
	/* 0xf37: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f3a:
	/* 0xf3a: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_f3d:
	/* 0xf3d: movzx  r13d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_f43:
	/* 0xf43: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_f4b:
	/* 0xf4b: je     1004 <sys_enter_submit+0x1004> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1004;
	}
x86_l_f51:
	/* 0xf51: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_f56:
	/* 0xf56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f58:
	/* 0xf58: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f5c:
	/* 0xf5c: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_f63:
	/* 0xf63: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_f6a:
	/* 0xf6a: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f72:
	/* 0xf72: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_f79:
	/* 0xf79: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_f7c:
	/* 0xf7c: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_f83:
	/* 0xf83: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f88:
	/* 0xf88: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_f8f:
	/* 0xf8f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f94:
	/* 0xf94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f99:
	/* 0xf99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9b:
	/* 0xf9b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f9e:
	/* 0xf9e: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fa2:
	/* 0xfa2: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fa7:
	/* 0xfa7: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fae:
	/* 0xfae: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_fb1:
	/* 0xfb1: je     fd0 <sys_enter_submit+0xfd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fd0;
	}
x86_l_fb3:
	/* 0xfb3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fb8:
	/* 0xfb8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fbd:
	/* 0xfbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbf:
	/* 0xfbf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fc2:
	/* 0xfc2: je     fd0 <sys_enter_submit+0xfd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fd0;
	}
x86_l_fc4:
	/* 0xfc4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc7:
	/* 0xfc7: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fcb:
	/* 0xfcb: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fce:
	/* 0xfce: jmp    fd2 <sys_enter_submit+0xfd2> */
	goto x86_l_fd2;
x86_l_fd0:
	/* 0xfd0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd2:
	/* 0xfd2: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fd5:
	/* 0xfd5: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fda:
	/* 0xfda: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_fdd:
	/* 0xfdd: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_fe0:
	/* 0xfe0: jb     ff8 <sys_enter_submit+0xff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ff8;
	}
x86_l_fe2:
	/* 0xfe2: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fe6:
	/* 0xfe6: je     fed <sys_enter_submit+0xfed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fed;
	}
x86_l_fe8:
	/* 0xfe8: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_feb:
	/* 0xfeb: jbe    ff8 <sys_enter_submit+0xff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ff8;
	}
x86_l_fed:
	/* 0xfed: and    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_ff5:
	/* 0xff5: or     rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_ff8:
	/* 0xff8: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ffb:
	/* 0xffb: and    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ffe:
	/* 0xffe: movzx  r13d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_1004:
	/* 0x1004: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_100c:
	/* 0x100c: je     10e4 <sys_enter_submit+0x10e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10e4;
	}
x86_l_1012:
	/* 0x1012: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1017:
	/* 0x1017: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_101e:
	/* 0x101e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1023:
	/* 0x1023: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1028:
	/* 0x1028: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_102d:
	/* 0x102d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1032:
	/* 0x1032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1034:
	/* 0x1034: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1039:
	/* 0x1039: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_103d:
	/* 0x103d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1042:
	/* 0x1042: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1047:
	/* 0x1047: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_104c:
	/* 0x104c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1051:
	/* 0x1051: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1053:
	/* 0x1053: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1058:
	/* 0x1058: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_105d:
	/* 0x105d: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1062:
	/* 0x1062: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1067:
	/* 0x1067: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_106c:
	/* 0x106c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1071:
	/* 0x1071: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1073:
	/* 0x1073: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1077:
	/* 0x1077: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_107b:
	/* 0x107b: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_1082:
	/* 0x1082: mov    r12,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_1089:
	/* 0x1089: mov    WORD PTR [rsp+0x40],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_108f:
	/* 0x108f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_1096:
	/* 0x1096: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_109b:
	/* 0x109b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10a0:
	/* 0x10a0: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10a3:
	/* 0x10a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a5:
	/* 0x10a5: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10ac:
	/* 0x10ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10af:
	/* 0x10af: je     10d0 <sys_enter_submit+0x10d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d0;
	}
x86_l_10b1:
	/* 0x10b1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10b4:
	/* 0x10b4: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10b8:
	/* 0x10b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10bd:
	/* 0x10bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bf:
	/* 0x10bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10c2:
	/* 0x10c2: je     10d0 <sys_enter_submit+0x10d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d0;
	}
x86_l_10c4:
	/* 0x10c4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c7:
	/* 0x10c7: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10cb:
	/* 0x10cb: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10ce:
	/* 0x10ce: jmp    10d2 <sys_enter_submit+0x10d2> */
	goto x86_l_10d2;
x86_l_10d0:
	/* 0x10d0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d2:
	/* 0x10d2: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10d5:
	/* 0x10d5: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_10d8:
	/* 0x10d8: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10db:
	/* 0x10db: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_10de:
	/* 0x10de: movzx  r13d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_10e4:
	/* 0x10e4: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_10ec:
	/* 0x10ec: je     11e7 <sys_enter_submit+0x11e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e7;
	}
x86_l_10f2:
	/* 0x10f2: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_10f9:
	/* 0x10f9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10fd:
	/* 0x10fd: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1102:
	/* 0x1102: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1107:
	/* 0x1107: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_110c:
	/* 0x110c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1111:
	/* 0x1111: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1113:
	/* 0x1113: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1118:
	/* 0x1118: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_111d:
	/* 0x111d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1122:
	/* 0x1122: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1127:
	/* 0x1127: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_112c:
	/* 0x112c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_112f:
	/* 0x112f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1131:
	/* 0x1131: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1135:
	/* 0x1135: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1139:
	/* 0x1139: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_113d:
	/* 0x113d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1141:
	/* 0x1141: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1146:
	/* 0x1146: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_114b:
	/* 0x114b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1150:
	/* 0x1150: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1155:
	/* 0x1155: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1157:
	/* 0x1157: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_115c:
	/* 0x115c: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1160:
	/* 0x1160: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1165:
	/* 0x1165: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_116a:
	/* 0x116a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_116f:
	/* 0x116f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1174:
	/* 0x1174: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1176:
	/* 0x1176: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_117a:
	/* 0x117a: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_117e:
	/* 0x117e: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1185:
	/* 0x1185: mov    r12,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_118c:
	/* 0x118c: mov    WORD PTR [rsp+0x40],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1192:
	/* 0x1192: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1199:
	/* 0x1199: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_119e:
	/* 0x119e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11a3:
	/* 0x11a3: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11a6:
	/* 0x11a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a8:
	/* 0x11a8: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11af:
	/* 0x11af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11b2:
	/* 0x11b2: je     11d3 <sys_enter_submit+0x11d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d3;
	}
x86_l_11b4:
	/* 0x11b4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11b7:
	/* 0x11b7: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11bb:
	/* 0x11bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11c0:
	/* 0x11c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c2:
	/* 0x11c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11c5:
	/* 0x11c5: je     11d3 <sys_enter_submit+0x11d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d3;
	}
x86_l_11c7:
	/* 0x11c7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ca:
	/* 0x11ca: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ce:
	/* 0x11ce: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11d1:
	/* 0x11d1: jmp    11d5 <sys_enter_submit+0x11d5> */
	goto x86_l_11d5;
x86_l_11d3:
	/* 0x11d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11d5:
	/* 0x11d5: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11d8:
	/* 0x11d8: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_11db:
	/* 0x11db: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11de:
	/* 0x11de: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_11e1:
	/* 0x11e1: movzx  r13d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_11e7:
	/* 0x11e7: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_11ef:
	/* 0x11ef: je     12d3 <sys_enter_submit+0x12d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12d3;
	}
x86_l_11f5:
	/* 0x11f5: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_11fa:
	/* 0x11fa: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1201:
	/* 0x1201: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1206:
	/* 0x1206: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_120b:
	/* 0x120b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1210:
	/* 0x1210: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1215:
	/* 0x1215: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1217:
	/* 0x1217: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_121c:
	/* 0x121c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1221:
	/* 0x1221: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1226:
	/* 0x1226: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_122b:
	/* 0x122b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1230:
	/* 0x1230: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1232:
	/* 0x1232: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1237:
	/* 0x1237: lea    rbx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_123c:
	/* 0x123c: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1241:
	/* 0x1241: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1246:
	/* 0x1246: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1249:
	/* 0x1249: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_124e:
	/* 0x124e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1250:
	/* 0x1250: lea    rbp,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1254:
	/* 0x1254: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1259:
	/* 0x1259: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_125e:
	/* 0x125e: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1261:
	/* 0x1261: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1266:
	/* 0x1266: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1269:
	/* 0x1269: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126b:
	/* 0x126b: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1272:
	/* 0x1272: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1279:
	/* 0x1279: mov    WORD PTR [rsp+0x40],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_127f:
	/* 0x127f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1286:
	/* 0x1286: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_128b:
	/* 0x128b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1290:
	/* 0x1290: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1293:
	/* 0x1293: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1295:
	/* 0x1295: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_129c:
	/* 0x129c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_129f:
	/* 0x129f: je     12bf <sys_enter_submit+0x12bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bf;
	}
x86_l_12a1:
	/* 0x12a1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12a4:
	/* 0x12a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12a9:
	/* 0x12a9: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_12ac:
	/* 0x12ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ae:
	/* 0x12ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12b1:
	/* 0x12b1: je     12bf <sys_enter_submit+0x12bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bf;
	}
x86_l_12b3:
	/* 0x12b3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b6:
	/* 0x12b6: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ba:
	/* 0x12ba: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12bd:
	/* 0x12bd: jmp    12c1 <sys_enter_submit+0x12c1> */
	goto x86_l_12c1;
x86_l_12bf:
	/* 0x12bf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c1:
	/* 0x12c1: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12c4:
	/* 0x12c4: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_12c7:
	/* 0x12c7: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12ca:
	/* 0x12ca: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_12cd:
	/* 0x12cd: movzx  r13d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_12d3:
	/* 0x12d3: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_12db:
	/* 0x12db: je     137a <sys_enter_submit+0x137a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_137a;
	}
x86_l_12e1:
	/* 0x12e1: lea    rbp,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_12e5:
	/* 0x12e5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_12ea:
	/* 0x12ea: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_12ef:
	/* 0x12ef: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_12f2:
	/* 0x12f2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12f7:
	/* 0x12f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f9:
	/* 0x12f9: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1300:
	/* 0x1300: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1307:
	/* 0x1307: mov    WORD PTR [rsp+0x40],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_130d:
	/* 0x130d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1314:
	/* 0x1314: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1319:
	/* 0x1319: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_131e:
	/* 0x131e: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1321:
	/* 0x1321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1323:
	/* 0x1323: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_132a:
	/* 0x132a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_132d:
	/* 0x132d: je     134d <sys_enter_submit+0x134d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_134d;
	}
x86_l_132f:
	/* 0x132f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1332:
	/* 0x1332: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1337:
	/* 0x1337: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_133a:
	/* 0x133a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_133c:
	/* 0x133c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_133f:
	/* 0x133f: je     134d <sys_enter_submit+0x134d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_134d;
	}
x86_l_1341:
	/* 0x1341: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1344:
	/* 0x1344: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1348:
	/* 0x1348: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_134b:
	/* 0x134b: jmp    134f <sys_enter_submit+0x134f> */
	goto x86_l_134f;
x86_l_134d:
	/* 0x134d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134f:
	/* 0x134f: mov    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1357:
	/* 0x1357: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_135a:
	/* 0x135a: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_135d:
	/* 0x135d: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1360:
	/* 0x1360: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1363:
	/* 0x1363: movzx  r13d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_1369:
	/* 0x1369: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1370:
	/* 0x1370: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1373:
	/* 0x1373: jne    138e <sys_enter_submit+0x138e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_138e;
	}
x86_l_1375:
	/* 0x1375: jmp    13f9 <sys_enter_submit+0x13f9> */
	goto x86_l_13f9;
x86_l_137a:
	/* 0x137a: mov    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1382:
	/* 0x1382: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1389:
	/* 0x1389: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_138c:
	/* 0x138c: je     13f9 <sys_enter_submit+0x13f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f9;
	}
x86_l_138e:
	/* 0x138e: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1392:
	/* 0x1392: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1396:
	/* 0x1396: mov    r12,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_139d:
	/* 0x139d: mov    WORD PTR [rsp+0x28],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13a3:
	/* 0x13a3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_13aa:
	/* 0x13aa: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13af:
	/* 0x13af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13b4:
	/* 0x13b4: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13b7:
	/* 0x13b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b9:
	/* 0x13b9: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13c0:
	/* 0x13c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13c3:
	/* 0x13c3: je     13e5 <sys_enter_submit+0x13e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e5;
	}
x86_l_13c5:
	/* 0x13c5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13c8:
	/* 0x13c8: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13cd:
	/* 0x13cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d2:
	/* 0x13d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d4:
	/* 0x13d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13d7:
	/* 0x13d7: je     13e5 <sys_enter_submit+0x13e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e5;
	}
x86_l_13d9:
	/* 0x13d9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13dc:
	/* 0x13dc: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e0:
	/* 0x13e0: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13e3:
	/* 0x13e3: jmp    13e7 <sys_enter_submit+0x13e7> */
	goto x86_l_13e7;
x86_l_13e5:
	/* 0x13e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e7:
	/* 0x13e7: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13ea:
	/* 0x13ea: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_13ed:
	/* 0x13ed: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13f0:
	/* 0x13f0: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_13f3:
	/* 0x13f3: movzx  r13d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_13f9:
	/* 0x13f9: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1400:
	/* 0x1400: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1403:
	/* 0x1403: je     1467 <sys_enter_submit+0x1467> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1467;
	}
x86_l_1405:
	/* 0x1405: mov    r12,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_140c:
	/* 0x140c: mov    WORD PTR [rsp+0x40],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1412:
	/* 0x1412: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1419:
	/* 0x1419: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_141e:
	/* 0x141e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1423:
	/* 0x1423: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1426:
	/* 0x1426: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1428:
	/* 0x1428: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_142f:
	/* 0x142f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1432:
	/* 0x1432: je     1453 <sys_enter_submit+0x1453> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1453;
	}
x86_l_1434:
	/* 0x1434: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1437:
	/* 0x1437: lea    rsi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_143b:
	/* 0x143b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1440:
	/* 0x1440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1442:
	/* 0x1442: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1445:
	/* 0x1445: je     1453 <sys_enter_submit+0x1453> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1453;
	}
x86_l_1447:
	/* 0x1447: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_144a:
	/* 0x144a: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_144e:
	/* 0x144e: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1451:
	/* 0x1451: jmp    1455 <sys_enter_submit+0x1455> */
	goto x86_l_1455;
x86_l_1453:
	/* 0x1453: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1455:
	/* 0x1455: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1458:
	/* 0x1458: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_145b:
	/* 0x145b: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_145e:
	/* 0x145e: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1461:
	/* 0x1461: movzx  r13d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_1467:
	/* 0x1467: mov    rbx,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_146e:
	/* 0x146e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1471:
	/* 0x1471: je     14fb <sys_enter_submit+0x14fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14fb;
	}
x86_l_1477:
	/* 0x1477: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_147e:
	/* 0x147e: mov    WORD PTR [rsp+0x40],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1484:
	/* 0x1484: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_148b:
	/* 0x148b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1490:
	/* 0x1490: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1495:
	/* 0x1495: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1498:
	/* 0x1498: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149a:
	/* 0x149a: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_14a1:
	/* 0x14a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a4:
	/* 0x14a4: je     14e5 <sys_enter_submit+0x14e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14e5;
	}
x86_l_14a6:
	/* 0x14a6: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_14a9:
	/* 0x14a9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ae:
	/* 0x14ae: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_14b2:
	/* 0x14b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14b7:
	/* 0x14b7: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_14ba:
	/* 0x14ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14bc:
	/* 0x14bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14bf:
	/* 0x14bf: jne    14d9 <sys_enter_submit+0x14d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14d9;
	}
x86_l_14c1:
	/* 0x14c1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14c6:
	/* 0x14c6: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ca:
	/* 0x14ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14cf:
	/* 0x14cf: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_14d2:
	/* 0x14d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d4:
	/* 0x14d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14d7:
	/* 0x14d7: je     14e5 <sys_enter_submit+0x14e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14e5;
	}
x86_l_14d9:
	/* 0x14d9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14dc:
	/* 0x14dc: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14e0:
	/* 0x14e0: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14e3:
	/* 0x14e3: jmp    14e7 <sys_enter_submit+0x14e7> */
	goto x86_l_14e7;
x86_l_14e5:
	/* 0x14e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e7:
	/* 0x14e7: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14ea:
	/* 0x14ea: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_14ed:
	/* 0x14ed: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14f0:
	/* 0x14f0: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_14f3:
	/* 0x14f3: mov    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_14fb:
	/* 0x14fb: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1502:
	/* 0x1502: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1505:
	/* 0x1505: mov    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_150d:
	/* 0x150d: je     151b <sys_enter_submit+0x151b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_151b;
	}
x86_l_150f:
	/* 0x150f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1514:
	/* 0x1514: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1518:
	/* 0x1518: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_151b:
	/* 0x151b: and    r15,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1522:
	/* 0x1522: mov    rcx,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1529:
	/* 0x1529: and    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_152c:
	/* 0x152c: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1533:
	/* 0x1533: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_153b:
	/* 0x153b: je     1efc <sys_enter_submit+0x1efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7932ULL;
	}
x86_l_1541:
	/* 0x1541: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_1544:
	/* 0x1544: test   BYTE PTR [rbp+0x4],0x40 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869248ULL);
x86_l_1548:
	/* 0x1548: je     1dcb <sys_enter_submit+0x1dcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7627ULL;
	}
x86_l_154e:
	/* 0x154e: mov    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1556:
	/* 0x1556: mov    eax,DWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1559:
	/* 0x1559: cmp    eax,0xd8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 216ULL);
x86_l_155e:
	/* 0x155e: jle    15ac <sys_enter_submit+0x15ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5548ULL;
	}
x86_l_1560:
	/* 0x1560: lea    ecx,[rax-0x118] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551336ULL);
	return 5478ULL;
}

static __noinline __u64 tracee_sys_enter_submit_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5478ULL: goto x86_l_1566;
	case 5481ULL: goto x86_l_1569;
	case 5487ULL: goto x86_l_156f;
	case 5493ULL: goto x86_l_1575;
	case 5496ULL: goto x86_l_1578;
	case 5498ULL: goto x86_l_157a;
	case 5508ULL: goto x86_l_1584;
	case 5512ULL: goto x86_l_1588;
	case 5518ULL: goto x86_l_158e;
	case 5524ULL: goto x86_l_1594;
	case 5527ULL: goto x86_l_1597;
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	case 5541ULL: goto x86_l_15a5;
	case 5543ULL: goto x86_l_15a7;
	case 5548ULL: goto x86_l_15ac;
	case 5551ULL: goto x86_l_15af;
	case 5553ULL: goto x86_l_15b1;
	case 5555ULL: goto x86_l_15b3;
	case 5565ULL: goto x86_l_15bd;
	case 5569ULL: goto x86_l_15c1;
	case 5571ULL: goto x86_l_15c3;
	case 5574ULL: goto x86_l_15c6;
	case 5577ULL: goto x86_l_15c9;
	case 5579ULL: goto x86_l_15cb;
	case 5584ULL: goto x86_l_15d0;
	case 5587ULL: goto x86_l_15d3;
	case 5589ULL: goto x86_l_15d5;
	case 5595ULL: goto x86_l_15db;
	case 5598ULL: goto x86_l_15de;
	case 5604ULL: goto x86_l_15e4;
	case 5614ULL: goto x86_l_15ee;
	case 5618ULL: goto x86_l_15f2;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5635ULL: goto x86_l_1603;
	case 5639ULL: goto x86_l_1607;
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5664ULL: goto x86_l_1620;
	case 5668ULL: goto x86_l_1624;
	case 5670ULL: goto x86_l_1626;
	case 5677ULL: goto x86_l_162d;
	case 5679ULL: goto x86_l_162f;
	case 5686ULL: goto x86_l_1636;
	case 5688ULL: goto x86_l_1638;
	case 5692ULL: goto x86_l_163c;
	case 5694ULL: goto x86_l_163e;
	case 5699ULL: goto x86_l_1643;
	case 5701ULL: goto x86_l_1645;
	case 5704ULL: goto x86_l_1648;
	case 5710ULL: goto x86_l_164e;
	case 5713ULL: goto x86_l_1651;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5727ULL: goto x86_l_165f;
	case 5732ULL: goto x86_l_1664;
	case 5737ULL: goto x86_l_1669;
	case 5739ULL: goto x86_l_166b;
	case 5744ULL: goto x86_l_1670;
	case 5749ULL: goto x86_l_1675;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5786ULL: goto x86_l_169a;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5803ULL: goto x86_l_16ab;
	case 5808ULL: goto x86_l_16b0;
	case 5811ULL: goto x86_l_16b3;
	case 5817ULL: goto x86_l_16b9;
	case 5821ULL: goto x86_l_16bd;
	case 5826ULL: goto x86_l_16c2;
	case 5831ULL: goto x86_l_16c7;
	case 5836ULL: goto x86_l_16cc;
	case 5841ULL: goto x86_l_16d1;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5851ULL: goto x86_l_16db;
	case 5857ULL: goto x86_l_16e1;
	case 5865ULL: goto x86_l_16e9;
	case 5872ULL: goto x86_l_16f0;
	case 5880ULL: goto x86_l_16f8;
	case 5889ULL: goto x86_l_1701;
	case 5898ULL: goto x86_l_170a;
	case 5907ULL: goto x86_l_1713;
	case 5916ULL: goto x86_l_171c;
	case 5925ULL: goto x86_l_1725;
	case 5934ULL: goto x86_l_172e;
	case 5943ULL: goto x86_l_1737;
	case 5952ULL: goto x86_l_1740;
	case 5960ULL: goto x86_l_1748;
	case 5967ULL: goto x86_l_174f;
	case 5972ULL: goto x86_l_1754;
	case 5977ULL: goto x86_l_1759;
	case 5979ULL: goto x86_l_175b;
	case 5982ULL: goto x86_l_175e;
	case 5988ULL: goto x86_l_1764;
	case 5991ULL: goto x86_l_1767;
	case 5995ULL: goto x86_l_176b;
	case 6000ULL: goto x86_l_1770;
	case 6005ULL: goto x86_l_1775;
	case 6010ULL: goto x86_l_177a;
	case 6015ULL: goto x86_l_177f;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6027ULL: goto x86_l_178b;
	case 6032ULL: goto x86_l_1790;
	case 6037ULL: goto x86_l_1795;
	case 6042ULL: goto x86_l_179a;
	case 6047ULL: goto x86_l_179f;
	case 6052ULL: goto x86_l_17a4;
	case 6054ULL: goto x86_l_17a6;
	case 6059ULL: goto x86_l_17ab;
	case 6065ULL: goto x86_l_17b1;
	case 6069ULL: goto x86_l_17b5;
	case 6074ULL: goto x86_l_17ba;
	case 6079ULL: goto x86_l_17bf;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6092ULL: goto x86_l_17cc;
	case 6094ULL: goto x86_l_17ce;
	case 6099ULL: goto x86_l_17d3;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6113ULL: goto x86_l_17e1;
	case 6118ULL: goto x86_l_17e6;
	case 6123ULL: goto x86_l_17eb;
	case 6128ULL: goto x86_l_17f0;
	case 6133ULL: goto x86_l_17f5;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6150ULL: goto x86_l_1806;
	case 6155ULL: goto x86_l_180b;
	case 6158ULL: goto x86_l_180e;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6196ULL: goto x86_l_1834;
	case 6201ULL: goto x86_l_1839;
	case 6204ULL: goto x86_l_183c;
	case 6210ULL: goto x86_l_1842;
	case 6215ULL: goto x86_l_1847;
	case 6218ULL: goto x86_l_184a;
	case 6224ULL: goto x86_l_1850;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6248ULL: goto x86_l_1868;
	case 6250ULL: goto x86_l_186a;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6261ULL: goto x86_l_1875;
	case 6267ULL: goto x86_l_187b;
	case 6269ULL: goto x86_l_187d;
	case 6271ULL: goto x86_l_187f;
	case 6277ULL: goto x86_l_1885;
	case 6280ULL: goto x86_l_1888;
	case 6285ULL: goto x86_l_188d;
	case 6287ULL: goto x86_l_188f;
	case 6290ULL: goto x86_l_1892;
	case 6296ULL: goto x86_l_1898;
	case 6299ULL: goto x86_l_189b;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6330ULL: goto x86_l_18ba;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6345ULL: goto x86_l_18c9;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6358ULL: goto x86_l_18d6;
	case 6363ULL: goto x86_l_18db;
	case 6365ULL: goto x86_l_18dd;
	case 6367ULL: goto x86_l_18df;
	case 6372ULL: goto x86_l_18e4;
	case 6375ULL: goto x86_l_18e7;
	case 6381ULL: goto x86_l_18ed;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6397ULL: goto x86_l_18fd;
	case 6400ULL: goto x86_l_1900;
	case 6404ULL: goto x86_l_1904;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6435ULL: goto x86_l_1923;
	case 6440ULL: goto x86_l_1928;
	case 6445ULL: goto x86_l_192d;
	case 6450ULL: goto x86_l_1932;
	case 6455ULL: goto x86_l_1937;
	case 6460ULL: goto x86_l_193c;
	case 6465ULL: goto x86_l_1941;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6492ULL: goto x86_l_195c;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6504ULL: goto x86_l_1968;
	case 6508ULL: goto x86_l_196c;
	case 6513ULL: goto x86_l_1971;
	case 6518ULL: goto x86_l_1976;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6541ULL: goto x86_l_198d;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6553ULL: goto x86_l_1999;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6577ULL: goto x86_l_19b1;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6589ULL: goto x86_l_19bd;
	case 6594ULL: goto x86_l_19c2;
	case 6597ULL: goto x86_l_19c5;
	case 6599ULL: goto x86_l_19c7;
	case 6603ULL: goto x86_l_19cb;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6618ULL: goto x86_l_19da;
	case 6623ULL: goto x86_l_19df;
	case 6625ULL: goto x86_l_19e1;
	case 6629ULL: goto x86_l_19e5;
	case 6631ULL: goto x86_l_19e7;
	case 6637ULL: goto x86_l_19ed;
	case 6642ULL: goto x86_l_19f2;
	case 6644ULL: goto x86_l_19f4;
	case 6646ULL: goto x86_l_19f6;
	case 6648ULL: goto x86_l_19f8;
	case 6651ULL: goto x86_l_19fb;
	case 6656ULL: goto x86_l_1a00;
	case 6659ULL: goto x86_l_1a03;
	case 6661ULL: goto x86_l_1a05;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6675ULL: goto x86_l_1a13;
	case 6681ULL: goto x86_l_1a19;
	case 6686ULL: goto x86_l_1a1e;
	case 6691ULL: goto x86_l_1a23;
	case 6697ULL: goto x86_l_1a29;
	case 6700ULL: goto x86_l_1a2c;
	case 6703ULL: goto x86_l_1a2f;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6712ULL: goto x86_l_1a38;
	case 6715ULL: goto x86_l_1a3b;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6729ULL: goto x86_l_1a49;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6745ULL: goto x86_l_1a59;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6772ULL: goto x86_l_1a74;
	case 6775ULL: goto x86_l_1a77;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6814ULL: goto x86_l_1a9e;
	case 6819ULL: goto x86_l_1aa3;
	case 6821ULL: goto x86_l_1aa5;
	case 6826ULL: goto x86_l_1aaa;
	case 6831ULL: goto x86_l_1aaf;
	case 6836ULL: goto x86_l_1ab4;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6873ULL: goto x86_l_1ad9;
	case 6878ULL: goto x86_l_1ade;
	case 6883ULL: goto x86_l_1ae3;
	case 6885ULL: goto x86_l_1ae5;
	case 6890ULL: goto x86_l_1aea;
	case 6894ULL: goto x86_l_1aee;
	case 6899ULL: goto x86_l_1af3;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6914ULL: goto x86_l_1b02;
	case 6917ULL: goto x86_l_1b05;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6963ULL: goto x86_l_1b33;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6977ULL: goto x86_l_1b41;
	case 6979ULL: goto x86_l_1b43;
	case 6983ULL: goto x86_l_1b47;
	case 6988ULL: goto x86_l_1b4c;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7005ULL: goto x86_l_1b5d;
	case 7009ULL: goto x86_l_1b61;
	case 7011ULL: goto x86_l_1b63;
	case 7017ULL: goto x86_l_1b69;
	case 7022ULL: goto x86_l_1b6e;
	case 7024ULL: goto x86_l_1b70;
	case 7026ULL: goto x86_l_1b72;
	case 7032ULL: goto x86_l_1b78;
	case 7037ULL: goto x86_l_1b7d;
	case 7042ULL: goto x86_l_1b82;
	case 7049ULL: goto x86_l_1b89;
	case 7052ULL: goto x86_l_1b8c;
	case 7056ULL: goto x86_l_1b90;
	case 7061ULL: goto x86_l_1b95;
	case 7066ULL: goto x86_l_1b9a;
	case 7071ULL: goto x86_l_1b9f;
	case 7073ULL: goto x86_l_1ba1;
	case 7076ULL: goto x86_l_1ba4;
	case 7082ULL: goto x86_l_1baa;
	case 7086ULL: goto x86_l_1bae;
	case 7091ULL: goto x86_l_1bb3;
	case 7096ULL: goto x86_l_1bb8;
	case 7099ULL: goto x86_l_1bbb;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7121ULL: goto x86_l_1bd1;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7156ULL: goto x86_l_1bf4;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7183ULL: goto x86_l_1c0f;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1566:
	/* 0x1566: cmp    ecx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 52ULL);
x86_l_1569:
	/* 0x1569: jbe    15f9 <sys_enter_submit+0x15f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_15f9;
	}
x86_l_156f:
	/* 0x156f: lea    ecx,[rax-0xd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551399ULL);
x86_l_1575:
	/* 0x1575: cmp    ecx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 61ULL);
x86_l_1578:
	/* 0x1578: ja     158e <sys_enter_submit+0x158e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_158e;
	}
x86_l_157a:
	/* 0x157a: movabs rdx,0x301e7f6000008011 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 3467348813415481361ULL);
x86_l_1584:
	/* 0x1584: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1588:
	/* 0x1588: jb     160d <sys_enter_submit+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_160d;
	}
x86_l_158e:
	/* 0x158e: lea    ecx,[rax-0x1a8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551192ULL);
x86_l_1594:
	/* 0x1594: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1597:
	/* 0x1597: ja     1dd6 <sys_enter_submit+0x1dd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7638ULL;
	}
x86_l_159d:
	/* 0x159d: mov    edx,0x16fa39d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24093597ULL);
x86_l_15a2:
	/* 0x15a2: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_15a5:
	/* 0x15a5: jb     160d <sys_enter_submit+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_160d;
	}
x86_l_15a7:
	/* 0x15a7: jmp    1dd6 <sys_enter_submit+0x1dd6> */
	return 7638ULL;
x86_l_15ac:
	/* 0x15ac: cmp    eax,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 55ULL);
x86_l_15af:
	/* 0x15af: ja     15c3 <sys_enter_submit+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15c3;
	}
x86_l_15b1:
	/* 0x15b1: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_15b3:
	/* 0x15b3: movabs rdx,0xdffc01001f032b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 63046001033675563ULL);
x86_l_15bd:
	/* 0x15bd: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_15c1:
	/* 0x15c1: jb     160d <sys_enter_submit+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_160d;
	}
x86_l_15c3:
	/* 0x15c3: lea    ecx,[rax-0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551544ULL);
x86_l_15c6:
	/* 0x15c6: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_15c9:
	/* 0x15c9: ja     15d5 <sys_enter_submit+0x15d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15d5;
	}
x86_l_15cb:
	/* 0x15cb: mov    edx,0x28026f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2622063ULL);
x86_l_15d0:
	/* 0x15d0: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_15d3:
	/* 0x15d3: jb     160d <sys_enter_submit+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_160d;
	}
x86_l_15d5:
	/* 0x15d5: lea    ecx,[rax-0x8a] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551478ULL);
x86_l_15db:
	/* 0x15db: cmp    ecx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 61ULL);
x86_l_15de:
	/* 0x15de: ja     1dd6 <sys_enter_submit+0x1dd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7638ULL;
	}
x86_l_15e4:
	/* 0x15e4: movabs rdx,0x2492000000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2635168731965161473ULL);
x86_l_15ee:
	/* 0x15ee: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_15f2:
	/* 0x15f2: jb     160d <sys_enter_submit+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_160d;
	}
x86_l_15f4:
	/* 0x15f4: jmp    1dd6 <sys_enter_submit+0x1dd6> */
	return 7638ULL;
x86_l_15f9:
	/* 0x15f9: movabs rdx,0x1184021d8d83e7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 4930219224695783ULL);
x86_l_1603:
	/* 0x1603: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1607:
	/* 0x1607: jae    156f <sys_enter_submit+0x156f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_156f;
	}
x86_l_160d:
	/* 0x160d: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1610:
	/* 0x1610: je     162f <sys_enter_submit+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_162f;
	}
x86_l_1612:
	/* 0x1612: cmp    eax,0x12a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 298ULL);
x86_l_1617:
	/* 0x1617: je     1626 <sys_enter_submit+0x1626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1626;
	}
x86_l_1619:
	/* 0x1619: cmp    eax,0x10a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 266ULL);
x86_l_161e:
	/* 0x161e: jne    1638 <sys_enter_submit+0x1638> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1638;
	}
x86_l_1620:
	/* 0x1620: lea    rax,[rbx+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1624:
	/* 0x1624: jmp    163c <sys_enter_submit+0x163c> */
	goto x86_l_163c;
x86_l_1626:
	/* 0x1626: lea    rax,[rbx+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_162d:
	/* 0x162d: jmp    163c <sys_enter_submit+0x163c> */
	goto x86_l_163c;
x86_l_162f:
	/* 0x162f: lea    rax,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1636:
	/* 0x1636: jmp    163c <sys_enter_submit+0x163c> */
	goto x86_l_163c;
x86_l_1638:
	/* 0x1638: lea    rax,[rbx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_163c:
	/* 0x163c: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163e:
	/* 0x163e: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_1643:
	/* 0x1643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1645:
	/* 0x1645: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1648:
	/* 0x1648: je     1dcb <sys_enter_submit+0x1dcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7627ULL;
	}
x86_l_164e:
	/* 0x164e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1651:
	/* 0x1651: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1655:
	/* 0x1655: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_165a:
	/* 0x165a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_165f:
	/* 0x165f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1664:
	/* 0x1664: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1669:
	/* 0x1669: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166b:
	/* 0x166b: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1670:
	/* 0x1670: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1675:
	/* 0x1675: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_167a:
	/* 0x167a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_167f:
	/* 0x167f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1684:
	/* 0x1684: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1689:
	/* 0x1689: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168b:
	/* 0x168b: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1690:
	/* 0x1690: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1695:
	/* 0x1695: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_169a:
	/* 0x169a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_169f:
	/* 0x169f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16a4:
	/* 0x16a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a9:
	/* 0x16a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ab:
	/* 0x16ab: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16b0:
	/* 0x16b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b3:
	/* 0x16b3: je     1dcb <sys_enter_submit+0x1dcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7627ULL;
	}
x86_l_16b9:
	/* 0x16b9: lea    rdx,[rax+rbx*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 0ULL);
x86_l_16bd:
	/* 0x16bd: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16c2:
	/* 0x16c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16c7:
	/* 0x16c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16cc:
	/* 0x16cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16d1:
	/* 0x16d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d3:
	/* 0x16d3: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16d8:
	/* 0x16d8: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_16db:
	/* 0x16db: je     1dcb <sys_enter_submit+0x1dcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7627ULL;
	}
x86_l_16e1:
	/* 0x16e1: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16e9:
	/* 0x16e9: mov    rax,QWORD PTR [rax+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_16f0:
	/* 0x16f0: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_16f8:
	/* 0x16f8: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1701:
	/* 0x1701: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_170a:
	/* 0x170a: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1713:
	/* 0x1713: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_171c:
	/* 0x171c: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1725:
	/* 0x1725: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_172e:
	/* 0x172e: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1737:
	/* 0x1737: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1740:
	/* 0x1740: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1748:
	/* 0x1748: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_174f:
	/* 0x174f: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1754:
	/* 0x1754: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1759:
	/* 0x1759: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175b:
	/* 0x175b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_175e:
	/* 0x175e: je     18ba <sys_enter_submit+0x18ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ba;
	}
x86_l_1764:
	/* 0x1764: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1767:
	/* 0x1767: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_176b:
	/* 0x176b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1770:
	/* 0x1770: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1775:
	/* 0x1775: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_177a:
	/* 0x177a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_177f:
	/* 0x177f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1781:
	/* 0x1781: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1786:
	/* 0x1786: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_178b:
	/* 0x178b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1790:
	/* 0x1790: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1795:
	/* 0x1795: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_179a:
	/* 0x179a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_179f:
	/* 0x179f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17a4:
	/* 0x17a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a6:
	/* 0x17a6: test   BYTE PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691872ULL);
x86_l_17ab:
	/* 0x17ab: jne    18c2 <sys_enter_submit+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18c2;
	}
x86_l_17b1:
	/* 0x17b1: add    rbp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17b5:
	/* 0x17b5: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17ba:
	/* 0x17ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17bf:
	/* 0x17bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17c4:
	/* 0x17c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17c9:
	/* 0x17c9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_17cc:
	/* 0x17cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ce:
	/* 0x17ce: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17d3:
	/* 0x17d3: lea    rcx,[rbp-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_17d7:
	/* 0x17d7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17dc:
	/* 0x17dc: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17e1:
	/* 0x17e1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_17e6:
	/* 0x17e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17eb:
	/* 0x17eb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f0:
	/* 0x17f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f5:
	/* 0x17f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f7:
	/* 0x17f7: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17fc:
	/* 0x17fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1801:
	/* 0x1801: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1806:
	/* 0x1806: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_180b:
	/* 0x180b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_180e:
	/* 0x180e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1810:
	/* 0x1810: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1815:
	/* 0x1815: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_181a:
	/* 0x181a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_181e:
	/* 0x181e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1823:
	/* 0x1823: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1828:
	/* 0x1828: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_182d:
	/* 0x182d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1832:
	/* 0x1832: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1834:
	/* 0x1834: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1839:
	/* 0x1839: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_183c:
	/* 0x183c: je     18e4 <sys_enter_submit+0x18e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18e4;
	}
x86_l_1842:
	/* 0x1842: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1847:
	/* 0x1847: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_184a:
	/* 0x184a: je     18e4 <sys_enter_submit+0x18e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18e4;
	}
x86_l_1850:
	/* 0x1850: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1854:
	/* 0x1854: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1859:
	/* 0x1859: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_185e:
	/* 0x185e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1863:
	/* 0x1863: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1868:
	/* 0x1868: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186a:
	/* 0x186a: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_186e:
	/* 0x186e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1873:
	/* 0x1873: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1875:
	/* 0x1875: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_187b:
	/* 0x187b: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_187d:
	/* 0x187d: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_187f:
	/* 0x187f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1885:
	/* 0x1885: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1888:
	/* 0x1888: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_188d:
	/* 0x188d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188f:
	/* 0x188f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1892:
	/* 0x1892: jl     1bd7 <sys_enter_submit+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1bd7;
	}
x86_l_1898:
	/* 0x1898: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_189b:
	/* 0x189b: mov    BYTE PTR [r12+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_18a4:
	/* 0x18a4: mov    ecx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16384ULL);
x86_l_18a9:
	/* 0x18a9: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_18ab:
	/* 0x18ab: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b0:
	/* 0x18b0: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18b5:
	/* 0x18b5: jmp    1976 <sys_enter_submit+0x1976> */
	goto x86_l_1976;
x86_l_18ba:
	/* 0x18ba: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18bd:
	/* 0x18bd: jmp    1d92 <sys_enter_submit+0x1d92> */
	return 7570ULL;
x86_l_18c2:
	/* 0x18c2: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_18c9:
	/* 0x18c9: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_18ce:
	/* 0x18ce: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_18d3:
	/* 0x18d3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_18d6:
	/* 0x18d6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18db:
	/* 0x18db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18dd:
	/* 0x18dd: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18df:
	/* 0x18df: jmp    1d8f <sys_enter_submit+0x1d8f> */
	return 7567ULL;
x86_l_18e4:
	/* 0x18e4: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_18e7:
	/* 0x18e7: jne    1bd7 <sys_enter_submit+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bd7;
	}
x86_l_18ed:
	/* 0x18ed: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f2:
	/* 0x18f2: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_18f7:
	/* 0x18f7: je     1bd7 <sys_enter_submit+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd7;
	}
x86_l_18fd:
	/* 0x18fd: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_1900:
	/* 0x1900: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1904:
	/* 0x1904: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1909:
	/* 0x1909: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_190e:
	/* 0x190e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1913:
	/* 0x1913: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1918:
	/* 0x1918: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_191c:
	/* 0x191c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1921:
	/* 0x1921: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1923:
	/* 0x1923: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1928:
	/* 0x1928: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_192d:
	/* 0x192d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1932:
	/* 0x1932: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1937:
	/* 0x1937: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193c:
	/* 0x193c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1941:
	/* 0x1941: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1943:
	/* 0x1943: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1948:
	/* 0x1948: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_194d:
	/* 0x194d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1952:
	/* 0x1952: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1957:
	/* 0x1957: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_195c:
	/* 0x195c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1961:
	/* 0x1961: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1963:
	/* 0x1963: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1968:
	/* 0x1968: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_196c:
	/* 0x196c: mov    eax,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16384ULL);
x86_l_1971:
	/* 0x1971: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1976:
	/* 0x1976: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_197b:
	/* 0x197b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1980:
	/* 0x1980: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1985:
	/* 0x1985: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_198a:
	/* 0x198a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_198d:
	/* 0x198d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_198f:
	/* 0x198f: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1994:
	/* 0x1994: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1999:
	/* 0x1999: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_199d:
	/* 0x199d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19a2:
	/* 0x19a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19a7:
	/* 0x19a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19ac:
	/* 0x19ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19b1:
	/* 0x19b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b3:
	/* 0x19b3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19b8:
	/* 0x19b8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_19bb:
	/* 0x19bb: je     1a00 <sys_enter_submit+0x1a00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a00;
	}
x86_l_19bd:
	/* 0x19bd: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19c2:
	/* 0x19c2: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19c5:
	/* 0x19c5: je     1a00 <sys_enter_submit+0x1a00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a00;
	}
x86_l_19c7:
	/* 0x19c7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_19cb:
	/* 0x19cb: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19d0:
	/* 0x19d0: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_19d5:
	/* 0x19d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19da:
	/* 0x19da: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_19df:
	/* 0x19df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e1:
	/* 0x19e1: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_19e5:
	/* 0x19e5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_19e7:
	/* 0x19e7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19ed:
	/* 0x19ed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f2:
	/* 0x19f2: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_19f4:
	/* 0x19f4: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19f6:
	/* 0x19f6: jae    1a1e <sys_enter_submit+0x1a1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a1e;
	}
x86_l_19f8:
	/* 0x19f8: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_19fb:
	/* 0x19fb: jmp    1d6a <sys_enter_submit+0x1d6a> */
	return 7530ULL;
x86_l_1a00:
	/* 0x1a00: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a03:
	/* 0x1a03: je     1a6a <sys_enter_submit+0x1a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a6a;
	}
x86_l_1a05:
	/* 0x1a05: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1a08:
	/* 0x1a08: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a0d:
	/* 0x1a0d: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_1a13:
	/* 0x1a13: je     1bd7 <sys_enter_submit+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd7;
	}
x86_l_1a19:
	/* 0x1a19: jmp    1d6a <sys_enter_submit+0x1d6a> */
	return 7530ULL;
x86_l_1a1e:
	/* 0x1a1e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a23:
	/* 0x1a23: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1a29:
	/* 0x1a29: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1a2c:
	/* 0x1a2c: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a2f:
	/* 0x1a2f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1a31:
	/* 0x1a31: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1a36:
	/* 0x1a36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a38:
	/* 0x1a38: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a3b:
	/* 0x1a3b: jl     1bc6 <sys_enter_submit+0x1bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1bc6;
	}
x86_l_1a41:
	/* 0x1a41: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a46:
	/* 0x1a46: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1a49:
	/* 0x1a49: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a54:
	/* 0x1a54: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1a59:
	/* 0x1a59: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1a5b:
	/* 0x1a5b: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a60:
	/* 0x1a60: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a65:
	/* 0x1a65: jmp    1aee <sys_enter_submit+0x1aee> */
	goto x86_l_1aee;
x86_l_1a6a:
	/* 0x1a6a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a6f:
	/* 0x1a6f: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1a74:
	/* 0x1a74: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1a77:
	/* 0x1a77: je     1bc6 <sys_enter_submit+0x1bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bc6;
	}
x86_l_1a7d:
	/* 0x1a7d: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a82:
	/* 0x1a82: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a86:
	/* 0x1a86: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a8b:
	/* 0x1a8b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a90:
	/* 0x1a90: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a95:
	/* 0x1a95: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a9a:
	/* 0x1a9a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a9e:
	/* 0x1a9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa3:
	/* 0x1aa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa5:
	/* 0x1aa5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aaa:
	/* 0x1aaa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aaf:
	/* 0x1aaf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ab4:
	/* 0x1ab4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ab9:
	/* 0x1ab9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1abe:
	/* 0x1abe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ac3:
	/* 0x1ac3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac5:
	/* 0x1ac5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aca:
	/* 0x1aca: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1acf:
	/* 0x1acf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ad4:
	/* 0x1ad4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ad9:
	/* 0x1ad9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ade:
	/* 0x1ade: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae3:
	/* 0x1ae3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae5:
	/* 0x1ae5: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aea:
	/* 0x1aea: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1aee:
	/* 0x1aee: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1af3:
	/* 0x1af3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1af8:
	/* 0x1af8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1afd:
	/* 0x1afd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b02:
	/* 0x1b02: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b05:
	/* 0x1b05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b07:
	/* 0x1b07: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b11:
	/* 0x1b11: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b15:
	/* 0x1b15: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b1a:
	/* 0x1b1a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b1f:
	/* 0x1b1f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b24:
	/* 0x1b24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b29:
	/* 0x1b29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2b:
	/* 0x1b2b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b30:
	/* 0x1b30: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b33:
	/* 0x1b33: je     1bb8 <sys_enter_submit+0x1bb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb8;
	}
x86_l_1b39:
	/* 0x1b39: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b3e:
	/* 0x1b3e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b41:
	/* 0x1b41: je     1bb8 <sys_enter_submit+0x1bb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb8;
	}
x86_l_1b43:
	/* 0x1b43: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b47:
	/* 0x1b47: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b51:
	/* 0x1b51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b56:
	/* 0x1b56: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b5b:
	/* 0x1b5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5d:
	/* 0x1b5d: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1b61:
	/* 0x1b61: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1b63:
	/* 0x1b63: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b69:
	/* 0x1b69: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b6e:
	/* 0x1b6e: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_1b70:
	/* 0x1b70: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b72:
	/* 0x1b72: jae    1c16 <sys_enter_submit+0x1c16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1c16;
	}
x86_l_1b78:
	/* 0x1b78: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b7d:
	/* 0x1b7d: jmp    1d6a <sys_enter_submit+0x1d6a> */
	return 7530ULL;
x86_l_1b82:
	/* 0x1b82: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1b89:
	/* 0x1b89: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b8c:
	/* 0x1b8c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b90:
	/* 0x1b90: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1b95:
	/* 0x1b95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1b9f:
	/* 0x1b9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba1:
	/* 0x1ba1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ba4:
	/* 0x1ba4: jne    1f13 <sys_enter_submit+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7955ULL;
	}
x86_l_1baa:
	/* 0x1baa: movzx  eax,WORD PTR [rbp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_1bae:
	/* 0x1bae: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_1bb3:
	/* 0x1bb3: jmp    bc3 <sys_enter_submit+0xbc3> */
	return 3011ULL;
x86_l_1bb8:
	/* 0x1bb8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1bbb:
	/* 0x1bbb: je     1c58 <sys_enter_submit+0x1c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7256ULL;
	}
x86_l_1bc1:
	/* 0x1bc1: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bcb:
	/* 0x1bcb: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_1bd1:
	/* 0x1bd1: jne    1d6a <sys_enter_submit+0x1d6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7530ULL;
	}
x86_l_1bd7:
	/* 0x1bd7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bdc:
	/* 0x1bdc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1be0:
	/* 0x1be0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1be5:
	/* 0x1be5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1bea:
	/* 0x1bea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bef:
	/* 0x1bef: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1bf4:
	/* 0x1bf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf6:
	/* 0x1bf6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1c00:
	/* 0x1c00: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1c05:
	/* 0x1c05: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1c08:
	/* 0x1c08: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c0d:
	/* 0x1c0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0f:
	/* 0x1c0f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c11:
	/* 0x1c11: jmp    1d87 <sys_enter_submit+0x1d87> */
	return 7559ULL;
x86_l_1c16:
	/* 0x1c16: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 7195ULL;
}

static __noinline __u64 tracee_sys_enter_submit_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7195ULL: goto x86_l_1c1b;
	case 7201ULL: goto x86_l_1c21;
	case 7206ULL: goto x86_l_1c26;
	case 7209ULL: goto x86_l_1c29;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7218ULL: goto x86_l_1c32;
	case 7221ULL: goto x86_l_1c35;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7231ULL: goto x86_l_1c3f;
	case 7237ULL: goto x86_l_1c45;
	case 7242ULL: goto x86_l_1c4a;
	case 7244ULL: goto x86_l_1c4c;
	case 7249ULL: goto x86_l_1c51;
	case 7254ULL: goto x86_l_1c56;
	case 7256ULL: goto x86_l_1c58;
	case 7261ULL: goto x86_l_1c5d;
	case 7266ULL: goto x86_l_1c62;
	case 7272ULL: goto x86_l_1c68;
	case 7276ULL: goto x86_l_1c6c;
	case 7281ULL: goto x86_l_1c71;
	case 7286ULL: goto x86_l_1c76;
	case 7291ULL: goto x86_l_1c7b;
	case 7296ULL: goto x86_l_1c80;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7349ULL: goto x86_l_1cb5;
	case 7354ULL: goto x86_l_1cba;
	case 7359ULL: goto x86_l_1cbf;
	case 7364ULL: goto x86_l_1cc4;
	case 7369ULL: goto x86_l_1cc9;
	case 7371ULL: goto x86_l_1ccb;
	case 7376ULL: goto x86_l_1cd0;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7390ULL: goto x86_l_1cde;
	case 7395ULL: goto x86_l_1ce3;
	case 7400ULL: goto x86_l_1ce8;
	case 7403ULL: goto x86_l_1ceb;
	case 7405ULL: goto x86_l_1ced;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7439ULL: goto x86_l_1d0f;
	case 7441ULL: goto x86_l_1d11;
	case 7446ULL: goto x86_l_1d16;
	case 7449ULL: goto x86_l_1d19;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7463ULL: goto x86_l_1d27;
	case 7469ULL: goto x86_l_1d2d;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7483ULL: goto x86_l_1d3b;
	case 7488ULL: goto x86_l_1d40;
	case 7493ULL: goto x86_l_1d45;
	case 7495ULL: goto x86_l_1d47;
	case 7499ULL: goto x86_l_1d4b;
	case 7501ULL: goto x86_l_1d4d;
	case 7507ULL: goto x86_l_1d53;
	case 7512ULL: goto x86_l_1d58;
	case 7514ULL: goto x86_l_1d5a;
	case 7520ULL: goto x86_l_1d60;
	case 7525ULL: goto x86_l_1d65;
	case 7530ULL: goto x86_l_1d6a;
	case 7532ULL: goto x86_l_1d6c;
	case 7534ULL: goto x86_l_1d6e;
	case 7539ULL: goto x86_l_1d73;
	case 7544ULL: goto x86_l_1d78;
	case 7553ULL: goto x86_l_1d81;
	case 7559ULL: goto x86_l_1d87;
	case 7567ULL: goto x86_l_1d8f;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7585ULL: goto x86_l_1da1;
	case 7588ULL: goto x86_l_1da4;
	case 7593ULL: goto x86_l_1da9;
	case 7596ULL: goto x86_l_1dac;
	case 7598ULL: goto x86_l_1dae;
	case 7605ULL: goto x86_l_1db5;
	case 7607ULL: goto x86_l_1db7;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7623ULL: goto x86_l_1dc7;
	case 7625ULL: goto x86_l_1dc9;
	case 7627ULL: goto x86_l_1dcb;
	case 7635ULL: goto x86_l_1dd3;
	case 7638ULL: goto x86_l_1dd6;
	case 7641ULL: goto x86_l_1dd9;
	case 7647ULL: goto x86_l_1ddf;
	case 7654ULL: goto x86_l_1de6;
	case 7660ULL: goto x86_l_1dec;
	case 7663ULL: goto x86_l_1def;
	case 7667ULL: goto x86_l_1df3;
	case 7675ULL: goto x86_l_1dfb;
	case 7682ULL: goto x86_l_1e02;
	case 7684ULL: goto x86_l_1e04;
	case 7693ULL: goto x86_l_1e0d;
	case 7699ULL: goto x86_l_1e13;
	case 7701ULL: goto x86_l_1e15;
	case 7709ULL: goto x86_l_1e1d;
	case 7713ULL: goto x86_l_1e21;
	case 7717ULL: goto x86_l_1e25;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7739ULL: goto x86_l_1e3b;
	case 7741ULL: goto x86_l_1e3d;
	case 7744ULL: goto x86_l_1e40;
	case 7746ULL: goto x86_l_1e42;
	case 7749ULL: goto x86_l_1e45;
	case 7757ULL: goto x86_l_1e4d;
	case 7764ULL: goto x86_l_1e54;
	case 7768ULL: goto x86_l_1e58;
	case 7772ULL: goto x86_l_1e5c;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7784ULL: goto x86_l_1e68;
	case 7792ULL: goto x86_l_1e70;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7802ULL: goto x86_l_1e7a;
	case 7806ULL: goto x86_l_1e7e;
	case 7810ULL: goto x86_l_1e82;
	case 7814ULL: goto x86_l_1e86;
	case 7819ULL: goto x86_l_1e8b;
	case 7822ULL: goto x86_l_1e8e;
	case 7825ULL: goto x86_l_1e91;
	case 7828ULL: goto x86_l_1e94;
	case 7834ULL: goto x86_l_1e9a;
	case 7836ULL: goto x86_l_1e9c;
	case 7843ULL: goto x86_l_1ea3;
	case 7848ULL: goto x86_l_1ea8;
	case 7853ULL: goto x86_l_1ead;
	case 7858ULL: goto x86_l_1eb2;
	case 7861ULL: goto x86_l_1eb5;
	case 7863ULL: goto x86_l_1eb7;
	case 7865ULL: goto x86_l_1eb9;
	case 7867ULL: goto x86_l_1ebb;
	case 7871ULL: goto x86_l_1ebf;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7892ULL: goto x86_l_1ed4;
	case 7898ULL: goto x86_l_1eda;
	case 7902ULL: goto x86_l_1ede;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7927ULL: goto x86_l_1ef7;
	case 7930ULL: goto x86_l_1efa;
	case 7932ULL: goto x86_l_1efc;
	case 7935ULL: goto x86_l_1eff;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7950ULL: goto x86_l_1f0e;
	case 7953ULL: goto x86_l_1f11;
	case 7955ULL: goto x86_l_1f13;
	case 7957ULL: goto x86_l_1f15;
	case 7964ULL: goto x86_l_1f1c;
	case 7965ULL: goto x86_l_1f1d;
	case 7967ULL: goto x86_l_1f1f;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7973ULL: goto x86_l_1f25;
	case 7974ULL: goto x86_l_1f26;
	case 7979ULL: goto x86_l_1f2b;
	case 7982ULL: goto x86_l_1f2e;
	case 7988ULL: goto x86_l_1f34;
	case 7993ULL: goto x86_l_1f39;
	case 7998ULL: goto x86_l_1f3e;
	case 8004ULL: goto x86_l_1f44;
	case 8008ULL: goto x86_l_1f48;
	case 8013ULL: goto x86_l_1f4d;
	case 8018ULL: goto x86_l_1f52;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8032ULL: goto x86_l_1f60;
	case 8037ULL: goto x86_l_1f65;
	case 8039ULL: goto x86_l_1f67;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8059ULL: goto x86_l_1f7b;
	case 8064ULL: goto x86_l_1f80;
	case 8069ULL: goto x86_l_1f85;
	case 8071ULL: goto x86_l_1f87;
	case 8076ULL: goto x86_l_1f8c;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8091ULL: goto x86_l_1f9b;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8103ULL: goto x86_l_1fa7;
	case 8108ULL: goto x86_l_1fac;
	case 8112ULL: goto x86_l_1fb0;
	case 8114ULL: goto x86_l_1fb2;
	case 8119ULL: goto x86_l_1fb7;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8139ULL: goto x86_l_1fcb;
	case 8142ULL: goto x86_l_1fce;
	case 8148ULL: goto x86_l_1fd4;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8171ULL: goto x86_l_1feb;
	case 8173ULL: goto x86_l_1fed;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8188ULL: goto x86_l_1ffc;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8203ULL: goto x86_l_200b;
	case 8206ULL: goto x86_l_200e;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8222ULL: goto x86_l_201e;
	case 8227ULL: goto x86_l_2023;
	case 8232ULL: goto x86_l_2028;
	case 8237ULL: goto x86_l_202d;
	case 8242ULL: goto x86_l_2032;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8252ULL: goto x86_l_203c;
	case 8258ULL: goto x86_l_2042;
	case 8263ULL: goto x86_l_2047;
	case 8266ULL: goto x86_l_204a;
	case 8272ULL: goto x86_l_2050;
	case 8276ULL: goto x86_l_2054;
	case 8281ULL: goto x86_l_2059;
	case 8286ULL: goto x86_l_205e;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8298ULL: goto x86_l_206a;
	case 8302ULL: goto x86_l_206e;
	case 8304ULL: goto x86_l_2070;
	case 8310ULL: goto x86_l_2076;
	case 8315ULL: goto x86_l_207b;
	case 8317ULL: goto x86_l_207d;
	case 8323ULL: goto x86_l_2083;
	case 8328ULL: goto x86_l_2088;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8341ULL: goto x86_l_2095;
	case 8346ULL: goto x86_l_209a;
	case 8348ULL: goto x86_l_209c;
	case 8351ULL: goto x86_l_209f;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8376ULL: goto x86_l_20b8;
	case 8380ULL: goto x86_l_20bc;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8397ULL: goto x86_l_20cd;
	case 8400ULL: goto x86_l_20d0;
	case 8406ULL: goto x86_l_20d6;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8422ULL: goto x86_l_20e6;
	case 8426ULL: goto x86_l_20ea;
	case 8431ULL: goto x86_l_20ef;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8446ULL: goto x86_l_20fe;
	case 8450ULL: goto x86_l_2102;
	case 8455ULL: goto x86_l_2107;
	case 8457ULL: goto x86_l_2109;
	case 8462ULL: goto x86_l_210e;
	case 8467ULL: goto x86_l_2113;
	case 8472ULL: goto x86_l_2118;
	case 8477ULL: goto x86_l_211d;
	case 8482ULL: goto x86_l_2122;
	case 8487ULL: goto x86_l_2127;
	case 8489ULL: goto x86_l_2129;
	case 8494ULL: goto x86_l_212e;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8509ULL: goto x86_l_213d;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8526ULL: goto x86_l_214e;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8540ULL: goto x86_l_215c;
	case 8545ULL: goto x86_l_2161;
	case 8550ULL: goto x86_l_2166;
	case 8553ULL: goto x86_l_2169;
	case 8555ULL: goto x86_l_216b;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8569ULL: goto x86_l_2179;
	case 8574ULL: goto x86_l_217e;
	case 8579ULL: goto x86_l_2183;
	case 8584ULL: goto x86_l_2188;
	case 8589ULL: goto x86_l_218d;
	case 8591ULL: goto x86_l_218f;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8605ULL: goto x86_l_219d;
	case 8610ULL: goto x86_l_21a2;
	case 8613ULL: goto x86_l_21a5;
	case 8619ULL: goto x86_l_21ab;
	case 8623ULL: goto x86_l_21af;
	case 8628ULL: goto x86_l_21b4;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8643ULL: goto x86_l_21c3;
	case 8645ULL: goto x86_l_21c5;
	case 8649ULL: goto x86_l_21c9;
	case 8651ULL: goto x86_l_21cb;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8664ULL: goto x86_l_21d8;
	case 8670ULL: goto x86_l_21de;
	case 8675ULL: goto x86_l_21e3;
	case 8681ULL: goto x86_l_21e9;
	case 8686ULL: goto x86_l_21ee;
	case 8688ULL: goto x86_l_21f0;
	case 8693ULL: goto x86_l_21f5;
	case 8695ULL: goto x86_l_21f7;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8712ULL: goto x86_l_2208;
	case 8718ULL: goto x86_l_220e;
	case 8723ULL: goto x86_l_2213;
	case 8727ULL: goto x86_l_2217;
	case 8729ULL: goto x86_l_2219;
	case 8734ULL: goto x86_l_221e;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8747ULL: goto x86_l_222b;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8763ULL: goto x86_l_223b;
	case 8769ULL: goto x86_l_2241;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8793ULL: goto x86_l_2259;
	case 8797ULL: goto x86_l_225d;
	case 8802ULL: goto x86_l_2262;
	case 8804ULL: goto x86_l_2264;
	case 8809ULL: goto x86_l_2269;
	case 8814ULL: goto x86_l_226e;
	case 8819ULL: goto x86_l_2273;
	case 8824ULL: goto x86_l_2278;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8836ULL: goto x86_l_2284;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8851ULL: goto x86_l_2293;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8866ULL: goto x86_l_22a2;
	case 8868ULL: goto x86_l_22a4;
	case 8873ULL: goto x86_l_22a9;
	case 8877ULL: goto x86_l_22ad;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c1b:
	/* 0x1c1b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1c21:
	/* 0x1c21: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c26:
	/* 0x1c26: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c29:
	/* 0x1c29: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1c2b:
	/* 0x1c2b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1c30:
	/* 0x1c30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c32:
	/* 0x1c32: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c35:
	/* 0x1c35: jl     1bc6 <sys_enter_submit+0x1bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7110ULL;
	}
x86_l_1c37:
	/* 0x1c37: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c3c:
	/* 0x1c3c: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1c3f:
	/* 0x1c3f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1c45:
	/* 0x1c45: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1c4a:
	/* 0x1c4a: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1c4c:
	/* 0x1c4c: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c51:
	/* 0x1c51: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c56:
	/* 0x1c56: jmp    1cd4 <sys_enter_submit+0x1cd4> */
	goto x86_l_1cd4;
x86_l_1c58:
	/* 0x1c58: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5d:
	/* 0x1c5d: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1c62:
	/* 0x1c62: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_1c68:
	/* 0x1c68: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c6c:
	/* 0x1c6c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c71:
	/* 0x1c71: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c76:
	/* 0x1c76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c7b:
	/* 0x1c7b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c80:
	/* 0x1c80: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c84:
	/* 0x1c84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c89:
	/* 0x1c89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c8b:
	/* 0x1c8b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c90:
	/* 0x1c90: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c95:
	/* 0x1c95: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ca9:
	/* 0x1ca9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cab:
	/* 0x1cab: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cb0:
	/* 0x1cb0: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1cb5:
	/* 0x1cb5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cba:
	/* 0x1cba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc4:
	/* 0x1cc4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cc9:
	/* 0x1cc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ccb:
	/* 0x1ccb: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd0:
	/* 0x1cd0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1cd4:
	/* 0x1cd4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cd9:
	/* 0x1cd9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cde:
	/* 0x1cde: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ce3:
	/* 0x1ce3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ce8:
	/* 0x1ce8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1ceb:
	/* 0x1ceb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ced:
	/* 0x1ced: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cf2:
	/* 0x1cf2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cf7:
	/* 0x1cf7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1cfb:
	/* 0x1cfb: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d00:
	/* 0x1d00: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d05:
	/* 0x1d05: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d0a:
	/* 0x1d0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d0f:
	/* 0x1d0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d11:
	/* 0x1d11: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d16:
	/* 0x1d16: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d19:
	/* 0x1d19: je     1f2b <sys_enter_submit+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f2b;
	}
x86_l_1d1f:
	/* 0x1d1f: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d24:
	/* 0x1d24: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d27:
	/* 0x1d27: je     1f2b <sys_enter_submit+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f2b;
	}
x86_l_1d2d:
	/* 0x1d2d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d31:
	/* 0x1d31: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d36:
	/* 0x1d36: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1d3b:
	/* 0x1d3b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d40:
	/* 0x1d40: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d45:
	/* 0x1d45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d47:
	/* 0x1d47: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1d4b:
	/* 0x1d4b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1d4d:
	/* 0x1d4d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d53:
	/* 0x1d53: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d58:
	/* 0x1d58: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1d5a:
	/* 0x1d5a: jae    1fb2 <sys_enter_submit+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fb2;
	}
x86_l_1d60:
	/* 0x1d60: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d65:
	/* 0x1d65: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d6a:
	/* 0x1d6a: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1d6c:
	/* 0x1d6c: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1d6e:
	/* 0x1d6e: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1d73:
	/* 0x1d73: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1d78:
	/* 0x1d78: mov    BYTE PTR [r12+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1d81:
	/* 0x1d81: and    edx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1d87:
	/* 0x1d87: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1d8f:
	/* 0x1d8f: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1d92:
	/* 0x1d92: lea    rbx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d97:
	/* 0x1d97: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_1d9c:
	/* 0x1d9c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1da1:
	/* 0x1da1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1da4:
	/* 0x1da4: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_1da9:
	/* 0x1da9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1dac:
	/* 0x1dac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dae:
	/* 0x1dae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fd_arg_path_map)));
x86_l_1db5:
	/* 0x1db5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1db7:
	/* 0x1db7: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1dc4:
	/* 0x1dc4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1dc7:
	/* 0x1dc7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dc9:
	/* 0x1dc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcb:
	/* 0x1dcb: mov    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1dd3:
	/* 0x1dd3: mov    eax,DWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1dd6:
	/* 0x1dd6: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1dd9:
	/* 0x1dd9: je     1efc <sys_enter_submit+0x1efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1efc;
	}
x86_l_1ddf:
	/* 0x1ddf: cmp    BYTE PTR [rbx+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_1de6:
	/* 0x1de6: jne    1efc <sys_enter_submit+0x1efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1efc;
	}
x86_l_1dec:
	/* 0x1dec: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_1def:
	/* 0x1def: lea    r13,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df3:
	/* 0x1df3: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1dfb:
	/* 0x1dfb: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1e02:
	/* 0x1e02: ja     1e54 <sys_enter_submit+0x1e54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e54;
	}
x86_l_1e04:
	/* 0x1e04: mov    BYTE PTR [r14+rbx*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519552ULL);
x86_l_1e0d:
	/* 0x1e0d: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1e13:
	/* 0x1e13: ja     1e54 <sys_enter_submit+0x1e54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e54;
	}
x86_l_1e15:
	/* 0x1e15: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e1d:
	/* 0x1e1d: lea    rdx,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e21:
	/* 0x1e21: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1e25:
	/* 0x1e25: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e31:
	/* 0x1e31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e36:
	/* 0x1e36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e3b:
	/* 0x1e3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3d:
	/* 0x1e3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e40:
	/* 0x1e40: js     1e54 <sys_enter_submit+0x1e54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e54;
	}
x86_l_1e42:
	/* 0x1e42: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1e45:
	/* 0x1e45: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e4d:
	/* 0x1e4d: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1e54:
	/* 0x1e54: mov    rax,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e58:
	/* 0x1e58: mov    rdx,QWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e5c:
	/* 0x1e5c: mov    r8d,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1e60:
	/* 0x1e60: mov    ecx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1e65:
	/* 0x1e65: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1e68:
	/* 0x1e68: mov    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e70:
	/* 0x1e70: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1e73:
	/* 0x1e73: rep movs QWORD PTR es:[rdi],QWORD PTR ds:[rsi] */
	X86_SIM_L_EXEC_REP_MOVS(X86_WIDTH_64, 13ULL);
x86_l_1e76:
	/* 0x1e76: mov    QWORD PTR [r14+0x24],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e7a:
	/* 0x1e7a: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e7e:
	/* 0x1e7e: and    r8d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_1e82:
	/* 0x1e82: or     DWORD PTR [r14+0x5c],r8d */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R8, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 92ULL);
x86_l_1e86:
	/* 0x1e86: mov    ecx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1e8b:
	/* 0x1e8b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e8e:
	/* 0x1e8e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1e91:
	/* 0x1e91: rep movs QWORD PTR es:[rdi],QWORD PTR ds:[rsi] */
	X86_SIM_L_EXEC_REP_MOVS(X86_WIDTH_64, 13ULL);
x86_l_1e94:
	/* 0x1e94: test   BYTE PTR [r12+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1e9a:
	/* 0x1e9a: je     1ebf <sys_enter_submit+0x1ebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ebf;
	}
x86_l_1e9c:
	/* 0x1e9c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1ea3:
	/* 0x1ea3: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1ea8:
	/* 0x1ea8: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1ead:
	/* 0x1ead: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1eb2:
	/* 0x1eb2: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1eb5:
	/* 0x1eb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb7:
	/* 0x1eb7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eb9:
	/* 0x1eb9: js     1ebf <sys_enter_submit+0x1ebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ebf;
	}
x86_l_1ebb:
	/* 0x1ebb: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ebf:
	/* 0x1ebf: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ec7:
	/* 0x1ec7: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1ed1:
	/* 0x1ed1: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1ed4:
	/* 0x1ed4: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1eda:
	/* 0x1eda: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ede:
	/* 0x1ede: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1ee5:
	/* 0x1ee5: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1eea:
	/* 0x1eea: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1eef:
	/* 0x1eef: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1ef4:
	/* 0x1ef4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1ef7:
	/* 0x1ef7: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1efa:
	/* 0x1efa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1efc:
	/* 0x1efc: mov    ecx,DWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1eff:
	/* 0x1eff: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&sys_enter_tails)));
x86_l_1f06:
	/* 0x1f06: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    edx,DWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f0e:
	/* 0x1f0e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f11:
	/* 0x1f11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f13:
	/* 0x1f13: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f15:
	/* 0x1f15: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1f1c:
	/* 0x1f1c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f1d:
	/* 0x1f1d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1f1f:
	/* 0x1f1f: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1f21:
	/* 0x1f21: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f23:
	/* 0x1f23: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1f25:
	/* 0x1f25: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1f26:
	/* 0x1f26: jmp    35ab <sys_enter_submit+0x35ab> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f2b:
	/* 0x1f2b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f2e:
	/* 0x1f2e: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_1f34:
	/* 0x1f34: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f39:
	/* 0x1f39: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1f3e:
	/* 0x1f3e: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_1f44:
	/* 0x1f44: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f48:
	/* 0x1f48: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f4d:
	/* 0x1f4d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f52:
	/* 0x1f52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f57:
	/* 0x1f57: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f5c:
	/* 0x1f5c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f60:
	/* 0x1f60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f65:
	/* 0x1f65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f67:
	/* 0x1f67: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f6c:
	/* 0x1f6c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f71:
	/* 0x1f71: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f76:
	/* 0x1f76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f7b:
	/* 0x1f7b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f80:
	/* 0x1f80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f85:
	/* 0x1f85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f87:
	/* 0x1f87: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f8c:
	/* 0x1f8c: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f91:
	/* 0x1f91: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f96:
	/* 0x1f96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f9b:
	/* 0x1f9b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa5:
	/* 0x1fa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa7:
	/* 0x1fa7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fac:
	/* 0x1fac: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fb0:
	/* 0x1fb0: jmp    1ff7 <sys_enter_submit+0x1ff7> */
	goto x86_l_1ff7;
x86_l_1fb2:
	/* 0x1fb2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fb7:
	/* 0x1fb7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1fbd:
	/* 0x1fbd: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1fc2:
	/* 0x1fc2: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1fc4:
	/* 0x1fc4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1fc9:
	/* 0x1fc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fcb:
	/* 0x1fcb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fce:
	/* 0x1fce: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_1fd4:
	/* 0x1fd4: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd9:
	/* 0x1fd9: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1fdc:
	/* 0x1fdc: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1feb:
	/* 0x1feb: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fed:
	/* 0x1fed: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff2:
	/* 0x1ff2: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ff7:
	/* 0x1ff7: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ffc:
	/* 0x1ffc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2001:
	/* 0x2001: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2006:
	/* 0x2006: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_200b:
	/* 0x200b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_200e:
	/* 0x200e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2010:
	/* 0x2010: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2015:
	/* 0x2015: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_201a:
	/* 0x201a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_201e:
	/* 0x201e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2023:
	/* 0x2023: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2028:
	/* 0x2028: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_202d:
	/* 0x202d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2032:
	/* 0x2032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2034:
	/* 0x2034: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2039:
	/* 0x2039: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_203c:
	/* 0x203c: je     20cd <sys_enter_submit+0x20cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20cd;
	}
x86_l_2042:
	/* 0x2042: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2047:
	/* 0x2047: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_204a:
	/* 0x204a: je     20cd <sys_enter_submit+0x20cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20cd;
	}
x86_l_2050:
	/* 0x2050: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2054:
	/* 0x2054: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2059:
	/* 0x2059: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_205e:
	/* 0x205e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2063:
	/* 0x2063: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2068:
	/* 0x2068: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206a:
	/* 0x206a: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_206e:
	/* 0x206e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2070:
	/* 0x2070: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2076:
	/* 0x2076: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_207b:
	/* 0x207b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_207d:
	/* 0x207d: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d60;
	}
x86_l_2083:
	/* 0x2083: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2088:
	/* 0x2088: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_208e:
	/* 0x208e: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2093:
	/* 0x2093: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2095:
	/* 0x2095: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_209a:
	/* 0x209a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_209c:
	/* 0x209c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_209f:
	/* 0x209f: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_20a5:
	/* 0x20a5: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20aa:
	/* 0x20aa: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_20ad:
	/* 0x20ad: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_20b3:
	/* 0x20b3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b8:
	/* 0x20b8: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_20bc:
	/* 0x20bc: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_20be:
	/* 0x20be: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c3:
	/* 0x20c3: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20c8:
	/* 0x20c8: jmp    2152 <sys_enter_submit+0x2152> */
	goto x86_l_2152;
x86_l_20cd:
	/* 0x20cd: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20d0:
	/* 0x20d0: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_20d6:
	/* 0x20d6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20db:
	/* 0x20db: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_20e0:
	/* 0x20e0: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_20e6:
	/* 0x20e6: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_20ea:
	/* 0x20ea: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20ef:
	/* 0x20ef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20f4:
	/* 0x20f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20f9:
	/* 0x20f9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20fe:
	/* 0x20fe: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2102:
	/* 0x2102: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2107:
	/* 0x2107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2109:
	/* 0x2109: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_210e:
	/* 0x210e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2113:
	/* 0x2113: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2118:
	/* 0x2118: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_211d:
	/* 0x211d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2122:
	/* 0x2122: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2127:
	/* 0x2127: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2129:
	/* 0x2129: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_212e:
	/* 0x212e: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2133:
	/* 0x2133: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2138:
	/* 0x2138: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_213d:
	/* 0x213d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2142:
	/* 0x2142: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2147:
	/* 0x2147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2149:
	/* 0x2149: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_214e:
	/* 0x214e: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2152:
	/* 0x2152: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2157:
	/* 0x2157: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_215c:
	/* 0x215c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2161:
	/* 0x2161: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2166:
	/* 0x2166: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2169:
	/* 0x2169: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216b:
	/* 0x216b: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2170:
	/* 0x2170: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2175:
	/* 0x2175: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2179:
	/* 0x2179: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_217e:
	/* 0x217e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2183:
	/* 0x2183: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2188:
	/* 0x2188: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_218d:
	/* 0x218d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218f:
	/* 0x218f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2194:
	/* 0x2194: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2197:
	/* 0x2197: je     2228 <sys_enter_submit+0x2228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2228;
	}
x86_l_219d:
	/* 0x219d: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21a2:
	/* 0x21a2: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_21a5:
	/* 0x21a5: je     2228 <sys_enter_submit+0x2228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2228;
	}
x86_l_21ab:
	/* 0x21ab: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_21af:
	/* 0x21af: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21b4:
	/* 0x21b4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_21b9:
	/* 0x21b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21be:
	/* 0x21be: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21c3:
	/* 0x21c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c5:
	/* 0x21c5: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_21c9:
	/* 0x21c9: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_21cb:
	/* 0x21cb: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21d1:
	/* 0x21d1: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d6:
	/* 0x21d6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21d8:
	/* 0x21d8: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d60;
	}
x86_l_21de:
	/* 0x21de: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21e3:
	/* 0x21e3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_21e9:
	/* 0x21e9: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_21ee:
	/* 0x21ee: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_21f0:
	/* 0x21f0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_21f5:
	/* 0x21f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f7:
	/* 0x21f7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21fa:
	/* 0x21fa: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_2200:
	/* 0x2200: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2205:
	/* 0x2205: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2208:
	/* 0x2208: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_220e:
	/* 0x220e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2213:
	/* 0x2213: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2217:
	/* 0x2217: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2219:
	/* 0x2219: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_221e:
	/* 0x221e: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2223:
	/* 0x2223: jmp    22ad <sys_enter_submit+0x22ad> */
	goto x86_l_22ad;
x86_l_2228:
	/* 0x2228: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_222b:
	/* 0x222b: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_2231:
	/* 0x2231: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2236:
	/* 0x2236: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_223b:
	/* 0x223b: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_2241:
	/* 0x2241: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2245:
	/* 0x2245: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_224a:
	/* 0x224a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_224f:
	/* 0x224f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2254:
	/* 0x2254: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2259:
	/* 0x2259: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_225d:
	/* 0x225d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2262:
	/* 0x2262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2264:
	/* 0x2264: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2269:
	/* 0x2269: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_226e:
	/* 0x226e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2273:
	/* 0x2273: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2278:
	/* 0x2278: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_227d:
	/* 0x227d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2282:
	/* 0x2282: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2284:
	/* 0x2284: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2289:
	/* 0x2289: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_228e:
	/* 0x228e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2293:
	/* 0x2293: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2298:
	/* 0x2298: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_229d:
	/* 0x229d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22a2:
	/* 0x22a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a4:
	/* 0x22a4: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a9:
	/* 0x22a9: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_22ad:
	/* 0x22ad: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
	return 8882ULL;
}

static __noinline __u64 tracee_sys_enter_submit_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8882ULL: goto x86_l_22b2;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8900ULL: goto x86_l_22c4;
	case 8902ULL: goto x86_l_22c6;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8938ULL: goto x86_l_22ea;
	case 8943ULL: goto x86_l_22ef;
	case 8946ULL: goto x86_l_22f2;
	case 8952ULL: goto x86_l_22f8;
	case 8957ULL: goto x86_l_22fd;
	case 8960ULL: goto x86_l_2300;
	case 8966ULL: goto x86_l_2306;
	case 8970ULL: goto x86_l_230a;
	case 8975ULL: goto x86_l_230f;
	case 8980ULL: goto x86_l_2314;
	case 8985ULL: goto x86_l_2319;
	case 8990ULL: goto x86_l_231e;
	case 8992ULL: goto x86_l_2320;
	case 8996ULL: goto x86_l_2324;
	case 8998ULL: goto x86_l_2326;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9011ULL: goto x86_l_2333;
	case 9017ULL: goto x86_l_2339;
	case 9022ULL: goto x86_l_233e;
	case 9028ULL: goto x86_l_2344;
	case 9033ULL: goto x86_l_2349;
	case 9035ULL: goto x86_l_234b;
	case 9040ULL: goto x86_l_2350;
	case 9042ULL: goto x86_l_2352;
	case 9045ULL: goto x86_l_2355;
	case 9051ULL: goto x86_l_235b;
	case 9056ULL: goto x86_l_2360;
	case 9059ULL: goto x86_l_2363;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9074ULL: goto x86_l_2372;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9091ULL: goto x86_l_2383;
	case 9094ULL: goto x86_l_2386;
	case 9100ULL: goto x86_l_238c;
	case 9105ULL: goto x86_l_2391;
	case 9110ULL: goto x86_l_2396;
	case 9116ULL: goto x86_l_239c;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9140ULL: goto x86_l_23b4;
	case 9144ULL: goto x86_l_23b8;
	case 9149ULL: goto x86_l_23bd;
	case 9151ULL: goto x86_l_23bf;
	case 9156ULL: goto x86_l_23c4;
	case 9161ULL: goto x86_l_23c9;
	case 9166ULL: goto x86_l_23ce;
	case 9171ULL: goto x86_l_23d3;
	case 9176ULL: goto x86_l_23d8;
	case 9181ULL: goto x86_l_23dd;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9193ULL: goto x86_l_23e9;
	case 9198ULL: goto x86_l_23ee;
	case 9203ULL: goto x86_l_23f3;
	case 9208ULL: goto x86_l_23f8;
	case 9213ULL: goto x86_l_23fd;
	case 9215ULL: goto x86_l_23ff;
	case 9220ULL: goto x86_l_2404;
	case 9224ULL: goto x86_l_2408;
	case 9229ULL: goto x86_l_240d;
	case 9234ULL: goto x86_l_2412;
	case 9239ULL: goto x86_l_2417;
	case 9244ULL: goto x86_l_241c;
	case 9247ULL: goto x86_l_241f;
	case 9249ULL: goto x86_l_2421;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9263ULL: goto x86_l_242f;
	case 9268ULL: goto x86_l_2434;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	case 9285ULL: goto x86_l_2445;
	case 9290ULL: goto x86_l_244a;
	case 9293ULL: goto x86_l_244d;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9307ULL: goto x86_l_245b;
	case 9313ULL: goto x86_l_2461;
	case 9317ULL: goto x86_l_2465;
	case 9322ULL: goto x86_l_246a;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9339ULL: goto x86_l_247b;
	case 9343ULL: goto x86_l_247f;
	case 9345ULL: goto x86_l_2481;
	case 9351ULL: goto x86_l_2487;
	case 9356ULL: goto x86_l_248c;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9375ULL: goto x86_l_249f;
	case 9380ULL: goto x86_l_24a4;
	case 9382ULL: goto x86_l_24a6;
	case 9387ULL: goto x86_l_24ab;
	case 9389ULL: goto x86_l_24ad;
	case 9392ULL: goto x86_l_24b0;
	case 9398ULL: goto x86_l_24b6;
	case 9403ULL: goto x86_l_24bb;
	case 9406ULL: goto x86_l_24be;
	case 9412ULL: goto x86_l_24c4;
	case 9417ULL: goto x86_l_24c9;
	case 9421ULL: goto x86_l_24cd;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9433ULL: goto x86_l_24d9;
	case 9438ULL: goto x86_l_24de;
	case 9441ULL: goto x86_l_24e1;
	case 9447ULL: goto x86_l_24e7;
	case 9452ULL: goto x86_l_24ec;
	case 9457ULL: goto x86_l_24f1;
	case 9463ULL: goto x86_l_24f7;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9482ULL: goto x86_l_250a;
	case 9487ULL: goto x86_l_250f;
	case 9491ULL: goto x86_l_2513;
	case 9496ULL: goto x86_l_2518;
	case 9498ULL: goto x86_l_251a;
	case 9503ULL: goto x86_l_251f;
	case 9508ULL: goto x86_l_2524;
	case 9513ULL: goto x86_l_2529;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9562ULL: goto x86_l_255a;
	case 9567ULL: goto x86_l_255f;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9581ULL: goto x86_l_256d;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9594ULL: goto x86_l_257a;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9606ULL: goto x86_l_2586;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9625ULL: goto x86_l_2599;
	case 9630ULL: goto x86_l_259e;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9640ULL: goto x86_l_25a8;
	case 9646ULL: goto x86_l_25ae;
	case 9651ULL: goto x86_l_25b3;
	case 9654ULL: goto x86_l_25b6;
	case 9660ULL: goto x86_l_25bc;
	case 9664ULL: goto x86_l_25c0;
	case 9669ULL: goto x86_l_25c5;
	case 9674ULL: goto x86_l_25ca;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9686ULL: goto x86_l_25d6;
	case 9690ULL: goto x86_l_25da;
	case 9692ULL: goto x86_l_25dc;
	case 9698ULL: goto x86_l_25e2;
	case 9703ULL: goto x86_l_25e7;
	case 9705ULL: goto x86_l_25e9;
	case 9711ULL: goto x86_l_25ef;
	case 9716ULL: goto x86_l_25f4;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9736ULL: goto x86_l_2608;
	case 9739ULL: goto x86_l_260b;
	case 9745ULL: goto x86_l_2611;
	case 9750ULL: goto x86_l_2616;
	case 9753ULL: goto x86_l_2619;
	case 9759ULL: goto x86_l_261f;
	case 9764ULL: goto x86_l_2624;
	case 9768ULL: goto x86_l_2628;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9785ULL: goto x86_l_2639;
	case 9788ULL: goto x86_l_263c;
	case 9794ULL: goto x86_l_2642;
	case 9799ULL: goto x86_l_2647;
	case 9804ULL: goto x86_l_264c;
	case 9810ULL: goto x86_l_2652;
	case 9814ULL: goto x86_l_2656;
	case 9819ULL: goto x86_l_265b;
	case 9824ULL: goto x86_l_2660;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9838ULL: goto x86_l_266e;
	case 9843ULL: goto x86_l_2673;
	case 9845ULL: goto x86_l_2675;
	case 9850ULL: goto x86_l_267a;
	case 9855ULL: goto x86_l_267f;
	case 9860ULL: goto x86_l_2684;
	case 9865ULL: goto x86_l_2689;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9877ULL: goto x86_l_2695;
	case 9882ULL: goto x86_l_269a;
	case 9887ULL: goto x86_l_269f;
	case 9892ULL: goto x86_l_26a4;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9907ULL: goto x86_l_26b3;
	case 9909ULL: goto x86_l_26b5;
	case 9914ULL: goto x86_l_26ba;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9928ULL: goto x86_l_26c8;
	case 9933ULL: goto x86_l_26cd;
	case 9938ULL: goto x86_l_26d2;
	case 9941ULL: goto x86_l_26d5;
	case 9943ULL: goto x86_l_26d7;
	case 9948ULL: goto x86_l_26dc;
	case 9953ULL: goto x86_l_26e1;
	case 9957ULL: goto x86_l_26e5;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9972ULL: goto x86_l_26f4;
	case 9977ULL: goto x86_l_26f9;
	case 9979ULL: goto x86_l_26fb;
	case 9984ULL: goto x86_l_2700;
	case 9987ULL: goto x86_l_2703;
	case 9993ULL: goto x86_l_2709;
	case 9998ULL: goto x86_l_270e;
	case 10001ULL: goto x86_l_2711;
	case 10007ULL: goto x86_l_2717;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10031ULL: goto x86_l_272f;
	case 10033ULL: goto x86_l_2731;
	case 10037ULL: goto x86_l_2735;
	case 10039ULL: goto x86_l_2737;
	case 10045ULL: goto x86_l_273d;
	case 10050ULL: goto x86_l_2742;
	case 10052ULL: goto x86_l_2744;
	case 10058ULL: goto x86_l_274a;
	case 10063ULL: goto x86_l_274f;
	case 10069ULL: goto x86_l_2755;
	case 10074ULL: goto x86_l_275a;
	case 10076ULL: goto x86_l_275c;
	case 10081ULL: goto x86_l_2761;
	case 10083ULL: goto x86_l_2763;
	case 10086ULL: goto x86_l_2766;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10100ULL: goto x86_l_2774;
	case 10106ULL: goto x86_l_277a;
	case 10111ULL: goto x86_l_277f;
	case 10115ULL: goto x86_l_2783;
	case 10117ULL: goto x86_l_2785;
	case 10122ULL: goto x86_l_278a;
	case 10127ULL: goto x86_l_278f;
	case 10132ULL: goto x86_l_2794;
	case 10135ULL: goto x86_l_2797;
	case 10141ULL: goto x86_l_279d;
	case 10146ULL: goto x86_l_27a2;
	case 10151ULL: goto x86_l_27a7;
	case 10157ULL: goto x86_l_27ad;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10181ULL: goto x86_l_27c5;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10192ULL: goto x86_l_27d0;
	case 10197ULL: goto x86_l_27d5;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10212ULL: goto x86_l_27e4;
	case 10217ULL: goto x86_l_27e9;
	case 10222ULL: goto x86_l_27ee;
	case 10224ULL: goto x86_l_27f0;
	case 10229ULL: goto x86_l_27f5;
	case 10234ULL: goto x86_l_27fa;
	case 10239ULL: goto x86_l_27ff;
	case 10244ULL: goto x86_l_2804;
	case 10249ULL: goto x86_l_2809;
	case 10254ULL: goto x86_l_280e;
	case 10256ULL: goto x86_l_2810;
	case 10261ULL: goto x86_l_2815;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10288ULL: goto x86_l_2830;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10300ULL: goto x86_l_283c;
	case 10304ULL: goto x86_l_2840;
	case 10309ULL: goto x86_l_2845;
	case 10314ULL: goto x86_l_284a;
	case 10319ULL: goto x86_l_284f;
	case 10324ULL: goto x86_l_2854;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10334ULL: goto x86_l_285e;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10348ULL: goto x86_l_286c;
	case 10354ULL: goto x86_l_2872;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10368ULL: goto x86_l_2880;
	case 10373ULL: goto x86_l_2885;
	case 10378ULL: goto x86_l_288a;
	case 10380ULL: goto x86_l_288c;
	case 10384ULL: goto x86_l_2890;
	case 10386ULL: goto x86_l_2892;
	case 10392ULL: goto x86_l_2898;
	case 10397ULL: goto x86_l_289d;
	case 10399ULL: goto x86_l_289f;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10416ULL: goto x86_l_28b0;
	case 10421ULL: goto x86_l_28b5;
	case 10423ULL: goto x86_l_28b7;
	case 10428ULL: goto x86_l_28bc;
	case 10430ULL: goto x86_l_28be;
	case 10433ULL: goto x86_l_28c1;
	case 10439ULL: goto x86_l_28c7;
	case 10444ULL: goto x86_l_28cc;
	case 10447ULL: goto x86_l_28cf;
	case 10453ULL: goto x86_l_28d5;
	case 10458ULL: goto x86_l_28da;
	case 10462ULL: goto x86_l_28de;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10482ULL: goto x86_l_28f2;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10504ULL: goto x86_l_2908;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10518ULL: goto x86_l_2916;
	case 10523ULL: goto x86_l_291b;
	case 10528ULL: goto x86_l_2920;
	case 10532ULL: goto x86_l_2924;
	case 10537ULL: goto x86_l_2929;
	case 10539ULL: goto x86_l_292b;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10559ULL: goto x86_l_293f;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10571ULL: goto x86_l_294b;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10586ULL: goto x86_l_295a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22b2:
	/* 0x22b2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22b7:
	/* 0x22b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22bc:
	/* 0x22bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22c1:
	/* 0x22c1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_22c4:
	/* 0x22c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c6:
	/* 0x22c6: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22cb:
	/* 0x22cb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22d0:
	/* 0x22d0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22d4:
	/* 0x22d4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22d9:
	/* 0x22d9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22de:
	/* 0x22de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22e3:
	/* 0x22e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e8:
	/* 0x22e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ea:
	/* 0x22ea: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22ef:
	/* 0x22ef: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_22f2:
	/* 0x22f2: je     2383 <sys_enter_submit+0x2383> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2383;
	}
x86_l_22f8:
	/* 0x22f8: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22fd:
	/* 0x22fd: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2300:
	/* 0x2300: je     2383 <sys_enter_submit+0x2383> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2383;
	}
x86_l_2306:
	/* 0x2306: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_230a:
	/* 0x230a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_230f:
	/* 0x230f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2314:
	/* 0x2314: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2319:
	/* 0x2319: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_231e:
	/* 0x231e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2320:
	/* 0x2320: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2324:
	/* 0x2324: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2326:
	/* 0x2326: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_232c:
	/* 0x232c: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2331:
	/* 0x2331: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2333:
	/* 0x2333: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_2339:
	/* 0x2339: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_233e:
	/* 0x233e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2344:
	/* 0x2344: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2349:
	/* 0x2349: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_234b:
	/* 0x234b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2350:
	/* 0x2350: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2352:
	/* 0x2352: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2355:
	/* 0x2355: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_235b:
	/* 0x235b: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2360:
	/* 0x2360: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2363:
	/* 0x2363: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2369:
	/* 0x2369: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_236e:
	/* 0x236e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2372:
	/* 0x2372: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2374:
	/* 0x2374: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2379:
	/* 0x2379: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_237e:
	/* 0x237e: jmp    2408 <sys_enter_submit+0x2408> */
	goto x86_l_2408;
x86_l_2383:
	/* 0x2383: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2386:
	/* 0x2386: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_238c:
	/* 0x238c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2391:
	/* 0x2391: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2396:
	/* 0x2396: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_239c:
	/* 0x239c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23a0:
	/* 0x23a0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23a5:
	/* 0x23a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23aa:
	/* 0x23aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23af:
	/* 0x23af: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23b4:
	/* 0x23b4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23b8:
	/* 0x23b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23bd:
	/* 0x23bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23bf:
	/* 0x23bf: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23c4:
	/* 0x23c4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23c9:
	/* 0x23c9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23ce:
	/* 0x23ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23d3:
	/* 0x23d3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d8:
	/* 0x23d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23dd:
	/* 0x23dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23df:
	/* 0x23df: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23e4:
	/* 0x23e4: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23e9:
	/* 0x23e9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23ee:
	/* 0x23ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23f3:
	/* 0x23f3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23f8:
	/* 0x23f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23fd:
	/* 0x23fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ff:
	/* 0x23ff: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2404:
	/* 0x2404: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2408:
	/* 0x2408: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_240d:
	/* 0x240d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2412:
	/* 0x2412: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2417:
	/* 0x2417: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_241c:
	/* 0x241c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_241f:
	/* 0x241f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2421:
	/* 0x2421: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2426:
	/* 0x2426: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_242b:
	/* 0x242b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_242f:
	/* 0x242f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2434:
	/* 0x2434: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2439:
	/* 0x2439: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_243e:
	/* 0x243e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2443:
	/* 0x2443: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2445:
	/* 0x2445: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_244a:
	/* 0x244a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_244d:
	/* 0x244d: je     24de <sys_enter_submit+0x24de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24de;
	}
x86_l_2453:
	/* 0x2453: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2458:
	/* 0x2458: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_245b:
	/* 0x245b: je     24de <sys_enter_submit+0x24de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24de;
	}
x86_l_2461:
	/* 0x2461: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2465:
	/* 0x2465: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_246a:
	/* 0x246a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_246f:
	/* 0x246f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2474:
	/* 0x2474: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2479:
	/* 0x2479: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247b:
	/* 0x247b: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_247f:
	/* 0x247f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2481:
	/* 0x2481: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2487:
	/* 0x2487: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_248c:
	/* 0x248c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_248e:
	/* 0x248e: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_2494:
	/* 0x2494: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2499:
	/* 0x2499: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_249f:
	/* 0x249f: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_24a4:
	/* 0x24a4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_24a6:
	/* 0x24a6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_24ab:
	/* 0x24ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ad:
	/* 0x24ad: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24b0:
	/* 0x24b0: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_24b6:
	/* 0x24b6: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24bb:
	/* 0x24bb: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_24be:
	/* 0x24be: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_24c4:
	/* 0x24c4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24c9:
	/* 0x24c9: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_24cd:
	/* 0x24cd: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24cf:
	/* 0x24cf: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d4:
	/* 0x24d4: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24d9:
	/* 0x24d9: jmp    2563 <sys_enter_submit+0x2563> */
	goto x86_l_2563;
x86_l_24de:
	/* 0x24de: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_24e1:
	/* 0x24e1: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_24e7:
	/* 0x24e7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ec:
	/* 0x24ec: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_24f1:
	/* 0x24f1: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_24f7:
	/* 0x24f7: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24fb:
	/* 0x24fb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2500:
	/* 0x2500: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2505:
	/* 0x2505: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_250a:
	/* 0x250a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_250f:
	/* 0x250f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2513:
	/* 0x2513: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2518:
	/* 0x2518: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251a:
	/* 0x251a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_251f:
	/* 0x251f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2524:
	/* 0x2524: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2529:
	/* 0x2529: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_252e:
	/* 0x252e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2533:
	/* 0x2533: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2538:
	/* 0x2538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253a:
	/* 0x253a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_253f:
	/* 0x253f: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2544:
	/* 0x2544: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2549:
	/* 0x2549: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_254e:
	/* 0x254e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2553:
	/* 0x2553: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2558:
	/* 0x2558: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255a:
	/* 0x255a: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255f:
	/* 0x255f: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2563:
	/* 0x2563: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2568:
	/* 0x2568: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_256d:
	/* 0x256d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2572:
	/* 0x2572: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2577:
	/* 0x2577: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_257a:
	/* 0x257a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257c:
	/* 0x257c: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2581:
	/* 0x2581: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2586:
	/* 0x2586: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_258a:
	/* 0x258a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_258f:
	/* 0x258f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2594:
	/* 0x2594: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2599:
	/* 0x2599: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_259e:
	/* 0x259e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a0:
	/* 0x25a0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25a5:
	/* 0x25a5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_25a8:
	/* 0x25a8: je     2639 <sys_enter_submit+0x2639> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2639;
	}
x86_l_25ae:
	/* 0x25ae: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25b3:
	/* 0x25b3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_25b6:
	/* 0x25b6: je     2639 <sys_enter_submit+0x2639> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2639;
	}
x86_l_25bc:
	/* 0x25bc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_25c0:
	/* 0x25c0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25c5:
	/* 0x25c5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_25ca:
	/* 0x25ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25cf:
	/* 0x25cf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25d4:
	/* 0x25d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d6:
	/* 0x25d6: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_25da:
	/* 0x25da: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_25dc:
	/* 0x25dc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25e2:
	/* 0x25e2: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25e7:
	/* 0x25e7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25e9:
	/* 0x25e9: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_25ef:
	/* 0x25ef: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25f4:
	/* 0x25f4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_25fa:
	/* 0x25fa: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_25ff:
	/* 0x25ff: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2601:
	/* 0x2601: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2606:
	/* 0x2606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2608:
	/* 0x2608: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_260b:
	/* 0x260b: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_2611:
	/* 0x2611: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2616:
	/* 0x2616: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2619:
	/* 0x2619: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_261f:
	/* 0x261f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2624:
	/* 0x2624: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2628:
	/* 0x2628: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_262a:
	/* 0x262a: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_262f:
	/* 0x262f: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2634:
	/* 0x2634: jmp    26be <sys_enter_submit+0x26be> */
	goto x86_l_26be;
x86_l_2639:
	/* 0x2639: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_263c:
	/* 0x263c: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_2642:
	/* 0x2642: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2647:
	/* 0x2647: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_264c:
	/* 0x264c: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_2652:
	/* 0x2652: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2656:
	/* 0x2656: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_265b:
	/* 0x265b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2660:
	/* 0x2660: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2665:
	/* 0x2665: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_266a:
	/* 0x266a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_266e:
	/* 0x266e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2673:
	/* 0x2673: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2675:
	/* 0x2675: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_267a:
	/* 0x267a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_267f:
	/* 0x267f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2684:
	/* 0x2684: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2689:
	/* 0x2689: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_268e:
	/* 0x268e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2693:
	/* 0x2693: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2695:
	/* 0x2695: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_269a:
	/* 0x269a: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_269f:
	/* 0x269f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26a4:
	/* 0x26a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26a9:
	/* 0x26a9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ae:
	/* 0x26ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26b3:
	/* 0x26b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b5:
	/* 0x26b5: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ba:
	/* 0x26ba: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26be:
	/* 0x26be: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26c3:
	/* 0x26c3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26c8:
	/* 0x26c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26cd:
	/* 0x26cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26d2:
	/* 0x26d2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_26d5:
	/* 0x26d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d7:
	/* 0x26d7: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26dc:
	/* 0x26dc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26e1:
	/* 0x26e1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26e5:
	/* 0x26e5: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26ea:
	/* 0x26ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26ef:
	/* 0x26ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26f4:
	/* 0x26f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26f9:
	/* 0x26f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26fb:
	/* 0x26fb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2700:
	/* 0x2700: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2703:
	/* 0x2703: je     2794 <sys_enter_submit+0x2794> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2794;
	}
x86_l_2709:
	/* 0x2709: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_270e:
	/* 0x270e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2711:
	/* 0x2711: je     2794 <sys_enter_submit+0x2794> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2794;
	}
x86_l_2717:
	/* 0x2717: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_271b:
	/* 0x271b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2720:
	/* 0x2720: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2725:
	/* 0x2725: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_272a:
	/* 0x272a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_272f:
	/* 0x272f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2731:
	/* 0x2731: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2735:
	/* 0x2735: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2737:
	/* 0x2737: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_273d:
	/* 0x273d: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2742:
	/* 0x2742: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2744:
	/* 0x2744: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_274a:
	/* 0x274a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_274f:
	/* 0x274f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2755:
	/* 0x2755: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_275a:
	/* 0x275a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_275c:
	/* 0x275c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2761:
	/* 0x2761: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2763:
	/* 0x2763: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2766:
	/* 0x2766: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_276c:
	/* 0x276c: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2771:
	/* 0x2771: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2774:
	/* 0x2774: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_277a:
	/* 0x277a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_277f:
	/* 0x277f: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2783:
	/* 0x2783: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2785:
	/* 0x2785: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_278a:
	/* 0x278a: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_278f:
	/* 0x278f: jmp    2819 <sys_enter_submit+0x2819> */
	goto x86_l_2819;
x86_l_2794:
	/* 0x2794: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2797:
	/* 0x2797: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_279d:
	/* 0x279d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a2:
	/* 0x27a2: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_27a7:
	/* 0x27a7: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_27ad:
	/* 0x27ad: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_27b1:
	/* 0x27b1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27b6:
	/* 0x27b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27bb:
	/* 0x27bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27c0:
	/* 0x27c0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27c5:
	/* 0x27c5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_27c9:
	/* 0x27c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ce:
	/* 0x27ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d0:
	/* 0x27d0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d5:
	/* 0x27d5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27da:
	/* 0x27da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27df:
	/* 0x27df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27e4:
	/* 0x27e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27e9:
	/* 0x27e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ee:
	/* 0x27ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f0:
	/* 0x27f0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27f5:
	/* 0x27f5: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27fa:
	/* 0x27fa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27ff:
	/* 0x27ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2804:
	/* 0x2804: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2809:
	/* 0x2809: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_280e:
	/* 0x280e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2810:
	/* 0x2810: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2815:
	/* 0x2815: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2819:
	/* 0x2819: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_281e:
	/* 0x281e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2823:
	/* 0x2823: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2828:
	/* 0x2828: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_282d:
	/* 0x282d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2830:
	/* 0x2830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2832:
	/* 0x2832: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2837:
	/* 0x2837: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_283c:
	/* 0x283c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2840:
	/* 0x2840: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2845:
	/* 0x2845: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_284a:
	/* 0x284a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_284f:
	/* 0x284f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2854:
	/* 0x2854: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2856:
	/* 0x2856: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_285b:
	/* 0x285b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_285e:
	/* 0x285e: je     28ef <sys_enter_submit+0x28ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28ef;
	}
x86_l_2864:
	/* 0x2864: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2869:
	/* 0x2869: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_286c:
	/* 0x286c: je     28ef <sys_enter_submit+0x28ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28ef;
	}
x86_l_2872:
	/* 0x2872: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2876:
	/* 0x2876: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_287b:
	/* 0x287b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2880:
	/* 0x2880: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2885:
	/* 0x2885: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_288a:
	/* 0x288a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288c:
	/* 0x288c: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2890:
	/* 0x2890: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2892:
	/* 0x2892: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2898:
	/* 0x2898: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_289d:
	/* 0x289d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_289f:
	/* 0x289f: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_28a5:
	/* 0x28a5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28aa:
	/* 0x28aa: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_28b0:
	/* 0x28b0: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_28b5:
	/* 0x28b5: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_28b7:
	/* 0x28b7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_28bc:
	/* 0x28bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28be:
	/* 0x28be: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28c1:
	/* 0x28c1: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_28c7:
	/* 0x28c7: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28cc:
	/* 0x28cc: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_28cf:
	/* 0x28cf: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_28d5:
	/* 0x28d5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28da:
	/* 0x28da: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_28de:
	/* 0x28de: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_28e0:
	/* 0x28e0: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28e5:
	/* 0x28e5: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28ea:
	/* 0x28ea: jmp    2974 <sys_enter_submit+0x2974> */
	return 10612ULL;
x86_l_28ef:
	/* 0x28ef: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_28f2:
	/* 0x28f2: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_28f8:
	/* 0x28f8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28fd:
	/* 0x28fd: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2902:
	/* 0x2902: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_2908:
	/* 0x2908: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_290c:
	/* 0x290c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2911:
	/* 0x2911: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2916:
	/* 0x2916: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_291b:
	/* 0x291b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2920:
	/* 0x2920: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2924:
	/* 0x2924: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2929:
	/* 0x2929: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292b:
	/* 0x292b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2930:
	/* 0x2930: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2935:
	/* 0x2935: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_293a:
	/* 0x293a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_293f:
	/* 0x293f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2944:
	/* 0x2944: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2949:
	/* 0x2949: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294b:
	/* 0x294b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2950:
	/* 0x2950: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2955:
	/* 0x2955: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_295a:
	/* 0x295a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 10591ULL;
}

static __noinline __u64 tracee_sys_enter_submit_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10591ULL: goto x86_l_295f;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10612ULL: goto x86_l_2974;
	case 10617ULL: goto x86_l_2979;
	case 10622ULL: goto x86_l_297e;
	case 10627ULL: goto x86_l_2983;
	case 10632ULL: goto x86_l_2988;
	case 10635ULL: goto x86_l_298b;
	case 10637ULL: goto x86_l_298d;
	case 10642ULL: goto x86_l_2992;
	case 10647ULL: goto x86_l_2997;
	case 10651ULL: goto x86_l_299b;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10673ULL: goto x86_l_29b1;
	case 10678ULL: goto x86_l_29b6;
	case 10681ULL: goto x86_l_29b9;
	case 10687ULL: goto x86_l_29bf;
	case 10692ULL: goto x86_l_29c4;
	case 10695ULL: goto x86_l_29c7;
	case 10701ULL: goto x86_l_29cd;
	case 10705ULL: goto x86_l_29d1;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10720ULL: goto x86_l_29e0;
	case 10725ULL: goto x86_l_29e5;
	case 10727ULL: goto x86_l_29e7;
	case 10731ULL: goto x86_l_29eb;
	case 10733ULL: goto x86_l_29ed;
	case 10739ULL: goto x86_l_29f3;
	case 10744ULL: goto x86_l_29f8;
	case 10746ULL: goto x86_l_29fa;
	case 10752ULL: goto x86_l_2a00;
	case 10757ULL: goto x86_l_2a05;
	case 10763ULL: goto x86_l_2a0b;
	case 10768ULL: goto x86_l_2a10;
	case 10770ULL: goto x86_l_2a12;
	case 10775ULL: goto x86_l_2a17;
	case 10777ULL: goto x86_l_2a19;
	case 10780ULL: goto x86_l_2a1c;
	case 10786ULL: goto x86_l_2a22;
	case 10791ULL: goto x86_l_2a27;
	case 10794ULL: goto x86_l_2a2a;
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10809ULL: goto x86_l_2a39;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10821ULL: goto x86_l_2a45;
	case 10826ULL: goto x86_l_2a4a;
	case 10829ULL: goto x86_l_2a4d;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10845ULL: goto x86_l_2a5d;
	case 10851ULL: goto x86_l_2a63;
	case 10855ULL: goto x86_l_2a67;
	case 10860ULL: goto x86_l_2a6c;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10886ULL: goto x86_l_2a86;
	case 10891ULL: goto x86_l_2a8b;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10918ULL: goto x86_l_2aa6;
	case 10923ULL: goto x86_l_2aab;
	case 10928ULL: goto x86_l_2ab0;
	case 10933ULL: goto x86_l_2ab5;
	case 10938ULL: goto x86_l_2aba;
	case 10943ULL: goto x86_l_2abf;
	case 10948ULL: goto x86_l_2ac4;
	case 10950ULL: goto x86_l_2ac6;
	case 10955ULL: goto x86_l_2acb;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10969ULL: goto x86_l_2ad9;
	case 10974ULL: goto x86_l_2ade;
	case 10979ULL: goto x86_l_2ae3;
	case 10982ULL: goto x86_l_2ae6;
	case 10984ULL: goto x86_l_2ae8;
	case 10989ULL: goto x86_l_2aed;
	case 10994ULL: goto x86_l_2af2;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11008ULL: goto x86_l_2b00;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11020ULL: goto x86_l_2b0c;
	case 11025ULL: goto x86_l_2b11;
	case 11028ULL: goto x86_l_2b14;
	case 11034ULL: goto x86_l_2b1a;
	case 11039ULL: goto x86_l_2b1f;
	case 11042ULL: goto x86_l_2b22;
	case 11048ULL: goto x86_l_2b28;
	case 11052ULL: goto x86_l_2b2c;
	case 11057ULL: goto x86_l_2b31;
	case 11062ULL: goto x86_l_2b36;
	case 11067ULL: goto x86_l_2b3b;
	case 11072ULL: goto x86_l_2b40;
	case 11074ULL: goto x86_l_2b42;
	case 11078ULL: goto x86_l_2b46;
	case 11080ULL: goto x86_l_2b48;
	case 11086ULL: goto x86_l_2b4e;
	case 11091ULL: goto x86_l_2b53;
	case 11093ULL: goto x86_l_2b55;
	case 11099ULL: goto x86_l_2b5b;
	case 11104ULL: goto x86_l_2b60;
	case 11110ULL: goto x86_l_2b66;
	case 11115ULL: goto x86_l_2b6b;
	case 11117ULL: goto x86_l_2b6d;
	case 11122ULL: goto x86_l_2b72;
	case 11124ULL: goto x86_l_2b74;
	case 11127ULL: goto x86_l_2b77;
	case 11133ULL: goto x86_l_2b7d;
	case 11138ULL: goto x86_l_2b82;
	case 11141ULL: goto x86_l_2b85;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11156ULL: goto x86_l_2b94;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11173ULL: goto x86_l_2ba5;
	case 11176ULL: goto x86_l_2ba8;
	case 11182ULL: goto x86_l_2bae;
	case 11187ULL: goto x86_l_2bb3;
	case 11192ULL: goto x86_l_2bb8;
	case 11198ULL: goto x86_l_2bbe;
	case 11202ULL: goto x86_l_2bc2;
	case 11207ULL: goto x86_l_2bc7;
	case 11212ULL: goto x86_l_2bcc;
	case 11217ULL: goto x86_l_2bd1;
	case 11222ULL: goto x86_l_2bd6;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11233ULL: goto x86_l_2be1;
	case 11238ULL: goto x86_l_2be6;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11285ULL: goto x86_l_2c15;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11297ULL: goto x86_l_2c21;
	case 11302ULL: goto x86_l_2c26;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11316ULL: goto x86_l_2c34;
	case 11321ULL: goto x86_l_2c39;
	case 11326ULL: goto x86_l_2c3e;
	case 11329ULL: goto x86_l_2c41;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11345ULL: goto x86_l_2c51;
	case 11350ULL: goto x86_l_2c56;
	case 11355ULL: goto x86_l_2c5b;
	case 11360ULL: goto x86_l_2c60;
	case 11365ULL: goto x86_l_2c65;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11375ULL: goto x86_l_2c6f;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11389ULL: goto x86_l_2c7d;
	case 11395ULL: goto x86_l_2c83;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11409ULL: goto x86_l_2c91;
	case 11414ULL: goto x86_l_2c96;
	case 11419ULL: goto x86_l_2c9b;
	case 11421ULL: goto x86_l_2c9d;
	case 11425ULL: goto x86_l_2ca1;
	case 11427ULL: goto x86_l_2ca3;
	case 11433ULL: goto x86_l_2ca9;
	case 11438ULL: goto x86_l_2cae;
	case 11440ULL: goto x86_l_2cb0;
	case 11446ULL: goto x86_l_2cb6;
	case 11451ULL: goto x86_l_2cbb;
	case 11457ULL: goto x86_l_2cc1;
	case 11462ULL: goto x86_l_2cc6;
	case 11464ULL: goto x86_l_2cc8;
	case 11469ULL: goto x86_l_2ccd;
	case 11471ULL: goto x86_l_2ccf;
	case 11474ULL: goto x86_l_2cd2;
	case 11480ULL: goto x86_l_2cd8;
	case 11485ULL: goto x86_l_2cdd;
	case 11488ULL: goto x86_l_2ce0;
	case 11494ULL: goto x86_l_2ce6;
	case 11499ULL: goto x86_l_2ceb;
	case 11503ULL: goto x86_l_2cef;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11523ULL: goto x86_l_2d03;
	case 11529ULL: goto x86_l_2d09;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11545ULL: goto x86_l_2d19;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11559ULL: goto x86_l_2d27;
	case 11564ULL: goto x86_l_2d2c;
	case 11569ULL: goto x86_l_2d31;
	case 11573ULL: goto x86_l_2d35;
	case 11578ULL: goto x86_l_2d3a;
	case 11580ULL: goto x86_l_2d3c;
	case 11585ULL: goto x86_l_2d41;
	case 11590ULL: goto x86_l_2d46;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11605ULL: goto x86_l_2d55;
	case 11610ULL: goto x86_l_2d5a;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11622ULL: goto x86_l_2d66;
	case 11627ULL: goto x86_l_2d6b;
	case 11632ULL: goto x86_l_2d70;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11663ULL: goto x86_l_2d8f;
	case 11668ULL: goto x86_l_2d94;
	case 11673ULL: goto x86_l_2d99;
	case 11676ULL: goto x86_l_2d9c;
	case 11678ULL: goto x86_l_2d9e;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11702ULL: goto x86_l_2db6;
	case 11707ULL: goto x86_l_2dbb;
	case 11712ULL: goto x86_l_2dc0;
	case 11714ULL: goto x86_l_2dc2;
	case 11719ULL: goto x86_l_2dc7;
	case 11722ULL: goto x86_l_2dca;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11736ULL: goto x86_l_2dd8;
	case 11742ULL: goto x86_l_2dde;
	case 11746ULL: goto x86_l_2de2;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11761ULL: goto x86_l_2df1;
	case 11766ULL: goto x86_l_2df6;
	case 11768ULL: goto x86_l_2df8;
	case 11772ULL: goto x86_l_2dfc;
	case 11774ULL: goto x86_l_2dfe;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11787ULL: goto x86_l_2e0b;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	case 11804ULL: goto x86_l_2e1c;
	case 11809ULL: goto x86_l_2e21;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11821ULL: goto x86_l_2e2d;
	case 11827ULL: goto x86_l_2e33;
	case 11832ULL: goto x86_l_2e38;
	case 11835ULL: goto x86_l_2e3b;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11850ULL: goto x86_l_2e4a;
	case 11852ULL: goto x86_l_2e4c;
	case 11857ULL: goto x86_l_2e51;
	case 11862ULL: goto x86_l_2e56;
	case 11867ULL: goto x86_l_2e5b;
	case 11870ULL: goto x86_l_2e5e;
	case 11876ULL: goto x86_l_2e64;
	case 11881ULL: goto x86_l_2e69;
	case 11886ULL: goto x86_l_2e6e;
	case 11892ULL: goto x86_l_2e74;
	case 11896ULL: goto x86_l_2e78;
	case 11901ULL: goto x86_l_2e7d;
	case 11906ULL: goto x86_l_2e82;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11937ULL: goto x86_l_2ea1;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11952ULL: goto x86_l_2eb0;
	case 11957ULL: goto x86_l_2eb5;
	case 11959ULL: goto x86_l_2eb7;
	case 11964ULL: goto x86_l_2ebc;
	case 11969ULL: goto x86_l_2ec1;
	case 11974ULL: goto x86_l_2ec6;
	case 11979ULL: goto x86_l_2ecb;
	case 11984ULL: goto x86_l_2ed0;
	case 11989ULL: goto x86_l_2ed5;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 12000ULL: goto x86_l_2ee0;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12020ULL: goto x86_l_2ef4;
	case 12023ULL: goto x86_l_2ef7;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12035ULL: goto x86_l_2f03;
	case 12039ULL: goto x86_l_2f07;
	case 12044ULL: goto x86_l_2f0c;
	case 12049ULL: goto x86_l_2f11;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12061ULL: goto x86_l_2f1d;
	case 12066ULL: goto x86_l_2f22;
	case 12069ULL: goto x86_l_2f25;
	case 12075ULL: goto x86_l_2f2b;
	case 12080ULL: goto x86_l_2f30;
	case 12083ULL: goto x86_l_2f33;
	case 12089ULL: goto x86_l_2f39;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12108ULL: goto x86_l_2f4c;
	case 12113ULL: goto x86_l_2f51;
	case 12115ULL: goto x86_l_2f53;
	case 12119ULL: goto x86_l_2f57;
	case 12121ULL: goto x86_l_2f59;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12134ULL: goto x86_l_2f66;
	case 12140ULL: goto x86_l_2f6c;
	case 12145ULL: goto x86_l_2f71;
	case 12151ULL: goto x86_l_2f77;
	case 12156ULL: goto x86_l_2f7c;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12165ULL: goto x86_l_2f85;
	case 12168ULL: goto x86_l_2f88;
	case 12174ULL: goto x86_l_2f8e;
	case 12179ULL: goto x86_l_2f93;
	case 12182ULL: goto x86_l_2f96;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12197ULL: goto x86_l_2fa5;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12209ULL: goto x86_l_2fb1;
	case 12214ULL: goto x86_l_2fb6;
	case 12217ULL: goto x86_l_2fb9;
	case 12223ULL: goto x86_l_2fbf;
	case 12228ULL: goto x86_l_2fc4;
	case 12233ULL: goto x86_l_2fc9;
	case 12239ULL: goto x86_l_2fcf;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12253ULL: goto x86_l_2fdd;
	case 12258ULL: goto x86_l_2fe2;
	case 12263ULL: goto x86_l_2fe7;
	case 12267ULL: goto x86_l_2feb;
	case 12272ULL: goto x86_l_2ff0;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12284ULL: goto x86_l_2ffc;
	case 12289ULL: goto x86_l_3001;
	case 12294ULL: goto x86_l_3006;
	default: return 0xffffffffffffffffULL;
	}
x86_l_295f:
	/* 0x295f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2964:
	/* 0x2964: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2969:
	/* 0x2969: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_296b:
	/* 0x296b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2970:
	/* 0x2970: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2974:
	/* 0x2974: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2979:
	/* 0x2979: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_297e:
	/* 0x297e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2983:
	/* 0x2983: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2988:
	/* 0x2988: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_298b:
	/* 0x298b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_298d:
	/* 0x298d: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2992:
	/* 0x2992: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2997:
	/* 0x2997: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_299b:
	/* 0x299b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29a0:
	/* 0x29a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29a5:
	/* 0x29a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29aa:
	/* 0x29aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29af:
	/* 0x29af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b1:
	/* 0x29b1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29b6:
	/* 0x29b6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_29b9:
	/* 0x29b9: je     2a4a <sys_enter_submit+0x2a4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a4a;
	}
x86_l_29bf:
	/* 0x29bf: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29c4:
	/* 0x29c4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_29c7:
	/* 0x29c7: je     2a4a <sys_enter_submit+0x2a4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a4a;
	}
x86_l_29cd:
	/* 0x29cd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29d1:
	/* 0x29d1: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29d6:
	/* 0x29d6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_29db:
	/* 0x29db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29e0:
	/* 0x29e0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_29e5:
	/* 0x29e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e7:
	/* 0x29e7: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_29eb:
	/* 0x29eb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_29ed:
	/* 0x29ed: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29f3:
	/* 0x29f3: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29f8:
	/* 0x29f8: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29fa:
	/* 0x29fa: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_2a00:
	/* 0x2a00: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a05:
	/* 0x2a05: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a0b:
	/* 0x2a0b: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2a10:
	/* 0x2a10: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2a12:
	/* 0x2a12: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2a17:
	/* 0x2a17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a19:
	/* 0x2a19: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a1c:
	/* 0x2a1c: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_2a22:
	/* 0x2a22: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a27:
	/* 0x2a27: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2a2a:
	/* 0x2a2a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2a30:
	/* 0x2a30: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a35:
	/* 0x2a35: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2a39:
	/* 0x2a39: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a3b:
	/* 0x2a3b: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a40:
	/* 0x2a40: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a45:
	/* 0x2a45: jmp    2acf <sys_enter_submit+0x2acf> */
	goto x86_l_2acf;
x86_l_2a4a:
	/* 0x2a4a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a4d:
	/* 0x2a4d: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_2a53:
	/* 0x2a53: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a58:
	/* 0x2a58: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2a5d:
	/* 0x2a5d: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_2a63:
	/* 0x2a63: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a67:
	/* 0x2a67: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a6c:
	/* 0x2a6c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a71:
	/* 0x2a71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a76:
	/* 0x2a76: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a7b:
	/* 0x2a7b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a7f:
	/* 0x2a7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a84:
	/* 0x2a84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a86:
	/* 0x2a86: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a8b:
	/* 0x2a8b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a90:
	/* 0x2a90: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a95:
	/* 0x2a95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a9a:
	/* 0x2a9a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aa4:
	/* 0x2aa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa6:
	/* 0x2aa6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2aab:
	/* 0x2aab: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ab0:
	/* 0x2ab0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ab5:
	/* 0x2ab5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2aba:
	/* 0x2aba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2abf:
	/* 0x2abf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ac4:
	/* 0x2ac4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac6:
	/* 0x2ac6: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2acb:
	/* 0x2acb: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2acf:
	/* 0x2acf: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ad4:
	/* 0x2ad4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ad9:
	/* 0x2ad9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ade:
	/* 0x2ade: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ae3:
	/* 0x2ae3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2ae6:
	/* 0x2ae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae8:
	/* 0x2ae8: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2aed:
	/* 0x2aed: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2af2:
	/* 0x2af2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2af6:
	/* 0x2af6: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2afb:
	/* 0x2afb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b00:
	/* 0x2b00: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b05:
	/* 0x2b05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b0a:
	/* 0x2b0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0c:
	/* 0x2b0c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b11:
	/* 0x2b11: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b14:
	/* 0x2b14: je     2ba5 <sys_enter_submit+0x2ba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba5;
	}
x86_l_2b1a:
	/* 0x2b1a: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b1f:
	/* 0x2b1f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2b22:
	/* 0x2b22: je     2ba5 <sys_enter_submit+0x2ba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba5;
	}
x86_l_2b28:
	/* 0x2b28: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b2c:
	/* 0x2b2c: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b31:
	/* 0x2b31: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2b36:
	/* 0x2b36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b3b:
	/* 0x2b3b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b40:
	/* 0x2b40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b42:
	/* 0x2b42: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2b46:
	/* 0x2b46: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b48:
	/* 0x2b48: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b4e:
	/* 0x2b4e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b53:
	/* 0x2b53: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b55:
	/* 0x2b55: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_2b5b:
	/* 0x2b5b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b60:
	/* 0x2b60: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b66:
	/* 0x2b66: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2b6b:
	/* 0x2b6b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2b6d:
	/* 0x2b6d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2b72:
	/* 0x2b72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b74:
	/* 0x2b74: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b77:
	/* 0x2b77: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_2b7d:
	/* 0x2b7d: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b82:
	/* 0x2b82: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2b85:
	/* 0x2b85: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2b8b:
	/* 0x2b8b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b90:
	/* 0x2b90: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2b94:
	/* 0x2b94: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b96:
	/* 0x2b96: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b9b:
	/* 0x2b9b: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ba0:
	/* 0x2ba0: jmp    2c2a <sys_enter_submit+0x2c2a> */
	goto x86_l_2c2a;
x86_l_2ba5:
	/* 0x2ba5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ba8:
	/* 0x2ba8: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_2bae:
	/* 0x2bae: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bb3:
	/* 0x2bb3: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2bb8:
	/* 0x2bb8: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_2bbe:
	/* 0x2bbe: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bc2:
	/* 0x2bc2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bc7:
	/* 0x2bc7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bcc:
	/* 0x2bcc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bd1:
	/* 0x2bd1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bd6:
	/* 0x2bd6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bda:
	/* 0x2bda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bdf:
	/* 0x2bdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be1:
	/* 0x2be1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be6:
	/* 0x2be6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2beb:
	/* 0x2beb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bf0:
	/* 0x2bf0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bf5:
	/* 0x2bf5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bfa:
	/* 0x2bfa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bff:
	/* 0x2bff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c01:
	/* 0x2c01: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c06:
	/* 0x2c06: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c0b:
	/* 0x2c0b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c10:
	/* 0x2c10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c15:
	/* 0x2c15: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1a:
	/* 0x2c1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c1f:
	/* 0x2c1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c21:
	/* 0x2c21: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c26:
	/* 0x2c26: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c2a:
	/* 0x2c2a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c2f:
	/* 0x2c2f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c34:
	/* 0x2c34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c39:
	/* 0x2c39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c3e:
	/* 0x2c3e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2c41:
	/* 0x2c41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c43:
	/* 0x2c43: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c48:
	/* 0x2c48: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c4d:
	/* 0x2c4d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c51:
	/* 0x2c51: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c56:
	/* 0x2c56: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c5b:
	/* 0x2c5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c60:
	/* 0x2c60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c65:
	/* 0x2c65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c67:
	/* 0x2c67: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c6c:
	/* 0x2c6c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c6f:
	/* 0x2c6f: je     2d00 <sys_enter_submit+0x2d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d00;
	}
x86_l_2c75:
	/* 0x2c75: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c7a:
	/* 0x2c7a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c7d:
	/* 0x2c7d: je     2d00 <sys_enter_submit+0x2d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d00;
	}
x86_l_2c83:
	/* 0x2c83: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c87:
	/* 0x2c87: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c8c:
	/* 0x2c8c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2c91:
	/* 0x2c91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c96:
	/* 0x2c96: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c9b:
	/* 0x2c9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9d:
	/* 0x2c9d: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2ca1:
	/* 0x2ca1: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ca3:
	/* 0x2ca3: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cae:
	/* 0x2cae: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cb0:
	/* 0x2cb0: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_2cb6:
	/* 0x2cb6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cbb:
	/* 0x2cbb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2cc1:
	/* 0x2cc1: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2cc6:
	/* 0x2cc6: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2cc8:
	/* 0x2cc8: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2ccd:
	/* 0x2ccd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ccf:
	/* 0x2ccf: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cd2:
	/* 0x2cd2: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_2cd8:
	/* 0x2cd8: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cdd:
	/* 0x2cdd: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2ce0:
	/* 0x2ce0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2ce6:
	/* 0x2ce6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ceb:
	/* 0x2ceb: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2cef:
	/* 0x2cef: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cf1:
	/* 0x2cf1: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf6:
	/* 0x2cf6: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cfb:
	/* 0x2cfb: jmp    2d85 <sys_enter_submit+0x2d85> */
	goto x86_l_2d85;
x86_l_2d00:
	/* 0x2d00: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d03:
	/* 0x2d03: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_2d09:
	/* 0x2d09: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d0e:
	/* 0x2d0e: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2d13:
	/* 0x2d13: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_2d19:
	/* 0x2d19: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d1d:
	/* 0x2d1d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d22:
	/* 0x2d22: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d27:
	/* 0x2d27: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d2c:
	/* 0x2d2c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d31:
	/* 0x2d31: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d35:
	/* 0x2d35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d3a:
	/* 0x2d3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3c:
	/* 0x2d3c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d41:
	/* 0x2d41: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d46:
	/* 0x2d46: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d4b:
	/* 0x2d4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d50:
	/* 0x2d50: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d55:
	/* 0x2d55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d5a:
	/* 0x2d5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5c:
	/* 0x2d5c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d61:
	/* 0x2d61: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d66:
	/* 0x2d66: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d6b:
	/* 0x2d6b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d70:
	/* 0x2d70: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d75:
	/* 0x2d75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d7a:
	/* 0x2d7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d7c:
	/* 0x2d7c: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d81:
	/* 0x2d81: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d85:
	/* 0x2d85: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d8a:
	/* 0x2d8a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d8f:
	/* 0x2d8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d94:
	/* 0x2d94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d99:
	/* 0x2d99: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2d9c:
	/* 0x2d9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9e:
	/* 0x2d9e: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2da3:
	/* 0x2da3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2da8:
	/* 0x2da8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2dac:
	/* 0x2dac: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2db1:
	/* 0x2db1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2db6:
	/* 0x2db6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dbb:
	/* 0x2dbb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dc0:
	/* 0x2dc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc2:
	/* 0x2dc2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dc7:
	/* 0x2dc7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2dca:
	/* 0x2dca: je     2e5b <sys_enter_submit+0x2e5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e5b;
	}
x86_l_2dd0:
	/* 0x2dd0: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dd5:
	/* 0x2dd5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2dd8:
	/* 0x2dd8: je     2e5b <sys_enter_submit+0x2e5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e5b;
	}
x86_l_2dde:
	/* 0x2dde: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2de2:
	/* 0x2de2: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2de7:
	/* 0x2de7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2dec:
	/* 0x2dec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2df1:
	/* 0x2df1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2df6:
	/* 0x2df6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df8:
	/* 0x2df8: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2dfc:
	/* 0x2dfc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2dfe:
	/* 0x2dfe: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e04:
	/* 0x2e04: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e09:
	/* 0x2e09: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e0b:
	/* 0x2e0b: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_2e11:
	/* 0x2e11: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e16:
	/* 0x2e16: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2e1c:
	/* 0x2e1c: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2e21:
	/* 0x2e21: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2e23:
	/* 0x2e23: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2e28:
	/* 0x2e28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2a:
	/* 0x2e2a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e2d:
	/* 0x2e2d: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_2e33:
	/* 0x2e33: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e38:
	/* 0x2e38: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2e3b:
	/* 0x2e3b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2e41:
	/* 0x2e41: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e46:
	/* 0x2e46: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e4a:
	/* 0x2e4a: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e4c:
	/* 0x2e4c: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e51:
	/* 0x2e51: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e56:
	/* 0x2e56: jmp    2ee0 <sys_enter_submit+0x2ee0> */
	goto x86_l_2ee0;
x86_l_2e5b:
	/* 0x2e5b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e5e:
	/* 0x2e5e: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_2e64:
	/* 0x2e64: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e69:
	/* 0x2e69: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2e6e:
	/* 0x2e6e: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_2e74:
	/* 0x2e74: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e78:
	/* 0x2e78: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e82:
	/* 0x2e82: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e87:
	/* 0x2e87: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e8c:
	/* 0x2e8c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e90:
	/* 0x2e90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e95:
	/* 0x2e95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e97:
	/* 0x2e97: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e9c:
	/* 0x2e9c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ea1:
	/* 0x2ea1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ea6:
	/* 0x2ea6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eab:
	/* 0x2eab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eb0:
	/* 0x2eb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb5:
	/* 0x2eb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb7:
	/* 0x2eb7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ebc:
	/* 0x2ebc: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ec6:
	/* 0x2ec6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ecb:
	/* 0x2ecb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ed0:
	/* 0x2ed0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ed5:
	/* 0x2ed5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed7:
	/* 0x2ed7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2edc:
	/* 0x2edc: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ee0:
	/* 0x2ee0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ee5:
	/* 0x2ee5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2eea:
	/* 0x2eea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eef:
	/* 0x2eef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ef4:
	/* 0x2ef4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2ef7:
	/* 0x2ef7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef9:
	/* 0x2ef9: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2efe:
	/* 0x2efe: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f03:
	/* 0x2f03: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f07:
	/* 0x2f07: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f0c:
	/* 0x2f0c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f11:
	/* 0x2f11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f16:
	/* 0x2f16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f1b:
	/* 0x2f1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1d:
	/* 0x2f1d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f22:
	/* 0x2f22: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2f25:
	/* 0x2f25: je     2fb6 <sys_enter_submit+0x2fb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fb6;
	}
x86_l_2f2b:
	/* 0x2f2b: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f30:
	/* 0x2f30: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2f33:
	/* 0x2f33: je     2fb6 <sys_enter_submit+0x2fb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fb6;
	}
x86_l_2f39:
	/* 0x2f39: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f3d:
	/* 0x2f3d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f42:
	/* 0x2f42: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2f47:
	/* 0x2f47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f4c:
	/* 0x2f4c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2f51:
	/* 0x2f51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f53:
	/* 0x2f53: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2f57:
	/* 0x2f57: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f59:
	/* 0x2f59: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f64:
	/* 0x2f64: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f66:
	/* 0x2f66: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_2f6c:
	/* 0x2f6c: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f71:
	/* 0x2f71: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f77:
	/* 0x2f77: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2f7c:
	/* 0x2f7c: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2f7e:
	/* 0x2f7e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f83:
	/* 0x2f83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f85:
	/* 0x2f85: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f88:
	/* 0x2f88: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_2f8e:
	/* 0x2f8e: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f93:
	/* 0x2f93: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2f96:
	/* 0x2f96: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f9c:
	/* 0x2f9c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fa1:
	/* 0x2fa1: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2fa5:
	/* 0x2fa5: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fa7:
	/* 0x2fa7: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fac:
	/* 0x2fac: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fb1:
	/* 0x2fb1: jmp    303b <sys_enter_submit+0x303b> */
	return 12347ULL;
x86_l_2fb6:
	/* 0x2fb6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2fb9:
	/* 0x2fb9: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_2fbf:
	/* 0x2fbf: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fc4:
	/* 0x2fc4: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2fc9:
	/* 0x2fc9: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_2fcf:
	/* 0x2fcf: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fd3:
	/* 0x2fd3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fd8:
	/* 0x2fd8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fdd:
	/* 0x2fdd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fe2:
	/* 0x2fe2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fe7:
	/* 0x2fe7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2feb:
	/* 0x2feb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ff0:
	/* 0x2ff0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff2:
	/* 0x2ff2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ff7:
	/* 0x2ff7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ffc:
	/* 0x2ffc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3001:
	/* 0x3001: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3006:
	/* 0x3006: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 12299ULL;
}

static __noinline __u64 tracee_sys_enter_submit_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12299ULL: goto x86_l_300b;
	case 12304ULL: goto x86_l_3010;
	case 12306ULL: goto x86_l_3012;
	case 12311ULL: goto x86_l_3017;
	case 12316ULL: goto x86_l_301c;
	case 12321ULL: goto x86_l_3021;
	case 12326ULL: goto x86_l_3026;
	case 12331ULL: goto x86_l_302b;
	case 12336ULL: goto x86_l_3030;
	case 12338ULL: goto x86_l_3032;
	case 12343ULL: goto x86_l_3037;
	case 12347ULL: goto x86_l_303b;
	case 12352ULL: goto x86_l_3040;
	case 12357ULL: goto x86_l_3045;
	case 12362ULL: goto x86_l_304a;
	case 12367ULL: goto x86_l_304f;
	case 12370ULL: goto x86_l_3052;
	case 12372ULL: goto x86_l_3054;
	case 12377ULL: goto x86_l_3059;
	case 12382ULL: goto x86_l_305e;
	case 12386ULL: goto x86_l_3062;
	case 12391ULL: goto x86_l_3067;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12406ULL: goto x86_l_3076;
	case 12408ULL: goto x86_l_3078;
	case 12413ULL: goto x86_l_307d;
	case 12416ULL: goto x86_l_3080;
	case 12422ULL: goto x86_l_3086;
	case 12427ULL: goto x86_l_308b;
	case 12430ULL: goto x86_l_308e;
	case 12436ULL: goto x86_l_3094;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12450ULL: goto x86_l_30a2;
	case 12455ULL: goto x86_l_30a7;
	case 12460ULL: goto x86_l_30ac;
	case 12462ULL: goto x86_l_30ae;
	case 12466ULL: goto x86_l_30b2;
	case 12468ULL: goto x86_l_30b4;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12481ULL: goto x86_l_30c1;
	case 12487ULL: goto x86_l_30c7;
	case 12492ULL: goto x86_l_30cc;
	case 12498ULL: goto x86_l_30d2;
	case 12503ULL: goto x86_l_30d7;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12512ULL: goto x86_l_30e0;
	case 12515ULL: goto x86_l_30e3;
	case 12521ULL: goto x86_l_30e9;
	case 12526ULL: goto x86_l_30ee;
	case 12529ULL: goto x86_l_30f1;
	case 12535ULL: goto x86_l_30f7;
	case 12540ULL: goto x86_l_30fc;
	case 12544ULL: goto x86_l_3100;
	case 12546ULL: goto x86_l_3102;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12561ULL: goto x86_l_3111;
	case 12564ULL: goto x86_l_3114;
	case 12570ULL: goto x86_l_311a;
	case 12575ULL: goto x86_l_311f;
	case 12580ULL: goto x86_l_3124;
	case 12586ULL: goto x86_l_312a;
	case 12590ULL: goto x86_l_312e;
	case 12595ULL: goto x86_l_3133;
	case 12600ULL: goto x86_l_3138;
	case 12605ULL: goto x86_l_313d;
	case 12610ULL: goto x86_l_3142;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12621ULL: goto x86_l_314d;
	case 12626ULL: goto x86_l_3152;
	case 12631ULL: goto x86_l_3157;
	case 12636ULL: goto x86_l_315c;
	case 12641ULL: goto x86_l_3161;
	case 12646ULL: goto x86_l_3166;
	case 12651ULL: goto x86_l_316b;
	case 12653ULL: goto x86_l_316d;
	case 12658ULL: goto x86_l_3172;
	case 12663ULL: goto x86_l_3177;
	case 12668ULL: goto x86_l_317c;
	case 12673ULL: goto x86_l_3181;
	case 12678ULL: goto x86_l_3186;
	case 12683ULL: goto x86_l_318b;
	case 12685ULL: goto x86_l_318d;
	case 12690ULL: goto x86_l_3192;
	case 12694ULL: goto x86_l_3196;
	case 12699ULL: goto x86_l_319b;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12714ULL: goto x86_l_31aa;
	case 12717ULL: goto x86_l_31ad;
	case 12719ULL: goto x86_l_31af;
	case 12724ULL: goto x86_l_31b4;
	case 12729ULL: goto x86_l_31b9;
	case 12733ULL: goto x86_l_31bd;
	case 12738ULL: goto x86_l_31c2;
	case 12743ULL: goto x86_l_31c7;
	case 12748ULL: goto x86_l_31cc;
	case 12753ULL: goto x86_l_31d1;
	case 12755ULL: goto x86_l_31d3;
	case 12760ULL: goto x86_l_31d8;
	case 12763ULL: goto x86_l_31db;
	case 12769ULL: goto x86_l_31e1;
	case 12774ULL: goto x86_l_31e6;
	case 12777ULL: goto x86_l_31e9;
	case 12783ULL: goto x86_l_31ef;
	case 12787ULL: goto x86_l_31f3;
	case 12792ULL: goto x86_l_31f8;
	case 12797ULL: goto x86_l_31fd;
	case 12802ULL: goto x86_l_3202;
	case 12807ULL: goto x86_l_3207;
	case 12809ULL: goto x86_l_3209;
	case 12813ULL: goto x86_l_320d;
	case 12815ULL: goto x86_l_320f;
	case 12821ULL: goto x86_l_3215;
	case 12826ULL: goto x86_l_321a;
	case 12828ULL: goto x86_l_321c;
	case 12834ULL: goto x86_l_3222;
	case 12839ULL: goto x86_l_3227;
	case 12845ULL: goto x86_l_322d;
	case 12850ULL: goto x86_l_3232;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12859ULL: goto x86_l_323b;
	case 12862ULL: goto x86_l_323e;
	case 12868ULL: goto x86_l_3244;
	case 12873ULL: goto x86_l_3249;
	case 12876ULL: goto x86_l_324c;
	case 12882ULL: goto x86_l_3252;
	case 12887ULL: goto x86_l_3257;
	case 12891ULL: goto x86_l_325b;
	case 12893ULL: goto x86_l_325d;
	case 12898ULL: goto x86_l_3262;
	case 12903ULL: goto x86_l_3267;
	case 12908ULL: goto x86_l_326c;
	case 12911ULL: goto x86_l_326f;
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12927ULL: goto x86_l_327f;
	case 12933ULL: goto x86_l_3285;
	case 12937ULL: goto x86_l_3289;
	case 12942ULL: goto x86_l_328e;
	case 12947ULL: goto x86_l_3293;
	case 12952ULL: goto x86_l_3298;
	case 12957ULL: goto x86_l_329d;
	case 12961ULL: goto x86_l_32a1;
	case 12966ULL: goto x86_l_32a6;
	case 12968ULL: goto x86_l_32a8;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12983ULL: goto x86_l_32b7;
	case 12988ULL: goto x86_l_32bc;
	case 12993ULL: goto x86_l_32c1;
	case 12998ULL: goto x86_l_32c6;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13010ULL: goto x86_l_32d2;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13025ULL: goto x86_l_32e1;
	case 13030ULL: goto x86_l_32e6;
	case 13032ULL: goto x86_l_32e8;
	case 13037ULL: goto x86_l_32ed;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13051ULL: goto x86_l_32fb;
	case 13056ULL: goto x86_l_3300;
	case 13061ULL: goto x86_l_3305;
	case 13064ULL: goto x86_l_3308;
	case 13066ULL: goto x86_l_330a;
	case 13071ULL: goto x86_l_330f;
	case 13076ULL: goto x86_l_3314;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13090ULL: goto x86_l_3322;
	case 13095ULL: goto x86_l_3327;
	case 13100ULL: goto x86_l_332c;
	case 13102ULL: goto x86_l_332e;
	case 13107ULL: goto x86_l_3333;
	case 13110ULL: goto x86_l_3336;
	case 13116ULL: goto x86_l_333c;
	case 13121ULL: goto x86_l_3341;
	case 13124ULL: goto x86_l_3344;
	case 13130ULL: goto x86_l_334a;
	case 13134ULL: goto x86_l_334e;
	case 13139ULL: goto x86_l_3353;
	case 13144ULL: goto x86_l_3358;
	case 13149ULL: goto x86_l_335d;
	case 13154ULL: goto x86_l_3362;
	case 13156ULL: goto x86_l_3364;
	case 13160ULL: goto x86_l_3368;
	case 13162ULL: goto x86_l_336a;
	case 13168ULL: goto x86_l_3370;
	case 13173ULL: goto x86_l_3375;
	case 13175ULL: goto x86_l_3377;
	case 13181ULL: goto x86_l_337d;
	case 13186ULL: goto x86_l_3382;
	case 13192ULL: goto x86_l_3388;
	case 13197ULL: goto x86_l_338d;
	case 13199ULL: goto x86_l_338f;
	case 13204ULL: goto x86_l_3394;
	case 13206ULL: goto x86_l_3396;
	case 13209ULL: goto x86_l_3399;
	case 13215ULL: goto x86_l_339f;
	case 13220ULL: goto x86_l_33a4;
	case 13223ULL: goto x86_l_33a7;
	case 13229ULL: goto x86_l_33ad;
	case 13234ULL: goto x86_l_33b2;
	case 13238ULL: goto x86_l_33b6;
	case 13240ULL: goto x86_l_33b8;
	case 13245ULL: goto x86_l_33bd;
	case 13250ULL: goto x86_l_33c2;
	case 13255ULL: goto x86_l_33c7;
	case 13258ULL: goto x86_l_33ca;
	case 13264ULL: goto x86_l_33d0;
	case 13269ULL: goto x86_l_33d5;
	case 13274ULL: goto x86_l_33da;
	case 13280ULL: goto x86_l_33e0;
	case 13284ULL: goto x86_l_33e4;
	case 13289ULL: goto x86_l_33e9;
	case 13294ULL: goto x86_l_33ee;
	case 13299ULL: goto x86_l_33f3;
	case 13304ULL: goto x86_l_33f8;
	case 13308ULL: goto x86_l_33fc;
	case 13313ULL: goto x86_l_3401;
	case 13315ULL: goto x86_l_3403;
	case 13320ULL: goto x86_l_3408;
	case 13325ULL: goto x86_l_340d;
	case 13330ULL: goto x86_l_3412;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13345ULL: goto x86_l_3421;
	case 13347ULL: goto x86_l_3423;
	case 13352ULL: goto x86_l_3428;
	case 13357ULL: goto x86_l_342d;
	case 13362ULL: goto x86_l_3432;
	case 13367ULL: goto x86_l_3437;
	case 13372ULL: goto x86_l_343c;
	case 13377ULL: goto x86_l_3441;
	case 13379ULL: goto x86_l_3443;
	case 13384ULL: goto x86_l_3448;
	case 13388ULL: goto x86_l_344c;
	case 13393ULL: goto x86_l_3451;
	case 13398ULL: goto x86_l_3456;
	case 13403ULL: goto x86_l_345b;
	case 13408ULL: goto x86_l_3460;
	case 13411ULL: goto x86_l_3463;
	case 13413ULL: goto x86_l_3465;
	case 13418ULL: goto x86_l_346a;
	case 13423ULL: goto x86_l_346f;
	case 13427ULL: goto x86_l_3473;
	case 13432ULL: goto x86_l_3478;
	case 13437ULL: goto x86_l_347d;
	case 13442ULL: goto x86_l_3482;
	case 13447ULL: goto x86_l_3487;
	case 13449ULL: goto x86_l_3489;
	case 13454ULL: goto x86_l_348e;
	case 13457ULL: goto x86_l_3491;
	case 13463ULL: goto x86_l_3497;
	case 13468ULL: goto x86_l_349c;
	case 13471ULL: goto x86_l_349f;
	case 13477ULL: goto x86_l_34a5;
	case 13481ULL: goto x86_l_34a9;
	case 13486ULL: goto x86_l_34ae;
	case 13491ULL: goto x86_l_34b3;
	case 13496ULL: goto x86_l_34b8;
	case 13501ULL: goto x86_l_34bd;
	case 13503ULL: goto x86_l_34bf;
	case 13507ULL: goto x86_l_34c3;
	case 13509ULL: goto x86_l_34c5;
	case 13515ULL: goto x86_l_34cb;
	case 13520ULL: goto x86_l_34d0;
	case 13522ULL: goto x86_l_34d2;
	case 13528ULL: goto x86_l_34d8;
	case 13533ULL: goto x86_l_34dd;
	case 13539ULL: goto x86_l_34e3;
	case 13544ULL: goto x86_l_34e8;
	case 13546ULL: goto x86_l_34ea;
	case 13551ULL: goto x86_l_34ef;
	case 13553ULL: goto x86_l_34f1;
	case 13556ULL: goto x86_l_34f4;
	case 13562ULL: goto x86_l_34fa;
	case 13567ULL: goto x86_l_34ff;
	case 13570ULL: goto x86_l_3502;
	case 13576ULL: goto x86_l_3508;
	case 13581ULL: goto x86_l_350d;
	case 13586ULL: goto x86_l_3512;
	case 13588ULL: goto x86_l_3514;
	case 13593ULL: goto x86_l_3519;
	case 13599ULL: goto x86_l_351f;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13613ULL: goto x86_l_352d;
	case 13619ULL: goto x86_l_3533;
	case 13624ULL: goto x86_l_3538;
	case 13629ULL: goto x86_l_353d;
	case 13635ULL: goto x86_l_3543;
	case 13639ULL: goto x86_l_3547;
	case 13644ULL: goto x86_l_354c;
	case 13649ULL: goto x86_l_3551;
	case 13654ULL: goto x86_l_3556;
	case 13659ULL: goto x86_l_355b;
	case 13663ULL: goto x86_l_355f;
	case 13668ULL: goto x86_l_3564;
	case 13670ULL: goto x86_l_3566;
	case 13675ULL: goto x86_l_356b;
	case 13680ULL: goto x86_l_3570;
	case 13685ULL: goto x86_l_3575;
	case 13690ULL: goto x86_l_357a;
	case 13695ULL: goto x86_l_357f;
	case 13700ULL: goto x86_l_3584;
	case 13702ULL: goto x86_l_3586;
	case 13707ULL: goto x86_l_358b;
	case 13712ULL: goto x86_l_3590;
	case 13717ULL: goto x86_l_3595;
	case 13722ULL: goto x86_l_359a;
	case 13727ULL: goto x86_l_359f;
	case 13732ULL: goto x86_l_35a4;
	case 13734ULL: goto x86_l_35a6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_300b:
	/* 0x300b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3010:
	/* 0x3010: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3012:
	/* 0x3012: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3017:
	/* 0x3017: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_301c:
	/* 0x301c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3021:
	/* 0x3021: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3026:
	/* 0x3026: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_302b:
	/* 0x302b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3030:
	/* 0x3030: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3032:
	/* 0x3032: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3037:
	/* 0x3037: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_303b:
	/* 0x303b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3040:
	/* 0x3040: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3045:
	/* 0x3045: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_304a:
	/* 0x304a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_304f:
	/* 0x304f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3052:
	/* 0x3052: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3054:
	/* 0x3054: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3059:
	/* 0x3059: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_305e:
	/* 0x305e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3062:
	/* 0x3062: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3067:
	/* 0x3067: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_306c:
	/* 0x306c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3071:
	/* 0x3071: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3076:
	/* 0x3076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3078:
	/* 0x3078: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_307d:
	/* 0x307d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3080:
	/* 0x3080: je     3111 <sys_enter_submit+0x3111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3111;
	}
x86_l_3086:
	/* 0x3086: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_308b:
	/* 0x308b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_308e:
	/* 0x308e: je     3111 <sys_enter_submit+0x3111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3111;
	}
x86_l_3094:
	/* 0x3094: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3098:
	/* 0x3098: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_309d:
	/* 0x309d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_30a2:
	/* 0x30a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30a7:
	/* 0x30a7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_30ac:
	/* 0x30ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ae:
	/* 0x30ae: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_30b2:
	/* 0x30b2: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_30b4:
	/* 0x30b4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30ba:
	/* 0x30ba: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30bf:
	/* 0x30bf: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30c1:
	/* 0x30c1: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_30c7:
	/* 0x30c7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30cc:
	/* 0x30cc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_30d2:
	/* 0x30d2: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_30d7:
	/* 0x30d7: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_30d9:
	/* 0x30d9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_30de:
	/* 0x30de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30e0:
	/* 0x30e0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_30e3:
	/* 0x30e3: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_30e9:
	/* 0x30e9: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30ee:
	/* 0x30ee: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_30f1:
	/* 0x30f1: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_30f7:
	/* 0x30f7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30fc:
	/* 0x30fc: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3100:
	/* 0x3100: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3102:
	/* 0x3102: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3107:
	/* 0x3107: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_310c:
	/* 0x310c: jmp    3196 <sys_enter_submit+0x3196> */
	goto x86_l_3196;
x86_l_3111:
	/* 0x3111: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3114:
	/* 0x3114: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_311a:
	/* 0x311a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_311f:
	/* 0x311f: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_3124:
	/* 0x3124: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_312a:
	/* 0x312a: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_312e:
	/* 0x312e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3133:
	/* 0x3133: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3138:
	/* 0x3138: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_313d:
	/* 0x313d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3142:
	/* 0x3142: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3146:
	/* 0x3146: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_314b:
	/* 0x314b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314d:
	/* 0x314d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3152:
	/* 0x3152: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3157:
	/* 0x3157: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_315c:
	/* 0x315c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3161:
	/* 0x3161: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3166:
	/* 0x3166: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_316b:
	/* 0x316b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_316d:
	/* 0x316d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3172:
	/* 0x3172: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3177:
	/* 0x3177: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_317c:
	/* 0x317c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3181:
	/* 0x3181: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3186:
	/* 0x3186: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_318b:
	/* 0x318b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_318d:
	/* 0x318d: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3192:
	/* 0x3192: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3196:
	/* 0x3196: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_319b:
	/* 0x319b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31a0:
	/* 0x31a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31a5:
	/* 0x31a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31aa:
	/* 0x31aa: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_31ad:
	/* 0x31ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31af:
	/* 0x31af: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31b4:
	/* 0x31b4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31b9:
	/* 0x31b9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31bd:
	/* 0x31bd: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31c2:
	/* 0x31c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31c7:
	/* 0x31c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31cc:
	/* 0x31cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d1:
	/* 0x31d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d3:
	/* 0x31d3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31d8:
	/* 0x31d8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31db:
	/* 0x31db: je     326c <sys_enter_submit+0x326c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326c;
	}
x86_l_31e1:
	/* 0x31e1: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31e6:
	/* 0x31e6: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31e9:
	/* 0x31e9: je     326c <sys_enter_submit+0x326c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326c;
	}
x86_l_31ef:
	/* 0x31ef: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31f3:
	/* 0x31f3: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31f8:
	/* 0x31f8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_31fd:
	/* 0x31fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3202:
	/* 0x3202: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3207:
	/* 0x3207: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3209:
	/* 0x3209: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_320d:
	/* 0x320d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_320f:
	/* 0x320f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3215:
	/* 0x3215: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_321a:
	/* 0x321a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_321c:
	/* 0x321c: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_3222:
	/* 0x3222: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3227:
	/* 0x3227: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_322d:
	/* 0x322d: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3232:
	/* 0x3232: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3234:
	/* 0x3234: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3239:
	/* 0x3239: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_323b:
	/* 0x323b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_323e:
	/* 0x323e: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_3244:
	/* 0x3244: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3249:
	/* 0x3249: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_324c:
	/* 0x324c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3252:
	/* 0x3252: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3257:
	/* 0x3257: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_325b:
	/* 0x325b: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_325d:
	/* 0x325d: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3262:
	/* 0x3262: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3267:
	/* 0x3267: jmp    32f1 <sys_enter_submit+0x32f1> */
	goto x86_l_32f1;
x86_l_326c:
	/* 0x326c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_326f:
	/* 0x326f: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_3275:
	/* 0x3275: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_327a:
	/* 0x327a: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_327f:
	/* 0x327f: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_3285:
	/* 0x3285: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3289:
	/* 0x3289: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_328e:
	/* 0x328e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3293:
	/* 0x3293: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3298:
	/* 0x3298: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_329d:
	/* 0x329d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_32a1:
	/* 0x32a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32a6:
	/* 0x32a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a8:
	/* 0x32a8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32ad:
	/* 0x32ad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32b2:
	/* 0x32b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32b7:
	/* 0x32b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32bc:
	/* 0x32bc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32c1:
	/* 0x32c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c6:
	/* 0x32c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c8:
	/* 0x32c8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32cd:
	/* 0x32cd: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_32d2:
	/* 0x32d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32d7:
	/* 0x32d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32dc:
	/* 0x32dc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32e1:
	/* 0x32e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e6:
	/* 0x32e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e8:
	/* 0x32e8: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32ed:
	/* 0x32ed: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32f1:
	/* 0x32f1: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32f6:
	/* 0x32f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32fb:
	/* 0x32fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3300:
	/* 0x3300: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3305:
	/* 0x3305: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3308:
	/* 0x3308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_330a:
	/* 0x330a: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_330f:
	/* 0x330f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3314:
	/* 0x3314: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3318:
	/* 0x3318: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_331d:
	/* 0x331d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3322:
	/* 0x3322: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3327:
	/* 0x3327: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_332c:
	/* 0x332c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332e:
	/* 0x332e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3333:
	/* 0x3333: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3336:
	/* 0x3336: je     33c7 <sys_enter_submit+0x33c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33c7;
	}
x86_l_333c:
	/* 0x333c: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3341:
	/* 0x3341: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3344:
	/* 0x3344: je     33c7 <sys_enter_submit+0x33c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33c7;
	}
x86_l_334a:
	/* 0x334a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_334e:
	/* 0x334e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3353:
	/* 0x3353: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3358:
	/* 0x3358: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_335d:
	/* 0x335d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3362:
	/* 0x3362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3364:
	/* 0x3364: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3368:
	/* 0x3368: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_336a:
	/* 0x336a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3370:
	/* 0x3370: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3375:
	/* 0x3375: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3377:
	/* 0x3377: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_337d:
	/* 0x337d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3382:
	/* 0x3382: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3388:
	/* 0x3388: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_338d:
	/* 0x338d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_338f:
	/* 0x338f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3394:
	/* 0x3394: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3396:
	/* 0x3396: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3399:
	/* 0x3399: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_339f:
	/* 0x339f: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33a4:
	/* 0x33a4: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_33a7:
	/* 0x33a7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_33ad:
	/* 0x33ad: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33b2:
	/* 0x33b2: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_33b6:
	/* 0x33b6: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33b8:
	/* 0x33b8: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33bd:
	/* 0x33bd: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33c2:
	/* 0x33c2: jmp    344c <sys_enter_submit+0x344c> */
	goto x86_l_344c;
x86_l_33c7:
	/* 0x33c7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_33ca:
	/* 0x33ca: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_33d0:
	/* 0x33d0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33d5:
	/* 0x33d5: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_33da:
	/* 0x33da: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_33e0:
	/* 0x33e0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33e4:
	/* 0x33e4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33e9:
	/* 0x33e9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33ee:
	/* 0x33ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33f3:
	/* 0x33f3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33f8:
	/* 0x33f8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33fc:
	/* 0x33fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3401:
	/* 0x3401: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3403:
	/* 0x3403: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3408:
	/* 0x3408: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_340d:
	/* 0x340d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3412:
	/* 0x3412: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3417:
	/* 0x3417: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_341c:
	/* 0x341c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3421:
	/* 0x3421: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3423:
	/* 0x3423: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3428:
	/* 0x3428: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_342d:
	/* 0x342d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3432:
	/* 0x3432: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3437:
	/* 0x3437: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_343c:
	/* 0x343c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3441:
	/* 0x3441: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3443:
	/* 0x3443: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3448:
	/* 0x3448: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_344c:
	/* 0x344c: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3451:
	/* 0x3451: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3456:
	/* 0x3456: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_345b:
	/* 0x345b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3460:
	/* 0x3460: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3463:
	/* 0x3463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3465:
	/* 0x3465: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_346a:
	/* 0x346a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_346f:
	/* 0x346f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3473:
	/* 0x3473: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3478:
	/* 0x3478: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_347d:
	/* 0x347d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3482:
	/* 0x3482: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3487:
	/* 0x3487: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3489:
	/* 0x3489: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_348e:
	/* 0x348e: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3491:
	/* 0x3491: je     352a <sys_enter_submit+0x352a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_352a;
	}
x86_l_3497:
	/* 0x3497: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_349c:
	/* 0x349c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_349f:
	/* 0x349f: je     352a <sys_enter_submit+0x352a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_352a;
	}
x86_l_34a5:
	/* 0x34a5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_34a9:
	/* 0x34a9: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_34ae:
	/* 0x34ae: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_34b3:
	/* 0x34b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34b8:
	/* 0x34b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_34bd:
	/* 0x34bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34bf:
	/* 0x34bf: mov    esi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_34c3:
	/* 0x34c3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_34c5:
	/* 0x34c5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_34cb:
	/* 0x34cb: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34d0:
	/* 0x34d0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34d2:
	/* 0x34d2: jb     1d60 <sys_enter_submit+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7520ULL;
	}
x86_l_34d8:
	/* 0x34d8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34dd:
	/* 0x34dd: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_34e3:
	/* 0x34e3: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_34e8:
	/* 0x34e8: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_34ea:
	/* 0x34ea: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_34ef:
	/* 0x34ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f1:
	/* 0x34f1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_34f4:
	/* 0x34f4: jl     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 7105ULL;
	}
x86_l_34fa:
	/* 0x34fa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34ff:
	/* 0x34ff: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3502:
	/* 0x3502: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3508:
	/* 0x3508: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_350d:
	/* 0x350d: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3512:
	/* 0x3512: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3514:
	/* 0x3514: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3519:
	/* 0x3519: cmp    edx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16384ULL);
x86_l_351f:
	/* 0x351f: je     1bd7 <sys_enter_submit+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7127ULL;
	}
x86_l_3525:
	/* 0x3525: jmp    1d6a <sys_enter_submit+0x1d6a> */
	return 7530ULL;
x86_l_352a:
	/* 0x352a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_352d:
	/* 0x352d: jne    1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7105ULL;
	}
x86_l_3533:
	/* 0x3533: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3538:
	/* 0x3538: cmp    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_353d:
	/* 0x353d: je     1bc1 <sys_enter_submit+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7105ULL;
	}
x86_l_3543:
	/* 0x3543: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3547:
	/* 0x3547: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_354c:
	/* 0x354c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3551:
	/* 0x3551: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3556:
	/* 0x3556: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_355b:
	/* 0x355b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_355f:
	/* 0x355f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3564:
	/* 0x3564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3566:
	/* 0x3566: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_356b:
	/* 0x356b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3570:
	/* 0x3570: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3575:
	/* 0x3575: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_357a:
	/* 0x357a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_357f:
	/* 0x357f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3584:
	/* 0x3584: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3586:
	/* 0x3586: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_358b:
	/* 0x358b: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3590:
	/* 0x3590: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3595:
	/* 0x3595: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_359a:
	/* 0x359a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_359f:
	/* 0x359f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35a4:
	/* 0x35a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35a6:
	/* 0x35a6: jmp    1bc1 <sys_enter_submit+0x1bc1> */
	return 7105ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_sys_enter_submit_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12044U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2124ULL)
			__x86_pc = tracee_sys_enter_submit_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2129ULL && __x86_pc <= 3870ULL)
			__x86_pc = tracee_sys_enter_submit_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3874ULL && __x86_pc <= 5472ULL)
			__x86_pc = tracee_sys_enter_submit_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5478ULL && __x86_pc <= 7190ULL)
			__x86_pc = tracee_sys_enter_submit_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7195ULL && __x86_pc <= 8877ULL)
			__x86_pc = tracee_sys_enter_submit_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8882ULL && __x86_pc <= 10586ULL)
			__x86_pc = tracee_sys_enter_submit_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10591ULL && __x86_pc <= 12294ULL)
			__x86_pc = tracee_sys_enter_submit_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12299ULL && __x86_pc <= 13734ULL)
			__x86_pc = tracee_sys_enter_submit_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

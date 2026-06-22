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

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_0(
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
	case 111ULL: goto x86_l_6f;
	case 116ULL: goto x86_l_74;
	case 121ULL: goto x86_l_79;
	case 126ULL: goto x86_l_7e;
	case 131ULL: goto x86_l_83;
	case 134ULL: goto x86_l_86;
	case 136ULL: goto x86_l_88;
	case 141ULL: goto x86_l_8d;
	case 143ULL: goto x86_l_8f;
	case 146ULL: goto x86_l_92;
	case 148ULL: goto x86_l_94;
	case 155ULL: goto x86_l_9b;
	case 158ULL: goto x86_l_9e;
	case 163ULL: goto x86_l_a3;
	case 165ULL: goto x86_l_a5;
	case 168ULL: goto x86_l_a8;
	case 170ULL: goto x86_l_aa;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 179ULL: goto x86_l_b3;
	case 187ULL: goto x86_l_bb;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 204ULL: goto x86_l_cc;
	case 206ULL: goto x86_l_ce;
	case 211ULL: goto x86_l_d3;
	case 214ULL: goto x86_l_d6;
	case 220ULL: goto x86_l_dc;
	case 227ULL: goto x86_l_e3;
	case 232ULL: goto x86_l_e8;
	case 237ULL: goto x86_l_ed;
	case 239ULL: goto x86_l_ef;
	case 242ULL: goto x86_l_f2;
	case 248ULL: goto x86_l_f8;
	case 256ULL: goto x86_l_100;
	case 261ULL: goto x86_l_105;
	case 271ULL: goto x86_l_10f;
	case 279ULL: goto x86_l_117;
	case 290ULL: goto x86_l_122;
	case 301ULL: goto x86_l_12d;
	case 312ULL: goto x86_l_138;
	case 323ULL: goto x86_l_143;
	case 334ULL: goto x86_l_14e;
	case 345ULL: goto x86_l_159;
	case 356ULL: goto x86_l_164;
	case 367ULL: goto x86_l_16f;
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
	case 478ULL: goto x86_l_1de;
	case 483ULL: goto x86_l_1e3;
	case 485ULL: goto x86_l_1e5;
	case 489ULL: goto x86_l_1e9;
	case 493ULL: goto x86_l_1ed;
	case 497ULL: goto x86_l_1f1;
	case 505ULL: goto x86_l_1f9;
	case 510ULL: goto x86_l_1fe;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 520ULL: goto x86_l_208;
	case 522ULL: goto x86_l_20a;
	case 527ULL: goto x86_l_20f;
	case 531ULL: goto x86_l_213;
	case 534ULL: goto x86_l_216;
	case 538ULL: goto x86_l_21a;
	case 542ULL: goto x86_l_21e;
	case 549ULL: goto x86_l_225;
	case 554ULL: goto x86_l_22a;
	case 559ULL: goto x86_l_22f;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 569ULL: goto x86_l_239;
	case 571ULL: goto x86_l_23b;
	case 574ULL: goto x86_l_23e;
	case 581ULL: goto x86_l_245;
	case 588ULL: goto x86_l_24c;
	case 596ULL: goto x86_l_254;
	case 601ULL: goto x86_l_259;
	case 603ULL: goto x86_l_25b;
	case 606ULL: goto x86_l_25e;
	case 609ULL: goto x86_l_261;
	case 617ULL: goto x86_l_269;
	case 625ULL: goto x86_l_271;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 642ULL: goto x86_l_282;
	case 647ULL: goto x86_l_287;
	case 649ULL: goto x86_l_289;
	case 654ULL: goto x86_l_28e;
	case 658ULL: goto x86_l_292;
	case 661ULL: goto x86_l_295;
	case 669ULL: goto x86_l_29d;
	case 676ULL: goto x86_l_2a4;
	case 681ULL: goto x86_l_2a9;
	case 686ULL: goto x86_l_2ae;
	case 688ULL: goto x86_l_2b0;
	case 691ULL: goto x86_l_2b3;
	case 697ULL: goto x86_l_2b9;
	case 700ULL: goto x86_l_2bc;
	case 703ULL: goto x86_l_2bf;
	case 707ULL: goto x86_l_2c3;
	case 718ULL: goto x86_l_2ce;
	case 729ULL: goto x86_l_2d9;
	case 740ULL: goto x86_l_2e4;
	case 751ULL: goto x86_l_2ef;
	case 762ULL: goto x86_l_2fa;
	case 773ULL: goto x86_l_305;
	case 784ULL: goto x86_l_310;
	case 795ULL: goto x86_l_31b;
	case 806ULL: goto x86_l_326;
	case 817ULL: goto x86_l_331;
	case 828ULL: goto x86_l_33c;
	case 839ULL: goto x86_l_347;
	case 850ULL: goto x86_l_352;
	case 861ULL: goto x86_l_35d;
	case 872ULL: goto x86_l_368;
	case 883ULL: goto x86_l_373;
	case 894ULL: goto x86_l_37e;
	case 905ULL: goto x86_l_389;
	case 916ULL: goto x86_l_394;
	case 927ULL: goto x86_l_39f;
	case 938ULL: goto x86_l_3aa;
	case 949ULL: goto x86_l_3b5;
	case 960ULL: goto x86_l_3c0;
	case 971ULL: goto x86_l_3cb;
	case 982ULL: goto x86_l_3d6;
	case 993ULL: goto x86_l_3e1;
	case 1004ULL: goto x86_l_3ec;
	case 1015ULL: goto x86_l_3f7;
	case 1026ULL: goto x86_l_402;
	case 1037ULL: goto x86_l_40d;
	case 1045ULL: goto x86_l_415;
	case 1053ULL: goto x86_l_41d;
	case 1061ULL: goto x86_l_425;
	case 1069ULL: goto x86_l_42d;
	case 1077ULL: goto x86_l_435;
	case 1085ULL: goto x86_l_43d;
	case 1093ULL: goto x86_l_445;
	case 1101ULL: goto x86_l_44d;
	case 1109ULL: goto x86_l_455;
	case 1117ULL: goto x86_l_45d;
	case 1125ULL: goto x86_l_465;
	case 1133ULL: goto x86_l_46d;
	case 1141ULL: goto x86_l_475;
	case 1149ULL: goto x86_l_47d;
	case 1157ULL: goto x86_l_485;
	case 1164ULL: goto x86_l_48c;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1189ULL: goto x86_l_4a5;
	case 1191ULL: goto x86_l_4a7;
	case 1194ULL: goto x86_l_4aa;
	case 1199ULL: goto x86_l_4af;
	case 1202ULL: goto x86_l_4b2;
	case 1204ULL: goto x86_l_4b4;
	case 1209ULL: goto x86_l_4b9;
	case 1212ULL: goto x86_l_4bc;
	case 1218ULL: goto x86_l_4c2;
	case 1223ULL: goto x86_l_4c7;
	case 1230ULL: goto x86_l_4ce;
	case 1233ULL: goto x86_l_4d1;
	case 1241ULL: goto x86_l_4d9;
	case 1248ULL: goto x86_l_4e0;
	case 1253ULL: goto x86_l_4e5;
	case 1258ULL: goto x86_l_4ea;
	case 1264ULL: goto x86_l_4f0;
	case 1266ULL: goto x86_l_4f2;
	case 1269ULL: goto x86_l_4f5;
	case 1275ULL: goto x86_l_4fb;
	case 1278ULL: goto x86_l_4fe;
	case 1281ULL: goto x86_l_501;
	case 1285ULL: goto x86_l_505;
	case 1296ULL: goto x86_l_510;
	case 1307ULL: goto x86_l_51b;
	case 1318ULL: goto x86_l_526;
	case 1329ULL: goto x86_l_531;
	case 1340ULL: goto x86_l_53c;
	case 1351ULL: goto x86_l_547;
	case 1362ULL: goto x86_l_552;
	case 1373ULL: goto x86_l_55d;
	case 1384ULL: goto x86_l_568;
	case 1392ULL: goto x86_l_570;
	case 1400ULL: goto x86_l_578;
	case 1408ULL: goto x86_l_580;
	case 1416ULL: goto x86_l_588;
	case 1424ULL: goto x86_l_590;
	case 1432ULL: goto x86_l_598;
	case 1440ULL: goto x86_l_5a0;
	case 1448ULL: goto x86_l_5a8;
	case 1456ULL: goto x86_l_5b0;
	case 1464ULL: goto x86_l_5b8;
	case 1472ULL: goto x86_l_5c0;
	case 1480ULL: goto x86_l_5c8;
	case 1488ULL: goto x86_l_5d0;
	case 1496ULL: goto x86_l_5d8;
	case 1504ULL: goto x86_l_5e0;
	case 1511ULL: goto x86_l_5e7;
	case 1518ULL: goto x86_l_5ee;
	case 1523ULL: goto x86_l_5f3;
	case 1528ULL: goto x86_l_5f8;
	case 1533ULL: goto x86_l_5fd;
	case 1536ULL: goto x86_l_600;
	case 1538ULL: goto x86_l_602;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1551ULL: goto x86_l_60f;
	case 1554ULL: goto x86_l_612;
	case 1560ULL: goto x86_l_618;
	case 1563ULL: goto x86_l_61b;
	case 1570ULL: goto x86_l_622;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1585ULL: goto x86_l_631;
	case 1590ULL: goto x86_l_636;
	case 1595ULL: goto x86_l_63b;
	case 1598ULL: goto x86_l_63e;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1610ULL: goto x86_l_64a;
	case 1614ULL: goto x86_l_64e;
	case 1619ULL: goto x86_l_653;
	case 1624ULL: goto x86_l_658;
	case 1629ULL: goto x86_l_65d;
	case 1634ULL: goto x86_l_662;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1645ULL: goto x86_l_66d;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1665ULL: goto x86_l_681;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1696ULL: goto x86_l_6a0;
	case 1698ULL: goto x86_l_6a2;
	case 1702ULL: goto x86_l_6a6;
	case 1706ULL: goto x86_l_6aa;
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
	case 1814ULL: goto x86_l_716;
	case 1819ULL: goto x86_l_71b;
	case 1824ULL: goto x86_l_720;
	case 1829ULL: goto x86_l_725;
	case 1834ULL: goto x86_l_72a;
	case 1837ULL: goto x86_l_72d;
	case 1839ULL: goto x86_l_72f;
	case 1844ULL: goto x86_l_734;
	case 1848ULL: goto x86_l_738;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1898ULL: goto x86_l_76a;
	case 1900ULL: goto x86_l_76c;
	case 1904ULL: goto x86_l_770;
	case 1908ULL: goto x86_l_774;
	case 1912ULL: goto x86_l_778;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1938ULL: goto x86_l_792;
	case 1942ULL: goto x86_l_796;
	case 1946ULL: goto x86_l_79a;
	case 1951ULL: goto x86_l_79f;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1966ULL: goto x86_l_7ae;
	case 1969ULL: goto x86_l_7b1;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1986ULL: goto x86_l_7c2;
	case 1991ULL: goto x86_l_7c7;
	case 1996ULL: goto x86_l_7cc;
	case 1999ULL: goto x86_l_7cf;
	case 2001ULL: goto x86_l_7d1;
	case 2005ULL: goto x86_l_7d5;
	case 2009ULL: goto x86_l_7d9;
	case 2013ULL: goto x86_l_7dd;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2037ULL: goto x86_l_7f5;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2048ULL: goto x86_l_800;
	case 2053ULL: goto x86_l_805;
	case 2058ULL: goto x86_l_80a;
	case 2063ULL: goto x86_l_80f;
	case 2068ULL: goto x86_l_814;
	case 2070ULL: goto x86_l_816;
	case 2074ULL: goto x86_l_81a;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2101ULL: goto x86_l_835;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
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
	/* 0xa: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
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
	/* 0x1b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
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
	/* 0x2c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x42: test   DWORD PTR [rsp+0x10],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68721573888ULL);
x86_l_4a:
	/* 0x4a: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_4f:
	/* 0x4f: jne    b3 <trace_call_usermodehelper+0xb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b3;
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
	/* 0x65: je     6c <trace_call_usermodehelper+0x6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c;
	}
x86_l_67:
	/* 0x67: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6a:
	/* 0x6a: jmp    6c <trace_call_usermodehelper+0x6c> */
	goto x86_l_6c;
x86_l_6c:
	/* 0x6c: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f:
	/* 0x6f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_74:
	/* 0x74: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_79:
	/* 0x79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e:
	/* 0x7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_83:
	/* 0x83: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_86:
	/* 0x86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88:
	/* 0x88: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_8d:
	/* 0x8d: jne    94 <trace_call_usermodehelper+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_94;
	}
x86_l_8f:
	/* 0x8f: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92:
	/* 0x92: jmp    b3 <trace_call_usermodehelper+0xb3> */
	goto x86_l_b3;
x86_l_94:
	/* 0x94: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_9b:
	/* 0x9b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_9e:
	/* 0x9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a3:
	/* 0xa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5:
	/* 0xa5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a8:
	/* 0xa8: je     ae <trace_call_usermodehelper+0xae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ae;
	}
x86_l_aa:
	/* 0xaa: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ac:
	/* 0xac: jmp    b3 <trace_call_usermodehelper+0xb3> */
	goto x86_l_b3;
x86_l_ae:
	/* 0xae: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_b3:
	/* 0xb3: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_bb:
	/* 0xbb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_c2:
	/* 0xc2: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_c7:
	/* 0xc7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cc:
	/* 0xcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce:
	/* 0xce: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d3:
	/* 0xd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d6:
	/* 0xd6: je     6045 <trace_call_usermodehelper+0x6045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24645ULL;
	}
x86_l_dc:
	/* 0xdc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_e3:
	/* 0xe3: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_e8:
	/* 0xe8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ed:
	/* 0xed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef:
	/* 0xef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f2:
	/* 0xf2: je     6045 <trace_call_usermodehelper+0x6045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24645ULL;
	}
x86_l_f8:
	/* 0xf8: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_100:
	/* 0x100: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_105:
	/* 0x105: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_10f:
	/* 0x10f: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_117:
	/* 0x117: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_122:
	/* 0x122: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_12d:
	/* 0x12d: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_138:
	/* 0x138: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_143:
	/* 0x143: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_14e:
	/* 0x14e: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_159:
	/* 0x159: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_164:
	/* 0x164: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_16f:
	/* 0x16f: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_176:
	/* 0x176: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_17e:
	/* 0x17e: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_186:
	/* 0x186: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_18e:
	/* 0x18e: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_196:
	/* 0x196: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_19e:
	/* 0x19e: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1a6:
	/* 0x1a6: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1ae:
	/* 0x1ae: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b6:
	/* 0x1b6: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1be:
	/* 0x1be: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1ce:
	/* 0x1ce: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1d6:
	/* 0x1d6: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1de:
	/* 0x1de: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1e3:
	/* 0x1e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5:
	/* 0x1e5: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e9:
	/* 0x1e9: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1ed:
	/* 0x1ed: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f1:
	/* 0x1f1: mov    DWORD PTR [r14+0x70],0x2f2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337906ULL);
x86_l_1f9:
	/* 0x1f9: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1fe:
	/* 0x1fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200:
	/* 0x200: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_203:
	/* 0x203: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_208:
	/* 0x208: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a:
	/* 0x20a: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_20f:
	/* 0x20f: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_213:
	/* 0x213: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_216:
	/* 0x216: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_21a:
	/* 0x21a: mov    DWORD PTR [rsp+0x64],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_21e:
	/* 0x21e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_225:
	/* 0x225: lea    rsi,[rsp+0x64] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_22a:
	/* 0x22a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22f:
	/* 0x22f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_231:
	/* 0x231: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_236:
	/* 0x236: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_239:
	/* 0x239: je     28e <trace_call_usermodehelper+0x28e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28e;
	}
x86_l_23b:
	/* 0x23b: mov    eax,DWORD PTR [rbp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23e:
	/* 0x23e: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_245:
	/* 0x245: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_24c:
	/* 0x24c: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_254:
	/* 0x254: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_259:
	/* 0x259: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b:
	/* 0x25b: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_25e:
	/* 0x25e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_261:
	/* 0x261: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_269:
	/* 0x269: mov    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_271:
	/* 0x271: je     4c7 <trace_call_usermodehelper+0x4c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c7;
	}
x86_l_277:
	/* 0x277: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_27c:
	/* 0x27c: jne    acd <trace_call_usermodehelper+0xacd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2765ULL;
	}
x86_l_282:
	/* 0x282: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_287:
	/* 0x287: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_289:
	/* 0x289: jmp    b73 <trace_call_usermodehelper+0xb73> */
	return 2931ULL;
x86_l_28e:
	/* 0x28e: mov    eax,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_292:
	/* 0x292: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295:
	/* 0x295: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_29d:
	/* 0x29d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_2a4:
	/* 0x2a4: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a9:
	/* 0x2a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ae:
	/* 0x2ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0:
	/* 0x2b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b3:
	/* 0x2b3: je     6045 <trace_call_usermodehelper+0x6045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24645ULL;
	}
x86_l_2b9:
	/* 0x2b9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2bc:
	/* 0x2bc: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf:
	/* 0x2bf: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c3:
	/* 0x2c3: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2ce:
	/* 0x2ce: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2d9:
	/* 0x2d9: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2e4:
	/* 0x2e4: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2ef:
	/* 0x2ef: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2fa:
	/* 0x2fa: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_305:
	/* 0x305: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_310:
	/* 0x310: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_31b:
	/* 0x31b: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_326:
	/* 0x326: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_331:
	/* 0x331: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_33c:
	/* 0x33c: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_347:
	/* 0x347: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_352:
	/* 0x352: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_35d:
	/* 0x35d: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_368:
	/* 0x368: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_373:
	/* 0x373: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_37e:
	/* 0x37e: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_389:
	/* 0x389: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_394:
	/* 0x394: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_39f:
	/* 0x39f: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_3aa:
	/* 0x3aa: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3b5:
	/* 0x3b5: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3c0:
	/* 0x3c0: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3cb:
	/* 0x3cb: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3d6:
	/* 0x3d6: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3e1:
	/* 0x3e1: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3ec:
	/* 0x3ec: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3f7:
	/* 0x3f7: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_402:
	/* 0x402: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_40d:
	/* 0x40d: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_415:
	/* 0x415: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_41d:
	/* 0x41d: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_425:
	/* 0x425: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_42d:
	/* 0x42d: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_435:
	/* 0x435: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_43d:
	/* 0x43d: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_445:
	/* 0x445: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_455:
	/* 0x455: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_45d:
	/* 0x45d: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_465:
	/* 0x465: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_46d:
	/* 0x46d: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_475:
	/* 0x475: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47d:
	/* 0x47d: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_485:
	/* 0x485: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48c:
	/* 0x48c: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_493:
	/* 0x493: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_498:
	/* 0x498: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_49d:
	/* 0x49d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4a2:
	/* 0x4a2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a5:
	/* 0x4a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a7:
	/* 0x4a7: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4aa:
	/* 0x4aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4af:
	/* 0x4af: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4b2:
	/* 0x4b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b4:
	/* 0x4b4: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4b9:
	/* 0x4b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4bc:
	/* 0x4bc: jne    23b <trace_call_usermodehelper+0x23b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23b;
	}
x86_l_4c2:
	/* 0x4c2: jmp    6045 <trace_call_usermodehelper+0x6045> */
	return 24645ULL;
x86_l_4c7:
	/* 0x4c7: mov    eax,DWORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_4ce:
	/* 0x4ce: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d1:
	/* 0x4d1: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_4d9:
	/* 0x4d9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4e0:
	/* 0x4e0: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4e5:
	/* 0x4e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ea:
	/* 0x4ea: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_4f0:
	/* 0x4f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f2:
	/* 0x4f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f5:
	/* 0x4f5: je     6045 <trace_call_usermodehelper+0x6045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24645ULL;
	}
x86_l_4fb:
	/* 0x4fb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4fe:
	/* 0x4fe: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_501:
	/* 0x501: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_505:
	/* 0x505: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_510:
	/* 0x510: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_51b:
	/* 0x51b: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_526:
	/* 0x526: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_531:
	/* 0x531: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_53c:
	/* 0x53c: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_547:
	/* 0x547: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_552:
	/* 0x552: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_55d:
	/* 0x55d: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_568:
	/* 0x568: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_570:
	/* 0x570: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_578:
	/* 0x578: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_580:
	/* 0x580: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_588:
	/* 0x588: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_590:
	/* 0x590: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_598:
	/* 0x598: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5a0:
	/* 0x5a0: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5a8:
	/* 0x5a8: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5b0:
	/* 0x5b0: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5b8:
	/* 0x5b8: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5c0:
	/* 0x5c0: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5d0:
	/* 0x5d0: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5d8:
	/* 0x5d8: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5e0:
	/* 0x5e0: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e7:
	/* 0x5e7: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5ee:
	/* 0x5ee: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f3:
	/* 0x5f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5f8:
	/* 0x5f8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5fd:
	/* 0x5fd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_600:
	/* 0x600: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_602:
	/* 0x602: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_605:
	/* 0x605: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60a:
	/* 0x60a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60f:
	/* 0x60f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_612:
	/* 0x612: je     6045 <trace_call_usermodehelper+0x6045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24645ULL;
	}
x86_l_618:
	/* 0x618: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_61b:
	/* 0x61b: mov    r12,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_622:
	/* 0x622: lea    r15,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_627:
	/* 0x627: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62c:
	/* 0x62c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_631:
	/* 0x631: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_636:
	/* 0x636: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63b:
	/* 0x63b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_63e:
	/* 0x63e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_640:
	/* 0x640: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_645:
	/* 0x645: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_64a:
	/* 0x64a: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64e:
	/* 0x64e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_653:
	/* 0x653: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_658:
	/* 0x658: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65d:
	/* 0x65d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_662:
	/* 0x662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_664:
	/* 0x664: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_669:
	/* 0x669: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_66d:
	/* 0x66d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_672:
	/* 0x672: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_677:
	/* 0x677: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67c:
	/* 0x67c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_681:
	/* 0x681: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_683:
	/* 0x683: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_688:
	/* 0x688: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_68c:
	/* 0x68c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_691:
	/* 0x691: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_696:
	/* 0x696: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_69b:
	/* 0x69b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6a0:
	/* 0x6a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a2:
	/* 0x6a2: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a6:
	/* 0x6a6: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6aa:
	/* 0x6aa: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_6ad:
	/* 0x6ad: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6b1:
	/* 0x6b1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x6ca: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6cf:
	/* 0x6cf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x6e8: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x6f8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x70e: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_712:
	/* 0x712: mov    DWORD PTR [r14+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_716:
	/* 0x716: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71b:
	/* 0x71b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_720:
	/* 0x720: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_725:
	/* 0x725: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_72a:
	/* 0x72a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_72d:
	/* 0x72d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72f:
	/* 0x72f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_734:
	/* 0x734: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_738:
	/* 0x738: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_73d:
	/* 0x73d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_742:
	/* 0x742: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_747:
	/* 0x747: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_74c:
	/* 0x74c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74e:
	/* 0x74e: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_753:
	/* 0x753: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_758:
	/* 0x758: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_75d:
	/* 0x75d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_762:
	/* 0x762: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_767:
	/* 0x767: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_76a:
	/* 0x76a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76c:
	/* 0x76c: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_770:
	/* 0x770: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_774:
	/* 0x774: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_778:
	/* 0x778: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_77c:
	/* 0x77c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_781:
	/* 0x781: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_786:
	/* 0x786: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_78b:
	/* 0x78b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_790:
	/* 0x790: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_792:
	/* 0x792: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_796:
	/* 0x796: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_79a:
	/* 0x79a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_79f:
	/* 0x79f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7a4:
	/* 0x7a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7a9:
	/* 0x7a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ae:
	/* 0x7ae: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7b1:
	/* 0x7b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b3:
	/* 0x7b3: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b8:
	/* 0x7b8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7bd:
	/* 0x7bd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7c2:
	/* 0x7c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7c7:
	/* 0x7c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7cc:
	/* 0x7cc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7cf:
	/* 0x7cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d1:
	/* 0x7d1: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7d5:
	/* 0x7d5: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7d9:
	/* 0x7d9: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7dd:
	/* 0x7dd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7e1:
	/* 0x7e1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e6:
	/* 0x7e6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7eb:
	/* 0x7eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f0:
	/* 0x7f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f5:
	/* 0x7f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f7:
	/* 0x7f7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7fc:
	/* 0x7fc: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_800:
	/* 0x800: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_805:
	/* 0x805: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_80a:
	/* 0x80a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_80f:
	/* 0x80f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_814:
	/* 0x814: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_816:
	/* 0x816: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_81a:
	/* 0x81a: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_81e:
	/* 0x81e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_823:
	/* 0x823: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_828:
	/* 0x828: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_82d:
	/* 0x82d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_832:
	/* 0x832: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_835:
	/* 0x835: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_837:
	/* 0x837: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83c:
	/* 0x83c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_841:
	/* 0x841: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_846:
	/* 0x846: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 2123ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2133ULL: goto x86_l_855;
	case 2137ULL: goto x86_l_859;
	case 2141ULL: goto x86_l_85d;
	case 2145ULL: goto x86_l_861;
	case 2149ULL: goto x86_l_865;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2162ULL: goto x86_l_872;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2174ULL: goto x86_l_87e;
	case 2179ULL: goto x86_l_883;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2205ULL: goto x86_l_89d;
	case 2209ULL: goto x86_l_8a1;
	case 2217ULL: goto x86_l_8a9;
	case 2219ULL: goto x86_l_8ab;
	case 2224ULL: goto x86_l_8b0;
	case 2229ULL: goto x86_l_8b5;
	case 2234ULL: goto x86_l_8ba;
	case 2239ULL: goto x86_l_8bf;
	case 2242ULL: goto x86_l_8c2;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2259ULL: goto x86_l_8d3;
	case 2264ULL: goto x86_l_8d8;
	case 2269ULL: goto x86_l_8dd;
	case 2272ULL: goto x86_l_8e0;
	case 2274ULL: goto x86_l_8e2;
	case 2278ULL: goto x86_l_8e6;
	case 2282ULL: goto x86_l_8ea;
	case 2286ULL: goto x86_l_8ee;
	case 2290ULL: goto x86_l_8f2;
	case 2295ULL: goto x86_l_8f7;
	case 2300ULL: goto x86_l_8fc;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2312ULL: goto x86_l_908;
	case 2316ULL: goto x86_l_90c;
	case 2321ULL: goto x86_l_911;
	case 2326ULL: goto x86_l_916;
	case 2333ULL: goto x86_l_91d;
	case 2338ULL: goto x86_l_922;
	case 2343ULL: goto x86_l_927;
	case 2348ULL: goto x86_l_92c;
	case 2353ULL: goto x86_l_931;
	case 2356ULL: goto x86_l_934;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2367ULL: goto x86_l_93f;
	case 2372ULL: goto x86_l_944;
	case 2377ULL: goto x86_l_949;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2389ULL: goto x86_l_955;
	case 2394ULL: goto x86_l_95a;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2419ULL: goto x86_l_973;
	case 2422ULL: goto x86_l_976;
	case 2427ULL: goto x86_l_97b;
	case 2432ULL: goto x86_l_980;
	case 2434ULL: goto x86_l_982;
	case 2439ULL: goto x86_l_987;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2463ULL: goto x86_l_99f;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2483ULL: goto x86_l_9b3;
	case 2488ULL: goto x86_l_9b8;
	case 2493ULL: goto x86_l_9bd;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2515ULL: goto x86_l_9d3;
	case 2519ULL: goto x86_l_9d7;
	case 2524ULL: goto x86_l_9dc;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2539ULL: goto x86_l_9eb;
	case 2542ULL: goto x86_l_9ee;
	case 2544ULL: goto x86_l_9f0;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2564ULL: goto x86_l_a04;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2577ULL: goto x86_l_a11;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2586ULL: goto x86_l_a1a;
	case 2592ULL: goto x86_l_a20;
	case 2601ULL: goto x86_l_a29;
	case 2606ULL: goto x86_l_a2e;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2630ULL: goto x86_l_a46;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2655ULL: goto x86_l_a5f;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2667ULL: goto x86_l_a6b;
	case 2672ULL: goto x86_l_a70;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2684ULL: goto x86_l_a7c;
	case 2689ULL: goto x86_l_a81;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2704ULL: goto x86_l_a90;
	case 2707ULL: goto x86_l_a93;
	case 2712ULL: goto x86_l_a98;
	case 2714ULL: goto x86_l_a9a;
	case 2717ULL: goto x86_l_a9d;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2736ULL: goto x86_l_ab0;
	case 2739ULL: goto x86_l_ab3;
	case 2741ULL: goto x86_l_ab5;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2759ULL: goto x86_l_ac7;
	case 2765ULL: goto x86_l_acd;
	case 2770ULL: goto x86_l_ad2;
	case 2777ULL: goto x86_l_ad9;
	case 2780ULL: goto x86_l_adc;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2797ULL: goto x86_l_aed;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2820ULL: goto x86_l_b04;
	case 2825ULL: goto x86_l_b09;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2857ULL: goto x86_l_b29;
	case 2859ULL: goto x86_l_b2b;
	case 2864ULL: goto x86_l_b30;
	case 2869ULL: goto x86_l_b35;
	case 2874ULL: goto x86_l_b3a;
	case 2879ULL: goto x86_l_b3f;
	case 2884ULL: goto x86_l_b44;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2894ULL: goto x86_l_b4e;
	case 2896ULL: goto x86_l_b50;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2929ULL: goto x86_l_b71;
	case 2931ULL: goto x86_l_b73;
	case 2935ULL: goto x86_l_b77;
	case 2940ULL: goto x86_l_b7c;
	case 2943ULL: goto x86_l_b7f;
	case 2950ULL: goto x86_l_b86;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2960ULL: goto x86_l_b90;
	case 2963ULL: goto x86_l_b93;
	case 2965ULL: goto x86_l_b95;
	case 2968ULL: goto x86_l_b98;
	case 2976ULL: goto x86_l_ba0;
	case 2979ULL: goto x86_l_ba3;
	case 2982ULL: goto x86_l_ba6;
	case 2984ULL: goto x86_l_ba8;
	case 2988ULL: goto x86_l_bac;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 3003ULL: goto x86_l_bbb;
	case 3014ULL: goto x86_l_bc6;
	case 3022ULL: goto x86_l_bce;
	case 3027ULL: goto x86_l_bd3;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3046ULL: goto x86_l_be6;
	case 3049ULL: goto x86_l_be9;
	case 3051ULL: goto x86_l_beb;
	case 3054ULL: goto x86_l_bee;
	case 3059ULL: goto x86_l_bf3;
	case 3064ULL: goto x86_l_bf8;
	case 3066ULL: goto x86_l_bfa;
	case 3069ULL: goto x86_l_bfd;
	case 3071ULL: goto x86_l_bff;
	case 3075ULL: goto x86_l_c03;
	case 3082ULL: goto x86_l_c0a;
	case 3085ULL: goto x86_l_c0d;
	case 3092ULL: goto x86_l_c14;
	case 3096ULL: goto x86_l_c18;
	case 3100ULL: goto x86_l_c1c;
	case 3107ULL: goto x86_l_c23;
	case 3114ULL: goto x86_l_c2a;
	case 3118ULL: goto x86_l_c2e;
	case 3125ULL: goto x86_l_c35;
	case 3129ULL: goto x86_l_c39;
	case 3136ULL: goto x86_l_c40;
	case 3140ULL: goto x86_l_c44;
	case 3147ULL: goto x86_l_c4b;
	case 3151ULL: goto x86_l_c4f;
	case 3158ULL: goto x86_l_c56;
	case 3165ULL: goto x86_l_c5d;
	case 3172ULL: goto x86_l_c64;
	case 3175ULL: goto x86_l_c67;
	case 3178ULL: goto x86_l_c6a;
	case 3186ULL: goto x86_l_c72;
	case 3188ULL: goto x86_l_c74;
	case 3191ULL: goto x86_l_c77;
	case 3193ULL: goto x86_l_c79;
	case 3196ULL: goto x86_l_c7c;
	case 3203ULL: goto x86_l_c83;
	case 3209ULL: goto x86_l_c89;
	case 3214ULL: goto x86_l_c8e;
	case 3221ULL: goto x86_l_c95;
	case 3224ULL: goto x86_l_c98;
	case 3230ULL: goto x86_l_c9e;
	case 3239ULL: goto x86_l_ca7;
	case 3242ULL: goto x86_l_caa;
	case 3245ULL: goto x86_l_cad;
	case 3248ULL: goto x86_l_cb0;
	case 3252ULL: goto x86_l_cb4;
	case 3255ULL: goto x86_l_cb7;
	case 3258ULL: goto x86_l_cba;
	case 3265ULL: goto x86_l_cc1;
	case 3268ULL: goto x86_l_cc4;
	case 3275ULL: goto x86_l_ccb;
	case 3278ULL: goto x86_l_cce;
	case 3280ULL: goto x86_l_cd0;
	case 3282ULL: goto x86_l_cd2;
	case 3291ULL: goto x86_l_cdb;
	case 3294ULL: goto x86_l_cde;
	case 3297ULL: goto x86_l_ce1;
	case 3300ULL: goto x86_l_ce4;
	case 3307ULL: goto x86_l_ceb;
	case 3310ULL: goto x86_l_cee;
	case 3313ULL: goto x86_l_cf1;
	case 3320ULL: goto x86_l_cf8;
	case 3323ULL: goto x86_l_cfb;
	case 3325ULL: goto x86_l_cfd;
	case 3328ULL: goto x86_l_d00;
	case 3331ULL: goto x86_l_d03;
	case 3334ULL: goto x86_l_d06;
	case 3337ULL: goto x86_l_d09;
	case 3344ULL: goto x86_l_d10;
	case 3347ULL: goto x86_l_d13;
	case 3350ULL: goto x86_l_d16;
	case 3357ULL: goto x86_l_d1d;
	case 3360ULL: goto x86_l_d20;
	case 3362ULL: goto x86_l_d22;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3384ULL: goto x86_l_d38;
	case 3387ULL: goto x86_l_d3b;
	case 3390ULL: goto x86_l_d3e;
	case 3394ULL: goto x86_l_d42;
	case 3401ULL: goto x86_l_d49;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3415ULL: goto x86_l_d57;
	case 3422ULL: goto x86_l_d5e;
	case 3430ULL: goto x86_l_d66;
	case 3437ULL: goto x86_l_d6d;
	case 3444ULL: goto x86_l_d74;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3461ULL: goto x86_l_d85;
	case 3466ULL: goto x86_l_d8a;
	case 3471ULL: goto x86_l_d8f;
	case 3473ULL: goto x86_l_d91;
	case 3476ULL: goto x86_l_d94;
	case 3479ULL: goto x86_l_d97;
	case 3484ULL: goto x86_l_d9c;
	case 3491ULL: goto x86_l_da3;
	case 3494ULL: goto x86_l_da6;
	case 3496ULL: goto x86_l_da8;
	case 3501ULL: goto x86_l_dad;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3511ULL: goto x86_l_db7;
	case 3514ULL: goto x86_l_dba;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3523ULL: goto x86_l_dc3;
	case 3526ULL: goto x86_l_dc6;
	case 3528ULL: goto x86_l_dc8;
	case 3531ULL: goto x86_l_dcb;
	case 3536ULL: goto x86_l_dd0;
	case 3541ULL: goto x86_l_dd5;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3549ULL: goto x86_l_ddd;
	case 3553ULL: goto x86_l_de1;
	case 3555ULL: goto x86_l_de3;
	case 3558ULL: goto x86_l_de6;
	case 3560ULL: goto x86_l_de8;
	case 3568ULL: goto x86_l_df0;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3579ULL: goto x86_l_dfb;
	case 3584ULL: goto x86_l_e00;
	case 3591ULL: goto x86_l_e07;
	case 3594ULL: goto x86_l_e0a;
	case 3596ULL: goto x86_l_e0c;
	case 3601ULL: goto x86_l_e11;
	case 3606ULL: goto x86_l_e16;
	case 3609ULL: goto x86_l_e19;
	case 3611ULL: goto x86_l_e1b;
	case 3614ULL: goto x86_l_e1e;
	case 3616ULL: goto x86_l_e20;
	case 3619ULL: goto x86_l_e23;
	case 3623ULL: goto x86_l_e27;
	case 3626ULL: goto x86_l_e2a;
	case 3628ULL: goto x86_l_e2c;
	case 3635ULL: goto x86_l_e33;
	case 3642ULL: goto x86_l_e3a;
	case 3645ULL: goto x86_l_e3d;
	case 3651ULL: goto x86_l_e43;
	case 3656ULL: goto x86_l_e48;
	case 3658ULL: goto x86_l_e4a;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3669ULL: goto x86_l_e55;
	case 3671ULL: goto x86_l_e57;
	case 3673ULL: goto x86_l_e59;
	case 3675ULL: goto x86_l_e5b;
	case 3680ULL: goto x86_l_e60;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3691ULL: goto x86_l_e6b;
	case 3693ULL: goto x86_l_e6d;
	case 3697ULL: goto x86_l_e71;
	case 3699ULL: goto x86_l_e73;
	case 3702ULL: goto x86_l_e76;
	case 3704ULL: goto x86_l_e78;
	case 3712ULL: goto x86_l_e80;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3724ULL: goto x86_l_e8c;
	case 3729ULL: goto x86_l_e91;
	case 3737ULL: goto x86_l_e99;
	case 3743ULL: goto x86_l_e9f;
	case 3748ULL: goto x86_l_ea4;
	case 3750ULL: goto x86_l_ea6;
	case 3753ULL: goto x86_l_ea9;
	case 3760ULL: goto x86_l_eb0;
	case 3767ULL: goto x86_l_eb7;
	case 3774ULL: goto x86_l_ebe;
	default: return 0xffffffffffffffffULL;
	}
x86_l_84b:
	/* 0x84b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_850:
	/* 0x850: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_853:
	/* 0x853: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_855:
	/* 0x855: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_859:
	/* 0x859: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_85d:
	/* 0x85d: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_861:
	/* 0x861: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_865:
	/* 0x865: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_868:
	/* 0x868: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_86d:
	/* 0x86d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_872:
	/* 0x872: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_877:
	/* 0x877: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_87c:
	/* 0x87c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87e:
	/* 0x87e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_883:
	/* 0x883: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_887:
	/* 0x887: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_88c:
	/* 0x88c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_891:
	/* 0x891: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_896:
	/* 0x896: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_89b:
	/* 0x89b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89d:
	/* 0x89d: cmp    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_8a1:
	/* 0x8a1: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8a9:
	/* 0x8a9: jne    911 <trace_call_usermodehelper+0x911> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_911;
	}
x86_l_8ab:
	/* 0x8ab: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8b0:
	/* 0x8b0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8b5:
	/* 0x8b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8ba:
	/* 0x8ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8bf:
	/* 0x8bf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8c2:
	/* 0x8c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c4:
	/* 0x8c4: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c9:
	/* 0x8c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ce:
	/* 0x8ce: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8d3:
	/* 0x8d3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8d8:
	/* 0x8d8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8dd:
	/* 0x8dd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8e0:
	/* 0x8e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e2:
	/* 0x8e2: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8e6:
	/* 0x8e6: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8ea:
	/* 0x8ea: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8ee:
	/* 0x8ee: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8f2:
	/* 0x8f2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f7:
	/* 0x8f7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8fc:
	/* 0x8fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_901:
	/* 0x901: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_906:
	/* 0x906: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_908:
	/* 0x908: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_90c:
	/* 0x90c: mov    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_911:
	/* 0x911: mov    DWORD PTR [r12+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_916:
	/* 0x916: lea    r15,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_91d:
	/* 0x91d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_922:
	/* 0x922: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_927:
	/* 0x927: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_92c:
	/* 0x92c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_931:
	/* 0x931: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_934:
	/* 0x934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_936:
	/* 0x936: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_93b:
	/* 0x93b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_93f:
	/* 0x93f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_944:
	/* 0x944: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_949:
	/* 0x949: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_94e:
	/* 0x94e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_953:
	/* 0x953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_955:
	/* 0x955: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_95a:
	/* 0x95a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_95d:
	/* 0x95d: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_962:
	/* 0x962: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_967:
	/* 0x967: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96c:
	/* 0x96c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_971:
	/* 0x971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_973:
	/* 0x973: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_976:
	/* 0x976: mov    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_97b:
	/* 0x97b: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_980:
	/* 0x980: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_982:
	/* 0x982: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_987:
	/* 0x987: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_98b:
	/* 0x98b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_990:
	/* 0x990: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_995:
	/* 0x995: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_99a:
	/* 0x99a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_99f:
	/* 0x99f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a1:
	/* 0x9a1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9a6:
	/* 0x9a6: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9aa:
	/* 0x9aa: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9af:
	/* 0x9af: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9b3:
	/* 0x9b3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9b8:
	/* 0x9b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9bd:
	/* 0x9bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9c2:
	/* 0x9c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9c7:
	/* 0x9c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c9:
	/* 0x9c9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ce:
	/* 0x9ce: mov    QWORD PTR [r12+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9d3:
	/* 0x9d3: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9d7:
	/* 0x9d7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9dc:
	/* 0x9dc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9e1:
	/* 0x9e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9e6:
	/* 0x9e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9eb:
	/* 0x9eb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_9ee:
	/* 0x9ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f0:
	/* 0x9f0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9f5:
	/* 0x9f5: mov    QWORD PTR [r12+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9fa:
	/* 0x9fa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ff:
	/* 0x9ff: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a04:
	/* 0xa04: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a09:
	/* 0xa09: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a0e:
	/* 0xa0e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a11:
	/* 0xa11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a13:
	/* 0xa13: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_a18:
	/* 0xa18: je     a20 <trace_call_usermodehelper+0xa20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a20;
	}
x86_l_a1a:
	/* 0xa1a: or     BYTE PTR [r12+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_a20:
	/* 0xa20: mov    QWORD PTR [r12+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_a29:
	/* 0xa29: lea    rdi,[r12+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a2e:
	/* 0xa2e: mov    QWORD PTR [r12+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_a37:
	/* 0xa37: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a3c:
	/* 0xa3c: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_a41:
	/* 0xa41: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a46:
	/* 0xa46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a48:
	/* 0xa48: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a4d:
	/* 0xa4d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a52:
	/* 0xa52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a57:
	/* 0xa57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a5c:
	/* 0xa5c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_a5f:
	/* 0xa5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a61:
	/* 0xa61: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a66:
	/* 0xa66: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a6b:
	/* 0xa6b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a70:
	/* 0xa70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a75:
	/* 0xa75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a7a:
	/* 0xa7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7c:
	/* 0xa7c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a81:
	/* 0xa81: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a86:
	/* 0xa86: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_a8b:
	/* 0xa8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a90:
	/* 0xa90: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a93:
	/* 0xa93: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_a98:
	/* 0xa98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9a:
	/* 0xa9a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_a9d:
	/* 0xa9d: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_aa1:
	/* 0xaa1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_aa6:
	/* 0xaa6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_aab:
	/* 0xaab: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ab0:
	/* 0xab0: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_ab3:
	/* 0xab3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab5:
	/* 0xab5: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_abd:
	/* 0xabd: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac2:
	/* 0xac2: test   BYTE PTR [r14+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_ac7:
	/* 0xac7: je     282 <trace_call_usermodehelper+0x282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 642ULL;
	}
x86_l_acd:
	/* 0xacd: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_ad2:
	/* 0xad2: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_ad9:
	/* 0xad9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_adc:
	/* 0xadc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ae1:
	/* 0xae1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ae6:
	/* 0xae6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aeb:
	/* 0xaeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aed:
	/* 0xaed: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af1:
	/* 0xaf1: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_af6:
	/* 0xaf6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_afb:
	/* 0xafb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b00:
	/* 0xb00: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b04:
	/* 0xb04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b09:
	/* 0xb09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0b:
	/* 0xb0b: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b10:
	/* 0xb10: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b15:
	/* 0xb15: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b1a:
	/* 0xb1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b1f:
	/* 0xb1f: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b24:
	/* 0xb24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b29:
	/* 0xb29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2b:
	/* 0xb2b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b30:
	/* 0xb30: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b35:
	/* 0xb35: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b3a:
	/* 0xb3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b3f:
	/* 0xb3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b44:
	/* 0xb44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b46:
	/* 0xb46: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b4b:
	/* 0xb4b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_b4e:
	/* 0xb4e: je     b71 <trace_call_usermodehelper+0xb71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b71;
	}
x86_l_b50:
	/* 0xb50: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b54:
	/* 0xb54: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b59:
	/* 0xb59: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b5e:
	/* 0xb5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b63:
	/* 0xb63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b68:
	/* 0xb68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6a:
	/* 0xb6a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b6f:
	/* 0xb6f: jmp    b73 <trace_call_usermodehelper+0xb73> */
	goto x86_l_b73;
x86_l_b71:
	/* 0xb71: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b73:
	/* 0xb73: mov    QWORD PTR [rbp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b77:
	/* 0xb77: mov    QWORD PTR [r12+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b7c:
	/* 0xb7c: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7f:
	/* 0xb7f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_b86:
	/* 0xb86: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_b89:
	/* 0xb89: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b8e:
	/* 0xb8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b90:
	/* 0xb90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b93:
	/* 0xb93: je     bac <trace_call_usermodehelper+0xbac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bac;
	}
x86_l_b95:
	/* 0xb95: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b98:
	/* 0xb98: mov    BYTE PTR [r12+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_ba0:
	/* 0xba0: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_ba3:
	/* 0xba3: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_ba6:
	/* 0xba6: jne    bac <trace_call_usermodehelper+0xbac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bac;
	}
x86_l_ba8:
	/* 0xba8: or     BYTE PTR [rbp+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_bac:
	/* 0xbac: movzx  eax,WORD PTR [rbp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_bb0:
	/* 0xbb0: cmp    ax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_bb5:
	/* 0xbb5: jne    6013 <trace_call_usermodehelper+0x6013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24595ULL;
	}
x86_l_bbb:
	/* 0xbbb: mov    QWORD PTR [rbp+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_bc6:
	/* 0xbc6: mov    DWORD PTR [rsp+0x10],0x2f2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719477490ULL);
x86_l_bce:
	/* 0xbce: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bd3:
	/* 0xbd3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_bda:
	/* 0xbda: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bdf:
	/* 0xbdf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_be4:
	/* 0xbe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be6:
	/* 0xbe6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_be9:
	/* 0xbe9: je     c56 <trace_call_usermodehelper+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_beb:
	/* 0xbeb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_bee:
	/* 0xbee: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf3:
	/* 0xbf3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bf8:
	/* 0xbf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfa:
	/* 0xbfa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bfd:
	/* 0xbfd: je     c56 <trace_call_usermodehelper+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_bff:
	/* 0xbff: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c03:
	/* 0xc03: mov    QWORD PTR [rbp+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_c0a:
	/* 0xc0a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0d:
	/* 0xc0d: mov    QWORD PTR [rbp+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c14:
	/* 0xc14: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c18:
	/* 0xc18: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c1c:
	/* 0xc1c: mov    QWORD PTR [rbp+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_c23:
	/* 0xc23: mov    QWORD PTR [rbp+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_c2a:
	/* 0xc2a: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c2e:
	/* 0xc2e: mov    QWORD PTR [rbp+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_c35:
	/* 0xc35: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c39:
	/* 0xc39: mov    QWORD PTR [rbp+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_c40:
	/* 0xc40: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c44:
	/* 0xc44: mov    QWORD PTR [rbp+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_c4b:
	/* 0xc4b: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c4f:
	/* 0xc4f: mov    QWORD PTR [rbp+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_c56:
	/* 0xc56: mov    rdx,QWORD PTR [rbp+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c5d:
	/* 0xc5d: mov    QWORD PTR [rbp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c64:
	/* 0xc64: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c67:
	/* 0xc67: cmp    ecx,DWORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_c6a:
	/* 0xc6a: mov    QWORD PTR [rsp+0xa0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_c72:
	/* 0xc72: jne    c8e <trace_call_usermodehelper+0xc8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c8e;
	}
x86_l_c74:
	/* 0xc74: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c77:
	/* 0xc77: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c79:
	/* 0xc79: and    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_c7c:
	/* 0xc7c: mov    QWORD PTR [rbp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c83:
	/* 0xc83: jne    1454 <trace_call_usermodehelper+0x1454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5204ULL;
	}
x86_l_c89:
	/* 0xc89: jmp    1c09 <trace_call_usermodehelper+0x1c09> */
	return 7177ULL;
x86_l_c8e:
	/* 0xc8e: mov    rax,QWORD PTR [rbp+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_c95:
	/* 0xc95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c98:
	/* 0xc98: je     e2c <trace_call_usermodehelper+0xe2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e2c;
	}
x86_l_c9e:
	/* 0xc9e: movzx  ecx,BYTE PTR [r12+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_ca7:
	/* 0xca7: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_caa:
	/* 0xcaa: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cad:
	/* 0xcad: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_cb0:
	/* 0xcb0: sete   r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_E);
x86_l_cb4:
	/* 0xcb4: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_cb7:
	/* 0xcb7: neg    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_cba:
	/* 0xcba: xor    r14,QWORD PTR [rbp+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_cc1:
	/* 0xcc1: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_cc4:
	/* 0xcc4: mov    rax,QWORD PTR [rbp+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_ccb:
	/* 0xccb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cce:
	/* 0xcce: je     cf1 <trace_call_usermodehelper+0xcf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf1;
	}
x86_l_cd0:
	/* 0xcd0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd2:
	/* 0xcd2: cmp    BYTE PTR [r12+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_cdb:
	/* 0xcdb: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_cde:
	/* 0xcde: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ce1:
	/* 0xce1: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_ce4:
	/* 0xce4: xor    rcx,QWORD PTR [rbp+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_ceb:
	/* 0xceb: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_cee:
	/* 0xcee: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_cf1:
	/* 0xcf1: mov    rax,QWORD PTR [rbp+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_cf8:
	/* 0xcf8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cfb:
	/* 0xcfb: je     d16 <trace_call_usermodehelper+0xd16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d16;
	}
x86_l_cfd:
	/* 0xcfd: mov    ecx,DWORD PTR [rbp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_d00:
	/* 0xd00: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d03:
	/* 0xd03: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_d06:
	/* 0xd06: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d09:
	/* 0xd09: xor    rcx,QWORD PTR [rbp+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_d10:
	/* 0xd10: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d13:
	/* 0xd13: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d16:
	/* 0xd16: mov    rax,QWORD PTR [rbp+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_d1d:
	/* 0xd1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d20:
	/* 0xd20: je     d3e <trace_call_usermodehelper+0xd3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d3e;
	}
x86_l_d22:
	/* 0xd22: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d25:
	/* 0xd25: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d2a:
	/* 0xd2a: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d2e:
	/* 0xd2e: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d31:
	/* 0xd31: xor    rcx,QWORD PTR [rbp+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_d38:
	/* 0xd38: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d3b:
	/* 0xd3b: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d3e:
	/* 0xd3e: movzx  eax,WORD PTR [rbp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_d42:
	/* 0xd42: mov    r15,QWORD PTR [rbp+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_d49:
	/* 0xd49: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_d4c:
	/* 0xd4c: mov    WORD PTR [rsp+0x68],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d51:
	/* 0xd51: je     e91 <trace_call_usermodehelper+0xe91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e91;
	}
x86_l_d57:
	/* 0xd57: mov    rcx,QWORD PTR [rbp+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_d5e:
	/* 0xd5e: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d66:
	/* 0xd66: mov    r13,QWORD PTR [rbp+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_d6d:
	/* 0xd6d: mov    rcx,QWORD PTR [rbp+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_d74:
	/* 0xd74: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d79:
	/* 0xd79: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d7e:
	/* 0xd7e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_d85:
	/* 0xd85: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d8a:
	/* 0xd8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d8f:
	/* 0xd8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d91:
	/* 0xd91: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_d94:
	/* 0xd94: mov    eax,DWORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d97:
	/* 0xd97: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d9c:
	/* 0xd9c: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_da3:
	/* 0xda3: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_da6:
	/* 0xda6: je     dc8 <trace_call_usermodehelper+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc8;
	}
x86_l_da8:
	/* 0xda8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dad:
	/* 0xdad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_db2:
	/* 0xdb2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_db5:
	/* 0xdb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db7:
	/* 0xdb7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dba:
	/* 0xdba: je     dc8 <trace_call_usermodehelper+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc8;
	}
x86_l_dbc:
	/* 0xdbc: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dbf:
	/* 0xdbf: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc3:
	/* 0xdc3: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dc6:
	/* 0xdc6: jmp    dcb <trace_call_usermodehelper+0xdcb> */
	goto x86_l_dcb;
x86_l_dc8:
	/* 0xdc8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dcb:
	/* 0xdcb: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_dd0:
	/* 0xdd0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd5:
	/* 0xdd5: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_dd8:
	/* 0xdd8: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_ddb:
	/* 0xddb: jb     df3 <trace_call_usermodehelper+0xdf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_df3;
	}
x86_l_ddd:
	/* 0xddd: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_de1:
	/* 0xde1: je     de8 <trace_call_usermodehelper+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de8;
	}
x86_l_de3:
	/* 0xde3: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_de6:
	/* 0xde6: jbe    df3 <trace_call_usermodehelper+0xdf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_df3;
	}
x86_l_de8:
	/* 0xde8: and    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_df0:
	/* 0xdf0: or     r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_df3:
	/* 0xdf3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df8:
	/* 0xdf8: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dfb:
	/* 0xdfb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e00:
	/* 0xe00: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e07:
	/* 0xe07: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_e0a:
	/* 0xe0a: je     e48 <trace_call_usermodehelper+0xe48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e48;
	}
x86_l_e0c:
	/* 0xe0c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e11:
	/* 0xe11: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e16:
	/* 0xe16: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e19:
	/* 0xe19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e1b:
	/* 0xe1b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e1e:
	/* 0xe1e: je     e59 <trace_call_usermodehelper+0xe59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e59;
	}
x86_l_e20:
	/* 0xe20: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e23:
	/* 0xe23: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e27:
	/* 0xe27: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e2a:
	/* 0xe2a: jmp    e5b <trace_call_usermodehelper+0xe5b> */
	goto x86_l_e5b;
x86_l_e2c:
	/* 0xe2c: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e33:
	/* 0xe33: mov    rax,QWORD PTR [rbp+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_e3a:
	/* 0xe3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e3d:
	/* 0xe3d: jne    cd0 <trace_call_usermodehelper+0xcd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cd0;
	}
x86_l_e43:
	/* 0xe43: jmp    cf1 <trace_call_usermodehelper+0xcf1> */
	goto x86_l_cf1;
x86_l_e48:
	/* 0xe48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e4a:
	/* 0xe4a: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e4d:
	/* 0xe4d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e52:
	/* 0xe52: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e55:
	/* 0xe55: jae    e6d <trace_call_usermodehelper+0xe6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e6d;
	}
x86_l_e57:
	/* 0xe57: jmp    e83 <trace_call_usermodehelper+0xe83> */
	goto x86_l_e83;
x86_l_e59:
	/* 0xe59: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5b:
	/* 0xe5b: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e60:
	/* 0xe60: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e63:
	/* 0xe63: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e68:
	/* 0xe68: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e6b:
	/* 0xe6b: jb     e83 <trace_call_usermodehelper+0xe83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e83;
	}
x86_l_e6d:
	/* 0xe6d: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e71:
	/* 0xe71: je     e78 <trace_call_usermodehelper+0xe78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e78;
	}
x86_l_e73:
	/* 0xe73: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e76:
	/* 0xe76: jbe    e83 <trace_call_usermodehelper+0xe83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e83;
	}
x86_l_e78:
	/* 0xe78: and    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_e80:
	/* 0xe80: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_e83:
	/* 0xe83: or     r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_e86:
	/* 0xe86: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e89:
	/* 0xe89: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_e8c:
	/* 0xe8c: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e91:
	/* 0xe91: cmp    QWORD PTR [rbp+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_e99:
	/* 0xe99: je     f30 <trace_call_usermodehelper+0xf30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3888ULL;
	}
x86_l_e9f:
	/* 0xe9f: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_ea4:
	/* 0xea4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea6:
	/* 0xea6: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ea9:
	/* 0xea9: mov    rbx,QWORD PTR [rbp+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_eb0:
	/* 0xeb0: mov    r15,QWORD PTR [rbp+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_eb7:
	/* 0xeb7: mov    r13,QWORD PTR [rbp+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_ebe:
	/* 0xebe: mov    r12,QWORD PTR [rbp+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
	return 3781ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3791ULL: goto x86_l_ecf;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3810ULL: goto x86_l_ee2;
	case 3813ULL: goto x86_l_ee5;
	case 3816ULL: goto x86_l_ee8;
	case 3821ULL: goto x86_l_eed;
	case 3828ULL: goto x86_l_ef4;
	case 3831ULL: goto x86_l_ef7;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3845ULL: goto x86_l_f05;
	case 3848ULL: goto x86_l_f08;
	case 3850ULL: goto x86_l_f0a;
	case 3853ULL: goto x86_l_f0d;
	case 3857ULL: goto x86_l_f11;
	case 3860ULL: goto x86_l_f14;
	case 3862ULL: goto x86_l_f16;
	case 3864ULL: goto x86_l_f18;
	case 3867ULL: goto x86_l_f1b;
	case 3872ULL: goto x86_l_f20;
	case 3875ULL: goto x86_l_f23;
	case 3878ULL: goto x86_l_f26;
	case 3880ULL: goto x86_l_f28;
	case 3886ULL: goto x86_l_f2e;
	case 3888ULL: goto x86_l_f30;
	case 3894ULL: goto x86_l_f36;
	case 3902ULL: goto x86_l_f3e;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3913ULL: goto x86_l_f49;
	case 3919ULL: goto x86_l_f4f;
	case 3921ULL: goto x86_l_f51;
	case 3924ULL: goto x86_l_f54;
	case 3926ULL: goto x86_l_f56;
	case 3929ULL: goto x86_l_f59;
	case 3932ULL: goto x86_l_f5c;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3943ULL: goto x86_l_f67;
	case 3951ULL: goto x86_l_f6f;
	case 3957ULL: goto x86_l_f75;
	case 3962ULL: goto x86_l_f7a;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3979ULL: goto x86_l_f8b;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4010ULL: goto x86_l_faa;
	case 4015ULL: goto x86_l_faf;
	case 4020ULL: goto x86_l_fb4;
	case 4022ULL: goto x86_l_fb6;
	case 4027ULL: goto x86_l_fbb;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4040ULL: goto x86_l_fc8;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4052ULL: goto x86_l_fd4;
	case 4055ULL: goto x86_l_fd7;
	case 4058ULL: goto x86_l_fda;
	case 4065ULL: goto x86_l_fe1;
	case 4072ULL: goto x86_l_fe8;
	case 4078ULL: goto x86_l_fee;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4095ULL: goto x86_l_fff;
	case 4098ULL: goto x86_l_1002;
	case 4100ULL: goto x86_l_1004;
	case 4107ULL: goto x86_l_100b;
	case 4110ULL: goto x86_l_100e;
	case 4112ULL: goto x86_l_1010;
	case 4115ULL: goto x86_l_1013;
	case 4119ULL: goto x86_l_1017;
	case 4124ULL: goto x86_l_101c;
	case 4126ULL: goto x86_l_101e;
	case 4129ULL: goto x86_l_1021;
	case 4131ULL: goto x86_l_1023;
	case 4134ULL: goto x86_l_1026;
	case 4138ULL: goto x86_l_102a;
	case 4141ULL: goto x86_l_102d;
	case 4143ULL: goto x86_l_102f;
	case 4145ULL: goto x86_l_1031;
	case 4148ULL: goto x86_l_1034;
	case 4151ULL: goto x86_l_1037;
	case 4154ULL: goto x86_l_103a;
	case 4157ULL: goto x86_l_103d;
	case 4165ULL: goto x86_l_1045;
	case 4171ULL: goto x86_l_104b;
	case 4178ULL: goto x86_l_1052;
	case 4182ULL: goto x86_l_1056;
	case 4187ULL: goto x86_l_105b;
	case 4192ULL: goto x86_l_1060;
	case 4197ULL: goto x86_l_1065;
	case 4202ULL: goto x86_l_106a;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4214ULL: goto x86_l_1076;
	case 4219ULL: goto x86_l_107b;
	case 4224ULL: goto x86_l_1080;
	case 4229ULL: goto x86_l_1085;
	case 4232ULL: goto x86_l_1088;
	case 4234ULL: goto x86_l_108a;
	case 4238ULL: goto x86_l_108e;
	case 4242ULL: goto x86_l_1092;
	case 4246ULL: goto x86_l_1096;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4291ULL: goto x86_l_10c3;
	case 4296ULL: goto x86_l_10c8;
	case 4301ULL: goto x86_l_10cd;
	case 4303ULL: goto x86_l_10cf;
	case 4307ULL: goto x86_l_10d3;
	case 4310ULL: goto x86_l_10d6;
	case 4317ULL: goto x86_l_10dd;
	case 4324ULL: goto x86_l_10e4;
	case 4330ULL: goto x86_l_10ea;
	case 4337ULL: goto x86_l_10f1;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4350ULL: goto x86_l_10fe;
	case 4352ULL: goto x86_l_1100;
	case 4359ULL: goto x86_l_1107;
	case 4362ULL: goto x86_l_110a;
	case 4364ULL: goto x86_l_110c;
	case 4367ULL: goto x86_l_110f;
	case 4371ULL: goto x86_l_1113;
	case 4376ULL: goto x86_l_1118;
	case 4378ULL: goto x86_l_111a;
	case 4381ULL: goto x86_l_111d;
	case 4383ULL: goto x86_l_111f;
	case 4386ULL: goto x86_l_1122;
	case 4390ULL: goto x86_l_1126;
	case 4393ULL: goto x86_l_1129;
	case 4395ULL: goto x86_l_112b;
	case 4397ULL: goto x86_l_112d;
	case 4400ULL: goto x86_l_1130;
	case 4403ULL: goto x86_l_1133;
	case 4406ULL: goto x86_l_1136;
	case 4409ULL: goto x86_l_1139;
	case 4417ULL: goto x86_l_1141;
	case 4423ULL: goto x86_l_1147;
	case 4428ULL: goto x86_l_114c;
	case 4435ULL: goto x86_l_1153;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4455ULL: goto x86_l_1167;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4477ULL: goto x86_l_117d;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4504ULL: goto x86_l_1198;
	case 4507ULL: goto x86_l_119b;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4528ULL: goto x86_l_11b0;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4539ULL: goto x86_l_11bb;
	case 4541ULL: goto x86_l_11bd;
	case 4548ULL: goto x86_l_11c4;
	case 4555ULL: goto x86_l_11cb;
	case 4561ULL: goto x86_l_11d1;
	case 4568ULL: goto x86_l_11d8;
	case 4573ULL: goto x86_l_11dd;
	case 4578ULL: goto x86_l_11e2;
	case 4581ULL: goto x86_l_11e5;
	case 4583ULL: goto x86_l_11e7;
	case 4590ULL: goto x86_l_11ee;
	case 4593ULL: goto x86_l_11f1;
	case 4595ULL: goto x86_l_11f3;
	case 4598ULL: goto x86_l_11f6;
	case 4603ULL: goto x86_l_11fb;
	case 4606ULL: goto x86_l_11fe;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4613ULL: goto x86_l_1205;
	case 4616ULL: goto x86_l_1208;
	case 4620ULL: goto x86_l_120c;
	case 4623ULL: goto x86_l_120f;
	case 4625ULL: goto x86_l_1211;
	case 4627ULL: goto x86_l_1213;
	case 4630ULL: goto x86_l_1216;
	case 4633ULL: goto x86_l_1219;
	case 4636ULL: goto x86_l_121c;
	case 4639ULL: goto x86_l_121f;
	case 4645ULL: goto x86_l_1225;
	case 4653ULL: goto x86_l_122d;
	case 4659ULL: goto x86_l_1233;
	case 4663ULL: goto x86_l_1237;
	case 4668ULL: goto x86_l_123c;
	case 4673ULL: goto x86_l_1241;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4683ULL: goto x86_l_124b;
	case 4690ULL: goto x86_l_1252;
	case 4697ULL: goto x86_l_1259;
	case 4703ULL: goto x86_l_125f;
	case 4710ULL: goto x86_l_1266;
	case 4715ULL: goto x86_l_126b;
	case 4720ULL: goto x86_l_1270;
	case 4723ULL: goto x86_l_1273;
	case 4725ULL: goto x86_l_1275;
	case 4732ULL: goto x86_l_127c;
	case 4735ULL: goto x86_l_127f;
	case 4737ULL: goto x86_l_1281;
	case 4740ULL: goto x86_l_1284;
	case 4745ULL: goto x86_l_1289;
	case 4748ULL: goto x86_l_128c;
	case 4750ULL: goto x86_l_128e;
	case 4753ULL: goto x86_l_1291;
	case 4755ULL: goto x86_l_1293;
	case 4758ULL: goto x86_l_1296;
	case 4762ULL: goto x86_l_129a;
	case 4765ULL: goto x86_l_129d;
	case 4767ULL: goto x86_l_129f;
	case 4769ULL: goto x86_l_12a1;
	case 4772ULL: goto x86_l_12a4;
	case 4775ULL: goto x86_l_12a7;
	case 4778ULL: goto x86_l_12aa;
	case 4781ULL: goto x86_l_12ad;
	case 4787ULL: goto x86_l_12b3;
	case 4794ULL: goto x86_l_12ba;
	case 4797ULL: goto x86_l_12bd;
	case 4799ULL: goto x86_l_12bf;
	case 4802ULL: goto x86_l_12c2;
	case 4806ULL: goto x86_l_12c6;
	case 4813ULL: goto x86_l_12cd;
	case 4818ULL: goto x86_l_12d2;
	case 4825ULL: goto x86_l_12d9;
	case 4828ULL: goto x86_l_12dc;
	case 4833ULL: goto x86_l_12e1;
	case 4836ULL: goto x86_l_12e4;
	case 4838ULL: goto x86_l_12e6;
	case 4845ULL: goto x86_l_12ed;
	case 4848ULL: goto x86_l_12f0;
	case 4850ULL: goto x86_l_12f2;
	case 4853ULL: goto x86_l_12f5;
	case 4858ULL: goto x86_l_12fa;
	case 4863ULL: goto x86_l_12ff;
	case 4865ULL: goto x86_l_1301;
	case 4868ULL: goto x86_l_1304;
	case 4870ULL: goto x86_l_1306;
	case 4873ULL: goto x86_l_1309;
	case 4877ULL: goto x86_l_130d;
	case 4880ULL: goto x86_l_1310;
	case 4882ULL: goto x86_l_1312;
	case 4884ULL: goto x86_l_1314;
	case 4887ULL: goto x86_l_1317;
	case 4890ULL: goto x86_l_131a;
	case 4893ULL: goto x86_l_131d;
	case 4896ULL: goto x86_l_1320;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4915ULL: goto x86_l_1333;
	case 4921ULL: goto x86_l_1339;
	case 4928ULL: goto x86_l_1340;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4941ULL: goto x86_l_134d;
	case 4943ULL: goto x86_l_134f;
	case 4950ULL: goto x86_l_1356;
	case 4953ULL: goto x86_l_1359;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4962ULL: goto x86_l_1362;
	case 4967ULL: goto x86_l_1367;
	case 4969ULL: goto x86_l_1369;
	case 4972ULL: goto x86_l_136c;
	case 4974ULL: goto x86_l_136e;
	case 4977ULL: goto x86_l_1371;
	case 4981ULL: goto x86_l_1375;
	case 4984ULL: goto x86_l_1378;
	case 4986ULL: goto x86_l_137a;
	case 4988ULL: goto x86_l_137c;
	case 4991ULL: goto x86_l_137f;
	case 4994ULL: goto x86_l_1382;
	case 4997ULL: goto x86_l_1385;
	case 5000ULL: goto x86_l_1388;
	case 5007ULL: goto x86_l_138f;
	case 5010ULL: goto x86_l_1392;
	case 5016ULL: goto x86_l_1398;
	case 5023ULL: goto x86_l_139f;
	case 5029ULL: goto x86_l_13a5;
	case 5036ULL: goto x86_l_13ac;
	case 5041ULL: goto x86_l_13b1;
	case 5046ULL: goto x86_l_13b6;
	case 5049ULL: goto x86_l_13b9;
	case 5051ULL: goto x86_l_13bb;
	case 5058ULL: goto x86_l_13c2;
	case 5061ULL: goto x86_l_13c5;
	case 5063ULL: goto x86_l_13c7;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5075ULL: goto x86_l_13d3;
	case 5080ULL: goto x86_l_13d8;
	case 5083ULL: goto x86_l_13db;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5090ULL: goto x86_l_13e2;
	case 5095ULL: goto x86_l_13e7;
	case 5099ULL: goto x86_l_13eb;
	case 5104ULL: goto x86_l_13f0;
	case 5107ULL: goto x86_l_13f3;
	case 5109ULL: goto x86_l_13f5;
	case 5112ULL: goto x86_l_13f8;
	case 5114ULL: goto x86_l_13fa;
	case 5117ULL: goto x86_l_13fd;
	case 5121ULL: goto x86_l_1401;
	case 5124ULL: goto x86_l_1404;
	case 5126ULL: goto x86_l_1406;
	case 5128ULL: goto x86_l_1408;
	case 5131ULL: goto x86_l_140b;
	case 5134ULL: goto x86_l_140e;
	case 5137ULL: goto x86_l_1411;
	case 5140ULL: goto x86_l_1414;
	case 5147ULL: goto x86_l_141b;
	case 5150ULL: goto x86_l_141e;
	case 5158ULL: goto x86_l_1426;
	case 5160ULL: goto x86_l_1428;
	case 5165ULL: goto x86_l_142d;
	case 5169ULL: goto x86_l_1431;
	case 5172ULL: goto x86_l_1434;
	case 5174ULL: goto x86_l_1436;
	case 5181ULL: goto x86_l_143d;
	case 5188ULL: goto x86_l_1444;
	case 5191ULL: goto x86_l_1447;
	case 5198ULL: goto x86_l_144e;
	case 5204ULL: goto x86_l_1454;
	case 5211ULL: goto x86_l_145b;
	case 5215ULL: goto x86_l_145f;
	case 5219ULL: goto x86_l_1463;
	case 5222ULL: goto x86_l_1466;
	case 5226ULL: goto x86_l_146a;
	case 5230ULL: goto x86_l_146e;
	case 5234ULL: goto x86_l_1472;
	case 5237ULL: goto x86_l_1475;
	case 5243ULL: goto x86_l_147b;
	case 5245ULL: goto x86_l_147d;
	case 5248ULL: goto x86_l_1480;
	case 5253ULL: goto x86_l_1485;
	case 5261ULL: goto x86_l_148d;
	case 5268ULL: goto x86_l_1494;
	case 5275ULL: goto x86_l_149b;
	case 5282ULL: goto x86_l_14a2;
	case 5284ULL: goto x86_l_14a4;
	case 5289ULL: goto x86_l_14a9;
	case 5292ULL: goto x86_l_14ac;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5309ULL: goto x86_l_14bd;
	case 5316ULL: goto x86_l_14c4;
	case 5319ULL: goto x86_l_14c7;
	case 5326ULL: goto x86_l_14ce;
	case 5331ULL: goto x86_l_14d3;
	case 5333ULL: goto x86_l_14d5;
	case 5335ULL: goto x86_l_14d7;
	case 5337ULL: goto x86_l_14d9;
	case 5340ULL: goto x86_l_14dc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_ec5:
	/* 0xec5: movzx  eax,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_eca:
	/* 0xeca: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ecf:
	/* 0xecf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_ed6:
	/* 0xed6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_edb:
	/* 0xedb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ee0:
	/* 0xee0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee2:
	/* 0xee2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ee5:
	/* 0xee5: mov    eax,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ee8:
	/* 0xee8: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eed:
	/* 0xeed: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ef4:
	/* 0xef4: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_ef7:
	/* 0xef7: je     f16 <trace_call_usermodehelper+0xf16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f16;
	}
x86_l_ef9:
	/* 0xef9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_efe:
	/* 0xefe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f03:
	/* 0xf03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f05:
	/* 0xf05: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f08:
	/* 0xf08: je     f16 <trace_call_usermodehelper+0xf16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f16;
	}
x86_l_f0a:
	/* 0xf0a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f0d:
	/* 0xf0d: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f11:
	/* 0xf11: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f14:
	/* 0xf14: jmp    f18 <trace_call_usermodehelper+0xf18> */
	goto x86_l_f18;
x86_l_f16:
	/* 0xf16: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f18:
	/* 0xf18: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f1b:
	/* 0xf1b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f20:
	/* 0xf20: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_f23:
	/* 0xf23: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_f26:
	/* 0xf26: jae    f45 <trace_call_usermodehelper+0xf45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f45;
	}
x86_l_f28:
	/* 0xf28: movzx  r13d,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_f2e:
	/* 0xf2e: jmp    f5c <trace_call_usermodehelper+0xf5c> */
	goto x86_l_f5c;
x86_l_f30:
	/* 0xf30: movzx  r13d,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_f36:
	/* 0xf36: cmp    QWORD PTR [rbp+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_f3e:
	/* 0xf3e: jne    f75 <trace_call_usermodehelper+0xf75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f75;
	}
x86_l_f40:
	/* 0xf40: jmp    103d <trace_call_usermodehelper+0x103d> */
	goto x86_l_103d;
x86_l_f45:
	/* 0xf45: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f49:
	/* 0xf49: movzx  r13d,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_f4f:
	/* 0xf4f: je     f56 <trace_call_usermodehelper+0xf56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f56;
	}
x86_l_f51:
	/* 0xf51: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_f54:
	/* 0xf54: jbe    f5c <trace_call_usermodehelper+0xf5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f5c;
	}
x86_l_f56:
	/* 0xf56: and    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_f59:
	/* 0xf59: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_f5c:
	/* 0xf5c: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f5f:
	/* 0xf5f: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_f62:
	/* 0xf62: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f67:
	/* 0xf67: cmp    QWORD PTR [rbp+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_f6f:
	/* 0xf6f: je     103d <trace_call_usermodehelper+0x103d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_103d;
	}
x86_l_f75:
	/* 0xf75: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_f7a:
	/* 0xf7a: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_f81:
	/* 0xf81: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f86:
	/* 0xf86: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f8b:
	/* 0xf8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f90:
	/* 0xf90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f95:
	/* 0xf95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f97:
	/* 0xf97: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f9c:
	/* 0xf9c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fa0:
	/* 0xfa0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fa5:
	/* 0xfa5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_faa:
	/* 0xfaa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_faf:
	/* 0xfaf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fb4:
	/* 0xfb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb6:
	/* 0xfb6: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fbb:
	/* 0xfbb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_fbe:
	/* 0xfbe: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_fc3:
	/* 0xfc3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fc8:
	/* 0xfc8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fcd:
	/* 0xfcd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fd2:
	/* 0xfd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd4:
	/* 0xfd4: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd7:
	/* 0xfd7: mov    DWORD PTR [rbp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_fda:
	/* 0xfda: mov    rbx,QWORD PTR [rbp+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_fe1:
	/* 0xfe1: mov    r15,QWORD PTR [rbp+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_fe8:
	/* 0xfe8: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fee:
	/* 0xfee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_ff5:
	/* 0xff5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ffa:
	/* 0xffa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fff:
	/* 0xfff: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1002:
	/* 0x1002: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1004:
	/* 0x1004: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_100b:
	/* 0x100b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_100e:
	/* 0x100e: je     102f <trace_call_usermodehelper+0x102f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_102f;
	}
x86_l_1010:
	/* 0x1010: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1013:
	/* 0x1013: lea    rsi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1017:
	/* 0x1017: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_101c:
	/* 0x101c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101e:
	/* 0x101e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1021:
	/* 0x1021: je     102f <trace_call_usermodehelper+0x102f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_102f;
	}
x86_l_1023:
	/* 0x1023: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1026:
	/* 0x1026: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_102a:
	/* 0x102a: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_102d:
	/* 0x102d: jmp    1031 <trace_call_usermodehelper+0x1031> */
	goto x86_l_1031;
x86_l_102f:
	/* 0x102f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1031:
	/* 0x1031: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1034:
	/* 0x1034: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1037:
	/* 0x1037: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_103a:
	/* 0x103a: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_103d:
	/* 0x103d: cmp    QWORD PTR [rbp+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1045:
	/* 0x1045: je     1139 <trace_call_usermodehelper+0x1139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1139;
	}
x86_l_104b:
	/* 0x104b: mov    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1052:
	/* 0x1052: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1056:
	/* 0x1056: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_105b:
	/* 0x105b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1060:
	/* 0x1060: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1065:
	/* 0x1065: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_106a:
	/* 0x106a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106c:
	/* 0x106c: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1071:
	/* 0x1071: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1076:
	/* 0x1076: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_107b:
	/* 0x107b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1080:
	/* 0x1080: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1085:
	/* 0x1085: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1088:
	/* 0x1088: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108a:
	/* 0x108a: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_108e:
	/* 0x108e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1092:
	/* 0x1092: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1096:
	/* 0x1096: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_109a:
	/* 0x109a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_109f:
	/* 0x109f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10a4:
	/* 0x10a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10a9:
	/* 0x10a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10ae:
	/* 0x10ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b0:
	/* 0x10b0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b5:
	/* 0x10b5: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_10b9:
	/* 0x10b9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10be:
	/* 0x10be: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10c3:
	/* 0x10c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10c8:
	/* 0x10c8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10cd:
	/* 0x10cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cf:
	/* 0x10cf: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10d3:
	/* 0x10d3: mov    DWORD PTR [rbp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10d6:
	/* 0x10d6: mov    rbx,QWORD PTR [rbp+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_10dd:
	/* 0x10dd: mov    r15,QWORD PTR [rbp+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_10e4:
	/* 0x10e4: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ea:
	/* 0x10ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_10f1:
	/* 0x10f1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f6:
	/* 0x10f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10fb:
	/* 0x10fb: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10fe:
	/* 0x10fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1100:
	/* 0x1100: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1107:
	/* 0x1107: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_110a:
	/* 0x110a: je     112b <trace_call_usermodehelper+0x112b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112b;
	}
x86_l_110c:
	/* 0x110c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_110f:
	/* 0x110f: lea    rsi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1113:
	/* 0x1113: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1118:
	/* 0x1118: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111a:
	/* 0x111a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_111d:
	/* 0x111d: je     112b <trace_call_usermodehelper+0x112b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112b;
	}
x86_l_111f:
	/* 0x111f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1122:
	/* 0x1122: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1126:
	/* 0x1126: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1129:
	/* 0x1129: jmp    112d <trace_call_usermodehelper+0x112d> */
	goto x86_l_112d;
x86_l_112b:
	/* 0x112b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_112d:
	/* 0x112d: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1130:
	/* 0x1130: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1133:
	/* 0x1133: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1136:
	/* 0x1136: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1139:
	/* 0x1139: cmp    QWORD PTR [rbp+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1141:
	/* 0x1141: je     1225 <trace_call_usermodehelper+0x1225> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1225;
	}
x86_l_1147:
	/* 0x1147: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_114c:
	/* 0x114c: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1153:
	/* 0x1153: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1158:
	/* 0x1158: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_115d:
	/* 0x115d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1162:
	/* 0x1162: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1167:
	/* 0x1167: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1169:
	/* 0x1169: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_116e:
	/* 0x116e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1173:
	/* 0x1173: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1178:
	/* 0x1178: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_117d:
	/* 0x117d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1182:
	/* 0x1182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1184:
	/* 0x1184: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1189:
	/* 0x1189: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_118e:
	/* 0x118e: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1193:
	/* 0x1193: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1198:
	/* 0x1198: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_119b:
	/* 0x119b: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_11a0:
	/* 0x11a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a2:
	/* 0x11a2: lea    rbx,[rbp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_11a6:
	/* 0x11a6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_11ab:
	/* 0x11ab: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_11b0:
	/* 0x11b0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11b3:
	/* 0x11b3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_11b8:
	/* 0x11b8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_11bb:
	/* 0x11bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11bd:
	/* 0x11bd: mov    r15,QWORD PTR [rbp+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_11c4:
	/* 0x11c4: mov    r12,QWORD PTR [rbp+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_11cb:
	/* 0x11cb: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d1:
	/* 0x11d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_11d8:
	/* 0x11d8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11dd:
	/* 0x11dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11e2:
	/* 0x11e2: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11e5:
	/* 0x11e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e7:
	/* 0x11e7: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11ee:
	/* 0x11ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11f1:
	/* 0x11f1: je     1211 <trace_call_usermodehelper+0x1211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1211;
	}
x86_l_11f3:
	/* 0x11f3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11f6:
	/* 0x11f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11fb:
	/* 0x11fb: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_11fe:
	/* 0x11fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1200:
	/* 0x1200: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1203:
	/* 0x1203: je     1211 <trace_call_usermodehelper+0x1211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1211;
	}
x86_l_1205:
	/* 0x1205: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1208:
	/* 0x1208: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_120c:
	/* 0x120c: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_120f:
	/* 0x120f: jmp    1213 <trace_call_usermodehelper+0x1213> */
	goto x86_l_1213;
x86_l_1211:
	/* 0x1211: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1213:
	/* 0x1213: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1216:
	/* 0x1216: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1219:
	/* 0x1219: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_121c:
	/* 0x121c: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_121f:
	/* 0x121f: movzx  r13d,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_1225:
	/* 0x1225: cmp    QWORD PTR [rbp+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_122d:
	/* 0x122d: je     12b3 <trace_call_usermodehelper+0x12b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12b3;
	}
x86_l_1233:
	/* 0x1233: lea    rbx,[rbp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1237:
	/* 0x1237: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_123c:
	/* 0x123c: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1241:
	/* 0x1241: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1244:
	/* 0x1244: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1249:
	/* 0x1249: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124b:
	/* 0x124b: mov    r15,QWORD PTR [rbp+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1252:
	/* 0x1252: mov    r12,QWORD PTR [rbp+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1259:
	/* 0x1259: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_125f:
	/* 0x125f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1266:
	/* 0x1266: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_126b:
	/* 0x126b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1270:
	/* 0x1270: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1273:
	/* 0x1273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1275:
	/* 0x1275: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_127c:
	/* 0x127c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_127f:
	/* 0x127f: je     129f <trace_call_usermodehelper+0x129f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_129f;
	}
x86_l_1281:
	/* 0x1281: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1284:
	/* 0x1284: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1289:
	/* 0x1289: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_128c:
	/* 0x128c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128e:
	/* 0x128e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1291:
	/* 0x1291: je     129f <trace_call_usermodehelper+0x129f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_129f;
	}
x86_l_1293:
	/* 0x1293: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1296:
	/* 0x1296: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_129a:
	/* 0x129a: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_129d:
	/* 0x129d: jmp    12a1 <trace_call_usermodehelper+0x12a1> */
	goto x86_l_12a1;
x86_l_129f:
	/* 0x129f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12a1:
	/* 0x12a1: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12a4:
	/* 0x12a4: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_12a7:
	/* 0x12a7: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_12aa:
	/* 0x12aa: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_12ad:
	/* 0x12ad: movzx  r13d,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_12b3:
	/* 0x12b3: mov    rbx,QWORD PTR [rbp+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_12ba:
	/* 0x12ba: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_12bd:
	/* 0x12bd: je     1320 <trace_call_usermodehelper+0x1320> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1320;
	}
x86_l_12bf:
	/* 0x12bf: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12c2:
	/* 0x12c2: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12c6:
	/* 0x12c6: mov    r15,QWORD PTR [rbp+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_12cd:
	/* 0x12cd: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d2:
	/* 0x12d2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_12d9:
	/* 0x12d9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_12dc:
	/* 0x12dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e1:
	/* 0x12e1: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12e4:
	/* 0x12e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e6:
	/* 0x12e6: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12ed:
	/* 0x12ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12f0:
	/* 0x12f0: je     1312 <trace_call_usermodehelper+0x1312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1312;
	}
x86_l_12f2:
	/* 0x12f2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12f5:
	/* 0x12f5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12fa:
	/* 0x12fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12ff:
	/* 0x12ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1301:
	/* 0x1301: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1304:
	/* 0x1304: je     1312 <trace_call_usermodehelper+0x1312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1312;
	}
x86_l_1306:
	/* 0x1306: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1309:
	/* 0x1309: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130d:
	/* 0x130d: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1310:
	/* 0x1310: jmp    1314 <trace_call_usermodehelper+0x1314> */
	goto x86_l_1314;
x86_l_1312:
	/* 0x1312: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1314:
	/* 0x1314: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1317:
	/* 0x1317: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_131a:
	/* 0x131a: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_131d:
	/* 0x131d: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1320:
	/* 0x1320: mov    rbx,QWORD PTR [rbp+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1327:
	/* 0x1327: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_132a:
	/* 0x132a: je     1388 <trace_call_usermodehelper+0x1388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1388;
	}
x86_l_132c:
	/* 0x132c: mov    r15,QWORD PTR [rbp+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1333:
	/* 0x1333: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1339:
	/* 0x1339: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1340:
	/* 0x1340: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1345:
	/* 0x1345: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_134a:
	/* 0x134a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_134d:
	/* 0x134d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134f:
	/* 0x134f: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1356:
	/* 0x1356: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1359:
	/* 0x1359: je     137a <trace_call_usermodehelper+0x137a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_137a;
	}
x86_l_135b:
	/* 0x135b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_135e:
	/* 0x135e: lea    rsi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1362:
	/* 0x1362: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1367:
	/* 0x1367: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1369:
	/* 0x1369: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_136c:
	/* 0x136c: je     137a <trace_call_usermodehelper+0x137a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_137a;
	}
x86_l_136e:
	/* 0x136e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1371:
	/* 0x1371: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1375:
	/* 0x1375: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1378:
	/* 0x1378: jmp    137c <trace_call_usermodehelper+0x137c> */
	goto x86_l_137c;
x86_l_137a:
	/* 0x137a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137c:
	/* 0x137c: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_137f:
	/* 0x137f: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1382:
	/* 0x1382: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1385:
	/* 0x1385: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1388:
	/* 0x1388: mov    r15,QWORD PTR [rbp+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_138f:
	/* 0x138f: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1392:
	/* 0x1392: je     1414 <trace_call_usermodehelper+0x1414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1414;
	}
x86_l_1398:
	/* 0x1398: mov    r12,QWORD PTR [rbp+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_139f:
	/* 0x139f: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a5:
	/* 0x13a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_13ac:
	/* 0x13ac: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13b1:
	/* 0x13b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13b6:
	/* 0x13b6: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13b9:
	/* 0x13b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13bb:
	/* 0x13bb: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13c2:
	/* 0x13c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13c5:
	/* 0x13c5: je     1406 <trace_call_usermodehelper+0x1406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1406;
	}
x86_l_13c7:
	/* 0x13c7: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_13ca:
	/* 0x13ca: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13cf:
	/* 0x13cf: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_13d3:
	/* 0x13d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d8:
	/* 0x13d8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_13db:
	/* 0x13db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dd:
	/* 0x13dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13e0:
	/* 0x13e0: jne    13fa <trace_call_usermodehelper+0x13fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13fa;
	}
x86_l_13e2:
	/* 0x13e2: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13e7:
	/* 0x13e7: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13eb:
	/* 0x13eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13f0:
	/* 0x13f0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_13f3:
	/* 0x13f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f5:
	/* 0x13f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13f8:
	/* 0x13f8: je     1406 <trace_call_usermodehelper+0x1406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1406;
	}
x86_l_13fa:
	/* 0x13fa: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13fd:
	/* 0x13fd: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1401:
	/* 0x1401: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1404:
	/* 0x1404: jmp    1408 <trace_call_usermodehelper+0x1408> */
	goto x86_l_1408;
x86_l_1406:
	/* 0x1406: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1408:
	/* 0x1408: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_140b:
	/* 0x140b: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_140e:
	/* 0x140e: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1411:
	/* 0x1411: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1414:
	/* 0x1414: mov    rax,QWORD PTR [rbp+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_141b:
	/* 0x141b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_141e:
	/* 0x141e: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1426:
	/* 0x1426: je     1434 <trace_call_usermodehelper+0x1434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1434;
	}
x86_l_1428:
	/* 0x1428: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_142d:
	/* 0x142d: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1431:
	/* 0x1431: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1434:
	/* 0x1434: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1436:
	/* 0x1436: and    r14,QWORD PTR [rbp+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_143d:
	/* 0x143d: mov    rdx,QWORD PTR [rbp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1444:
	/* 0x1444: and    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1447:
	/* 0x1447: mov    QWORD PTR [rbp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_144e:
	/* 0x144e: je     1c09 <trace_call_usermodehelper+0x1c09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7177ULL;
	}
x86_l_1454:
	/* 0x1454: lea    rbx,[rbp+0x7d8a] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_145b:
	/* 0x145b: mov    rdx,QWORD PTR [r15+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_145f:
	/* 0x145f: mov    r13,QWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1463:
	/* 0x1463: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1466:
	/* 0x1466: mov    rbp,QWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_146a:
	/* 0x146a: mov    eax,DWORD PTR [r15+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_146e:
	/* 0x146e: mov    DWORD PTR [rsp+0x64],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_1472:
	/* 0x1472: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1475:
	/* 0x1475: cmp    rax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32000ULL);
x86_l_147b:
	/* 0x147b: jb     1485 <trace_call_usermodehelper+0x1485> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1485;
	}
x86_l_147d:
	/* 0x147d: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_1480:
	/* 0x1480: jmp    16a7 <trace_call_usermodehelper+0x16a7> */
	return 5799ULL;
x86_l_1485:
	/* 0x1485: mov    BYTE PTR [rsi+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_148d:
	/* 0x148d: movzx  ecx,WORD PTR [rsi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1494:
	/* 0x1494: mov    WORD PTR [rsi+0x7d8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_149b:
	/* 0x149b: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_14a2:
	/* 0x14a2: ja     150f <trace_call_usermodehelper+0x150f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5391ULL;
	}
x86_l_14a4:
	/* 0x14a4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a9:
	/* 0x14a9: add    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14ac:
	/* 0x14ac: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_14b3:
	/* 0x14b3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14b8:
	/* 0x14b8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_14bd:
	/* 0x14bd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_14c4:
	/* 0x14c4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14c7:
	/* 0x14c7: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_14ce:
	/* 0x14ce: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14d3:
	/* 0x14d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d5:
	/* 0x14d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14d7:
	/* 0x14d7: jle    150c <trace_call_usermodehelper+0x150c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5388ULL;
	}
x86_l_14d9:
	/* 0x14d9: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14dc:
	/* 0x14dc: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
	return 5347ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5347ULL: goto x86_l_14e3;
	case 5349ULL: goto x86_l_14e5;
	case 5354ULL: goto x86_l_14ea;
	case 5361ULL: goto x86_l_14f1;
	case 5368ULL: goto x86_l_14f8;
	case 5371ULL: goto x86_l_14fb;
	case 5378ULL: goto x86_l_1502;
	case 5384ULL: goto x86_l_1508;
	case 5386ULL: goto x86_l_150a;
	case 5388ULL: goto x86_l_150c;
	case 5391ULL: goto x86_l_150f;
	case 5394ULL: goto x86_l_1512;
	case 5399ULL: goto x86_l_1517;
	case 5405ULL: goto x86_l_151d;
	case 5410ULL: goto x86_l_1522;
	case 5418ULL: goto x86_l_152a;
	case 5426ULL: goto x86_l_1532;
	case 5430ULL: goto x86_l_1536;
	case 5437ULL: goto x86_l_153d;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5466ULL: goto x86_l_155a;
	case 5469ULL: goto x86_l_155d;
	case 5471ULL: goto x86_l_155f;
	case 5476ULL: goto x86_l_1564;
	case 5479ULL: goto x86_l_1567;
	case 5481ULL: goto x86_l_1569;
	case 5484ULL: goto x86_l_156c;
	case 5490ULL: goto x86_l_1572;
	case 5492ULL: goto x86_l_1574;
	case 5497ULL: goto x86_l_1579;
	case 5501ULL: goto x86_l_157d;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5518ULL: goto x86_l_158e;
	case 5525ULL: goto x86_l_1595;
	case 5528ULL: goto x86_l_1598;
	case 5535ULL: goto x86_l_159f;
	case 5540ULL: goto x86_l_15a4;
	case 5545ULL: goto x86_l_15a9;
	case 5547ULL: goto x86_l_15ab;
	case 5550ULL: goto x86_l_15ae;
	case 5552ULL: goto x86_l_15b0;
	case 5554ULL: goto x86_l_15b2;
	case 5557ULL: goto x86_l_15b5;
	case 5563ULL: goto x86_l_15bb;
	case 5569ULL: goto x86_l_15c1;
	case 5571ULL: goto x86_l_15c3;
	case 5578ULL: goto x86_l_15ca;
	case 5580ULL: goto x86_l_15cc;
	case 5585ULL: goto x86_l_15d1;
	case 5593ULL: goto x86_l_15d9;
	case 5599ULL: goto x86_l_15df;
	case 5602ULL: goto x86_l_15e2;
	case 5608ULL: goto x86_l_15e8;
	case 5613ULL: goto x86_l_15ed;
	case 5619ULL: goto x86_l_15f3;
	case 5627ULL: goto x86_l_15fb;
	case 5635ULL: goto x86_l_1603;
	case 5639ULL: goto x86_l_1607;
	case 5646ULL: goto x86_l_160e;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5678ULL: goto x86_l_162e;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5688ULL: goto x86_l_1638;
	case 5690ULL: goto x86_l_163a;
	case 5693ULL: goto x86_l_163d;
	case 5699ULL: goto x86_l_1643;
	case 5701ULL: goto x86_l_1645;
	case 5705ULL: goto x86_l_1649;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5729ULL: goto x86_l_1661;
	case 5733ULL: goto x86_l_1665;
	case 5740ULL: goto x86_l_166c;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5752ULL: goto x86_l_1678;
	case 5755ULL: goto x86_l_167b;
	case 5757ULL: goto x86_l_167d;
	case 5759ULL: goto x86_l_167f;
	case 5762ULL: goto x86_l_1682;
	case 5768ULL: goto x86_l_1688;
	case 5774ULL: goto x86_l_168e;
	case 5776ULL: goto x86_l_1690;
	case 5783ULL: goto x86_l_1697;
	case 5785ULL: goto x86_l_1699;
	case 5793ULL: goto x86_l_16a1;
	case 5799ULL: goto x86_l_16a7;
	case 5802ULL: goto x86_l_16aa;
	case 5809ULL: goto x86_l_16b1;
	case 5811ULL: goto x86_l_16b3;
	case 5819ULL: goto x86_l_16bb;
	case 5825ULL: goto x86_l_16c1;
	case 5827ULL: goto x86_l_16c3;
	case 5831ULL: goto x86_l_16c7;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5875ULL: goto x86_l_16f3;
	case 5881ULL: goto x86_l_16f9;
	case 5888ULL: goto x86_l_1700;
	case 5892ULL: goto x86_l_1704;
	case 5897ULL: goto x86_l_1709;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5917ULL: goto x86_l_171d;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5951ULL: goto x86_l_173f;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5962ULL: goto x86_l_174a;
	case 5967ULL: goto x86_l_174f;
	case 5972ULL: goto x86_l_1754;
	case 5977ULL: goto x86_l_1759;
	case 5982ULL: goto x86_l_175e;
	case 5984ULL: goto x86_l_1760;
	case 5989ULL: goto x86_l_1765;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6003ULL: goto x86_l_1773;
	case 6008ULL: goto x86_l_1778;
	case 6013ULL: goto x86_l_177d;
	case 6015ULL: goto x86_l_177f;
	case 6019ULL: goto x86_l_1783;
	case 6022ULL: goto x86_l_1786;
	case 6026ULL: goto x86_l_178a;
	case 6031ULL: goto x86_l_178f;
	case 6036ULL: goto x86_l_1794;
	case 6041ULL: goto x86_l_1799;
	case 6046ULL: goto x86_l_179e;
	case 6049ULL: goto x86_l_17a1;
	case 6051ULL: goto x86_l_17a3;
	case 6056ULL: goto x86_l_17a8;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6076ULL: goto x86_l_17bc;
	case 6079ULL: goto x86_l_17bf;
	case 6081ULL: goto x86_l_17c1;
	case 6085ULL: goto x86_l_17c5;
	case 6089ULL: goto x86_l_17c9;
	case 6093ULL: goto x86_l_17cd;
	case 6097ULL: goto x86_l_17d1;
	case 6102ULL: goto x86_l_17d6;
	case 6107ULL: goto x86_l_17db;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6119ULL: goto x86_l_17e7;
	case 6123ULL: goto x86_l_17eb;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6136ULL: goto x86_l_17f8;
	case 6141ULL: goto x86_l_17fd;
	case 6146ULL: goto x86_l_1802;
	case 6149ULL: goto x86_l_1805;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6182ULL: goto x86_l_1826;
	case 6187ULL: goto x86_l_182b;
	case 6192ULL: goto x86_l_1830;
	case 6197ULL: goto x86_l_1835;
	case 6202ULL: goto x86_l_183a;
	case 6207ULL: goto x86_l_183f;
	case 6210ULL: goto x86_l_1842;
	case 6212ULL: goto x86_l_1844;
	case 6216ULL: goto x86_l_1848;
	case 6220ULL: goto x86_l_184c;
	case 6224ULL: goto x86_l_1850;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6248ULL: goto x86_l_1868;
	case 6250ULL: goto x86_l_186a;
	case 6254ULL: goto x86_l_186e;
	case 6257ULL: goto x86_l_1871;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6280ULL: goto x86_l_1888;
	case 6282ULL: goto x86_l_188a;
	case 6287ULL: goto x86_l_188f;
	case 6292ULL: goto x86_l_1894;
	case 6297ULL: goto x86_l_1899;
	case 6302ULL: goto x86_l_189e;
	case 6307ULL: goto x86_l_18a3;
	case 6310ULL: goto x86_l_18a6;
	case 6312ULL: goto x86_l_18a8;
	case 6316ULL: goto x86_l_18ac;
	case 6320ULL: goto x86_l_18b0;
	case 6324ULL: goto x86_l_18b4;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6348ULL: goto x86_l_18cc;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6359ULL: goto x86_l_18d7;
	case 6364ULL: goto x86_l_18dc;
	case 6369ULL: goto x86_l_18e1;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6381ULL: goto x86_l_18ed;
	case 6386ULL: goto x86_l_18f2;
	case 6390ULL: goto x86_l_18f6;
	case 6395ULL: goto x86_l_18fb;
	case 6400ULL: goto x86_l_1900;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6420ULL: goto x86_l_1914;
	case 6425ULL: goto x86_l_1919;
	case 6430ULL: goto x86_l_191e;
	case 6435ULL: goto x86_l_1923;
	case 6440ULL: goto x86_l_1928;
	case 6443ULL: goto x86_l_192b;
	case 6445ULL: goto x86_l_192d;
	case 6449ULL: goto x86_l_1931;
	case 6453ULL: goto x86_l_1935;
	case 6457ULL: goto x86_l_1939;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6471ULL: goto x86_l_1947;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6492ULL: goto x86_l_195c;
	case 6497ULL: goto x86_l_1961;
	case 6502ULL: goto x86_l_1966;
	case 6507ULL: goto x86_l_196b;
	case 6512ULL: goto x86_l_1970;
	case 6514ULL: goto x86_l_1972;
	case 6519ULL: goto x86_l_1977;
	case 6521ULL: goto x86_l_1979;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6541ULL: goto x86_l_198d;
	case 6544ULL: goto x86_l_1990;
	case 6546ULL: goto x86_l_1992;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6561ULL: goto x86_l_19a1;
	case 6566ULL: goto x86_l_19a6;
	case 6571ULL: goto x86_l_19ab;
	case 6574ULL: goto x86_l_19ae;
	case 6576ULL: goto x86_l_19b0;
	case 6580ULL: goto x86_l_19b4;
	case 6584ULL: goto x86_l_19b8;
	case 6588ULL: goto x86_l_19bc;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6614ULL: goto x86_l_19d6;
	case 6618ULL: goto x86_l_19da;
	case 6621ULL: goto x86_l_19dd;
	case 6625ULL: goto x86_l_19e1;
	case 6632ULL: goto x86_l_19e8;
	case 6637ULL: goto x86_l_19ed;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6651ULL: goto x86_l_19fb;
	case 6656ULL: goto x86_l_1a00;
	case 6659ULL: goto x86_l_1a03;
	case 6661ULL: goto x86_l_1a05;
	case 6666ULL: goto x86_l_1a0a;
	case 6670ULL: goto x86_l_1a0e;
	case 6675ULL: goto x86_l_1a13;
	case 6680ULL: goto x86_l_1a18;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6692ULL: goto x86_l_1a24;
	case 6697ULL: goto x86_l_1a29;
	case 6700ULL: goto x86_l_1a2c;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6715ULL: goto x86_l_1a3b;
	case 6720ULL: goto x86_l_1a40;
	case 6722ULL: goto x86_l_1a42;
	case 6725ULL: goto x86_l_1a45;
	case 6728ULL: goto x86_l_1a48;
	case 6733ULL: goto x86_l_1a4d;
	case 6735ULL: goto x86_l_1a4f;
	case 6738ULL: goto x86_l_1a52;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6764ULL: goto x86_l_1a6c;
	case 6769ULL: goto x86_l_1a71;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6782ULL: goto x86_l_1a7e;
	case 6787ULL: goto x86_l_1a83;
	case 6792ULL: goto x86_l_1a88;
	case 6797ULL: goto x86_l_1a8d;
	case 6802ULL: goto x86_l_1a92;
	case 6804ULL: goto x86_l_1a94;
	case 6809ULL: goto x86_l_1a99;
	case 6813ULL: goto x86_l_1a9d;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6840ULL: goto x86_l_1ab8;
	case 6842ULL: goto x86_l_1aba;
	case 6847ULL: goto x86_l_1abf;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6861ULL: goto x86_l_1acd;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6874ULL: goto x86_l_1ada;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6883ULL: goto x86_l_1ae3;
	case 6887ULL: goto x86_l_1ae7;
	case 6895ULL: goto x86_l_1aef;
	case 6899ULL: goto x86_l_1af3;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6917ULL: goto x86_l_1b05;
	case 6922ULL: goto x86_l_1b0a;
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6947ULL: goto x86_l_1b23;
	case 6949ULL: goto x86_l_1b25;
	case 6954ULL: goto x86_l_1b2a;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6986ULL: goto x86_l_1b4a;
	case 6991ULL: goto x86_l_1b4f;
	case 6996ULL: goto x86_l_1b54;
	case 6999ULL: goto x86_l_1b57;
	case 7004ULL: goto x86_l_1b5c;
	case 7006ULL: goto x86_l_1b5e;
	case 7009ULL: goto x86_l_1b61;
	case 7013ULL: goto x86_l_1b65;
	case 7018ULL: goto x86_l_1b6a;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7031ULL: goto x86_l_1b77;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14e3:
	/* 0x14e3: ja     150f <trace_call_usermodehelper+0x150f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_150f;
	}
x86_l_14e5:
	/* 0x14e5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ea:
	/* 0x14ea: mov    DWORD PTR [rcx+rdx*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 138ULL);
x86_l_14f1:
	/* 0x14f1: add    ax,WORD PTR [rdx+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_14f8:
	/* 0x14f8: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_14fb:
	/* 0x14fb: mov    WORD PTR [rdx+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1502:
	/* 0x1502: inc    BYTE PTR [rdx+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1508:
	/* 0x1508: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_150a:
	/* 0x150a: jmp    150f <trace_call_usermodehelper+0x150f> */
	goto x86_l_150f;
x86_l_150c:
	/* 0x150c: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_150f:
	/* 0x150f: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1512:
	/* 0x1512: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1517:
	/* 0x1517: ja     15df <trace_call_usermodehelper+0x15df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15df;
	}
x86_l_151d:
	/* 0x151d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1522:
	/* 0x1522: mov    BYTE PTR [rcx+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_152a:
	/* 0x152a: movzx  r14d,WORD PTR [rcx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1532:
	/* 0x1532: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1536:
	/* 0x1536: mov    WORD PTR [rcx+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_153d:
	/* 0x153d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1546:
	/* 0x1546: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_154b:
	/* 0x154b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1550:
	/* 0x1550: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1555:
	/* 0x1555: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_155a:
	/* 0x155a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_155d:
	/* 0x155d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155f:
	/* 0x155f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1564:
	/* 0x1564: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1567:
	/* 0x1567: je     15c1 <trace_call_usermodehelper+0x15c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15c1;
	}
x86_l_1569:
	/* 0x1569: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_156c:
	/* 0x156c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1572:
	/* 0x1572: ja     15c1 <trace_call_usermodehelper+0x15c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15c1;
	}
x86_l_1574:
	/* 0x1574: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1579:
	/* 0x1579: lea    rdx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_157d:
	/* 0x157d: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1584:
	/* 0x1584: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1589:
	/* 0x1589: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_158e:
	/* 0x158e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1595:
	/* 0x1595: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1598:
	/* 0x1598: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_159f:
	/* 0x159f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15a4:
	/* 0x15a4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15a9:
	/* 0x15a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ab:
	/* 0x15ab: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ae:
	/* 0x15ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15b0:
	/* 0x15b0: jle    15c1 <trace_call_usermodehelper+0x15c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_15c1;
	}
x86_l_15b2:
	/* 0x15b2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15b5:
	/* 0x15b5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_15bb:
	/* 0x15bb: jbe    1c1f <trace_call_usermodehelper+0x1c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7199ULL;
	}
x86_l_15c1:
	/* 0x15c1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15c3:
	/* 0x15c3: cmp    r14d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 31998ULL);
x86_l_15ca:
	/* 0x15ca: ja     15df <trace_call_usermodehelper+0x15df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15df;
	}
x86_l_15cc:
	/* 0x15cc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d1:
	/* 0x15d1: mov    BYTE PTR [rax+r14*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_15d9:
	/* 0x15d9: inc    BYTE PTR [rax+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_15df:
	/* 0x15df: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15e2:
	/* 0x15e2: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_15e8:
	/* 0x15e8: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ed:
	/* 0x15ed: ja     16a7 <trace_call_usermodehelper+0x16a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16a7;
	}
x86_l_15f3:
	/* 0x15f3: mov    BYTE PTR [rbp+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_15fb:
	/* 0x15fb: movzx  r14d,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1603:
	/* 0x1603: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1607:
	/* 0x1607: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_160e:
	/* 0x160e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1617:
	/* 0x1617: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161c:
	/* 0x161c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1621:
	/* 0x1621: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1626:
	/* 0x1626: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_162b:
	/* 0x162b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_162e:
	/* 0x162e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1630:
	/* 0x1630: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1635:
	/* 0x1635: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1638:
	/* 0x1638: je     168e <trace_call_usermodehelper+0x168e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168e;
	}
x86_l_163a:
	/* 0x163a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_163d:
	/* 0x163d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1643:
	/* 0x1643: ja     168e <trace_call_usermodehelper+0x168e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_168e;
	}
x86_l_1645:
	/* 0x1645: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1649:
	/* 0x1649: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1650:
	/* 0x1650: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1655:
	/* 0x1655: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_165a:
	/* 0x165a: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1661:
	/* 0x1661: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1665:
	/* 0x1665: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_166c:
	/* 0x166c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1671:
	/* 0x1671: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1676:
	/* 0x1676: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1678:
	/* 0x1678: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_167b:
	/* 0x167b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_167d:
	/* 0x167d: jle    168e <trace_call_usermodehelper+0x168e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_168e;
	}
x86_l_167f:
	/* 0x167f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1682:
	/* 0x1682: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1688:
	/* 0x1688: jbe    3e54 <trace_call_usermodehelper+0x3e54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 15956ULL;
	}
x86_l_168e:
	/* 0x168e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1690:
	/* 0x1690: cmp    r14d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 31998ULL);
x86_l_1697:
	/* 0x1697: ja     16a7 <trace_call_usermodehelper+0x16a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16a7;
	}
x86_l_1699:
	/* 0x1699: mov    BYTE PTR [rbp+r14*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_16a1:
	/* 0x16a1: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_16a7:
	/* 0x16a7: movzx  ebx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16aa:
	/* 0x16aa: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_16b1:
	/* 0x16b1: ja     16f9 <trace_call_usermodehelper+0x16f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16f9;
	}
x86_l_16b3:
	/* 0x16b3: mov    BYTE PTR [rbp+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_16bb:
	/* 0x16bb: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_16c1:
	/* 0x16c1: ja     16f9 <trace_call_usermodehelper+0x16f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16f9;
	}
x86_l_16c3:
	/* 0x16c3: lea    rdi,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_16c7:
	/* 0x16c7: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_16ce:
	/* 0x16ce: lea    rdx,[rsp+0x64] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_16d3:
	/* 0x16d3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16d8:
	/* 0x16d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16dd:
	/* 0x16dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16e2:
	/* 0x16e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e4:
	/* 0x16e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16e7:
	/* 0x16e7: js     16f9 <trace_call_usermodehelper+0x16f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_16f9;
	}
x86_l_16e9:
	/* 0x16e9: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_16ec:
	/* 0x16ec: mov    WORD PTR [rbp+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_16f3:
	/* 0x16f3: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_16f9:
	/* 0x16f9: mov    r13,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1700:
	/* 0x1700: lea    r15,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1704:
	/* 0x1704: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1709:
	/* 0x1709: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_170e:
	/* 0x170e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1713:
	/* 0x1713: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1718:
	/* 0x1718: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_171b:
	/* 0x171b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171d:
	/* 0x171d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1722:
	/* 0x1722: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1727:
	/* 0x1727: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_172b:
	/* 0x172b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1730:
	/* 0x1730: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1735:
	/* 0x1735: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_173a:
	/* 0x173a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_173f:
	/* 0x173f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1741:
	/* 0x1741: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1746:
	/* 0x1746: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_174a:
	/* 0x174a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_174f:
	/* 0x174f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1754:
	/* 0x1754: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1759:
	/* 0x1759: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_175e:
	/* 0x175e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1760:
	/* 0x1760: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1765:
	/* 0x1765: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1769:
	/* 0x1769: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_176e:
	/* 0x176e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1773:
	/* 0x1773: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1778:
	/* 0x1778: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_177d:
	/* 0x177d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177f:
	/* 0x177f: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1783:
	/* 0x1783: mov    DWORD PTR [rbp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1786:
	/* 0x1786: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_178a:
	/* 0x178a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_178f:
	/* 0x178f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1794:
	/* 0x1794: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1799:
	/* 0x1799: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_179e:
	/* 0x179e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_17a1:
	/* 0x17a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a3:
	/* 0x17a3: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17a8:
	/* 0x17a8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17ad:
	/* 0x17ad: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17b2:
	/* 0x17b2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17b7:
	/* 0x17b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17bc:
	/* 0x17bc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_17bf:
	/* 0x17bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c1:
	/* 0x17c1: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17c5:
	/* 0x17c5: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_17c9:
	/* 0x17c9: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17cd:
	/* 0x17cd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17d1:
	/* 0x17d1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d6:
	/* 0x17d6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17db:
	/* 0x17db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17e0:
	/* 0x17e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17e5:
	/* 0x17e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e7:
	/* 0x17e7: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17eb:
	/* 0x17eb: mov    DWORD PTR [rbp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17ee:
	/* 0x17ee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17f3:
	/* 0x17f3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17f8:
	/* 0x17f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17fd:
	/* 0x17fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1802:
	/* 0x1802: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1805:
	/* 0x1805: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1807:
	/* 0x1807: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180c:
	/* 0x180c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1810:
	/* 0x1810: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1815:
	/* 0x1815: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_181a:
	/* 0x181a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_181f:
	/* 0x181f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1824:
	/* 0x1824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1826:
	/* 0x1826: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_182b:
	/* 0x182b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1830:
	/* 0x1830: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1835:
	/* 0x1835: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_183a:
	/* 0x183a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_183f:
	/* 0x183f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1842:
	/* 0x1842: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1844:
	/* 0x1844: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1848:
	/* 0x1848: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_184c:
	/* 0x184c: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1850:
	/* 0x1850: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1854:
	/* 0x1854: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1859:
	/* 0x1859: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_185e:
	/* 0x185e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1863:
	/* 0x1863: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1868:
	/* 0x1868: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186a:
	/* 0x186a: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_186e:
	/* 0x186e: mov    DWORD PTR [rbp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1871:
	/* 0x1871: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1876:
	/* 0x1876: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_187b:
	/* 0x187b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1880:
	/* 0x1880: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1885:
	/* 0x1885: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1888:
	/* 0x1888: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188a:
	/* 0x188a: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_188f:
	/* 0x188f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1894:
	/* 0x1894: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1899:
	/* 0x1899: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_189e:
	/* 0x189e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18a3:
	/* 0x18a3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_18a6:
	/* 0x18a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a8:
	/* 0x18a8: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18ac:
	/* 0x18ac: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_18b0:
	/* 0x18b0: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_18b4:
	/* 0x18b4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18b8:
	/* 0x18b8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18bd:
	/* 0x18bd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18c2:
	/* 0x18c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18c7:
	/* 0x18c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18cc:
	/* 0x18cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ce:
	/* 0x18ce: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18d3:
	/* 0x18d3: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_18d7:
	/* 0x18d7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18dc:
	/* 0x18dc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18e1:
	/* 0x18e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18e6:
	/* 0x18e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18eb:
	/* 0x18eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ed:
	/* 0x18ed: mov    r12d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18f2:
	/* 0x18f2: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18f6:
	/* 0x18f6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18fb:
	/* 0x18fb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1900:
	/* 0x1900: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1905:
	/* 0x1905: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190a:
	/* 0x190a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_190d:
	/* 0x190d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190f:
	/* 0x190f: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1914:
	/* 0x1914: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1919:
	/* 0x1919: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_191e:
	/* 0x191e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1923:
	/* 0x1923: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1928:
	/* 0x1928: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_192b:
	/* 0x192b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192d:
	/* 0x192d: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1931:
	/* 0x1931: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1935:
	/* 0x1935: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1939:
	/* 0x1939: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_193d:
	/* 0x193d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1942:
	/* 0x1942: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1947:
	/* 0x1947: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_194c:
	/* 0x194c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1951:
	/* 0x1951: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1953:
	/* 0x1953: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1958:
	/* 0x1958: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_195c:
	/* 0x195c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1961:
	/* 0x1961: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1966:
	/* 0x1966: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_196b:
	/* 0x196b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1970:
	/* 0x1970: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1972:
	/* 0x1972: cmp    r12d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1977:
	/* 0x1977: jne    19dd <trace_call_usermodehelper+0x19dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19dd;
	}
x86_l_1979:
	/* 0x1979: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_197e:
	/* 0x197e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1983:
	/* 0x1983: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1988:
	/* 0x1988: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_198d:
	/* 0x198d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1990:
	/* 0x1990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1992:
	/* 0x1992: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1997:
	/* 0x1997: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_199c:
	/* 0x199c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19a1:
	/* 0x19a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19a6:
	/* 0x19a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19ab:
	/* 0x19ab: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_19ae:
	/* 0x19ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b0:
	/* 0x19b0: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19b4:
	/* 0x19b4: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_19b8:
	/* 0x19b8: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_19bc:
	/* 0x19bc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_19c0:
	/* 0x19c0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19c5:
	/* 0x19c5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19ca:
	/* 0x19ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19cf:
	/* 0x19cf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19d4:
	/* 0x19d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d6:
	/* 0x19d6: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19da:
	/* 0x19da: mov    DWORD PTR [rbp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19dd:
	/* 0x19dd: mov    DWORD PTR [rbp+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19e1:
	/* 0x19e1: lea    r12,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_19e8:
	/* 0x19e8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ed:
	/* 0x19ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19f2:
	/* 0x19f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19f7:
	/* 0x19f7: lea    r15,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19fb:
	/* 0x19fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a00:
	/* 0x1a00: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a03:
	/* 0x1a03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a05:
	/* 0x1a05: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a0a:
	/* 0x1a0a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a0e:
	/* 0x1a0e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a13:
	/* 0x1a13: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a18:
	/* 0x1a18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a22:
	/* 0x1a22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a24:
	/* 0x1a24: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a29:
	/* 0x1a29: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a2c:
	/* 0x1a2c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1a31:
	/* 0x1a31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a36:
	/* 0x1a36: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a3b:
	/* 0x1a3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a40:
	/* 0x1a40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a42:
	/* 0x1a42: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a45:
	/* 0x1a45: mov    DWORD PTR [rbp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1a48:
	/* 0x1a48: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1a4d:
	/* 0x1a4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4f:
	/* 0x1a4f: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a52:
	/* 0x1a52: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a56:
	/* 0x1a56: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a60:
	/* 0x1a60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a65:
	/* 0x1a65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a6a:
	/* 0x1a6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6c:
	/* 0x1a6c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a71:
	/* 0x1a71: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a75:
	/* 0x1a75: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7a:
	/* 0x1a7a: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1a7e:
	/* 0x1a7e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a83:
	/* 0x1a83: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a88:
	/* 0x1a88: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a8d:
	/* 0x1a8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a92:
	/* 0x1a92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a94:
	/* 0x1a94: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a99:
	/* 0x1a99: mov    QWORD PTR [rbp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a9d:
	/* 0x1a9d: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1aa1:
	/* 0x1aa1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aa6:
	/* 0x1aa6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1aab:
	/* 0x1aab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1ab8:
	/* 0x1ab8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aba:
	/* 0x1aba: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1abf:
	/* 0x1abf: mov    QWORD PTR [rbp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ac3:
	/* 0x1ac3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ac8:
	/* 0x1ac8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1acd:
	/* 0x1acd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ad7:
	/* 0x1ad7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ada:
	/* 0x1ada: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1adc:
	/* 0x1adc: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1ae1:
	/* 0x1ae1: je     1ae7 <trace_call_usermodehelper+0x1ae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae7;
	}
x86_l_1ae3:
	/* 0x1ae3: or     BYTE PTR [rbp+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    QWORD PTR [rbp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_1aef:
	/* 0x1aef: lea    rdi,[rbp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1af3:
	/* 0x1af3: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1afb:
	/* 0x1afb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b00:
	/* 0x1b00: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1b05:
	/* 0x1b05: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b0a:
	/* 0x1b0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0c:
	/* 0x1b0c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x1b20: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b23:
	/* 0x1b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b25:
	/* 0x1b25: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b2a:
	/* 0x1b2a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b2f:
	/* 0x1b2f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b34:
	/* 0x1b34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b39:
	/* 0x1b39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b3e:
	/* 0x1b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b40:
	/* 0x1b40: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b45:
	/* 0x1b45: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b4a:
	/* 0x1b4a: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1b4f:
	/* 0x1b4f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b54:
	/* 0x1b54: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b57:
	/* 0x1b57: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1b5c:
	/* 0x1b5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5e:
	/* 0x1b5e: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1b61:
	/* 0x1b61: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1b65:
	/* 0x1b65: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b6a:
	/* 0x1b6a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b6f:
	/* 0x1b6f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b74:
	/* 0x1b74: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1b77:
	/* 0x1b77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 7033ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7059ULL: goto x86_l_1b93;
	case 7061ULL: goto x86_l_1b95;
	case 7069ULL: goto x86_l_1b9d;
	case 7073ULL: goto x86_l_1ba1;
	case 7081ULL: goto x86_l_1ba9;
	case 7083ULL: goto x86_l_1bab;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7105ULL: goto x86_l_1bc1;
	case 7108ULL: goto x86_l_1bc4;
	case 7110ULL: goto x86_l_1bc6;
	case 7112ULL: goto x86_l_1bc8;
	case 7114ULL: goto x86_l_1bca;
	case 7117ULL: goto x86_l_1bcd;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7137ULL: goto x86_l_1be1;
	case 7143ULL: goto x86_l_1be7;
	case 7147ULL: goto x86_l_1beb;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7164ULL: goto x86_l_1bfc;
	case 7169ULL: goto x86_l_1c01;
	case 7172ULL: goto x86_l_1c04;
	case 7175ULL: goto x86_l_1c07;
	case 7177ULL: goto x86_l_1c09;
	case 7184ULL: goto x86_l_1c10;
	case 7185ULL: goto x86_l_1c11;
	case 7187ULL: goto x86_l_1c13;
	case 7189ULL: goto x86_l_1c15;
	case 7191ULL: goto x86_l_1c17;
	case 7193ULL: goto x86_l_1c19;
	case 7194ULL: goto x86_l_1c1a;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7208ULL: goto x86_l_1c28;
	case 7215ULL: goto x86_l_1c2f;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7237ULL: goto x86_l_1c45;
	case 7241ULL: goto x86_l_1c49;
	case 7248ULL: goto x86_l_1c50;
	case 7253ULL: goto x86_l_1c55;
	case 7255ULL: goto x86_l_1c57;
	case 7259ULL: goto x86_l_1c5b;
	case 7268ULL: goto x86_l_1c64;
	case 7271ULL: goto x86_l_1c67;
	case 7280ULL: goto x86_l_1c70;
	case 7289ULL: goto x86_l_1c79;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7313ULL: goto x86_l_1c91;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	case 7325ULL: goto x86_l_1c9d;
	case 7331ULL: goto x86_l_1ca3;
	case 7334ULL: goto x86_l_1ca6;
	case 7340ULL: goto x86_l_1cac;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7355ULL: goto x86_l_1cbb;
	case 7362ULL: goto x86_l_1cc2;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7379ULL: goto x86_l_1cd3;
	case 7382ULL: goto x86_l_1cd6;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
	case 7401ULL: goto x86_l_1ce9;
	case 7404ULL: goto x86_l_1cec;
	case 7406ULL: goto x86_l_1cee;
	case 7408ULL: goto x86_l_1cf0;
	case 7414ULL: goto x86_l_1cf6;
	case 7417ULL: goto x86_l_1cf9;
	case 7423ULL: goto x86_l_1cff;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7438ULL: goto x86_l_1d0e;
	case 7445ULL: goto x86_l_1d15;
	case 7448ULL: goto x86_l_1d18;
	case 7453ULL: goto x86_l_1d1d;
	case 7458ULL: goto x86_l_1d22;
	case 7467ULL: goto x86_l_1d2b;
	case 7471ULL: goto x86_l_1d2f;
	case 7478ULL: goto x86_l_1d36;
	case 7483ULL: goto x86_l_1d3b;
	case 7485ULL: goto x86_l_1d3d;
	case 7489ULL: goto x86_l_1d41;
	case 7498ULL: goto x86_l_1d4a;
	case 7501ULL: goto x86_l_1d4d;
	case 7510ULL: goto x86_l_1d56;
	case 7519ULL: goto x86_l_1d5f;
	case 7523ULL: goto x86_l_1d63;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7538ULL: goto x86_l_1d72;
	case 7543ULL: goto x86_l_1d77;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7552ULL: goto x86_l_1d80;
	case 7555ULL: goto x86_l_1d83;
	case 7561ULL: goto x86_l_1d89;
	case 7564ULL: goto x86_l_1d8c;
	case 7570ULL: goto x86_l_1d92;
	case 7576ULL: goto x86_l_1d98;
	case 7581ULL: goto x86_l_1d9d;
	case 7585ULL: goto x86_l_1da1;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7609ULL: goto x86_l_1db9;
	case 7612ULL: goto x86_l_1dbc;
	case 7619ULL: goto x86_l_1dc3;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7631ULL: goto x86_l_1dcf;
	case 7634ULL: goto x86_l_1dd2;
	case 7636ULL: goto x86_l_1dd4;
	case 7638ULL: goto x86_l_1dd6;
	case 7644ULL: goto x86_l_1ddc;
	case 7647ULL: goto x86_l_1ddf;
	case 7653ULL: goto x86_l_1de5;
	case 7659ULL: goto x86_l_1deb;
	case 7664ULL: goto x86_l_1df0;
	case 7668ULL: goto x86_l_1df4;
	case 7675ULL: goto x86_l_1dfb;
	case 7678ULL: goto x86_l_1dfe;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7697ULL: goto x86_l_1e11;
	case 7701ULL: goto x86_l_1e15;
	case 7708ULL: goto x86_l_1e1c;
	case 7713ULL: goto x86_l_1e21;
	case 7715ULL: goto x86_l_1e23;
	case 7719ULL: goto x86_l_1e27;
	case 7728ULL: goto x86_l_1e30;
	case 7731ULL: goto x86_l_1e33;
	case 7740ULL: goto x86_l_1e3c;
	case 7749ULL: goto x86_l_1e45;
	case 7753ULL: goto x86_l_1e49;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7782ULL: goto x86_l_1e66;
	case 7785ULL: goto x86_l_1e69;
	case 7791ULL: goto x86_l_1e6f;
	case 7794ULL: goto x86_l_1e72;
	case 7800ULL: goto x86_l_1e78;
	case 7806ULL: goto x86_l_1e7e;
	case 7811ULL: goto x86_l_1e83;
	case 7815ULL: goto x86_l_1e87;
	case 7822ULL: goto x86_l_1e8e;
	case 7827ULL: goto x86_l_1e93;
	case 7832ULL: goto x86_l_1e98;
	case 7839ULL: goto x86_l_1e9f;
	case 7842ULL: goto x86_l_1ea2;
	case 7849ULL: goto x86_l_1ea9;
	case 7854ULL: goto x86_l_1eae;
	case 7859ULL: goto x86_l_1eb3;
	case 7861ULL: goto x86_l_1eb5;
	case 7864ULL: goto x86_l_1eb8;
	case 7866ULL: goto x86_l_1eba;
	case 7868ULL: goto x86_l_1ebc;
	case 7874ULL: goto x86_l_1ec2;
	case 7877ULL: goto x86_l_1ec5;
	case 7883ULL: goto x86_l_1ecb;
	case 7889ULL: goto x86_l_1ed1;
	case 7894ULL: goto x86_l_1ed6;
	case 7898ULL: goto x86_l_1eda;
	case 7905ULL: goto x86_l_1ee1;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7918ULL: goto x86_l_1eee;
	case 7926ULL: goto x86_l_1ef6;
	case 7930ULL: goto x86_l_1efa;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7944ULL: goto x86_l_1f08;
	case 7948ULL: goto x86_l_1f0c;
	case 7956ULL: goto x86_l_1f14;
	case 7959ULL: goto x86_l_1f17;
	case 7967ULL: goto x86_l_1f1f;
	case 7976ULL: goto x86_l_1f28;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8002ULL: goto x86_l_1f42;
	case 8007ULL: goto x86_l_1f47;
	case 8009ULL: goto x86_l_1f49;
	case 8012ULL: goto x86_l_1f4c;
	case 8018ULL: goto x86_l_1f52;
	case 8021ULL: goto x86_l_1f55;
	case 8027ULL: goto x86_l_1f5b;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8042ULL: goto x86_l_1f6a;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8059ULL: goto x86_l_1f7b;
	case 8066ULL: goto x86_l_1f82;
	case 8069ULL: goto x86_l_1f85;
	case 8076ULL: goto x86_l_1f8c;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8088ULL: goto x86_l_1f98;
	case 8091ULL: goto x86_l_1f9b;
	case 8093ULL: goto x86_l_1f9d;
	case 8095ULL: goto x86_l_1f9f;
	case 8101ULL: goto x86_l_1fa5;
	case 8104ULL: goto x86_l_1fa8;
	case 8110ULL: goto x86_l_1fae;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8125ULL: goto x86_l_1fbd;
	case 8132ULL: goto x86_l_1fc4;
	case 8135ULL: goto x86_l_1fc7;
	case 8140ULL: goto x86_l_1fcc;
	case 8145ULL: goto x86_l_1fd1;
	case 8153ULL: goto x86_l_1fd9;
	case 8157ULL: goto x86_l_1fdd;
	case 8164ULL: goto x86_l_1fe4;
	case 8169ULL: goto x86_l_1fe9;
	case 8171ULL: goto x86_l_1feb;
	case 8175ULL: goto x86_l_1fef;
	case 8183ULL: goto x86_l_1ff7;
	case 8186ULL: goto x86_l_1ffa;
	case 8194ULL: goto x86_l_2002;
	case 8203ULL: goto x86_l_200b;
	case 8207ULL: goto x86_l_200f;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8222ULL: goto x86_l_201e;
	case 8227ULL: goto x86_l_2023;
	case 8229ULL: goto x86_l_2025;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8245ULL: goto x86_l_2035;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8260ULL: goto x86_l_2044;
	case 8265ULL: goto x86_l_2049;
	case 8269ULL: goto x86_l_204d;
	case 8276ULL: goto x86_l_2054;
	case 8281ULL: goto x86_l_2059;
	case 8286ULL: goto x86_l_205e;
	case 8293ULL: goto x86_l_2065;
	case 8296ULL: goto x86_l_2068;
	case 8303ULL: goto x86_l_206f;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8315ULL: goto x86_l_207b;
	case 8318ULL: goto x86_l_207e;
	case 8320ULL: goto x86_l_2080;
	case 8322ULL: goto x86_l_2082;
	case 8328ULL: goto x86_l_2088;
	case 8331ULL: goto x86_l_208b;
	case 8337ULL: goto x86_l_2091;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8352ULL: goto x86_l_20a0;
	case 8359ULL: goto x86_l_20a7;
	case 8362ULL: goto x86_l_20aa;
	case 8367ULL: goto x86_l_20af;
	case 8372ULL: goto x86_l_20b4;
	case 8380ULL: goto x86_l_20bc;
	case 8384ULL: goto x86_l_20c0;
	case 8391ULL: goto x86_l_20c7;
	case 8396ULL: goto x86_l_20cc;
	case 8398ULL: goto x86_l_20ce;
	case 8402ULL: goto x86_l_20d2;
	case 8410ULL: goto x86_l_20da;
	case 8413ULL: goto x86_l_20dd;
	case 8421ULL: goto x86_l_20e5;
	case 8430ULL: goto x86_l_20ee;
	case 8434ULL: goto x86_l_20f2;
	case 8439ULL: goto x86_l_20f7;
	case 8444ULL: goto x86_l_20fc;
	case 8449ULL: goto x86_l_2101;
	case 8454ULL: goto x86_l_2106;
	case 8456ULL: goto x86_l_2108;
	case 8461ULL: goto x86_l_210d;
	case 8463ULL: goto x86_l_210f;
	case 8466ULL: goto x86_l_2112;
	case 8472ULL: goto x86_l_2118;
	case 8475ULL: goto x86_l_211b;
	case 8481ULL: goto x86_l_2121;
	case 8487ULL: goto x86_l_2127;
	case 8492ULL: goto x86_l_212c;
	case 8496ULL: goto x86_l_2130;
	case 8503ULL: goto x86_l_2137;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8520ULL: goto x86_l_2148;
	case 8523ULL: goto x86_l_214b;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8540ULL: goto x86_l_215c;
	case 8542ULL: goto x86_l_215e;
	case 8545ULL: goto x86_l_2161;
	case 8547ULL: goto x86_l_2163;
	case 8549ULL: goto x86_l_2165;
	case 8555ULL: goto x86_l_216b;
	case 8558ULL: goto x86_l_216e;
	case 8564ULL: goto x86_l_2174;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8579ULL: goto x86_l_2183;
	case 8586ULL: goto x86_l_218a;
	case 8589ULL: goto x86_l_218d;
	case 8594ULL: goto x86_l_2192;
	case 8599ULL: goto x86_l_2197;
	case 8607ULL: goto x86_l_219f;
	case 8611ULL: goto x86_l_21a3;
	case 8618ULL: goto x86_l_21aa;
	case 8623ULL: goto x86_l_21af;
	case 8625ULL: goto x86_l_21b1;
	case 8629ULL: goto x86_l_21b5;
	case 8637ULL: goto x86_l_21bd;
	case 8640ULL: goto x86_l_21c0;
	case 8648ULL: goto x86_l_21c8;
	case 8657ULL: goto x86_l_21d1;
	case 8661ULL: goto x86_l_21d5;
	case 8666ULL: goto x86_l_21da;
	case 8671ULL: goto x86_l_21df;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8690ULL: goto x86_l_21f2;
	case 8693ULL: goto x86_l_21f5;
	case 8699ULL: goto x86_l_21fb;
	case 8702ULL: goto x86_l_21fe;
	case 8708ULL: goto x86_l_2204;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8723ULL: goto x86_l_2213;
	case 8730ULL: goto x86_l_221a;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8747ULL: goto x86_l_222b;
	case 8750ULL: goto x86_l_222e;
	case 8757ULL: goto x86_l_2235;
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8769ULL: goto x86_l_2241;
	case 8772ULL: goto x86_l_2244;
	case 8774ULL: goto x86_l_2246;
	case 8776ULL: goto x86_l_2248;
	case 8782ULL: goto x86_l_224e;
	case 8785ULL: goto x86_l_2251;
	case 8791ULL: goto x86_l_2257;
	case 8797ULL: goto x86_l_225d;
	case 8802ULL: goto x86_l_2262;
	case 8806ULL: goto x86_l_2266;
	case 8813ULL: goto x86_l_226d;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8834ULL: goto x86_l_2282;
	case 8838ULL: goto x86_l_2286;
	case 8845ULL: goto x86_l_228d;
	case 8850ULL: goto x86_l_2292;
	case 8852ULL: goto x86_l_2294;
	case 8856ULL: goto x86_l_2298;
	case 8864ULL: goto x86_l_22a0;
	case 8867ULL: goto x86_l_22a3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b79:
	/* 0x1b79: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b83:
	/* 0x1b83: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_1b90:
	/* 0x1b90: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b93:
	/* 0x1b93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b95:
	/* 0x1b95: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1b9d:
	/* 0x1b9d: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    rbx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1ba9:
	/* 0x1ba9: je     1bcd <trace_call_usermodehelper+0x1bcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bcd;
	}
x86_l_1bab:
	/* 0x1bab: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1bb2:
	/* 0x1bb2: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1bbc:
	/* 0x1bbc: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1bc4:
	/* 0x1bc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc6:
	/* 0x1bc6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bc8:
	/* 0x1bc8: js     1bcd <trace_call_usermodehelper+0x1bcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1bcd;
	}
x86_l_1bca:
	/* 0x1bca: mov    DWORD PTR [rbp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1bcd:
	/* 0x1bcd: movzx  eax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bd4:
	/* 0x1bd4: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1bd9:
	/* 0x1bd9: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1bde:
	/* 0x1bde: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1be1:
	/* 0x1be1: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1be7:
	/* 0x1be7: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1beb:
	/* 0x1beb: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1bf2:
	/* 0x1bf2: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1bf7:
	/* 0x1bf7: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1bfc:
	/* 0x1bfc: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1c01:
	/* 0x1c01: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c04:
	/* 0x1c04: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1c07:
	/* 0x1c07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c09:
	/* 0x1c09: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1c10:
	/* 0x1c10: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1c11:
	/* 0x1c11: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1c13:
	/* 0x1c13: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1c15:
	/* 0x1c15: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1c17:
	/* 0x1c17: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1c19:
	/* 0x1c19: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1c1a:
	/* 0x1c1a: jmp    6056 <trace_call_usermodehelper+0x6056> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1c1f:
	/* 0x1c1f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c24:
	/* 0x1c24: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c28:
	/* 0x1c28: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c2f:
	/* 0x1c2f: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1c32:
	/* 0x1c32: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c37:
	/* 0x1c37: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c3c:
	/* 0x1c3c: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c45:
	/* 0x1c45: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c49:
	/* 0x1c49: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c50:
	/* 0x1c50: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c55:
	/* 0x1c55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c57:
	/* 0x1c57: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c5b:
	/* 0x1c5b: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1c64:
	/* 0x1c64: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1c67:
	/* 0x1c67: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c70:
	/* 0x1c70: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c79:
	/* 0x1c79: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c7d:
	/* 0x1c7d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c82:
	/* 0x1c82: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c87:
	/* 0x1c87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c8c:
	/* 0x1c8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c91:
	/* 0x1c91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c93:
	/* 0x1c93: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c98:
	/* 0x1c98: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1c9a:
	/* 0x1c9a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1c9d:
	/* 0x1c9d: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_1ca3:
	/* 0x1ca3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ca6:
	/* 0x1ca6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1cac:
	/* 0x1cac: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_1cb2:
	/* 0x1cb2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cb7:
	/* 0x1cb7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1cbb:
	/* 0x1cbb: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1cc2:
	/* 0x1cc2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1cc7:
	/* 0x1cc7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ccc:
	/* 0x1ccc: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cd3:
	/* 0x1cd3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1cd6:
	/* 0x1cd6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1cdd:
	/* 0x1cdd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ce2:
	/* 0x1ce2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ce7:
	/* 0x1ce7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce9:
	/* 0x1ce9: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cec:
	/* 0x1cec: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1cee:
	/* 0x1cee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cf0:
	/* 0x1cf0: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_1cf6:
	/* 0x1cf6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cf9:
	/* 0x1cf9: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1cff:
	/* 0x1cff: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_1d05:
	/* 0x1d05: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d0a:
	/* 0x1d0a: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1d0e:
	/* 0x1d0e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d15:
	/* 0x1d15: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1d18:
	/* 0x1d18: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d1d:
	/* 0x1d1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d22:
	/* 0x1d22: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d2b:
	/* 0x1d2b: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1d2f:
	/* 0x1d2f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d36:
	/* 0x1d36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d3b:
	/* 0x1d3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3d:
	/* 0x1d3d: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d41:
	/* 0x1d41: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1d4a:
	/* 0x1d4a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d56:
	/* 0x1d56: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d5f:
	/* 0x1d5f: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d63:
	/* 0x1d63: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d68:
	/* 0x1d68: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d72:
	/* 0x1d72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d77:
	/* 0x1d77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d79:
	/* 0x1d79: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7e:
	/* 0x1d7e: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1d80:
	/* 0x1d80: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1d83:
	/* 0x1d83: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_1d89:
	/* 0x1d89: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d8c:
	/* 0x1d8c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1d92:
	/* 0x1d92: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_1d98:
	/* 0x1d98: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d9d:
	/* 0x1d9d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1da1:
	/* 0x1da1: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1da8:
	/* 0x1da8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1dad:
	/* 0x1dad: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1db2:
	/* 0x1db2: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1db9:
	/* 0x1db9: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1dbc:
	/* 0x1dbc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1dc3:
	/* 0x1dc3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc8:
	/* 0x1dc8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1dcd:
	/* 0x1dcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcf:
	/* 0x1dcf: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dd2:
	/* 0x1dd2: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1dd4:
	/* 0x1dd4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dd6:
	/* 0x1dd6: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_1ddc:
	/* 0x1ddc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ddf:
	/* 0x1ddf: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1de5:
	/* 0x1de5: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_1deb:
	/* 0x1deb: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df0:
	/* 0x1df0: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1df4:
	/* 0x1df4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1dfb:
	/* 0x1dfb: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1dfe:
	/* 0x1dfe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e03:
	/* 0x1e03: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e08:
	/* 0x1e08: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e11:
	/* 0x1e11: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1e15:
	/* 0x1e15: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e1c:
	/* 0x1e1c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e21:
	/* 0x1e21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e23:
	/* 0x1e23: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e27:
	/* 0x1e27: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1e30:
	/* 0x1e30: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1e33:
	/* 0x1e33: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e3c:
	/* 0x1e3c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e45:
	/* 0x1e45: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e49:
	/* 0x1e49: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e4e:
	/* 0x1e4e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e53:
	/* 0x1e53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e58:
	/* 0x1e58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e5d:
	/* 0x1e5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5f:
	/* 0x1e5f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e64:
	/* 0x1e64: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1e66:
	/* 0x1e66: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1e69:
	/* 0x1e69: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_1e6f:
	/* 0x1e6f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e72:
	/* 0x1e72: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1e78:
	/* 0x1e78: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_1e7e:
	/* 0x1e7e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e83:
	/* 0x1e83: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1e87:
	/* 0x1e87: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1e8e:
	/* 0x1e8e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e93:
	/* 0x1e93: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e98:
	/* 0x1e98: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e9f:
	/* 0x1e9f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ea2:
	/* 0x1ea2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1ea9:
	/* 0x1ea9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eae:
	/* 0x1eae: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1eb3:
	/* 0x1eb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb5:
	/* 0x1eb5: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eb8:
	/* 0x1eb8: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1eba:
	/* 0x1eba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ebc:
	/* 0x1ebc: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_1ec2:
	/* 0x1ec2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ec5:
	/* 0x1ec5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1ecb:
	/* 0x1ecb: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_1ed1:
	/* 0x1ed1: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ed6:
	/* 0x1ed6: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1eda:
	/* 0x1eda: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ee1:
	/* 0x1ee1: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1ee4:
	/* 0x1ee4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1eee:
	/* 0x1eee: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ef6:
	/* 0x1ef6: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1efa:
	/* 0x1efa: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f01:
	/* 0x1f01: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f06:
	/* 0x1f06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f08:
	/* 0x1f08: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f0c:
	/* 0x1f0c: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f14:
	/* 0x1f14: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f17:
	/* 0x1f17: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f1f:
	/* 0x1f1f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f28:
	/* 0x1f28: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f2c:
	/* 0x1f2c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f31:
	/* 0x1f31: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f36:
	/* 0x1f36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f40:
	/* 0x1f40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f42:
	/* 0x1f42: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f47:
	/* 0x1f47: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_1f49:
	/* 0x1f49: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1f4c:
	/* 0x1f4c: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_1f52:
	/* 0x1f52: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f55:
	/* 0x1f55: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1f5b:
	/* 0x1f5b: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_1f61:
	/* 0x1f61: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f66:
	/* 0x1f66: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1f6a:
	/* 0x1f6a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1f71:
	/* 0x1f71: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f76:
	/* 0x1f76: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f7b:
	/* 0x1f7b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f82:
	/* 0x1f82: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f85:
	/* 0x1f85: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1f8c:
	/* 0x1f8c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f91:
	/* 0x1f91: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f96:
	/* 0x1f96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f98:
	/* 0x1f98: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f9b:
	/* 0x1f9b: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_1f9d:
	/* 0x1f9d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f9f:
	/* 0x1f9f: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_1fa5:
	/* 0x1fa5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fa8:
	/* 0x1fa8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1fae:
	/* 0x1fae: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_1fb4:
	/* 0x1fb4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fb9:
	/* 0x1fb9: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1fbd:
	/* 0x1fbd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1fc7:
	/* 0x1fc7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fcc:
	/* 0x1fcc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fd1:
	/* 0x1fd1: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fd9:
	/* 0x1fd9: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1fdd:
	/* 0x1fdd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1fe4:
	/* 0x1fe4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fe9:
	/* 0x1fe9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1feb:
	/* 0x1feb: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fef:
	/* 0x1fef: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1ff7:
	/* 0x1ff7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2002:
	/* 0x2002: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_200b:
	/* 0x200b: lea    rdx,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_200f:
	/* 0x200f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2014:
	/* 0x2014: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2019:
	/* 0x2019: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_201e:
	/* 0x201e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2023:
	/* 0x2023: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2025:
	/* 0x2025: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_202a:
	/* 0x202a: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_202c:
	/* 0x202c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_202f:
	/* 0x202f: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2035:
	/* 0x2035: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2038:
	/* 0x2038: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_203e:
	/* 0x203e: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2044:
	/* 0x2044: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2049:
	/* 0x2049: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_204d:
	/* 0x204d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2054:
	/* 0x2054: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2059:
	/* 0x2059: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_205e:
	/* 0x205e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2065:
	/* 0x2065: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2068:
	/* 0x2068: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_206f:
	/* 0x206f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2074:
	/* 0x2074: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2079:
	/* 0x2079: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_207b:
	/* 0x207b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_207e:
	/* 0x207e: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_2080:
	/* 0x2080: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2082:
	/* 0x2082: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2088:
	/* 0x2088: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_208b:
	/* 0x208b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2091:
	/* 0x2091: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2097:
	/* 0x2097: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_209c:
	/* 0x209c: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20a0:
	/* 0x20a0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_20a7:
	/* 0x20a7: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_20aa:
	/* 0x20aa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20af:
	/* 0x20af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20b4:
	/* 0x20b4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20bc:
	/* 0x20bc: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_20c0:
	/* 0x20c0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_20c7:
	/* 0x20c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20cc:
	/* 0x20cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ce:
	/* 0x20ce: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20d2:
	/* 0x20d2: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_20da:
	/* 0x20da: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_20dd:
	/* 0x20dd: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_20e5:
	/* 0x20e5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_20ee:
	/* 0x20ee: lea    rdx,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20f2:
	/* 0x20f2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f7:
	/* 0x20f7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20fc:
	/* 0x20fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2101:
	/* 0x2101: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2106:
	/* 0x2106: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2108:
	/* 0x2108: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_210d:
	/* 0x210d: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_210f:
	/* 0x210f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2112:
	/* 0x2112: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2118:
	/* 0x2118: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_211b:
	/* 0x211b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2121:
	/* 0x2121: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2127:
	/* 0x2127: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_212c:
	/* 0x212c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2130:
	/* 0x2130: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2137:
	/* 0x2137: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_213c:
	/* 0x213c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2141:
	/* 0x2141: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2148:
	/* 0x2148: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_214b:
	/* 0x214b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2152:
	/* 0x2152: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2157:
	/* 0x2157: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_215c:
	/* 0x215c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_215e:
	/* 0x215e: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2161:
	/* 0x2161: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_2163:
	/* 0x2163: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2165:
	/* 0x2165: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_216b:
	/* 0x216b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_216e:
	/* 0x216e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2174:
	/* 0x2174: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_217a:
	/* 0x217a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_217f:
	/* 0x217f: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2183:
	/* 0x2183: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_218a:
	/* 0x218a: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_218d:
	/* 0x218d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2192:
	/* 0x2192: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2197:
	/* 0x2197: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_219f:
	/* 0x219f: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_21a3:
	/* 0x21a3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_21aa:
	/* 0x21aa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21af:
	/* 0x21af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b1:
	/* 0x21b1: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21b5:
	/* 0x21b5: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_21bd:
	/* 0x21bd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_21c0:
	/* 0x21c0: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_21c8:
	/* 0x21c8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_21d1:
	/* 0x21d1: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21d5:
	/* 0x21d5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21da:
	/* 0x21da: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21df:
	/* 0x21df: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21e4:
	/* 0x21e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e9:
	/* 0x21e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21eb:
	/* 0x21eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21f0:
	/* 0x21f0: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_21f2:
	/* 0x21f2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_21f5:
	/* 0x21f5: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_21fb:
	/* 0x21fb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21fe:
	/* 0x21fe: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2204:
	/* 0x2204: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_220a:
	/* 0x220a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_220f:
	/* 0x220f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2213:
	/* 0x2213: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_221a:
	/* 0x221a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_221f:
	/* 0x221f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2224:
	/* 0x2224: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_222b:
	/* 0x222b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_222e:
	/* 0x222e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2235:
	/* 0x2235: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_223a:
	/* 0x223a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_223f:
	/* 0x223f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2241:
	/* 0x2241: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2244:
	/* 0x2244: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_2246:
	/* 0x2246: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2248:
	/* 0x2248: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_224e:
	/* 0x224e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2251:
	/* 0x2251: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2257:
	/* 0x2257: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_225d:
	/* 0x225d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2262:
	/* 0x2262: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2266:
	/* 0x2266: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_226d:
	/* 0x226d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2270:
	/* 0x2270: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2275:
	/* 0x2275: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_227a:
	/* 0x227a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2282:
	/* 0x2282: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2286:
	/* 0x2286: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_228d:
	/* 0x228d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2292:
	/* 0x2292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2294:
	/* 0x2294: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2298:
	/* 0x2298: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_22a0:
	/* 0x22a0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_22a3:
	/* 0x22a3: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
	return 8875ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8875ULL: goto x86_l_22ab;
	case 8884ULL: goto x86_l_22b4;
	case 8888ULL: goto x86_l_22b8;
	case 8893ULL: goto x86_l_22bd;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8910ULL: goto x86_l_22ce;
	case 8915ULL: goto x86_l_22d3;
	case 8917ULL: goto x86_l_22d5;
	case 8920ULL: goto x86_l_22d8;
	case 8926ULL: goto x86_l_22de;
	case 8929ULL: goto x86_l_22e1;
	case 8935ULL: goto x86_l_22e7;
	case 8941ULL: goto x86_l_22ed;
	case 8946ULL: goto x86_l_22f2;
	case 8950ULL: goto x86_l_22f6;
	case 8957ULL: goto x86_l_22fd;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8974ULL: goto x86_l_230e;
	case 8977ULL: goto x86_l_2311;
	case 8984ULL: goto x86_l_2318;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9001ULL: goto x86_l_2329;
	case 9003ULL: goto x86_l_232b;
	case 9009ULL: goto x86_l_2331;
	case 9012ULL: goto x86_l_2334;
	case 9018ULL: goto x86_l_233a;
	case 9024ULL: goto x86_l_2340;
	case 9029ULL: goto x86_l_2345;
	case 9033ULL: goto x86_l_2349;
	case 9040ULL: goto x86_l_2350;
	case 9043ULL: goto x86_l_2353;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9061ULL: goto x86_l_2365;
	case 9065ULL: goto x86_l_2369;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9079ULL: goto x86_l_2377;
	case 9083ULL: goto x86_l_237b;
	case 9091ULL: goto x86_l_2383;
	case 9094ULL: goto x86_l_2386;
	case 9102ULL: goto x86_l_238e;
	case 9111ULL: goto x86_l_2397;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9137ULL: goto x86_l_23b1;
	case 9142ULL: goto x86_l_23b6;
	case 9144ULL: goto x86_l_23b8;
	case 9147ULL: goto x86_l_23bb;
	case 9153ULL: goto x86_l_23c1;
	case 9156ULL: goto x86_l_23c4;
	case 9162ULL: goto x86_l_23ca;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9177ULL: goto x86_l_23d9;
	case 9184ULL: goto x86_l_23e0;
	case 9189ULL: goto x86_l_23e5;
	case 9194ULL: goto x86_l_23ea;
	case 9201ULL: goto x86_l_23f1;
	case 9204ULL: goto x86_l_23f4;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9223ULL: goto x86_l_2407;
	case 9226ULL: goto x86_l_240a;
	case 9228ULL: goto x86_l_240c;
	case 9230ULL: goto x86_l_240e;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9245ULL: goto x86_l_241d;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9260ULL: goto x86_l_242c;
	case 9267ULL: goto x86_l_2433;
	case 9270ULL: goto x86_l_2436;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9288ULL: goto x86_l_2448;
	case 9292ULL: goto x86_l_244c;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9306ULL: goto x86_l_245a;
	case 9310ULL: goto x86_l_245e;
	case 9318ULL: goto x86_l_2466;
	case 9321ULL: goto x86_l_2469;
	case 9329ULL: goto x86_l_2471;
	case 9338ULL: goto x86_l_247a;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9352ULL: goto x86_l_2488;
	case 9357ULL: goto x86_l_248d;
	case 9362ULL: goto x86_l_2492;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9371ULL: goto x86_l_249b;
	case 9374ULL: goto x86_l_249e;
	case 9380ULL: goto x86_l_24a4;
	case 9383ULL: goto x86_l_24a7;
	case 9389ULL: goto x86_l_24ad;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9404ULL: goto x86_l_24bc;
	case 9411ULL: goto x86_l_24c3;
	case 9416ULL: goto x86_l_24c8;
	case 9421ULL: goto x86_l_24cd;
	case 9428ULL: goto x86_l_24d4;
	case 9431ULL: goto x86_l_24d7;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9448ULL: goto x86_l_24e8;
	case 9450ULL: goto x86_l_24ea;
	case 9453ULL: goto x86_l_24ed;
	case 9455ULL: goto x86_l_24ef;
	case 9457ULL: goto x86_l_24f1;
	case 9463ULL: goto x86_l_24f7;
	case 9466ULL: goto x86_l_24fa;
	case 9472ULL: goto x86_l_2500;
	case 9478ULL: goto x86_l_2506;
	case 9483ULL: goto x86_l_250b;
	case 9487ULL: goto x86_l_250f;
	case 9494ULL: goto x86_l_2516;
	case 9497ULL: goto x86_l_2519;
	case 9502ULL: goto x86_l_251e;
	case 9507ULL: goto x86_l_2523;
	case 9515ULL: goto x86_l_252b;
	case 9519ULL: goto x86_l_252f;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9533ULL: goto x86_l_253d;
	case 9537ULL: goto x86_l_2541;
	case 9545ULL: goto x86_l_2549;
	case 9548ULL: goto x86_l_254c;
	case 9556ULL: goto x86_l_2554;
	case 9565ULL: goto x86_l_255d;
	case 9569ULL: goto x86_l_2561;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9598ULL: goto x86_l_257e;
	case 9601ULL: goto x86_l_2581;
	case 9607ULL: goto x86_l_2587;
	case 9610ULL: goto x86_l_258a;
	case 9616ULL: goto x86_l_2590;
	case 9622ULL: goto x86_l_2596;
	case 9627ULL: goto x86_l_259b;
	case 9631ULL: goto x86_l_259f;
	case 9638ULL: goto x86_l_25a6;
	case 9643ULL: goto x86_l_25ab;
	case 9648ULL: goto x86_l_25b0;
	case 9655ULL: goto x86_l_25b7;
	case 9658ULL: goto x86_l_25ba;
	case 9665ULL: goto x86_l_25c1;
	case 9670ULL: goto x86_l_25c6;
	case 9675ULL: goto x86_l_25cb;
	case 9677ULL: goto x86_l_25cd;
	case 9680ULL: goto x86_l_25d0;
	case 9682ULL: goto x86_l_25d2;
	case 9684ULL: goto x86_l_25d4;
	case 9690ULL: goto x86_l_25da;
	case 9693ULL: goto x86_l_25dd;
	case 9699ULL: goto x86_l_25e3;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9714ULL: goto x86_l_25f2;
	case 9721ULL: goto x86_l_25f9;
	case 9724ULL: goto x86_l_25fc;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9742ULL: goto x86_l_260e;
	case 9746ULL: goto x86_l_2612;
	case 9753ULL: goto x86_l_2619;
	case 9758ULL: goto x86_l_261e;
	case 9760ULL: goto x86_l_2620;
	case 9764ULL: goto x86_l_2624;
	case 9772ULL: goto x86_l_262c;
	case 9775ULL: goto x86_l_262f;
	case 9783ULL: goto x86_l_2637;
	case 9792ULL: goto x86_l_2640;
	case 9796ULL: goto x86_l_2644;
	case 9801ULL: goto x86_l_2649;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9816ULL: goto x86_l_2658;
	case 9818ULL: goto x86_l_265a;
	case 9823ULL: goto x86_l_265f;
	case 9825ULL: goto x86_l_2661;
	case 9828ULL: goto x86_l_2664;
	case 9834ULL: goto x86_l_266a;
	case 9837ULL: goto x86_l_266d;
	case 9843ULL: goto x86_l_2673;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9858ULL: goto x86_l_2682;
	case 9865ULL: goto x86_l_2689;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9882ULL: goto x86_l_269a;
	case 9885ULL: goto x86_l_269d;
	case 9892ULL: goto x86_l_26a4;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9904ULL: goto x86_l_26b0;
	case 9907ULL: goto x86_l_26b3;
	case 9909ULL: goto x86_l_26b5;
	case 9911ULL: goto x86_l_26b7;
	case 9917ULL: goto x86_l_26bd;
	case 9920ULL: goto x86_l_26c0;
	case 9926ULL: goto x86_l_26c6;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9941ULL: goto x86_l_26d5;
	case 9948ULL: goto x86_l_26dc;
	case 9951ULL: goto x86_l_26df;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9969ULL: goto x86_l_26f1;
	case 9973ULL: goto x86_l_26f5;
	case 9980ULL: goto x86_l_26fc;
	case 9985ULL: goto x86_l_2701;
	case 9987ULL: goto x86_l_2703;
	case 9991ULL: goto x86_l_2707;
	case 9999ULL: goto x86_l_270f;
	case 10002ULL: goto x86_l_2712;
	case 10010ULL: goto x86_l_271a;
	case 10019ULL: goto x86_l_2723;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10033ULL: goto x86_l_2731;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10045ULL: goto x86_l_273d;
	case 10050ULL: goto x86_l_2742;
	case 10052ULL: goto x86_l_2744;
	case 10055ULL: goto x86_l_2747;
	case 10061ULL: goto x86_l_274d;
	case 10064ULL: goto x86_l_2750;
	case 10070ULL: goto x86_l_2756;
	case 10076ULL: goto x86_l_275c;
	case 10081ULL: goto x86_l_2761;
	case 10085ULL: goto x86_l_2765;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10109ULL: goto x86_l_277d;
	case 10112ULL: goto x86_l_2780;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10129ULL: goto x86_l_2791;
	case 10131ULL: goto x86_l_2793;
	case 10134ULL: goto x86_l_2796;
	case 10136ULL: goto x86_l_2798;
	case 10138ULL: goto x86_l_279a;
	case 10144ULL: goto x86_l_27a0;
	case 10147ULL: goto x86_l_27a3;
	case 10153ULL: goto x86_l_27a9;
	case 10159ULL: goto x86_l_27af;
	case 10164ULL: goto x86_l_27b4;
	case 10168ULL: goto x86_l_27b8;
	case 10175ULL: goto x86_l_27bf;
	case 10178ULL: goto x86_l_27c2;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10196ULL: goto x86_l_27d4;
	case 10200ULL: goto x86_l_27d8;
	case 10207ULL: goto x86_l_27df;
	case 10212ULL: goto x86_l_27e4;
	case 10214ULL: goto x86_l_27e6;
	case 10218ULL: goto x86_l_27ea;
	case 10226ULL: goto x86_l_27f2;
	case 10229ULL: goto x86_l_27f5;
	case 10237ULL: goto x86_l_27fd;
	case 10246ULL: goto x86_l_2806;
	case 10250ULL: goto x86_l_280a;
	case 10255ULL: goto x86_l_280f;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10272ULL: goto x86_l_2820;
	case 10277ULL: goto x86_l_2825;
	case 10279ULL: goto x86_l_2827;
	case 10282ULL: goto x86_l_282a;
	case 10288ULL: goto x86_l_2830;
	case 10291ULL: goto x86_l_2833;
	case 10297ULL: goto x86_l_2839;
	case 10303ULL: goto x86_l_283f;
	case 10308ULL: goto x86_l_2844;
	case 10312ULL: goto x86_l_2848;
	case 10319ULL: goto x86_l_284f;
	case 10324ULL: goto x86_l_2854;
	case 10329ULL: goto x86_l_2859;
	case 10336ULL: goto x86_l_2860;
	case 10339ULL: goto x86_l_2863;
	case 10346ULL: goto x86_l_286a;
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10361ULL: goto x86_l_2879;
	case 10363ULL: goto x86_l_287b;
	case 10365ULL: goto x86_l_287d;
	case 10371ULL: goto x86_l_2883;
	case 10374ULL: goto x86_l_2886;
	case 10380ULL: goto x86_l_288c;
	case 10386ULL: goto x86_l_2892;
	case 10391ULL: goto x86_l_2897;
	case 10395ULL: goto x86_l_289b;
	case 10402ULL: goto x86_l_28a2;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10415ULL: goto x86_l_28af;
	case 10423ULL: goto x86_l_28b7;
	case 10427ULL: goto x86_l_28bb;
	case 10434ULL: goto x86_l_28c2;
	case 10439ULL: goto x86_l_28c7;
	case 10441ULL: goto x86_l_28c9;
	case 10445ULL: goto x86_l_28cd;
	case 10453ULL: goto x86_l_28d5;
	case 10456ULL: goto x86_l_28d8;
	case 10464ULL: goto x86_l_28e0;
	case 10473ULL: goto x86_l_28e9;
	case 10477ULL: goto x86_l_28ed;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10492ULL: goto x86_l_28fc;
	case 10497ULL: goto x86_l_2901;
	case 10499ULL: goto x86_l_2903;
	case 10504ULL: goto x86_l_2908;
	case 10506ULL: goto x86_l_290a;
	case 10509ULL: goto x86_l_290d;
	case 10515ULL: goto x86_l_2913;
	case 10518ULL: goto x86_l_2916;
	case 10524ULL: goto x86_l_291c;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10539ULL: goto x86_l_292b;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10563ULL: goto x86_l_2943;
	case 10566ULL: goto x86_l_2946;
	case 10573ULL: goto x86_l_294d;
	case 10578ULL: goto x86_l_2952;
	case 10583ULL: goto x86_l_2957;
	case 10585ULL: goto x86_l_2959;
	case 10588ULL: goto x86_l_295c;
	case 10590ULL: goto x86_l_295e;
	case 10592ULL: goto x86_l_2960;
	case 10598ULL: goto x86_l_2966;
	case 10601ULL: goto x86_l_2969;
	case 10607ULL: goto x86_l_296f;
	case 10613ULL: goto x86_l_2975;
	case 10618ULL: goto x86_l_297a;
	case 10622ULL: goto x86_l_297e;
	case 10629ULL: goto x86_l_2985;
	case 10632ULL: goto x86_l_2988;
	case 10637ULL: goto x86_l_298d;
	case 10642ULL: goto x86_l_2992;
	case 10650ULL: goto x86_l_299a;
	case 10654ULL: goto x86_l_299e;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10668ULL: goto x86_l_29ac;
	case 10672ULL: goto x86_l_29b0;
	case 10680ULL: goto x86_l_29b8;
	case 10683ULL: goto x86_l_29bb;
	case 10691ULL: goto x86_l_29c3;
	case 10700ULL: goto x86_l_29cc;
	case 10707ULL: goto x86_l_29d3;
	case 10712ULL: goto x86_l_29d8;
	case 10717ULL: goto x86_l_29dd;
	case 10722ULL: goto x86_l_29e2;
	case 10727ULL: goto x86_l_29e7;
	case 10729ULL: goto x86_l_29e9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22ab:
	/* 0x22ab: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_22b4:
	/* 0x22b4: lea    rdx,[rbp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22b8:
	/* 0x22b8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22bd:
	/* 0x22bd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22c2:
	/* 0x22c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22c7:
	/* 0x22c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22cc:
	/* 0x22cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ce:
	/* 0x22ce: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d3:
	/* 0x22d3: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_22d5:
	/* 0x22d5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_22d8:
	/* 0x22d8: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_22de:
	/* 0x22de: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22e1:
	/* 0x22e1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_22e7:
	/* 0x22e7: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_22ed:
	/* 0x22ed: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f2:
	/* 0x22f2: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_22f6:
	/* 0x22f6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_22fd:
	/* 0x22fd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2302:
	/* 0x2302: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2307:
	/* 0x2307: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_230e:
	/* 0x230e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2311:
	/* 0x2311: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2318:
	/* 0x2318: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_231d:
	/* 0x231d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2322:
	/* 0x2322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2324:
	/* 0x2324: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2327:
	/* 0x2327: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_2329:
	/* 0x2329: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_232b:
	/* 0x232b: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2331:
	/* 0x2331: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2334:
	/* 0x2334: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_233a:
	/* 0x233a: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2340:
	/* 0x2340: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2345:
	/* 0x2345: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2349:
	/* 0x2349: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2350:
	/* 0x2350: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2353:
	/* 0x2353: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2358:
	/* 0x2358: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_235d:
	/* 0x235d: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2365:
	/* 0x2365: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2369:
	/* 0x2369: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2370:
	/* 0x2370: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2375:
	/* 0x2375: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2377:
	/* 0x2377: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_237b:
	/* 0x237b: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2383:
	/* 0x2383: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2386:
	/* 0x2386: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_238e:
	/* 0x238e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2397:
	/* 0x2397: lea    rdx,[rbp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_239b:
	/* 0x239b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23a0:
	/* 0x23a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23a5:
	/* 0x23a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23aa:
	/* 0x23aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23af:
	/* 0x23af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b1:
	/* 0x23b1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23b6:
	/* 0x23b6: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_23b8:
	/* 0x23b8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_23bb:
	/* 0x23bb: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_23c1:
	/* 0x23c1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23c4:
	/* 0x23c4: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_23ca:
	/* 0x23ca: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_23d0:
	/* 0x23d0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d5:
	/* 0x23d5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_23d9:
	/* 0x23d9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_23e0:
	/* 0x23e0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_23e5:
	/* 0x23e5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_23ea:
	/* 0x23ea: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_23f1:
	/* 0x23f1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23f4:
	/* 0x23f4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_23fb:
	/* 0x23fb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2400:
	/* 0x2400: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2405:
	/* 0x2405: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2407:
	/* 0x2407: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_240a:
	/* 0x240a: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_240c:
	/* 0x240c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_240e:
	/* 0x240e: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2414:
	/* 0x2414: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2417:
	/* 0x2417: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_241d:
	/* 0x241d: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2423:
	/* 0x2423: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2428:
	/* 0x2428: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_242c:
	/* 0x242c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2433:
	/* 0x2433: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2436:
	/* 0x2436: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_243b:
	/* 0x243b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2440:
	/* 0x2440: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2448:
	/* 0x2448: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_244c:
	/* 0x244c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2453:
	/* 0x2453: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2458:
	/* 0x2458: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_245a:
	/* 0x245a: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_245e:
	/* 0x245e: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2466:
	/* 0x2466: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2469:
	/* 0x2469: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2471:
	/* 0x2471: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_247a:
	/* 0x247a: lea    rdx,[rbp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_247e:
	/* 0x247e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2483:
	/* 0x2483: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2488:
	/* 0x2488: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_248d:
	/* 0x248d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2492:
	/* 0x2492: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2494:
	/* 0x2494: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2499:
	/* 0x2499: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_249b:
	/* 0x249b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_249e:
	/* 0x249e: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_24a4:
	/* 0x24a4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24a7:
	/* 0x24a7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_24ad:
	/* 0x24ad: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_24b3:
	/* 0x24b3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24b8:
	/* 0x24b8: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_24bc:
	/* 0x24bc: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_24c3:
	/* 0x24c3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_24c8:
	/* 0x24c8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_24cd:
	/* 0x24cd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24d4:
	/* 0x24d4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24d7:
	/* 0x24d7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_24de:
	/* 0x24de: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e3:
	/* 0x24e3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_24e8:
	/* 0x24e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ea:
	/* 0x24ea: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ed:
	/* 0x24ed: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_24ef:
	/* 0x24ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24f1:
	/* 0x24f1: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_24f7:
	/* 0x24f7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24fa:
	/* 0x24fa: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2500:
	/* 0x2500: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2506:
	/* 0x2506: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_250b:
	/* 0x250b: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_250f:
	/* 0x250f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2516:
	/* 0x2516: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2519:
	/* 0x2519: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_251e:
	/* 0x251e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2523:
	/* 0x2523: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_252b:
	/* 0x252b: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_252f:
	/* 0x252f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2536:
	/* 0x2536: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_253b:
	/* 0x253b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253d:
	/* 0x253d: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2541:
	/* 0x2541: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2549:
	/* 0x2549: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_254c:
	/* 0x254c: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2554:
	/* 0x2554: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_255d:
	/* 0x255d: lea    rdx,[rbp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2561:
	/* 0x2561: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2566:
	/* 0x2566: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_256b:
	/* 0x256b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2570:
	/* 0x2570: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2575:
	/* 0x2575: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2577:
	/* 0x2577: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_257c:
	/* 0x257c: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_257e:
	/* 0x257e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2581:
	/* 0x2581: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2587:
	/* 0x2587: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_258a:
	/* 0x258a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2590:
	/* 0x2590: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2596:
	/* 0x2596: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_259b:
	/* 0x259b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_259f:
	/* 0x259f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_25a6:
	/* 0x25a6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_25ab:
	/* 0x25ab: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_25b0:
	/* 0x25b0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_25b7:
	/* 0x25b7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25ba:
	/* 0x25ba: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_25c1:
	/* 0x25c1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c6:
	/* 0x25c6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_25cb:
	/* 0x25cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25cd:
	/* 0x25cd: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25d0:
	/* 0x25d0: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_25d2:
	/* 0x25d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25d4:
	/* 0x25d4: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_25da:
	/* 0x25da: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25dd:
	/* 0x25dd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_25e3:
	/* 0x25e3: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_25e9:
	/* 0x25e9: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ee:
	/* 0x25ee: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_25f2:
	/* 0x25f2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_25f9:
	/* 0x25f9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_25fc:
	/* 0x25fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2601:
	/* 0x2601: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2606:
	/* 0x2606: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_260e:
	/* 0x260e: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2612:
	/* 0x2612: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2619:
	/* 0x2619: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_261e:
	/* 0x261e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2620:
	/* 0x2620: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2624:
	/* 0x2624: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_262c:
	/* 0x262c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_262f:
	/* 0x262f: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2637:
	/* 0x2637: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2640:
	/* 0x2640: lea    rdx,[rbp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2644:
	/* 0x2644: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2649:
	/* 0x2649: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_264e:
	/* 0x264e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2653:
	/* 0x2653: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2658:
	/* 0x2658: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265a:
	/* 0x265a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_265f:
	/* 0x265f: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_2661:
	/* 0x2661: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2664:
	/* 0x2664: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_266a:
	/* 0x266a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_266d:
	/* 0x266d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2673:
	/* 0x2673: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2679:
	/* 0x2679: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_267e:
	/* 0x267e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2682:
	/* 0x2682: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2689:
	/* 0x2689: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_268e:
	/* 0x268e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2693:
	/* 0x2693: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_269a:
	/* 0x269a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_269d:
	/* 0x269d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_26a4:
	/* 0x26a4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26a9:
	/* 0x26a9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_26ae:
	/* 0x26ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b0:
	/* 0x26b0: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26b3:
	/* 0x26b3: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_26b5:
	/* 0x26b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26b7:
	/* 0x26b7: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_26bd:
	/* 0x26bd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26c0:
	/* 0x26c0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_26c6:
	/* 0x26c6: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_26cc:
	/* 0x26cc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26d1:
	/* 0x26d1: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_26d5:
	/* 0x26d5: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_26dc:
	/* 0x26dc: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_26df:
	/* 0x26df: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26e4:
	/* 0x26e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26e9:
	/* 0x26e9: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26f1:
	/* 0x26f1: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_26f5:
	/* 0x26f5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_26fc:
	/* 0x26fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2701:
	/* 0x2701: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2703:
	/* 0x2703: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2707:
	/* 0x2707: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_270f:
	/* 0x270f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2712:
	/* 0x2712: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_271a:
	/* 0x271a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2723:
	/* 0x2723: lea    rdx,[rbp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2727:
	/* 0x2727: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_272c:
	/* 0x272c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2731:
	/* 0x2731: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2736:
	/* 0x2736: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_273b:
	/* 0x273b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273d:
	/* 0x273d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2742:
	/* 0x2742: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_2744:
	/* 0x2744: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2747:
	/* 0x2747: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_274d:
	/* 0x274d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2750:
	/* 0x2750: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2756:
	/* 0x2756: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_275c:
	/* 0x275c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2761:
	/* 0x2761: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2765:
	/* 0x2765: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_276c:
	/* 0x276c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2771:
	/* 0x2771: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2776:
	/* 0x2776: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_277d:
	/* 0x277d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2780:
	/* 0x2780: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2787:
	/* 0x2787: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_278c:
	/* 0x278c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2791:
	/* 0x2791: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2793:
	/* 0x2793: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2796:
	/* 0x2796: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_2798:
	/* 0x2798: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_279a:
	/* 0x279a: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_27a0:
	/* 0x27a0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27a3:
	/* 0x27a3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_27a9:
	/* 0x27a9: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_27af:
	/* 0x27af: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b4:
	/* 0x27b4: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_27b8:
	/* 0x27b8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_27bf:
	/* 0x27bf: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_27c2:
	/* 0x27c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27c7:
	/* 0x27c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27cc:
	/* 0x27cc: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27d4:
	/* 0x27d4: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_27d8:
	/* 0x27d8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_27df:
	/* 0x27df: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27e4:
	/* 0x27e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e6:
	/* 0x27e6: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27ea:
	/* 0x27ea: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_27f2:
	/* 0x27f2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_27f5:
	/* 0x27f5: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_27fd:
	/* 0x27fd: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2806:
	/* 0x2806: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_280a:
	/* 0x280a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_280f:
	/* 0x280f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2814:
	/* 0x2814: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2819:
	/* 0x2819: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_281e:
	/* 0x281e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2820:
	/* 0x2820: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2825:
	/* 0x2825: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_2827:
	/* 0x2827: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_282a:
	/* 0x282a: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2830:
	/* 0x2830: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2833:
	/* 0x2833: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2839:
	/* 0x2839: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_283f:
	/* 0x283f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2844:
	/* 0x2844: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2848:
	/* 0x2848: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_284f:
	/* 0x284f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2854:
	/* 0x2854: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2859:
	/* 0x2859: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2860:
	/* 0x2860: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2863:
	/* 0x2863: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_286a:
	/* 0x286a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_286f:
	/* 0x286f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2874:
	/* 0x2874: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2876:
	/* 0x2876: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2879:
	/* 0x2879: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_287b:
	/* 0x287b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_287d:
	/* 0x287d: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2883:
	/* 0x2883: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2886:
	/* 0x2886: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_288c:
	/* 0x288c: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2892:
	/* 0x2892: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2897:
	/* 0x2897: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_289b:
	/* 0x289b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_28a2:
	/* 0x28a2: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_28a5:
	/* 0x28a5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28aa:
	/* 0x28aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28af:
	/* 0x28af: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_28b7:
	/* 0x28b7: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_28bb:
	/* 0x28bb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_28c2:
	/* 0x28c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28c7:
	/* 0x28c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c9:
	/* 0x28c9: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28cd:
	/* 0x28cd: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_28d5:
	/* 0x28d5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_28d8:
	/* 0x28d8: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_28e0:
	/* 0x28e0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_28e9:
	/* 0x28e9: lea    rdx,[rbp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_28ed:
	/* 0x28ed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28f2:
	/* 0x28f2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28f7:
	/* 0x28f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28fc:
	/* 0x28fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2901:
	/* 0x2901: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2903:
	/* 0x2903: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2908:
	/* 0x2908: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_290a:
	/* 0x290a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_290d:
	/* 0x290d: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2913:
	/* 0x2913: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2916:
	/* 0x2916: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_291c:
	/* 0x291c: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2922:
	/* 0x2922: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2927:
	/* 0x2927: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_292b:
	/* 0x292b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2932:
	/* 0x2932: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2937:
	/* 0x2937: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_293c:
	/* 0x293c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2943:
	/* 0x2943: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2946:
	/* 0x2946: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_294d:
	/* 0x294d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2952:
	/* 0x2952: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2957:
	/* 0x2957: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2959:
	/* 0x2959: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295c:
	/* 0x295c: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_295e:
	/* 0x295e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2960:
	/* 0x2960: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2966:
	/* 0x2966: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2969:
	/* 0x2969: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_296f:
	/* 0x296f: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2975:
	/* 0x2975: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_297a:
	/* 0x297a: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_297e:
	/* 0x297e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2985:
	/* 0x2985: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2988:
	/* 0x2988: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_298d:
	/* 0x298d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2992:
	/* 0x2992: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_299a:
	/* 0x299a: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_299e:
	/* 0x299e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_29a5:
	/* 0x29a5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29aa:
	/* 0x29aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ac:
	/* 0x29ac: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29b0:
	/* 0x29b0: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_29b8:
	/* 0x29b8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_29bb:
	/* 0x29bb: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_29c3:
	/* 0x29c3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_29cc:
	/* 0x29cc: lea    rdx,[rbp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_29d3:
	/* 0x29d3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29d8:
	/* 0x29d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29dd:
	/* 0x29dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29e2:
	/* 0x29e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29e7:
	/* 0x29e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e9:
	/* 0x29e9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 10734ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10734ULL: goto x86_l_29ee;
	case 10736ULL: goto x86_l_29f0;
	case 10739ULL: goto x86_l_29f3;
	case 10745ULL: goto x86_l_29f9;
	case 10748ULL: goto x86_l_29fc;
	case 10754ULL: goto x86_l_2a02;
	case 10760ULL: goto x86_l_2a08;
	case 10765ULL: goto x86_l_2a0d;
	case 10769ULL: goto x86_l_2a11;
	case 10776ULL: goto x86_l_2a18;
	case 10781ULL: goto x86_l_2a1d;
	case 10786ULL: goto x86_l_2a22;
	case 10793ULL: goto x86_l_2a29;
	case 10796ULL: goto x86_l_2a2c;
	case 10803ULL: goto x86_l_2a33;
	case 10808ULL: goto x86_l_2a38;
	case 10813ULL: goto x86_l_2a3d;
	case 10815ULL: goto x86_l_2a3f;
	case 10818ULL: goto x86_l_2a42;
	case 10820ULL: goto x86_l_2a44;
	case 10822ULL: goto x86_l_2a46;
	case 10828ULL: goto x86_l_2a4c;
	case 10831ULL: goto x86_l_2a4f;
	case 10837ULL: goto x86_l_2a55;
	case 10843ULL: goto x86_l_2a5b;
	case 10848ULL: goto x86_l_2a60;
	case 10852ULL: goto x86_l_2a64;
	case 10859ULL: goto x86_l_2a6b;
	case 10862ULL: goto x86_l_2a6e;
	case 10867ULL: goto x86_l_2a73;
	case 10872ULL: goto x86_l_2a78;
	case 10880ULL: goto x86_l_2a80;
	case 10884ULL: goto x86_l_2a84;
	case 10891ULL: goto x86_l_2a8b;
	case 10896ULL: goto x86_l_2a90;
	case 10898ULL: goto x86_l_2a92;
	case 10902ULL: goto x86_l_2a96;
	case 10910ULL: goto x86_l_2a9e;
	case 10913ULL: goto x86_l_2aa1;
	case 10921ULL: goto x86_l_2aa9;
	case 10930ULL: goto x86_l_2ab2;
	case 10937ULL: goto x86_l_2ab9;
	case 10942ULL: goto x86_l_2abe;
	case 10947ULL: goto x86_l_2ac3;
	case 10952ULL: goto x86_l_2ac8;
	case 10957ULL: goto x86_l_2acd;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10966ULL: goto x86_l_2ad6;
	case 10969ULL: goto x86_l_2ad9;
	case 10975ULL: goto x86_l_2adf;
	case 10978ULL: goto x86_l_2ae2;
	case 10984ULL: goto x86_l_2ae8;
	case 10990ULL: goto x86_l_2aee;
	case 10995ULL: goto x86_l_2af3;
	case 10999ULL: goto x86_l_2af7;
	case 11006ULL: goto x86_l_2afe;
	case 11011ULL: goto x86_l_2b03;
	case 11016ULL: goto x86_l_2b08;
	case 11023ULL: goto x86_l_2b0f;
	case 11026ULL: goto x86_l_2b12;
	case 11033ULL: goto x86_l_2b19;
	case 11038ULL: goto x86_l_2b1e;
	case 11043ULL: goto x86_l_2b23;
	case 11045ULL: goto x86_l_2b25;
	case 11048ULL: goto x86_l_2b28;
	case 11050ULL: goto x86_l_2b2a;
	case 11052ULL: goto x86_l_2b2c;
	case 11058ULL: goto x86_l_2b32;
	case 11061ULL: goto x86_l_2b35;
	case 11067ULL: goto x86_l_2b3b;
	case 11073ULL: goto x86_l_2b41;
	case 11078ULL: goto x86_l_2b46;
	case 11082ULL: goto x86_l_2b4a;
	case 11089ULL: goto x86_l_2b51;
	case 11092ULL: goto x86_l_2b54;
	case 11097ULL: goto x86_l_2b59;
	case 11102ULL: goto x86_l_2b5e;
	case 11110ULL: goto x86_l_2b66;
	case 11114ULL: goto x86_l_2b6a;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11128ULL: goto x86_l_2b78;
	case 11132ULL: goto x86_l_2b7c;
	case 11140ULL: goto x86_l_2b84;
	case 11143ULL: goto x86_l_2b87;
	case 11151ULL: goto x86_l_2b8f;
	case 11160ULL: goto x86_l_2b98;
	case 11167ULL: goto x86_l_2b9f;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11182ULL: goto x86_l_2bae;
	case 11187ULL: goto x86_l_2bb3;
	case 11189ULL: goto x86_l_2bb5;
	case 11194ULL: goto x86_l_2bba;
	case 11196ULL: goto x86_l_2bbc;
	case 11199ULL: goto x86_l_2bbf;
	case 11205ULL: goto x86_l_2bc5;
	case 11208ULL: goto x86_l_2bc8;
	case 11214ULL: goto x86_l_2bce;
	case 11220ULL: goto x86_l_2bd4;
	case 11225ULL: goto x86_l_2bd9;
	case 11229ULL: goto x86_l_2bdd;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11246ULL: goto x86_l_2bee;
	case 11253ULL: goto x86_l_2bf5;
	case 11256ULL: goto x86_l_2bf8;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11273ULL: goto x86_l_2c09;
	case 11275ULL: goto x86_l_2c0b;
	case 11278ULL: goto x86_l_2c0e;
	case 11280ULL: goto x86_l_2c10;
	case 11282ULL: goto x86_l_2c12;
	case 11288ULL: goto x86_l_2c18;
	case 11291ULL: goto x86_l_2c1b;
	case 11297ULL: goto x86_l_2c21;
	case 11303ULL: goto x86_l_2c27;
	case 11308ULL: goto x86_l_2c2c;
	case 11312ULL: goto x86_l_2c30;
	case 11319ULL: goto x86_l_2c37;
	case 11322ULL: goto x86_l_2c3a;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11340ULL: goto x86_l_2c4c;
	case 11344ULL: goto x86_l_2c50;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11358ULL: goto x86_l_2c5e;
	case 11362ULL: goto x86_l_2c62;
	case 11370ULL: goto x86_l_2c6a;
	case 11373ULL: goto x86_l_2c6d;
	case 11381ULL: goto x86_l_2c75;
	case 11390ULL: goto x86_l_2c7e;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11407ULL: goto x86_l_2c8f;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11426ULL: goto x86_l_2ca2;
	case 11429ULL: goto x86_l_2ca5;
	case 11435ULL: goto x86_l_2cab;
	case 11438ULL: goto x86_l_2cae;
	case 11444ULL: goto x86_l_2cb4;
	case 11450ULL: goto x86_l_2cba;
	case 11455ULL: goto x86_l_2cbf;
	case 11459ULL: goto x86_l_2cc3;
	case 11466ULL: goto x86_l_2cca;
	case 11471ULL: goto x86_l_2ccf;
	case 11476ULL: goto x86_l_2cd4;
	case 11483ULL: goto x86_l_2cdb;
	case 11486ULL: goto x86_l_2cde;
	case 11493ULL: goto x86_l_2ce5;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11505ULL: goto x86_l_2cf1;
	case 11508ULL: goto x86_l_2cf4;
	case 11510ULL: goto x86_l_2cf6;
	case 11512ULL: goto x86_l_2cf8;
	case 11518ULL: goto x86_l_2cfe;
	case 11521ULL: goto x86_l_2d01;
	case 11527ULL: goto x86_l_2d07;
	case 11533ULL: goto x86_l_2d0d;
	case 11538ULL: goto x86_l_2d12;
	case 11542ULL: goto x86_l_2d16;
	case 11549ULL: goto x86_l_2d1d;
	case 11552ULL: goto x86_l_2d20;
	case 11557ULL: goto x86_l_2d25;
	case 11562ULL: goto x86_l_2d2a;
	case 11570ULL: goto x86_l_2d32;
	case 11574ULL: goto x86_l_2d36;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11588ULL: goto x86_l_2d44;
	case 11592ULL: goto x86_l_2d48;
	case 11600ULL: goto x86_l_2d50;
	case 11603ULL: goto x86_l_2d53;
	case 11611ULL: goto x86_l_2d5b;
	case 11620ULL: goto x86_l_2d64;
	case 11627ULL: goto x86_l_2d6b;
	case 11632ULL: goto x86_l_2d70;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11647ULL: goto x86_l_2d7f;
	case 11649ULL: goto x86_l_2d81;
	case 11654ULL: goto x86_l_2d86;
	case 11656ULL: goto x86_l_2d88;
	case 11659ULL: goto x86_l_2d8b;
	case 11665ULL: goto x86_l_2d91;
	case 11668ULL: goto x86_l_2d94;
	case 11674ULL: goto x86_l_2d9a;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11689ULL: goto x86_l_2da9;
	case 11696ULL: goto x86_l_2db0;
	case 11701ULL: goto x86_l_2db5;
	case 11706ULL: goto x86_l_2dba;
	case 11713ULL: goto x86_l_2dc1;
	case 11716ULL: goto x86_l_2dc4;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11735ULL: goto x86_l_2dd7;
	case 11738ULL: goto x86_l_2dda;
	case 11740ULL: goto x86_l_2ddc;
	case 11742ULL: goto x86_l_2dde;
	case 11748ULL: goto x86_l_2de4;
	case 11751ULL: goto x86_l_2de7;
	case 11757ULL: goto x86_l_2ded;
	case 11763ULL: goto x86_l_2df3;
	case 11768ULL: goto x86_l_2df8;
	case 11772ULL: goto x86_l_2dfc;
	case 11779ULL: goto x86_l_2e03;
	case 11782ULL: goto x86_l_2e06;
	case 11787ULL: goto x86_l_2e0b;
	case 11792ULL: goto x86_l_2e10;
	case 11800ULL: goto x86_l_2e18;
	case 11804ULL: goto x86_l_2e1c;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11822ULL: goto x86_l_2e2e;
	case 11830ULL: goto x86_l_2e36;
	case 11833ULL: goto x86_l_2e39;
	case 11841ULL: goto x86_l_2e41;
	case 11850ULL: goto x86_l_2e4a;
	case 11857ULL: goto x86_l_2e51;
	case 11862ULL: goto x86_l_2e56;
	case 11867ULL: goto x86_l_2e5b;
	case 11872ULL: goto x86_l_2e60;
	case 11877ULL: goto x86_l_2e65;
	case 11879ULL: goto x86_l_2e67;
	case 11884ULL: goto x86_l_2e6c;
	case 11886ULL: goto x86_l_2e6e;
	case 11889ULL: goto x86_l_2e71;
	case 11895ULL: goto x86_l_2e77;
	case 11898ULL: goto x86_l_2e7a;
	case 11904ULL: goto x86_l_2e80;
	case 11910ULL: goto x86_l_2e86;
	case 11915ULL: goto x86_l_2e8b;
	case 11919ULL: goto x86_l_2e8f;
	case 11926ULL: goto x86_l_2e96;
	case 11931ULL: goto x86_l_2e9b;
	case 11936ULL: goto x86_l_2ea0;
	case 11943ULL: goto x86_l_2ea7;
	case 11946ULL: goto x86_l_2eaa;
	case 11953ULL: goto x86_l_2eb1;
	case 11958ULL: goto x86_l_2eb6;
	case 11963ULL: goto x86_l_2ebb;
	case 11965ULL: goto x86_l_2ebd;
	case 11968ULL: goto x86_l_2ec0;
	case 11970ULL: goto x86_l_2ec2;
	case 11972ULL: goto x86_l_2ec4;
	case 11978ULL: goto x86_l_2eca;
	case 11981ULL: goto x86_l_2ecd;
	case 11987ULL: goto x86_l_2ed3;
	case 11993ULL: goto x86_l_2ed9;
	case 11998ULL: goto x86_l_2ede;
	case 12002ULL: goto x86_l_2ee2;
	case 12009ULL: goto x86_l_2ee9;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12030ULL: goto x86_l_2efe;
	case 12034ULL: goto x86_l_2f02;
	case 12041ULL: goto x86_l_2f09;
	case 12046ULL: goto x86_l_2f0e;
	case 12048ULL: goto x86_l_2f10;
	case 12052ULL: goto x86_l_2f14;
	case 12060ULL: goto x86_l_2f1c;
	case 12063ULL: goto x86_l_2f1f;
	case 12071ULL: goto x86_l_2f27;
	case 12080ULL: goto x86_l_2f30;
	case 12087ULL: goto x86_l_2f37;
	case 12092ULL: goto x86_l_2f3c;
	case 12097ULL: goto x86_l_2f41;
	case 12102ULL: goto x86_l_2f46;
	case 12107ULL: goto x86_l_2f4b;
	case 12109ULL: goto x86_l_2f4d;
	case 12114ULL: goto x86_l_2f52;
	case 12116ULL: goto x86_l_2f54;
	case 12119ULL: goto x86_l_2f57;
	case 12125ULL: goto x86_l_2f5d;
	case 12128ULL: goto x86_l_2f60;
	case 12134ULL: goto x86_l_2f66;
	case 12140ULL: goto x86_l_2f6c;
	case 12145ULL: goto x86_l_2f71;
	case 12149ULL: goto x86_l_2f75;
	case 12156ULL: goto x86_l_2f7c;
	case 12161ULL: goto x86_l_2f81;
	case 12166ULL: goto x86_l_2f86;
	case 12173ULL: goto x86_l_2f8d;
	case 12176ULL: goto x86_l_2f90;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12195ULL: goto x86_l_2fa3;
	case 12198ULL: goto x86_l_2fa6;
	case 12200ULL: goto x86_l_2fa8;
	case 12202ULL: goto x86_l_2faa;
	case 12208ULL: goto x86_l_2fb0;
	case 12211ULL: goto x86_l_2fb3;
	case 12217ULL: goto x86_l_2fb9;
	case 12223ULL: goto x86_l_2fbf;
	case 12228ULL: goto x86_l_2fc4;
	case 12232ULL: goto x86_l_2fc8;
	case 12239ULL: goto x86_l_2fcf;
	case 12242ULL: goto x86_l_2fd2;
	case 12247ULL: goto x86_l_2fd7;
	case 12252ULL: goto x86_l_2fdc;
	case 12260ULL: goto x86_l_2fe4;
	case 12264ULL: goto x86_l_2fe8;
	case 12271ULL: goto x86_l_2fef;
	case 12276ULL: goto x86_l_2ff4;
	case 12278ULL: goto x86_l_2ff6;
	case 12282ULL: goto x86_l_2ffa;
	case 12290ULL: goto x86_l_3002;
	case 12293ULL: goto x86_l_3005;
	case 12301ULL: goto x86_l_300d;
	case 12310ULL: goto x86_l_3016;
	case 12317ULL: goto x86_l_301d;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12346ULL: goto x86_l_303a;
	case 12349ULL: goto x86_l_303d;
	case 12355ULL: goto x86_l_3043;
	case 12358ULL: goto x86_l_3046;
	case 12364ULL: goto x86_l_304c;
	case 12370ULL: goto x86_l_3052;
	case 12375ULL: goto x86_l_3057;
	case 12379ULL: goto x86_l_305b;
	case 12386ULL: goto x86_l_3062;
	case 12391ULL: goto x86_l_3067;
	case 12396ULL: goto x86_l_306c;
	case 12403ULL: goto x86_l_3073;
	case 12406ULL: goto x86_l_3076;
	case 12413ULL: goto x86_l_307d;
	case 12418ULL: goto x86_l_3082;
	case 12423ULL: goto x86_l_3087;
	case 12425ULL: goto x86_l_3089;
	case 12428ULL: goto x86_l_308c;
	case 12430ULL: goto x86_l_308e;
	case 12432ULL: goto x86_l_3090;
	case 12438ULL: goto x86_l_3096;
	case 12441ULL: goto x86_l_3099;
	case 12447ULL: goto x86_l_309f;
	case 12453ULL: goto x86_l_30a5;
	case 12458ULL: goto x86_l_30aa;
	case 12462ULL: goto x86_l_30ae;
	case 12469ULL: goto x86_l_30b5;
	case 12472ULL: goto x86_l_30b8;
	case 12477ULL: goto x86_l_30bd;
	case 12482ULL: goto x86_l_30c2;
	case 12490ULL: goto x86_l_30ca;
	case 12494ULL: goto x86_l_30ce;
	case 12501ULL: goto x86_l_30d5;
	case 12506ULL: goto x86_l_30da;
	case 12508ULL: goto x86_l_30dc;
	case 12512ULL: goto x86_l_30e0;
	case 12520ULL: goto x86_l_30e8;
	case 12523ULL: goto x86_l_30eb;
	case 12531ULL: goto x86_l_30f3;
	case 12540ULL: goto x86_l_30fc;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12557ULL: goto x86_l_310d;
	case 12562ULL: goto x86_l_3112;
	case 12567ULL: goto x86_l_3117;
	case 12569ULL: goto x86_l_3119;
	case 12574ULL: goto x86_l_311e;
	case 12576ULL: goto x86_l_3120;
	case 12579ULL: goto x86_l_3123;
	case 12585ULL: goto x86_l_3129;
	case 12588ULL: goto x86_l_312c;
	case 12594ULL: goto x86_l_3132;
	case 12600ULL: goto x86_l_3138;
	case 12605ULL: goto x86_l_313d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29ee:
	/* 0x29ee: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_29f0:
	/* 0x29f0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_29f3:
	/* 0x29f3: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_29f9:
	/* 0x29f9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29fc:
	/* 0x29fc: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2a02:
	/* 0x2a02: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2a08:
	/* 0x2a08: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a0d:
	/* 0x2a0d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2a11:
	/* 0x2a11: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a18:
	/* 0x2a18: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a1d:
	/* 0x2a1d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2a22:
	/* 0x2a22: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a29:
	/* 0x2a29: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a2c:
	/* 0x2a2c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a33:
	/* 0x2a33: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a38:
	/* 0x2a38: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a3d:
	/* 0x2a3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3f:
	/* 0x2a3f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a42:
	/* 0x2a42: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_2a44:
	/* 0x2a44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a46:
	/* 0x2a46: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2a4c:
	/* 0x2a4c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a4f:
	/* 0x2a4f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2a55:
	/* 0x2a55: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2a5b:
	/* 0x2a5b: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a60:
	/* 0x2a60: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a64:
	/* 0x2a64: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2a6e:
	/* 0x2a6e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a73:
	/* 0x2a73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a78:
	/* 0x2a78: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a80:
	/* 0x2a80: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2a84:
	/* 0x2a84: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a8b:
	/* 0x2a8b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a90:
	/* 0x2a90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a92:
	/* 0x2a92: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a96:
	/* 0x2a96: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2a9e:
	/* 0x2a9e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2aa1:
	/* 0x2aa1: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2aa9:
	/* 0x2aa9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ab2:
	/* 0x2ab2: lea    rdx,[rbp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2ab9:
	/* 0x2ab9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2abe:
	/* 0x2abe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ac3:
	/* 0x2ac3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ac8:
	/* 0x2ac8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2acd:
	/* 0x2acd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2acf:
	/* 0x2acf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ad4:
	/* 0x2ad4: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2ad6:
	/* 0x2ad6: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2ad9:
	/* 0x2ad9: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2adf:
	/* 0x2adf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ae2:
	/* 0x2ae2: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2ae8:
	/* 0x2ae8: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2aee:
	/* 0x2aee: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2af3:
	/* 0x2af3: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2af7:
	/* 0x2af7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2afe:
	/* 0x2afe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b03:
	/* 0x2b03: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2b08:
	/* 0x2b08: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b0f:
	/* 0x2b0f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b12:
	/* 0x2b12: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2b19:
	/* 0x2b19: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b1e:
	/* 0x2b1e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b23:
	/* 0x2b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b25:
	/* 0x2b25: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b28:
	/* 0x2b28: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2b2a:
	/* 0x2b2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b2c:
	/* 0x2b2c: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2b32:
	/* 0x2b32: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b35:
	/* 0x2b35: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2b3b:
	/* 0x2b3b: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2b41:
	/* 0x2b41: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b46:
	/* 0x2b46: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2b4a:
	/* 0x2b4a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b51:
	/* 0x2b51: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2b54:
	/* 0x2b54: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b59:
	/* 0x2b59: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b5e:
	/* 0x2b5e: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b66:
	/* 0x2b66: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2b6a:
	/* 0x2b6a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b71:
	/* 0x2b71: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b76:
	/* 0x2b76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b78:
	/* 0x2b78: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b7c:
	/* 0x2b7c: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b84:
	/* 0x2b84: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2b87:
	/* 0x2b87: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b8f:
	/* 0x2b8f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b98:
	/* 0x2b98: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b9f:
	/* 0x2b9f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba4:
	/* 0x2ba4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ba9:
	/* 0x2ba9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bae:
	/* 0x2bae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bb3:
	/* 0x2bb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb5:
	/* 0x2bb5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bba:
	/* 0x2bba: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_2bbc:
	/* 0x2bbc: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2bbf:
	/* 0x2bbf: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2bc5:
	/* 0x2bc5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bc8:
	/* 0x2bc8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2bce:
	/* 0x2bce: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2bd4:
	/* 0x2bd4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bd9:
	/* 0x2bd9: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2bdd:
	/* 0x2bdd: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2be4:
	/* 0x2be4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2be9:
	/* 0x2be9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2bee:
	/* 0x2bee: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bf5:
	/* 0x2bf5: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bf8:
	/* 0x2bf8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2bff:
	/* 0x2bff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c04:
	/* 0x2c04: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c09:
	/* 0x2c09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c0b:
	/* 0x2c0b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c0e:
	/* 0x2c0e: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_2c10:
	/* 0x2c10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c12:
	/* 0x2c12: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2c18:
	/* 0x2c18: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c1b:
	/* 0x2c1b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2c21:
	/* 0x2c21: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2c27:
	/* 0x2c27: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c2c:
	/* 0x2c2c: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2c30:
	/* 0x2c30: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c37:
	/* 0x2c37: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2c3a:
	/* 0x2c3a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c3f:
	/* 0x2c3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c44:
	/* 0x2c44: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c4c:
	/* 0x2c4c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c50:
	/* 0x2c50: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c57:
	/* 0x2c57: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c5c:
	/* 0x2c5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5e:
	/* 0x2c5e: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c62:
	/* 0x2c62: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c6a:
	/* 0x2c6a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c6d:
	/* 0x2c6d: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c75:
	/* 0x2c75: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c7e:
	/* 0x2c7e: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2c85:
	/* 0x2c85: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c94:
	/* 0x2c94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c99:
	/* 0x2c99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9b:
	/* 0x2c9b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_2ca2:
	/* 0x2ca2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2ca5:
	/* 0x2ca5: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2cab:
	/* 0x2cab: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cae:
	/* 0x2cae: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2cb4:
	/* 0x2cb4: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2cba:
	/* 0x2cba: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cbf:
	/* 0x2cbf: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2cc3:
	/* 0x2cc3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2cca:
	/* 0x2cca: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ccf:
	/* 0x2ccf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2cd4:
	/* 0x2cd4: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2cdb:
	/* 0x2cdb: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cde:
	/* 0x2cde: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ce5:
	/* 0x2ce5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cea:
	/* 0x2cea: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2cef:
	/* 0x2cef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf1:
	/* 0x2cf1: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf4:
	/* 0x2cf4: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_2cf6:
	/* 0x2cf6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cf8:
	/* 0x2cf8: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2cfe:
	/* 0x2cfe: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d01:
	/* 0x2d01: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2d07:
	/* 0x2d07: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2d0d:
	/* 0x2d0d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d12:
	/* 0x2d12: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2d16:
	/* 0x2d16: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d1d:
	/* 0x2d1d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2d20:
	/* 0x2d20: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d25:
	/* 0x2d25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d2a:
	/* 0x2d2a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d32:
	/* 0x2d32: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d36:
	/* 0x2d36: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d42:
	/* 0x2d42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d44:
	/* 0x2d44: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d48:
	/* 0x2d48: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2d50:
	/* 0x2d50: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2d53:
	/* 0x2d53: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d64:
	/* 0x2d64: lea    rdx,[rbp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2d6b:
	/* 0x2d6b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d70:
	/* 0x2d70: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d75:
	/* 0x2d75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d7a:
	/* 0x2d7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d7f:
	/* 0x2d7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d81:
	/* 0x2d81: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d86:
	/* 0x2d86: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_2d88:
	/* 0x2d88: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2d8b:
	/* 0x2d8b: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2d91:
	/* 0x2d91: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d94:
	/* 0x2d94: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2d9a:
	/* 0x2d9a: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2da0:
	/* 0x2da0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da5:
	/* 0x2da5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2da9:
	/* 0x2da9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2db0:
	/* 0x2db0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2db5:
	/* 0x2db5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2dba:
	/* 0x2dba: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2dc1:
	/* 0x2dc1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2dc4:
	/* 0x2dc4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2dcb:
	/* 0x2dcb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dd0:
	/* 0x2dd0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2dd5:
	/* 0x2dd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd7:
	/* 0x2dd7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dda:
	/* 0x2dda: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_2ddc:
	/* 0x2ddc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dde:
	/* 0x2dde: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2de4:
	/* 0x2de4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2de7:
	/* 0x2de7: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2ded:
	/* 0x2ded: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2df3:
	/* 0x2df3: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2df8:
	/* 0x2df8: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2dfc:
	/* 0x2dfc: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e03:
	/* 0x2e03: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2e06:
	/* 0x2e06: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e0b:
	/* 0x2e0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e10:
	/* 0x2e10: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e18:
	/* 0x2e18: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e1c:
	/* 0x2e1c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e23:
	/* 0x2e23: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e28:
	/* 0x2e28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2a:
	/* 0x2e2a: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e2e:
	/* 0x2e2e: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2e36:
	/* 0x2e36: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2e39:
	/* 0x2e39: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e41:
	/* 0x2e41: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e4a:
	/* 0x2e4a: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2e51:
	/* 0x2e51: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e56:
	/* 0x2e56: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e5b:
	/* 0x2e5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e60:
	/* 0x2e60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e65:
	/* 0x2e65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e67:
	/* 0x2e67: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e6c:
	/* 0x2e6c: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_2e6e:
	/* 0x2e6e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2e71:
	/* 0x2e71: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2e77:
	/* 0x2e77: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e7a:
	/* 0x2e7a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2e80:
	/* 0x2e80: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2e86:
	/* 0x2e86: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e8b:
	/* 0x2e8b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2e8f:
	/* 0x2e8f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e96:
	/* 0x2e96: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e9b:
	/* 0x2e9b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ea0:
	/* 0x2ea0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ea7:
	/* 0x2ea7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2eaa:
	/* 0x2eaa: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2eb1:
	/* 0x2eb1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eb6:
	/* 0x2eb6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ebb:
	/* 0x2ebb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ebd:
	/* 0x2ebd: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec0:
	/* 0x2ec0: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_2ec2:
	/* 0x2ec2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ec4:
	/* 0x2ec4: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2eca:
	/* 0x2eca: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ecd:
	/* 0x2ecd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2ed3:
	/* 0x2ed3: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2ed9:
	/* 0x2ed9: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ede:
	/* 0x2ede: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2ee2:
	/* 0x2ee2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ee9:
	/* 0x2ee9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2eec:
	/* 0x2eec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ef1:
	/* 0x2ef1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ef6:
	/* 0x2ef6: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2efe:
	/* 0x2efe: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f02:
	/* 0x2f02: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f09:
	/* 0x2f09: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f0e:
	/* 0x2f0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f10:
	/* 0x2f10: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f14:
	/* 0x2f14: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2f1c:
	/* 0x2f1c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2f1f:
	/* 0x2f1f: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f27:
	/* 0x2f27: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f30:
	/* 0x2f30: lea    rdx,[rbp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2f37:
	/* 0x2f37: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f3c:
	/* 0x2f3c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f41:
	/* 0x2f41: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f46:
	/* 0x2f46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f4b:
	/* 0x2f4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f4d:
	/* 0x2f4d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f52:
	/* 0x2f52: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2f54:
	/* 0x2f54: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2f57:
	/* 0x2f57: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_2f5d:
	/* 0x2f5d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f60:
	/* 0x2f60: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2f66:
	/* 0x2f66: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2f6c:
	/* 0x2f6c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f71:
	/* 0x2f71: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2f75:
	/* 0x2f75: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f7c:
	/* 0x2f7c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f81:
	/* 0x2f81: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2f86:
	/* 0x2f86: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f8d:
	/* 0x2f8d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f90:
	/* 0x2f90: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f97:
	/* 0x2f97: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f9c:
	/* 0x2f9c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2fa1:
	/* 0x2fa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fa3:
	/* 0x2fa3: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa6:
	/* 0x2fa6: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2fa8:
	/* 0x2fa8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2faa:
	/* 0x2faa: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_2fb0:
	/* 0x2fb0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fb3:
	/* 0x2fb3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2fb9:
	/* 0x2fb9: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_2fbf:
	/* 0x2fbf: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fc4:
	/* 0x2fc4: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2fc8:
	/* 0x2fc8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2fcf:
	/* 0x2fcf: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2fd2:
	/* 0x2fd2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2fd7:
	/* 0x2fd7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fdc:
	/* 0x2fdc: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2fe4:
	/* 0x2fe4: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2fe8:
	/* 0x2fe8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2fef:
	/* 0x2fef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ff4:
	/* 0x2ff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff6:
	/* 0x2ff6: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ffa:
	/* 0x2ffa: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3002:
	/* 0x3002: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3005:
	/* 0x3005: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_300d:
	/* 0x300d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3016:
	/* 0x3016: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_301d:
	/* 0x301d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3022:
	/* 0x3022: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3027:
	/* 0x3027: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_302c:
	/* 0x302c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3031:
	/* 0x3031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3033:
	/* 0x3033: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3038:
	/* 0x3038: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_303a:
	/* 0x303a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_303d:
	/* 0x303d: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_3043:
	/* 0x3043: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3046:
	/* 0x3046: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_304c:
	/* 0x304c: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3052:
	/* 0x3052: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3057:
	/* 0x3057: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_305b:
	/* 0x305b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3062:
	/* 0x3062: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3067:
	/* 0x3067: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_306c:
	/* 0x306c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3073:
	/* 0x3073: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3076:
	/* 0x3076: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_307d:
	/* 0x307d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3082:
	/* 0x3082: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3087:
	/* 0x3087: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3089:
	/* 0x3089: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_308c:
	/* 0x308c: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_308e:
	/* 0x308e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3090:
	/* 0x3090: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3096:
	/* 0x3096: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3099:
	/* 0x3099: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_309f:
	/* 0x309f: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_30a5:
	/* 0x30a5: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30aa:
	/* 0x30aa: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_30ae:
	/* 0x30ae: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_30b5:
	/* 0x30b5: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_30b8:
	/* 0x30b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30bd:
	/* 0x30bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30c2:
	/* 0x30c2: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30ca:
	/* 0x30ca: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_30ce:
	/* 0x30ce: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_30d5:
	/* 0x30d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30da:
	/* 0x30da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30dc:
	/* 0x30dc: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30e0:
	/* 0x30e0: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_30e8:
	/* 0x30e8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_30eb:
	/* 0x30eb: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_30f3:
	/* 0x30f3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_30fc:
	/* 0x30fc: lea    rdx,[rbp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3103:
	/* 0x3103: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3108:
	/* 0x3108: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_310d:
	/* 0x310d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3112:
	/* 0x3112: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3117:
	/* 0x3117: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3119:
	/* 0x3119: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_311e:
	/* 0x311e: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3120:
	/* 0x3120: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3123:
	/* 0x3123: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_3129:
	/* 0x3129: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_312c:
	/* 0x312c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3132:
	/* 0x3132: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3138:
	/* 0x3138: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_313d:
	/* 0x313d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
	return 12609ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12609ULL: goto x86_l_3141;
	case 12616ULL: goto x86_l_3148;
	case 12621ULL: goto x86_l_314d;
	case 12626ULL: goto x86_l_3152;
	case 12633ULL: goto x86_l_3159;
	case 12636ULL: goto x86_l_315c;
	case 12643ULL: goto x86_l_3163;
	case 12648ULL: goto x86_l_3168;
	case 12653ULL: goto x86_l_316d;
	case 12655ULL: goto x86_l_316f;
	case 12658ULL: goto x86_l_3172;
	case 12660ULL: goto x86_l_3174;
	case 12662ULL: goto x86_l_3176;
	case 12668ULL: goto x86_l_317c;
	case 12671ULL: goto x86_l_317f;
	case 12677ULL: goto x86_l_3185;
	case 12683ULL: goto x86_l_318b;
	case 12688ULL: goto x86_l_3190;
	case 12692ULL: goto x86_l_3194;
	case 12699ULL: goto x86_l_319b;
	case 12702ULL: goto x86_l_319e;
	case 12707ULL: goto x86_l_31a3;
	case 12712ULL: goto x86_l_31a8;
	case 12720ULL: goto x86_l_31b0;
	case 12724ULL: goto x86_l_31b4;
	case 12731ULL: goto x86_l_31bb;
	case 12736ULL: goto x86_l_31c0;
	case 12738ULL: goto x86_l_31c2;
	case 12742ULL: goto x86_l_31c6;
	case 12750ULL: goto x86_l_31ce;
	case 12753ULL: goto x86_l_31d1;
	case 12761ULL: goto x86_l_31d9;
	case 12770ULL: goto x86_l_31e2;
	case 12777ULL: goto x86_l_31e9;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12792ULL: goto x86_l_31f8;
	case 12797ULL: goto x86_l_31fd;
	case 12799ULL: goto x86_l_31ff;
	case 12804ULL: goto x86_l_3204;
	case 12806ULL: goto x86_l_3206;
	case 12809ULL: goto x86_l_3209;
	case 12815ULL: goto x86_l_320f;
	case 12818ULL: goto x86_l_3212;
	case 12824ULL: goto x86_l_3218;
	case 12830ULL: goto x86_l_321e;
	case 12835ULL: goto x86_l_3223;
	case 12839ULL: goto x86_l_3227;
	case 12846ULL: goto x86_l_322e;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12863ULL: goto x86_l_323f;
	case 12866ULL: goto x86_l_3242;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12883ULL: goto x86_l_3253;
	case 12885ULL: goto x86_l_3255;
	case 12888ULL: goto x86_l_3258;
	case 12890ULL: goto x86_l_325a;
	case 12892ULL: goto x86_l_325c;
	case 12898ULL: goto x86_l_3262;
	case 12901ULL: goto x86_l_3265;
	case 12907ULL: goto x86_l_326b;
	case 12913ULL: goto x86_l_3271;
	case 12918ULL: goto x86_l_3276;
	case 12922ULL: goto x86_l_327a;
	case 12929ULL: goto x86_l_3281;
	case 12932ULL: goto x86_l_3284;
	case 12937ULL: goto x86_l_3289;
	case 12942ULL: goto x86_l_328e;
	case 12950ULL: goto x86_l_3296;
	case 12954ULL: goto x86_l_329a;
	case 12961ULL: goto x86_l_32a1;
	case 12966ULL: goto x86_l_32a6;
	case 12968ULL: goto x86_l_32a8;
	case 12972ULL: goto x86_l_32ac;
	case 12980ULL: goto x86_l_32b4;
	case 12983ULL: goto x86_l_32b7;
	case 12991ULL: goto x86_l_32bf;
	case 13000ULL: goto x86_l_32c8;
	case 13007ULL: goto x86_l_32cf;
	case 13012ULL: goto x86_l_32d4;
	case 13017ULL: goto x86_l_32d9;
	case 13022ULL: goto x86_l_32de;
	case 13027ULL: goto x86_l_32e3;
	case 13029ULL: goto x86_l_32e5;
	case 13034ULL: goto x86_l_32ea;
	case 13036ULL: goto x86_l_32ec;
	case 13039ULL: goto x86_l_32ef;
	case 13045ULL: goto x86_l_32f5;
	case 13048ULL: goto x86_l_32f8;
	case 13054ULL: goto x86_l_32fe;
	case 13060ULL: goto x86_l_3304;
	case 13065ULL: goto x86_l_3309;
	case 13069ULL: goto x86_l_330d;
	case 13076ULL: goto x86_l_3314;
	case 13081ULL: goto x86_l_3319;
	case 13086ULL: goto x86_l_331e;
	case 13093ULL: goto x86_l_3325;
	case 13096ULL: goto x86_l_3328;
	case 13103ULL: goto x86_l_332f;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13115ULL: goto x86_l_333b;
	case 13118ULL: goto x86_l_333e;
	case 13120ULL: goto x86_l_3340;
	case 13122ULL: goto x86_l_3342;
	case 13128ULL: goto x86_l_3348;
	case 13131ULL: goto x86_l_334b;
	case 13137ULL: goto x86_l_3351;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13152ULL: goto x86_l_3360;
	case 13159ULL: goto x86_l_3367;
	case 13162ULL: goto x86_l_336a;
	case 13167ULL: goto x86_l_336f;
	case 13172ULL: goto x86_l_3374;
	case 13180ULL: goto x86_l_337c;
	case 13184ULL: goto x86_l_3380;
	case 13191ULL: goto x86_l_3387;
	case 13196ULL: goto x86_l_338c;
	case 13198ULL: goto x86_l_338e;
	case 13202ULL: goto x86_l_3392;
	case 13210ULL: goto x86_l_339a;
	case 13213ULL: goto x86_l_339d;
	case 13221ULL: goto x86_l_33a5;
	case 13230ULL: goto x86_l_33ae;
	case 13237ULL: goto x86_l_33b5;
	case 13242ULL: goto x86_l_33ba;
	case 13247ULL: goto x86_l_33bf;
	case 13252ULL: goto x86_l_33c4;
	case 13257ULL: goto x86_l_33c9;
	case 13259ULL: goto x86_l_33cb;
	case 13264ULL: goto x86_l_33d0;
	case 13266ULL: goto x86_l_33d2;
	case 13269ULL: goto x86_l_33d5;
	case 13275ULL: goto x86_l_33db;
	case 13278ULL: goto x86_l_33de;
	case 13284ULL: goto x86_l_33e4;
	case 13290ULL: goto x86_l_33ea;
	case 13295ULL: goto x86_l_33ef;
	case 13299ULL: goto x86_l_33f3;
	case 13306ULL: goto x86_l_33fa;
	case 13311ULL: goto x86_l_33ff;
	case 13316ULL: goto x86_l_3404;
	case 13323ULL: goto x86_l_340b;
	case 13326ULL: goto x86_l_340e;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13343ULL: goto x86_l_341f;
	case 13345ULL: goto x86_l_3421;
	case 13348ULL: goto x86_l_3424;
	case 13350ULL: goto x86_l_3426;
	case 13352ULL: goto x86_l_3428;
	case 13358ULL: goto x86_l_342e;
	case 13361ULL: goto x86_l_3431;
	case 13367ULL: goto x86_l_3437;
	case 13373ULL: goto x86_l_343d;
	case 13378ULL: goto x86_l_3442;
	case 13382ULL: goto x86_l_3446;
	case 13389ULL: goto x86_l_344d;
	case 13392ULL: goto x86_l_3450;
	case 13397ULL: goto x86_l_3455;
	case 13402ULL: goto x86_l_345a;
	case 13410ULL: goto x86_l_3462;
	case 13414ULL: goto x86_l_3466;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13428ULL: goto x86_l_3474;
	case 13432ULL: goto x86_l_3478;
	case 13440ULL: goto x86_l_3480;
	case 13443ULL: goto x86_l_3483;
	case 13451ULL: goto x86_l_348b;
	case 13460ULL: goto x86_l_3494;
	case 13467ULL: goto x86_l_349b;
	case 13472ULL: goto x86_l_34a0;
	case 13477ULL: goto x86_l_34a5;
	case 13482ULL: goto x86_l_34aa;
	case 13487ULL: goto x86_l_34af;
	case 13489ULL: goto x86_l_34b1;
	case 13494ULL: goto x86_l_34b6;
	case 13496ULL: goto x86_l_34b8;
	case 13499ULL: goto x86_l_34bb;
	case 13505ULL: goto x86_l_34c1;
	case 13508ULL: goto x86_l_34c4;
	case 13514ULL: goto x86_l_34ca;
	case 13520ULL: goto x86_l_34d0;
	case 13525ULL: goto x86_l_34d5;
	case 13529ULL: goto x86_l_34d9;
	case 13536ULL: goto x86_l_34e0;
	case 13541ULL: goto x86_l_34e5;
	case 13546ULL: goto x86_l_34ea;
	case 13553ULL: goto x86_l_34f1;
	case 13556ULL: goto x86_l_34f4;
	case 13563ULL: goto x86_l_34fb;
	case 13568ULL: goto x86_l_3500;
	case 13573ULL: goto x86_l_3505;
	case 13575ULL: goto x86_l_3507;
	case 13578ULL: goto x86_l_350a;
	case 13580ULL: goto x86_l_350c;
	case 13582ULL: goto x86_l_350e;
	case 13588ULL: goto x86_l_3514;
	case 13591ULL: goto x86_l_3517;
	case 13597ULL: goto x86_l_351d;
	case 13603ULL: goto x86_l_3523;
	case 13608ULL: goto x86_l_3528;
	case 13612ULL: goto x86_l_352c;
	case 13619ULL: goto x86_l_3533;
	case 13622ULL: goto x86_l_3536;
	case 13627ULL: goto x86_l_353b;
	case 13632ULL: goto x86_l_3540;
	case 13640ULL: goto x86_l_3548;
	case 13644ULL: goto x86_l_354c;
	case 13651ULL: goto x86_l_3553;
	case 13656ULL: goto x86_l_3558;
	case 13658ULL: goto x86_l_355a;
	case 13662ULL: goto x86_l_355e;
	case 13670ULL: goto x86_l_3566;
	case 13673ULL: goto x86_l_3569;
	case 13681ULL: goto x86_l_3571;
	case 13690ULL: goto x86_l_357a;
	case 13697ULL: goto x86_l_3581;
	case 13702ULL: goto x86_l_3586;
	case 13707ULL: goto x86_l_358b;
	case 13712ULL: goto x86_l_3590;
	case 13717ULL: goto x86_l_3595;
	case 13719ULL: goto x86_l_3597;
	case 13724ULL: goto x86_l_359c;
	case 13726ULL: goto x86_l_359e;
	case 13729ULL: goto x86_l_35a1;
	case 13735ULL: goto x86_l_35a7;
	case 13738ULL: goto x86_l_35aa;
	case 13744ULL: goto x86_l_35b0;
	case 13750ULL: goto x86_l_35b6;
	case 13755ULL: goto x86_l_35bb;
	case 13759ULL: goto x86_l_35bf;
	case 13766ULL: goto x86_l_35c6;
	case 13771ULL: goto x86_l_35cb;
	case 13776ULL: goto x86_l_35d0;
	case 13783ULL: goto x86_l_35d7;
	case 13786ULL: goto x86_l_35da;
	case 13793ULL: goto x86_l_35e1;
	case 13798ULL: goto x86_l_35e6;
	case 13803ULL: goto x86_l_35eb;
	case 13805ULL: goto x86_l_35ed;
	case 13808ULL: goto x86_l_35f0;
	case 13810ULL: goto x86_l_35f2;
	case 13812ULL: goto x86_l_35f4;
	case 13818ULL: goto x86_l_35fa;
	case 13821ULL: goto x86_l_35fd;
	case 13827ULL: goto x86_l_3603;
	case 13833ULL: goto x86_l_3609;
	case 13838ULL: goto x86_l_360e;
	case 13842ULL: goto x86_l_3612;
	case 13849ULL: goto x86_l_3619;
	case 13852ULL: goto x86_l_361c;
	case 13857ULL: goto x86_l_3621;
	case 13862ULL: goto x86_l_3626;
	case 13870ULL: goto x86_l_362e;
	case 13874ULL: goto x86_l_3632;
	case 13881ULL: goto x86_l_3639;
	case 13886ULL: goto x86_l_363e;
	case 13888ULL: goto x86_l_3640;
	case 13892ULL: goto x86_l_3644;
	case 13900ULL: goto x86_l_364c;
	case 13903ULL: goto x86_l_364f;
	case 13911ULL: goto x86_l_3657;
	case 13920ULL: goto x86_l_3660;
	case 13927ULL: goto x86_l_3667;
	case 13932ULL: goto x86_l_366c;
	case 13937ULL: goto x86_l_3671;
	case 13942ULL: goto x86_l_3676;
	case 13947ULL: goto x86_l_367b;
	case 13949ULL: goto x86_l_367d;
	case 13954ULL: goto x86_l_3682;
	case 13956ULL: goto x86_l_3684;
	case 13959ULL: goto x86_l_3687;
	case 13965ULL: goto x86_l_368d;
	case 13968ULL: goto x86_l_3690;
	case 13974ULL: goto x86_l_3696;
	case 13980ULL: goto x86_l_369c;
	case 13985ULL: goto x86_l_36a1;
	case 13989ULL: goto x86_l_36a5;
	case 13996ULL: goto x86_l_36ac;
	case 14001ULL: goto x86_l_36b1;
	case 14006ULL: goto x86_l_36b6;
	case 14013ULL: goto x86_l_36bd;
	case 14016ULL: goto x86_l_36c0;
	case 14023ULL: goto x86_l_36c7;
	case 14028ULL: goto x86_l_36cc;
	case 14033ULL: goto x86_l_36d1;
	case 14035ULL: goto x86_l_36d3;
	case 14038ULL: goto x86_l_36d6;
	case 14040ULL: goto x86_l_36d8;
	case 14042ULL: goto x86_l_36da;
	case 14048ULL: goto x86_l_36e0;
	case 14051ULL: goto x86_l_36e3;
	case 14057ULL: goto x86_l_36e9;
	case 14063ULL: goto x86_l_36ef;
	case 14068ULL: goto x86_l_36f4;
	case 14072ULL: goto x86_l_36f8;
	case 14079ULL: goto x86_l_36ff;
	case 14082ULL: goto x86_l_3702;
	case 14087ULL: goto x86_l_3707;
	case 14092ULL: goto x86_l_370c;
	case 14100ULL: goto x86_l_3714;
	case 14104ULL: goto x86_l_3718;
	case 14111ULL: goto x86_l_371f;
	case 14116ULL: goto x86_l_3724;
	case 14118ULL: goto x86_l_3726;
	case 14122ULL: goto x86_l_372a;
	case 14130ULL: goto x86_l_3732;
	case 14133ULL: goto x86_l_3735;
	case 14141ULL: goto x86_l_373d;
	case 14150ULL: goto x86_l_3746;
	case 14157ULL: goto x86_l_374d;
	case 14162ULL: goto x86_l_3752;
	case 14167ULL: goto x86_l_3757;
	case 14172ULL: goto x86_l_375c;
	case 14177ULL: goto x86_l_3761;
	case 14179ULL: goto x86_l_3763;
	case 14184ULL: goto x86_l_3768;
	case 14186ULL: goto x86_l_376a;
	case 14189ULL: goto x86_l_376d;
	case 14195ULL: goto x86_l_3773;
	case 14198ULL: goto x86_l_3776;
	case 14204ULL: goto x86_l_377c;
	case 14210ULL: goto x86_l_3782;
	case 14215ULL: goto x86_l_3787;
	case 14219ULL: goto x86_l_378b;
	case 14226ULL: goto x86_l_3792;
	case 14231ULL: goto x86_l_3797;
	case 14236ULL: goto x86_l_379c;
	case 14243ULL: goto x86_l_37a3;
	case 14246ULL: goto x86_l_37a6;
	case 14253ULL: goto x86_l_37ad;
	case 14258ULL: goto x86_l_37b2;
	case 14263ULL: goto x86_l_37b7;
	case 14265ULL: goto x86_l_37b9;
	case 14268ULL: goto x86_l_37bc;
	case 14270ULL: goto x86_l_37be;
	case 14272ULL: goto x86_l_37c0;
	case 14278ULL: goto x86_l_37c6;
	case 14281ULL: goto x86_l_37c9;
	case 14287ULL: goto x86_l_37cf;
	case 14293ULL: goto x86_l_37d5;
	case 14298ULL: goto x86_l_37da;
	case 14302ULL: goto x86_l_37de;
	case 14309ULL: goto x86_l_37e5;
	case 14312ULL: goto x86_l_37e8;
	case 14317ULL: goto x86_l_37ed;
	case 14322ULL: goto x86_l_37f2;
	case 14330ULL: goto x86_l_37fa;
	case 14334ULL: goto x86_l_37fe;
	case 14341ULL: goto x86_l_3805;
	case 14346ULL: goto x86_l_380a;
	case 14348ULL: goto x86_l_380c;
	case 14352ULL: goto x86_l_3810;
	case 14360ULL: goto x86_l_3818;
	case 14363ULL: goto x86_l_381b;
	case 14371ULL: goto x86_l_3823;
	case 14380ULL: goto x86_l_382c;
	case 14387ULL: goto x86_l_3833;
	case 14392ULL: goto x86_l_3838;
	case 14397ULL: goto x86_l_383d;
	case 14402ULL: goto x86_l_3842;
	case 14407ULL: goto x86_l_3847;
	case 14409ULL: goto x86_l_3849;
	case 14414ULL: goto x86_l_384e;
	case 14416ULL: goto x86_l_3850;
	case 14419ULL: goto x86_l_3853;
	case 14425ULL: goto x86_l_3859;
	case 14428ULL: goto x86_l_385c;
	case 14434ULL: goto x86_l_3862;
	case 14440ULL: goto x86_l_3868;
	case 14445ULL: goto x86_l_386d;
	case 14449ULL: goto x86_l_3871;
	case 14456ULL: goto x86_l_3878;
	case 14461ULL: goto x86_l_387d;
	case 14466ULL: goto x86_l_3882;
	case 14473ULL: goto x86_l_3889;
	case 14476ULL: goto x86_l_388c;
	case 14483ULL: goto x86_l_3893;
	case 14488ULL: goto x86_l_3898;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3141:
	/* 0x3141: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3148:
	/* 0x3148: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_314d:
	/* 0x314d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3152:
	/* 0x3152: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3159:
	/* 0x3159: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_315c:
	/* 0x315c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3163:
	/* 0x3163: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3168:
	/* 0x3168: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_316d:
	/* 0x316d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_316f:
	/* 0x316f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3172:
	/* 0x3172: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3174:
	/* 0x3174: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3176:
	/* 0x3176: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_317c:
	/* 0x317c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_317f:
	/* 0x317f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3185:
	/* 0x3185: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_318b:
	/* 0x318b: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3190:
	/* 0x3190: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3194:
	/* 0x3194: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_319b:
	/* 0x319b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_319e:
	/* 0x319e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31a3:
	/* 0x31a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31a8:
	/* 0x31a8: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31b0:
	/* 0x31b0: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_31b4:
	/* 0x31b4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_31bb:
	/* 0x31bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31c0:
	/* 0x31c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c2:
	/* 0x31c2: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31c6:
	/* 0x31c6: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_31ce:
	/* 0x31ce: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_31d1:
	/* 0x31d1: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_31d9:
	/* 0x31d9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_31e2:
	/* 0x31e2: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_31e9:
	/* 0x31e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ee:
	/* 0x31ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31f3:
	/* 0x31f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31f8:
	/* 0x31f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31fd:
	/* 0x31fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ff:
	/* 0x31ff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3204:
	/* 0x3204: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3206:
	/* 0x3206: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3209:
	/* 0x3209: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_320f:
	/* 0x320f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3212:
	/* 0x3212: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3218:
	/* 0x3218: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_321e:
	/* 0x321e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3223:
	/* 0x3223: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3227:
	/* 0x3227: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_322e:
	/* 0x322e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3233:
	/* 0x3233: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3238:
	/* 0x3238: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_323f:
	/* 0x323f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3242:
	/* 0x3242: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3249:
	/* 0x3249: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_324e:
	/* 0x324e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3253:
	/* 0x3253: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3255:
	/* 0x3255: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3258:
	/* 0x3258: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_325a:
	/* 0x325a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_325c:
	/* 0x325c: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3262:
	/* 0x3262: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3265:
	/* 0x3265: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_326b:
	/* 0x326b: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3271:
	/* 0x3271: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3276:
	/* 0x3276: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_327a:
	/* 0x327a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3281:
	/* 0x3281: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3284:
	/* 0x3284: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3289:
	/* 0x3289: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_328e:
	/* 0x328e: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3296:
	/* 0x3296: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_329a:
	/* 0x329a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_32a1:
	/* 0x32a1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_32a6:
	/* 0x32a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a8:
	/* 0x32a8: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32ac:
	/* 0x32ac: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_32b4:
	/* 0x32b4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_32b7:
	/* 0x32b7: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_32bf:
	/* 0x32bf: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_32c8:
	/* 0x32c8: lea    rdx,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_32cf:
	/* 0x32cf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32d4:
	/* 0x32d4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32d9:
	/* 0x32d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32de:
	/* 0x32de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e3:
	/* 0x32e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e5:
	/* 0x32e5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ea:
	/* 0x32ea: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_32ec:
	/* 0x32ec: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_32ef:
	/* 0x32ef: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_32f5:
	/* 0x32f5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32f8:
	/* 0x32f8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_32fe:
	/* 0x32fe: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3304:
	/* 0x3304: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3309:
	/* 0x3309: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_330d:
	/* 0x330d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3314:
	/* 0x3314: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3319:
	/* 0x3319: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_331e:
	/* 0x331e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3325:
	/* 0x3325: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3328:
	/* 0x3328: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_332f:
	/* 0x332f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3334:
	/* 0x3334: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3339:
	/* 0x3339: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_333b:
	/* 0x333b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_333e:
	/* 0x333e: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_3340:
	/* 0x3340: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3342:
	/* 0x3342: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3348:
	/* 0x3348: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_334b:
	/* 0x334b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3351:
	/* 0x3351: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3357:
	/* 0x3357: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_335c:
	/* 0x335c: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3360:
	/* 0x3360: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3367:
	/* 0x3367: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_336a:
	/* 0x336a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_336f:
	/* 0x336f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3374:
	/* 0x3374: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_337c:
	/* 0x337c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3380:
	/* 0x3380: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3387:
	/* 0x3387: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_338c:
	/* 0x338c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_338e:
	/* 0x338e: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3392:
	/* 0x3392: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_339a:
	/* 0x339a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_339d:
	/* 0x339d: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_33a5:
	/* 0x33a5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_33ae:
	/* 0x33ae: lea    rdx,[rbp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_33b5:
	/* 0x33b5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33ba:
	/* 0x33ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33bf:
	/* 0x33bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33c4:
	/* 0x33c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c9:
	/* 0x33c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33cb:
	/* 0x33cb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d0:
	/* 0x33d0: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_33d2:
	/* 0x33d2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_33d5:
	/* 0x33d5: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_33db:
	/* 0x33db: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33de:
	/* 0x33de: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_33e4:
	/* 0x33e4: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_33ea:
	/* 0x33ea: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33ef:
	/* 0x33ef: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_33f3:
	/* 0x33f3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33fa:
	/* 0x33fa: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33ff:
	/* 0x33ff: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3404:
	/* 0x3404: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_340b:
	/* 0x340b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_340e:
	/* 0x340e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3415:
	/* 0x3415: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_341a:
	/* 0x341a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_341f:
	/* 0x341f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3421:
	/* 0x3421: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3424:
	/* 0x3424: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_3426:
	/* 0x3426: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3428:
	/* 0x3428: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_342e:
	/* 0x342e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3431:
	/* 0x3431: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3437:
	/* 0x3437: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_343d:
	/* 0x343d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3442:
	/* 0x3442: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3446:
	/* 0x3446: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_344d:
	/* 0x344d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3450:
	/* 0x3450: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3455:
	/* 0x3455: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_345a:
	/* 0x345a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3462:
	/* 0x3462: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3466:
	/* 0x3466: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_346d:
	/* 0x346d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3472:
	/* 0x3472: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3474:
	/* 0x3474: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3478:
	/* 0x3478: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3480:
	/* 0x3480: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3483:
	/* 0x3483: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_348b:
	/* 0x348b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3494:
	/* 0x3494: lea    rdx,[rbp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_349b:
	/* 0x349b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34a0:
	/* 0x34a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34a5:
	/* 0x34a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34aa:
	/* 0x34aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34af:
	/* 0x34af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b1:
	/* 0x34b1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34b6:
	/* 0x34b6: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_34b8:
	/* 0x34b8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_34bb:
	/* 0x34bb: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_34c1:
	/* 0x34c1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34c4:
	/* 0x34c4: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_34ca:
	/* 0x34ca: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_34d0:
	/* 0x34d0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34d5:
	/* 0x34d5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_34d9:
	/* 0x34d9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_34e0:
	/* 0x34e0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_34e5:
	/* 0x34e5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_34ea:
	/* 0x34ea: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34f1:
	/* 0x34f1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34f4:
	/* 0x34f4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_34fb:
	/* 0x34fb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3500:
	/* 0x3500: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3505:
	/* 0x3505: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3507:
	/* 0x3507: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_350a:
	/* 0x350a: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_350c:
	/* 0x350c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_350e:
	/* 0x350e: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3514:
	/* 0x3514: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3517:
	/* 0x3517: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_351d:
	/* 0x351d: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3523:
	/* 0x3523: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3528:
	/* 0x3528: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_352c:
	/* 0x352c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3533:
	/* 0x3533: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3536:
	/* 0x3536: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_353b:
	/* 0x353b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3540:
	/* 0x3540: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3548:
	/* 0x3548: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_354c:
	/* 0x354c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3553:
	/* 0x3553: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3558:
	/* 0x3558: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_355a:
	/* 0x355a: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_355e:
	/* 0x355e: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3566:
	/* 0x3566: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3569:
	/* 0x3569: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3571:
	/* 0x3571: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_357a:
	/* 0x357a: lea    rdx,[rbp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3581:
	/* 0x3581: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3586:
	/* 0x3586: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_358b:
	/* 0x358b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3590:
	/* 0x3590: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3595:
	/* 0x3595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3597:
	/* 0x3597: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_359c:
	/* 0x359c: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_359e:
	/* 0x359e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_35a1:
	/* 0x35a1: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_35a7:
	/* 0x35a7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35aa:
	/* 0x35aa: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_35b0:
	/* 0x35b0: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_35b6:
	/* 0x35b6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35bb:
	/* 0x35bb: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_35bf:
	/* 0x35bf: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35c6:
	/* 0x35c6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35cb:
	/* 0x35cb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_35d0:
	/* 0x35d0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35d7:
	/* 0x35d7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_35da:
	/* 0x35da: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35e1:
	/* 0x35e1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35e6:
	/* 0x35e6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35eb:
	/* 0x35eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ed:
	/* 0x35ed: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35f0:
	/* 0x35f0: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_35f2:
	/* 0x35f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35f4:
	/* 0x35f4: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_35fa:
	/* 0x35fa: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35fd:
	/* 0x35fd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3603:
	/* 0x3603: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3609:
	/* 0x3609: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_360e:
	/* 0x360e: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3612:
	/* 0x3612: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3619:
	/* 0x3619: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_361c:
	/* 0x361c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3621:
	/* 0x3621: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3626:
	/* 0x3626: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_362e:
	/* 0x362e: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3632:
	/* 0x3632: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3639:
	/* 0x3639: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_363e:
	/* 0x363e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3640:
	/* 0x3640: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3644:
	/* 0x3644: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_364c:
	/* 0x364c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_364f:
	/* 0x364f: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3657:
	/* 0x3657: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3660:
	/* 0x3660: lea    rdx,[rbp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_3667:
	/* 0x3667: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_366c:
	/* 0x366c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3671:
	/* 0x3671: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3676:
	/* 0x3676: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_367b:
	/* 0x367b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367d:
	/* 0x367d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3682:
	/* 0x3682: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_3684:
	/* 0x3684: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3687:
	/* 0x3687: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_368d:
	/* 0x368d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3690:
	/* 0x3690: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3696:
	/* 0x3696: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_369c:
	/* 0x369c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36a1:
	/* 0x36a1: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_36a5:
	/* 0x36a5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36ac:
	/* 0x36ac: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36b1:
	/* 0x36b1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_36b6:
	/* 0x36b6: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36bd:
	/* 0x36bd: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36c0:
	/* 0x36c0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36c7:
	/* 0x36c7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36cc:
	/* 0x36cc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36d1:
	/* 0x36d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d3:
	/* 0x36d3: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36d6:
	/* 0x36d6: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_36d8:
	/* 0x36d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36da:
	/* 0x36da: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_36e0:
	/* 0x36e0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36e3:
	/* 0x36e3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_36e9:
	/* 0x36e9: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_36ef:
	/* 0x36ef: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36f4:
	/* 0x36f4: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_36f8:
	/* 0x36f8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_36ff:
	/* 0x36ff: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3702:
	/* 0x3702: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3707:
	/* 0x3707: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_370c:
	/* 0x370c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3714:
	/* 0x3714: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3718:
	/* 0x3718: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_371f:
	/* 0x371f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3724:
	/* 0x3724: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3726:
	/* 0x3726: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_372a:
	/* 0x372a: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3732:
	/* 0x3732: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3735:
	/* 0x3735: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_373d:
	/* 0x373d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3746:
	/* 0x3746: lea    rdx,[rbp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_374d:
	/* 0x374d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3752:
	/* 0x3752: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3757:
	/* 0x3757: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_375c:
	/* 0x375c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3761:
	/* 0x3761: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3763:
	/* 0x3763: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3768:
	/* 0x3768: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_376a:
	/* 0x376a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_376d:
	/* 0x376d: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_3773:
	/* 0x3773: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3776:
	/* 0x3776: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_377c:
	/* 0x377c: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3782:
	/* 0x3782: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3787:
	/* 0x3787: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_378b:
	/* 0x378b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3792:
	/* 0x3792: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3797:
	/* 0x3797: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_379c:
	/* 0x379c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37a3:
	/* 0x37a3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37a6:
	/* 0x37a6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_37ad:
	/* 0x37ad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37b2:
	/* 0x37b2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_37b7:
	/* 0x37b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37b9:
	/* 0x37b9: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37bc:
	/* 0x37bc: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_37be:
	/* 0x37be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37c0:
	/* 0x37c0: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_37c6:
	/* 0x37c6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37c9:
	/* 0x37c9: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_37cf:
	/* 0x37cf: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_37d5:
	/* 0x37d5: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37da:
	/* 0x37da: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_37de:
	/* 0x37de: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_37e5:
	/* 0x37e5: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_37e8:
	/* 0x37e8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37ed:
	/* 0x37ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37f2:
	/* 0x37f2: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37fa:
	/* 0x37fa: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_37fe:
	/* 0x37fe: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3805:
	/* 0x3805: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_380a:
	/* 0x380a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_380c:
	/* 0x380c: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3810:
	/* 0x3810: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3818:
	/* 0x3818: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_381b:
	/* 0x381b: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3823:
	/* 0x3823: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_382c:
	/* 0x382c: lea    rdx,[rbp+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_3833:
	/* 0x3833: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3838:
	/* 0x3838: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_383d:
	/* 0x383d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3842:
	/* 0x3842: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3847:
	/* 0x3847: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3849:
	/* 0x3849: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_384e:
	/* 0x384e: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_3850:
	/* 0x3850: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3853:
	/* 0x3853: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_3859:
	/* 0x3859: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_385c:
	/* 0x385c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3862:
	/* 0x3862: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3868:
	/* 0x3868: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_386d:
	/* 0x386d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3871:
	/* 0x3871: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3878:
	/* 0x3878: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_387d:
	/* 0x387d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3882:
	/* 0x3882: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3889:
	/* 0x3889: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_388c:
	/* 0x388c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3893:
	/* 0x3893: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3898:
	/* 0x3898: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
	return 14493ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14493ULL: goto x86_l_389d;
	case 14495ULL: goto x86_l_389f;
	case 14498ULL: goto x86_l_38a2;
	case 14500ULL: goto x86_l_38a4;
	case 14502ULL: goto x86_l_38a6;
	case 14508ULL: goto x86_l_38ac;
	case 14511ULL: goto x86_l_38af;
	case 14517ULL: goto x86_l_38b5;
	case 14523ULL: goto x86_l_38bb;
	case 14528ULL: goto x86_l_38c0;
	case 14532ULL: goto x86_l_38c4;
	case 14539ULL: goto x86_l_38cb;
	case 14542ULL: goto x86_l_38ce;
	case 14547ULL: goto x86_l_38d3;
	case 14552ULL: goto x86_l_38d8;
	case 14560ULL: goto x86_l_38e0;
	case 14564ULL: goto x86_l_38e4;
	case 14571ULL: goto x86_l_38eb;
	case 14576ULL: goto x86_l_38f0;
	case 14578ULL: goto x86_l_38f2;
	case 14582ULL: goto x86_l_38f6;
	case 14590ULL: goto x86_l_38fe;
	case 14593ULL: goto x86_l_3901;
	case 14601ULL: goto x86_l_3909;
	case 14610ULL: goto x86_l_3912;
	case 14617ULL: goto x86_l_3919;
	case 14622ULL: goto x86_l_391e;
	case 14627ULL: goto x86_l_3923;
	case 14632ULL: goto x86_l_3928;
	case 14637ULL: goto x86_l_392d;
	case 14639ULL: goto x86_l_392f;
	case 14644ULL: goto x86_l_3934;
	case 14646ULL: goto x86_l_3936;
	case 14649ULL: goto x86_l_3939;
	case 14655ULL: goto x86_l_393f;
	case 14658ULL: goto x86_l_3942;
	case 14664ULL: goto x86_l_3948;
	case 14670ULL: goto x86_l_394e;
	case 14675ULL: goto x86_l_3953;
	case 14679ULL: goto x86_l_3957;
	case 14686ULL: goto x86_l_395e;
	case 14691ULL: goto x86_l_3963;
	case 14696ULL: goto x86_l_3968;
	case 14703ULL: goto x86_l_396f;
	case 14706ULL: goto x86_l_3972;
	case 14713ULL: goto x86_l_3979;
	case 14718ULL: goto x86_l_397e;
	case 14723ULL: goto x86_l_3983;
	case 14725ULL: goto x86_l_3985;
	case 14728ULL: goto x86_l_3988;
	case 14730ULL: goto x86_l_398a;
	case 14732ULL: goto x86_l_398c;
	case 14738ULL: goto x86_l_3992;
	case 14741ULL: goto x86_l_3995;
	case 14747ULL: goto x86_l_399b;
	case 14753ULL: goto x86_l_39a1;
	case 14758ULL: goto x86_l_39a6;
	case 14762ULL: goto x86_l_39aa;
	case 14769ULL: goto x86_l_39b1;
	case 14772ULL: goto x86_l_39b4;
	case 14777ULL: goto x86_l_39b9;
	case 14782ULL: goto x86_l_39be;
	case 14790ULL: goto x86_l_39c6;
	case 14794ULL: goto x86_l_39ca;
	case 14801ULL: goto x86_l_39d1;
	case 14806ULL: goto x86_l_39d6;
	case 14808ULL: goto x86_l_39d8;
	case 14812ULL: goto x86_l_39dc;
	case 14820ULL: goto x86_l_39e4;
	case 14823ULL: goto x86_l_39e7;
	case 14831ULL: goto x86_l_39ef;
	case 14840ULL: goto x86_l_39f8;
	case 14847ULL: goto x86_l_39ff;
	case 14852ULL: goto x86_l_3a04;
	case 14857ULL: goto x86_l_3a09;
	case 14862ULL: goto x86_l_3a0e;
	case 14867ULL: goto x86_l_3a13;
	case 14869ULL: goto x86_l_3a15;
	case 14874ULL: goto x86_l_3a1a;
	case 14876ULL: goto x86_l_3a1c;
	case 14879ULL: goto x86_l_3a1f;
	case 14885ULL: goto x86_l_3a25;
	case 14888ULL: goto x86_l_3a28;
	case 14894ULL: goto x86_l_3a2e;
	case 14900ULL: goto x86_l_3a34;
	case 14905ULL: goto x86_l_3a39;
	case 14909ULL: goto x86_l_3a3d;
	case 14916ULL: goto x86_l_3a44;
	case 14921ULL: goto x86_l_3a49;
	case 14926ULL: goto x86_l_3a4e;
	case 14933ULL: goto x86_l_3a55;
	case 14936ULL: goto x86_l_3a58;
	case 14943ULL: goto x86_l_3a5f;
	case 14948ULL: goto x86_l_3a64;
	case 14953ULL: goto x86_l_3a69;
	case 14955ULL: goto x86_l_3a6b;
	case 14958ULL: goto x86_l_3a6e;
	case 14960ULL: goto x86_l_3a70;
	case 14962ULL: goto x86_l_3a72;
	case 14968ULL: goto x86_l_3a78;
	case 14971ULL: goto x86_l_3a7b;
	case 14977ULL: goto x86_l_3a81;
	case 14983ULL: goto x86_l_3a87;
	case 14988ULL: goto x86_l_3a8c;
	case 14992ULL: goto x86_l_3a90;
	case 14999ULL: goto x86_l_3a97;
	case 15002ULL: goto x86_l_3a9a;
	case 15007ULL: goto x86_l_3a9f;
	case 15012ULL: goto x86_l_3aa4;
	case 15020ULL: goto x86_l_3aac;
	case 15024ULL: goto x86_l_3ab0;
	case 15031ULL: goto x86_l_3ab7;
	case 15036ULL: goto x86_l_3abc;
	case 15038ULL: goto x86_l_3abe;
	case 15042ULL: goto x86_l_3ac2;
	case 15050ULL: goto x86_l_3aca;
	case 15053ULL: goto x86_l_3acd;
	case 15061ULL: goto x86_l_3ad5;
	case 15070ULL: goto x86_l_3ade;
	case 15077ULL: goto x86_l_3ae5;
	case 15082ULL: goto x86_l_3aea;
	case 15087ULL: goto x86_l_3aef;
	case 15092ULL: goto x86_l_3af4;
	case 15097ULL: goto x86_l_3af9;
	case 15099ULL: goto x86_l_3afb;
	case 15104ULL: goto x86_l_3b00;
	case 15106ULL: goto x86_l_3b02;
	case 15109ULL: goto x86_l_3b05;
	case 15115ULL: goto x86_l_3b0b;
	case 15118ULL: goto x86_l_3b0e;
	case 15124ULL: goto x86_l_3b14;
	case 15130ULL: goto x86_l_3b1a;
	case 15135ULL: goto x86_l_3b1f;
	case 15139ULL: goto x86_l_3b23;
	case 15146ULL: goto x86_l_3b2a;
	case 15151ULL: goto x86_l_3b2f;
	case 15156ULL: goto x86_l_3b34;
	case 15163ULL: goto x86_l_3b3b;
	case 15166ULL: goto x86_l_3b3e;
	case 15173ULL: goto x86_l_3b45;
	case 15178ULL: goto x86_l_3b4a;
	case 15183ULL: goto x86_l_3b4f;
	case 15185ULL: goto x86_l_3b51;
	case 15188ULL: goto x86_l_3b54;
	case 15190ULL: goto x86_l_3b56;
	case 15192ULL: goto x86_l_3b58;
	case 15198ULL: goto x86_l_3b5e;
	case 15201ULL: goto x86_l_3b61;
	case 15207ULL: goto x86_l_3b67;
	case 15213ULL: goto x86_l_3b6d;
	case 15218ULL: goto x86_l_3b72;
	case 15222ULL: goto x86_l_3b76;
	case 15229ULL: goto x86_l_3b7d;
	case 15232ULL: goto x86_l_3b80;
	case 15237ULL: goto x86_l_3b85;
	case 15242ULL: goto x86_l_3b8a;
	case 15250ULL: goto x86_l_3b92;
	case 15254ULL: goto x86_l_3b96;
	case 15261ULL: goto x86_l_3b9d;
	case 15266ULL: goto x86_l_3ba2;
	case 15268ULL: goto x86_l_3ba4;
	case 15272ULL: goto x86_l_3ba8;
	case 15280ULL: goto x86_l_3bb0;
	case 15283ULL: goto x86_l_3bb3;
	case 15291ULL: goto x86_l_3bbb;
	case 15300ULL: goto x86_l_3bc4;
	case 15307ULL: goto x86_l_3bcb;
	case 15312ULL: goto x86_l_3bd0;
	case 15317ULL: goto x86_l_3bd5;
	case 15322ULL: goto x86_l_3bda;
	case 15327ULL: goto x86_l_3bdf;
	case 15329ULL: goto x86_l_3be1;
	case 15334ULL: goto x86_l_3be6;
	case 15336ULL: goto x86_l_3be8;
	case 15339ULL: goto x86_l_3beb;
	case 15345ULL: goto x86_l_3bf1;
	case 15348ULL: goto x86_l_3bf4;
	case 15354ULL: goto x86_l_3bfa;
	case 15360ULL: goto x86_l_3c00;
	case 15365ULL: goto x86_l_3c05;
	case 15369ULL: goto x86_l_3c09;
	case 15376ULL: goto x86_l_3c10;
	case 15381ULL: goto x86_l_3c15;
	case 15386ULL: goto x86_l_3c1a;
	case 15393ULL: goto x86_l_3c21;
	case 15396ULL: goto x86_l_3c24;
	case 15403ULL: goto x86_l_3c2b;
	case 15408ULL: goto x86_l_3c30;
	case 15413ULL: goto x86_l_3c35;
	case 15415ULL: goto x86_l_3c37;
	case 15418ULL: goto x86_l_3c3a;
	case 15420ULL: goto x86_l_3c3c;
	case 15422ULL: goto x86_l_3c3e;
	case 15428ULL: goto x86_l_3c44;
	case 15431ULL: goto x86_l_3c47;
	case 15437ULL: goto x86_l_3c4d;
	case 15443ULL: goto x86_l_3c53;
	case 15448ULL: goto x86_l_3c58;
	case 15452ULL: goto x86_l_3c5c;
	case 15459ULL: goto x86_l_3c63;
	case 15462ULL: goto x86_l_3c66;
	case 15467ULL: goto x86_l_3c6b;
	case 15472ULL: goto x86_l_3c70;
	case 15480ULL: goto x86_l_3c78;
	case 15484ULL: goto x86_l_3c7c;
	case 15491ULL: goto x86_l_3c83;
	case 15496ULL: goto x86_l_3c88;
	case 15498ULL: goto x86_l_3c8a;
	case 15502ULL: goto x86_l_3c8e;
	case 15510ULL: goto x86_l_3c96;
	case 15513ULL: goto x86_l_3c99;
	case 15521ULL: goto x86_l_3ca1;
	case 15530ULL: goto x86_l_3caa;
	case 15537ULL: goto x86_l_3cb1;
	case 15542ULL: goto x86_l_3cb6;
	case 15547ULL: goto x86_l_3cbb;
	case 15552ULL: goto x86_l_3cc0;
	case 15557ULL: goto x86_l_3cc5;
	case 15560ULL: goto x86_l_3cc8;
	case 15562ULL: goto x86_l_3cca;
	case 15567ULL: goto x86_l_3ccf;
	case 15569ULL: goto x86_l_3cd1;
	case 15572ULL: goto x86_l_3cd4;
	case 15578ULL: goto x86_l_3cda;
	case 15581ULL: goto x86_l_3cdd;
	case 15587ULL: goto x86_l_3ce3;
	case 15593ULL: goto x86_l_3ce9;
	case 15598ULL: goto x86_l_3cee;
	case 15602ULL: goto x86_l_3cf2;
	case 15609ULL: goto x86_l_3cf9;
	case 15614ULL: goto x86_l_3cfe;
	case 15619ULL: goto x86_l_3d03;
	case 15626ULL: goto x86_l_3d0a;
	case 15629ULL: goto x86_l_3d0d;
	case 15636ULL: goto x86_l_3d14;
	case 15641ULL: goto x86_l_3d19;
	case 15646ULL: goto x86_l_3d1e;
	case 15648ULL: goto x86_l_3d20;
	case 15651ULL: goto x86_l_3d23;
	case 15653ULL: goto x86_l_3d25;
	case 15655ULL: goto x86_l_3d27;
	case 15661ULL: goto x86_l_3d2d;
	case 15664ULL: goto x86_l_3d30;
	case 15670ULL: goto x86_l_3d36;
	case 15676ULL: goto x86_l_3d3c;
	case 15681ULL: goto x86_l_3d41;
	case 15685ULL: goto x86_l_3d45;
	case 15692ULL: goto x86_l_3d4c;
	case 15695ULL: goto x86_l_3d4f;
	case 15700ULL: goto x86_l_3d54;
	case 15705ULL: goto x86_l_3d59;
	case 15713ULL: goto x86_l_3d61;
	case 15717ULL: goto x86_l_3d65;
	case 15724ULL: goto x86_l_3d6c;
	case 15729ULL: goto x86_l_3d71;
	case 15731ULL: goto x86_l_3d73;
	case 15735ULL: goto x86_l_3d77;
	case 15743ULL: goto x86_l_3d7f;
	case 15746ULL: goto x86_l_3d82;
	case 15754ULL: goto x86_l_3d8a;
	case 15762ULL: goto x86_l_3d92;
	case 15765ULL: goto x86_l_3d95;
	case 15771ULL: goto x86_l_3d9b;
	case 15773ULL: goto x86_l_3d9d;
	case 15778ULL: goto x86_l_3da2;
	case 15782ULL: goto x86_l_3da6;
	case 15785ULL: goto x86_l_3da9;
	case 15790ULL: goto x86_l_3dae;
	case 15794ULL: goto x86_l_3db2;
	case 15801ULL: goto x86_l_3db9;
	case 15806ULL: goto x86_l_3dbe;
	case 15811ULL: goto x86_l_3dc3;
	case 15816ULL: goto x86_l_3dc8;
	case 15823ULL: goto x86_l_3dcf;
	case 15826ULL: goto x86_l_3dd2;
	case 15833ULL: goto x86_l_3dd9;
	case 15838ULL: goto x86_l_3dde;
	case 15840ULL: goto x86_l_3de0;
	case 15843ULL: goto x86_l_3de3;
	case 15845ULL: goto x86_l_3de5;
	case 15847ULL: goto x86_l_3de7;
	case 15853ULL: goto x86_l_3ded;
	case 15856ULL: goto x86_l_3df0;
	case 15862ULL: goto x86_l_3df6;
	case 15868ULL: goto x86_l_3dfc;
	case 15873ULL: goto x86_l_3e01;
	case 15877ULL: goto x86_l_3e05;
	case 15884ULL: goto x86_l_3e0c;
	case 15887ULL: goto x86_l_3e0f;
	case 15892ULL: goto x86_l_3e14;
	case 15897ULL: goto x86_l_3e19;
	case 15906ULL: goto x86_l_3e22;
	case 15910ULL: goto x86_l_3e26;
	case 15917ULL: goto x86_l_3e2d;
	case 15922ULL: goto x86_l_3e32;
	case 15924ULL: goto x86_l_3e34;
	case 15928ULL: goto x86_l_3e38;
	case 15937ULL: goto x86_l_3e41;
	case 15940ULL: goto x86_l_3e44;
	case 15949ULL: goto x86_l_3e4d;
	case 15951ULL: goto x86_l_3e4f;
	case 15956ULL: goto x86_l_3e54;
	case 15960ULL: goto x86_l_3e58;
	case 15967ULL: goto x86_l_3e5f;
	case 15970ULL: goto x86_l_3e62;
	case 15975ULL: goto x86_l_3e67;
	case 15980ULL: goto x86_l_3e6c;
	case 15987ULL: goto x86_l_3e73;
	case 15991ULL: goto x86_l_3e77;
	case 15998ULL: goto x86_l_3e7e;
	case 16003ULL: goto x86_l_3e83;
	case 16005ULL: goto x86_l_3e85;
	case 16009ULL: goto x86_l_3e89;
	case 16016ULL: goto x86_l_3e90;
	case 16019ULL: goto x86_l_3e93;
	case 16026ULL: goto x86_l_3e9a;
	case 16035ULL: goto x86_l_3ea3;
	case 16039ULL: goto x86_l_3ea7;
	case 16044ULL: goto x86_l_3eac;
	case 16049ULL: goto x86_l_3eb1;
	case 16054ULL: goto x86_l_3eb6;
	case 16059ULL: goto x86_l_3ebb;
	case 16061ULL: goto x86_l_3ebd;
	case 16066ULL: goto x86_l_3ec2;
	case 16068ULL: goto x86_l_3ec4;
	case 16071ULL: goto x86_l_3ec7;
	case 16077ULL: goto x86_l_3ecd;
	case 16080ULL: goto x86_l_3ed0;
	case 16086ULL: goto x86_l_3ed6;
	case 16092ULL: goto x86_l_3edc;
	case 16096ULL: goto x86_l_3ee0;
	case 16103ULL: goto x86_l_3ee7;
	case 16108ULL: goto x86_l_3eec;
	case 16113ULL: goto x86_l_3ef1;
	case 16120ULL: goto x86_l_3ef8;
	case 16124ULL: goto x86_l_3efc;
	case 16131ULL: goto x86_l_3f03;
	case 16136ULL: goto x86_l_3f08;
	case 16141ULL: goto x86_l_3f0d;
	case 16143ULL: goto x86_l_3f0f;
	case 16146ULL: goto x86_l_3f12;
	case 16148ULL: goto x86_l_3f14;
	case 16150ULL: goto x86_l_3f16;
	case 16156ULL: goto x86_l_3f1c;
	case 16159ULL: goto x86_l_3f1f;
	case 16165ULL: goto x86_l_3f25;
	case 16171ULL: goto x86_l_3f2b;
	case 16175ULL: goto x86_l_3f2f;
	case 16182ULL: goto x86_l_3f36;
	case 16185ULL: goto x86_l_3f39;
	case 16190ULL: goto x86_l_3f3e;
	case 16195ULL: goto x86_l_3f43;
	case 16202ULL: goto x86_l_3f4a;
	case 16206ULL: goto x86_l_3f4e;
	case 16213ULL: goto x86_l_3f55;
	case 16218ULL: goto x86_l_3f5a;
	case 16220ULL: goto x86_l_3f5c;
	case 16224ULL: goto x86_l_3f60;
	case 16231ULL: goto x86_l_3f67;
	case 16234ULL: goto x86_l_3f6a;
	case 16241ULL: goto x86_l_3f71;
	case 16250ULL: goto x86_l_3f7a;
	case 16254ULL: goto x86_l_3f7e;
	case 16259ULL: goto x86_l_3f83;
	case 16264ULL: goto x86_l_3f88;
	case 16269ULL: goto x86_l_3f8d;
	case 16274ULL: goto x86_l_3f92;
	case 16276ULL: goto x86_l_3f94;
	case 16281ULL: goto x86_l_3f99;
	case 16283ULL: goto x86_l_3f9b;
	case 16286ULL: goto x86_l_3f9e;
	case 16292ULL: goto x86_l_3fa4;
	case 16295ULL: goto x86_l_3fa7;
	case 16301ULL: goto x86_l_3fad;
	case 16307ULL: goto x86_l_3fb3;
	case 16311ULL: goto x86_l_3fb7;
	case 16318ULL: goto x86_l_3fbe;
	case 16323ULL: goto x86_l_3fc3;
	case 16328ULL: goto x86_l_3fc8;
	case 16335ULL: goto x86_l_3fcf;
	case 16339ULL: goto x86_l_3fd3;
	case 16346ULL: goto x86_l_3fda;
	case 16351ULL: goto x86_l_3fdf;
	case 16356ULL: goto x86_l_3fe4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_389d:
	/* 0x389d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_389f:
	/* 0x389f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38a2:
	/* 0x38a2: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_38a4:
	/* 0x38a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38a6:
	/* 0x38a6: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_38ac:
	/* 0x38ac: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38af:
	/* 0x38af: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_38b5:
	/* 0x38b5: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_38bb:
	/* 0x38bb: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38c0:
	/* 0x38c0: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_38c4:
	/* 0x38c4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_38cb:
	/* 0x38cb: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_38ce:
	/* 0x38ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38d3:
	/* 0x38d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38d8:
	/* 0x38d8: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_38e0:
	/* 0x38e0: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_38e4:
	/* 0x38e4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_38eb:
	/* 0x38eb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38f0:
	/* 0x38f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38f2:
	/* 0x38f2: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38f6:
	/* 0x38f6: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_38fe:
	/* 0x38fe: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3901:
	/* 0x3901: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3909:
	/* 0x3909: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3912:
	/* 0x3912: lea    rdx,[rbp+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_3919:
	/* 0x3919: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_391e:
	/* 0x391e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3923:
	/* 0x3923: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3928:
	/* 0x3928: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_392d:
	/* 0x392d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_392f:
	/* 0x392f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3934:
	/* 0x3934: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_3936:
	/* 0x3936: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3939:
	/* 0x3939: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_393f:
	/* 0x393f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3942:
	/* 0x3942: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3948:
	/* 0x3948: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_394e:
	/* 0x394e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3953:
	/* 0x3953: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3957:
	/* 0x3957: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_395e:
	/* 0x395e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3963:
	/* 0x3963: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3968:
	/* 0x3968: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_396f:
	/* 0x396f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3972:
	/* 0x3972: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3979:
	/* 0x3979: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_397e:
	/* 0x397e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3983:
	/* 0x3983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3985:
	/* 0x3985: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3988:
	/* 0x3988: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_398a:
	/* 0x398a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_398c:
	/* 0x398c: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3992:
	/* 0x3992: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3995:
	/* 0x3995: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_399b:
	/* 0x399b: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_39a1:
	/* 0x39a1: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39a6:
	/* 0x39a6: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_39aa:
	/* 0x39aa: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_39b1:
	/* 0x39b1: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_39b4:
	/* 0x39b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39b9:
	/* 0x39b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39be:
	/* 0x39be: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39c6:
	/* 0x39c6: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_39ca:
	/* 0x39ca: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_39d1:
	/* 0x39d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39d6:
	/* 0x39d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39d8:
	/* 0x39d8: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39dc:
	/* 0x39dc: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_39e4:
	/* 0x39e4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_39e7:
	/* 0x39e7: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_39ef:
	/* 0x39ef: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_39f8:
	/* 0x39f8: lea    rdx,[rbp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_39ff:
	/* 0x39ff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a04:
	/* 0x3a04: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a09:
	/* 0x3a09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a0e:
	/* 0x3a0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a13:
	/* 0x3a13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a15:
	/* 0x3a15: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a1a:
	/* 0x3a1a: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_3a1c:
	/* 0x3a1c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3a1f:
	/* 0x3a1f: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_3a25:
	/* 0x3a25: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a28:
	/* 0x3a28: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3a2e:
	/* 0x3a2e: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3a34:
	/* 0x3a34: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a39:
	/* 0x3a39: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3a3d:
	/* 0x3a3d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a44:
	/* 0x3a44: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a49:
	/* 0x3a49: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3a4e:
	/* 0x3a4e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a55:
	/* 0x3a55: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a58:
	/* 0x3a58: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a5f:
	/* 0x3a5f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a64:
	/* 0x3a64: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a69:
	/* 0x3a69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a6b:
	/* 0x3a6b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a6e:
	/* 0x3a6e: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_3a70:
	/* 0x3a70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a72:
	/* 0x3a72: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3a78:
	/* 0x3a78: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a7b:
	/* 0x3a7b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3a81:
	/* 0x3a81: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3a87:
	/* 0x3a87: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a8c:
	/* 0x3a8c: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3a90:
	/* 0x3a90: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a97:
	/* 0x3a97: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3a9a:
	/* 0x3a9a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a9f:
	/* 0x3a9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3aa4:
	/* 0x3aa4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3aac:
	/* 0x3aac: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3ab0:
	/* 0x3ab0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ab7:
	/* 0x3ab7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3abc:
	/* 0x3abc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3abe:
	/* 0x3abe: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ac2:
	/* 0x3ac2: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3aca:
	/* 0x3aca: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3acd:
	/* 0x3acd: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3ad5:
	/* 0x3ad5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ade:
	/* 0x3ade: lea    rdx,[rbp+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3ae5:
	/* 0x3ae5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aea:
	/* 0x3aea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3aef:
	/* 0x3aef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3af4:
	/* 0x3af4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3af9:
	/* 0x3af9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3afb:
	/* 0x3afb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b00:
	/* 0x3b00: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_3b02:
	/* 0x3b02: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3b05:
	/* 0x3b05: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_3b0b:
	/* 0x3b0b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b0e:
	/* 0x3b0e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3b14:
	/* 0x3b14: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3b1a:
	/* 0x3b1a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b1f:
	/* 0x3b1f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3b23:
	/* 0x3b23: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b2a:
	/* 0x3b2a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b2f:
	/* 0x3b2f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b34:
	/* 0x3b34: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b3b:
	/* 0x3b3b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3b3e:
	/* 0x3b3e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b45:
	/* 0x3b45: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b4a:
	/* 0x3b4a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b4f:
	/* 0x3b4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b51:
	/* 0x3b51: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b54:
	/* 0x3b54: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_3b56:
	/* 0x3b56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b58:
	/* 0x3b58: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3b5e:
	/* 0x3b5e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b61:
	/* 0x3b61: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3b67:
	/* 0x3b67: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3b6d:
	/* 0x3b6d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b72:
	/* 0x3b72: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3b76:
	/* 0x3b76: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b7d:
	/* 0x3b7d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3b80:
	/* 0x3b80: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b85:
	/* 0x3b85: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b8a:
	/* 0x3b8a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b92:
	/* 0x3b92: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b96:
	/* 0x3b96: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b9d:
	/* 0x3b9d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ba2:
	/* 0x3ba2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ba4:
	/* 0x3ba4: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ba8:
	/* 0x3ba8: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3bb0:
	/* 0x3bb0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3bb3:
	/* 0x3bb3: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3bbb:
	/* 0x3bbb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3bc4:
	/* 0x3bc4: lea    rdx,[rbp+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3bcb:
	/* 0x3bcb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bd0:
	/* 0x3bd0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bd5:
	/* 0x3bd5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bda:
	/* 0x3bda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bdf:
	/* 0x3bdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be1:
	/* 0x3be1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3be6:
	/* 0x3be6: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_3be8:
	/* 0x3be8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3beb:
	/* 0x3beb: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_3bf1:
	/* 0x3bf1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3bf4:
	/* 0x3bf4: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3bfa:
	/* 0x3bfa: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3c00:
	/* 0x3c00: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c05:
	/* 0x3c05: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3c09:
	/* 0x3c09: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c10:
	/* 0x3c10: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c15:
	/* 0x3c15: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3c1a:
	/* 0x3c1a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c21:
	/* 0x3c21: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c24:
	/* 0x3c24: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c2b:
	/* 0x3c2b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c30:
	/* 0x3c30: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c35:
	/* 0x3c35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c37:
	/* 0x3c37: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c3a:
	/* 0x3c3a: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_3c3c:
	/* 0x3c3c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c3e:
	/* 0x3c3e: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3c44:
	/* 0x3c44: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c47:
	/* 0x3c47: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3c4d:
	/* 0x3c4d: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3c53:
	/* 0x3c53: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c58:
	/* 0x3c58: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3c5c:
	/* 0x3c5c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c63:
	/* 0x3c63: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3c66:
	/* 0x3c66: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c6b:
	/* 0x3c6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c70:
	/* 0x3c70: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c78:
	/* 0x3c78: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3c7c:
	/* 0x3c7c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c83:
	/* 0x3c83: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c88:
	/* 0x3c88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c8a:
	/* 0x3c8a: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c8e:
	/* 0x3c8e: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3c96:
	/* 0x3c96: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3c99:
	/* 0x3c99: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3ca1:
	/* 0x3ca1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3caa:
	/* 0x3caa: add    rbp,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_3cb1:
	/* 0x3cb1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cb6:
	/* 0x3cb6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cbb:
	/* 0x3cbb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cc0:
	/* 0x3cc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cc5:
	/* 0x3cc5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3cc8:
	/* 0x3cc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cca:
	/* 0x3cca: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ccf:
	/* 0x3ccf: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_3cd1:
	/* 0x3cd1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3cd4:
	/* 0x3cd4: je     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5571ULL;
	}
x86_l_3cda:
	/* 0x3cda: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cdd:
	/* 0x3cdd: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3ce3:
	/* 0x3ce3: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3ce9:
	/* 0x3ce9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cee:
	/* 0x3cee: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3cf2:
	/* 0x3cf2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3cf9:
	/* 0x3cf9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3cfe:
	/* 0x3cfe: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3d03:
	/* 0x3d03: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d0a:
	/* 0x3d0a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d0d:
	/* 0x3d0d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d14:
	/* 0x3d14: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d19:
	/* 0x3d19: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d1e:
	/* 0x3d1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d20:
	/* 0x3d20: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d23:
	/* 0x3d23: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_3d25:
	/* 0x3d25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d27:
	/* 0x3d27: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3d2d:
	/* 0x3d2d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d30:
	/* 0x3d30: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3d36:
	/* 0x3d36: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3d3c:
	/* 0x3d3c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d41:
	/* 0x3d41: lea    rcx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3d45:
	/* 0x3d45: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d4c:
	/* 0x3d4c: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3d4f:
	/* 0x3d4f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d54:
	/* 0x3d54: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d59:
	/* 0x3d59: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d61:
	/* 0x3d61: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d65:
	/* 0x3d65: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d6c:
	/* 0x3d6c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d71:
	/* 0x3d71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d73:
	/* 0x3d73: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d77:
	/* 0x3d77: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3d7f:
	/* 0x3d7f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3d82:
	/* 0x3d82: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3d8a:
	/* 0x3d8a: mov    DWORD PTR [rsp+0x10],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68722503214ULL);
x86_l_3d92:
	/* 0x3d92: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3d95:
	/* 0x3d95: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_3d9b:
	/* 0x3d9b: jb     3da6 <trace_call_usermodehelper+0x3da6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3da6;
	}
x86_l_3d9d:
	/* 0x3d9d: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_3da2:
	/* 0x3da2: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_3da6:
	/* 0x3da6: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3da9:
	/* 0x3da9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dae:
	/* 0x3dae: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3db2:
	/* 0x3db2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3db9:
	/* 0x3db9: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dbe:
	/* 0x3dbe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3dc3:
	/* 0x3dc3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3dc8:
	/* 0x3dc8: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3dcf:
	/* 0x3dcf: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3dd2:
	/* 0x3dd2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3dd9:
	/* 0x3dd9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3dde:
	/* 0x3dde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3de0:
	/* 0x3de0: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3de3:
	/* 0x3de3: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_3de5:
	/* 0x3de5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3de7:
	/* 0x3de7: jle    15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5571ULL;
	}
x86_l_3ded:
	/* 0x3ded: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3df0:
	/* 0x3df0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3df6:
	/* 0x3df6: ja     15c3 <trace_call_usermodehelper+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5571ULL;
	}
x86_l_3dfc:
	/* 0x3dfc: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e01:
	/* 0x3e01: lea    rcx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3e05:
	/* 0x3e05: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e0c:
	/* 0x3e0c: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3e0f:
	/* 0x3e0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e14:
	/* 0x3e14: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e19:
	/* 0x3e19: movzx  ecx,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e22:
	/* 0x3e22: lea    rdi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3e26:
	/* 0x3e26: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e2d:
	/* 0x3e2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e32:
	/* 0x3e32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e34:
	/* 0x3e34: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e38:
	/* 0x3e38: add    ax,WORD PTR [r12+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e41:
	/* 0x3e41: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e44:
	/* 0x3e44: mov    WORD PTR [r12+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3e4d:
	/* 0x3e4d: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_3e4f:
	/* 0x3e4f: jmp    15c3 <trace_call_usermodehelper+0x15c3> */
	return 5571ULL;
x86_l_3e54:
	/* 0x3e54: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3e58:
	/* 0x3e58: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e5f:
	/* 0x3e5f: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3e62:
	/* 0x3e62: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e67:
	/* 0x3e67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e6c:
	/* 0x3e6c: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e73:
	/* 0x3e73: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3e77:
	/* 0x3e77: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e7e:
	/* 0x3e7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e83:
	/* 0x3e83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e85:
	/* 0x3e85: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e89:
	/* 0x3e89: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e90:
	/* 0x3e90: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e93:
	/* 0x3e93: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3e9a:
	/* 0x3e9a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ea3:
	/* 0x3ea3: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ea7:
	/* 0x3ea7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3eac:
	/* 0x3eac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3eb1:
	/* 0x3eb1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3eb6:
	/* 0x3eb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ebb:
	/* 0x3ebb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ebd:
	/* 0x3ebd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ec2:
	/* 0x3ec2: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_3ec4:
	/* 0x3ec4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3ec7:
	/* 0x3ec7: je     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5776ULL;
	}
x86_l_3ecd:
	/* 0x3ecd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ed0:
	/* 0x3ed0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3ed6:
	/* 0x3ed6: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_3edc:
	/* 0x3edc: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3ee0:
	/* 0x3ee0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3ee7:
	/* 0x3ee7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3eec:
	/* 0x3eec: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ef1:
	/* 0x3ef1: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ef8:
	/* 0x3ef8: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3efc:
	/* 0x3efc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3f03:
	/* 0x3f03: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f08:
	/* 0x3f08: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f0d:
	/* 0x3f0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f0f:
	/* 0x3f0f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f12:
	/* 0x3f12: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_3f14:
	/* 0x3f14: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f16:
	/* 0x3f16: jle    1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5776ULL;
	}
x86_l_3f1c:
	/* 0x3f1c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f1f:
	/* 0x3f1f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3f25:
	/* 0x3f25: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_3f2b:
	/* 0x3f2b: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3f2f:
	/* 0x3f2f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f36:
	/* 0x3f36: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3f39:
	/* 0x3f39: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f3e:
	/* 0x3f3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f43:
	/* 0x3f43: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f4a:
	/* 0x3f4a: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3f4e:
	/* 0x3f4e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f55:
	/* 0x3f55: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f5a:
	/* 0x3f5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f5c:
	/* 0x3f5c: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f60:
	/* 0x3f60: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3f67:
	/* 0x3f67: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3f6a:
	/* 0x3f6a: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3f71:
	/* 0x3f71: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f7a:
	/* 0x3f7a: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f7e:
	/* 0x3f7e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f83:
	/* 0x3f83: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f88:
	/* 0x3f88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f8d:
	/* 0x3f8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f92:
	/* 0x3f92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f94:
	/* 0x3f94: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f99:
	/* 0x3f99: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_3f9b:
	/* 0x3f9b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3f9e:
	/* 0x3f9e: je     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5776ULL;
	}
x86_l_3fa4:
	/* 0x3fa4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fa7:
	/* 0x3fa7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3fad:
	/* 0x3fad: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_3fb3:
	/* 0x3fb3: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3fb7:
	/* 0x3fb7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3fbe:
	/* 0x3fbe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3fc3:
	/* 0x3fc3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3fc8:
	/* 0x3fc8: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3fcf:
	/* 0x3fcf: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3fd3:
	/* 0x3fd3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3fda:
	/* 0x3fda: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fdf:
	/* 0x3fdf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3fe4:
	/* 0x3fe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 16358ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16358ULL: goto x86_l_3fe6;
	case 16361ULL: goto x86_l_3fe9;
	case 16363ULL: goto x86_l_3feb;
	case 16365ULL: goto x86_l_3fed;
	case 16371ULL: goto x86_l_3ff3;
	case 16374ULL: goto x86_l_3ff6;
	case 16380ULL: goto x86_l_3ffc;
	case 16386ULL: goto x86_l_4002;
	case 16390ULL: goto x86_l_4006;
	case 16397ULL: goto x86_l_400d;
	case 16400ULL: goto x86_l_4010;
	case 16405ULL: goto x86_l_4015;
	case 16410ULL: goto x86_l_401a;
	case 16417ULL: goto x86_l_4021;
	case 16421ULL: goto x86_l_4025;
	case 16428ULL: goto x86_l_402c;
	case 16433ULL: goto x86_l_4031;
	case 16435ULL: goto x86_l_4033;
	case 16439ULL: goto x86_l_4037;
	case 16446ULL: goto x86_l_403e;
	case 16449ULL: goto x86_l_4041;
	case 16456ULL: goto x86_l_4048;
	case 16465ULL: goto x86_l_4051;
	case 16469ULL: goto x86_l_4055;
	case 16474ULL: goto x86_l_405a;
	case 16479ULL: goto x86_l_405f;
	case 16484ULL: goto x86_l_4064;
	case 16489ULL: goto x86_l_4069;
	case 16491ULL: goto x86_l_406b;
	case 16496ULL: goto x86_l_4070;
	case 16498ULL: goto x86_l_4072;
	case 16501ULL: goto x86_l_4075;
	case 16507ULL: goto x86_l_407b;
	case 16510ULL: goto x86_l_407e;
	case 16516ULL: goto x86_l_4084;
	case 16522ULL: goto x86_l_408a;
	case 16526ULL: goto x86_l_408e;
	case 16533ULL: goto x86_l_4095;
	case 16538ULL: goto x86_l_409a;
	case 16543ULL: goto x86_l_409f;
	case 16550ULL: goto x86_l_40a6;
	case 16554ULL: goto x86_l_40aa;
	case 16561ULL: goto x86_l_40b1;
	case 16566ULL: goto x86_l_40b6;
	case 16571ULL: goto x86_l_40bb;
	case 16573ULL: goto x86_l_40bd;
	case 16576ULL: goto x86_l_40c0;
	case 16578ULL: goto x86_l_40c2;
	case 16580ULL: goto x86_l_40c4;
	case 16586ULL: goto x86_l_40ca;
	case 16589ULL: goto x86_l_40cd;
	case 16595ULL: goto x86_l_40d3;
	case 16600ULL: goto x86_l_40d8;
	case 16606ULL: goto x86_l_40de;
	case 16610ULL: goto x86_l_40e2;
	case 16617ULL: goto x86_l_40e9;
	case 16620ULL: goto x86_l_40ec;
	case 16625ULL: goto x86_l_40f1;
	case 16630ULL: goto x86_l_40f6;
	case 16637ULL: goto x86_l_40fd;
	case 16641ULL: goto x86_l_4101;
	case 16648ULL: goto x86_l_4108;
	case 16653ULL: goto x86_l_410d;
	case 16655ULL: goto x86_l_410f;
	case 16659ULL: goto x86_l_4113;
	case 16666ULL: goto x86_l_411a;
	case 16669ULL: goto x86_l_411d;
	case 16676ULL: goto x86_l_4124;
	case 16685ULL: goto x86_l_412d;
	case 16689ULL: goto x86_l_4131;
	case 16694ULL: goto x86_l_4136;
	case 16699ULL: goto x86_l_413b;
	case 16704ULL: goto x86_l_4140;
	case 16709ULL: goto x86_l_4145;
	case 16711ULL: goto x86_l_4147;
	case 16716ULL: goto x86_l_414c;
	case 16718ULL: goto x86_l_414e;
	case 16721ULL: goto x86_l_4151;
	case 16727ULL: goto x86_l_4157;
	case 16730ULL: goto x86_l_415a;
	case 16736ULL: goto x86_l_4160;
	case 16741ULL: goto x86_l_4165;
	case 16747ULL: goto x86_l_416b;
	case 16751ULL: goto x86_l_416f;
	case 16758ULL: goto x86_l_4176;
	case 16763ULL: goto x86_l_417b;
	case 16768ULL: goto x86_l_4180;
	case 16775ULL: goto x86_l_4187;
	case 16779ULL: goto x86_l_418b;
	case 16786ULL: goto x86_l_4192;
	case 16791ULL: goto x86_l_4197;
	case 16796ULL: goto x86_l_419c;
	case 16798ULL: goto x86_l_419e;
	case 16801ULL: goto x86_l_41a1;
	case 16803ULL: goto x86_l_41a3;
	case 16805ULL: goto x86_l_41a5;
	case 16811ULL: goto x86_l_41ab;
	case 16814ULL: goto x86_l_41ae;
	case 16820ULL: goto x86_l_41b4;
	case 16825ULL: goto x86_l_41b9;
	case 16831ULL: goto x86_l_41bf;
	case 16835ULL: goto x86_l_41c3;
	case 16842ULL: goto x86_l_41ca;
	case 16845ULL: goto x86_l_41cd;
	case 16850ULL: goto x86_l_41d2;
	case 16855ULL: goto x86_l_41d7;
	case 16862ULL: goto x86_l_41de;
	case 16866ULL: goto x86_l_41e2;
	case 16873ULL: goto x86_l_41e9;
	case 16878ULL: goto x86_l_41ee;
	case 16880ULL: goto x86_l_41f0;
	case 16884ULL: goto x86_l_41f4;
	case 16891ULL: goto x86_l_41fb;
	case 16894ULL: goto x86_l_41fe;
	case 16901ULL: goto x86_l_4205;
	case 16910ULL: goto x86_l_420e;
	case 16914ULL: goto x86_l_4212;
	case 16919ULL: goto x86_l_4217;
	case 16924ULL: goto x86_l_421c;
	case 16929ULL: goto x86_l_4221;
	case 16934ULL: goto x86_l_4226;
	case 16936ULL: goto x86_l_4228;
	case 16941ULL: goto x86_l_422d;
	case 16943ULL: goto x86_l_422f;
	case 16946ULL: goto x86_l_4232;
	case 16952ULL: goto x86_l_4238;
	case 16955ULL: goto x86_l_423b;
	case 16961ULL: goto x86_l_4241;
	case 16966ULL: goto x86_l_4246;
	case 16972ULL: goto x86_l_424c;
	case 16976ULL: goto x86_l_4250;
	case 16983ULL: goto x86_l_4257;
	case 16988ULL: goto x86_l_425c;
	case 16993ULL: goto x86_l_4261;
	case 17000ULL: goto x86_l_4268;
	case 17004ULL: goto x86_l_426c;
	case 17011ULL: goto x86_l_4273;
	case 17016ULL: goto x86_l_4278;
	case 17021ULL: goto x86_l_427d;
	case 17023ULL: goto x86_l_427f;
	case 17026ULL: goto x86_l_4282;
	case 17028ULL: goto x86_l_4284;
	case 17030ULL: goto x86_l_4286;
	case 17036ULL: goto x86_l_428c;
	case 17039ULL: goto x86_l_428f;
	case 17045ULL: goto x86_l_4295;
	case 17050ULL: goto x86_l_429a;
	case 17056ULL: goto x86_l_42a0;
	case 17060ULL: goto x86_l_42a4;
	case 17067ULL: goto x86_l_42ab;
	case 17070ULL: goto x86_l_42ae;
	case 17075ULL: goto x86_l_42b3;
	case 17080ULL: goto x86_l_42b8;
	case 17087ULL: goto x86_l_42bf;
	case 17091ULL: goto x86_l_42c3;
	case 17098ULL: goto x86_l_42ca;
	case 17103ULL: goto x86_l_42cf;
	case 17105ULL: goto x86_l_42d1;
	case 17109ULL: goto x86_l_42d5;
	case 17116ULL: goto x86_l_42dc;
	case 17119ULL: goto x86_l_42df;
	case 17126ULL: goto x86_l_42e6;
	case 17135ULL: goto x86_l_42ef;
	case 17139ULL: goto x86_l_42f3;
	case 17144ULL: goto x86_l_42f8;
	case 17149ULL: goto x86_l_42fd;
	case 17154ULL: goto x86_l_4302;
	case 17159ULL: goto x86_l_4307;
	case 17161ULL: goto x86_l_4309;
	case 17166ULL: goto x86_l_430e;
	case 17168ULL: goto x86_l_4310;
	case 17171ULL: goto x86_l_4313;
	case 17177ULL: goto x86_l_4319;
	case 17180ULL: goto x86_l_431c;
	case 17186ULL: goto x86_l_4322;
	case 17191ULL: goto x86_l_4327;
	case 17197ULL: goto x86_l_432d;
	case 17201ULL: goto x86_l_4331;
	case 17208ULL: goto x86_l_4338;
	case 17213ULL: goto x86_l_433d;
	case 17218ULL: goto x86_l_4342;
	case 17225ULL: goto x86_l_4349;
	case 17229ULL: goto x86_l_434d;
	case 17236ULL: goto x86_l_4354;
	case 17241ULL: goto x86_l_4359;
	case 17246ULL: goto x86_l_435e;
	case 17248ULL: goto x86_l_4360;
	case 17251ULL: goto x86_l_4363;
	case 17253ULL: goto x86_l_4365;
	case 17255ULL: goto x86_l_4367;
	case 17261ULL: goto x86_l_436d;
	case 17264ULL: goto x86_l_4370;
	case 17270ULL: goto x86_l_4376;
	case 17275ULL: goto x86_l_437b;
	case 17281ULL: goto x86_l_4381;
	case 17285ULL: goto x86_l_4385;
	case 17292ULL: goto x86_l_438c;
	case 17295ULL: goto x86_l_438f;
	case 17300ULL: goto x86_l_4394;
	case 17305ULL: goto x86_l_4399;
	case 17312ULL: goto x86_l_43a0;
	case 17316ULL: goto x86_l_43a4;
	case 17323ULL: goto x86_l_43ab;
	case 17328ULL: goto x86_l_43b0;
	case 17330ULL: goto x86_l_43b2;
	case 17334ULL: goto x86_l_43b6;
	case 17341ULL: goto x86_l_43bd;
	case 17344ULL: goto x86_l_43c0;
	case 17351ULL: goto x86_l_43c7;
	case 17360ULL: goto x86_l_43d0;
	case 17364ULL: goto x86_l_43d4;
	case 17369ULL: goto x86_l_43d9;
	case 17374ULL: goto x86_l_43de;
	case 17379ULL: goto x86_l_43e3;
	case 17384ULL: goto x86_l_43e8;
	case 17386ULL: goto x86_l_43ea;
	case 17391ULL: goto x86_l_43ef;
	case 17393ULL: goto x86_l_43f1;
	case 17396ULL: goto x86_l_43f4;
	case 17402ULL: goto x86_l_43fa;
	case 17405ULL: goto x86_l_43fd;
	case 17411ULL: goto x86_l_4403;
	case 17416ULL: goto x86_l_4408;
	case 17422ULL: goto x86_l_440e;
	case 17426ULL: goto x86_l_4412;
	case 17433ULL: goto x86_l_4419;
	case 17438ULL: goto x86_l_441e;
	case 17443ULL: goto x86_l_4423;
	case 17450ULL: goto x86_l_442a;
	case 17454ULL: goto x86_l_442e;
	case 17461ULL: goto x86_l_4435;
	case 17466ULL: goto x86_l_443a;
	case 17471ULL: goto x86_l_443f;
	case 17473ULL: goto x86_l_4441;
	case 17476ULL: goto x86_l_4444;
	case 17478ULL: goto x86_l_4446;
	case 17480ULL: goto x86_l_4448;
	case 17486ULL: goto x86_l_444e;
	case 17489ULL: goto x86_l_4451;
	case 17495ULL: goto x86_l_4457;
	case 17500ULL: goto x86_l_445c;
	case 17506ULL: goto x86_l_4462;
	case 17510ULL: goto x86_l_4466;
	case 17517ULL: goto x86_l_446d;
	case 17520ULL: goto x86_l_4470;
	case 17525ULL: goto x86_l_4475;
	case 17530ULL: goto x86_l_447a;
	case 17537ULL: goto x86_l_4481;
	case 17541ULL: goto x86_l_4485;
	case 17548ULL: goto x86_l_448c;
	case 17553ULL: goto x86_l_4491;
	case 17555ULL: goto x86_l_4493;
	case 17559ULL: goto x86_l_4497;
	case 17566ULL: goto x86_l_449e;
	case 17569ULL: goto x86_l_44a1;
	case 17576ULL: goto x86_l_44a8;
	case 17585ULL: goto x86_l_44b1;
	case 17589ULL: goto x86_l_44b5;
	case 17594ULL: goto x86_l_44ba;
	case 17599ULL: goto x86_l_44bf;
	case 17604ULL: goto x86_l_44c4;
	case 17609ULL: goto x86_l_44c9;
	case 17611ULL: goto x86_l_44cb;
	case 17616ULL: goto x86_l_44d0;
	case 17618ULL: goto x86_l_44d2;
	case 17621ULL: goto x86_l_44d5;
	case 17627ULL: goto x86_l_44db;
	case 17630ULL: goto x86_l_44de;
	case 17636ULL: goto x86_l_44e4;
	case 17641ULL: goto x86_l_44e9;
	case 17647ULL: goto x86_l_44ef;
	case 17651ULL: goto x86_l_44f3;
	case 17658ULL: goto x86_l_44fa;
	case 17663ULL: goto x86_l_44ff;
	case 17668ULL: goto x86_l_4504;
	case 17675ULL: goto x86_l_450b;
	case 17679ULL: goto x86_l_450f;
	case 17686ULL: goto x86_l_4516;
	case 17691ULL: goto x86_l_451b;
	case 17696ULL: goto x86_l_4520;
	case 17698ULL: goto x86_l_4522;
	case 17701ULL: goto x86_l_4525;
	case 17703ULL: goto x86_l_4527;
	case 17705ULL: goto x86_l_4529;
	case 17711ULL: goto x86_l_452f;
	case 17714ULL: goto x86_l_4532;
	case 17720ULL: goto x86_l_4538;
	case 17725ULL: goto x86_l_453d;
	case 17731ULL: goto x86_l_4543;
	case 17735ULL: goto x86_l_4547;
	case 17742ULL: goto x86_l_454e;
	case 17745ULL: goto x86_l_4551;
	case 17750ULL: goto x86_l_4556;
	case 17755ULL: goto x86_l_455b;
	case 17762ULL: goto x86_l_4562;
	case 17766ULL: goto x86_l_4566;
	case 17773ULL: goto x86_l_456d;
	case 17778ULL: goto x86_l_4572;
	case 17780ULL: goto x86_l_4574;
	case 17784ULL: goto x86_l_4578;
	case 17791ULL: goto x86_l_457f;
	case 17794ULL: goto x86_l_4582;
	case 17801ULL: goto x86_l_4589;
	case 17810ULL: goto x86_l_4592;
	case 17814ULL: goto x86_l_4596;
	case 17819ULL: goto x86_l_459b;
	case 17824ULL: goto x86_l_45a0;
	case 17829ULL: goto x86_l_45a5;
	case 17834ULL: goto x86_l_45aa;
	case 17836ULL: goto x86_l_45ac;
	case 17841ULL: goto x86_l_45b1;
	case 17843ULL: goto x86_l_45b3;
	case 17846ULL: goto x86_l_45b6;
	case 17852ULL: goto x86_l_45bc;
	case 17855ULL: goto x86_l_45bf;
	case 17861ULL: goto x86_l_45c5;
	case 17866ULL: goto x86_l_45ca;
	case 17872ULL: goto x86_l_45d0;
	case 17876ULL: goto x86_l_45d4;
	case 17883ULL: goto x86_l_45db;
	case 17888ULL: goto x86_l_45e0;
	case 17893ULL: goto x86_l_45e5;
	case 17900ULL: goto x86_l_45ec;
	case 17904ULL: goto x86_l_45f0;
	case 17911ULL: goto x86_l_45f7;
	case 17916ULL: goto x86_l_45fc;
	case 17921ULL: goto x86_l_4601;
	case 17923ULL: goto x86_l_4603;
	case 17926ULL: goto x86_l_4606;
	case 17928ULL: goto x86_l_4608;
	case 17930ULL: goto x86_l_460a;
	case 17936ULL: goto x86_l_4610;
	case 17939ULL: goto x86_l_4613;
	case 17945ULL: goto x86_l_4619;
	case 17950ULL: goto x86_l_461e;
	case 17956ULL: goto x86_l_4624;
	case 17960ULL: goto x86_l_4628;
	case 17967ULL: goto x86_l_462f;
	case 17970ULL: goto x86_l_4632;
	case 17975ULL: goto x86_l_4637;
	case 17980ULL: goto x86_l_463c;
	case 17987ULL: goto x86_l_4643;
	case 17991ULL: goto x86_l_4647;
	case 17998ULL: goto x86_l_464e;
	case 18003ULL: goto x86_l_4653;
	case 18005ULL: goto x86_l_4655;
	case 18009ULL: goto x86_l_4659;
	case 18016ULL: goto x86_l_4660;
	case 18019ULL: goto x86_l_4663;
	case 18026ULL: goto x86_l_466a;
	case 18035ULL: goto x86_l_4673;
	case 18039ULL: goto x86_l_4677;
	case 18044ULL: goto x86_l_467c;
	case 18049ULL: goto x86_l_4681;
	case 18054ULL: goto x86_l_4686;
	case 18059ULL: goto x86_l_468b;
	case 18061ULL: goto x86_l_468d;
	case 18066ULL: goto x86_l_4692;
	case 18068ULL: goto x86_l_4694;
	case 18071ULL: goto x86_l_4697;
	case 18077ULL: goto x86_l_469d;
	case 18080ULL: goto x86_l_46a0;
	case 18086ULL: goto x86_l_46a6;
	case 18091ULL: goto x86_l_46ab;
	case 18097ULL: goto x86_l_46b1;
	case 18101ULL: goto x86_l_46b5;
	case 18108ULL: goto x86_l_46bc;
	case 18113ULL: goto x86_l_46c1;
	case 18118ULL: goto x86_l_46c6;
	case 18125ULL: goto x86_l_46cd;
	case 18129ULL: goto x86_l_46d1;
	case 18136ULL: goto x86_l_46d8;
	case 18141ULL: goto x86_l_46dd;
	case 18146ULL: goto x86_l_46e2;
	case 18148ULL: goto x86_l_46e4;
	case 18151ULL: goto x86_l_46e7;
	case 18153ULL: goto x86_l_46e9;
	case 18155ULL: goto x86_l_46eb;
	case 18161ULL: goto x86_l_46f1;
	case 18164ULL: goto x86_l_46f4;
	case 18170ULL: goto x86_l_46fa;
	case 18175ULL: goto x86_l_46ff;
	case 18181ULL: goto x86_l_4705;
	case 18185ULL: goto x86_l_4709;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3fe6:
	/* 0x3fe6: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fe9:
	/* 0x3fe9: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_3feb:
	/* 0x3feb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fed:
	/* 0x3fed: jle    1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5776ULL;
	}
x86_l_3ff3:
	/* 0x3ff3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ff6:
	/* 0x3ff6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3ffc:
	/* 0x3ffc: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4002:
	/* 0x4002: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4006:
	/* 0x4006: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_400d:
	/* 0x400d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4010:
	/* 0x4010: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4015:
	/* 0x4015: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_401a:
	/* 0x401a: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4021:
	/* 0x4021: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4025:
	/* 0x4025: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_402c:
	/* 0x402c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4031:
	/* 0x4031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4033:
	/* 0x4033: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4037:
	/* 0x4037: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_403e:
	/* 0x403e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4041:
	/* 0x4041: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4048:
	/* 0x4048: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4051:
	/* 0x4051: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4055:
	/* 0x4055: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_405a:
	/* 0x405a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_405f:
	/* 0x405f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4064:
	/* 0x4064: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4069:
	/* 0x4069: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_406b:
	/* 0x406b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4070:
	/* 0x4070: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_4072:
	/* 0x4072: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4075:
	/* 0x4075: je     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5776ULL;
	}
x86_l_407b:
	/* 0x407b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_407e:
	/* 0x407e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4084:
	/* 0x4084: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_408a:
	/* 0x408a: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_408e:
	/* 0x408e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4095:
	/* 0x4095: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_409a:
	/* 0x409a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_409f:
	/* 0x409f: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40a6:
	/* 0x40a6: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_40aa:
	/* 0x40aa: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_40b1:
	/* 0x40b1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40b6:
	/* 0x40b6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_40bb:
	/* 0x40bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40bd:
	/* 0x40bd: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40c0:
	/* 0x40c0: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_40c2:
	/* 0x40c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40c4:
	/* 0x40c4: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_40ca:
	/* 0x40ca: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40cd:
	/* 0x40cd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_40d3:
	/* 0x40d3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40d8:
	/* 0x40d8: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_40de:
	/* 0x40de: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_40e2:
	/* 0x40e2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_40e9:
	/* 0x40e9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_40ec:
	/* 0x40ec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40f1:
	/* 0x40f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40f6:
	/* 0x40f6: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40fd:
	/* 0x40fd: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4101:
	/* 0x4101: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4108:
	/* 0x4108: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_410d:
	/* 0x410d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_410f:
	/* 0x410f: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4113:
	/* 0x4113: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_411a:
	/* 0x411a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_411d:
	/* 0x411d: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4124:
	/* 0x4124: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_412d:
	/* 0x412d: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4131:
	/* 0x4131: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4136:
	/* 0x4136: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_413b:
	/* 0x413b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4140:
	/* 0x4140: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4145:
	/* 0x4145: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4147:
	/* 0x4147: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_414c:
	/* 0x414c: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_414e:
	/* 0x414e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4151:
	/* 0x4151: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4157:
	/* 0x4157: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_415a:
	/* 0x415a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4160:
	/* 0x4160: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4165:
	/* 0x4165: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_416b:
	/* 0x416b: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_416f:
	/* 0x416f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4176:
	/* 0x4176: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_417b:
	/* 0x417b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4180:
	/* 0x4180: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4187:
	/* 0x4187: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_418b:
	/* 0x418b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4192:
	/* 0x4192: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4197:
	/* 0x4197: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_419c:
	/* 0x419c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_419e:
	/* 0x419e: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41a1:
	/* 0x41a1: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_41a3:
	/* 0x41a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41a5:
	/* 0x41a5: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_41ab:
	/* 0x41ab: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41ae:
	/* 0x41ae: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_41b4:
	/* 0x41b4: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41b9:
	/* 0x41b9: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_41bf:
	/* 0x41bf: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_41c3:
	/* 0x41c3: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41ca:
	/* 0x41ca: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_41cd:
	/* 0x41cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41d2:
	/* 0x41d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41d7:
	/* 0x41d7: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_41de:
	/* 0x41de: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_41e2:
	/* 0x41e2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41e9:
	/* 0x41e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41ee:
	/* 0x41ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41f0:
	/* 0x41f0: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41f4:
	/* 0x41f4: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_41fb:
	/* 0x41fb: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_41fe:
	/* 0x41fe: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4205:
	/* 0x4205: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_420e:
	/* 0x420e: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4212:
	/* 0x4212: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4217:
	/* 0x4217: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_421c:
	/* 0x421c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4221:
	/* 0x4221: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4226:
	/* 0x4226: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4228:
	/* 0x4228: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_422d:
	/* 0x422d: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_422f:
	/* 0x422f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4232:
	/* 0x4232: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4238:
	/* 0x4238: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_423b:
	/* 0x423b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4241:
	/* 0x4241: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4246:
	/* 0x4246: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_424c:
	/* 0x424c: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4250:
	/* 0x4250: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4257:
	/* 0x4257: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_425c:
	/* 0x425c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4261:
	/* 0x4261: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4268:
	/* 0x4268: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_426c:
	/* 0x426c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4273:
	/* 0x4273: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4278:
	/* 0x4278: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_427d:
	/* 0x427d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_427f:
	/* 0x427f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4282:
	/* 0x4282: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_4284:
	/* 0x4284: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4286:
	/* 0x4286: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_428c:
	/* 0x428c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_428f:
	/* 0x428f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4295:
	/* 0x4295: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_429a:
	/* 0x429a: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_42a0:
	/* 0x42a0: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_42a4:
	/* 0x42a4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42ab:
	/* 0x42ab: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_42ae:
	/* 0x42ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42b3:
	/* 0x42b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42b8:
	/* 0x42b8: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_42bf:
	/* 0x42bf: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_42c3:
	/* 0x42c3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42ca:
	/* 0x42ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42cf:
	/* 0x42cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42d1:
	/* 0x42d1: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_42d5:
	/* 0x42d5: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_42dc:
	/* 0x42dc: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_42df:
	/* 0x42df: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_42e6:
	/* 0x42e6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_42ef:
	/* 0x42ef: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_42f3:
	/* 0x42f3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42f8:
	/* 0x42f8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_42fd:
	/* 0x42fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4302:
	/* 0x4302: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4307:
	/* 0x4307: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4309:
	/* 0x4309: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_430e:
	/* 0x430e: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_4310:
	/* 0x4310: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4313:
	/* 0x4313: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4319:
	/* 0x4319: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_431c:
	/* 0x431c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4322:
	/* 0x4322: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4327:
	/* 0x4327: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_432d:
	/* 0x432d: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4331:
	/* 0x4331: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4338:
	/* 0x4338: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_433d:
	/* 0x433d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4342:
	/* 0x4342: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4349:
	/* 0x4349: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_434d:
	/* 0x434d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4354:
	/* 0x4354: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4359:
	/* 0x4359: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_435e:
	/* 0x435e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4360:
	/* 0x4360: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4363:
	/* 0x4363: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_4365:
	/* 0x4365: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4367:
	/* 0x4367: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_436d:
	/* 0x436d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4370:
	/* 0x4370: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4376:
	/* 0x4376: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_437b:
	/* 0x437b: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4381:
	/* 0x4381: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4385:
	/* 0x4385: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_438c:
	/* 0x438c: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_438f:
	/* 0x438f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4394:
	/* 0x4394: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4399:
	/* 0x4399: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43a0:
	/* 0x43a0: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_43a4:
	/* 0x43a4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_43ab:
	/* 0x43ab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_43b0:
	/* 0x43b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43b2:
	/* 0x43b2: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_43b6:
	/* 0x43b6: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_43bd:
	/* 0x43bd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_43c0:
	/* 0x43c0: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_43c7:
	/* 0x43c7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_43d0:
	/* 0x43d0: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_43d4:
	/* 0x43d4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43d9:
	/* 0x43d9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_43de:
	/* 0x43de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43e3:
	/* 0x43e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43e8:
	/* 0x43e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43ea:
	/* 0x43ea: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43ef:
	/* 0x43ef: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_43f1:
	/* 0x43f1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_43f4:
	/* 0x43f4: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_43fa:
	/* 0x43fa: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_43fd:
	/* 0x43fd: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4403:
	/* 0x4403: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4408:
	/* 0x4408: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_440e:
	/* 0x440e: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4412:
	/* 0x4412: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4419:
	/* 0x4419: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_441e:
	/* 0x441e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4423:
	/* 0x4423: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_442a:
	/* 0x442a: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_442e:
	/* 0x442e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4435:
	/* 0x4435: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_443a:
	/* 0x443a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_443f:
	/* 0x443f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4441:
	/* 0x4441: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4444:
	/* 0x4444: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_4446:
	/* 0x4446: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4448:
	/* 0x4448: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_444e:
	/* 0x444e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4451:
	/* 0x4451: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4457:
	/* 0x4457: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_445c:
	/* 0x445c: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4462:
	/* 0x4462: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4466:
	/* 0x4466: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_446d:
	/* 0x446d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4470:
	/* 0x4470: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4475:
	/* 0x4475: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_447a:
	/* 0x447a: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4481:
	/* 0x4481: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4485:
	/* 0x4485: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_448c:
	/* 0x448c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4491:
	/* 0x4491: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4493:
	/* 0x4493: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4497:
	/* 0x4497: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_449e:
	/* 0x449e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_44a1:
	/* 0x44a1: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_44a8:
	/* 0x44a8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_44b1:
	/* 0x44b1: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_44b5:
	/* 0x44b5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44ba:
	/* 0x44ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_44bf:
	/* 0x44bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44c4:
	/* 0x44c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44c9:
	/* 0x44c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44cb:
	/* 0x44cb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44d0:
	/* 0x44d0: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_44d2:
	/* 0x44d2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_44d5:
	/* 0x44d5: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_44db:
	/* 0x44db: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44de:
	/* 0x44de: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_44e4:
	/* 0x44e4: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44e9:
	/* 0x44e9: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_44ef:
	/* 0x44ef: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_44f3:
	/* 0x44f3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_44fa:
	/* 0x44fa: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_44ff:
	/* 0x44ff: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4504:
	/* 0x4504: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_450b:
	/* 0x450b: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_450f:
	/* 0x450f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4516:
	/* 0x4516: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_451b:
	/* 0x451b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4520:
	/* 0x4520: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4522:
	/* 0x4522: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4525:
	/* 0x4525: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_4527:
	/* 0x4527: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4529:
	/* 0x4529: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_452f:
	/* 0x452f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4532:
	/* 0x4532: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4538:
	/* 0x4538: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_453d:
	/* 0x453d: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4543:
	/* 0x4543: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4547:
	/* 0x4547: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_454e:
	/* 0x454e: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4551:
	/* 0x4551: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4556:
	/* 0x4556: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_455b:
	/* 0x455b: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4562:
	/* 0x4562: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4566:
	/* 0x4566: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_456d:
	/* 0x456d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4572:
	/* 0x4572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4574:
	/* 0x4574: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4578:
	/* 0x4578: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_457f:
	/* 0x457f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4582:
	/* 0x4582: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4589:
	/* 0x4589: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4592:
	/* 0x4592: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4596:
	/* 0x4596: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_459b:
	/* 0x459b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45a0:
	/* 0x45a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45a5:
	/* 0x45a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45aa:
	/* 0x45aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45ac:
	/* 0x45ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45b1:
	/* 0x45b1: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_45b3:
	/* 0x45b3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_45b6:
	/* 0x45b6: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_45bc:
	/* 0x45bc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_45bf:
	/* 0x45bf: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_45c5:
	/* 0x45c5: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45ca:
	/* 0x45ca: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_45d0:
	/* 0x45d0: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_45d4:
	/* 0x45d4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_45db:
	/* 0x45db: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_45e0:
	/* 0x45e0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_45e5:
	/* 0x45e5: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_45ec:
	/* 0x45ec: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_45f0:
	/* 0x45f0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_45f7:
	/* 0x45f7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45fc:
	/* 0x45fc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4601:
	/* 0x4601: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4603:
	/* 0x4603: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4606:
	/* 0x4606: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_4608:
	/* 0x4608: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_460a:
	/* 0x460a: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_4610:
	/* 0x4610: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4613:
	/* 0x4613: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4619:
	/* 0x4619: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_461e:
	/* 0x461e: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4624:
	/* 0x4624: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4628:
	/* 0x4628: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_462f:
	/* 0x462f: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4632:
	/* 0x4632: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4637:
	/* 0x4637: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_463c:
	/* 0x463c: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4643:
	/* 0x4643: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4647:
	/* 0x4647: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_464e:
	/* 0x464e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4653:
	/* 0x4653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4655:
	/* 0x4655: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4659:
	/* 0x4659: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4660:
	/* 0x4660: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4663:
	/* 0x4663: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_466a:
	/* 0x466a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4673:
	/* 0x4673: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4677:
	/* 0x4677: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_467c:
	/* 0x467c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4681:
	/* 0x4681: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4686:
	/* 0x4686: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_468b:
	/* 0x468b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_468d:
	/* 0x468d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4692:
	/* 0x4692: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_4694:
	/* 0x4694: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4697:
	/* 0x4697: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_469d:
	/* 0x469d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_46a0:
	/* 0x46a0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_46a6:
	/* 0x46a6: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46ab:
	/* 0x46ab: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_46b1:
	/* 0x46b1: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_46b5:
	/* 0x46b5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_46bc:
	/* 0x46bc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_46c1:
	/* 0x46c1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_46c6:
	/* 0x46c6: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_46cd:
	/* 0x46cd: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_46d1:
	/* 0x46d1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_46d8:
	/* 0x46d8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46dd:
	/* 0x46dd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_46e2:
	/* 0x46e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46e4:
	/* 0x46e4: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e7:
	/* 0x46e7: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_46e9:
	/* 0x46e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46eb:
	/* 0x46eb: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_46f1:
	/* 0x46f1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_46f4:
	/* 0x46f4: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_46fa:
	/* 0x46fa: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46ff:
	/* 0x46ff: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4705:
	/* 0x4705: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4709:
	/* 0x4709: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
	return 18192ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18192ULL: goto x86_l_4710;
	case 18195ULL: goto x86_l_4713;
	case 18200ULL: goto x86_l_4718;
	case 18205ULL: goto x86_l_471d;
	case 18212ULL: goto x86_l_4724;
	case 18216ULL: goto x86_l_4728;
	case 18223ULL: goto x86_l_472f;
	case 18228ULL: goto x86_l_4734;
	case 18230ULL: goto x86_l_4736;
	case 18234ULL: goto x86_l_473a;
	case 18241ULL: goto x86_l_4741;
	case 18244ULL: goto x86_l_4744;
	case 18251ULL: goto x86_l_474b;
	case 18260ULL: goto x86_l_4754;
	case 18264ULL: goto x86_l_4758;
	case 18269ULL: goto x86_l_475d;
	case 18274ULL: goto x86_l_4762;
	case 18279ULL: goto x86_l_4767;
	case 18284ULL: goto x86_l_476c;
	case 18286ULL: goto x86_l_476e;
	case 18291ULL: goto x86_l_4773;
	case 18293ULL: goto x86_l_4775;
	case 18296ULL: goto x86_l_4778;
	case 18302ULL: goto x86_l_477e;
	case 18305ULL: goto x86_l_4781;
	case 18311ULL: goto x86_l_4787;
	case 18316ULL: goto x86_l_478c;
	case 18322ULL: goto x86_l_4792;
	case 18326ULL: goto x86_l_4796;
	case 18333ULL: goto x86_l_479d;
	case 18338ULL: goto x86_l_47a2;
	case 18343ULL: goto x86_l_47a7;
	case 18350ULL: goto x86_l_47ae;
	case 18354ULL: goto x86_l_47b2;
	case 18361ULL: goto x86_l_47b9;
	case 18366ULL: goto x86_l_47be;
	case 18371ULL: goto x86_l_47c3;
	case 18373ULL: goto x86_l_47c5;
	case 18376ULL: goto x86_l_47c8;
	case 18378ULL: goto x86_l_47ca;
	case 18380ULL: goto x86_l_47cc;
	case 18386ULL: goto x86_l_47d2;
	case 18389ULL: goto x86_l_47d5;
	case 18395ULL: goto x86_l_47db;
	case 18400ULL: goto x86_l_47e0;
	case 18406ULL: goto x86_l_47e6;
	case 18410ULL: goto x86_l_47ea;
	case 18417ULL: goto x86_l_47f1;
	case 18420ULL: goto x86_l_47f4;
	case 18425ULL: goto x86_l_47f9;
	case 18430ULL: goto x86_l_47fe;
	case 18437ULL: goto x86_l_4805;
	case 18441ULL: goto x86_l_4809;
	case 18448ULL: goto x86_l_4810;
	case 18453ULL: goto x86_l_4815;
	case 18455ULL: goto x86_l_4817;
	case 18459ULL: goto x86_l_481b;
	case 18466ULL: goto x86_l_4822;
	case 18469ULL: goto x86_l_4825;
	case 18476ULL: goto x86_l_482c;
	case 18485ULL: goto x86_l_4835;
	case 18489ULL: goto x86_l_4839;
	case 18494ULL: goto x86_l_483e;
	case 18499ULL: goto x86_l_4843;
	case 18504ULL: goto x86_l_4848;
	case 18509ULL: goto x86_l_484d;
	case 18511ULL: goto x86_l_484f;
	case 18516ULL: goto x86_l_4854;
	case 18518ULL: goto x86_l_4856;
	case 18521ULL: goto x86_l_4859;
	case 18527ULL: goto x86_l_485f;
	case 18530ULL: goto x86_l_4862;
	case 18536ULL: goto x86_l_4868;
	case 18541ULL: goto x86_l_486d;
	case 18547ULL: goto x86_l_4873;
	case 18551ULL: goto x86_l_4877;
	case 18558ULL: goto x86_l_487e;
	case 18563ULL: goto x86_l_4883;
	case 18568ULL: goto x86_l_4888;
	case 18575ULL: goto x86_l_488f;
	case 18579ULL: goto x86_l_4893;
	case 18586ULL: goto x86_l_489a;
	case 18591ULL: goto x86_l_489f;
	case 18596ULL: goto x86_l_48a4;
	case 18598ULL: goto x86_l_48a6;
	case 18601ULL: goto x86_l_48a9;
	case 18603ULL: goto x86_l_48ab;
	case 18605ULL: goto x86_l_48ad;
	case 18611ULL: goto x86_l_48b3;
	case 18614ULL: goto x86_l_48b6;
	case 18620ULL: goto x86_l_48bc;
	case 18625ULL: goto x86_l_48c1;
	case 18631ULL: goto x86_l_48c7;
	case 18635ULL: goto x86_l_48cb;
	case 18642ULL: goto x86_l_48d2;
	case 18645ULL: goto x86_l_48d5;
	case 18650ULL: goto x86_l_48da;
	case 18655ULL: goto x86_l_48df;
	case 18662ULL: goto x86_l_48e6;
	case 18666ULL: goto x86_l_48ea;
	case 18673ULL: goto x86_l_48f1;
	case 18678ULL: goto x86_l_48f6;
	case 18680ULL: goto x86_l_48f8;
	case 18684ULL: goto x86_l_48fc;
	case 18691ULL: goto x86_l_4903;
	case 18694ULL: goto x86_l_4906;
	case 18701ULL: goto x86_l_490d;
	case 18710ULL: goto x86_l_4916;
	case 18714ULL: goto x86_l_491a;
	case 18719ULL: goto x86_l_491f;
	case 18724ULL: goto x86_l_4924;
	case 18729ULL: goto x86_l_4929;
	case 18734ULL: goto x86_l_492e;
	case 18736ULL: goto x86_l_4930;
	case 18741ULL: goto x86_l_4935;
	case 18743ULL: goto x86_l_4937;
	case 18746ULL: goto x86_l_493a;
	case 18752ULL: goto x86_l_4940;
	case 18755ULL: goto x86_l_4943;
	case 18761ULL: goto x86_l_4949;
	case 18766ULL: goto x86_l_494e;
	case 18772ULL: goto x86_l_4954;
	case 18776ULL: goto x86_l_4958;
	case 18783ULL: goto x86_l_495f;
	case 18788ULL: goto x86_l_4964;
	case 18793ULL: goto x86_l_4969;
	case 18800ULL: goto x86_l_4970;
	case 18804ULL: goto x86_l_4974;
	case 18811ULL: goto x86_l_497b;
	case 18816ULL: goto x86_l_4980;
	case 18821ULL: goto x86_l_4985;
	case 18823ULL: goto x86_l_4987;
	case 18826ULL: goto x86_l_498a;
	case 18828ULL: goto x86_l_498c;
	case 18830ULL: goto x86_l_498e;
	case 18836ULL: goto x86_l_4994;
	case 18839ULL: goto x86_l_4997;
	case 18845ULL: goto x86_l_499d;
	case 18850ULL: goto x86_l_49a2;
	case 18856ULL: goto x86_l_49a8;
	case 18860ULL: goto x86_l_49ac;
	case 18867ULL: goto x86_l_49b3;
	case 18870ULL: goto x86_l_49b6;
	case 18875ULL: goto x86_l_49bb;
	case 18880ULL: goto x86_l_49c0;
	case 18887ULL: goto x86_l_49c7;
	case 18891ULL: goto x86_l_49cb;
	case 18898ULL: goto x86_l_49d2;
	case 18903ULL: goto x86_l_49d7;
	case 18905ULL: goto x86_l_49d9;
	case 18909ULL: goto x86_l_49dd;
	case 18916ULL: goto x86_l_49e4;
	case 18919ULL: goto x86_l_49e7;
	case 18926ULL: goto x86_l_49ee;
	case 18935ULL: goto x86_l_49f7;
	case 18939ULL: goto x86_l_49fb;
	case 18944ULL: goto x86_l_4a00;
	case 18949ULL: goto x86_l_4a05;
	case 18954ULL: goto x86_l_4a0a;
	case 18959ULL: goto x86_l_4a0f;
	case 18961ULL: goto x86_l_4a11;
	case 18966ULL: goto x86_l_4a16;
	case 18968ULL: goto x86_l_4a18;
	case 18971ULL: goto x86_l_4a1b;
	case 18977ULL: goto x86_l_4a21;
	case 18980ULL: goto x86_l_4a24;
	case 18986ULL: goto x86_l_4a2a;
	case 18991ULL: goto x86_l_4a2f;
	case 18997ULL: goto x86_l_4a35;
	case 19001ULL: goto x86_l_4a39;
	case 19008ULL: goto x86_l_4a40;
	case 19013ULL: goto x86_l_4a45;
	case 19018ULL: goto x86_l_4a4a;
	case 19025ULL: goto x86_l_4a51;
	case 19029ULL: goto x86_l_4a55;
	case 19036ULL: goto x86_l_4a5c;
	case 19041ULL: goto x86_l_4a61;
	case 19046ULL: goto x86_l_4a66;
	case 19048ULL: goto x86_l_4a68;
	case 19051ULL: goto x86_l_4a6b;
	case 19053ULL: goto x86_l_4a6d;
	case 19055ULL: goto x86_l_4a6f;
	case 19061ULL: goto x86_l_4a75;
	case 19064ULL: goto x86_l_4a78;
	case 19070ULL: goto x86_l_4a7e;
	case 19075ULL: goto x86_l_4a83;
	case 19081ULL: goto x86_l_4a89;
	case 19085ULL: goto x86_l_4a8d;
	case 19092ULL: goto x86_l_4a94;
	case 19095ULL: goto x86_l_4a97;
	case 19100ULL: goto x86_l_4a9c;
	case 19105ULL: goto x86_l_4aa1;
	case 19112ULL: goto x86_l_4aa8;
	case 19116ULL: goto x86_l_4aac;
	case 19123ULL: goto x86_l_4ab3;
	case 19128ULL: goto x86_l_4ab8;
	case 19130ULL: goto x86_l_4aba;
	case 19134ULL: goto x86_l_4abe;
	case 19141ULL: goto x86_l_4ac5;
	case 19144ULL: goto x86_l_4ac8;
	case 19151ULL: goto x86_l_4acf;
	case 19160ULL: goto x86_l_4ad8;
	case 19164ULL: goto x86_l_4adc;
	case 19169ULL: goto x86_l_4ae1;
	case 19174ULL: goto x86_l_4ae6;
	case 19179ULL: goto x86_l_4aeb;
	case 19184ULL: goto x86_l_4af0;
	case 19186ULL: goto x86_l_4af2;
	case 19191ULL: goto x86_l_4af7;
	case 19193ULL: goto x86_l_4af9;
	case 19196ULL: goto x86_l_4afc;
	case 19202ULL: goto x86_l_4b02;
	case 19205ULL: goto x86_l_4b05;
	case 19211ULL: goto x86_l_4b0b;
	case 19216ULL: goto x86_l_4b10;
	case 19222ULL: goto x86_l_4b16;
	case 19226ULL: goto x86_l_4b1a;
	case 19233ULL: goto x86_l_4b21;
	case 19238ULL: goto x86_l_4b26;
	case 19243ULL: goto x86_l_4b2b;
	case 19250ULL: goto x86_l_4b32;
	case 19254ULL: goto x86_l_4b36;
	case 19261ULL: goto x86_l_4b3d;
	case 19266ULL: goto x86_l_4b42;
	case 19271ULL: goto x86_l_4b47;
	case 19273ULL: goto x86_l_4b49;
	case 19276ULL: goto x86_l_4b4c;
	case 19278ULL: goto x86_l_4b4e;
	case 19280ULL: goto x86_l_4b50;
	case 19286ULL: goto x86_l_4b56;
	case 19289ULL: goto x86_l_4b59;
	case 19295ULL: goto x86_l_4b5f;
	case 19300ULL: goto x86_l_4b64;
	case 19306ULL: goto x86_l_4b6a;
	case 19310ULL: goto x86_l_4b6e;
	case 19317ULL: goto x86_l_4b75;
	case 19320ULL: goto x86_l_4b78;
	case 19325ULL: goto x86_l_4b7d;
	case 19330ULL: goto x86_l_4b82;
	case 19337ULL: goto x86_l_4b89;
	case 19341ULL: goto x86_l_4b8d;
	case 19348ULL: goto x86_l_4b94;
	case 19353ULL: goto x86_l_4b99;
	case 19355ULL: goto x86_l_4b9b;
	case 19359ULL: goto x86_l_4b9f;
	case 19366ULL: goto x86_l_4ba6;
	case 19369ULL: goto x86_l_4ba9;
	case 19376ULL: goto x86_l_4bb0;
	case 19385ULL: goto x86_l_4bb9;
	case 19392ULL: goto x86_l_4bc0;
	case 19397ULL: goto x86_l_4bc5;
	case 19402ULL: goto x86_l_4bca;
	case 19407ULL: goto x86_l_4bcf;
	case 19412ULL: goto x86_l_4bd4;
	case 19414ULL: goto x86_l_4bd6;
	case 19419ULL: goto x86_l_4bdb;
	case 19421ULL: goto x86_l_4bdd;
	case 19424ULL: goto x86_l_4be0;
	case 19430ULL: goto x86_l_4be6;
	case 19433ULL: goto x86_l_4be9;
	case 19439ULL: goto x86_l_4bef;
	case 19444ULL: goto x86_l_4bf4;
	case 19450ULL: goto x86_l_4bfa;
	case 19454ULL: goto x86_l_4bfe;
	case 19461ULL: goto x86_l_4c05;
	case 19466ULL: goto x86_l_4c0a;
	case 19471ULL: goto x86_l_4c0f;
	case 19478ULL: goto x86_l_4c16;
	case 19482ULL: goto x86_l_4c1a;
	case 19489ULL: goto x86_l_4c21;
	case 19494ULL: goto x86_l_4c26;
	case 19499ULL: goto x86_l_4c2b;
	case 19501ULL: goto x86_l_4c2d;
	case 19504ULL: goto x86_l_4c30;
	case 19506ULL: goto x86_l_4c32;
	case 19508ULL: goto x86_l_4c34;
	case 19514ULL: goto x86_l_4c3a;
	case 19517ULL: goto x86_l_4c3d;
	case 19523ULL: goto x86_l_4c43;
	case 19528ULL: goto x86_l_4c48;
	case 19534ULL: goto x86_l_4c4e;
	case 19538ULL: goto x86_l_4c52;
	case 19545ULL: goto x86_l_4c59;
	case 19548ULL: goto x86_l_4c5c;
	case 19553ULL: goto x86_l_4c61;
	case 19558ULL: goto x86_l_4c66;
	case 19565ULL: goto x86_l_4c6d;
	case 19569ULL: goto x86_l_4c71;
	case 19576ULL: goto x86_l_4c78;
	case 19581ULL: goto x86_l_4c7d;
	case 19583ULL: goto x86_l_4c7f;
	case 19587ULL: goto x86_l_4c83;
	case 19594ULL: goto x86_l_4c8a;
	case 19597ULL: goto x86_l_4c8d;
	case 19604ULL: goto x86_l_4c94;
	case 19613ULL: goto x86_l_4c9d;
	case 19620ULL: goto x86_l_4ca4;
	case 19625ULL: goto x86_l_4ca9;
	case 19630ULL: goto x86_l_4cae;
	case 19635ULL: goto x86_l_4cb3;
	case 19640ULL: goto x86_l_4cb8;
	case 19642ULL: goto x86_l_4cba;
	case 19647ULL: goto x86_l_4cbf;
	case 19649ULL: goto x86_l_4cc1;
	case 19652ULL: goto x86_l_4cc4;
	case 19658ULL: goto x86_l_4cca;
	case 19661ULL: goto x86_l_4ccd;
	case 19667ULL: goto x86_l_4cd3;
	case 19672ULL: goto x86_l_4cd8;
	case 19678ULL: goto x86_l_4cde;
	case 19682ULL: goto x86_l_4ce2;
	case 19689ULL: goto x86_l_4ce9;
	case 19694ULL: goto x86_l_4cee;
	case 19699ULL: goto x86_l_4cf3;
	case 19706ULL: goto x86_l_4cfa;
	case 19710ULL: goto x86_l_4cfe;
	case 19717ULL: goto x86_l_4d05;
	case 19722ULL: goto x86_l_4d0a;
	case 19727ULL: goto x86_l_4d0f;
	case 19729ULL: goto x86_l_4d11;
	case 19732ULL: goto x86_l_4d14;
	case 19734ULL: goto x86_l_4d16;
	case 19736ULL: goto x86_l_4d18;
	case 19742ULL: goto x86_l_4d1e;
	case 19745ULL: goto x86_l_4d21;
	case 19751ULL: goto x86_l_4d27;
	case 19756ULL: goto x86_l_4d2c;
	case 19762ULL: goto x86_l_4d32;
	case 19766ULL: goto x86_l_4d36;
	case 19773ULL: goto x86_l_4d3d;
	case 19776ULL: goto x86_l_4d40;
	case 19781ULL: goto x86_l_4d45;
	case 19786ULL: goto x86_l_4d4a;
	case 19793ULL: goto x86_l_4d51;
	case 19797ULL: goto x86_l_4d55;
	case 19804ULL: goto x86_l_4d5c;
	case 19809ULL: goto x86_l_4d61;
	case 19811ULL: goto x86_l_4d63;
	case 19815ULL: goto x86_l_4d67;
	case 19822ULL: goto x86_l_4d6e;
	case 19825ULL: goto x86_l_4d71;
	case 19832ULL: goto x86_l_4d78;
	case 19841ULL: goto x86_l_4d81;
	case 19848ULL: goto x86_l_4d88;
	case 19853ULL: goto x86_l_4d8d;
	case 19858ULL: goto x86_l_4d92;
	case 19863ULL: goto x86_l_4d97;
	case 19868ULL: goto x86_l_4d9c;
	case 19870ULL: goto x86_l_4d9e;
	case 19875ULL: goto x86_l_4da3;
	case 19877ULL: goto x86_l_4da5;
	case 19880ULL: goto x86_l_4da8;
	case 19886ULL: goto x86_l_4dae;
	case 19889ULL: goto x86_l_4db1;
	case 19895ULL: goto x86_l_4db7;
	case 19900ULL: goto x86_l_4dbc;
	case 19906ULL: goto x86_l_4dc2;
	case 19910ULL: goto x86_l_4dc6;
	case 19917ULL: goto x86_l_4dcd;
	case 19922ULL: goto x86_l_4dd2;
	case 19927ULL: goto x86_l_4dd7;
	case 19934ULL: goto x86_l_4dde;
	case 19938ULL: goto x86_l_4de2;
	case 19945ULL: goto x86_l_4de9;
	case 19950ULL: goto x86_l_4dee;
	case 19955ULL: goto x86_l_4df3;
	case 19957ULL: goto x86_l_4df5;
	case 19960ULL: goto x86_l_4df8;
	case 19962ULL: goto x86_l_4dfa;
	case 19964ULL: goto x86_l_4dfc;
	case 19970ULL: goto x86_l_4e02;
	case 19973ULL: goto x86_l_4e05;
	case 19979ULL: goto x86_l_4e0b;
	case 19984ULL: goto x86_l_4e10;
	case 19990ULL: goto x86_l_4e16;
	case 19994ULL: goto x86_l_4e1a;
	case 20001ULL: goto x86_l_4e21;
	case 20004ULL: goto x86_l_4e24;
	case 20009ULL: goto x86_l_4e29;
	case 20014ULL: goto x86_l_4e2e;
	case 20021ULL: goto x86_l_4e35;
	case 20025ULL: goto x86_l_4e39;
	case 20032ULL: goto x86_l_4e40;
	case 20037ULL: goto x86_l_4e45;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4710:
	/* 0x4710: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4713:
	/* 0x4713: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4718:
	/* 0x4718: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_471d:
	/* 0x471d: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4724:
	/* 0x4724: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4728:
	/* 0x4728: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_472f:
	/* 0x472f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4734:
	/* 0x4734: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4736:
	/* 0x4736: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_473a:
	/* 0x473a: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4741:
	/* 0x4741: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4744:
	/* 0x4744: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_474b:
	/* 0x474b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4754:
	/* 0x4754: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4758:
	/* 0x4758: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_475d:
	/* 0x475d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4762:
	/* 0x4762: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4767:
	/* 0x4767: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_476c:
	/* 0x476c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_476e:
	/* 0x476e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4773:
	/* 0x4773: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_4775:
	/* 0x4775: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4778:
	/* 0x4778: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_477e:
	/* 0x477e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4781:
	/* 0x4781: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4787:
	/* 0x4787: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_478c:
	/* 0x478c: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4792:
	/* 0x4792: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4796:
	/* 0x4796: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_479d:
	/* 0x479d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_47a2:
	/* 0x47a2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_47a7:
	/* 0x47a7: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_47ae:
	/* 0x47ae: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_47b2:
	/* 0x47b2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_47b9:
	/* 0x47b9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47be:
	/* 0x47be: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_47c3:
	/* 0x47c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47c5:
	/* 0x47c5: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47c8:
	/* 0x47c8: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_47ca:
	/* 0x47ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47cc:
	/* 0x47cc: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_47d2:
	/* 0x47d2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_47d5:
	/* 0x47d5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_47db:
	/* 0x47db: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47e0:
	/* 0x47e0: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_47e6:
	/* 0x47e6: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_47ea:
	/* 0x47ea: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_47f1:
	/* 0x47f1: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_47f4:
	/* 0x47f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_47f9:
	/* 0x47f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_47fe:
	/* 0x47fe: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4805:
	/* 0x4805: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4809:
	/* 0x4809: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4810:
	/* 0x4810: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4815:
	/* 0x4815: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4817:
	/* 0x4817: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_481b:
	/* 0x481b: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4822:
	/* 0x4822: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4825:
	/* 0x4825: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_482c:
	/* 0x482c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4835:
	/* 0x4835: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4839:
	/* 0x4839: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_483e:
	/* 0x483e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4843:
	/* 0x4843: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4848:
	/* 0x4848: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_484d:
	/* 0x484d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_484f:
	/* 0x484f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4854:
	/* 0x4854: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_4856:
	/* 0x4856: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4859:
	/* 0x4859: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_485f:
	/* 0x485f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4862:
	/* 0x4862: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4868:
	/* 0x4868: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_486d:
	/* 0x486d: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4873:
	/* 0x4873: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4877:
	/* 0x4877: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_487e:
	/* 0x487e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4883:
	/* 0x4883: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4888:
	/* 0x4888: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_488f:
	/* 0x488f: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4893:
	/* 0x4893: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_489a:
	/* 0x489a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_489f:
	/* 0x489f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_48a4:
	/* 0x48a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48a6:
	/* 0x48a6: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48a9:
	/* 0x48a9: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_48ab:
	/* 0x48ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48ad:
	/* 0x48ad: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_48b3:
	/* 0x48b3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48b6:
	/* 0x48b6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_48bc:
	/* 0x48bc: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48c1:
	/* 0x48c1: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_48c7:
	/* 0x48c7: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_48cb:
	/* 0x48cb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_48d2:
	/* 0x48d2: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_48d5:
	/* 0x48d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_48da:
	/* 0x48da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_48df:
	/* 0x48df: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_48e6:
	/* 0x48e6: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_48ea:
	/* 0x48ea: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_48f1:
	/* 0x48f1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_48f6:
	/* 0x48f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48f8:
	/* 0x48f8: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48fc:
	/* 0x48fc: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4903:
	/* 0x4903: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4906:
	/* 0x4906: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_490d:
	/* 0x490d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4916:
	/* 0x4916: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_491a:
	/* 0x491a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_491f:
	/* 0x491f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4924:
	/* 0x4924: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4929:
	/* 0x4929: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_492e:
	/* 0x492e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4930:
	/* 0x4930: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4935:
	/* 0x4935: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_4937:
	/* 0x4937: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_493a:
	/* 0x493a: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4940:
	/* 0x4940: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4943:
	/* 0x4943: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4949:
	/* 0x4949: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_494e:
	/* 0x494e: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4954:
	/* 0x4954: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4958:
	/* 0x4958: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_495f:
	/* 0x495f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4964:
	/* 0x4964: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4969:
	/* 0x4969: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4970:
	/* 0x4970: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4974:
	/* 0x4974: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_497b:
	/* 0x497b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4980:
	/* 0x4980: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4985:
	/* 0x4985: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4987:
	/* 0x4987: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_498a:
	/* 0x498a: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_498c:
	/* 0x498c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_498e:
	/* 0x498e: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_4994:
	/* 0x4994: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4997:
	/* 0x4997: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_499d:
	/* 0x499d: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49a2:
	/* 0x49a2: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_49a8:
	/* 0x49a8: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_49ac:
	/* 0x49ac: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_49b3:
	/* 0x49b3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_49b6:
	/* 0x49b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_49bb:
	/* 0x49bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_49c0:
	/* 0x49c0: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_49c7:
	/* 0x49c7: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_49cb:
	/* 0x49cb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_49d2:
	/* 0x49d2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_49d7:
	/* 0x49d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d9:
	/* 0x49d9: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_49dd:
	/* 0x49dd: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_49e4:
	/* 0x49e4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_49e7:
	/* 0x49e7: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_49ee:
	/* 0x49ee: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_49f7:
	/* 0x49f7: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_49fb:
	/* 0x49fb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a00:
	/* 0x4a00: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a05:
	/* 0x4a05: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a0a:
	/* 0x4a0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a0f:
	/* 0x4a0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a11:
	/* 0x4a11: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a16:
	/* 0x4a16: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_4a18:
	/* 0x4a18: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4a1b:
	/* 0x4a1b: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4a21:
	/* 0x4a21: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a24:
	/* 0x4a24: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4a2a:
	/* 0x4a2a: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a2f:
	/* 0x4a2f: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4a35:
	/* 0x4a35: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4a39:
	/* 0x4a39: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4a40:
	/* 0x4a40: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4a45:
	/* 0x4a45: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4a4a:
	/* 0x4a4a: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a51:
	/* 0x4a51: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4a55:
	/* 0x4a55: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4a5c:
	/* 0x4a5c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a61:
	/* 0x4a61: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4a66:
	/* 0x4a66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a68:
	/* 0x4a68: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a6b:
	/* 0x4a6b: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_4a6d:
	/* 0x4a6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a6f:
	/* 0x4a6f: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_4a75:
	/* 0x4a75: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a78:
	/* 0x4a78: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4a7e:
	/* 0x4a7e: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a83:
	/* 0x4a83: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4a89:
	/* 0x4a89: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4a8d:
	/* 0x4a8d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a94:
	/* 0x4a94: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4a97:
	/* 0x4a97: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a9c:
	/* 0x4a9c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4aa1:
	/* 0x4aa1: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4aa8:
	/* 0x4aa8: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4aac:
	/* 0x4aac: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4ab3:
	/* 0x4ab3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ab8:
	/* 0x4ab8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4aba:
	/* 0x4aba: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4abe:
	/* 0x4abe: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4ac5:
	/* 0x4ac5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4ac8:
	/* 0x4ac8: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4acf:
	/* 0x4acf: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4ad8:
	/* 0x4ad8: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4adc:
	/* 0x4adc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ae1:
	/* 0x4ae1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ae6:
	/* 0x4ae6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4aeb:
	/* 0x4aeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4af0:
	/* 0x4af0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4af2:
	/* 0x4af2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4af7:
	/* 0x4af7: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_4af9:
	/* 0x4af9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4afc:
	/* 0x4afc: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4b02:
	/* 0x4b02: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b05:
	/* 0x4b05: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4b0b:
	/* 0x4b0b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b10:
	/* 0x4b10: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4b16:
	/* 0x4b16: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4b1a:
	/* 0x4b1a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4b21:
	/* 0x4b21: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4b26:
	/* 0x4b26: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4b2b:
	/* 0x4b2b: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b32:
	/* 0x4b32: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4b36:
	/* 0x4b36: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4b3d:
	/* 0x4b3d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b42:
	/* 0x4b42: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4b47:
	/* 0x4b47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b49:
	/* 0x4b49: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b4c:
	/* 0x4b4c: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_4b4e:
	/* 0x4b4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b50:
	/* 0x4b50: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_4b56:
	/* 0x4b56: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b59:
	/* 0x4b59: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4b5f:
	/* 0x4b5f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b64:
	/* 0x4b64: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4b6a:
	/* 0x4b6a: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4b6e:
	/* 0x4b6e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4b75:
	/* 0x4b75: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4b78:
	/* 0x4b78: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4b7d:
	/* 0x4b7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b82:
	/* 0x4b82: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b89:
	/* 0x4b89: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4b8d:
	/* 0x4b8d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4b94:
	/* 0x4b94: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4b99:
	/* 0x4b99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b9b:
	/* 0x4b9b: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b9f:
	/* 0x4b9f: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4ba6:
	/* 0x4ba6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4ba9:
	/* 0x4ba9: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4bb0:
	/* 0x4bb0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4bb9:
	/* 0x4bb9: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4bc0:
	/* 0x4bc0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bc5:
	/* 0x4bc5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4bca:
	/* 0x4bca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4bcf:
	/* 0x4bcf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bd4:
	/* 0x4bd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bd6:
	/* 0x4bd6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bdb:
	/* 0x4bdb: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_4bdd:
	/* 0x4bdd: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4be0:
	/* 0x4be0: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4be6:
	/* 0x4be6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4be9:
	/* 0x4be9: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4bef:
	/* 0x4bef: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf4:
	/* 0x4bf4: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4bfa:
	/* 0x4bfa: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4bfe:
	/* 0x4bfe: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4c05:
	/* 0x4c05: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c0a:
	/* 0x4c0a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4c0f:
	/* 0x4c0f: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c16:
	/* 0x4c16: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4c1a:
	/* 0x4c1a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4c21:
	/* 0x4c21: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c26:
	/* 0x4c26: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c2b:
	/* 0x4c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c2d:
	/* 0x4c2d: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c30:
	/* 0x4c30: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_4c32:
	/* 0x4c32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c34:
	/* 0x4c34: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_4c3a:
	/* 0x4c3a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c3d:
	/* 0x4c3d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4c43:
	/* 0x4c43: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c48:
	/* 0x4c48: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4c4e:
	/* 0x4c4e: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4c52:
	/* 0x4c52: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4c59:
	/* 0x4c59: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4c5c:
	/* 0x4c5c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c61:
	/* 0x4c61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c66:
	/* 0x4c66: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c6d:
	/* 0x4c6d: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4c71:
	/* 0x4c71: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4c78:
	/* 0x4c78: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c7d:
	/* 0x4c7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c7f:
	/* 0x4c7f: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c83:
	/* 0x4c83: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4c8a:
	/* 0x4c8a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4c8d:
	/* 0x4c8d: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4c94:
	/* 0x4c94: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4c9d:
	/* 0x4c9d: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4ca4:
	/* 0x4ca4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ca9:
	/* 0x4ca9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4cae:
	/* 0x4cae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4cb3:
	/* 0x4cb3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cb8:
	/* 0x4cb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cba:
	/* 0x4cba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4cbf:
	/* 0x4cbf: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4cc1:
	/* 0x4cc1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4cc4:
	/* 0x4cc4: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4cca:
	/* 0x4cca: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ccd:
	/* 0x4ccd: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4cd3:
	/* 0x4cd3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cd8:
	/* 0x4cd8: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4cde:
	/* 0x4cde: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4ce2:
	/* 0x4ce2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ce9:
	/* 0x4ce9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4cee:
	/* 0x4cee: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4cf3:
	/* 0x4cf3: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4cfa:
	/* 0x4cfa: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4cfe:
	/* 0x4cfe: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4d05:
	/* 0x4d05: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d0a:
	/* 0x4d0a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4d0f:
	/* 0x4d0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d11:
	/* 0x4d11: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d14:
	/* 0x4d14: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4d16:
	/* 0x4d16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d18:
	/* 0x4d18: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_4d1e:
	/* 0x4d1e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d21:
	/* 0x4d21: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4d27:
	/* 0x4d27: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d2c:
	/* 0x4d2c: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4d32:
	/* 0x4d32: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4d36:
	/* 0x4d36: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4d3d:
	/* 0x4d3d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4d40:
	/* 0x4d40: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4d45:
	/* 0x4d45: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d4a:
	/* 0x4d4a: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4d51:
	/* 0x4d51: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4d55:
	/* 0x4d55: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4d5c:
	/* 0x4d5c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4d61:
	/* 0x4d61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d63:
	/* 0x4d63: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d67:
	/* 0x4d67: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4d6e:
	/* 0x4d6e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4d71:
	/* 0x4d71: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4d78:
	/* 0x4d78: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4d81:
	/* 0x4d81: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4d88:
	/* 0x4d88: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d8d:
	/* 0x4d8d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4d92:
	/* 0x4d92: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d97:
	/* 0x4d97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d9c:
	/* 0x4d9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d9e:
	/* 0x4d9e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4da3:
	/* 0x4da3: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_4da5:
	/* 0x4da5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4da8:
	/* 0x4da8: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4dae:
	/* 0x4dae: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4db1:
	/* 0x4db1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4db7:
	/* 0x4db7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dbc:
	/* 0x4dbc: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4dc2:
	/* 0x4dc2: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4dc6:
	/* 0x4dc6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4dcd:
	/* 0x4dcd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4dd2:
	/* 0x4dd2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4dd7:
	/* 0x4dd7: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4dde:
	/* 0x4dde: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4de2:
	/* 0x4de2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4de9:
	/* 0x4de9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4dee:
	/* 0x4dee: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4df3:
	/* 0x4df3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4df5:
	/* 0x4df5: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4df8:
	/* 0x4df8: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_4dfa:
	/* 0x4dfa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4dfc:
	/* 0x4dfc: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_4e02:
	/* 0x4e02: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e05:
	/* 0x4e05: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4e0b:
	/* 0x4e0b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e10:
	/* 0x4e10: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4e16:
	/* 0x4e16: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4e1a:
	/* 0x4e1a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4e21:
	/* 0x4e21: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4e24:
	/* 0x4e24: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e29:
	/* 0x4e29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e2e:
	/* 0x4e2e: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4e35:
	/* 0x4e35: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4e39:
	/* 0x4e39: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4e40:
	/* 0x4e40: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e45:
	/* 0x4e45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 20039ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20039ULL: goto x86_l_4e47;
	case 20043ULL: goto x86_l_4e4b;
	case 20050ULL: goto x86_l_4e52;
	case 20053ULL: goto x86_l_4e55;
	case 20060ULL: goto x86_l_4e5c;
	case 20069ULL: goto x86_l_4e65;
	case 20076ULL: goto x86_l_4e6c;
	case 20081ULL: goto x86_l_4e71;
	case 20086ULL: goto x86_l_4e76;
	case 20091ULL: goto x86_l_4e7b;
	case 20096ULL: goto x86_l_4e80;
	case 20098ULL: goto x86_l_4e82;
	case 20103ULL: goto x86_l_4e87;
	case 20105ULL: goto x86_l_4e89;
	case 20108ULL: goto x86_l_4e8c;
	case 20114ULL: goto x86_l_4e92;
	case 20117ULL: goto x86_l_4e95;
	case 20123ULL: goto x86_l_4e9b;
	case 20128ULL: goto x86_l_4ea0;
	case 20134ULL: goto x86_l_4ea6;
	case 20138ULL: goto x86_l_4eaa;
	case 20145ULL: goto x86_l_4eb1;
	case 20150ULL: goto x86_l_4eb6;
	case 20155ULL: goto x86_l_4ebb;
	case 20162ULL: goto x86_l_4ec2;
	case 20166ULL: goto x86_l_4ec6;
	case 20173ULL: goto x86_l_4ecd;
	case 20178ULL: goto x86_l_4ed2;
	case 20183ULL: goto x86_l_4ed7;
	case 20185ULL: goto x86_l_4ed9;
	case 20188ULL: goto x86_l_4edc;
	case 20190ULL: goto x86_l_4ede;
	case 20192ULL: goto x86_l_4ee0;
	case 20198ULL: goto x86_l_4ee6;
	case 20201ULL: goto x86_l_4ee9;
	case 20207ULL: goto x86_l_4eef;
	case 20212ULL: goto x86_l_4ef4;
	case 20218ULL: goto x86_l_4efa;
	case 20222ULL: goto x86_l_4efe;
	case 20229ULL: goto x86_l_4f05;
	case 20232ULL: goto x86_l_4f08;
	case 20237ULL: goto x86_l_4f0d;
	case 20242ULL: goto x86_l_4f12;
	case 20249ULL: goto x86_l_4f19;
	case 20253ULL: goto x86_l_4f1d;
	case 20260ULL: goto x86_l_4f24;
	case 20265ULL: goto x86_l_4f29;
	case 20267ULL: goto x86_l_4f2b;
	case 20271ULL: goto x86_l_4f2f;
	case 20278ULL: goto x86_l_4f36;
	case 20281ULL: goto x86_l_4f39;
	case 20288ULL: goto x86_l_4f40;
	case 20297ULL: goto x86_l_4f49;
	case 20304ULL: goto x86_l_4f50;
	case 20309ULL: goto x86_l_4f55;
	case 20314ULL: goto x86_l_4f5a;
	case 20319ULL: goto x86_l_4f5f;
	case 20324ULL: goto x86_l_4f64;
	case 20326ULL: goto x86_l_4f66;
	case 20331ULL: goto x86_l_4f6b;
	case 20333ULL: goto x86_l_4f6d;
	case 20336ULL: goto x86_l_4f70;
	case 20342ULL: goto x86_l_4f76;
	case 20345ULL: goto x86_l_4f79;
	case 20351ULL: goto x86_l_4f7f;
	case 20356ULL: goto x86_l_4f84;
	case 20362ULL: goto x86_l_4f8a;
	case 20366ULL: goto x86_l_4f8e;
	case 20373ULL: goto x86_l_4f95;
	case 20378ULL: goto x86_l_4f9a;
	case 20383ULL: goto x86_l_4f9f;
	case 20390ULL: goto x86_l_4fa6;
	case 20394ULL: goto x86_l_4faa;
	case 20401ULL: goto x86_l_4fb1;
	case 20406ULL: goto x86_l_4fb6;
	case 20411ULL: goto x86_l_4fbb;
	case 20413ULL: goto x86_l_4fbd;
	case 20416ULL: goto x86_l_4fc0;
	case 20418ULL: goto x86_l_4fc2;
	case 20420ULL: goto x86_l_4fc4;
	case 20426ULL: goto x86_l_4fca;
	case 20429ULL: goto x86_l_4fcd;
	case 20435ULL: goto x86_l_4fd3;
	case 20440ULL: goto x86_l_4fd8;
	case 20446ULL: goto x86_l_4fde;
	case 20450ULL: goto x86_l_4fe2;
	case 20457ULL: goto x86_l_4fe9;
	case 20460ULL: goto x86_l_4fec;
	case 20465ULL: goto x86_l_4ff1;
	case 20470ULL: goto x86_l_4ff6;
	case 20477ULL: goto x86_l_4ffd;
	case 20481ULL: goto x86_l_5001;
	case 20488ULL: goto x86_l_5008;
	case 20493ULL: goto x86_l_500d;
	case 20495ULL: goto x86_l_500f;
	case 20499ULL: goto x86_l_5013;
	case 20506ULL: goto x86_l_501a;
	case 20509ULL: goto x86_l_501d;
	case 20516ULL: goto x86_l_5024;
	case 20525ULL: goto x86_l_502d;
	case 20532ULL: goto x86_l_5034;
	case 20537ULL: goto x86_l_5039;
	case 20542ULL: goto x86_l_503e;
	case 20547ULL: goto x86_l_5043;
	case 20552ULL: goto x86_l_5048;
	case 20554ULL: goto x86_l_504a;
	case 20559ULL: goto x86_l_504f;
	case 20561ULL: goto x86_l_5051;
	case 20564ULL: goto x86_l_5054;
	case 20570ULL: goto x86_l_505a;
	case 20573ULL: goto x86_l_505d;
	case 20579ULL: goto x86_l_5063;
	case 20584ULL: goto x86_l_5068;
	case 20590ULL: goto x86_l_506e;
	case 20594ULL: goto x86_l_5072;
	case 20601ULL: goto x86_l_5079;
	case 20606ULL: goto x86_l_507e;
	case 20611ULL: goto x86_l_5083;
	case 20618ULL: goto x86_l_508a;
	case 20622ULL: goto x86_l_508e;
	case 20629ULL: goto x86_l_5095;
	case 20634ULL: goto x86_l_509a;
	case 20639ULL: goto x86_l_509f;
	case 20641ULL: goto x86_l_50a1;
	case 20644ULL: goto x86_l_50a4;
	case 20646ULL: goto x86_l_50a6;
	case 20648ULL: goto x86_l_50a8;
	case 20654ULL: goto x86_l_50ae;
	case 20657ULL: goto x86_l_50b1;
	case 20663ULL: goto x86_l_50b7;
	case 20668ULL: goto x86_l_50bc;
	case 20674ULL: goto x86_l_50c2;
	case 20678ULL: goto x86_l_50c6;
	case 20685ULL: goto x86_l_50cd;
	case 20688ULL: goto x86_l_50d0;
	case 20693ULL: goto x86_l_50d5;
	case 20698ULL: goto x86_l_50da;
	case 20705ULL: goto x86_l_50e1;
	case 20709ULL: goto x86_l_50e5;
	case 20716ULL: goto x86_l_50ec;
	case 20721ULL: goto x86_l_50f1;
	case 20723ULL: goto x86_l_50f3;
	case 20727ULL: goto x86_l_50f7;
	case 20734ULL: goto x86_l_50fe;
	case 20737ULL: goto x86_l_5101;
	case 20744ULL: goto x86_l_5108;
	case 20753ULL: goto x86_l_5111;
	case 20760ULL: goto x86_l_5118;
	case 20765ULL: goto x86_l_511d;
	case 20770ULL: goto x86_l_5122;
	case 20775ULL: goto x86_l_5127;
	case 20780ULL: goto x86_l_512c;
	case 20782ULL: goto x86_l_512e;
	case 20787ULL: goto x86_l_5133;
	case 20789ULL: goto x86_l_5135;
	case 20792ULL: goto x86_l_5138;
	case 20798ULL: goto x86_l_513e;
	case 20801ULL: goto x86_l_5141;
	case 20807ULL: goto x86_l_5147;
	case 20812ULL: goto x86_l_514c;
	case 20818ULL: goto x86_l_5152;
	case 20822ULL: goto x86_l_5156;
	case 20829ULL: goto x86_l_515d;
	case 20834ULL: goto x86_l_5162;
	case 20839ULL: goto x86_l_5167;
	case 20846ULL: goto x86_l_516e;
	case 20850ULL: goto x86_l_5172;
	case 20857ULL: goto x86_l_5179;
	case 20862ULL: goto x86_l_517e;
	case 20867ULL: goto x86_l_5183;
	case 20869ULL: goto x86_l_5185;
	case 20872ULL: goto x86_l_5188;
	case 20874ULL: goto x86_l_518a;
	case 20876ULL: goto x86_l_518c;
	case 20882ULL: goto x86_l_5192;
	case 20885ULL: goto x86_l_5195;
	case 20891ULL: goto x86_l_519b;
	case 20896ULL: goto x86_l_51a0;
	case 20902ULL: goto x86_l_51a6;
	case 20906ULL: goto x86_l_51aa;
	case 20913ULL: goto x86_l_51b1;
	case 20916ULL: goto x86_l_51b4;
	case 20921ULL: goto x86_l_51b9;
	case 20926ULL: goto x86_l_51be;
	case 20933ULL: goto x86_l_51c5;
	case 20937ULL: goto x86_l_51c9;
	case 20944ULL: goto x86_l_51d0;
	case 20949ULL: goto x86_l_51d5;
	case 20951ULL: goto x86_l_51d7;
	case 20955ULL: goto x86_l_51db;
	case 20962ULL: goto x86_l_51e2;
	case 20965ULL: goto x86_l_51e5;
	case 20972ULL: goto x86_l_51ec;
	case 20981ULL: goto x86_l_51f5;
	case 20988ULL: goto x86_l_51fc;
	case 20993ULL: goto x86_l_5201;
	case 20998ULL: goto x86_l_5206;
	case 21003ULL: goto x86_l_520b;
	case 21008ULL: goto x86_l_5210;
	case 21010ULL: goto x86_l_5212;
	case 21015ULL: goto x86_l_5217;
	case 21017ULL: goto x86_l_5219;
	case 21020ULL: goto x86_l_521c;
	case 21026ULL: goto x86_l_5222;
	case 21029ULL: goto x86_l_5225;
	case 21035ULL: goto x86_l_522b;
	case 21040ULL: goto x86_l_5230;
	case 21046ULL: goto x86_l_5236;
	case 21050ULL: goto x86_l_523a;
	case 21057ULL: goto x86_l_5241;
	case 21062ULL: goto x86_l_5246;
	case 21067ULL: goto x86_l_524b;
	case 21074ULL: goto x86_l_5252;
	case 21078ULL: goto x86_l_5256;
	case 21085ULL: goto x86_l_525d;
	case 21090ULL: goto x86_l_5262;
	case 21095ULL: goto x86_l_5267;
	case 21097ULL: goto x86_l_5269;
	case 21100ULL: goto x86_l_526c;
	case 21102ULL: goto x86_l_526e;
	case 21104ULL: goto x86_l_5270;
	case 21110ULL: goto x86_l_5276;
	case 21113ULL: goto x86_l_5279;
	case 21119ULL: goto x86_l_527f;
	case 21124ULL: goto x86_l_5284;
	case 21130ULL: goto x86_l_528a;
	case 21134ULL: goto x86_l_528e;
	case 21141ULL: goto x86_l_5295;
	case 21144ULL: goto x86_l_5298;
	case 21149ULL: goto x86_l_529d;
	case 21154ULL: goto x86_l_52a2;
	case 21161ULL: goto x86_l_52a9;
	case 21165ULL: goto x86_l_52ad;
	case 21172ULL: goto x86_l_52b4;
	case 21177ULL: goto x86_l_52b9;
	case 21179ULL: goto x86_l_52bb;
	case 21183ULL: goto x86_l_52bf;
	case 21190ULL: goto x86_l_52c6;
	case 21193ULL: goto x86_l_52c9;
	case 21200ULL: goto x86_l_52d0;
	case 21209ULL: goto x86_l_52d9;
	case 21216ULL: goto x86_l_52e0;
	case 21221ULL: goto x86_l_52e5;
	case 21226ULL: goto x86_l_52ea;
	case 21231ULL: goto x86_l_52ef;
	case 21236ULL: goto x86_l_52f4;
	case 21238ULL: goto x86_l_52f6;
	case 21243ULL: goto x86_l_52fb;
	case 21245ULL: goto x86_l_52fd;
	case 21248ULL: goto x86_l_5300;
	case 21254ULL: goto x86_l_5306;
	case 21257ULL: goto x86_l_5309;
	case 21263ULL: goto x86_l_530f;
	case 21268ULL: goto x86_l_5314;
	case 21274ULL: goto x86_l_531a;
	case 21278ULL: goto x86_l_531e;
	case 21285ULL: goto x86_l_5325;
	case 21290ULL: goto x86_l_532a;
	case 21295ULL: goto x86_l_532f;
	case 21302ULL: goto x86_l_5336;
	case 21306ULL: goto x86_l_533a;
	case 21313ULL: goto x86_l_5341;
	case 21318ULL: goto x86_l_5346;
	case 21323ULL: goto x86_l_534b;
	case 21325ULL: goto x86_l_534d;
	case 21328ULL: goto x86_l_5350;
	case 21330ULL: goto x86_l_5352;
	case 21332ULL: goto x86_l_5354;
	case 21338ULL: goto x86_l_535a;
	case 21341ULL: goto x86_l_535d;
	case 21347ULL: goto x86_l_5363;
	case 21352ULL: goto x86_l_5368;
	case 21358ULL: goto x86_l_536e;
	case 21362ULL: goto x86_l_5372;
	case 21369ULL: goto x86_l_5379;
	case 21372ULL: goto x86_l_537c;
	case 21377ULL: goto x86_l_5381;
	case 21382ULL: goto x86_l_5386;
	case 21389ULL: goto x86_l_538d;
	case 21393ULL: goto x86_l_5391;
	case 21400ULL: goto x86_l_5398;
	case 21405ULL: goto x86_l_539d;
	case 21407ULL: goto x86_l_539f;
	case 21411ULL: goto x86_l_53a3;
	case 21418ULL: goto x86_l_53aa;
	case 21421ULL: goto x86_l_53ad;
	case 21428ULL: goto x86_l_53b4;
	case 21437ULL: goto x86_l_53bd;
	case 21444ULL: goto x86_l_53c4;
	case 21449ULL: goto x86_l_53c9;
	case 21454ULL: goto x86_l_53ce;
	case 21459ULL: goto x86_l_53d3;
	case 21464ULL: goto x86_l_53d8;
	case 21466ULL: goto x86_l_53da;
	case 21471ULL: goto x86_l_53df;
	case 21473ULL: goto x86_l_53e1;
	case 21476ULL: goto x86_l_53e4;
	case 21482ULL: goto x86_l_53ea;
	case 21485ULL: goto x86_l_53ed;
	case 21491ULL: goto x86_l_53f3;
	case 21496ULL: goto x86_l_53f8;
	case 21502ULL: goto x86_l_53fe;
	case 21506ULL: goto x86_l_5402;
	case 21513ULL: goto x86_l_5409;
	case 21518ULL: goto x86_l_540e;
	case 21523ULL: goto x86_l_5413;
	case 21530ULL: goto x86_l_541a;
	case 21534ULL: goto x86_l_541e;
	case 21541ULL: goto x86_l_5425;
	case 21546ULL: goto x86_l_542a;
	case 21551ULL: goto x86_l_542f;
	case 21553ULL: goto x86_l_5431;
	case 21556ULL: goto x86_l_5434;
	case 21558ULL: goto x86_l_5436;
	case 21560ULL: goto x86_l_5438;
	case 21566ULL: goto x86_l_543e;
	case 21569ULL: goto x86_l_5441;
	case 21575ULL: goto x86_l_5447;
	case 21580ULL: goto x86_l_544c;
	case 21586ULL: goto x86_l_5452;
	case 21590ULL: goto x86_l_5456;
	case 21597ULL: goto x86_l_545d;
	case 21600ULL: goto x86_l_5460;
	case 21605ULL: goto x86_l_5465;
	case 21610ULL: goto x86_l_546a;
	case 21617ULL: goto x86_l_5471;
	case 21621ULL: goto x86_l_5475;
	case 21628ULL: goto x86_l_547c;
	case 21633ULL: goto x86_l_5481;
	case 21635ULL: goto x86_l_5483;
	case 21639ULL: goto x86_l_5487;
	case 21646ULL: goto x86_l_548e;
	case 21649ULL: goto x86_l_5491;
	case 21656ULL: goto x86_l_5498;
	case 21665ULL: goto x86_l_54a1;
	case 21672ULL: goto x86_l_54a8;
	case 21677ULL: goto x86_l_54ad;
	case 21682ULL: goto x86_l_54b2;
	case 21687ULL: goto x86_l_54b7;
	case 21692ULL: goto x86_l_54bc;
	case 21694ULL: goto x86_l_54be;
	case 21699ULL: goto x86_l_54c3;
	case 21701ULL: goto x86_l_54c5;
	case 21704ULL: goto x86_l_54c8;
	case 21710ULL: goto x86_l_54ce;
	case 21713ULL: goto x86_l_54d1;
	case 21719ULL: goto x86_l_54d7;
	case 21724ULL: goto x86_l_54dc;
	case 21730ULL: goto x86_l_54e2;
	case 21734ULL: goto x86_l_54e6;
	case 21741ULL: goto x86_l_54ed;
	case 21746ULL: goto x86_l_54f2;
	case 21751ULL: goto x86_l_54f7;
	case 21758ULL: goto x86_l_54fe;
	case 21762ULL: goto x86_l_5502;
	case 21769ULL: goto x86_l_5509;
	case 21774ULL: goto x86_l_550e;
	case 21779ULL: goto x86_l_5513;
	case 21781ULL: goto x86_l_5515;
	case 21784ULL: goto x86_l_5518;
	case 21786ULL: goto x86_l_551a;
	case 21788ULL: goto x86_l_551c;
	case 21794ULL: goto x86_l_5522;
	case 21797ULL: goto x86_l_5525;
	case 21803ULL: goto x86_l_552b;
	case 21808ULL: goto x86_l_5530;
	case 21814ULL: goto x86_l_5536;
	case 21818ULL: goto x86_l_553a;
	case 21825ULL: goto x86_l_5541;
	case 21828ULL: goto x86_l_5544;
	case 21833ULL: goto x86_l_5549;
	case 21838ULL: goto x86_l_554e;
	case 21845ULL: goto x86_l_5555;
	case 21849ULL: goto x86_l_5559;
	case 21856ULL: goto x86_l_5560;
	case 21861ULL: goto x86_l_5565;
	case 21863ULL: goto x86_l_5567;
	case 21867ULL: goto x86_l_556b;
	case 21874ULL: goto x86_l_5572;
	case 21877ULL: goto x86_l_5575;
	case 21884ULL: goto x86_l_557c;
	case 21893ULL: goto x86_l_5585;
	case 21900ULL: goto x86_l_558c;
	case 21905ULL: goto x86_l_5591;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4e47:
	/* 0x4e47: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e4b:
	/* 0x4e4b: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4e52:
	/* 0x4e52: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4e55:
	/* 0x4e55: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4e5c:
	/* 0x4e5c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4e65:
	/* 0x4e65: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4e6c:
	/* 0x4e6c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e71:
	/* 0x4e71: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e76:
	/* 0x4e76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e7b:
	/* 0x4e7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e80:
	/* 0x4e80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e82:
	/* 0x4e82: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e87:
	/* 0x4e87: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_4e89:
	/* 0x4e89: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4e8c:
	/* 0x4e8c: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4e92:
	/* 0x4e92: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e95:
	/* 0x4e95: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4e9b:
	/* 0x4e9b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ea0:
	/* 0x4ea0: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4ea6:
	/* 0x4ea6: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4eaa:
	/* 0x4eaa: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4eb1:
	/* 0x4eb1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4eb6:
	/* 0x4eb6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4ebb:
	/* 0x4ebb: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ec2:
	/* 0x4ec2: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4ec6:
	/* 0x4ec6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ecd:
	/* 0x4ecd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ed2:
	/* 0x4ed2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ed7:
	/* 0x4ed7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ed9:
	/* 0x4ed9: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4edc:
	/* 0x4edc: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_4ede:
	/* 0x4ede: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ee0:
	/* 0x4ee0: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_4ee6:
	/* 0x4ee6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ee9:
	/* 0x4ee9: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4eef:
	/* 0x4eef: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ef4:
	/* 0x4ef4: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4efa:
	/* 0x4efa: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4efe:
	/* 0x4efe: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4f05:
	/* 0x4f05: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4f08:
	/* 0x4f08: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f0d:
	/* 0x4f0d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f12:
	/* 0x4f12: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f19:
	/* 0x4f19: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4f1d:
	/* 0x4f1d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4f24:
	/* 0x4f24: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f29:
	/* 0x4f29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f2b:
	/* 0x4f2b: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f2f:
	/* 0x4f2f: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4f36:
	/* 0x4f36: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4f39:
	/* 0x4f39: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4f40:
	/* 0x4f40: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4f49:
	/* 0x4f49: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4f50:
	/* 0x4f50: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f55:
	/* 0x4f55: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f5a:
	/* 0x4f5a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f5f:
	/* 0x4f5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f64:
	/* 0x4f64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f66:
	/* 0x4f66: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f6b:
	/* 0x4f6b: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_4f6d:
	/* 0x4f6d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4f70:
	/* 0x4f70: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_4f76:
	/* 0x4f76: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f79:
	/* 0x4f79: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4f7f:
	/* 0x4f7f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f84:
	/* 0x4f84: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4f8a:
	/* 0x4f8a: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4f8e:
	/* 0x4f8e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4f95:
	/* 0x4f95: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4f9a:
	/* 0x4f9a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4f9f:
	/* 0x4f9f: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4fa6:
	/* 0x4fa6: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4faa:
	/* 0x4faa: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4fb1:
	/* 0x4fb1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fb6:
	/* 0x4fb6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4fbb:
	/* 0x4fbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fbd:
	/* 0x4fbd: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fc0:
	/* 0x4fc0: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_4fc2:
	/* 0x4fc2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fc4:
	/* 0x4fc4: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_4fca:
	/* 0x4fca: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4fcd:
	/* 0x4fcd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4fd3:
	/* 0x4fd3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fd8:
	/* 0x4fd8: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_4fde:
	/* 0x4fde: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4fe2:
	/* 0x4fe2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4fe9:
	/* 0x4fe9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4fec:
	/* 0x4fec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ff1:
	/* 0x4ff1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ff6:
	/* 0x4ff6: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ffd:
	/* 0x4ffd: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5001:
	/* 0x5001: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5008:
	/* 0x5008: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_500d:
	/* 0x500d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_500f:
	/* 0x500f: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5013:
	/* 0x5013: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_501a:
	/* 0x501a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_501d:
	/* 0x501d: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5024:
	/* 0x5024: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_502d:
	/* 0x502d: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5034:
	/* 0x5034: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5039:
	/* 0x5039: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_503e:
	/* 0x503e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5043:
	/* 0x5043: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5048:
	/* 0x5048: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_504a:
	/* 0x504a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_504f:
	/* 0x504f: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_5051:
	/* 0x5051: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5054:
	/* 0x5054: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_505a:
	/* 0x505a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_505d:
	/* 0x505d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5063:
	/* 0x5063: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5068:
	/* 0x5068: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_506e:
	/* 0x506e: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5072:
	/* 0x5072: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5079:
	/* 0x5079: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_507e:
	/* 0x507e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5083:
	/* 0x5083: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_508a:
	/* 0x508a: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_508e:
	/* 0x508e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5095:
	/* 0x5095: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_509a:
	/* 0x509a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_509f:
	/* 0x509f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50a1:
	/* 0x50a1: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50a4:
	/* 0x50a4: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_50a6:
	/* 0x50a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50a8:
	/* 0x50a8: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_50ae:
	/* 0x50ae: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_50b1:
	/* 0x50b1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_50b7:
	/* 0x50b7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50bc:
	/* 0x50bc: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_50c2:
	/* 0x50c2: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_50c6:
	/* 0x50c6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_50cd:
	/* 0x50cd: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_50d0:
	/* 0x50d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_50d5:
	/* 0x50d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_50da:
	/* 0x50da: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_50e1:
	/* 0x50e1: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_50e5:
	/* 0x50e5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_50ec:
	/* 0x50ec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_50f1:
	/* 0x50f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50f3:
	/* 0x50f3: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_50f7:
	/* 0x50f7: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_50fe:
	/* 0x50fe: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5101:
	/* 0x5101: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5108:
	/* 0x5108: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5111:
	/* 0x5111: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5118:
	/* 0x5118: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_511d:
	/* 0x511d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5122:
	/* 0x5122: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5127:
	/* 0x5127: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_512c:
	/* 0x512c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_512e:
	/* 0x512e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5133:
	/* 0x5133: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_5135:
	/* 0x5135: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5138:
	/* 0x5138: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_513e:
	/* 0x513e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5141:
	/* 0x5141: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5147:
	/* 0x5147: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_514c:
	/* 0x514c: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5152:
	/* 0x5152: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5156:
	/* 0x5156: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_515d:
	/* 0x515d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5162:
	/* 0x5162: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5167:
	/* 0x5167: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_516e:
	/* 0x516e: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5172:
	/* 0x5172: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5179:
	/* 0x5179: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_517e:
	/* 0x517e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5183:
	/* 0x5183: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5185:
	/* 0x5185: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5188:
	/* 0x5188: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_518a:
	/* 0x518a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_518c:
	/* 0x518c: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_5192:
	/* 0x5192: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5195:
	/* 0x5195: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_519b:
	/* 0x519b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51a0:
	/* 0x51a0: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_51a6:
	/* 0x51a6: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_51aa:
	/* 0x51aa: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_51b1:
	/* 0x51b1: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_51b4:
	/* 0x51b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_51b9:
	/* 0x51b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51be:
	/* 0x51be: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_51c5:
	/* 0x51c5: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_51c9:
	/* 0x51c9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_51d0:
	/* 0x51d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_51d5:
	/* 0x51d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51d7:
	/* 0x51d7: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_51db:
	/* 0x51db: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_51e2:
	/* 0x51e2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_51e5:
	/* 0x51e5: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_51ec:
	/* 0x51ec: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_51f5:
	/* 0x51f5: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_51fc:
	/* 0x51fc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5201:
	/* 0x5201: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5206:
	/* 0x5206: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_520b:
	/* 0x520b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5210:
	/* 0x5210: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5212:
	/* 0x5212: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5217:
	/* 0x5217: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_5219:
	/* 0x5219: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_521c:
	/* 0x521c: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_5222:
	/* 0x5222: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5225:
	/* 0x5225: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_522b:
	/* 0x522b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5230:
	/* 0x5230: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5236:
	/* 0x5236: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_523a:
	/* 0x523a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5241:
	/* 0x5241: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5246:
	/* 0x5246: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_524b:
	/* 0x524b: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5252:
	/* 0x5252: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5256:
	/* 0x5256: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_525d:
	/* 0x525d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5262:
	/* 0x5262: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5267:
	/* 0x5267: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5269:
	/* 0x5269: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_526c:
	/* 0x526c: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_526e:
	/* 0x526e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5270:
	/* 0x5270: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_5276:
	/* 0x5276: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5279:
	/* 0x5279: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_527f:
	/* 0x527f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5284:
	/* 0x5284: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_528a:
	/* 0x528a: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_528e:
	/* 0x528e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5295:
	/* 0x5295: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5298:
	/* 0x5298: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_529d:
	/* 0x529d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52a2:
	/* 0x52a2: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_52a9:
	/* 0x52a9: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_52ad:
	/* 0x52ad: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_52b4:
	/* 0x52b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_52b9:
	/* 0x52b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52bb:
	/* 0x52bb: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_52bf:
	/* 0x52bf: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_52c6:
	/* 0x52c6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_52c9:
	/* 0x52c9: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_52d0:
	/* 0x52d0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_52d9:
	/* 0x52d9: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_52e0:
	/* 0x52e0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52e5:
	/* 0x52e5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_52ea:
	/* 0x52ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52ef:
	/* 0x52ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52f4:
	/* 0x52f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f6:
	/* 0x52f6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52fb:
	/* 0x52fb: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_52fd:
	/* 0x52fd: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5300:
	/* 0x5300: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_5306:
	/* 0x5306: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5309:
	/* 0x5309: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_530f:
	/* 0x530f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5314:
	/* 0x5314: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_531a:
	/* 0x531a: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_531e:
	/* 0x531e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5325:
	/* 0x5325: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_532a:
	/* 0x532a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_532f:
	/* 0x532f: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5336:
	/* 0x5336: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_533a:
	/* 0x533a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5341:
	/* 0x5341: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5346:
	/* 0x5346: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_534b:
	/* 0x534b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_534d:
	/* 0x534d: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5350:
	/* 0x5350: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_5352:
	/* 0x5352: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5354:
	/* 0x5354: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_535a:
	/* 0x535a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_535d:
	/* 0x535d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5363:
	/* 0x5363: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5368:
	/* 0x5368: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_536e:
	/* 0x536e: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5372:
	/* 0x5372: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5379:
	/* 0x5379: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_537c:
	/* 0x537c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5381:
	/* 0x5381: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5386:
	/* 0x5386: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_538d:
	/* 0x538d: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5391:
	/* 0x5391: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5398:
	/* 0x5398: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_539d:
	/* 0x539d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_539f:
	/* 0x539f: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_53a3:
	/* 0x53a3: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_53aa:
	/* 0x53aa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_53ad:
	/* 0x53ad: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_53b4:
	/* 0x53b4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_53bd:
	/* 0x53bd: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_53c4:
	/* 0x53c4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53c9:
	/* 0x53c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_53ce:
	/* 0x53ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53d3:
	/* 0x53d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53d8:
	/* 0x53d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53da:
	/* 0x53da: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53df:
	/* 0x53df: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_53e1:
	/* 0x53e1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_53e4:
	/* 0x53e4: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_53ea:
	/* 0x53ea: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_53ed:
	/* 0x53ed: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_53f3:
	/* 0x53f3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53f8:
	/* 0x53f8: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_53fe:
	/* 0x53fe: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5402:
	/* 0x5402: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5409:
	/* 0x5409: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_540e:
	/* 0x540e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5413:
	/* 0x5413: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_541a:
	/* 0x541a: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_541e:
	/* 0x541e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5425:
	/* 0x5425: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_542a:
	/* 0x542a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_542f:
	/* 0x542f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5431:
	/* 0x5431: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5434:
	/* 0x5434: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_5436:
	/* 0x5436: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5438:
	/* 0x5438: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_543e:
	/* 0x543e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5441:
	/* 0x5441: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5447:
	/* 0x5447: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_544c:
	/* 0x544c: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5452:
	/* 0x5452: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5456:
	/* 0x5456: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_545d:
	/* 0x545d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5460:
	/* 0x5460: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5465:
	/* 0x5465: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_546a:
	/* 0x546a: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5471:
	/* 0x5471: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5475:
	/* 0x5475: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_547c:
	/* 0x547c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5481:
	/* 0x5481: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5483:
	/* 0x5483: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5487:
	/* 0x5487: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_548e:
	/* 0x548e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5491:
	/* 0x5491: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5498:
	/* 0x5498: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_54a1:
	/* 0x54a1: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_54a8:
	/* 0x54a8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54ad:
	/* 0x54ad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_54b2:
	/* 0x54b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_54b7:
	/* 0x54b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54bc:
	/* 0x54bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54be:
	/* 0x54be: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54c3:
	/* 0x54c3: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_54c5:
	/* 0x54c5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_54c8:
	/* 0x54c8: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_54ce:
	/* 0x54ce: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_54d1:
	/* 0x54d1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_54d7:
	/* 0x54d7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54dc:
	/* 0x54dc: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_54e2:
	/* 0x54e2: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_54e6:
	/* 0x54e6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_54ed:
	/* 0x54ed: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_54f2:
	/* 0x54f2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_54f7:
	/* 0x54f7: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_54fe:
	/* 0x54fe: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5502:
	/* 0x5502: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5509:
	/* 0x5509: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_550e:
	/* 0x550e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5513:
	/* 0x5513: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5515:
	/* 0x5515: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5518:
	/* 0x5518: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_551a:
	/* 0x551a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_551c:
	/* 0x551c: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_5522:
	/* 0x5522: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5525:
	/* 0x5525: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_552b:
	/* 0x552b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5530:
	/* 0x5530: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5536:
	/* 0x5536: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_553a:
	/* 0x553a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5541:
	/* 0x5541: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5544:
	/* 0x5544: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5549:
	/* 0x5549: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_554e:
	/* 0x554e: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5555:
	/* 0x5555: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5559:
	/* 0x5559: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5560:
	/* 0x5560: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5565:
	/* 0x5565: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5567:
	/* 0x5567: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_556b:
	/* 0x556b: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5572:
	/* 0x5572: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5575:
	/* 0x5575: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_557c:
	/* 0x557c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5585:
	/* 0x5585: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_558c:
	/* 0x558c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5591:
	/* 0x5591: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 21910ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21910ULL: goto x86_l_5596;
	case 21915ULL: goto x86_l_559b;
	case 21920ULL: goto x86_l_55a0;
	case 21922ULL: goto x86_l_55a2;
	case 21927ULL: goto x86_l_55a7;
	case 21929ULL: goto x86_l_55a9;
	case 21932ULL: goto x86_l_55ac;
	case 21938ULL: goto x86_l_55b2;
	case 21941ULL: goto x86_l_55b5;
	case 21947ULL: goto x86_l_55bb;
	case 21952ULL: goto x86_l_55c0;
	case 21958ULL: goto x86_l_55c6;
	case 21962ULL: goto x86_l_55ca;
	case 21969ULL: goto x86_l_55d1;
	case 21974ULL: goto x86_l_55d6;
	case 21979ULL: goto x86_l_55db;
	case 21986ULL: goto x86_l_55e2;
	case 21990ULL: goto x86_l_55e6;
	case 21997ULL: goto x86_l_55ed;
	case 22002ULL: goto x86_l_55f2;
	case 22007ULL: goto x86_l_55f7;
	case 22009ULL: goto x86_l_55f9;
	case 22012ULL: goto x86_l_55fc;
	case 22014ULL: goto x86_l_55fe;
	case 22016ULL: goto x86_l_5600;
	case 22022ULL: goto x86_l_5606;
	case 22025ULL: goto x86_l_5609;
	case 22031ULL: goto x86_l_560f;
	case 22036ULL: goto x86_l_5614;
	case 22042ULL: goto x86_l_561a;
	case 22046ULL: goto x86_l_561e;
	case 22053ULL: goto x86_l_5625;
	case 22056ULL: goto x86_l_5628;
	case 22061ULL: goto x86_l_562d;
	case 22066ULL: goto x86_l_5632;
	case 22073ULL: goto x86_l_5639;
	case 22077ULL: goto x86_l_563d;
	case 22084ULL: goto x86_l_5644;
	case 22089ULL: goto x86_l_5649;
	case 22091ULL: goto x86_l_564b;
	case 22095ULL: goto x86_l_564f;
	case 22102ULL: goto x86_l_5656;
	case 22105ULL: goto x86_l_5659;
	case 22112ULL: goto x86_l_5660;
	case 22121ULL: goto x86_l_5669;
	case 22128ULL: goto x86_l_5670;
	case 22133ULL: goto x86_l_5675;
	case 22138ULL: goto x86_l_567a;
	case 22143ULL: goto x86_l_567f;
	case 22148ULL: goto x86_l_5684;
	case 22150ULL: goto x86_l_5686;
	case 22155ULL: goto x86_l_568b;
	case 22157ULL: goto x86_l_568d;
	case 22160ULL: goto x86_l_5690;
	case 22166ULL: goto x86_l_5696;
	case 22169ULL: goto x86_l_5699;
	case 22175ULL: goto x86_l_569f;
	case 22180ULL: goto x86_l_56a4;
	case 22186ULL: goto x86_l_56aa;
	case 22190ULL: goto x86_l_56ae;
	case 22197ULL: goto x86_l_56b5;
	case 22202ULL: goto x86_l_56ba;
	case 22207ULL: goto x86_l_56bf;
	case 22214ULL: goto x86_l_56c6;
	case 22218ULL: goto x86_l_56ca;
	case 22225ULL: goto x86_l_56d1;
	case 22230ULL: goto x86_l_56d6;
	case 22235ULL: goto x86_l_56db;
	case 22237ULL: goto x86_l_56dd;
	case 22240ULL: goto x86_l_56e0;
	case 22242ULL: goto x86_l_56e2;
	case 22244ULL: goto x86_l_56e4;
	case 22250ULL: goto x86_l_56ea;
	case 22253ULL: goto x86_l_56ed;
	case 22259ULL: goto x86_l_56f3;
	case 22264ULL: goto x86_l_56f8;
	case 22270ULL: goto x86_l_56fe;
	case 22274ULL: goto x86_l_5702;
	case 22281ULL: goto x86_l_5709;
	case 22284ULL: goto x86_l_570c;
	case 22289ULL: goto x86_l_5711;
	case 22294ULL: goto x86_l_5716;
	case 22301ULL: goto x86_l_571d;
	case 22305ULL: goto x86_l_5721;
	case 22312ULL: goto x86_l_5728;
	case 22317ULL: goto x86_l_572d;
	case 22319ULL: goto x86_l_572f;
	case 22323ULL: goto x86_l_5733;
	case 22330ULL: goto x86_l_573a;
	case 22333ULL: goto x86_l_573d;
	case 22340ULL: goto x86_l_5744;
	case 22349ULL: goto x86_l_574d;
	case 22356ULL: goto x86_l_5754;
	case 22361ULL: goto x86_l_5759;
	case 22366ULL: goto x86_l_575e;
	case 22371ULL: goto x86_l_5763;
	case 22376ULL: goto x86_l_5768;
	case 22378ULL: goto x86_l_576a;
	case 22383ULL: goto x86_l_576f;
	case 22385ULL: goto x86_l_5771;
	case 22388ULL: goto x86_l_5774;
	case 22394ULL: goto x86_l_577a;
	case 22397ULL: goto x86_l_577d;
	case 22403ULL: goto x86_l_5783;
	case 22408ULL: goto x86_l_5788;
	case 22414ULL: goto x86_l_578e;
	case 22418ULL: goto x86_l_5792;
	case 22425ULL: goto x86_l_5799;
	case 22430ULL: goto x86_l_579e;
	case 22435ULL: goto x86_l_57a3;
	case 22442ULL: goto x86_l_57aa;
	case 22446ULL: goto x86_l_57ae;
	case 22453ULL: goto x86_l_57b5;
	case 22458ULL: goto x86_l_57ba;
	case 22463ULL: goto x86_l_57bf;
	case 22465ULL: goto x86_l_57c1;
	case 22468ULL: goto x86_l_57c4;
	case 22470ULL: goto x86_l_57c6;
	case 22472ULL: goto x86_l_57c8;
	case 22478ULL: goto x86_l_57ce;
	case 22481ULL: goto x86_l_57d1;
	case 22487ULL: goto x86_l_57d7;
	case 22492ULL: goto x86_l_57dc;
	case 22498ULL: goto x86_l_57e2;
	case 22502ULL: goto x86_l_57e6;
	case 22509ULL: goto x86_l_57ed;
	case 22512ULL: goto x86_l_57f0;
	case 22517ULL: goto x86_l_57f5;
	case 22522ULL: goto x86_l_57fa;
	case 22529ULL: goto x86_l_5801;
	case 22533ULL: goto x86_l_5805;
	case 22540ULL: goto x86_l_580c;
	case 22545ULL: goto x86_l_5811;
	case 22547ULL: goto x86_l_5813;
	case 22551ULL: goto x86_l_5817;
	case 22558ULL: goto x86_l_581e;
	case 22561ULL: goto x86_l_5821;
	case 22568ULL: goto x86_l_5828;
	case 22577ULL: goto x86_l_5831;
	case 22584ULL: goto x86_l_5838;
	case 22589ULL: goto x86_l_583d;
	case 22594ULL: goto x86_l_5842;
	case 22599ULL: goto x86_l_5847;
	case 22604ULL: goto x86_l_584c;
	case 22606ULL: goto x86_l_584e;
	case 22611ULL: goto x86_l_5853;
	case 22613ULL: goto x86_l_5855;
	case 22616ULL: goto x86_l_5858;
	case 22622ULL: goto x86_l_585e;
	case 22625ULL: goto x86_l_5861;
	case 22631ULL: goto x86_l_5867;
	case 22636ULL: goto x86_l_586c;
	case 22642ULL: goto x86_l_5872;
	case 22646ULL: goto x86_l_5876;
	case 22653ULL: goto x86_l_587d;
	case 22658ULL: goto x86_l_5882;
	case 22663ULL: goto x86_l_5887;
	case 22670ULL: goto x86_l_588e;
	case 22674ULL: goto x86_l_5892;
	case 22681ULL: goto x86_l_5899;
	case 22686ULL: goto x86_l_589e;
	case 22691ULL: goto x86_l_58a3;
	case 22693ULL: goto x86_l_58a5;
	case 22696ULL: goto x86_l_58a8;
	case 22698ULL: goto x86_l_58aa;
	case 22700ULL: goto x86_l_58ac;
	case 22706ULL: goto x86_l_58b2;
	case 22709ULL: goto x86_l_58b5;
	case 22715ULL: goto x86_l_58bb;
	case 22720ULL: goto x86_l_58c0;
	case 22726ULL: goto x86_l_58c6;
	case 22730ULL: goto x86_l_58ca;
	case 22737ULL: goto x86_l_58d1;
	case 22740ULL: goto x86_l_58d4;
	case 22745ULL: goto x86_l_58d9;
	case 22750ULL: goto x86_l_58de;
	case 22757ULL: goto x86_l_58e5;
	case 22761ULL: goto x86_l_58e9;
	case 22768ULL: goto x86_l_58f0;
	case 22773ULL: goto x86_l_58f5;
	case 22775ULL: goto x86_l_58f7;
	case 22779ULL: goto x86_l_58fb;
	case 22786ULL: goto x86_l_5902;
	case 22789ULL: goto x86_l_5905;
	case 22796ULL: goto x86_l_590c;
	case 22805ULL: goto x86_l_5915;
	case 22812ULL: goto x86_l_591c;
	case 22817ULL: goto x86_l_5921;
	case 22822ULL: goto x86_l_5926;
	case 22827ULL: goto x86_l_592b;
	case 22832ULL: goto x86_l_5930;
	case 22834ULL: goto x86_l_5932;
	case 22839ULL: goto x86_l_5937;
	case 22841ULL: goto x86_l_5939;
	case 22844ULL: goto x86_l_593c;
	case 22850ULL: goto x86_l_5942;
	case 22853ULL: goto x86_l_5945;
	case 22859ULL: goto x86_l_594b;
	case 22864ULL: goto x86_l_5950;
	case 22870ULL: goto x86_l_5956;
	case 22874ULL: goto x86_l_595a;
	case 22881ULL: goto x86_l_5961;
	case 22886ULL: goto x86_l_5966;
	case 22891ULL: goto x86_l_596b;
	case 22898ULL: goto x86_l_5972;
	case 22902ULL: goto x86_l_5976;
	case 22909ULL: goto x86_l_597d;
	case 22914ULL: goto x86_l_5982;
	case 22919ULL: goto x86_l_5987;
	case 22921ULL: goto x86_l_5989;
	case 22924ULL: goto x86_l_598c;
	case 22926ULL: goto x86_l_598e;
	case 22928ULL: goto x86_l_5990;
	case 22934ULL: goto x86_l_5996;
	case 22937ULL: goto x86_l_5999;
	case 22943ULL: goto x86_l_599f;
	case 22948ULL: goto x86_l_59a4;
	case 22954ULL: goto x86_l_59aa;
	case 22958ULL: goto x86_l_59ae;
	case 22965ULL: goto x86_l_59b5;
	case 22968ULL: goto x86_l_59b8;
	case 22973ULL: goto x86_l_59bd;
	case 22978ULL: goto x86_l_59c2;
	case 22985ULL: goto x86_l_59c9;
	case 22989ULL: goto x86_l_59cd;
	case 22996ULL: goto x86_l_59d4;
	case 23001ULL: goto x86_l_59d9;
	case 23003ULL: goto x86_l_59db;
	case 23007ULL: goto x86_l_59df;
	case 23014ULL: goto x86_l_59e6;
	case 23017ULL: goto x86_l_59e9;
	case 23024ULL: goto x86_l_59f0;
	case 23033ULL: goto x86_l_59f9;
	case 23040ULL: goto x86_l_5a00;
	case 23045ULL: goto x86_l_5a05;
	case 23050ULL: goto x86_l_5a0a;
	case 23055ULL: goto x86_l_5a0f;
	case 23060ULL: goto x86_l_5a14;
	case 23062ULL: goto x86_l_5a16;
	case 23067ULL: goto x86_l_5a1b;
	case 23069ULL: goto x86_l_5a1d;
	case 23072ULL: goto x86_l_5a20;
	case 23078ULL: goto x86_l_5a26;
	case 23081ULL: goto x86_l_5a29;
	case 23087ULL: goto x86_l_5a2f;
	case 23092ULL: goto x86_l_5a34;
	case 23098ULL: goto x86_l_5a3a;
	case 23102ULL: goto x86_l_5a3e;
	case 23109ULL: goto x86_l_5a45;
	case 23114ULL: goto x86_l_5a4a;
	case 23119ULL: goto x86_l_5a4f;
	case 23126ULL: goto x86_l_5a56;
	case 23130ULL: goto x86_l_5a5a;
	case 23137ULL: goto x86_l_5a61;
	case 23142ULL: goto x86_l_5a66;
	case 23147ULL: goto x86_l_5a6b;
	case 23149ULL: goto x86_l_5a6d;
	case 23152ULL: goto x86_l_5a70;
	case 23154ULL: goto x86_l_5a72;
	case 23156ULL: goto x86_l_5a74;
	case 23162ULL: goto x86_l_5a7a;
	case 23165ULL: goto x86_l_5a7d;
	case 23171ULL: goto x86_l_5a83;
	case 23176ULL: goto x86_l_5a88;
	case 23182ULL: goto x86_l_5a8e;
	case 23186ULL: goto x86_l_5a92;
	case 23193ULL: goto x86_l_5a99;
	case 23196ULL: goto x86_l_5a9c;
	case 23201ULL: goto x86_l_5aa1;
	case 23206ULL: goto x86_l_5aa6;
	case 23213ULL: goto x86_l_5aad;
	case 23217ULL: goto x86_l_5ab1;
	case 23224ULL: goto x86_l_5ab8;
	case 23229ULL: goto x86_l_5abd;
	case 23231ULL: goto x86_l_5abf;
	case 23235ULL: goto x86_l_5ac3;
	case 23242ULL: goto x86_l_5aca;
	case 23245ULL: goto x86_l_5acd;
	case 23252ULL: goto x86_l_5ad4;
	case 23261ULL: goto x86_l_5add;
	case 23268ULL: goto x86_l_5ae4;
	case 23273ULL: goto x86_l_5ae9;
	case 23278ULL: goto x86_l_5aee;
	case 23283ULL: goto x86_l_5af3;
	case 23288ULL: goto x86_l_5af8;
	case 23290ULL: goto x86_l_5afa;
	case 23295ULL: goto x86_l_5aff;
	case 23297ULL: goto x86_l_5b01;
	case 23300ULL: goto x86_l_5b04;
	case 23306ULL: goto x86_l_5b0a;
	case 23309ULL: goto x86_l_5b0d;
	case 23315ULL: goto x86_l_5b13;
	case 23320ULL: goto x86_l_5b18;
	case 23326ULL: goto x86_l_5b1e;
	case 23330ULL: goto x86_l_5b22;
	case 23337ULL: goto x86_l_5b29;
	case 23342ULL: goto x86_l_5b2e;
	case 23347ULL: goto x86_l_5b33;
	case 23354ULL: goto x86_l_5b3a;
	case 23358ULL: goto x86_l_5b3e;
	case 23365ULL: goto x86_l_5b45;
	case 23370ULL: goto x86_l_5b4a;
	case 23375ULL: goto x86_l_5b4f;
	case 23377ULL: goto x86_l_5b51;
	case 23380ULL: goto x86_l_5b54;
	case 23382ULL: goto x86_l_5b56;
	case 23384ULL: goto x86_l_5b58;
	case 23390ULL: goto x86_l_5b5e;
	case 23393ULL: goto x86_l_5b61;
	case 23399ULL: goto x86_l_5b67;
	case 23404ULL: goto x86_l_5b6c;
	case 23410ULL: goto x86_l_5b72;
	case 23414ULL: goto x86_l_5b76;
	case 23421ULL: goto x86_l_5b7d;
	case 23424ULL: goto x86_l_5b80;
	case 23429ULL: goto x86_l_5b85;
	case 23434ULL: goto x86_l_5b8a;
	case 23441ULL: goto x86_l_5b91;
	case 23445ULL: goto x86_l_5b95;
	case 23452ULL: goto x86_l_5b9c;
	case 23457ULL: goto x86_l_5ba1;
	case 23459ULL: goto x86_l_5ba3;
	case 23463ULL: goto x86_l_5ba7;
	case 23470ULL: goto x86_l_5bae;
	case 23473ULL: goto x86_l_5bb1;
	case 23480ULL: goto x86_l_5bb8;
	case 23489ULL: goto x86_l_5bc1;
	case 23496ULL: goto x86_l_5bc8;
	case 23501ULL: goto x86_l_5bcd;
	case 23506ULL: goto x86_l_5bd2;
	case 23511ULL: goto x86_l_5bd7;
	case 23516ULL: goto x86_l_5bdc;
	case 23518ULL: goto x86_l_5bde;
	case 23523ULL: goto x86_l_5be3;
	case 23525ULL: goto x86_l_5be5;
	case 23528ULL: goto x86_l_5be8;
	case 23534ULL: goto x86_l_5bee;
	case 23537ULL: goto x86_l_5bf1;
	case 23543ULL: goto x86_l_5bf7;
	case 23548ULL: goto x86_l_5bfc;
	case 23554ULL: goto x86_l_5c02;
	case 23558ULL: goto x86_l_5c06;
	case 23565ULL: goto x86_l_5c0d;
	case 23570ULL: goto x86_l_5c12;
	case 23575ULL: goto x86_l_5c17;
	case 23582ULL: goto x86_l_5c1e;
	case 23586ULL: goto x86_l_5c22;
	case 23593ULL: goto x86_l_5c29;
	case 23598ULL: goto x86_l_5c2e;
	case 23603ULL: goto x86_l_5c33;
	case 23605ULL: goto x86_l_5c35;
	case 23608ULL: goto x86_l_5c38;
	case 23610ULL: goto x86_l_5c3a;
	case 23612ULL: goto x86_l_5c3c;
	case 23618ULL: goto x86_l_5c42;
	case 23621ULL: goto x86_l_5c45;
	case 23627ULL: goto x86_l_5c4b;
	case 23632ULL: goto x86_l_5c50;
	case 23638ULL: goto x86_l_5c56;
	case 23642ULL: goto x86_l_5c5a;
	case 23649ULL: goto x86_l_5c61;
	case 23652ULL: goto x86_l_5c64;
	case 23657ULL: goto x86_l_5c69;
	case 23662ULL: goto x86_l_5c6e;
	case 23669ULL: goto x86_l_5c75;
	case 23673ULL: goto x86_l_5c79;
	case 23680ULL: goto x86_l_5c80;
	case 23685ULL: goto x86_l_5c85;
	case 23687ULL: goto x86_l_5c87;
	case 23691ULL: goto x86_l_5c8b;
	case 23698ULL: goto x86_l_5c92;
	case 23701ULL: goto x86_l_5c95;
	case 23708ULL: goto x86_l_5c9c;
	case 23717ULL: goto x86_l_5ca5;
	case 23724ULL: goto x86_l_5cac;
	case 23729ULL: goto x86_l_5cb1;
	case 23734ULL: goto x86_l_5cb6;
	case 23739ULL: goto x86_l_5cbb;
	case 23744ULL: goto x86_l_5cc0;
	case 23746ULL: goto x86_l_5cc2;
	case 23751ULL: goto x86_l_5cc7;
	case 23753ULL: goto x86_l_5cc9;
	case 23756ULL: goto x86_l_5ccc;
	case 23762ULL: goto x86_l_5cd2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5596:
	/* 0x5596: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_559b:
	/* 0x559b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55a0:
	/* 0x55a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55a2:
	/* 0x55a2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55a7:
	/* 0x55a7: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_55a9:
	/* 0x55a9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_55ac:
	/* 0x55ac: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_55b2:
	/* 0x55b2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_55b5:
	/* 0x55b5: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_55bb:
	/* 0x55bb: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55c0:
	/* 0x55c0: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_55c6:
	/* 0x55c6: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_55ca:
	/* 0x55ca: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_55d1:
	/* 0x55d1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_55d6:
	/* 0x55d6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_55db:
	/* 0x55db: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_55e2:
	/* 0x55e2: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_55e6:
	/* 0x55e6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_55ed:
	/* 0x55ed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55f2:
	/* 0x55f2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_55f7:
	/* 0x55f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55f9:
	/* 0x55f9: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55fc:
	/* 0x55fc: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_55fe:
	/* 0x55fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5600:
	/* 0x5600: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_5606:
	/* 0x5606: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5609:
	/* 0x5609: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_560f:
	/* 0x560f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5614:
	/* 0x5614: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_561a:
	/* 0x561a: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_561e:
	/* 0x561e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5625:
	/* 0x5625: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5628:
	/* 0x5628: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_562d:
	/* 0x562d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5632:
	/* 0x5632: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5639:
	/* 0x5639: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_563d:
	/* 0x563d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5644:
	/* 0x5644: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5649:
	/* 0x5649: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_564b:
	/* 0x564b: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_564f:
	/* 0x564f: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5656:
	/* 0x5656: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5659:
	/* 0x5659: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5660:
	/* 0x5660: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5669:
	/* 0x5669: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_5670:
	/* 0x5670: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5675:
	/* 0x5675: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_567a:
	/* 0x567a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_567f:
	/* 0x567f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5684:
	/* 0x5684: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5686:
	/* 0x5686: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_568b:
	/* 0x568b: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_568d:
	/* 0x568d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5690:
	/* 0x5690: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_5696:
	/* 0x5696: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5699:
	/* 0x5699: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_569f:
	/* 0x569f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56a4:
	/* 0x56a4: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_56aa:
	/* 0x56aa: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_56ae:
	/* 0x56ae: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_56b5:
	/* 0x56b5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_56ba:
	/* 0x56ba: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_56bf:
	/* 0x56bf: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_56c6:
	/* 0x56c6: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_56ca:
	/* 0x56ca: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_56d1:
	/* 0x56d1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56d6:
	/* 0x56d6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_56db:
	/* 0x56db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56dd:
	/* 0x56dd: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56e0:
	/* 0x56e0: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_56e2:
	/* 0x56e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56e4:
	/* 0x56e4: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_56ea:
	/* 0x56ea: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_56ed:
	/* 0x56ed: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_56f3:
	/* 0x56f3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56f8:
	/* 0x56f8: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_56fe:
	/* 0x56fe: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5702:
	/* 0x5702: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5709:
	/* 0x5709: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_570c:
	/* 0x570c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5711:
	/* 0x5711: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5716:
	/* 0x5716: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_571d:
	/* 0x571d: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5721:
	/* 0x5721: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5728:
	/* 0x5728: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_572d:
	/* 0x572d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_572f:
	/* 0x572f: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5733:
	/* 0x5733: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_573a:
	/* 0x573a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_573d:
	/* 0x573d: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5744:
	/* 0x5744: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_574d:
	/* 0x574d: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_5754:
	/* 0x5754: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5759:
	/* 0x5759: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_575e:
	/* 0x575e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5763:
	/* 0x5763: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5768:
	/* 0x5768: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_576a:
	/* 0x576a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_576f:
	/* 0x576f: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_5771:
	/* 0x5771: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5774:
	/* 0x5774: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_577a:
	/* 0x577a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_577d:
	/* 0x577d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5783:
	/* 0x5783: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5788:
	/* 0x5788: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_578e:
	/* 0x578e: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5792:
	/* 0x5792: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5799:
	/* 0x5799: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_579e:
	/* 0x579e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_57a3:
	/* 0x57a3: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_57aa:
	/* 0x57aa: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_57ae:
	/* 0x57ae: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_57b5:
	/* 0x57b5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57ba:
	/* 0x57ba: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_57bf:
	/* 0x57bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57c1:
	/* 0x57c1: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57c4:
	/* 0x57c4: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_57c6:
	/* 0x57c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57c8:
	/* 0x57c8: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_57ce:
	/* 0x57ce: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_57d1:
	/* 0x57d1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_57d7:
	/* 0x57d7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57dc:
	/* 0x57dc: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_57e2:
	/* 0x57e2: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_57e6:
	/* 0x57e6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_57ed:
	/* 0x57ed: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_57f0:
	/* 0x57f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_57f5:
	/* 0x57f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_57fa:
	/* 0x57fa: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5801:
	/* 0x5801: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5805:
	/* 0x5805: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_580c:
	/* 0x580c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5811:
	/* 0x5811: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5813:
	/* 0x5813: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5817:
	/* 0x5817: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_581e:
	/* 0x581e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5821:
	/* 0x5821: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5828:
	/* 0x5828: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5831:
	/* 0x5831: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_5838:
	/* 0x5838: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_583d:
	/* 0x583d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5842:
	/* 0x5842: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5847:
	/* 0x5847: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_584c:
	/* 0x584c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_584e:
	/* 0x584e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5853:
	/* 0x5853: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_5855:
	/* 0x5855: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5858:
	/* 0x5858: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_585e:
	/* 0x585e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5861:
	/* 0x5861: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5867:
	/* 0x5867: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_586c:
	/* 0x586c: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5872:
	/* 0x5872: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5876:
	/* 0x5876: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_587d:
	/* 0x587d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5882:
	/* 0x5882: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5887:
	/* 0x5887: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_588e:
	/* 0x588e: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5892:
	/* 0x5892: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5899:
	/* 0x5899: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_589e:
	/* 0x589e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_58a3:
	/* 0x58a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58a5:
	/* 0x58a5: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58a8:
	/* 0x58a8: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_58aa:
	/* 0x58aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58ac:
	/* 0x58ac: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_58b2:
	/* 0x58b2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_58b5:
	/* 0x58b5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_58bb:
	/* 0x58bb: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58c0:
	/* 0x58c0: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_58c6:
	/* 0x58c6: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_58ca:
	/* 0x58ca: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_58d1:
	/* 0x58d1: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_58d4:
	/* 0x58d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_58d9:
	/* 0x58d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_58de:
	/* 0x58de: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_58e5:
	/* 0x58e5: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_58e9:
	/* 0x58e9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_58f0:
	/* 0x58f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_58f5:
	/* 0x58f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58f7:
	/* 0x58f7: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_58fb:
	/* 0x58fb: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5902:
	/* 0x5902: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5905:
	/* 0x5905: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_590c:
	/* 0x590c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5915:
	/* 0x5915: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_591c:
	/* 0x591c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5921:
	/* 0x5921: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5926:
	/* 0x5926: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_592b:
	/* 0x592b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5930:
	/* 0x5930: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5932:
	/* 0x5932: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5937:
	/* 0x5937: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_5939:
	/* 0x5939: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_593c:
	/* 0x593c: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_5942:
	/* 0x5942: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5945:
	/* 0x5945: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_594b:
	/* 0x594b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5950:
	/* 0x5950: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5956:
	/* 0x5956: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_595a:
	/* 0x595a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5961:
	/* 0x5961: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5966:
	/* 0x5966: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_596b:
	/* 0x596b: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5972:
	/* 0x5972: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5976:
	/* 0x5976: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_597d:
	/* 0x597d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5982:
	/* 0x5982: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5987:
	/* 0x5987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5989:
	/* 0x5989: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_598c:
	/* 0x598c: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_598e:
	/* 0x598e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5990:
	/* 0x5990: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_5996:
	/* 0x5996: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5999:
	/* 0x5999: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_599f:
	/* 0x599f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a4:
	/* 0x59a4: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_59aa:
	/* 0x59aa: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_59ae:
	/* 0x59ae: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_59b5:
	/* 0x59b5: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_59b8:
	/* 0x59b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_59bd:
	/* 0x59bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_59c2:
	/* 0x59c2: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_59c9:
	/* 0x59c9: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_59cd:
	/* 0x59cd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_59d4:
	/* 0x59d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_59d9:
	/* 0x59d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59db:
	/* 0x59db: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_59df:
	/* 0x59df: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_59e6:
	/* 0x59e6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_59e9:
	/* 0x59e9: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_59f0:
	/* 0x59f0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_59f9:
	/* 0x59f9: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_5a00:
	/* 0x5a00: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a05:
	/* 0x5a05: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a0a:
	/* 0x5a0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a0f:
	/* 0x5a0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a14:
	/* 0x5a14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a16:
	/* 0x5a16: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a1b:
	/* 0x5a1b: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_5a1d:
	/* 0x5a1d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5a20:
	/* 0x5a20: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_5a26:
	/* 0x5a26: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5a29:
	/* 0x5a29: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5a2f:
	/* 0x5a2f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a34:
	/* 0x5a34: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5a3a:
	/* 0x5a3a: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5a3e:
	/* 0x5a3e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5a45:
	/* 0x5a45: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5a4a:
	/* 0x5a4a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5a4f:
	/* 0x5a4f: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5a56:
	/* 0x5a56: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5a5a:
	/* 0x5a5a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5a61:
	/* 0x5a61: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a66:
	/* 0x5a66: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5a6b:
	/* 0x5a6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a6d:
	/* 0x5a6d: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a70:
	/* 0x5a70: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_5a72:
	/* 0x5a72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a74:
	/* 0x5a74: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_5a7a:
	/* 0x5a7a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5a7d:
	/* 0x5a7d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5a83:
	/* 0x5a83: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a88:
	/* 0x5a88: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5a8e:
	/* 0x5a8e: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5a92:
	/* 0x5a92: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5a99:
	/* 0x5a99: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5a9c:
	/* 0x5a9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5aa1:
	/* 0x5aa1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5aa6:
	/* 0x5aa6: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5aad:
	/* 0x5aad: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5ab1:
	/* 0x5ab1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5ab8:
	/* 0x5ab8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5abd:
	/* 0x5abd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5abf:
	/* 0x5abf: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5ac3:
	/* 0x5ac3: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5aca:
	/* 0x5aca: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5acd:
	/* 0x5acd: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5ad4:
	/* 0x5ad4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5add:
	/* 0x5add: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5ae4:
	/* 0x5ae4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ae9:
	/* 0x5ae9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5aee:
	/* 0x5aee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5af3:
	/* 0x5af3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5af8:
	/* 0x5af8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5afa:
	/* 0x5afa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5aff:
	/* 0x5aff: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_5b01:
	/* 0x5b01: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5b04:
	/* 0x5b04: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_5b0a:
	/* 0x5b0a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5b0d:
	/* 0x5b0d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5b13:
	/* 0x5b13: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b18:
	/* 0x5b18: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5b1e:
	/* 0x5b1e: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5b22:
	/* 0x5b22: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5b29:
	/* 0x5b29: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5b2e:
	/* 0x5b2e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5b33:
	/* 0x5b33: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5b3a:
	/* 0x5b3a: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5b3e:
	/* 0x5b3e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5b45:
	/* 0x5b45: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b4a:
	/* 0x5b4a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5b4f:
	/* 0x5b4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b51:
	/* 0x5b51: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b54:
	/* 0x5b54: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_5b56:
	/* 0x5b56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b58:
	/* 0x5b58: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_5b5e:
	/* 0x5b5e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5b61:
	/* 0x5b61: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5b67:
	/* 0x5b67: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b6c:
	/* 0x5b6c: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5b72:
	/* 0x5b72: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5b76:
	/* 0x5b76: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5b7d:
	/* 0x5b7d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5b80:
	/* 0x5b80: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5b85:
	/* 0x5b85: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5b8a:
	/* 0x5b8a: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5b91:
	/* 0x5b91: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5b95:
	/* 0x5b95: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5b9c:
	/* 0x5b9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5ba1:
	/* 0x5ba1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ba3:
	/* 0x5ba3: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5ba7:
	/* 0x5ba7: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5bae:
	/* 0x5bae: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5bb1:
	/* 0x5bb1: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5bb8:
	/* 0x5bb8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5bc1:
	/* 0x5bc1: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_5bc8:
	/* 0x5bc8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bcd:
	/* 0x5bcd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5bd2:
	/* 0x5bd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5bd7:
	/* 0x5bd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bdc:
	/* 0x5bdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bde:
	/* 0x5bde: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5be3:
	/* 0x5be3: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_5be5:
	/* 0x5be5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5be8:
	/* 0x5be8: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_5bee:
	/* 0x5bee: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5bf1:
	/* 0x5bf1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5bf7:
	/* 0x5bf7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bfc:
	/* 0x5bfc: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5c02:
	/* 0x5c02: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5c06:
	/* 0x5c06: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5c0d:
	/* 0x5c0d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5c12:
	/* 0x5c12: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5c17:
	/* 0x5c17: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5c1e:
	/* 0x5c1e: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5c22:
	/* 0x5c22: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5c29:
	/* 0x5c29: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c2e:
	/* 0x5c2e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5c33:
	/* 0x5c33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c35:
	/* 0x5c35: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c38:
	/* 0x5c38: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_5c3a:
	/* 0x5c3a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c3c:
	/* 0x5c3c: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24652ULL;
	}
x86_l_5c42:
	/* 0x5c42: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5c45:
	/* 0x5c45: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5c4b:
	/* 0x5c4b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c50:
	/* 0x5c50: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5c56:
	/* 0x5c56: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5c5a:
	/* 0x5c5a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5c61:
	/* 0x5c61: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5c64:
	/* 0x5c64: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5c69:
	/* 0x5c69: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5c6e:
	/* 0x5c6e: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5c75:
	/* 0x5c75: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5c79:
	/* 0x5c79: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5c80:
	/* 0x5c80: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5c85:
	/* 0x5c85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c87:
	/* 0x5c87: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5c8b:
	/* 0x5c8b: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5c92:
	/* 0x5c92: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5c95:
	/* 0x5c95: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5c9c:
	/* 0x5c9c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5ca5:
	/* 0x5ca5: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_5cac:
	/* 0x5cac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cb1:
	/* 0x5cb1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5cb6:
	/* 0x5cb6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5cbb:
	/* 0x5cbb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cc0:
	/* 0x5cc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cc2:
	/* 0x5cc2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cc7:
	/* 0x5cc7: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_5cc9:
	/* 0x5cc9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5ccc:
	/* 0x5ccc: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24652ULL;
	}
x86_l_5cd2:
	/* 0x5cd2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
	return 23765ULL;
}

static __noinline __u64 tracee_trace_call_usermodehelper_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 23765ULL: goto x86_l_5cd5;
	case 23771ULL: goto x86_l_5cdb;
	case 23776ULL: goto x86_l_5ce0;
	case 23782ULL: goto x86_l_5ce6;
	case 23786ULL: goto x86_l_5cea;
	case 23793ULL: goto x86_l_5cf1;
	case 23798ULL: goto x86_l_5cf6;
	case 23803ULL: goto x86_l_5cfb;
	case 23810ULL: goto x86_l_5d02;
	case 23814ULL: goto x86_l_5d06;
	case 23821ULL: goto x86_l_5d0d;
	case 23826ULL: goto x86_l_5d12;
	case 23831ULL: goto x86_l_5d17;
	case 23833ULL: goto x86_l_5d19;
	case 23836ULL: goto x86_l_5d1c;
	case 23838ULL: goto x86_l_5d1e;
	case 23840ULL: goto x86_l_5d20;
	case 23846ULL: goto x86_l_5d26;
	case 23849ULL: goto x86_l_5d29;
	case 23855ULL: goto x86_l_5d2f;
	case 23860ULL: goto x86_l_5d34;
	case 23866ULL: goto x86_l_5d3a;
	case 23870ULL: goto x86_l_5d3e;
	case 23877ULL: goto x86_l_5d45;
	case 23880ULL: goto x86_l_5d48;
	case 23885ULL: goto x86_l_5d4d;
	case 23890ULL: goto x86_l_5d52;
	case 23897ULL: goto x86_l_5d59;
	case 23901ULL: goto x86_l_5d5d;
	case 23908ULL: goto x86_l_5d64;
	case 23913ULL: goto x86_l_5d69;
	case 23915ULL: goto x86_l_5d6b;
	case 23919ULL: goto x86_l_5d6f;
	case 23926ULL: goto x86_l_5d76;
	case 23929ULL: goto x86_l_5d79;
	case 23936ULL: goto x86_l_5d80;
	case 23945ULL: goto x86_l_5d89;
	case 23952ULL: goto x86_l_5d90;
	case 23957ULL: goto x86_l_5d95;
	case 23962ULL: goto x86_l_5d9a;
	case 23967ULL: goto x86_l_5d9f;
	case 23972ULL: goto x86_l_5da4;
	case 23974ULL: goto x86_l_5da6;
	case 23979ULL: goto x86_l_5dab;
	case 23981ULL: goto x86_l_5dad;
	case 23984ULL: goto x86_l_5db0;
	case 23990ULL: goto x86_l_5db6;
	case 23993ULL: goto x86_l_5db9;
	case 23999ULL: goto x86_l_5dbf;
	case 24004ULL: goto x86_l_5dc4;
	case 24010ULL: goto x86_l_5dca;
	case 24014ULL: goto x86_l_5dce;
	case 24021ULL: goto x86_l_5dd5;
	case 24026ULL: goto x86_l_5dda;
	case 24031ULL: goto x86_l_5ddf;
	case 24038ULL: goto x86_l_5de6;
	case 24042ULL: goto x86_l_5dea;
	case 24049ULL: goto x86_l_5df1;
	case 24054ULL: goto x86_l_5df6;
	case 24059ULL: goto x86_l_5dfb;
	case 24061ULL: goto x86_l_5dfd;
	case 24064ULL: goto x86_l_5e00;
	case 24066ULL: goto x86_l_5e02;
	case 24068ULL: goto x86_l_5e04;
	case 24074ULL: goto x86_l_5e0a;
	case 24077ULL: goto x86_l_5e0d;
	case 24083ULL: goto x86_l_5e13;
	case 24088ULL: goto x86_l_5e18;
	case 24094ULL: goto x86_l_5e1e;
	case 24098ULL: goto x86_l_5e22;
	case 24105ULL: goto x86_l_5e29;
	case 24108ULL: goto x86_l_5e2c;
	case 24113ULL: goto x86_l_5e31;
	case 24118ULL: goto x86_l_5e36;
	case 24125ULL: goto x86_l_5e3d;
	case 24129ULL: goto x86_l_5e41;
	case 24136ULL: goto x86_l_5e48;
	case 24141ULL: goto x86_l_5e4d;
	case 24143ULL: goto x86_l_5e4f;
	case 24147ULL: goto x86_l_5e53;
	case 24154ULL: goto x86_l_5e5a;
	case 24157ULL: goto x86_l_5e5d;
	case 24164ULL: goto x86_l_5e64;
	case 24173ULL: goto x86_l_5e6d;
	case 24180ULL: goto x86_l_5e74;
	case 24185ULL: goto x86_l_5e79;
	case 24190ULL: goto x86_l_5e7e;
	case 24195ULL: goto x86_l_5e83;
	case 24200ULL: goto x86_l_5e88;
	case 24203ULL: goto x86_l_5e8b;
	case 24205ULL: goto x86_l_5e8d;
	case 24210ULL: goto x86_l_5e92;
	case 24212ULL: goto x86_l_5e94;
	case 24215ULL: goto x86_l_5e97;
	case 24221ULL: goto x86_l_5e9d;
	case 24224ULL: goto x86_l_5ea0;
	case 24230ULL: goto x86_l_5ea6;
	case 24235ULL: goto x86_l_5eab;
	case 24241ULL: goto x86_l_5eb1;
	case 24245ULL: goto x86_l_5eb5;
	case 24252ULL: goto x86_l_5ebc;
	case 24257ULL: goto x86_l_5ec1;
	case 24262ULL: goto x86_l_5ec6;
	case 24269ULL: goto x86_l_5ecd;
	case 24273ULL: goto x86_l_5ed1;
	case 24280ULL: goto x86_l_5ed8;
	case 24285ULL: goto x86_l_5edd;
	case 24290ULL: goto x86_l_5ee2;
	case 24292ULL: goto x86_l_5ee4;
	case 24295ULL: goto x86_l_5ee7;
	case 24297ULL: goto x86_l_5ee9;
	case 24299ULL: goto x86_l_5eeb;
	case 24305ULL: goto x86_l_5ef1;
	case 24308ULL: goto x86_l_5ef4;
	case 24314ULL: goto x86_l_5efa;
	case 24319ULL: goto x86_l_5eff;
	case 24325ULL: goto x86_l_5f05;
	case 24329ULL: goto x86_l_5f09;
	case 24336ULL: goto x86_l_5f10;
	case 24339ULL: goto x86_l_5f13;
	case 24344ULL: goto x86_l_5f18;
	case 24349ULL: goto x86_l_5f1d;
	case 24356ULL: goto x86_l_5f24;
	case 24360ULL: goto x86_l_5f28;
	case 24367ULL: goto x86_l_5f2f;
	case 24372ULL: goto x86_l_5f34;
	case 24374ULL: goto x86_l_5f36;
	case 24378ULL: goto x86_l_5f3a;
	case 24385ULL: goto x86_l_5f41;
	case 24388ULL: goto x86_l_5f44;
	case 24395ULL: goto x86_l_5f4b;
	case 24403ULL: goto x86_l_5f53;
	case 24406ULL: goto x86_l_5f56;
	case 24412ULL: goto x86_l_5f5c;
	case 24414ULL: goto x86_l_5f5e;
	case 24419ULL: goto x86_l_5f63;
	case 24423ULL: goto x86_l_5f67;
	case 24426ULL: goto x86_l_5f6a;
	case 24431ULL: goto x86_l_5f6f;
	case 24435ULL: goto x86_l_5f73;
	case 24442ULL: goto x86_l_5f7a;
	case 24447ULL: goto x86_l_5f7f;
	case 24452ULL: goto x86_l_5f84;
	case 24457ULL: goto x86_l_5f89;
	case 24464ULL: goto x86_l_5f90;
	case 24467ULL: goto x86_l_5f93;
	case 24474ULL: goto x86_l_5f9a;
	case 24479ULL: goto x86_l_5f9f;
	case 24481ULL: goto x86_l_5fa1;
	case 24485ULL: goto x86_l_5fa5;
	case 24487ULL: goto x86_l_5fa7;
	case 24489ULL: goto x86_l_5fa9;
	case 24495ULL: goto x86_l_5faf;
	case 24498ULL: goto x86_l_5fb2;
	case 24504ULL: goto x86_l_5fb8;
	case 24509ULL: goto x86_l_5fbd;
	case 24515ULL: goto x86_l_5fc3;
	case 24519ULL: goto x86_l_5fc7;
	case 24526ULL: goto x86_l_5fce;
	case 24531ULL: goto x86_l_5fd3;
	case 24536ULL: goto x86_l_5fd8;
	case 24541ULL: goto x86_l_5fdd;
	case 24548ULL: goto x86_l_5fe4;
	case 24552ULL: goto x86_l_5fe8;
	case 24559ULL: goto x86_l_5fef;
	case 24564ULL: goto x86_l_5ff4;
	case 24566ULL: goto x86_l_5ff6;
	case 24571ULL: goto x86_l_5ffb;
	case 24578ULL: goto x86_l_6002;
	case 24581ULL: goto x86_l_6005;
	case 24588ULL: goto x86_l_600c;
	case 24590ULL: goto x86_l_600e;
	case 24595ULL: goto x86_l_6013;
	case 24602ULL: goto x86_l_601a;
	case 24605ULL: goto x86_l_601d;
	case 24609ULL: goto x86_l_6021;
	case 24614ULL: goto x86_l_6026;
	case 24619ULL: goto x86_l_602b;
	case 24624ULL: goto x86_l_6030;
	case 24626ULL: goto x86_l_6032;
	case 24629ULL: goto x86_l_6035;
	case 24631ULL: goto x86_l_6037;
	case 24636ULL: goto x86_l_603c;
	case 24640ULL: goto x86_l_6040;
	case 24645ULL: goto x86_l_6045;
	case 24647ULL: goto x86_l_6047;
	case 24652ULL: goto x86_l_604c;
	case 24657ULL: goto x86_l_6051;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5cd5:
	/* 0x5cd5: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5cdb:
	/* 0x5cdb: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ce0:
	/* 0x5ce0: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5ce6:
	/* 0x5ce6: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5cea:
	/* 0x5cea: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5cf1:
	/* 0x5cf1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5cf6:
	/* 0x5cf6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5cfb:
	/* 0x5cfb: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5d02:
	/* 0x5d02: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5d06:
	/* 0x5d06: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5d0d:
	/* 0x5d0d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d12:
	/* 0x5d12: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5d17:
	/* 0x5d17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d19:
	/* 0x5d19: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d1c:
	/* 0x5d1c: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_5d1e:
	/* 0x5d1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d20:
	/* 0x5d20: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_604c;
	}
x86_l_5d26:
	/* 0x5d26: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5d29:
	/* 0x5d29: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5d2f:
	/* 0x5d2f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d34:
	/* 0x5d34: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5d3a:
	/* 0x5d3a: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5d3e:
	/* 0x5d3e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5d45:
	/* 0x5d45: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5d48:
	/* 0x5d48: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5d4d:
	/* 0x5d4d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d52:
	/* 0x5d52: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5d59:
	/* 0x5d59: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5d5d:
	/* 0x5d5d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5d64:
	/* 0x5d64: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5d69:
	/* 0x5d69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d6b:
	/* 0x5d6b: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5d6f:
	/* 0x5d6f: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5d76:
	/* 0x5d76: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5d79:
	/* 0x5d79: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5d80:
	/* 0x5d80: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5d89:
	/* 0x5d89: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_5d90:
	/* 0x5d90: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d95:
	/* 0x5d95: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5d9a:
	/* 0x5d9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d9f:
	/* 0x5d9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5da4:
	/* 0x5da4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5da6:
	/* 0x5da6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dab:
	/* 0x5dab: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_5dad:
	/* 0x5dad: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5db0:
	/* 0x5db0: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_604c;
	}
x86_l_5db6:
	/* 0x5db6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5db9:
	/* 0x5db9: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5dbf:
	/* 0x5dbf: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dc4:
	/* 0x5dc4: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5dca:
	/* 0x5dca: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5dce:
	/* 0x5dce: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5dd5:
	/* 0x5dd5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5dda:
	/* 0x5dda: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5ddf:
	/* 0x5ddf: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5de6:
	/* 0x5de6: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5dea:
	/* 0x5dea: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5df1:
	/* 0x5df1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5df6:
	/* 0x5df6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5dfb:
	/* 0x5dfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dfd:
	/* 0x5dfd: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e00:
	/* 0x5e00: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_5e02:
	/* 0x5e02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e04:
	/* 0x5e04: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_604c;
	}
x86_l_5e0a:
	/* 0x5e0a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5e0d:
	/* 0x5e0d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5e13:
	/* 0x5e13: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e18:
	/* 0x5e18: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5e1e:
	/* 0x5e1e: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5e22:
	/* 0x5e22: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5e29:
	/* 0x5e29: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5e2c:
	/* 0x5e2c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5e31:
	/* 0x5e31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e36:
	/* 0x5e36: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5e3d:
	/* 0x5e3d: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5e41:
	/* 0x5e41: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5e48:
	/* 0x5e48: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5e4d:
	/* 0x5e4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e4f:
	/* 0x5e4f: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5e53:
	/* 0x5e53: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5e5a:
	/* 0x5e5a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5e5d:
	/* 0x5e5d: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5e64:
	/* 0x5e64: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5e6d:
	/* 0x5e6d: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_5e74:
	/* 0x5e74: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e79:
	/* 0x5e79: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e7e:
	/* 0x5e7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e83:
	/* 0x5e83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e88:
	/* 0x5e88: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5e8b:
	/* 0x5e8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e8d:
	/* 0x5e8d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e92:
	/* 0x5e92: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_5e94:
	/* 0x5e94: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5e97:
	/* 0x5e97: je     604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_604c;
	}
x86_l_5e9d:
	/* 0x5e9d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5ea0:
	/* 0x5ea0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5ea6:
	/* 0x5ea6: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5eab:
	/* 0x5eab: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5eb1:
	/* 0x5eb1: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5eb5:
	/* 0x5eb5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5ebc:
	/* 0x5ebc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5ec1:
	/* 0x5ec1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5ec6:
	/* 0x5ec6: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5ecd:
	/* 0x5ecd: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5ed1:
	/* 0x5ed1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5ed8:
	/* 0x5ed8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5edd:
	/* 0x5edd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5ee2:
	/* 0x5ee2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ee4:
	/* 0x5ee4: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ee7:
	/* 0x5ee7: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_5ee9:
	/* 0x5ee9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5eeb:
	/* 0x5eeb: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_604c;
	}
x86_l_5ef1:
	/* 0x5ef1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5ef4:
	/* 0x5ef4: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5efa:
	/* 0x5efa: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5eff:
	/* 0x5eff: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5f05:
	/* 0x5f05: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5f09:
	/* 0x5f09: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5f10:
	/* 0x5f10: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5f13:
	/* 0x5f13: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5f18:
	/* 0x5f18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5f1d:
	/* 0x5f1d: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5f24:
	/* 0x5f24: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5f28:
	/* 0x5f28: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5f2f:
	/* 0x5f2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5f34:
	/* 0x5f34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f36:
	/* 0x5f36: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5f3a:
	/* 0x5f3a: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5f41:
	/* 0x5f41: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5f44:
	/* 0x5f44: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5f4b:
	/* 0x5f4b: mov    DWORD PTR [rsp+0x58],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377960148526ULL);
x86_l_5f53:
	/* 0x5f53: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5f56:
	/* 0x5f56: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_5f5c:
	/* 0x5f5c: jb     5f67 <trace_call_usermodehelper+0x5f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5f67;
	}
x86_l_5f5e:
	/* 0x5f5e: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_5f63:
	/* 0x5f63: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_5f67:
	/* 0x5f67: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5f6a:
	/* 0x5f6a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f6f:
	/* 0x5f6f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5f73:
	/* 0x5f73: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5f7a:
	/* 0x5f7a: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5f7f:
	/* 0x5f7f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5f84:
	/* 0x5f84: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5f89:
	/* 0x5f89: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5f90:
	/* 0x5f90: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5f93:
	/* 0x5f93: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5f9a:
	/* 0x5f9a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5f9f:
	/* 0x5f9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fa1:
	/* 0x5fa1: mov    DWORD PTR [rsp+0x54],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_5fa5:
	/* 0x5fa5: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_5fa7:
	/* 0x5fa7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fa9:
	/* 0x5fa9: jle    604c <trace_call_usermodehelper+0x604c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_604c;
	}
x86_l_5faf:
	/* 0x5faf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5fb2:
	/* 0x5fb2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5fb8:
	/* 0x5fb8: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fbd:
	/* 0x5fbd: ja     1690 <trace_call_usermodehelper+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5776ULL;
	}
x86_l_5fc3:
	/* 0x5fc3: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5fc7:
	/* 0x5fc7: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5fce:
	/* 0x5fce: lea    rdx,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_5fd3:
	/* 0x5fd3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5fd8:
	/* 0x5fd8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5fdd:
	/* 0x5fdd: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5fe4:
	/* 0x5fe4: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5fe8:
	/* 0x5fe8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5fef:
	/* 0x5fef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5ff4:
	/* 0x5ff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ff6:
	/* 0x5ff6: movzx  eax,WORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 84ULL);
x86_l_5ffb:
	/* 0x5ffb: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_6002:
	/* 0x6002: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_6005:
	/* 0x6005: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_600c:
	/* 0x600c: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_600e:
	/* 0x600e: jmp    1690 <trace_call_usermodehelper+0x1690> */
	return 5776ULL;
x86_l_6013:
	/* 0x6013: lea    rdi,[rbp+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_601a:
	/* 0x601a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_601d:
	/* 0x601d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6021:
	/* 0x6021: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_6026:
	/* 0x6026: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_602b:
	/* 0x602b: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_6030:
	/* 0x6030: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6032:
	/* 0x6032: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6035:
	/* 0x6035: jne    6045 <trace_call_usermodehelper+0x6045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6045;
	}
x86_l_6037:
	/* 0x6037: movzx  eax,WORD PTR [r14+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_603c:
	/* 0x603c: mov    WORD PTR [rbp+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_6040:
	/* 0x6040: jmp    bbb <trace_call_usermodehelper+0xbbb> */
	return 3003ULL;
x86_l_6045:
	/* 0x6045: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6047:
	/* 0x6047: jmp    1c09 <trace_call_usermodehelper+0x1c09> */
	return 7177ULL;
x86_l_604c:
	/* 0x604c: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6051:
	/* 0x6051: jmp    1690 <trace_call_usermodehelper+0x1690> */
	return 5776ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_call_usermodehelper_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 20720U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2118ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2123ULL && __x86_pc <= 3774ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3781ULL && __x86_pc <= 5340ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5347ULL && __x86_pc <= 7031ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7033ULL && __x86_pc <= 8867ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8875ULL && __x86_pc <= 10729ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10734ULL && __x86_pc <= 12605ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12609ULL && __x86_pc <= 14488ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14493ULL && __x86_pc <= 16356ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16358ULL && __x86_pc <= 18185ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18192ULL && __x86_pc <= 20037ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20039ULL && __x86_pc <= 21905ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 21910ULL && __x86_pc <= 23762ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 23765ULL && __x86_pc <= 24657ULL)
			__x86_pc = tracee_trace_call_usermodehelper_x86_chunk_13(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
